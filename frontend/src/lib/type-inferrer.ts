/**
 * Helper to infer ASN.1 types for OpenTypes (ANY/TYPE) based on protocol-specific
 * identifiers like procedureCode or ProtocolIE-ID.
 */

const E1AP_PROCEDURES: Record<number, string> = {
  1: 'Reset',
  2: 'ErrorIndication',
  3: 'GNB_CU_UP_E1Setup',
  4: 'GNB_CU_CP_E1Setup',
  5: 'GNB_CU_UP_ConfigurationUpdate',
  6: 'GNB_CU_CP_ConfigurationUpdate',
  7: 'E1Release',
  8: 'BearerContextSetup',
  9: 'BearerContextModification',
  10: 'BearerContextModificationRequired',
  11: 'BearerContextRelease',
  12: 'BearerContextReleaseRequest',
  13: 'BearerContextInactivityNotification',
  14: 'DLDataNotification',
  15: 'ULDataNotification',
  16: 'DataUsageReport',
  17: 'GNB_CU_UP_CounterCheck',
  18: 'GNB_CU_UP_StatusIndication',
  19: 'MRDC_DataUsageReport',
  20: 'PrivateMessage'
};

const E1AP_IE_IDS: Record<number, string> = {
  2: 'E1AP_IEs::GNB_CU_CP_UE_E1AP_ID',
  3: 'E1AP_IEs::GNB_CU_UP_UE_E1AP_ID',
  18: 'E1AP_PDU_Contents::System_BearerContextModificationRequest',
  43: 'E1AP_IEs::PDU_Session_Resource_To_Modify_List',
  45: 'E1AP_IEs::PDU_Session_Resource_To_Setup_List',
  47: 'E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List',
  64: 'E1AP_IEs::DRB_To_Modify_List_NG_RAN',
  65: 'E1AP_IEs::DRB_To_Remove_List_NG_RAN',
};

export function inferAsnType(parentData: any, schema: any): string | null {
  // If it's not an OpenType, don't bother
  const typeRef = schema?.type_ref || schema?.name || '';
  if (typeRef !== 'TYPE' && schema?.kind !== 'any' && !typeRef.includes('ANY')) return null;

  // 1. Try resolving based on sibling 'procedureCode' (Standard for 3GPP InitiatingMessage/SuccessfulOutcome)
  if (parentData && parentData.procedureCode !== undefined) {
    const codeValue = parentData.procedureCode;
    // Handle both number and string/object if aliased
    const code = typeof codeValue === 'object' ? Number(codeValue.value) : Number(codeValue);
    
    const baseName = E1AP_PROCEDURES[code];
    if (baseName) {
      const parentLabel = (schema?.parentLabel || '').toLowerCase();
      if (parentLabel.includes('initiating')) return `E1AP_PDU_Contents::${baseName}Request`;
      if (parentLabel.includes('successful')) return `E1AP_PDU_Contents::${baseName}Response`;
      if (parentLabel.includes('unsuccessful')) return `E1AP_PDU_Contents::${baseName}Failure`;
      return `E1AP_PDU_Contents::${baseName}`;
    }
  }

  // 2. Try resolving based on sibling 'id' (Standard for ProtocolIE-Field)
  if (parentData && parentData.id !== undefined) {
     const idValue = parentData.id;
     const id = typeof idValue === 'object' ? Number(idValue.value) : Number(idValue);
     
     if (E1AP_IE_IDS[id]) return E1AP_IE_IDS[id];
     
     // String fallbacks if the backend returned names instead of numbers
     if (typeof idValue === 'string') {
        if (idValue.includes('System-BearerContextModificationRequest')) return 'E1AP_PDU_Contents::System_BearerContextModificationRequest';
        if (idValue.includes('PDU-Session-Resource-To-Modify-List')) return 'E1AP_IEs::PDU_Session_Resource_To_Modify_List';
     }
  }

  return null;
}
