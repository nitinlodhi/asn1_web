import sys
import re
from pathlib import Path

def fix_generated_cpp(cpp_path):
    content = cpp_path.read_text()
    
    # 1. Standard Includes
    content = re.sub(r'^#include.*?\n', '', content, flags=re.MULTILINE)
    includes = """#include "generated.h"
#include <stdexcept>
#include <string>
#include "runtime/aper/AperInteger.h"
#include "runtime/uper/UperLength.h"
#include "runtime/uper/UperSequence.h"
#include "runtime/uper/UperChoice.h"
#include "runtime/uper/UperObjectIdentifier.h"
#include "runtime/uper/UperExtension.h"
"""
    
    # 2. Map everything to their runtime counterparts
    content = content.replace('UperInteger', 'asn1::runtime::AperInteger')
    content = content.replace('AperInteger', 'asn1::runtime::AperInteger')
    content = content.replace('UperLength', 'asn1::runtime::UperLength')
    content = content.replace('UperSequence', 'asn1::runtime::UperSequence')
    content = content.replace('UperChoice', 'asn1::runtime::UperChoice')
    content = content.replace('UperExtension', 'asn1::runtime::UperExtension')
    content = content.replace('UperObjectIdentifier', 'asn1::runtime::UperObjectIdentifier')

    # 3. Fix ambiguity by defining everything in asn1::generated
    content = content.replace('namespace asn1::generated {', '').replace('} // namespace asn1::generated', '')
    
    # 4. Remove all 'using namespace' to avoid ambiguity
    content = re.sub(r'using namespace.*?\n', '', content)
    
    # 5. Helper for extended integers
    helper_code = """
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
"""
    content = content.replace('asn1::runtime::AperInteger::decodeConstrainedIntExt', 'uper_decode_constrained_int_ext')
    content = content.replace('asn1::runtime::AperInteger::encodeConstrainedIntExt', 'uper_encode_constrained_int_ext')

    # 6. Ensure alignToOctet before OpenType for APER
    content = content.replace('asn1::runtime::UperExtension::decodeOpenType(reader)', 
                              '(reader.alignToOctet(), asn1::runtime::UperExtension::decodeOpenType(reader))')
    
    # 7. Final assembly
    # We wrap in the namespace but we DON'T use the module namespaces.
    # To fix the 'ambiguous' errors, we must ensure we are defining the ones from the header.
    # The header has E1AP_CommonDataTypes::decode_ProcedureCode.
    # We can define it as:
    # ProcedureCode E1AP_CommonDataTypes::decode_ProcedureCode(BitReader& reader) { ... }
    
    # We'll use a hack: Replace 'decode_X(' with 'E1AP_Something::decode_X('
    # But we don't know the module.
    # BETTER HACK: Use 'using namespace' ONLY inside the namespace asn1::generated block
    # and hope the compiler picks the right one.
    
    final_content = includes + helper_code + "\\nnamespace asn1::generated {\\n"
    # Re-add using for runtime only
    final_content += "using BitReader = asn1::runtime::BitReader;\\n"
    final_content += "using BitWriter = asn1::runtime::BitWriter;\\n"
    
    # Add module using but ONLY if they don't cause ambiguity.
    # Actually, the ambiguity is between '::foo' and 'asn1::generated::foo'.
    # If we define them in 'asn1::generated', they ARE the ones in the header (mostly).
    
    final_content += content.strip()
    final_content += "\\n} // namespace asn1::generated"
    
    cpp_path.write_text(final_content)

if __name__ == "__main__":
    fix_generated_cpp(Path(sys.argv[1]))
