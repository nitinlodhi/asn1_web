# --- Stage 1: Build Frontend ---
FROM node:20-slim AS frontend-builder
WORKDIR /app/asn1_web/frontend
COPY asn1_web/frontend/package*.json ./
RUN npm install
COPY asn1_web/frontend/ ./
RUN npm run build

# --- Stage 2: Build ASN1 Compiler ---
FROM gcc:13 AS compiler-builder
RUN apt-get update && apt-get install -y cmake
WORKDIR /app/asn_compiler
COPY asn_compiler/ ./
RUN mkdir build && cd build && cmake .. && make -j$(nproc)

# --- Stage 3: Final Runtime Image ---
FROM python:3.11-slim
# Install build tools (needed by backend to build harnesses at runtime)
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    make \
    curl \
    lsof \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy built compiler and runtime library
COPY --from=compiler-builder /app/asn_compiler/build/bin/asn1_compiler /app/asn_compiler/build/bin/asn1_compiler
COPY --from=compiler-builder /app/asn_compiler/build/lib/libasn1_runtime.a /app/asn_compiler/build/lib/libasn1_runtime.a
COPY --from=compiler-builder /app/asn_compiler/include /app/asn_compiler/include

# Copy frontend distribution
COPY --from=frontend-builder /app/asn1_web/frontend/dist /app/asn1_web/frontend/dist

# Copy backend and vendor files
COPY asn1_web/backend /app/asn1_web/backend
COPY asn1_web/vendor /app/asn1_web/vendor

# Install Python dependencies
COPY asn1_web/backend/requirements.txt /app/asn1_web/backend/requirements.txt
RUN pip install --no-cache-dir -r /app/asn1_web/backend/requirements.txt

# Ensure nlohmann/json single-header is present
RUN mkdir -p /app/asn1_web/vendor/nlohmann && \
    curl -fsSL -o /app/asn1_web/vendor/nlohmann/json.hpp \
    "https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp"

# Set environment variables
ENV PORT=8080
ENV PYTHONPATH=/app/asn1_web

# Create cache directory and set permissions
RUN mkdir -p /root/.asn1_web/cache

WORKDIR /app/asn1_web
EXPOSE 8080

CMD ["uvicorn", "backend.main:app", "--host", "0.0.0.0", "--port", "8080"]
