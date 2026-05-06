<script setup lang="ts">
import { ChevronDown, ChevronRight } from 'lucide-vue-next'
import { ref } from 'vue'
import { getFieldKey } from '@/schema-utils'
import AsnField from './AsnField.vue'

const props = defineProps<{
  fields: any[]
  data: any
  depth: number
}>()

const emit = defineEmits(['update:data'])

const openStates = ref<Record<string, boolean>>({})

const toggle = (key: string) => {
  openStates.value[key] = !openStates.value[key]
}

const isOpen = (key: string) => openStates.value[key] !== false

const updateField = (key: string, val: any) => {
  emit('update:data', { ...props.data, [key]: val })
}
</script>

<template>
  <div class="space-y-1">
    <div v-for="field in fields" :key="field.name" class="border rounded-sm bg-white overflow-hidden shadow-sm">
      <div 
        class="flex items-center gap-2 px-2 py-1.5 bg-slate-50 border-b cursor-pointer hover:bg-slate-100 select-none"
        @click="toggle(field.name)"
      >
        <component :is="isOpen(field.name) ? ChevronDown : ChevronRight" class="w-3.5 h-3.5 text-slate-400" />
        <span class="text-xs font-bold text-slate-700">{{ field.name }}</span>
        <span v-if="field.optional" class="text-[9px] bg-amber-100 text-amber-700 px-1 rounded font-bold uppercase">opt</span>
        <div class="flex-1"></div>
        <span class="text-[10px] text-slate-400 font-mono italic">{{ field.kind }}</span>
      </div>
      
      <div v-show="isOpen(field.name)" class="p-2 bg-white">
        <AsnField 
          :schema="field" 
          :data="data[getFieldKey(field)]" 
          :depth="depth + 1"
          @update:data="(val) => updateField(getFieldKey(field), val)"
        />
      </div>
    </div>
  </div>
</template>
