<script setup lang="ts">
import { computed } from 'vue'

const props = defineProps<{
  schema: any
  data: any
}>()

const emit = defineEmits(['update:data'])

const values = computed(() => props.schema.values || props.schema.enum_values || [])

const update = (e: Event) => {
  emit('update:data', (e.target as HTMLSelectElement).value)
}
</script>

<template>
  <select 
    :value="data || ''" 
    @change="update"
    class="w-full h-8 px-2 bg-white border border-slate-200 rounded text-xs focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none"
  >
    <option value="" disabled>— select enumeration —</option>
    <option v-for="v in values" :key="typeof v === 'string' ? v : v.name" :value="typeof v === 'string' ? v : v.name">
      {{ typeof v === 'string' ? v : v.name }}
    </option>
  </select>
</template>
