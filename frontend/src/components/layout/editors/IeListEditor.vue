<script setup lang="ts">
import { computed } from 'vue'
import AsnField from './AsnField.vue'

const props = defineProps<{
  ies: any[]
  data: any
  depth: number
}>()

const emit = defineEmits(['update:data'])

const safeData = computed(() => Array.isArray(props.data) ? props.data : [])

const toggleIe = (ie: any, enabled: boolean) => {
  if (enabled) {
    if (!safeData.value.find((it: any) => it.id === ie.id)) {
      emit('update:data', [...safeData.value, { id: ie.id, criticality: ie.criticality, value: { [ie.type]: "" } }])
    }
  } else {
    emit('update:data', safeData.value.filter((it: any) => it.id !== ie.id))
  }
}

const updateIeValue = (id: any, type: string, val: any) => {
  emit('update:data', safeData.value.map((it: any) => (it.id === id ? { ...it, value: { [type]: val } } : it)))
}

const isEnabled = (id: any) => !!safeData.value.find((it: any) => it.id === id)
const getIeData = (id: any, type: string) => {
  const entry = safeData.value.find((it: any) => it.id === id)
  return entry?.value?.[type]
}
</script>

<template>
  <div class="space-y-3 p-2 bg-slate-50 border rounded border-slate-200 shadow-inner">
    <div class="flex items-center justify-between mb-1">
      <span class="text-[10px] font-bold text-slate-500 uppercase">Information Elements ({{ ies.length }})</span>
      <span class="text-[9px] text-slate-400 italic">Toggle to include in message</span>
    </div>
    
    <div class="space-y-3 divide-y divide-slate-200">
      <div v-for="ie in ies" :key="ie.id" class="pt-2">
        <div class="flex items-center gap-2 group mb-2">
          <input 
            type="checkbox" 
            :id="`ie-${ie.id}`"
            :checked="isEnabled(ie.id)"
            @change="(e) => toggleIe(ie, (e.target as HTMLInputElement).checked)"
            class="w-3.5 h-3.5 rounded border-slate-300 text-wireshark-blue focus:ring-wireshark-blue cursor-pointer"
          />
          <label 
            :for="`ie-${ie.id}`" 
            class="text-xs font-semibold cursor-pointer select-none group-hover:text-wireshark-blue transition-colors"
          >
            {{ ie.id_name || ie.id }}
          </label>
          <span 
            class="text-[9px] px-1 rounded font-bold uppercase"
            :class="ie.criticality === 'mandatory' ? 'bg-green-100 text-green-700' : 'bg-slate-200 text-slate-500'"
          >
            {{ ie.criticality }}
          </span>
          <div class="flex-1"></div>
          <span class="text-[9px] text-slate-400 font-mono">{{ ie.type }}</span>
        </div>

        <div v-if="isEnabled(ie.id)" class="pl-6 pb-2">
          <AsnField 
            :schema="{ type_ref: ie.type }" 
            :data="getIeData(ie.id, ie.type)" 
            :depth="depth + 1"
            @update:data="(val) => updateIeValue(ie.id, ie.type, val)"
          />
        </div>
      </div>
    </div>
  </div>
</template>
