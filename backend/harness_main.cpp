// Fixed harness entry point — compiled together with generated.cpp and generated_json.hpp.
// Usage:
//   harness list                     → prints JSON array of registered type keys
//   harness encode <ModuleNs::Type>  → reads JSON from stdin, writes hex to stdout
//   harness decode <ModuleNs::Type>  → reads hex from stdin, writes JSON to stdout

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <iomanip>
#include <stdexcept>

#include "generated.h"
#include "generated_json.hpp"
#include "runtime/core/BitWriter.h"
#include "runtime/core/BitReader.h"

using json = nlohmann::json;
using namespace asn1::runtime;

static std::unordered_map<std::string, std::function<void(const json&, BitWriter&)>> g_encoders;
static std::unordered_map<std::string, std::function<json(BitReader&)>>              g_decoders;

static std::string toHex(const uint8_t* data, size_t len) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (size_t i = 0; i < len; ++i)
        oss << std::setw(2) << static_cast<int>(data[i]);
    return oss.str();
}

static std::vector<uint8_t> fromHex(const std::string& hex) {
    std::vector<uint8_t> bytes;
    for (size_t i = 0; i + 1 < hex.size(); i += 2)
        bytes.push_back(static_cast<uint8_t>(std::stoul(hex.substr(i, 2), nullptr, 16)));
    return bytes;
}

int main(int argc, char** argv) {
    registerTypes(g_encoders, g_decoders);

    if (argc < 2) {
        std::cerr << "{\"error\":\"Usage: harness list|encode|decode [TypeName]\"}\n";
        return 1;
    }

    std::string mode = argv[1];

    try {
        if (mode == "list") {
            json types = json::array();
            for (const auto& [k, _] : g_encoders) types.push_back(k);
            std::cout << types.dump() << "\n";
            return 0;
        }

        if (argc < 3) {
            std::cerr << "{\"error\":\"TypeName required for encode/decode\"}\n";
            return 1;
        }
        std::string type_name = argv[2];

        if (mode == "encode") {
            auto it = g_encoders.find(type_name);
            if (it == g_encoders.end()) {
                std::cerr << "{\"error\":\"Unknown type: " << type_name << "\"}\n";
                return 2;
            }
            std::string input((std::istreambuf_iterator<char>(std::cin)),
                               std::istreambuf_iterator<char>());
            json j = json::parse(input);
            BitWriter bw;
            it->second(j, bw);
            std::cout << toHex(bw.getBuffer(), bw.getBufferSize()) << "\n";
            return 0;
        }

        if (mode == "decode") {
            auto it = g_decoders.find(type_name);
            if (it == g_decoders.end()) {
                std::cerr << "{\"error\":\"Unknown type: " << type_name << "\"}\n";
                return 2;
            }
            std::string hex_str;
            std::cin >> hex_str;
            auto bytes = fromHex(hex_str);
            BitReader br(bytes.data(), bytes.size());
            json result = it->second(br);
            std::cout << result.dump(2) << "\n";
            return 0;
        }

        std::cerr << "{\"error\":\"Unknown mode: " << mode << "\"}\n";
        return 1;

    } catch (const std::exception& e) {
        std::cerr << "{\"error\":" << json(e.what()).dump() << "}\n";
        return 1;
    }
}
