std::any decode_ProtocolIE_Value(int64_t id, BitReader& reader) {
    reader.alignToOctet();
    BitReader sub_reader = UperExtension::decodeOpenType(reader);
    switch(id) {
        case 0: return decode_Cause(sub_reader);
        case 1: return decode_CriticalityDiagnostics(sub_reader);
        case 2: return decode_GNB_CU_CP_UE_E1AP_ID(sub_reader);
        case 3: return decode_GNB_CU_UP_UE_E1AP_ID(sub_reader);
        case 4: return decode_ResetType(sub_reader);
        case 5: return decode_UE_associatedLogicalE1_ConnectionItem(sub_reader);
        case 6: return decode_UE_associatedLogicalE1_ConnectionListResAck(sub_reader);
        case 7: return decode_GNB_CU_UP_ID(sub_reader);
        case 8: return decode_GNB_CU_UP_Name(sub_reader);
        case 9: return decode_GNB_CU_UP_Name(sub_reader);
        case 10: return decode_CNSupport(sub_reader);
        case 11: return decode_SupportedPLMNs_List(sub_reader);
        case 12: return decode_TimeToWait(sub_reader);
        case 13: return decode_SecurityInformation(sub_reader);
        case 14: return decode_BitRate(sub_reader);
        case 15: return decode_System_BearerContextSetupRequest(sub_reader);
        case 16: return decode_System_BearerContextSetupResponse(sub_reader);
        case 17: return decode_BearerContextStatusChange(sub_reader);
        case 18: return decode_System_BearerContextModificationRequest(sub_reader);
        case 19: return decode_System_BearerContextModificationResponse(sub_reader);
        case 20: return decode_System_BearerContextModificationConfirm(sub_reader);
        case 21: return decode_System_BearerContextModificationRequired(sub_reader);
        case 22: return decode_DRB_Status_List(sub_reader);
        case 23: return decode_ActivityNotificationLevel(sub_reader);
        case 24: return decode_ActivityInformation(sub_reader);
        case 25: return decode_Data_Usage_Report_List(sub_reader);
        case 26: return decode_New_UL_TNL_Information_Required(sub_reader);
        case 27: return decode_GNB_CU_CP_TNLA_To_Add_List(sub_reader);
        case 28: return decode_GNB_CU_CP_TNLA_To_Remove_List(sub_reader);
        case 29: return decode_GNB_CU_CP_TNLA_To_Update_List(sub_reader);
        case 30: return decode_GNB_CU_CP_TNLA_Setup_List(sub_reader);
        case 31: return decode_GNB_CU_CP_TNLA_Failed_To_Setup_List(sub_reader);
        case 32: return decode_DRB_To_Setup_List_EUTRAN(sub_reader);
        case 33: return decode_DRB_To_Modify_List_EUTRAN(sub_reader);
        case 34: return decode_DRB_To_Remove_List_EUTRAN(sub_reader);
        case 35: return decode_DRB_Required_To_Modify_List_EUTRAN(sub_reader);
        case 36: return decode_DRB_Required_To_Remove_List_EUTRAN(sub_reader);
        case 37: return decode_DRB_Setup_List_EUTRAN(sub_reader);
        case 38: return decode_DRB_Failed_List_EUTRAN(sub_reader);
        case 39: return decode_DRB_Modified_List_EUTRAN(sub_reader);
        case 40: return decode_DRB_Failed_To_Modify_List_EUTRAN(sub_reader);
        case 41: return decode_DRB_Confirm_Modified_List_EUTRAN(sub_reader);
        case 42: return decode_PDU_Session_Resource_To_Setup_List(sub_reader);
        case 43: return decode_PDU_Session_Resource_To_Modify_List(sub_reader);
        case 44: return decode_PDU_Session_Resource_To_Remove_List(sub_reader);
        case 45: return decode_PDU_Session_Resource_Required_To_Modify_List(sub_reader);
        case 46: return decode_PDU_Session_Resource_Setup_List(sub_reader);
        case 47: return decode_PDU_Session_Resource_Failed_List(sub_reader);
        case 48: return decode_PDU_Session_Resource_Modified_List(sub_reader);
        case 49: return decode_PDU_Session_Resource_Failed_To_Modify_List(sub_reader);
        case 50: return decode_PDU_Session_Resource_Confirm_Modified_List(sub_reader);
        case 51: return decode_DRB_To_Setup_Mod_List_EUTRAN(sub_reader);
        case 52: return decode_DRB_Setup_Mod_List_EUTRAN(sub_reader);
        case 53: return decode_DRB_Failed_Mod_List_EUTRAN(sub_reader);
        case 54: return decode_PDU_Session_Resource_Setup_Mod_List(sub_reader);
        case 55: return decode_PDU_Session_Resource_Failed_Mod_List(sub_reader);
        case 56: return decode_PDU_Session_Resource_To_Setup_Mod_List(sub_reader);
        case 57: return decode_TransactionID(sub_reader);
        case 58: return decode_PLMN_Identity(sub_reader);
        case 59: return decode_Inactivity_Timer(sub_reader);
        case 60: return decode_System_GNB_CU_UP_CounterCheckRequest(sub_reader);
        case 61: return decode_DRBs_Subject_To_Counter_Check_List_EUTRAN(sub_reader);
        case 62: return decode_DRBs_Subject_To_Counter_Check_List_NG_RAN(sub_reader);
        case 63: return decode_PPI(sub_reader);
        case 64: return decode_GNB_CU_UP_Capacity(sub_reader);
        case 65: return decode_GNB_CU_UP_OverloadInformation(sub_reader);
        case 66: return decode_BitRate(sub_reader);
        case 67: return decode_PDU_Session_To_Notify_List(sub_reader);
        case 68: return decode_PDU_Session_Resource_Data_Usage_List(sub_reader);
        case 70: return decode_DataDiscardRequired(sub_reader);
        case 73: return decode_GNB_CU_UP_TNLA_To_Remove_List(sub_reader);
        case 74: return decode_Endpoint_IP_address_and_port(sub_reader);
        case 76: return decode_RANUEID(sub_reader);
        case 77: return decode_GNB_DU_ID(sub_reader);
        default: return sub_reader.getBitString();
    }
}

std::any decode_InitiatingMessage_Value(int64_t procCode, BitReader& reader) {
    reader.alignToOctet();
    BitReader sub_reader = UperExtension::decodeOpenType(reader);
    switch(procCode) {
        case 0: return decode_Reset(sub_reader);
        case 1: return decode_ErrorIndication(sub_reader);
        case 2: return decode_PrivateMessage(sub_reader);
        case 3: return decode_GNB_CU_UP_E1SetupRequest(sub_reader);
        case 4: return decode_GNB_CU_CP_E1SetupRequest(sub_reader);
        case 5: return decode_GNB_CU_UP_ConfigurationUpdate(sub_reader);
        case 6: return decode_GNB_CU_CP_ConfigurationUpdate(sub_reader);
        case 7: return decode_E1ReleaseRequest(sub_reader);
        case 8: return decode_BearerContextSetupRequest(sub_reader);
        case 9: return decode_BearerContextModificationRequest(sub_reader);
        case 10: return decode_BearerContextModificationRequired(sub_reader);
        case 11: return decode_BearerContextReleaseCommand(sub_reader);
        case 12: return decode_BearerContextReleaseRequest(sub_reader);
        case 13: return decode_BearerContextInactivityNotification(sub_reader);
        case 14: return decode_DLDataNotification(sub_reader);
        case 15: return decode_DataUsageReport(sub_reader);
        case 16: return decode_GNB_CU_UP_CounterCheckRequest(sub_reader);
        case 17: return decode_GNB_CU_UP_StatusIndication(sub_reader);
        case 18: return decode_ULDataNotification(sub_reader);
        case 19: return decode_MRDC_DataUsageReport(sub_reader);
        default: return sub_reader.getBitString();
    }
}

std::any decode_SuccessfulOutcome_Value(int64_t procCode, BitReader& reader) {
    reader.alignToOctet();
    BitReader sub_reader = UperExtension::decodeOpenType(reader);
    switch(procCode) {
        case 0: return decode_ResetAcknowledge(sub_reader);
        case 3: return decode_GNB_CU_UP_E1SetupResponse(sub_reader);
        case 4: return decode_GNB_CU_CP_E1SetupResponse(sub_reader);
        case 5: return decode_GNB_CU_UP_ConfigurationUpdateAcknowledge(sub_reader);
        case 6: return decode_GNB_CU_CP_ConfigurationUpdateAcknowledge(sub_reader);
        case 7: return decode_E1ReleaseResponse(sub_reader);
        case 8: return decode_BearerContextSetupResponse(sub_reader);
        case 9: return decode_BearerContextModificationResponse(sub_reader);
        case 10: return decode_BearerContextModificationConfirm(sub_reader);
        case 11: return decode_BearerContextReleaseComplete(sub_reader);
        default: return sub_reader.getBitString();
    }
}

std::any decode_UnsuccessfulOutcome_Value(int64_t procCode, BitReader& reader) {
    reader.alignToOctet();
    BitReader sub_reader = UperExtension::decodeOpenType(reader);
    switch(procCode) {
        case 3: return decode_GNB_CU_UP_E1SetupFailure(sub_reader);
        case 4: return decode_GNB_CU_CP_E1SetupFailure(sub_reader);
        case 5: return decode_GNB_CU_UP_ConfigurationUpdateFailure(sub_reader);
        case 6: return decode_GNB_CU_CP_ConfigurationUpdateFailure(sub_reader);
        case 8: return decode_BearerContextSetupFailure(sub_reader);
        case 9: return decode_BearerContextModificationFailure(sub_reader);
        default: return sub_reader.getBitString();
    }
}

