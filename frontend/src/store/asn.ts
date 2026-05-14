import { defineStore } from 'pinia'
import { api } from '@/api'
import { processSchema, lookupType, getFieldKey, resolveFullType } from '@/schema-utils'

export const useAsnStore = defineStore('asn', {
  state: () => ({
    sessionId: null as string | null,
    types: [] as string[],
    selectedType: null as string | null,
    schema: null as any | null,
    indexedSchema: {} as Record<string, any>,
    messageData: {} as any,
    encodedHex: '' as string,
    decodedData: null as any | null,
    isCompiling: false,
    isEncoding: false,
    isDecoding: false,
    error: null as string | null,
    encoding: 'uper' as string,
    isEncodingAutoDetected: false,
  }),
  getters: {
    messageTypes(state): string[] {
      return state.types.filter(t => {
        const lower = t.toLowerCase()
        // Heuristic for top-level messages in 3GPP protocols
        return lower.endsWith('request') || 
               lower.endsWith('response') || 
               lower.endsWith('failure') || 
               lower.endsWith('command') || 
               lower.endsWith('indication') ||
               lower.endsWith('pdu') ||
               t.includes('::') // Likely a fully qualified type
      })
    }
  },
  actions: {
    setEncoding(enc: string) {
      this.encoding = enc
    },
    async compileSchema(file: File) {
      this.isCompiling = true
      this.error = null
      this.selectedType = null
      this.messageData = {}
      this.encodedHex = ''
      this.decodedData = null
      this.isEncodingAutoDetected = false

      // 1. Auto-detect encoding based on filename hints or standard protocol names
      const filename = file.name.toLowerCase()
      if (filename.includes('uper')) {
        this.encoding = 'uper'
        this.isEncodingAutoDetected = true
      } else if (filename.includes('aper')) {
        this.encoding = 'aper'
        this.isEncodingAutoDetected = true
      } else if (
        filename.includes('ngap') || 
        filename.includes('s1ap') || 
        filename.includes('e1ap') || 
        filename.includes('f1ap') || 
        filename.includes('x2ap') || 
        filename.includes('rrc')
      ) {
        // Modern 3GPP protocols use UPER
        this.encoding = 'uper'
        this.isEncodingAutoDetected = true
      } else if (
        filename.includes('ranap') || 
        filename.includes('nbap') || 
        filename.includes('rnsap') || 
        filename.includes('sabp') ||
        filename.includes('hnbap')
      ) {
        // Older 3GPP/RAN protocols use APER
        this.encoding = 'aper'
        this.isEncodingAutoDetected = true
      }

      try {
        const res = await api.sessionCompile(file, this.encoding)
        if (res.error) {
          this.error = res.error
        } else {
          this.sessionId = res.session_id
          this.types = res.types
          this.schema = res.schema
          this.indexedSchema = processSchema(res.schema) || {}

          // Auto-select likely top-level PDU
          if (this.types.length > 0) {
            const pduCandidate = this.types.find(t => {
              const lower = t.toLowerCase()
              return lower.endsWith('::e1ap_pdu') || 
                     lower.endsWith('::ngap_pdu') ||
                     lower.endsWith('::s1ap_pdu') ||
                     lower.endsWith('::x2ap_pdu') ||
                     lower.endsWith('::f1ap_pdu') ||
                     lower.endsWith('pdu')
            })
            
            // Refine encoding based on detected types if not already determined
            const allTypesString = this.types.join(' ').toLowerCase()
            // Modern APs (NGAP, E1AP, etc.) already defaulted to UPER above.
            // But we can check content as a fallback.
            if (!filename.includes('aper') && !filename.includes('uper')) {
                if (allTypesString.includes('ranap') || allTypesString.includes('nbap')) {
                    this.encoding = 'aper'
                    this.isEncodingAutoDetected = true
                }
            }

            if (pduCandidate) {
              this.selectType(pduCandidate)
            }
          }
        }
      } catch (e: any) {
        this.error = e.message || 'Compilation failed'
      } finally {
        this.isCompiling = false
      }
    },
    selectType(typeName: string) {
      this.selectedType = typeName
      this.encodedHex = ''
      this.decodedData = null
      
      // Auto-populate defaults
      const rootSchema = lookupType(typeName, this.indexedSchema)
      this.messageData = rootSchema ? this.getDefaults(rootSchema) : {}
    },
    getDefaults(schema: any): any {
      const kind = (schema.kind || '').toLowerCase()
      
      // If the schema itself has a default value (leaf node)
      if (schema.default !== undefined) {
        return schema.default
      }

      if (kind === 'sequence') {
        const data: any = {}
        if (schema.fields) {
          for (const field of schema.fields) {
            const fieldKey = getFieldKey(field)
            const fieldSchema = field.type_ref ? lookupType(field.type_ref, this.indexedSchema) : field
            
            if (field.default !== undefined) {
              data[fieldKey] = field.default
            } else if (fieldSchema) {
              const nestedDefaults = this.getDefaults(fieldSchema)
              // Only add if it's not an empty object/null to avoid bloat
              if (nestedDefaults !== undefined && (typeof nestedDefaults !== 'object' || Object.keys(nestedDefaults).length > 0)) {
                data[fieldKey] = nestedDefaults
              }
            }
          }
        }
        return data
      }
      
      // For choices, we don't pick a default unless explicitly forced, 
      // as it requires selecting an alternative.
      
      return undefined
    },
    updateMessageData(newData: any) {
      this.messageData = newData
    },
    updateHex(newHex: string) {
      this.encodedHex = newHex
    },
    transformForEncoder(data: any, schema: any): any {
      if (data === null || data === undefined) return data
      
      const resolved = resolveFullType(schema, this.indexedSchema)
      if (!resolved) return data
      
      const kind = (resolved.kind || '').toLowerCase()

      // Handle OCTET STRING -> [byte, byte, ...]
      if (kind === 'octet_string' && typeof data === 'string') {
        const clean = data.replace(/[^0-9A-Fa-f]/g, '')
        const bytes = []
        for (let i = 0; i < clean.length; i += 2) {
          bytes.push(parseInt(clean.substring(i, i + 2), 16))
        }
        return bytes
      }

      // Handle BIT STRING -> { hex, bit_length }
      if (kind === 'bit_string') {
        if (typeof data === 'string') {
          const clean = data.replace(/[^0-9A-Fa-f]/g, '')
          return {
            hex: clean,
            bit_length: clean.length * 4
          }
        }
        if (data && typeof data === 'object' && data.hex !== undefined) {
          return {
            hex: data.hex.replace(/[^0-9A-Fa-f]/g, ''),
            bit_length: data.bit_length ?? (data.hex.length * 4)
          }
        }
      }

      // Handle SEQUENCE
      if (kind === 'sequence' && typeof data === 'object') {
        const result: any = {}
        for (const field of (resolved.fields || [])) {
          const key = getFieldKey(field)
          if (data[key] !== undefined) {
            result[key] = this.transformForEncoder(data[key], field)
          }
        }
        return result
      }

      // Handle SEQUENCE OF
      if (kind === 'sequence_of' && Array.isArray(data)) {
        const elSchema = { 
          kind: resolved.element_kind, 
          type_ref: resolved.element_type,
          ies: resolved.ies // Preserve IEs if present
        }
        return data.map(item => this.transformForEncoder(item, elSchema))
      }

      // Handle CHOICE
      if (kind === 'choice' && typeof data === 'object') {
        const key = Object.keys(data)[0]
        if (!key) return data
        const alt = (resolved.alternatives || []).find((a: any) => a.name === key)
        if (alt) {
          return { [key]: this.transformForEncoder(data[key], alt) }
        }
      }

      return data
    },
    async decodeHex(typeName: string, hex: string) {
      if (!this.sessionId) return null
      try {
        return await api.decode(this.sessionId, typeName, hex)
      } catch (e) {
        console.error('Sub-decode failed:', e)
        return null
      }
    },
    async encodeMessage() {
      if (!this.sessionId || !this.selectedType) return
      
      this.isEncoding = true
      this.error = null
      try {
        const rootSchema = lookupType(this.selectedType, this.indexedSchema)
        const transformedData = rootSchema ? this.transformForEncoder(this.messageData, rootSchema) : this.messageData

        const res = await api.encode(
          this.sessionId, 
          this.selectedType, 
          JSON.stringify(transformedData)
        )
        if (res.error) {
          this.error = res.error
        } else {
          this.encodedHex = res.hex || ''
          await this.decodeMessage()
        }
      } catch (e: any) {
        this.error = e.message || 'Encoding failed'
      } finally {
        this.isEncoding = false
      }
    },
    async decodeMessage() {
      if (!this.sessionId || !this.selectedType || !this.encodedHex) return

      this.isDecoding = true
      this.error = null
      try {
        const res = await api.decode(
          this.sessionId,
          this.selectedType,
          this.encodedHex
        )
        if (res.error) {
          this.error = res.error
          this.decodedData = null
        } else {
          this.decodedData = res
        }
      } catch (e: any) {
        this.error = e.message || 'Decoding failed'
      } finally {
        this.isDecoding = false
      }
    }
  }
})
