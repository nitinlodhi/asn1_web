<script setup lang="ts">
import { ref, watch, onUnmounted } from 'vue'
import { useAsnStore } from '@/store/asn'
import { Upload, Activity, Loader2, Clock } from 'lucide-vue-next'

const asnStore = useAsnStore()
const fileInput = ref<HTMLInputElement | null>(null)
const compilationSeconds = ref(0)
let timerInterval: number | null = null

const handleFileUpload = (e: Event) => {
  const file = (e.target as HTMLInputElement).files?.[0]
  if (file) {
    asnStore.compileSchema(file)
  }
}

const triggerUpload = () => {
  fileInput.value?.click()
}

// Timer logic
watch(() => asnStore.isCompiling, (isCompiling) => {
  if (isCompiling) {
    compilationSeconds.value = 0
    timerInterval = window.setInterval(() => {
      compilationSeconds.value++
    }, 1000)
  } else {
    if (timerInterval) {
      clearInterval(timerInterval)
      timerInterval = null
    }
  }
})

onUnmounted(() => {
  if (timerInterval) clearInterval(timerInterval)
})
</script>

<template>
  <nav class="h-12 bg-wireshark-blue text-white flex items-center px-4 gap-4 shadow-md z-10">
    <div class="flex items-center gap-2 font-bold text-lg mr-4">
      <Activity class="w-6 h-6" />
      <span>ASN.1 Compiler</span>
    </div>

    <div class="flex items-center gap-2">
      <select
        v-model="asnStore.encoding"
        :disabled="asnStore.isCompiling"
        class="px-2 py-1.5 rounded text-sm font-mono bg-white/10 hover:bg-white/20 text-white border border-white/20 cursor-pointer disabled:opacity-50"
        title="Encoding rules"
      >
        <option value="uper">UPER</option>
        <option value="aper">APER</option>
      </select>

      <button
        @click="triggerUpload"
        :disabled="asnStore.isCompiling"
        class="flex items-center gap-2 px-3 py-1.5 rounded text-sm font-bold transition-all shadow-sm"
        :class="asnStore.isCompiling 
          ? 'bg-amber-500 hover:bg-amber-600 text-white cursor-wait animate-pulse' 
          : 'bg-white/10 hover:bg-white/20 text-white active:scale-95'"
      >
        <Loader2 v-if="asnStore.isCompiling" class="w-4 h-4 animate-spin" />
        <Upload v-else class="w-4 h-4" />
        <span>{{ asnStore.isCompiling ? 'Compiling Schema...' : 'Upload ASN.1' }}</span>
      </button>

      <!-- Compilation Timer -->
      <div v-if="asnStore.isCompiling" class="flex items-center gap-1.5 px-2 py-1 bg-black/20 rounded text-[11px] font-mono border border-white/10">
        <Clock class="w-3 h-3 text-amber-300" />
        <span>{{ compilationSeconds }}s</span>
      </div>
    </div>
    
    <input 
      ref="fileInput" 
      type="file" 
      class="hidden" 
      accept=".asn,.asn1" 
      @change="handleFileUpload" 
    />

    <div v-if="asnStore.sessionId && !asnStore.isCompiling" class="text-[10px] text-white/50 font-mono flex items-center gap-2 bg-black/10 px-2 py-1 rounded">
      <span class="uppercase font-bold text-[9px] text-green-400/70">Session:</span>
      <span class="truncate max-w-[120px]">{{ asnStore.sessionId }}</span>
    </div>

    <div class="flex-1"></div>

    <div class="flex items-center gap-4 text-xs font-medium">
      <div class="flex items-center gap-2 px-3 py-1 rounded-full bg-black/10 border border-white/5">
        <div class="w-2 h-2 rounded-full" :class="asnStore.sessionId ? 'bg-green-400 shadow-[0_0_8px_rgba(74,222,128,0.5)]' : 'bg-slate-500'"></div>
        <span class="uppercase tracking-widest text-[9px] font-bold">{{ asnStore.sessionId ? 'Connected' : 'Disconnected' }}</span>
      </div>
    </div>
  </nav>
</template>
