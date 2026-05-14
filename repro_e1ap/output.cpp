#include "output.h"

#include <stdexcept>
#include <string>

#include "runtime/uper/UperLength.h"
#include "runtime/uper/UperInteger.h"
#include "runtime/uper/UperSequence.h"
#include "runtime/uper/UperChoice.h"
#include "runtime/uper/UperExtension.h"
#include "runtime/uper/UperObjectIdentifier.h"
#include "runtime/uper/UperReal.h"

using namespace asn1::runtime;

namespace asn1::generated {

namespace E1AP_CommonDataTypes {

// Encoder for Criticality
void encode_Criticality(BitWriter& writer, const Criticality& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case Criticality::reject: enum_index = 0; break;
            case Criticality::ignore: enum_index = 1; break;
            case Criticality::notify: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Criticality
Criticality decode_Criticality(BitReader& reader) {
    Criticality value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = Criticality::reject; break;
            case 1: value = Criticality::ignore; break;
            case 2: value = Criticality::notify; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Presence
void encode_Presence(BitWriter& writer, const Presence& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case Presence::optional: enum_index = 0; break;
            case Presence::conditional: enum_index = 1; break;
            case Presence::mandatory: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Presence
Presence decode_Presence(BitReader& reader) {
    Presence value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = Presence::optional; break;
            case 1: value = Presence::conditional; break;
            case 2: value = Presence::mandatory; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PrivateIE_ID
void encode_PrivateIE_ID(BitWriter& writer, const PrivateIE_ID& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 2);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                if (arg_1.local < 0LL || arg_1.local > 65535LL) {
                    throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(arg_1.local) + " out of range [0, 65535].");
                }
                UperInteger::encodeConstrainedInt(writer, arg_1.local, 0LL, 65535LL);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                UperObjectIdentifier::encode(writer, arg_1.global);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for PrivateIE_ID
PrivateIE_ID decode_PrivateIE_ID(BitReader& reader) {
    PrivateIE_ID value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 2);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.local = UperInteger::decodeConstrainedInt(reader, 0LL, 65535LL);
            if (it_1_0.local < 0LL || it_1_0.local > 65535LL) {
                throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(it_1_0.local) + " out of range [0, 65535].");
            }
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            UperObjectIdentifier::decode(reader, it_1_1.global);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for ProcedureCode
void encode_ProcedureCode(BitWriter& writer, const ProcedureCode& value) {
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 255].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 255LL);
}

// Decoder for ProcedureCode
ProcedureCode decode_ProcedureCode(BitReader& reader) {
    ProcedureCode value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 255].");
    }
    return value;
}

// Encoder for ProtocolExtensionID
void encode_ProtocolExtensionID(BitWriter& writer, const ProtocolExtensionID& value) {
    if (value < 0LL || value > 65535LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 65535].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 65535LL);
}

// Decoder for ProtocolExtensionID
ProtocolExtensionID decode_ProtocolExtensionID(BitReader& reader) {
    ProtocolExtensionID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 65535LL);
    if (value < 0LL || value > 65535LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 65535].");
    }
    return value;
}

// Encoder for ProtocolIE_ID
void encode_ProtocolIE_ID(BitWriter& writer, const ProtocolIE_ID& value) {
    if (value < 0LL || value > 65535LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 65535].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 65535LL);
}

// Decoder for ProtocolIE_ID
ProtocolIE_ID decode_ProtocolIE_ID(BitReader& reader) {
    ProtocolIE_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 65535LL);
    if (value < 0LL || value > 65535LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 65535].");
    }
    return value;
}

// Encoder for TriggeringMessage
void encode_TriggeringMessage(BitWriter& writer, const TriggeringMessage& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case TriggeringMessage::initiating_message: enum_index = 0; break;
            case TriggeringMessage::successful_outcome: enum_index = 1; break;
            case TriggeringMessage::unsuccessful_outcome: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for TriggeringMessage
TriggeringMessage decode_TriggeringMessage(BitReader& reader) {
    TriggeringMessage value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = TriggeringMessage::initiating_message; break;
            case 1: value = TriggeringMessage::successful_outcome; break;
            case 2: value = TriggeringMessage::unsuccessful_outcome; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

} // namespace E1AP_CommonDataTypes

namespace E1AP_Constants {

} // namespace E1AP_Constants

namespace E1AP_Containers {

// Encoder for ProtocolIE_Field
void encode_ProtocolIE_Field(BitWriter& writer, const ProtocolIE_Field& value) {
    {
        // TODO: encode value.id of type E1AP-PROTOCOL-IES
        // TODO: encode value.criticality of type E1AP-PROTOCOL-IES
        // TODO: encode value.value of type E1AP-PROTOCOL-IES
    }
}

// Decoder for ProtocolIE_Field
ProtocolIE_Field decode_ProtocolIE_Field(BitReader& reader) {
    ProtocolIE_Field value{};
    value.id = (int64_t)reader.readBits(16);
    value.criticality = (int64_t)reader.readBits(2);
    value.value = UperExtension::decodeOpenType(reader);
    return value;
}
    }
    return value;
}

// Encoder for ProtocolIE_Container
void encode_ProtocolIE_Container(BitWriter& writer, const ProtocolIE_Container& value) {
    if (value.size() > 65535) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [0, 65535].");
    }
    UperLength::encodeLength(writer, value.size(), 0, 65535);
    for (const auto& element : value) {
        // TODO: encode element of type ProtocolIE-Field
    }
}

// Decoder for ProtocolIE_Container
ProtocolIE_Container decode_ProtocolIE_Container(BitReader& reader) {
    ProtocolIE_Container value{};
    {
        size_t length = UperLength::decodeLength(reader, 0, 65535);
        if (length > 65535) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [0, 65535].");
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_ProtocolIE_Field(reader);
        }
            // TODO: decode value[i] of type ProtocolIE-Field
        }
    }
    return value;
}

// Encoder for ProtocolIE_SingleContainer
void encode_ProtocolIE_SingleContainer(BitWriter& writer, const ProtocolIE_SingleContainer& value) {
    // TODO: Implement encoding for type ProtocolIE-Field
}

// Decoder for ProtocolIE_SingleContainer
ProtocolIE_SingleContainer decode_ProtocolIE_SingleContainer(BitReader& reader) {
    ProtocolIE_SingleContainer value{};
    // TODO: Implement decoding for type ProtocolIE-Field
    return value;
}

// Encoder for ProtocolIE_ContainerList
void encode_ProtocolIE_ContainerList(BitWriter& writer, const ProtocolIE_ContainerList& value) {
    UperLength::encodeUnconstrainedLength(writer, value.size());
    for (const auto& element : value) {
        // TODO: encode element of type ProtocolIE-Container
    }
}

// Decoder for ProtocolIE_ContainerList
ProtocolIE_ContainerList decode_ProtocolIE_ContainerList(BitReader& reader) {
    ProtocolIE_ContainerList value{};
    {
        size_t length = UperLength::decodeUnconstrainedLength(reader);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            // TODO: decode value[i] of type ProtocolIE-Container
        }
    }
    return value;
}

// Encoder for ProtocolExtensionField
void encode_ProtocolExtensionField(BitWriter& writer, const ProtocolExtensionField& value) {
    {
        // TODO: encode value.id of type E1AP-PROTOCOL-EXTENSION
        // TODO: encode value.criticality of type E1AP-PROTOCOL-EXTENSION
        // TODO: encode value.extensionValue of type E1AP-PROTOCOL-EXTENSION
    }
}

// Decoder for ProtocolExtensionField
ProtocolExtensionField decode_ProtocolExtensionField(BitReader& reader) {
    ProtocolExtensionField value{};
    {
        // TODO: decode value.id of type E1AP-PROTOCOL-EXTENSION
        // TODO: decode value.criticality of type E1AP-PROTOCOL-EXTENSION
        // TODO: decode value.extensionValue of type E1AP-PROTOCOL-EXTENSION
    }
    return value;
}

// Encoder for ProtocolExtensionContainer
void encode_ProtocolExtensionContainer(BitWriter& writer, const ProtocolExtensionContainer& value) {
    if (value.size() < 1 || value.size() > 65535) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 65535].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 65535);
    for (const auto& element : value) {
        // TODO: encode element of type ProtocolExtensionField
    }
}

// Decoder for ProtocolExtensionContainer
ProtocolExtensionContainer decode_ProtocolExtensionContainer(BitReader& reader) {
    ProtocolExtensionContainer value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 65535);
        if (length < 1 || length > 65535) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 65535].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            // TODO: decode value[i] of type ProtocolExtensionField
        }
    }
    return value;
}

// Encoder for PrivateIE_Field
void encode_PrivateIE_Field(BitWriter& writer, const PrivateIE_Field& value) {
    {
        // TODO: encode value.id of type E1AP-PRIVATE-IES
        // TODO: encode value.criticality of type E1AP-PRIVATE-IES
        // TODO: encode value.value of type E1AP-PRIVATE-IES
    }
}

// Decoder for PrivateIE_Field
PrivateIE_Field decode_PrivateIE_Field(BitReader& reader) {
    PrivateIE_Field value{};
    {
        // TODO: decode value.id of type E1AP-PRIVATE-IES
        // TODO: decode value.criticality of type E1AP-PRIVATE-IES
        // TODO: decode value.value of type E1AP-PRIVATE-IES
    }
    return value;
}

// Encoder for PrivateIE_Container
void encode_PrivateIE_Container(BitWriter& writer, const PrivateIE_Container& value) {
    if (value.size() < 1 || value.size() > 65535) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 65535].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 65535);
    for (const auto& element : value) {
        // TODO: encode element of type PrivateIE-Field
    }
}

// Decoder for PrivateIE_Container
PrivateIE_Container decode_PrivateIE_Container(BitReader& reader) {
    PrivateIE_Container value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 65535);
        if (length < 1 || length > 65535) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 65535].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            // TODO: decode value[i] of type PrivateIE-Field
        }
    }
    return value;
}

} // namespace E1AP_Containers

namespace E1AP_IEs {

// Encoder for ActivityNotificationLevel
void encode_ActivityNotificationLevel(BitWriter& writer, const ActivityNotificationLevel& value) {
    bool is_extended = true;
    switch (value) {
        case ActivityNotificationLevel::drb: is_extended = false; break;
        case ActivityNotificationLevel::pdu_session: is_extended = false; break;
        case ActivityNotificationLevel::ue: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case ActivityNotificationLevel::drb: enum_index = 0; break;
            case ActivityNotificationLevel::pdu_session: enum_index = 1; break;
            case ActivityNotificationLevel::ue: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for ActivityNotificationLevel
ActivityNotificationLevel decode_ActivityNotificationLevel(BitReader& reader) {
    ActivityNotificationLevel value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = ActivityNotificationLevel::drb; break;
            case 1: value = ActivityNotificationLevel::pdu_session; break;
            case 2: value = ActivityNotificationLevel::ue; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for AveragingWindow
void encode_AveragingWindow(BitWriter& writer, const AveragingWindow& value) {
    if (value < 0LL || value > 4095LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4095].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4095LL);
}

// Decoder for AveragingWindow
AveragingWindow decode_AveragingWindow(BitReader& reader) {
    AveragingWindow value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4095LL);
    if (value < 0LL || value > 4095LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4095].");
    }
    return value;
}

// Encoder for BearerContextStatusChange
void encode_BearerContextStatusChange(BitWriter& writer, const BearerContextStatusChange& value) {
    bool is_extended = true;
    switch (value) {
        case BearerContextStatusChange::suspend: is_extended = false; break;
        case BearerContextStatusChange::resume: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case BearerContextStatusChange::suspend: enum_index = 0; break;
            case BearerContextStatusChange::resume: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for BearerContextStatusChange
BearerContextStatusChange decode_BearerContextStatusChange(BitReader& reader) {
    BearerContextStatusChange value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = BearerContextStatusChange::suspend; break;
            case 1: value = BearerContextStatusChange::resume; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for BitRate
void encode_BitRate(BitWriter& writer, const BitRate& value) {
    if (value < 0LL || value > 4000000000000LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4000000000000].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4000000000000LL);
}

// Decoder for BitRate
BitRate decode_BitRate(BitReader& reader) {
    BitRate value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4000000000000LL);
    if (value < 0LL || value > 4000000000000LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4000000000000].");
    }
    return value;
}

// Encoder for CauseMisc
void encode_CauseMisc(BitWriter& writer, const CauseMisc& value) {
    bool is_extended = true;
    switch (value) {
        case CauseMisc::control_processing_overload: is_extended = false; break;
        case CauseMisc::not_enough_user_plane_processing_resources: is_extended = false; break;
        case CauseMisc::hardware_failure: is_extended = false; break;
        case CauseMisc::om_intervention: is_extended = false; break;
        case CauseMisc::unspecified: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CauseMisc::control_processing_overload: enum_index = 0; break;
            case CauseMisc::not_enough_user_plane_processing_resources: enum_index = 1; break;
            case CauseMisc::hardware_failure: enum_index = 2; break;
            case CauseMisc::om_intervention: enum_index = 3; break;
            case CauseMisc::unspecified: enum_index = 4; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 5);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CauseMisc
CauseMisc decode_CauseMisc(BitReader& reader) {
    CauseMisc value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 5);
        switch (enum_index) {
            case 0: value = CauseMisc::control_processing_overload; break;
            case 1: value = CauseMisc::not_enough_user_plane_processing_resources; break;
            case 2: value = CauseMisc::hardware_failure; break;
            case 3: value = CauseMisc::om_intervention; break;
            case 4: value = CauseMisc::unspecified; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CauseProtocol
void encode_CauseProtocol(BitWriter& writer, const CauseProtocol& value) {
    bool is_extended = true;
    switch (value) {
        case CauseProtocol::transfer_syntax_error: is_extended = false; break;
        case CauseProtocol::abstract_syntax_error_reject: is_extended = false; break;
        case CauseProtocol::abstract_syntax_error_ignore_and_notify: is_extended = false; break;
        case CauseProtocol::message_not_compatible_with_receiver_state: is_extended = false; break;
        case CauseProtocol::semantic_error: is_extended = false; break;
        case CauseProtocol::abstract_syntax_error_falsely_constructed_message: is_extended = false; break;
        case CauseProtocol::unspecified: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CauseProtocol::transfer_syntax_error: enum_index = 0; break;
            case CauseProtocol::abstract_syntax_error_reject: enum_index = 1; break;
            case CauseProtocol::abstract_syntax_error_ignore_and_notify: enum_index = 2; break;
            case CauseProtocol::message_not_compatible_with_receiver_state: enum_index = 3; break;
            case CauseProtocol::semantic_error: enum_index = 4; break;
            case CauseProtocol::abstract_syntax_error_falsely_constructed_message: enum_index = 5; break;
            case CauseProtocol::unspecified: enum_index = 6; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 7);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CauseProtocol
CauseProtocol decode_CauseProtocol(BitReader& reader) {
    CauseProtocol value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 7);
        switch (enum_index) {
            case 0: value = CauseProtocol::transfer_syntax_error; break;
            case 1: value = CauseProtocol::abstract_syntax_error_reject; break;
            case 2: value = CauseProtocol::abstract_syntax_error_ignore_and_notify; break;
            case 3: value = CauseProtocol::message_not_compatible_with_receiver_state; break;
            case 4: value = CauseProtocol::semantic_error; break;
            case 5: value = CauseProtocol::abstract_syntax_error_falsely_constructed_message; break;
            case 6: value = CauseProtocol::unspecified; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CauseRadioNetwork
void encode_CauseRadioNetwork(BitWriter& writer, const CauseRadioNetwork& value) {
    bool is_extended = true;
    switch (value) {
        case CauseRadioNetwork::unspecified: is_extended = false; break;
        case CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id: is_extended = false; break;
        case CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id: is_extended = false; break;
        case CauseRadioNetwork::unknown_or_inconsistent_pair_of_ue_e1ap_id: is_extended = false; break;
        case CauseRadioNetwork::interaction_with_other_procedure: is_extended = false; break;
        case CauseRadioNetwork::pPDCP_Count_wrap_around: is_extended = false; break;
        case CauseRadioNetwork::not_supported_QCI_value: is_extended = false; break;
        case CauseRadioNetwork::not_supported_5QI_value: is_extended = false; break;
        case CauseRadioNetwork::encryption_algorithms_not_supported: is_extended = false; break;
        case CauseRadioNetwork::integrity_protection_algorithms_not_supported: is_extended = false; break;
        case CauseRadioNetwork::uP_integrity_protection_not_possible: is_extended = false; break;
        case CauseRadioNetwork::uP_confidentiality_protection_not_possible: is_extended = false; break;
        case CauseRadioNetwork::multiple_PDU_Session_ID_Instances: is_extended = false; break;
        case CauseRadioNetwork::unknown_PDU_Session_ID: is_extended = false; break;
        case CauseRadioNetwork::multiple_QoS_Flow_ID_Instances: is_extended = false; break;
        case CauseRadioNetwork::unknown_QoS_Flow_ID: is_extended = false; break;
        case CauseRadioNetwork::multiple_DRB_ID_Instances: is_extended = false; break;
        case CauseRadioNetwork::unknown_DRB_ID: is_extended = false; break;
        case CauseRadioNetwork::invalid_QoS_combination: is_extended = false; break;
        case CauseRadioNetwork::procedure_cancelled: is_extended = false; break;
        case CauseRadioNetwork::normal_release: is_extended = false; break;
        case CauseRadioNetwork::no_radio_resources_available: is_extended = false; break;
        case CauseRadioNetwork::action_desirable_for_radio_reasons: is_extended = false; break;
        case CauseRadioNetwork::resources_not_available_for_the_slice: is_extended = false; break;
        case CauseRadioNetwork::pDCP_configuration_not_supported: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CauseRadioNetwork::unspecified: enum_index = 0; break;
            case CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id: enum_index = 1; break;
            case CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id: enum_index = 2; break;
            case CauseRadioNetwork::unknown_or_inconsistent_pair_of_ue_e1ap_id: enum_index = 3; break;
            case CauseRadioNetwork::interaction_with_other_procedure: enum_index = 4; break;
            case CauseRadioNetwork::pPDCP_Count_wrap_around: enum_index = 5; break;
            case CauseRadioNetwork::not_supported_QCI_value: enum_index = 6; break;
            case CauseRadioNetwork::not_supported_5QI_value: enum_index = 7; break;
            case CauseRadioNetwork::encryption_algorithms_not_supported: enum_index = 8; break;
            case CauseRadioNetwork::integrity_protection_algorithms_not_supported: enum_index = 9; break;
            case CauseRadioNetwork::uP_integrity_protection_not_possible: enum_index = 10; break;
            case CauseRadioNetwork::uP_confidentiality_protection_not_possible: enum_index = 11; break;
            case CauseRadioNetwork::multiple_PDU_Session_ID_Instances: enum_index = 12; break;
            case CauseRadioNetwork::unknown_PDU_Session_ID: enum_index = 13; break;
            case CauseRadioNetwork::multiple_QoS_Flow_ID_Instances: enum_index = 14; break;
            case CauseRadioNetwork::unknown_QoS_Flow_ID: enum_index = 15; break;
            case CauseRadioNetwork::multiple_DRB_ID_Instances: enum_index = 16; break;
            case CauseRadioNetwork::unknown_DRB_ID: enum_index = 17; break;
            case CauseRadioNetwork::invalid_QoS_combination: enum_index = 18; break;
            case CauseRadioNetwork::procedure_cancelled: enum_index = 19; break;
            case CauseRadioNetwork::normal_release: enum_index = 20; break;
            case CauseRadioNetwork::no_radio_resources_available: enum_index = 21; break;
            case CauseRadioNetwork::action_desirable_for_radio_reasons: enum_index = 22; break;
            case CauseRadioNetwork::resources_not_available_for_the_slice: enum_index = 23; break;
            case CauseRadioNetwork::pDCP_configuration_not_supported: enum_index = 24; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 25);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CauseRadioNetwork
CauseRadioNetwork decode_CauseRadioNetwork(BitReader& reader) {
    CauseRadioNetwork value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 25);
        switch (enum_index) {
            case 0: value = CauseRadioNetwork::unspecified; break;
            case 1: value = CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_cp_ue_e1ap_id; break;
            case 2: value = CauseRadioNetwork::unknown_or_already_allocated_gnb_cu_up_ue_e1ap_id; break;
            case 3: value = CauseRadioNetwork::unknown_or_inconsistent_pair_of_ue_e1ap_id; break;
            case 4: value = CauseRadioNetwork::interaction_with_other_procedure; break;
            case 5: value = CauseRadioNetwork::pPDCP_Count_wrap_around; break;
            case 6: value = CauseRadioNetwork::not_supported_QCI_value; break;
            case 7: value = CauseRadioNetwork::not_supported_5QI_value; break;
            case 8: value = CauseRadioNetwork::encryption_algorithms_not_supported; break;
            case 9: value = CauseRadioNetwork::integrity_protection_algorithms_not_supported; break;
            case 10: value = CauseRadioNetwork::uP_integrity_protection_not_possible; break;
            case 11: value = CauseRadioNetwork::uP_confidentiality_protection_not_possible; break;
            case 12: value = CauseRadioNetwork::multiple_PDU_Session_ID_Instances; break;
            case 13: value = CauseRadioNetwork::unknown_PDU_Session_ID; break;
            case 14: value = CauseRadioNetwork::multiple_QoS_Flow_ID_Instances; break;
            case 15: value = CauseRadioNetwork::unknown_QoS_Flow_ID; break;
            case 16: value = CauseRadioNetwork::multiple_DRB_ID_Instances; break;
            case 17: value = CauseRadioNetwork::unknown_DRB_ID; break;
            case 18: value = CauseRadioNetwork::invalid_QoS_combination; break;
            case 19: value = CauseRadioNetwork::procedure_cancelled; break;
            case 20: value = CauseRadioNetwork::normal_release; break;
            case 21: value = CauseRadioNetwork::no_radio_resources_available; break;
            case 22: value = CauseRadioNetwork::action_desirable_for_radio_reasons; break;
            case 23: value = CauseRadioNetwork::resources_not_available_for_the_slice; break;
            case 24: value = CauseRadioNetwork::pDCP_configuration_not_supported; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CauseTransport
void encode_CauseTransport(BitWriter& writer, const CauseTransport& value) {
    bool is_extended = true;
    switch (value) {
        case CauseTransport::unspecified: is_extended = false; break;
        case CauseTransport::transport_resource_unavailable: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CauseTransport::unspecified: enum_index = 0; break;
            case CauseTransport::transport_resource_unavailable: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CauseTransport
CauseTransport decode_CauseTransport(BitReader& reader) {
    CauseTransport value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = CauseTransport::unspecified; break;
            case 1: value = CauseTransport::transport_resource_unavailable; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Cause
void encode_Cause(BitWriter& writer, const Cause& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 5);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_CauseRadioNetwork(writer, arg_1.radioNetwork);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_CauseTransport(writer, arg_1.transport);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                encode_CauseProtocol(writer, arg_1.protocol);
            }
            using WrapperType3 = std::variant_alternative_t<3, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType3>) {
                encode_CauseMisc(writer, arg_1.misc);
            }
            using WrapperType4 = std::variant_alternative_t<4, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType4>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for Cause
Cause decode_Cause(BitReader& reader) {
    Cause value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 5);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.radioNetwork = decode_CauseRadioNetwork(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.transport = decode_CauseTransport(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.protocol = decode_CauseProtocol(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        case 3: {
            using WrapperType = std::variant_alternative_t<3, std::decay_t<decltype(value)>>;
            WrapperType it_1_3;
            it_1_3.misc = decode_CauseMisc(reader);
            value.emplace<WrapperType>(it_1_3);
            break;
        }
        case 4: {
            using WrapperType = std::variant_alternative_t<4, std::decay_t<decltype(value)>>;
            WrapperType it_1_4;
            it_1_4.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_4);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for Cell_Group_ID
void encode_Cell_Group_ID(BitWriter& writer, const Cell_Group_ID& value) {
    if (value < 0LL || value > 3LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 3].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 3LL);
}

// Decoder for Cell_Group_ID
Cell_Group_ID decode_Cell_Group_ID(BitReader& reader) {
    Cell_Group_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 3LL);
    if (value < 0LL || value > 3LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 3].");
    }
    return value;
}

// Encoder for CipheringAlgorithm
void encode_CipheringAlgorithm(BitWriter& writer, const CipheringAlgorithm& value) {
    bool is_extended = true;
    switch (value) {
        case CipheringAlgorithm::nEA0: is_extended = false; break;
        case CipheringAlgorithm::c_128_NEA1: is_extended = false; break;
        case CipheringAlgorithm::c_128_NEA2: is_extended = false; break;
        case CipheringAlgorithm::c_128_NEA3: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CipheringAlgorithm::nEA0: enum_index = 0; break;
            case CipheringAlgorithm::c_128_NEA1: enum_index = 1; break;
            case CipheringAlgorithm::c_128_NEA2: enum_index = 2; break;
            case CipheringAlgorithm::c_128_NEA3: enum_index = 3; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 4);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CipheringAlgorithm
CipheringAlgorithm decode_CipheringAlgorithm(BitReader& reader) {
    CipheringAlgorithm value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 4);
        switch (enum_index) {
            case 0: value = CipheringAlgorithm::nEA0; break;
            case 1: value = CipheringAlgorithm::c_128_NEA1; break;
            case 2: value = CipheringAlgorithm::c_128_NEA2; break;
            case 3: value = CipheringAlgorithm::c_128_NEA3; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CNSupport
void encode_CNSupport(BitWriter& writer, const CNSupport& value) {
    bool is_extended = true;
    switch (value) {
        case CNSupport::c_epc: is_extended = false; break;
        case CNSupport::c_5gc: is_extended = false; break;
        case CNSupport::both: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case CNSupport::c_epc: enum_index = 0; break;
            case CNSupport::c_5gc: enum_index = 1; break;
            case CNSupport::both: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for CNSupport
CNSupport decode_CNSupport(BitReader& reader) {
    CNSupport value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = CNSupport::c_epc; break;
            case 1: value = CNSupport::c_5gc; break;
            case 2: value = CNSupport::both; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CommonNetworkInstance
void encode_CommonNetworkInstance(BitWriter& writer, const CommonNetworkInstance& value) {
    UperLength::encodeUnconstrainedLength(writer, value.size());
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for CommonNetworkInstance
CommonNetworkInstance decode_CommonNetworkInstance(BitReader& reader) {
    CommonNetworkInstance value{};
    {
        size_t length = UperLength::decodeUnconstrainedLength(reader);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for ConfidentialityProtectionIndication
void encode_ConfidentialityProtectionIndication(BitWriter& writer, const ConfidentialityProtectionIndication& value) {
    bool is_extended = true;
    switch (value) {
        case ConfidentialityProtectionIndication::required: is_extended = false; break;
        case ConfidentialityProtectionIndication::preferred: is_extended = false; break;
        case ConfidentialityProtectionIndication::not_needed: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case ConfidentialityProtectionIndication::required: enum_index = 0; break;
            case ConfidentialityProtectionIndication::preferred: enum_index = 1; break;
            case ConfidentialityProtectionIndication::not_needed: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for ConfidentialityProtectionIndication
ConfidentialityProtectionIndication decode_ConfidentialityProtectionIndication(BitReader& reader) {
    ConfidentialityProtectionIndication value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = ConfidentialityProtectionIndication::required; break;
            case 1: value = ConfidentialityProtectionIndication::preferred; break;
            case 2: value = ConfidentialityProtectionIndication::not_needed; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for ConfidentialityProtectionResult
void encode_ConfidentialityProtectionResult(BitWriter& writer, const ConfidentialityProtectionResult& value) {
    bool is_extended = true;
    switch (value) {
        case ConfidentialityProtectionResult::performed: is_extended = false; break;
        case ConfidentialityProtectionResult::not_performed: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case ConfidentialityProtectionResult::performed: enum_index = 0; break;
            case ConfidentialityProtectionResult::not_performed: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for ConfidentialityProtectionResult
ConfidentialityProtectionResult decode_ConfidentialityProtectionResult(BitReader& reader) {
    ConfidentialityProtectionResult value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = ConfidentialityProtectionResult::performed; break;
            case 1: value = ConfidentialityProtectionResult::not_performed; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Data_Forwarding_Request
void encode_Data_Forwarding_Request(BitWriter& writer, const Data_Forwarding_Request& value) {
    bool is_extended = true;
    switch (value) {
        case Data_Forwarding_Request::uL: is_extended = false; break;
        case Data_Forwarding_Request::dL: is_extended = false; break;
        case Data_Forwarding_Request::both: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case Data_Forwarding_Request::uL: enum_index = 0; break;
            case Data_Forwarding_Request::dL: enum_index = 1; break;
            case Data_Forwarding_Request::both: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Data_Forwarding_Request
Data_Forwarding_Request decode_Data_Forwarding_Request(BitReader& reader) {
    Data_Forwarding_Request value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = Data_Forwarding_Request::uL; break;
            case 1: value = Data_Forwarding_Request::dL; break;
            case 2: value = Data_Forwarding_Request::both; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DefaultDRB
void encode_DefaultDRB(BitWriter& writer, const DefaultDRB& value) {
    bool is_extended = true;
    switch (value) {
        case DefaultDRB::true_: is_extended = false; break;
        case DefaultDRB::false_: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case DefaultDRB::true_: enum_index = 0; break;
            case DefaultDRB::false_: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for DefaultDRB
DefaultDRB decode_DefaultDRB(BitReader& reader) {
    DefaultDRB value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = DefaultDRB::true_; break;
            case 1: value = DefaultDRB::false_; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DiscardTimer
void encode_DiscardTimer(BitWriter& writer, const DiscardTimer& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case DiscardTimer::ms10: enum_index = 0; break;
            case DiscardTimer::ms20: enum_index = 1; break;
            case DiscardTimer::ms30: enum_index = 2; break;
            case DiscardTimer::ms40: enum_index = 3; break;
            case DiscardTimer::ms50: enum_index = 4; break;
            case DiscardTimer::ms60: enum_index = 5; break;
            case DiscardTimer::ms75: enum_index = 6; break;
            case DiscardTimer::ms100: enum_index = 7; break;
            case DiscardTimer::ms150: enum_index = 8; break;
            case DiscardTimer::ms200: enum_index = 9; break;
            case DiscardTimer::ms250: enum_index = 10; break;
            case DiscardTimer::ms300: enum_index = 11; break;
            case DiscardTimer::ms500: enum_index = 12; break;
            case DiscardTimer::ms750: enum_index = 13; break;
            case DiscardTimer::ms1500: enum_index = 14; break;
            case DiscardTimer::infinity: enum_index = 15; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 16);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for DiscardTimer
DiscardTimer decode_DiscardTimer(BitReader& reader) {
    DiscardTimer value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 16);
        switch (enum_index) {
            case 0: value = DiscardTimer::ms10; break;
            case 1: value = DiscardTimer::ms20; break;
            case 2: value = DiscardTimer::ms30; break;
            case 3: value = DiscardTimer::ms40; break;
            case 4: value = DiscardTimer::ms50; break;
            case 5: value = DiscardTimer::ms60; break;
            case 6: value = DiscardTimer::ms75; break;
            case 7: value = DiscardTimer::ms100; break;
            case 8: value = DiscardTimer::ms150; break;
            case 9: value = DiscardTimer::ms200; break;
            case 10: value = DiscardTimer::ms250; break;
            case 11: value = DiscardTimer::ms300; break;
            case 12: value = DiscardTimer::ms500; break;
            case 13: value = DiscardTimer::ms750; break;
            case 14: value = DiscardTimer::ms1500; break;
            case 15: value = DiscardTimer::infinity; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DL_TX_Stop
void encode_DL_TX_Stop(BitWriter& writer, const DL_TX_Stop& value) {
    bool is_extended = true;
    switch (value) {
        case DL_TX_Stop::stop: is_extended = false; break;
        case DL_TX_Stop::resume: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case DL_TX_Stop::stop: enum_index = 0; break;
            case DL_TX_Stop::resume: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for DL_TX_Stop
DL_TX_Stop decode_DL_TX_Stop(BitReader& reader) {
    DL_TX_Stop value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = DL_TX_Stop::stop; break;
            case 1: value = DL_TX_Stop::resume; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DRB_Activity
void encode_DRB_Activity(BitWriter& writer, const DRB_Activity& value) {
    bool is_extended = true;
    switch (value) {
        case DRB_Activity::active: is_extended = false; break;
        case DRB_Activity::not_active: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case DRB_Activity::active: enum_index = 0; break;
            case DRB_Activity::not_active: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for DRB_Activity
DRB_Activity decode_DRB_Activity(BitReader& reader) {
    DRB_Activity value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = DRB_Activity::active; break;
            case 1: value = DRB_Activity::not_active; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DRB_ID
void encode_DRB_ID(BitWriter& writer, const DRB_ID& value) {
    if (value < 1LL || value > 32LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [1, 32].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 1LL, 32LL);
}

// Decoder for DRB_ID
DRB_ID decode_DRB_ID(BitReader& reader) {
    DRB_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 1LL, 32LL);
    if (value < 1LL || value > 32LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [1, 32].");
    }
    return value;
}

// Encoder for DRB_Activity_Item
void encode_DRB_Activity_Item(BitWriter& writer, const DRB_Activity_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_DRB_Activity(writer, value.dRB_Activity);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Activity_Item
DRB_Activity_Item decode_DRB_Activity_Item(BitReader& reader) {
    DRB_Activity_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.dRB_Activity = decode_DRB_Activity(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Activity_List
void encode_DRB_Activity_List(BitWriter& writer, const DRB_Activity_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Activity_Item(writer, element);
    }
}

// Decoder for DRB_Activity_List
DRB_Activity_List decode_DRB_Activity_List(BitReader& reader) {
    DRB_Activity_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Activity_Item(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_Item_EUTRAN
void encode_DRB_Failed_Item_EUTRAN(BitWriter& writer, const DRB_Failed_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_Item_EUTRAN
DRB_Failed_Item_EUTRAN decode_DRB_Failed_Item_EUTRAN(BitReader& reader) {
    DRB_Failed_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_List_EUTRAN
void encode_DRB_Failed_List_EUTRAN(BitWriter& writer, const DRB_Failed_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Failed_List_EUTRAN
DRB_Failed_List_EUTRAN decode_DRB_Failed_List_EUTRAN(BitReader& reader) {
    DRB_Failed_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_Mod_Item_EUTRAN
void encode_DRB_Failed_Mod_Item_EUTRAN(BitWriter& writer, const DRB_Failed_Mod_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_Mod_Item_EUTRAN
DRB_Failed_Mod_Item_EUTRAN decode_DRB_Failed_Mod_Item_EUTRAN(BitReader& reader) {
    DRB_Failed_Mod_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_Mod_List_EUTRAN
void encode_DRB_Failed_Mod_List_EUTRAN(BitWriter& writer, const DRB_Failed_Mod_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_Mod_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Failed_Mod_List_EUTRAN
DRB_Failed_Mod_List_EUTRAN decode_DRB_Failed_Mod_List_EUTRAN(BitReader& reader) {
    DRB_Failed_Mod_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_Mod_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_Item_NG_RAN
void encode_DRB_Failed_Item_NG_RAN(BitWriter& writer, const DRB_Failed_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_Item_NG_RAN
DRB_Failed_Item_NG_RAN decode_DRB_Failed_Item_NG_RAN(BitReader& reader) {
    DRB_Failed_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_List_NG_RAN
void encode_DRB_Failed_List_NG_RAN(BitWriter& writer, const DRB_Failed_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Failed_List_NG_RAN
DRB_Failed_List_NG_RAN decode_DRB_Failed_List_NG_RAN(BitReader& reader) {
    DRB_Failed_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_Mod_Item_NG_RAN
void encode_DRB_Failed_Mod_Item_NG_RAN(BitWriter& writer, const DRB_Failed_Mod_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_Mod_Item_NG_RAN
DRB_Failed_Mod_Item_NG_RAN decode_DRB_Failed_Mod_Item_NG_RAN(BitReader& reader) {
    DRB_Failed_Mod_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_Mod_List_NG_RAN
void encode_DRB_Failed_Mod_List_NG_RAN(BitWriter& writer, const DRB_Failed_Mod_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_Mod_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Failed_Mod_List_NG_RAN
DRB_Failed_Mod_List_NG_RAN decode_DRB_Failed_Mod_List_NG_RAN(BitReader& reader) {
    DRB_Failed_Mod_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_Mod_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_To_Modify_Item_EUTRAN
void encode_DRB_Failed_To_Modify_Item_EUTRAN(BitWriter& writer, const DRB_Failed_To_Modify_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_To_Modify_Item_EUTRAN
DRB_Failed_To_Modify_Item_EUTRAN decode_DRB_Failed_To_Modify_Item_EUTRAN(BitReader& reader) {
    DRB_Failed_To_Modify_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_To_Modify_List_EUTRAN
void encode_DRB_Failed_To_Modify_List_EUTRAN(BitWriter& writer, const DRB_Failed_To_Modify_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_To_Modify_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Failed_To_Modify_List_EUTRAN
DRB_Failed_To_Modify_List_EUTRAN decode_DRB_Failed_To_Modify_List_EUTRAN(BitReader& reader) {
    DRB_Failed_To_Modify_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_To_Modify_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Failed_To_Modify_Item_NG_RAN
void encode_DRB_Failed_To_Modify_Item_NG_RAN(BitWriter& writer, const DRB_Failed_To_Modify_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Failed_To_Modify_Item_NG_RAN
DRB_Failed_To_Modify_Item_NG_RAN decode_DRB_Failed_To_Modify_Item_NG_RAN(BitReader& reader) {
    DRB_Failed_To_Modify_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Failed_To_Modify_List_NG_RAN
void encode_DRB_Failed_To_Modify_List_NG_RAN(BitWriter& writer, const DRB_Failed_To_Modify_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Failed_To_Modify_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Failed_To_Modify_List_NG_RAN
DRB_Failed_To_Modify_List_NG_RAN decode_DRB_Failed_To_Modify_List_NG_RAN(BitReader& reader) {
    DRB_Failed_To_Modify_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Failed_To_Modify_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Remove_Item_EUTRAN
void encode_DRB_To_Remove_Item_EUTRAN(BitWriter& writer, const DRB_To_Remove_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Remove_Item_EUTRAN
DRB_To_Remove_Item_EUTRAN decode_DRB_To_Remove_Item_EUTRAN(BitReader& reader) {
    DRB_To_Remove_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Remove_List_EUTRAN
void encode_DRB_To_Remove_List_EUTRAN(BitWriter& writer, const DRB_To_Remove_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Remove_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_To_Remove_List_EUTRAN
DRB_To_Remove_List_EUTRAN decode_DRB_To_Remove_List_EUTRAN(BitReader& reader) {
    DRB_To_Remove_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Remove_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Remove_Item_EUTRAN
void encode_DRB_Required_To_Remove_Item_EUTRAN(BitWriter& writer, const DRB_Required_To_Remove_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Required_To_Remove_Item_EUTRAN
DRB_Required_To_Remove_Item_EUTRAN decode_DRB_Required_To_Remove_Item_EUTRAN(BitReader& reader) {
    DRB_Required_To_Remove_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Remove_List_EUTRAN
void encode_DRB_Required_To_Remove_List_EUTRAN(BitWriter& writer, const DRB_Required_To_Remove_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Required_To_Remove_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Required_To_Remove_List_EUTRAN
DRB_Required_To_Remove_List_EUTRAN decode_DRB_Required_To_Remove_List_EUTRAN(BitReader& reader) {
    DRB_Required_To_Remove_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Required_To_Remove_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Remove_Item_NG_RAN
void encode_DRB_To_Remove_Item_NG_RAN(BitWriter& writer, const DRB_To_Remove_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Remove_Item_NG_RAN
DRB_To_Remove_Item_NG_RAN decode_DRB_To_Remove_Item_NG_RAN(BitReader& reader) {
    DRB_To_Remove_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Remove_List_NG_RAN
void encode_DRB_To_Remove_List_NG_RAN(BitWriter& writer, const DRB_To_Remove_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Remove_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_To_Remove_List_NG_RAN
DRB_To_Remove_List_NG_RAN decode_DRB_To_Remove_List_NG_RAN(BitReader& reader) {
    DRB_To_Remove_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Remove_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Remove_Item_NG_RAN
void encode_DRB_Required_To_Remove_Item_NG_RAN(BitWriter& writer, const DRB_Required_To_Remove_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Required_To_Remove_Item_NG_RAN
DRB_Required_To_Remove_Item_NG_RAN decode_DRB_Required_To_Remove_Item_NG_RAN(BitReader& reader) {
    DRB_Required_To_Remove_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Remove_List_NG_RAN
void encode_DRB_Required_To_Remove_List_NG_RAN(BitWriter& writer, const DRB_Required_To_Remove_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Required_To_Remove_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Required_To_Remove_List_NG_RAN
DRB_Required_To_Remove_List_NG_RAN decode_DRB_Required_To_Remove_List_NG_RAN(BitReader& reader) {
    DRB_Required_To_Remove_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Required_To_Remove_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Usage_Report_Item
void encode_DRB_Usage_Report_Item(BitWriter& writer, const DRB_Usage_Report_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        if (value.startTimeStamp.size() != 4) {
            throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.startTimeStamp.size()) + " != 4.");
        }
        UperLength::encodeLength(writer, value.startTimeStamp.size(), 4, 4);
        for (uint8_t byte : value.startTimeStamp) {
            writer.writeByte(byte);
        }
        if (value.endTimeStamp.size() != 4) {
            throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.endTimeStamp.size()) + " != 4.");
        }
        UperLength::encodeLength(writer, value.endTimeStamp.size(), 4, 4);
        for (uint8_t byte : value.endTimeStamp) {
            writer.writeByte(byte);
        }
        if (value.usageCountUL < 0LL || value.usageCountUL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.usageCountUL) + " out of range [0, 18446744073709].");
        }
        UperInteger::encodeConstrainedInt(writer, value.usageCountUL, 0LL, 18446744073709LL);
        if (value.usageCountDL < 0LL || value.usageCountDL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.usageCountDL) + " out of range [0, 18446744073709].");
        }
        UperInteger::encodeConstrainedInt(writer, value.usageCountDL, 0LL, 18446744073709LL);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Usage_Report_Item
DRB_Usage_Report_Item decode_DRB_Usage_Report_Item(BitReader& reader) {
    DRB_Usage_Report_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        {
            size_t length = UperLength::decodeLength(reader, 4, 4);
            value.startTimeStamp.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.startTimeStamp[i] = reader.readByte();
            }
        }
        {
            size_t length = UperLength::decodeLength(reader, 4, 4);
            value.endTimeStamp.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.endTimeStamp[i] = reader.readByte();
            }
        }
        value.usageCountUL = UperInteger::decodeConstrainedInt(reader, 0LL, 18446744073709LL);
        if (value.usageCountUL < 0LL || value.usageCountUL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.usageCountUL) + " out of range [0, 18446744073709].");
        }
        value.usageCountDL = UperInteger::decodeConstrainedInt(reader, 0LL, 18446744073709LL);
        if (value.usageCountDL < 0LL || value.usageCountDL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.usageCountDL) + " out of range [0, 18446744073709].");
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Usage_Report_List
void encode_DRB_Usage_Report_List(BitWriter& writer, const DRB_Usage_Report_List& value) {
    if (value.size() < 1 || value.size() > 2) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 2].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 2);
    for (const auto& element : value) {
        encode_DRB_Usage_Report_Item(writer, element);
    }
}

// Decoder for DRB_Usage_Report_List
DRB_Usage_Report_List decode_DRB_Usage_Report_List(BitReader& reader) {
    DRB_Usage_Report_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 2);
        if (length < 1 || length > 2) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 2].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Usage_Report_Item(reader);
        }
    }
    return value;
}

// Encoder for Duplication_Activation
void encode_Duplication_Activation(BitWriter& writer, const Duplication_Activation& value) {
    bool is_extended = true;
    switch (value) {
        case Duplication_Activation::active: is_extended = false; break;
        case Duplication_Activation::inactive: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case Duplication_Activation::active: enum_index = 0; break;
            case Duplication_Activation::inactive: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Duplication_Activation
Duplication_Activation decode_Duplication_Activation(BitReader& reader) {
    Duplication_Activation value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = Duplication_Activation::active; break;
            case 1: value = Duplication_Activation::inactive; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DataDiscardRequired
void encode_DataDiscardRequired(BitWriter& writer, const DataDiscardRequired& value) {
    bool is_extended = true;
    switch (value) {
        case DataDiscardRequired::required: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case DataDiscardRequired::required: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for DataDiscardRequired
DataDiscardRequired decode_DataDiscardRequired(BitReader& reader) {
    DataDiscardRequired value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = DataDiscardRequired::required; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for EncryptionKey
void encode_EncryptionKey(BitWriter& writer, const EncryptionKey& value) {
    UperLength::encodeUnconstrainedLength(writer, value.size());
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for EncryptionKey
EncryptionKey decode_EncryptionKey(BitReader& reader) {
    EncryptionKey value{};
    {
        size_t length = UperLength::decodeUnconstrainedLength(reader);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_Name
void encode_GNB_CU_CP_Name(BitWriter& writer, const GNB_CU_CP_Name& value) {
    if (value.size() < 1 || value.size() > 150) {
        throw std::runtime_error("String SIZE constraint violation: length " + std::to_string(value.size()) + " out of range [1, 150].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 150);
    writer.writeBytes(reinterpret_cast<const uint8_t*>(value.data()), value.size() * 8);
}

// Decoder for GNB_CU_CP_Name
GNB_CU_CP_Name decode_GNB_CU_CP_Name(BitReader& reader) {
    GNB_CU_CP_Name value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 150);
        if (length < 1 || length > 150) {
            throw std::runtime_error("String SIZE constraint violation: decoded length " + std::to_string(length) + " out of range [1, 150].");
        }
        value.resize(length);
        reader.readBytes(reinterpret_cast<uint8_t*>(value.data()), length * 8);
    }
    return value;
}

// Encoder for GNB_CU_CP_UE_E1AP_ID
void encode_GNB_CU_CP_UE_E1AP_ID(BitWriter& writer, const GNB_CU_CP_UE_E1AP_ID& value) {
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4294967295LL);
}

// Decoder for GNB_CU_CP_UE_E1AP_ID
GNB_CU_CP_UE_E1AP_ID decode_GNB_CU_CP_UE_E1AP_ID(BitReader& reader) {
    GNB_CU_CP_UE_E1AP_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4294967295LL);
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    return value;
}

// Encoder for GNB_CU_UP_Capacity
void encode_GNB_CU_UP_Capacity(BitWriter& writer, const GNB_CU_UP_Capacity& value) {
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 255].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 255LL);
}

// Decoder for GNB_CU_UP_Capacity
GNB_CU_UP_Capacity decode_GNB_CU_UP_Capacity(BitReader& reader) {
    GNB_CU_UP_Capacity value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 255].");
    }
    return value;
}

// Encoder for GNB_CU_UP_ID
void encode_GNB_CU_UP_ID(BitWriter& writer, const GNB_CU_UP_ID& value) {
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4294967295LL);
}

// Decoder for GNB_CU_UP_ID
GNB_CU_UP_ID decode_GNB_CU_UP_ID(BitReader& reader) {
    GNB_CU_UP_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4294967295LL);
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    return value;
}

// Encoder for GNB_CU_UP_Name
void encode_GNB_CU_UP_Name(BitWriter& writer, const GNB_CU_UP_Name& value) {
    if (value.size() < 1 || value.size() > 150) {
        throw std::runtime_error("String SIZE constraint violation: length " + std::to_string(value.size()) + " out of range [1, 150].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 150);
    writer.writeBytes(reinterpret_cast<const uint8_t*>(value.data()), value.size() * 8);
}

// Decoder for GNB_CU_UP_Name
GNB_CU_UP_Name decode_GNB_CU_UP_Name(BitReader& reader) {
    GNB_CU_UP_Name value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 150);
        if (length < 1 || length > 150) {
            throw std::runtime_error("String SIZE constraint violation: decoded length " + std::to_string(length) + " out of range [1, 150].");
        }
        value.resize(length);
        reader.readBytes(reinterpret_cast<uint8_t*>(value.data()), length * 8);
    }
    return value;
}

// Encoder for GNB_CU_UP_UE_E1AP_ID
void encode_GNB_CU_UP_UE_E1AP_ID(BitWriter& writer, const GNB_CU_UP_UE_E1AP_ID& value) {
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4294967295LL);
}

// Decoder for GNB_CU_UP_UE_E1AP_ID
GNB_CU_UP_UE_E1AP_ID decode_GNB_CU_UP_UE_E1AP_ID(BitReader& reader) {
    GNB_CU_UP_UE_E1AP_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4294967295LL);
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    return value;
}

// Encoder for GBR_QosInformation
void encode_GBR_QosInformation(BitWriter& writer, const GBR_QosInformation& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_BitRate(writer, value.e_RAB_MaximumBitrateDL);
        encode_BitRate(writer, value.e_RAB_MaximumBitrateUL);
        encode_BitRate(writer, value.e_RAB_GuaranteedBitrateDL);
        encode_BitRate(writer, value.e_RAB_GuaranteedBitrateUL);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GBR_QosInformation
GBR_QosInformation decode_GBR_QosInformation(BitReader& reader) {
    GBR_QosInformation value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.e_RAB_MaximumBitrateDL = decode_BitRate(reader);
        value.e_RAB_MaximumBitrateUL = decode_BitRate(reader);
        value.e_RAB_GuaranteedBitrateDL = decode_BitRate(reader);
        value.e_RAB_GuaranteedBitrateUL = decode_BitRate(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GTP_TEID
void encode_GTP_TEID(BitWriter& writer, const GTP_TEID& value) {
    if (value.size() != 4) {
        throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.size()) + " != 4.");
    }
    UperLength::encodeLength(writer, value.size(), 4, 4);
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for GTP_TEID
GTP_TEID decode_GTP_TEID(BitReader& reader) {
    GTP_TEID value{};
    {
        size_t length = UperLength::decodeLength(reader, 4, 4);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_OverloadInformation
void encode_GNB_CU_UP_OverloadInformation(BitWriter& writer, const GNB_CU_UP_OverloadInformation& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case GNB_CU_UP_OverloadInformation::overloaded: enum_index = 0; break;
            case GNB_CU_UP_OverloadInformation::not_overloaded: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for GNB_CU_UP_OverloadInformation
GNB_CU_UP_OverloadInformation decode_GNB_CU_UP_OverloadInformation(BitReader& reader) {
    GNB_CU_UP_OverloadInformation value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = GNB_CU_UP_OverloadInformation::overloaded; break;
            case 1: value = GNB_CU_UP_OverloadInformation::not_overloaded; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for GNB_DU_ID
void encode_GNB_DU_ID(BitWriter& writer, const GNB_DU_ID& value) {
    if (value < 0LL || value > 68719476735LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 68719476735].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 68719476735LL);
}

// Decoder for GNB_DU_ID
GNB_DU_ID decode_GNB_DU_ID(BitReader& reader) {
    GNB_DU_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 68719476735LL);
    if (value < 0LL || value > 68719476735LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 68719476735].");
    }
    return value;
}

// Encoder for HFN
void encode_HFN(BitWriter& writer, const HFN& value) {
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4294967295LL);
}

// Decoder for HFN
HFN decode_HFN(BitReader& reader) {
    HFN value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4294967295LL);
    if (value < 0LL || value > 4294967295LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4294967295].");
    }
    return value;
}

// Encoder for IntegrityProtectionIndication
void encode_IntegrityProtectionIndication(BitWriter& writer, const IntegrityProtectionIndication& value) {
    bool is_extended = true;
    switch (value) {
        case IntegrityProtectionIndication::required: is_extended = false; break;
        case IntegrityProtectionIndication::preferred: is_extended = false; break;
        case IntegrityProtectionIndication::not_needed: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case IntegrityProtectionIndication::required: enum_index = 0; break;
            case IntegrityProtectionIndication::preferred: enum_index = 1; break;
            case IntegrityProtectionIndication::not_needed: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for IntegrityProtectionIndication
IntegrityProtectionIndication decode_IntegrityProtectionIndication(BitReader& reader) {
    IntegrityProtectionIndication value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = IntegrityProtectionIndication::required; break;
            case 1: value = IntegrityProtectionIndication::preferred; break;
            case 2: value = IntegrityProtectionIndication::not_needed; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for IntegrityProtectionAlgorithm
void encode_IntegrityProtectionAlgorithm(BitWriter& writer, const IntegrityProtectionAlgorithm& value) {
    bool is_extended = true;
    switch (value) {
        case IntegrityProtectionAlgorithm::nIA0: is_extended = false; break;
        case IntegrityProtectionAlgorithm::i_128_NIA1: is_extended = false; break;
        case IntegrityProtectionAlgorithm::i_128_NIA2: is_extended = false; break;
        case IntegrityProtectionAlgorithm::i_128_NIA3: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case IntegrityProtectionAlgorithm::nIA0: enum_index = 0; break;
            case IntegrityProtectionAlgorithm::i_128_NIA1: enum_index = 1; break;
            case IntegrityProtectionAlgorithm::i_128_NIA2: enum_index = 2; break;
            case IntegrityProtectionAlgorithm::i_128_NIA3: enum_index = 3; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 4);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for IntegrityProtectionAlgorithm
IntegrityProtectionAlgorithm decode_IntegrityProtectionAlgorithm(BitReader& reader) {
    IntegrityProtectionAlgorithm value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 4);
        switch (enum_index) {
            case 0: value = IntegrityProtectionAlgorithm::nIA0; break;
            case 1: value = IntegrityProtectionAlgorithm::i_128_NIA1; break;
            case 2: value = IntegrityProtectionAlgorithm::i_128_NIA2; break;
            case 3: value = IntegrityProtectionAlgorithm::i_128_NIA3; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for IntegrityProtectionKey
void encode_IntegrityProtectionKey(BitWriter& writer, const IntegrityProtectionKey& value) {
    UperLength::encodeUnconstrainedLength(writer, value.size());
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for IntegrityProtectionKey
IntegrityProtectionKey decode_IntegrityProtectionKey(BitReader& reader) {
    IntegrityProtectionKey value{};
    {
        size_t length = UperLength::decodeUnconstrainedLength(reader);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for IntegrityProtectionResult
void encode_IntegrityProtectionResult(BitWriter& writer, const IntegrityProtectionResult& value) {
    bool is_extended = true;
    switch (value) {
        case IntegrityProtectionResult::performed: is_extended = false; break;
        case IntegrityProtectionResult::not_performed: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case IntegrityProtectionResult::performed: enum_index = 0; break;
            case IntegrityProtectionResult::not_performed: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for IntegrityProtectionResult
IntegrityProtectionResult decode_IntegrityProtectionResult(BitReader& reader) {
    IntegrityProtectionResult value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = IntegrityProtectionResult::performed; break;
            case 1: value = IntegrityProtectionResult::not_performed; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Inactivity_Timer
void encode_Inactivity_Timer(BitWriter& writer, const Inactivity_Timer& value) {
    if (value < 1LL || value > 7200LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [1, 7200].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 1LL, 7200LL);
}

// Decoder for Inactivity_Timer
Inactivity_Timer decode_Inactivity_Timer(BitReader& reader) {
    Inactivity_Timer value{};
    value = UperInteger::decodeConstrainedInt(reader, 1LL, 7200LL);
    if (value < 1LL || value > 7200LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [1, 7200].");
    }
    return value;
}

// Encoder for MaxDataBurstVolume
void encode_MaxDataBurstVolume(BitWriter& writer, const MaxDataBurstVolume& value) {
    if (value < 0LL || value > 4095LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 4095].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 4095LL);
}

// Decoder for MaxDataBurstVolume
MaxDataBurstVolume decode_MaxDataBurstVolume(BitReader& reader) {
    MaxDataBurstVolume value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 4095LL);
    if (value < 0LL || value > 4095LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 4095].");
    }
    return value;
}

// Encoder for MaxIPrate
void encode_MaxIPrate(BitWriter& writer, const MaxIPrate& value) {
    bool is_extended = true;
    switch (value) {
        case MaxIPrate::bitrate64kbs: is_extended = false; break;
        case MaxIPrate::max_UErate: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case MaxIPrate::bitrate64kbs: enum_index = 0; break;
            case MaxIPrate::max_UErate: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for MaxIPrate
MaxIPrate decode_MaxIPrate(BitReader& reader) {
    MaxIPrate value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = MaxIPrate::bitrate64kbs; break;
            case 1: value = MaxIPrate::max_UErate; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for MaximumIPdatarate
void encode_MaximumIPdatarate(BitWriter& writer, const MaximumIPdatarate& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_MaxIPrate(writer, value.maxIPrate);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for MaximumIPdatarate
MaximumIPdatarate decode_MaximumIPdatarate(BitReader& reader) {
    MaximumIPdatarate value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.maxIPrate = decode_MaxIPrate(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for MaxPacketLossRate
void encode_MaxPacketLossRate(BitWriter& writer, const MaxPacketLossRate& value) {
    if (value < 0LL || value > 1000LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 1000].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 1000LL);
}

// Decoder for MaxPacketLossRate
MaxPacketLossRate decode_MaxPacketLossRate(BitReader& reader) {
    MaxPacketLossRate value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 1000LL);
    if (value < 0LL || value > 1000LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 1000].");
    }
    return value;
}

// Encoder for GBR_QoSFlowInformation
void encode_GBR_QoSFlowInformation(BitWriter& writer, const GBR_QoSFlowInformation& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.maxPacketLossRateDownlink.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.maxPacketLossRateUplink.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        encode_BitRate(writer, value.maxFlowBitRateDownlink);
        encode_BitRate(writer, value.maxFlowBitRateUplink);
        encode_BitRate(writer, value.guaranteedFlowBitRateDownlink);
        encode_BitRate(writer, value.guaranteedFlowBitRateUplink);
        if (value.maxPacketLossRateDownlink.has_value()) {
            encode_MaxPacketLossRate(writer, (*value.maxPacketLossRateDownlink));
        }
        if (value.maxPacketLossRateUplink.has_value()) {
            encode_MaxPacketLossRate(writer, (*value.maxPacketLossRateUplink));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GBR_QoSFlowInformation
GBR_QoSFlowInformation decode_GBR_QoSFlowInformation(BitReader& reader) {
    GBR_QoSFlowInformation value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        value.maxFlowBitRateDownlink = decode_BitRate(reader);
        value.maxFlowBitRateUplink = decode_BitRate(reader);
        value.guaranteedFlowBitRateDownlink = decode_BitRate(reader);
        value.guaranteedFlowBitRateUplink = decode_BitRate(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.maxPacketLossRateDownlink)::value_type t_1{};
            t_1 = decode_MaxPacketLossRate(reader);
            value.maxPacketLossRateDownlink.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.maxPacketLossRateUplink)::value_type t_1{};
            t_1 = decode_MaxPacketLossRate(reader);
            value.maxPacketLossRateUplink.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for MRDC_Data_Usage_Report_Item
void encode_MRDC_Data_Usage_Report_Item(BitWriter& writer, const MRDC_Data_Usage_Report_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        if (value.startTimeStamp.size() != 4) {
            throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.startTimeStamp.size()) + " != 4.");
        }
        UperLength::encodeLength(writer, value.startTimeStamp.size(), 4, 4);
        for (uint8_t byte : value.startTimeStamp) {
            writer.writeByte(byte);
        }
        if (value.endTimeStamp.size() != 4) {
            throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.endTimeStamp.size()) + " != 4.");
        }
        UperLength::encodeLength(writer, value.endTimeStamp.size(), 4, 4);
        for (uint8_t byte : value.endTimeStamp) {
            writer.writeByte(byte);
        }
        if (value.usageCountUL < 0LL || value.usageCountUL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.usageCountUL) + " out of range [0, 18446744073709].");
        }
        UperInteger::encodeConstrainedInt(writer, value.usageCountUL, 0LL, 18446744073709LL);
        if (value.usageCountDL < 0LL || value.usageCountDL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.usageCountDL) + " out of range [0, 18446744073709].");
        }
        UperInteger::encodeConstrainedInt(writer, value.usageCountDL, 0LL, 18446744073709LL);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for MRDC_Data_Usage_Report_Item
MRDC_Data_Usage_Report_Item decode_MRDC_Data_Usage_Report_Item(BitReader& reader) {
    MRDC_Data_Usage_Report_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        {
            size_t length = UperLength::decodeLength(reader, 4, 4);
            value.startTimeStamp.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.startTimeStamp[i] = reader.readByte();
            }
        }
        {
            size_t length = UperLength::decodeLength(reader, 4, 4);
            value.endTimeStamp.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.endTimeStamp[i] = reader.readByte();
            }
        }
        value.usageCountUL = UperInteger::decodeConstrainedInt(reader, 0LL, 18446744073709LL);
        if (value.usageCountUL < 0LL || value.usageCountUL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.usageCountUL) + " out of range [0, 18446744073709].");
        }
        value.usageCountDL = UperInteger::decodeConstrainedInt(reader, 0LL, 18446744073709LL);
        if (value.usageCountDL < 0LL || value.usageCountDL > 18446744073709LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.usageCountDL) + " out of range [0, 18446744073709].");
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for Data_Usage_per_PDU_Session_Report
void encode_Data_Usage_per_PDU_Session_Report(BitWriter& writer, const Data_Usage_per_PDU_Session_Report& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        bool is_extended = true;
        switch (value.secondaryRATType) {
            case std::decay_t<decltype(value.secondaryRATType)>::nR: is_extended = false; break;
            case std::decay_t<decltype(value.secondaryRATType)>::e_UTRA: is_extended = false; break;
            default: break;
        }
        UperExtension::encodeExtensionMarker(writer, is_extended);

        if (!is_extended) {
            uint64_t enum_index = 0;
            switch (value.secondaryRATType) {
                case std::decay_t<decltype(value.secondaryRATType)>::nR: enum_index = 0; break;
                case std::decay_t<decltype(value.secondaryRATType)>::e_UTRA: enum_index = 1; break;
                default: throw std::runtime_error("Invalid enum value for encoding root");
            }
            UperChoice::encodeChoiceIndex(writer, enum_index, 2);
        } else {
            // Encoding of extended ENUMERATED is not supported.
            throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
        }
        if (value.pDU_session_Timed_Report_List.size() < 1 || value.pDU_session_Timed_Report_List.size() > 2) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.pDU_session_Timed_Report_List.size()) + " out of range [1, 2].");
        }
        UperLength::encodeLength(writer, value.pDU_session_Timed_Report_List.size(), 1, 2);
        for (const auto& element : value.pDU_session_Timed_Report_List) {
            encode_MRDC_Data_Usage_Report_Item(writer, element);
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Data_Usage_per_PDU_Session_Report
Data_Usage_per_PDU_Session_Report decode_Data_Usage_per_PDU_Session_Report(BitReader& reader) {
    Data_Usage_per_PDU_Session_Report value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        bool is_extended = UperExtension::decodeExtensionMarker(reader);

        if (!is_extended) {
            size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
            switch (enum_index) {
                case 0: value.secondaryRATType = std::decay_t<decltype(value.secondaryRATType)>::nR; break;
                case 1: value.secondaryRATType = std::decay_t<decltype(value.secondaryRATType)>::e_UTRA; break;
                default: throw std::runtime_error("Invalid enum index decoded");
            }
        } else {
            // For ENUMERATED, we can't store the value if it's an unknown extension.
            // We decode and discard, then throw to signal an unhandled extension.
            UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
            UperExtension::decodeOpenType(reader);
            throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
        }
        {
            size_t length = UperLength::decodeLength(reader, 1, 2);
            if (length < 1 || length > 2) {
                throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 2].");
            }
            value.pDU_session_Timed_Report_List.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.pDU_session_Timed_Report_List[i] = decode_MRDC_Data_Usage_Report_Item(reader);
            }
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for NetworkInstance
void encode_NetworkInstance(BitWriter& writer, const NetworkInstance& value) {
    if (value < 1LL || value > 256LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [1, 256].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 1LL, 256LL);
}

// Decoder for NetworkInstance
NetworkInstance decode_NetworkInstance(BitReader& reader) {
    NetworkInstance value{};
    value = UperInteger::decodeConstrainedInt(reader, 1LL, 256LL);
    if (value < 1LL || value > 256LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [1, 256].");
    }
    return value;
}

// Encoder for New_UL_TNL_Information_Required
void encode_New_UL_TNL_Information_Required(BitWriter& writer, const New_UL_TNL_Information_Required& value) {
    bool is_extended = true;
    switch (value) {
        case New_UL_TNL_Information_Required::required: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case New_UL_TNL_Information_Required::required: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for New_UL_TNL_Information_Required
New_UL_TNL_Information_Required decode_New_UL_TNL_Information_Required(BitReader& reader) {
    New_UL_TNL_Information_Required value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = New_UL_TNL_Information_Required::required; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for NR_Cell_Identity
void encode_NR_Cell_Identity(BitWriter& writer, const NR_Cell_Identity& value) {
    if (value.bit_length != 36) {
        throw std::runtime_error("BIT STRING SIZE constraint violation: length " + std::to_string(value.bit_length) + " != 36.");
    }
    UperLength::encodeLength(writer, value.bit_length, 36, 36);
    writer.writeBytes(value.data.data(), value.bit_length);
}

// Decoder for NR_Cell_Identity
NR_Cell_Identity decode_NR_Cell_Identity(BitReader& reader) {
    NR_Cell_Identity value{};
    {
        value.bit_length = UperLength::decodeLength(reader, 36, 36);
        size_t byte_length = (value.bit_length + 7) / 8;
        value.data.resize(byte_length);
        if (value.bit_length > 0) {
            reader.readBytes(value.data.data(), value.bit_length);
        }
    }
    return value;
}

// Encoder for OutOfOrderDelivery
void encode_OutOfOrderDelivery(BitWriter& writer, const OutOfOrderDelivery& value) {
    bool is_extended = true;
    switch (value) {
        case OutOfOrderDelivery::true_: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case OutOfOrderDelivery::true_: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for OutOfOrderDelivery
OutOfOrderDelivery decode_OutOfOrderDelivery(BitReader& reader) {
    OutOfOrderDelivery value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = OutOfOrderDelivery::true_; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PacketDelayBudget
void encode_PacketDelayBudget(BitWriter& writer, const PacketDelayBudget& value) {
    if (value < 0LL || value > 1023LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 1023].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 1023LL);
}

// Decoder for PacketDelayBudget
PacketDelayBudget decode_PacketDelayBudget(BitReader& reader) {
    PacketDelayBudget value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 1023LL);
    if (value < 0LL || value > 1023LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 1023].");
    }
    return value;
}

// Encoder for PER_Scalar
void encode_PER_Scalar(BitWriter& writer, const PER_Scalar& value) {
    if (value < 0LL || value > 9LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 9].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 9LL);
}

// Decoder for PER_Scalar
PER_Scalar decode_PER_Scalar(BitReader& reader) {
    PER_Scalar value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 9LL);
    if (value < 0LL || value > 9LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 9].");
    }
    return value;
}

// Encoder for PER_Exponent
void encode_PER_Exponent(BitWriter& writer, const PER_Exponent& value) {
    if (value < 0LL || value > 9LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 9].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 9LL);
}

// Decoder for PER_Exponent
PER_Exponent decode_PER_Exponent(BitReader& reader) {
    PER_Exponent value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 9LL);
    if (value < 0LL || value > 9LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 9].");
    }
    return value;
}

// Encoder for PacketErrorRate
void encode_PacketErrorRate(BitWriter& writer, const PacketErrorRate& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PER_Scalar(writer, value.pER_Scalar);
        encode_PER_Exponent(writer, value.pER_Exponent);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PacketErrorRate
PacketErrorRate decode_PacketErrorRate(BitReader& reader) {
    PacketErrorRate value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pER_Scalar = decode_PER_Scalar(reader);
        value.pER_Exponent = decode_PER_Exponent(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDCP_SN_Status_Request
void encode_PDCP_SN_Status_Request(BitWriter& writer, const PDCP_SN_Status_Request& value) {
    bool is_extended = true;
    switch (value) {
        case PDCP_SN_Status_Request::requested: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDCP_SN_Status_Request::requested: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDCP_SN_Status_Request
PDCP_SN_Status_Request decode_PDCP_SN_Status_Request(BitReader& reader) {
    PDCP_SN_Status_Request value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = PDCP_SN_Status_Request::requested; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PDCP_DataRecovery
void encode_PDCP_DataRecovery(BitWriter& writer, const PDCP_DataRecovery& value) {
    bool is_extended = true;
    switch (value) {
        case PDCP_DataRecovery::true_: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDCP_DataRecovery::true_: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDCP_DataRecovery
PDCP_DataRecovery decode_PDCP_DataRecovery(BitReader& reader) {
    PDCP_DataRecovery value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = PDCP_DataRecovery::true_; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PDCP_Duplication
void encode_PDCP_Duplication(BitWriter& writer, const PDCP_Duplication& value) {
    bool is_extended = true;
    switch (value) {
        case PDCP_Duplication::true_: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDCP_Duplication::true_: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDCP_Duplication
PDCP_Duplication decode_PDCP_Duplication(BitReader& reader) {
    PDCP_Duplication value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = PDCP_Duplication::true_; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PDCP_Reestablishment
void encode_PDCP_Reestablishment(BitWriter& writer, const PDCP_Reestablishment& value) {
    bool is_extended = true;
    switch (value) {
        case PDCP_Reestablishment::true_: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDCP_Reestablishment::true_: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDCP_Reestablishment
PDCP_Reestablishment decode_PDCP_Reestablishment(BitReader& reader) {
    PDCP_Reestablishment value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = PDCP_Reestablishment::true_; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PDCP_SN
void encode_PDCP_SN(BitWriter& writer, const PDCP_SN& value) {
    if (value < 0LL || value > 262143LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 262143].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 262143LL);
}

// Decoder for PDCP_SN
PDCP_SN decode_PDCP_SN(BitReader& reader) {
    PDCP_SN value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 262143LL);
    if (value < 0LL || value > 262143LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 262143].");
    }
    return value;
}

// Encoder for PDCP_Count
void encode_PDCP_Count(BitWriter& writer, const PDCP_Count& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDCP_SN(writer, value.pDCP_SN);
        encode_HFN(writer, value.hFN);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDCP_Count
PDCP_Count decode_PDCP_Count(BitReader& reader) {
    PDCP_Count value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDCP_SN = decode_PDCP_SN(reader);
        value.hFN = decode_HFN(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Status_Item
void encode_DRB_Status_Item(BitWriter& writer, const DRB_Status_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.pDCP_DL_Count.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.pDCP_UL_Count.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.pDCP_DL_Count.has_value()) {
            encode_PDCP_Count(writer, (*value.pDCP_DL_Count));
        }
        if (value.pDCP_UL_Count.has_value()) {
            encode_PDCP_Count(writer, (*value.pDCP_UL_Count));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Status_Item
DRB_Status_Item decode_DRB_Status_Item(BitReader& reader) {
    DRB_Status_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.pDCP_DL_Count)::value_type t_1{};
            t_1 = decode_PDCP_Count(reader);
            value.pDCP_DL_Count.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.pDCP_UL_Count)::value_type t_1{};
            t_1 = decode_PDCP_Count(reader);
            value.pDCP_UL_Count.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRBs_Subject_To_Counter_Check_Item_EUTRAN
void encode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(BitWriter& writer, const DRBs_Subject_To_Counter_Check_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_PDCP_Count(writer, value.pDCP_UL_Count);
        encode_PDCP_Count(writer, value.pDCP_DL_Count);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRBs_Subject_To_Counter_Check_Item_EUTRAN
DRBs_Subject_To_Counter_Check_Item_EUTRAN decode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(BitReader& reader) {
    DRBs_Subject_To_Counter_Check_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.pDCP_UL_Count = decode_PDCP_Count(reader);
        value.pDCP_DL_Count = decode_PDCP_Count(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRBs_Subject_To_Counter_Check_List_EUTRAN
void encode_DRBs_Subject_To_Counter_Check_List_EUTRAN(BitWriter& writer, const DRBs_Subject_To_Counter_Check_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRBs_Subject_To_Counter_Check_List_EUTRAN
DRBs_Subject_To_Counter_Check_List_EUTRAN decode_DRBs_Subject_To_Counter_Check_List_EUTRAN(BitReader& reader) {
    DRBs_Subject_To_Counter_Check_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRBs_Subject_To_Counter_Check_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for PDCP_SN_Size
void encode_PDCP_SN_Size(BitWriter& writer, const PDCP_SN_Size& value) {
    bool is_extended = true;
    switch (value) {
        case PDCP_SN_Size::s_12: is_extended = false; break;
        case PDCP_SN_Size::s_18: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDCP_SN_Size::s_12: enum_index = 0; break;
            case PDCP_SN_Size::s_18: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDCP_SN_Size
PDCP_SN_Size decode_PDCP_SN_Size(BitReader& reader) {
    PDCP_SN_Size value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = PDCP_SN_Size::s_12; break;
            case 1: value = PDCP_SN_Size::s_18; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for DRBBStatusTransfer
void encode_DRBBStatusTransfer(BitWriter& writer, const DRBBStatusTransfer& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.receiveStatusofPDCPSDU.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extension.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        if (value.receiveStatusofPDCPSDU.has_value()) {
            if ((*value.receiveStatusofPDCPSDU).bit_length < 1 || (*value.receiveStatusofPDCPSDU).bit_length > 131072) {
                throw std::runtime_error("BIT STRING SIZE constraint violation: length " + std::to_string((*value.receiveStatusofPDCPSDU).bit_length) + " out of range [1, 131072].");
            }
            UperLength::encodeLength(writer, (*value.receiveStatusofPDCPSDU).bit_length, 1, 131072);
            writer.writeBytes((*value.receiveStatusofPDCPSDU).data.data(), (*value.receiveStatusofPDCPSDU).bit_length);
        }
        encode_PDCP_Count(writer, value.countValue);
        if (value.iE_Extension.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extension));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRBBStatusTransfer
DRBBStatusTransfer decode_DRBBStatusTransfer(BitReader& reader) {
    DRBBStatusTransfer value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        if ((presenceBitmap >> 1) & 1) {
            decltype(value.receiveStatusofPDCPSDU)::value_type t_1{};
            {
                t_1.bit_length = UperLength::decodeLength(reader, 1, 131072);
                if (t_1.bit_length < 1 || t_1.bit_length > 131072) {
                    throw std::runtime_error("BIT STRING SIZE constraint violation: decoded length " + std::to_string(t_1.bit_length) + " out of range [1, 131072].");
                }
                size_t byte_length = (t_1.bit_length + 7) / 8;
                t_1.data.resize(byte_length);
                if (t_1.bit_length > 0) {
                    reader.readBytes(t_1.data.data(), t_1.bit_length);
                }
            }
            value.receiveStatusofPDCPSDU.emplace(t_1);
        }
        value.countValue = decode_PDCP_Count(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extension)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extension.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDCP_SN_Status_Information
void encode_PDCP_SN_Status_Information(BitWriter& writer, const PDCP_SN_Status_Information& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extension.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRBBStatusTransfer(writer, value.pdcpStatusTransfer_UL);
        encode_PDCP_Count(writer, value.pdcpStatusTransfer_DL);
        if (value.iE_Extension.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extension));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDCP_SN_Status_Information
PDCP_SN_Status_Information decode_PDCP_SN_Status_Information(BitReader& reader) {
    PDCP_SN_Status_Information value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pdcpStatusTransfer_UL = decode_DRBBStatusTransfer(reader);
        value.pdcpStatusTransfer_DL = decode_PDCP_Count(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extension)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extension.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_ID
void encode_PDU_Session_ID(BitWriter& writer, const PDU_Session_ID& value) {
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 255].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 255LL);
}

// Decoder for PDU_Session_ID
PDU_Session_ID decode_PDU_Session_ID(BitReader& reader) {
    PDU_Session_ID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 255].");
    }
    return value;
}

// Encoder for DRBs_Subject_To_Counter_Check_Item_NG_RAN
void encode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(BitWriter& writer, const DRBs_Subject_To_Counter_Check_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_DRB_ID(writer, value.dRB_ID);
        encode_PDCP_Count(writer, value.pDCP_UL_Count);
        encode_PDCP_Count(writer, value.pDCP_DL_Count);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRBs_Subject_To_Counter_Check_Item_NG_RAN
DRBs_Subject_To_Counter_Check_Item_NG_RAN decode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(BitReader& reader) {
    DRBs_Subject_To_Counter_Check_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.dRB_ID = decode_DRB_ID(reader);
        value.pDCP_UL_Count = decode_PDCP_Count(reader);
        value.pDCP_DL_Count = decode_PDCP_Count(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRBs_Subject_To_Counter_Check_List_NG_RAN
void encode_DRBs_Subject_To_Counter_Check_List_NG_RAN(BitWriter& writer, const DRBs_Subject_To_Counter_Check_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRBs_Subject_To_Counter_Check_List_NG_RAN
DRBs_Subject_To_Counter_Check_List_NG_RAN decode_DRBs_Subject_To_Counter_Check_List_NG_RAN(BitReader& reader) {
    DRBs_Subject_To_Counter_Check_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRBs_Subject_To_Counter_Check_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Activity
void encode_PDU_Session_Resource_Activity(BitWriter& writer, const PDU_Session_Resource_Activity& value) {
    bool is_extended = true;
    switch (value) {
        case PDU_Session_Resource_Activity::active: is_extended = false; break;
        case PDU_Session_Resource_Activity::not_active: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDU_Session_Resource_Activity::active: enum_index = 0; break;
            case PDU_Session_Resource_Activity::not_active: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDU_Session_Resource_Activity
PDU_Session_Resource_Activity decode_PDU_Session_Resource_Activity(BitReader& reader) {
    PDU_Session_Resource_Activity value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = PDU_Session_Resource_Activity::active; break;
            case 1: value = PDU_Session_Resource_Activity::not_active; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PDU_Session_Resource_Activity_Item
void encode_PDU_Session_Resource_Activity_Item(BitWriter& writer, const PDU_Session_Resource_Activity_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_PDU_Session_Resource_Activity(writer, value.pDU_Session_Resource_Activity);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Activity_Item
PDU_Session_Resource_Activity_Item decode_PDU_Session_Resource_Activity_Item(BitReader& reader) {
    PDU_Session_Resource_Activity_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.pDU_Session_Resource_Activity = decode_PDU_Session_Resource_Activity(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Activity_List
void encode_PDU_Session_Resource_Activity_List(BitWriter& writer, const PDU_Session_Resource_Activity_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Activity_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Activity_List
PDU_Session_Resource_Activity_List decode_PDU_Session_Resource_Activity_List(BitReader& reader) {
    PDU_Session_Resource_Activity_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Activity_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_Item
void encode_PDU_Session_Resource_Failed_Item(BitWriter& writer, const PDU_Session_Resource_Failed_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Failed_Item
PDU_Session_Resource_Failed_Item decode_PDU_Session_Resource_Failed_Item(BitReader& reader) {
    PDU_Session_Resource_Failed_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_List
void encode_PDU_Session_Resource_Failed_List(BitWriter& writer, const PDU_Session_Resource_Failed_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Failed_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Failed_List
PDU_Session_Resource_Failed_List decode_PDU_Session_Resource_Failed_List(BitReader& reader) {
    PDU_Session_Resource_Failed_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Failed_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_Mod_Item
void encode_PDU_Session_Resource_Failed_Mod_Item(BitWriter& writer, const PDU_Session_Resource_Failed_Mod_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Failed_Mod_Item
PDU_Session_Resource_Failed_Mod_Item decode_PDU_Session_Resource_Failed_Mod_Item(BitReader& reader) {
    PDU_Session_Resource_Failed_Mod_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_Mod_List
void encode_PDU_Session_Resource_Failed_Mod_List(BitWriter& writer, const PDU_Session_Resource_Failed_Mod_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Failed_Mod_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Failed_Mod_List
PDU_Session_Resource_Failed_Mod_List decode_PDU_Session_Resource_Failed_Mod_List(BitReader& reader) {
    PDU_Session_Resource_Failed_Mod_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Failed_Mod_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_To_Modify_Item
void encode_PDU_Session_Resource_Failed_To_Modify_Item(BitWriter& writer, const PDU_Session_Resource_Failed_To_Modify_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Failed_To_Modify_Item
PDU_Session_Resource_Failed_To_Modify_Item decode_PDU_Session_Resource_Failed_To_Modify_Item(BitReader& reader) {
    PDU_Session_Resource_Failed_To_Modify_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Failed_To_Modify_List
void encode_PDU_Session_Resource_Failed_To_Modify_List(BitWriter& writer, const PDU_Session_Resource_Failed_To_Modify_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Failed_To_Modify_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Failed_To_Modify_List
PDU_Session_Resource_Failed_To_Modify_List decode_PDU_Session_Resource_Failed_To_Modify_List(BitReader& reader) {
    PDU_Session_Resource_Failed_To_Modify_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Failed_To_Modify_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Remove_Item
void encode_PDU_Session_Resource_To_Remove_Item(BitWriter& writer, const PDU_Session_Resource_To_Remove_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_To_Remove_Item
PDU_Session_Resource_To_Remove_Item decode_PDU_Session_Resource_To_Remove_Item(BitReader& reader) {
    PDU_Session_Resource_To_Remove_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Remove_List
void encode_PDU_Session_Resource_To_Remove_List(BitWriter& writer, const PDU_Session_Resource_To_Remove_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_To_Remove_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_To_Remove_List
PDU_Session_Resource_To_Remove_List decode_PDU_Session_Resource_To_Remove_List(BitReader& reader) {
    PDU_Session_Resource_To_Remove_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_To_Remove_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Type
void encode_PDU_Session_Type(BitWriter& writer, const PDU_Session_Type& value) {
    bool is_extended = true;
    switch (value) {
        case PDU_Session_Type::ipv4: is_extended = false; break;
        case PDU_Session_Type::ipv6: is_extended = false; break;
        case PDU_Session_Type::ipv4v6: is_extended = false; break;
        case PDU_Session_Type::ethernet: is_extended = false; break;
        case PDU_Session_Type::unstructured: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case PDU_Session_Type::ipv4: enum_index = 0; break;
            case PDU_Session_Type::ipv6: enum_index = 1; break;
            case PDU_Session_Type::ipv4v6: enum_index = 2; break;
            case PDU_Session_Type::ethernet: enum_index = 3; break;
            case PDU_Session_Type::unstructured: enum_index = 4; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 5);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for PDU_Session_Type
PDU_Session_Type decode_PDU_Session_Type(BitReader& reader) {
    PDU_Session_Type value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 5);
        switch (enum_index) {
            case 0: value = PDU_Session_Type::ipv4; break;
            case 1: value = PDU_Session_Type::ipv6; break;
            case 2: value = PDU_Session_Type::ipv4v6; break;
            case 3: value = PDU_Session_Type::ethernet; break;
            case 4: value = PDU_Session_Type::unstructured; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for PLMN_Identity
void encode_PLMN_Identity(BitWriter& writer, const PLMN_Identity& value) {
    if (value.size() != 3) {
        throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.size()) + " != 3.");
    }
    UperLength::encodeLength(writer, value.size(), 3, 3);
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for PLMN_Identity
PLMN_Identity decode_PLMN_Identity(BitReader& reader) {
    PLMN_Identity value{};
    {
        size_t length = UperLength::decodeLength(reader, 3, 3);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for NR_CGI
void encode_NR_CGI(BitWriter& writer, const NR_CGI& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PLMN_Identity(writer, value.pLMN_Identity);
        encode_NR_Cell_Identity(writer, value.nR_Cell_Identity);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for NR_CGI
NR_CGI decode_NR_CGI(BitReader& reader) {
    NR_CGI value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pLMN_Identity = decode_PLMN_Identity(reader);
        value.nR_Cell_Identity = decode_NR_Cell_Identity(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for NR_CGI_Support_Item
void encode_NR_CGI_Support_Item(BitWriter& writer, const NR_CGI_Support_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_NR_CGI(writer, value.nR_CGI);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for NR_CGI_Support_Item
NR_CGI_Support_Item decode_NR_CGI_Support_Item(BitReader& reader) {
    NR_CGI_Support_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.nR_CGI = decode_NR_CGI(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for NR_CGI_Support_List
void encode_NR_CGI_Support_List(BitWriter& writer, const NR_CGI_Support_List& value) {
    if (value.size() < 1 || value.size() > 512) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 512].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 512);
    for (const auto& element : value) {
        encode_NR_CGI_Support_Item(writer, element);
    }
}

// Decoder for NR_CGI_Support_List
NR_CGI_Support_List decode_NR_CGI_Support_List(BitReader& reader) {
    NR_CGI_Support_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 512);
        if (length < 1 || length > 512) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 512].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_NR_CGI_Support_Item(reader);
        }
    }
    return value;
}

// Encoder for PortNumber
void encode_PortNumber(BitWriter& writer, const PortNumber& value) {
    if (value.bit_length != 16) {
        throw std::runtime_error("BIT STRING SIZE constraint violation: length " + std::to_string(value.bit_length) + " != 16.");
    }
    UperLength::encodeLength(writer, value.bit_length, 16, 16);
    writer.writeBytes(value.data.data(), value.bit_length);
}

// Decoder for PortNumber
PortNumber decode_PortNumber(BitReader& reader) {
    PortNumber value{};
    {
        value.bit_length = UperLength::decodeLength(reader, 16, 16);
        size_t byte_length = (value.bit_length + 7) / 8;
        value.data.resize(byte_length);
        if (value.bit_length > 0) {
            reader.readBytes(value.data.data(), value.bit_length);
        }
    }
    return value;
}

// Encoder for PPI
void encode_PPI(BitWriter& writer, const PPI& value) {
    if (value < 0LL || value > 7LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 7].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 7LL);
}

// Decoder for PPI
PPI decode_PPI(BitReader& reader) {
    PPI value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 7LL);
    if (value < 0LL || value > 7LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 7].");
    }
    return value;
}

// Encoder for PriorityLevel
void encode_PriorityLevel(BitWriter& writer, const PriorityLevel& value) {
    if (value < 0LL || value > 15LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 15].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 15LL);
}

// Decoder for PriorityLevel
PriorityLevel decode_PriorityLevel(BitReader& reader) {
    PriorityLevel value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 15LL);
    if (value < 0LL || value > 15LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 15].");
    }
    return value;
}

// Encoder for Pre_emptionCapability
void encode_Pre_emptionCapability(BitWriter& writer, const Pre_emptionCapability& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case Pre_emptionCapability::shall_not_trigger_pre_emption: enum_index = 0; break;
            case Pre_emptionCapability::may_trigger_pre_emption: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Pre_emptionCapability
Pre_emptionCapability decode_Pre_emptionCapability(BitReader& reader) {
    Pre_emptionCapability value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = Pre_emptionCapability::shall_not_trigger_pre_emption; break;
            case 1: value = Pre_emptionCapability::may_trigger_pre_emption; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Pre_emptionVulnerability
void encode_Pre_emptionVulnerability(BitWriter& writer, const Pre_emptionVulnerability& value) {
    if (true) {
        uint64_t enum_index = 0;
        switch (value) {
            case Pre_emptionVulnerability::not_pre_emptable: enum_index = 0; break;
            case Pre_emptionVulnerability::pre_emptable: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for Pre_emptionVulnerability
Pre_emptionVulnerability decode_Pre_emptionVulnerability(BitReader& reader) {
    Pre_emptionVulnerability value{};
    if (true) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = Pre_emptionVulnerability::not_pre_emptable; break;
            case 1: value = Pre_emptionVulnerability::pre_emptable; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for EUTRANAllocationAndRetentionPriority
void encode_EUTRANAllocationAndRetentionPriority(BitWriter& writer, const EUTRANAllocationAndRetentionPriority& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PriorityLevel(writer, value.priorityLevel);
        encode_Pre_emptionCapability(writer, value.pre_emptionCapability);
        encode_Pre_emptionVulnerability(writer, value.pre_emptionVulnerability);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for EUTRANAllocationAndRetentionPriority
EUTRANAllocationAndRetentionPriority decode_EUTRANAllocationAndRetentionPriority(BitReader& reader) {
    EUTRANAllocationAndRetentionPriority value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.priorityLevel = decode_PriorityLevel(reader);
        value.pre_emptionCapability = decode_Pre_emptionCapability(reader);
        value.pre_emptionVulnerability = decode_Pre_emptionVulnerability(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for NGRANAllocationAndRetentionPriority
void encode_NGRANAllocationAndRetentionPriority(BitWriter& writer, const NGRANAllocationAndRetentionPriority& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PriorityLevel(writer, value.priorityLevel);
        encode_Pre_emptionCapability(writer, value.pre_emptionCapability);
        encode_Pre_emptionVulnerability(writer, value.pre_emptionVulnerability);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for NGRANAllocationAndRetentionPriority
NGRANAllocationAndRetentionPriority decode_NGRANAllocationAndRetentionPriority(BitReader& reader) {
    NGRANAllocationAndRetentionPriority value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.priorityLevel = decode_PriorityLevel(reader);
        value.pre_emptionCapability = decode_Pre_emptionCapability(reader);
        value.pre_emptionVulnerability = decode_Pre_emptionVulnerability(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for QCI
void encode_QCI(BitWriter& writer, const QCI& value) {
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 255].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 255LL);
}

// Decoder for QCI
QCI decode_QCI(BitReader& reader) {
    QCI value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 255].");
    }
    return value;
}

// Encoder for EUTRAN_QoS
void encode_EUTRAN_QoS(BitWriter& writer, const EUTRAN_QoS& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.gbrQosInformation.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_QCI(writer, value.qCI);
        encode_EUTRANAllocationAndRetentionPriority(writer, value.eUTRANallocationAndRetentionPriority);
        if (value.gbrQosInformation.has_value()) {
            encode_GBR_QosInformation(writer, (*value.gbrQosInformation));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for EUTRAN_QoS
EUTRAN_QoS decode_EUTRAN_QoS(BitReader& reader) {
    EUTRAN_QoS value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.qCI = decode_QCI(reader);
        value.eUTRANallocationAndRetentionPriority = decode_EUTRANAllocationAndRetentionPriority(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.gbrQosInformation)::value_type t_1{};
            t_1 = decode_GBR_QosInformation(reader);
            value.gbrQosInformation.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for EUTRAN_QoS_Support_Item
void encode_EUTRAN_QoS_Support_Item(BitWriter& writer, const EUTRAN_QoS_Support_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_EUTRAN_QoS(writer, value.eUTRAN_QoS);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for EUTRAN_QoS_Support_Item
EUTRAN_QoS_Support_Item decode_EUTRAN_QoS_Support_Item(BitReader& reader) {
    EUTRAN_QoS_Support_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.eUTRAN_QoS = decode_EUTRAN_QoS(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for EUTRAN_QoS_Support_List
void encode_EUTRAN_QoS_Support_List(BitWriter& writer, const EUTRAN_QoS_Support_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_EUTRAN_QoS_Support_Item(writer, element);
    }
}

// Decoder for EUTRAN_QoS_Support_List
EUTRAN_QoS_Support_List decode_EUTRAN_QoS_Support_List(BitReader& reader) {
    EUTRAN_QoS_Support_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_EUTRAN_QoS_Support_Item(reader);
        }
    }
    return value;
}

// Encoder for QoS_Flow_Identifier
void encode_QoS_Flow_Identifier(BitWriter& writer, const QoS_Flow_Identifier& value) {
    if (value < 0LL || value > 63LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 63].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 63LL);
}

// Decoder for QoS_Flow_Identifier
QoS_Flow_Identifier decode_QoS_Flow_Identifier(BitReader& reader) {
    QoS_Flow_Identifier value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 63LL);
    if (value < 0LL || value > 63LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 63].");
    }
    return value;
}

// Encoder for Data_Usage_per_QoS_Flow_Item
void encode_Data_Usage_per_QoS_Flow_Item(BitWriter& writer, const Data_Usage_per_QoS_Flow_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_QoS_Flow_Identifier(writer, value.qoS_Flow_Identifier);
        bool is_extended = true;
        switch (value.secondaryRATType) {
            case std::decay_t<decltype(value.secondaryRATType)>::nR: is_extended = false; break;
            case std::decay_t<decltype(value.secondaryRATType)>::e_UTRA: is_extended = false; break;
            default: break;
        }
        UperExtension::encodeExtensionMarker(writer, is_extended);

        if (!is_extended) {
            uint64_t enum_index = 0;
            switch (value.secondaryRATType) {
                case std::decay_t<decltype(value.secondaryRATType)>::nR: enum_index = 0; break;
                case std::decay_t<decltype(value.secondaryRATType)>::e_UTRA: enum_index = 1; break;
                default: throw std::runtime_error("Invalid enum value for encoding root");
            }
            UperChoice::encodeChoiceIndex(writer, enum_index, 2);
        } else {
            // Encoding of extended ENUMERATED is not supported.
            throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
        }
        if (value.qoS_Flow_Timed_Report_List.size() < 1 || value.qoS_Flow_Timed_Report_List.size() > 2) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.qoS_Flow_Timed_Report_List.size()) + " out of range [1, 2].");
        }
        UperLength::encodeLength(writer, value.qoS_Flow_Timed_Report_List.size(), 1, 2);
        for (const auto& element : value.qoS_Flow_Timed_Report_List) {
            encode_MRDC_Data_Usage_Report_Item(writer, element);
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Data_Usage_per_QoS_Flow_Item
Data_Usage_per_QoS_Flow_Item decode_Data_Usage_per_QoS_Flow_Item(BitReader& reader) {
    Data_Usage_per_QoS_Flow_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.qoS_Flow_Identifier = decode_QoS_Flow_Identifier(reader);
        bool is_extended = UperExtension::decodeExtensionMarker(reader);

        if (!is_extended) {
            size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
            switch (enum_index) {
                case 0: value.secondaryRATType = std::decay_t<decltype(value.secondaryRATType)>::nR; break;
                case 1: value.secondaryRATType = std::decay_t<decltype(value.secondaryRATType)>::e_UTRA; break;
                default: throw std::runtime_error("Invalid enum index decoded");
            }
        } else {
            // For ENUMERATED, we can't store the value if it's an unknown extension.
            // We decode and discard, then throw to signal an unhandled extension.
            UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
            UperExtension::decodeOpenType(reader);
            throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
        }
        {
            size_t length = UperLength::decodeLength(reader, 1, 2);
            if (length < 1 || length > 2) {
                throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 2].");
            }
            value.qoS_Flow_Timed_Report_List.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.qoS_Flow_Timed_Report_List[i] = decode_MRDC_Data_Usage_Report_Item(reader);
            }
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for Data_Usage_per_QoS_Flow_List
void encode_Data_Usage_per_QoS_Flow_List(BitWriter& writer, const Data_Usage_per_QoS_Flow_List& value) {
    if (value.size() < 1 || value.size() > 64) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 64].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 64);
    for (const auto& element : value) {
        encode_Data_Usage_per_QoS_Flow_Item(writer, element);
    }
}

// Decoder for Data_Usage_per_QoS_Flow_List
Data_Usage_per_QoS_Flow_List decode_Data_Usage_per_QoS_Flow_List(BitReader& reader) {
    Data_Usage_per_QoS_Flow_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 64);
        if (length < 1 || length > 64) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 64].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_Data_Usage_per_QoS_Flow_Item(reader);
        }
    }
    return value;
}

// Encoder for MRDC_Usage_Information
void encode_MRDC_Usage_Information(BitWriter& writer, const MRDC_Usage_Information& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.data_Usage_per_PDU_Session_Report.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.data_Usage_per_QoS_Flow_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        if (value.data_Usage_per_PDU_Session_Report.has_value()) {
            encode_Data_Usage_per_PDU_Session_Report(writer, (*value.data_Usage_per_PDU_Session_Report));
        }
        if (value.data_Usage_per_QoS_Flow_List.has_value()) {
            encode_Data_Usage_per_QoS_Flow_List(writer, (*value.data_Usage_per_QoS_Flow_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for MRDC_Usage_Information
MRDC_Usage_Information decode_MRDC_Usage_Information(BitReader& reader) {
    MRDC_Usage_Information value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        if ((presenceBitmap >> 2) & 1) {
            decltype(value.data_Usage_per_PDU_Session_Report)::value_type t_1{};
            t_1 = decode_Data_Usage_per_PDU_Session_Report(reader);
            value.data_Usage_per_PDU_Session_Report.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.data_Usage_per_QoS_Flow_List)::value_type t_1{};
            t_1 = decode_Data_Usage_per_QoS_Flow_List(reader);
            value.data_Usage_per_QoS_Flow_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Data_Usage_Item
void encode_PDU_Session_Resource_Data_Usage_Item(BitWriter& writer, const PDU_Session_Resource_Data_Usage_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_MRDC_Usage_Information(writer, value.mRDC_Usage_Information);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Data_Usage_Item
PDU_Session_Resource_Data_Usage_Item decode_PDU_Session_Resource_Data_Usage_Item(BitReader& reader) {
    PDU_Session_Resource_Data_Usage_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.mRDC_Usage_Information = decode_MRDC_Usage_Information(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Data_Usage_List
void encode_PDU_Session_Resource_Data_Usage_List(BitWriter& writer, const PDU_Session_Resource_Data_Usage_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Data_Usage_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Data_Usage_List
PDU_Session_Resource_Data_Usage_List decode_PDU_Session_Resource_Data_Usage_List(BitReader& reader) {
    PDU_Session_Resource_Data_Usage_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Data_Usage_Item(reader);
        }
    }
    return value;
}

// Encoder for QoS_Flow_Item
void encode_QoS_Flow_Item(BitWriter& writer, const QoS_Flow_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_QoS_Flow_Identifier(writer, value.qoS_Flow_Identifier);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for QoS_Flow_Item
QoS_Flow_Item decode_QoS_Flow_Item(BitReader& reader) {
    QoS_Flow_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.qoS_Flow_Identifier = decode_QoS_Flow_Identifier(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoS_Flow_List
void encode_QoS_Flow_List(BitWriter& writer, const QoS_Flow_List& value) {
    if (value.size() < 1 || value.size() > 64) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 64].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 64);
    for (const auto& element : value) {
        encode_QoS_Flow_Item(writer, element);
    }
}

// Decoder for QoS_Flow_List
QoS_Flow_List decode_QoS_Flow_List(BitReader& reader) {
    QoS_Flow_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 64);
        if (length < 1 || length > 64) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 64].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_QoS_Flow_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_To_Notify_Item
void encode_PDU_Session_To_Notify_Item(BitWriter& writer, const PDU_Session_To_Notify_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_QoS_Flow_List(writer, value.qoS_Flow_List);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_To_Notify_Item
PDU_Session_To_Notify_Item decode_PDU_Session_To_Notify_Item(BitReader& reader) {
    PDU_Session_To_Notify_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.qoS_Flow_List = decode_QoS_Flow_List(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_To_Notify_List
void encode_PDU_Session_To_Notify_List(BitWriter& writer, const PDU_Session_To_Notify_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_To_Notify_Item(writer, element);
    }
}

// Decoder for PDU_Session_To_Notify_List
PDU_Session_To_Notify_List decode_PDU_Session_To_Notify_List(BitReader& reader) {
    PDU_Session_To_Notify_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_To_Notify_Item(reader);
        }
    }
    return value;
}

// Encoder for QoS_Flow_Failed_Item
void encode_QoS_Flow_Failed_Item(BitWriter& writer, const QoS_Flow_Failed_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_QoS_Flow_Identifier(writer, value.qoS_Flow_Identifier);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for QoS_Flow_Failed_Item
QoS_Flow_Failed_Item decode_QoS_Flow_Failed_Item(BitReader& reader) {
    QoS_Flow_Failed_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.qoS_Flow_Identifier = decode_QoS_Flow_Identifier(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoS_Flow_Failed_List
void encode_QoS_Flow_Failed_List(BitWriter& writer, const QoS_Flow_Failed_List& value) {
    if (value.size() < 1 || value.size() > 64) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 64].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 64);
    for (const auto& element : value) {
        encode_QoS_Flow_Failed_Item(writer, element);
    }
}

// Decoder for QoS_Flow_Failed_List
QoS_Flow_Failed_List decode_QoS_Flow_Failed_List(BitReader& reader) {
    QoS_Flow_Failed_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 64);
        if (length < 1 || length > 64) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 64].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_QoS_Flow_Failed_Item(reader);
        }
    }
    return value;
}

// Encoder for QoS_Flow_Mapping_Indication
void encode_QoS_Flow_Mapping_Indication(BitWriter& writer, const QoS_Flow_Mapping_Indication& value) {
    bool is_extended = true;
    switch (value) {
        case QoS_Flow_Mapping_Indication::ul: is_extended = false; break;
        case QoS_Flow_Mapping_Indication::dl: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case QoS_Flow_Mapping_Indication::ul: enum_index = 0; break;
            case QoS_Flow_Mapping_Indication::dl: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for QoS_Flow_Mapping_Indication
QoS_Flow_Mapping_Indication decode_QoS_Flow_Mapping_Indication(BitReader& reader) {
    QoS_Flow_Mapping_Indication value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = QoS_Flow_Mapping_Indication::ul; break;
            case 1: value = QoS_Flow_Mapping_Indication::dl; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for QoS_Flow_Mapping_Item
void encode_QoS_Flow_Mapping_Item(BitWriter& writer, const QoS_Flow_Mapping_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.qoSFlowMappingIndication.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_QoS_Flow_Identifier(writer, value.qoS_Flow_Identifier);
        if (value.qoSFlowMappingIndication.has_value()) {
            encode_QoS_Flow_Mapping_Indication(writer, (*value.qoSFlowMappingIndication));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for QoS_Flow_Mapping_Item
QoS_Flow_Mapping_Item decode_QoS_Flow_Mapping_Item(BitReader& reader) {
    QoS_Flow_Mapping_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.qoS_Flow_Identifier = decode_QoS_Flow_Identifier(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.qoSFlowMappingIndication)::value_type t_1{};
            t_1 = decode_QoS_Flow_Mapping_Indication(reader);
            value.qoSFlowMappingIndication.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoS_Flow_Mapping_List
void encode_QoS_Flow_Mapping_List(BitWriter& writer, const QoS_Flow_Mapping_List& value) {
    if (value.size() < 1 || value.size() > 64) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 64].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 64);
    for (const auto& element : value) {
        encode_QoS_Flow_Mapping_Item(writer, element);
    }
}

// Decoder for QoS_Flow_Mapping_List
QoS_Flow_Mapping_List decode_QoS_Flow_Mapping_List(BitReader& reader) {
    QoS_Flow_Mapping_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 64);
        if (length < 1 || length > 64) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 64].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_QoS_Flow_Mapping_Item(reader);
        }
    }
    return value;
}

// Encoder for Data_Forwarding_Information_Request
void encode_Data_Forwarding_Information_Request(BitWriter& writer, const Data_Forwarding_Information_Request& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.qoS_Flows_Forwarded_On_Fwd_Tunnels.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_Data_Forwarding_Request(writer, value.data_Forwarding_Request);
        if (value.qoS_Flows_Forwarded_On_Fwd_Tunnels.has_value()) {
            encode_QoS_Flow_Mapping_List(writer, (*value.qoS_Flows_Forwarded_On_Fwd_Tunnels));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Data_Forwarding_Information_Request
Data_Forwarding_Information_Request decode_Data_Forwarding_Information_Request(BitReader& reader) {
    Data_Forwarding_Information_Request value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.data_Forwarding_Request = decode_Data_Forwarding_Request(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.qoS_Flows_Forwarded_On_Fwd_Tunnels)::value_type t_1{};
            t_1 = decode_QoS_Flow_Mapping_List(reader);
            value.qoS_Flows_Forwarded_On_Fwd_Tunnels.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoSPriorityLevel
void encode_QoSPriorityLevel(BitWriter& writer, const QoSPriorityLevel& value) {
    if (value < 0LL || value > 127LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 127].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 127LL);
}

// Decoder for QoSPriorityLevel
QoSPriorityLevel decode_QoSPriorityLevel(BitReader& reader) {
    QoSPriorityLevel value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 127LL);
    if (value < 0LL || value > 127LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 127].");
    }
    return value;
}

// Encoder for Dynamic5QIDescriptor
void encode_Dynamic5QIDescriptor(BitWriter& writer, const Dynamic5QIDescriptor& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.fiveQI.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.delayCritical.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.averagingWindow.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.maxDataBurstVolume.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 5);

        encode_QoSPriorityLevel(writer, value.qoSPriorityLevel);
        encode_PacketDelayBudget(writer, value.packetDelayBudget);
        encode_PacketErrorRate(writer, value.packetErrorRate);
        if (value.fiveQI.has_value()) {
            if ((*value.fiveQI) < 0LL || (*value.fiveQI) > 255LL) {
                throw std::runtime_error("INTEGER constraint violation: value " + std::to_string((*value.fiveQI)) + " out of range [0, 255].");
            }
            UperInteger::encodeConstrainedInt(writer, (*value.fiveQI), 0LL, 255LL);
        }
        if (value.delayCritical.has_value()) {
            if (true) {
                uint64_t enum_index = 0;
                switch ((*value.delayCritical)) {
                    case std::decay_t<decltype((*value.delayCritical))>::delay_critical: enum_index = 0; break;
                    case std::decay_t<decltype((*value.delayCritical))>::non_delay_critical: enum_index = 1; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 2);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.averagingWindow.has_value()) {
            encode_AveragingWindow(writer, (*value.averagingWindow));
        }
        if (value.maxDataBurstVolume.has_value()) {
            encode_MaxDataBurstVolume(writer, (*value.maxDataBurstVolume));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for Dynamic5QIDescriptor
Dynamic5QIDescriptor decode_Dynamic5QIDescriptor(BitReader& reader) {
    Dynamic5QIDescriptor value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 5);

        value.qoSPriorityLevel = decode_QoSPriorityLevel(reader);
        value.packetDelayBudget = decode_PacketDelayBudget(reader);
        value.packetErrorRate = decode_PacketErrorRate(reader);
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.fiveQI)::value_type t_1{};
            t_1 = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
            if (t_1 < 0LL || t_1 > 255LL) {
                throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(t_1) + " out of range [0, 255].");
            }
            value.fiveQI.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.delayCritical)::value_type t_1{};
            if (true) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::delay_critical; break;
                    case 1: t_1 = std::decay_t<decltype(t_1)>::non_delay_critical; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.delayCritical.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.averagingWindow)::value_type t_1{};
            t_1 = decode_AveragingWindow(reader);
            value.averagingWindow.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.maxDataBurstVolume)::value_type t_1{};
            t_1 = decode_MaxDataBurstVolume(reader);
            value.maxDataBurstVolume.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for Non_Dynamic5QIDescriptor
void encode_Non_Dynamic5QIDescriptor(BitWriter& writer, const Non_Dynamic5QIDescriptor& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.qoSPriorityLevel.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.averagingWindow.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.maxDataBurstVolume.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        if (value.fiveQI < 0LL || value.fiveQI > 255LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.fiveQI) + " out of range [0, 255].");
        }
        UperInteger::encodeConstrainedInt(writer, value.fiveQI, 0LL, 255LL);
        if (value.qoSPriorityLevel.has_value()) {
            encode_QoSPriorityLevel(writer, (*value.qoSPriorityLevel));
        }
        if (value.averagingWindow.has_value()) {
            encode_AveragingWindow(writer, (*value.averagingWindow));
        }
        if (value.maxDataBurstVolume.has_value()) {
            encode_MaxDataBurstVolume(writer, (*value.maxDataBurstVolume));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for Non_Dynamic5QIDescriptor
Non_Dynamic5QIDescriptor decode_Non_Dynamic5QIDescriptor(BitReader& reader) {
    Non_Dynamic5QIDescriptor value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.fiveQI = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
        if (value.fiveQI < 0LL || value.fiveQI > 255LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.fiveQI) + " out of range [0, 255].");
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.qoSPriorityLevel)::value_type t_1{};
            t_1 = decode_QoSPriorityLevel(reader);
            value.qoSPriorityLevel.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.averagingWindow)::value_type t_1{};
            t_1 = decode_AveragingWindow(reader);
            value.averagingWindow.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.maxDataBurstVolume)::value_type t_1{};
            t_1 = decode_MaxDataBurstVolume(reader);
            value.maxDataBurstVolume.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for NG_RAN_QoS_Support_Item
void encode_NG_RAN_QoS_Support_Item(BitWriter& writer, const NG_RAN_QoS_Support_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_Non_Dynamic5QIDescriptor(writer, value.non_Dynamic5QIDescriptor);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for NG_RAN_QoS_Support_Item
NG_RAN_QoS_Support_Item decode_NG_RAN_QoS_Support_Item(BitReader& reader) {
    NG_RAN_QoS_Support_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.non_Dynamic5QIDescriptor = decode_Non_Dynamic5QIDescriptor(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for NG_RAN_QoS_Support_List
void encode_NG_RAN_QoS_Support_List(BitWriter& writer, const NG_RAN_QoS_Support_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_NG_RAN_QoS_Support_Item(writer, element);
    }
}

// Decoder for NG_RAN_QoS_Support_List
NG_RAN_QoS_Support_List decode_NG_RAN_QoS_Support_List(BitReader& reader) {
    NG_RAN_QoS_Support_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_NG_RAN_QoS_Support_Item(reader);
        }
    }
    return value;
}

// Encoder for QoS_Characteristics
void encode_QoS_Characteristics(BitWriter& writer, const QoS_Characteristics& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_Non_Dynamic5QIDescriptor(writer, arg_1.non_Dynamic_5QI);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_Dynamic5QIDescriptor(writer, arg_1.dynamic_5QI);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for QoS_Characteristics
QoS_Characteristics decode_QoS_Characteristics(BitReader& reader) {
    QoS_Characteristics value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.non_Dynamic_5QI = decode_Non_Dynamic5QIDescriptor(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.dynamic_5QI = decode_Dynamic5QIDescriptor(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for QoS_Parameters_Support_List
void encode_QoS_Parameters_Support_List(BitWriter& writer, const QoS_Parameters_Support_List& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.eUTRAN_QoS_Support_List.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.nG_RAN_QoS_Support_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        if (value.eUTRAN_QoS_Support_List.has_value()) {
            encode_EUTRAN_QoS_Support_List(writer, (*value.eUTRAN_QoS_Support_List));
        }
        if (value.nG_RAN_QoS_Support_List.has_value()) {
            encode_NG_RAN_QoS_Support_List(writer, (*value.nG_RAN_QoS_Support_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for QoS_Parameters_Support_List
QoS_Parameters_Support_List decode_QoS_Parameters_Support_List(BitReader& reader) {
    QoS_Parameters_Support_List value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        if ((presenceBitmap >> 2) & 1) {
            decltype(value.eUTRAN_QoS_Support_List)::value_type t_1{};
            t_1 = decode_EUTRAN_QoS_Support_List(reader);
            value.eUTRAN_QoS_Support_List.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.nG_RAN_QoS_Support_List)::value_type t_1{};
            t_1 = decode_NG_RAN_QoS_Support_List(reader);
            value.nG_RAN_QoS_Support_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoSFlowLevelQoSParameters
void encode_QoSFlowLevelQoSParameters(BitWriter& writer, const QoSFlowLevelQoSParameters& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.gBR_QoS_Flow_Information.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.reflective_QoS_Attribute.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.additional_QoS_Information.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.paging_Policy_Indicator.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.reflective_QoS_Indicator.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 6);

        encode_QoS_Characteristics(writer, value.qoS_Characteristics);
        encode_NGRANAllocationAndRetentionPriority(writer, value.nGRANallocationRetentionPriority);
        if (value.gBR_QoS_Flow_Information.has_value()) {
            encode_GBR_QoSFlowInformation(writer, (*value.gBR_QoS_Flow_Information));
        }
        if (value.reflective_QoS_Attribute.has_value()) {
            bool is_extended = true;
            switch ((*value.reflective_QoS_Attribute)) {
                case std::decay_t<decltype((*value.reflective_QoS_Attribute))>::subject_to: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.reflective_QoS_Attribute)) {
                    case std::decay_t<decltype((*value.reflective_QoS_Attribute))>::subject_to: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.additional_QoS_Information.has_value()) {
            bool is_extended = true;
            switch ((*value.additional_QoS_Information)) {
                case std::decay_t<decltype((*value.additional_QoS_Information))>::more_likely: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.additional_QoS_Information)) {
                    case std::decay_t<decltype((*value.additional_QoS_Information))>::more_likely: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.paging_Policy_Indicator.has_value()) {
            if ((*value.paging_Policy_Indicator) < 1LL || (*value.paging_Policy_Indicator) > 8LL) {
                throw std::runtime_error("INTEGER constraint violation: value " + std::to_string((*value.paging_Policy_Indicator)) + " out of range [1, 8].");
            }
            UperInteger::encodeConstrainedInt(writer, (*value.paging_Policy_Indicator), 1LL, 8LL);
        }
        if (value.reflective_QoS_Indicator.has_value()) {
            bool is_extended = true;
            switch ((*value.reflective_QoS_Indicator)) {
                case std::decay_t<decltype((*value.reflective_QoS_Indicator))>::enabled: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.reflective_QoS_Indicator)) {
                    case std::decay_t<decltype((*value.reflective_QoS_Indicator))>::enabled: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for QoSFlowLevelQoSParameters
QoSFlowLevelQoSParameters decode_QoSFlowLevelQoSParameters(BitReader& reader) {
    QoSFlowLevelQoSParameters value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 6);

        value.qoS_Characteristics = decode_QoS_Characteristics(reader);
        value.nGRANallocationRetentionPriority = decode_NGRANAllocationAndRetentionPriority(reader);
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.gBR_QoS_Flow_Information)::value_type t_1{};
            t_1 = decode_GBR_QoSFlowInformation(reader);
            value.gBR_QoS_Flow_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.reflective_QoS_Attribute)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::subject_to; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.reflective_QoS_Attribute.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.additional_QoS_Information)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::more_likely; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.additional_QoS_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.paging_Policy_Indicator)::value_type t_1{};
            t_1 = UperInteger::decodeConstrainedInt(reader, 1LL, 8LL);
            if (t_1 < 1LL || t_1 > 8LL) {
                throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(t_1) + " out of range [1, 8].");
            }
            value.paging_Policy_Indicator.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.reflective_QoS_Indicator)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::enabled; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.reflective_QoS_Indicator.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for QoS_Flow_QoS_Parameter_Item
void encode_QoS_Flow_QoS_Parameter_Item(BitWriter& writer, const QoS_Flow_QoS_Parameter_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.qoSFlowMappingIndication.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_QoS_Flow_Identifier(writer, value.qoS_Flow_Identifier);
        encode_QoSFlowLevelQoSParameters(writer, value.qoSFlowLevelQoSParameters);
        if (value.qoSFlowMappingIndication.has_value()) {
            encode_QoS_Flow_Mapping_Indication(writer, (*value.qoSFlowMappingIndication));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for QoS_Flow_QoS_Parameter_Item
QoS_Flow_QoS_Parameter_Item decode_QoS_Flow_QoS_Parameter_Item(BitReader& reader) {
    QoS_Flow_QoS_Parameter_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.qoS_Flow_Identifier = decode_QoS_Flow_Identifier(reader);
        value.qoSFlowLevelQoSParameters = decode_QoSFlowLevelQoSParameters(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.qoSFlowMappingIndication)::value_type t_1{};
            t_1 = decode_QoS_Flow_Mapping_Indication(reader);
            value.qoSFlowMappingIndication.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for QoS_Flow_QoS_Parameter_List
void encode_QoS_Flow_QoS_Parameter_List(BitWriter& writer, const QoS_Flow_QoS_Parameter_List& value) {
    if (value.size() < 1 || value.size() > 64) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 64].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 64);
    for (const auto& element : value) {
        encode_QoS_Flow_QoS_Parameter_Item(writer, element);
    }
}

// Decoder for QoS_Flow_QoS_Parameter_List
QoS_Flow_QoS_Parameter_List decode_QoS_Flow_QoS_Parameter_List(BitReader& reader) {
    QoS_Flow_QoS_Parameter_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 64);
        if (length < 1 || length > 64) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 64].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_QoS_Flow_QoS_Parameter_Item(reader);
        }
    }
    return value;
}

// Encoder for RANUEID
void encode_RANUEID(BitWriter& writer, const RANUEID& value) {
    if (value.size() != 8) {
        throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.size()) + " != 8.");
    }
    UperLength::encodeLength(writer, value.size(), 8, 8);
    for (uint8_t byte : value) {
        writer.writeByte(byte);
    }
}

// Decoder for RANUEID
RANUEID decode_RANUEID(BitReader& reader) {
    RANUEID value{};
    {
        size_t length = UperLength::decodeLength(reader, 8, 8);
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = reader.readByte();
        }
    }
    return value;
}

// Encoder for RAT_Type
void encode_RAT_Type(BitWriter& writer, const RAT_Type& value) {
    bool is_extended = true;
    switch (value) {
        case RAT_Type::e_UTRA: is_extended = false; break;
        case RAT_Type::nR: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case RAT_Type::e_UTRA: enum_index = 0; break;
            case RAT_Type::nR: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for RAT_Type
RAT_Type decode_RAT_Type(BitReader& reader) {
    RAT_Type value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = RAT_Type::e_UTRA; break;
            case 1: value = RAT_Type::nR; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Data_Usage_Report_Item
void encode_Data_Usage_Report_Item(BitWriter& writer, const Data_Usage_Report_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_RAT_Type(writer, value.rAT_Type);
        encode_DRB_Usage_Report_List(writer, value.dRB_Usage_Report_List);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Data_Usage_Report_Item
Data_Usage_Report_Item decode_Data_Usage_Report_Item(BitReader& reader) {
    Data_Usage_Report_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.dRB_ID = decode_DRB_ID(reader);
        value.rAT_Type = decode_RAT_Type(reader);
        value.dRB_Usage_Report_List = decode_DRB_Usage_Report_List(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for Data_Usage_Report_List
void encode_Data_Usage_Report_List(BitWriter& writer, const Data_Usage_Report_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_Data_Usage_Report_Item(writer, element);
    }
}

// Decoder for Data_Usage_Report_List
Data_Usage_Report_List decode_Data_Usage_Report_List(BitReader& reader) {
    Data_Usage_Report_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_Data_Usage_Report_Item(reader);
        }
    }
    return value;
}

// Encoder for RLC_Mode
void encode_RLC_Mode(BitWriter& writer, const RLC_Mode& value) {
    bool is_extended = true;
    switch (value) {
        case RLC_Mode::rlc_tm: is_extended = false; break;
        case RLC_Mode::rlc_am: is_extended = false; break;
        case RLC_Mode::rlc_um_bidirectional: is_extended = false; break;
        case RLC_Mode::rlc_um_unidirectional_ul: is_extended = false; break;
        case RLC_Mode::rlc_um_unidirectional_dl: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case RLC_Mode::rlc_tm: enum_index = 0; break;
            case RLC_Mode::rlc_am: enum_index = 1; break;
            case RLC_Mode::rlc_um_bidirectional: enum_index = 2; break;
            case RLC_Mode::rlc_um_unidirectional_ul: enum_index = 3; break;
            case RLC_Mode::rlc_um_unidirectional_dl: enum_index = 4; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 5);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for RLC_Mode
RLC_Mode decode_RLC_Mode(BitReader& reader) {
    RLC_Mode value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 5);
        switch (enum_index) {
            case 0: value = RLC_Mode::rlc_tm; break;
            case 1: value = RLC_Mode::rlc_am; break;
            case 2: value = RLC_Mode::rlc_um_bidirectional; break;
            case 3: value = RLC_Mode::rlc_um_unidirectional_ul; break;
            case 4: value = RLC_Mode::rlc_um_unidirectional_dl; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for ROHC
void encode_ROHC(BitWriter& writer, const ROHC& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.continueROHC.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        if (value.maxCID < 0LL || value.maxCID > 16383LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.maxCID) + " out of range [0, 16383].");
        }
        UperInteger::encodeConstrainedInt(writer, value.maxCID, 0LL, 16383LL);
        if (value.rOHC_Profiles < 0LL || value.rOHC_Profiles > 511LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.rOHC_Profiles) + " out of range [0, 511].");
        }
        UperInteger::encodeConstrainedInt(writer, value.rOHC_Profiles, 0LL, 511LL);
        if (value.continueROHC.has_value()) {
            bool is_extended = true;
            switch ((*value.continueROHC)) {
                case std::decay_t<decltype((*value.continueROHC))>::true_: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.continueROHC)) {
                    case std::decay_t<decltype((*value.continueROHC))>::true_: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for ROHC
ROHC decode_ROHC(BitReader& reader) {
    ROHC value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.maxCID = UperInteger::decodeConstrainedInt(reader, 0LL, 16383LL);
        if (value.maxCID < 0LL || value.maxCID > 16383LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.maxCID) + " out of range [0, 16383].");
        }
        value.rOHC_Profiles = UperInteger::decodeConstrainedInt(reader, 0LL, 511LL);
        if (value.rOHC_Profiles < 0LL || value.rOHC_Profiles > 511LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.rOHC_Profiles) + " out of range [0, 511].");
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.continueROHC)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::true_; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.continueROHC.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for SecurityAlgorithm
void encode_SecurityAlgorithm(BitWriter& writer, const SecurityAlgorithm& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.integrityProtectionAlgorithm.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_CipheringAlgorithm(writer, value.cipheringAlgorithm);
        if (value.integrityProtectionAlgorithm.has_value()) {
            encode_IntegrityProtectionAlgorithm(writer, (*value.integrityProtectionAlgorithm));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SecurityAlgorithm
SecurityAlgorithm decode_SecurityAlgorithm(BitReader& reader) {
    SecurityAlgorithm value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.cipheringAlgorithm = decode_CipheringAlgorithm(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.integrityProtectionAlgorithm)::value_type t_1{};
            t_1 = decode_IntegrityProtectionAlgorithm(reader);
            value.integrityProtectionAlgorithm.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SecurityIndication
void encode_SecurityIndication(BitWriter& writer, const SecurityIndication& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.maximumIPdatarate.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_IntegrityProtectionIndication(writer, value.integrityProtectionIndication);
        encode_ConfidentialityProtectionIndication(writer, value.confidentialityProtectionIndication);
        if (value.maximumIPdatarate.has_value()) {
            encode_MaximumIPdatarate(writer, (*value.maximumIPdatarate));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SecurityIndication
SecurityIndication decode_SecurityIndication(BitReader& reader) {
    SecurityIndication value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.integrityProtectionIndication = decode_IntegrityProtectionIndication(reader);
        value.confidentialityProtectionIndication = decode_ConfidentialityProtectionIndication(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.maximumIPdatarate)::value_type t_1{};
            t_1 = decode_MaximumIPdatarate(reader);
            value.maximumIPdatarate.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SecurityResult
void encode_SecurityResult(BitWriter& writer, const SecurityResult& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_IntegrityProtectionResult(writer, value.integrityProtectionResult);
        encode_ConfidentialityProtectionResult(writer, value.confidentialityProtectionResult);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SecurityResult
SecurityResult decode_SecurityResult(BitReader& reader) {
    SecurityResult value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.integrityProtectionResult = decode_IntegrityProtectionResult(reader);
        value.confidentialityProtectionResult = decode_ConfidentialityProtectionResult(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SNSSAI
void encode_SNSSAI(BitWriter& writer, const SNSSAI& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.sD.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        if (value.sST.size() != 1) {
            throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string(value.sST.size()) + " != 1.");
        }
        UperLength::encodeLength(writer, value.sST.size(), 1, 1);
        for (uint8_t byte : value.sST) {
            writer.writeByte(byte);
        }
        if (value.sD.has_value()) {
            if ((*value.sD).size() != 3) {
                throw std::runtime_error("OCTET STRING SIZE constraint violation: length " + std::to_string((*value.sD).size()) + " != 3.");
            }
            UperLength::encodeLength(writer, (*value.sD).size(), 3, 3);
            for (uint8_t byte : (*value.sD)) {
                writer.writeByte(byte);
            }
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SNSSAI
SNSSAI decode_SNSSAI(BitReader& reader) {
    SNSSAI value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        {
            size_t length = UperLength::decodeLength(reader, 1, 1);
            value.sST.resize(length);
            for (size_t i = 0; i < length; ++i) {
                value.sST[i] = reader.readByte();
            }
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.sD)::value_type t_1{};
            {
                size_t length = UperLength::decodeLength(reader, 3, 3);
                t_1.resize(length);
                for (size_t i = 0; i < length; ++i) {
                    t_1[i] = reader.readByte();
                }
            }
            value.sD.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for Slice_Support_Item
void encode_Slice_Support_Item(BitWriter& writer, const Slice_Support_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_SNSSAI(writer, value.sNSSAI);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for Slice_Support_Item
Slice_Support_Item decode_Slice_Support_Item(BitReader& reader) {
    Slice_Support_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.sNSSAI = decode_SNSSAI(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for Slice_Support_List
void encode_Slice_Support_List(BitWriter& writer, const Slice_Support_List& value) {
    if (value.size() < 1 || value.size() > 1024) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 1024].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 1024);
    for (const auto& element : value) {
        encode_Slice_Support_Item(writer, element);
    }
}

// Decoder for Slice_Support_List
Slice_Support_List decode_Slice_Support_List(BitReader& reader) {
    Slice_Support_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 1024);
        if (length < 1 || length > 1024) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 1024].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_Slice_Support_Item(reader);
        }
    }
    return value;
}

// Encoder for SDAP_Header_DL
void encode_SDAP_Header_DL(BitWriter& writer, const SDAP_Header_DL& value) {
    bool is_extended = true;
    switch (value) {
        case SDAP_Header_DL::present: is_extended = false; break;
        case SDAP_Header_DL::absent: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case SDAP_Header_DL::present: enum_index = 0; break;
            case SDAP_Header_DL::absent: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for SDAP_Header_DL
SDAP_Header_DL decode_SDAP_Header_DL(BitReader& reader) {
    SDAP_Header_DL value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = SDAP_Header_DL::present; break;
            case 1: value = SDAP_Header_DL::absent; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for SDAP_Header_UL
void encode_SDAP_Header_UL(BitWriter& writer, const SDAP_Header_UL& value) {
    bool is_extended = true;
    switch (value) {
        case SDAP_Header_UL::present: is_extended = false; break;
        case SDAP_Header_UL::absent: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case SDAP_Header_UL::present: enum_index = 0; break;
            case SDAP_Header_UL::absent: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for SDAP_Header_UL
SDAP_Header_UL decode_SDAP_Header_UL(BitReader& reader) {
    SDAP_Header_UL value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = SDAP_Header_UL::present; break;
            case 1: value = SDAP_Header_UL::absent; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for SDAP_Configuration
void encode_SDAP_Configuration(BitWriter& writer, const SDAP_Configuration& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_DefaultDRB(writer, value.defaultDRB);
        encode_SDAP_Header_UL(writer, value.sDAP_Header_UL);
        encode_SDAP_Header_DL(writer, value.sDAP_Header_DL);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SDAP_Configuration
SDAP_Configuration decode_SDAP_Configuration(BitReader& reader) {
    SDAP_Configuration value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.defaultDRB = decode_DefaultDRB(reader);
        value.sDAP_Header_UL = decode_SDAP_Header_UL(reader);
        value.sDAP_Header_DL = decode_SDAP_Header_DL(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for TimeToWait
void encode_TimeToWait(BitWriter& writer, const TimeToWait& value) {
    bool is_extended = true;
    switch (value) {
        case TimeToWait::v1s: is_extended = false; break;
        case TimeToWait::v2s: is_extended = false; break;
        case TimeToWait::v5s: is_extended = false; break;
        case TimeToWait::v10s: is_extended = false; break;
        case TimeToWait::v20s: is_extended = false; break;
        case TimeToWait::v60s: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case TimeToWait::v1s: enum_index = 0; break;
            case TimeToWait::v2s: enum_index = 1; break;
            case TimeToWait::v5s: enum_index = 2; break;
            case TimeToWait::v10s: enum_index = 3; break;
            case TimeToWait::v20s: enum_index = 4; break;
            case TimeToWait::v60s: enum_index = 5; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 6);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for TimeToWait
TimeToWait decode_TimeToWait(BitReader& reader) {
    TimeToWait value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 6);
        switch (enum_index) {
            case 0: value = TimeToWait::v1s; break;
            case 1: value = TimeToWait::v2s; break;
            case 2: value = TimeToWait::v5s; break;
            case 3: value = TimeToWait::v10s; break;
            case 4: value = TimeToWait::v20s; break;
            case 5: value = TimeToWait::v60s; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for TNLAssociationUsage
void encode_TNLAssociationUsage(BitWriter& writer, const TNLAssociationUsage& value) {
    bool is_extended = true;
    switch (value) {
        case TNLAssociationUsage::ue: is_extended = false; break;
        case TNLAssociationUsage::non_ue: is_extended = false; break;
        case TNLAssociationUsage::both: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case TNLAssociationUsage::ue: enum_index = 0; break;
            case TNLAssociationUsage::non_ue: enum_index = 1; break;
            case TNLAssociationUsage::both: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for TNLAssociationUsage
TNLAssociationUsage decode_TNLAssociationUsage(BitReader& reader) {
    TNLAssociationUsage value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = TNLAssociationUsage::ue; break;
            case 1: value = TNLAssociationUsage::non_ue; break;
            case 2: value = TNLAssociationUsage::both; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for TransportLayerAddress
void encode_TransportLayerAddress(BitWriter& writer, const TransportLayerAddress& value) {
    if (value.bit_length < 1 || value.bit_length > 160) {
        throw std::runtime_error("BIT STRING SIZE constraint violation: length " + std::to_string(value.bit_length) + " out of range [1, 160].");
    }
    UperLength::encodeLength(writer, value.bit_length, 1, 160);
    writer.writeBytes(value.data.data(), value.bit_length);
}

// Decoder for TransportLayerAddress
TransportLayerAddress decode_TransportLayerAddress(BitReader& reader) {
    TransportLayerAddress value{};
    {
        value.bit_length = UperLength::decodeLength(reader, 1, 160);
        if (value.bit_length < 1 || value.bit_length > 160) {
            throw std::runtime_error("BIT STRING SIZE constraint violation: decoded length " + std::to_string(value.bit_length) + " out of range [1, 160].");
        }
        size_t byte_length = (value.bit_length + 7) / 8;
        value.data.resize(byte_length);
        if (value.bit_length > 0) {
            reader.readBytes(value.data.data(), value.bit_length);
        }
    }
    return value;
}

// Encoder for CP_TNL_Information
void encode_CP_TNL_Information(BitWriter& writer, const CP_TNL_Information& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 2);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_TransportLayerAddress(writer, arg_1.endpoint_IP_Address);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for CP_TNL_Information
CP_TNL_Information decode_CP_TNL_Information(BitReader& reader) {
    CP_TNL_Information value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 2);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.endpoint_IP_Address = decode_TransportLayerAddress(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for Endpoint_IP_address_and_port
void encode_Endpoint_IP_address_and_port(BitWriter& writer, const Endpoint_IP_address_and_port& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_TransportLayerAddress(writer, value.endpoint_IP_Address);
        encode_PortNumber(writer, value.portNumber);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for Endpoint_IP_address_and_port
Endpoint_IP_address_and_port decode_Endpoint_IP_address_and_port(BitReader& reader) {
    Endpoint_IP_address_and_port value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.endpoint_IP_Address = decode_TransportLayerAddress(reader);
        value.portNumber = decode_PortNumber(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_Setup_Item
void encode_GNB_CU_CP_TNLA_Setup_Item(BitWriter& writer, const GNB_CU_CP_TNLA_Setup_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_TNLA_Setup_Item
GNB_CU_CP_TNLA_Setup_Item decode_GNB_CU_CP_TNLA_Setup_Item(BitReader& reader) {
    GNB_CU_CP_TNLA_Setup_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_Failed_To_Setup_Item
void encode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(BitWriter& writer, const GNB_CU_CP_TNLA_Failed_To_Setup_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        encode_Cause(writer, value.cause);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_CP_TNLA_Failed_To_Setup_Item
GNB_CU_CP_TNLA_Failed_To_Setup_Item decode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(BitReader& reader) {
    GNB_CU_CP_TNLA_Failed_To_Setup_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        value.cause = decode_Cause(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Add_Item
void encode_GNB_CU_CP_TNLA_To_Add_Item(BitWriter& writer, const GNB_CU_CP_TNLA_To_Add_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        encode_TNLAssociationUsage(writer, value.tNLAssociationUsage);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Add_Item
GNB_CU_CP_TNLA_To_Add_Item decode_GNB_CU_CP_TNLA_To_Add_Item(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Add_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        value.tNLAssociationUsage = decode_TNLAssociationUsage(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Remove_Item
void encode_GNB_CU_CP_TNLA_To_Remove_Item(BitWriter& writer, const GNB_CU_CP_TNLA_To_Remove_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Remove_Item
GNB_CU_CP_TNLA_To_Remove_Item decode_GNB_CU_CP_TNLA_To_Remove_Item(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Remove_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Update_Item
void encode_GNB_CU_CP_TNLA_To_Update_Item(BitWriter& writer, const GNB_CU_CP_TNLA_To_Update_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.tNLAssociationUsage.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        if (value.tNLAssociationUsage.has_value()) {
            encode_TNLAssociationUsage(writer, (*value.tNLAssociationUsage));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Update_Item
GNB_CU_CP_TNLA_To_Update_Item decode_GNB_CU_CP_TNLA_To_Update_Item(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Update_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.tNLAssociationUsage)::value_type t_1{};
            t_1 = decode_TNLAssociationUsage(reader);
            value.tNLAssociationUsage.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_TNLA_To_Remove_Item
void encode_GNB_CU_UP_TNLA_To_Remove_Item(BitWriter& writer, const GNB_CU_UP_TNLA_To_Remove_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.tNLAssociationTransportLayerAddressgNBCUCP.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_CP_TNL_Information(writer, value.tNLAssociationTransportLayerAddress);
        if (value.tNLAssociationTransportLayerAddressgNBCUCP.has_value()) {
            encode_CP_TNL_Information(writer, (*value.tNLAssociationTransportLayerAddressgNBCUCP));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_UP_TNLA_To_Remove_Item
GNB_CU_UP_TNLA_To_Remove_Item decode_GNB_CU_UP_TNLA_To_Remove_Item(BitReader& reader) {
    GNB_CU_UP_TNLA_To_Remove_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.tNLAssociationTransportLayerAddress = decode_CP_TNL_Information(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.tNLAssociationTransportLayerAddressgNBCUCP)::value_type t_1{};
            t_1 = decode_CP_TNL_Information(reader);
            value.tNLAssociationTransportLayerAddressgNBCUCP.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GTPTunnel
void encode_GTPTunnel(BitWriter& writer, const GTPTunnel& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_TransportLayerAddress(writer, value.transportLayerAddress);
        encode_GTP_TEID(writer, value.gTP_TEID);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GTPTunnel
GTPTunnel decode_GTPTunnel(BitReader& reader) {
    GTPTunnel value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.transportLayerAddress = decode_TransportLayerAddress(reader);
        value.gTP_TEID = decode_GTP_TEID(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for TransactionID
void encode_TransactionID(BitWriter& writer, const TransactionID& value) {
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value) + " out of range [0, 255].");
    }
    UperInteger::encodeConstrainedInt(writer, value, 0LL, 255LL);
}

// Decoder for TransactionID
TransactionID decode_TransactionID(BitReader& reader) {
    TransactionID value{};
    value = UperInteger::decodeConstrainedInt(reader, 0LL, 255LL);
    if (value < 0LL || value > 255LL) {
        throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value) + " out of range [0, 255].");
    }
    return value;
}

// Encoder for T_Reordering
void encode_T_Reordering(BitWriter& writer, const T_Reordering& value) {
    bool is_extended = true;
    switch (value) {
        case T_Reordering::ms0: is_extended = false; break;
        case T_Reordering::ms1: is_extended = false; break;
        case T_Reordering::ms2: is_extended = false; break;
        case T_Reordering::ms4: is_extended = false; break;
        case T_Reordering::ms5: is_extended = false; break;
        case T_Reordering::ms8: is_extended = false; break;
        case T_Reordering::ms10: is_extended = false; break;
        case T_Reordering::ms15: is_extended = false; break;
        case T_Reordering::ms20: is_extended = false; break;
        case T_Reordering::ms30: is_extended = false; break;
        case T_Reordering::ms40: is_extended = false; break;
        case T_Reordering::ms50: is_extended = false; break;
        case T_Reordering::ms60: is_extended = false; break;
        case T_Reordering::ms80: is_extended = false; break;
        case T_Reordering::ms100: is_extended = false; break;
        case T_Reordering::ms120: is_extended = false; break;
        case T_Reordering::ms140: is_extended = false; break;
        case T_Reordering::ms160: is_extended = false; break;
        case T_Reordering::ms180: is_extended = false; break;
        case T_Reordering::ms200: is_extended = false; break;
        case T_Reordering::ms220: is_extended = false; break;
        case T_Reordering::ms240: is_extended = false; break;
        case T_Reordering::ms260: is_extended = false; break;
        case T_Reordering::ms280: is_extended = false; break;
        case T_Reordering::ms300: is_extended = false; break;
        case T_Reordering::ms500: is_extended = false; break;
        case T_Reordering::ms750: is_extended = false; break;
        case T_Reordering::ms1000: is_extended = false; break;
        case T_Reordering::ms1250: is_extended = false; break;
        case T_Reordering::ms1500: is_extended = false; break;
        case T_Reordering::ms1750: is_extended = false; break;
        case T_Reordering::ms2000: is_extended = false; break;
        case T_Reordering::ms2250: is_extended = false; break;
        case T_Reordering::ms2500: is_extended = false; break;
        case T_Reordering::ms2750: is_extended = false; break;
        case T_Reordering::ms3000: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case T_Reordering::ms0: enum_index = 0; break;
            case T_Reordering::ms1: enum_index = 1; break;
            case T_Reordering::ms2: enum_index = 2; break;
            case T_Reordering::ms4: enum_index = 3; break;
            case T_Reordering::ms5: enum_index = 4; break;
            case T_Reordering::ms8: enum_index = 5; break;
            case T_Reordering::ms10: enum_index = 6; break;
            case T_Reordering::ms15: enum_index = 7; break;
            case T_Reordering::ms20: enum_index = 8; break;
            case T_Reordering::ms30: enum_index = 9; break;
            case T_Reordering::ms40: enum_index = 10; break;
            case T_Reordering::ms50: enum_index = 11; break;
            case T_Reordering::ms60: enum_index = 12; break;
            case T_Reordering::ms80: enum_index = 13; break;
            case T_Reordering::ms100: enum_index = 14; break;
            case T_Reordering::ms120: enum_index = 15; break;
            case T_Reordering::ms140: enum_index = 16; break;
            case T_Reordering::ms160: enum_index = 17; break;
            case T_Reordering::ms180: enum_index = 18; break;
            case T_Reordering::ms200: enum_index = 19; break;
            case T_Reordering::ms220: enum_index = 20; break;
            case T_Reordering::ms240: enum_index = 21; break;
            case T_Reordering::ms260: enum_index = 22; break;
            case T_Reordering::ms280: enum_index = 23; break;
            case T_Reordering::ms300: enum_index = 24; break;
            case T_Reordering::ms500: enum_index = 25; break;
            case T_Reordering::ms750: enum_index = 26; break;
            case T_Reordering::ms1000: enum_index = 27; break;
            case T_Reordering::ms1250: enum_index = 28; break;
            case T_Reordering::ms1500: enum_index = 29; break;
            case T_Reordering::ms1750: enum_index = 30; break;
            case T_Reordering::ms2000: enum_index = 31; break;
            case T_Reordering::ms2250: enum_index = 32; break;
            case T_Reordering::ms2500: enum_index = 33; break;
            case T_Reordering::ms2750: enum_index = 34; break;
            case T_Reordering::ms3000: enum_index = 35; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 36);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for T_Reordering
T_Reordering decode_T_Reordering(BitReader& reader) {
    T_Reordering value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 36);
        switch (enum_index) {
            case 0: value = T_Reordering::ms0; break;
            case 1: value = T_Reordering::ms1; break;
            case 2: value = T_Reordering::ms2; break;
            case 3: value = T_Reordering::ms4; break;
            case 4: value = T_Reordering::ms5; break;
            case 5: value = T_Reordering::ms8; break;
            case 6: value = T_Reordering::ms10; break;
            case 7: value = T_Reordering::ms15; break;
            case 8: value = T_Reordering::ms20; break;
            case 9: value = T_Reordering::ms30; break;
            case 10: value = T_Reordering::ms40; break;
            case 11: value = T_Reordering::ms50; break;
            case 12: value = T_Reordering::ms60; break;
            case 13: value = T_Reordering::ms80; break;
            case 14: value = T_Reordering::ms100; break;
            case 15: value = T_Reordering::ms120; break;
            case 16: value = T_Reordering::ms140; break;
            case 17: value = T_Reordering::ms160; break;
            case 18: value = T_Reordering::ms180; break;
            case 19: value = T_Reordering::ms200; break;
            case 20: value = T_Reordering::ms220; break;
            case 21: value = T_Reordering::ms240; break;
            case 22: value = T_Reordering::ms260; break;
            case 23: value = T_Reordering::ms280; break;
            case 24: value = T_Reordering::ms300; break;
            case 25: value = T_Reordering::ms500; break;
            case 26: value = T_Reordering::ms750; break;
            case 27: value = T_Reordering::ms1000; break;
            case 28: value = T_Reordering::ms1250; break;
            case 29: value = T_Reordering::ms1500; break;
            case 30: value = T_Reordering::ms1750; break;
            case 31: value = T_Reordering::ms2000; break;
            case 32: value = T_Reordering::ms2250; break;
            case 33: value = T_Reordering::ms2500; break;
            case 34: value = T_Reordering::ms2750; break;
            case 35: value = T_Reordering::ms3000; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for T_ReorderingTimer
void encode_T_ReorderingTimer(BitWriter& writer, const T_ReorderingTimer& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_T_Reordering(writer, value.t_Reordering);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for T_ReorderingTimer
T_ReorderingTimer decode_T_ReorderingTimer(BitReader& reader) {
    T_ReorderingTimer value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.t_Reordering = decode_T_Reordering(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for TypeOfError
void encode_TypeOfError(BitWriter& writer, const TypeOfError& value) {
    bool is_extended = true;
    switch (value) {
        case TypeOfError::not_understood: is_extended = false; break;
        case TypeOfError::missing: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case TypeOfError::not_understood: enum_index = 0; break;
            case TypeOfError::missing: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for TypeOfError
TypeOfError decode_TypeOfError(BitReader& reader) {
    TypeOfError value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = TypeOfError::not_understood; break;
            case 1: value = TypeOfError::missing; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for CriticalityDiagnostics_IE_List
void encode_CriticalityDiagnostics_IE_List(BitWriter& writer, const CriticalityDiagnostics_IE_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        {
            bool has_extensions = false;
            UperExtension::encodeExtensionMarker(writer, has_extensions);

            uint64_t presenceBitmap = 0;
            if (element.iE_Extensions.has_value()) {
                presenceBitmap |= (1ULL << 0);
            }
            UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

            E1AP_CommonDataTypes::encode_Criticality(writer, element.iECriticality);
            E1AP_CommonDataTypes::encode_ProtocolIE_ID(writer, element.iE_ID);
            encode_TypeOfError(writer, element.typeOfError);
            if (element.iE_Extensions.has_value()) {
                E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*element.iE_Extensions));
            }
            if (has_extensions) {
                uint64_t extension_bitmap = 0;
                UperLength::encodeUnconstrainedLength(writer, 0);
                writer.writeBits(extension_bitmap, 0);

                // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
            }
        }
    }
}

// Decoder for CriticalityDiagnostics_IE_List
CriticalityDiagnostics_IE_List decode_CriticalityDiagnostics_IE_List(BitReader& reader) {
    CriticalityDiagnostics_IE_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            {
                bool has_extensions = UperExtension::decodeExtensionMarker(reader);

                uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

                value[i].iECriticality = E1AP_CommonDataTypes::decode_Criticality(reader);
                value[i].iE_ID = E1AP_CommonDataTypes::decode_ProtocolIE_ID(reader);
                value[i].typeOfError = decode_TypeOfError(reader);
                if ((presenceBitmap >> 0) & 1) {
                    decltype(value[i].iE_Extensions)::value_type t_3{};
                    t_3 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
                    value[i].iE_Extensions.emplace(t_3);
                }
                if (has_extensions) {
                    size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
                    uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
                    for (size_t i = 0; i < num_extensions_in_message; ++i) {
                        if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                            value[i].unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                        }
                    }
                }
            }
        }
    }
    return value;
}

// Encoder for CriticalityDiagnostics
void encode_CriticalityDiagnostics(BitWriter& writer, const CriticalityDiagnostics& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.procedureCode.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.triggeringMessage.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.procedureCriticality.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.transactionID.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.iEsCriticalityDiagnostics.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 6);

        if (value.procedureCode.has_value()) {
            E1AP_CommonDataTypes::encode_ProcedureCode(writer, (*value.procedureCode));
        }
        if (value.triggeringMessage.has_value()) {
            E1AP_CommonDataTypes::encode_TriggeringMessage(writer, (*value.triggeringMessage));
        }
        if (value.procedureCriticality.has_value()) {
            E1AP_CommonDataTypes::encode_Criticality(writer, (*value.procedureCriticality));
        }
        if (value.transactionID.has_value()) {
            encode_TransactionID(writer, (*value.transactionID));
        }
        if (value.iEsCriticalityDiagnostics.has_value()) {
            encode_CriticalityDiagnostics_IE_List(writer, (*value.iEsCriticalityDiagnostics));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for CriticalityDiagnostics
CriticalityDiagnostics decode_CriticalityDiagnostics(BitReader& reader) {
    CriticalityDiagnostics value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 6);

        if ((presenceBitmap >> 5) & 1) {
            decltype(value.procedureCode)::value_type t_1{};
            t_1 = E1AP_CommonDataTypes::decode_ProcedureCode(reader);
            value.procedureCode.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.triggeringMessage)::value_type t_1{};
            t_1 = E1AP_CommonDataTypes::decode_TriggeringMessage(reader);
            value.triggeringMessage.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.procedureCriticality)::value_type t_1{};
            t_1 = E1AP_CommonDataTypes::decode_Criticality(reader);
            value.procedureCriticality.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.transactionID)::value_type t_1{};
            t_1 = decode_TransactionID(reader);
            value.transactionID.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.iEsCriticalityDiagnostics)::value_type t_1{};
            t_1 = decode_CriticalityDiagnostics_IE_List(reader);
            value.iEsCriticalityDiagnostics.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for UE_Activity
void encode_UE_Activity(BitWriter& writer, const UE_Activity& value) {
    bool is_extended = true;
    switch (value) {
        case UE_Activity::active: is_extended = false; break;
        case UE_Activity::not_active: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case UE_Activity::active: enum_index = 0; break;
            case UE_Activity::not_active: enum_index = 1; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 2);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for UE_Activity
UE_Activity decode_UE_Activity(BitReader& reader) {
    UE_Activity value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 2);
        switch (enum_index) {
            case 0: value = UE_Activity::active; break;
            case 1: value = UE_Activity::not_active; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for ActivityInformation
void encode_ActivityInformation(BitWriter& writer, const ActivityInformation& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 4);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_DRB_Activity_List(writer, arg_1.dRB_Activity_List);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_PDU_Session_Resource_Activity_List(writer, arg_1.pDU_Session_Resource_Activity_List);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                encode_UE_Activity(writer, arg_1.uE_Activity);
            }
            using WrapperType3 = std::variant_alternative_t<3, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType3>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for ActivityInformation
ActivityInformation decode_ActivityInformation(BitReader& reader) {
    ActivityInformation value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 4);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.dRB_Activity_List = decode_DRB_Activity_List(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.pDU_Session_Resource_Activity_List = decode_PDU_Session_Resource_Activity_List(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.uE_Activity = decode_UE_Activity(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        case 3: {
            using WrapperType = std::variant_alternative_t<3, std::decay_t<decltype(value)>>;
            WrapperType it_1_3;
            it_1_3.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_3);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for UE_associatedLogicalE1_ConnectionItem
void encode_UE_associatedLogicalE1_ConnectionItem(BitWriter& writer, const UE_associatedLogicalE1_ConnectionItem& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.gNB_CU_CP_UE_E1AP_ID.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.gNB_CU_UP_UE_E1AP_ID.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        if (value.gNB_CU_CP_UE_E1AP_ID.has_value()) {
            encode_GNB_CU_CP_UE_E1AP_ID(writer, (*value.gNB_CU_CP_UE_E1AP_ID));
        }
        if (value.gNB_CU_UP_UE_E1AP_ID.has_value()) {
            encode_GNB_CU_UP_UE_E1AP_ID(writer, (*value.gNB_CU_UP_UE_E1AP_ID));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for UE_associatedLogicalE1_ConnectionItem
UE_associatedLogicalE1_ConnectionItem decode_UE_associatedLogicalE1_ConnectionItem(BitReader& reader) {
    UE_associatedLogicalE1_ConnectionItem value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        if ((presenceBitmap >> 2) & 1) {
            decltype(value.gNB_CU_CP_UE_E1AP_ID)::value_type t_1{};
            t_1 = decode_GNB_CU_CP_UE_E1AP_ID(reader);
            value.gNB_CU_CP_UE_E1AP_ID.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.gNB_CU_UP_UE_E1AP_ID)::value_type t_1{};
            t_1 = decode_GNB_CU_UP_UE_E1AP_ID(reader);
            value.gNB_CU_UP_UE_E1AP_ID.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for UL_Configuration
void encode_UL_Configuration(BitWriter& writer, const UL_Configuration& value) {
    bool is_extended = true;
    switch (value) {
        case UL_Configuration::no_data: is_extended = false; break;
        case UL_Configuration::shared: is_extended = false; break;
        case UL_Configuration::only: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case UL_Configuration::no_data: enum_index = 0; break;
            case UL_Configuration::shared: enum_index = 1; break;
            case UL_Configuration::only: enum_index = 2; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 3);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for UL_Configuration
UL_Configuration decode_UL_Configuration(BitReader& reader) {
    UL_Configuration value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 3);
        switch (enum_index) {
            case 0: value = UL_Configuration::no_data; break;
            case 1: value = UL_Configuration::shared; break;
            case 2: value = UL_Configuration::only; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for Cell_Group_Information_Item
void encode_Cell_Group_Information_Item(BitWriter& writer, const Cell_Group_Information_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.uL_Configuration.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dL_TX_Stop.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.rAT_Type.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_Cell_Group_ID(writer, value.cell_Group_ID);
        if (value.uL_Configuration.has_value()) {
            encode_UL_Configuration(writer, (*value.uL_Configuration));
        }
        if (value.dL_TX_Stop.has_value()) {
            encode_DL_TX_Stop(writer, (*value.dL_TX_Stop));
        }
        if (value.rAT_Type.has_value()) {
            encode_RAT_Type(writer, (*value.rAT_Type));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Cell_Group_Information_Item
Cell_Group_Information_Item decode_Cell_Group_Information_Item(BitReader& reader) {
    Cell_Group_Information_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.cell_Group_ID = decode_Cell_Group_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.uL_Configuration)::value_type t_1{};
            t_1 = decode_UL_Configuration(reader);
            value.uL_Configuration.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dL_TX_Stop)::value_type t_1{};
            t_1 = decode_DL_TX_Stop(reader);
            value.dL_TX_Stop.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.rAT_Type)::value_type t_1{};
            t_1 = decode_RAT_Type(reader);
            value.rAT_Type.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for Cell_Group_Information
void encode_Cell_Group_Information(BitWriter& writer, const Cell_Group_Information& value) {
    if (value.size() < 1 || value.size() > 4) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 4].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 4);
    for (const auto& element : value) {
        encode_Cell_Group_Information_Item(writer, element);
    }
}

// Decoder for Cell_Group_Information
Cell_Group_Information decode_Cell_Group_Information(BitReader& reader) {
    Cell_Group_Information value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 4);
        if (length < 1 || length > 4) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 4].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_Cell_Group_Information_Item(reader);
        }
    }
    return value;
}

// Encoder for DRB_Confirm_Modified_Item_EUTRAN
void encode_DRB_Confirm_Modified_Item_EUTRAN(BitWriter& writer, const DRB_Confirm_Modified_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.cell_Group_Information.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.cell_Group_Information.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_Information));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Confirm_Modified_Item_EUTRAN
DRB_Confirm_Modified_Item_EUTRAN decode_DRB_Confirm_Modified_Item_EUTRAN(BitReader& reader) {
    DRB_Confirm_Modified_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.cell_Group_Information)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Confirm_Modified_List_EUTRAN
void encode_DRB_Confirm_Modified_List_EUTRAN(BitWriter& writer, const DRB_Confirm_Modified_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Confirm_Modified_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Confirm_Modified_List_EUTRAN
DRB_Confirm_Modified_List_EUTRAN decode_DRB_Confirm_Modified_List_EUTRAN(BitReader& reader) {
    DRB_Confirm_Modified_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Confirm_Modified_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Confirm_Modified_Item_NG_RAN
void encode_DRB_Confirm_Modified_Item_NG_RAN(BitWriter& writer, const DRB_Confirm_Modified_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.cell_Group_Information.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.cell_Group_Information.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_Information));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Confirm_Modified_Item_NG_RAN
DRB_Confirm_Modified_Item_NG_RAN decode_DRB_Confirm_Modified_Item_NG_RAN(BitReader& reader) {
    DRB_Confirm_Modified_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.cell_Group_Information)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Confirm_Modified_List_NG_RAN
void encode_DRB_Confirm_Modified_List_NG_RAN(BitWriter& writer, const DRB_Confirm_Modified_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Confirm_Modified_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Confirm_Modified_List_NG_RAN
DRB_Confirm_Modified_List_NG_RAN decode_DRB_Confirm_Modified_List_NG_RAN(BitReader& reader) {
    DRB_Confirm_Modified_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Confirm_Modified_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Confirm_Modified_Item
void encode_PDU_Session_Resource_Confirm_Modified_Item(BitWriter& writer, const PDU_Session_Resource_Confirm_Modified_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.dRB_Confirm_Modified_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.dRB_Confirm_Modified_List_NG_RAN.has_value()) {
            encode_DRB_Confirm_Modified_List_NG_RAN(writer, (*value.dRB_Confirm_Modified_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Confirm_Modified_Item
PDU_Session_Resource_Confirm_Modified_Item decode_PDU_Session_Resource_Confirm_Modified_Item(BitReader& reader) {
    PDU_Session_Resource_Confirm_Modified_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Confirm_Modified_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Confirm_Modified_List_NG_RAN(reader);
            value.dRB_Confirm_Modified_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Confirm_Modified_List
void encode_PDU_Session_Resource_Confirm_Modified_List(BitWriter& writer, const PDU_Session_Resource_Confirm_Modified_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Confirm_Modified_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Confirm_Modified_List
PDU_Session_Resource_Confirm_Modified_List decode_PDU_Session_Resource_Confirm_Modified_List(BitReader& reader) {
    PDU_Session_Resource_Confirm_Modified_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Confirm_Modified_Item(reader);
        }
    }
    return value;
}

// Encoder for ULDataSplitThreshold
void encode_ULDataSplitThreshold(BitWriter& writer, const ULDataSplitThreshold& value) {
    bool is_extended = true;
    switch (value) {
        case ULDataSplitThreshold::b0: is_extended = false; break;
        case ULDataSplitThreshold::b100: is_extended = false; break;
        case ULDataSplitThreshold::b200: is_extended = false; break;
        case ULDataSplitThreshold::b400: is_extended = false; break;
        case ULDataSplitThreshold::b800: is_extended = false; break;
        case ULDataSplitThreshold::b1600: is_extended = false; break;
        case ULDataSplitThreshold::b3200: is_extended = false; break;
        case ULDataSplitThreshold::b6400: is_extended = false; break;
        case ULDataSplitThreshold::b12800: is_extended = false; break;
        case ULDataSplitThreshold::b25600: is_extended = false; break;
        case ULDataSplitThreshold::b51200: is_extended = false; break;
        case ULDataSplitThreshold::b102400: is_extended = false; break;
        case ULDataSplitThreshold::b204800: is_extended = false; break;
        case ULDataSplitThreshold::b409600: is_extended = false; break;
        case ULDataSplitThreshold::b819200: is_extended = false; break;
        case ULDataSplitThreshold::b1228800: is_extended = false; break;
        case ULDataSplitThreshold::b1638400: is_extended = false; break;
        case ULDataSplitThreshold::b2457600: is_extended = false; break;
        case ULDataSplitThreshold::b3276800: is_extended = false; break;
        case ULDataSplitThreshold::b4096000: is_extended = false; break;
        case ULDataSplitThreshold::b4915200: is_extended = false; break;
        case ULDataSplitThreshold::b5734400: is_extended = false; break;
        case ULDataSplitThreshold::b6553600: is_extended = false; break;
        case ULDataSplitThreshold::infinity: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case ULDataSplitThreshold::b0: enum_index = 0; break;
            case ULDataSplitThreshold::b100: enum_index = 1; break;
            case ULDataSplitThreshold::b200: enum_index = 2; break;
            case ULDataSplitThreshold::b400: enum_index = 3; break;
            case ULDataSplitThreshold::b800: enum_index = 4; break;
            case ULDataSplitThreshold::b1600: enum_index = 5; break;
            case ULDataSplitThreshold::b3200: enum_index = 6; break;
            case ULDataSplitThreshold::b6400: enum_index = 7; break;
            case ULDataSplitThreshold::b12800: enum_index = 8; break;
            case ULDataSplitThreshold::b25600: enum_index = 9; break;
            case ULDataSplitThreshold::b51200: enum_index = 10; break;
            case ULDataSplitThreshold::b102400: enum_index = 11; break;
            case ULDataSplitThreshold::b204800: enum_index = 12; break;
            case ULDataSplitThreshold::b409600: enum_index = 13; break;
            case ULDataSplitThreshold::b819200: enum_index = 14; break;
            case ULDataSplitThreshold::b1228800: enum_index = 15; break;
            case ULDataSplitThreshold::b1638400: enum_index = 16; break;
            case ULDataSplitThreshold::b2457600: enum_index = 17; break;
            case ULDataSplitThreshold::b3276800: enum_index = 18; break;
            case ULDataSplitThreshold::b4096000: enum_index = 19; break;
            case ULDataSplitThreshold::b4915200: enum_index = 20; break;
            case ULDataSplitThreshold::b5734400: enum_index = 21; break;
            case ULDataSplitThreshold::b6553600: enum_index = 22; break;
            case ULDataSplitThreshold::infinity: enum_index = 23; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 24);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for ULDataSplitThreshold
ULDataSplitThreshold decode_ULDataSplitThreshold(BitReader& reader) {
    ULDataSplitThreshold value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 24);
        switch (enum_index) {
            case 0: value = ULDataSplitThreshold::b0; break;
            case 1: value = ULDataSplitThreshold::b100; break;
            case 2: value = ULDataSplitThreshold::b200; break;
            case 3: value = ULDataSplitThreshold::b400; break;
            case 4: value = ULDataSplitThreshold::b800; break;
            case 5: value = ULDataSplitThreshold::b1600; break;
            case 6: value = ULDataSplitThreshold::b3200; break;
            case 7: value = ULDataSplitThreshold::b6400; break;
            case 8: value = ULDataSplitThreshold::b12800; break;
            case 9: value = ULDataSplitThreshold::b25600; break;
            case 10: value = ULDataSplitThreshold::b51200; break;
            case 11: value = ULDataSplitThreshold::b102400; break;
            case 12: value = ULDataSplitThreshold::b204800; break;
            case 13: value = ULDataSplitThreshold::b409600; break;
            case 14: value = ULDataSplitThreshold::b819200; break;
            case 15: value = ULDataSplitThreshold::b1228800; break;
            case 16: value = ULDataSplitThreshold::b1638400; break;
            case 17: value = ULDataSplitThreshold::b2457600; break;
            case 18: value = ULDataSplitThreshold::b3276800; break;
            case 19: value = ULDataSplitThreshold::b4096000; break;
            case 20: value = ULDataSplitThreshold::b4915200; break;
            case 21: value = ULDataSplitThreshold::b5734400; break;
            case 22: value = ULDataSplitThreshold::b6553600; break;
            case 23: value = ULDataSplitThreshold::infinity; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for UPSecuritykey
void encode_UPSecuritykey(BitWriter& writer, const UPSecuritykey& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.integrityProtectionKey.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_EncryptionKey(writer, value.encryptionKey);
        if (value.integrityProtectionKey.has_value()) {
            encode_IntegrityProtectionKey(writer, (*value.integrityProtectionKey));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for UPSecuritykey
UPSecuritykey decode_UPSecuritykey(BitReader& reader) {
    UPSecuritykey value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.encryptionKey = decode_EncryptionKey(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.integrityProtectionKey)::value_type t_1{};
            t_1 = decode_IntegrityProtectionKey(reader);
            value.integrityProtectionKey.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SecurityInformation
void encode_SecurityInformation(BitWriter& writer, const SecurityInformation& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_SecurityAlgorithm(writer, value.securityAlgorithm);
        encode_UPSecuritykey(writer, value.uPSecuritykey);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SecurityInformation
SecurityInformation decode_SecurityInformation(BitReader& reader) {
    SecurityInformation value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.securityAlgorithm = decode_SecurityAlgorithm(reader);
        value.uPSecuritykey = decode_UPSecuritykey(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for UP_TNL_Information
void encode_UP_TNL_Information(BitWriter& writer, const UP_TNL_Information& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 2);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_GTPTunnel(writer, arg_1.gTPTunnel);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for UP_TNL_Information
UP_TNL_Information decode_UP_TNL_Information(BitReader& reader) {
    UP_TNL_Information value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 2);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.gTPTunnel = decode_GTPTunnel(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for Data_Forwarding_Information
void encode_Data_Forwarding_Information(BitWriter& writer, const Data_Forwarding_Information& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.uL_Data_Forwarding.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dL_Data_Forwarding.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        if (value.uL_Data_Forwarding.has_value()) {
            encode_UP_TNL_Information(writer, (*value.uL_Data_Forwarding));
        }
        if (value.dL_Data_Forwarding.has_value()) {
            encode_UP_TNL_Information(writer, (*value.dL_Data_Forwarding));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Data_Forwarding_Information
Data_Forwarding_Information decode_Data_Forwarding_Information(BitReader& reader) {
    Data_Forwarding_Information value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        if ((presenceBitmap >> 2) & 1) {
            decltype(value.uL_Data_Forwarding)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.uL_Data_Forwarding.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dL_Data_Forwarding)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.dL_Data_Forwarding.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_CellGroupRelatedConfiguration_Item
void encode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(BitWriter& writer, const GNB_CU_UP_CellGroupRelatedConfiguration_Item& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.uL_Configuration.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_Cell_Group_ID(writer, value.cell_Group_ID);
        encode_UP_TNL_Information(writer, value.uP_TNL_Information);
        if (value.uL_Configuration.has_value()) {
            encode_UL_Configuration(writer, (*value.uL_Configuration));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for GNB_CU_UP_CellGroupRelatedConfiguration_Item
GNB_CU_UP_CellGroupRelatedConfiguration_Item decode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(BitReader& reader) {
    GNB_CU_UP_CellGroupRelatedConfiguration_Item value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.cell_Group_ID = decode_Cell_Group_ID(reader);
        value.uP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.uL_Configuration)::value_type t_1{};
            t_1 = decode_UL_Configuration(reader);
            value.uL_Configuration.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_CellGroupRelatedConfiguration
void encode_GNB_CU_UP_CellGroupRelatedConfiguration(BitWriter& writer, const GNB_CU_UP_CellGroupRelatedConfiguration& value) {
    if (value.size() < 1 || value.size() > 8) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 8].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 8);
    for (const auto& element : value) {
        encode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(writer, element);
    }
}

// Decoder for GNB_CU_UP_CellGroupRelatedConfiguration
GNB_CU_UP_CellGroupRelatedConfiguration decode_GNB_CU_UP_CellGroupRelatedConfiguration(BitReader& reader) {
    GNB_CU_UP_CellGroupRelatedConfiguration value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 8);
        if (length < 1 || length > 8) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 8].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_GNB_CU_UP_CellGroupRelatedConfiguration_Item(reader);
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Modify_Item_EUTRAN
void encode_DRB_Required_To_Modify_Item_EUTRAN(BitWriter& writer, const DRB_Required_To_Modify_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.s1_DL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.cause.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.s1_DL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.s1_DL_UP_TNL_Information));
        }
        if (value.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
            encode_GNB_CU_UP_CellGroupRelatedConfiguration(writer, (*value.gNB_CU_UP_CellGroupRelatedConfiguration));
        }
        if (value.cause.has_value()) {
            encode_Cause(writer, (*value.cause));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Required_To_Modify_Item_EUTRAN
DRB_Required_To_Modify_Item_EUTRAN decode_DRB_Required_To_Modify_Item_EUTRAN(BitReader& reader) {
    DRB_Required_To_Modify_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.s1_DL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.s1_DL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.gNB_CU_UP_CellGroupRelatedConfiguration)::value_type t_1{};
            t_1 = decode_GNB_CU_UP_CellGroupRelatedConfiguration(reader);
            value.gNB_CU_UP_CellGroupRelatedConfiguration.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.cause)::value_type t_1{};
            t_1 = decode_Cause(reader);
            value.cause.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Modify_List_EUTRAN
void encode_DRB_Required_To_Modify_List_EUTRAN(BitWriter& writer, const DRB_Required_To_Modify_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Required_To_Modify_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Required_To_Modify_List_EUTRAN
DRB_Required_To_Modify_List_EUTRAN decode_DRB_Required_To_Modify_List_EUTRAN(BitReader& reader) {
    DRB_Required_To_Modify_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Required_To_Modify_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Modify_Item_NG_RAN
void encode_DRB_Required_To_Modify_Item_NG_RAN(BitWriter& writer, const DRB_Required_To_Modify_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.flow_To_Remove.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.cause.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.gNB_CU_UP_CellGroupRelatedConfiguration.has_value()) {
            encode_GNB_CU_UP_CellGroupRelatedConfiguration(writer, (*value.gNB_CU_UP_CellGroupRelatedConfiguration));
        }
        if (value.flow_To_Remove.has_value()) {
            encode_QoS_Flow_List(writer, (*value.flow_To_Remove));
        }
        if (value.cause.has_value()) {
            encode_Cause(writer, (*value.cause));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Required_To_Modify_Item_NG_RAN
DRB_Required_To_Modify_Item_NG_RAN decode_DRB_Required_To_Modify_Item_NG_RAN(BitReader& reader) {
    DRB_Required_To_Modify_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.gNB_CU_UP_CellGroupRelatedConfiguration)::value_type t_1{};
            t_1 = decode_GNB_CU_UP_CellGroupRelatedConfiguration(reader);
            value.gNB_CU_UP_CellGroupRelatedConfiguration.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.flow_To_Remove)::value_type t_1{};
            t_1 = decode_QoS_Flow_List(reader);
            value.flow_To_Remove.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.cause)::value_type t_1{};
            t_1 = decode_Cause(reader);
            value.cause.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Required_To_Modify_List_NG_RAN
void encode_DRB_Required_To_Modify_List_NG_RAN(BitWriter& writer, const DRB_Required_To_Modify_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Required_To_Modify_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Required_To_Modify_List_NG_RAN
DRB_Required_To_Modify_List_NG_RAN decode_DRB_Required_To_Modify_List_NG_RAN(BitReader& reader) {
    DRB_Required_To_Modify_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Required_To_Modify_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Required_To_Modify_Item
void encode_PDU_Session_Resource_Required_To_Modify_Item(BitWriter& writer, const PDU_Session_Resource_Required_To_Modify_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.nG_DL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_Required_To_Modify_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Required_To_Remove_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.nG_DL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.nG_DL_UP_TNL_Information));
        }
        if (value.dRB_Required_To_Modify_List_NG_RAN.has_value()) {
            encode_DRB_Required_To_Modify_List_NG_RAN(writer, (*value.dRB_Required_To_Modify_List_NG_RAN));
        }
        if (value.dRB_Required_To_Remove_List_NG_RAN.has_value()) {
            encode_DRB_Required_To_Remove_List_NG_RAN(writer, (*value.dRB_Required_To_Remove_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Required_To_Modify_Item
PDU_Session_Resource_Required_To_Modify_Item decode_PDU_Session_Resource_Required_To_Modify_Item(BitReader& reader) {
    PDU_Session_Resource_Required_To_Modify_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.nG_DL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.nG_DL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_Required_To_Modify_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Required_To_Modify_List_NG_RAN(reader);
            value.dRB_Required_To_Modify_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Required_To_Remove_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Required_To_Remove_List_NG_RAN(reader);
            value.dRB_Required_To_Remove_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Required_To_Modify_List
void encode_PDU_Session_Resource_Required_To_Modify_List(BitWriter& writer, const PDU_Session_Resource_Required_To_Modify_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Required_To_Modify_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Required_To_Modify_List
PDU_Session_Resource_Required_To_Modify_List decode_PDU_Session_Resource_Required_To_Modify_List(BitReader& reader) {
    PDU_Session_Resource_Required_To_Modify_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Required_To_Modify_Item(reader);
        }
    }
    return value;
}

// Encoder for UP_Parameters_Item
void encode_UP_Parameters_Item(BitWriter& writer, const UP_Parameters_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 1);

        encode_UP_TNL_Information(writer, value.uP_TNL_Information);
        encode_Cell_Group_ID(writer, value.cell_Group_ID);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for UP_Parameters_Item
UP_Parameters_Item decode_UP_Parameters_Item(BitReader& reader) {
    UP_Parameters_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 1);

        value.uP_TNL_Information = decode_UP_TNL_Information(reader);
        value.cell_Group_ID = decode_Cell_Group_ID(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for UP_Parameters
void encode_UP_Parameters(BitWriter& writer, const UP_Parameters& value) {
    if (value.size() < 1 || value.size() > 8) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 8].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 8);
    for (const auto& element : value) {
        encode_UP_Parameters_Item(writer, element);
    }
}

// Decoder for UP_Parameters
UP_Parameters decode_UP_Parameters(BitReader& reader) {
    UP_Parameters value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 8);
        if (length < 1 || length > 8) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 8].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_UP_Parameters_Item(reader);
        }
    }
    return value;
}

// Encoder for DRB_Modified_Item_EUTRAN
void encode_DRB_Modified_Item_EUTRAN(BitWriter& writer, const DRB_Modified_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.s1_DL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.uL_UP_Transport_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.s1_DL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.s1_DL_UP_TNL_Information));
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pDCP_SN_Status_Information));
        }
        if (value.uL_UP_Transport_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.uL_UP_Transport_Parameters));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Modified_Item_EUTRAN
DRB_Modified_Item_EUTRAN decode_DRB_Modified_Item_EUTRAN(BitReader& reader) {
    DRB_Modified_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.s1_DL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.s1_DL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.pDCP_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pDCP_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.uL_UP_Transport_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.uL_UP_Transport_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Modified_List_EUTRAN
void encode_DRB_Modified_List_EUTRAN(BitWriter& writer, const DRB_Modified_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Modified_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Modified_List_EUTRAN
DRB_Modified_List_EUTRAN decode_DRB_Modified_List_EUTRAN(BitReader& reader) {
    DRB_Modified_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Modified_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Modified_Item_NG_RAN
void encode_DRB_Modified_Item_NG_RAN(BitWriter& writer, const DRB_Modified_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.uL_UP_Transport_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.flow_Setup_List.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.flow_Failed_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 5);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.uL_UP_Transport_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.uL_UP_Transport_Parameters));
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pDCP_SN_Status_Information));
        }
        if (value.flow_Setup_List.has_value()) {
            encode_QoS_Flow_List(writer, (*value.flow_Setup_List));
        }
        if (value.flow_Failed_List.has_value()) {
            encode_QoS_Flow_Failed_List(writer, (*value.flow_Failed_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Modified_Item_NG_RAN
DRB_Modified_Item_NG_RAN decode_DRB_Modified_Item_NG_RAN(BitReader& reader) {
    DRB_Modified_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 5);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.uL_UP_Transport_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.uL_UP_Transport_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.pDCP_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pDCP_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.flow_Setup_List)::value_type t_1{};
            t_1 = decode_QoS_Flow_List(reader);
            value.flow_Setup_List.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.flow_Failed_List)::value_type t_1{};
            t_1 = decode_QoS_Flow_Failed_List(reader);
            value.flow_Failed_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Modified_List_NG_RAN
void encode_DRB_Modified_List_NG_RAN(BitWriter& writer, const DRB_Modified_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Modified_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Modified_List_NG_RAN
DRB_Modified_List_NG_RAN decode_DRB_Modified_List_NG_RAN(BitReader& reader) {
    DRB_Modified_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Modified_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Setup_Item_EUTRAN
void encode_DRB_Setup_Item_EUTRAN(BitWriter& writer, const DRB_Setup_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.s1_DL_UP_Unchanged.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_UP_TNL_Information(writer, value.s1_DL_UP_TNL_Information);
        if (value.data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.data_Forwarding_Information_Response));
        }
        encode_UP_Parameters(writer, value.uL_UP_Transport_Parameters);
        if (value.s1_DL_UP_Unchanged.has_value()) {
            bool is_extended = true;
            switch ((*value.s1_DL_UP_Unchanged)) {
                case std::decay_t<decltype((*value.s1_DL_UP_Unchanged))>::true_: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.s1_DL_UP_Unchanged)) {
                    case std::decay_t<decltype((*value.s1_DL_UP_Unchanged))>::true_: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Setup_Item_EUTRAN
DRB_Setup_Item_EUTRAN decode_DRB_Setup_Item_EUTRAN(BitReader& reader) {
    DRB_Setup_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        value.dRB_ID = decode_DRB_ID(reader);
        value.s1_DL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.data_Forwarding_Information_Response.emplace(t_1);
        }
        value.uL_UP_Transport_Parameters = decode_UP_Parameters(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.s1_DL_UP_Unchanged)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::true_; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.s1_DL_UP_Unchanged.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Setup_List_EUTRAN
void encode_DRB_Setup_List_EUTRAN(BitWriter& writer, const DRB_Setup_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Setup_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Setup_List_EUTRAN
DRB_Setup_List_EUTRAN decode_DRB_Setup_List_EUTRAN(BitReader& reader) {
    DRB_Setup_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Setup_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Setup_Mod_Item_EUTRAN
void encode_DRB_Setup_Mod_Item_EUTRAN(BitWriter& writer, const DRB_Setup_Mod_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_UP_TNL_Information(writer, value.s1_DL_UP_TNL_Information);
        if (value.data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.data_Forwarding_Information_Response));
        }
        encode_UP_Parameters(writer, value.uL_UP_Transport_Parameters);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Setup_Mod_Item_EUTRAN
DRB_Setup_Mod_Item_EUTRAN decode_DRB_Setup_Mod_Item_EUTRAN(BitReader& reader) {
    DRB_Setup_Mod_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.dRB_ID = decode_DRB_ID(reader);
        value.s1_DL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.data_Forwarding_Information_Response.emplace(t_1);
        }
        value.uL_UP_Transport_Parameters = decode_UP_Parameters(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Setup_Mod_List_EUTRAN
void encode_DRB_Setup_Mod_List_EUTRAN(BitWriter& writer, const DRB_Setup_Mod_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Setup_Mod_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_Setup_Mod_List_EUTRAN
DRB_Setup_Mod_List_EUTRAN decode_DRB_Setup_Mod_List_EUTRAN(BitReader& reader) {
    DRB_Setup_Mod_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Setup_Mod_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Setup_Item_NG_RAN
void encode_DRB_Setup_Item_NG_RAN(BitWriter& writer, const DRB_Setup_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.dRB_data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.flow_Failed_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.dRB_data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.dRB_data_Forwarding_Information_Response));
        }
        encode_UP_Parameters(writer, value.uL_UP_Transport_Parameters);
        encode_QoS_Flow_List(writer, value.flow_Setup_List);
        if (value.flow_Failed_List.has_value()) {
            encode_QoS_Flow_Failed_List(writer, (*value.flow_Failed_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Setup_Item_NG_RAN
DRB_Setup_Item_NG_RAN decode_DRB_Setup_Item_NG_RAN(BitReader& reader) {
    DRB_Setup_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.dRB_data_Forwarding_Information_Response.emplace(t_1);
        }
        value.uL_UP_Transport_Parameters = decode_UP_Parameters(reader);
        value.flow_Setup_List = decode_QoS_Flow_List(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.flow_Failed_List)::value_type t_1{};
            t_1 = decode_QoS_Flow_Failed_List(reader);
            value.flow_Failed_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Setup_List_NG_RAN
void encode_DRB_Setup_List_NG_RAN(BitWriter& writer, const DRB_Setup_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Setup_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Setup_List_NG_RAN
DRB_Setup_List_NG_RAN decode_DRB_Setup_List_NG_RAN(BitReader& reader) {
    DRB_Setup_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Setup_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_Setup_Mod_Item_NG_RAN
void encode_DRB_Setup_Mod_Item_NG_RAN(BitWriter& writer, const DRB_Setup_Mod_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.dRB_data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.flow_Failed_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 3);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.dRB_data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.dRB_data_Forwarding_Information_Response));
        }
        encode_UP_Parameters(writer, value.uL_UP_Transport_Parameters);
        encode_QoS_Flow_List(writer, value.flow_Setup_List);
        if (value.flow_Failed_List.has_value()) {
            encode_QoS_Flow_Failed_List(writer, (*value.flow_Failed_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_Setup_Mod_Item_NG_RAN
DRB_Setup_Mod_Item_NG_RAN decode_DRB_Setup_Mod_Item_NG_RAN(BitReader& reader) {
    DRB_Setup_Mod_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 3);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.dRB_data_Forwarding_Information_Response.emplace(t_1);
        }
        value.uL_UP_Transport_Parameters = decode_UP_Parameters(reader);
        value.flow_Setup_List = decode_QoS_Flow_List(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.flow_Failed_List)::value_type t_1{};
            t_1 = decode_QoS_Flow_Failed_List(reader);
            value.flow_Failed_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Setup_Mod_List_NG_RAN
void encode_DRB_Setup_Mod_List_NG_RAN(BitWriter& writer, const DRB_Setup_Mod_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_Setup_Mod_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_Setup_Mod_List_NG_RAN
DRB_Setup_Mod_List_NG_RAN decode_DRB_Setup_Mod_List_NG_RAN(BitReader& reader) {
    DRB_Setup_Mod_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_Setup_Mod_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Modified_Item
void encode_PDU_Session_Resource_Modified_Item(BitWriter& writer, const PDU_Session_Resource_Modified_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.nG_DL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 7);
        }
        if (value.securityResult.has_value()) {
            presenceBitmap |= (1ULL << 6);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.dRB_Setup_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.dRB_Failed_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_Modified_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Failed_To_Modify_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 8);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.nG_DL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.nG_DL_UP_TNL_Information));
        }
        if (value.securityResult.has_value()) {
            encode_SecurityResult(writer, (*value.securityResult));
        }
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.pDU_Session_Data_Forwarding_Information_Response));
        }
        if (value.dRB_Setup_List_NG_RAN.has_value()) {
            encode_DRB_Setup_List_NG_RAN(writer, (*value.dRB_Setup_List_NG_RAN));
        }
        if (value.dRB_Failed_List_NG_RAN.has_value()) {
            encode_DRB_Failed_List_NG_RAN(writer, (*value.dRB_Failed_List_NG_RAN));
        }
        if (value.dRB_Modified_List_NG_RAN.has_value()) {
            encode_DRB_Modified_List_NG_RAN(writer, (*value.dRB_Modified_List_NG_RAN));
        }
        if (value.dRB_Failed_To_Modify_List_NG_RAN.has_value()) {
            encode_DRB_Failed_To_Modify_List_NG_RAN(writer, (*value.dRB_Failed_To_Modify_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Modified_Item
PDU_Session_Resource_Modified_Item decode_PDU_Session_Resource_Modified_Item(BitReader& reader) {
    PDU_Session_Resource_Modified_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 8);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 7) & 1) {
            decltype(value.nG_DL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.nG_DL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 6) & 1) {
            decltype(value.securityResult)::value_type t_1{};
            t_1 = decode_SecurityResult(reader);
            value.securityResult.emplace(t_1);
        }
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.pDU_Session_Data_Forwarding_Information_Response.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.dRB_Setup_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Setup_List_NG_RAN(reader);
            value.dRB_Setup_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.dRB_Failed_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Failed_List_NG_RAN(reader);
            value.dRB_Failed_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_Modified_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Modified_List_NG_RAN(reader);
            value.dRB_Modified_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Failed_To_Modify_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Failed_To_Modify_List_NG_RAN(reader);
            value.dRB_Failed_To_Modify_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Modified_List
void encode_PDU_Session_Resource_Modified_List(BitWriter& writer, const PDU_Session_Resource_Modified_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Modified_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Modified_List
PDU_Session_Resource_Modified_List decode_PDU_Session_Resource_Modified_List(BitReader& reader) {
    PDU_Session_Resource_Modified_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Modified_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Setup_Item
void encode_PDU_Session_Resource_Setup_Item(BitWriter& writer, const PDU_Session_Resource_Setup_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.securityResult.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.nG_DL_UP_Unchanged.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Failed_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 5);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.securityResult.has_value()) {
            encode_SecurityResult(writer, (*value.securityResult));
        }
        encode_UP_TNL_Information(writer, value.nG_DL_UP_TNL_Information);
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.pDU_Session_Data_Forwarding_Information_Response));
        }
        if (value.nG_DL_UP_Unchanged.has_value()) {
            bool is_extended = true;
            switch ((*value.nG_DL_UP_Unchanged)) {
                case std::decay_t<decltype((*value.nG_DL_UP_Unchanged))>::true_: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.nG_DL_UP_Unchanged)) {
                    case std::decay_t<decltype((*value.nG_DL_UP_Unchanged))>::true_: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        encode_DRB_Setup_List_NG_RAN(writer, value.dRB_Setup_List_NG_RAN);
        if (value.dRB_Failed_List_NG_RAN.has_value()) {
            encode_DRB_Failed_List_NG_RAN(writer, (*value.dRB_Failed_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Setup_Item
PDU_Session_Resource_Setup_Item decode_PDU_Session_Resource_Setup_Item(BitReader& reader) {
    PDU_Session_Resource_Setup_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 5);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.securityResult)::value_type t_1{};
            t_1 = decode_SecurityResult(reader);
            value.securityResult.emplace(t_1);
        }
        value.nG_DL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.pDU_Session_Data_Forwarding_Information_Response.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.nG_DL_UP_Unchanged)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::true_; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.nG_DL_UP_Unchanged.emplace(t_1);
        }
        value.dRB_Setup_List_NG_RAN = decode_DRB_Setup_List_NG_RAN(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Failed_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Failed_List_NG_RAN(reader);
            value.dRB_Failed_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Setup_List
void encode_PDU_Session_Resource_Setup_List(BitWriter& writer, const PDU_Session_Resource_Setup_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Setup_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Setup_List
PDU_Session_Resource_Setup_List decode_PDU_Session_Resource_Setup_List(BitReader& reader) {
    PDU_Session_Resource_Setup_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Setup_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Setup_Mod_Item
void encode_PDU_Session_Resource_Setup_Mod_Item(BitWriter& writer, const PDU_Session_Resource_Setup_Mod_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.securityResult.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Failed_Mod_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.securityResult.has_value()) {
            encode_SecurityResult(writer, (*value.securityResult));
        }
        encode_UP_TNL_Information(writer, value.nG_DL_UP_TNL_Information);
        if (value.pDU_Session_Data_Forwarding_Information_Response.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.pDU_Session_Data_Forwarding_Information_Response));
        }
        encode_DRB_Setup_Mod_List_NG_RAN(writer, value.dRB_Setup_Mod_List_NG_RAN);
        if (value.dRB_Failed_Mod_List_NG_RAN.has_value()) {
            encode_DRB_Failed_Mod_List_NG_RAN(writer, (*value.dRB_Failed_Mod_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_Setup_Mod_Item
PDU_Session_Resource_Setup_Mod_Item decode_PDU_Session_Resource_Setup_Mod_Item(BitReader& reader) {
    PDU_Session_Resource_Setup_Mod_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.securityResult)::value_type t_1{};
            t_1 = decode_SecurityResult(reader);
            value.securityResult.emplace(t_1);
        }
        value.nG_DL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Response)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.pDU_Session_Data_Forwarding_Information_Response.emplace(t_1);
        }
        value.dRB_Setup_Mod_List_NG_RAN = decode_DRB_Setup_Mod_List_NG_RAN(reader);
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Failed_Mod_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_Failed_Mod_List_NG_RAN(reader);
            value.dRB_Failed_Mod_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_Setup_Mod_List
void encode_PDU_Session_Resource_Setup_Mod_List(BitWriter& writer, const PDU_Session_Resource_Setup_Mod_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_Setup_Mod_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_Setup_Mod_List
PDU_Session_Resource_Setup_Mod_List decode_PDU_Session_Resource_Setup_Mod_List(BitReader& reader) {
    PDU_Session_Resource_Setup_Mod_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_Setup_Mod_Item(reader);
        }
    }
    return value;
}

// Encoder for UplinkOnlyROHC
void encode_UplinkOnlyROHC(BitWriter& writer, const UplinkOnlyROHC& value) {
    {
        uint64_t presenceBitmap = 0;
        if (value.continueROHC.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 2);

        if (value.maxCID < 0LL || value.maxCID > 16383LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.maxCID) + " out of range [0, 16383].");
        }
        UperInteger::encodeConstrainedInt(writer, value.maxCID, 0LL, 16383LL);
        if (value.rOHC_Profiles < 0LL || value.rOHC_Profiles > 511LL) {
            throw std::runtime_error("INTEGER constraint violation: value " + std::to_string(value.rOHC_Profiles) + " out of range [0, 511].");
        }
        UperInteger::encodeConstrainedInt(writer, value.rOHC_Profiles, 0LL, 511LL);
        if (value.continueROHC.has_value()) {
            bool is_extended = true;
            switch ((*value.continueROHC)) {
                case std::decay_t<decltype((*value.continueROHC))>::true_: is_extended = false; break;
                default: break;
            }
            UperExtension::encodeExtensionMarker(writer, is_extended);

            if (!is_extended) {
                uint64_t enum_index = 0;
                switch ((*value.continueROHC)) {
                    case std::decay_t<decltype((*value.continueROHC))>::true_: enum_index = 0; break;
                    default: throw std::runtime_error("Invalid enum value for encoding root");
                }
                UperChoice::encodeChoiceIndex(writer, enum_index, 1);
            } else {
                // Encoding of extended ENUMERATED is not supported.
                throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
            }
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
    }
}

// Decoder for UplinkOnlyROHC
UplinkOnlyROHC decode_UplinkOnlyROHC(BitReader& reader) {
    UplinkOnlyROHC value{};
    {
        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 2);

        value.maxCID = UperInteger::decodeConstrainedInt(reader, 0LL, 16383LL);
        if (value.maxCID < 0LL || value.maxCID > 16383LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.maxCID) + " out of range [0, 16383].");
        }
        value.rOHC_Profiles = UperInteger::decodeConstrainedInt(reader, 0LL, 511LL);
        if (value.rOHC_Profiles < 0LL || value.rOHC_Profiles > 511LL) {
            throw std::runtime_error("INTEGER constraint violation: decoded value " + std::to_string(value.rOHC_Profiles) + " out of range [0, 511].");
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.continueROHC)::value_type t_1{};
            bool is_extended = UperExtension::decodeExtensionMarker(reader);

            if (!is_extended) {
                size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
                switch (enum_index) {
                    case 0: t_1 = std::decay_t<decltype(t_1)>::true_; break;
                    default: throw std::runtime_error("Invalid enum index decoded");
                }
            } else {
                // For ENUMERATED, we can't store the value if it's an unknown extension.
                // We decode and discard, then throw to signal an unhandled extension.
                UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
                UperExtension::decodeOpenType(reader);
                throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
            }
            value.continueROHC.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
    }
    return value;
}

// Encoder for ROHC_Parameters
void encode_ROHC_Parameters(BitWriter& writer, const ROHC_Parameters& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_ROHC(writer, arg_1.rOHC);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_UplinkOnlyROHC(writer, arg_1.uPlinkOnlyROHC);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_Extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for ROHC_Parameters
ROHC_Parameters decode_ROHC_Parameters(BitReader& reader) {
    ROHC_Parameters value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.rOHC = decode_ROHC(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.uPlinkOnlyROHC = decode_UplinkOnlyROHC(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_Extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for PDCP_Configuration
void encode_PDCP_Configuration(BitWriter& writer, const PDCP_Configuration& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.rOHC_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 9);
        }
        if (value.t_ReorderingTimer.has_value()) {
            presenceBitmap |= (1ULL << 8);
        }
        if (value.discardTimer.has_value()) {
            presenceBitmap |= (1ULL << 7);
        }
        if (value.uLDataSplitThreshold.has_value()) {
            presenceBitmap |= (1ULL << 6);
        }
        if (value.pDCP_Duplication.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.pDCP_Reestablishment.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.pDCP_DataRecovery.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.duplication_Activation.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.outOfOrderDelivery.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 10);

        encode_PDCP_SN_Size(writer, value.pDCP_SN_Size_UL);
        encode_PDCP_SN_Size(writer, value.pDCP_SN_Size_DL);
        encode_RLC_Mode(writer, value.rLC_Mode);
        if (value.rOHC_Parameters.has_value()) {
            encode_ROHC_Parameters(writer, (*value.rOHC_Parameters));
        }
        if (value.t_ReorderingTimer.has_value()) {
            encode_T_ReorderingTimer(writer, (*value.t_ReorderingTimer));
        }
        if (value.discardTimer.has_value()) {
            encode_DiscardTimer(writer, (*value.discardTimer));
        }
        if (value.uLDataSplitThreshold.has_value()) {
            encode_ULDataSplitThreshold(writer, (*value.uLDataSplitThreshold));
        }
        if (value.pDCP_Duplication.has_value()) {
            encode_PDCP_Duplication(writer, (*value.pDCP_Duplication));
        }
        if (value.pDCP_Reestablishment.has_value()) {
            encode_PDCP_Reestablishment(writer, (*value.pDCP_Reestablishment));
        }
        if (value.pDCP_DataRecovery.has_value()) {
            encode_PDCP_DataRecovery(writer, (*value.pDCP_DataRecovery));
        }
        if (value.duplication_Activation.has_value()) {
            encode_Duplication_Activation(writer, (*value.duplication_Activation));
        }
        if (value.outOfOrderDelivery.has_value()) {
            encode_OutOfOrderDelivery(writer, (*value.outOfOrderDelivery));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDCP_Configuration
PDCP_Configuration decode_PDCP_Configuration(BitReader& reader) {
    PDCP_Configuration value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 10);

        value.pDCP_SN_Size_UL = decode_PDCP_SN_Size(reader);
        value.pDCP_SN_Size_DL = decode_PDCP_SN_Size(reader);
        value.rLC_Mode = decode_RLC_Mode(reader);
        if ((presenceBitmap >> 9) & 1) {
            decltype(value.rOHC_Parameters)::value_type t_1{};
            t_1 = decode_ROHC_Parameters(reader);
            value.rOHC_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 8) & 1) {
            decltype(value.t_ReorderingTimer)::value_type t_1{};
            t_1 = decode_T_ReorderingTimer(reader);
            value.t_ReorderingTimer.emplace(t_1);
        }
        if ((presenceBitmap >> 7) & 1) {
            decltype(value.discardTimer)::value_type t_1{};
            t_1 = decode_DiscardTimer(reader);
            value.discardTimer.emplace(t_1);
        }
        if ((presenceBitmap >> 6) & 1) {
            decltype(value.uLDataSplitThreshold)::value_type t_1{};
            t_1 = decode_ULDataSplitThreshold(reader);
            value.uLDataSplitThreshold.emplace(t_1);
        }
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.pDCP_Duplication)::value_type t_1{};
            t_1 = decode_PDCP_Duplication(reader);
            value.pDCP_Duplication.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.pDCP_Reestablishment)::value_type t_1{};
            t_1 = decode_PDCP_Reestablishment(reader);
            value.pDCP_Reestablishment.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.pDCP_DataRecovery)::value_type t_1{};
            t_1 = decode_PDCP_DataRecovery(reader);
            value.pDCP_DataRecovery.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.duplication_Activation)::value_type t_1{};
            t_1 = decode_Duplication_Activation(reader);
            value.duplication_Activation.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.outOfOrderDelivery)::value_type t_1{};
            t_1 = decode_OutOfOrderDelivery(reader);
            value.outOfOrderDelivery.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Modify_Item_EUTRAN
void encode_DRB_To_Modify_Item_EUTRAN(BitWriter& writer, const DRB_To_Modify_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.pDCP_Configuration.has_value()) {
            presenceBitmap |= (1ULL << 11);
        }
        if (value.eUTRAN_QoS.has_value()) {
            presenceBitmap |= (1ULL << 10);
        }
        if (value.s1_UL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 9);
        }
        if (value.data_Forwarding_Information.has_value()) {
            presenceBitmap |= (1ULL << 8);
        }
        if (value.pDCP_SN_Status_Request.has_value()) {
            presenceBitmap |= (1ULL << 7);
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 6);
        }
        if (value.dL_UP_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.cell_Group_To_Add.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.cell_Group_To_Modify.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.cell_Group_To_Remove.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 12);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.pDCP_Configuration.has_value()) {
            encode_PDCP_Configuration(writer, (*value.pDCP_Configuration));
        }
        if (value.eUTRAN_QoS.has_value()) {
            encode_EUTRAN_QoS(writer, (*value.eUTRAN_QoS));
        }
        if (value.s1_UL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.s1_UL_UP_TNL_Information));
        }
        if (value.data_Forwarding_Information.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.data_Forwarding_Information));
        }
        if (value.pDCP_SN_Status_Request.has_value()) {
            encode_PDCP_SN_Status_Request(writer, (*value.pDCP_SN_Status_Request));
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pDCP_SN_Status_Information));
        }
        if (value.dL_UP_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.dL_UP_Parameters));
        }
        if (value.cell_Group_To_Add.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Add));
        }
        if (value.cell_Group_To_Modify.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Modify));
        }
        if (value.cell_Group_To_Remove.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Remove));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Modify_Item_EUTRAN
DRB_To_Modify_Item_EUTRAN decode_DRB_To_Modify_Item_EUTRAN(BitReader& reader) {
    DRB_To_Modify_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 12);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 11) & 1) {
            decltype(value.pDCP_Configuration)::value_type t_1{};
            t_1 = decode_PDCP_Configuration(reader);
            value.pDCP_Configuration.emplace(t_1);
        }
        if ((presenceBitmap >> 10) & 1) {
            decltype(value.eUTRAN_QoS)::value_type t_1{};
            t_1 = decode_EUTRAN_QoS(reader);
            value.eUTRAN_QoS.emplace(t_1);
        }
        if ((presenceBitmap >> 9) & 1) {
            decltype(value.s1_UL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.s1_UL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 8) & 1) {
            decltype(value.data_Forwarding_Information)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.data_Forwarding_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 7) & 1) {
            decltype(value.pDCP_SN_Status_Request)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Request(reader);
            value.pDCP_SN_Status_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 6) & 1) {
            decltype(value.pDCP_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pDCP_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.dL_UP_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.dL_UP_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.cell_Group_To_Add)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Add.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.cell_Group_To_Modify)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Modify.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.cell_Group_To_Remove)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Remove.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Modify_List_EUTRAN
void encode_DRB_To_Modify_List_EUTRAN(BitWriter& writer, const DRB_To_Modify_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Modify_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_To_Modify_List_EUTRAN
DRB_To_Modify_List_EUTRAN decode_DRB_To_Modify_List_EUTRAN(BitReader& reader) {
    DRB_To_Modify_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Modify_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Modify_Item_NG_RAN
void encode_DRB_To_Modify_Item_NG_RAN(BitWriter& writer, const DRB_To_Modify_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.sDAP_Configuration.has_value()) {
            presenceBitmap |= (1ULL << 11);
        }
        if (value.pDCP_Configuration.has_value()) {
            presenceBitmap |= (1ULL << 10);
        }
        if (value.dRB_Data_Forwarding_Information.has_value()) {
            presenceBitmap |= (1ULL << 9);
        }
        if (value.pDCP_SN_Status_Request.has_value()) {
            presenceBitmap |= (1ULL << 8);
        }
        if (value.pdcp_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 7);
        }
        if (value.dL_UP_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 6);
        }
        if (value.cell_Group_To_Add.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.cell_Group_To_Modify.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.cell_Group_To_Remove.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.flow_Mapping_Information.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 12);

        encode_DRB_ID(writer, value.dRB_ID);
        if (value.sDAP_Configuration.has_value()) {
            encode_SDAP_Configuration(writer, (*value.sDAP_Configuration));
        }
        if (value.pDCP_Configuration.has_value()) {
            encode_PDCP_Configuration(writer, (*value.pDCP_Configuration));
        }
        if (value.dRB_Data_Forwarding_Information.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.dRB_Data_Forwarding_Information));
        }
        if (value.pDCP_SN_Status_Request.has_value()) {
            encode_PDCP_SN_Status_Request(writer, (*value.pDCP_SN_Status_Request));
        }
        if (value.pdcp_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pdcp_SN_Status_Information));
        }
        if (value.dL_UP_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.dL_UP_Parameters));
        }
        if (value.cell_Group_To_Add.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Add));
        }
        if (value.cell_Group_To_Modify.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Modify));
        }
        if (value.cell_Group_To_Remove.has_value()) {
            encode_Cell_Group_Information(writer, (*value.cell_Group_To_Remove));
        }
        if (value.flow_Mapping_Information.has_value()) {
            encode_QoS_Flow_QoS_Parameter_List(writer, (*value.flow_Mapping_Information));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Modify_Item_NG_RAN
DRB_To_Modify_Item_NG_RAN decode_DRB_To_Modify_Item_NG_RAN(BitReader& reader) {
    DRB_To_Modify_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 12);

        value.dRB_ID = decode_DRB_ID(reader);
        if ((presenceBitmap >> 11) & 1) {
            decltype(value.sDAP_Configuration)::value_type t_1{};
            t_1 = decode_SDAP_Configuration(reader);
            value.sDAP_Configuration.emplace(t_1);
        }
        if ((presenceBitmap >> 10) & 1) {
            decltype(value.pDCP_Configuration)::value_type t_1{};
            t_1 = decode_PDCP_Configuration(reader);
            value.pDCP_Configuration.emplace(t_1);
        }
        if ((presenceBitmap >> 9) & 1) {
            decltype(value.dRB_Data_Forwarding_Information)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.dRB_Data_Forwarding_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 8) & 1) {
            decltype(value.pDCP_SN_Status_Request)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Request(reader);
            value.pDCP_SN_Status_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 7) & 1) {
            decltype(value.pdcp_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pdcp_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 6) & 1) {
            decltype(value.dL_UP_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.dL_UP_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.cell_Group_To_Add)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Add.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.cell_Group_To_Modify)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Modify.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.cell_Group_To_Remove)::value_type t_1{};
            t_1 = decode_Cell_Group_Information(reader);
            value.cell_Group_To_Remove.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.flow_Mapping_Information)::value_type t_1{};
            t_1 = decode_QoS_Flow_QoS_Parameter_List(reader);
            value.flow_Mapping_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Modify_List_NG_RAN
void encode_DRB_To_Modify_List_NG_RAN(BitWriter& writer, const DRB_To_Modify_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Modify_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_To_Modify_List_NG_RAN
DRB_To_Modify_List_NG_RAN decode_DRB_To_Modify_List_NG_RAN(BitReader& reader) {
    DRB_To_Modify_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Modify_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Item_EUTRAN
void encode_DRB_To_Setup_Item_EUTRAN(BitWriter& writer, const DRB_To_Setup_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.dL_UP_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.existing_Allocated_S1_DL_UP_TNL_Info.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 5);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_PDCP_Configuration(writer, value.pDCP_Configuration);
        encode_EUTRAN_QoS(writer, value.eUTRAN_QoS);
        encode_UP_TNL_Information(writer, value.s1_UL_UP_TNL_Information);
        if (value.data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.data_Forwarding_Information_Request));
        }
        encode_Cell_Group_Information(writer, value.cell_Group_Information);
        if (value.dL_UP_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.dL_UP_Parameters));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.existing_Allocated_S1_DL_UP_TNL_Info.has_value()) {
            encode_UP_TNL_Information(writer, (*value.existing_Allocated_S1_DL_UP_TNL_Info));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Setup_Item_EUTRAN
DRB_To_Setup_Item_EUTRAN decode_DRB_To_Setup_Item_EUTRAN(BitReader& reader) {
    DRB_To_Setup_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 5);

        value.dRB_ID = decode_DRB_ID(reader);
        value.pDCP_Configuration = decode_PDCP_Configuration(reader);
        value.eUTRAN_QoS = decode_EUTRAN_QoS(reader);
        value.s1_UL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.data_Forwarding_Information_Request.emplace(t_1);
        }
        value.cell_Group_Information = decode_Cell_Group_Information(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.dL_UP_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.dL_UP_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.existing_Allocated_S1_DL_UP_TNL_Info)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.existing_Allocated_S1_DL_UP_TNL_Info.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_List_EUTRAN
void encode_DRB_To_Setup_List_EUTRAN(BitWriter& writer, const DRB_To_Setup_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Setup_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_To_Setup_List_EUTRAN
DRB_To_Setup_List_EUTRAN decode_DRB_To_Setup_List_EUTRAN(BitReader& reader) {
    DRB_To_Setup_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Setup_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Mod_Item_EUTRAN
void encode_DRB_To_Setup_Mod_Item_EUTRAN(BitWriter& writer, const DRB_To_Setup_Mod_Item_EUTRAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dL_UP_Parameters.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_PDCP_Configuration(writer, value.pDCP_Configuration);
        encode_EUTRAN_QoS(writer, value.eUTRAN_QoS);
        encode_UP_TNL_Information(writer, value.s1_UL_UP_TNL_Information);
        if (value.data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.data_Forwarding_Information_Request));
        }
        encode_Cell_Group_Information(writer, value.cell_Group_Information);
        if (value.dL_UP_Parameters.has_value()) {
            encode_UP_Parameters(writer, (*value.dL_UP_Parameters));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Setup_Mod_Item_EUTRAN
DRB_To_Setup_Mod_Item_EUTRAN decode_DRB_To_Setup_Mod_Item_EUTRAN(BitReader& reader) {
    DRB_To_Setup_Mod_Item_EUTRAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        value.pDCP_Configuration = decode_PDCP_Configuration(reader);
        value.eUTRAN_QoS = decode_EUTRAN_QoS(reader);
        value.s1_UL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.data_Forwarding_Information_Request.emplace(t_1);
        }
        value.cell_Group_Information = decode_Cell_Group_Information(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dL_UP_Parameters)::value_type t_1{};
            t_1 = decode_UP_Parameters(reader);
            value.dL_UP_Parameters.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Mod_List_EUTRAN
void encode_DRB_To_Setup_Mod_List_EUTRAN(BitWriter& writer, const DRB_To_Setup_Mod_List_EUTRAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Setup_Mod_Item_EUTRAN(writer, element);
    }
}

// Decoder for DRB_To_Setup_Mod_List_EUTRAN
DRB_To_Setup_Mod_List_EUTRAN decode_DRB_To_Setup_Mod_List_EUTRAN(BitReader& reader) {
    DRB_To_Setup_Mod_List_EUTRAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Setup_Mod_Item_EUTRAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Item_NG_RAN
void encode_DRB_To_Setup_Item_NG_RAN(BitWriter& writer, const DRB_To_Setup_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.dRB_Data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_SDAP_Configuration(writer, value.sDAP_Configuration);
        encode_PDCP_Configuration(writer, value.pDCP_Configuration);
        encode_Cell_Group_Information(writer, value.cell_Group_Information);
        encode_QoS_Flow_QoS_Parameter_List(writer, value.qos_flow_Information_To_Be_Setup);
        if (value.dRB_Data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.dRB_Data_Forwarding_Information_Request));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pDCP_SN_Status_Information));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Setup_Item_NG_RAN
DRB_To_Setup_Item_NG_RAN decode_DRB_To_Setup_Item_NG_RAN(BitReader& reader) {
    DRB_To_Setup_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        value.sDAP_Configuration = decode_SDAP_Configuration(reader);
        value.pDCP_Configuration = decode_PDCP_Configuration(reader);
        value.cell_Group_Information = decode_Cell_Group_Information(reader);
        value.qos_flow_Information_To_Be_Setup = decode_QoS_Flow_QoS_Parameter_List(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.dRB_Data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.dRB_Data_Forwarding_Information_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.pDCP_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pDCP_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_List_NG_RAN
void encode_DRB_To_Setup_List_NG_RAN(BitWriter& writer, const DRB_To_Setup_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Setup_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_To_Setup_List_NG_RAN
DRB_To_Setup_List_NG_RAN decode_DRB_To_Setup_List_NG_RAN(BitReader& reader) {
    DRB_To_Setup_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Setup_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Mod_Item_NG_RAN
void encode_DRB_To_Setup_Mod_Item_NG_RAN(BitWriter& writer, const DRB_To_Setup_Mod_Item_NG_RAN& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.dRB_Data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_DRB_ID(writer, value.dRB_ID);
        encode_SDAP_Configuration(writer, value.sDAP_Configuration);
        encode_PDCP_Configuration(writer, value.pDCP_Configuration);
        encode_Cell_Group_Information(writer, value.cell_Group_Information);
        encode_QoS_Flow_QoS_Parameter_List(writer, value.flow_Mapping_Information);
        if (value.dRB_Data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.dRB_Data_Forwarding_Information_Request));
        }
        if (value.dRB_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.dRB_Inactivity_Timer));
        }
        if (value.pDCP_SN_Status_Information.has_value()) {
            encode_PDCP_SN_Status_Information(writer, (*value.pDCP_SN_Status_Information));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DRB_To_Setup_Mod_Item_NG_RAN
DRB_To_Setup_Mod_Item_NG_RAN decode_DRB_To_Setup_Mod_Item_NG_RAN(BitReader& reader) {
    DRB_To_Setup_Mod_Item_NG_RAN value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.dRB_ID = decode_DRB_ID(reader);
        value.sDAP_Configuration = decode_SDAP_Configuration(reader);
        value.pDCP_Configuration = decode_PDCP_Configuration(reader);
        value.cell_Group_Information = decode_Cell_Group_Information(reader);
        value.flow_Mapping_Information = decode_QoS_Flow_QoS_Parameter_List(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.dRB_Data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.dRB_Data_Forwarding_Information_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.dRB_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.pDCP_SN_Status_Information)::value_type t_1{};
            t_1 = decode_PDCP_SN_Status_Information(reader);
            value.pDCP_SN_Status_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_To_Setup_Mod_List_NG_RAN
void encode_DRB_To_Setup_Mod_List_NG_RAN(BitWriter& writer, const DRB_To_Setup_Mod_List_NG_RAN& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        encode_DRB_To_Setup_Mod_Item_NG_RAN(writer, element);
    }
}

// Decoder for DRB_To_Setup_Mod_List_NG_RAN
DRB_To_Setup_Mod_List_NG_RAN decode_DRB_To_Setup_Mod_List_NG_RAN(BitReader& reader) {
    DRB_To_Setup_Mod_List_NG_RAN value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_DRB_To_Setup_Mod_Item_NG_RAN(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Modify_Item
void encode_PDU_Session_Resource_To_Modify_Item(BitWriter& writer, const PDU_Session_Resource_To_Modify_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.securityIndication.has_value()) {
            presenceBitmap |= (1ULL << 10);
        }
        if (value.pDU_Session_Resource_DL_AMBR.has_value()) {
            presenceBitmap |= (1ULL << 9);
        }
        if (value.nG_UL_UP_TNL_Information.has_value()) {
            presenceBitmap |= (1ULL << 8);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 7);
        }
        if (value.pDU_Session_Data_Forwarding_Information.has_value()) {
            presenceBitmap |= (1ULL << 6);
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.networkInstance.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.dRB_To_Setup_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.dRB_To_Modify_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.dRB_To_Remove_List_NG_RAN.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 11);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        if (value.securityIndication.has_value()) {
            encode_SecurityIndication(writer, (*value.securityIndication));
        }
        if (value.pDU_Session_Resource_DL_AMBR.has_value()) {
            encode_BitRate(writer, (*value.pDU_Session_Resource_DL_AMBR));
        }
        if (value.nG_UL_UP_TNL_Information.has_value()) {
            encode_UP_TNL_Information(writer, (*value.nG_UL_UP_TNL_Information));
        }
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.pDU_Session_Data_Forwarding_Information_Request));
        }
        if (value.pDU_Session_Data_Forwarding_Information.has_value()) {
            encode_Data_Forwarding_Information(writer, (*value.pDU_Session_Data_Forwarding_Information));
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.pDU_Session_Inactivity_Timer));
        }
        if (value.networkInstance.has_value()) {
            encode_NetworkInstance(writer, (*value.networkInstance));
        }
        if (value.dRB_To_Setup_List_NG_RAN.has_value()) {
            encode_DRB_To_Setup_List_NG_RAN(writer, (*value.dRB_To_Setup_List_NG_RAN));
        }
        if (value.dRB_To_Modify_List_NG_RAN.has_value()) {
            encode_DRB_To_Modify_List_NG_RAN(writer, (*value.dRB_To_Modify_List_NG_RAN));
        }
        if (value.dRB_To_Remove_List_NG_RAN.has_value()) {
            encode_DRB_To_Remove_List_NG_RAN(writer, (*value.dRB_To_Remove_List_NG_RAN));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_To_Modify_Item
PDU_Session_Resource_To_Modify_Item decode_PDU_Session_Resource_To_Modify_Item(BitReader& reader) {
    PDU_Session_Resource_To_Modify_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 11);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        if ((presenceBitmap >> 10) & 1) {
            decltype(value.securityIndication)::value_type t_1{};
            t_1 = decode_SecurityIndication(reader);
            value.securityIndication.emplace(t_1);
        }
        if ((presenceBitmap >> 9) & 1) {
            decltype(value.pDU_Session_Resource_DL_AMBR)::value_type t_1{};
            t_1 = decode_BitRate(reader);
            value.pDU_Session_Resource_DL_AMBR.emplace(t_1);
        }
        if ((presenceBitmap >> 8) & 1) {
            decltype(value.nG_UL_UP_TNL_Information)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.nG_UL_UP_TNL_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 7) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.pDU_Session_Data_Forwarding_Information_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 6) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information(reader);
            value.pDU_Session_Data_Forwarding_Information.emplace(t_1);
        }
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.pDU_Session_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.pDU_Session_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.networkInstance)::value_type t_1{};
            t_1 = decode_NetworkInstance(reader);
            value.networkInstance.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.dRB_To_Setup_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_To_Setup_List_NG_RAN(reader);
            value.dRB_To_Setup_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.dRB_To_Modify_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_To_Modify_List_NG_RAN(reader);
            value.dRB_To_Modify_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.dRB_To_Remove_List_NG_RAN)::value_type t_1{};
            t_1 = decode_DRB_To_Remove_List_NG_RAN(reader);
            value.dRB_To_Remove_List_NG_RAN.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Modify_List
void encode_PDU_Session_Resource_To_Modify_List(BitWriter& writer, const PDU_Session_Resource_To_Modify_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_To_Modify_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_To_Modify_List
PDU_Session_Resource_To_Modify_List decode_PDU_Session_Resource_To_Modify_List(BitReader& reader) {
    PDU_Session_Resource_To_Modify_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_To_Modify_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Setup_Item
void encode_PDU_Session_Resource_To_Setup_Item(BitWriter& writer, const PDU_Session_Resource_To_Setup_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.pDU_Session_Resource_DL_AMBR.has_value()) {
            presenceBitmap |= (1ULL << 5);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 4);
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.existing_Allocated_NG_DL_UP_TNL_Info.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.networkInstance.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 6);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_PDU_Session_Type(writer, value.pDU_Session_Type);
        encode_SNSSAI(writer, value.sNSSAI);
        encode_SecurityIndication(writer, value.securityIndication);
        if (value.pDU_Session_Resource_DL_AMBR.has_value()) {
            encode_BitRate(writer, (*value.pDU_Session_Resource_DL_AMBR));
        }
        encode_UP_TNL_Information(writer, value.nG_UL_UP_TNL_Information);
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.pDU_Session_Data_Forwarding_Information_Request));
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.pDU_Session_Inactivity_Timer));
        }
        if (value.existing_Allocated_NG_DL_UP_TNL_Info.has_value()) {
            encode_UP_TNL_Information(writer, (*value.existing_Allocated_NG_DL_UP_TNL_Info));
        }
        if (value.networkInstance.has_value()) {
            encode_NetworkInstance(writer, (*value.networkInstance));
        }
        encode_DRB_To_Setup_List_NG_RAN(writer, value.dRB_To_Setup_List_NG_RAN);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_To_Setup_Item
PDU_Session_Resource_To_Setup_Item decode_PDU_Session_Resource_To_Setup_Item(BitReader& reader) {
    PDU_Session_Resource_To_Setup_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 6);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.pDU_Session_Type = decode_PDU_Session_Type(reader);
        value.sNSSAI = decode_SNSSAI(reader);
        value.securityIndication = decode_SecurityIndication(reader);
        if ((presenceBitmap >> 5) & 1) {
            decltype(value.pDU_Session_Resource_DL_AMBR)::value_type t_1{};
            t_1 = decode_BitRate(reader);
            value.pDU_Session_Resource_DL_AMBR.emplace(t_1);
        }
        value.nG_UL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 4) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.pDU_Session_Data_Forwarding_Information_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.pDU_Session_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.pDU_Session_Inactivity_Timer.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.existing_Allocated_NG_DL_UP_TNL_Info)::value_type t_1{};
            t_1 = decode_UP_TNL_Information(reader);
            value.existing_Allocated_NG_DL_UP_TNL_Info.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.networkInstance)::value_type t_1{};
            t_1 = decode_NetworkInstance(reader);
            value.networkInstance.emplace(t_1);
        }
        value.dRB_To_Setup_List_NG_RAN = decode_DRB_To_Setup_List_NG_RAN(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Setup_List
void encode_PDU_Session_Resource_To_Setup_List(BitWriter& writer, const PDU_Session_Resource_To_Setup_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_To_Setup_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_To_Setup_List
PDU_Session_Resource_To_Setup_List decode_PDU_Session_Resource_To_Setup_List(BitReader& reader) {
    PDU_Session_Resource_To_Setup_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_To_Setup_Item(reader);
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Setup_Mod_Item
void encode_PDU_Session_Resource_To_Setup_Mod_Item(BitWriter& writer, const PDU_Session_Resource_To_Setup_Mod_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.pDU_Session_Resource_AMBR.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        encode_PDU_Session_ID(writer, value.pDU_Session_ID);
        encode_PDU_Session_Type(writer, value.pDU_Session_Type);
        encode_SNSSAI(writer, value.sNSSAI);
        encode_SecurityIndication(writer, value.securityIndication);
        if (value.pDU_Session_Resource_AMBR.has_value()) {
            encode_BitRate(writer, (*value.pDU_Session_Resource_AMBR));
        }
        encode_UP_TNL_Information(writer, value.nG_UL_UP_TNL_Information);
        if (value.pDU_Session_Data_Forwarding_Information_Request.has_value()) {
            encode_Data_Forwarding_Information_Request(writer, (*value.pDU_Session_Data_Forwarding_Information_Request));
        }
        if (value.pDU_Session_Inactivity_Timer.has_value()) {
            encode_Inactivity_Timer(writer, (*value.pDU_Session_Inactivity_Timer));
        }
        encode_DRB_To_Setup_Mod_List_NG_RAN(writer, value.dRB_To_Setup_Mod_List_NG_RAN);
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PDU_Session_Resource_To_Setup_Mod_Item
PDU_Session_Resource_To_Setup_Mod_Item decode_PDU_Session_Resource_To_Setup_Mod_Item(BitReader& reader) {
    PDU_Session_Resource_To_Setup_Mod_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.pDU_Session_ID = decode_PDU_Session_ID(reader);
        value.pDU_Session_Type = decode_PDU_Session_Type(reader);
        value.sNSSAI = decode_SNSSAI(reader);
        value.securityIndication = decode_SecurityIndication(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.pDU_Session_Resource_AMBR)::value_type t_1{};
            t_1 = decode_BitRate(reader);
            value.pDU_Session_Resource_AMBR.emplace(t_1);
        }
        value.nG_UL_UP_TNL_Information = decode_UP_TNL_Information(reader);
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.pDU_Session_Data_Forwarding_Information_Request)::value_type t_1{};
            t_1 = decode_Data_Forwarding_Information_Request(reader);
            value.pDU_Session_Data_Forwarding_Information_Request.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.pDU_Session_Inactivity_Timer)::value_type t_1{};
            t_1 = decode_Inactivity_Timer(reader);
            value.pDU_Session_Inactivity_Timer.emplace(t_1);
        }
        value.dRB_To_Setup_Mod_List_NG_RAN = decode_DRB_To_Setup_Mod_List_NG_RAN(reader);
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PDU_Session_Resource_To_Setup_Mod_List
void encode_PDU_Session_Resource_To_Setup_Mod_List(BitWriter& writer, const PDU_Session_Resource_To_Setup_Mod_List& value) {
    if (value.size() < 1 || value.size() > 256) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 256].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 256);
    for (const auto& element : value) {
        encode_PDU_Session_Resource_To_Setup_Mod_Item(writer, element);
    }
}

// Decoder for PDU_Session_Resource_To_Setup_Mod_List
PDU_Session_Resource_To_Setup_Mod_List decode_PDU_Session_Resource_To_Setup_Mod_List(BitReader& reader) {
    PDU_Session_Resource_To_Setup_Mod_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 256);
        if (length < 1 || length > 256) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 256].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_PDU_Session_Resource_To_Setup_Mod_Item(reader);
        }
    }
    return value;
}

} // namespace E1AP_IEs

namespace E1AP_PDU_Contents {

// Encoder for Reset
void encode_Reset(BitWriter& writer, const Reset& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for Reset
Reset decode_Reset(BitReader& reader) {
    Reset value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for ResetAll
void encode_ResetAll(BitWriter& writer, const ResetAll& value) {
    bool is_extended = true;
    switch (value) {
        case ResetAll::reset_all: is_extended = false; break;
        default: break;
    }
    UperExtension::encodeExtensionMarker(writer, is_extended);

    if (!is_extended) {
        uint64_t enum_index = 0;
        switch (value) {
            case ResetAll::reset_all: enum_index = 0; break;
            default: throw std::runtime_error("Invalid enum value for encoding root");
        }
        UperChoice::encodeChoiceIndex(writer, enum_index, 1);
    } else {
        // Encoding of extended ENUMERATED is not supported.
        throw std::runtime_error("Encoding of extended ENUMERATED not supported.");
    }
}

// Decoder for ResetAll
ResetAll decode_ResetAll(BitReader& reader) {
    ResetAll value{};
    bool is_extended = UperExtension::decodeExtensionMarker(reader);

    if (!is_extended) {
        size_t enum_index = UperChoice::decodeChoiceIndex(reader, 1);
        switch (enum_index) {
            case 0: value = ResetAll::reset_all; break;
            default: throw std::runtime_error("Invalid enum index decoded");
        }
    } else {
        // For ENUMERATED, we can't store the value if it's an unknown extension.
        // We decode and discard, then throw to signal an unhandled extension.
        UperLength::decodeUnconstrainedLength(reader); // extended_enum_idx
        UperExtension::decodeOpenType(reader);
        throw std::runtime_error("Received an unhandled extended ENUMERATED value.");
    }
    return value;
}

// Encoder for UE_associatedLogicalE1_ConnectionListRes
void encode_UE_associatedLogicalE1_ConnectionListRes(BitWriter& writer, const UE_associatedLogicalE1_ConnectionListRes& value) {
    if (value.size() < 1 || value.size() > 65536) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 65536].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 65536);
    for (const auto& element : value) {
        E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, element);
    }
}

// Decoder for UE_associatedLogicalE1_ConnectionListRes
UE_associatedLogicalE1_ConnectionListRes decode_UE_associatedLogicalE1_ConnectionListRes(BitReader& reader) {
    UE_associatedLogicalE1_ConnectionListRes value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 65536);
        if (length < 1 || length > 65536) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 65536].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
        }
    }
    return value;
}

// Encoder for ResetType
void encode_ResetType(BitWriter& writer, const ResetType& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_ResetAll(writer, arg_1.e1_Interface);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_UE_associatedLogicalE1_ConnectionListRes(writer, arg_1.partOfE1_Interface);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for ResetType
ResetType decode_ResetType(BitReader& reader) {
    ResetType value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e1_Interface = decode_ResetAll(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.partOfE1_Interface = decode_UE_associatedLogicalE1_ConnectionListRes(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for ResetAcknowledge
void encode_ResetAcknowledge(BitWriter& writer, const ResetAcknowledge& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for ResetAcknowledge
ResetAcknowledge decode_ResetAcknowledge(BitReader& reader) {
    ResetAcknowledge value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for UE_associatedLogicalE1_ConnectionListResAck
void encode_UE_associatedLogicalE1_ConnectionListResAck(BitWriter& writer, const UE_associatedLogicalE1_ConnectionListResAck& value) {
    if (value.size() < 1 || value.size() > 65536) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 65536].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 65536);
    for (const auto& element : value) {
        E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, element);
    }
}

// Decoder for UE_associatedLogicalE1_ConnectionListResAck
UE_associatedLogicalE1_ConnectionListResAck decode_UE_associatedLogicalE1_ConnectionListResAck(BitReader& reader) {
    UE_associatedLogicalE1_ConnectionListResAck value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 65536);
        if (length < 1 || length > 65536) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 65536].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
        }
    }
    return value;
}

// Encoder for ErrorIndication
void encode_ErrorIndication(BitWriter& writer, const ErrorIndication& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for ErrorIndication
ErrorIndication decode_ErrorIndication(BitReader& reader) {
    ErrorIndication value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_E1SetupRequest
void encode_GNB_CU_UP_E1SetupRequest(BitWriter& writer, const GNB_CU_UP_E1SetupRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_E1SetupRequest
GNB_CU_UP_E1SetupRequest decode_GNB_CU_UP_E1SetupRequest(BitReader& reader) {
    GNB_CU_UP_E1SetupRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SupportedPLMNs_Item
void encode_SupportedPLMNs_Item(BitWriter& writer, const SupportedPLMNs_Item& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        uint64_t presenceBitmap = 0;
        if (value.slice_Support_List.has_value()) {
            presenceBitmap |= (1ULL << 3);
        }
        if (value.nR_CGI_Support_List.has_value()) {
            presenceBitmap |= (1ULL << 2);
        }
        if (value.qoS_Parameters_Support_List.has_value()) {
            presenceBitmap |= (1ULL << 1);
        }
        if (value.iE_Extensions.has_value()) {
            presenceBitmap |= (1ULL << 0);
        }
        UperSequence::encodeSequencePreamble(writer, presenceBitmap, 4);

        E1AP_IEs::encode_PLMN_Identity(writer, value.pLMN_Identity);
        if (value.slice_Support_List.has_value()) {
            E1AP_IEs::encode_Slice_Support_List(writer, (*value.slice_Support_List));
        }
        if (value.nR_CGI_Support_List.has_value()) {
            E1AP_IEs::encode_NR_CGI_Support_List(writer, (*value.nR_CGI_Support_List));
        }
        if (value.qoS_Parameters_Support_List.has_value()) {
            E1AP_IEs::encode_QoS_Parameters_Support_List(writer, (*value.qoS_Parameters_Support_List));
        }
        if (value.iE_Extensions.has_value()) {
            E1AP_Containers::encode_ProtocolExtensionContainer(writer, (*value.iE_Extensions));
        }
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for SupportedPLMNs_Item
SupportedPLMNs_Item decode_SupportedPLMNs_Item(BitReader& reader) {
    SupportedPLMNs_Item value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        uint64_t presenceBitmap = UperSequence::decodeSequencePreamble(reader, 4);

        value.pLMN_Identity = E1AP_IEs::decode_PLMN_Identity(reader);
        if ((presenceBitmap >> 3) & 1) {
            decltype(value.slice_Support_List)::value_type t_1{};
            t_1 = E1AP_IEs::decode_Slice_Support_List(reader);
            value.slice_Support_List.emplace(t_1);
        }
        if ((presenceBitmap >> 2) & 1) {
            decltype(value.nR_CGI_Support_List)::value_type t_1{};
            t_1 = E1AP_IEs::decode_NR_CGI_Support_List(reader);
            value.nR_CGI_Support_List.emplace(t_1);
        }
        if ((presenceBitmap >> 1) & 1) {
            decltype(value.qoS_Parameters_Support_List)::value_type t_1{};
            t_1 = E1AP_IEs::decode_QoS_Parameters_Support_List(reader);
            value.qoS_Parameters_Support_List.emplace(t_1);
        }
        if ((presenceBitmap >> 0) & 1) {
            decltype(value.iE_Extensions)::value_type t_1{};
            t_1 = E1AP_Containers::decode_ProtocolExtensionContainer(reader);
            value.iE_Extensions.emplace(t_1);
        }
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for SupportedPLMNs_List
void encode_SupportedPLMNs_List(BitWriter& writer, const SupportedPLMNs_List& value) {
    if (value.size() < 1 || value.size() > 12) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 12].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 12);
    for (const auto& element : value) {
        encode_SupportedPLMNs_Item(writer, element);
    }
}

// Decoder for SupportedPLMNs_List
SupportedPLMNs_List decode_SupportedPLMNs_List(BitReader& reader) {
    SupportedPLMNs_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 12);
        if (length < 1 || length > 12) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 12].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = decode_SupportedPLMNs_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_E1SetupResponse
void encode_GNB_CU_UP_E1SetupResponse(BitWriter& writer, const GNB_CU_UP_E1SetupResponse& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_E1SetupResponse
GNB_CU_UP_E1SetupResponse decode_GNB_CU_UP_E1SetupResponse(BitReader& reader) {
    GNB_CU_UP_E1SetupResponse value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_E1SetupFailure
void encode_GNB_CU_UP_E1SetupFailure(BitWriter& writer, const GNB_CU_UP_E1SetupFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_E1SetupFailure
GNB_CU_UP_E1SetupFailure decode_GNB_CU_UP_E1SetupFailure(BitReader& reader) {
    GNB_CU_UP_E1SetupFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_E1SetupRequest
void encode_GNB_CU_CP_E1SetupRequest(BitWriter& writer, const GNB_CU_CP_E1SetupRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_E1SetupRequest
GNB_CU_CP_E1SetupRequest decode_GNB_CU_CP_E1SetupRequest(BitReader& reader) {
    GNB_CU_CP_E1SetupRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_E1SetupResponse
void encode_GNB_CU_CP_E1SetupResponse(BitWriter& writer, const GNB_CU_CP_E1SetupResponse& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_E1SetupResponse
GNB_CU_CP_E1SetupResponse decode_GNB_CU_CP_E1SetupResponse(BitReader& reader) {
    GNB_CU_CP_E1SetupResponse value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_E1SetupFailure
void encode_GNB_CU_CP_E1SetupFailure(BitWriter& writer, const GNB_CU_CP_E1SetupFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_E1SetupFailure
GNB_CU_CP_E1SetupFailure decode_GNB_CU_CP_E1SetupFailure(BitReader& reader) {
    GNB_CU_CP_E1SetupFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_ConfigurationUpdate
void encode_GNB_CU_UP_ConfigurationUpdate(BitWriter& writer, const GNB_CU_UP_ConfigurationUpdate& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_ConfigurationUpdate
GNB_CU_UP_ConfigurationUpdate decode_GNB_CU_UP_ConfigurationUpdate(BitReader& reader) {
    GNB_CU_UP_ConfigurationUpdate value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_TNLA_To_Remove_List
void encode_GNB_CU_UP_TNLA_To_Remove_List(BitWriter& writer, const GNB_CU_UP_TNLA_To_Remove_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_UP_TNLA_To_Remove_Item(writer, element);
    }
}

// Decoder for GNB_CU_UP_TNLA_To_Remove_List
GNB_CU_UP_TNLA_To_Remove_List decode_GNB_CU_UP_TNLA_To_Remove_List(BitReader& reader) {
    GNB_CU_UP_TNLA_To_Remove_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_UP_TNLA_To_Remove_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_ConfigurationUpdateAcknowledge
void encode_GNB_CU_UP_ConfigurationUpdateAcknowledge(BitWriter& writer, const GNB_CU_UP_ConfigurationUpdateAcknowledge& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_ConfigurationUpdateAcknowledge
GNB_CU_UP_ConfigurationUpdateAcknowledge decode_GNB_CU_UP_ConfigurationUpdateAcknowledge(BitReader& reader) {
    GNB_CU_UP_ConfigurationUpdateAcknowledge value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_ConfigurationUpdateFailure
void encode_GNB_CU_UP_ConfigurationUpdateFailure(BitWriter& writer, const GNB_CU_UP_ConfigurationUpdateFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_ConfigurationUpdateFailure
GNB_CU_UP_ConfigurationUpdateFailure decode_GNB_CU_UP_ConfigurationUpdateFailure(BitReader& reader) {
    GNB_CU_UP_ConfigurationUpdateFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_ConfigurationUpdate
void encode_GNB_CU_CP_ConfigurationUpdate(BitWriter& writer, const GNB_CU_CP_ConfigurationUpdate& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_ConfigurationUpdate
GNB_CU_CP_ConfigurationUpdate decode_GNB_CU_CP_ConfigurationUpdate(BitReader& reader) {
    GNB_CU_CP_ConfigurationUpdate value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Add_List
void encode_GNB_CU_CP_TNLA_To_Add_List(BitWriter& writer, const GNB_CU_CP_TNLA_To_Add_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Add_Item(writer, element);
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Add_List
GNB_CU_CP_TNLA_To_Add_List decode_GNB_CU_CP_TNLA_To_Add_List(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Add_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Add_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Remove_List
void encode_GNB_CU_CP_TNLA_To_Remove_List(BitWriter& writer, const GNB_CU_CP_TNLA_To_Remove_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Remove_Item(writer, element);
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Remove_List
GNB_CU_CP_TNLA_To_Remove_List decode_GNB_CU_CP_TNLA_To_Remove_List(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Remove_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Remove_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_To_Update_List
void encode_GNB_CU_CP_TNLA_To_Update_List(BitWriter& writer, const GNB_CU_CP_TNLA_To_Update_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_CP_TNLA_To_Update_Item(writer, element);
    }
}

// Decoder for GNB_CU_CP_TNLA_To_Update_List
GNB_CU_CP_TNLA_To_Update_List decode_GNB_CU_CP_TNLA_To_Update_List(BitReader& reader) {
    GNB_CU_CP_TNLA_To_Update_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_CP_TNLA_To_Update_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_ConfigurationUpdateAcknowledge
void encode_GNB_CU_CP_ConfigurationUpdateAcknowledge(BitWriter& writer, const GNB_CU_CP_ConfigurationUpdateAcknowledge& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_ConfigurationUpdateAcknowledge
GNB_CU_CP_ConfigurationUpdateAcknowledge decode_GNB_CU_CP_ConfigurationUpdateAcknowledge(BitReader& reader) {
    GNB_CU_CP_ConfigurationUpdateAcknowledge value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_Setup_List
void encode_GNB_CU_CP_TNLA_Setup_List(BitWriter& writer, const GNB_CU_CP_TNLA_Setup_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_CP_TNLA_Setup_Item(writer, element);
    }
}

// Decoder for GNB_CU_CP_TNLA_Setup_List
GNB_CU_CP_TNLA_Setup_List decode_GNB_CU_CP_TNLA_Setup_List(BitReader& reader) {
    GNB_CU_CP_TNLA_Setup_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_CP_TNLA_Setup_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_TNLA_Failed_To_Setup_List
void encode_GNB_CU_CP_TNLA_Failed_To_Setup_List(BitWriter& writer, const GNB_CU_CP_TNLA_Failed_To_Setup_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(writer, element);
    }
}

// Decoder for GNB_CU_CP_TNLA_Failed_To_Setup_List
GNB_CU_CP_TNLA_Failed_To_Setup_List decode_GNB_CU_CP_TNLA_Failed_To_Setup_List(BitReader& reader) {
    GNB_CU_CP_TNLA_Failed_To_Setup_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_GNB_CU_CP_TNLA_Failed_To_Setup_Item(reader);
        }
    }
    return value;
}

// Encoder for GNB_CU_CP_ConfigurationUpdateFailure
void encode_GNB_CU_CP_ConfigurationUpdateFailure(BitWriter& writer, const GNB_CU_CP_ConfigurationUpdateFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_CP_ConfigurationUpdateFailure
GNB_CU_CP_ConfigurationUpdateFailure decode_GNB_CU_CP_ConfigurationUpdateFailure(BitReader& reader) {
    GNB_CU_CP_ConfigurationUpdateFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for E1ReleaseRequest
void encode_E1ReleaseRequest(BitWriter& writer, const E1ReleaseRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for E1ReleaseRequest
E1ReleaseRequest decode_E1ReleaseRequest(BitReader& reader) {
    E1ReleaseRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for E1ReleaseResponse
void encode_E1ReleaseResponse(BitWriter& writer, const E1ReleaseResponse& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for E1ReleaseResponse
E1ReleaseResponse decode_E1ReleaseResponse(BitReader& reader) {
    E1ReleaseResponse value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for BearerContextSetupRequest
void encode_BearerContextSetupRequest(BitWriter& writer, const BearerContextSetupRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextSetupRequest
BearerContextSetupRequest decode_BearerContextSetupRequest(BitReader& reader) {
    BearerContextSetupRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextSetupRequest
void encode_System_BearerContextSetupRequest(BitWriter& writer, const System_BearerContextSetupRequest& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextSetupRequest);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextSetupRequest);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextSetupRequest
System_BearerContextSetupRequest decode_System_BearerContextSetupRequest(BitReader& reader) {
    System_BearerContextSetupRequest value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextSetupRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextSetupRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextSetupResponse
void encode_BearerContextSetupResponse(BitWriter& writer, const BearerContextSetupResponse& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextSetupResponse
BearerContextSetupResponse decode_BearerContextSetupResponse(BitReader& reader) {
    BearerContextSetupResponse value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextSetupResponse
void encode_System_BearerContextSetupResponse(BitWriter& writer, const System_BearerContextSetupResponse& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextSetupResponse);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextSetupResponse);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextSetupResponse
System_BearerContextSetupResponse decode_System_BearerContextSetupResponse(BitReader& reader) {
    System_BearerContextSetupResponse value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextSetupResponse = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextSetupResponse = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextSetupFailure
void encode_BearerContextSetupFailure(BitWriter& writer, const BearerContextSetupFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextSetupFailure
BearerContextSetupFailure decode_BearerContextSetupFailure(BitReader& reader) {
    BearerContextSetupFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for BearerContextModificationRequest
void encode_BearerContextModificationRequest(BitWriter& writer, const BearerContextModificationRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextModificationRequest
BearerContextModificationRequest decode_BearerContextModificationRequest(BitReader& reader) {
    BearerContextModificationRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextModificationRequest
void encode_System_BearerContextModificationRequest(BitWriter& writer, const System_BearerContextModificationRequest& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextModificationRequest);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextModificationRequest);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextModificationRequest
System_BearerContextModificationRequest decode_System_BearerContextModificationRequest(BitReader& reader) {
    System_BearerContextModificationRequest value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextModificationRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextModificationRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextModificationResponse
void encode_BearerContextModificationResponse(BitWriter& writer, const BearerContextModificationResponse& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextModificationResponse
BearerContextModificationResponse decode_BearerContextModificationResponse(BitReader& reader) {
    BearerContextModificationResponse value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextModificationResponse
void encode_System_BearerContextModificationResponse(BitWriter& writer, const System_BearerContextModificationResponse& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextModificationResponse);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextModificationResponse);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextModificationResponse
System_BearerContextModificationResponse decode_System_BearerContextModificationResponse(BitReader& reader) {
    System_BearerContextModificationResponse value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextModificationResponse = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextModificationResponse = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextModificationFailure
void encode_BearerContextModificationFailure(BitWriter& writer, const BearerContextModificationFailure& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextModificationFailure
BearerContextModificationFailure decode_BearerContextModificationFailure(BitReader& reader) {
    BearerContextModificationFailure value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for BearerContextModificationRequired
void encode_BearerContextModificationRequired(BitWriter& writer, const BearerContextModificationRequired& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextModificationRequired
BearerContextModificationRequired decode_BearerContextModificationRequired(BitReader& reader) {
    BearerContextModificationRequired value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextModificationRequired
void encode_System_BearerContextModificationRequired(BitWriter& writer, const System_BearerContextModificationRequired& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextModificationRequired);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextModificationRequired);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextModificationRequired
System_BearerContextModificationRequired decode_System_BearerContextModificationRequired(BitReader& reader) {
    System_BearerContextModificationRequired value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextModificationRequired = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextModificationRequired = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextModificationConfirm
void encode_BearerContextModificationConfirm(BitWriter& writer, const BearerContextModificationConfirm& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextModificationConfirm
BearerContextModificationConfirm decode_BearerContextModificationConfirm(BitReader& reader) {
    BearerContextModificationConfirm value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_BearerContextModificationConfirm
void encode_System_BearerContextModificationConfirm(BitWriter& writer, const System_BearerContextModificationConfirm& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_BearerContextModificationConfirm);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_BearerContextModificationConfirm);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_BearerContextModificationConfirm
System_BearerContextModificationConfirm decode_System_BearerContextModificationConfirm(BitReader& reader) {
    System_BearerContextModificationConfirm value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_BearerContextModificationConfirm = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_BearerContextModificationConfirm = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for BearerContextReleaseCommand
void encode_BearerContextReleaseCommand(BitWriter& writer, const BearerContextReleaseCommand& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextReleaseCommand
BearerContextReleaseCommand decode_BearerContextReleaseCommand(BitReader& reader) {
    BearerContextReleaseCommand value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for BearerContextReleaseComplete
void encode_BearerContextReleaseComplete(BitWriter& writer, const BearerContextReleaseComplete& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextReleaseComplete
BearerContextReleaseComplete decode_BearerContextReleaseComplete(BitReader& reader) {
    BearerContextReleaseComplete value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for BearerContextReleaseRequest
void encode_BearerContextReleaseRequest(BitWriter& writer, const BearerContextReleaseRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextReleaseRequest
BearerContextReleaseRequest decode_BearerContextReleaseRequest(BitReader& reader) {
    BearerContextReleaseRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DRB_Status_List
void encode_DRB_Status_List(BitWriter& writer, const DRB_Status_List& value) {
    if (value.size() < 1 || value.size() > 32) {
        throw std::runtime_error("SEQUENCE OF SIZE constraint violation: size " + std::to_string(value.size()) + " out of range [1, 32].");
    }
    UperLength::encodeLength(writer, value.size(), 1, 32);
    for (const auto& element : value) {
        E1AP_IEs::encode_DRB_Status_Item(writer, element);
    }
}

// Decoder for DRB_Status_List
DRB_Status_List decode_DRB_Status_List(BitReader& reader) {
    DRB_Status_List value{};
    {
        size_t length = UperLength::decodeLength(reader, 1, 32);
        if (length < 1 || length > 32) {
            throw std::runtime_error("SEQUENCE OF SIZE constraint violation: decoded size " + std::to_string(length) + " out of range [1, 32].");
        }
        value.resize(length);
        for (size_t i = 0; i < length; ++i) {
            value[i] = E1AP_IEs::decode_DRB_Status_Item(reader);
        }
    }
    return value;
}

// Encoder for BearerContextInactivityNotification
void encode_BearerContextInactivityNotification(BitWriter& writer, const BearerContextInactivityNotification& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for BearerContextInactivityNotification
BearerContextInactivityNotification decode_BearerContextInactivityNotification(BitReader& reader) {
    BearerContextInactivityNotification value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DLDataNotification
void encode_DLDataNotification(BitWriter& writer, const DLDataNotification& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DLDataNotification
DLDataNotification decode_DLDataNotification(BitReader& reader) {
    DLDataNotification value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for ULDataNotification
void encode_ULDataNotification(BitWriter& writer, const ULDataNotification& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for ULDataNotification
ULDataNotification decode_ULDataNotification(BitReader& reader) {
    ULDataNotification value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for DataUsageReport
void encode_DataUsageReport(BitWriter& writer, const DataUsageReport& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for DataUsageReport
DataUsageReport decode_DataUsageReport(BitReader& reader) {
    DataUsageReport value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_CounterCheckRequest
void encode_GNB_CU_UP_CounterCheckRequest(BitWriter& writer, const GNB_CU_UP_CounterCheckRequest& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_CounterCheckRequest
GNB_CU_UP_CounterCheckRequest decode_GNB_CU_UP_CounterCheckRequest(BitReader& reader) {
    GNB_CU_UP_CounterCheckRequest value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for System_GNB_CU_UP_CounterCheckRequest
void encode_System_GNB_CU_UP_CounterCheckRequest(BitWriter& writer, const System_GNB_CU_UP_CounterCheckRequest& value) {
    {
        size_t choice_index_1 = value.index();
        UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.e_UTRAN_GNB_CU_UP_CounterCheckRequest);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                E1AP_Containers::encode_ProtocolIE_Container(writer, arg_1.nG_RAN_GNB_CU_UP_CounterCheckRequest);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                E1AP_Containers::encode_ProtocolIE_SingleContainer(writer, arg_1.choice_extension);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for System_GNB_CU_UP_CounterCheckRequest
System_GNB_CU_UP_CounterCheckRequest decode_System_GNB_CU_UP_CounterCheckRequest(BitReader& reader) {
    System_GNB_CU_UP_CounterCheckRequest value{};
    {
        size_t choice_index_1 = 0;
        choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.e_UTRAN_GNB_CU_UP_CounterCheckRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.nG_RAN_GNB_CU_UP_CounterCheckRequest = E1AP_Containers::decode_ProtocolIE_Container(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.choice_extension = E1AP_Containers::decode_ProtocolIE_SingleContainer(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

// Encoder for GNB_CU_UP_StatusIndication
void encode_GNB_CU_UP_StatusIndication(BitWriter& writer, const GNB_CU_UP_StatusIndication& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for GNB_CU_UP_StatusIndication
GNB_CU_UP_StatusIndication decode_GNB_CU_UP_StatusIndication(BitReader& reader) {
    GNB_CU_UP_StatusIndication value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for MRDC_DataUsageReport
void encode_MRDC_DataUsageReport(BitWriter& writer, const MRDC_DataUsageReport& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_ProtocolIE_Container(writer, value.protocolIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for MRDC_DataUsageReport
MRDC_DataUsageReport decode_MRDC_DataUsageReport(BitReader& reader) {
    MRDC_DataUsageReport value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.protocolIEs = E1AP_Containers::decode_ProtocolIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

// Encoder for PrivateMessage
void encode_PrivateMessage(BitWriter& writer, const PrivateMessage& value) {
    {
        bool has_extensions = false;
        UperExtension::encodeExtensionMarker(writer, has_extensions);

        E1AP_Containers::encode_PrivateIE_Container(writer, value.privateIEs);
        if (has_extensions) {
            uint64_t extension_bitmap = 0;
            UperLength::encodeUnconstrainedLength(writer, 0);
            writer.writeBits(extension_bitmap, 0);

            // The 'unknown_extensions' field is for round-tripping and is not used during encoding.
        }
    }
}

// Decoder for PrivateMessage
PrivateMessage decode_PrivateMessage(BitReader& reader) {
    PrivateMessage value{};
    {
        bool has_extensions = UperExtension::decodeExtensionMarker(reader);

        value.privateIEs = E1AP_Containers::decode_PrivateIE_Container(reader);
        if (has_extensions) {
            size_t num_extensions_in_message = UperLength::decodeUnconstrainedLength(reader);
            uint64_t extension_bitmap = reader.readBits(num_extensions_in_message);
            for (size_t i = 0; i < num_extensions_in_message; ++i) {
                if ((extension_bitmap >> (num_extensions_in_message - 1 - i)) & 1) {
                    value.unknown_extensions.push_back(UperExtension::decodeOpenType(reader));
                }
            }
        }
    }
    return value;
}

} // namespace E1AP_PDU_Contents

namespace E1AP_PDU_Descriptions {

// Encoder for InitiatingMessage
void encode_InitiatingMessage(BitWriter& writer, const InitiatingMessage& value) {
    {
        E1AP_CommonDataTypes::encode_ProcedureCode(writer, value.procedureCode);
        E1AP_CommonDataTypes::encode_Criticality(writer, value.criticality);
        UperExtension::encodeOpenType(writer, {}); // open type
    }
}

// Decoder for InitiatingMessage
InitiatingMessage decode_InitiatingMessage(BitReader& reader) {
    InitiatingMessage value{};
    {
        value.procedureCode = E1AP_CommonDataTypes::decode_ProcedureCode(reader);
        value.criticality = E1AP_CommonDataTypes::decode_Criticality(reader);
        UperExtension::decodeOpenType(reader); // open type
    }
    return value;
}

// Encoder for SuccessfulOutcome
void encode_SuccessfulOutcome(BitWriter& writer, const SuccessfulOutcome& value) {
    {
        E1AP_CommonDataTypes::encode_ProcedureCode(writer, value.procedureCode);
        E1AP_CommonDataTypes::encode_Criticality(writer, value.criticality);
        UperExtension::encodeOpenType(writer, {}); // open type
    }
}

// Decoder for SuccessfulOutcome
SuccessfulOutcome decode_SuccessfulOutcome(BitReader& reader) {
    SuccessfulOutcome value{};
    {
        value.procedureCode = E1AP_CommonDataTypes::decode_ProcedureCode(reader);
        value.criticality = E1AP_CommonDataTypes::decode_Criticality(reader);
        UperExtension::decodeOpenType(reader); // open type
    }
    return value;
}

// Encoder for UnsuccessfulOutcome
void encode_UnsuccessfulOutcome(BitWriter& writer, const UnsuccessfulOutcome& value) {
    {
        E1AP_CommonDataTypes::encode_ProcedureCode(writer, value.procedureCode);
        E1AP_CommonDataTypes::encode_Criticality(writer, value.criticality);
        UperExtension::encodeOpenType(writer, {}); // open type
    }
}

// Decoder for UnsuccessfulOutcome
UnsuccessfulOutcome decode_UnsuccessfulOutcome(BitReader& reader) {
    UnsuccessfulOutcome value{};
    {
        value.procedureCode = E1AP_CommonDataTypes::decode_ProcedureCode(reader);
        value.criticality = E1AP_CommonDataTypes::decode_Criticality(reader);
        UperExtension::decodeOpenType(reader); // open type
    }
    return value;
}

// Encoder for E1AP_PDU
void encode_E1AP_PDU(BitWriter& writer, const E1AP_PDU& value) {
    {
        bool is_extended = std::holds_alternative<asn1::runtime::ExtensionValue>(value);
        UperExtension::encodeExtensionMarker(writer, is_extended);

        size_t choice_index_1 = value.index();
        if (!is_extended) {
            UperChoice::encodeChoiceIndex(writer, choice_index_1, 3);
        } else {
            const auto& ext_val = std::get<asn1::runtime::ExtensionValue>(value);
            UperLength::encodeUnconstrainedLength(writer, ext_val.extension_index);
        }

        std::visit([&](auto&& arg_1) {
            using T = std::decay_t<decltype(arg_1)>;
            using WrapperType0 = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType0>) {
                encode_InitiatingMessage(writer, arg_1.initiatingMessage);
            }
            using WrapperType1 = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType1>) {
                encode_SuccessfulOutcome(writer, arg_1.successfulOutcome);
            }
            using WrapperType2 = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            if constexpr (std::is_same_v<T, WrapperType2>) {
                encode_UnsuccessfulOutcome(writer, arg_1.unsuccessfulOutcome);
            }
            if constexpr (std::is_same_v<T, asn1::runtime::ExtensionValue>) {
                UperExtension::encodeOpenType(writer, arg_1.encoded_value);
            }
        }, value);
    }
}

// Decoder for E1AP_PDU
E1AP_PDU decode_E1AP_PDU(BitReader& reader) {
    E1AP_PDU value{};
    {
        bool is_extended = UperExtension::decodeExtensionMarker(reader);

        size_t choice_index_1 = 0;
        if (!is_extended) {
            choice_index_1 = UperChoice::decodeChoiceIndex(reader, 3);
        } else {
            asn1::runtime::ExtensionValue ext_val;
            ext_val.extension_index = UperLength::decodeUnconstrainedLength(reader);
            ext_val.encoded_value = UperExtension::decodeOpenType(reader);
            value.emplace<asn1::runtime::ExtensionValue>(ext_val);
        }

        switch (choice_index_1) {
        case 0: {
            using WrapperType = std::variant_alternative_t<0, std::decay_t<decltype(value)>>;
            WrapperType it_1_0;
            it_1_0.initiatingMessage = decode_InitiatingMessage(reader);
            value.emplace<WrapperType>(it_1_0);
            break;
        }
        case 1: {
            using WrapperType = std::variant_alternative_t<1, std::decay_t<decltype(value)>>;
            WrapperType it_1_1;
            it_1_1.successfulOutcome = decode_SuccessfulOutcome(reader);
            value.emplace<WrapperType>(it_1_1);
            break;
        }
        case 2: {
            using WrapperType = std::variant_alternative_t<2, std::decay_t<decltype(value)>>;
            WrapperType it_1_2;
            it_1_2.unsuccessfulOutcome = decode_UnsuccessfulOutcome(reader);
            value.emplace<WrapperType>(it_1_2);
            break;
        }
        default:
            throw std::runtime_error("Invalid choice index decoded");
        }
    }
    return value;
}

} // namespace E1AP_PDU_Descriptions

} // namespace asn1::generated
