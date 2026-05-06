<script setup lang="ts">
import { ChevronDown, ChevronRight, Hash, Square, Layers, List } from 'lucide-vue-next'
import { ref, computed } from 'vue'
import { useAsnStore } from '@/store/asn'
import { resolveFullType, getDataValue } from '@/schema-utils'

const props = defineProps<{
  label: string
  value: any
  schema?: any
  depth: number
}>()

const isOpen = ref(true)
const asnStore = useAsnStore()

const resolvedSchema = computed(() => {
  if (!props.schema) return null
  try {
    return resolveFullType(props.schema, asnStore.indexedSchema)
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

const hasChildren = computed(() => isObject.value || isArray.value)

const toggle = () => {
  if (hasChildren.value) {
    isOpen.value = !isOpen.value
  }
}

const displayValue = computed(() => {
  if (hasChildren.value) return ''
  if (props.value === null) return 'NULL'
  if (typeof props.value === 'boolean') return props.value ? 'True' : 'False'
  
  // Bit String / Octet String objects
  if (props.value && typeof props.value === 'object') {
    if (props.value.hex !== undefined) return props.value.hex
    return JSON.stringify(props.value)
  }
  
  return String(props.value)
})

const getIcon = computed(() => {
  if (isArray.value) return List
  if (isObject.value) return Layers
  if (typeof props.value === 'number') return Hash
  return Square
})

// Schema-Driven Children Calculation with robust fallbacks
const orderedChildren = computed(() => {
  if (!hasChildren.value) return []
  
  const schema = resolvedSchema.value
  const data = props.value

  // Fallback function: raw JSON iteration
  const getRawChildren = () => {
    if (isArray.value) return data.map((v: any, i: number) => ({ label: String(i), value: v }))
    return Object.entries(data).map(([k, v]) => ({ label: k, value: v }))
  }

  if (!schema) return getRawChildren()

  try {
    if (kind.value === 'sequence') {
      const children = []
      const fields = schema.fields || []
      
      for (const field of fields) {
        const val = getDataValue(data, field)
        if (val !== undefined) {
          children.push({
            label: field.name,
            value: val,
            schema: field
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
        schema: alt
      }]
    }

    if (kind.value === 'sequence_of') {
      const elSchema = { 
        kind: schema.element_kind, 
        type_ref: schema.element_type,
        ies: schema.ies
      }
      if (!Array.isArray(data)) return getRawChildren()
      return data.map((v: any, i: number) => ({
        label: String(i),
        value: v,
        schema: elSchema
      }))
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
      <div class="text-[11px] font-sans flex items-baseline gap-2 truncate">
        <span class="font-bold text-slate-700">{{ label }}:</span>
        <span v-if="!hasChildren" class="text-wireshark-blue font-mono">{{ displayValue }}</span>
        <span v-else class="text-slate-400 italic text-[10px]">
          {{ isArray ? `(${value.length} items)` : '' }}
        </span>
      </div>
    </div>

    <!-- Children -->
    <div v-if="hasChildren && isOpen">
      <TreeNode 
        v-for="(child, idx) in orderedChildren" 
        :key="idx"
        :label="child.label"
        :value="child.value"
        :schema="child.schema"
        :depth="depth + 1"
      />
    </div>
  </div>
</template>

<style scoped>
.tree-node:nth-child(even) > div {
  background-color: rgba(248, 250, 252, 0.5); /* zebra stripes */
}
</style>
