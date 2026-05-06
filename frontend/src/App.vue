<script setup lang="ts">
import { ref, onMounted } from 'vue'
import { useAsnStore } from '@/store/asn'
import Navbar from '@/components/layout/Navbar.vue'
import TypeBrowser from '@/components/layout/TypeBrowser.vue'
import StructureFiller from '@/components/layout/StructureFiller.vue'
import DecodedTree from '@/components/layout/DecodedTree.vue'
import HexView from '@/components/layout/HexView.vue'

const asnStore = useAsnStore()

// Pane Sizes
const sidebarWidth = ref(256)
const editorWidth = ref(0) // Will be set on mount to 50% of available
const hexHeight = ref(192)

const isResizingSidebar = ref(false)
const isResizingEditor = ref(false)
const isResizingHex = ref(false)

const startSidebarResize = () => { isResizingSidebar.value = true; setupListeners() }
const startEditorResize = () => { isResizingEditor.value = true; setupListeners() }
const startHexResize = () => { isResizingHex.value = true; setupListeners() }

const handleMouseMove = (e: MouseEvent) => {
  if (isResizingSidebar.value) {
    sidebarWidth.value = Math.max(150, Math.min(e.clientX, 600))
  } else if (isResizingEditor.value) {
    // Editor width relative to the container between sidebar and tree
    const containerStart = sidebarWidth.value
    const newWidth = e.clientX - containerStart
    editorWidth.value = Math.max(200, Math.min(newWidth, window.innerWidth - sidebarWidth.value - 200))
  } else if (isResizingHex.value) {
    const newHeight = window.innerHeight - e.clientY
    hexHeight.value = Math.max(100, Math.min(newHeight, window.innerHeight - 200))
  }
}

const stopResizing = () => {
  isResizingSidebar.value = false
  isResizingEditor.value = false
  isResizingHex.value = false
  document.removeEventListener('mousemove', handleMouseMove)
  document.removeEventListener('mouseup', stopResizing)
  document.body.style.cursor = ''
  document.body.style.userSelect = ''
}

const setupListeners = () => {
  document.addEventListener('mousemove', handleMouseMove)
  document.addEventListener('mouseup', stopResizing)
  document.body.style.userSelect = 'none'
  if (isResizingSidebar.value || isResizingEditor.value) document.body.style.cursor = 'col-resize'
  if (isResizingHex.value) document.body.style.cursor = 'row-resize'
}

onMounted(() => {
  // Initialize editor width to 50% of remaining space
  const remaining = window.innerWidth - sidebarWidth.value
  editorWidth.value = remaining / 2
})
</script>

<template>
  <div class="h-screen flex flex-col bg-slate-100 overflow-hidden">
    <Navbar />
    
    <main class="flex-1 flex overflow-hidden relative">
      <!-- Left: Type Browser -->
      <aside 
        :style="{ width: sidebarWidth + 'px' }"
        class="border-r bg-white flex flex-col flex-shrink-0"
      >
        <TypeBrowser />
      </aside>

      <!-- Sidebar Splitter -->
      <div 
        class="w-1 cursor-col-resize hover:bg-wireshark-blue/30 active:bg-wireshark-blue/50 z-30 transition-colors"
        @mousedown="startSidebarResize"
      ></div>

      <!-- Main Content Area (Center + Right + Bottom) -->
      <div class="flex-1 flex flex-col overflow-hidden min-w-0">
        <!-- Top Half: Editor and Tree -->
        <div class="flex-1 flex overflow-hidden relative">
          <!-- Center: Structure Filler -->
          <section 
            :style="{ width: editorWidth + 'px' }"
            class="border-r bg-white overflow-y-auto flex-shrink-0"
          >
            <StructureFiller v-if="asnStore.selectedType" />
            <div v-else class="h-full flex items-center justify-center text-slate-400 italic">
              Select a type to begin filling
            </div>
          </section>

          <!-- Editor Splitter -->
          <div 
            class="w-1 cursor-col-resize hover:bg-wireshark-blue/30 active:bg-wireshark-blue/50 z-30 transition-colors"
            @mousedown="startEditorResize"
          ></div>

          <!-- Right: Decoded Tree View -->
          <section class="flex-1 bg-white overflow-y-auto min-w-0">
            <DecodedTree />
          </section>
        </div>

        <!-- Hex Splitter -->
        <div 
          class="h-1 cursor-row-resize hover:bg-wireshark-blue/30 active:bg-wireshark-blue/50 z-30 transition-colors"
          @mousedown="startHexResize"
        ></div>

        <!-- Bottom: Hex View -->
        <footer 
          :style="{ height: hexHeight + 'px' }"
          class="bg-slate-50 flex-shrink-0 overflow-hidden"
        >
          <HexView />
        </footer>
      </div>
    </main>

    <!-- Error Toast (Global) -->
    <div v-if="asnStore.error" class="fixed bottom-4 right-4 bg-red-600 text-white px-4 py-2 rounded shadow-lg z-50 flex items-center gap-2">
      <span>{{ asnStore.error }}</span>
      <button @click="asnStore.error = null" class="font-bold">&times;</button>
    </div>
  </div>
</template>

<style>
/* Global styles for resizing */
.cursor-col-resize { cursor: col-resize; }
.cursor-row-resize { cursor: row-resize; }
</style>
