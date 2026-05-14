template <> struct adl_serializer<std::any> {
    static void to_json(json& j, const std::any& v) {
        if (!v.has_value()) { j = nullptr; return; }
        const auto& ti = v.type();
        if (ti == typeid(int64_t)) { j = std::any_cast<int64_t>(v); return; }
        if (ti == typeid(int)) { j = std::any_cast<int>(v); return; }
        if (ti == typeid(bool)) { j = std::any_cast<bool>(v); return; }
        if (ti == typeid(std::string)) { j = std::any_cast<std::string>(v); return; }
        if (ti == typeid(double)) { j = std::any_cast<double>(v); return; }
        if (ti == typeid(asn1::runtime::BitString)) { j = std::any_cast<asn1::runtime::BitString>(v); return; }
        // Generated types dispatch
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::GNB_CU_CP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::GNB_CU_CP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::GNB_CU_CP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::GNB_CU_CP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_UP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_UP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::GNB_CU_UP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::GNB_CU_UP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::GNB_CU_UP_UE_E1AP_ID)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::GNB_CU_UP_UE_E1AP_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::System_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_IEs::System_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::System_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::System_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::System_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::System_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_IEs::BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::PDU_Session_Resource_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::PDU_Session_Resource_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::PDU_Session_Resource_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::PDU_Session_Resource_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::PDU_Session_Resource_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::PDU_Session_Resource_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::PDU_Session_Resource_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::PDU_Session_Resource_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::PDU_Session_Resource_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::PDU_Session_Resource_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::PDU_Session_Resource_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::PDU_Session_Resource_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::DRB_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::DRB_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::DRB_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::DRB_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::DRB_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::DRB_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::DRB_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::DRB_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::DRB_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::DRB_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::DRB_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::DRB_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_Parameters)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::UP_Parameters)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::UP_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::UP_Parameters)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::UP_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::UP_Parameters)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::UP_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_Parameters_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_Parameters_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::UP_Parameters_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::UP_Parameters_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::UP_Parameters_Item)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::UP_Parameters_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::UP_Parameters_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::UP_Parameters_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::QoS_Flow_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::QoS_Flow_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::QoS_Flow_Item>(v); return; }
        j = nullptr;
    }
    static void from_json(const json& j, std::any& v) { /* TODO */ }
};
