<script setup lang="ts">
import { computed, ref, watch } from 'vue'

const props = defineProps<{
  data: any // Can be string or { hex, bit_length }
  label?: string
  schema?: any
}>()

const emit = defineEmits(['update:data'])

// Normalize incoming data
const getInitialHex = () => {
  if (typeof props.data === 'string') return props.data
  if (props.data && typeof props.data === 'object') return props.data.hex || ''
  return ''
}

const getInitialBitLength = () => {
  if (props.data && typeof props.data === 'object' && props.data.bit_length !== undefined) {
    return props.data.bit_length
  }
  const hex = getInitialHex()
  return hex.length * 4
}

const innerHex = ref(getInitialHex())
const innerBitLength = ref(getInitialBitLength())
const isBitString = computed(() => props.schema?.kind?.toLowerCase() === 'bit_string')

const isDefault = computed(() => {
  // Complex default check if it's an object
  if (props.schema?.default === undefined) return false
  if (typeof props.data === 'string') return props.data === props.schema.default
  return props.data?.hex === props.schema.default?.hex && props.data?.bit_length === props.schema.default?.bit_length
})

const formattedValue = computed({
  get: () => {
    const clean = innerHex.value.replace(/[^0-9A-Fa-f]/g, '')
    const parts = []
    for (let i = 0; i < clean.length; i += 2) {
      parts.push(clean.substring(i, i + 2))
    }
    return parts.join(' ').toUpperCase()
  },
  set: (val: string) => {
    const clean = val.replace(/[^0-9A-Fa-f]/g, '')
    innerHex.value = clean
    updateParent()
  }
})

const updateParent = () => {
  if (isBitString.value) {
    emit('update:data', {
      hex: innerHex.value,
      bit_length: innerBitLength.value
    })
  } else {
    emit('update:data', innerHex.value)
  }
}

const handleBitLengthInput = (e: Event) => {
  const val = parseInt((e.target as HTMLInputElement).value)
  innerBitLength.value = isNaN(val) ? innerHex.value.length * 4 : val
  updateParent()
}

// Auto-calculate bit length when hex changes, but only if it hasn't been manually overridden?
// Actually, let's just provide a "Recalculate" button or just let user override.
// For simplicity, if hex length changes and bit length was exactly 4*old_hex, update it.
watch(innerHex, (newHex, oldHex) => {
  if (isBitString.value) {
    if (innerBitLength.value === oldHex.length * 4) {
      innerBitLength.value = newHex.length * 4
      updateParent()
    }
  }
})

const byteCount = computed(() => {
  return Math.ceil(innerHex.value.length / 2)
})
</script>

<template>
  <div class="space-y-1">
    <div class="flex items-center justify-between px-1">
      <span class="text-[9px] text-slate-400 font-bold uppercase">{{ label || 'Hex Bytes' }}</span>
      <div class="flex items-center gap-3">
        <span v-if="isDefault" class="text-[8px] bg-wireshark-light text-wireshark-blue px-1 rounded font-bold uppercase">Default</span>
        
        <!-- Bit Length Input for BIT STRING -->
        <div v-if="isBitString" class="flex items-center gap-1 border-l pl-2 border-slate-200">
          <span class="text-[9px] text-slate-400 uppercase font-bold">Bits:</span>
          <input 
            type="number" 
            :value="innerBitLength"
            @input="handleBitLengthInput"
            class="w-10 bg-transparent text-[10px] font-mono text-wireshark-blue font-bold outline-none border-b border-transparent focus:border-wireshark-blue/30"
          />
        </div>

        <span class="text-[9px] text-wireshark-blue font-mono">{{ byteCount }} bytes</span>
      </div>
    </div>
    <div class="relative group">
      <textarea 
        v-model="formattedValue"
        rows="2"
        placeholder="e.g. DE AD BE EF"
        class="w-full p-2 bg-slate-50 border border-slate-200 rounded text-xs font-mono focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none resize-none transition-all group-hover:border-slate-300"
        :class="{ 'text-wireshark-blue font-bold': isDefault }"
        spellcheck="false"
      ></textarea>
      <div class="absolute bottom-1 right-2 text-[8px] text-slate-300 pointer-events-none group-focus-within:opacity-0 transition-opacity">
        HEX ONLY
      </div>
    </div>
  </div>
</template>
