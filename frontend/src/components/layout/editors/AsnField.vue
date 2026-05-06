<script setup lang="ts">
import { computed } from 'vue'
import { useAsnStore } from '@/store/asn'
import { resolveFullType } from '@/schema-utils'
import SequenceEditor from './SequenceEditor.vue'
import ChoiceEditor from './ChoiceEditor.vue'
import EnumEditor from './EnumEditor.vue'
import SequenceOfEditor from './SequenceOfEditor.vue'
import BaseFieldEditor from './BaseFieldEditor.vue'
import HexEditor from './HexEditor.vue'
import IeListEditor from './IeListEditor.vue'

const props = defineProps<{
  schema: any
  data: any
  depth: number
}>()

const emit = defineEmits(['update:data'])

const asnStore = useAsnStore()

const currentSchema = computed(() => {
  return resolveFullType(props.schema, asnStore.indexedSchema)
})

const kind = computed(() => (currentSchema.value.kind || '').toLowerCase())

const isIeList = computed(() => {
  return kind.value === 'sequence_of' && currentSchema.value.ies && currentSchema.value.ies.length > 0
})

const updateData = (val: any) => {
  emit('update:data', val)
}
</script>

<template>
  <div class="asn-field">
    <template v-if="isIeList">
      <IeListEditor 
        :ies="currentSchema.ies" 
        :data="data || []" 
        :depth="depth"
        @update:data="updateData"
      />
    </template>

    <template v-else-if="kind === 'sequence'">
      <SequenceEditor 
        :fields="currentSchema.fields || []" 
        :data="data || {}" 
        :depth="depth"
        @update:data="updateData"
      />
    </template>
    
    <template v-else-if="kind === 'choice'">
      <ChoiceEditor 
        :schema="currentSchema" 
        :data="data" 
        :depth="depth"
        @update:data="updateData"
      />
    </template>

    <template v-else-if="kind === 'enumeration'">
      <EnumEditor 
        :schema="currentSchema" 
        :data="data" 
        @update:data="updateData"
      />
    </template>

    <template v-else-if="kind === 'sequence_of'">
      <SequenceOfEditor 
        :schema="currentSchema" 
        :data="data" 
        :depth="depth"
        @update:data="updateData"
      />
    </template>

    <template v-else-if="kind === 'octet_string' || kind === 'bit_string'">
      <HexEditor 
        :data="data" 
        :label="kind"
        :schema="currentSchema"
        @update:data="updateData"
      />
    </template>

    <template v-else>
      <BaseFieldEditor 
        :kind="kind" 
        :data="data" 
        :schema="currentSchema"
        @update:data="updateData"
      />
    </template>
  </div>
</template>
