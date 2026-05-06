<script setup lang="ts">
import { computed } from 'vue'
import { Plus, Trash2 } from 'lucide-vue-next'
import { isComplexType, lookupType } from '@/schema-utils'
import { useAsnStore } from '@/store/asn'
import AsnField from './AsnField.vue'

const props = defineProps<{
  schema: any
  data: any[]
  depth: number
}>()

const emit = defineEmits(['update:data'])
const asnStore = useAsnStore()

const items = computed(() => props.data || [])
const elKind = computed(() => (props.schema.element_kind || '').toLowerCase())
const elType = computed(() => props.schema.element_type || '')

// The schema to pass to the child AsnField for each item
const itemSchema = computed(() => ({
  kind: elKind.value,
  type_ref: elType.value
}))

const addItem = () => {
  let initVal: any = ''
  if (isComplexType(elKind.value)) {
    // If it's a complex type, try to get its defaults
    const resolvedEl = lookupType(elType.value, asnStore.indexedSchema)
    initVal = resolvedEl ? asnStore.getDefaults(resolvedEl) : {}
  }
  emit('update:data', [...items.value, initVal])
}

const removeItem = (idx: number) => {
  const newItems = [...items.value]
  newItems.splice(idx, 1)
  emit('update:data', newItems)
}

const updateItem = (idx: number, val: any) => {
  const newItems = [...items.value]
  newItems[idx] = val
  emit('update:data', newItems)
}
</script>

<template>
  <div class="space-y-2">
    <div v-for="(item, idx) in items" :key="idx" class="flex gap-2 items-start group">
      <div class="flex-1 p-2 border rounded-sm bg-slate-50/50 shadow-inner">
        <div class="flex items-center justify-between mb-2 px-1">
          <span class="text-[9px] font-bold text-slate-400 uppercase">Item #{{ idx + 1 }}</span>
          <span class="text-[9px] text-slate-300 font-mono">{{ elType || elKind }}</span>
        </div>
        <AsnField 
          :schema="itemSchema" 
          :data="item" 
          :depth="depth + 1"
          @update:data="(val) => updateItem(idx, val)"
        />
      </div>
      <button 
        @click="removeItem(idx)"
        class="mt-8 p-1 text-slate-400 hover:text-red-600 transition-colors"
        title="Remove Item"
      >
        <Trash2 class="w-3.5 h-3.5" />
      </button>
    </div>

    <button 
      @click="addItem"
      class="w-full py-1.5 border border-dashed border-slate-300 rounded flex items-center justify-center gap-2 text-[10px] font-bold text-slate-500 hover:border-wireshark-blue hover:text-wireshark-blue transition-colors bg-white shadow-sm"
    >
      <Plus class="w-3 h-3" />
      ADD {{ (elType || elKind).toUpperCase() }} ITEM
    </button>
  </div>
</template>
