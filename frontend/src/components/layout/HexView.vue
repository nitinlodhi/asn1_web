<script setup lang="ts">
import { Binary, Copy, Check, Play, Loader2, LayoutGrid, Type, Search, ChevronDown } from 'lucide-vue-next'
import { ref, computed, onMounted, onUnmounted, nextTick } from 'vue'
import { useAsnStore } from '@/store/asn'
import HexGrid from './HexGrid.vue'

const asnStore = useAsnStore()
const copied = ref(false)
const viewMode = ref<'grid' | 'text'>('grid')
const showTypeSearch = ref(false)
const typeFilter = ref('')
const searchInput = ref<HTMLInputElement | null>(null)
const triggerButton = ref<HTMLElement | null>(null)
const dropdownStyle = ref({})

const copyHex = () => {
  if (!asnStore.encodedHex) return
  navigator.clipboard.writeText(asnStore.encodedHex)
  copied.value = true
  setTimeout(() => copied.value = false, 2000)
}

const handleHexInput = (e: Event) => {
  const val = (e.target as HTMLTextAreaElement).value
  // Keep only hex chars for the store, but allow whitespace in the textarea for readability
  asnStore.updateHex(val.replace(/[^0-9A-Fa-f]/g, ''))
}

// Display hex with spaces for the textarea
const hexWithSpaces = computed(() => {
  const clean = asnStore.encodedHex.replace(/[^0-9A-Fa-f]/g, '')
  const parts = []
  for (let i = 0; i < clean.length; i += 2) {
    parts.push(clean.substring(i, i + 2))
  }
  return parts.join(' ').toUpperCase()
})

const filteredTypes = computed(() => {
  if (!typeFilter.value) return asnStore.types
  const filter = typeFilter.value.toLowerCase()
  return asnStore.types.filter(t => t.toLowerCase().includes(filter))
})

const selectType = (type: string) => {
  asnStore.selectType(type)
  showTypeSearch.value = false
  typeFilter.value = ''
}

const toggleDropdown = async () => {
  if (!showTypeSearch.value) {
    if (triggerButton.value) {
      const rect = triggerButton.value.getBoundingClientRect()
      dropdownStyle.value = {
        position: 'fixed',
        bottom: `${window.innerHeight - rect.top + 4}px`,
        left: `${rect.right - 256}px`,
        width: '256px',
        zIndex: 9999
      }
    }
    showTypeSearch.value = true
    await nextTick()
    searchInput.value?.focus()
  } else {
    showTypeSearch.value = false
  }
}

const handleClickOutside = (e: MouseEvent) => {
  const target = e.target as HTMLElement
  if (showTypeSearch.value && !target.closest('.type-selector-container') && !target.closest('.type-dropdown-portal')) {
    showTypeSearch.value = false
  }
}

onMounted(() => document.addEventListener('click', handleClickOutside))
onUnmounted(() => document.removeEventListener('click', handleClickOutside))
</script>

<template>
  <div class="h-full flex flex-col overflow-hidden">
    <div class="px-3 py-1.5 border-b bg-slate-100 flex items-center justify-between shadow-sm z-20">
      <div class="flex items-center gap-2">
        <Binary class="w-3.5 h-3.5 text-wireshark-blue" />
        <h2 class="text-[10px] font-bold uppercase tracking-wider text-slate-500">Hex / Byte View</h2>
      </div>
      
      <div class="flex items-center gap-3">
        <!-- Type Selector Dropdown -->
        <div class="relative type-selector-container">
          <button 
            ref="triggerButton"
            @click.stop="toggleDropdown"
            class="flex items-center gap-2 px-2 py-1 bg-white border border-slate-200 rounded text-[10px] font-mono hover:border-wireshark-blue transition-colors max-w-[150px]"
          >
            <span class="truncate">{{ asnStore.selectedType || 'Select Type...' }}</span>
            <ChevronDown class="w-3 h-3 text-slate-400" />
          </button>
          
          <Teleport to="body">
            <div 
              v-if="showTypeSearch" 
              :style="dropdownStyle"
              class="type-dropdown-portal bg-white border rounded shadow-2xl overflow-hidden flex flex-col max-h-64"
            >
              <div class="p-2 border-b bg-slate-50">
                <div class="relative">
                  <Search class="absolute left-2 top-1/2 -translate-y-1/2 w-3 h-3 text-slate-400" />
                  <input 
                    ref="searchInput"
                    v-model="typeFilter"
                    placeholder="Search types..."
                    class="w-full pl-7 pr-2 py-1.5 text-xs border rounded outline-none focus:ring-1 focus:ring-wireshark-blue"
                    @click.stop
                  />
                </div>
              </div>
              <div class="overflow-y-auto flex-1 custom-scrollbar">
                <button 
                  v-for="type in filteredTypes" 
                  :key="type"
                  @click="selectType(type)"
                  class="w-full text-left px-3 py-2 text-xs hover:bg-wireshark-light transition-colors border-b border-slate-50 last:border-0"
                  :class="{ 'bg-wireshark-light text-wireshark-blue font-bold': asnStore.selectedType === type }"
                >
                  {{ type }}
                </button>
                <div v-if="filteredTypes.length === 0" class="p-4 text-center text-xs text-slate-400 italic">
                  No matching types
                </div>
              </div>
            </div>
          </Teleport>
        </div>

        <!-- View Toggle -->
        <div class="flex bg-slate-200 p-0.5 rounded">
          <button 
            @click="viewMode = 'grid'"
            class="p-1 rounded transition-all"
            :class="viewMode === 'grid' ? 'bg-white shadow-sm text-wireshark-blue' : 'text-slate-500'"
            title="Grid View"
          >
            <LayoutGrid class="w-3 h-3" />
          </button>
          <button 
            @click="viewMode = 'text'"
            class="p-1 rounded transition-all"
            :class="viewMode === 'text' ? 'bg-white shadow-sm text-wireshark-blue' : 'text-slate-500'"
            title="Raw Text"
          >
            <Type class="w-3 h-3" />
          </button>
        </div>

        <button 
          @click="asnStore.decodeMessage"
          :disabled="!asnStore.encodedHex || !asnStore.selectedType || asnStore.isDecoding"
          class="flex items-center gap-1 px-3 py-1 bg-green-600 hover:bg-green-700 disabled:bg-slate-300 text-white text-xs font-bold rounded transition-colors shadow-sm"
        >
          <Loader2 v-if="asnStore.isDecoding" class="w-3 h-3 animate-spin" />
          <Play v-else class="w-3 h-3 fill-current" />
          DECODE
        </button>

        <button 
          v-if="asnStore.encodedHex"
          @click="copyHex"
          class="p-1 hover:bg-slate-200 rounded transition-colors"
          title="Copy Hex"
        >
          <component :is="copied ? Check : Copy" class="w-3.5 h-3.5 text-slate-500" />
        </button>
      </div>
    </div>
    
    <div class="flex-1 bg-slate-900 text-green-400 font-mono text-xs overflow-hidden relative custom-scrollbar">
      <template v-if="viewMode === 'grid'">
        <div class="p-3 h-full overflow-y-auto">
          <HexGrid :hex="asnStore.encodedHex" />
        </div>
      </template>
      <template v-else>
        <textarea
          :value="hexWithSpaces"
          @input="handleHexInput"
          placeholder="Paste or type hex here (e.g. DE AD BE EF)"
          class="w-full h-full p-3 bg-slate-900 text-green-400 font-mono text-xs outline-none border-none resize-none placeholder:text-slate-700 tracking-[0.15em] leading-relaxed font-bold"
          spellcheck="false"
        ></textarea>
      </template>

      <!-- Loading Overlay -->
      <div v-if="asnStore.isEncoding" class="absolute inset-0 bg-slate-900/50 backdrop-blur-[1px] flex items-center justify-center">
         <div class="flex items-center gap-2 text-white bg-slate-800 px-4 py-2 rounded-lg shadow-xl border border-slate-700">
           <Loader2 class="w-4 h-4 animate-spin text-wireshark-blue" />
           <span class="text-xs font-bold uppercase tracking-widest">Encoding Structure...</span>
         </div>
      </div>
    </div>
  </div>
</template>

<style scoped>
.custom-scrollbar::-webkit-scrollbar {
  width: 6px;
}
.custom-scrollbar::-webkit-scrollbar-track {
  background: rgba(255,255,255,0.05);
}
.custom-scrollbar::-webkit-scrollbar-thumb {
  background: rgba(255,255,255,0.1);
  border-radius: 10px;
}
.custom-scrollbar::-webkit-scrollbar-thumb:hover {
  background: rgba(255,255,255,0.2);
}
</style>
