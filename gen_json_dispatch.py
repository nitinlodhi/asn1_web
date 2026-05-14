import re
from pathlib import Path

def extract_types(header_path):
    content = Path(header_path).read_text()
    types = []
    # Match namespaces and structs/using within them
    current_ns = None
    for line in content.splitlines():
        ns_match = re.match(r'namespace ([\w_]+) \{', line)
        if ns_match:
            current_ns = ns_match.group(1)
        elif line.startswith('} // namespace'):
            current_ns = None
        elif current_ns:
            struct_match = re.match(r'struct ([\w_]+) \{', line)
            using_match = re.match(r'using ([\w_]+) = ', line)
            if struct_match:
                types.append((current_ns, struct_match.group(1)))
            elif using_match:
                # Avoid simple aliases like int64_t
                if 'variant' in line or 'vector' in line:
                    types.append((current_ns, using_match.group(1)))
    return types

def gen_json_dispatch(types):
    code = []
    code.append("namespace nlohmann {")
    code.append("template <> struct adl_serializer<std::any> {")
    code.append("    static void to_json(json& j, const std::any& v) {")
    code.append("        if (!v.has_value()) { j = nullptr; return; }")
    code.append("        const auto& ti = v.type();")
    
    # Primitives
    for t in ['int64_t', 'int', 'bool', 'std::string', 'double']:
        code.append(f"        if (ti == typeid({t})) {{ j = std::any_cast<{t}>(v); return; }}")
    code.append("        if (ti == typeid(asn1::runtime::BitString)) { j = std::any_cast<asn1::runtime::BitString>(v); return; }")

    # Generated types
    for ns, t in types:
        full_name = f"asn1::generated::{ns}::{t}"
        # Skip some types that might cause issues or are redundant
        if t in ["PrivateIE_ID_local", "PrivateIE_ID_global"]: continue
        code.append(f"        if (ti == typeid({full_name})) {{ j = std::any_cast<{full_name}>(v); return; }}")

    code.append("        j = nullptr;")
    code.append("    }")
    code.append("    static void from_json(const json& j, std::any& v) {")
    # from_json is harder because we don't know the type from JSON alone
    # unless we have a hint. But for now we don't strictly need it for the round-trip
    # if the harness handles the top-level type.
    code.append("        // Default fallback to BitString for now")
    code.append("        if (j.is_object() && j.contains(\"hex\") && j.contains(\"bit_length\")) {")
    code.append("            asn1::runtime::BitString bs;")
    code.append("            bs.bit_length = j.at(\"bit_length\").get<size_t>();")
    code.append("            std::string hex = j.at(\"hex\").get<std::string>();")
    code.append("            for (size_t i = 0; i + 1 < hex.size(); i += 2)")
    code.append("                bs.data.push_back(static_cast<uint8_t>(std::stoul(hex.substr(i, 2), nullptr, 16)));")
    code.append("            v = std::move(bs);")
    code.append("        }")
    code.append("    }")
    code.append("};")
    code.append("} // namespace nlohmann")
    return "\n".join(code)

if __name__ == "__main__":
    types = extract_types("repro_e1ap/generated.h")
    print(gen_json_dispatch(types))
