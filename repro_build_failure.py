import sys
import re
from pathlib import Path
import shutil
import tempfile
import subprocess

# Mimic backend/main.py and backend/harness_builder.py
COMPILER = Path("../asn_compiler/build/bin/asn1_compiler").resolve()
RUNTIME_INC = Path("../asn_compiler/include").resolve()
RUNTIME_LIB = Path("../asn_compiler/build/lib/libasn1_runtime.a").resolve()
HARNESS_MAIN = Path("backend/harness_main.cpp").resolve()
VENDOR_DIR = Path("vendor").resolve()
SCHEMA_FILE = Path("repro_e1ap/input.asn1").resolve()

def test_repro():
    workdir = Path(tempfile.mkdtemp(prefix="repro_build_"))
    print(f"Workdir: {workdir}")
    
    try:
        # 1. Compile
        cmd = [str(COMPILER), str(SCHEMA_FILE), "-o", str(workdir / "generated"), 
               "--lang", "cpp", "--json", "--schema", "--encoding", "uper"]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0:
            print("Compile failed:", r.stderr)
            return

        # 2. Patch (Mimic backend/main.py)
        generated_cpp = workdir / "generated.cpp"
        content = generated_cpp.read_text()
        
        # --- START HACKS ---
        import re
        if '#include "runtime/aper/AperInteger.h"' not in content:
            content = '#include "runtime/aper/AperInteger.h"\n' + content
        if '#include "runtime/uper/UperExtension.h"' not in content:
            content = '#include "runtime/uper/UperExtension.h"\n' + content
        
        content = content.replace('AperInteger::decodeConstrainedIntExt', 'uper_decode_constrained_int_ext')
        content = content.replace('AperInteger::encodeConstrainedIntExt', 'uper_encode_constrained_int_ext')
        content = content.replace('AperInteger::', 'asn1::runtime::AperInteger::')
        content = content.replace('UperInteger::', 'asn1::runtime::AperInteger::')
        
        # 2. Add alignment for Open Types and Lengths (Critical for 3GPP protocols)
        
        # OpenType Decode
        content = content.replace('UperExtension::decodeOpenType(reader)', 
                                  '([](asn1::runtime::BitReader& r){ r.alignToOctet(); return asn1::runtime::UperExtension::decodeOpenType(r); }(reader))')
        
        # OpenType Encode
        content = re.sub(r'UperExtension::encodeOpenType\(writer,\s*(.*?)\);',
                         r'{ writer.alignToOctet(); asn1::runtime::UperExtension::encodeOpenType(writer, \1); }',
                         content)

        # Length Decode (Constrained)
        content = re.sub(r'UperLength::decodeLength\(reader,\s*(.*?),\s*(.*?)\)',
                         r'([](asn1::runtime::BitReader& r, size_t min, size_t max){ r.alignToOctet(); return asn1::runtime::UperLength::decodeLength(r, min, max); }(reader, \1, \2))',
                         content)
        
        # Length Encode (Constrained)
        content = re.sub(r'UperLength::encodeLength\(writer,\s*(.*?),\s*(.*?),\s*(.*?)\)',
                         r'([](asn1::runtime::BitWriter& w, size_t l, size_t min, size_t max){ w.alignToOctet(); asn1::runtime::UperLength::encodeLength(w, l, min, max); })(writer, \1, \2, \3)',
                         content)

        # Length Decode (Unconstrained)
        content = content.replace('UperLength::decodeUnconstrainedLength(reader)',
                                  '([](asn1::runtime::BitReader& r){ r.alignToOctet(); return asn1::runtime::UperLength::decodeUnconstrainedLength(r); }(reader))')
        
        # Length Encode (Unconstrained)
        content = re.sub(r'UperLength::encodeUnconstrainedLength\(writer,\s*(.*?)\)',
                         r'([](asn1::runtime::BitWriter& w, size_t l){ w.alignToOctet(); asn1::runtime::UperLength::encodeUnconstrainedLength(w, l); })(writer, \1)',
                         content)

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
        pos = content.find('\n//')
        if pos == -1: pos = content.find('\nnamespace')
        if pos != -1:
            content = content[:pos] + helper_code + content[pos:]
        # --- END HACKS ---
        
        generated_cpp.write_text(content)

        # 3. Build
        cmd = [
            "g++", "-std=c++20", "-O0",
            f"-I{workdir}", f"-I{RUNTIME_INC}", f"-I{VENDOR_DIR}",
            "-o", str(workdir / "harness"),
            str(HARNESS_MAIN),
            str(generated_cpp),
            str(RUNTIME_LIB),
            "-lpthread",
        ]
        print("Building...")
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0:
            print("BUILD FAILED:")
            print(r.stderr)
        else:
            print("BUILD SUCCESSFUL")

    finally:
        shutil.rmtree(workdir)

if __name__ == "__main__":
    test_repro()
