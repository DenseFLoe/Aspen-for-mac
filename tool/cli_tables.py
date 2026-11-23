# -*- coding: utf-8 -*-
"""Generic CLI metadata table reader (ECMA-335 II.22 row sizes, tables 0..44).

Unlike tool/md_reader.py this decodes every table needed to resolve IL operand
tokens (TypeRef / TypeDef / MethodDef / MemberRef / TypeSpec / ModuleRef), so an
IL 0x73 newobj operand can be followed to its owning type without reading any
symbol or name text.
"""
import struct

TABLES = {
    0: ("Module", [("Generation", 2), ("Name", "S"), ("Mvid", "G"), ("EncId", "G"), ("EncBaseId", "G")]),
    1: ("TypeRef", [("ResolutionScope", ("coded", 2, [0, 26, 35, 1])), ("TypeName", "S"), ("TypeNamespace", "S")]),
    2: ("TypeDef", [("Flags", 4), ("TypeName", "S"), ("TypeNamespace", "S"),
                    ("Extends", ("coded", 2, [2, 1, 27])), ("FieldList", ("idx", 4)), ("MethodList", ("idx", 6))]),
    3: ("FieldPtr", [("Field", ("idx", 4))]),
    4: ("Field", [("Flags", 2), ("Name", "S"), ("Signature", "B")]),
    5: ("MethodPtr", [("Method", ("idx", 6))]),
    6: ("MethodDef", [("RVA", 4), ("ImplFlags", 2), ("Flags", 2), ("Name", "S"), ("Signature", "B"),
                      ("ParamList", ("idx", 8))]),
    7: ("ParamPtr", [("Param", ("idx", 8))]),
    8: ("Param", [("Flags", 2), ("Sequence", 2), ("Name", "S")]),
    9: ("InterfaceImpl", [("Class", ("idx", 2)), ("Interface", ("coded", 2, [2, 1, 27]))]),
    10: ("MemberRef", [("Class", ("coded", 2, [2, 1, 26, 6, 27])), ("Name", "S"), ("Signature", "B")]),
    11: ("Constant", [("Type", 1), ("Padding", 1), ("Parent", ("coded", 2, [4, 8, 23])), ("Value", "B")]),
    12: ("CustomAttribute", [("Parent", ("coded", 5, [6, 4, 1, 2, 8, 9, 10, 0, 14, 23, 20, 17, 26, 27, 32, 35, 38,
                                                   39, 40, 42, 43, 44])),
                             ("Type", ("coded", 2, [6, 10])), ("Value", "B")]),
    13: ("FieldMarshal", [("Parent", ("coded", 2, [4, 8])), ("NativeType", "B")]),
    14: ("DeclSecurity", [("Action", 2), ("Parent", ("coded", 2, [2, 6, 32])), ("PermissionSet", "B")]),
    15: ("ClassLayout", [("PackingSize", 2), ("ClassSize", 4), ("Parent", ("idx", 2))]),
    16: ("FieldLayout", [("Offset", 4), ("Field", ("idx", 4))]),
    17: ("StandAloneSig", [("Signature", "B")]),
    18: ("EventMap", [("Parent", ("idx", 2)), ("EventList", ("idx", 20))]),
    19: ("EventPtr", [("Event", ("idx", 20))]),
    20: ("Event", [("EventFlags", 2), ("Name", "S"), ("EventType", ("coded", 2, [2, 1, 27]))]),
    21: ("PropertyMap", [("Parent", ("idx", 2)), ("PropertyList", ("idx", 23))]),
    22: ("PropertyPtr", [("Property", ("idx", 23))]),
    23: ("Property", [("Flags", 2), ("Name", "S"), ("Type", "B")]),
    24: ("MethodSemantics", [("Semantics", 2), ("Method", ("idx", 6)), ("Association", ("coded", 2, [20, 23]))]),
    25: ("MethodImpl", [("Class", ("idx", 2)), ("MethodBody", ("coded", 2, [6, 10])),
                        ("MethodDeclaration", ("coded", 2, [6, 10]))]),
    26: ("ModuleRef", [("Name", "S")]),
    27: ("TypeSpec", [("Signature", "B")]),
    28: ("ImplMap", [("MappingFlags", 2), ("MemberForwarded", ("coded", 2, [4, 6])), ("ImportName", "S"),
                     ("ImportScope", ("idx", 26))]),
    29: ("FieldRVA", [("RVA", 4), ("Field", ("idx", 4))]),
    30: ("ENCLog", [("Token", 4), ("FuncCode", 4)]),
    31: ("ENCMap", [("Token", 4)]),
    32: ("Assembly", [("HashAlgId", 4), ("Major", 2), ("Minor", 2), ("Build", 2), ("Revision", 2), ("Flags", 4),
                      ("PublicKey", "B"), ("Name", "S"), ("Culture", "S")]),
    33: ("AssemblyProcessor", [("Processor", 4)]),
    34: ("AssemblyOS", [("OSPlatformID", 4), ("OSMajor", 4), ("OSMinor", 4)]),
    35: ("AssemblyRef", [("Major", 2), ("Minor", 2), ("Build", 2), ("Revision", 2), ("Flags", 4),
                         ("PublicKeyOrToken", "B"), ("Name", "S"), ("Culture", "S"), ("HashValue", "B")]),
    36: ("AssemblyRefProcessor", [("Processor", 4), ("AssemblyRef", ("idx", 35))]),
    37: ("AssemblyRefOS", [("OSPlatformID", 4), ("OSMajor", 4), ("OSMinor", 4), ("AssemblyRef", ("idx", 35))]),
    38: ("File", [("Flags", 4), ("Name", "S"), ("HashValue", "B")]),
    39: ("ExportedType", [("Flags", 4), ("TypeDefId", 4), ("TypeName", "S"), ("TypeNamespace", "S"),
                          ("Implementation", ("coded", 2, [38, 35, 39]))]),
    40: ("ManifestResource", [("Offset", 4), ("Flags", 4), ("Name", "S"),
                              ("Implementation", ("coded", 2, [38, 35, 39]))]),
    41: ("NestedClass", [("NestedClass", ("idx", 2)), ("EnclosingClass", ("idx", 2))]),
    42: ("GenericParam", [("Number", 2), ("Flags", 2), ("Owner", ("coded", 2, [2, 6])), ("Name", "S")]),
    43: ("MethodSpec", [("Method", ("coded", 2, [6, 10])), ("Instantiation", "B")]),
    44: ("GenericParamConstraint", [("Owner", ("idx", 42)), ("Constraint", ("coded", 2, [2, 1, 27]))]),
}


def _cstr(data, start):
    return data[start:data.index(b"\0", start)].decode("utf-8", "replace")


def read(data, offset):
    """Return {counts, rows, streams}; rows[table] is a list of dicts with _row."""
    assert data[offset:offset + 4] == b"BSJB", "CLI metadata signature"
    pos = offset + 16 + int.from_bytes(data[offset + 12:offset + 16], "little")
    n = int.from_bytes(data[pos + 2:pos + 4], "little")
    pos += 4
    streams = {}
    for _ in range(n):
        rel, size = struct.unpack_from("<II", data, pos)
        name = _cstr(data, pos + 8)
        streams[name] = (offset + rel, size)
        pos += 8 + ((len(name) + 4) // 4) * 4
    # both compressed (#~) and uncompressed (#-) streams share this header layout; read the
    # HeapSizes byte from the stream header, never from a constant.
    tname = "#~" if "#~" in streams else "#-"
    t = streams[tname][0]
    heap = data[t + 6]
    ssize = 4 if (heap & 1 or tname == "#-") else 2
    gsize = 4 if (heap & 2 or tname == "#-") else 2
    bsize = 4 if (heap & 4 or tname == "#-") else 2
    valid = int.from_bytes(data[t + 8:t + 16], "little")
    counts = [0] * 64
    p = t + 24
    for i in range(64):
        if valid & (1 << i):
            counts[i] = int.from_bytes(data[p:p + 4], "little")
            p += 4

    def idxsize(table):
        return 4 if counts[table] >= 65536 else 2

    def codedsize(bits, tables):
        return 4 if max(counts[x] for x in tables) >= (1 << (16 - bits)) else 2

    def fsize(kind):
        if kind == "S":
            return ssize
        if kind == "G":
            return gsize
        if kind == "B":
            return bsize
        if isinstance(kind, int):
            return kind
        if kind[0] == "idx":
            return idxsize(kind[1])
        return codedsize(kind[1], kind[2])

    starts = {}
    p = t + 24 + 4 * bin(valid).count("1")
    for i in range(64):
        if not counts[i]:
            continue
        if i not in TABLES:
            raise ValueError("table %d has rows but no schema" % i)
        size = sum(fsize(k) for _, k in TABLES[i][1])
        starts[i] = (p, size)
        p += counts[i] * size
    rows = {}
    for i in sorted(starts):
        base, size = starts[i]
        out = []
        for r in range(counts[i]):
            off = base + r * size
            row = {}
            for name, kind in TABLES[i][1]:
                width = fsize(kind)
                raw = int.from_bytes(data[off:off + width], "little")
                row[name] = _cstr(data, streams["#Strings"][0] + raw) if kind == "S" else raw
                off += width
            row["_row"] = r + 1
            out.append(row)
        rows[i] = out
    layout = []
    for i in sorted(starts):
        base, size = starts[i]
        for name, kind in TABLES[i][1]:
            if isinstance(kind, int):
                rule = "fixed %d" % kind
            elif kind in ("S", "G", "B"):
                rule = "heap %s -> %d (HeapSizes 0x%02X)" % (kind, fsize(kind), heap)
            elif kind[0] == "idx":
                rule = "table %d rows %d < 65536 -> %d" % (kind[1], counts[kind[1]], fsize(kind))
            else:
                rule = "coded tag %d bits, max rows %d < 2**%d -> %d" % (
                    kind[1], max(counts[x] for x in kind[2]), 16 - kind[1], fsize(kind))
            layout.append(dict(table=TABLES[i][0], column=name, width=fsize(kind),
                               rule=rule, row_size=size, rows=counts[i]))
    return dict(counts=counts, rows=rows, streams=streams, heap_sizes=heap,
                stream=tname, layout=layout)


def coded_width(bits, max_rows):
    """2 bytes while max_rows < 2**(16-bits); the single rule used by the parser."""
    return 2 if max_rows < (1 << (16 - bits)) else 4


CODED_TAGS = {
    1: {0: 2, 1: 1, 2: 27},                    # TypeDefOrRef
    9: {0: 2, 1: 1, 2: 27},                    # TypeDefOrRef (InterfaceImpl)
    10: {0: 2, 1: 1, 2: 26, 3: 6, 4: 27},      # MemberRefParent
    11: {0: 4, 1: 8, 2: 23},                   # HasConstant
    12: {0: 6, 1: 4, 2: 1, 3: 2, 4: 8, 5: 9, 6: 10, 7: 0, 8: 14, 9: 23, 10: 20,
         11: 17, 12: 26, 13: 27, 14: 32, 15: 35, 16: 38, 17: 39, 18: 40, 19: 42, 20: 43, 21: 44},
    13: {0: 4, 1: 8},                          # HasFieldMarshal
    14: {0: 2, 1: 6, 2: 32},                   # HasDeclSecurity
    24: {0: 20, 1: 23},                        # HasSemantics
    25: {0: 6, 1: 10},                         # MethodDefOrRef
    28: {0: 4, 1: 6},                          # MemberForwarded
    42: {0: 2, 1: 6},                          # TypeOrMethodDef
    43: {0: 6, 1: 10},                         # MethodDefOrRef
}
CODED_BITS = {1: 2, 9: 2, 10: 3, 11: 2, 12: 5, 13: 1, 14: 2, 24: 1, 25: 1, 28: 1, 42: 1, 43: 1}


def decode_coded(table, value):
    """Split a coded index held by table column into (table, row) or (None, 0)."""
    bits = CODED_BITS[table]
    tag = value & ((1 << bits) - 1)
    row = value >> bits
    return CODED_TAGS[table].get(tag), row


def token(table, row):
    return (table << 24) | row


def split_token(tok):
    return tok >> 24, tok & 0xFFFFFF

# ---- signature helpers (TypeSpec) ------------------------------------------
ELEMENT = {0x01: "void", 0x02: "bool", 0x03: "char", 0x04: "System.SByte", 0x05: "System.Byte",
           0x06: "System.Int16", 0x07: "System.UInt16", 0x08: "System.Int32", 0x09: "System.UInt32",
           0x0A: "System.Int64", 0x0B: "System.UInt64", 0x0C: "System.Single", 0x0D: "System.Double",
           0x0E: "System.String", 0x18: "System.IntPtr", 0x19: "System.UIntPtr",
           0x1C: "System.Object"}

# TypeRef.ResolutionScope is its own coded index (Module/ModuleRef/AssemblyRef/TypeRef),
# distinct from TypeDefOrRef even though both live in 2 bits.
RESOLUTION_SCOPE = {0: 0, 1: 26, 2: 35, 3: 1}


def decode_resolution_scope(value):
    return RESOLUTION_SCOPE[value & 3], value >> 2


def blob_bytes(data, tables, index):
    """#Blob heap entry at index -> raw bytes."""
    base = tables["streams"]["#Blob"][0]
    i = base + index
    b0 = data[i]
    if b0 & 0x80 == 0:
        n, start = b0, i + 1
    elif b0 & 0xC0 == 0x80:
        n, start = ((b0 & 0x3F) << 8) | data[i + 1], i + 2
    else:
        n = ((b0 & 0x1F) << 24) | (data[i + 1] << 16) | (data[i + 2] << 8) | data[i + 3]
        start = i + 4
    return data[start:start + n]


def compressed(data, i):
    b0 = data[i]
    if b0 & 0x80 == 0:
        return b0, i + 1
    if b0 & 0xC0 == 0x80:
        return ((b0 & 0x3F) << 8) | data[i + 1], i + 2
    return ((b0 & 0x1F) << 24) | (data[i + 1] << 16) | (data[i + 2] << 8) | data[i + 3], i + 4


def typedeforref_name(tables, value):
    tag, row = value & 3, value >> 2
    if tag == 1 and row <= len(tables["rows"].get(1, [])):
        tr = tables["rows"][1][row - 1]
        scope, srow = decode_resolution_scope(tr["ResolutionScope"])
        asm = ""
        if scope == 35 and srow <= len(tables["rows"].get(35, [])):
            asm = tables["rows"][35][srow - 1]["Name"]
        return asm, "%s.%s" % (tr["TypeNamespace"], tr["TypeName"])
    if tag == 0 and row <= len(tables["rows"].get(2, [])):
        td = tables["rows"][2][row - 1]
        return "this-module", "%s.%s" % (td["TypeNamespace"], td["TypeName"])
    return "", "TypeDefOrRef#%d" % value


def typespec_name(data, tables, row):
    """Render a TypeSpec row (GENERICINST and simple class forms)."""
    ts = tables["rows"][27][row - 1]
    sig = blob_bytes(data, tables, ts["Signature"])
    i = 0
    et = sig[i]
    i += 1
    if et == 0x15:                                  # GENERICINST
        kind = sig[i]
        i += 1
        value, i = compressed(sig, i)
        asm, name = typedeforref_name(tables, value)
        n, i = compressed(sig, i)
        args = []
        for _ in range(n):
            a = sig[i]
            i += 1
            if a == 0x12:                            # CLASS/VALUETYPE
                v, i = compressed(sig, i)
                _, an = typedeforref_name(tables, v)
                args.append(an)
            else:
                args.append(ELEMENT.get(a, "et%#x" % a))
        return asm, "%s<%s>" % (name, ",".join(args))
    if et == 0x12:
        v, i = compressed(sig, i)
        return typedeforref_name(tables, v)
    return "", "TypeSpec#%d" % row
