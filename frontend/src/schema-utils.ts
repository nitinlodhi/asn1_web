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
    if (type.key) {
      indexed[type.key] = processed;
      indexed[type.key.replace(/-/g, '_')] = processed;
      indexed[type.key.replace(/_/g, '-')] = processed;
    }
    if (type.name) {
      indexed[type.name] = processed;
      indexed[type.name.replace(/-/g, '_')] = processed;
      indexed[type.name.replace(/_/g, '-')] = processed;
    }
  });
  return indexed;
}

export function lookupType(name: string, indexedSchema: Record<string, any>) {
  if (!name || !indexedSchema) return null;
  if (indexedSchema[name]) return indexedSchema[name];
  
  // Try all combinations of - and _
  const variations = [
    name.replace(/-/g, '_'),
    name.replace(/_/g, '-'),
    name.replace(/-/g, '_').toLowerCase(),
    name.replace(/_/g, '-').toLowerCase()
  ];
  
  for (const v of variations) {
    if (indexedSchema[v]) return indexedSchema[v];
  }

  let doubleColon = name.indexOf(`::`);
  if (doubleColon !== -1) {
    let shortName = name.slice(doubleColon + 2);
    return lookupType(shortName, indexedSchema);
  }
  return null;
}

export function resolveFullType(schema: any, indexedSchema: Record<string, any>): any {
  if (!schema) return null;
  let current = schema;
  let depth = 0;
  const MAX_DEPTH = 10;

  while (current.type_ref && depth < MAX_DEPTH) {
    const resolved = lookupType(current.type_ref, indexedSchema);
    if (!resolved) break;
    // Merge properties (preserve field-level overrides like 'ies' or 'default')
    current = { ...resolved, ...current };
    if (current.kind && current.kind !== 'unknown') break;
    depth++;
  }
  return current;
}

export function isComplexType(kind: string) {
  const k = kind.toLowerCase();
  return ![
    `integer`,
    `boolean`,
    `string`,
    `octet_string`,
    `bit_string`,
    `null`,
    `real`,
    `oid`,
    `utf8string`,
    `printablestring`,
    `visiblestring`,
    `ia5string`,
    `numericstring`,
    `bmpstring`,
    `universalstring`,
    `generalizedtime`,
    `utctime`,
  ].includes(k);
}

export function getFieldKey(field: any) {
  return field.json_key || field.name;
}

export function getDataValue(data: any, field: any): any {
  if (!data || !field) return undefined;
  const key = getFieldKey(field);
  if (data[key] !== undefined) return data[key];
  
  // Try normalization (e.g., c-RNTI -> c_RNTI)
  const normalizedKey = key.replace(/-/g, '_');
  if (data[normalizedKey] !== undefined) return data[normalizedKey];
  
  // Try reverse normalization (e.g., c_RNTI -> c-RNTI)
  const reverseKey = key.replace(/_/g, '-');
  if (data[reverseKey] !== undefined) return data[reverseKey];
  
  return undefined;
}
