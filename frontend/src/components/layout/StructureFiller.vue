<script setup lang="ts">
import { computed } from 'vue'
import { useAsnStore } from '@/store/asn'
import { FileEdit, Play, Loader2 } from 'lucide-vue-next'
import { lookupType } from '@/schema-utils'
import AsnField from './editors/AsnField.vue'

const asnStore = useAsnStore()

const rootSchema = computed(() => {
  if (!asnStore.selectedType) return null
  return lookupType(asnStore.selectedType, asnStore.indexedSchema)
})

const updateMessage = (val: any) => {
  asnStore.updateMessageData(val)
}
</script>

<template>
  <div class="h-full flex flex-col">
    <div class="p-3 border-b bg-slate-50 flex items-center justify-between">
      <div class="flex items-center gap-2 overflow-hidden mr-2">
        <FileEdit class="w-4 h-4 text-wireshark-blue flex-shrink-0" />
        <h2 class="text-xs font-bold uppercase tracking-wider text-slate-500 whitespace-nowrap">Structure Filler</h2>
        <span class="text-[10px] px-2 py-0.5 bg-wireshark-blue text-white rounded font-mono truncate">{{ asnStore.selectedType }}</span>
      </div>
      
      <button 
        @click="asnStore.encodeMessage"
        :disabled="asnStore.isEncoding"
        class="flex items-center gap-1 px-3 py-1 bg-green-600 hover:bg-green-700 disabled:bg-slate-300 text-white text-xs font-bold rounded shadow-sm transition-colors flex-shrink-0"
      >
        <Loader2 v-if="asnStore.isEncoding" class="w-3 h-3 animate-spin" />
        <Play v-else class="w-3 h-3 fill-current" />
        ENCODE
      </button>
    </div>

    <div class="flex-1 p-4 overflow-y-auto">
      <div v-if="asnStore.isCompiling" class="h-full flex flex-col items-center justify-center text-slate-400 gap-4 animate-pulse">
        <div class="p-6 bg-slate-50 rounded-full">
           <Loader2 class="w-12 h-12 animate-spin text-wireshark-blue" />
        </div>
        <p class="text-xs font-bold uppercase tracking-widest">Building Harness...</p>
        <p class="text-[10px] italic">This may take up to 90 seconds for large schemas</p>
      </div>

      <div v-else-if="rootSchema" class="max-w-3xl mx-auto pb-20">
        <AsnField 
          :schema="rootSchema" 
          :data="asnStore.messageData" 
          :depth="0"
          @update:data="updateMessage"
        />
      </div>
      
      <div v-else class="h-full flex flex-col items-center justify-center text-slate-400 gap-2">
        <div class="p-8 border-2 border-dashed border-slate-200 rounded-lg">
           Select a type from the browser to start filling its structure.
        </div>
      </div>
    </div>
  </div>
</template>
