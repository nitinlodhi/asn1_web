import sys
import subprocess
from pathlib import Path
import tempfile
import shutil
import json
import os
import re

# Adjust paths to match your environment
ROOT = Path(__file__).resolve().parent.parent
COMPILER = ROOT.parent / "asn_compiler/build/bin/asn1_compiler"
RUNTIME_INC = ROOT.parent / "asn_compiler/include"
RUNTIME_LIB = ROOT.parent / "asn_compiler/build/lib/libasn1_runtime.a"
HARNESS_MAIN = ROOT / "backend/harness_main.cpp"
VENDOR_INC = ROOT / "vendor"

# Input Data
SCHEMA_FILE = ROOT / "repro_e1ap/input.asn1"
HEX_DATA = "0009003400000300020005C00309000100030005C0030900010012001B400001002B00140000400502100000000F80C0A809020000000100"
PDU_TYPE = "E1AP_PDU_Descriptions::E1AP_PDU"

def apply_patches(cpp_path, hpp_path):
    # 1. generated.cpp
    if cpp_path.exists():
        print("Patching generated.cpp...")
        content = cpp_path.read_text()
        
        # Match the robust fixes in backend/main.py
        # Ensure we have the headers
        if '#include "runtime/aper/AperInteger.h"' not in content:
             content = '#include "runtime/aper/AperInteger.h"\n' + content
        if '#include "runtime/uper/UperExtension.h"' not in content:
             content = '#include "runtime/uper/UperExtension.h"\n' + content

        # Replace helpers
        content = content.replace('AperInteger::decodeConstrainedIntExt', 'uper_decode_constrained_int_ext')
        content = content.replace('AperInteger::encodeConstrainedIntExt', 'uper_encode_constrained_int_ext')
        
        # Map to full names
        content = content.replace('AperInteger::', 'asn1::runtime::AperInteger::')
        content = content.replace('UperInteger::', 'asn1::runtime::AperInteger::')
        
        # Add alignment for Open Types - FIXED SYNTAX
        content = content.replace('UperExtension::decodeOpenType(reader)', 
                                  '([](asn1::runtime::BitReader& r){ r.alignToOctet(); return asn1::runtime::UperExtension::decodeOpenType(r); }(reader))')
        
        # Special case for encode which has multiple args
        # UperExtension::encodeOpenType(writer, ...)
        # We need a regex or a very specific replace
        content = re.sub(r'UperExtension::encodeOpenType\(writer,\s*(.*?)\);',
                         r'{ writer.alignToOctet(); asn1::runtime::UperExtension::encodeOpenType(writer, \1); }',
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
        # Insert helpers after includes
        pos = content.find('\n//')
        if pos == -1: pos = content.find('\nnamespace')
        if pos != -1:
            content = content[:pos] + helper_code + content[pos:]
        
        cpp_path.write_text(content)

    # 2. generated_json.hpp
    if hpp_path.exists():
        print("Patching generated_json.hpp...")
        content = hpp_path.read_text()
        content = content.replace('"true_"', '"true"').replace('"false_"', '"false"')
        hpp_path.write_text(content)

def test_codec():
    print(f"Using compiler: {COMPILER}")
    if not COMPILER.exists():
        print(f"ERROR: Compiler not found at {COMPILER}")
        return

    workdir = Path(tempfile.mkdtemp(prefix="test_e1ap_"))
    try:
        print(f"Workdir: {workdir}")
        # 1. Compile schema
        print(f"Compiling {SCHEMA_FILE}...")
        cmd = [str(COMPILER), str(SCHEMA_FILE), "-o", str(workdir / "generated"), "--lang", "cpp", "--json", "--schema"]
        subprocess.run(cmd, check=True, capture_output=True)

        # 2. Apply patches
        apply_patches(workdir / "generated.cpp", workdir / "generated_json.hpp")

        # 3. Build harness
        harness_bin = workdir / "harness"
        build_cmd = [
            "g++", "-std=c++20", "-O0",
            f"-I{workdir}", f"-I{RUNTIME_INC}", f"-I{VENDOR_INC}",
            "-o", str(harness_bin),
            str(HARNESS_MAIN),
            str(workdir / "generated.cpp"),
            str(RUNTIME_LIB),
            "-lpthread"
        ]
        print("Building harness...")
        try:
            subprocess.run(build_cmd, check=True, capture_output=True)
        except subprocess.CalledProcessError as e:
            print("Harness build FAILED:")
            print(e.stderr.decode() if isinstance(e.stderr, bytes) else e.stderr)
            return

        # 4. Decode
        print("Testing Decode...")
        decode_cmd = [str(harness_bin), "decode", PDU_TYPE]
        r = subprocess.run(decode_cmd, input=HEX_DATA, text=True, capture_output=True)
        if r.returncode != 0:
            print("Decode FAILED:")
            print(r.stderr)
            return
        
        decoded_json = r.stdout.strip()
        # print("Decoded JSON:")
        # print(decoded_json)

        # 5. Encode
        print("Testing Encode...")
        encode_cmd = [str(harness_bin), "encode", PDU_TYPE]
        r = subprocess.run(encode_cmd, input=decoded_json, text=True, capture_output=True)
        if r.returncode != 0:
            print("Encode FAILED:")
            print(r.stderr)
            return
        
        encoded_hex = r.stdout.strip().replace(" ", "").upper()
        print(f"Encoded Hex: {encoded_hex}")

        if encoded_hex == HEX_DATA.upper():
            print("\nSUCCESS! Round-trip matched original hex.")
        else:
            print("\nFAILURE! Hex mismatch.")
            print(f"Expected: {HEX_DATA.upper()}")
            print(f"Got:      {encoded_hex}")

    finally:
        shutil.rmtree(workdir)

if __name__ == "__main__":
    if not SCHEMA_FILE.exists():
        print(f"ERROR: Schema file {SCHEMA_FILE} not found.")
        sys.exit(1)
    
    test_codec()
