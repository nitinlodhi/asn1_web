<script setup lang="ts">
import { computed } from 'vue'
import { useAsnStore } from '@/store/asn'
import { resolveFullType } from '@/schema-utils'
import AsnField from './AsnField.vue'

const props = defineProps<{
  schema: any
  data: any
  depth: number
}>()

const emit = defineEmits(['update:data'])

const asnStore = useAsnStore()

const alternatives = computed(() => props.schema.alternatives || [])
const selectedKey = computed(() => props.data ? Object.keys(props.data)[0] : '')

const selectAlternative = (name: string) => {
  const alt = alternatives.value.find((a: any) => a.name === name)
  const resolved = resolveFullType(alt, asnStore.indexedSchema)
  
  let initVal: any = ''
  const kind = (resolved?.kind || '').toLowerCase()
  
  if (kind === 'integer') initVal = 0
  else if (kind === 'boolean') initVal = false
  else if (kind === 'null') initVal = null
  else if (kind === 'sequence' || kind === 'sequence_of') initVal = kind === 'sequence_of' ? [] : {}
  
  emit('update:data', { [name]: initVal })
}

const updateValue = (val: any) => {
  emit('update:data', { [selectedKey.value]: val })
}

const selectedAlt = computed(() => alternatives.value.find((a: any) => a.name === selectedKey.value))
</script>

<template>
  <div class="space-y-3">
    <div class="flex flex-wrap gap-2">
      <button 
        v-for="alt in alternatives" 
        :key="alt.name"
        @click="selectAlternative(alt.name)"
        class="px-2 py-1 text-[10px] font-bold rounded border transition-colors"
        :class="selectedKey === alt.name 
          ? 'bg-wireshark-blue text-white border-wireshark-blue' 
          : 'bg-white text-slate-600 border-slate-200 hover:border-wireshark-blue/50'"
      >
        {{ alt.name }}
      </button>
    </div>

    <div v-if="selectedAlt" class="pl-3 border-l-2 border-wireshark-blue/20 py-1">
      <AsnField 
        :schema="selectedAlt" 
        :data="data[selectedKey]" 
        :depth="depth + 1"
        @update:data="updateValue"
      />
    </div>
    <div v-else class="text-[10px] text-slate-400 italic">
      Select a choice alternative...
    </div>
  </div>
</template>
