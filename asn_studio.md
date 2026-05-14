# ASN.1 Studio: Compiler and Desktop GUI Plan (C++14, OOP, Cross-Platform / Windows MSVC)

## Objective
Create a brand new ASN.1 development suite located in the `../projects/asn_studio` directory. This suite will be designed to support both Windows (MSVC) and Linux natively.

The suite consists of two primary projects:
1. **`asn_compiler`**: A cross-platform C++14 compiler (built without template metaprogramming) that translates `.asn1` schemas into OOP-based C++ source code. Via compile-time switches, it can be built for Linux or Windows. On Windows, it generates code that compiles into a **Windows DLL (`.dll`)**, and on Linux into a shared object (`.so`).
2. **`asn_gui`**: A Desktop GUI application (similar to Wireshark) designed primarily for local testing. It dynamically loads the generated DLLs/SOs at runtime, allowing users to interactively encode, decode, and visualize ASN.1 payloads.

## System Architecture

### Project 1: `asn_compiler` (The Generator & Builder)
*   **Language:** C++14 (Strictly OOP, no SFINAE or complex template metaprogramming).
*   **Build System:** CMake. This ensures cross-platform compatibility (Generating Visual Studio `.sln` on Windows, and Makefiles/Ninja on Linux).
*   **Cross-Platform Portability:** The compiler source will use `#ifdef _WIN32` and `#ifdef __linux__` where platform-specific behavior is required (e.g., invoking the local build toolchain).
*   **Output:** The compiler reads `.asn1` and generates:
    1. `generated.h` / `generated.cpp` (The OOP codecs).
    2. A `CMakeLists.txt` configured to build a shared library (`.dll` or `.so`).
*   **Dynamic Library Generation:** After generating the C++ files, the compiler orchestrates the local toolchain (MSVC on Windows, GCC/Clang on Linux) via CMake to compile the generated code and the `libasn1_runtime` into a stand-alone shared library.

### Project 2: `asn_gui` (The Wireshark-like Desktop App)
*   **Framework:** Qt (C++) or Dear ImGui (Provides the best ecosystem for a Wireshark-like hex-grid and tree-view UI).
*   **Dynamic Loading:** The GUI will use OS-specific APIs (`LoadLibrary`/`GetProcAddress` on Windows, `dlopen`/`dlsym` on Linux) to dynamically load the generated schema library.
*   **Features:**
    *   **Schema Manager:** Load `.asn1` files and trigger the compiler.
    *   **Hex Editor:** A Wireshark-style hex grid for raw payload manipulation.
    *   **Decoder Tree:** A hierarchical tree view showing the decoded ASN.1 fields, populated by querying the loaded library.

---

## Compiler Design: OOP vs. Table-Driven

The generated code inside the shared library will use an **Object-Oriented Programming (OOP)** paradigm rather than the traditional Table-Driven approach.

### The Generated Code (OOP Paradigm)
Every complex type becomes a C++ class extending `AsnObject`. All logic is explicitly written in virtual methods. To support dynamic linking, classes will use export macros (`ASN_EXPORT`).

```cpp
// Cross-platform export macro
#if defined(_WIN32)
  #ifdef BUILD_ASN_LIB
    #define ASN_EXPORT __declspec(dllexport)
  #else
    #define ASN_EXPORT __declspec(dllimport)
  #endif
#else
  #define ASN_EXPORT __attribute__((visibility("default")))
#endif

class ASN_EXPORT MySequence : public asn1::runtime::AsnObject {
public:
    asn1::runtime::AsnInteger id{0, 255}; 
    asn1::runtime::AsnBoolean active;

    void encode(asn1::runtime::BitWriter& writer) const override {
        id.encode(writer);
        active.encode(writer);
    }

    void decode(asn1::runtime::BitReader& reader) override {
        id.decode(reader);
        active.decode(reader);
    }
};
```

### Alternatives Considered: The Table-Driven Paradigm
In a **Table-Driven** approach, the compiler generates plain C-style structs and a static array of metadata. A generic runtime engine loops over this table using pointer arithmetic.
**Why we chose OOP:** OOP provides stronger type safety, avoids `void*` pointer arithmetic bugs (`offsetof`), and makes debugging significantly easier (e.g., setting a breakpoint in `MySequence::decode()`).

---

## Implementation Phases (For Future Execution)

*Note: The user has requested this plan solely for documentation at this time. No immediate implementation will occur.*

### Phase 1: Workspace Setup & Cross-Platform Integration
1. Create the new directory structure in `../projects/asn_studio`.
2. Setup the root `CMakeLists.txt` to support both Windows MSVC and Linux GCC/Clang.
3. Create the `libasn1_runtime` ensuring all base classes are exportable.

### Phase 2: Compiler Core (No Metaprogramming)
1. Write the lexer/parser (Flex/Bison) to generate the C++14 OOP AST.
2. Implement the `CppEmitter` to generate the `.h`/`.cpp` files with explicit `encode`/`decode` methods and cross-platform export macros.

### Phase 3: Dynamic Library Orchestration Pipeline
1. Modify the `asn_compiler` executable to generate code and invoke `cmake` + local build system (`msbuild` or `make`) to compile the resulting `.dll`/`.so`.
2. Generate an exported factory function in the library (`extern "C" ASN_EXPORT AsnObject* create_instance(const char* type_name);`).

### Phase 4: Desktop GUI (Wireshark Clone)
1. Initialize the Qt/ImGui desktop application.
2. Build the UI layout: Workspace pane, Hex Grid (bottom), Decoder Tree (top right).
3. Implement the OS-aware dynamic library loader.

### Phase 5: Testing & Validation
1. Compile schemas through the new pipeline on both Linux and Windows.
2. Validate decoding accuracy against known hex payloads.