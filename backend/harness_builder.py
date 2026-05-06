"""
Builds a harness executable from a compiled ASN.1 schema.

Given a workdir containing:
  generated.h, generated.cpp, generated_json.hpp

Compiles them together with harness_main.cpp into a binary that can
encode/decode any registered type.

Compiled harnesses are cached on disk at ~/.asn1_web/cache/<hash>/ so they
survive server restarts without recompilation.
"""
import json as _json
import os
import subprocess
import hashlib
from pathlib import Path

CACHE_DIR = Path.home() / ".asn1_web" / "cache"

COMPILER_DIR = Path(__file__).resolve().parents[2] / "asn_compiler"
BACKEND_DIR  = Path(__file__).resolve().parent
VENDOR_DIR   = Path(__file__).resolve().parents[1] / "vendor"

ASN1_COMPILER  = COMPILER_DIR / "build" / "bin" / "asn1_compiler"
RUNTIME_LIB    = COMPILER_DIR / "build" / "lib" / "libasn1_runtime.a"
INCLUDE_DIR    = COMPILER_DIR / "include"
HARNESS_MAIN   = BACKEND_DIR / "harness_main.cpp"
NLOHMANN_DIR   = VENDOR_DIR / "nlohmann"


def schema_hash(schema_bytes: bytes) -> str:
    return hashlib.sha256(schema_bytes).hexdigest()[:16]


# ── Disk cache helpers ────────────────────────────────────────────────────────

def _cache_slot(sid: str) -> Path:
    return CACHE_DIR / sid


def load_cached_session(sid: str) -> dict | None:
    """Return {harness_bin, types, schema} if a valid cached harness exists, else None.

    Treats missing schema.json as a cache miss so stale pre-schema entries are
    automatically recompiled rather than silently returning schema=None.
    """
    slot = _cache_slot(sid)
    harness_bin  = slot / "harness"
    types_file   = slot / "types.json"
    schema_file  = slot / "schema.json"
    if (harness_bin.exists() and harness_bin.stat().st_size > 0
            and types_file.exists() and schema_file.exists()):
        try:
            types  = _json.loads(types_file.read_text())
            schema = _json.loads(schema_file.read_text())
            return {"harness_bin": harness_bin, "types": types, "schema": schema}
        except Exception:
            pass
    return None


def save_session_to_cache(sid: str, harness_bin: Path, types: list[str],
                          schema: dict | None = None) -> None:
    """Copy the harness binary + types list + schema into the persistent cache slot."""
    import shutil
    slot = _cache_slot(sid)
    slot.mkdir(parents=True, exist_ok=True)
    dest = slot / "harness"
    shutil.copy2(harness_bin, dest)
    dest.chmod(0o755)
    (slot / "types.json").write_text(_json.dumps(types))
    if schema is not None:
        (slot / "schema.json").write_text(_json.dumps(schema))


def iter_cached_sessions() -> list[tuple[str, dict]]:
    """Yield (session_id, {harness_bin, types}) for every valid cache slot."""
    if not CACHE_DIR.exists():
        return []
    results = []
    for slot in CACHE_DIR.iterdir():
        if slot.is_dir():
            entry = load_cached_session(slot.name)
            if entry:
                results.append((slot.name, entry))
    return results


def compile_schema(workdir: Path, schema_path: Path, lang: str = "cpp",
                   namespace: str = "", encoding: str = "uper") -> dict:
    """
    Run asn1_compiler on the schema.  Returns {"ok": True} or {"error": "..."}.
    Writes generated.h, generated.cpp, generated_json.hpp, generated_schema.json.
    """
    out_prefix = workdir / "generated"
    cmd = [str(ASN1_COMPILER), str(schema_path),
           "-o", str(out_prefix), "--lang", lang, "--json", "--schema",
           "--encoding", encoding]
    if namespace and lang == "cpp":
        cmd += ["--namespace", namespace]

    r = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
    if r.returncode != 0:
        return {"error": (r.stderr or r.stdout).strip()}
    return {"ok": True, "stdout": (r.stdout or "").strip()}


def build_harness(workdir: Path) -> dict:
    """
    Compile generated.cpp + harness_main.cpp → workdir/harness binary.
    Returns {"ok": True, "binary": Path} or {"error": "..."}.
    """
    if not RUNTIME_LIB.exists():
        return {"error": f"Runtime library not found at {RUNTIME_LIB}"}
    if not NLOHMANN_DIR.exists():
        return {"error": f"nlohmann/json not found at {NLOHMANN_DIR}"}
    if not HARNESS_MAIN.exists():
        return {"error": f"harness_main.cpp not found at {HARNESS_MAIN}"}

    generated_cpp = workdir / "generated.cpp"
    harness_bin   = workdir / "harness"

    if not generated_cpp.exists():
        return {"error": "generated.cpp not found in workdir"}

    cmd = [
        "g++", "-std=c++20", "-O0",
        f"-I{workdir}",          # generated.h, generated_json.hpp
        f"-I{INCLUDE_DIR}",      # runtime/core/*, runtime/uper/*
        f"-I{VENDOR_DIR}",       # nlohmann/json.hpp
        "-o", str(harness_bin),
        str(HARNESS_MAIN),
        str(generated_cpp),
        str(RUNTIME_LIB),
        "-lpthread",
    ]

    r = subprocess.run(cmd, capture_output=True, text=True, timeout=600)
    if r.returncode != 0:
        return {"error": (r.stderr or r.stdout).strip()}

    return {"ok": True, "binary": harness_bin}


def list_types(harness_bin: Path) -> list[str]:
    r = subprocess.run([str(harness_bin), "list"],
                       capture_output=True, text=True, timeout=10)
    if r.returncode != 0:
        return []
    import json
    try:
        return sorted(json.loads(r.stdout.strip()))
    except Exception:
        return []


def run_encode(harness_bin: Path, type_name: str, json_data: str) -> dict:
    r = subprocess.run([str(harness_bin), "encode", type_name],
                       input=json_data, capture_output=True, text=True, timeout=10)
    if r.returncode != 0:
        import json as _json
        try:
            err = _json.loads(r.stderr.strip()).get("error", r.stderr.strip())
        except Exception:
            err = r.stderr.strip() or "encode failed"
        return {"error": err}
    return {"hex": r.stdout.strip()}


def run_decode(harness_bin: Path, type_name: str, hex_data: str) -> dict:
    r = subprocess.run([str(harness_bin), "decode", type_name],
                       input=hex_data, capture_output=True, text=True, timeout=10)
    if r.returncode != 0:
        import json as _json
        try:
            err = _json.loads(r.stderr.strip()).get("error", r.stderr.strip())
        except Exception:
            err = r.stderr.strip() or "decode failed"
        return {"error": err}
    import json as _json
    try:
        return {"result": _json.loads(r.stdout.strip())}
    except Exception:
        return {"result": r.stdout.strip()}
