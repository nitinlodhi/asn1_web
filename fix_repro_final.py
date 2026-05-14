import re
from pathlib import Path

cpp = Path("repro_e1ap/generated.cpp")
content = cpp.read_text()

# 1. Map to Aper and add alignment
content = content.replace('UperInteger', 'asn1::runtime::AperInteger')
content = content.replace('AperInteger', 'asn1::runtime::AperInteger')
content = content.replace('UperExtension::decodeOpenType(reader)', 
                          '(reader.alignToOctet(), asn1::runtime::UperExtension::decodeOpenType(reader))')
content = content.replace('UperExtension::encodeOpenType(writer,', 
                          '(writer.alignToOctet(), asn1::runtime::UperExtension::encodeOpenType(writer,')

# 2. Fix Includes
content = re.sub(r'#include.*?\n', '', content)
includes = """#include "generated.h"
#include <stdexcept>
#include <string>
#include "runtime/aper/AperInteger.h"
#include "runtime/uper/UperLength.h"
#include "runtime/uper/UperSequence.h"
#include "runtime/uper/UperChoice.h"
#include "runtime/uper/UperObjectIdentifier.h"
#include "runtime/uper/UperExtension.h"

namespace {
    int64_t uper_decode_constrained_int_ext(asn1::runtime::BitReader& reader, int64_t min, int64_t max, bool& isExt) {
        isExt = asn1::runtime::UperExtension::decodeExtensionMarker(reader);
        if (!isExt) return asn1::runtime::AperInteger::decodeConstrainedInt(reader, min, max);
        return 0;
    }
    void uper_encode_constrained_int_ext(asn1::runtime::BitWriter& writer, int64_t value, int64_t min, int64_t max) {
        asn1::runtime::UperExtension::encodeExtensionMarker(writer, false);
        asn1::runtime::AperInteger::encodeConstrainedInt(writer, value, min, max);
    }
}

using namespace asn1::runtime;
"""
content = content.replace('uper_decode_constrained_int_ext', 'AperInteger::decodeConstrainedIntExt')
content = content.replace('uper_encode_constrained_int_ext', 'AperInteger::encodeConstrainedIntExt')

content = content.replace('asn1::runtime::AperInteger::decodeConstrainedIntExt', 'uper_decode_constrained_int_ext')
content = content.replace('asn1::runtime::AperInteger::encodeConstrainedIntExt', 'uper_encode_constrained_int_ext')

# 3. Assemble
final_content = includes + content
cpp.write_text(final_content)
