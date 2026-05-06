export const api = {
  async getHealth() {
    return (await fetch(`/api/health`)).json();
  },
  async compile(file: File, lang: string, namespace?: string) {
    let formData = new FormData();
    formData.append(`file`, file);
    formData.append(`lang`, lang);
    if (namespace) formData.append(`namespace`, namespace);

    const response = await fetch(`/api/compile`, {
      method: `POST`,
      body: formData,
    });
    
    if (response.ok) return response.blob();
    return response.json();
  },
  async sessionCompile(file: File) {
    let formData = new FormData();
    formData.append(`file`, file);

    const response = await fetch(`/api/session/compile`, {
      method: `POST`,
      body: formData,
    });
    
    const text = await response.text();
    try {
      return JSON.parse(text);
    } catch (e) {
      return { error: `Server error during compilation: ${text.slice(0, 100)}...` };
    }
  },
  async encode(sessionId: string, typeName: string, jsonData: string) {
    const response = await fetch(`/api/encode`, {
      method: `POST`,
      headers: { "Content-Type": `application/json` },
      body: JSON.stringify({ session_id: sessionId, type_name: typeName, json_data: jsonData }),
    });
    
    const text = await response.text();
    try {
      return JSON.parse(text);
    } catch (e) {
      return { error: `Server error during encoding: ${text.slice(0, 100)}...` };
    }
  },
  async decode(sessionId: string, typeName: string, hexData: string) {
    const response = await fetch(`/api/decode`, {
      method: `POST`,
      headers: { "Content-Type": `application/json` },
      body: JSON.stringify({ session_id: sessionId, type_name: typeName, hex_data: hexData }),
    });
    
    const text = await response.text();
    try {
      return JSON.parse(text);
    } catch (e) {
      return { error: `Server error during decoding: ${text.slice(0, 100)}...` };
    }
  },
};
