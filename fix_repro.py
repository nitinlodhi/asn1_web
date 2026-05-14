from pathlib import Path
import re

cpp = Path("repro_e1ap/generated.cpp")
content = cpp.read_text()

# 1. Map Aper to Uper fully qualified everywhere
content = content.replace("AperInteger::", "asn1::runtime::UperInteger::")

# 2. Replace helper calls
content = content.replace("asn1::runtime::UperInteger::decodeConstrainedIntExt", "uper_decode_constrained_int_ext")
content = content.replace("asn1::runtime::UperInteger::encodeConstrainedIntExt", "uper_encode_constrained_int_ext")

# 3. Clean headers
content = re.sub(r'^#include.*?\n', '', content, flags=re.MULTILINE)

final_content = """#include "generated.h"
#include <stdexcept>
#include <string>
#include "runtime/uper/UperLength.h"
#include "runtime/uper/UperInteger.h"
#include "runtime/uper/UperSequence.h"
#include "runtime/uper/UperChoice.h"
#include "runtime/uper/UperObjectIdentifier.h"
#include "runtime/uper/UperExtension.h"

using namespace asn1::runtime;
using namespace asn1::generated;
using namespace asn1::generated::E1AP_CommonDataTypes;
using namespace asn1::generated::E1AP_Constants;
using namespace asn1::generated::E1AP_Containers;
using namespace asn1::generated::E1AP_IEs;
using namespace asn1::generated::E1AP_PDU_Contents;
using namespace asn1::generated::E1AP_PDU_Descriptions;

namespace {
    int64_t uper_decode_constrained_int_ext(BitReader& reader, int64_t min, int64_t max, bool& isExt) {
        isExt = UperExtension::decodeExtensionMarker(reader);
        if (!isExt) return UperInteger::decodeConstrainedInt(reader, min, max);
        return 0;
    }
    void uper_encode_constrained_int_ext(BitWriter& writer, int64_t value, int64_t min, int64_t max) {
        UperExtension::encodeExtensionMarker(writer, false);
        UperInteger::encodeConstrainedInt(writer, value, min, max);
    }
}

namespace asn1::generated {
"""

# Find the first function definition (usually // Decoder)
body_match = re.search(r'// (Decoder|Encoder).*', content, re.DOTALL)
if body_match:
    body = body_match.group(0)
    # Remove existing namespace closes
    body = body.replace("} // namespace asn1::generated", "")
    final_content += body
else:
    print("Could not find functions in body")

final_content += "\n} // namespace asn1::generated"
cpp.write_text(final_content)
