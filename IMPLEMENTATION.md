# ASN.1 Web Service — Implementation Notes

## Overview

A web service wrapping the `asn_compiler` CLI. Users upload `.asn1` files, receive generated C++/C code as a ZIP (Phase 1), and can interactively encode/decode data using the generated codecs (Phase 2). Compiled harnesses survive server restarts via a persistent disk cache (Phase 3).

**Directory layout:**
```
asn1_web/           ← this repo
  backend/
    main.py             FastAPI application
    harness_builder.py  Build orchestration + cache helpers
    harness_main.cpp    Harness entry point (compiled per schema)
    requirements.txt
  frontend/
    src/                Vue 3 + TypeScript components
    dist/               Production build (served by FastAPI)
    package.json        Vite configuration
  vendor/
    nlohmann/json.hpp   v3.11.3 single-header (downloaded by start.sh)
  start.sh

asn_compiler/       ← sibling directory (separate repo)
  build/bin/asn1_compiler
  build/lib/libasn1_runtime.a
  include/
  src/codegen/cpp/JsonEmitter.cpp   ← added for this project
```

---

## Phases

### Phase 1 — Compile & Download

`POST /api/compile` accepts an `.asn1` file + `lang` (`cpp`/`c`) + optional `namespace`, runs `asn1_compiler`, and streams a ZIP of `generated.h` + `generated.cpp` (or `.c`) back to the browser.

### Phase 2 — Encode / Decode Harness

`POST /api/session/compile` compiles the schema **with `--json`** and then builds a standalone binary (`harness`) by linking `harness_main.cpp` + `generated.cpp` + `libasn1_runtime.a`. The session is keyed by a 16-character SHA-256 prefix of the raw schema bytes.

The harness accepts three subcommands:
- `harness list` → JSON array of registered type names
- `harness encode <TypeName>` → reads JSON from stdin, writes UPER hex to stdout
- `harness decode <TypeName>` → reads hex from stdin, writes pretty-printed JSON to stdout

`POST /api/encode` and `POST /api/decode` proxy stdin/stdout through the harness.

### Phase 3 — Persistent Disk Cache

Compiled harnesses are persisted at `~/.asn1_web/cache/<session_id>/`:
```
~/.asn1_web/cache/
  <sha256_prefix>/
    harness       ← executable (chmod 755)
    types.json    ← JSON array of type names
```

On startup (`lifespan`) all valid cache slots are loaded into the in-memory `_sessions` dict. On a cache hit the harness is served immediately without recompilation. Cached sessions are never deleted by `_cleanup_session` (only ephemeral temp dirs are removed).

### Phase 4 — Modern UI Rewrite (Vue 3 + Tailwind)

The frontend has been rewritten using a modern stack:
- **Framework:** Vue 3 (Composition API)
- **State:** Pinia
- **Styling:** Tailwind CSS v4 (Wireshark-inspired theme)
- **Icons:** Lucide Vue
- **Build Tool:** Vite

**Key UI Components:**
- **Type Browser:** Sidebar for selecting ASN.1 types from the compiled harness.
- **Structure Filler:** Dynamic form engine that generates input fields based on JSON schema.
- **Decoder Tree:** Hierarchical "Wireshark-style" tree view with zebra stripes and expand/collapse support.
- **Hex Grid:** Advanced hex viewer with Offsets, Hex pairs, and ASCII translation.

---

## Compiler Addition: `JsonEmitter`

The `--json` flag on `asn1_compiler` triggers a new `JsonEmitter` pass that writes `<output>_json.hpp` alongside the normal `.h`/`.cpp` files.

**New files in `asn_compiler`:**
- `include/codegen/cpp/JsonEmitter.h`
- `src/codegen/cpp/JsonEmitter.cpp`
- Added `JsonEmitter.cpp` to `src/codegen/cpp/CMakeLists.txt`

The emitter walks the AST and generates nlohmann/json adapters:

| ASN.1 type | Generated adapter |
|---|---|
| ENUMERATION | `NLOHMANN_JSON_SERIALIZE_ENUM` macro |
| SEQUENCE / SET | `to_json` / `from_json` with field-by-field mapping |
| CHOICE | `to_json` via `std::visit`, `from_json` via type-string dispatch |
| BIT STRING | `{"hex": "...", "bit_length": N}` (custom runtime adapter) |
| OCTET STRING | JSON array of byte values (nlohmann default for `vector<uint8_t>`) |
| `ExtensionValue` | `{"__extension": true}` (custom runtime adapter) |

Inline types (enums / CHOICEs defined inside a SEQUENCE field) are emitted inside the enclosing struct's scope as `fieldName_type` and require a pre-pass in `emitStructAdapterImpl` so their adapters appear before the parent struct's adapter.

The emitter also generates a single `inline void registerTypes(encoders, decoders)` function at global scope. `harness_main.cpp` calls this on startup to populate two maps keyed by `"ModuleNamespace::TypeName"`.

---

## Key Files

| File | Purpose |
|---|---|
| `backend/main.py` | FastAPI routes; mounts `frontend/dist` if present |
| `frontend/src/store/asn.ts` | Centralized Pinia store for ASN session, encoding, and decoding |
| `frontend/src/components/layout/editors/AsnField.vue` | Recursive dispatcher for dynamic form generation |
| `frontend/src/components/layout/HexGrid.vue` | Wireshark-like hex grid implementation |
| `start.sh` | Launches both Backend (8080) and Frontend Dev Server (5173) |
| `vendor/nlohmann/json.hpp` | JSON library used by harness and generated adapters |

---

## Build Requirements

- `g++` with C++20 support
- `asn_compiler` built at `../asn_compiler/build/bin/asn1_compiler`
- `libasn1_runtime.a` at `../asn_compiler/build/lib/libasn1_runtime.a`
- Python 3.10+ (uses `dict | None` and `match`-era type hints)

The harness is compiled with:
```
g++ -std=c++20 -O1 \
    -I<workdir>        \  # generated.h, generated_json.hpp
    -I<include_dir>    \  # runtime/core/*, runtime/uper/*
    -I<vendor_dir>     \  # nlohmann/json.hpp
    -o harness \
    harness_main.cpp generated.cpp libasn1_runtime.a -lpthread
```

---

## Known Limitations

- Session cache is never evicted — the `~/.asn1_web/cache/` directory grows unbounded. Add a TTL or LRU eviction policy if disk space becomes a concern.
- The `--json` flag only targets the C++ backend. The C backend has no JSON adapter generation.
- Inline SEQUENCE-OF types are not deeply introspected by the JSON emitter; they rely on nlohmann's default `std::vector` handling.
- Some schemas with repeated local variable names (e.g., multiple `size_t length` declarations in the same codec function) cause harness build failures. This is a pre-existing `CodecEmitter` limitation, not specific to the web service.
