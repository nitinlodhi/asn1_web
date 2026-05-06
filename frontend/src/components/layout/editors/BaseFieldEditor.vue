<script setup lang="ts">
import { computed } from 'vue'

const props = defineProps<{
  kind: string
  data: any
  schema?: any
}>()

const emit = defineEmits(['update:data'])

const val = computed(() => props.data === undefined ? '' : props.data)

const isDefault = computed(() => {
  return props.schema?.default !== undefined && props.data === props.schema.default
})

const update = (e: Event) => {
  const v = (e.target as HTMLInputElement).value
  if (props.kind === 'integer') {
    emit('update:data', v === '' ? 0 : Number(v))
  } else {
    emit('update:data', v)
  }
}

const updateBool = (e: Event) => {
  emit('update:data', (e.target as HTMLSelectElement).value === 'true')
}
</script>

<template>
  <div class="w-full">
    <template v-if="kind === 'boolean'">
      <select 
        :value="String(val)" 
        @change="updateBool"
        class="w-full h-8 px-2 bg-white border border-slate-200 rounded text-xs focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none"
      >
        <option value="false">false</option>
        <option value="true">true</option>
      </select>
    </template>

    <template v-else-if="kind === 'integer'">
      <div class="relative">
        <input 
          type="number"
          :value="val"
          @input="update"
          class="w-full h-8 px-2 bg-white border border-slate-200 rounded text-xs focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none font-mono"
          :class="{ 'text-wireshark-blue font-bold': isDefault }"
        />
        <div v-if="isDefault" class="absolute right-2 top-1/2 -translate-y-1/2 text-[8px] bg-wireshark-light text-wireshark-blue px-1 rounded font-bold uppercase pointer-events-none">
          Default
        </div>
      </div>
    </template>

    <template v-else-if="kind === 'null'">
      <div class="h-8 flex items-center px-2 bg-slate-100 border border-slate-200 rounded text-xs text-slate-400 italic font-mono">
        NULL
      </div>
    </template>

    <template v-else>
      <div class="relative">
        <input 
          type="text"
          :value="typeof val === 'object' ? JSON.stringify(val) : val"
          @input="update"
          :placeholder="kind === 'octet_string' ? 'hex bytes (e.g. DE ADB E EF)' : kind"
          class="w-full h-8 px-2 bg-white border border-slate-200 rounded text-xs focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none font-mono"
          :class="{ 'text-wireshark-blue font-bold': isDefault }"
        />
        <div v-if="isDefault" class="absolute right-2 top-1/2 -translate-y-1/2 text-[8px] bg-wireshark-light text-wireshark-blue px-1 rounded font-bold uppercase pointer-events-none">
          Default
        </div>
      </div>
    </template>
  </div>
</template>
