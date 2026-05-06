<script setup lang="ts">
import { computed } from 'vue'

const props = defineProps<{
  hex: string
}>()

const bytes = computed(() => {
  const cleanHex = props.hex.replace(/\s/g, '')
  const result = []
  for (let i = 0; i < cleanHex.length; i += 2) {
    result.push(cleanHex.substring(i, i + 2))
  }
  return result
})

const rows = computed(() => {
  const rowSize = 16
  const result = []
  for (let i = 0; i < bytes.value.length; i += rowSize) {
    const chunk = bytes.value.slice(i, i + rowSize)
    const offset = i.toString(16).padStart(4, '0').toUpperCase()
    
    // Hex display
    const hexParts = chunk.map(b => b.toUpperCase())
    
    // ASCII display
    const asciiParts = chunk.map(b => {
      const charCode = parseInt(b, 16)
      return (charCode >= 32 && charCode <= 126) ? String.fromCharCode(charCode) : '.'
    })
    
    result.push({
      offset,
      hex: hexParts,
      ascii: asciiParts.join('')
    })
  }
  return result
})
</script>

<template>
  <div class="font-mono text-[11px] leading-relaxed select-text">
    <div v-for="row in rows" :key="row.offset" class="flex gap-4 hover:bg-white/5 py-0.5 px-1 rounded transition-colors group">
      <!-- Offset -->
      <span class="text-slate-500 font-bold w-10 flex-shrink-0">{{ row.offset }}</span>
      
      <!-- Hex Grid -->
      <div class="flex gap-1.5 flex-1 min-w-[380px]">
        <div v-for="(byte, idx) in row.hex" :key="idx" class="w-5 text-center group-hover:text-green-300">
          {{ byte }}
        </div>
        <!-- Padding for short rows -->
        <div v-for="i in (16 - row.hex.length)" :key="'pad-'+i" class="w-5"></div>
      </div>
      
      <!-- ASCII -->
      <span class="text-slate-400 border-l border-slate-700 pl-4 w-32 flex-shrink-0">
        {{ row.ascii }}
      </span>
    </div>
    
    <div v-if="bytes.length === 0" class="text-slate-600 italic">
      No data to display in grid.
    </div>
  </div>
</template>
