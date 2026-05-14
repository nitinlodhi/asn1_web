import sys
import re
from pathlib import Path

def fix_file(path):
    p = Path(path)
    lines = p.read_text().splitlines()
    
    # 1. Strip everything before #include "generated.h"
    start_idx = -1
    for i, line in enumerate(lines):
        if '#include "generated.h"' in line:
            start_idx = i
            break
    
    if start_idx == -1:
        print("Could not find generated.h include")
        return
        
    lines = lines[start_idx:]
    
    # 2. Fix includes and collect module namespaces from the header
    new_lines = []
    has_uper_int = False
    
    header_path = p.with_suffix('.h')
    header_content = header_path.read_text()
    namespaces = re.findall(r'namespace (E1AP_\w+)', header_content)
    namespaces = sorted(list(set(namespaces)))

    new_lines.append('#include "generated.h"')
    new_lines.append('#include <stdexcept>')
    new_lines.append('#include <string>')
    new_lines.append('#include "runtime/uper/UperLength.h"')
    new_lines.append('#include "runtime/uper/UperInteger.h"')
    new_lines.append('#include "runtime/uper/UperSequence.h"')
    new_lines.append('#include "runtime/uper/UperChoice.h"')
    new_lines.append('#include "runtime/uper/UperObjectIdentifier.h"')
    new_lines.append('#include "runtime/uper/UperExtension.h"')
    new_lines.append('')
    new_lines.append('namespace asn1::generated {')
    new_lines.append('using namespace asn1::runtime;')
    for ns in namespaces:
        new_lines.append(f'using namespace {ns};')
    
    new_lines.append('')
    new_lines.append('namespace {')
    new_lines.append('    int64_t uper_decode_constrained_int_ext(BitReader& reader, int64_t min, int64_t max, bool& isExt) {')
    new_lines.append('        isExt = UperExtension::decodeExtensionMarker(reader);')
    new_lines.append('        if (!isExt) return UperInteger::decodeConstrainedInt(reader, min, max);')
    new_lines.append('        return 0;')
    new_lines.append('    }')
    new_lines.append('    void uper_encode_constrained_int_ext(BitWriter& writer, int64_t value, int64_t min, int64_t max) {')
    new_lines.append('        UperExtension::encodeExtensionMarker(writer, false);')
    new_lines.append('        UperInteger::encodeConstrainedInt(writer, value, min, max);')
    new_lines.append('    }')
    new_lines.append('}')
    new_lines.append('')

    # Skip original includes in the source
    for line in lines[1:]:
        if line.startswith('#include') or 'namespace' in line or 'using namespace' in line:
            continue
        new_lines.append(line)
    
    # Ensure one final closing brace for asn1::generated
    content = "\n".join(new_lines)
    
    # Global replacements
    content = content.replace("AperInteger::", "UperInteger::")
    content = content.replace("UperInteger::decodeConstrainedIntExt", "uper_decode_constrained_int_ext")
    content = content.replace("UperInteger::encodeConstrainedIntExt", "uper_encode_constrained_int_ext")
    
    # Clean up multiple closing braces at end if any
    content = content.strip()
    while content.endswith('}'):
        content = content[:-1].strip()
    content += "\n\n} // namespace asn1::generated"

    p.write_text(content)
    print(f"Fixed {path}")

if __name__ == "__main__":
    fix_file(sys.argv[1])
