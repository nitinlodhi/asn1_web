#ifndef ASN1_GENERATED_GENERATED_H
#define ASN1_GENERATED_GENERATED_H

#include <cstdint>
#include <vector>
#include <optional>
#include <variant>
#include <string>
#include <any>
#include <cstddef>

#include "runtime/core/BitString.h"
#include "runtime/core/ExtensionValue.h"
#include "runtime/core/ObjectIdentifier.h"
#include "runtime/core/BitWriter.h"
#include "runtime/core/BitReader.h"

namespace asn1::generated {

namespace E1AP_CommonDataTypes {

enum class Criticality {
    reject,
    ignore,
    notify,
};

enum class Presence {
    optional,
    conditional,
    mandatory,
};

struct PrivateIE_ID_local {
    int64_t local;
};
struct PrivateIE_ID_global {
    asn1::runtime::ObjectIdentifier global;
};
using PrivateIE_ID = std::variant<
    PrivateIE_ID_local,
    PrivateIE_ID_global
>;

using ProcedureCode = int64_t;

using ProtocolExtensionID = int64_t;

using ProtocolIE_ID = int64_t;

enum class TriggeringMessage {
    initiating_message,
    successful_outcome,
    unsuccessful_outcome,
};

constexpr int64_t maxPrivateIEs = 65535;

constexpr int64_t maxProtocolExtensions = 65535;

constexpr int64_t maxProtocolIEs = 65535;

void encode_Criticality(asn1::runtime::BitWriter& writer, const Criticality& value);
Criticality decode_Criticality(asn1::runtime::BitReader& reader);
void encode_Presence(asn1::runtime::BitWriter& writer, const Presence& value);
Presence decode_Presence(asn1::runtime::BitReader& reader);
void encode_PrivateIE_ID(asn1::runtime::BitWriter& writer, const PrivateIE_ID& value);
PrivateIE_ID decode_PrivateIE_ID(asn1::runtime::BitReader& reader);
void encode_ProcedureCode(asn1::runtime::BitWriter& writer, const ProcedureCode& value);
ProcedureCode decode_ProcedureCode(asn1::runtime::BitReader& reader);
void encode_ProtocolExtensionID(asn1::runtime::BitWriter& writer, const ProtocolExtensionID& value);
ProtocolExtensionID decode_ProtocolExtensionID(asn1::runtime::BitReader& reader);
void encode_ProtocolIE_ID(asn1::runtime::BitWriter& writer, const ProtocolIE_ID& value);
ProtocolIE_ID decode_ProtocolIE_ID(asn1::runtime::BitReader& reader);
void encode_TriggeringMessage(asn1::runtime::BitWriter& writer, const TriggeringMessage& value);
TriggeringMessage decode_TriggeringMessage(asn1::runtime::BitReader& reader);

} // namespace E1AP_CommonDataTypes

namespace E1AP_Constants {

// Value assignment for id_reset of type ProcedureCode not implemented
// Value assignment for id_errorIndication of type ProcedureCode not implemented
// Value assignment for id_privateMessage of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_UP_E1Setup of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_CP_E1Setup of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_UP_ConfigurationUpdate of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_CP_ConfigurationUpdate of type ProcedureCode not implemented
// Value assignment for id_e1Release of type ProcedureCode not implemented
// Value assignment for id_bearerContextSetup of type ProcedureCode not implemented
// Value assignment for id_bearerContextModification of type ProcedureCode not implemented
// Value assignment for id_bearerContextModificationRequired of type ProcedureCode not implemented
// Value assignment for id_bearerContextRelease of type ProcedureCode not implemented
// Value assignment for id_bearerContextReleaseRequest of type ProcedureCode not implemented
// Value assignment for id_bearerContextInactivityNotification of type ProcedureCode not implemented
// Value assignment for id_dLDataNotification of type ProcedureCode not implemented
// Value assignment for id_dataUsageReport of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_UP_CounterCheck of type ProcedureCode not implemented
// Value assignment for id_gNB_CU_UP_StatusIndication of type ProcedureCode not implemented
// Value assignment for id_uLDataNotification of type ProcedureCode not implemented
// Value assignment for id_mRDC_DataUsageReport of type ProcedureCode not implemented
constexpr int64_t maxnoofErrors = 256;

constexpr int64_t maxnoofSPLMNs = 12;

constexpr int64_t maxnoofSliceItems = 1024;

constexpr int64_t maxnoofIndividualE1ConnectionsToReset = 65536;

constexpr int64_t maxnoofEUTRANQOSParameters = 256;

constexpr int64_t maxnoofNGRANQOSParameters = 256;

constexpr int64_t maxnoofDRBs = 32;

constexpr int64_t maxnoofNRCGI = 512;

constexpr int64_t maxnoofPDUSessionResource = 256;

constexpr int64_t maxnoofQoSFlows = 64;

constexpr int64_t maxnoofUPParameters = 8;

constexpr int64_t maxnoofCellGroups = 4;

constexpr int64_t maxnooftimeperiods = 2;

constexpr int64_t maxnoofTNLAssociations = 32;

// Value assignment for id_Cause of type ProtocolIE-ID not implemented
// Value assignment for id_CriticalityDiagnostics of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_CP_UE_E1AP_ID of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_UP_UE_E1AP_ID of type ProtocolIE-ID not implemented
// Value assignment for id_ResetType of type ProtocolIE-ID not implemented
// Value assignment for id_UE_associatedLogicalE1_ConnectionItem of type ProtocolIE-ID not implemented
// Value assignment for id_UE_associatedLogicalE1_ConnectionListResAck of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_UP_ID of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_UP_Name of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_CP_Name of type ProtocolIE-ID not implemented
// Value assignment for id_CNSupport of type ProtocolIE-ID not implemented
// Value assignment for id_SupportedPLMNs of type ProtocolIE-ID not implemented
// Value assignment for id_TimeToWait of type ProtocolIE-ID not implemented
// Value assignment for id_SecurityInformation of type ProtocolIE-ID not implemented
// Value assignment for id_UEDLAggregateMaximumBitRate of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextSetupRequest of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextSetupResponse of type ProtocolIE-ID not implemented
// Value assignment for id_BearerContextStatusChange of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextModificationRequest of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextModificationResponse of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextModificationConfirm of type ProtocolIE-ID not implemented
// Value assignment for id_System_BearerContextModificationRequired of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Status_List of type ProtocolIE-ID not implemented
// Value assignment for id_ActivityNotificationLevel of type ProtocolIE-ID not implemented
// Value assignment for id_ActivityInformation of type ProtocolIE-ID not implemented
// Value assignment for id_Data_Usage_Report_List of type ProtocolIE-ID not implemented
// Value assignment for id_New_UL_TNL_Information_Required of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_CP_TNLA_To_Add_List of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_CP_TNLA_To_Remove_List of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_CP_TNLA_To_Update_List of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_CP_TNLA_Setup_List of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_CP_TNLA_Failed_To_Setup_List of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_To_Setup_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_To_Modify_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_To_Remove_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Required_To_Modify_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Required_To_Remove_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Setup_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Failed_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Modified_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Failed_To_Modify_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Confirm_Modified_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_To_Setup_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_To_Modify_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_To_Remove_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Required_To_Modify_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Setup_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Failed_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Modified_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Failed_To_Modify_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Confirm_Modified_List of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_To_Setup_Mod_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Setup_Mod_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_Failed_Mod_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Setup_Mod_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Failed_Mod_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_To_Setup_Mod_List of type ProtocolIE-ID not implemented
// Value assignment for id_TransactionID of type ProtocolIE-ID not implemented
// Value assignment for id_Serving_PLMN of type ProtocolIE-ID not implemented
// Value assignment for id_UE_Inactivity_Timer of type ProtocolIE-ID not implemented
// Value assignment for id_System_GNB_CU_UP_CounterCheckRequest of type ProtocolIE-ID not implemented
// Value assignment for id_DRBs_Subject_To_Counter_Check_List_EUTRAN of type ProtocolIE-ID not implemented
// Value assignment for id_DRBs_Subject_To_Counter_Check_List_NG_RAN of type ProtocolIE-ID not implemented
// Value assignment for id_PPI of type ProtocolIE-ID not implemented
// Value assignment for id_gNB_CU_UP_Capacity of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_UP_OverloadInformation of type ProtocolIE-ID not implemented
// Value assignment for id_UEDLMaximumIntegrityProtectedDataRate of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_To_Notify_List of type ProtocolIE-ID not implemented
// Value assignment for id_PDU_Session_Resource_Data_Usage_List of type ProtocolIE-ID not implemented
// Value assignment for id_SNSSAI of type ProtocolIE-ID not implemented
// Value assignment for id_DataDiscardRequired of type ProtocolIE-ID not implemented
// Value assignment for id_OldQoSFlowMap_ULendmarkerexpected of type ProtocolIE-ID not implemented
// Value assignment for id_DRB_QoS of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_CU_UP_TNLA_To_Remove_List of type ProtocolIE-ID not implemented
// Value assignment for id_endpoint_IP_Address_and_Port of type ProtocolIE-ID not implemented
// Value assignment for id_TNLAssociationTransportLayerAddressgNBCUUP of type ProtocolIE-ID not implemented
// Value assignment for id_RANUEID of type ProtocolIE-ID not implemented
// Value assignment for id_GNB_DU_ID of type ProtocolIE-ID not implemented
// Value assignment for id_CommonNetworkInstance of type ProtocolIE-ID not implemented
// Value assignment for id_NetworkInstance of type ProtocolIE-ID not implemented
// Value assignment for id_QoSFlowMappingIndication of type ProtocolIE-ID not implemented

} // namespace E1AP_Constants

namespace E1AP_Containers {

struct ProtocolIE_Field {
    E1AP_CommonDataTypes::ProtocolIE_ID id;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any value;
};

using ProtocolIE_Container = std::vector<ProtocolIE_Field>;

using ProtocolIE_SingleContainer = ProtocolIE_Field;

using ProtocolIE_ContainerList = std::vector<ProtocolIE_Container>;

struct ProtocolExtensionField {
    E1AP_CommonDataTypes::ProtocolIE_ID id;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any extensionValue;
};

using ProtocolExtensionContainer = std::vector<ProtocolExtensionField>;

struct PrivateIE_Field {
    E1AP_CommonDataTypes::PrivateIE_ID id;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any value;
};

using PrivateIE_Container = std::vector<PrivateIE_Field>;

void encode_ProtocolIE_Field(asn1::runtime::BitWriter& writer, const ProtocolIE_Field& value);
ProtocolIE_Field decode_ProtocolIE_Field(asn1::runtime::BitReader& reader);
void encode_ProtocolIE_Container(asn1::runtime::BitWriter& writer, const ProtocolIE_Container& value);
ProtocolIE_Container decode_ProtocolIE_Container(asn1::runtime::BitReader& reader);
void encode_ProtocolIE_SingleContainer(asn1::runtime::BitWriter& writer, const ProtocolIE_SingleContainer& value);
ProtocolIE_SingleContainer decode_ProtocolIE_SingleContainer(asn1::runtime::BitReader& reader);
void encode_ProtocolIE_ContainerList(asn1::runtime::BitWriter& writer, const ProtocolIE_ContainerList& value);
ProtocolIE_ContainerList decode_ProtocolIE_ContainerList(asn1::runtime::BitReader& reader);
void encode_ProtocolExtensionField(asn1::runtime::BitWriter& writer, const ProtocolExtensionField& value);
ProtocolExtensionField decode_ProtocolExtensionField(asn1::runtime::BitReader& reader);
void encode_ProtocolExtensionContainer(asn1::runtime::BitWriter& writer, const ProtocolExtensionContainer& value);
ProtocolExtensionContainer decode_ProtocolExtensionContainer(asn1::runtime::BitReader& reader);
void encode_PrivateIE_Field(asn1::runtime::BitWriter& writer, const PrivateIE_Field& value);
PrivateIE_Field decode_PrivateIE_Field(asn1::runtime::BitReader& reader);
void encode_PrivateIE_Container(asn1::runtime::BitWriter& writer, const PrivateIE_Container& value);
PrivateIE_Container decode_PrivateIE_Container(asn1::runtime::BitReader& reader);

} // namespace E1AP_Containers

namespace E1AP_IEs {

enum class ActivityNotificationLevel {
    drb,
    pdu_session,
    ue,
    //... extension marker
};

using AveragingWindow = int64_t;

enum class BearerContextStatusChange {
    suspend,
    resume,
    //... extension marker
};

using BitRate = int64_t;

enum class CauseMisc {
    control_processing_overload,
    not_enough_user_plane_processing_resources,
    hardware_failure,
    om_intervention,
    unspecified,
    //... extension marker
};

enum class CauseProtocol {
    transfer_syntax_error,
    abstract_syntax_error_reject,
    abstract_syntax_error_ignore_and_notify,
    message_not_compatible_with_receiver_state,
    semantic_error,
    abstract_syntax_error_falsely_constructed_message,
    unspecified,
    //... extension marker
};

enum class CauseRadioNetwork {
    unspecified,
    unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id,
    unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id,
    unknown_or_inconsistent_pair_of_ue_e1ap_id,
    interaction_with_other_procedure,
    pPDCP_Count_wrap_around,
    not_supported_QCI_value,
    not_supported_5QI_value,
    encryption_algorithms_not_supported,
    integrity_protection_algorithms_not_supported,
    uP_integrity_protection_not_possible,
    uP_confidentiality_protection_not_possible,
    multiple_PDU_Session_ID_Instances,
    unknown_PDU_Session_ID,
    multiple_QoS_Flow_ID_Instances,
    unknown_QoS_Flow_ID,
    multiple_DRB_ID_Instances,
    unknown_DRB_ID,
    invalid_QoS_combination,
    procedure_cancelled,
    normal_release,
    no_radio_resources_available,
    action_desirable_for_radio_reasons,
    resources_not_available_for_the_slice,
    pDCP_configuration_not_supported,
    //... extension marker
    ue_dl_max_IP_data_rate_reason,
    uP_integrity_protection_failure,
    release_due_to_pre_emption,
};

enum class CauseTransport {
    unspecified,
    transport_resource_unavailable,
    //... extension marker
};

struct Cause_radioNetwork {
    CauseRadioNetwork radioNetwork;
};
struct Cause_transport {
    CauseTransport transport;
};
struct Cause_protocol {
    CauseProtocol protocol;
};
struct Cause_misc {
    CauseMisc misc;
};
struct Cause_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using Cause = std::variant<
    Cause_radioNetwork,
    Cause_transport,
    Cause_protocol,
    Cause_misc,
    Cause_choice_extension
>;

using Cell_Group_ID = int64_t;

enum class CipheringAlgorithm {
    nEA0,
    c_128_NEA1,
    c_128_NEA2,
    c_128_NEA3,
    //... extension marker
};

enum class CNSupport {
    c_epc,
    c_5gc,
    both,
    //... extension marker
};

using CommonNetworkInstance = std::vector<uint8_t>;

enum class ConfidentialityProtectionIndication {
    required,
    preferred,
    not_needed,
    //... extension marker
};

enum class ConfidentialityProtectionResult {
    performed,
    not_performed,
    //... extension marker
};

enum class Data_Forwarding_Request {
    uL,
    dL,
    both,
    //... extension marker
};

enum class DefaultDRB {
    true_,
    false_,
    //... extension marker
};

enum class DiscardTimer {
    ms10,
    ms20,
    ms30,
    ms40,
    ms50,
    ms60,
    ms75,
    ms100,
    ms150,
    ms200,
    ms250,
    ms300,
    ms500,
    ms750,
    ms1500,
    infinity,
};

enum class DL_TX_Stop {
    stop,
    resume,
    //... extension marker
};

enum class DRB_Activity {
    active,
    not_active,
    //... extension marker
};

using DRB_ID = int64_t;

struct DRB_Activity_Item {
    DRB_ID dRB_ID;
    DRB_Activity dRB_Activity;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Activity_List = std::vector<DRB_Activity_Item>;

struct DRB_Failed_Item_EUTRAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_List_EUTRAN = std::vector<DRB_Failed_Item_EUTRAN>;

struct DRB_Failed_Mod_Item_EUTRAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_Mod_List_EUTRAN = std::vector<DRB_Failed_Mod_Item_EUTRAN>;

struct DRB_Failed_Item_NG_RAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_List_NG_RAN = std::vector<DRB_Failed_Item_NG_RAN>;

struct DRB_Failed_Mod_Item_NG_RAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_Mod_List_NG_RAN = std::vector<DRB_Failed_Mod_Item_NG_RAN>;

struct DRB_Failed_To_Modify_Item_EUTRAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_To_Modify_List_EUTRAN = std::vector<DRB_Failed_To_Modify_Item_EUTRAN>;

struct DRB_Failed_To_Modify_Item_NG_RAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Failed_To_Modify_List_NG_RAN = std::vector<DRB_Failed_To_Modify_Item_NG_RAN>;

struct DRB_To_Remove_Item_EUTRAN {
    DRB_ID dRB_ID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Remove_List_EUTRAN = std::vector<DRB_To_Remove_Item_EUTRAN>;

struct DRB_Required_To_Remove_Item_EUTRAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Required_To_Remove_List_EUTRAN = std::vector<DRB_Required_To_Remove_Item_EUTRAN>;

struct DRB_To_Remove_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Remove_List_NG_RAN = std::vector<DRB_To_Remove_Item_NG_RAN>;

struct DRB_Required_To_Remove_Item_NG_RAN {
    DRB_ID dRB_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Required_To_Remove_List_NG_RAN = std::vector<DRB_Required_To_Remove_Item_NG_RAN>;

struct DRB_Usage_Report_Item {
    std::vector<uint8_t> startTimeStamp;
    std::vector<uint8_t> endTimeStamp;
    int64_t usageCountUL;
    int64_t usageCountDL;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Usage_Report_List = std::vector<DRB_Usage_Report_Item>;

enum class Duplication_Activation {
    active,
    inactive,
    //... extension marker
};

enum class DataDiscardRequired {
    required,
    //... extension marker
};

using EncryptionKey = std::vector<uint8_t>;

using GNB_CU_CP_Name = std::string;

using GNB_CU_CP_UE_E1AP_ID = int64_t;

using GNB_CU_UP_Capacity = int64_t;

using GNB_CU_UP_ID = int64_t;

using GNB_CU_UP_Name = std::string;

using GNB_CU_UP_UE_E1AP_ID = int64_t;

struct GBR_QosInformation {
    BitRate e_RAB_MaximumBitrateDL;
    BitRate e_RAB_MaximumBitrateUL;
    BitRate e_RAB_GuaranteedBitrateDL;
    BitRate e_RAB_GuaranteedBitrateUL;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using GTP_TEID = std::vector<uint8_t>;

enum class GNB_CU_UP_OverloadInformation {
    overloaded,
    not_overloaded,
};

using GNB_DU_ID = int64_t;

using HFN = int64_t;

enum class IntegrityProtectionIndication {
    required,
    preferred,
    not_needed,
    //... extension marker
};

enum class IntegrityProtectionAlgorithm {
    nIA0,
    i_128_NIA1,
    i_128_NIA2,
    i_128_NIA3,
    //... extension marker
};

using IntegrityProtectionKey = std::vector<uint8_t>;

enum class IntegrityProtectionResult {
    performed,
    not_performed,
    //... extension marker
};

using Inactivity_Timer = int64_t;

using MaxDataBurstVolume = int64_t;

enum class MaxIPrate {
    bitrate64kbs,
    max_UErate,
    //... extension marker
};

struct MaximumIPdatarate {
    MaxIPrate maxIPrate;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using MaxPacketLossRate = int64_t;

struct GBR_QoSFlowInformation {
    BitRate maxFlowBitRateDownlink;
    BitRate maxFlowBitRateUplink;
    BitRate guaranteedFlowBitRateDownlink;
    BitRate guaranteedFlowBitRateUplink;
    std::optional<MaxPacketLossRate> maxPacketLossRateDownlink;
    std::optional<MaxPacketLossRate> maxPacketLossRateUplink;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct MRDC_Data_Usage_Report_Item {
    std::vector<uint8_t> startTimeStamp;
    std::vector<uint8_t> endTimeStamp;
    int64_t usageCountUL;
    int64_t usageCountDL;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct Data_Usage_per_PDU_Session_Report {
    enum class secondaryRATType_type {
        nR,
        e_UTRA,
        //... extension marker
    };
    secondaryRATType_type secondaryRATType;
    std::vector<MRDC_Data_Usage_Report_Item> pDU_session_Timed_Report_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using NetworkInstance = int64_t;

enum class New_UL_TNL_Information_Required {
    required,
    //... extension marker
};

using NR_Cell_Identity = asn1::runtime::BitString;

enum class OutOfOrderDelivery {
    true_,
    //... extension marker
};

using PacketDelayBudget = int64_t;

using PER_Scalar = int64_t;

using PER_Exponent = int64_t;

struct PacketErrorRate {
    PER_Scalar pER_Scalar;
    PER_Exponent pER_Exponent;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class PDCP_SN_Status_Request {
    requested,
    //... extension marker
};

enum class PDCP_DataRecovery {
    true_,
    //... extension marker
};

enum class PDCP_Duplication {
    true_,
    //... extension marker
};

enum class PDCP_Reestablishment {
    true_,
    //... extension marker
};

using PDCP_SN = int64_t;

struct PDCP_Count {
    PDCP_SN pDCP_SN;
    HFN hFN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct DRB_Status_Item {
    DRB_ID dRB_ID;
    std::optional<PDCP_Count> pDCP_DL_Count;
    std::optional<PDCP_Count> pDCP_UL_Count;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct DRBs_Subject_To_Counter_Check_Item_EUTRAN {
    DRB_ID dRB_ID;
    PDCP_Count pDCP_UL_Count;
    PDCP_Count pDCP_DL_Count;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRBs_Subject_To_Counter_Check_List_EUTRAN = std::vector<DRBs_Subject_To_Counter_Check_Item_EUTRAN>;

enum class PDCP_SN_Size {
    s_12,
    s_18,
    //... extension marker
};

struct DRBBStatusTransfer {
    std::optional<asn1::runtime::BitString> receiveStatusofPDCPSDU;
    PDCP_Count countValue;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extension;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct PDCP_SN_Status_Information {
    DRBBStatusTransfer pdcpStatusTransfer_UL;
    PDCP_Count pdcpStatusTransfer_DL;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extension;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_ID = int64_t;

struct DRBs_Subject_To_Counter_Check_Item_NG_RAN {
    PDU_Session_ID pDU_Session_ID;
    DRB_ID dRB_ID;
    PDCP_Count pDCP_UL_Count;
    PDCP_Count pDCP_DL_Count;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRBs_Subject_To_Counter_Check_List_NG_RAN = std::vector<DRBs_Subject_To_Counter_Check_Item_NG_RAN>;

enum class PDU_Session_Resource_Activity {
    active,
    not_active,
    //... extension marker
};

struct PDU_Session_Resource_Activity_Item {
    PDU_Session_ID pDU_Session_ID;
    PDU_Session_Resource_Activity pDU_Session_Resource_Activity;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Activity_List = std::vector<PDU_Session_Resource_Activity_Item>;

struct PDU_Session_Resource_Failed_Item {
    PDU_Session_ID pDU_Session_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Failed_List = std::vector<PDU_Session_Resource_Failed_Item>;

struct PDU_Session_Resource_Failed_Mod_Item {
    PDU_Session_ID pDU_Session_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Failed_Mod_List = std::vector<PDU_Session_Resource_Failed_Mod_Item>;

struct PDU_Session_Resource_Failed_To_Modify_Item {
    PDU_Session_ID pDU_Session_ID;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Failed_To_Modify_List = std::vector<PDU_Session_Resource_Failed_To_Modify_Item>;

struct PDU_Session_Resource_To_Remove_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_To_Remove_List = std::vector<PDU_Session_Resource_To_Remove_Item>;

enum class PDU_Session_Type {
    ipv4,
    ipv6,
    ipv4v6,
    ethernet,
    unstructured,
    //... extension marker
};

using PLMN_Identity = std::vector<uint8_t>;

struct NR_CGI {
    PLMN_Identity pLMN_Identity;
    NR_Cell_Identity nR_Cell_Identity;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct NR_CGI_Support_Item {
    NR_CGI nR_CGI;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using NR_CGI_Support_List = std::vector<NR_CGI_Support_Item>;

using PortNumber = asn1::runtime::BitString;

using PPI = int64_t;

using PriorityLevel = int64_t;

enum class Pre_emptionCapability {
    shall_not_trigger_pre_emption,
    may_trigger_pre_emption,
};

enum class Pre_emptionVulnerability {
    not_pre_emptable,
    pre_emptable,
};

struct EUTRANAllocationAndRetentionPriority {
    PriorityLevel priorityLevel;
    Pre_emptionCapability pre_emptionCapability;
    Pre_emptionVulnerability pre_emptionVulnerability;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct NGRANAllocationAndRetentionPriority {
    PriorityLevel priorityLevel;
    Pre_emptionCapability pre_emptionCapability;
    Pre_emptionVulnerability pre_emptionVulnerability;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using QCI = int64_t;

struct EUTRAN_QoS {
    QCI qCI;
    EUTRANAllocationAndRetentionPriority eUTRANallocationAndRetentionPriority;
    std::optional<GBR_QosInformation> gbrQosInformation;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct EUTRAN_QoS_Support_Item {
    EUTRAN_QoS eUTRAN_QoS;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using EUTRAN_QoS_Support_List = std::vector<EUTRAN_QoS_Support_Item>;

using QoS_Flow_Identifier = int64_t;

struct Data_Usage_per_QoS_Flow_Item {
    enum class secondaryRATType_type {
        nR,
        e_UTRA,
        //... extension marker
    };
    QoS_Flow_Identifier qoS_Flow_Identifier;
    secondaryRATType_type secondaryRATType;
    std::vector<MRDC_Data_Usage_Report_Item> qoS_Flow_Timed_Report_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using Data_Usage_per_QoS_Flow_List = std::vector<Data_Usage_per_QoS_Flow_Item>;

struct MRDC_Usage_Information {
    std::optional<Data_Usage_per_PDU_Session_Report> data_Usage_per_PDU_Session_Report;
    std::optional<Data_Usage_per_QoS_Flow_List> data_Usage_per_QoS_Flow_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct PDU_Session_Resource_Data_Usage_Item {
    PDU_Session_ID pDU_Session_ID;
    MRDC_Usage_Information mRDC_Usage_Information;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Data_Usage_List = std::vector<PDU_Session_Resource_Data_Usage_Item>;

struct QoS_Flow_Item {
    QoS_Flow_Identifier qoS_Flow_Identifier;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using QoS_Flow_List = std::vector<QoS_Flow_Item>;

struct PDU_Session_To_Notify_Item {
    PDU_Session_ID pDU_Session_ID;
    QoS_Flow_List qoS_Flow_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_To_Notify_List = std::vector<PDU_Session_To_Notify_Item>;

struct QoS_Flow_Failed_Item {
    QoS_Flow_Identifier qoS_Flow_Identifier;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using QoS_Flow_Failed_List = std::vector<QoS_Flow_Failed_Item>;

enum class QoS_Flow_Mapping_Indication {
    ul,
    dl,
    //... extension marker
};

struct QoS_Flow_Mapping_Item {
    QoS_Flow_Identifier qoS_Flow_Identifier;
    std::optional<QoS_Flow_Mapping_Indication> qoSFlowMappingIndication;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using QoS_Flow_Mapping_List = std::vector<QoS_Flow_Mapping_Item>;

struct Data_Forwarding_Information_Request {
    Data_Forwarding_Request data_Forwarding_Request;
    std::optional<QoS_Flow_Mapping_List> qoS_Flows_Forwarded_On_Fwd_Tunnels;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using QoSPriorityLevel = int64_t;

struct Dynamic5QIDescriptor {
    enum class delayCritical_type {
        delay_critical,
        non_delay_critical,
    };
    QoSPriorityLevel qoSPriorityLevel;
    PacketDelayBudget packetDelayBudget;
    PacketErrorRate packetErrorRate;
    std::optional<int64_t> fiveQI;
    std::optional<delayCritical_type> delayCritical;
    std::optional<AveragingWindow> averagingWindow;
    std::optional<MaxDataBurstVolume> maxDataBurstVolume;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct Non_Dynamic5QIDescriptor {
    int64_t fiveQI;
    std::optional<QoSPriorityLevel> qoSPriorityLevel;
    std::optional<AveragingWindow> averagingWindow;
    std::optional<MaxDataBurstVolume> maxDataBurstVolume;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct NG_RAN_QoS_Support_Item {
    Non_Dynamic5QIDescriptor non_Dynamic5QIDescriptor;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using NG_RAN_QoS_Support_List = std::vector<NG_RAN_QoS_Support_Item>;

struct QoS_Characteristics_non_Dynamic_5QI {
    Non_Dynamic5QIDescriptor non_Dynamic_5QI;
};
struct QoS_Characteristics_dynamic_5QI {
    Dynamic5QIDescriptor dynamic_5QI;
};
struct QoS_Characteristics_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using QoS_Characteristics = std::variant<
    QoS_Characteristics_non_Dynamic_5QI,
    QoS_Characteristics_dynamic_5QI,
    QoS_Characteristics_choice_extension
>;

struct QoS_Parameters_Support_List {
    std::optional<EUTRAN_QoS_Support_List> eUTRAN_QoS_Support_List;
    std::optional<NG_RAN_QoS_Support_List> nG_RAN_QoS_Support_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct QoSFlowLevelQoSParameters {
    enum class reflective_QoS_Attribute_type {
        subject_to,
        //... extension marker
    };
    enum class additional_QoS_Information_type {
        more_likely,
        //... extension marker
    };
    enum class reflective_QoS_Indicator_type {
        enabled,
        //... extension marker
    };
    QoS_Characteristics qoS_Characteristics;
    NGRANAllocationAndRetentionPriority nGRANallocationRetentionPriority;
    std::optional<GBR_QoSFlowInformation> gBR_QoS_Flow_Information;
    std::optional<reflective_QoS_Attribute_type> reflective_QoS_Attribute;
    std::optional<additional_QoS_Information_type> additional_QoS_Information;
    std::optional<int64_t> paging_Policy_Indicator;
    std::optional<reflective_QoS_Indicator_type> reflective_QoS_Indicator;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct QoS_Flow_QoS_Parameter_Item {
    QoS_Flow_Identifier qoS_Flow_Identifier;
    QoSFlowLevelQoSParameters qoSFlowLevelQoSParameters;
    std::optional<QoS_Flow_Mapping_Indication> qoSFlowMappingIndication;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using QoS_Flow_QoS_Parameter_List = std::vector<QoS_Flow_QoS_Parameter_Item>;

using RANUEID = std::vector<uint8_t>;

enum class RAT_Type {
    e_UTRA,
    nR,
    //... extension marker
};

struct Data_Usage_Report_Item {
    DRB_ID dRB_ID;
    RAT_Type rAT_Type;
    DRB_Usage_Report_List dRB_Usage_Report_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using Data_Usage_Report_List = std::vector<Data_Usage_Report_Item>;

enum class RLC_Mode {
    rlc_tm,
    rlc_am,
    rlc_um_bidirectional,
    rlc_um_unidirectional_ul,
    rlc_um_unidirectional_dl,
    //... extension marker
};

struct ROHC {
    enum class continueROHC_type {
        true_,
        //... extension marker
    };
    int64_t maxCID;
    int64_t rOHC_Profiles;
    std::optional<continueROHC_type> continueROHC;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct SecurityAlgorithm {
    CipheringAlgorithm cipheringAlgorithm;
    std::optional<IntegrityProtectionAlgorithm> integrityProtectionAlgorithm;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct SecurityIndication {
    IntegrityProtectionIndication integrityProtectionIndication;
    ConfidentialityProtectionIndication confidentialityProtectionIndication;
    std::optional<MaximumIPdatarate> maximumIPdatarate;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct SecurityResult {
    IntegrityProtectionResult integrityProtectionResult;
    ConfidentialityProtectionResult confidentialityProtectionResult;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct SNSSAI {
    std::vector<uint8_t> sST;
    std::optional<std::vector<uint8_t>> sD;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct Slice_Support_Item {
    SNSSAI sNSSAI;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using Slice_Support_List = std::vector<Slice_Support_Item>;

enum class SDAP_Header_DL {
    present,
    absent,
    //... extension marker
};

enum class SDAP_Header_UL {
    present,
    absent,
    //... extension marker
};

struct SDAP_Configuration {
    DefaultDRB defaultDRB;
    SDAP_Header_UL sDAP_Header_UL;
    SDAP_Header_DL sDAP_Header_DL;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class TimeToWait {
    v1s,
    v2s,
    v5s,
    v10s,
    v20s,
    v60s,
    //... extension marker
};

enum class TNLAssociationUsage {
    ue,
    non_ue,
    both,
    //... extension marker
};

using TransportLayerAddress = asn1::runtime::BitString;

struct CP_TNL_Information_endpoint_IP_Address {
    TransportLayerAddress endpoint_IP_Address;
};
struct CP_TNL_Information_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using CP_TNL_Information = std::variant<
    CP_TNL_Information_endpoint_IP_Address,
    CP_TNL_Information_choice_extension
>;

struct Endpoint_IP_address_and_port {
    TransportLayerAddress endpoint_IP_Address;
    PortNumber portNumber;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GNB_CU_CP_TNLA_Setup_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_CP_TNLA_Failed_To_Setup_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    Cause cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GNB_CU_CP_TNLA_To_Add_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    TNLAssociationUsage tNLAssociationUsage;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GNB_CU_CP_TNLA_To_Remove_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GNB_CU_CP_TNLA_To_Update_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    std::optional<TNLAssociationUsage> tNLAssociationUsage;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GNB_CU_UP_TNLA_To_Remove_Item {
    CP_TNL_Information tNLAssociationTransportLayerAddress;
    std::optional<CP_TNL_Information> tNLAssociationTransportLayerAddressgNBCUCP;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct GTPTunnel {
    TransportLayerAddress transportLayerAddress;
    GTP_TEID gTP_TEID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using TransactionID = int64_t;

enum class T_Reordering {
    ms0,
    ms1,
    ms2,
    ms4,
    ms5,
    ms8,
    ms10,
    ms15,
    ms20,
    ms30,
    ms40,
    ms50,
    ms60,
    ms80,
    ms100,
    ms120,
    ms140,
    ms160,
    ms180,
    ms200,
    ms220,
    ms240,
    ms260,
    ms280,
    ms300,
    ms500,
    ms750,
    ms1000,
    ms1250,
    ms1500,
    ms1750,
    ms2000,
    ms2250,
    ms2500,
    ms2750,
    ms3000,
    //... extension marker
};

struct T_ReorderingTimer {
    T_Reordering t_Reordering;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class TypeOfError {
    not_understood,
    missing,
    //... extension marker
};

struct CriticalityDiagnostics_IE_List_element {
    E1AP_CommonDataTypes::Criticality iECriticality;
    E1AP_CommonDataTypes::ProtocolIE_ID iE_ID;
    TypeOfError typeOfError;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using CriticalityDiagnostics_IE_List = std::vector<CriticalityDiagnostics_IE_List_element>;

struct CriticalityDiagnostics {
    std::optional<E1AP_CommonDataTypes::ProcedureCode> procedureCode;
    std::optional<E1AP_CommonDataTypes::TriggeringMessage> triggeringMessage;
    std::optional<E1AP_CommonDataTypes::Criticality> procedureCriticality;
    std::optional<TransactionID> transactionID;
    std::optional<CriticalityDiagnostics_IE_List> iEsCriticalityDiagnostics;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class UE_Activity {
    active,
    not_active,
    //... extension marker
};

struct ActivityInformation_dRB_Activity_List {
    DRB_Activity_List dRB_Activity_List;
};
struct ActivityInformation_pDU_Session_Resource_Activity_List {
    PDU_Session_Resource_Activity_List pDU_Session_Resource_Activity_List;
};
struct ActivityInformation_uE_Activity {
    UE_Activity uE_Activity;
};
struct ActivityInformation_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using ActivityInformation = std::variant<
    ActivityInformation_dRB_Activity_List,
    ActivityInformation_pDU_Session_Resource_Activity_List,
    ActivityInformation_uE_Activity,
    ActivityInformation_choice_extension
>;

struct UE_associatedLogicalE1_ConnectionItem {
    std::optional<GNB_CU_CP_UE_E1AP_ID> gNB_CU_CP_UE_E1AP_ID;
    std::optional<GNB_CU_UP_UE_E1AP_ID> gNB_CU_UP_UE_E1AP_ID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class UL_Configuration {
    no_data,
    shared,
    only,
    //... extension marker
};

struct Cell_Group_Information_Item {
    Cell_Group_ID cell_Group_ID;
    std::optional<UL_Configuration> uL_Configuration;
    std::optional<DL_TX_Stop> dL_TX_Stop;
    std::optional<RAT_Type> rAT_Type;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using Cell_Group_Information = std::vector<Cell_Group_Information_Item>;

struct DRB_Confirm_Modified_Item_EUTRAN {
    DRB_ID dRB_ID;
    std::optional<Cell_Group_Information> cell_Group_Information;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Confirm_Modified_List_EUTRAN = std::vector<DRB_Confirm_Modified_Item_EUTRAN>;

struct DRB_Confirm_Modified_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<Cell_Group_Information> cell_Group_Information;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Confirm_Modified_List_NG_RAN = std::vector<DRB_Confirm_Modified_Item_NG_RAN>;

struct PDU_Session_Resource_Confirm_Modified_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<DRB_Confirm_Modified_List_NG_RAN> dRB_Confirm_Modified_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Confirm_Modified_List = std::vector<PDU_Session_Resource_Confirm_Modified_Item>;

enum class ULDataSplitThreshold {
    b0,
    b100,
    b200,
    b400,
    b800,
    b1600,
    b3200,
    b6400,
    b12800,
    b25600,
    b51200,
    b102400,
    b204800,
    b409600,
    b819200,
    b1228800,
    b1638400,
    b2457600,
    b3276800,
    b4096000,
    b4915200,
    b5734400,
    b6553600,
    infinity,
    //... extension marker
};

struct UPSecuritykey {
    EncryptionKey encryptionKey;
    std::optional<IntegrityProtectionKey> integrityProtectionKey;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct SecurityInformation {
    SecurityAlgorithm securityAlgorithm;
    UPSecuritykey uPSecuritykey;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct UP_TNL_Information_gTPTunnel {
    GTPTunnel gTPTunnel;
};
struct UP_TNL_Information_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using UP_TNL_Information = std::variant<
    UP_TNL_Information_gTPTunnel,
    UP_TNL_Information_choice_extension
>;

struct Data_Forwarding_Information {
    std::optional<UP_TNL_Information> uL_Data_Forwarding;
    std::optional<UP_TNL_Information> dL_Data_Forwarding;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_CellGroupRelatedConfiguration_Item {
    Cell_Group_ID cell_Group_ID;
    UP_TNL_Information uP_TNL_Information;
    std::optional<UL_Configuration> uL_Configuration;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

using GNB_CU_UP_CellGroupRelatedConfiguration = std::vector<GNB_CU_UP_CellGroupRelatedConfiguration_Item>;

struct DRB_Required_To_Modify_Item_EUTRAN {
    DRB_ID dRB_ID;
    std::optional<UP_TNL_Information> s1_DL_UP_TNL_Information;
    std::optional<GNB_CU_UP_CellGroupRelatedConfiguration> gNB_CU_UP_CellGroupRelatedConfiguration;
    std::optional<Cause> cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Required_To_Modify_List_EUTRAN = std::vector<DRB_Required_To_Modify_Item_EUTRAN>;

struct DRB_Required_To_Modify_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<GNB_CU_UP_CellGroupRelatedConfiguration> gNB_CU_UP_CellGroupRelatedConfiguration;
    std::optional<QoS_Flow_List> flow_To_Remove;
    std::optional<Cause> cause;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Required_To_Modify_List_NG_RAN = std::vector<DRB_Required_To_Modify_Item_NG_RAN>;

struct PDU_Session_Resource_Required_To_Modify_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<UP_TNL_Information> nG_DL_UP_TNL_Information;
    std::optional<DRB_Required_To_Modify_List_NG_RAN> dRB_Required_To_Modify_List_NG_RAN;
    std::optional<DRB_Required_To_Remove_List_NG_RAN> dRB_Required_To_Remove_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Required_To_Modify_List = std::vector<PDU_Session_Resource_Required_To_Modify_Item>;

struct UP_Parameters_Item {
    UP_TNL_Information uP_TNL_Information;
    Cell_Group_ID cell_Group_ID;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using UP_Parameters = std::vector<UP_Parameters_Item>;

struct DRB_Modified_Item_EUTRAN {
    DRB_ID dRB_ID;
    std::optional<UP_TNL_Information> s1_DL_UP_TNL_Information;
    std::optional<PDCP_SN_Status_Information> pDCP_SN_Status_Information;
    std::optional<UP_Parameters> uL_UP_Transport_Parameters;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Modified_List_EUTRAN = std::vector<DRB_Modified_Item_EUTRAN>;

struct DRB_Modified_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<UP_Parameters> uL_UP_Transport_Parameters;
    std::optional<PDCP_SN_Status_Information> pDCP_SN_Status_Information;
    std::optional<QoS_Flow_List> flow_Setup_List;
    std::optional<QoS_Flow_Failed_List> flow_Failed_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Modified_List_NG_RAN = std::vector<DRB_Modified_Item_NG_RAN>;

struct DRB_Setup_Item_EUTRAN {
    enum class s1_DL_UP_Unchanged_type {
        true_,
        //... extension marker
    };
    DRB_ID dRB_ID;
    UP_TNL_Information s1_DL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information> data_Forwarding_Information_Response;
    UP_Parameters uL_UP_Transport_Parameters;
    std::optional<s1_DL_UP_Unchanged_type> s1_DL_UP_Unchanged;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Setup_List_EUTRAN = std::vector<DRB_Setup_Item_EUTRAN>;

struct DRB_Setup_Mod_Item_EUTRAN {
    DRB_ID dRB_ID;
    UP_TNL_Information s1_DL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information> data_Forwarding_Information_Response;
    UP_Parameters uL_UP_Transport_Parameters;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Setup_Mod_List_EUTRAN = std::vector<DRB_Setup_Mod_Item_EUTRAN>;

struct DRB_Setup_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<Data_Forwarding_Information> dRB_data_Forwarding_Information_Response;
    UP_Parameters uL_UP_Transport_Parameters;
    QoS_Flow_List flow_Setup_List;
    std::optional<QoS_Flow_Failed_List> flow_Failed_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Setup_List_NG_RAN = std::vector<DRB_Setup_Item_NG_RAN>;

struct DRB_Setup_Mod_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<Data_Forwarding_Information> dRB_data_Forwarding_Information_Response;
    UP_Parameters uL_UP_Transport_Parameters;
    QoS_Flow_List flow_Setup_List;
    std::optional<QoS_Flow_Failed_List> flow_Failed_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Setup_Mod_List_NG_RAN = std::vector<DRB_Setup_Mod_Item_NG_RAN>;

struct PDU_Session_Resource_Modified_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<UP_TNL_Information> nG_DL_UP_TNL_Information;
    std::optional<SecurityResult> securityResult;
    std::optional<Data_Forwarding_Information> pDU_Session_Data_Forwarding_Information_Response;
    std::optional<DRB_Setup_List_NG_RAN> dRB_Setup_List_NG_RAN;
    std::optional<DRB_Failed_List_NG_RAN> dRB_Failed_List_NG_RAN;
    std::optional<DRB_Modified_List_NG_RAN> dRB_Modified_List_NG_RAN;
    std::optional<DRB_Failed_To_Modify_List_NG_RAN> dRB_Failed_To_Modify_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Modified_List = std::vector<PDU_Session_Resource_Modified_Item>;

struct PDU_Session_Resource_Setup_Item {
    enum class nG_DL_UP_Unchanged_type {
        true_,
        //... extension marker
    };
    PDU_Session_ID pDU_Session_ID;
    std::optional<SecurityResult> securityResult;
    UP_TNL_Information nG_DL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information> pDU_Session_Data_Forwarding_Information_Response;
    std::optional<nG_DL_UP_Unchanged_type> nG_DL_UP_Unchanged;
    DRB_Setup_List_NG_RAN dRB_Setup_List_NG_RAN;
    std::optional<DRB_Failed_List_NG_RAN> dRB_Failed_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Setup_List = std::vector<PDU_Session_Resource_Setup_Item>;

struct PDU_Session_Resource_Setup_Mod_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<SecurityResult> securityResult;
    UP_TNL_Information nG_DL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information> pDU_Session_Data_Forwarding_Information_Response;
    DRB_Setup_Mod_List_NG_RAN dRB_Setup_Mod_List_NG_RAN;
    std::optional<DRB_Failed_Mod_List_NG_RAN> dRB_Failed_Mod_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_Setup_Mod_List = std::vector<PDU_Session_Resource_Setup_Mod_Item>;

struct UplinkOnlyROHC {
    enum class continueROHC_type {
        true_,
        //... extension marker
    };
    int64_t maxCID;
    int64_t rOHC_Profiles;
    std::optional<continueROHC_type> continueROHC;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
};

struct ROHC_Parameters_rOHC {
    ROHC rOHC;
};
struct ROHC_Parameters_uPlinkOnlyROHC {
    UplinkOnlyROHC uPlinkOnlyROHC;
};
struct ROHC_Parameters_choice_Extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_Extension;
};
using ROHC_Parameters = std::variant<
    ROHC_Parameters_rOHC,
    ROHC_Parameters_uPlinkOnlyROHC,
    ROHC_Parameters_choice_Extension
>;

struct PDCP_Configuration {
    PDCP_SN_Size pDCP_SN_Size_UL;
    PDCP_SN_Size pDCP_SN_Size_DL;
    RLC_Mode rLC_Mode;
    std::optional<ROHC_Parameters> rOHC_Parameters;
    std::optional<T_ReorderingTimer> t_ReorderingTimer;
    std::optional<DiscardTimer> discardTimer;
    std::optional<ULDataSplitThreshold> uLDataSplitThreshold;
    std::optional<PDCP_Duplication> pDCP_Duplication;
    std::optional<PDCP_Reestablishment> pDCP_Reestablishment;
    std::optional<PDCP_DataRecovery> pDCP_DataRecovery;
    std::optional<Duplication_Activation> duplication_Activation;
    std::optional<OutOfOrderDelivery> outOfOrderDelivery;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct DRB_To_Modify_Item_EUTRAN {
    DRB_ID dRB_ID;
    std::optional<PDCP_Configuration> pDCP_Configuration;
    std::optional<EUTRAN_QoS> eUTRAN_QoS;
    std::optional<UP_TNL_Information> s1_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information> data_Forwarding_Information;
    std::optional<PDCP_SN_Status_Request> pDCP_SN_Status_Request;
    std::optional<PDCP_SN_Status_Information> pDCP_SN_Status_Information;
    std::optional<UP_Parameters> dL_UP_Parameters;
    std::optional<Cell_Group_Information> cell_Group_To_Add;
    std::optional<Cell_Group_Information> cell_Group_To_Modify;
    std::optional<Cell_Group_Information> cell_Group_To_Remove;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Modify_List_EUTRAN = std::vector<DRB_To_Modify_Item_EUTRAN>;

struct DRB_To_Modify_Item_NG_RAN {
    DRB_ID dRB_ID;
    std::optional<SDAP_Configuration> sDAP_Configuration;
    std::optional<PDCP_Configuration> pDCP_Configuration;
    std::optional<Data_Forwarding_Information> dRB_Data_Forwarding_Information;
    std::optional<PDCP_SN_Status_Request> pDCP_SN_Status_Request;
    std::optional<PDCP_SN_Status_Information> pdcp_SN_Status_Information;
    std::optional<UP_Parameters> dL_UP_Parameters;
    std::optional<Cell_Group_Information> cell_Group_To_Add;
    std::optional<Cell_Group_Information> cell_Group_To_Modify;
    std::optional<Cell_Group_Information> cell_Group_To_Remove;
    std::optional<QoS_Flow_QoS_Parameter_List> flow_Mapping_Information;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Modify_List_NG_RAN = std::vector<DRB_To_Modify_Item_NG_RAN>;

struct DRB_To_Setup_Item_EUTRAN {
    DRB_ID dRB_ID;
    PDCP_Configuration pDCP_Configuration;
    EUTRAN_QoS eUTRAN_QoS;
    UP_TNL_Information s1_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information_Request> data_Forwarding_Information_Request;
    Cell_Group_Information cell_Group_Information;
    std::optional<UP_Parameters> dL_UP_Parameters;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<UP_TNL_Information> existing_Allocated_S1_DL_UP_TNL_Info;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Setup_List_EUTRAN = std::vector<DRB_To_Setup_Item_EUTRAN>;

struct DRB_To_Setup_Mod_Item_EUTRAN {
    DRB_ID dRB_ID;
    PDCP_Configuration pDCP_Configuration;
    EUTRAN_QoS eUTRAN_QoS;
    UP_TNL_Information s1_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information_Request> data_Forwarding_Information_Request;
    Cell_Group_Information cell_Group_Information;
    std::optional<UP_Parameters> dL_UP_Parameters;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Setup_Mod_List_EUTRAN = std::vector<DRB_To_Setup_Mod_Item_EUTRAN>;

struct DRB_To_Setup_Item_NG_RAN {
    DRB_ID dRB_ID;
    SDAP_Configuration sDAP_Configuration;
    PDCP_Configuration pDCP_Configuration;
    Cell_Group_Information cell_Group_Information;
    QoS_Flow_QoS_Parameter_List qos_flow_Information_To_Be_Setup;
    std::optional<Data_Forwarding_Information_Request> dRB_Data_Forwarding_Information_Request;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<PDCP_SN_Status_Information> pDCP_SN_Status_Information;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Setup_List_NG_RAN = std::vector<DRB_To_Setup_Item_NG_RAN>;

struct DRB_To_Setup_Mod_Item_NG_RAN {
    DRB_ID dRB_ID;
    SDAP_Configuration sDAP_Configuration;
    PDCP_Configuration pDCP_Configuration;
    Cell_Group_Information cell_Group_Information;
    QoS_Flow_QoS_Parameter_List flow_Mapping_Information;
    std::optional<Data_Forwarding_Information_Request> dRB_Data_Forwarding_Information_Request;
    std::optional<Inactivity_Timer> dRB_Inactivity_Timer;
    std::optional<PDCP_SN_Status_Information> pDCP_SN_Status_Information;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_To_Setup_Mod_List_NG_RAN = std::vector<DRB_To_Setup_Mod_Item_NG_RAN>;

struct PDU_Session_Resource_To_Modify_Item {
    PDU_Session_ID pDU_Session_ID;
    std::optional<SecurityIndication> securityIndication;
    std::optional<BitRate> pDU_Session_Resource_DL_AMBR;
    std::optional<UP_TNL_Information> nG_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information_Request> pDU_Session_Data_Forwarding_Information_Request;
    std::optional<Data_Forwarding_Information> pDU_Session_Data_Forwarding_Information;
    std::optional<Inactivity_Timer> pDU_Session_Inactivity_Timer;
    std::optional<NetworkInstance> networkInstance;
    std::optional<DRB_To_Setup_List_NG_RAN> dRB_To_Setup_List_NG_RAN;
    std::optional<DRB_To_Modify_List_NG_RAN> dRB_To_Modify_List_NG_RAN;
    std::optional<DRB_To_Remove_List_NG_RAN> dRB_To_Remove_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_To_Modify_List = std::vector<PDU_Session_Resource_To_Modify_Item>;

struct PDU_Session_Resource_To_Setup_Item {
    PDU_Session_ID pDU_Session_ID;
    PDU_Session_Type pDU_Session_Type;
    SNSSAI sNSSAI;
    SecurityIndication securityIndication;
    std::optional<BitRate> pDU_Session_Resource_DL_AMBR;
    UP_TNL_Information nG_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information_Request> pDU_Session_Data_Forwarding_Information_Request;
    std::optional<Inactivity_Timer> pDU_Session_Inactivity_Timer;
    std::optional<UP_TNL_Information> existing_Allocated_NG_DL_UP_TNL_Info;
    std::optional<NetworkInstance> networkInstance;
    DRB_To_Setup_List_NG_RAN dRB_To_Setup_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_To_Setup_List = std::vector<PDU_Session_Resource_To_Setup_Item>;

struct PDU_Session_Resource_To_Setup_Mod_Item {
    PDU_Session_ID pDU_Session_ID;
    PDU_Session_Type pDU_Session_Type;
    SNSSAI sNSSAI;
    SecurityIndication securityIndication;
    std::optional<BitRate> pDU_Session_Resource_AMBR;
    UP_TNL_Information nG_UL_UP_TNL_Information;
    std::optional<Data_Forwarding_Information_Request> pDU_Session_Data_Forwarding_Information_Request;
    std::optional<Inactivity_Timer> pDU_Session_Inactivity_Timer;
    DRB_To_Setup_Mod_List_NG_RAN dRB_To_Setup_Mod_List_NG_RAN;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using PDU_Session_Resource_To_Setup_Mod_List = std::vector<PDU_Session_Resource_To_Setup_Mod_Item>;

void encode_ActivityNotificationLevel(asn1::runtime::BitWriter& writer, const ActivityNotificationLevel& value);
ActivityNotificationLevel decode_ActivityNotificationLevel(asn1::runtime::BitReader& reader);
void encode_AveragingWindow(asn1::runtime::BitWriter& writer, const AveragingWindow& value);
AveragingWindow decode_AveragingWindow(asn1::runtime::BitReader& reader);
void encode_BearerContextStatusChange(asn1::runtime::BitWriter& writer, const BearerContextStatusChange& value);
BearerContextStatusChange decode_BearerContextStatusChange(asn1::runtime::BitReader& reader);
void encode_BitRate(asn1::runtime::BitWriter& writer, const BitRate& value);
BitRate decode_BitRate(asn1::runtime::BitReader& reader);
void encode_CauseMisc(asn1::runtime::BitWriter& writer, const CauseMisc& value);
CauseMisc decode_CauseMisc(asn1::runtime::BitReader& reader);
void encode_CauseProtocol(asn1::runtime::BitWriter& writer, const CauseProtocol& value);
CauseProtocol decode_CauseProtocol(asn1::runtime::BitReader& reader);
void encode_CauseRadioNetwork(asn1::runtime::BitWriter& writer, const CauseRadioNetwork& value);
CauseRadioNetwork decode_CauseRadioNetwork(asn1::runtime::BitReader& reader);
void encode_CauseTransport(asn1::runtime::BitWriter& writer, const CauseTransport& value);
CauseTransport decode_CauseTransport(asn1::runtime::BitReader& reader);
void encode_Cause(asn1::runtime::BitWriter& writer, const Cause& value);
Cause decode_Cause(asn1::runtime::BitReader& reader);
void encode_Cell_Group_ID(asn1::runtime::BitWriter& writer, const Cell_Group_ID& value);
Cell_Group_ID decode_Cell_Group_ID(asn1::runtime::BitReader& reader);
void encode_CipheringAlgorithm(asn1::runtime::BitWriter& writer, const CipheringAlgorithm& value);
CipheringAlgorithm decode_CipheringAlgorithm(asn1::runtime::BitReader& reader);
void encode_CNSupport(asn1::runtime::BitWriter& writer, const CNSupport& value);
CNSupport decode_CNSupport(asn1::runtime::BitReader& reader);
void encode_CommonNetworkInstance(asn1::runtime::BitWriter& writer, const CommonNetworkInstance& value);
CommonNetworkInstance decode_CommonNetworkInstance(asn1::runtime::BitReader& reader);
void encode_ConfidentialityProtectionIndication(asn1::runtime::BitWriter& writer, const ConfidentialityProtectionIndication& value);
ConfidentialityProtectionIndication decode_ConfidentialityProtectionIndication(asn1::runtime::BitReader& reader);
void encode_ConfidentialityProtectionResult(asn1::runtime::BitWriter& writer, const ConfidentialityProtectionResult& value);
ConfidentialityProtectionResult decode_ConfidentialityProtectionResult(asn1::runtime::BitReader& reader);
void encode_Data_Forwarding_Request(asn1::runtime::BitWriter& writer, const Data_Forwarding_Request& value);
Data_Forwarding_Request decode_Data_Forwarding_Request(asn1::runtime::BitReader& reader);
void encode_DefaultDRB(asn1::runtime::BitWriter& writer, const DefaultDRB& value);
DefaultDRB decode_DefaultDRB(asn1::runtime::BitReader& reader);
void encode_DiscardTimer(asn1::runtime::BitWriter& writer, const DiscardTimer& value);
DiscardTimer decode_DiscardTimer(asn1::runtime::BitReader& reader);
void encode_DL_TX_Stop(asn1::runtime::BitWriter& writer, const DL_TX_Stop& value);
DL_TX_Stop decode_DL_TX_Stop(asn1::runtime::BitReader& reader);
void encode_DRB_Activity(asn1::runtime::BitWriter& writer, const DRB_Activity& value);
DRB_Activity decode_DRB_Activity(asn1::runtime::BitReader& reader);
void encode_DRB_ID(asn1::runtime::BitWriter& writer, const DRB_ID& value);
DRB_ID decode_DRB_ID(asn1::runtime::BitReader& reader);
void encode_DRB_Activity_Item(asn1::runtime::BitWriter& writer, const DRB_Activity_Item& value);
DRB_Activity_Item decode_DRB_Activity_Item(asn1::runtime::BitReader& reader);
void encode_DRB_Activity_List(asn1::runtime::BitWriter& writer, const DRB_Activity_List& value);
DRB_Activity_List decode_DRB_Activity_List(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Item_EUTRAN& value);
DRB_Failed_Item_EUTRAN decode_DRB_Failed_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_List_EUTRAN& value);
DRB_Failed_List_EUTRAN decode_DRB_Failed_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Mod_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Mod_Item_EUTRAN& value);
DRB_Failed_Mod_Item_EUTRAN decode_DRB_Failed_Mod_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Mod_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Mod_List_EUTRAN& value);
DRB_Failed_Mod_List_EUTRAN decode_DRB_Failed_Mod_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Item_NG_RAN& value);
DRB_Failed_Item_NG_RAN decode_DRB_Failed_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_List_NG_RAN& value);
DRB_Failed_List_NG_RAN decode_DRB_Failed_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Mod_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Mod_Item_NG_RAN& value);
DRB_Failed_Mod_Item_NG_RAN decode_DRB_Failed_Mod_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_Mod_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_Mod_List_NG_RAN& value);
DRB_Failed_Mod_List_NG_RAN decode_DRB_Failed_Mod_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_To_Modify_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_To_Modify_Item_EUTRAN& value);
DRB_Failed_To_Modify_Item_EUTRAN decode_DRB_Failed_To_Modify_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_To_Modify_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Failed_To_Modify_List_EUTRAN& value);
DRB_Failed_To_Modify_List_EUTRAN decode_DRB_Failed_To_Modify_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_To_Modify_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_To_Modify_Item_NG_RAN& value);
DRB_Failed_To_Modify_Item_NG_RAN decode_DRB_Failed_To_Modify_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Failed_To_Modify_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Failed_To_Modify_List_NG_RAN& value);
DRB_Failed_To_Modify_List_NG_RAN decode_DRB_Failed_To_Modify_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Remove_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Remove_Item_EUTRAN& value);
DRB_To_Remove_Item_EUTRAN decode_DRB_To_Remove_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Remove_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Remove_List_EUTRAN& value);
DRB_To_Remove_List_EUTRAN decode_DRB_To_Remove_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Remove_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Remove_Item_EUTRAN& value);
DRB_Required_To_Remove_Item_EUTRAN decode_DRB_Required_To_Remove_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Remove_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Remove_List_EUTRAN& value);
DRB_Required_To_Remove_List_EUTRAN decode_DRB_Required_To_Remove_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Remove_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Remove_Item_NG_RAN& value);
DRB_To_Remove_Item_NG_RAN decode_DRB_To_Remove_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Remove_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Remove_List_NG_RAN& value);
DRB_To_Remove_List_NG_RAN decode_DRB_To_Remove_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Remove_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Remove_Item_NG_RAN& value);
DRB_Required_To_Remove_Item_NG_RAN decode_DRB_Required_To_Remove_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Remove_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Remove_List_NG_RAN& value);
DRB_Required_To_Remove_List_NG_RAN decode_DRB_Required_To_Remove_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Usage_Report_Item(asn1::runtime::BitWriter& writer, const DRB_Usage_Report_Item& value);
DRB_Usage_Report_Item decode_DRB_Usage_Report_Item(asn1::runtime::BitReader& reader);
void encode_DRB_Usage_Report_List(asn1::runtime::BitWriter& writer, const DRB_Usage_Report_List& value);
DRB_Usage_Report_List decode_DRB_Usage_Report_List(asn1::runtime::BitReader& reader);
void encode_Duplication_Activation(asn1::runtime::BitWriter& writer, const Duplication_Activation& value);
Duplication_Activation decode_Duplication_Activation(asn1::runtime::BitReader& reader);
void encode_DataDiscardRequired(asn1::runtime::BitWriter& writer, const DataDiscardRequired& value);
DataDiscardRequired decode_DataDiscardRequired(asn1::runtime::BitReader& reader);
void encode_EncryptionKey(asn1::runtime::BitWriter& writer, const EncryptionKey& value);
EncryptionKey decode_EncryptionKey(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_Name(asn1::runtime::BitWriter& writer, const GNB_CU_CP_Name& value);
GNB_CU_CP_Name decode_GNB_CU_CP_Name(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_UE_E1AP_ID(asn1::runtime::BitWriter& writer, const GNB_CU_CP_UE_E1AP_ID& value);
GNB_CU_CP_UE_E1AP_ID decode_GNB_CU_CP_UE_E1AP_ID(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_Capacity(asn1::runtime::BitWriter& writer, const GNB_CU_UP_Capacity& value);
GNB_CU_UP_Capacity decode_GNB_CU_UP_Capacity(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_ID(asn1::runtime::BitWriter& writer, const GNB_CU_UP_ID& value);
GNB_CU_UP_ID decode_GNB_CU_UP_ID(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_Name(asn1::runtime::BitWriter& writer, const GNB_CU_UP_Name& value);
GNB_CU_UP_Name decode_GNB_CU_UP_Name(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_UE_E1AP_ID(asn1::runtime::BitWriter& writer, const GNB_CU_UP_UE_E1AP_ID& value);
GNB_CU_UP_UE_E1AP_ID decode_GNB_CU_UP_UE_E1AP_ID(asn1::runtime::BitReader& reader);
void encode_GBR_QosInformation(asn1::runtime::BitWriter& writer, const GBR_QosInformation& value);
GBR_QosInformation decode_GBR_QosInformation(asn1::runtime::BitReader& reader);
void encode_GTP_TEID(asn1::runtime::BitWriter& writer, const GTP_TEID& value);
GTP_TEID decode_GTP_TEID(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_OverloadInformation(asn1::runtime::BitWriter& writer, const GNB_CU_UP_OverloadInformation& value);
GNB_CU_UP_OverloadInformation decode_GNB_CU_UP_OverloadInformation(asn1::runtime::BitReader& reader);
void encode_GNB_DU_ID(asn1::runtime::BitWriter& writer, const GNB_DU_ID& value);
GNB_DU_ID decode_GNB_DU_ID(asn1::runtime::BitReader& reader);
void encode_HFN(asn1::runtime::BitWriter& writer, const HFN& value);
HFN decode_HFN(asn1::runtime::BitReader& reader);
void encode_IntegrityProtectionIndication(asn1::runtime::BitWriter& writer, const IntegrityProtectionIndication& value);
IntegrityProtectionIndication decode_IntegrityProtectionIndication(asn1::runtime::BitReader& reader);
void encode_IntegrityProtectionAlgorithm(asn1::runtime::BitWriter& writer, const IntegrityProtectionAlgorithm& value);
IntegrityProtectionAlgorithm decode_IntegrityProtectionAlgorithm(asn1::runtime::BitReader& reader);
void encode_IntegrityProtectionKey(asn1::runtime::BitWriter& writer, const IntegrityProtectionKey& value);
IntegrityProtectionKey decode_IntegrityProtectionKey(asn1::runtime::BitReader& reader);
void encode_IntegrityProtectionResult(asn1::runtime::BitWriter& writer, const IntegrityProtectionResult& value);
IntegrityProtectionResult decode_IntegrityProtectionResult(asn1::runtime::BitReader& reader);
void encode_Inactivity_Timer(asn1::runtime::BitWriter& writer, const Inactivity_Timer& value);
Inactivity_Timer decode_Inactivity_Timer(asn1::runtime::BitReader& reader);
void encode_MaxDataBurstVolume(asn1::runtime::BitWriter& writer, const MaxDataBurstVolume& value);
MaxDataBurstVolume decode_MaxDataBurstVolume(asn1::runtime::BitReader& reader);
void encode_MaxIPrate(asn1::runtime::BitWriter& writer, const MaxIPrate& value);
MaxIPrate decode_MaxIPrate(asn1::runtime::BitReader& reader);
void encode_MaximumIPdatarate(asn1::runtime::BitWriter& writer, const MaximumIPdatarate& value);
MaximumIPdatarate decode_MaximumIPdatarate(asn1::runtime::BitReader& reader);
void encode_MaxPacketLossRate(asn1::runtime::BitWriter& writer, const MaxPacketLossRate& value);
MaxPacketLossRate decode_MaxPacketLossRate(asn1::runtime::BitReader& reader);
void encode_GBR_QoSFlowInformation(asn1::runtime::BitWriter& writer, const GBR_QoSFlowInformation& value);
GBR_QoSFlowInformation decode_GBR_QoSFlowInformation(asn1::runtime::BitReader& reader);
void encode_MRDC_Data_Usage_Report_Item(asn1::runtime::BitWriter& writer, const MRDC_Data_Usage_Report_Item& value);
MRDC_Data_Usage_Report_Item decode_MRDC_Data_Usage_Report_Item(asn1::runtime::BitReader& reader);
void encode_Data_Usage_per_PDU_Session_Report(asn1::runtime::BitWriter& writer, const Data_Usage_per_PDU_Session_Report& value);
Data_Usage_per_PDU_Session_Report decode_Data_Usage_per_PDU_Session_Report(asn1::runtime::BitReader& reader);
void encode_NetworkInstance(asn1::runtime::BitWriter& writer, const NetworkInstance& value);
NetworkInstance decode_NetworkInstance(asn1::runtime::BitReader& reader);
void encode_New_UL_TNL_Information_Required(asn1::runtime::BitWriter& writer, const New_UL_TNL_Information_Required& value);
New_UL_TNL_Information_Required decode_New_UL_TNL_Information_Required(asn1::runtime::BitReader& reader);
void encode_NR_Cell_Identity(asn1::runtime::BitWriter& writer, const NR_Cell_Identity& value);
NR_Cell_Identity decode_NR_Cell_Identity(asn1::runtime::BitReader& reader);
void encode_OutOfOrderDelivery(asn1::runtime::BitWriter& writer, const OutOfOrderDelivery& value);
OutOfOrderDelivery decode_OutOfOrderDelivery(asn1::runtime::BitReader& reader);
void encode_PacketDelayBudget(asn1::runtime::BitWriter& writer, const PacketDelayBudget& value);
PacketDelayBudget decode_PacketDelayBudget(asn1::runtime::BitReader& reader);
void encode_PER_Scalar(asn1::runtime::BitWriter& writer, const PER_Scalar& value);
PER_Scalar decode_PER_Scalar(asn1::runtime::BitReader& reader);
void encode_PER_Exponent(asn1::runtime::BitWriter& writer, const PER_Exponent& value);
PER_Exponent decode_PER_Exponent(asn1::runtime::BitReader& reader);
void encode_PacketErrorRate(asn1::runtime::BitWriter& writer, const PacketErrorRate& value);
PacketErrorRate decode_PacketErrorRate(asn1::runtime::BitReader& reader);
void encode_PDCP_SN_Status_Request(asn1::runtime::BitWriter& writer, const PDCP_SN_Status_Request& value);
PDCP_SN_Status_Request decode_PDCP_SN_Status_Request(asn1::runtime::BitReader& reader);
void encode_PDCP_DataRecovery(asn1::runtime::BitWriter& writer, const PDCP_DataRecovery& value);
PDCP_DataRecovery decode_PDCP_DataRecovery(asn1::runtime::BitReader& reader);
void encode_PDCP_Duplication(asn1::runtime::BitWriter& writer, const PDCP_Duplication& value);
PDCP_Duplication decode_PDCP_Duplication(asn1::runtime::BitReader& reader);
void encode_PDCP_Reestablishment(asn1::runtime::BitWriter& writer, const PDCP_Reestablishment& value);
PDCP_Reestablishment decode_PDCP_Reestablishment(asn1::runtime::BitReader& reader);
void encode_PDCP_SN(asn1::runtime::BitWriter& writer, const PDCP_SN& value);
PDCP_SN decode_PDCP_SN(asn1::runtime::BitReader& reader);
void encode_PDCP_Count(asn1::runtime::BitWriter& writer, const PDCP_Count& value);
PDCP_Count decode_PDCP_Count(asn1::runtime::BitReader& reader);
void encode_DRB_Status_Item(asn1::runtime::BitWriter& writer, const DRB_Status_Item& value);
DRB_Status_Item decode_DRB_Status_Item(asn1::runtime::BitReader& reader);
void encode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRBs_Subject_To_Counter_Check_Item_EUTRAN& value);
DRBs_Subject_To_Counter_Check_Item_EUTRAN decode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRBs_Subject_To_Counter_Check_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRBs_Subject_To_Counter_Check_List_EUTRAN& value);
DRBs_Subject_To_Counter_Check_List_EUTRAN decode_DRBs_Subject_To_Counter_Check_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_PDCP_SN_Size(asn1::runtime::BitWriter& writer, const PDCP_SN_Size& value);
PDCP_SN_Size decode_PDCP_SN_Size(asn1::runtime::BitReader& reader);
void encode_DRBBStatusTransfer(asn1::runtime::BitWriter& writer, const DRBBStatusTransfer& value);
DRBBStatusTransfer decode_DRBBStatusTransfer(asn1::runtime::BitReader& reader);
void encode_PDCP_SN_Status_Information(asn1::runtime::BitWriter& writer, const PDCP_SN_Status_Information& value);
PDCP_SN_Status_Information decode_PDCP_SN_Status_Information(asn1::runtime::BitReader& reader);
void encode_PDU_Session_ID(asn1::runtime::BitWriter& writer, const PDU_Session_ID& value);
PDU_Session_ID decode_PDU_Session_ID(asn1::runtime::BitReader& reader);
void encode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRBs_Subject_To_Counter_Check_Item_NG_RAN& value);
DRBs_Subject_To_Counter_Check_Item_NG_RAN decode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRBs_Subject_To_Counter_Check_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRBs_Subject_To_Counter_Check_List_NG_RAN& value);
DRBs_Subject_To_Counter_Check_List_NG_RAN decode_DRBs_Subject_To_Counter_Check_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Activity(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Activity& value);
PDU_Session_Resource_Activity decode_PDU_Session_Resource_Activity(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Activity_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Activity_Item& value);
PDU_Session_Resource_Activity_Item decode_PDU_Session_Resource_Activity_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Activity_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Activity_List& value);
PDU_Session_Resource_Activity_List decode_PDU_Session_Resource_Activity_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_Item& value);
PDU_Session_Resource_Failed_Item decode_PDU_Session_Resource_Failed_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_List& value);
PDU_Session_Resource_Failed_List decode_PDU_Session_Resource_Failed_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_Mod_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_Mod_Item& value);
PDU_Session_Resource_Failed_Mod_Item decode_PDU_Session_Resource_Failed_Mod_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_Mod_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_Mod_List& value);
PDU_Session_Resource_Failed_Mod_List decode_PDU_Session_Resource_Failed_Mod_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_To_Modify_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_To_Modify_Item& value);
PDU_Session_Resource_Failed_To_Modify_Item decode_PDU_Session_Resource_Failed_To_Modify_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Failed_To_Modify_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Failed_To_Modify_List& value);
PDU_Session_Resource_Failed_To_Modify_List decode_PDU_Session_Resource_Failed_To_Modify_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Remove_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Remove_Item& value);
PDU_Session_Resource_To_Remove_Item decode_PDU_Session_Resource_To_Remove_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Remove_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Remove_List& value);
PDU_Session_Resource_To_Remove_List decode_PDU_Session_Resource_To_Remove_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Type(asn1::runtime::BitWriter& writer, const PDU_Session_Type& value);
PDU_Session_Type decode_PDU_Session_Type(asn1::runtime::BitReader& reader);
void encode_PLMN_Identity(asn1::runtime::BitWriter& writer, const PLMN_Identity& value);
PLMN_Identity decode_PLMN_Identity(asn1::runtime::BitReader& reader);
void encode_NR_CGI(asn1::runtime::BitWriter& writer, const NR_CGI& value);
NR_CGI decode_NR_CGI(asn1::runtime::BitReader& reader);
void encode_NR_CGI_Support_Item(asn1::runtime::BitWriter& writer, const NR_CGI_Support_Item& value);
NR_CGI_Support_Item decode_NR_CGI_Support_Item(asn1::runtime::BitReader& reader);
void encode_NR_CGI_Support_List(asn1::runtime::BitWriter& writer, const NR_CGI_Support_List& value);
NR_CGI_Support_List decode_NR_CGI_Support_List(asn1::runtime::BitReader& reader);
void encode_PortNumber(asn1::runtime::BitWriter& writer, const PortNumber& value);
PortNumber decode_PortNumber(asn1::runtime::BitReader& reader);
void encode_PPI(asn1::runtime::BitWriter& writer, const PPI& value);
PPI decode_PPI(asn1::runtime::BitReader& reader);
void encode_PriorityLevel(asn1::runtime::BitWriter& writer, const PriorityLevel& value);
PriorityLevel decode_PriorityLevel(asn1::runtime::BitReader& reader);
void encode_Pre_emptionCapability(asn1::runtime::BitWriter& writer, const Pre_emptionCapability& value);
Pre_emptionCapability decode_Pre_emptionCapability(asn1::runtime::BitReader& reader);
void encode_Pre_emptionVulnerability(asn1::runtime::BitWriter& writer, const Pre_emptionVulnerability& value);
Pre_emptionVulnerability decode_Pre_emptionVulnerability(asn1::runtime::BitReader& reader);
void encode_EUTRANAllocationAndRetentionPriority(asn1::runtime::BitWriter& writer, const EUTRANAllocationAndRetentionPriority& value);
EUTRANAllocationAndRetentionPriority decode_EUTRANAllocationAndRetentionPriority(asn1::runtime::BitReader& reader);
void encode_NGRANAllocationAndRetentionPriority(asn1::runtime::BitWriter& writer, const NGRANAllocationAndRetentionPriority& value);
NGRANAllocationAndRetentionPriority decode_NGRANAllocationAndRetentionPriority(asn1::runtime::BitReader& reader);
void encode_QCI(asn1::runtime::BitWriter& writer, const QCI& value);
QCI decode_QCI(asn1::runtime::BitReader& reader);
void encode_EUTRAN_QoS(asn1::runtime::BitWriter& writer, const EUTRAN_QoS& value);
EUTRAN_QoS decode_EUTRAN_QoS(asn1::runtime::BitReader& reader);
void encode_EUTRAN_QoS_Support_Item(asn1::runtime::BitWriter& writer, const EUTRAN_QoS_Support_Item& value);
EUTRAN_QoS_Support_Item decode_EUTRAN_QoS_Support_Item(asn1::runtime::BitReader& reader);
void encode_EUTRAN_QoS_Support_List(asn1::runtime::BitWriter& writer, const EUTRAN_QoS_Support_List& value);
EUTRAN_QoS_Support_List decode_EUTRAN_QoS_Support_List(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Identifier(asn1::runtime::BitWriter& writer, const QoS_Flow_Identifier& value);
QoS_Flow_Identifier decode_QoS_Flow_Identifier(asn1::runtime::BitReader& reader);
void encode_Data_Usage_per_QoS_Flow_Item(asn1::runtime::BitWriter& writer, const Data_Usage_per_QoS_Flow_Item& value);
Data_Usage_per_QoS_Flow_Item decode_Data_Usage_per_QoS_Flow_Item(asn1::runtime::BitReader& reader);
void encode_Data_Usage_per_QoS_Flow_List(asn1::runtime::BitWriter& writer, const Data_Usage_per_QoS_Flow_List& value);
Data_Usage_per_QoS_Flow_List decode_Data_Usage_per_QoS_Flow_List(asn1::runtime::BitReader& reader);
void encode_MRDC_Usage_Information(asn1::runtime::BitWriter& writer, const MRDC_Usage_Information& value);
MRDC_Usage_Information decode_MRDC_Usage_Information(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Data_Usage_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Data_Usage_Item& value);
PDU_Session_Resource_Data_Usage_Item decode_PDU_Session_Resource_Data_Usage_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Data_Usage_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Data_Usage_List& value);
PDU_Session_Resource_Data_Usage_List decode_PDU_Session_Resource_Data_Usage_List(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Item(asn1::runtime::BitWriter& writer, const QoS_Flow_Item& value);
QoS_Flow_Item decode_QoS_Flow_Item(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_List(asn1::runtime::BitWriter& writer, const QoS_Flow_List& value);
QoS_Flow_List decode_QoS_Flow_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_To_Notify_Item(asn1::runtime::BitWriter& writer, const PDU_Session_To_Notify_Item& value);
PDU_Session_To_Notify_Item decode_PDU_Session_To_Notify_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_To_Notify_List(asn1::runtime::BitWriter& writer, const PDU_Session_To_Notify_List& value);
PDU_Session_To_Notify_List decode_PDU_Session_To_Notify_List(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Failed_Item(asn1::runtime::BitWriter& writer, const QoS_Flow_Failed_Item& value);
QoS_Flow_Failed_Item decode_QoS_Flow_Failed_Item(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Failed_List(asn1::runtime::BitWriter& writer, const QoS_Flow_Failed_List& value);
QoS_Flow_Failed_List decode_QoS_Flow_Failed_List(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Mapping_Indication(asn1::runtime::BitWriter& writer, const QoS_Flow_Mapping_Indication& value);
QoS_Flow_Mapping_Indication decode_QoS_Flow_Mapping_Indication(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Mapping_Item(asn1::runtime::BitWriter& writer, const QoS_Flow_Mapping_Item& value);
QoS_Flow_Mapping_Item decode_QoS_Flow_Mapping_Item(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_Mapping_List(asn1::runtime::BitWriter& writer, const QoS_Flow_Mapping_List& value);
QoS_Flow_Mapping_List decode_QoS_Flow_Mapping_List(asn1::runtime::BitReader& reader);
void encode_Data_Forwarding_Information_Request(asn1::runtime::BitWriter& writer, const Data_Forwarding_Information_Request& value);
Data_Forwarding_Information_Request decode_Data_Forwarding_Information_Request(asn1::runtime::BitReader& reader);
void encode_QoSPriorityLevel(asn1::runtime::BitWriter& writer, const QoSPriorityLevel& value);
QoSPriorityLevel decode_QoSPriorityLevel(asn1::runtime::BitReader& reader);
void encode_Dynamic5QIDescriptor(asn1::runtime::BitWriter& writer, const Dynamic5QIDescriptor& value);
Dynamic5QIDescriptor decode_Dynamic5QIDescriptor(asn1::runtime::BitReader& reader);
void encode_Non_Dynamic5QIDescriptor(asn1::runtime::BitWriter& writer, const Non_Dynamic5QIDescriptor& value);
Non_Dynamic5QIDescriptor decode_Non_Dynamic5QIDescriptor(asn1::runtime::BitReader& reader);
void encode_NG_RAN_QoS_Support_Item(asn1::runtime::BitWriter& writer, const NG_RAN_QoS_Support_Item& value);
NG_RAN_QoS_Support_Item decode_NG_RAN_QoS_Support_Item(asn1::runtime::BitReader& reader);
void encode_NG_RAN_QoS_Support_List(asn1::runtime::BitWriter& writer, const NG_RAN_QoS_Support_List& value);
NG_RAN_QoS_Support_List decode_NG_RAN_QoS_Support_List(asn1::runtime::BitReader& reader);
void encode_QoS_Characteristics(asn1::runtime::BitWriter& writer, const QoS_Characteristics& value);
QoS_Characteristics decode_QoS_Characteristics(asn1::runtime::BitReader& reader);
void encode_QoS_Parameters_Support_List(asn1::runtime::BitWriter& writer, const QoS_Parameters_Support_List& value);
QoS_Parameters_Support_List decode_QoS_Parameters_Support_List(asn1::runtime::BitReader& reader);
void encode_QoSFlowLevelQoSParameters(asn1::runtime::BitWriter& writer, const QoSFlowLevelQoSParameters& value);
QoSFlowLevelQoSParameters decode_QoSFlowLevelQoSParameters(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_QoS_Parameter_Item(asn1::runtime::BitWriter& writer, const QoS_Flow_QoS_Parameter_Item& value);
QoS_Flow_QoS_Parameter_Item decode_QoS_Flow_QoS_Parameter_Item(asn1::runtime::BitReader& reader);
void encode_QoS_Flow_QoS_Parameter_List(asn1::runtime::BitWriter& writer, const QoS_Flow_QoS_Parameter_List& value);
QoS_Flow_QoS_Parameter_List decode_QoS_Flow_QoS_Parameter_List(asn1::runtime::BitReader& reader);
void encode_RANUEID(asn1::runtime::BitWriter& writer, const RANUEID& value);
RANUEID decode_RANUEID(asn1::runtime::BitReader& reader);
void encode_RAT_Type(asn1::runtime::BitWriter& writer, const RAT_Type& value);
RAT_Type decode_RAT_Type(asn1::runtime::BitReader& reader);
void encode_Data_Usage_Report_Item(asn1::runtime::BitWriter& writer, const Data_Usage_Report_Item& value);
Data_Usage_Report_Item decode_Data_Usage_Report_Item(asn1::runtime::BitReader& reader);
void encode_Data_Usage_Report_List(asn1::runtime::BitWriter& writer, const Data_Usage_Report_List& value);
Data_Usage_Report_List decode_Data_Usage_Report_List(asn1::runtime::BitReader& reader);
void encode_RLC_Mode(asn1::runtime::BitWriter& writer, const RLC_Mode& value);
RLC_Mode decode_RLC_Mode(asn1::runtime::BitReader& reader);
void encode_ROHC(asn1::runtime::BitWriter& writer, const ROHC& value);
ROHC decode_ROHC(asn1::runtime::BitReader& reader);
void encode_SecurityAlgorithm(asn1::runtime::BitWriter& writer, const SecurityAlgorithm& value);
SecurityAlgorithm decode_SecurityAlgorithm(asn1::runtime::BitReader& reader);
void encode_SecurityIndication(asn1::runtime::BitWriter& writer, const SecurityIndication& value);
SecurityIndication decode_SecurityIndication(asn1::runtime::BitReader& reader);
void encode_SecurityResult(asn1::runtime::BitWriter& writer, const SecurityResult& value);
SecurityResult decode_SecurityResult(asn1::runtime::BitReader& reader);
void encode_SNSSAI(asn1::runtime::BitWriter& writer, const SNSSAI& value);
SNSSAI decode_SNSSAI(asn1::runtime::BitReader& reader);
void encode_Slice_Support_Item(asn1::runtime::BitWriter& writer, const Slice_Support_Item& value);
Slice_Support_Item decode_Slice_Support_Item(asn1::runtime::BitReader& reader);
void encode_Slice_Support_List(asn1::runtime::BitWriter& writer, const Slice_Support_List& value);
Slice_Support_List decode_Slice_Support_List(asn1::runtime::BitReader& reader);
void encode_SDAP_Header_DL(asn1::runtime::BitWriter& writer, const SDAP_Header_DL& value);
SDAP_Header_DL decode_SDAP_Header_DL(asn1::runtime::BitReader& reader);
void encode_SDAP_Header_UL(asn1::runtime::BitWriter& writer, const SDAP_Header_UL& value);
SDAP_Header_UL decode_SDAP_Header_UL(asn1::runtime::BitReader& reader);
void encode_SDAP_Configuration(asn1::runtime::BitWriter& writer, const SDAP_Configuration& value);
SDAP_Configuration decode_SDAP_Configuration(asn1::runtime::BitReader& reader);
void encode_TimeToWait(asn1::runtime::BitWriter& writer, const TimeToWait& value);
TimeToWait decode_TimeToWait(asn1::runtime::BitReader& reader);
void encode_TNLAssociationUsage(asn1::runtime::BitWriter& writer, const TNLAssociationUsage& value);
TNLAssociationUsage decode_TNLAssociationUsage(asn1::runtime::BitReader& reader);
void encode_TransportLayerAddress(asn1::runtime::BitWriter& writer, const TransportLayerAddress& value);
TransportLayerAddress decode_TransportLayerAddress(asn1::runtime::BitReader& reader);
void encode_CP_TNL_Information(asn1::runtime::BitWriter& writer, const CP_TNL_Information& value);
CP_TNL_Information decode_CP_TNL_Information(asn1::runtime::BitReader& reader);
void encode_Endpoint_IP_address_and_port(asn1::runtime::BitWriter& writer, const Endpoint_IP_address_and_port& value);
Endpoint_IP_address_and_port decode_Endpoint_IP_address_and_port(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_Setup_Item(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_Setup_Item& value);
GNB_CU_CP_TNLA_Setup_Item decode_GNB_CU_CP_TNLA_Setup_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_Failed_To_Setup_Item& value);
GNB_CU_CP_TNLA_Failed_To_Setup_Item decode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Add_Item(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Add_Item& value);
GNB_CU_CP_TNLA_To_Add_Item decode_GNB_CU_CP_TNLA_To_Add_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Remove_Item(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Remove_Item& value);
GNB_CU_CP_TNLA_To_Remove_Item decode_GNB_CU_CP_TNLA_To_Remove_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Update_Item(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Update_Item& value);
GNB_CU_CP_TNLA_To_Update_Item decode_GNB_CU_CP_TNLA_To_Update_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_TNLA_To_Remove_Item(asn1::runtime::BitWriter& writer, const GNB_CU_UP_TNLA_To_Remove_Item& value);
GNB_CU_UP_TNLA_To_Remove_Item decode_GNB_CU_UP_TNLA_To_Remove_Item(asn1::runtime::BitReader& reader);
void encode_GTPTunnel(asn1::runtime::BitWriter& writer, const GTPTunnel& value);
GTPTunnel decode_GTPTunnel(asn1::runtime::BitReader& reader);
void encode_TransactionID(asn1::runtime::BitWriter& writer, const TransactionID& value);
TransactionID decode_TransactionID(asn1::runtime::BitReader& reader);
void encode_T_Reordering(asn1::runtime::BitWriter& writer, const T_Reordering& value);
T_Reordering decode_T_Reordering(asn1::runtime::BitReader& reader);
void encode_T_ReorderingTimer(asn1::runtime::BitWriter& writer, const T_ReorderingTimer& value);
T_ReorderingTimer decode_T_ReorderingTimer(asn1::runtime::BitReader& reader);
void encode_TypeOfError(asn1::runtime::BitWriter& writer, const TypeOfError& value);
TypeOfError decode_TypeOfError(asn1::runtime::BitReader& reader);
void encode_CriticalityDiagnostics_IE_List(asn1::runtime::BitWriter& writer, const CriticalityDiagnostics_IE_List& value);
CriticalityDiagnostics_IE_List decode_CriticalityDiagnostics_IE_List(asn1::runtime::BitReader& reader);
void encode_CriticalityDiagnostics(asn1::runtime::BitWriter& writer, const CriticalityDiagnostics& value);
CriticalityDiagnostics decode_CriticalityDiagnostics(asn1::runtime::BitReader& reader);
void encode_UE_Activity(asn1::runtime::BitWriter& writer, const UE_Activity& value);
UE_Activity decode_UE_Activity(asn1::runtime::BitReader& reader);
void encode_ActivityInformation(asn1::runtime::BitWriter& writer, const ActivityInformation& value);
ActivityInformation decode_ActivityInformation(asn1::runtime::BitReader& reader);
void encode_UE_associatedLogicalE1_ConnectionItem(asn1::runtime::BitWriter& writer, const UE_associatedLogicalE1_ConnectionItem& value);
UE_associatedLogicalE1_ConnectionItem decode_UE_associatedLogicalE1_ConnectionItem(asn1::runtime::BitReader& reader);
void encode_UL_Configuration(asn1::runtime::BitWriter& writer, const UL_Configuration& value);
UL_Configuration decode_UL_Configuration(asn1::runtime::BitReader& reader);
void encode_Cell_Group_Information_Item(asn1::runtime::BitWriter& writer, const Cell_Group_Information_Item& value);
Cell_Group_Information_Item decode_Cell_Group_Information_Item(asn1::runtime::BitReader& reader);
void encode_Cell_Group_Information(asn1::runtime::BitWriter& writer, const Cell_Group_Information& value);
Cell_Group_Information decode_Cell_Group_Information(asn1::runtime::BitReader& reader);
void encode_DRB_Confirm_Modified_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Confirm_Modified_Item_EUTRAN& value);
DRB_Confirm_Modified_Item_EUTRAN decode_DRB_Confirm_Modified_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Confirm_Modified_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Confirm_Modified_List_EUTRAN& value);
DRB_Confirm_Modified_List_EUTRAN decode_DRB_Confirm_Modified_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Confirm_Modified_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Confirm_Modified_Item_NG_RAN& value);
DRB_Confirm_Modified_Item_NG_RAN decode_DRB_Confirm_Modified_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Confirm_Modified_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Confirm_Modified_List_NG_RAN& value);
DRB_Confirm_Modified_List_NG_RAN decode_DRB_Confirm_Modified_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Confirm_Modified_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Confirm_Modified_Item& value);
PDU_Session_Resource_Confirm_Modified_Item decode_PDU_Session_Resource_Confirm_Modified_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Confirm_Modified_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Confirm_Modified_List& value);
PDU_Session_Resource_Confirm_Modified_List decode_PDU_Session_Resource_Confirm_Modified_List(asn1::runtime::BitReader& reader);
void encode_ULDataSplitThreshold(asn1::runtime::BitWriter& writer, const ULDataSplitThreshold& value);
ULDataSplitThreshold decode_ULDataSplitThreshold(asn1::runtime::BitReader& reader);
void encode_UPSecuritykey(asn1::runtime::BitWriter& writer, const UPSecuritykey& value);
UPSecuritykey decode_UPSecuritykey(asn1::runtime::BitReader& reader);
void encode_SecurityInformation(asn1::runtime::BitWriter& writer, const SecurityInformation& value);
SecurityInformation decode_SecurityInformation(asn1::runtime::BitReader& reader);
void encode_UP_TNL_Information(asn1::runtime::BitWriter& writer, const UP_TNL_Information& value);
UP_TNL_Information decode_UP_TNL_Information(asn1::runtime::BitReader& reader);
void encode_Data_Forwarding_Information(asn1::runtime::BitWriter& writer, const Data_Forwarding_Information& value);
Data_Forwarding_Information decode_Data_Forwarding_Information(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(asn1::runtime::BitWriter& writer, const GNB_CU_UP_CellGroupRelatedConfiguration_Item& value);
GNB_CU_UP_CellGroupRelatedConfiguration_Item decode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_CellGroupRelatedConfiguration(asn1::runtime::BitWriter& writer, const GNB_CU_UP_CellGroupRelatedConfiguration& value);
GNB_CU_UP_CellGroupRelatedConfiguration decode_GNB_CU_UP_CellGroupRelatedConfiguration(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Modify_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Modify_Item_EUTRAN& value);
DRB_Required_To_Modify_Item_EUTRAN decode_DRB_Required_To_Modify_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Modify_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Modify_List_EUTRAN& value);
DRB_Required_To_Modify_List_EUTRAN decode_DRB_Required_To_Modify_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Modify_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Modify_Item_NG_RAN& value);
DRB_Required_To_Modify_Item_NG_RAN decode_DRB_Required_To_Modify_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Required_To_Modify_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Required_To_Modify_List_NG_RAN& value);
DRB_Required_To_Modify_List_NG_RAN decode_DRB_Required_To_Modify_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Required_To_Modify_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Required_To_Modify_Item& value);
PDU_Session_Resource_Required_To_Modify_Item decode_PDU_Session_Resource_Required_To_Modify_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Required_To_Modify_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Required_To_Modify_List& value);
PDU_Session_Resource_Required_To_Modify_List decode_PDU_Session_Resource_Required_To_Modify_List(asn1::runtime::BitReader& reader);
void encode_UP_Parameters_Item(asn1::runtime::BitWriter& writer, const UP_Parameters_Item& value);
UP_Parameters_Item decode_UP_Parameters_Item(asn1::runtime::BitReader& reader);
void encode_UP_Parameters(asn1::runtime::BitWriter& writer, const UP_Parameters& value);
UP_Parameters decode_UP_Parameters(asn1::runtime::BitReader& reader);
void encode_DRB_Modified_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Modified_Item_EUTRAN& value);
DRB_Modified_Item_EUTRAN decode_DRB_Modified_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Modified_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Modified_List_EUTRAN& value);
DRB_Modified_List_EUTRAN decode_DRB_Modified_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Modified_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Modified_Item_NG_RAN& value);
DRB_Modified_Item_NG_RAN decode_DRB_Modified_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Modified_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Modified_List_NG_RAN& value);
DRB_Modified_List_NG_RAN decode_DRB_Modified_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Item_EUTRAN& value);
DRB_Setup_Item_EUTRAN decode_DRB_Setup_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Setup_List_EUTRAN& value);
DRB_Setup_List_EUTRAN decode_DRB_Setup_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Mod_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Mod_Item_EUTRAN& value);
DRB_Setup_Mod_Item_EUTRAN decode_DRB_Setup_Mod_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Mod_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Mod_List_EUTRAN& value);
DRB_Setup_Mod_List_EUTRAN decode_DRB_Setup_Mod_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Item_NG_RAN& value);
DRB_Setup_Item_NG_RAN decode_DRB_Setup_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Setup_List_NG_RAN& value);
DRB_Setup_List_NG_RAN decode_DRB_Setup_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Mod_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Mod_Item_NG_RAN& value);
DRB_Setup_Mod_Item_NG_RAN decode_DRB_Setup_Mod_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_Setup_Mod_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_Setup_Mod_List_NG_RAN& value);
DRB_Setup_Mod_List_NG_RAN decode_DRB_Setup_Mod_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Modified_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Modified_Item& value);
PDU_Session_Resource_Modified_Item decode_PDU_Session_Resource_Modified_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Modified_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Modified_List& value);
PDU_Session_Resource_Modified_List decode_PDU_Session_Resource_Modified_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Setup_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Setup_Item& value);
PDU_Session_Resource_Setup_Item decode_PDU_Session_Resource_Setup_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Setup_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Setup_List& value);
PDU_Session_Resource_Setup_List decode_PDU_Session_Resource_Setup_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Setup_Mod_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Setup_Mod_Item& value);
PDU_Session_Resource_Setup_Mod_Item decode_PDU_Session_Resource_Setup_Mod_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_Setup_Mod_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_Setup_Mod_List& value);
PDU_Session_Resource_Setup_Mod_List decode_PDU_Session_Resource_Setup_Mod_List(asn1::runtime::BitReader& reader);
void encode_UplinkOnlyROHC(asn1::runtime::BitWriter& writer, const UplinkOnlyROHC& value);
UplinkOnlyROHC decode_UplinkOnlyROHC(asn1::runtime::BitReader& reader);
void encode_ROHC_Parameters(asn1::runtime::BitWriter& writer, const ROHC_Parameters& value);
ROHC_Parameters decode_ROHC_Parameters(asn1::runtime::BitReader& reader);
void encode_PDCP_Configuration(asn1::runtime::BitWriter& writer, const PDCP_Configuration& value);
PDCP_Configuration decode_PDCP_Configuration(asn1::runtime::BitReader& reader);
void encode_DRB_To_Modify_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Modify_Item_EUTRAN& value);
DRB_To_Modify_Item_EUTRAN decode_DRB_To_Modify_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Modify_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Modify_List_EUTRAN& value);
DRB_To_Modify_List_EUTRAN decode_DRB_To_Modify_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Modify_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Modify_Item_NG_RAN& value);
DRB_To_Modify_Item_NG_RAN decode_DRB_To_Modify_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Modify_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Modify_List_NG_RAN& value);
DRB_To_Modify_List_NG_RAN decode_DRB_To_Modify_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Item_EUTRAN& value);
DRB_To_Setup_Item_EUTRAN decode_DRB_To_Setup_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_List_EUTRAN& value);
DRB_To_Setup_List_EUTRAN decode_DRB_To_Setup_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Mod_Item_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Mod_Item_EUTRAN& value);
DRB_To_Setup_Mod_Item_EUTRAN decode_DRB_To_Setup_Mod_Item_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Mod_List_EUTRAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Mod_List_EUTRAN& value);
DRB_To_Setup_Mod_List_EUTRAN decode_DRB_To_Setup_Mod_List_EUTRAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Item_NG_RAN& value);
DRB_To_Setup_Item_NG_RAN decode_DRB_To_Setup_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_List_NG_RAN& value);
DRB_To_Setup_List_NG_RAN decode_DRB_To_Setup_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Mod_Item_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Mod_Item_NG_RAN& value);
DRB_To_Setup_Mod_Item_NG_RAN decode_DRB_To_Setup_Mod_Item_NG_RAN(asn1::runtime::BitReader& reader);
void encode_DRB_To_Setup_Mod_List_NG_RAN(asn1::runtime::BitWriter& writer, const DRB_To_Setup_Mod_List_NG_RAN& value);
DRB_To_Setup_Mod_List_NG_RAN decode_DRB_To_Setup_Mod_List_NG_RAN(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Modify_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Modify_Item& value);
PDU_Session_Resource_To_Modify_Item decode_PDU_Session_Resource_To_Modify_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Modify_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Modify_List& value);
PDU_Session_Resource_To_Modify_List decode_PDU_Session_Resource_To_Modify_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Setup_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Setup_Item& value);
PDU_Session_Resource_To_Setup_Item decode_PDU_Session_Resource_To_Setup_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Setup_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Setup_List& value);
PDU_Session_Resource_To_Setup_List decode_PDU_Session_Resource_To_Setup_List(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Setup_Mod_Item(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Setup_Mod_Item& value);
PDU_Session_Resource_To_Setup_Mod_Item decode_PDU_Session_Resource_To_Setup_Mod_Item(asn1::runtime::BitReader& reader);
void encode_PDU_Session_Resource_To_Setup_Mod_List(asn1::runtime::BitWriter& writer, const PDU_Session_Resource_To_Setup_Mod_List& value);
PDU_Session_Resource_To_Setup_Mod_List decode_PDU_Session_Resource_To_Setup_Mod_List(asn1::runtime::BitReader& reader);

} // namespace E1AP_IEs

namespace E1AP_PDU_Contents {

struct Reset {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

enum class ResetAll {
    reset_all,
    //... extension marker
};

using UE_associatedLogicalE1_ConnectionListRes = std::vector<E1AP_Containers::ProtocolIE_SingleContainer>;

struct ResetType_e1_Interface {
    ResetAll e1_Interface;
};
struct ResetType_partOfE1_Interface {
    UE_associatedLogicalE1_ConnectionListRes partOfE1_Interface;
};
struct ResetType_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using ResetType = std::variant<
    ResetType_e1_Interface,
    ResetType_partOfE1_Interface,
    ResetType_choice_extension
>;

struct ResetAcknowledge {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using UE_associatedLogicalE1_ConnectionListResAck = std::vector<E1AP_Containers::ProtocolIE_SingleContainer>;

struct ErrorIndication {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_E1SetupRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct SupportedPLMNs_Item {
    E1AP_IEs::PLMN_Identity pLMN_Identity;
    std::optional<E1AP_IEs::Slice_Support_List> slice_Support_List;
    std::optional<E1AP_IEs::NR_CGI_Support_List> nR_CGI_Support_List;
    std::optional<E1AP_IEs::QoS_Parameters_Support_List> qoS_Parameters_Support_List;
    std::optional<E1AP_Containers::ProtocolExtensionContainer> iE_Extensions;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using SupportedPLMNs_List = std::vector<SupportedPLMNs_Item>;

struct GNB_CU_UP_E1SetupResponse {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_E1SetupFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_CP_E1SetupRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_CP_E1SetupResponse {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_CP_E1SetupFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_ConfigurationUpdate {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using GNB_CU_UP_TNLA_To_Remove_List = std::vector<E1AP_IEs::GNB_CU_UP_TNLA_To_Remove_Item>;

struct GNB_CU_UP_ConfigurationUpdateAcknowledge {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_ConfigurationUpdateFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_CP_ConfigurationUpdate {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using GNB_CU_CP_TNLA_To_Add_List = std::vector<E1AP_IEs::GNB_CU_CP_TNLA_To_Add_Item>;

using GNB_CU_CP_TNLA_To_Remove_List = std::vector<E1AP_IEs::GNB_CU_CP_TNLA_To_Remove_Item>;

using GNB_CU_CP_TNLA_To_Update_List = std::vector<E1AP_IEs::GNB_CU_CP_TNLA_To_Update_Item>;

struct GNB_CU_CP_ConfigurationUpdateAcknowledge {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using GNB_CU_CP_TNLA_Setup_List = std::vector<E1AP_IEs::GNB_CU_CP_TNLA_Setup_Item>;

using GNB_CU_CP_TNLA_Failed_To_Setup_List = std::vector<E1AP_IEs::GNB_CU_CP_TNLA_Failed_To_Setup_Item>;

struct GNB_CU_CP_ConfigurationUpdateFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct E1ReleaseRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct E1ReleaseResponse {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct BearerContextSetupRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextSetupRequest;
};
struct System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextSetupRequest;
};
struct System_BearerContextSetupRequest_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextSetupRequest = std::variant<
    System_BearerContextSetupRequest_e_UTRAN_BearerContextSetupRequest,
    System_BearerContextSetupRequest_nG_RAN_BearerContextSetupRequest,
    System_BearerContextSetupRequest_choice_extension
>;

struct BearerContextSetupResponse {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextSetupResponse;
};
struct System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextSetupResponse;
};
struct System_BearerContextSetupResponse_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextSetupResponse = std::variant<
    System_BearerContextSetupResponse_e_UTRAN_BearerContextSetupResponse,
    System_BearerContextSetupResponse_nG_RAN_BearerContextSetupResponse,
    System_BearerContextSetupResponse_choice_extension
>;

struct BearerContextSetupFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct BearerContextModificationRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextModificationRequest;
};
struct System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextModificationRequest;
};
struct System_BearerContextModificationRequest_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextModificationRequest = std::variant<
    System_BearerContextModificationRequest_e_UTRAN_BearerContextModificationRequest,
    System_BearerContextModificationRequest_nG_RAN_BearerContextModificationRequest,
    System_BearerContextModificationRequest_choice_extension
>;

struct BearerContextModificationResponse {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextModificationResponse;
};
struct System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextModificationResponse;
};
struct System_BearerContextModificationResponse_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextModificationResponse = std::variant<
    System_BearerContextModificationResponse_e_UTRAN_BearerContextModificationResponse,
    System_BearerContextModificationResponse_nG_RAN_BearerContextModificationResponse,
    System_BearerContextModificationResponse_choice_extension
>;

struct BearerContextModificationFailure {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct BearerContextModificationRequired {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextModificationRequired;
};
struct System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextModificationRequired;
};
struct System_BearerContextModificationRequired_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextModificationRequired = std::variant<
    System_BearerContextModificationRequired_e_UTRAN_BearerContextModificationRequired,
    System_BearerContextModificationRequired_nG_RAN_BearerContextModificationRequired,
    System_BearerContextModificationRequired_choice_extension
>;

struct BearerContextModificationConfirm {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_BearerContextModificationConfirm;
};
struct System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm {
    E1AP_Containers::ProtocolIE_Container nG_RAN_BearerContextModificationConfirm;
};
struct System_BearerContextModificationConfirm_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_BearerContextModificationConfirm = std::variant<
    System_BearerContextModificationConfirm_e_UTRAN_BearerContextModificationConfirm,
    System_BearerContextModificationConfirm_nG_RAN_BearerContextModificationConfirm,
    System_BearerContextModificationConfirm_choice_extension
>;

struct BearerContextReleaseCommand {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct BearerContextReleaseComplete {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct BearerContextReleaseRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

using DRB_Status_List = std::vector<E1AP_IEs::DRB_Status_Item>;

struct BearerContextInactivityNotification {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct DLDataNotification {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct ULDataNotification {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct DataUsageReport {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct GNB_CU_UP_CounterCheckRequest {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest {
    E1AP_Containers::ProtocolIE_Container e_UTRAN_GNB_CU_UP_CounterCheckRequest;
};
struct System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest {
    E1AP_Containers::ProtocolIE_Container nG_RAN_GNB_CU_UP_CounterCheckRequest;
};
struct System_GNB_CU_UP_CounterCheckRequest_choice_extension {
    E1AP_Containers::ProtocolIE_SingleContainer choice_extension;
};
using System_GNB_CU_UP_CounterCheckRequest = std::variant<
    System_GNB_CU_UP_CounterCheckRequest_e_UTRAN_GNB_CU_UP_CounterCheckRequest,
    System_GNB_CU_UP_CounterCheckRequest_nG_RAN_GNB_CU_UP_CounterCheckRequest,
    System_GNB_CU_UP_CounterCheckRequest_choice_extension
>;

struct GNB_CU_UP_StatusIndication {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct MRDC_DataUsageReport {
    E1AP_Containers::ProtocolIE_Container protocolIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

struct PrivateMessage {
    E1AP_Containers::PrivateIE_Container privateIEs;
    std::vector<asn1::runtime::BitString> unknown_extensions;
};

void encode_Reset(asn1::runtime::BitWriter& writer, const Reset& value);
Reset decode_Reset(asn1::runtime::BitReader& reader);
void encode_ResetAll(asn1::runtime::BitWriter& writer, const ResetAll& value);
ResetAll decode_ResetAll(asn1::runtime::BitReader& reader);
void encode_UE_associatedLogicalE1_ConnectionListRes(asn1::runtime::BitWriter& writer, const UE_associatedLogicalE1_ConnectionListRes& value);
UE_associatedLogicalE1_ConnectionListRes decode_UE_associatedLogicalE1_ConnectionListRes(asn1::runtime::BitReader& reader);
void encode_ResetType(asn1::runtime::BitWriter& writer, const ResetType& value);
ResetType decode_ResetType(asn1::runtime::BitReader& reader);
void encode_ResetAcknowledge(asn1::runtime::BitWriter& writer, const ResetAcknowledge& value);
ResetAcknowledge decode_ResetAcknowledge(asn1::runtime::BitReader& reader);
void encode_UE_associatedLogicalE1_ConnectionListResAck(asn1::runtime::BitWriter& writer, const UE_associatedLogicalE1_ConnectionListResAck& value);
UE_associatedLogicalE1_ConnectionListResAck decode_UE_associatedLogicalE1_ConnectionListResAck(asn1::runtime::BitReader& reader);
void encode_ErrorIndication(asn1::runtime::BitWriter& writer, const ErrorIndication& value);
ErrorIndication decode_ErrorIndication(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_E1SetupRequest(asn1::runtime::BitWriter& writer, const GNB_CU_UP_E1SetupRequest& value);
GNB_CU_UP_E1SetupRequest decode_GNB_CU_UP_E1SetupRequest(asn1::runtime::BitReader& reader);
void encode_SupportedPLMNs_Item(asn1::runtime::BitWriter& writer, const SupportedPLMNs_Item& value);
SupportedPLMNs_Item decode_SupportedPLMNs_Item(asn1::runtime::BitReader& reader);
void encode_SupportedPLMNs_List(asn1::runtime::BitWriter& writer, const SupportedPLMNs_List& value);
SupportedPLMNs_List decode_SupportedPLMNs_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_E1SetupResponse(asn1::runtime::BitWriter& writer, const GNB_CU_UP_E1SetupResponse& value);
GNB_CU_UP_E1SetupResponse decode_GNB_CU_UP_E1SetupResponse(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_E1SetupFailure(asn1::runtime::BitWriter& writer, const GNB_CU_UP_E1SetupFailure& value);
GNB_CU_UP_E1SetupFailure decode_GNB_CU_UP_E1SetupFailure(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_E1SetupRequest(asn1::runtime::BitWriter& writer, const GNB_CU_CP_E1SetupRequest& value);
GNB_CU_CP_E1SetupRequest decode_GNB_CU_CP_E1SetupRequest(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_E1SetupResponse(asn1::runtime::BitWriter& writer, const GNB_CU_CP_E1SetupResponse& value);
GNB_CU_CP_E1SetupResponse decode_GNB_CU_CP_E1SetupResponse(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_E1SetupFailure(asn1::runtime::BitWriter& writer, const GNB_CU_CP_E1SetupFailure& value);
GNB_CU_CP_E1SetupFailure decode_GNB_CU_CP_E1SetupFailure(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_ConfigurationUpdate(asn1::runtime::BitWriter& writer, const GNB_CU_UP_ConfigurationUpdate& value);
GNB_CU_UP_ConfigurationUpdate decode_GNB_CU_UP_ConfigurationUpdate(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_TNLA_To_Remove_List(asn1::runtime::BitWriter& writer, const GNB_CU_UP_TNLA_To_Remove_List& value);
GNB_CU_UP_TNLA_To_Remove_List decode_GNB_CU_UP_TNLA_To_Remove_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_ConfigurationUpdateAcknowledge(asn1::runtime::BitWriter& writer, const GNB_CU_UP_ConfigurationUpdateAcknowledge& value);
GNB_CU_UP_ConfigurationUpdateAcknowledge decode_GNB_CU_UP_ConfigurationUpdateAcknowledge(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_ConfigurationUpdateFailure(asn1::runtime::BitWriter& writer, const GNB_CU_UP_ConfigurationUpdateFailure& value);
GNB_CU_UP_ConfigurationUpdateFailure decode_GNB_CU_UP_ConfigurationUpdateFailure(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_ConfigurationUpdate(asn1::runtime::BitWriter& writer, const GNB_CU_CP_ConfigurationUpdate& value);
GNB_CU_CP_ConfigurationUpdate decode_GNB_CU_CP_ConfigurationUpdate(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Add_List(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Add_List& value);
GNB_CU_CP_TNLA_To_Add_List decode_GNB_CU_CP_TNLA_To_Add_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Remove_List(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Remove_List& value);
GNB_CU_CP_TNLA_To_Remove_List decode_GNB_CU_CP_TNLA_To_Remove_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_To_Update_List(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_To_Update_List& value);
GNB_CU_CP_TNLA_To_Update_List decode_GNB_CU_CP_TNLA_To_Update_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_ConfigurationUpdateAcknowledge(asn1::runtime::BitWriter& writer, const GNB_CU_CP_ConfigurationUpdateAcknowledge& value);
GNB_CU_CP_ConfigurationUpdateAcknowledge decode_GNB_CU_CP_ConfigurationUpdateAcknowledge(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_Setup_List(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_Setup_List& value);
GNB_CU_CP_TNLA_Setup_List decode_GNB_CU_CP_TNLA_Setup_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_TNLA_Failed_To_Setup_List(asn1::runtime::BitWriter& writer, const GNB_CU_CP_TNLA_Failed_To_Setup_List& value);
GNB_CU_CP_TNLA_Failed_To_Setup_List decode_GNB_CU_CP_TNLA_Failed_To_Setup_List(asn1::runtime::BitReader& reader);
void encode_GNB_CU_CP_ConfigurationUpdateFailure(asn1::runtime::BitWriter& writer, const GNB_CU_CP_ConfigurationUpdateFailure& value);
GNB_CU_CP_ConfigurationUpdateFailure decode_GNB_CU_CP_ConfigurationUpdateFailure(asn1::runtime::BitReader& reader);
void encode_E1ReleaseRequest(asn1::runtime::BitWriter& writer, const E1ReleaseRequest& value);
E1ReleaseRequest decode_E1ReleaseRequest(asn1::runtime::BitReader& reader);
void encode_E1ReleaseResponse(asn1::runtime::BitWriter& writer, const E1ReleaseResponse& value);
E1ReleaseResponse decode_E1ReleaseResponse(asn1::runtime::BitReader& reader);
void encode_BearerContextSetupRequest(asn1::runtime::BitWriter& writer, const BearerContextSetupRequest& value);
BearerContextSetupRequest decode_BearerContextSetupRequest(asn1::runtime::BitReader& reader);
void encode_System_BearerContextSetupRequest(asn1::runtime::BitWriter& writer, const System_BearerContextSetupRequest& value);
System_BearerContextSetupRequest decode_System_BearerContextSetupRequest(asn1::runtime::BitReader& reader);
void encode_BearerContextSetupResponse(asn1::runtime::BitWriter& writer, const BearerContextSetupResponse& value);
BearerContextSetupResponse decode_BearerContextSetupResponse(asn1::runtime::BitReader& reader);
void encode_System_BearerContextSetupResponse(asn1::runtime::BitWriter& writer, const System_BearerContextSetupResponse& value);
System_BearerContextSetupResponse decode_System_BearerContextSetupResponse(asn1::runtime::BitReader& reader);
void encode_BearerContextSetupFailure(asn1::runtime::BitWriter& writer, const BearerContextSetupFailure& value);
BearerContextSetupFailure decode_BearerContextSetupFailure(asn1::runtime::BitReader& reader);
void encode_BearerContextModificationRequest(asn1::runtime::BitWriter& writer, const BearerContextModificationRequest& value);
BearerContextModificationRequest decode_BearerContextModificationRequest(asn1::runtime::BitReader& reader);
void encode_System_BearerContextModificationRequest(asn1::runtime::BitWriter& writer, const System_BearerContextModificationRequest& value);
System_BearerContextModificationRequest decode_System_BearerContextModificationRequest(asn1::runtime::BitReader& reader);
void encode_BearerContextModificationResponse(asn1::runtime::BitWriter& writer, const BearerContextModificationResponse& value);
BearerContextModificationResponse decode_BearerContextModificationResponse(asn1::runtime::BitReader& reader);
void encode_System_BearerContextModificationResponse(asn1::runtime::BitWriter& writer, const System_BearerContextModificationResponse& value);
System_BearerContextModificationResponse decode_System_BearerContextModificationResponse(asn1::runtime::BitReader& reader);
void encode_BearerContextModificationFailure(asn1::runtime::BitWriter& writer, const BearerContextModificationFailure& value);
BearerContextModificationFailure decode_BearerContextModificationFailure(asn1::runtime::BitReader& reader);
void encode_BearerContextModificationRequired(asn1::runtime::BitWriter& writer, const BearerContextModificationRequired& value);
BearerContextModificationRequired decode_BearerContextModificationRequired(asn1::runtime::BitReader& reader);
void encode_System_BearerContextModificationRequired(asn1::runtime::BitWriter& writer, const System_BearerContextModificationRequired& value);
System_BearerContextModificationRequired decode_System_BearerContextModificationRequired(asn1::runtime::BitReader& reader);
void encode_BearerContextModificationConfirm(asn1::runtime::BitWriter& writer, const BearerContextModificationConfirm& value);
BearerContextModificationConfirm decode_BearerContextModificationConfirm(asn1::runtime::BitReader& reader);
void encode_System_BearerContextModificationConfirm(asn1::runtime::BitWriter& writer, const System_BearerContextModificationConfirm& value);
System_BearerContextModificationConfirm decode_System_BearerContextModificationConfirm(asn1::runtime::BitReader& reader);
void encode_BearerContextReleaseCommand(asn1::runtime::BitWriter& writer, const BearerContextReleaseCommand& value);
BearerContextReleaseCommand decode_BearerContextReleaseCommand(asn1::runtime::BitReader& reader);
void encode_BearerContextReleaseComplete(asn1::runtime::BitWriter& writer, const BearerContextReleaseComplete& value);
BearerContextReleaseComplete decode_BearerContextReleaseComplete(asn1::runtime::BitReader& reader);
void encode_BearerContextReleaseRequest(asn1::runtime::BitWriter& writer, const BearerContextReleaseRequest& value);
BearerContextReleaseRequest decode_BearerContextReleaseRequest(asn1::runtime::BitReader& reader);
void encode_DRB_Status_List(asn1::runtime::BitWriter& writer, const DRB_Status_List& value);
DRB_Status_List decode_DRB_Status_List(asn1::runtime::BitReader& reader);
void encode_BearerContextInactivityNotification(asn1::runtime::BitWriter& writer, const BearerContextInactivityNotification& value);
BearerContextInactivityNotification decode_BearerContextInactivityNotification(asn1::runtime::BitReader& reader);
void encode_DLDataNotification(asn1::runtime::BitWriter& writer, const DLDataNotification& value);
DLDataNotification decode_DLDataNotification(asn1::runtime::BitReader& reader);
void encode_ULDataNotification(asn1::runtime::BitWriter& writer, const ULDataNotification& value);
ULDataNotification decode_ULDataNotification(asn1::runtime::BitReader& reader);
void encode_DataUsageReport(asn1::runtime::BitWriter& writer, const DataUsageReport& value);
DataUsageReport decode_DataUsageReport(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_CounterCheckRequest(asn1::runtime::BitWriter& writer, const GNB_CU_UP_CounterCheckRequest& value);
GNB_CU_UP_CounterCheckRequest decode_GNB_CU_UP_CounterCheckRequest(asn1::runtime::BitReader& reader);
void encode_System_GNB_CU_UP_CounterCheckRequest(asn1::runtime::BitWriter& writer, const System_GNB_CU_UP_CounterCheckRequest& value);
System_GNB_CU_UP_CounterCheckRequest decode_System_GNB_CU_UP_CounterCheckRequest(asn1::runtime::BitReader& reader);
void encode_GNB_CU_UP_StatusIndication(asn1::runtime::BitWriter& writer, const GNB_CU_UP_StatusIndication& value);
GNB_CU_UP_StatusIndication decode_GNB_CU_UP_StatusIndication(asn1::runtime::BitReader& reader);
void encode_MRDC_DataUsageReport(asn1::runtime::BitWriter& writer, const MRDC_DataUsageReport& value);
MRDC_DataUsageReport decode_MRDC_DataUsageReport(asn1::runtime::BitReader& reader);
void encode_PrivateMessage(asn1::runtime::BitWriter& writer, const PrivateMessage& value);
PrivateMessage decode_PrivateMessage(asn1::runtime::BitReader& reader);

} // namespace E1AP_PDU_Contents

namespace E1AP_PDU_Descriptions {

struct InitiatingMessage {
    E1AP_CommonDataTypes::ProcedureCode procedureCode;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any value;
};

struct SuccessfulOutcome {
    E1AP_CommonDataTypes::ProcedureCode procedureCode;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any value;
};

struct UnsuccessfulOutcome {
    E1AP_CommonDataTypes::ProcedureCode procedureCode;
    E1AP_CommonDataTypes::Criticality criticality;
    std::any value;
};

struct E1AP_PDU_initiatingMessage {
    InitiatingMessage initiatingMessage;
};
struct E1AP_PDU_successfulOutcome {
    SuccessfulOutcome successfulOutcome;
};
struct E1AP_PDU_unsuccessfulOutcome {
    UnsuccessfulOutcome unsuccessfulOutcome;
};
using E1AP_PDU = std::variant<
    E1AP_PDU_initiatingMessage,
    E1AP_PDU_successfulOutcome,
    E1AP_PDU_unsuccessfulOutcome,
    asn1::runtime::ExtensionValue
>;

void encode_InitiatingMessage(asn1::runtime::BitWriter& writer, const InitiatingMessage& value);
InitiatingMessage decode_InitiatingMessage(asn1::runtime::BitReader& reader);
void encode_SuccessfulOutcome(asn1::runtime::BitWriter& writer, const SuccessfulOutcome& value);
SuccessfulOutcome decode_SuccessfulOutcome(asn1::runtime::BitReader& reader);
void encode_UnsuccessfulOutcome(asn1::runtime::BitWriter& writer, const UnsuccessfulOutcome& value);
UnsuccessfulOutcome decode_UnsuccessfulOutcome(asn1::runtime::BitReader& reader);
void encode_E1AP_PDU(asn1::runtime::BitWriter& writer, const E1AP_PDU& value);
E1AP_PDU decode_E1AP_PDU(asn1::runtime::BitReader& reader);

} // namespace E1AP_PDU_Descriptions

} // namespace asn1::generated

#endif // ASN1_GENERATED_GENERATED_H
