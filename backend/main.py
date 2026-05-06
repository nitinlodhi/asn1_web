import io
import os
import sys
import shutil
import subprocess
import tempfile
import zipfile
from pathlib import Path

# Ensure the backend/ directory is on sys.path so sibling modules are importable.
sys.path.insert(0, str(Path(__file__).parent))

from contextlib import asynccontextmanager

from fastapi import FastAPI, File, Form, HTTPException, UploadFile
from fastapi.middleware.cors import CORSMiddleware
from fastapi.responses import JSONResponse, StreamingResponse
from fastapi.staticfiles import StaticFiles
from pydantic import BaseModel

from harness_builder import (
    ASN1_COMPILER,
    compile_schema,
    build_harness,
    list_types,
    run_encode,
    run_decode,
    schema_hash,
    load_cached_session,
    save_session_to_cache,
    iter_cached_sessions,
)

FRONTEND = Path(__file__).resolve().parents[1] / "frontend" / "dist"

# In-memory session store: session_id → {workdir, harness_bin, types, is_cached}
_sessions: dict[str, dict] = {}


@asynccontextmanager
async def lifespan(app: FastAPI):
    for sid, entry in iter_cached_sessions():
        if sid not in _sessions:
            _sessions[sid] = {
                "workdir": None,
                "harness_bin": entry["harness_bin"],
                "types": entry["types"],
                "schema": entry.get("schema"),
                "is_cached": True,
            }
    yield


app = FastAPI(title="ASN.1 Compiler Service", lifespan=lifespan)

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_methods=["GET", "POST"],
    allow_headers=["*"],
)


def _cleanup_session(session_id: str) -> None:
    s = _sessions.pop(session_id, None)
    if s and not s.get("is_cached") and s.get("workdir"):
        shutil.rmtree(s["workdir"], ignore_errors=True)


# ── Health ────────────────────────────────────────────────────────────────────

@app.get("/api/health")
def health():
    return {
        "status": "ok",
        "compiler_found": ASN1_COMPILER.exists(),
        "compiler": str(ASN1_COMPILER),
    }


# ── Compile (Phase 1 — download generated code) ───────────────────────────────

@app.post("/api/compile")
async def compile_endpoint(
    file: UploadFile = File(...),
    lang: str = Form("cpp"),
    namespace: str = Form(""),
):
    if lang not in ("cpp", "c"):
        raise HTTPException(status_code=400, detail="lang must be 'cpp' or 'c'")

    if not ASN1_COMPILER.exists():
        raise HTTPException(
            status_code=503,
            detail=f"Compiler binary not found at {ASN1_COMPILER}. Run cmake --build.",
        )

    workdir = Path(tempfile.mkdtemp(prefix="asn1_"))
    try:
        input_path = workdir / "input.asn1"
        schema_bytes = await file.read()
        input_path.write_bytes(schema_bytes)

        out_prefix = workdir / "generated"
        cmd = [str(ASN1_COMPILER), str(input_path), "-o", str(out_prefix), "--lang", lang]
        if namespace and lang == "cpp":
            cmd += ["--namespace", namespace]

        try:
            proc = subprocess.run(cmd, capture_output=True, text=True, timeout=30)
        except subprocess.TimeoutExpired:
            return JSONResponse(status_code=408, content={"error": "Compilation timed out (30s limit)"})

        if proc.returncode != 0:
            return JSONResponse(
                status_code=422,
                content={"error": "Compilation failed", "details": (proc.stderr or proc.stdout).strip()},
            )

        source_ext = ".cpp" if lang == "cpp" else ".c"
        output_files = [p for s in (".h", source_ext) if (p := workdir / f"generated{s}").exists()]
        if not output_files:
            return JSONResponse(status_code=500, content={"error": "Compiler produced no output files"})

        buf = io.BytesIO()
        with zipfile.ZipFile(buf, "w", zipfile.ZIP_DEFLATED) as zf:
            for p in output_files:
                zf.write(p, p.name)
        buf.seek(0)

        stem = Path(file.filename or "schema").stem
        return StreamingResponse(
            buf,
            media_type="application/zip",
            headers={"Content-Disposition": f'attachment; filename="{stem}_generated.zip"'},
        )
    finally:
        shutil.rmtree(workdir, ignore_errors=True)


# ── Session compile (Phase 2 — build harness for encode/decode) ───────────────

@app.post("/api/session/compile")
async def session_compile(
    file: UploadFile = File(...),
    namespace: str = Form(""),
):
    """
    Compile schema + build encode/decode harness.
    Returns {session_id, types: [...]} on success.
    Harness compilation can take up to ~90 seconds for large schemas.
    """
    if not ASN1_COMPILER.exists():
        raise HTTPException(status_code=503, detail="Compiler binary not found.")

    schema_bytes = await file.read()
    sid = schema_hash(schema_bytes)

    # Return in-memory session if already built this run.
    if sid in _sessions:
        sess = _sessions[sid]
        return {"session_id": sid, "types": sess["types"], "schema": sess.get("schema")}

    # Check persistent disk cache before recompiling.
    cached = load_cached_session(sid)
    if cached:
        _sessions[sid] = {
            "workdir": None,
            "harness_bin": cached["harness_bin"],
            "types": cached["types"],
            "schema": cached.get("schema"),
            "is_cached": True,
        }
        return {"session_id": sid, "types": cached["types"], "schema": cached.get("schema")}

    workdir = Path(tempfile.mkdtemp(prefix="asn1_sess_"))
    try:
        input_path = workdir / "input.asn1"
        input_path.write_bytes(schema_bytes)

        result = compile_schema(workdir, input_path, lang="cpp", namespace=namespace)
        if "error" in result:
            shutil.rmtree(workdir, ignore_errors=True)
            return JSONResponse(status_code=422, content={"error": result["error"]})

        harness_result = build_harness(workdir)
        if "error" in harness_result:
            shutil.rmtree(workdir, ignore_errors=True)
            return JSONResponse(
                status_code=500,
                content={"error": "Harness build failed", "details": harness_result["error"]},
            )

        harness_bin = harness_result["binary"]
        types = list_types(harness_bin)

        # Load schema if the compiler emitted it.
        import json as _json_mod
        schema = None
        schema_path = workdir / "generated_schema.json"
        if schema_path.exists():
            try:
                schema = _json_mod.loads(schema_path.read_text())
            except Exception:
                pass

        save_session_to_cache(sid, harness_bin, types, schema)
        cached_entry = load_cached_session(sid)
        _sessions[sid] = {
            "workdir": workdir,
            "harness_bin": cached_entry["harness_bin"],
            "types": types,
            "schema": schema,
            "is_cached": True,
        }
        return {"session_id": sid, "types": types, "schema": schema}

    except Exception as e:
        shutil.rmtree(workdir, ignore_errors=True)
        raise HTTPException(status_code=500, detail=str(e))


# ── Encode ────────────────────────────────────────────────────────────────────

class EncodeRequest(BaseModel):
    session_id: str
    type_name: str
    json_data: str


@app.post("/api/encode")
def encode_endpoint(req: EncodeRequest):
    session = _sessions.get(req.session_id)
    if not session:
        raise HTTPException(status_code=404, detail="Session not found. Re-upload the schema.")

    harness_bin = Path(session["harness_bin"])
    if not harness_bin.exists():
        _cleanup_session(req.session_id)
        raise HTTPException(status_code=410, detail="Harness binary missing. Please re-upload schema.")

    try:
        result = run_encode(harness_bin, req.type_name, req.json_data)
    except Exception as e:
        return JSONResponse(status_code=500, content={"error": f"Encode runtime error: {str(e)}"})

    if "error" in result:
        return JSONResponse(status_code=422, content=result)
    return result


# ── Decode ────────────────────────────────────────────────────────────────────

class DecodeRequest(BaseModel):
    session_id: str
    type_name: str
    hex_data: str


@app.post("/api/decode")
def decode_endpoint(req: DecodeRequest):
    session = _sessions.get(req.session_id)
    if not session:
        raise HTTPException(status_code=404, detail="Session not found. Re-upload the schema.")

    harness_bin = Path(session["harness_bin"])
    if not harness_bin.exists():
        _cleanup_session(req.session_id)
        raise HTTPException(status_code=410, detail="Harness binary missing. Please re-upload schema.")

    try:
        result = run_decode(harness_bin, req.type_name, req.hex_data)
    except Exception as e:
        return JSONResponse(status_code=500, content={"error": f"Decode runtime error: {str(e)}"})

    if "error" in result:
        return JSONResponse(status_code=422, content=result)
    
    # Unwrap the result if it's the standard wrapper from run_decode
    if "result" in result and len(result) == 1:
        return result["result"]
        
    return result


# ── Static frontend ───────────────────────────────────────────────────────────

if FRONTEND.exists():
    app.mount("/", StaticFiles(directory=str(FRONTEND), html=True), name="static")
else:
    print(f"WARNING: Frontend distribution directory not found at {FRONTEND}")
    print("Static files will not be served.")
