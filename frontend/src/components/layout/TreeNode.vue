<script setup lang="ts">
import { ChevronDown, ChevronRight, Hash, Square, Layers, List } from 'lucide-vue-next'
import { ref, computed, watch } from 'vue'
import { useAsnStore } from '@/store/asn'
import { resolveFullType, getDataValue } from '@/schema-utils'
import { inferAsnType } from '@/lib/type-inferrer'

const props = defineProps<{
  label: string
  value: any
  schema?: any
  depth: number
  parentData?: any
}>()

const isOpen = ref(true)
const asnStore = useAsnStore()
const decodedOpenType = ref<any>(null)
const isDecodingOpenType = ref(false)
const decodeError = ref<string | null>(null)
const showTypeSelector = ref(false)

const resolvedSchema = computed(() => {
  if (!props.schema) return null
  try {
    const res = resolveFullType(props.schema, asnStore.indexedSchema)
    // If it's a generic ANY/TYPE, mark it so we can show the manual override button
    if (res && (res.type_ref === 'TYPE' || res.name === 'TYPE' || res.kind === 'any')) {
       res.isOpenType = true
    }
    return res
  } catch (e) {
    console.error('Schema resolution failed:', e)
    return null
  }
})

const kind = computed(() => (resolvedSchema.value?.kind || '').toLowerCase())

const isObject = computed(() => {
  return typeof props.value === 'object' && props.value !== null && !Array.isArray(props.value)
})

const isArray = computed(() => Array.isArray(props.value))

// Check if this is a BitString that should be decoded as an OpenType
const isOpenTypeBitString = computed(() => {
  const schema = resolvedSchema.value
  if (!schema) return false
  
  // Support both BitString {hex, bit_length} and OctetString [byte, byte, ...]
  const hasHex = isObject.value && props.value.hex
  const isByteArray = isArray.value && props.value.length > 0 && typeof props.value[0] === 'number'
  
  if (!hasHex && !isByteArray) return false
  
  // 1. Generic OpenType markers
  if (schema.kind === 'alias' && schema.type_ref === 'TYPE') return true
  if (schema.kind === 'any') return true
  
  // 2. Specific type resolved but we still have hex data (meaning it's an OpenType)
  // We check if it's a complex type or if it was explicitly requested via type_ref
  const kind = (schema.kind || '').toLowerCase()
  const isComplex = [`sequence`, `choice`, `sequence_of`, `enumeration`].includes(kind)
  
  if (isComplex) return true
  
  // 3. Check for specific type names that are not BitString/OctetString
  const typeRef = props.schema?.type_ref || schema?.key || schema?.name
  if (typeRef && typeRef !== 'TYPE' && !typeRef.includes('BitString') && !typeRef.includes('OctetString')) {
     return true
  }
  
  return false
})

const resolvedData = computed(() => {
  if (decodedOpenType.value) return decodedOpenType.value
  return props.value
})

const tryDecodeOpenType = async (manualType?: string) => {
  if (!isOpenTypeBitString.value || (decodedOpenType.value && !manualType) || isDecodingOpenType.value) return
  
  const schema = resolvedSchema.value
  let typeRef = manualType || schema?.key || schema?.type_ref
  
  // Attempt to infer the specific type if it's a generic OpenType (TYPE/ANY)
  if (!typeRef || typeRef === 'TYPE') {
     const inferred = inferAsnType(props.parentData, schema)
     if (inferred) {
        console.log(`[DEBUG] Inferred type for ${props.label}: ${inferred}`)
        typeRef = inferred
     }
  }

  let hexToDecode = ''
  if (props.value.hex) {
    hexToDecode = props.value.hex
    // Truncate hex if it has extra bits that might cause constraint violations in the harness
    if (props.value.bit_length !== undefined) {
      const byteLen = Math.ceil(props.value.bit_length / 8)
      if (hexToDecode.length > byteLen * 2) {
        console.log(`[DEBUG] Truncating hex for ${props.label} from ${hexToDecode.length} to ${byteLen * 2} nibbles (bit_length: ${props.value.bit_length})`)
        hexToDecode = hexToDecode.substring(0, byteLen * 2)
      }
    }
  } else if (Array.isArray(props.value)) {
    hexToDecode = props.value.map((b: number) => b.toString(16).padStart(2, '0')).join('')
  }

  if (!typeRef || typeRef === 'TYPE') {
     console.warn(`[DEBUG] Cannot sub-decode ${props.label}: no typeRef and inference failed`)
     decodeError.value = "Unable to infer type. Please select manually."
     return
  }

  console.log(`[DEBUG] Attempting sub-decode for ${props.label}. type: ${typeRef}, hex: ${hexToDecode}`)
  
  isDecodingOpenType.value = true
  decodeError.value = null
  try {
    const res = await asnStore.decodeHex(typeRef, hexToDecode)
    console.log(`[DEBUG] Sub-decode result for ${props.label}:`, res)
    if (res && !res.error) {
      // If the result is just a wrapper {"result": ...}, unwrap it
      if (typeof res === 'object' && res !== null && 'result' in res && Object.keys(res).length === 1) {
        decodedOpenType.value = res.result
      } else {
        decodedOpenType.value = res
      }
      showTypeSelector.value = false
    } else {
       decodeError.value = res?.error || "Decoding failed"
    }
  } catch (e: any) {
    console.error('[DEBUG] Failed to decode open type:', e)
    decodeError.value = e.message || "Decoding error"
  } finally {
    isDecodingOpenType.value = false
  }
}

// Auto-decode if it's an OpenType
watch(() => isOpenTypeBitString.value, (val) => {
  if (val) tryDecodeOpenType()
}, { immediate: true })

const hasChildren = computed(() => {
  if (decodedOpenType.value !== null) {
     // If it's a simple value (number, string, bool), it doesn't have children to show
     if (typeof decodedOpenType.value !== 'object') return false
     return true
  }
  if (isArray.value) return props.value.length > 0
  if (isObject.value) {
     if (props.value.hex !== undefined && !isOpenTypeBitString.value) return false
     return Object.keys(props.value).length > 0
  }
  return false
})

const toggle = () => {
  if (hasChildren.value) {
    isOpen.value = !isOpen.value
  }
}

const displayValue = computed(() => {
  if (hasChildren.value && !isOpenTypeBitString.value) return ''
  
  // If we decoded an OpenType and it's a simple value, show it
  if (decodedOpenType.value !== null && typeof decodedOpenType.value !== 'object') {
    return String(decodedOpenType.value)
  }

  if (props.value === null) return 'NULL'
  if (typeof props.value === 'boolean') return props.value ? 'True' : 'False'
  
  // ENUMERATED resolution
  if (resolvedSchema.value?.kind === 'enumeration' && resolvedSchema.value.values) {
    const vals = resolvedSchema.value.values
    if (typeof props.value === 'string') {
      const idx = vals.indexOf(props.value)
      if (idx !== -1) return `${props.value} (${idx})`
    }
    if (typeof props.value === 'number' && vals[props.value]) {
      return `${vals[props.value]} (${props.value})`
    }
  }

  // Bit String / Octet String objects
  if (props.value && typeof props.value === 'object') {
    if (props.value.hex !== undefined) {
       // Specialized decoding for IP addresses in Bit Strings
       if (props.value.bit_length === 32) {
          const hex = props.value.hex
          const octets = []
          for (let i = 0; i < 8; i += 2) octets.push(parseInt(hex.substring(i, i + 2), 16))
          return `${hex.toUpperCase()} (IPv4: ${octets.join('.')})`
       }
       if (props.value.bit_length === 128) {
          const hex = props.value.hex
          const groups = []
          for (let i = 0; i < 32; i += 4) groups.push(hex.substring(i, i + 4))
          return `${hex.toUpperCase()} (IPv6: ${groups.join(':')})`
       }
       return props.value.hex.toUpperCase()
    }
    return JSON.stringify(props.value)
  }
  
  return String(props.value)
})

const getIcon = computed(() => {
  if (isArray.value) return List
  if (isObject.value || decodedOpenType.value) return Layers
  if (typeof props.value === 'number') return Hash
  return Square
})

// Schema-Driven Children Calculation with robust fallbacks
const orderedChildren = computed(() => {
  if (!hasChildren.value) return []
  
  const schema = resolvedSchema.value
  const data = resolvedData.value

  // Fallback function: raw JSON iteration
  const getRawChildren = (): { label: string, value: any, schema?: any, parentData?: any }[] => {
    if (Array.isArray(data)) return data.map((v: any, i: number) => ({ label: String(i), value: v, parentData: data }))
    if (typeof data === 'object' && data !== null) {
      return Object.entries(data).map(([k, v]) => ({ label: k, value: v, parentData: data }))
    }
    return []
  }

  if (!schema || (decodedOpenType.value && !schema.fields)) return getRawChildren()

  try {
    if (kind.value === 'sequence') {
      const children: { label: string, value: any, schema?: any, parentData?: any }[] = []
      const fields = schema.fields || []
      
      for (const field of fields) {
        const val = getDataValue(data, field)
        if (val !== undefined) {
          let fieldSchema = field
          let label = field.name
          let finalVal = val
          
          // Special handling for ProtocolIE-Field resolution
          const idField = fields.find((f: any) => f.name === 'id')
          const idVal = idField ? getDataValue(data, idField) : undefined
          
          if (schema.ies && idVal !== undefined) {
            const ie = schema.ies.find((ie: any) => ie.id === idVal)
            if (ie) {
              if (field.name === 'value') {
                fieldSchema = { ...field, type_ref: ie.type, name: ie.type }
                // Use the type name as the label for the value container to match Wireshark style
                label = ie.type
              } else if (field.name === 'id') {
                finalVal = `${ie.id_name || ie.id} (${val})`
              }
            }
          }

          children.push({
            label: label,
            value: finalVal,
            schema: { ...fieldSchema, parentLabel: props.label },
            parentData: data
          })
        }
      }
      
      // If we found NO children via schema but data is not empty, fallback to raw
      if (children.length === 0 && Object.keys(data).length > 0) {
        return getRawChildren()
      }
      
      return children
    }

    if (kind.value === 'choice') {
      const keys = Object.keys(data)
      if (keys.length === 0) return []
      const key = keys[0]
      // Search for the key in alternatives with fuzzy matching
      const alt = (schema.alternatives || []).find((a: any) => {
        const altKey = a.name
        return altKey === key || altKey.replace(/-/g, '_') === key || altKey === key.replace(/-/g, '_')
      })
      
      return [{
        label: alt?.name || key,
        value: data[key],
        schema: { ...alt, parentLabel: props.label },
        parentData: data
      }]
    }

    if (kind.value === 'sequence_of') {
      const elSchema = { 
        kind: schema.element_kind, 
        type_ref: schema.element_type,
        ies: schema.ies,
        parentLabel: props.label
      }
      if (!Array.isArray(data)) return getRawChildren()
      return data.map((v: any, i: number) => {
        let label = String(i)
        if (schema.ies && v && v.id !== undefined) {
          const ie = schema.ies.find((ie: any) => ie.id === v.id)
          if (ie) {
            label = `Item ${i}: ${ie.id_name || ie.id}`
          }
        }
        return {
          label: label,
          value: v,
          schema: elSchema,
          parentData: data
        }
      })
    }
  } catch (e) {
    console.error('Error calculating ordered children:', e)
  }

  return getRawChildren()
})
</script>

<template>
  <div class="tree-node">
    <div 
      class="flex items-center py-0.5 px-2 hover:bg-wireshark-blue/10 cursor-pointer select-none group border-b border-slate-50"
      @click="toggle"
    >
      <!-- Indent -->
      <div v-for="i in depth" :key="i" class="w-4 flex-shrink-0"></div>
      
      <!-- Toggle Icon -->
      <div class="w-4 h-4 flex items-center justify-center flex-shrink-0">
        <template v-if="hasChildren && orderedChildren.length > 0">
          <ChevronDown v-if="isOpen" class="w-3 h-3 text-slate-400" />
          <ChevronRight v-else class="w-3 h-3 text-slate-400" />
        </template>
      </div>

      <!-- Type Icon -->
      <component :is="getIcon" class="w-3 h-3 mr-2 text-slate-400" />

      <!-- Label & Value -->
      <div class="text-[11px] font-sans flex items-baseline gap-2 truncate flex-1">
        <span class="font-bold text-slate-700">{{ label }}:</span>
        <span v-if="!hasChildren" class="text-wireshark-blue font-mono">{{ displayValue }}</span>
        <span v-else class="text-slate-400 italic text-[10px] flex-1 truncate">
          {{ isArray ? `(${resolvedData.length} items)` : '' }}
          {{ resolvedSchema?.name && !label.includes(resolvedSchema.name) && resolvedSchema.name !== 'ProtocolIE_Field' ? resolvedSchema.name : '' }}
          <span v-if="isOpenTypeBitString && !decodedOpenType" class="ml-2 text-amber-600 not-italic font-bold bg-amber-50 px-1 rounded border border-amber-200">
             [NOT DECODED]
          </span>
        </span>
      </div>

      <!-- Manual Decode Button for OpenTypes -->
      <button 
        v-if="isOpenTypeBitString" 
        @click.stop="showTypeSelector = !showTypeSelector"
        class="opacity-0 group-hover:opacity-100 px-1.5 py-0.5 rounded bg-slate-100 hover:bg-wireshark-blue hover:text-white text-[9px] font-bold transition-all mr-2 uppercase tracking-tighter"
        title="Manually select type for decoding"
      >
        {{ decodedOpenType ? 'Change Type' : 'Decode As...' }}
      </button>
    </div>

    <!-- Manual Type Selector Overlay -->
    <div v-if="showTypeSelector" class="ml-12 mr-4 my-1 p-2 bg-white border-2 border-wireshark-blue/30 rounded-lg shadow-xl z-20">
       <div class="text-[10px] font-bold text-wireshark-blue uppercase mb-2 flex justify-between items-center">
          <span>Manual Type Override</span>
          <button @click="showTypeSelector = false" class="text-slate-400 hover:text-red-500 text-sm">&times;</button>
       </div>
       <select 
          class="w-full p-1 text-[11px] font-mono border rounded bg-slate-50 focus:ring-2 focus:ring-wireshark-blue/50 outline-none mb-2"
          @change="(e) => tryDecodeOpenType((e.target as HTMLSelectElement).value)"
       >
          <option value="">— Select ASN.1 Type —</option>
          <option v-for="t in asnStore.types" :key="t" :value="t">{{ t }}</option>
       </select>
       <div v-if="decodeError" class="text-[10px] text-red-500 font-mono mt-1 bg-red-50 p-1 border border-red-100 rounded truncate" :title="decodeError">
          Error: {{ decodeError }}
       </div>
       <div v-if="isDecodingOpenType" class="text-[9px] text-amber-500 italic mt-1 animate-pulse">
          Decoding bitstream...
       </div>
    </div>

    <!-- Children -->
    <div v-if="hasChildren && isOpen">
      <!-- Specialized level for ProtocolIE-Field if it's an item in a container -->
      <div v-if="resolvedSchema?.name === 'ProtocolIE_Field' && label.startsWith('Item')" class="bg-slate-50/50 py-0.5 border-l-2 border-wireshark-blue/20 ml-4">
         <div class="px-2 text-[9px] uppercase tracking-widest text-slate-400 font-bold">ProtocolIE-Field</div>
      </div>
      
      <TreeNode 
        v-for="(child, idx) in orderedChildren" 
        :key="idx"
        :label="child.label"
        :value="child.value"
        :schema="child.schema"
        :depth="depth + 1"
        :parentData="child.parentData"
      />
    </div>
  </div>
</template>

<style scoped>
.tree-node:nth-child(even) > div {
  background-color: rgba(248, 250, 252, 0.5); /* zebra stripes */
}
</style>
