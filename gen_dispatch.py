import re
from pathlib import Path

def extract_mappings(asn1_path):
    content = Path(asn1_path).read_text()
    
    # Match ID definitions: id-foo ProtocolIE-ID ::= 123
    id_to_val = {}
    for match in re.finditer(r'(id-[\w-]+)\s+ProtocolIE-ID\s+::=\s+(\d+)', content):
        id_to_val[match.group(1)] = int(match.group(2))
    
    # Match IE mappings in PROTOCOL-IES: { ID id-foo ... TYPE Bar ... }
    ie_mappings = {}
    for match in re.finditer(r'ID\s+(id-[\w-]+)\s+.*?TYPE\s+([\w-]+)', content, re.DOTALL):
        id_name = match.group(1)
        type_name = match.group(2)
        if id_name in id_to_val:
            ie_mappings[id_to_val[id_name]] = type_name
            
    # Match ProcedureCode definitions: id-foo ProcedureCode ::= 123
    proc_to_val = {}
    for match in re.finditer(r'(id-[\w-]+)\s+ProcedureCode\s+::=\s+(\d+)', content):
        proc_to_val[match.group(1)] = int(match.group(2))
        
    # Match Elementary Procedures: foo E1AP-ELEMENTARY-PROCEDURE ::= { ... INITIATING MESSAGE Bar SUCCESSFUL OUTCOME Baz ... PROCEDURE CODE id-foo ... }
    proc_mappings = {}
    # This is harder because it's multiline and complex
    # Let's use a simpler regex for common procedures
    for match in re.finditer(r'(\w+)\s+E1AP-ELEMENTARY-PROCEDURE\s+::=\s+{(.*?)PROCEDURE CODE\s+(id-[\w-]+)', content, re.DOTALL):
        name = match.group(1)
        body = match.group(2)
        proc_id_name = match.group(3)
        if proc_id_name in proc_to_val:
            val = proc_to_val[proc_id_name]
            init = re.search(r'INITIATING MESSAGE\s+([\w-]+)', body)
            success = re.search(r'SUCCESSFUL OUTCOME\s+([\w-]+)', body)
            fail = re.search(r'UNSUCCESSFUL OUTCOME\s+([\w-]+)', body)
            proc_mappings[val] = {
                'initiating': init.group(1) if init else None,
                'successful': success.group(1) if success else None,
                'unsuccessful': fail.group(1) if fail else None
            }
            
    return ie_mappings, proc_mappings

def gen_dispatch_code(ie_mappings, proc_mappings):
    code = []
    code.append("std::any decode_ProtocolIE_Value(int64_t id, BitReader& reader) {")
    code.append("    reader.alignToOctet();")
    code.append("    BitReader sub_reader = UperExtension::decodeOpenType(reader);")
    code.append("    switch(id) {")
    for id_val, type_name in sorted(ie_mappings.items()):
        cpp_type = type_name.replace('-', '_')
        code.append(f"        case {id_val}: return decode_{cpp_type}(sub_reader);")
    code.append("        default: return sub_reader.getBitString();")
    code.append("    }")
    code.append("}")
    code.append("")
    
    for outcome in ['InitiatingMessage', 'SuccessfulOutcome', 'UnsuccessfulOutcome']:
        key = outcome.lower().replace('message', '').replace('outcome', '')
        if key == 'initiating': key = 'initiating' # wait
        # map 'initiating' to 'initiating', 'successful' to 'successful', 'unsuccessful' to 'unsuccessful'
        
        code.append(f"std::any decode_{outcome}_Value(int64_t procCode, BitReader& reader) {{")
        code.append("    reader.alignToOctet();")
        code.append("    BitReader sub_reader = UperExtension::decodeOpenType(reader);")
        code.append("    switch(procCode) {")
        for proc_val, types in sorted(proc_mappings.items()):
            type_name = types.get(key)
            if type_name:
                cpp_type = type_name.replace('-', '_')
                code.append(f"        case {proc_val}: return decode_{cpp_type}(sub_reader);")
        code.append("        default: return sub_reader.getBitString();")
        code.append("    }")
        code.append("}")
        code.append("")

    return "\n".join(code)


def gen_json_dispatch_code(ie_mappings, proc_mappings):
    code = []
    
    # ProtocolIE_Field from_json
    code.append("inline void from_json(const nlohmann::json& j, ProtocolIE_Field& v) {")
    code.append("    if (j.contains(\"id\")) j.at(\"id\").get_to(v.id);")
    code.append("    if (j.contains(\"criticality\")) j.at(\"criticality\").get_to(v.criticality);")
    code.append("    if (j.contains(\"value\")) {")
    code.append("        const auto& jv = j.at(\"value\");")
    code.append("        switch(v.id) {")
    for id_val, type_name in sorted(ie_mappings.items()):
        cpp_type = type_name.replace('-', '_')
        # We need to find the namespace. This is hard in the script.
        # But for now, we'll use a hack or just raw types if namespaces are used.
        code.append(f"            case {id_val}: v.value = jv.get<E1AP_IEs::{cpp_type}>(); break;")
    code.append("            default: v.value = jv.get<asn1::runtime::BitString>(); break;")
    code.append("        }")
    code.append("    }")
    code.append("}")
    code.append("")

    # InitiatingMessage/SuccessfulOutcome/UnsuccessfulOutcome from_json
    for outcome in ['InitiatingMessage', 'SuccessfulOutcome', 'UnsuccessfulOutcome']:
        key = outcome.lower().replace('message', '').replace('outcome', '')
        ns = "E1AP_PDU_Contents"
        if outcome == "InitiatingMessage": ns = "E1AP_PDU_Descriptions" # Wait, no, they are all in Descriptions
        # Actually they are all in E1AP_PDU_Descriptions in generated.h
        
        code.append(f"inline void from_json(const nlohmann::json& j, {outcome}& v) {{")
        code.append("    if (j.contains(\"procedureCode\")) j.at(\"procedureCode\").get_to(v.procedureCode);")
        code.append("    if (j.contains(\"criticality\")) j.at(\"criticality\").get_to(v.criticality);")
        code.append("    if (j.contains(\"value\")) {")
        code.append("        const auto& jv = j.at(\"value\");")
        code.append("        switch(v.procedureCode) {")
        for proc_val, types in sorted(proc_mappings.items()):
            type_name = types.get(key)
            if type_name:
                cpp_type = type_name.replace('-', '_')
                code.append(f"            case {proc_val}: v.value = jv.get<E1AP_PDU_Contents::{cpp_type}>(); break;")
        code.append("            default: v.value = jv.get<asn1::runtime::BitString>(); break;")
        code.append("        }")
        code.append("    }")
        code.append("}")
        code.append("")

    return "\n".join(code)

if __name__ == "__main__":
    ie_map, proc_map = extract_mappings("repro_e1ap/input.asn1")
    print("// C++ Dispatchers")
    print(gen_dispatch_code(ie_map, proc_map))
    print("// JSON Dispatchers")
    print(gen_json_dispatch_code(ie_map, proc_map))
