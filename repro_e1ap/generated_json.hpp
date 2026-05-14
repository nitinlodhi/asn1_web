#pragma once
#include "generated.h"
#include <nlohmann/json.hpp>
#include <functional>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <stdexcept>

namespace asn1::runtime {

inline void to_json(nlohmann::json& j, const asn1::runtime::BitString& v) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (uint8_t byte : v.data) oss << std::setw(2) << static_cast<int>(byte);
    j = nlohmann::json{{"hex", oss.str()}, {"bit_length", v.bit_length}};
}

inline void from_json(const nlohmann::json& j, asn1::runtime::BitString& v) {
    v.bit_length = j.at("bit_length").get<size_t>();
    std::string hex = j.at("hex").get<std::string>();
    v.data.clear();
    for (size_t i = 0; i + 1 < hex.size(); i += 2) {
        v.data.push_back(static_cast<uint8_t>(std::stoul(hex.substr(i, 2), nullptr, 16)));
    }
}

inline void to_json(nlohmann::json& j, const asn1::runtime::ExtensionValue& /*v*/) {
    j = nlohmann::json{{"__extension", true}};
}

inline void from_json(const nlohmann::json& /*j*/, asn1::runtime::ExtensionValue& /*v*/) {
    throw std::runtime_error("Cannot deserialize ExtensionValue from JSON");
}

} // namespace asn1::runtime

namespace nlohmann {
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
        if (ti == typeid(asn1::generated::E1AP_CommonDataTypes::PrivateIE_ID)) { j = std::any_cast<asn1::generated::E1AP_CommonDataTypes::PrivateIE_ID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::ProtocolIE_Field)) { j = std::any_cast<asn1::generated::E1AP_Containers::ProtocolIE_Field>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::ProtocolIE_Container)) { j = std::any_cast<asn1::generated::E1AP_Containers::ProtocolIE_Container>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::ProtocolIE_ContainerList)) { j = std::any_cast<asn1::generated::E1AP_Containers::ProtocolIE_ContainerList>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::ProtocolExtensionField)) { j = std::any_cast<asn1::generated::E1AP_Containers::ProtocolExtensionField>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::ProtocolExtensionContainer)) { j = std::any_cast<asn1::generated::E1AP_Containers::ProtocolExtensionContainer>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::PrivateIE_Field)) { j = std::any_cast<asn1::generated::E1AP_Containers::PrivateIE_Field>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_Containers::PrivateIE_Container)) { j = std::any_cast<asn1::generated::E1AP_Containers::PrivateIE_Container>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause_radioNetwork)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause_radioNetwork>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause_transport)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause_transport>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause_protocol)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause_protocol>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause_misc)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause_misc>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cause)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cause>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::CommonNetworkInstance)) { j = std::any_cast<asn1::generated::E1AP_IEs::CommonNetworkInstance>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Activity_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Activity_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Activity_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Activity_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Remove_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Remove_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Remove_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Remove_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Remove_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Remove_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Remove_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Remove_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Usage_Report_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Usage_Report_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Usage_Report_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Usage_Report_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::EncryptionKey)) { j = std::any_cast<asn1::generated::E1AP_IEs::EncryptionKey>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GBR_QosInformation)) { j = std::any_cast<asn1::generated::E1AP_IEs::GBR_QosInformation>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GTP_TEID)) { j = std::any_cast<asn1::generated::E1AP_IEs::GTP_TEID>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::IntegrityProtectionKey)) { j = std::any_cast<asn1::generated::E1AP_IEs::IntegrityProtectionKey>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::MaximumIPdatarate)) { j = std::any_cast<asn1::generated::E1AP_IEs::MaximumIPdatarate>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GBR_QoSFlowInformation)) { j = std::any_cast<asn1::generated::E1AP_IEs::GBR_QoSFlowInformation>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::MRDC_Data_Usage_Report_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::MRDC_Data_Usage_Report_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Data_Usage_per_PDU_Session_Report)) { j = std::any_cast<asn1::generated::E1AP_IEs::Data_Usage_per_PDU_Session_Report>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NR_CGI)) { j = std::any_cast<asn1::generated::E1AP_IEs::NR_CGI>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NR_CGI_Support_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::NR_CGI_Support_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NR_CGI_Support_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::NR_CGI_Support_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::EUTRANAllocationAndRetentionPriority)) { j = std::any_cast<asn1::generated::E1AP_IEs::EUTRANAllocationAndRetentionPriority>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NGRANAllocationAndRetentionPriority)) { j = std::any_cast<asn1::generated::E1AP_IEs::NGRANAllocationAndRetentionPriority>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::EUTRAN_QoS)) { j = std::any_cast<asn1::generated::E1AP_IEs::EUTRAN_QoS>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::MRDC_Usage_Information)) { j = std::any_cast<asn1::generated::E1AP_IEs::MRDC_Usage_Information>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_To_Notify_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_To_Notify_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_To_Notify_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_To_Notify_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Failed_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Failed_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Failed_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Failed_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_Mapping_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_Mapping_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Data_Forwarding_Information_Request)) { j = std::any_cast<asn1::generated::E1AP_IEs::Data_Forwarding_Information_Request>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Dynamic5QIDescriptor)) { j = std::any_cast<asn1::generated::E1AP_IEs::Dynamic5QIDescriptor>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Non_Dynamic5QIDescriptor)) { j = std::any_cast<asn1::generated::E1AP_IEs::Non_Dynamic5QIDescriptor>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Characteristics_dynamic5QI)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Characteristics_dynamic5QI>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Characteristics_non_dynamic5QI)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Characteristics_non_dynamic5QI>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Characteristics_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Characteristics_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Characteristics)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Characteristics>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Parameters_Support_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Parameters_Support_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoSFlowLevelQoSParameters)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoSFlowLevelQoSParameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Slice_Support_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::Slice_Support_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Slice_Support_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::Slice_Support_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::SDAP_Configuration)) { j = std::any_cast<asn1::generated::E1AP_IEs::SDAP_Configuration>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Endpoint_IP_address_and_port)) { j = std::any_cast<asn1::generated::E1AP_IEs::Endpoint_IP_address_and_port>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GTPTunnel)) { j = std::any_cast<asn1::generated::E1AP_IEs::GTPTunnel>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::T_Reordering)) { j = std::any_cast<asn1::generated::E1AP_IEs::T_Reordering>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List_element)) { j = std::any_cast<asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List_element>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::CriticalityDiagnostics)) { j = std::any_cast<asn1::generated::E1AP_IEs::CriticalityDiagnostics>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ActivityInformation_dRB_Activity_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::ActivityInformation_dRB_Activity_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ActivityInformation_pDU_Session_Resource_Activity_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::ActivityInformation_pDU_Session_Resource_Activity_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ActivityInformation_uE_Activity)) { j = std::any_cast<asn1::generated::E1AP_IEs::ActivityInformation_uE_Activity>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ActivityInformation_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_IEs::ActivityInformation_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ActivityInformation)) { j = std::any_cast<asn1::generated::E1AP_IEs::ActivityInformation>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UE_associatedLogicalE1_ConnectionItem)) { j = std::any_cast<asn1::generated::E1AP_IEs::UE_associatedLogicalE1_ConnectionItem>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cell_Group_Information_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cell_Group_Information_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Cell_Group_Information)) { j = std::any_cast<asn1::generated::E1AP_IEs::Cell_Group_Information>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::SecurityInformation)) { j = std::any_cast<asn1::generated::E1AP_IEs::SecurityInformation>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_TNL_Information_gTPTunnel)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_TNL_Information_gTPTunnel>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_TNL_Information_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_TNL_Information_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_TNL_Information)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_TNL_Information>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::Data_Forwarding_Information)) { j = std::any_cast<asn1::generated::E1AP_IEs::Data_Forwarding_Information>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration)) { j = std::any_cast<asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_Parameters_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_Parameters_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::UP_Parameters)) { j = std::any_cast<asn1::generated::E1AP_IEs::UP_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Modified_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Modified_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Modified_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Modified_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Modified_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Modified_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Modified_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Modified_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ROHC_Parameters_rOHC)) { j = std::any_cast<asn1::generated::E1AP_IEs::ROHC_Parameters_rOHC>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ROHC_Parameters_uPlinkOnlyROHC)) { j = std::any_cast<asn1::generated::E1AP_IEs::ROHC_Parameters_uPlinkOnlyROHC>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ROHC_Parameters_choice_Extension)) { j = std::any_cast<asn1::generated::E1AP_IEs::ROHC_Parameters_choice_Extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::ROHC_Parameters)) { j = std::any_cast<asn1::generated::E1AP_IEs::ROHC_Parameters>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDCP_Configuration)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDCP_Configuration>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Modify_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Modify_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Modify_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Modify_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Modify_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Modify_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Modify_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Modify_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN)) { j = std::any_cast<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List)) { j = std::any_cast<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::Reset)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::Reset>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ResetType_e1_Interface)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ResetType_e1_Interface>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ResetType_partOfE1_Interface)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ResetType_partOfE1_Interface>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ResetType_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ResetType_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ResetType)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ResetType>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ResetAcknowledge)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ResetAcknowledge>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ErrorIndication)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ErrorIndication>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_Item)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_Item>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::E1ReleaseRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::E1ReleaseRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::E1ReleaseResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::E1ReleaseResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextSetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextSetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextSetupFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextSetupFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextModificationResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextModificationResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextModificationFailure)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextModificationFailure>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequired)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequired>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextModificationConfirm)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextModificationConfirm>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextReleaseCommand)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseCommand>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextReleaseComplete)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseComplete>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextReleaseRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::DRB_Status_List)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::DRB_Status_List>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::BearerContextInactivityNotification)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::BearerContextInactivityNotification>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::DLDataNotification)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::DLDataNotification>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::ULDataNotification)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::ULDataNotification>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::DataUsageReport)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::DataUsageReport>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_choice_extension)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest_choice_extension>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_StatusIndication)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_StatusIndication>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::MRDC_DataUsageReport)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::MRDC_DataUsageReport>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Contents::PrivateMessage)) { j = std::any_cast<asn1::generated::E1AP_PDU_Contents::PrivateMessage>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::InitiatingMessage)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::InitiatingMessage>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::SuccessfulOutcome)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::SuccessfulOutcome>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::UnsuccessfulOutcome)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::UnsuccessfulOutcome>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_initiatingMessage)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_initiatingMessage>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_successfulOutcome)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_successfulOutcome>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_unsuccessfulOutcome)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU_unsuccessfulOutcome>(v); return; }
        if (ti == typeid(asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU)) { j = std::any_cast<asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU>(v); return; }
        j = nullptr;
    }
    static void from_json(const json& j, std::any& v) {
        // Default fallback to BitString for now
        if (j.is_object() && j.contains("hex") && j.contains("bit_length")) {
            asn1::runtime::BitString bs;
            bs.bit_length = j.at("bit_length").get<size_t>();
            std::string hex = j.at("hex").get<std::string>();
            for (size_t i = 0; i + 1 < hex.size(); i += 2)
                bs.data.push_back(static_cast<uint8_t>(std::stoul(hex.substr(i, 2), nullptr, 16)));
            v = std::move(bs);
        }
    }
};
} // namespace nlohmann

namespace asn1::generated {

namespace E1AP_CommonDataTypes {

NLOHMANN_JSON_SERIALIZE_ENUM(Criticality, {
    {Criticality::reject, "reject"},
    {Criticality::ignore, "ignore"},
    {Criticality::notify, "notify"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(Presence, {
    {Presence::optional, "optional"},
    {Presence::conditional, "conditional"},
    {Presence::mandatory, "mandatory"}
})

inline void to_json(nlohmann::json& j, const PrivateIE_ID& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, PrivateIE_ID_local>) {
            j = nlohmann::json{{"local", alt.local}};
        } else
        if constexpr (std::is_same_v<T, PrivateIE_ID_global>) {
            j = nlohmann::json{{"global", alt.global}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, PrivateIE_ID& v) {
    if (j.contains("local")) {
        PrivateIE_ID_local alt;
        j.at("local").get_to(alt.local);
        v = std::move(alt);
        return;
    }
    if (j.contains("global")) {
        PrivateIE_ID_global alt;
        j.at("global").get_to(alt.global);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

NLOHMANN_JSON_SERIALIZE_ENUM(TriggeringMessage, {
    {TriggeringMessage::initiating_message, "initiating_message"},
    {TriggeringMessage::successful_outcome, "successful_outcome"},
    {TriggeringMessage::unsuccessful_outcome, "unsuccessful_outcome"}
})

} // namespace E1AP_CommonDataTypes

namespace E1AP_Constants {

} // namespace E1AP_Constants

namespace E1AP_Containers {

inline void to_json(nlohmann::json& j, const ProtocolIE_Field& v) {
    j = nlohmann::json::object();
    j["id"] = v.id;
    j["criticality"] = v.criticality;
    j["value"] = v.value;
}

inline void from_json(const nlohmann::json& j, ProtocolIE_Field& v) {
    if (j.contains("id")) {
        j.at("id").get_to(v.id);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("value")) {
        j.at("value").get_to(v.value);
    }
}

inline void to_json(nlohmann::json& j, const ProtocolExtensionField& v) {
    j = nlohmann::json::object();
    j["id"] = v.id;
    j["criticality"] = v.criticality;
    j["extensionValue"] = v.extensionValue;
}

inline void from_json(const nlohmann::json& j, ProtocolExtensionField& v) {
    if (j.contains("id")) {
        j.at("id").get_to(v.id);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("extensionValue")) {
        j.at("extensionValue").get_to(v.extensionValue);
    }
}

inline void to_json(nlohmann::json& j, const PrivateIE_Field& v) {
    j = nlohmann::json::object();
    j["id"] = v.id;
    j["criticality"] = v.criticality;
    j["value"] = v.value;
}

inline void from_json(const nlohmann::json& j, PrivateIE_Field& v) {
    if (j.contains("id")) {
        j.at("id").get_to(v.id);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("value")) {
        j.at("value").get_to(v.value);
    }
}

} // namespace E1AP_Containers

namespace E1AP_IEs {

NLOHMANN_JSON_SERIALIZE_ENUM(ActivityNotificationLevel, {
    {ActivityNotificationLevel::drb, "drb"},
    {ActivityNotificationLevel::pdu_session, "pdu_session"},
    {ActivityNotificationLevel::ue, "ue"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(BearerContextStatusChange, {
    {BearerContextStatusChange::suspend, "suspend"},
    {BearerContextStatusChange::resume, "resume"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(CauseMisc, {
    {CauseMisc::control_processing_overload, "control_processing_overload"},
    {CauseMisc::not_enough_user_plane_processing_resources, "not_enough_user_plane_processing_resources"},
    {CauseMisc::hardware_failure, "hardware_failure"},
    {CauseMisc::om_intervention, "om_intervention"},
    {CauseMisc::unspecified, "unspecified"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(CauseProtocol, {
    {CauseProtocol::transfer_syntax_error, "transfer_syntax_error"},
    {CauseProtocol::abstract_syntax_error_reject, "abstract_syntax_error_reject"},
    {CauseProtocol::abstract_syntax_error_ignore_and_notify, "abstract_syntax_error_ignore_and_notify"},
    {CauseProtocol::message_not_compatible_with_receiver_state, "message_not_compatible_with_receiver_state"},
    {CauseProtocol::semantic_error, "semantic_error"},
    {CauseProtocol::abstract_syntax_error_falsely_constructed_message, "abstract_syntax_error_falsely_constructed_message"},
    {CauseProtocol::unspecified, "unspecified"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(CauseRadioNetwork, {
    {CauseRadioNetwork::unspecified, "unspecified"},
    {CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id, "unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id"},
    {CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id, "unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id"},
    {CauseRadioNetwork::unknown_or_inconsistent_pair_of_ue_e1ap_id, "unknown_or_inconsistent_pair_of_ue_e1ap_id"},
    {CauseRadioNetwork::interaction_with_other_procedure, "interaction_with_other_procedure"},
    {CauseRadioNetwork::pPDCP_Count_wrap_around, "pPDCP_Count_wrap_around"},
    {CauseRadioNetwork::not_supported_QCI_value, "not_supported_QCI_value"},
    {CauseRadioNetwork::not_supported_5QI_value, "not_supported_5QI_value"},
    {CauseRadioNetwork::encryption_algorithms_not_supported, "encryption_algorithms_not_supported"},
    {CauseRadioNetwork::integrity_protection_algorithms_not_supported, "integrity_protection_algorithms_not_supported"},
    {CauseRadioNetwork::uP_integrity_protection_not_possible, "uP_integrity_protection_not_possible"},
    {CauseRadioNetwork::uP_confidentiality_protection_not_possible, "uP_confidentiality_protection_not_possible"},
    {CauseRadioNetwork::multiple_PDU_Session_ID_Instances, "multiple_PDU_Session_ID_Instances"},
    {CauseRadioNetwork::unknown_PDU_Session_ID, "unknown_PDU_Session_ID"},
    {CauseRadioNetwork::multiple_QoS_Flow_ID_Instances, "multiple_QoS_Flow_ID_Instances"},
    {CauseRadioNetwork::unknown_QoS_Flow_ID, "unknown_QoS_Flow_ID"},
    {CauseRadioNetwork::multiple_DRB_ID_Instances, "multiple_DRB_ID_Instances"},
    {CauseRadioNetwork::unknown_DRB_ID, "unknown_DRB_ID"},
    {CauseRadioNetwork::invalid_QoS_combination, "invalid_QoS_combination"},
    {CauseRadioNetwork::procedure_cancelled, "procedure_cancelled"},
    {CauseRadioNetwork::normal_release, "normal_release"},
    {CauseRadioNetwork::no_radio_resources_available, "no_radio_resources_available"},
    {CauseRadioNetwork::action_desirable_for_radio_reasons, "action_desirable_for_radio_reasons"},
    {CauseRadioNetwork::resources_not_available_for_the_slice, "resources_not_available_for_the_slice"},
    {CauseRadioNetwork::pDCP_configuration_not_supported, "pDCP_configuration_not_supported"},
    {CauseRadioNetwork::ue_dl_max_IP_data_rate_reason, "ue_dl_max_IP_data_rate_reason"},
    {CauseRadioNetwork::uP_integrity_protection_failure, "uP_integrity_protection_failure"},
    {CauseRadioNetwork::release_due_to_pre_emption, "release_due_to_pre_emption"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(CauseTransport, {
    {CauseTransport::unspecified, "unspecified"},
    {CauseTransport::transport_resource_unavailable, "transport_resource_unavailable"}
})

inline void to_json(nlohmann::json& j, const Cause& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, Cause_radioNetwork>) {
            j = nlohmann::json{{"radioNetwork", alt.radioNetwork}};
        } else
        if constexpr (std::is_same_v<T, Cause_transport>) {
            j = nlohmann::json{{"transport", alt.transport}};
        } else
        if constexpr (std::is_same_v<T, Cause_protocol>) {
            j = nlohmann::json{{"protocol", alt.protocol}};
        } else
        if constexpr (std::is_same_v<T, Cause_misc>) {
            j = nlohmann::json{{"misc", alt.misc}};
        } else
        if constexpr (std::is_same_v<T, Cause_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, Cause& v) {
    if (j.contains("radioNetwork")) {
        Cause_radioNetwork alt;
        j.at("radioNetwork").get_to(alt.radioNetwork);
        v = std::move(alt);
        return;
    }
    if (j.contains("transport")) {
        Cause_transport alt;
        j.at("transport").get_to(alt.transport);
        v = std::move(alt);
        return;
    }
    if (j.contains("protocol")) {
        Cause_protocol alt;
        j.at("protocol").get_to(alt.protocol);
        v = std::move(alt);
        return;
    }
    if (j.contains("misc")) {
        Cause_misc alt;
        j.at("misc").get_to(alt.misc);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        Cause_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

NLOHMANN_JSON_SERIALIZE_ENUM(CipheringAlgorithm, {
    {CipheringAlgorithm::nEA0, "nEA0"},
    {CipheringAlgorithm::c_128_NEA1, "c_128_NEA1"},
    {CipheringAlgorithm::c_128_NEA2, "c_128_NEA2"},
    {CipheringAlgorithm::c_128_NEA3, "c_128_NEA3"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(CNSupport, {
    {CNSupport::c_epc, "c_epc"},
    {CNSupport::c_5gc, "c_5gc"},
    {CNSupport::both, "both"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(ConfidentialityProtectionIndication, {
    {ConfidentialityProtectionIndication::required, "required"},
    {ConfidentialityProtectionIndication::preferred, "preferred"},
    {ConfidentialityProtectionIndication::not_needed, "not_needed"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(ConfidentialityProtectionResult, {
    {ConfidentialityProtectionResult::performed, "performed"},
    {ConfidentialityProtectionResult::not_performed, "not_performed"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(Data_Forwarding_Request, {
    {Data_Forwarding_Request::uL, "uL"},
    {Data_Forwarding_Request::dL, "dL"},
    {Data_Forwarding_Request::both, "both"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(DefaultDRB, {
    {DefaultDRB::true_, "true_"},
    {DefaultDRB::false_, "false_"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(DiscardTimer, {
    {DiscardTimer::ms10, "ms10"},
    {DiscardTimer::ms20, "ms20"},
    {DiscardTimer::ms30, "ms30"},
    {DiscardTimer::ms40, "ms40"},
    {DiscardTimer::ms50, "ms50"},
    {DiscardTimer::ms60, "ms60"},
    {DiscardTimer::ms75, "ms75"},
    {DiscardTimer::ms100, "ms100"},
    {DiscardTimer::ms150, "ms150"},
    {DiscardTimer::ms200, "ms200"},
    {DiscardTimer::ms250, "ms250"},
    {DiscardTimer::ms300, "ms300"},
    {DiscardTimer::ms500, "ms500"},
    {DiscardTimer::ms750, "ms750"},
    {DiscardTimer::ms1500, "ms1500"},
    {DiscardTimer::infinity, "infinity"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(DL_TX_Stop, {
    {DL_TX_Stop::stop, "stop"},
    {DL_TX_Stop::resume, "resume"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(DRB_Activity, {
    {DRB_Activity::active, "active"},
    {DRB_Activity::not_active, "not_active"}
})

inline void to_json(nlohmann::json& j, const DRB_Activity_Item& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["dRB-Activity"] = v.dRB_Activity;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Activity_Item& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("dRB-Activity")) {
        j.at("dRB-Activity").get_to(v.dRB_Activity);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_Mod_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_Mod_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_Mod_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_Mod_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_To_Modify_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_To_Modify_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Failed_To_Modify_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Failed_To_Modify_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Remove_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Remove_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Required_To_Remove_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Required_To_Remove_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Remove_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Remove_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Required_To_Remove_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Required_To_Remove_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Usage_Report_Item& v) {
    j = nlohmann::json::object();
    j["startTimeStamp"] = v.startTimeStamp;
    j["endTimeStamp"] = v.endTimeStamp;
    j["usageCountUL"] = v.usageCountUL;
    j["usageCountDL"] = v.usageCountDL;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Usage_Report_Item& v) {
    if (j.contains("startTimeStamp")) {
        j.at("startTimeStamp").get_to(v.startTimeStamp);
    }
    if (j.contains("endTimeStamp")) {
        j.at("endTimeStamp").get_to(v.endTimeStamp);
    }
    if (j.contains("usageCountUL")) {
        j.at("usageCountUL").get_to(v.usageCountUL);
    }
    if (j.contains("usageCountDL")) {
        j.at("usageCountDL").get_to(v.usageCountDL);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(Duplication_Activation, {
    {Duplication_Activation::active, "active"},
    {Duplication_Activation::inactive, "inactive"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(DataDiscardRequired, {
    {DataDiscardRequired::required, "required"}
})

inline void to_json(nlohmann::json& j, const GBR_QosInformation& v) {
    j = nlohmann::json::object();
    j["e-RAB-MaximumBitrateDL"] = v.e_RAB_MaximumBitrateDL;
    j["e-RAB-MaximumBitrateUL"] = v.e_RAB_MaximumBitrateUL;
    j["e-RAB-GuaranteedBitrateDL"] = v.e_RAB_GuaranteedBitrateDL;
    j["e-RAB-GuaranteedBitrateUL"] = v.e_RAB_GuaranteedBitrateUL;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GBR_QosInformation& v) {
    if (j.contains("e-RAB-MaximumBitrateDL")) {
        j.at("e-RAB-MaximumBitrateDL").get_to(v.e_RAB_MaximumBitrateDL);
    }
    if (j.contains("e-RAB-MaximumBitrateUL")) {
        j.at("e-RAB-MaximumBitrateUL").get_to(v.e_RAB_MaximumBitrateUL);
    }
    if (j.contains("e-RAB-GuaranteedBitrateDL")) {
        j.at("e-RAB-GuaranteedBitrateDL").get_to(v.e_RAB_GuaranteedBitrateDL);
    }
    if (j.contains("e-RAB-GuaranteedBitrateUL")) {
        j.at("e-RAB-GuaranteedBitrateUL").get_to(v.e_RAB_GuaranteedBitrateUL);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(GNB_CU_UP_OverloadInformation, {
    {GNB_CU_UP_OverloadInformation::overloaded, "overloaded"},
    {GNB_CU_UP_OverloadInformation::not_overloaded, "not_overloaded"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(IntegrityProtectionIndication, {
    {IntegrityProtectionIndication::required, "required"},
    {IntegrityProtectionIndication::preferred, "preferred"},
    {IntegrityProtectionIndication::not_needed, "not_needed"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(IntegrityProtectionAlgorithm, {
    {IntegrityProtectionAlgorithm::nIA0, "nIA0"},
    {IntegrityProtectionAlgorithm::i_128_NIA1, "i_128_NIA1"},
    {IntegrityProtectionAlgorithm::i_128_NIA2, "i_128_NIA2"},
    {IntegrityProtectionAlgorithm::i_128_NIA3, "i_128_NIA3"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(IntegrityProtectionResult, {
    {IntegrityProtectionResult::performed, "performed"},
    {IntegrityProtectionResult::not_performed, "not_performed"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(MaxIPrate, {
    {MaxIPrate::bitrate64kbs, "bitrate64kbs"},
    {MaxIPrate::max_UErate, "max_UErate"}
})

inline void to_json(nlohmann::json& j, const MaximumIPdatarate& v) {
    j = nlohmann::json::object();
    j["maxIPrate"] = v.maxIPrate;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, MaximumIPdatarate& v) {
    if (j.contains("maxIPrate")) {
        j.at("maxIPrate").get_to(v.maxIPrate);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GBR_QoSFlowInformation& v) {
    j = nlohmann::json::object();
    j["maxFlowBitRateDownlink"] = v.maxFlowBitRateDownlink;
    j["maxFlowBitRateUplink"] = v.maxFlowBitRateUplink;
    j["guaranteedFlowBitRateDownlink"] = v.guaranteedFlowBitRateDownlink;
    j["guaranteedFlowBitRateUplink"] = v.guaranteedFlowBitRateUplink;
    if (v.maxPacketLossRateDownlink.has_value()) {
        j["maxPacketLossRateDownlink"] = *v.maxPacketLossRateDownlink;
    }
    if (v.maxPacketLossRateUplink.has_value()) {
        j["maxPacketLossRateUplink"] = *v.maxPacketLossRateUplink;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GBR_QoSFlowInformation& v) {
    if (j.contains("maxFlowBitRateDownlink")) {
        j.at("maxFlowBitRateDownlink").get_to(v.maxFlowBitRateDownlink);
    }
    if (j.contains("maxFlowBitRateUplink")) {
        j.at("maxFlowBitRateUplink").get_to(v.maxFlowBitRateUplink);
    }
    if (j.contains("guaranteedFlowBitRateDownlink")) {
        j.at("guaranteedFlowBitRateDownlink").get_to(v.guaranteedFlowBitRateDownlink);
    }
    if (j.contains("guaranteedFlowBitRateUplink")) {
        j.at("guaranteedFlowBitRateUplink").get_to(v.guaranteedFlowBitRateUplink);
    }
    if (j.contains("maxPacketLossRateDownlink") && !j.at("maxPacketLossRateDownlink").is_null()) {
        decltype(v.maxPacketLossRateDownlink)::value_type tmp{};
        j.at("maxPacketLossRateDownlink").get_to(tmp);
        v.maxPacketLossRateDownlink = std::move(tmp);
    }
    if (j.contains("maxPacketLossRateUplink") && !j.at("maxPacketLossRateUplink").is_null()) {
        decltype(v.maxPacketLossRateUplink)::value_type tmp{};
        j.at("maxPacketLossRateUplink").get_to(tmp);
        v.maxPacketLossRateUplink = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const MRDC_Data_Usage_Report_Item& v) {
    j = nlohmann::json::object();
    j["startTimeStamp"] = v.startTimeStamp;
    j["endTimeStamp"] = v.endTimeStamp;
    j["usageCountUL"] = v.usageCountUL;
    j["usageCountDL"] = v.usageCountDL;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, MRDC_Data_Usage_Report_Item& v) {
    if (j.contains("startTimeStamp")) {
        j.at("startTimeStamp").get_to(v.startTimeStamp);
    }
    if (j.contains("endTimeStamp")) {
        j.at("endTimeStamp").get_to(v.endTimeStamp);
    }
    if (j.contains("usageCountUL")) {
        j.at("usageCountUL").get_to(v.usageCountUL);
    }
    if (j.contains("usageCountDL")) {
        j.at("usageCountDL").get_to(v.usageCountDL);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(Data_Usage_per_PDU_Session_Report::secondaryRATType_type, {
    {Data_Usage_per_PDU_Session_Report::secondaryRATType_type::nR, "nR"},
    {Data_Usage_per_PDU_Session_Report::secondaryRATType_type::e_UTRA, "e_UTRA"}
})

inline void to_json(nlohmann::json& j, const Data_Usage_per_PDU_Session_Report& v) {
    j = nlohmann::json::object();
    j["secondaryRATType"] = v.secondaryRATType;
    j["pDU-session-Timed-Report-List"] = v.pDU_session_Timed_Report_List;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Data_Usage_per_PDU_Session_Report& v) {
    if (j.contains("secondaryRATType")) {
        j.at("secondaryRATType").get_to(v.secondaryRATType);
    }
    if (j.contains("pDU-session-Timed-Report-List")) {
        j.at("pDU-session-Timed-Report-List").get_to(v.pDU_session_Timed_Report_List);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(New_UL_TNL_Information_Required, {
    {New_UL_TNL_Information_Required::required, "required"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(OutOfOrderDelivery, {
    {OutOfOrderDelivery::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const PacketErrorRate& v) {
    j = nlohmann::json::object();
    j["pER-Scalar"] = v.pER_Scalar;
    j["pER-Exponent"] = v.pER_Exponent;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PacketErrorRate& v) {
    if (j.contains("pER-Scalar")) {
        j.at("pER-Scalar").get_to(v.pER_Scalar);
    }
    if (j.contains("pER-Exponent")) {
        j.at("pER-Exponent").get_to(v.pER_Exponent);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(PDCP_SN_Status_Request, {
    {PDCP_SN_Status_Request::requested, "requested"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(PDCP_DataRecovery, {
    {PDCP_DataRecovery::true_, "true_"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(PDCP_Duplication, {
    {PDCP_Duplication::true_, "true_"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(PDCP_Reestablishment, {
    {PDCP_Reestablishment::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const PDCP_Count& v) {
    j = nlohmann::json::object();
    j["pDCP-SN"] = v.pDCP_SN;
    j["hFN"] = v.hFN;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDCP_Count& v) {
    if (j.contains("pDCP-SN")) {
        j.at("pDCP-SN").get_to(v.pDCP_SN);
    }
    if (j.contains("hFN")) {
        j.at("hFN").get_to(v.hFN);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Status_Item& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.pDCP_DL_Count.has_value()) {
        j["pDCP-DL-Count"] = *v.pDCP_DL_Count;
    }
    if (v.pDCP_UL_Count.has_value()) {
        j["pDCP-UL-Count"] = *v.pDCP_UL_Count;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Status_Item& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-DL-Count") && !j.at("pDCP-DL-Count").is_null()) {
        decltype(v.pDCP_DL_Count)::value_type tmp{};
        j.at("pDCP-DL-Count").get_to(tmp);
        v.pDCP_DL_Count = std::move(tmp);
    }
    if (j.contains("pDCP-UL-Count") && !j.at("pDCP-UL-Count").is_null()) {
        decltype(v.pDCP_UL_Count)::value_type tmp{};
        j.at("pDCP-UL-Count").get_to(tmp);
        v.pDCP_UL_Count = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRBs_Subject_To_Counter_Check_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["pDCP-UL-Count"] = v.pDCP_UL_Count;
    j["pDCP-DL-Count"] = v.pDCP_DL_Count;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRBs_Subject_To_Counter_Check_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-UL-Count")) {
        j.at("pDCP-UL-Count").get_to(v.pDCP_UL_Count);
    }
    if (j.contains("pDCP-DL-Count")) {
        j.at("pDCP-DL-Count").get_to(v.pDCP_DL_Count);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(PDCP_SN_Size, {
    {PDCP_SN_Size::s_12, "s_12"},
    {PDCP_SN_Size::s_18, "s_18"}
})

inline void to_json(nlohmann::json& j, const DRBBStatusTransfer& v) {
    j = nlohmann::json::object();
    if (v.receiveStatusofPDCPSDU.has_value()) {
        j["receiveStatusofPDCPSDU"] = *v.receiveStatusofPDCPSDU;
    }
    j["countValue"] = v.countValue;
    if (v.iE_Extension.has_value()) {
        j["iE-Extension"] = *v.iE_Extension;
    }
}

inline void from_json(const nlohmann::json& j, DRBBStatusTransfer& v) {
    if (j.contains("receiveStatusofPDCPSDU") && !j.at("receiveStatusofPDCPSDU").is_null()) {
        decltype(v.receiveStatusofPDCPSDU)::value_type tmp{};
        j.at("receiveStatusofPDCPSDU").get_to(tmp);
        v.receiveStatusofPDCPSDU = std::move(tmp);
    }
    if (j.contains("countValue")) {
        j.at("countValue").get_to(v.countValue);
    }
    if (j.contains("iE-Extension") && !j.at("iE-Extension").is_null()) {
        decltype(v.iE_Extension)::value_type tmp{};
        j.at("iE-Extension").get_to(tmp);
        v.iE_Extension = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDCP_SN_Status_Information& v) {
    j = nlohmann::json::object();
    j["pdcpStatusTransfer-UL"] = v.pdcpStatusTransfer_UL;
    j["pdcpStatusTransfer-DL"] = v.pdcpStatusTransfer_DL;
    if (v.iE_Extension.has_value()) {
        j["iE-Extension"] = *v.iE_Extension;
    }
}

inline void from_json(const nlohmann::json& j, PDCP_SN_Status_Information& v) {
    if (j.contains("pdcpStatusTransfer-UL")) {
        j.at("pdcpStatusTransfer-UL").get_to(v.pdcpStatusTransfer_UL);
    }
    if (j.contains("pdcpStatusTransfer-DL")) {
        j.at("pdcpStatusTransfer-DL").get_to(v.pdcpStatusTransfer_DL);
    }
    if (j.contains("iE-Extension") && !j.at("iE-Extension").is_null()) {
        decltype(v.iE_Extension)::value_type tmp{};
        j.at("iE-Extension").get_to(tmp);
        v.iE_Extension = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRBs_Subject_To_Counter_Check_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["dRB-ID"] = v.dRB_ID;
    j["pDCP-UL-Count"] = v.pDCP_UL_Count;
    j["pDCP-DL-Count"] = v.pDCP_DL_Count;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRBs_Subject_To_Counter_Check_Item_NG_RAN& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-UL-Count")) {
        j.at("pDCP-UL-Count").get_to(v.pDCP_UL_Count);
    }
    if (j.contains("pDCP-DL-Count")) {
        j.at("pDCP-DL-Count").get_to(v.pDCP_DL_Count);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(PDU_Session_Resource_Activity, {
    {PDU_Session_Resource_Activity::active, "active"},
    {PDU_Session_Resource_Activity::not_active, "not_active"}
})

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Activity_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["pDU-Session-Resource-Activity"] = v.pDU_Session_Resource_Activity;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Activity_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("pDU-Session-Resource-Activity")) {
        j.at("pDU-Session-Resource-Activity").get_to(v.pDU_Session_Resource_Activity);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Failed_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Failed_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Failed_Mod_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Failed_Mod_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Failed_To_Modify_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Failed_To_Modify_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_To_Remove_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_To_Remove_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(PDU_Session_Type, {
    {PDU_Session_Type::ipv4, "ipv4"},
    {PDU_Session_Type::ipv6, "ipv6"},
    {PDU_Session_Type::ipv4v6, "ipv4v6"},
    {PDU_Session_Type::ethernet, "ethernet"},
    {PDU_Session_Type::unstructured, "unstructured"}
})

inline void to_json(nlohmann::json& j, const NR_CGI& v) {
    j = nlohmann::json::object();
    j["pLMN-Identity"] = v.pLMN_Identity;
    j["nR-Cell-Identity"] = v.nR_Cell_Identity;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, NR_CGI& v) {
    if (j.contains("pLMN-Identity")) {
        j.at("pLMN-Identity").get_to(v.pLMN_Identity);
    }
    if (j.contains("nR-Cell-Identity")) {
        j.at("nR-Cell-Identity").get_to(v.nR_Cell_Identity);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const NR_CGI_Support_Item& v) {
    j = nlohmann::json::object();
    j["nR-CGI"] = v.nR_CGI;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, NR_CGI_Support_Item& v) {
    if (j.contains("nR-CGI")) {
        j.at("nR-CGI").get_to(v.nR_CGI);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(Pre_emptionCapability, {
    {Pre_emptionCapability::shall_not_trigger_pre_emption, "shall_not_trigger_pre_emption"},
    {Pre_emptionCapability::may_trigger_pre_emption, "may_trigger_pre_emption"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(Pre_emptionVulnerability, {
    {Pre_emptionVulnerability::not_pre_emptable, "not_pre_emptable"},
    {Pre_emptionVulnerability::pre_emptable, "pre_emptable"}
})

inline void to_json(nlohmann::json& j, const EUTRANAllocationAndRetentionPriority& v) {
    j = nlohmann::json::object();
    j["priorityLevel"] = v.priorityLevel;
    j["pre-emptionCapability"] = v.pre_emptionCapability;
    j["pre-emptionVulnerability"] = v.pre_emptionVulnerability;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, EUTRANAllocationAndRetentionPriority& v) {
    if (j.contains("priorityLevel")) {
        j.at("priorityLevel").get_to(v.priorityLevel);
    }
    if (j.contains("pre-emptionCapability")) {
        j.at("pre-emptionCapability").get_to(v.pre_emptionCapability);
    }
    if (j.contains("pre-emptionVulnerability")) {
        j.at("pre-emptionVulnerability").get_to(v.pre_emptionVulnerability);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const NGRANAllocationAndRetentionPriority& v) {
    j = nlohmann::json::object();
    j["priorityLevel"] = v.priorityLevel;
    j["pre-emptionCapability"] = v.pre_emptionCapability;
    j["pre-emptionVulnerability"] = v.pre_emptionVulnerability;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, NGRANAllocationAndRetentionPriority& v) {
    if (j.contains("priorityLevel")) {
        j.at("priorityLevel").get_to(v.priorityLevel);
    }
    if (j.contains("pre-emptionCapability")) {
        j.at("pre-emptionCapability").get_to(v.pre_emptionCapability);
    }
    if (j.contains("pre-emptionVulnerability")) {
        j.at("pre-emptionVulnerability").get_to(v.pre_emptionVulnerability);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const EUTRAN_QoS& v) {
    j = nlohmann::json::object();
    j["qCI"] = v.qCI;
    j["eUTRANallocationAndRetentionPriority"] = v.eUTRANallocationAndRetentionPriority;
    if (v.gbrQosInformation.has_value()) {
        j["gbrQosInformation"] = *v.gbrQosInformation;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, EUTRAN_QoS& v) {
    if (j.contains("qCI")) {
        j.at("qCI").get_to(v.qCI);
    }
    if (j.contains("eUTRANallocationAndRetentionPriority")) {
        j.at("eUTRANallocationAndRetentionPriority").get_to(v.eUTRANallocationAndRetentionPriority);
    }
    if (j.contains("gbrQosInformation") && !j.at("gbrQosInformation").is_null()) {
        decltype(v.gbrQosInformation)::value_type tmp{};
        j.at("gbrQosInformation").get_to(tmp);
        v.gbrQosInformation = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const EUTRAN_QoS_Support_Item& v) {
    j = nlohmann::json::object();
    j["eUTRAN-QoS"] = v.eUTRAN_QoS;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, EUTRAN_QoS_Support_Item& v) {
    if (j.contains("eUTRAN-QoS")) {
        j.at("eUTRAN-QoS").get_to(v.eUTRAN_QoS);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(Data_Usage_per_QoS_Flow_Item::secondaryRATType_type, {
    {Data_Usage_per_QoS_Flow_Item::secondaryRATType_type::nR, "nR"},
    {Data_Usage_per_QoS_Flow_Item::secondaryRATType_type::e_UTRA, "e_UTRA"}
})

inline void to_json(nlohmann::json& j, const Data_Usage_per_QoS_Flow_Item& v) {
    j = nlohmann::json::object();
    j["qoS-Flow-Identifier"] = v.qoS_Flow_Identifier;
    j["secondaryRATType"] = v.secondaryRATType;
    j["qoS-Flow-Timed-Report-List"] = v.qoS_Flow_Timed_Report_List;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Data_Usage_per_QoS_Flow_Item& v) {
    if (j.contains("qoS-Flow-Identifier")) {
        j.at("qoS-Flow-Identifier").get_to(v.qoS_Flow_Identifier);
    }
    if (j.contains("secondaryRATType")) {
        j.at("secondaryRATType").get_to(v.secondaryRATType);
    }
    if (j.contains("qoS-Flow-Timed-Report-List")) {
        j.at("qoS-Flow-Timed-Report-List").get_to(v.qoS_Flow_Timed_Report_List);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const MRDC_Usage_Information& v) {
    j = nlohmann::json::object();
    if (v.data_Usage_per_PDU_Session_Report.has_value()) {
        j["data-Usage-per-PDU-Session-Report"] = *v.data_Usage_per_PDU_Session_Report;
    }
    if (v.data_Usage_per_QoS_Flow_List.has_value()) {
        j["data-Usage-per-QoS-Flow-List"] = *v.data_Usage_per_QoS_Flow_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, MRDC_Usage_Information& v) {
    if (j.contains("data-Usage-per-PDU-Session-Report") && !j.at("data-Usage-per-PDU-Session-Report").is_null()) {
        decltype(v.data_Usage_per_PDU_Session_Report)::value_type tmp{};
        j.at("data-Usage-per-PDU-Session-Report").get_to(tmp);
        v.data_Usage_per_PDU_Session_Report = std::move(tmp);
    }
    if (j.contains("data-Usage-per-QoS-Flow-List") && !j.at("data-Usage-per-QoS-Flow-List").is_null()) {
        decltype(v.data_Usage_per_QoS_Flow_List)::value_type tmp{};
        j.at("data-Usage-per-QoS-Flow-List").get_to(tmp);
        v.data_Usage_per_QoS_Flow_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Data_Usage_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["mRDC-Usage-Information"] = v.mRDC_Usage_Information;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Data_Usage_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("mRDC-Usage-Information")) {
        j.at("mRDC-Usage-Information").get_to(v.mRDC_Usage_Information);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const QoS_Flow_Item& v) {
    j = nlohmann::json::object();
    j["qoS-Flow-Identifier"] = v.qoS_Flow_Identifier;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoS_Flow_Item& v) {
    if (j.contains("qoS-Flow-Identifier")) {
        j.at("qoS-Flow-Identifier").get_to(v.qoS_Flow_Identifier);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_To_Notify_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["qoS-Flow-List"] = v.qoS_Flow_List;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_To_Notify_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("qoS-Flow-List")) {
        j.at("qoS-Flow-List").get_to(v.qoS_Flow_List);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const QoS_Flow_Failed_Item& v) {
    j = nlohmann::json::object();
    j["qoS-Flow-Identifier"] = v.qoS_Flow_Identifier;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoS_Flow_Failed_Item& v) {
    if (j.contains("qoS-Flow-Identifier")) {
        j.at("qoS-Flow-Identifier").get_to(v.qoS_Flow_Identifier);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(QoS_Flow_Mapping_Indication, {
    {QoS_Flow_Mapping_Indication::ul, "ul"},
    {QoS_Flow_Mapping_Indication::dl, "dl"}
})

inline void to_json(nlohmann::json& j, const QoS_Flow_Mapping_Item& v) {
    j = nlohmann::json::object();
    j["qoS-Flow-Identifier"] = v.qoS_Flow_Identifier;
    if (v.qoSFlowMappingIndication.has_value()) {
        j["qoSFlowMappingIndication"] = *v.qoSFlowMappingIndication;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoS_Flow_Mapping_Item& v) {
    if (j.contains("qoS-Flow-Identifier")) {
        j.at("qoS-Flow-Identifier").get_to(v.qoS_Flow_Identifier);
    }
    if (j.contains("qoSFlowMappingIndication") && !j.at("qoSFlowMappingIndication").is_null()) {
        decltype(v.qoSFlowMappingIndication)::value_type tmp{};
        j.at("qoSFlowMappingIndication").get_to(tmp);
        v.qoSFlowMappingIndication = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const Data_Forwarding_Information_Request& v) {
    j = nlohmann::json::object();
    j["data-Forwarding-Request"] = v.data_Forwarding_Request;
    if (v.qoS_Flows_Forwarded_On_Fwd_Tunnels.has_value()) {
        j["qoS-Flows-Forwarded-On-Fwd-Tunnels"] = *v.qoS_Flows_Forwarded_On_Fwd_Tunnels;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Data_Forwarding_Information_Request& v) {
    if (j.contains("data-Forwarding-Request")) {
        j.at("data-Forwarding-Request").get_to(v.data_Forwarding_Request);
    }
    if (j.contains("qoS-Flows-Forwarded-On-Fwd-Tunnels") && !j.at("qoS-Flows-Forwarded-On-Fwd-Tunnels").is_null()) {
        decltype(v.qoS_Flows_Forwarded_On_Fwd_Tunnels)::value_type tmp{};
        j.at("qoS-Flows-Forwarded-On-Fwd-Tunnels").get_to(tmp);
        v.qoS_Flows_Forwarded_On_Fwd_Tunnels = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(Dynamic5QIDescriptor::delayCritical_type, {
    {Dynamic5QIDescriptor::delayCritical_type::delay_critical, "delay_critical"},
    {Dynamic5QIDescriptor::delayCritical_type::non_delay_critical, "non_delay_critical"}
})

inline void to_json(nlohmann::json& j, const Dynamic5QIDescriptor& v) {
    j = nlohmann::json::object();
    j["qoSPriorityLevel"] = v.qoSPriorityLevel;
    j["packetDelayBudget"] = v.packetDelayBudget;
    j["packetErrorRate"] = v.packetErrorRate;
    if (v.fiveQI.has_value()) {
        j["fiveQI"] = *v.fiveQI;
    }
    if (v.delayCritical.has_value()) {
        j["delayCritical"] = *v.delayCritical;
    }
    if (v.averagingWindow.has_value()) {
        j["averagingWindow"] = *v.averagingWindow;
    }
    if (v.maxDataBurstVolume.has_value()) {
        j["maxDataBurstVolume"] = *v.maxDataBurstVolume;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Dynamic5QIDescriptor& v) {
    if (j.contains("qoSPriorityLevel")) {
        j.at("qoSPriorityLevel").get_to(v.qoSPriorityLevel);
    }
    if (j.contains("packetDelayBudget")) {
        j.at("packetDelayBudget").get_to(v.packetDelayBudget);
    }
    if (j.contains("packetErrorRate")) {
        j.at("packetErrorRate").get_to(v.packetErrorRate);
    }
    if (j.contains("fiveQI") && !j.at("fiveQI").is_null()) {
        decltype(v.fiveQI)::value_type tmp{};
        j.at("fiveQI").get_to(tmp);
        v.fiveQI = std::move(tmp);
    }
    if (j.contains("delayCritical") && !j.at("delayCritical").is_null()) {
        decltype(v.delayCritical)::value_type tmp{};
        j.at("delayCritical").get_to(tmp);
        v.delayCritical = std::move(tmp);
    }
    if (j.contains("averagingWindow") && !j.at("averagingWindow").is_null()) {
        decltype(v.averagingWindow)::value_type tmp{};
        j.at("averagingWindow").get_to(tmp);
        v.averagingWindow = std::move(tmp);
    }
    if (j.contains("maxDataBurstVolume") && !j.at("maxDataBurstVolume").is_null()) {
        decltype(v.maxDataBurstVolume)::value_type tmp{};
        j.at("maxDataBurstVolume").get_to(tmp);
        v.maxDataBurstVolume = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const Non_Dynamic5QIDescriptor& v) {
    j = nlohmann::json::object();
    j["fiveQI"] = v.fiveQI;
    if (v.qoSPriorityLevel.has_value()) {
        j["qoSPriorityLevel"] = *v.qoSPriorityLevel;
    }
    if (v.averagingWindow.has_value()) {
        j["averagingWindow"] = *v.averagingWindow;
    }
    if (v.maxDataBurstVolume.has_value()) {
        j["maxDataBurstVolume"] = *v.maxDataBurstVolume;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Non_Dynamic5QIDescriptor& v) {
    if (j.contains("fiveQI")) {
        j.at("fiveQI").get_to(v.fiveQI);
    }
    if (j.contains("qoSPriorityLevel") && !j.at("qoSPriorityLevel").is_null()) {
        decltype(v.qoSPriorityLevel)::value_type tmp{};
        j.at("qoSPriorityLevel").get_to(tmp);
        v.qoSPriorityLevel = std::move(tmp);
    }
    if (j.contains("averagingWindow") && !j.at("averagingWindow").is_null()) {
        decltype(v.averagingWindow)::value_type tmp{};
        j.at("averagingWindow").get_to(tmp);
        v.averagingWindow = std::move(tmp);
    }
    if (j.contains("maxDataBurstVolume") && !j.at("maxDataBurstVolume").is_null()) {
        decltype(v.maxDataBurstVolume)::value_type tmp{};
        j.at("maxDataBurstVolume").get_to(tmp);
        v.maxDataBurstVolume = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const NG_RAN_QoS_Support_Item& v) {
    j = nlohmann::json::object();
    j["non-Dynamic5QIDescriptor"] = v.non_Dynamic5QIDescriptor;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, NG_RAN_QoS_Support_Item& v) {
    if (j.contains("non-Dynamic5QIDescriptor")) {
        j.at("non-Dynamic5QIDescriptor").get_to(v.non_Dynamic5QIDescriptor);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const QoS_Characteristics& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, QoS_Characteristics_non_Dynamic_5QI>) {
            j = nlohmann::json{{"non_Dynamic_5QI", alt.non_Dynamic_5QI}};
        } else
        if constexpr (std::is_same_v<T, QoS_Characteristics_dynamic_5QI>) {
            j = nlohmann::json{{"dynamic_5QI", alt.dynamic_5QI}};
        } else
        if constexpr (std::is_same_v<T, QoS_Characteristics_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, QoS_Characteristics& v) {
    if (j.contains("non_Dynamic_5QI")) {
        QoS_Characteristics_non_Dynamic_5QI alt;
        j.at("non_Dynamic_5QI").get_to(alt.non_Dynamic_5QI);
        v = std::move(alt);
        return;
    }
    if (j.contains("dynamic_5QI")) {
        QoS_Characteristics_dynamic_5QI alt;
        j.at("dynamic_5QI").get_to(alt.dynamic_5QI);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        QoS_Characteristics_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const QoS_Parameters_Support_List& v) {
    j = nlohmann::json::object();
    if (v.eUTRAN_QoS_Support_List.has_value()) {
        j["eUTRAN-QoS-Support-List"] = *v.eUTRAN_QoS_Support_List;
    }
    if (v.nG_RAN_QoS_Support_List.has_value()) {
        j["nG-RAN-QoS-Support-List"] = *v.nG_RAN_QoS_Support_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoS_Parameters_Support_List& v) {
    if (j.contains("eUTRAN-QoS-Support-List") && !j.at("eUTRAN-QoS-Support-List").is_null()) {
        decltype(v.eUTRAN_QoS_Support_List)::value_type tmp{};
        j.at("eUTRAN-QoS-Support-List").get_to(tmp);
        v.eUTRAN_QoS_Support_List = std::move(tmp);
    }
    if (j.contains("nG-RAN-QoS-Support-List") && !j.at("nG-RAN-QoS-Support-List").is_null()) {
        decltype(v.nG_RAN_QoS_Support_List)::value_type tmp{};
        j.at("nG-RAN-QoS-Support-List").get_to(tmp);
        v.nG_RAN_QoS_Support_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(QoSFlowLevelQoSParameters::reflective_QoS_Attribute_type, {
    {QoSFlowLevelQoSParameters::reflective_QoS_Attribute_type::subject_to, "subject_to"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(QoSFlowLevelQoSParameters::additional_QoS_Information_type, {
    {QoSFlowLevelQoSParameters::additional_QoS_Information_type::more_likely, "more_likely"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(QoSFlowLevelQoSParameters::reflective_QoS_Indicator_type, {
    {QoSFlowLevelQoSParameters::reflective_QoS_Indicator_type::enabled, "enabled"}
})

inline void to_json(nlohmann::json& j, const QoSFlowLevelQoSParameters& v) {
    j = nlohmann::json::object();
    j["qoS-Characteristics"] = v.qoS_Characteristics;
    j["nGRANallocationRetentionPriority"] = v.nGRANallocationRetentionPriority;
    if (v.gBR_QoS_Flow_Information.has_value()) {
        j["gBR-QoS-Flow-Information"] = *v.gBR_QoS_Flow_Information;
    }
    if (v.reflective_QoS_Attribute.has_value()) {
        j["reflective-QoS-Attribute"] = *v.reflective_QoS_Attribute;
    }
    if (v.additional_QoS_Information.has_value()) {
        j["additional-QoS-Information"] = *v.additional_QoS_Information;
    }
    if (v.paging_Policy_Indicator.has_value()) {
        j["paging-Policy-Indicator"] = *v.paging_Policy_Indicator;
    }
    if (v.reflective_QoS_Indicator.has_value()) {
        j["reflective-QoS-Indicator"] = *v.reflective_QoS_Indicator;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoSFlowLevelQoSParameters& v) {
    if (j.contains("qoS-Characteristics")) {
        j.at("qoS-Characteristics").get_to(v.qoS_Characteristics);
    }
    if (j.contains("nGRANallocationRetentionPriority")) {
        j.at("nGRANallocationRetentionPriority").get_to(v.nGRANallocationRetentionPriority);
    }
    if (j.contains("gBR-QoS-Flow-Information") && !j.at("gBR-QoS-Flow-Information").is_null()) {
        decltype(v.gBR_QoS_Flow_Information)::value_type tmp{};
        j.at("gBR-QoS-Flow-Information").get_to(tmp);
        v.gBR_QoS_Flow_Information = std::move(tmp);
    }
    if (j.contains("reflective-QoS-Attribute") && !j.at("reflective-QoS-Attribute").is_null()) {
        decltype(v.reflective_QoS_Attribute)::value_type tmp{};
        j.at("reflective-QoS-Attribute").get_to(tmp);
        v.reflective_QoS_Attribute = std::move(tmp);
    }
    if (j.contains("additional-QoS-Information") && !j.at("additional-QoS-Information").is_null()) {
        decltype(v.additional_QoS_Information)::value_type tmp{};
        j.at("additional-QoS-Information").get_to(tmp);
        v.additional_QoS_Information = std::move(tmp);
    }
    if (j.contains("paging-Policy-Indicator") && !j.at("paging-Policy-Indicator").is_null()) {
        decltype(v.paging_Policy_Indicator)::value_type tmp{};
        j.at("paging-Policy-Indicator").get_to(tmp);
        v.paging_Policy_Indicator = std::move(tmp);
    }
    if (j.contains("reflective-QoS-Indicator") && !j.at("reflective-QoS-Indicator").is_null()) {
        decltype(v.reflective_QoS_Indicator)::value_type tmp{};
        j.at("reflective-QoS-Indicator").get_to(tmp);
        v.reflective_QoS_Indicator = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const QoS_Flow_QoS_Parameter_Item& v) {
    j = nlohmann::json::object();
    j["qoS-Flow-Identifier"] = v.qoS_Flow_Identifier;
    j["qoSFlowLevelQoSParameters"] = v.qoSFlowLevelQoSParameters;
    if (v.qoSFlowMappingIndication.has_value()) {
        j["qoSFlowMappingIndication"] = *v.qoSFlowMappingIndication;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, QoS_Flow_QoS_Parameter_Item& v) {
    if (j.contains("qoS-Flow-Identifier")) {
        j.at("qoS-Flow-Identifier").get_to(v.qoS_Flow_Identifier);
    }
    if (j.contains("qoSFlowLevelQoSParameters")) {
        j.at("qoSFlowLevelQoSParameters").get_to(v.qoSFlowLevelQoSParameters);
    }
    if (j.contains("qoSFlowMappingIndication") && !j.at("qoSFlowMappingIndication").is_null()) {
        decltype(v.qoSFlowMappingIndication)::value_type tmp{};
        j.at("qoSFlowMappingIndication").get_to(tmp);
        v.qoSFlowMappingIndication = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(RAT_Type, {
    {RAT_Type::e_UTRA, "e_UTRA"},
    {RAT_Type::nR, "nR"}
})

inline void to_json(nlohmann::json& j, const Data_Usage_Report_Item& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["rAT-Type"] = v.rAT_Type;
    j["dRB-Usage-Report-List"] = v.dRB_Usage_Report_List;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Data_Usage_Report_Item& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("rAT-Type")) {
        j.at("rAT-Type").get_to(v.rAT_Type);
    }
    if (j.contains("dRB-Usage-Report-List")) {
        j.at("dRB-Usage-Report-List").get_to(v.dRB_Usage_Report_List);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(RLC_Mode, {
    {RLC_Mode::rlc_tm, "rlc_tm"},
    {RLC_Mode::rlc_am, "rlc_am"},
    {RLC_Mode::rlc_um_bidirectional, "rlc_um_bidirectional"},
    {RLC_Mode::rlc_um_unidirectional_ul, "rlc_um_unidirectional_ul"},
    {RLC_Mode::rlc_um_unidirectional_dl, "rlc_um_unidirectional_dl"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(ROHC::continueROHC_type, {
    {ROHC::continueROHC_type::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const ROHC& v) {
    j = nlohmann::json::object();
    j["maxCID"] = v.maxCID;
    j["rOHC-Profiles"] = v.rOHC_Profiles;
    if (v.continueROHC.has_value()) {
        j["continueROHC"] = *v.continueROHC;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, ROHC& v) {
    if (j.contains("maxCID")) {
        j.at("maxCID").get_to(v.maxCID);
    }
    if (j.contains("rOHC-Profiles")) {
        j.at("rOHC-Profiles").get_to(v.rOHC_Profiles);
    }
    if (j.contains("continueROHC") && !j.at("continueROHC").is_null()) {
        decltype(v.continueROHC)::value_type tmp{};
        j.at("continueROHC").get_to(tmp);
        v.continueROHC = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const SecurityAlgorithm& v) {
    j = nlohmann::json::object();
    j["cipheringAlgorithm"] = v.cipheringAlgorithm;
    if (v.integrityProtectionAlgorithm.has_value()) {
        j["integrityProtectionAlgorithm"] = *v.integrityProtectionAlgorithm;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SecurityAlgorithm& v) {
    if (j.contains("cipheringAlgorithm")) {
        j.at("cipheringAlgorithm").get_to(v.cipheringAlgorithm);
    }
    if (j.contains("integrityProtectionAlgorithm") && !j.at("integrityProtectionAlgorithm").is_null()) {
        decltype(v.integrityProtectionAlgorithm)::value_type tmp{};
        j.at("integrityProtectionAlgorithm").get_to(tmp);
        v.integrityProtectionAlgorithm = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const SecurityIndication& v) {
    j = nlohmann::json::object();
    j["integrityProtectionIndication"] = v.integrityProtectionIndication;
    j["confidentialityProtectionIndication"] = v.confidentialityProtectionIndication;
    if (v.maximumIPdatarate.has_value()) {
        j["maximumIPdatarate"] = *v.maximumIPdatarate;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SecurityIndication& v) {
    if (j.contains("integrityProtectionIndication")) {
        j.at("integrityProtectionIndication").get_to(v.integrityProtectionIndication);
    }
    if (j.contains("confidentialityProtectionIndication")) {
        j.at("confidentialityProtectionIndication").get_to(v.confidentialityProtectionIndication);
    }
    if (j.contains("maximumIPdatarate") && !j.at("maximumIPdatarate").is_null()) {
        decltype(v.maximumIPdatarate)::value_type tmp{};
        j.at("maximumIPdatarate").get_to(tmp);
        v.maximumIPdatarate = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const SecurityResult& v) {
    j = nlohmann::json::object();
    j["integrityProtectionResult"] = v.integrityProtectionResult;
    j["confidentialityProtectionResult"] = v.confidentialityProtectionResult;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SecurityResult& v) {
    if (j.contains("integrityProtectionResult")) {
        j.at("integrityProtectionResult").get_to(v.integrityProtectionResult);
    }
    if (j.contains("confidentialityProtectionResult")) {
        j.at("confidentialityProtectionResult").get_to(v.confidentialityProtectionResult);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const SNSSAI& v) {
    j = nlohmann::json::object();
    j["sST"] = v.sST;
    if (v.sD.has_value()) {
        j["sD"] = *v.sD;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SNSSAI& v) {
    if (j.contains("sST")) {
        j.at("sST").get_to(v.sST);
    }
    if (j.contains("sD") && !j.at("sD").is_null()) {
        decltype(v.sD)::value_type tmp{};
        j.at("sD").get_to(tmp);
        v.sD = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const Slice_Support_Item& v) {
    j = nlohmann::json::object();
    j["sNSSAI"] = v.sNSSAI;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Slice_Support_Item& v) {
    if (j.contains("sNSSAI")) {
        j.at("sNSSAI").get_to(v.sNSSAI);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(SDAP_Header_DL, {
    {SDAP_Header_DL::present, "present"},
    {SDAP_Header_DL::absent, "absent"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(SDAP_Header_UL, {
    {SDAP_Header_UL::present, "present"},
    {SDAP_Header_UL::absent, "absent"}
})

inline void to_json(nlohmann::json& j, const SDAP_Configuration& v) {
    j = nlohmann::json::object();
    j["defaultDRB"] = v.defaultDRB;
    j["sDAP-Header-UL"] = v.sDAP_Header_UL;
    j["sDAP-Header-DL"] = v.sDAP_Header_DL;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SDAP_Configuration& v) {
    if (j.contains("defaultDRB")) {
        j.at("defaultDRB").get_to(v.defaultDRB);
    }
    if (j.contains("sDAP-Header-UL")) {
        j.at("sDAP-Header-UL").get_to(v.sDAP_Header_UL);
    }
    if (j.contains("sDAP-Header-DL")) {
        j.at("sDAP-Header-DL").get_to(v.sDAP_Header_DL);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(TimeToWait, {
    {TimeToWait::v1s, "v1s"},
    {TimeToWait::v2s, "v2s"},
    {TimeToWait::v5s, "v5s"},
    {TimeToWait::v10s, "v10s"},
    {TimeToWait::v20s, "v20s"},
    {TimeToWait::v60s, "v60s"}
})

NLOHMANN_JSON_SERIALIZE_ENUM(TNLAssociationUsage, {
    {TNLAssociationUsage::ue, "ue"},
    {TNLAssociationUsage::non_ue, "non_ue"},
    {TNLAssociationUsage::both, "both"}
})

inline void to_json(nlohmann::json& j, const CP_TNL_Information& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, CP_TNL_Information_endpoint_IP_Address>) {
            j = nlohmann::json{{"endpoint_IP_Address", alt.endpoint_IP_Address}};
        } else
        if constexpr (std::is_same_v<T, CP_TNL_Information_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, CP_TNL_Information& v) {
    if (j.contains("endpoint_IP_Address")) {
        CP_TNL_Information_endpoint_IP_Address alt;
        j.at("endpoint_IP_Address").get_to(alt.endpoint_IP_Address);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        CP_TNL_Information_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const Endpoint_IP_address_and_port& v) {
    j = nlohmann::json::object();
    j["endpoint-IP-Address"] = v.endpoint_IP_Address;
    j["portNumber"] = v.portNumber;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Endpoint_IP_address_and_port& v) {
    if (j.contains("endpoint-IP-Address")) {
        j.at("endpoint-IP-Address").get_to(v.endpoint_IP_Address);
    }
    if (j.contains("portNumber")) {
        j.at("portNumber").get_to(v.portNumber);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_TNLA_Setup_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_TNLA_Setup_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_TNLA_Failed_To_Setup_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    j["cause"] = v.cause;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_TNLA_Failed_To_Setup_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("cause")) {
        j.at("cause").get_to(v.cause);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_TNLA_To_Add_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    j["tNLAssociationUsage"] = v.tNLAssociationUsage;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_TNLA_To_Add_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("tNLAssociationUsage")) {
        j.at("tNLAssociationUsage").get_to(v.tNLAssociationUsage);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_TNLA_To_Remove_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_TNLA_To_Remove_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_TNLA_To_Update_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    if (v.tNLAssociationUsage.has_value()) {
        j["tNLAssociationUsage"] = *v.tNLAssociationUsage;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_TNLA_To_Update_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("tNLAssociationUsage") && !j.at("tNLAssociationUsage").is_null()) {
        decltype(v.tNLAssociationUsage)::value_type tmp{};
        j.at("tNLAssociationUsage").get_to(tmp);
        v.tNLAssociationUsage = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_TNLA_To_Remove_Item& v) {
    j = nlohmann::json::object();
    j["tNLAssociationTransportLayerAddress"] = v.tNLAssociationTransportLayerAddress;
    if (v.tNLAssociationTransportLayerAddressgNBCUCP.has_value()) {
        j["tNLAssociationTransportLayerAddressgNBCUCP"] = *v.tNLAssociationTransportLayerAddressgNBCUCP;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_TNLA_To_Remove_Item& v) {
    if (j.contains("tNLAssociationTransportLayerAddress")) {
        j.at("tNLAssociationTransportLayerAddress").get_to(v.tNLAssociationTransportLayerAddress);
    }
    if (j.contains("tNLAssociationTransportLayerAddressgNBCUCP") && !j.at("tNLAssociationTransportLayerAddressgNBCUCP").is_null()) {
        decltype(v.tNLAssociationTransportLayerAddressgNBCUCP)::value_type tmp{};
        j.at("tNLAssociationTransportLayerAddressgNBCUCP").get_to(tmp);
        v.tNLAssociationTransportLayerAddressgNBCUCP = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GTPTunnel& v) {
    j = nlohmann::json::object();
    j["transportLayerAddress"] = v.transportLayerAddress;
    j["gTP-TEID"] = v.gTP_TEID;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GTPTunnel& v) {
    if (j.contains("transportLayerAddress")) {
        j.at("transportLayerAddress").get_to(v.transportLayerAddress);
    }
    if (j.contains("gTP-TEID")) {
        j.at("gTP-TEID").get_to(v.gTP_TEID);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(T_Reordering, {
    {T_Reordering::ms0, "ms0"},
    {T_Reordering::ms1, "ms1"},
    {T_Reordering::ms2, "ms2"},
    {T_Reordering::ms4, "ms4"},
    {T_Reordering::ms5, "ms5"},
    {T_Reordering::ms8, "ms8"},
    {T_Reordering::ms10, "ms10"},
    {T_Reordering::ms15, "ms15"},
    {T_Reordering::ms20, "ms20"},
    {T_Reordering::ms30, "ms30"},
    {T_Reordering::ms40, "ms40"},
    {T_Reordering::ms50, "ms50"},
    {T_Reordering::ms60, "ms60"},
    {T_Reordering::ms80, "ms80"},
    {T_Reordering::ms100, "ms100"},
    {T_Reordering::ms120, "ms120"},
    {T_Reordering::ms140, "ms140"},
    {T_Reordering::ms160, "ms160"},
    {T_Reordering::ms180, "ms180"},
    {T_Reordering::ms200, "ms200"},
    {T_Reordering::ms220, "ms220"},
    {T_Reordering::ms240, "ms240"},
    {T_Reordering::ms260, "ms260"},
    {T_Reordering::ms280, "ms280"},
    {T_Reordering::ms300, "ms300"},
    {T_Reordering::ms500, "ms500"},
    {T_Reordering::ms750, "ms750"},
    {T_Reordering::ms1000, "ms1000"},
    {T_Reordering::ms1250, "ms1250"},
    {T_Reordering::ms1500, "ms1500"},
    {T_Reordering::ms1750, "ms1750"},
    {T_Reordering::ms2000, "ms2000"},
    {T_Reordering::ms2250, "ms2250"},
    {T_Reordering::ms2500, "ms2500"},
    {T_Reordering::ms2750, "ms2750"},
    {T_Reordering::ms3000, "ms3000"}
})

inline void to_json(nlohmann::json& j, const T_ReorderingTimer& v) {
    j = nlohmann::json::object();
    j["t-Reordering"] = v.t_Reordering;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, T_ReorderingTimer& v) {
    if (j.contains("t-Reordering")) {
        j.at("t-Reordering").get_to(v.t_Reordering);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(TypeOfError, {
    {TypeOfError::not_understood, "not_understood"},
    {TypeOfError::missing, "missing"}
})

inline void to_json(nlohmann::json& j, const CriticalityDiagnostics_IE_List_element& v) {
    j = nlohmann::json::object();
    j["iECriticality"] = v.iECriticality;
    j["iE-ID"] = v.iE_ID;
    j["typeOfError"] = v.typeOfError;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, CriticalityDiagnostics_IE_List_element& v) {
    if (j.contains("iECriticality")) {
        j.at("iECriticality").get_to(v.iECriticality);
    }
    if (j.contains("iE-ID")) {
        j.at("iE-ID").get_to(v.iE_ID);
    }
    if (j.contains("typeOfError")) {
        j.at("typeOfError").get_to(v.typeOfError);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const CriticalityDiagnostics& v) {
    j = nlohmann::json::object();
    if (v.procedureCode.has_value()) {
        j["procedureCode"] = *v.procedureCode;
    }
    if (v.triggeringMessage.has_value()) {
        j["triggeringMessage"] = *v.triggeringMessage;
    }
    if (v.procedureCriticality.has_value()) {
        j["procedureCriticality"] = *v.procedureCriticality;
    }
    if (v.transactionID.has_value()) {
        j["transactionID"] = *v.transactionID;
    }
    if (v.iEsCriticalityDiagnostics.has_value()) {
        j["iEsCriticalityDiagnostics"] = *v.iEsCriticalityDiagnostics;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, CriticalityDiagnostics& v) {
    if (j.contains("procedureCode") && !j.at("procedureCode").is_null()) {
        decltype(v.procedureCode)::value_type tmp{};
        j.at("procedureCode").get_to(tmp);
        v.procedureCode = std::move(tmp);
    }
    if (j.contains("triggeringMessage") && !j.at("triggeringMessage").is_null()) {
        decltype(v.triggeringMessage)::value_type tmp{};
        j.at("triggeringMessage").get_to(tmp);
        v.triggeringMessage = std::move(tmp);
    }
    if (j.contains("procedureCriticality") && !j.at("procedureCriticality").is_null()) {
        decltype(v.procedureCriticality)::value_type tmp{};
        j.at("procedureCriticality").get_to(tmp);
        v.procedureCriticality = std::move(tmp);
    }
    if (j.contains("transactionID") && !j.at("transactionID").is_null()) {
        decltype(v.transactionID)::value_type tmp{};
        j.at("transactionID").get_to(tmp);
        v.transactionID = std::move(tmp);
    }
    if (j.contains("iEsCriticalityDiagnostics") && !j.at("iEsCriticalityDiagnostics").is_null()) {
        decltype(v.iEsCriticalityDiagnostics)::value_type tmp{};
        j.at("iEsCriticalityDiagnostics").get_to(tmp);
        v.iEsCriticalityDiagnostics = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(UE_Activity, {
    {UE_Activity::active, "active"},
    {UE_Activity::not_active, "not_active"}
})

inline void to_json(nlohmann::json& j, const ActivityInformation& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, ActivityInformation_dRB_Activity_List>) {
            j = nlohmann::json{{"dRB_Activity_List", alt.dRB_Activity_List}};
        } else
        if constexpr (std::is_same_v<T, ActivityInformation_pDU_Session_Resource_Activity_List>) {
            j = nlohmann::json{{"pDU_Session_Resource_Activity_List", alt.pDU_Session_Resource_Activity_List}};
        } else
        if constexpr (std::is_same_v<T, ActivityInformation_uE_Activity>) {
            j = nlohmann::json{{"uE_Activity", alt.uE_Activity}};
        } else
        if constexpr (std::is_same_v<T, ActivityInformation_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, ActivityInformation& v) {
    if (j.contains("dRB_Activity_List")) {
        ActivityInformation_dRB_Activity_List alt;
        j.at("dRB_Activity_List").get_to(alt.dRB_Activity_List);
        v = std::move(alt);
        return;
    }
    if (j.contains("pDU_Session_Resource_Activity_List")) {
        ActivityInformation_pDU_Session_Resource_Activity_List alt;
        j.at("pDU_Session_Resource_Activity_List").get_to(alt.pDU_Session_Resource_Activity_List);
        v = std::move(alt);
        return;
    }
    if (j.contains("uE_Activity")) {
        ActivityInformation_uE_Activity alt;
        j.at("uE_Activity").get_to(alt.uE_Activity);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        ActivityInformation_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const UE_associatedLogicalE1_ConnectionItem& v) {
    j = nlohmann::json::object();
    if (v.gNB_CU_CP_UE_E1AP_ID.has_value()) {
        j["gNB-CU-CP-UE-E1AP-ID"] = *v.gNB_CU_CP_UE_E1AP_ID;
    }
    if (v.gNB_CU_UP_UE_E1AP_ID.has_value()) {
        j["gNB-CU-UP-UE-E1AP-ID"] = *v.gNB_CU_UP_UE_E1AP_ID;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, UE_associatedLogicalE1_ConnectionItem& v) {
    if (j.contains("gNB-CU-CP-UE-E1AP-ID") && !j.at("gNB-CU-CP-UE-E1AP-ID").is_null()) {
        decltype(v.gNB_CU_CP_UE_E1AP_ID)::value_type tmp{};
        j.at("gNB-CU-CP-UE-E1AP-ID").get_to(tmp);
        v.gNB_CU_CP_UE_E1AP_ID = std::move(tmp);
    }
    if (j.contains("gNB-CU-UP-UE-E1AP-ID") && !j.at("gNB-CU-UP-UE-E1AP-ID").is_null()) {
        decltype(v.gNB_CU_UP_UE_E1AP_ID)::value_type tmp{};
        j.at("gNB-CU-UP-UE-E1AP-ID").get_to(tmp);
        v.gNB_CU_UP_UE_E1AP_ID = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(UL_Configuration, {
    {UL_Configuration::no_data, "no_data"},
    {UL_Configuration::shared, "shared"},
    {UL_Configuration::only, "only"}
})

inline void to_json(nlohmann::json& j, const Cell_Group_Information_Item& v) {
    j = nlohmann::json::object();
    j["cell-Group-ID"] = v.cell_Group_ID;
    if (v.uL_Configuration.has_value()) {
        j["uL-Configuration"] = *v.uL_Configuration;
    }
    if (v.dL_TX_Stop.has_value()) {
        j["dL-TX-Stop"] = *v.dL_TX_Stop;
    }
    if (v.rAT_Type.has_value()) {
        j["rAT-Type"] = *v.rAT_Type;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Cell_Group_Information_Item& v) {
    if (j.contains("cell-Group-ID")) {
        j.at("cell-Group-ID").get_to(v.cell_Group_ID);
    }
    if (j.contains("uL-Configuration") && !j.at("uL-Configuration").is_null()) {
        decltype(v.uL_Configuration)::value_type tmp{};
        j.at("uL-Configuration").get_to(tmp);
        v.uL_Configuration = std::move(tmp);
    }
    if (j.contains("dL-TX-Stop") && !j.at("dL-TX-Stop").is_null()) {
        decltype(v.dL_TX_Stop)::value_type tmp{};
        j.at("dL-TX-Stop").get_to(tmp);
        v.dL_TX_Stop = std::move(tmp);
    }
    if (j.contains("rAT-Type") && !j.at("rAT-Type").is_null()) {
        decltype(v.rAT_Type)::value_type tmp{};
        j.at("rAT-Type").get_to(tmp);
        v.rAT_Type = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Confirm_Modified_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.cell_Group_Information.has_value()) {
        j["cell-Group-Information"] = *v.cell_Group_Information;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Confirm_Modified_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cell-Group-Information") && !j.at("cell-Group-Information").is_null()) {
        decltype(v.cell_Group_Information)::value_type tmp{};
        j.at("cell-Group-Information").get_to(tmp);
        v.cell_Group_Information = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Confirm_Modified_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.cell_Group_Information.has_value()) {
        j["cell-Group-Information"] = *v.cell_Group_Information;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Confirm_Modified_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("cell-Group-Information") && !j.at("cell-Group-Information").is_null()) {
        decltype(v.cell_Group_Information)::value_type tmp{};
        j.at("cell-Group-Information").get_to(tmp);
        v.cell_Group_Information = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Confirm_Modified_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.dRB_Confirm_Modified_List_NG_RAN.has_value()) {
        j["dRB-Confirm-Modified-List-NG-RAN"] = *v.dRB_Confirm_Modified_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Confirm_Modified_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("dRB-Confirm-Modified-List-NG-RAN") && !j.at("dRB-Confirm-Modified-List-NG-RAN").is_null()) {
        decltype(v.dRB_Confirm_Modified_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Confirm-Modified-List-NG-RAN").get_to(tmp);
        v.dRB_Confirm_Modified_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(ULDataSplitThreshold, {
    {ULDataSplitThreshold::b0, "b0"},
    {ULDataSplitThreshold::b100, "b100"},
    {ULDataSplitThreshold::b200, "b200"},
    {ULDataSplitThreshold::b400, "b400"},
    {ULDataSplitThreshold::b800, "b800"},
    {ULDataSplitThreshold::b1600, "b1600"},
    {ULDataSplitThreshold::b3200, "b3200"},
    {ULDataSplitThreshold::b6400, "b6400"},
    {ULDataSplitThreshold::b12800, "b12800"},
    {ULDataSplitThreshold::b25600, "b25600"},
    {ULDataSplitThreshold::b51200, "b51200"},
    {ULDataSplitThreshold::b102400, "b102400"},
    {ULDataSplitThreshold::b204800, "b204800"},
    {ULDataSplitThreshold::b409600, "b409600"},
    {ULDataSplitThreshold::b819200, "b819200"},
    {ULDataSplitThreshold::b1228800, "b1228800"},
    {ULDataSplitThreshold::b1638400, "b1638400"},
    {ULDataSplitThreshold::b2457600, "b2457600"},
    {ULDataSplitThreshold::b3276800, "b3276800"},
    {ULDataSplitThreshold::b4096000, "b4096000"},
    {ULDataSplitThreshold::b4915200, "b4915200"},
    {ULDataSplitThreshold::b5734400, "b5734400"},
    {ULDataSplitThreshold::b6553600, "b6553600"},
    {ULDataSplitThreshold::infinity, "infinity"}
})

inline void to_json(nlohmann::json& j, const UPSecuritykey& v) {
    j = nlohmann::json::object();
    j["encryptionKey"] = v.encryptionKey;
    if (v.integrityProtectionKey.has_value()) {
        j["integrityProtectionKey"] = *v.integrityProtectionKey;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, UPSecuritykey& v) {
    if (j.contains("encryptionKey")) {
        j.at("encryptionKey").get_to(v.encryptionKey);
    }
    if (j.contains("integrityProtectionKey") && !j.at("integrityProtectionKey").is_null()) {
        decltype(v.integrityProtectionKey)::value_type tmp{};
        j.at("integrityProtectionKey").get_to(tmp);
        v.integrityProtectionKey = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const SecurityInformation& v) {
    j = nlohmann::json::object();
    j["securityAlgorithm"] = v.securityAlgorithm;
    j["uPSecuritykey"] = v.uPSecuritykey;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SecurityInformation& v) {
    if (j.contains("securityAlgorithm")) {
        j.at("securityAlgorithm").get_to(v.securityAlgorithm);
    }
    if (j.contains("uPSecuritykey")) {
        j.at("uPSecuritykey").get_to(v.uPSecuritykey);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const UP_TNL_Information& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, UP_TNL_Information_gTPTunnel>) {
            j = nlohmann::json{{"gTPTunnel", alt.gTPTunnel}};
        } else
        if constexpr (std::is_same_v<T, UP_TNL_Information_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, UP_TNL_Information& v) {
    if (j.contains("gTPTunnel")) {
        UP_TNL_Information_gTPTunnel alt;
        j.at("gTPTunnel").get_to(alt.gTPTunnel);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        UP_TNL_Information_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const Data_Forwarding_Information& v) {
    j = nlohmann::json::object();
    if (v.uL_Data_Forwarding.has_value()) {
        j["uL-Data-Forwarding"] = *v.uL_Data_Forwarding;
    }
    if (v.dL_Data_Forwarding.has_value()) {
        j["dL-Data-Forwarding"] = *v.dL_Data_Forwarding;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, Data_Forwarding_Information& v) {
    if (j.contains("uL-Data-Forwarding") && !j.at("uL-Data-Forwarding").is_null()) {
        decltype(v.uL_Data_Forwarding)::value_type tmp{};
        j.at("uL-Data-Forwarding").get_to(tmp);
        v.uL_Data_Forwarding = std::move(tmp);
    }
    if (j.contains("dL-Data-Forwarding") && !j.at("dL-Data-Forwarding").is_null()) {
        decltype(v.dL_Data_Forwarding)::value_type tmp{};
        j.at("dL-Data-Forwarding").get_to(tmp);
        v.dL_Data_Forwarding = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_CellGroupRelatedConfiguration_Item& v) {
    j = nlohmann::json::object();
    j["cell-Group-ID"] = v.cell_Group_ID;
    j["uP-TNL-Information"] = v.uP_TNL_Information;
    if (v.uL_Configuration.has_value()) {
        j["uL-Configuration"] = *v.uL_Configuration;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_CellGroupRelatedConfiguration_Item& v) {
    if (j.contains("cell-Group-ID")) {
        j.at("cell-Group-ID").get_to(v.cell_Group_ID);
    }
    if (j.contains("uP-TNL-Information")) {
        j.at("uP-TNL-Information").get_to(v.uP_TNL_Information);
    }
    if (j.contains("uL-Configuration") && !j.at("uL-Configuration").is_null()) {
        decltype(v.uL_Configuration)::value_type tmp{};
        j.at("uL-Configuration").get_to(tmp);
        v.uL_Configuration = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Required_To_Modify_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.s1_DL_UP_TNL_Information.has_value()) {
        j["s1-DL-UP-TNL-Information"] = *v.s1_DL_UP_TNL_Information;
    }
    if (v.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
        j["gNB-CU-UP-CellGroupRelatedConfiguration"] = *v.gNB_CU_UP_CellGroupRelatedConfiguration;
    }
    if (v.cause.has_value()) {
        j["cause"] = *v.cause;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Required_To_Modify_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("s1-DL-UP-TNL-Information") && !j.at("s1-DL-UP-TNL-Information").is_null()) {
        decltype(v.s1_DL_UP_TNL_Information)::value_type tmp{};
        j.at("s1-DL-UP-TNL-Information").get_to(tmp);
        v.s1_DL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("gNB-CU-UP-CellGroupRelatedConfiguration") && !j.at("gNB-CU-UP-CellGroupRelatedConfiguration").is_null()) {
        decltype(v.gNB_CU_UP_CellGroupRelatedConfiguration)::value_type tmp{};
        j.at("gNB-CU-UP-CellGroupRelatedConfiguration").get_to(tmp);
        v.gNB_CU_UP_CellGroupRelatedConfiguration = std::move(tmp);
    }
    if (j.contains("cause") && !j.at("cause").is_null()) {
        decltype(v.cause)::value_type tmp{};
        j.at("cause").get_to(tmp);
        v.cause = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Required_To_Modify_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
        j["gNB-CU-UP-CellGroupRelatedConfiguration"] = *v.gNB_CU_UP_CellGroupRelatedConfiguration;
    }
    if (v.flow_To_Remove.has_value()) {
        j["flow-To-Remove"] = *v.flow_To_Remove;
    }
    if (v.cause.has_value()) {
        j["cause"] = *v.cause;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Required_To_Modify_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("gNB-CU-UP-CellGroupRelatedConfiguration") && !j.at("gNB-CU-UP-CellGroupRelatedConfiguration").is_null()) {
        decltype(v.gNB_CU_UP_CellGroupRelatedConfiguration)::value_type tmp{};
        j.at("gNB-CU-UP-CellGroupRelatedConfiguration").get_to(tmp);
        v.gNB_CU_UP_CellGroupRelatedConfiguration = std::move(tmp);
    }
    if (j.contains("flow-To-Remove") && !j.at("flow-To-Remove").is_null()) {
        decltype(v.flow_To_Remove)::value_type tmp{};
        j.at("flow-To-Remove").get_to(tmp);
        v.flow_To_Remove = std::move(tmp);
    }
    if (j.contains("cause") && !j.at("cause").is_null()) {
        decltype(v.cause)::value_type tmp{};
        j.at("cause").get_to(tmp);
        v.cause = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Required_To_Modify_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.nG_DL_UP_TNL_Information.has_value()) {
        j["nG-DL-UP-TNL-Information"] = *v.nG_DL_UP_TNL_Information;
    }
    if (v.dRB_Required_To_Modify_List_NG_RAN.has_value()) {
        j["dRB-Required-To-Modify-List-NG-RAN"] = *v.dRB_Required_To_Modify_List_NG_RAN;
    }
    if (v.dRB_Required_To_Remove_List_NG_RAN.has_value()) {
        j["dRB-Required-To-Remove-List-NG-RAN"] = *v.dRB_Required_To_Remove_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Required_To_Modify_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("nG-DL-UP-TNL-Information") && !j.at("nG-DL-UP-TNL-Information").is_null()) {
        decltype(v.nG_DL_UP_TNL_Information)::value_type tmp{};
        j.at("nG-DL-UP-TNL-Information").get_to(tmp);
        v.nG_DL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("dRB-Required-To-Modify-List-NG-RAN") && !j.at("dRB-Required-To-Modify-List-NG-RAN").is_null()) {
        decltype(v.dRB_Required_To_Modify_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Required-To-Modify-List-NG-RAN").get_to(tmp);
        v.dRB_Required_To_Modify_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-Required-To-Remove-List-NG-RAN") && !j.at("dRB-Required-To-Remove-List-NG-RAN").is_null()) {
        decltype(v.dRB_Required_To_Remove_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Required-To-Remove-List-NG-RAN").get_to(tmp);
        v.dRB_Required_To_Remove_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const UP_Parameters_Item& v) {
    j = nlohmann::json::object();
    j["uP-TNL-Information"] = v.uP_TNL_Information;
    j["cell-Group-ID"] = v.cell_Group_ID;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, UP_Parameters_Item& v) {
    if (j.contains("uP-TNL-Information")) {
        j.at("uP-TNL-Information").get_to(v.uP_TNL_Information);
    }
    if (j.contains("cell-Group-ID")) {
        j.at("cell-Group-ID").get_to(v.cell_Group_ID);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Modified_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.s1_DL_UP_TNL_Information.has_value()) {
        j["s1-DL-UP-TNL-Information"] = *v.s1_DL_UP_TNL_Information;
    }
    if (v.pDCP_SN_Status_Information.has_value()) {
        j["pDCP-SN-Status-Information"] = *v.pDCP_SN_Status_Information;
    }
    if (v.uL_UP_Transport_Parameters.has_value()) {
        j["uL-UP-Transport-Parameters"] = *v.uL_UP_Transport_Parameters;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Modified_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("s1-DL-UP-TNL-Information") && !j.at("s1-DL-UP-TNL-Information").is_null()) {
        decltype(v.s1_DL_UP_TNL_Information)::value_type tmp{};
        j.at("s1-DL-UP-TNL-Information").get_to(tmp);
        v.s1_DL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Information") && !j.at("pDCP-SN-Status-Information").is_null()) {
        decltype(v.pDCP_SN_Status_Information)::value_type tmp{};
        j.at("pDCP-SN-Status-Information").get_to(tmp);
        v.pDCP_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("uL-UP-Transport-Parameters") && !j.at("uL-UP-Transport-Parameters").is_null()) {
        decltype(v.uL_UP_Transport_Parameters)::value_type tmp{};
        j.at("uL-UP-Transport-Parameters").get_to(tmp);
        v.uL_UP_Transport_Parameters = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Modified_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.uL_UP_Transport_Parameters.has_value()) {
        j["uL-UP-Transport-Parameters"] = *v.uL_UP_Transport_Parameters;
    }
    if (v.pDCP_SN_Status_Information.has_value()) {
        j["pDCP-SN-Status-Information"] = *v.pDCP_SN_Status_Information;
    }
    if (v.flow_Setup_List.has_value()) {
        j["flow-Setup-List"] = *v.flow_Setup_List;
    }
    if (v.flow_Failed_List.has_value()) {
        j["flow-Failed-List"] = *v.flow_Failed_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Modified_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("uL-UP-Transport-Parameters") && !j.at("uL-UP-Transport-Parameters").is_null()) {
        decltype(v.uL_UP_Transport_Parameters)::value_type tmp{};
        j.at("uL-UP-Transport-Parameters").get_to(tmp);
        v.uL_UP_Transport_Parameters = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Information") && !j.at("pDCP-SN-Status-Information").is_null()) {
        decltype(v.pDCP_SN_Status_Information)::value_type tmp{};
        j.at("pDCP-SN-Status-Information").get_to(tmp);
        v.pDCP_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("flow-Setup-List") && !j.at("flow-Setup-List").is_null()) {
        decltype(v.flow_Setup_List)::value_type tmp{};
        j.at("flow-Setup-List").get_to(tmp);
        v.flow_Setup_List = std::move(tmp);
    }
    if (j.contains("flow-Failed-List") && !j.at("flow-Failed-List").is_null()) {
        decltype(v.flow_Failed_List)::value_type tmp{};
        j.at("flow-Failed-List").get_to(tmp);
        v.flow_Failed_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(DRB_Setup_Item_EUTRAN::s1_DL_UP_Unchanged_type, {
    {DRB_Setup_Item_EUTRAN::s1_DL_UP_Unchanged_type::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const DRB_Setup_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["s1-DL-UP-TNL-Information"] = v.s1_DL_UP_TNL_Information;
    if (v.data_Forwarding_Information_Response.has_value()) {
        j["data-Forwarding-Information-Response"] = *v.data_Forwarding_Information_Response;
    }
    j["uL-UP-Transport-Parameters"] = v.uL_UP_Transport_Parameters;
    if (v.s1_DL_UP_Unchanged.has_value()) {
        j["s1-DL-UP-Unchanged"] = *v.s1_DL_UP_Unchanged;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Setup_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("s1-DL-UP-TNL-Information")) {
        j.at("s1-DL-UP-TNL-Information").get_to(v.s1_DL_UP_TNL_Information);
    }
    if (j.contains("data-Forwarding-Information-Response") && !j.at("data-Forwarding-Information-Response").is_null()) {
        decltype(v.data_Forwarding_Information_Response)::value_type tmp{};
        j.at("data-Forwarding-Information-Response").get_to(tmp);
        v.data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("uL-UP-Transport-Parameters")) {
        j.at("uL-UP-Transport-Parameters").get_to(v.uL_UP_Transport_Parameters);
    }
    if (j.contains("s1-DL-UP-Unchanged") && !j.at("s1-DL-UP-Unchanged").is_null()) {
        decltype(v.s1_DL_UP_Unchanged)::value_type tmp{};
        j.at("s1-DL-UP-Unchanged").get_to(tmp);
        v.s1_DL_UP_Unchanged = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Setup_Mod_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["s1-DL-UP-TNL-Information"] = v.s1_DL_UP_TNL_Information;
    if (v.data_Forwarding_Information_Response.has_value()) {
        j["data-Forwarding-Information-Response"] = *v.data_Forwarding_Information_Response;
    }
    j["uL-UP-Transport-Parameters"] = v.uL_UP_Transport_Parameters;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Setup_Mod_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("s1-DL-UP-TNL-Information")) {
        j.at("s1-DL-UP-TNL-Information").get_to(v.s1_DL_UP_TNL_Information);
    }
    if (j.contains("data-Forwarding-Information-Response") && !j.at("data-Forwarding-Information-Response").is_null()) {
        decltype(v.data_Forwarding_Information_Response)::value_type tmp{};
        j.at("data-Forwarding-Information-Response").get_to(tmp);
        v.data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("uL-UP-Transport-Parameters")) {
        j.at("uL-UP-Transport-Parameters").get_to(v.uL_UP_Transport_Parameters);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Setup_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.dRB_data_Forwarding_Information_Response.has_value()) {
        j["dRB-data-Forwarding-Information-Response"] = *v.dRB_data_Forwarding_Information_Response;
    }
    j["uL-UP-Transport-Parameters"] = v.uL_UP_Transport_Parameters;
    j["flow-Setup-List"] = v.flow_Setup_List;
    if (v.flow_Failed_List.has_value()) {
        j["flow-Failed-List"] = *v.flow_Failed_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Setup_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("dRB-data-Forwarding-Information-Response") && !j.at("dRB-data-Forwarding-Information-Response").is_null()) {
        decltype(v.dRB_data_Forwarding_Information_Response)::value_type tmp{};
        j.at("dRB-data-Forwarding-Information-Response").get_to(tmp);
        v.dRB_data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("uL-UP-Transport-Parameters")) {
        j.at("uL-UP-Transport-Parameters").get_to(v.uL_UP_Transport_Parameters);
    }
    if (j.contains("flow-Setup-List")) {
        j.at("flow-Setup-List").get_to(v.flow_Setup_List);
    }
    if (j.contains("flow-Failed-List") && !j.at("flow-Failed-List").is_null()) {
        decltype(v.flow_Failed_List)::value_type tmp{};
        j.at("flow-Failed-List").get_to(tmp);
        v.flow_Failed_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_Setup_Mod_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.dRB_data_Forwarding_Information_Response.has_value()) {
        j["dRB-data-Forwarding-Information-Response"] = *v.dRB_data_Forwarding_Information_Response;
    }
    j["uL-UP-Transport-Parameters"] = v.uL_UP_Transport_Parameters;
    j["flow-Setup-List"] = v.flow_Setup_List;
    if (v.flow_Failed_List.has_value()) {
        j["flow-Failed-List"] = *v.flow_Failed_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_Setup_Mod_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("dRB-data-Forwarding-Information-Response") && !j.at("dRB-data-Forwarding-Information-Response").is_null()) {
        decltype(v.dRB_data_Forwarding_Information_Response)::value_type tmp{};
        j.at("dRB-data-Forwarding-Information-Response").get_to(tmp);
        v.dRB_data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("uL-UP-Transport-Parameters")) {
        j.at("uL-UP-Transport-Parameters").get_to(v.uL_UP_Transport_Parameters);
    }
    if (j.contains("flow-Setup-List")) {
        j.at("flow-Setup-List").get_to(v.flow_Setup_List);
    }
    if (j.contains("flow-Failed-List") && !j.at("flow-Failed-List").is_null()) {
        decltype(v.flow_Failed_List)::value_type tmp{};
        j.at("flow-Failed-List").get_to(tmp);
        v.flow_Failed_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Modified_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.nG_DL_UP_TNL_Information.has_value()) {
        j["nG-DL-UP-TNL-Information"] = *v.nG_DL_UP_TNL_Information;
    }
    if (v.securityResult.has_value()) {
        j["securityResult"] = *v.securityResult;
    }
    if (v.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Response"] = *v.pDU_Session_Data_Forwarding_Information_Response;
    }
    if (v.dRB_Setup_List_NG_RAN.has_value()) {
        j["dRB-Setup-List-NG-RAN"] = *v.dRB_Setup_List_NG_RAN;
    }
    if (v.dRB_Failed_List_NG_RAN.has_value()) {
        j["dRB-Failed-List-NG-RAN"] = *v.dRB_Failed_List_NG_RAN;
    }
    if (v.dRB_Modified_List_NG_RAN.has_value()) {
        j["dRB-Modified-List-NG-RAN"] = *v.dRB_Modified_List_NG_RAN;
    }
    if (v.dRB_Failed_To_Modify_List_NG_RAN.has_value()) {
        j["dRB-Failed-To-Modify-List-NG-RAN"] = *v.dRB_Failed_To_Modify_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Modified_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("nG-DL-UP-TNL-Information") && !j.at("nG-DL-UP-TNL-Information").is_null()) {
        decltype(v.nG_DL_UP_TNL_Information)::value_type tmp{};
        j.at("nG-DL-UP-TNL-Information").get_to(tmp);
        v.nG_DL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("securityResult") && !j.at("securityResult").is_null()) {
        decltype(v.securityResult)::value_type tmp{};
        j.at("securityResult").get_to(tmp);
        v.securityResult = std::move(tmp);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Response") && !j.at("pDU-Session-Data-Forwarding-Information-Response").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Response)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Response").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("dRB-Setup-List-NG-RAN") && !j.at("dRB-Setup-List-NG-RAN").is_null()) {
        decltype(v.dRB_Setup_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Setup-List-NG-RAN").get_to(tmp);
        v.dRB_Setup_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-Failed-List-NG-RAN") && !j.at("dRB-Failed-List-NG-RAN").is_null()) {
        decltype(v.dRB_Failed_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Failed-List-NG-RAN").get_to(tmp);
        v.dRB_Failed_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-Modified-List-NG-RAN") && !j.at("dRB-Modified-List-NG-RAN").is_null()) {
        decltype(v.dRB_Modified_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Modified-List-NG-RAN").get_to(tmp);
        v.dRB_Modified_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-Failed-To-Modify-List-NG-RAN") && !j.at("dRB-Failed-To-Modify-List-NG-RAN").is_null()) {
        decltype(v.dRB_Failed_To_Modify_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Failed-To-Modify-List-NG-RAN").get_to(tmp);
        v.dRB_Failed_To_Modify_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(PDU_Session_Resource_Setup_Item::nG_DL_UP_Unchanged_type, {
    {PDU_Session_Resource_Setup_Item::nG_DL_UP_Unchanged_type::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Setup_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.securityResult.has_value()) {
        j["securityResult"] = *v.securityResult;
    }
    j["nG-DL-UP-TNL-Information"] = v.nG_DL_UP_TNL_Information;
    if (v.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Response"] = *v.pDU_Session_Data_Forwarding_Information_Response;
    }
    if (v.nG_DL_UP_Unchanged.has_value()) {
        j["nG-DL-UP-Unchanged"] = *v.nG_DL_UP_Unchanged;
    }
    j["dRB-Setup-List-NG-RAN"] = v.dRB_Setup_List_NG_RAN;
    if (v.dRB_Failed_List_NG_RAN.has_value()) {
        j["dRB-Failed-List-NG-RAN"] = *v.dRB_Failed_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Setup_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("securityResult") && !j.at("securityResult").is_null()) {
        decltype(v.securityResult)::value_type tmp{};
        j.at("securityResult").get_to(tmp);
        v.securityResult = std::move(tmp);
    }
    if (j.contains("nG-DL-UP-TNL-Information")) {
        j.at("nG-DL-UP-TNL-Information").get_to(v.nG_DL_UP_TNL_Information);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Response") && !j.at("pDU-Session-Data-Forwarding-Information-Response").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Response)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Response").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("nG-DL-UP-Unchanged") && !j.at("nG-DL-UP-Unchanged").is_null()) {
        decltype(v.nG_DL_UP_Unchanged)::value_type tmp{};
        j.at("nG-DL-UP-Unchanged").get_to(tmp);
        v.nG_DL_UP_Unchanged = std::move(tmp);
    }
    if (j.contains("dRB-Setup-List-NG-RAN")) {
        j.at("dRB-Setup-List-NG-RAN").get_to(v.dRB_Setup_List_NG_RAN);
    }
    if (j.contains("dRB-Failed-List-NG-RAN") && !j.at("dRB-Failed-List-NG-RAN").is_null()) {
        decltype(v.dRB_Failed_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Failed-List-NG-RAN").get_to(tmp);
        v.dRB_Failed_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_Setup_Mod_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.securityResult.has_value()) {
        j["securityResult"] = *v.securityResult;
    }
    j["nG-DL-UP-TNL-Information"] = v.nG_DL_UP_TNL_Information;
    if (v.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Response"] = *v.pDU_Session_Data_Forwarding_Information_Response;
    }
    j["dRB-Setup-Mod-List-NG-RAN"] = v.dRB_Setup_Mod_List_NG_RAN;
    if (v.dRB_Failed_Mod_List_NG_RAN.has_value()) {
        j["dRB-Failed-Mod-List-NG-RAN"] = *v.dRB_Failed_Mod_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_Setup_Mod_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("securityResult") && !j.at("securityResult").is_null()) {
        decltype(v.securityResult)::value_type tmp{};
        j.at("securityResult").get_to(tmp);
        v.securityResult = std::move(tmp);
    }
    if (j.contains("nG-DL-UP-TNL-Information")) {
        j.at("nG-DL-UP-TNL-Information").get_to(v.nG_DL_UP_TNL_Information);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Response") && !j.at("pDU-Session-Data-Forwarding-Information-Response").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Response)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Response").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Response = std::move(tmp);
    }
    if (j.contains("dRB-Setup-Mod-List-NG-RAN")) {
        j.at("dRB-Setup-Mod-List-NG-RAN").get_to(v.dRB_Setup_Mod_List_NG_RAN);
    }
    if (j.contains("dRB-Failed-Mod-List-NG-RAN") && !j.at("dRB-Failed-Mod-List-NG-RAN").is_null()) {
        decltype(v.dRB_Failed_Mod_List_NG_RAN)::value_type tmp{};
        j.at("dRB-Failed-Mod-List-NG-RAN").get_to(tmp);
        v.dRB_Failed_Mod_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(UplinkOnlyROHC::continueROHC_type, {
    {UplinkOnlyROHC::continueROHC_type::true_, "true_"}
})

inline void to_json(nlohmann::json& j, const UplinkOnlyROHC& v) {
    j = nlohmann::json::object();
    j["maxCID"] = v.maxCID;
    j["rOHC-Profiles"] = v.rOHC_Profiles;
    if (v.continueROHC.has_value()) {
        j["continueROHC"] = *v.continueROHC;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, UplinkOnlyROHC& v) {
    if (j.contains("maxCID")) {
        j.at("maxCID").get_to(v.maxCID);
    }
    if (j.contains("rOHC-Profiles")) {
        j.at("rOHC-Profiles").get_to(v.rOHC_Profiles);
    }
    if (j.contains("continueROHC") && !j.at("continueROHC").is_null()) {
        decltype(v.continueROHC)::value_type tmp{};
        j.at("continueROHC").get_to(tmp);
        v.continueROHC = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const ROHC_Parameters& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, ROHC_Parameters_rOHC>) {
            j = nlohmann::json{{"rOHC", alt.rOHC}};
        } else
        if constexpr (std::is_same_v<T, ROHC_Parameters_uPlinkOnlyROHC>) {
            j = nlohmann::json{{"uPlinkOnlyROHC", alt.uPlinkOnlyROHC}};
        } else
        if constexpr (std::is_same_v<T, ROHC_Parameters_choice_Extension>) {
            j = nlohmann::json{{"choice_Extension", alt.choice_Extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, ROHC_Parameters& v) {
    if (j.contains("rOHC")) {
        ROHC_Parameters_rOHC alt;
        j.at("rOHC").get_to(alt.rOHC);
        v = std::move(alt);
        return;
    }
    if (j.contains("uPlinkOnlyROHC")) {
        ROHC_Parameters_uPlinkOnlyROHC alt;
        j.at("uPlinkOnlyROHC").get_to(alt.uPlinkOnlyROHC);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_Extension")) {
        ROHC_Parameters_choice_Extension alt;
        j.at("choice_Extension").get_to(alt.choice_Extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const PDCP_Configuration& v) {
    j = nlohmann::json::object();
    j["pDCP-SN-Size-UL"] = v.pDCP_SN_Size_UL;
    j["pDCP-SN-Size-DL"] = v.pDCP_SN_Size_DL;
    j["rLC-Mode"] = v.rLC_Mode;
    if (v.rOHC_Parameters.has_value()) {
        j["rOHC-Parameters"] = *v.rOHC_Parameters;
    }
    if (v.t_ReorderingTimer.has_value()) {
        j["t-ReorderingTimer"] = *v.t_ReorderingTimer;
    }
    if (v.discardTimer.has_value()) {
        j["discardTimer"] = *v.discardTimer;
    }
    if (v.uLDataSplitThreshold.has_value()) {
        j["uLDataSplitThreshold"] = *v.uLDataSplitThreshold;
    }
    if (v.pDCP_Duplication.has_value()) {
        j["pDCP-Duplication"] = *v.pDCP_Duplication;
    }
    if (v.pDCP_Reestablishment.has_value()) {
        j["pDCP-Reestablishment"] = *v.pDCP_Reestablishment;
    }
    if (v.pDCP_DataRecovery.has_value()) {
        j["pDCP-DataRecovery"] = *v.pDCP_DataRecovery;
    }
    if (v.duplication_Activation.has_value()) {
        j["duplication-Activation"] = *v.duplication_Activation;
    }
    if (v.outOfOrderDelivery.has_value()) {
        j["outOfOrderDelivery"] = *v.outOfOrderDelivery;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDCP_Configuration& v) {
    if (j.contains("pDCP-SN-Size-UL")) {
        j.at("pDCP-SN-Size-UL").get_to(v.pDCP_SN_Size_UL);
    }
    if (j.contains("pDCP-SN-Size-DL")) {
        j.at("pDCP-SN-Size-DL").get_to(v.pDCP_SN_Size_DL);
    }
    if (j.contains("rLC-Mode")) {
        j.at("rLC-Mode").get_to(v.rLC_Mode);
    }
    if (j.contains("rOHC-Parameters") && !j.at("rOHC-Parameters").is_null()) {
        decltype(v.rOHC_Parameters)::value_type tmp{};
        j.at("rOHC-Parameters").get_to(tmp);
        v.rOHC_Parameters = std::move(tmp);
    }
    if (j.contains("t-ReorderingTimer") && !j.at("t-ReorderingTimer").is_null()) {
        decltype(v.t_ReorderingTimer)::value_type tmp{};
        j.at("t-ReorderingTimer").get_to(tmp);
        v.t_ReorderingTimer = std::move(tmp);
    }
    if (j.contains("discardTimer") && !j.at("discardTimer").is_null()) {
        decltype(v.discardTimer)::value_type tmp{};
        j.at("discardTimer").get_to(tmp);
        v.discardTimer = std::move(tmp);
    }
    if (j.contains("uLDataSplitThreshold") && !j.at("uLDataSplitThreshold").is_null()) {
        decltype(v.uLDataSplitThreshold)::value_type tmp{};
        j.at("uLDataSplitThreshold").get_to(tmp);
        v.uLDataSplitThreshold = std::move(tmp);
    }
    if (j.contains("pDCP-Duplication") && !j.at("pDCP-Duplication").is_null()) {
        decltype(v.pDCP_Duplication)::value_type tmp{};
        j.at("pDCP-Duplication").get_to(tmp);
        v.pDCP_Duplication = std::move(tmp);
    }
    if (j.contains("pDCP-Reestablishment") && !j.at("pDCP-Reestablishment").is_null()) {
        decltype(v.pDCP_Reestablishment)::value_type tmp{};
        j.at("pDCP-Reestablishment").get_to(tmp);
        v.pDCP_Reestablishment = std::move(tmp);
    }
    if (j.contains("pDCP-DataRecovery") && !j.at("pDCP-DataRecovery").is_null()) {
        decltype(v.pDCP_DataRecovery)::value_type tmp{};
        j.at("pDCP-DataRecovery").get_to(tmp);
        v.pDCP_DataRecovery = std::move(tmp);
    }
    if (j.contains("duplication-Activation") && !j.at("duplication-Activation").is_null()) {
        decltype(v.duplication_Activation)::value_type tmp{};
        j.at("duplication-Activation").get_to(tmp);
        v.duplication_Activation = std::move(tmp);
    }
    if (j.contains("outOfOrderDelivery") && !j.at("outOfOrderDelivery").is_null()) {
        decltype(v.outOfOrderDelivery)::value_type tmp{};
        j.at("outOfOrderDelivery").get_to(tmp);
        v.outOfOrderDelivery = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Modify_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.pDCP_Configuration.has_value()) {
        j["pDCP-Configuration"] = *v.pDCP_Configuration;
    }
    if (v.eUTRAN_QoS.has_value()) {
        j["eUTRAN-QoS"] = *v.eUTRAN_QoS;
    }
    if (v.s1_UL_UP_TNL_Information.has_value()) {
        j["s1-UL-UP-TNL-Information"] = *v.s1_UL_UP_TNL_Information;
    }
    if (v.data_Forwarding_Information.has_value()) {
        j["data-Forwarding-Information"] = *v.data_Forwarding_Information;
    }
    if (v.pDCP_SN_Status_Request.has_value()) {
        j["pDCP-SN-Status-Request"] = *v.pDCP_SN_Status_Request;
    }
    if (v.pDCP_SN_Status_Information.has_value()) {
        j["pDCP-SN-Status-Information"] = *v.pDCP_SN_Status_Information;
    }
    if (v.dL_UP_Parameters.has_value()) {
        j["dL-UP-Parameters"] = *v.dL_UP_Parameters;
    }
    if (v.cell_Group_To_Add.has_value()) {
        j["cell-Group-To-Add"] = *v.cell_Group_To_Add;
    }
    if (v.cell_Group_To_Modify.has_value()) {
        j["cell-Group-To-Modify"] = *v.cell_Group_To_Modify;
    }
    if (v.cell_Group_To_Remove.has_value()) {
        j["cell-Group-To-Remove"] = *v.cell_Group_To_Remove;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Modify_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-Configuration") && !j.at("pDCP-Configuration").is_null()) {
        decltype(v.pDCP_Configuration)::value_type tmp{};
        j.at("pDCP-Configuration").get_to(tmp);
        v.pDCP_Configuration = std::move(tmp);
    }
    if (j.contains("eUTRAN-QoS") && !j.at("eUTRAN-QoS").is_null()) {
        decltype(v.eUTRAN_QoS)::value_type tmp{};
        j.at("eUTRAN-QoS").get_to(tmp);
        v.eUTRAN_QoS = std::move(tmp);
    }
    if (j.contains("s1-UL-UP-TNL-Information") && !j.at("s1-UL-UP-TNL-Information").is_null()) {
        decltype(v.s1_UL_UP_TNL_Information)::value_type tmp{};
        j.at("s1-UL-UP-TNL-Information").get_to(tmp);
        v.s1_UL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("data-Forwarding-Information") && !j.at("data-Forwarding-Information").is_null()) {
        decltype(v.data_Forwarding_Information)::value_type tmp{};
        j.at("data-Forwarding-Information").get_to(tmp);
        v.data_Forwarding_Information = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Request") && !j.at("pDCP-SN-Status-Request").is_null()) {
        decltype(v.pDCP_SN_Status_Request)::value_type tmp{};
        j.at("pDCP-SN-Status-Request").get_to(tmp);
        v.pDCP_SN_Status_Request = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Information") && !j.at("pDCP-SN-Status-Information").is_null()) {
        decltype(v.pDCP_SN_Status_Information)::value_type tmp{};
        j.at("pDCP-SN-Status-Information").get_to(tmp);
        v.pDCP_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("dL-UP-Parameters") && !j.at("dL-UP-Parameters").is_null()) {
        decltype(v.dL_UP_Parameters)::value_type tmp{};
        j.at("dL-UP-Parameters").get_to(tmp);
        v.dL_UP_Parameters = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Add") && !j.at("cell-Group-To-Add").is_null()) {
        decltype(v.cell_Group_To_Add)::value_type tmp{};
        j.at("cell-Group-To-Add").get_to(tmp);
        v.cell_Group_To_Add = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Modify") && !j.at("cell-Group-To-Modify").is_null()) {
        decltype(v.cell_Group_To_Modify)::value_type tmp{};
        j.at("cell-Group-To-Modify").get_to(tmp);
        v.cell_Group_To_Modify = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Remove") && !j.at("cell-Group-To-Remove").is_null()) {
        decltype(v.cell_Group_To_Remove)::value_type tmp{};
        j.at("cell-Group-To-Remove").get_to(tmp);
        v.cell_Group_To_Remove = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Modify_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    if (v.sDAP_Configuration.has_value()) {
        j["sDAP-Configuration"] = *v.sDAP_Configuration;
    }
    if (v.pDCP_Configuration.has_value()) {
        j["pDCP-Configuration"] = *v.pDCP_Configuration;
    }
    if (v.dRB_Data_Forwarding_Information.has_value()) {
        j["dRB-Data-Forwarding-Information"] = *v.dRB_Data_Forwarding_Information;
    }
    if (v.pDCP_SN_Status_Request.has_value()) {
        j["pDCP-SN-Status-Request"] = *v.pDCP_SN_Status_Request;
    }
    if (v.pdcp_SN_Status_Information.has_value()) {
        j["pdcp-SN-Status-Information"] = *v.pdcp_SN_Status_Information;
    }
    if (v.dL_UP_Parameters.has_value()) {
        j["dL-UP-Parameters"] = *v.dL_UP_Parameters;
    }
    if (v.cell_Group_To_Add.has_value()) {
        j["cell-Group-To-Add"] = *v.cell_Group_To_Add;
    }
    if (v.cell_Group_To_Modify.has_value()) {
        j["cell-Group-To-Modify"] = *v.cell_Group_To_Modify;
    }
    if (v.cell_Group_To_Remove.has_value()) {
        j["cell-Group-To-Remove"] = *v.cell_Group_To_Remove;
    }
    if (v.flow_Mapping_Information.has_value()) {
        j["flow-Mapping-Information"] = *v.flow_Mapping_Information;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Modify_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("sDAP-Configuration") && !j.at("sDAP-Configuration").is_null()) {
        decltype(v.sDAP_Configuration)::value_type tmp{};
        j.at("sDAP-Configuration").get_to(tmp);
        v.sDAP_Configuration = std::move(tmp);
    }
    if (j.contains("pDCP-Configuration") && !j.at("pDCP-Configuration").is_null()) {
        decltype(v.pDCP_Configuration)::value_type tmp{};
        j.at("pDCP-Configuration").get_to(tmp);
        v.pDCP_Configuration = std::move(tmp);
    }
    if (j.contains("dRB-Data-Forwarding-Information") && !j.at("dRB-Data-Forwarding-Information").is_null()) {
        decltype(v.dRB_Data_Forwarding_Information)::value_type tmp{};
        j.at("dRB-Data-Forwarding-Information").get_to(tmp);
        v.dRB_Data_Forwarding_Information = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Request") && !j.at("pDCP-SN-Status-Request").is_null()) {
        decltype(v.pDCP_SN_Status_Request)::value_type tmp{};
        j.at("pDCP-SN-Status-Request").get_to(tmp);
        v.pDCP_SN_Status_Request = std::move(tmp);
    }
    if (j.contains("pdcp-SN-Status-Information") && !j.at("pdcp-SN-Status-Information").is_null()) {
        decltype(v.pdcp_SN_Status_Information)::value_type tmp{};
        j.at("pdcp-SN-Status-Information").get_to(tmp);
        v.pdcp_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("dL-UP-Parameters") && !j.at("dL-UP-Parameters").is_null()) {
        decltype(v.dL_UP_Parameters)::value_type tmp{};
        j.at("dL-UP-Parameters").get_to(tmp);
        v.dL_UP_Parameters = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Add") && !j.at("cell-Group-To-Add").is_null()) {
        decltype(v.cell_Group_To_Add)::value_type tmp{};
        j.at("cell-Group-To-Add").get_to(tmp);
        v.cell_Group_To_Add = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Modify") && !j.at("cell-Group-To-Modify").is_null()) {
        decltype(v.cell_Group_To_Modify)::value_type tmp{};
        j.at("cell-Group-To-Modify").get_to(tmp);
        v.cell_Group_To_Modify = std::move(tmp);
    }
    if (j.contains("cell-Group-To-Remove") && !j.at("cell-Group-To-Remove").is_null()) {
        decltype(v.cell_Group_To_Remove)::value_type tmp{};
        j.at("cell-Group-To-Remove").get_to(tmp);
        v.cell_Group_To_Remove = std::move(tmp);
    }
    if (j.contains("flow-Mapping-Information") && !j.at("flow-Mapping-Information").is_null()) {
        decltype(v.flow_Mapping_Information)::value_type tmp{};
        j.at("flow-Mapping-Information").get_to(tmp);
        v.flow_Mapping_Information = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Setup_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["pDCP-Configuration"] = v.pDCP_Configuration;
    j["eUTRAN-QoS"] = v.eUTRAN_QoS;
    j["s1-UL-UP-TNL-Information"] = v.s1_UL_UP_TNL_Information;
    if (v.data_Forwarding_Information_Request.has_value()) {
        j["data-Forwarding-Information-Request"] = *v.data_Forwarding_Information_Request;
    }
    j["cell-Group-Information"] = v.cell_Group_Information;
    if (v.dL_UP_Parameters.has_value()) {
        j["dL-UP-Parameters"] = *v.dL_UP_Parameters;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.existing_Allocated_S1_DL_UP_TNL_Info.has_value()) {
        j["existing-Allocated-S1-DL-UP-TNL-Info"] = *v.existing_Allocated_S1_DL_UP_TNL_Info;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Setup_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-Configuration")) {
        j.at("pDCP-Configuration").get_to(v.pDCP_Configuration);
    }
    if (j.contains("eUTRAN-QoS")) {
        j.at("eUTRAN-QoS").get_to(v.eUTRAN_QoS);
    }
    if (j.contains("s1-UL-UP-TNL-Information")) {
        j.at("s1-UL-UP-TNL-Information").get_to(v.s1_UL_UP_TNL_Information);
    }
    if (j.contains("data-Forwarding-Information-Request") && !j.at("data-Forwarding-Information-Request").is_null()) {
        decltype(v.data_Forwarding_Information_Request)::value_type tmp{};
        j.at("data-Forwarding-Information-Request").get_to(tmp);
        v.data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("cell-Group-Information")) {
        j.at("cell-Group-Information").get_to(v.cell_Group_Information);
    }
    if (j.contains("dL-UP-Parameters") && !j.at("dL-UP-Parameters").is_null()) {
        decltype(v.dL_UP_Parameters)::value_type tmp{};
        j.at("dL-UP-Parameters").get_to(tmp);
        v.dL_UP_Parameters = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("existing-Allocated-S1-DL-UP-TNL-Info") && !j.at("existing-Allocated-S1-DL-UP-TNL-Info").is_null()) {
        decltype(v.existing_Allocated_S1_DL_UP_TNL_Info)::value_type tmp{};
        j.at("existing-Allocated-S1-DL-UP-TNL-Info").get_to(tmp);
        v.existing_Allocated_S1_DL_UP_TNL_Info = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Setup_Mod_Item_EUTRAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["pDCP-Configuration"] = v.pDCP_Configuration;
    j["eUTRAN-QoS"] = v.eUTRAN_QoS;
    j["s1-UL-UP-TNL-Information"] = v.s1_UL_UP_TNL_Information;
    if (v.data_Forwarding_Information_Request.has_value()) {
        j["data-Forwarding-Information-Request"] = *v.data_Forwarding_Information_Request;
    }
    j["cell-Group-Information"] = v.cell_Group_Information;
    if (v.dL_UP_Parameters.has_value()) {
        j["dL-UP-Parameters"] = *v.dL_UP_Parameters;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Setup_Mod_Item_EUTRAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("pDCP-Configuration")) {
        j.at("pDCP-Configuration").get_to(v.pDCP_Configuration);
    }
    if (j.contains("eUTRAN-QoS")) {
        j.at("eUTRAN-QoS").get_to(v.eUTRAN_QoS);
    }
    if (j.contains("s1-UL-UP-TNL-Information")) {
        j.at("s1-UL-UP-TNL-Information").get_to(v.s1_UL_UP_TNL_Information);
    }
    if (j.contains("data-Forwarding-Information-Request") && !j.at("data-Forwarding-Information-Request").is_null()) {
        decltype(v.data_Forwarding_Information_Request)::value_type tmp{};
        j.at("data-Forwarding-Information-Request").get_to(tmp);
        v.data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("cell-Group-Information")) {
        j.at("cell-Group-Information").get_to(v.cell_Group_Information);
    }
    if (j.contains("dL-UP-Parameters") && !j.at("dL-UP-Parameters").is_null()) {
        decltype(v.dL_UP_Parameters)::value_type tmp{};
        j.at("dL-UP-Parameters").get_to(tmp);
        v.dL_UP_Parameters = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Setup_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["sDAP-Configuration"] = v.sDAP_Configuration;
    j["pDCP-Configuration"] = v.pDCP_Configuration;
    j["cell-Group-Information"] = v.cell_Group_Information;
    j["qos-flow-Information-To-Be-Setup"] = v.qos_flow_Information_To_Be_Setup;
    if (v.dRB_Data_Forwarding_Information_Request.has_value()) {
        j["dRB-Data-Forwarding-Information-Request"] = *v.dRB_Data_Forwarding_Information_Request;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.pDCP_SN_Status_Information.has_value()) {
        j["pDCP-SN-Status-Information"] = *v.pDCP_SN_Status_Information;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Setup_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("sDAP-Configuration")) {
        j.at("sDAP-Configuration").get_to(v.sDAP_Configuration);
    }
    if (j.contains("pDCP-Configuration")) {
        j.at("pDCP-Configuration").get_to(v.pDCP_Configuration);
    }
    if (j.contains("cell-Group-Information")) {
        j.at("cell-Group-Information").get_to(v.cell_Group_Information);
    }
    if (j.contains("qos-flow-Information-To-Be-Setup")) {
        j.at("qos-flow-Information-To-Be-Setup").get_to(v.qos_flow_Information_To_Be_Setup);
    }
    if (j.contains("dRB-Data-Forwarding-Information-Request") && !j.at("dRB-Data-Forwarding-Information-Request").is_null()) {
        decltype(v.dRB_Data_Forwarding_Information_Request)::value_type tmp{};
        j.at("dRB-Data-Forwarding-Information-Request").get_to(tmp);
        v.dRB_Data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Information") && !j.at("pDCP-SN-Status-Information").is_null()) {
        decltype(v.pDCP_SN_Status_Information)::value_type tmp{};
        j.at("pDCP-SN-Status-Information").get_to(tmp);
        v.pDCP_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const DRB_To_Setup_Mod_Item_NG_RAN& v) {
    j = nlohmann::json::object();
    j["dRB-ID"] = v.dRB_ID;
    j["sDAP-Configuration"] = v.sDAP_Configuration;
    j["pDCP-Configuration"] = v.pDCP_Configuration;
    j["cell-Group-Information"] = v.cell_Group_Information;
    j["flow-Mapping-Information"] = v.flow_Mapping_Information;
    if (v.dRB_Data_Forwarding_Information_Request.has_value()) {
        j["dRB-Data-Forwarding-Information-Request"] = *v.dRB_Data_Forwarding_Information_Request;
    }
    if (v.dRB_Inactivity_Timer.has_value()) {
        j["dRB-Inactivity-Timer"] = *v.dRB_Inactivity_Timer;
    }
    if (v.pDCP_SN_Status_Information.has_value()) {
        j["pDCP-SN-Status-Information"] = *v.pDCP_SN_Status_Information;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, DRB_To_Setup_Mod_Item_NG_RAN& v) {
    if (j.contains("dRB-ID")) {
        j.at("dRB-ID").get_to(v.dRB_ID);
    }
    if (j.contains("sDAP-Configuration")) {
        j.at("sDAP-Configuration").get_to(v.sDAP_Configuration);
    }
    if (j.contains("pDCP-Configuration")) {
        j.at("pDCP-Configuration").get_to(v.pDCP_Configuration);
    }
    if (j.contains("cell-Group-Information")) {
        j.at("cell-Group-Information").get_to(v.cell_Group_Information);
    }
    if (j.contains("flow-Mapping-Information")) {
        j.at("flow-Mapping-Information").get_to(v.flow_Mapping_Information);
    }
    if (j.contains("dRB-Data-Forwarding-Information-Request") && !j.at("dRB-Data-Forwarding-Information-Request").is_null()) {
        decltype(v.dRB_Data_Forwarding_Information_Request)::value_type tmp{};
        j.at("dRB-Data-Forwarding-Information-Request").get_to(tmp);
        v.dRB_Data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("dRB-Inactivity-Timer") && !j.at("dRB-Inactivity-Timer").is_null()) {
        decltype(v.dRB_Inactivity_Timer)::value_type tmp{};
        j.at("dRB-Inactivity-Timer").get_to(tmp);
        v.dRB_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("pDCP-SN-Status-Information") && !j.at("pDCP-SN-Status-Information").is_null()) {
        decltype(v.pDCP_SN_Status_Information)::value_type tmp{};
        j.at("pDCP-SN-Status-Information").get_to(tmp);
        v.pDCP_SN_Status_Information = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_To_Modify_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    if (v.securityIndication.has_value()) {
        j["securityIndication"] = *v.securityIndication;
    }
    if (v.pDU_Session_Resource_DL_AMBR.has_value()) {
        j["pDU-Session-Resource-DL-AMBR"] = *v.pDU_Session_Resource_DL_AMBR;
    }
    if (v.nG_UL_UP_TNL_Information.has_value()) {
        j["nG-UL-UP-TNL-Information"] = *v.nG_UL_UP_TNL_Information;
    }
    if (v.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Request"] = *v.pDU_Session_Data_Forwarding_Information_Request;
    }
    if (v.pDU_Session_Data_Forwarding_Information.has_value()) {
        j["pDU-Session-Data-Forwarding-Information"] = *v.pDU_Session_Data_Forwarding_Information;
    }
    if (v.pDU_Session_Inactivity_Timer.has_value()) {
        j["pDU-Session-Inactivity-Timer"] = *v.pDU_Session_Inactivity_Timer;
    }
    if (v.networkInstance.has_value()) {
        j["networkInstance"] = *v.networkInstance;
    }
    if (v.dRB_To_Setup_List_NG_RAN.has_value()) {
        j["dRB-To-Setup-List-NG-RAN"] = *v.dRB_To_Setup_List_NG_RAN;
    }
    if (v.dRB_To_Modify_List_NG_RAN.has_value()) {
        j["dRB-To-Modify-List-NG-RAN"] = *v.dRB_To_Modify_List_NG_RAN;
    }
    if (v.dRB_To_Remove_List_NG_RAN.has_value()) {
        j["dRB-To-Remove-List-NG-RAN"] = *v.dRB_To_Remove_List_NG_RAN;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_To_Modify_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("securityIndication") && !j.at("securityIndication").is_null()) {
        decltype(v.securityIndication)::value_type tmp{};
        j.at("securityIndication").get_to(tmp);
        v.securityIndication = std::move(tmp);
    }
    if (j.contains("pDU-Session-Resource-DL-AMBR") && !j.at("pDU-Session-Resource-DL-AMBR").is_null()) {
        decltype(v.pDU_Session_Resource_DL_AMBR)::value_type tmp{};
        j.at("pDU-Session-Resource-DL-AMBR").get_to(tmp);
        v.pDU_Session_Resource_DL_AMBR = std::move(tmp);
    }
    if (j.contains("nG-UL-UP-TNL-Information") && !j.at("nG-UL-UP-TNL-Information").is_null()) {
        decltype(v.nG_UL_UP_TNL_Information)::value_type tmp{};
        j.at("nG-UL-UP-TNL-Information").get_to(tmp);
        v.nG_UL_UP_TNL_Information = std::move(tmp);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Request") && !j.at("pDU-Session-Data-Forwarding-Information-Request").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Request)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Request").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information") && !j.at("pDU-Session-Data-Forwarding-Information").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information = std::move(tmp);
    }
    if (j.contains("pDU-Session-Inactivity-Timer") && !j.at("pDU-Session-Inactivity-Timer").is_null()) {
        decltype(v.pDU_Session_Inactivity_Timer)::value_type tmp{};
        j.at("pDU-Session-Inactivity-Timer").get_to(tmp);
        v.pDU_Session_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("networkInstance") && !j.at("networkInstance").is_null()) {
        decltype(v.networkInstance)::value_type tmp{};
        j.at("networkInstance").get_to(tmp);
        v.networkInstance = std::move(tmp);
    }
    if (j.contains("dRB-To-Setup-List-NG-RAN") && !j.at("dRB-To-Setup-List-NG-RAN").is_null()) {
        decltype(v.dRB_To_Setup_List_NG_RAN)::value_type tmp{};
        j.at("dRB-To-Setup-List-NG-RAN").get_to(tmp);
        v.dRB_To_Setup_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-To-Modify-List-NG-RAN") && !j.at("dRB-To-Modify-List-NG-RAN").is_null()) {
        decltype(v.dRB_To_Modify_List_NG_RAN)::value_type tmp{};
        j.at("dRB-To-Modify-List-NG-RAN").get_to(tmp);
        v.dRB_To_Modify_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("dRB-To-Remove-List-NG-RAN") && !j.at("dRB-To-Remove-List-NG-RAN").is_null()) {
        decltype(v.dRB_To_Remove_List_NG_RAN)::value_type tmp{};
        j.at("dRB-To-Remove-List-NG-RAN").get_to(tmp);
        v.dRB_To_Remove_List_NG_RAN = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_To_Setup_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["pDU-Session-Type"] = v.pDU_Session_Type;
    j["sNSSAI"] = v.sNSSAI;
    j["securityIndication"] = v.securityIndication;
    if (v.pDU_Session_Resource_DL_AMBR.has_value()) {
        j["pDU-Session-Resource-DL-AMBR"] = *v.pDU_Session_Resource_DL_AMBR;
    }
    j["nG-UL-UP-TNL-Information"] = v.nG_UL_UP_TNL_Information;
    if (v.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Request"] = *v.pDU_Session_Data_Forwarding_Information_Request;
    }
    if (v.pDU_Session_Inactivity_Timer.has_value()) {
        j["pDU-Session-Inactivity-Timer"] = *v.pDU_Session_Inactivity_Timer;
    }
    if (v.existing_Allocated_NG_DL_UP_TNL_Info.has_value()) {
        j["existing-Allocated-NG-DL-UP-TNL-Info"] = *v.existing_Allocated_NG_DL_UP_TNL_Info;
    }
    if (v.networkInstance.has_value()) {
        j["networkInstance"] = *v.networkInstance;
    }
    j["dRB-To-Setup-List-NG-RAN"] = v.dRB_To_Setup_List_NG_RAN;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_To_Setup_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("pDU-Session-Type")) {
        j.at("pDU-Session-Type").get_to(v.pDU_Session_Type);
    }
    if (j.contains("sNSSAI")) {
        j.at("sNSSAI").get_to(v.sNSSAI);
    }
    if (j.contains("securityIndication")) {
        j.at("securityIndication").get_to(v.securityIndication);
    }
    if (j.contains("pDU-Session-Resource-DL-AMBR") && !j.at("pDU-Session-Resource-DL-AMBR").is_null()) {
        decltype(v.pDU_Session_Resource_DL_AMBR)::value_type tmp{};
        j.at("pDU-Session-Resource-DL-AMBR").get_to(tmp);
        v.pDU_Session_Resource_DL_AMBR = std::move(tmp);
    }
    if (j.contains("nG-UL-UP-TNL-Information")) {
        j.at("nG-UL-UP-TNL-Information").get_to(v.nG_UL_UP_TNL_Information);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Request") && !j.at("pDU-Session-Data-Forwarding-Information-Request").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Request)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Request").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("pDU-Session-Inactivity-Timer") && !j.at("pDU-Session-Inactivity-Timer").is_null()) {
        decltype(v.pDU_Session_Inactivity_Timer)::value_type tmp{};
        j.at("pDU-Session-Inactivity-Timer").get_to(tmp);
        v.pDU_Session_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("existing-Allocated-NG-DL-UP-TNL-Info") && !j.at("existing-Allocated-NG-DL-UP-TNL-Info").is_null()) {
        decltype(v.existing_Allocated_NG_DL_UP_TNL_Info)::value_type tmp{};
        j.at("existing-Allocated-NG-DL-UP-TNL-Info").get_to(tmp);
        v.existing_Allocated_NG_DL_UP_TNL_Info = std::move(tmp);
    }
    if (j.contains("networkInstance") && !j.at("networkInstance").is_null()) {
        decltype(v.networkInstance)::value_type tmp{};
        j.at("networkInstance").get_to(tmp);
        v.networkInstance = std::move(tmp);
    }
    if (j.contains("dRB-To-Setup-List-NG-RAN")) {
        j.at("dRB-To-Setup-List-NG-RAN").get_to(v.dRB_To_Setup_List_NG_RAN);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const PDU_Session_Resource_To_Setup_Mod_Item& v) {
    j = nlohmann::json::object();
    j["pDU-Session-ID"] = v.pDU_Session_ID;
    j["pDU-Session-Type"] = v.pDU_Session_Type;
    j["sNSSAI"] = v.sNSSAI;
    j["securityIndication"] = v.securityIndication;
    if (v.pDU_Session_Resource_AMBR.has_value()) {
        j["pDU-Session-Resource-AMBR"] = *v.pDU_Session_Resource_AMBR;
    }
    j["nG-UL-UP-TNL-Information"] = v.nG_UL_UP_TNL_Information;
    if (v.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
        j["pDU-Session-Data-Forwarding-Information-Request"] = *v.pDU_Session_Data_Forwarding_Information_Request;
    }
    if (v.pDU_Session_Inactivity_Timer.has_value()) {
        j["pDU-Session-Inactivity-Timer"] = *v.pDU_Session_Inactivity_Timer;
    }
    j["dRB-To-Setup-Mod-List-NG-RAN"] = v.dRB_To_Setup_Mod_List_NG_RAN;
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, PDU_Session_Resource_To_Setup_Mod_Item& v) {
    if (j.contains("pDU-Session-ID")) {
        j.at("pDU-Session-ID").get_to(v.pDU_Session_ID);
    }
    if (j.contains("pDU-Session-Type")) {
        j.at("pDU-Session-Type").get_to(v.pDU_Session_Type);
    }
    if (j.contains("sNSSAI")) {
        j.at("sNSSAI").get_to(v.sNSSAI);
    }
    if (j.contains("securityIndication")) {
        j.at("securityIndication").get_to(v.securityIndication);
    }
    if (j.contains("pDU-Session-Resource-AMBR") && !j.at("pDU-Session-Resource-AMBR").is_null()) {
        decltype(v.pDU_Session_Resource_AMBR)::value_type tmp{};
        j.at("pDU-Session-Resource-AMBR").get_to(tmp);
        v.pDU_Session_Resource_AMBR = std::move(tmp);
    }
    if (j.contains("nG-UL-UP-TNL-Information")) {
        j.at("nG-UL-UP-TNL-Information").get_to(v.nG_UL_UP_TNL_Information);
    }
    if (j.contains("pDU-Session-Data-Forwarding-Information-Request") && !j.at("pDU-Session-Data-Forwarding-Information-Request").is_null()) {
        decltype(v.pDU_Session_Data_Forwarding_Information_Request)::value_type tmp{};
        j.at("pDU-Session-Data-Forwarding-Information-Request").get_to(tmp);
        v.pDU_Session_Data_Forwarding_Information_Request = std::move(tmp);
    }
    if (j.contains("pDU-Session-Inactivity-Timer") && !j.at("pDU-Session-Inactivity-Timer").is_null()) {
        decltype(v.pDU_Session_Inactivity_Timer)::value_type tmp{};
        j.at("pDU-Session-Inactivity-Timer").get_to(tmp);
        v.pDU_Session_Inactivity_Timer = std::move(tmp);
    }
    if (j.contains("dRB-To-Setup-Mod-List-NG-RAN")) {
        j.at("dRB-To-Setup-Mod-List-NG-RAN").get_to(v.dRB_To_Setup_Mod_List_NG_RAN);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

} // namespace E1AP_IEs

namespace E1AP_PDU_Contents {

inline void to_json(nlohmann::json& j, const Reset& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, Reset& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

NLOHMANN_JSON_SERIALIZE_ENUM(ResetAll, {
    {ResetAll::reset_all, "reset_all"}
})

inline void to_json(nlohmann::json& j, const ResetType& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, ResetType_e1_Interface>) {
            j = nlohmann::json{{"e1_Interface", alt.e1_Interface}};
        } else
        if constexpr (std::is_same_v<T, ResetType_partOfE1_Interface>) {
            j = nlohmann::json{{"partOfE1_Interface", alt.partOfE1_Interface}};
        } else
        if constexpr (std::is_same_v<T, ResetType_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, ResetType& v) {
    if (j.contains("e1_Interface")) {
        ResetType_e1_Interface alt;
        j.at("e1_Interface").get_to(alt.e1_Interface);
        v = std::move(alt);
        return;
    }
    if (j.contains("partOfE1_Interface")) {
        ResetType_partOfE1_Interface alt;
        j.at("partOfE1_Interface").get_to(alt.partOfE1_Interface);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        ResetType_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const ResetAcknowledge& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, ResetAcknowledge& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const ErrorIndication& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, ErrorIndication& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_E1SetupRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_E1SetupRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const SupportedPLMNs_Item& v) {
    j = nlohmann::json::object();
    j["pLMN-Identity"] = v.pLMN_Identity;
    if (v.slice_Support_List.has_value()) {
        j["slice-Support-List"] = *v.slice_Support_List;
    }
    if (v.nR_CGI_Support_List.has_value()) {
        j["nR-CGI-Support-List"] = *v.nR_CGI_Support_List;
    }
    if (v.qoS_Parameters_Support_List.has_value()) {
        j["qoS-Parameters-Support-List"] = *v.qoS_Parameters_Support_List;
    }
    if (v.iE_Extensions.has_value()) {
        j["iE-Extensions"] = *v.iE_Extensions;
    }
}

inline void from_json(const nlohmann::json& j, SupportedPLMNs_Item& v) {
    if (j.contains("pLMN-Identity")) {
        j.at("pLMN-Identity").get_to(v.pLMN_Identity);
    }
    if (j.contains("slice-Support-List") && !j.at("slice-Support-List").is_null()) {
        decltype(v.slice_Support_List)::value_type tmp{};
        j.at("slice-Support-List").get_to(tmp);
        v.slice_Support_List = std::move(tmp);
    }
    if (j.contains("nR-CGI-Support-List") && !j.at("nR-CGI-Support-List").is_null()) {
        decltype(v.nR_CGI_Support_List)::value_type tmp{};
        j.at("nR-CGI-Support-List").get_to(tmp);
        v.nR_CGI_Support_List = std::move(tmp);
    }
    if (j.contains("qoS-Parameters-Support-List") && !j.at("qoS-Parameters-Support-List").is_null()) {
        decltype(v.qoS_Parameters_Support_List)::value_type tmp{};
        j.at("qoS-Parameters-Support-List").get_to(tmp);
        v.qoS_Parameters_Support_List = std::move(tmp);
    }
    if (j.contains("iE-Extensions") && !j.at("iE-Extensions").is_null()) {
        decltype(v.iE_Extensions)::value_type tmp{};
        j.at("iE-Extensions").get_to(tmp);
        v.iE_Extensions = std::move(tmp);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_E1SetupResponse& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_E1SetupResponse& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_E1SetupFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_E1SetupFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_E1SetupRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_E1SetupRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_E1SetupResponse& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_E1SetupResponse& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_E1SetupFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_E1SetupFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_ConfigurationUpdate& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_ConfigurationUpdate& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_ConfigurationUpdateAcknowledge& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_ConfigurationUpdateAcknowledge& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_ConfigurationUpdateFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_ConfigurationUpdateFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_ConfigurationUpdate& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_ConfigurationUpdate& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_ConfigurationUpdateAcknowledge& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_ConfigurationUpdateAcknowledge& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_CP_ConfigurationUpdateFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_CP_ConfigurationUpdateFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const E1ReleaseRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, E1ReleaseRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const E1ReleaseResponse& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, E1ReleaseResponse& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextSetupRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextSetupRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextSetupRequest& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextSetupRequest", alt.e_UTRAN_BearerContextSetupRequest}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest>) {
            j = nlohmann::json{{"nG_RAN_BearerContextSetupRequest", alt.nG_RAN_BearerContextSetupRequest}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextSetupRequest_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextSetupRequest& v) {
    if (j.contains("e_UTRAN_BearerContextSetupRequest")) {
        System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest alt;
        j.at("e_UTRAN_BearerContextSetupRequest").get_to(alt.e_UTRAN_BearerContextSetupRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextSetupRequest")) {
        System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest alt;
        j.at("nG_RAN_BearerContextSetupRequest").get_to(alt.nG_RAN_BearerContextSetupRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextSetupRequest_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextSetupResponse& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextSetupResponse& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextSetupResponse& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextSetupResponse", alt.e_UTRAN_BearerContextSetupResponse}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse>) {
            j = nlohmann::json{{"nG_RAN_BearerContextSetupResponse", alt.nG_RAN_BearerContextSetupResponse}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextSetupResponse_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextSetupResponse& v) {
    if (j.contains("e_UTRAN_BearerContextSetupResponse")) {
        System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse alt;
        j.at("e_UTRAN_BearerContextSetupResponse").get_to(alt.e_UTRAN_BearerContextSetupResponse);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextSetupResponse")) {
        System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse alt;
        j.at("nG_RAN_BearerContextSetupResponse").get_to(alt.nG_RAN_BearerContextSetupResponse);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextSetupResponse_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextSetupFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextSetupFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextModificationRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextModificationRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextModificationRequest& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextModificationRequest", alt.e_UTRAN_BearerContextModificationRequest}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest>) {
            j = nlohmann::json{{"nG_RAN_BearerContextModificationRequest", alt.nG_RAN_BearerContextModificationRequest}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequest_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextModificationRequest& v) {
    if (j.contains("e_UTRAN_BearerContextModificationRequest")) {
        System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest alt;
        j.at("e_UTRAN_BearerContextModificationRequest").get_to(alt.e_UTRAN_BearerContextModificationRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextModificationRequest")) {
        System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest alt;
        j.at("nG_RAN_BearerContextModificationRequest").get_to(alt.nG_RAN_BearerContextModificationRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextModificationRequest_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextModificationResponse& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextModificationResponse& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextModificationResponse& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextModificationResponse", alt.e_UTRAN_BearerContextModificationResponse}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse>) {
            j = nlohmann::json{{"nG_RAN_BearerContextModificationResponse", alt.nG_RAN_BearerContextModificationResponse}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationResponse_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextModificationResponse& v) {
    if (j.contains("e_UTRAN_BearerContextModificationResponse")) {
        System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse alt;
        j.at("e_UTRAN_BearerContextModificationResponse").get_to(alt.e_UTRAN_BearerContextModificationResponse);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextModificationResponse")) {
        System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse alt;
        j.at("nG_RAN_BearerContextModificationResponse").get_to(alt.nG_RAN_BearerContextModificationResponse);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextModificationResponse_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextModificationFailure& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextModificationFailure& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextModificationRequired& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextModificationRequired& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextModificationRequired& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextModificationRequired", alt.e_UTRAN_BearerContextModificationRequired}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired>) {
            j = nlohmann::json{{"nG_RAN_BearerContextModificationRequired", alt.nG_RAN_BearerContextModificationRequired}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationRequired_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextModificationRequired& v) {
    if (j.contains("e_UTRAN_BearerContextModificationRequired")) {
        System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired alt;
        j.at("e_UTRAN_BearerContextModificationRequired").get_to(alt.e_UTRAN_BearerContextModificationRequired);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextModificationRequired")) {
        System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired alt;
        j.at("nG_RAN_BearerContextModificationRequired").get_to(alt.nG_RAN_BearerContextModificationRequired);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextModificationRequired_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextModificationConfirm& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextModificationConfirm& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_BearerContextModificationConfirm& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm>) {
            j = nlohmann::json{{"e_UTRAN_BearerContextModificationConfirm", alt.e_UTRAN_BearerContextModificationConfirm}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm>) {
            j = nlohmann::json{{"nG_RAN_BearerContextModificationConfirm", alt.nG_RAN_BearerContextModificationConfirm}};
        } else
        if constexpr (std::is_same_v<T, System_BearerContextModificationConfirm_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_BearerContextModificationConfirm& v) {
    if (j.contains("e_UTRAN_BearerContextModificationConfirm")) {
        System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm alt;
        j.at("e_UTRAN_BearerContextModificationConfirm").get_to(alt.e_UTRAN_BearerContextModificationConfirm);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_BearerContextModificationConfirm")) {
        System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm alt;
        j.at("nG_RAN_BearerContextModificationConfirm").get_to(alt.nG_RAN_BearerContextModificationConfirm);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_BearerContextModificationConfirm_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const BearerContextReleaseCommand& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextReleaseCommand& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextReleaseComplete& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextReleaseComplete& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextReleaseRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextReleaseRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const BearerContextInactivityNotification& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, BearerContextInactivityNotification& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const DLDataNotification& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, DLDataNotification& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const ULDataNotification& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, ULDataNotification& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const DataUsageReport& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, DataUsageReport& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_CounterCheckRequest& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_CounterCheckRequest& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const System_GNB_CU_UP_CounterCheckRequest& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest>) {
            j = nlohmann::json{{"e_UTRAN_GNB_CU_UP_CounterCheckRequest", alt.e_UTRAN_GNB_CU_UP_CounterCheckRequest}};
        } else
        if constexpr (std::is_same_v<T, System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest>) {
            j = nlohmann::json{{"nG_RAN_GNB_CU_UP_CounterCheckRequest", alt.nG_RAN_GNB_CU_UP_CounterCheckRequest}};
        } else
        if constexpr (std::is_same_v<T, System_GNB_CU_UP_CounterCheckRequest_choice_extension>) {
            j = nlohmann::json{{"choice_extension", alt.choice_extension}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, System_GNB_CU_UP_CounterCheckRequest& v) {
    if (j.contains("e_UTRAN_GNB_CU_UP_CounterCheckRequest")) {
        System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest alt;
        j.at("e_UTRAN_GNB_CU_UP_CounterCheckRequest").get_to(alt.e_UTRAN_GNB_CU_UP_CounterCheckRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("nG_RAN_GNB_CU_UP_CounterCheckRequest")) {
        System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest alt;
        j.at("nG_RAN_GNB_CU_UP_CounterCheckRequest").get_to(alt.nG_RAN_GNB_CU_UP_CounterCheckRequest);
        v = std::move(alt);
        return;
    }
    if (j.contains("choice_extension")) {
        System_GNB_CU_UP_CounterCheckRequest_choice_extension alt;
        j.at("choice_extension").get_to(alt.choice_extension);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

inline void to_json(nlohmann::json& j, const GNB_CU_UP_StatusIndication& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, GNB_CU_UP_StatusIndication& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const MRDC_DataUsageReport& v) {
    j = nlohmann::json::object();
    j["protocolIEs"] = v.protocolIEs;
}

inline void from_json(const nlohmann::json& j, MRDC_DataUsageReport& v) {
    if (j.contains("protocolIEs")) {
        j.at("protocolIEs").get_to(v.protocolIEs);
    }
}

inline void to_json(nlohmann::json& j, const PrivateMessage& v) {
    j = nlohmann::json::object();
    j["privateIEs"] = v.privateIEs;
}

inline void from_json(const nlohmann::json& j, PrivateMessage& v) {
    if (j.contains("privateIEs")) {
        j.at("privateIEs").get_to(v.privateIEs);
    }
}

} // namespace E1AP_PDU_Contents

namespace E1AP_PDU_Descriptions {

inline void to_json(nlohmann::json& j, const InitiatingMessage& v) {
    j = nlohmann::json::object();
    j["procedureCode"] = v.procedureCode;
    j["criticality"] = v.criticality;
    j["value"] = v.value;
}

inline void from_json(const nlohmann::json& j, InitiatingMessage& v) {
    if (j.contains("procedureCode")) {
        j.at("procedureCode").get_to(v.procedureCode);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("value")) {
        j.at("value").get_to(v.value);
    }
}

inline void to_json(nlohmann::json& j, const SuccessfulOutcome& v) {
    j = nlohmann::json::object();
    j["procedureCode"] = v.procedureCode;
    j["criticality"] = v.criticality;
    j["value"] = v.value;
}

inline void from_json(const nlohmann::json& j, SuccessfulOutcome& v) {
    if (j.contains("procedureCode")) {
        j.at("procedureCode").get_to(v.procedureCode);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("value")) {
        j.at("value").get_to(v.value);
    }
}

inline void to_json(nlohmann::json& j, const UnsuccessfulOutcome& v) {
    j = nlohmann::json::object();
    j["procedureCode"] = v.procedureCode;
    j["criticality"] = v.criticality;
    j["value"] = v.value;
}

inline void from_json(const nlohmann::json& j, UnsuccessfulOutcome& v) {
    if (j.contains("procedureCode")) {
        j.at("procedureCode").get_to(v.procedureCode);
    }
    if (j.contains("criticality")) {
        j.at("criticality").get_to(v.criticality);
    }
    if (j.contains("value")) {
        j.at("value").get_to(v.value);
    }
}

inline void to_json(nlohmann::json& j, const E1AP_PDU& v) {
    std::visit([&j](const auto& alt) {
        using T = std::decay_t<decltype(alt)>;
        if constexpr (std::is_same_v<T, E1AP_PDU_initiatingMessage>) {
            j = nlohmann::json{{"initiatingMessage", alt.initiatingMessage}};
        } else
        if constexpr (std::is_same_v<T, E1AP_PDU_successfulOutcome>) {
            j = nlohmann::json{{"successfulOutcome", alt.successfulOutcome}};
        } else
        if constexpr (std::is_same_v<T, E1AP_PDU_unsuccessfulOutcome>) {
            j = nlohmann::json{{"unsuccessfulOutcome", alt.unsuccessfulOutcome}};
        } else
        if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
            j = nlohmann::json{{"__extension", true}};
        } else
        { (void)alt; } // unreachable
    }, v);
}

inline void from_json(const nlohmann::json& j, E1AP_PDU& v) {
    if (j.contains("initiatingMessage")) {
        E1AP_PDU_initiatingMessage alt;
        j.at("initiatingMessage").get_to(alt.initiatingMessage);
        v = std::move(alt);
        return;
    }
    if (j.contains("successfulOutcome")) {
        E1AP_PDU_successfulOutcome alt;
        j.at("successfulOutcome").get_to(alt.successfulOutcome);
        v = std::move(alt);
        return;
    }
    if (j.contains("unsuccessfulOutcome")) {
        E1AP_PDU_unsuccessfulOutcome alt;
        j.at("unsuccessfulOutcome").get_to(alt.unsuccessfulOutcome);
        v = std::move(alt);
        return;
    }
    // Unknown alternative – leave v unchanged
}

} // namespace E1AP_PDU_Descriptions

} // namespace asn1::generated

inline void registerTypes(
    std::unordered_map<std::string, std::function<void(const nlohmann::json&, asn1::runtime::BitWriter&)>>& encoders,
    std::unordered_map<std::string, std::function<nlohmann::json(asn1::runtime::BitReader&)>>& decoders)
{
    encoders["E1AP_CommonDataTypes::Criticality"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::Criticality obj = j.get<asn1::generated::E1AP_CommonDataTypes::Criticality>();
        asn1::generated::E1AP_CommonDataTypes::encode_Criticality(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::Criticality"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_Criticality(br));
    };
    encoders["E1AP_CommonDataTypes::Presence"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::Presence obj = j.get<asn1::generated::E1AP_CommonDataTypes::Presence>();
        asn1::generated::E1AP_CommonDataTypes::encode_Presence(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::Presence"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_Presence(br));
    };
    encoders["E1AP_CommonDataTypes::PrivateIE_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::PrivateIE_ID obj = j.get<asn1::generated::E1AP_CommonDataTypes::PrivateIE_ID>();
        asn1::generated::E1AP_CommonDataTypes::encode_PrivateIE_ID(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::PrivateIE_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_PrivateIE_ID(br));
    };
    encoders["E1AP_CommonDataTypes::ProcedureCode"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::ProcedureCode obj = j.get<asn1::generated::E1AP_CommonDataTypes::ProcedureCode>();
        asn1::generated::E1AP_CommonDataTypes::encode_ProcedureCode(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::ProcedureCode"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_ProcedureCode(br));
    };
    encoders["E1AP_CommonDataTypes::ProtocolExtensionID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::ProtocolExtensionID obj = j.get<asn1::generated::E1AP_CommonDataTypes::ProtocolExtensionID>();
        asn1::generated::E1AP_CommonDataTypes::encode_ProtocolExtensionID(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::ProtocolExtensionID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_ProtocolExtensionID(br));
    };
    encoders["E1AP_CommonDataTypes::ProtocolIE_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::ProtocolIE_ID obj = j.get<asn1::generated::E1AP_CommonDataTypes::ProtocolIE_ID>();
        asn1::generated::E1AP_CommonDataTypes::encode_ProtocolIE_ID(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::ProtocolIE_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_ProtocolIE_ID(br));
    };
    encoders["E1AP_CommonDataTypes::TriggeringMessage"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_CommonDataTypes::TriggeringMessage obj = j.get<asn1::generated::E1AP_CommonDataTypes::TriggeringMessage>();
        asn1::generated::E1AP_CommonDataTypes::encode_TriggeringMessage(bw, obj);
    };
    decoders["E1AP_CommonDataTypes::TriggeringMessage"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_CommonDataTypes::decode_TriggeringMessage(br));
    };
    encoders["E1AP_Containers::ProtocolIE_Field"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolIE_Field obj = j.get<asn1::generated::E1AP_Containers::ProtocolIE_Field>();
        asn1::generated::E1AP_Containers::encode_ProtocolIE_Field(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolIE_Field"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolIE_Field(br));
    };
    encoders["E1AP_Containers::ProtocolIE_Container"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolIE_Container obj = j.get<asn1::generated::E1AP_Containers::ProtocolIE_Container>();
        asn1::generated::E1AP_Containers::encode_ProtocolIE_Container(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolIE_Container"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolIE_Container(br));
    };
    encoders["E1AP_Containers::ProtocolIE_SingleContainer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolIE_SingleContainer obj = j.get<asn1::generated::E1AP_Containers::ProtocolIE_SingleContainer>();
        asn1::generated::E1AP_Containers::encode_ProtocolIE_SingleContainer(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolIE_SingleContainer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolIE_SingleContainer(br));
    };
    encoders["E1AP_Containers::ProtocolIE_ContainerList"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolIE_ContainerList obj = j.get<asn1::generated::E1AP_Containers::ProtocolIE_ContainerList>();
        asn1::generated::E1AP_Containers::encode_ProtocolIE_ContainerList(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolIE_ContainerList"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolIE_ContainerList(br));
    };
    encoders["E1AP_Containers::ProtocolExtensionField"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolExtensionField obj = j.get<asn1::generated::E1AP_Containers::ProtocolExtensionField>();
        asn1::generated::E1AP_Containers::encode_ProtocolExtensionField(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolExtensionField"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolExtensionField(br));
    };
    encoders["E1AP_Containers::ProtocolExtensionContainer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::ProtocolExtensionContainer obj = j.get<asn1::generated::E1AP_Containers::ProtocolExtensionContainer>();
        asn1::generated::E1AP_Containers::encode_ProtocolExtensionContainer(bw, obj);
    };
    decoders["E1AP_Containers::ProtocolExtensionContainer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_ProtocolExtensionContainer(br));
    };
    encoders["E1AP_Containers::PrivateIE_Field"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::PrivateIE_Field obj = j.get<asn1::generated::E1AP_Containers::PrivateIE_Field>();
        asn1::generated::E1AP_Containers::encode_PrivateIE_Field(bw, obj);
    };
    decoders["E1AP_Containers::PrivateIE_Field"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_PrivateIE_Field(br));
    };
    encoders["E1AP_Containers::PrivateIE_Container"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_Containers::PrivateIE_Container obj = j.get<asn1::generated::E1AP_Containers::PrivateIE_Container>();
        asn1::generated::E1AP_Containers::encode_PrivateIE_Container(bw, obj);
    };
    decoders["E1AP_Containers::PrivateIE_Container"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_Containers::decode_PrivateIE_Container(br));
    };
    encoders["E1AP_IEs::ActivityNotificationLevel"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ActivityNotificationLevel obj = j.get<asn1::generated::E1AP_IEs::ActivityNotificationLevel>();
        asn1::generated::E1AP_IEs::encode_ActivityNotificationLevel(bw, obj);
    };
    decoders["E1AP_IEs::ActivityNotificationLevel"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ActivityNotificationLevel(br));
    };
    encoders["E1AP_IEs::AveragingWindow"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::AveragingWindow obj = j.get<asn1::generated::E1AP_IEs::AveragingWindow>();
        asn1::generated::E1AP_IEs::encode_AveragingWindow(bw, obj);
    };
    decoders["E1AP_IEs::AveragingWindow"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_AveragingWindow(br));
    };
    encoders["E1AP_IEs::BearerContextStatusChange"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::BearerContextStatusChange obj = j.get<asn1::generated::E1AP_IEs::BearerContextStatusChange>();
        asn1::generated::E1AP_IEs::encode_BearerContextStatusChange(bw, obj);
    };
    decoders["E1AP_IEs::BearerContextStatusChange"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_BearerContextStatusChange(br));
    };
    encoders["E1AP_IEs::BitRate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::BitRate obj = j.get<asn1::generated::E1AP_IEs::BitRate>();
        asn1::generated::E1AP_IEs::encode_BitRate(bw, obj);
    };
    decoders["E1AP_IEs::BitRate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_BitRate(br));
    };
    encoders["E1AP_IEs::CauseMisc"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CauseMisc obj = j.get<asn1::generated::E1AP_IEs::CauseMisc>();
        asn1::generated::E1AP_IEs::encode_CauseMisc(bw, obj);
    };
    decoders["E1AP_IEs::CauseMisc"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CauseMisc(br));
    };
    encoders["E1AP_IEs::CauseProtocol"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CauseProtocol obj = j.get<asn1::generated::E1AP_IEs::CauseProtocol>();
        asn1::generated::E1AP_IEs::encode_CauseProtocol(bw, obj);
    };
    decoders["E1AP_IEs::CauseProtocol"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CauseProtocol(br));
    };
    encoders["E1AP_IEs::CauseRadioNetwork"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CauseRadioNetwork obj = j.get<asn1::generated::E1AP_IEs::CauseRadioNetwork>();
        asn1::generated::E1AP_IEs::encode_CauseRadioNetwork(bw, obj);
    };
    decoders["E1AP_IEs::CauseRadioNetwork"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CauseRadioNetwork(br));
    };
    encoders["E1AP_IEs::CauseTransport"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CauseTransport obj = j.get<asn1::generated::E1AP_IEs::CauseTransport>();
        asn1::generated::E1AP_IEs::encode_CauseTransport(bw, obj);
    };
    decoders["E1AP_IEs::CauseTransport"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CauseTransport(br));
    };
    encoders["E1AP_IEs::Cause"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Cause obj = j.get<asn1::generated::E1AP_IEs::Cause>();
        asn1::generated::E1AP_IEs::encode_Cause(bw, obj);
    };
    decoders["E1AP_IEs::Cause"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Cause(br));
    };
    encoders["E1AP_IEs::Cell_Group_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Cell_Group_ID obj = j.get<asn1::generated::E1AP_IEs::Cell_Group_ID>();
        asn1::generated::E1AP_IEs::encode_Cell_Group_ID(bw, obj);
    };
    decoders["E1AP_IEs::Cell_Group_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Cell_Group_ID(br));
    };
    encoders["E1AP_IEs::CipheringAlgorithm"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CipheringAlgorithm obj = j.get<asn1::generated::E1AP_IEs::CipheringAlgorithm>();
        asn1::generated::E1AP_IEs::encode_CipheringAlgorithm(bw, obj);
    };
    decoders["E1AP_IEs::CipheringAlgorithm"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CipheringAlgorithm(br));
    };
    encoders["E1AP_IEs::CNSupport"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CNSupport obj = j.get<asn1::generated::E1AP_IEs::CNSupport>();
        asn1::generated::E1AP_IEs::encode_CNSupport(bw, obj);
    };
    decoders["E1AP_IEs::CNSupport"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CNSupport(br));
    };
    encoders["E1AP_IEs::CommonNetworkInstance"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CommonNetworkInstance obj = j.get<asn1::generated::E1AP_IEs::CommonNetworkInstance>();
        asn1::generated::E1AP_IEs::encode_CommonNetworkInstance(bw, obj);
    };
    decoders["E1AP_IEs::CommonNetworkInstance"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CommonNetworkInstance(br));
    };
    encoders["E1AP_IEs::ConfidentialityProtectionIndication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ConfidentialityProtectionIndication obj = j.get<asn1::generated::E1AP_IEs::ConfidentialityProtectionIndication>();
        asn1::generated::E1AP_IEs::encode_ConfidentialityProtectionIndication(bw, obj);
    };
    decoders["E1AP_IEs::ConfidentialityProtectionIndication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ConfidentialityProtectionIndication(br));
    };
    encoders["E1AP_IEs::ConfidentialityProtectionResult"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ConfidentialityProtectionResult obj = j.get<asn1::generated::E1AP_IEs::ConfidentialityProtectionResult>();
        asn1::generated::E1AP_IEs::encode_ConfidentialityProtectionResult(bw, obj);
    };
    decoders["E1AP_IEs::ConfidentialityProtectionResult"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ConfidentialityProtectionResult(br));
    };
    encoders["E1AP_IEs::Data_Forwarding_Request"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Forwarding_Request obj = j.get<asn1::generated::E1AP_IEs::Data_Forwarding_Request>();
        asn1::generated::E1AP_IEs::encode_Data_Forwarding_Request(bw, obj);
    };
    decoders["E1AP_IEs::Data_Forwarding_Request"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Forwarding_Request(br));
    };
    encoders["E1AP_IEs::DefaultDRB"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DefaultDRB obj = j.get<asn1::generated::E1AP_IEs::DefaultDRB>();
        asn1::generated::E1AP_IEs::encode_DefaultDRB(bw, obj);
    };
    decoders["E1AP_IEs::DefaultDRB"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DefaultDRB(br));
    };
    encoders["E1AP_IEs::DiscardTimer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DiscardTimer obj = j.get<asn1::generated::E1AP_IEs::DiscardTimer>();
        asn1::generated::E1AP_IEs::encode_DiscardTimer(bw, obj);
    };
    decoders["E1AP_IEs::DiscardTimer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DiscardTimer(br));
    };
    encoders["E1AP_IEs::DL_TX_Stop"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DL_TX_Stop obj = j.get<asn1::generated::E1AP_IEs::DL_TX_Stop>();
        asn1::generated::E1AP_IEs::encode_DL_TX_Stop(bw, obj);
    };
    decoders["E1AP_IEs::DL_TX_Stop"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DL_TX_Stop(br));
    };
    encoders["E1AP_IEs::DRB_Activity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Activity obj = j.get<asn1::generated::E1AP_IEs::DRB_Activity>();
        asn1::generated::E1AP_IEs::encode_DRB_Activity(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Activity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Activity(br));
    };
    encoders["E1AP_IEs::DRB_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_ID obj = j.get<asn1::generated::E1AP_IEs::DRB_ID>();
        asn1::generated::E1AP_IEs::encode_DRB_ID(bw, obj);
    };
    decoders["E1AP_IEs::DRB_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_ID(br));
    };
    encoders["E1AP_IEs::DRB_Activity_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Activity_Item obj = j.get<asn1::generated::E1AP_IEs::DRB_Activity_Item>();
        asn1::generated::E1AP_IEs::encode_DRB_Activity_Item(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Activity_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Activity_Item(br));
    };
    encoders["E1AP_IEs::DRB_Activity_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Activity_List obj = j.get<asn1::generated::E1AP_IEs::DRB_Activity_List>();
        asn1::generated::E1AP_IEs::encode_DRB_Activity_List(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Activity_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Activity_List(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Mod_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Mod_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Mod_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Mod_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Mod_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Mod_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Mod_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Mod_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Mod_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Mod_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_Mod_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_Mod_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_Mod_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_Mod_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_Mod_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_To_Modify_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_To_Modify_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_To_Modify_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_To_Modify_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_To_Modify_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_To_Modify_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_To_Modify_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_To_Modify_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_To_Modify_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Failed_To_Modify_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Failed_To_Modify_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Failed_To_Modify_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Remove_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Remove_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Remove_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Remove_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Remove_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Remove_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Remove_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Remove_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Remove_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Remove_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Remove_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Remove_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Remove_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Remove_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Remove_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Remove_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Remove_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Remove_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Remove_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Remove_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Remove_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Remove_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Remove_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Remove_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Remove_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Remove_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Remove_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Remove_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Remove_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Remove_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Remove_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Remove_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Remove_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Remove_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Remove_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Remove_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Usage_Report_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Usage_Report_Item obj = j.get<asn1::generated::E1AP_IEs::DRB_Usage_Report_Item>();
        asn1::generated::E1AP_IEs::encode_DRB_Usage_Report_Item(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Usage_Report_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Usage_Report_Item(br));
    };
    encoders["E1AP_IEs::DRB_Usage_Report_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Usage_Report_List obj = j.get<asn1::generated::E1AP_IEs::DRB_Usage_Report_List>();
        asn1::generated::E1AP_IEs::encode_DRB_Usage_Report_List(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Usage_Report_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Usage_Report_List(br));
    };
    encoders["E1AP_IEs::Duplication_Activation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Duplication_Activation obj = j.get<asn1::generated::E1AP_IEs::Duplication_Activation>();
        asn1::generated::E1AP_IEs::encode_Duplication_Activation(bw, obj);
    };
    decoders["E1AP_IEs::Duplication_Activation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Duplication_Activation(br));
    };
    encoders["E1AP_IEs::DataDiscardRequired"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DataDiscardRequired obj = j.get<asn1::generated::E1AP_IEs::DataDiscardRequired>();
        asn1::generated::E1AP_IEs::encode_DataDiscardRequired(bw, obj);
    };
    decoders["E1AP_IEs::DataDiscardRequired"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DataDiscardRequired(br));
    };
    encoders["E1AP_IEs::EncryptionKey"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::EncryptionKey obj = j.get<asn1::generated::E1AP_IEs::EncryptionKey>();
        asn1::generated::E1AP_IEs::encode_EncryptionKey(bw, obj);
    };
    decoders["E1AP_IEs::EncryptionKey"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_EncryptionKey(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_Name"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_Name obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_Name>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_Name(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_Name"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_Name(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_UE_E1AP_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_UE_E1AP_ID obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_UE_E1AP_ID>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_UE_E1AP_ID(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_UE_E1AP_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_UE_E1AP_ID(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_Capacity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_Capacity obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_Capacity>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_Capacity(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_Capacity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_Capacity(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_ID obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_ID>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_ID(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_ID(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_Name"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_Name obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_Name>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_Name(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_Name"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_Name(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_UE_E1AP_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_UE_E1AP_ID obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_UE_E1AP_ID>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_UE_E1AP_ID(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_UE_E1AP_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_UE_E1AP_ID(br));
    };
    encoders["E1AP_IEs::GBR_QosInformation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GBR_QosInformation obj = j.get<asn1::generated::E1AP_IEs::GBR_QosInformation>();
        asn1::generated::E1AP_IEs::encode_GBR_QosInformation(bw, obj);
    };
    decoders["E1AP_IEs::GBR_QosInformation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GBR_QosInformation(br));
    };
    encoders["E1AP_IEs::GTP_TEID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GTP_TEID obj = j.get<asn1::generated::E1AP_IEs::GTP_TEID>();
        asn1::generated::E1AP_IEs::encode_GTP_TEID(bw, obj);
    };
    decoders["E1AP_IEs::GTP_TEID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GTP_TEID(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_OverloadInformation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_OverloadInformation obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_OverloadInformation>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_OverloadInformation(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_OverloadInformation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_OverloadInformation(br));
    };
    encoders["E1AP_IEs::GNB_DU_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_DU_ID obj = j.get<asn1::generated::E1AP_IEs::GNB_DU_ID>();
        asn1::generated::E1AP_IEs::encode_GNB_DU_ID(bw, obj);
    };
    decoders["E1AP_IEs::GNB_DU_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_DU_ID(br));
    };
    encoders["E1AP_IEs::HFN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::HFN obj = j.get<asn1::generated::E1AP_IEs::HFN>();
        asn1::generated::E1AP_IEs::encode_HFN(bw, obj);
    };
    decoders["E1AP_IEs::HFN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_HFN(br));
    };
    encoders["E1AP_IEs::IntegrityProtectionIndication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::IntegrityProtectionIndication obj = j.get<asn1::generated::E1AP_IEs::IntegrityProtectionIndication>();
        asn1::generated::E1AP_IEs::encode_IntegrityProtectionIndication(bw, obj);
    };
    decoders["E1AP_IEs::IntegrityProtectionIndication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_IntegrityProtectionIndication(br));
    };
    encoders["E1AP_IEs::IntegrityProtectionAlgorithm"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::IntegrityProtectionAlgorithm obj = j.get<asn1::generated::E1AP_IEs::IntegrityProtectionAlgorithm>();
        asn1::generated::E1AP_IEs::encode_IntegrityProtectionAlgorithm(bw, obj);
    };
    decoders["E1AP_IEs::IntegrityProtectionAlgorithm"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_IntegrityProtectionAlgorithm(br));
    };
    encoders["E1AP_IEs::IntegrityProtectionKey"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::IntegrityProtectionKey obj = j.get<asn1::generated::E1AP_IEs::IntegrityProtectionKey>();
        asn1::generated::E1AP_IEs::encode_IntegrityProtectionKey(bw, obj);
    };
    decoders["E1AP_IEs::IntegrityProtectionKey"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_IntegrityProtectionKey(br));
    };
    encoders["E1AP_IEs::IntegrityProtectionResult"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::IntegrityProtectionResult obj = j.get<asn1::generated::E1AP_IEs::IntegrityProtectionResult>();
        asn1::generated::E1AP_IEs::encode_IntegrityProtectionResult(bw, obj);
    };
    decoders["E1AP_IEs::IntegrityProtectionResult"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_IntegrityProtectionResult(br));
    };
    encoders["E1AP_IEs::Inactivity_Timer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Inactivity_Timer obj = j.get<asn1::generated::E1AP_IEs::Inactivity_Timer>();
        asn1::generated::E1AP_IEs::encode_Inactivity_Timer(bw, obj);
    };
    decoders["E1AP_IEs::Inactivity_Timer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Inactivity_Timer(br));
    };
    encoders["E1AP_IEs::MaxDataBurstVolume"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MaxDataBurstVolume obj = j.get<asn1::generated::E1AP_IEs::MaxDataBurstVolume>();
        asn1::generated::E1AP_IEs::encode_MaxDataBurstVolume(bw, obj);
    };
    decoders["E1AP_IEs::MaxDataBurstVolume"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MaxDataBurstVolume(br));
    };
    encoders["E1AP_IEs::MaxIPrate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MaxIPrate obj = j.get<asn1::generated::E1AP_IEs::MaxIPrate>();
        asn1::generated::E1AP_IEs::encode_MaxIPrate(bw, obj);
    };
    decoders["E1AP_IEs::MaxIPrate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MaxIPrate(br));
    };
    encoders["E1AP_IEs::MaximumIPdatarate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MaximumIPdatarate obj = j.get<asn1::generated::E1AP_IEs::MaximumIPdatarate>();
        asn1::generated::E1AP_IEs::encode_MaximumIPdatarate(bw, obj);
    };
    decoders["E1AP_IEs::MaximumIPdatarate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MaximumIPdatarate(br));
    };
    encoders["E1AP_IEs::MaxPacketLossRate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MaxPacketLossRate obj = j.get<asn1::generated::E1AP_IEs::MaxPacketLossRate>();
        asn1::generated::E1AP_IEs::encode_MaxPacketLossRate(bw, obj);
    };
    decoders["E1AP_IEs::MaxPacketLossRate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MaxPacketLossRate(br));
    };
    encoders["E1AP_IEs::GBR_QoSFlowInformation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GBR_QoSFlowInformation obj = j.get<asn1::generated::E1AP_IEs::GBR_QoSFlowInformation>();
        asn1::generated::E1AP_IEs::encode_GBR_QoSFlowInformation(bw, obj);
    };
    decoders["E1AP_IEs::GBR_QoSFlowInformation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GBR_QoSFlowInformation(br));
    };
    encoders["E1AP_IEs::MRDC_Data_Usage_Report_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MRDC_Data_Usage_Report_Item obj = j.get<asn1::generated::E1AP_IEs::MRDC_Data_Usage_Report_Item>();
        asn1::generated::E1AP_IEs::encode_MRDC_Data_Usage_Report_Item(bw, obj);
    };
    decoders["E1AP_IEs::MRDC_Data_Usage_Report_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MRDC_Data_Usage_Report_Item(br));
    };
    encoders["E1AP_IEs::Data_Usage_per_PDU_Session_Report"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Usage_per_PDU_Session_Report obj = j.get<asn1::generated::E1AP_IEs::Data_Usage_per_PDU_Session_Report>();
        asn1::generated::E1AP_IEs::encode_Data_Usage_per_PDU_Session_Report(bw, obj);
    };
    decoders["E1AP_IEs::Data_Usage_per_PDU_Session_Report"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Usage_per_PDU_Session_Report(br));
    };
    encoders["E1AP_IEs::NetworkInstance"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NetworkInstance obj = j.get<asn1::generated::E1AP_IEs::NetworkInstance>();
        asn1::generated::E1AP_IEs::encode_NetworkInstance(bw, obj);
    };
    decoders["E1AP_IEs::NetworkInstance"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NetworkInstance(br));
    };
    encoders["E1AP_IEs::New_UL_TNL_Information_Required"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::New_UL_TNL_Information_Required obj = j.get<asn1::generated::E1AP_IEs::New_UL_TNL_Information_Required>();
        asn1::generated::E1AP_IEs::encode_New_UL_TNL_Information_Required(bw, obj);
    };
    decoders["E1AP_IEs::New_UL_TNL_Information_Required"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_New_UL_TNL_Information_Required(br));
    };
    encoders["E1AP_IEs::NR_Cell_Identity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NR_Cell_Identity obj = j.get<asn1::generated::E1AP_IEs::NR_Cell_Identity>();
        asn1::generated::E1AP_IEs::encode_NR_Cell_Identity(bw, obj);
    };
    decoders["E1AP_IEs::NR_Cell_Identity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NR_Cell_Identity(br));
    };
    encoders["E1AP_IEs::OutOfOrderDelivery"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::OutOfOrderDelivery obj = j.get<asn1::generated::E1AP_IEs::OutOfOrderDelivery>();
        asn1::generated::E1AP_IEs::encode_OutOfOrderDelivery(bw, obj);
    };
    decoders["E1AP_IEs::OutOfOrderDelivery"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_OutOfOrderDelivery(br));
    };
    encoders["E1AP_IEs::PacketDelayBudget"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PacketDelayBudget obj = j.get<asn1::generated::E1AP_IEs::PacketDelayBudget>();
        asn1::generated::E1AP_IEs::encode_PacketDelayBudget(bw, obj);
    };
    decoders["E1AP_IEs::PacketDelayBudget"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PacketDelayBudget(br));
    };
    encoders["E1AP_IEs::PER_Scalar"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PER_Scalar obj = j.get<asn1::generated::E1AP_IEs::PER_Scalar>();
        asn1::generated::E1AP_IEs::encode_PER_Scalar(bw, obj);
    };
    decoders["E1AP_IEs::PER_Scalar"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PER_Scalar(br));
    };
    encoders["E1AP_IEs::PER_Exponent"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PER_Exponent obj = j.get<asn1::generated::E1AP_IEs::PER_Exponent>();
        asn1::generated::E1AP_IEs::encode_PER_Exponent(bw, obj);
    };
    decoders["E1AP_IEs::PER_Exponent"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PER_Exponent(br));
    };
    encoders["E1AP_IEs::PacketErrorRate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PacketErrorRate obj = j.get<asn1::generated::E1AP_IEs::PacketErrorRate>();
        asn1::generated::E1AP_IEs::encode_PacketErrorRate(bw, obj);
    };
    decoders["E1AP_IEs::PacketErrorRate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PacketErrorRate(br));
    };
    encoders["E1AP_IEs::PDCP_SN_Status_Request"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_SN_Status_Request obj = j.get<asn1::generated::E1AP_IEs::PDCP_SN_Status_Request>();
        asn1::generated::E1AP_IEs::encode_PDCP_SN_Status_Request(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_SN_Status_Request"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_SN_Status_Request(br));
    };
    encoders["E1AP_IEs::PDCP_DataRecovery"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_DataRecovery obj = j.get<asn1::generated::E1AP_IEs::PDCP_DataRecovery>();
        asn1::generated::E1AP_IEs::encode_PDCP_DataRecovery(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_DataRecovery"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_DataRecovery(br));
    };
    encoders["E1AP_IEs::PDCP_Duplication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_Duplication obj = j.get<asn1::generated::E1AP_IEs::PDCP_Duplication>();
        asn1::generated::E1AP_IEs::encode_PDCP_Duplication(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_Duplication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_Duplication(br));
    };
    encoders["E1AP_IEs::PDCP_Reestablishment"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_Reestablishment obj = j.get<asn1::generated::E1AP_IEs::PDCP_Reestablishment>();
        asn1::generated::E1AP_IEs::encode_PDCP_Reestablishment(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_Reestablishment"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_Reestablishment(br));
    };
    encoders["E1AP_IEs::PDCP_SN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_SN obj = j.get<asn1::generated::E1AP_IEs::PDCP_SN>();
        asn1::generated::E1AP_IEs::encode_PDCP_SN(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_SN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_SN(br));
    };
    encoders["E1AP_IEs::PDCP_Count"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_Count obj = j.get<asn1::generated::E1AP_IEs::PDCP_Count>();
        asn1::generated::E1AP_IEs::encode_PDCP_Count(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_Count"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_Count(br));
    };
    encoders["E1AP_IEs::DRB_Status_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Status_Item obj = j.get<asn1::generated::E1AP_IEs::DRB_Status_Item>();
        asn1::generated::E1AP_IEs::encode_DRB_Status_Item(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Status_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Status_Item(br));
    };
    encoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRBs_Subject_To_Counter_Check_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRBs_Subject_To_Counter_Check_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::PDCP_SN_Size"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_SN_Size obj = j.get<asn1::generated::E1AP_IEs::PDCP_SN_Size>();
        asn1::generated::E1AP_IEs::encode_PDCP_SN_Size(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_SN_Size"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_SN_Size(br));
    };
    encoders["E1AP_IEs::DRBBStatusTransfer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRBBStatusTransfer obj = j.get<asn1::generated::E1AP_IEs::DRBBStatusTransfer>();
        asn1::generated::E1AP_IEs::encode_DRBBStatusTransfer(bw, obj);
    };
    decoders["E1AP_IEs::DRBBStatusTransfer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRBBStatusTransfer(br));
    };
    encoders["E1AP_IEs::PDCP_SN_Status_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_SN_Status_Information obj = j.get<asn1::generated::E1AP_IEs::PDCP_SN_Status_Information>();
        asn1::generated::E1AP_IEs::encode_PDCP_SN_Status_Information(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_SN_Status_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_SN_Status_Information(br));
    };
    encoders["E1AP_IEs::PDU_Session_ID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_ID obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_ID>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_ID(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_ID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_ID(br));
    };
    encoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRBs_Subject_To_Counter_Check_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRBs_Subject_To_Counter_Check_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRBs_Subject_To_Counter_Check_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRBs_Subject_To_Counter_Check_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Activity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Activity(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Activity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Activity(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Activity_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Activity_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Activity_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Activity_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Activity_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Activity_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Activity_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Activity_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Activity_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_Mod_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Mod_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Mod_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_Mod_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_Mod_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_Mod_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_Mod_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Mod_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_Mod_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_Mod_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_Mod_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_Mod_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_To_Modify_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_To_Modify_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Failed_To_Modify_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Failed_To_Modify_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Failed_To_Modify_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Remove_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Remove_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Remove_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Remove_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Remove_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Remove_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Remove_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Remove_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Remove_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Remove_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Remove_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Remove_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Type"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Type obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Type>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Type(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Type"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Type(br));
    };
    encoders["E1AP_IEs::PLMN_Identity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PLMN_Identity obj = j.get<asn1::generated::E1AP_IEs::PLMN_Identity>();
        asn1::generated::E1AP_IEs::encode_PLMN_Identity(bw, obj);
    };
    decoders["E1AP_IEs::PLMN_Identity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PLMN_Identity(br));
    };
    encoders["E1AP_IEs::NR_CGI"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NR_CGI obj = j.get<asn1::generated::E1AP_IEs::NR_CGI>();
        asn1::generated::E1AP_IEs::encode_NR_CGI(bw, obj);
    };
    decoders["E1AP_IEs::NR_CGI"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NR_CGI(br));
    };
    encoders["E1AP_IEs::NR_CGI_Support_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NR_CGI_Support_Item obj = j.get<asn1::generated::E1AP_IEs::NR_CGI_Support_Item>();
        asn1::generated::E1AP_IEs::encode_NR_CGI_Support_Item(bw, obj);
    };
    decoders["E1AP_IEs::NR_CGI_Support_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NR_CGI_Support_Item(br));
    };
    encoders["E1AP_IEs::NR_CGI_Support_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NR_CGI_Support_List obj = j.get<asn1::generated::E1AP_IEs::NR_CGI_Support_List>();
        asn1::generated::E1AP_IEs::encode_NR_CGI_Support_List(bw, obj);
    };
    decoders["E1AP_IEs::NR_CGI_Support_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NR_CGI_Support_List(br));
    };
    encoders["E1AP_IEs::PortNumber"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PortNumber obj = j.get<asn1::generated::E1AP_IEs::PortNumber>();
        asn1::generated::E1AP_IEs::encode_PortNumber(bw, obj);
    };
    decoders["E1AP_IEs::PortNumber"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PortNumber(br));
    };
    encoders["E1AP_IEs::PPI"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PPI obj = j.get<asn1::generated::E1AP_IEs::PPI>();
        asn1::generated::E1AP_IEs::encode_PPI(bw, obj);
    };
    decoders["E1AP_IEs::PPI"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PPI(br));
    };
    encoders["E1AP_IEs::PriorityLevel"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PriorityLevel obj = j.get<asn1::generated::E1AP_IEs::PriorityLevel>();
        asn1::generated::E1AP_IEs::encode_PriorityLevel(bw, obj);
    };
    decoders["E1AP_IEs::PriorityLevel"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PriorityLevel(br));
    };
    encoders["E1AP_IEs::Pre_emptionCapability"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Pre_emptionCapability obj = j.get<asn1::generated::E1AP_IEs::Pre_emptionCapability>();
        asn1::generated::E1AP_IEs::encode_Pre_emptionCapability(bw, obj);
    };
    decoders["E1AP_IEs::Pre_emptionCapability"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Pre_emptionCapability(br));
    };
    encoders["E1AP_IEs::Pre_emptionVulnerability"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Pre_emptionVulnerability obj = j.get<asn1::generated::E1AP_IEs::Pre_emptionVulnerability>();
        asn1::generated::E1AP_IEs::encode_Pre_emptionVulnerability(bw, obj);
    };
    decoders["E1AP_IEs::Pre_emptionVulnerability"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Pre_emptionVulnerability(br));
    };
    encoders["E1AP_IEs::EUTRANAllocationAndRetentionPriority"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::EUTRANAllocationAndRetentionPriority obj = j.get<asn1::generated::E1AP_IEs::EUTRANAllocationAndRetentionPriority>();
        asn1::generated::E1AP_IEs::encode_EUTRANAllocationAndRetentionPriority(bw, obj);
    };
    decoders["E1AP_IEs::EUTRANAllocationAndRetentionPriority"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_EUTRANAllocationAndRetentionPriority(br));
    };
    encoders["E1AP_IEs::NGRANAllocationAndRetentionPriority"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NGRANAllocationAndRetentionPriority obj = j.get<asn1::generated::E1AP_IEs::NGRANAllocationAndRetentionPriority>();
        asn1::generated::E1AP_IEs::encode_NGRANAllocationAndRetentionPriority(bw, obj);
    };
    decoders["E1AP_IEs::NGRANAllocationAndRetentionPriority"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NGRANAllocationAndRetentionPriority(br));
    };
    encoders["E1AP_IEs::QCI"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QCI obj = j.get<asn1::generated::E1AP_IEs::QCI>();
        asn1::generated::E1AP_IEs::encode_QCI(bw, obj);
    };
    decoders["E1AP_IEs::QCI"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QCI(br));
    };
    encoders["E1AP_IEs::EUTRAN_QoS"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::EUTRAN_QoS obj = j.get<asn1::generated::E1AP_IEs::EUTRAN_QoS>();
        asn1::generated::E1AP_IEs::encode_EUTRAN_QoS(bw, obj);
    };
    decoders["E1AP_IEs::EUTRAN_QoS"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_EUTRAN_QoS(br));
    };
    encoders["E1AP_IEs::EUTRAN_QoS_Support_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_Item obj = j.get<asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_Item>();
        asn1::generated::E1AP_IEs::encode_EUTRAN_QoS_Support_Item(bw, obj);
    };
    decoders["E1AP_IEs::EUTRAN_QoS_Support_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_EUTRAN_QoS_Support_Item(br));
    };
    encoders["E1AP_IEs::EUTRAN_QoS_Support_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_List obj = j.get<asn1::generated::E1AP_IEs::EUTRAN_QoS_Support_List>();
        asn1::generated::E1AP_IEs::encode_EUTRAN_QoS_Support_List(bw, obj);
    };
    decoders["E1AP_IEs::EUTRAN_QoS_Support_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_EUTRAN_QoS_Support_List(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Identifier"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Identifier obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Identifier>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Identifier(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Identifier"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Identifier(br));
    };
    encoders["E1AP_IEs::Data_Usage_per_QoS_Flow_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_Item obj = j.get<asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_Item>();
        asn1::generated::E1AP_IEs::encode_Data_Usage_per_QoS_Flow_Item(bw, obj);
    };
    decoders["E1AP_IEs::Data_Usage_per_QoS_Flow_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Usage_per_QoS_Flow_Item(br));
    };
    encoders["E1AP_IEs::Data_Usage_per_QoS_Flow_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_List obj = j.get<asn1::generated::E1AP_IEs::Data_Usage_per_QoS_Flow_List>();
        asn1::generated::E1AP_IEs::encode_Data_Usage_per_QoS_Flow_List(bw, obj);
    };
    decoders["E1AP_IEs::Data_Usage_per_QoS_Flow_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Usage_per_QoS_Flow_List(br));
    };
    encoders["E1AP_IEs::MRDC_Usage_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::MRDC_Usage_Information obj = j.get<asn1::generated::E1AP_IEs::MRDC_Usage_Information>();
        asn1::generated::E1AP_IEs::encode_MRDC_Usage_Information(bw, obj);
    };
    decoders["E1AP_IEs::MRDC_Usage_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_MRDC_Usage_Information(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Data_Usage_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Data_Usage_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Data_Usage_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Data_Usage_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Data_Usage_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Data_Usage_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Data_Usage_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Data_Usage_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Data_Usage_List(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Item obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Item>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Item(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Item(br));
    };
    encoders["E1AP_IEs::QoS_Flow_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_List obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_List>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_List(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_To_Notify_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_To_Notify_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_To_Notify_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_To_Notify_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_To_Notify_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_To_Notify_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_To_Notify_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_To_Notify_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_To_Notify_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_To_Notify_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_To_Notify_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_To_Notify_List(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Failed_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Failed_Item obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Failed_Item>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Failed_Item(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Failed_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Failed_Item(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Failed_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Failed_List obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Failed_List>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Failed_List(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Failed_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Failed_List(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Mapping_Indication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Indication obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Indication>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Mapping_Indication(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Mapping_Indication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Mapping_Indication(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Mapping_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Item obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Mapping_Item>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Mapping_Item(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Mapping_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Mapping_Item(br));
    };
    encoders["E1AP_IEs::QoS_Flow_Mapping_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_Mapping_List obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_Mapping_List>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_Mapping_List(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_Mapping_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_Mapping_List(br));
    };
    encoders["E1AP_IEs::Data_Forwarding_Information_Request"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Forwarding_Information_Request obj = j.get<asn1::generated::E1AP_IEs::Data_Forwarding_Information_Request>();
        asn1::generated::E1AP_IEs::encode_Data_Forwarding_Information_Request(bw, obj);
    };
    decoders["E1AP_IEs::Data_Forwarding_Information_Request"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Forwarding_Information_Request(br));
    };
    encoders["E1AP_IEs::QoSPriorityLevel"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoSPriorityLevel obj = j.get<asn1::generated::E1AP_IEs::QoSPriorityLevel>();
        asn1::generated::E1AP_IEs::encode_QoSPriorityLevel(bw, obj);
    };
    decoders["E1AP_IEs::QoSPriorityLevel"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoSPriorityLevel(br));
    };
    encoders["E1AP_IEs::Dynamic5QIDescriptor"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Dynamic5QIDescriptor obj = j.get<asn1::generated::E1AP_IEs::Dynamic5QIDescriptor>();
        asn1::generated::E1AP_IEs::encode_Dynamic5QIDescriptor(bw, obj);
    };
    decoders["E1AP_IEs::Dynamic5QIDescriptor"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Dynamic5QIDescriptor(br));
    };
    encoders["E1AP_IEs::Non_Dynamic5QIDescriptor"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Non_Dynamic5QIDescriptor obj = j.get<asn1::generated::E1AP_IEs::Non_Dynamic5QIDescriptor>();
        asn1::generated::E1AP_IEs::encode_Non_Dynamic5QIDescriptor(bw, obj);
    };
    decoders["E1AP_IEs::Non_Dynamic5QIDescriptor"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Non_Dynamic5QIDescriptor(br));
    };
    encoders["E1AP_IEs::NG_RAN_QoS_Support_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_Item obj = j.get<asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_Item>();
        asn1::generated::E1AP_IEs::encode_NG_RAN_QoS_Support_Item(bw, obj);
    };
    decoders["E1AP_IEs::NG_RAN_QoS_Support_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NG_RAN_QoS_Support_Item(br));
    };
    encoders["E1AP_IEs::NG_RAN_QoS_Support_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_List obj = j.get<asn1::generated::E1AP_IEs::NG_RAN_QoS_Support_List>();
        asn1::generated::E1AP_IEs::encode_NG_RAN_QoS_Support_List(bw, obj);
    };
    decoders["E1AP_IEs::NG_RAN_QoS_Support_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_NG_RAN_QoS_Support_List(br));
    };
    encoders["E1AP_IEs::QoS_Characteristics"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Characteristics obj = j.get<asn1::generated::E1AP_IEs::QoS_Characteristics>();
        asn1::generated::E1AP_IEs::encode_QoS_Characteristics(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Characteristics"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Characteristics(br));
    };
    encoders["E1AP_IEs::QoS_Parameters_Support_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Parameters_Support_List obj = j.get<asn1::generated::E1AP_IEs::QoS_Parameters_Support_List>();
        asn1::generated::E1AP_IEs::encode_QoS_Parameters_Support_List(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Parameters_Support_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Parameters_Support_List(br));
    };
    encoders["E1AP_IEs::QoSFlowLevelQoSParameters"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoSFlowLevelQoSParameters obj = j.get<asn1::generated::E1AP_IEs::QoSFlowLevelQoSParameters>();
        asn1::generated::E1AP_IEs::encode_QoSFlowLevelQoSParameters(bw, obj);
    };
    decoders["E1AP_IEs::QoSFlowLevelQoSParameters"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoSFlowLevelQoSParameters(br));
    };
    encoders["E1AP_IEs::QoS_Flow_QoS_Parameter_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_Item obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_Item>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_QoS_Parameter_Item(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_QoS_Parameter_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_QoS_Parameter_Item(br));
    };
    encoders["E1AP_IEs::QoS_Flow_QoS_Parameter_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_List obj = j.get<asn1::generated::E1AP_IEs::QoS_Flow_QoS_Parameter_List>();
        asn1::generated::E1AP_IEs::encode_QoS_Flow_QoS_Parameter_List(bw, obj);
    };
    decoders["E1AP_IEs::QoS_Flow_QoS_Parameter_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_QoS_Flow_QoS_Parameter_List(br));
    };
    encoders["E1AP_IEs::RANUEID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::RANUEID obj = j.get<asn1::generated::E1AP_IEs::RANUEID>();
        asn1::generated::E1AP_IEs::encode_RANUEID(bw, obj);
    };
    decoders["E1AP_IEs::RANUEID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_RANUEID(br));
    };
    encoders["E1AP_IEs::RAT_Type"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::RAT_Type obj = j.get<asn1::generated::E1AP_IEs::RAT_Type>();
        asn1::generated::E1AP_IEs::encode_RAT_Type(bw, obj);
    };
    decoders["E1AP_IEs::RAT_Type"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_RAT_Type(br));
    };
    encoders["E1AP_IEs::Data_Usage_Report_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Usage_Report_Item obj = j.get<asn1::generated::E1AP_IEs::Data_Usage_Report_Item>();
        asn1::generated::E1AP_IEs::encode_Data_Usage_Report_Item(bw, obj);
    };
    decoders["E1AP_IEs::Data_Usage_Report_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Usage_Report_Item(br));
    };
    encoders["E1AP_IEs::Data_Usage_Report_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Usage_Report_List obj = j.get<asn1::generated::E1AP_IEs::Data_Usage_Report_List>();
        asn1::generated::E1AP_IEs::encode_Data_Usage_Report_List(bw, obj);
    };
    decoders["E1AP_IEs::Data_Usage_Report_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Usage_Report_List(br));
    };
    encoders["E1AP_IEs::RLC_Mode"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::RLC_Mode obj = j.get<asn1::generated::E1AP_IEs::RLC_Mode>();
        asn1::generated::E1AP_IEs::encode_RLC_Mode(bw, obj);
    };
    decoders["E1AP_IEs::RLC_Mode"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_RLC_Mode(br));
    };
    encoders["E1AP_IEs::ROHC"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ROHC obj = j.get<asn1::generated::E1AP_IEs::ROHC>();
        asn1::generated::E1AP_IEs::encode_ROHC(bw, obj);
    };
    decoders["E1AP_IEs::ROHC"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ROHC(br));
    };
    encoders["E1AP_IEs::SecurityAlgorithm"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SecurityAlgorithm obj = j.get<asn1::generated::E1AP_IEs::SecurityAlgorithm>();
        asn1::generated::E1AP_IEs::encode_SecurityAlgorithm(bw, obj);
    };
    decoders["E1AP_IEs::SecurityAlgorithm"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SecurityAlgorithm(br));
    };
    encoders["E1AP_IEs::SecurityIndication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SecurityIndication obj = j.get<asn1::generated::E1AP_IEs::SecurityIndication>();
        asn1::generated::E1AP_IEs::encode_SecurityIndication(bw, obj);
    };
    decoders["E1AP_IEs::SecurityIndication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SecurityIndication(br));
    };
    encoders["E1AP_IEs::SecurityResult"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SecurityResult obj = j.get<asn1::generated::E1AP_IEs::SecurityResult>();
        asn1::generated::E1AP_IEs::encode_SecurityResult(bw, obj);
    };
    decoders["E1AP_IEs::SecurityResult"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SecurityResult(br));
    };
    encoders["E1AP_IEs::SNSSAI"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SNSSAI obj = j.get<asn1::generated::E1AP_IEs::SNSSAI>();
        asn1::generated::E1AP_IEs::encode_SNSSAI(bw, obj);
    };
    decoders["E1AP_IEs::SNSSAI"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SNSSAI(br));
    };
    encoders["E1AP_IEs::Slice_Support_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Slice_Support_Item obj = j.get<asn1::generated::E1AP_IEs::Slice_Support_Item>();
        asn1::generated::E1AP_IEs::encode_Slice_Support_Item(bw, obj);
    };
    decoders["E1AP_IEs::Slice_Support_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Slice_Support_Item(br));
    };
    encoders["E1AP_IEs::Slice_Support_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Slice_Support_List obj = j.get<asn1::generated::E1AP_IEs::Slice_Support_List>();
        asn1::generated::E1AP_IEs::encode_Slice_Support_List(bw, obj);
    };
    decoders["E1AP_IEs::Slice_Support_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Slice_Support_List(br));
    };
    encoders["E1AP_IEs::SDAP_Header_DL"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SDAP_Header_DL obj = j.get<asn1::generated::E1AP_IEs::SDAP_Header_DL>();
        asn1::generated::E1AP_IEs::encode_SDAP_Header_DL(bw, obj);
    };
    decoders["E1AP_IEs::SDAP_Header_DL"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SDAP_Header_DL(br));
    };
    encoders["E1AP_IEs::SDAP_Header_UL"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SDAP_Header_UL obj = j.get<asn1::generated::E1AP_IEs::SDAP_Header_UL>();
        asn1::generated::E1AP_IEs::encode_SDAP_Header_UL(bw, obj);
    };
    decoders["E1AP_IEs::SDAP_Header_UL"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SDAP_Header_UL(br));
    };
    encoders["E1AP_IEs::SDAP_Configuration"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SDAP_Configuration obj = j.get<asn1::generated::E1AP_IEs::SDAP_Configuration>();
        asn1::generated::E1AP_IEs::encode_SDAP_Configuration(bw, obj);
    };
    decoders["E1AP_IEs::SDAP_Configuration"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SDAP_Configuration(br));
    };
    encoders["E1AP_IEs::TimeToWait"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::TimeToWait obj = j.get<asn1::generated::E1AP_IEs::TimeToWait>();
        asn1::generated::E1AP_IEs::encode_TimeToWait(bw, obj);
    };
    decoders["E1AP_IEs::TimeToWait"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_TimeToWait(br));
    };
    encoders["E1AP_IEs::TNLAssociationUsage"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::TNLAssociationUsage obj = j.get<asn1::generated::E1AP_IEs::TNLAssociationUsage>();
        asn1::generated::E1AP_IEs::encode_TNLAssociationUsage(bw, obj);
    };
    decoders["E1AP_IEs::TNLAssociationUsage"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_TNLAssociationUsage(br));
    };
    encoders["E1AP_IEs::TransportLayerAddress"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::TransportLayerAddress obj = j.get<asn1::generated::E1AP_IEs::TransportLayerAddress>();
        asn1::generated::E1AP_IEs::encode_TransportLayerAddress(bw, obj);
    };
    decoders["E1AP_IEs::TransportLayerAddress"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_TransportLayerAddress(br));
    };
    encoders["E1AP_IEs::CP_TNL_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CP_TNL_Information obj = j.get<asn1::generated::E1AP_IEs::CP_TNL_Information>();
        asn1::generated::E1AP_IEs::encode_CP_TNL_Information(bw, obj);
    };
    decoders["E1AP_IEs::CP_TNL_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CP_TNL_Information(br));
    };
    encoders["E1AP_IEs::Endpoint_IP_address_and_port"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Endpoint_IP_address_and_port obj = j.get<asn1::generated::E1AP_IEs::Endpoint_IP_address_and_port>();
        asn1::generated::E1AP_IEs::encode_Endpoint_IP_address_and_port(bw, obj);
    };
    decoders["E1AP_IEs::Endpoint_IP_address_and_port"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Endpoint_IP_address_and_port(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_TNLA_Setup_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_TNLA_Setup_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Add_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Add_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Remove_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Remove_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Update_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Update_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_TNLA_To_Remove_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_TNLA_To_Remove_Item(br));
    };
    encoders["E1AP_IEs::GTPTunnel"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GTPTunnel obj = j.get<asn1::generated::E1AP_IEs::GTPTunnel>();
        asn1::generated::E1AP_IEs::encode_GTPTunnel(bw, obj);
    };
    decoders["E1AP_IEs::GTPTunnel"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GTPTunnel(br));
    };
    encoders["E1AP_IEs::TransactionID"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::TransactionID obj = j.get<asn1::generated::E1AP_IEs::TransactionID>();
        asn1::generated::E1AP_IEs::encode_TransactionID(bw, obj);
    };
    decoders["E1AP_IEs::TransactionID"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_TransactionID(br));
    };
    encoders["E1AP_IEs::T_Reordering"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::T_Reordering obj = j.get<asn1::generated::E1AP_IEs::T_Reordering>();
        asn1::generated::E1AP_IEs::encode_T_Reordering(bw, obj);
    };
    decoders["E1AP_IEs::T_Reordering"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_T_Reordering(br));
    };
    encoders["E1AP_IEs::T_ReorderingTimer"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::T_ReorderingTimer obj = j.get<asn1::generated::E1AP_IEs::T_ReorderingTimer>();
        asn1::generated::E1AP_IEs::encode_T_ReorderingTimer(bw, obj);
    };
    decoders["E1AP_IEs::T_ReorderingTimer"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_T_ReorderingTimer(br));
    };
    encoders["E1AP_IEs::TypeOfError"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::TypeOfError obj = j.get<asn1::generated::E1AP_IEs::TypeOfError>();
        asn1::generated::E1AP_IEs::encode_TypeOfError(bw, obj);
    };
    decoders["E1AP_IEs::TypeOfError"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_TypeOfError(br));
    };
    encoders["E1AP_IEs::CriticalityDiagnostics_IE_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List obj = j.get<asn1::generated::E1AP_IEs::CriticalityDiagnostics_IE_List>();
        asn1::generated::E1AP_IEs::encode_CriticalityDiagnostics_IE_List(bw, obj);
    };
    decoders["E1AP_IEs::CriticalityDiagnostics_IE_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CriticalityDiagnostics_IE_List(br));
    };
    encoders["E1AP_IEs::CriticalityDiagnostics"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::CriticalityDiagnostics obj = j.get<asn1::generated::E1AP_IEs::CriticalityDiagnostics>();
        asn1::generated::E1AP_IEs::encode_CriticalityDiagnostics(bw, obj);
    };
    decoders["E1AP_IEs::CriticalityDiagnostics"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_CriticalityDiagnostics(br));
    };
    encoders["E1AP_IEs::UE_Activity"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UE_Activity obj = j.get<asn1::generated::E1AP_IEs::UE_Activity>();
        asn1::generated::E1AP_IEs::encode_UE_Activity(bw, obj);
    };
    decoders["E1AP_IEs::UE_Activity"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UE_Activity(br));
    };
    encoders["E1AP_IEs::ActivityInformation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ActivityInformation obj = j.get<asn1::generated::E1AP_IEs::ActivityInformation>();
        asn1::generated::E1AP_IEs::encode_ActivityInformation(bw, obj);
    };
    decoders["E1AP_IEs::ActivityInformation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ActivityInformation(br));
    };
    encoders["E1AP_IEs::UE_associatedLogicalE1_ConnectionItem"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UE_associatedLogicalE1_ConnectionItem obj = j.get<asn1::generated::E1AP_IEs::UE_associatedLogicalE1_ConnectionItem>();
        asn1::generated::E1AP_IEs::encode_UE_associatedLogicalE1_ConnectionItem(bw, obj);
    };
    decoders["E1AP_IEs::UE_associatedLogicalE1_ConnectionItem"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UE_associatedLogicalE1_ConnectionItem(br));
    };
    encoders["E1AP_IEs::UL_Configuration"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UL_Configuration obj = j.get<asn1::generated::E1AP_IEs::UL_Configuration>();
        asn1::generated::E1AP_IEs::encode_UL_Configuration(bw, obj);
    };
    decoders["E1AP_IEs::UL_Configuration"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UL_Configuration(br));
    };
    encoders["E1AP_IEs::Cell_Group_Information_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Cell_Group_Information_Item obj = j.get<asn1::generated::E1AP_IEs::Cell_Group_Information_Item>();
        asn1::generated::E1AP_IEs::encode_Cell_Group_Information_Item(bw, obj);
    };
    decoders["E1AP_IEs::Cell_Group_Information_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Cell_Group_Information_Item(br));
    };
    encoders["E1AP_IEs::Cell_Group_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Cell_Group_Information obj = j.get<asn1::generated::E1AP_IEs::Cell_Group_Information>();
        asn1::generated::E1AP_IEs::encode_Cell_Group_Information(bw, obj);
    };
    decoders["E1AP_IEs::Cell_Group_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Cell_Group_Information(br));
    };
    encoders["E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Confirm_Modified_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Confirm_Modified_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Confirm_Modified_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Confirm_Modified_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Confirm_Modified_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Confirm_Modified_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Confirm_Modified_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Confirm_Modified_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Confirm_Modified_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Confirm_Modified_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Confirm_Modified_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Confirm_Modified_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Confirm_Modified_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Confirm_Modified_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Confirm_Modified_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Confirm_Modified_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Confirm_Modified_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Confirm_Modified_List(br));
    };
    encoders["E1AP_IEs::ULDataSplitThreshold"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ULDataSplitThreshold obj = j.get<asn1::generated::E1AP_IEs::ULDataSplitThreshold>();
        asn1::generated::E1AP_IEs::encode_ULDataSplitThreshold(bw, obj);
    };
    decoders["E1AP_IEs::ULDataSplitThreshold"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ULDataSplitThreshold(br));
    };
    encoders["E1AP_IEs::UPSecuritykey"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UPSecuritykey obj = j.get<asn1::generated::E1AP_IEs::UPSecuritykey>();
        asn1::generated::E1AP_IEs::encode_UPSecuritykey(bw, obj);
    };
    decoders["E1AP_IEs::UPSecuritykey"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UPSecuritykey(br));
    };
    encoders["E1AP_IEs::SecurityInformation"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::SecurityInformation obj = j.get<asn1::generated::E1AP_IEs::SecurityInformation>();
        asn1::generated::E1AP_IEs::encode_SecurityInformation(bw, obj);
    };
    decoders["E1AP_IEs::SecurityInformation"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_SecurityInformation(br));
    };
    encoders["E1AP_IEs::UP_TNL_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UP_TNL_Information obj = j.get<asn1::generated::E1AP_IEs::UP_TNL_Information>();
        asn1::generated::E1AP_IEs::encode_UP_TNL_Information(bw, obj);
    };
    decoders["E1AP_IEs::UP_TNL_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UP_TNL_Information(br));
    };
    encoders["E1AP_IEs::Data_Forwarding_Information"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::Data_Forwarding_Information obj = j.get<asn1::generated::E1AP_IEs::Data_Forwarding_Information>();
        asn1::generated::E1AP_IEs::encode_Data_Forwarding_Information(bw, obj);
    };
    decoders["E1AP_IEs::Data_Forwarding_Information"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_Data_Forwarding_Information(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(br));
    };
    encoders["E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration obj = j.get<asn1::generated::E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration>();
        asn1::generated::E1AP_IEs::encode_GNB_CU_UP_CellGroupRelatedConfiguration(bw, obj);
    };
    decoders["E1AP_IEs::GNB_CU_UP_CellGroupRelatedConfiguration"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_GNB_CU_UP_CellGroupRelatedConfiguration(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Modify_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Modify_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Modify_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Modify_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Modify_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Modify_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Modify_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Modify_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Modify_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Required_To_Modify_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Required_To_Modify_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Required_To_Modify_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Required_To_Modify_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Required_To_Modify_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Required_To_Modify_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Required_To_Modify_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Required_To_Modify_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Required_To_Modify_List(br));
    };
    encoders["E1AP_IEs::UP_Parameters_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UP_Parameters_Item obj = j.get<asn1::generated::E1AP_IEs::UP_Parameters_Item>();
        asn1::generated::E1AP_IEs::encode_UP_Parameters_Item(bw, obj);
    };
    decoders["E1AP_IEs::UP_Parameters_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UP_Parameters_Item(br));
    };
    encoders["E1AP_IEs::UP_Parameters"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UP_Parameters obj = j.get<asn1::generated::E1AP_IEs::UP_Parameters>();
        asn1::generated::E1AP_IEs::encode_UP_Parameters(bw, obj);
    };
    decoders["E1AP_IEs::UP_Parameters"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UP_Parameters(br));
    };
    encoders["E1AP_IEs::DRB_Modified_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Modified_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Modified_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Modified_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Modified_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Modified_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Modified_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Modified_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Modified_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Modified_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Modified_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Modified_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Modified_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Modified_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Modified_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Modified_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Modified_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Modified_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Modified_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Modified_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Modified_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Modified_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Modified_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Modified_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Mod_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Mod_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Mod_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Mod_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Mod_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Mod_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Mod_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Mod_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Mod_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Mod_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_Setup_Mod_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_Setup_Mod_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_Setup_Mod_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_Setup_Mod_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_Setup_Mod_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Modified_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Modified_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Modified_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Modified_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Modified_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Modified_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Modified_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Modified_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Modified_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Setup_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Setup_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Setup_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Setup_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Setup_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Setup_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Setup_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Setup_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Setup_Mod_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Setup_Mod_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Setup_Mod_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_Setup_Mod_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_Setup_Mod_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_Setup_Mod_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_Setup_Mod_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_Setup_Mod_List(br));
    };
    encoders["E1AP_IEs::UplinkOnlyROHC"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::UplinkOnlyROHC obj = j.get<asn1::generated::E1AP_IEs::UplinkOnlyROHC>();
        asn1::generated::E1AP_IEs::encode_UplinkOnlyROHC(bw, obj);
    };
    decoders["E1AP_IEs::UplinkOnlyROHC"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_UplinkOnlyROHC(br));
    };
    encoders["E1AP_IEs::ROHC_Parameters"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::ROHC_Parameters obj = j.get<asn1::generated::E1AP_IEs::ROHC_Parameters>();
        asn1::generated::E1AP_IEs::encode_ROHC_Parameters(bw, obj);
    };
    decoders["E1AP_IEs::ROHC_Parameters"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_ROHC_Parameters(br));
    };
    encoders["E1AP_IEs::PDCP_Configuration"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDCP_Configuration obj = j.get<asn1::generated::E1AP_IEs::PDCP_Configuration>();
        asn1::generated::E1AP_IEs::encode_PDCP_Configuration(bw, obj);
    };
    decoders["E1AP_IEs::PDCP_Configuration"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDCP_Configuration(br));
    };
    encoders["E1AP_IEs::DRB_To_Modify_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Modify_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Modify_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Modify_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Modify_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Modify_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Modify_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Modify_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Modify_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Modify_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Modify_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Modify_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Modify_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Modify_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Modify_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Modify_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Modify_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Modify_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Modify_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Modify_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Modify_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Modify_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Modify_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Modify_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Mod_Item_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Mod_Item_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Mod_Item_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Mod_List_EUTRAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Mod_List_EUTRAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Mod_List_EUTRAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Mod_Item_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Mod_Item_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Mod_Item_NG_RAN(br));
    };
    encoders["E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN obj = j.get<asn1::generated::E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN>();
        asn1::generated::E1AP_IEs::encode_DRB_To_Setup_Mod_List_NG_RAN(bw, obj);
    };
    decoders["E1AP_IEs::DRB_To_Setup_Mod_List_NG_RAN"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_DRB_To_Setup_Mod_List_NG_RAN(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Modify_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Modify_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Modify_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Modify_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Modify_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Modify_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Modify_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Modify_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Modify_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Setup_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Setup_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Setup_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Setup_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Setup_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Setup_List(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Setup_Mod_Item(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Setup_Mod_Item(br));
    };
    encoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List obj = j.get<asn1::generated::E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List>();
        asn1::generated::E1AP_IEs::encode_PDU_Session_Resource_To_Setup_Mod_List(bw, obj);
    };
    decoders["E1AP_IEs::PDU_Session_Resource_To_Setup_Mod_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_IEs::decode_PDU_Session_Resource_To_Setup_Mod_List(br));
    };
    encoders["E1AP_PDU_Contents::Reset"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::Reset obj = j.get<asn1::generated::E1AP_PDU_Contents::Reset>();
        asn1::generated::E1AP_PDU_Contents::encode_Reset(bw, obj);
    };
    decoders["E1AP_PDU_Contents::Reset"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_Reset(br));
    };
    encoders["E1AP_PDU_Contents::ResetAll"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::ResetAll obj = j.get<asn1::generated::E1AP_PDU_Contents::ResetAll>();
        asn1::generated::E1AP_PDU_Contents::encode_ResetAll(bw, obj);
    };
    decoders["E1AP_PDU_Contents::ResetAll"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_ResetAll(br));
    };
    encoders["E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes obj = j.get<asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes>();
        asn1::generated::E1AP_PDU_Contents::encode_UE_associatedLogicalE1_ConnectionListRes(bw, obj);
    };
    decoders["E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListRes"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_UE_associatedLogicalE1_ConnectionListRes(br));
    };
    encoders["E1AP_PDU_Contents::ResetType"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::ResetType obj = j.get<asn1::generated::E1AP_PDU_Contents::ResetType>();
        asn1::generated::E1AP_PDU_Contents::encode_ResetType(bw, obj);
    };
    decoders["E1AP_PDU_Contents::ResetType"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_ResetType(br));
    };
    encoders["E1AP_PDU_Contents::ResetAcknowledge"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::ResetAcknowledge obj = j.get<asn1::generated::E1AP_PDU_Contents::ResetAcknowledge>();
        asn1::generated::E1AP_PDU_Contents::encode_ResetAcknowledge(bw, obj);
    };
    decoders["E1AP_PDU_Contents::ResetAcknowledge"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_ResetAcknowledge(br));
    };
    encoders["E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck obj = j.get<asn1::generated::E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck>();
        asn1::generated::E1AP_PDU_Contents::encode_UE_associatedLogicalE1_ConnectionListResAck(bw, obj);
    };
    decoders["E1AP_PDU_Contents::UE_associatedLogicalE1_ConnectionListResAck"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_UE_associatedLogicalE1_ConnectionListResAck(br));
    };
    encoders["E1AP_PDU_Contents::ErrorIndication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::ErrorIndication obj = j.get<asn1::generated::E1AP_PDU_Contents::ErrorIndication>();
        asn1::generated::E1AP_PDU_Contents::encode_ErrorIndication(bw, obj);
    };
    decoders["E1AP_PDU_Contents::ErrorIndication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_ErrorIndication(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_E1SetupRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_E1SetupRequest(br));
    };
    encoders["E1AP_PDU_Contents::SupportedPLMNs_Item"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_Item obj = j.get<asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_Item>();
        asn1::generated::E1AP_PDU_Contents::encode_SupportedPLMNs_Item(bw, obj);
    };
    decoders["E1AP_PDU_Contents::SupportedPLMNs_Item"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_SupportedPLMNs_Item(br));
    };
    encoders["E1AP_PDU_Contents::SupportedPLMNs_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_List obj = j.get<asn1::generated::E1AP_PDU_Contents::SupportedPLMNs_List>();
        asn1::generated::E1AP_PDU_Contents::encode_SupportedPLMNs_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::SupportedPLMNs_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_SupportedPLMNs_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_E1SetupResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_E1SetupResponse(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_E1SetupFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_E1SetupFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_E1SetupFailure(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_E1SetupRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_E1SetupRequest(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_E1SetupResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_E1SetupResponse(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_E1SetupFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_E1SetupFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_E1SetupFailure(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_ConfigurationUpdate(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_ConfigurationUpdate(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_TNLA_To_Remove_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_TNLA_To_Remove_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_TNLA_To_Remove_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_ConfigurationUpdateAcknowledge(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateAcknowledge"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_ConfigurationUpdateAcknowledge(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_ConfigurationUpdateFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_ConfigurationUpdateFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_ConfigurationUpdateFailure(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_ConfigurationUpdate(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdate"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_ConfigurationUpdate(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_TNLA_To_Add_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Add_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_TNLA_To_Add_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_TNLA_To_Remove_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Remove_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_TNLA_To_Remove_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_TNLA_To_Update_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_To_Update_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_TNLA_To_Update_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_ConfigurationUpdateAcknowledge(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateAcknowledge"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_ConfigurationUpdateAcknowledge(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_TNLA_Setup_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_Setup_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_TNLA_Setup_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_TNLA_Failed_To_Setup_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_TNLA_Failed_To_Setup_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_TNLA_Failed_To_Setup_List(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_CP_ConfigurationUpdateFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_CP_ConfigurationUpdateFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_CP_ConfigurationUpdateFailure(br));
    };
    encoders["E1AP_PDU_Contents::E1ReleaseRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::E1ReleaseRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::E1ReleaseRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_E1ReleaseRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::E1ReleaseRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_E1ReleaseRequest(br));
    };
    encoders["E1AP_PDU_Contents::E1ReleaseResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::E1ReleaseResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::E1ReleaseResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_E1ReleaseResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::E1ReleaseResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_E1ReleaseResponse(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextSetupRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextSetupRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextSetupRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextSetupRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextSetupRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextSetupRequest(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextSetupRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextSetupRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextSetupRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextSetupRequest(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextSetupResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextSetupResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextSetupResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextSetupResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextSetupResponse(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextSetupResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextSetupResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextSetupResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextSetupResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextSetupResponse(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextSetupFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextSetupFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextSetupFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextSetupFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextSetupFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextSetupFailure(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextModificationRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextModificationRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextModificationRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextModificationRequest(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextModificationRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextModificationRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextModificationRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextModificationRequest(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextModificationResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextModificationResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextModificationResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextModificationResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextModificationResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextModificationResponse(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextModificationResponse"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationResponse>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextModificationResponse(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextModificationResponse"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextModificationResponse(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextModificationFailure"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextModificationFailure obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextModificationFailure>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextModificationFailure(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextModificationFailure"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextModificationFailure(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextModificationRequired"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequired obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextModificationRequired>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextModificationRequired(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextModificationRequired"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextModificationRequired(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextModificationRequired"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationRequired>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextModificationRequired(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextModificationRequired"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextModificationRequired(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextModificationConfirm"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextModificationConfirm obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextModificationConfirm>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextModificationConfirm(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextModificationConfirm"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextModificationConfirm(br));
    };
    encoders["E1AP_PDU_Contents::System_BearerContextModificationConfirm"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm obj = j.get<asn1::generated::E1AP_PDU_Contents::System_BearerContextModificationConfirm>();
        asn1::generated::E1AP_PDU_Contents::encode_System_BearerContextModificationConfirm(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_BearerContextModificationConfirm"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_BearerContextModificationConfirm(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextReleaseCommand"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextReleaseCommand obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseCommand>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextReleaseCommand(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextReleaseCommand"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextReleaseCommand(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextReleaseComplete"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextReleaseComplete obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseComplete>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextReleaseComplete(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextReleaseComplete"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextReleaseComplete(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextReleaseRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextReleaseRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextReleaseRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextReleaseRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextReleaseRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextReleaseRequest(br));
    };
    encoders["E1AP_PDU_Contents::DRB_Status_List"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::DRB_Status_List obj = j.get<asn1::generated::E1AP_PDU_Contents::DRB_Status_List>();
        asn1::generated::E1AP_PDU_Contents::encode_DRB_Status_List(bw, obj);
    };
    decoders["E1AP_PDU_Contents::DRB_Status_List"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_DRB_Status_List(br));
    };
    encoders["E1AP_PDU_Contents::BearerContextInactivityNotification"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::BearerContextInactivityNotification obj = j.get<asn1::generated::E1AP_PDU_Contents::BearerContextInactivityNotification>();
        asn1::generated::E1AP_PDU_Contents::encode_BearerContextInactivityNotification(bw, obj);
    };
    decoders["E1AP_PDU_Contents::BearerContextInactivityNotification"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_BearerContextInactivityNotification(br));
    };
    encoders["E1AP_PDU_Contents::DLDataNotification"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::DLDataNotification obj = j.get<asn1::generated::E1AP_PDU_Contents::DLDataNotification>();
        asn1::generated::E1AP_PDU_Contents::encode_DLDataNotification(bw, obj);
    };
    decoders["E1AP_PDU_Contents::DLDataNotification"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_DLDataNotification(br));
    };
    encoders["E1AP_PDU_Contents::ULDataNotification"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::ULDataNotification obj = j.get<asn1::generated::E1AP_PDU_Contents::ULDataNotification>();
        asn1::generated::E1AP_PDU_Contents::encode_ULDataNotification(bw, obj);
    };
    decoders["E1AP_PDU_Contents::ULDataNotification"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_ULDataNotification(br));
    };
    encoders["E1AP_PDU_Contents::DataUsageReport"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::DataUsageReport obj = j.get<asn1::generated::E1AP_PDU_Contents::DataUsageReport>();
        asn1::generated::E1AP_PDU_Contents::encode_DataUsageReport(bw, obj);
    };
    decoders["E1AP_PDU_Contents::DataUsageReport"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_DataUsageReport(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_CounterCheckRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_CounterCheckRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_CounterCheckRequest(br));
    };
    encoders["E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest obj = j.get<asn1::generated::E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest>();
        asn1::generated::E1AP_PDU_Contents::encode_System_GNB_CU_UP_CounterCheckRequest(bw, obj);
    };
    decoders["E1AP_PDU_Contents::System_GNB_CU_UP_CounterCheckRequest"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_System_GNB_CU_UP_CounterCheckRequest(br));
    };
    encoders["E1AP_PDU_Contents::GNB_CU_UP_StatusIndication"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_StatusIndication obj = j.get<asn1::generated::E1AP_PDU_Contents::GNB_CU_UP_StatusIndication>();
        asn1::generated::E1AP_PDU_Contents::encode_GNB_CU_UP_StatusIndication(bw, obj);
    };
    decoders["E1AP_PDU_Contents::GNB_CU_UP_StatusIndication"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_GNB_CU_UP_StatusIndication(br));
    };
    encoders["E1AP_PDU_Contents::MRDC_DataUsageReport"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::MRDC_DataUsageReport obj = j.get<asn1::generated::E1AP_PDU_Contents::MRDC_DataUsageReport>();
        asn1::generated::E1AP_PDU_Contents::encode_MRDC_DataUsageReport(bw, obj);
    };
    decoders["E1AP_PDU_Contents::MRDC_DataUsageReport"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_MRDC_DataUsageReport(br));
    };
    encoders["E1AP_PDU_Contents::PrivateMessage"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Contents::PrivateMessage obj = j.get<asn1::generated::E1AP_PDU_Contents::PrivateMessage>();
        asn1::generated::E1AP_PDU_Contents::encode_PrivateMessage(bw, obj);
    };
    decoders["E1AP_PDU_Contents::PrivateMessage"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Contents::decode_PrivateMessage(br));
    };
    encoders["E1AP_PDU_Descriptions::InitiatingMessage"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Descriptions::InitiatingMessage obj = j.get<asn1::generated::E1AP_PDU_Descriptions::InitiatingMessage>();
        asn1::generated::E1AP_PDU_Descriptions::encode_InitiatingMessage(bw, obj);
    };
    decoders["E1AP_PDU_Descriptions::InitiatingMessage"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Descriptions::decode_InitiatingMessage(br));
    };
    encoders["E1AP_PDU_Descriptions::SuccessfulOutcome"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Descriptions::SuccessfulOutcome obj = j.get<asn1::generated::E1AP_PDU_Descriptions::SuccessfulOutcome>();
        asn1::generated::E1AP_PDU_Descriptions::encode_SuccessfulOutcome(bw, obj);
    };
    decoders["E1AP_PDU_Descriptions::SuccessfulOutcome"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Descriptions::decode_SuccessfulOutcome(br));
    };
    encoders["E1AP_PDU_Descriptions::UnsuccessfulOutcome"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Descriptions::UnsuccessfulOutcome obj = j.get<asn1::generated::E1AP_PDU_Descriptions::UnsuccessfulOutcome>();
        asn1::generated::E1AP_PDU_Descriptions::encode_UnsuccessfulOutcome(bw, obj);
    };
    decoders["E1AP_PDU_Descriptions::UnsuccessfulOutcome"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Descriptions::decode_UnsuccessfulOutcome(br));
    };
    encoders["E1AP_PDU_Descriptions::E1AP_PDU"] = [](const nlohmann::json& j, asn1::runtime::BitWriter& bw) {
        asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU obj = j.get<asn1::generated::E1AP_PDU_Descriptions::E1AP_PDU>();
        asn1::generated::E1AP_PDU_Descriptions::encode_E1AP_PDU(bw, obj);
    };
    decoders["E1AP_PDU_Descriptions::E1AP_PDU"] = [](asn1::runtime::BitReader& br) -> nlohmann::json {
        return nlohmann::json(asn1::generated::E1AP_PDU_Descriptions::decode_E1AP_PDU(br));
    };
}

