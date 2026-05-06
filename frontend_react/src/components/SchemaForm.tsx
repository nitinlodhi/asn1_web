import React, { useState, useEffect } from "react";
import { Button } from "./ui/button";
import { Input } from "./ui/input";
import { Label } from "./ui/label";
import { Textarea } from "./ui/textarea";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "./ui/select";
import { Checkbox } from "./ui/checkbox";
import { ChevronDown, ChevronRight, Plus, Trash2 } from "lucide-react";
import { cn } from "@/lib/utils";
import { lookupType, isComplexType, getFieldKey } from "@/schema-utils";

interface SchemaFormProps {
  schema: any;
  schemaIndex: Record<string, any>;
  onChange: (data: any) => void;
  initialData?: any;
}

export const SchemaForm: React.FC<SchemaFormProps> = ({
  schema,
  schemaIndex,
  onChange,
  initialData,
}) => {
  const [data, setData] = useState(initialData || {});

  useEffect(() => {
    onChange(data);
  }, [data, onChange]);

  if (!schema) {
    return (
      <div className="p-4">
        <Label>Raw JSON Input</Label>
        <Textarea
          placeholder='{ "field": value }'
          className="font-mono mt-2 h-40"
          value={typeof data === "string" ? data : JSON.stringify(data, null, 2)}
          onChange={(e) => {
            try {
              setData(JSON.parse(e.target.value));
            } catch {
              setData(e.target.value);
            }
          }}
        />
      </div>
    );
  }

  return (
    <div className="space-y-4 p-1">
      <Dispatcher
        schema={schema}
        schemaIndex={schemaIndex}
        data={data}
        onChange={(val) => setData(val)}
      />
    </div>
  );
};

const Dispatcher = ({ schema, schemaIndex, data, onChange }: any) => {
  switch (schema.kind) {
    case "sequence":
      return (
        <div className="border rounded-md overflow-hidden">
          <SequenceEditor
            fields={schema.fields || []}
            schemaIndex={schemaIndex}
            data={data || {}}
            onChange={onChange}
            depth={0}
          />
        </div>
      );
    case "choice":
      return (
        <ChoiceEditor
          schema={schema}
          schemaIndex={schemaIndex}
          data={data}
          onChange={onChange}
          depth={0}
          label="Root"
        />
      );
    case "enumeration":
      return <EnumEditor schema={schema} data={data} onChange={onChange} label="Root" />;
    case "sequence_of":
      return (
        <SequenceOfEditor
          schema={schema}
          schemaIndex={schemaIndex}
          data={data}
          onChange={onChange}
          depth={0}
          label="Root"
        />
      );
    default:
      return <BaseFieldEditor kind={schema.kind} data={data} onChange={onChange} label="Root" />;
  }
};

const SequenceEditor = ({ fields, schemaIndex, data, onChange, depth }: any) => (
  <div className="">
    {fields.map((field: any) => {
      const key = getFieldKey(field);
      return (
        <FieldWrapper
          key={key}
          field={field}
          schemaIndex={schemaIndex}
          data={data[key]}
          onChange={(val: any) => onChange({ ...data, [key]: val })}
          depth={depth}
        />
      );
    })}
  </div>
);

const FieldWrapper = ({ field, schemaIndex, data, onChange, depth }: any) => {
  const [isOpen, setIsOpen] = useState(true);
  const isSeq = field.kind === "sequence";
  const typeDef = isSeq ? lookupType(field.type_ref, schemaIndex) : null;
  const hasFields = isSeq && typeDef?.fields?.length;

  return (
    <>
      <div className="grid grid-cols-[auto_1fr] items-start hover:bg-accent/5 transition-colors">
        <div
          className="p-2 flex items-center gap-1 min-h-[40px]"
          style={{ paddingLeft: `${depth * 16 + 12}px` }}
        >
          {hasFields ? (
            <Button
              variant="ghost"
              size="icon"
              className="h-4 w-4"
              onClick={() => setIsOpen(!isOpen)}
            >
              {isOpen ? <ChevronDown className="h-3 w-3" /> : <ChevronRight className="h-3 w-3" />}
            </Button>
          ) : (
            <div className="w-4" />
          )}
          <span className="text-sm font-bold truncate" title={field.name}>
            {field.name}
          </span>
          {field.optional && (
            <span className="text-[10px] bg-amber-500/10 text-amber-600 px-1 rounded">opt</span>
          )}
        </div>
        <div className="p-2 flex flex-wrap gap-2 min-h-[40px]">
          <TypeSwitcher
            field={field}
            schemaIndex={schemaIndex}
            data={data}
            onChange={onChange}
            depth={depth}
          />
        </div>
      </div>
      {hasFields && isOpen && (
        <SequenceEditor
          fields={typeDef.fields}
          schemaIndex={schemaIndex}
          data={data || {}}
          onChange={onChange}
          depth={depth + 1}
        />
      )}
    </>
  );
};

const TypeSwitcher = ({ field, schemaIndex, data, onChange, depth }: any) => {
  if (field.kind === "sequence") {
    const typeDef = lookupType(field.type_ref, schemaIndex);
    if (typeDef?.fields?.length) {
      return <span className="text-xs text-muted-foreground italic">sequence</span>;
    }
    return <BaseFieldEditor kind={typeDef?.kind || "string"} data={data} onChange={onChange} />;
  }
  if (field.kind === "choice") {
    return (
      <ChoiceEditor
        schema={field}
        schemaIndex={schemaIndex}
        data={data}
        onChange={onChange}
        depth={depth}
      />
    );
  }
  if (field.kind === "enumeration") {
    return <EnumEditor schema={field} data={data} onChange={onChange} />;
  }
  if (field.kind === "sequence_of") {
    if (field.ies?.length) {
      return (
        <IeListEditor
          ies={field.ies}
          schemaIndex={schemaIndex}
          data={data}
          onChange={onChange}
          depth={depth}
        />
      );
    }
    return (
      <SequenceOfEditor
        schema={field}
        schemaIndex={schemaIndex}
        data={data}
        onChange={onChange}
        depth={depth}
      />
    );
  }
  return <BaseFieldEditor kind={field.kind} data={data} onChange={onChange} />;
};

const BaseFieldEditor = ({ kind, data, onChange }: any) => {
  const val = data === undefined ? "" : data;

  if (kind === "boolean") {
    return (
      <Select value={String(val)} onValueChange={(v) => onChange(v === "true")}>
        <SelectTrigger className="h-8 text-xs">
          <SelectValue placeholder="—" />
        </SelectTrigger>
        <SelectContent>
          <SelectItem value="true">true</SelectItem>
          <SelectItem value="false">false</SelectItem>
        </SelectContent>
      </Select>
    );
  }
  if (kind === "integer") {
    return (
      <Input
        type="number"
        className="h-8 text-xs"
        value={val}
        onChange={(e) => onChange(e.target.value === "" ? 0 : Number(e.target.value))}
      />
    );
  }
  if (kind === "null") {
    return (
      <Input className="h-8 text-xs opacity-50" value="null" readOnly disabled />
    );
  }
  return (
    <Input
      className="h-8 text-xs"
      placeholder={kind === "octet_string" ? "hex bytes" : kind}
      value={typeof val === "object" ? JSON.stringify(val) : val}
      onChange={(e) => onChange(e.target.value)}
    />
  );
};

const EnumEditor = ({ schema, data, onChange }: any) => {
  const values = schema.values || schema.enum_values || [];
  return (
    <Select value={data || ""} onValueChange={onChange}>
      <SelectTrigger className="h-8 text-xs">
        <SelectValue placeholder="— select —" />
      </SelectTrigger>
      <SelectContent>
        {values.map((v: any) => {
          const label = typeof v === "string" ? v : v.name || v;
          return (
            <SelectItem key={label} value={label}>
              {label}
            </SelectItem>
          );
        })}
      </SelectContent>
    </Select>
  );
};

const ChoiceEditor = ({ schema, schemaIndex, data, onChange, depth }: any) => {
  const alts = schema.alternatives || [];
  const selectedKey = data ? Object.keys(data)[0] : "";
  const selectedVal = selectedKey ? data[selectedKey] : undefined;

  return (
    <div className="w-full space-y-2">
      <Select
        value={selectedKey}
        onValueChange={(val) => {
          const alt = alts.find((a: any) => a.name === val);
          let initVal: any = "";
          if (alt?.kind === "integer") initVal = 0;
          else if (alt?.kind === "boolean") initVal = false;
          else if (alt?.kind === "null") initVal = null;
          onChange({ [val]: initVal });
        }}
      >
        <SelectTrigger className="h-8 text-xs">
          <SelectValue placeholder="— select alternative —" />
        </SelectTrigger>
        <SelectContent>
          {alts.map((alt: any) => (
            <SelectItem key={alt.name} value={alt.name}>
              {alt.name} {alt.kind && alt.kind !== "unknown" ? `(${alt.kind})` : ""}
            </SelectItem>
          ))}
        </SelectContent>
      </Select>
      {selectedKey && (
        <div className="pl-4 border-l-2 border-primary/20 mt-2">
          <ChoiceValueEditor
            alt={alts.find((a: any) => a.name === selectedKey)}
            schemaIndex={schemaIndex}
            data={selectedVal}
            onChange={(val: any) => onChange({ [selectedKey]: val })}
            depth={depth + 1}
          />
        </div>
      )}
    </div>
  );
};

const ChoiceValueEditor = ({ alt, schemaIndex, data, onChange, depth }: any) => {
  if (alt.kind === "sequence_of" && alt.ies?.length) {
    return (
      <IeListEditor
        ies={alt.ies}
        schemaIndex={schemaIndex}
        data={data}
        onChange={onChange}
        depth={depth}
      />
    );
  }
  if (alt.kind === "sequence") {
    const typeDef = lookupType(alt.type_ref, schemaIndex);
    if (typeDef?.fields?.length) {
      return (
        <div className="border rounded-md overflow-hidden bg-background">
          <SequenceEditor
            fields={typeDef.fields}
            schemaIndex={schemaIndex}
            data={data || {}}
            onChange={onChange}
            depth={depth}
          />
        </div>
      );
    }
  }
  return <BaseFieldEditor kind={alt.kind} data={data} onChange={onChange} />;
};

const SequenceOfEditor = ({ schema, data, onChange }: any) => {
  const items = Array.isArray(data) ? data : [];
  const elKind = schema.element_kind || "";

  const addItem = () => {
    onChange([...items, isComplexType(elKind) ? {} : ""]);
  };

  const removeItem = (idx: number) => {
    const newItems = [...items];
    newItems.splice(idx, 1);
    onChange(newItems);
  };

  return (
    <div className="w-full space-y-2">
      <div className="text-[10px] text-muted-foreground uppercase font-bold">
        Items ({elKind || schema.element_type || "value"})
      </div>
      <div className="space-y-2">
        {items.map((item, idx) => (
          <div key={idx} className="flex gap-2 items-start">
            <div className="flex-1">
              <BaseFieldEditor
                kind={elKind}
                data={item}
                onChange={(val: any) => {
                  const newItems = [...items];
                  newItems[idx] = val;
                  onChange(newItems);
                }}
              />
            </div>
            <Button
              variant="outline"
              size="icon"
              className="h-8 w-8 text-destructive"
              onClick={() => removeItem(idx)}
            >
              <Trash2 className="h-4 w-4" />
            </Button>
          </div>
        ))}
        <Button
          variant="outline"
          size="sm"
          className="w-full h-8 gap-1 text-xs"
          onClick={addItem}
        >
          <Plus className="h-3 w-3" /> Add Item
        </Button>
      </div>
    </div>
  );
};

const IeListEditor = ({ ies, schemaIndex, data, onChange, depth }: any) => {
  const items = Array.isArray(data) ? data : [];

  const toggleIe = (ie: any, enabled: boolean) => {
    if (enabled) {
      if (!items.find((it) => it.id === ie.id)) {
        onChange([...items, { id: ie.id, criticality: ie.criticality, value: { [ie.type]: "" } }]);
      }
    } else {
      onChange(items.filter((it) => it.id !== ie.id));
    }
  };

  const updateIeValue = (id: any, type: string, val: any) => {
    onChange(items.map((it) => (it.id === id ? { ...it, value: { [type]: val } } : it)));
  };

  return (
    <div className="w-full space-y-2 border rounded p-2 bg-muted/20">
      <div className="text-[10px] text-muted-foreground uppercase font-bold">
        IE List ({ies.length} items)
      </div>
      <div className="space-y-3 divide-y">
        {ies.map((ie: any) => {
          const entry = items.find((it) => it.id === ie.id);
          const enabled = !!entry;
          const typeDef = lookupType(ie.type, schemaIndex);

          return (
            <div key={ie.id} className="pt-2 space-y-2">
              <div className="flex items-center gap-2">
                <Checkbox
                  id={`ie-${ie.id}`}
                  checked={enabled}
                  onCheckedChange={(checked) => toggleIe(ie, !!checked)}
                />
                <Label
                  htmlFor={`ie-${ie.id}`}
                  className="text-sm font-medium leading-none cursor-pointer"
                >
                  {ie.id_name}
                </Label>
                <span
                  className={cn(
                    "text-[10px] px-1 rounded uppercase font-bold",
                    ie.criticality === "mandatory"
                      ? "bg-green-500/10 text-green-600"
                      : "bg-muted text-muted-foreground"
                  )}
                >
                  {ie.criticality}
                </span>
              </div>
              {enabled && (
                <div className="pl-6">
                  <IeValueEditor
                    ieSchema={typeDef}
                    schemaIndex={schemaIndex}
                    data={entry.value[ie.type]}
                    onChange={(val: any) => updateIeValue(ie.id, ie.type, val)}
                    depth={depth + 1}
                    typeName={ie.type}
                  />
                </div>
              )}
            </div>
          );
        })}
      </div>
    </div>
  );
};

const IeValueEditor = ({ ieSchema, schemaIndex, data, onChange, depth, typeName }: any) => {
  if (!ieSchema) {
    return (
      <Textarea
        className="text-xs h-20"
        placeholder={`JSON for ${typeName}`}
        value={typeof data === "string" ? data : JSON.stringify(data)}
        onChange={(e) => {
          try {
            onChange(JSON.parse(e.target.value));
          } catch {
            onChange(e.target.value);
          }
        }}
      />
    );
  }

  if (ieSchema.fields?.length) {
    return (
      <div className="border rounded-md overflow-hidden bg-background">
        <SequenceEditor
          fields={ieSchema.fields}
          schemaIndex={schemaIndex}
          data={data || {}}
          onChange={onChange}
          depth={depth}
        />
      </div>
    );
  }

  if (ieSchema.kind === "choice") {
    return (
      <ChoiceEditor
        schema={ieSchema}
        schemaIndex={schemaIndex}
        data={data}
        onChange={onChange}
        depth={depth}
      />
    );
  }

  return <BaseFieldEditor kind={ieSchema.kind} data={data} onChange={onChange} />;
};
