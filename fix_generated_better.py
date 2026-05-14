import sys
import re
from pathlib import Path

def fix_generated_cpp(cpp_path):
    content = cpp_path.read_text()
    
    # 1. Map Aper to Uper fully qualified logic
    # We do this BEFORE wrapping in namespace to avoid double prefixing
    content = content.replace('AperInteger::', 'asn1::runtime::UperInteger::')
    
    # 2. Inject UperExtension helper
    helper_code = """
namespace {
    int64_t uper_decode_constrained_int_ext(asn1::runtime::BitReader& reader, int64_t min, int64_t max, bool& isExt) {
        isExt = asn1::runtime::UperExtension::decodeExtensionMarker(reader);
        if (!isExt) return asn1::runtime::UperInteger::decodeConstrainedInt(reader, min, max);
        return 0;
    }
    void uper_encode_constrained_int_ext(asn1::runtime::BitWriter& writer, int64_t value, int64_t min, int64_t max) {
        asn1::runtime::UperExtension::encodeExtensionMarker(writer, false);
        asn1::runtime::UperInteger::encodeConstrainedInt(writer, value, min, max);
    }
}
"""
    content = content.replace('asn1::runtime::UperInteger::decodeConstrainedIntExt', 'uper_decode_constrained_int_ext')
    content = content.replace('asn1::runtime::UperInteger::encodeConstrainedIntExt', 'uper_encode_constrained_int_ext')

    # 3. Handle includes and namespaces
    # Remove existing includes and namespaces
    content = re.sub(r'#include.*?\n', '', content)
    content = content.replace('namespace asn1::generated {', '').replace('} // namespace asn1::generated', '')
    content = content.replace('using namespace asn1::runtime;', '')
    
    header_name = cpp_path.with_suffix('.h').name
    
    final_content = f'#include "{header_name}"\n'
    final_content += '#include <stdexcept>\n#include <string>\n'
    final_content += '#include "runtime/uper/UperLength.h"\n'
    final_content += '#include "runtime/uper/UperInteger.h"\n'
    final_content += '#include "runtime/uper/UperSequence.h"\n'
    final_content += '#include "runtime/uper/UperChoice.h"\n'
    final_content += '#include "runtime/uper/UperObjectIdentifier.h"\n'
    final_content += '#include "runtime/uper/UperExtension.h"\n'
    final_content += helper_code
    final_content += '\nnamespace asn1::generated {\n'
    final_content += 'using namespace asn1::runtime;\n'
    # We do NOT use the module namespaces here to avoid ambiguity with the global functions
    
    # Prefix all module types with their namespace if they aren't already?
    # Actually, the compiler usually generates them as 'Criticality' but they are in 'E1AP_CommonDataTypes'.
    # If I don't use 'using namespace', it will fail.
    # BUT if I DO use it, it's ambiguous.
    # FIX: Define the functions AS members of the module namespaces!
    
    # Let's try a different trick: Use 'using' for ONLY the types we need.
    # Or better: Wrap the whole thing in module-specific namespaces in the CPP too!
    
    # Wait, the compiler generated code looks like:
    # Criticality decode_Criticality(...) { ... }
    # In the header it's:
    # namespace E1AP_CommonDataTypes { Criticality decode_Criticality(...); }
    
    # If I change the CPP to:
    # namespace E1AP_CommonDataTypes {
    #   Criticality decode_Criticality(...) { ... }
    # }
    # Then it matches the header and avoids ambiguity.
    
    # I will attempt to split the file by "// Decoder for [Module]::[Type]" comments
    # and wrap them in the appropriate namespace.
    
    final_content += content.strip()
    final_content += "\n\n} // namespace asn1::generated"
    
    cpp_path.write_text(final_content)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        fix_generated_cpp(Path(sys.argv[1]))
