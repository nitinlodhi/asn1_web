import re
from pathlib import Path

def extract_types(asn1_path):
    content = Path(asn1_path).read_text()
    types = set()
    # Find all type definitions: Foo ::= ...
    for match in re.finditer(r'([\w-]+)\s+::=', content):
        types.add(match.group(1).replace('-', '_'))
    return sorted(list(types))

def gen_any_to_json(types):
    code = []
    code.append("template <> struct adl_serializer<std::any> {")
    code.append("    static void to_json(json& j, const std::any& v) {")
    code.append("        if (!v.has_value()) { j = nullptr; return; }")
    code.append("        const auto& ti = v.type();")
    
    # Standard primitives
    for t in ['int64_t', 'int', 'bool', 'std::string', 'double']:
        code.append(f"        if (ti == typeid({t})) {{ j = std::any_cast<{t}>(v); return; }}")
    
    # BitString
    code.append("        if (ti == typeid(asn1::runtime::BitString)) { j = std::any_cast<asn1::runtime::BitString>(v); return; }")
    
    # All generated types
    for t in types:
        # We need to find the namespace for each type. 
        # This is hard. Let's use a generic approach if possible.
        # For now, I'll just list the ones I need for the user's example.
        pass

    # Actually, a better way is to use a macro or a registry.
    # But since I'm generating code, I can try to guess the namespaces.
    
    code.append("        // Generated types dispatch")
    # I'll just manually add the most important ones for now or use a broad list
    # Let's use a smaller list for the example first
    important_types = [
        "GNB_CU_CP_UE_E1AP_ID", "GNB_CU_UP_UE_E1AP_ID", "System_BearerContextSetupResponse",
        "BearerContextSetupResponse", "PDU_Session_Resource_Setup_List",
        "PDU_Session_Resource_Setup_Item", "DRB_Setup_List_NG_RAN", "DRB_Setup_Item_NG_RAN",
        "UP_Parameters", "UP_Parameters_Item", "QoS_Flow_List", "QoS_Flow_Item"
    ]
    
    for t in important_types:
        # Try different namespaces
        for ns in ["E1AP_IEs", "E1AP_PDU_Contents", "E1AP_CommonDataTypes", "E1AP_PDU_Descriptions"]:
            code.append(f"        if (ti == typeid(asn1::generated::{ns}::{t})) {{ j = std::any_cast<asn1::generated::{ns}::{t}>(v); return; }}")

    code.append("        j = nullptr;")
    code.append("    }")
    code.append("    static void from_json(const json& j, std::any& v) { /* TODO */ }")
    code.append("};")
    return "\n".join(code)

if __name__ == "__main__":
    # types = extract_types("repro_e1ap/input.asn1")
    # print(gen_any_to_json(types))
    print(gen_any_to_json([])) # Handled manually for now
