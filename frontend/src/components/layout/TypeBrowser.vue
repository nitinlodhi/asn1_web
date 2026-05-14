<script setup lang="ts">
import { useAsnStore } from '@/store/asn'
import { Box, Search } from 'lucide-vue-next'
import { ref, computed } from 'vue'

const asnStore = useAsnStore()
const filter = ref('')
const showAll = ref(false)

const filteredTypes = computed(() => {
  const baseList = (showAll.value ? asnStore.types : asnStore.messageTypes) || []
  // Exclude internal containers that are usually not used directly
  const filtered = baseList.filter(t => !t.includes('ProtocolIE-Field') && !t.includes('ProtocolExtensionField') && !t.includes('PrivateIE-Field'))
  
  if (!filter.value) return filtered
  return filtered.filter((t: string) => t.toLowerCase().includes(filter.value.toLowerCase()))
})
</script>

<template>
  <div class="h-full flex flex-col">
    <div class="p-3 border-b bg-slate-50">
      <div class="flex items-center justify-between mb-2">
        <h2 class="text-xs font-bold uppercase tracking-wider text-slate-500">ASN.1 Types</h2>
        <label class="flex items-center gap-1 cursor-pointer">
          <input type="checkbox" v-model="showAll" class="w-3 h-3" />
          <span class="text-[10px] text-slate-400">Show All</span>
        </label>
      </div>
      <div class="relative">
        <Search class="absolute left-2 top-1/2 -translate-y-1/2 w-3 h-3 text-slate-400" />
        <input 
          v-model="filter"
          placeholder="Filter types..."
          class="w-full pl-7 pr-2 py-1 bg-white border rounded text-xs focus:ring-1 focus:ring-wireshark-blue focus:border-wireshark-blue outline-none"
        />
      </div>
    </div>
    
    <div class="flex-1 overflow-y-auto">
      <div v-if="asnStore.types.length === 0" class="p-4 text-center text-slate-400 text-xs italic">
        No schema loaded
      </div>
      <ul v-else class="py-1">
        <li v-for="type in filteredTypes" :key="type">
          <button 
            @click="asnStore.selectType(type)"
            class="w-full text-left px-3 py-2 text-xs flex items-center gap-2 transition-colors border-l-2"
            :class="asnStore.selectedType === type 
              ? 'bg-wireshark-light border-wireshark-blue text-wireshark-blue font-semibold' 
              : 'hover:bg-slate-50 border-transparent text-slate-700'"
          >
            <Box class="w-3 h-3 flex-shrink-0" />
            <span class="truncate" :title="type">{{ type }}</span>
          </button>
        </li>
      </ul>
    </div>
  </div>
</template>
