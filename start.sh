#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"

COMPILER="${ASN1_COMPILER:-$(pwd)/../asn_compiler/build/bin/asn1_compiler}"
PORT="${PORT:-8080}"

if [ ! -f "$COMPILER" ]; then
  echo "ERROR: Compiler binary not found at: $COMPILER"
  echo "Build it first:"
  echo "  cd ../asn_compiler && cmake --build build"
  exit 1
fi

# Kill any processes already bound to the port
OLD_PIDS=$(lsof -ti tcp:$PORT 2>/dev/null) || true
if [ -n "$OLD_PIDS" ]; then
  echo "Killing existing processes on port $PORT (PIDs: $(echo $OLD_PIDS | tr '\n' ' '))..."
  echo "$OLD_PIDS" | xargs kill 2>/dev/null || true
  sleep 1
fi

# Clean harness cache
CACHE_DIR="$HOME/.asn1_web/cache"
if [ -d "$CACHE_DIR" ]; then
  echo "Cleaning cache: $CACHE_DIR"
  rm -rf "$CACHE_DIR"
fi

if [ ! -d ".venv" ]; then
  echo "Creating virtual environment..."
  python3 -m venv .venv
fi

source .venv/bin/activate
pip install -q -r backend/requirements.txt

# Frontend setup
if [ ! -d "frontend/node_modules" ]; then
  echo "Installing frontend dependencies..."
  (cd frontend && npm install)
fi

# Download nlohmann/json single-header if not present
if [ ! -f "vendor/nlohmann/json.hpp" ]; then
  echo "Downloading nlohmann/json..."
  mkdir -p vendor/nlohmann
  curl -fsSL -o vendor/nlohmann/json.hpp \
    "https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp"
fi

echo "Compiler : $COMPILER"
echo "Backend  : http://localhost:$PORT"
echo "Frontend : http://localhost:5173 (Dev Mode)"
echo ""

# Function to kill background processes on exit
cleanup() {
  echo "Shutting down..."
  kill $(jobs -p) 2>/dev/null || true
  exit
}
trap cleanup SIGINT SIGTERM

# Start backend
uvicorn backend.main:app --host 0.0.0.0 --port "$PORT" --reload &

# Start frontend dev server
(cd frontend && npm run dev) &

# Wait for all background processes
wait
