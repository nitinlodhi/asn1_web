from pathlib import Path
import re

cpp = Path("repro_e1ap/generated.cpp")
content = cpp.read_text()

# 1. Ensure APER headers are used
content = content.replace('runtime/uper/Uper', 'runtime/aper/Aper')
content = content.replace('UperInteger', 'AperInteger')
content = content.replace('UperLength', 'AperLength')
content = content.replace('UperSequence', 'AperSequence')
content = content.replace('UperChoice', 'AperChoice')
content = content.replace('UperExtension', 'AperExtension')

# 2. Fix Includes
content = re.sub(r'#include "runtime/aper/Aper.*?\n', '', content)
includes = """#include "generated.h"
#include <stdexcept>
#include <string>
#include "runtime/aper/AperInteger.h"
#include "runtime/aper/AperLength.h"
#include "runtime/aper/AperSequence.h"
#include "runtime/aper/AperChoice.h"
#include "runtime/aper/AperObjectIdentifier.h"
#include "runtime/aper/AperExtension.h"
"""
content = re.sub(r'#include "generated.h".*?\n', includes, content, flags=re.DOTALL)

# 3. Clean up my previous UPER helper injections
content = re.sub(r'namespace \{.*?uper_decode_constrained_int_ext.*?\}', '', content, flags=re.DOTALL)
content = content.replace('uper_decode_constrained_int_ext', 'AperInteger::decodeConstrainedIntExt')
content = content.replace('uper_encode_constrained_int_ext', 'AperInteger::encodeConstrainedIntExt')

# 4. Correctly wrap in namespace and handle ambiguity
# We'll use a safer approach: wrap the whole file except includes in the namespace
content = content.replace('namespace asn1::generated {', '').replace('} // namespace asn1::generated', '')
content = content.replace('using namespace asn1::runtime;', '')

final_content = includes + "\nnamespace asn1::generated {\nusing namespace asn1::runtime;\n"
# Add module aliases to avoid ambiguity
header_path = cpp.with_suffix('.h')
header_content = header_path.read_text()
namespaces = re.findall(r'namespace (E1AP_\w+)', header_content)
namespaces = sorted(list(set(namespaces)))
for ns in namespaces:
    final_content += f"using namespace {ns};\n"

# Filter out the body
body_match = re.search(r'// Decoder for.*', content, re.DOTALL)
if body_match:
    final_content += body_match.group(0)
final_content += "\n} // namespace asn1::generated"

cpp.write_text(final_content)
