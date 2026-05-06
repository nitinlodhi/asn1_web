<script setup lang="ts">
import { useAsnStore } from '@/store/asn'
import { TreeDeciduous, Terminal, Info, Code, Bug } from 'lucide-vue-next'
import { computed, ref } from 'vue'
import { lookupType } from '@/schema-utils'
import TreeNode from './TreeNode.vue'

const asnStore = useAsnStore()
const showRaw = ref(false)

const rootSchema = computed(() => {
  if (!asnStore.selectedType) return null
  return lookupType(asnStore.selectedType, asnStore.indexedSchema)
})

const dataType = computed(() => {
  if (!asnStore.decodedData) return 'None'
  if (Array.isArray(asnStore.decodedData)) return `Array(${asnStore.decodedData.length})`
  return typeof asnStore.decodedData
})
</script>

<template>
  <div class="h-full flex flex-col overflow-hidden">
    <div class="p-3 border-b bg-slate-50 flex items-center justify-between shadow-sm">
      <div class="flex items-center gap-2">
        <TreeDeciduous class="w-4 h-4 text-wireshark-blue" />
        <h2 class="text-xs font-bold uppercase tracking-wider text-slate-500">Decoded Tree</h2>
      </div>
      
      <div class="flex items-center gap-2">
        <div v-if="asnStore.decodedData" class="text-[9px] bg-slate-200 text-slate-600 px-1.5 py-0.5 rounded font-mono">
          {{ dataType }}
        </div>
        <button 
          v-if="asnStore.decodedData"
          @click="showRaw = !showRaw"
          class="p-1 hover:bg-slate-200 rounded transition-colors text-slate-400"
          :class="{ 'text-wireshark-blue': showRaw }"
          title="Toggle Raw JSON"
        >
          <Code class="w-3.5 h-3.5" />
        </button>
        <div v-if="asnStore.decodedData" class="text-[10px] bg-green-100 text-green-700 px-2 py-0.5 rounded font-bold uppercase">
          Success
        </div>
      </div>
    </div>

    <div class="flex-1 overflow-y-auto bg-white custom-scrollbar">
       <!-- Empty State -->
       <div v-if="!asnStore.decodedData" class="h-full flex flex-col items-center justify-center text-slate-400 gap-3 p-6 text-center">
          <div class="p-4 bg-slate-50 rounded-full">
            <Terminal class="w-8 h-8 text-slate-200" />
          </div>
          <p class="text-xs italic leading-relaxed">
            Hex data will be decoded here.<br/>
            Select a type and press <b>ENCODE</b> or <b>DECODE</b>.
          </p>
       </div>

       <!-- Raw View Fallback/Debug -->
       <div v-else-if="showRaw" class="p-4">
          <pre class="text-[10px] font-mono text-slate-600 bg-slate-50 p-3 rounded border overflow-x-auto">
            {{ JSON.stringify(asnStore.decodedData, null, 2) }}
          </pre>
       </div>

       <!-- Tree View -->
       <div v-else class="py-2">
          <TreeNode 
            :label="asnStore.selectedType || 'Root'" 
            :value="asnStore.decodedData" 
            :schema="rootSchema"
            :depth="0" 
          />
          
          <div class="mt-8 px-4 py-2 flex items-start gap-2 text-[10px] text-slate-400 border-t border-slate-50 italic">
             <Info class="w-3 h-3 flex-shrink-0 mt-0.5" />
             <span>Click on labels to expand/collapse branches. Zebra stripes indicate field separation.</span>
          </div>
       </div>
    </div>
    
    <!-- Error Indicator -->
    <div v-if="asnStore.error" class="p-2 bg-red-50 border-t border-red-100 flex items-center gap-2 text-red-600 text-[10px]">
       <Bug class="w-3 h-3" />
       <span class="font-bold">Error:</span>
       <span class="truncate">{{ asnStore.error }}</span>
    </div>
  </div>
</template>

<style scoped>
.custom-scrollbar::-webkit-scrollbar {
  width: 6px;
}
.custom-scrollbar::-webkit-scrollbar-track {
  background: transparent;
}
.custom-scrollbar::-webkit-scrollbar-thumb {
  background: #e2e8f0;
  border-radius: 10px;
}
.custom-scrollbar::-webkit-scrollbar-thumb:hover {
  background: #cbd5e1;
}
</style>
