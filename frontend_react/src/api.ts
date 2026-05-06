export const api = {
  async getHealth() {
    return (await fetch(`/api/health`)).json();
  },
  async compile(file: File, lang: string, namespace?: string) {
    let formData = new FormData();
    formData.append(`file`, file);
    formData.append(`lang`, lang);
    if (namespace) formData.append(`namespace`, namespace);
    let response = await fetch(`/api/compile`, { method: `POST`, body: formData });
    return response.ok ? response.blob() : response.json();
  },
  async sessionCompile(file: File, namespace?: string) {
    let formData = new FormData();
    formData.append(`file`, file);
    if (namespace) formData.append(`namespace`, namespace);
    return (await fetch(`/api/session/compile`, { method: `POST`, body: formData })).json();
  },
  async encode(sessionId: string, typeName: string, jsonData: string) {
    return (await fetch(`/api/encode`, {
      method: `POST`,
      headers: { "Content-Type": `application/json` },
      body: JSON.stringify({ session_id: sessionId, type_name: typeName, json_data: jsonData }),
    })).json();
  },
  async decode(sessionId: string, typeName: string, hexData: string) {
    return (await fetch(`/api/decode`, {
      method: `POST`,
      headers: { "Content-Type": `application/json` },
      body: JSON.stringify({ session_id: sessionId, type_name: typeName, hex_data: hexData }),
    })).json();
  },
};
