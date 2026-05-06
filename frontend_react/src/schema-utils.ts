export function processSchema(schema: any) {
  let typesList = Array.isArray(schema) ? schema : schema?.types;
  if (!Array.isArray(typesList)) return null;
  let indexed: Record<string, any> = {};
  typesList.forEach((type: any) => {
    let processed = {
      ...type,
      kind: (type.kind || ``).toLowerCase(),
      element_kind: (type.element_kind || ``).toLowerCase(),
      fields: (type.fields || []).map((f: any) => ({
        ...f,
        kind: (f.kind || ``).toLowerCase(),
        element_kind: (f.element_kind || ``).toLowerCase(),
      })),
    };
    if (type.key) indexed[type.key] = processed;
    if (type.name) indexed[type.name] = processed;
  });
  return indexed;
}

export function lookupType(name: string, indexedSchema: Record<string, any>) {
  if (!name || !indexedSchema) return null;
  if (indexedSchema[name]) return indexedSchema[name];
  let normalized = name.replace(/-/g, `_`);
  if (indexedSchema[normalized]) return indexedSchema[normalized];
  let doubleColon = name.indexOf(`::`);
  if (doubleColon !== -1) {
    let shortName = name.slice(doubleColon + 2);
    if (indexedSchema[shortName]) return indexedSchema[shortName];
    let shortNormalized = shortName.replace(/-/g, `_`);
    if (indexedSchema[shortNormalized]) return indexedSchema[shortNormalized];
  }
  return null;
}

export function isComplexType(kind: string) {
  return ![
    `integer`,
    `boolean`,
    `string`,
    `octet_string`,
    `bit_string`,
    `null`,
    `real`,
    `oid`,
  ].includes(kind);
}

export function getFieldKey(field: any) {
  return field.json_key || field.name;
}
