# -*- coding: utf-8 -*-
"""IL 0x73 newobj sites -> ctor -> owning type, resolved from original bytes only.

No signature text or assembly name is used: the operand is a 4-byte metadata
token, the token table decides the target (MethodDef) or the intermediate
(MemberRef -> Class coded index -> TypeDef/TypeRef/ModuleRef/TypeSpec).
"""
import struct

import cli_tables
import il_disasm


def _owner_of_type(types, row_number):
    """TypeDef row (1-based) -> (token, name)."""
    t = types[row_number - 1]
    return t["token"], t["name"]


def _memberref_class(tables, memberref_row):
    """Decode MemberRef.Class -> (table_id, row) of the parent."""
    row = tables["rows"][10][memberref_row - 1]
    return cli_tables.decode_coded(10, row["Class"])


def resolve(tables, meta, tok, data=None):
    """Resolve one operand token.  Returns dict with kind/owner/verdict."""
    table, row = cli_tables.split_token(tok)
    types = meta["types"]
    methods = meta["methods"]
    out = dict(token=tok, table=table, row=row, name="", owner_kind="", owner_row=0,
               owner_name="", owner_token=0, verdict="unresolved", note="")
    if table == 6:                                    # MethodDef
        if not (1 <= row <= len(methods)):
            out["note"] = "MethodDef row %d outside table" % row
            return out
        m = methods[row - 1]
        out.update(name=m["name"], owner_kind="MethodDef", owner_row=row,
                   owner_token=m["token"], flavor=m["flavor"], rva=m["rva"])
        if m["name"] != ".ctor":
            out.update(verdict="rejected", note="MethodDef %s is not .ctor" % m["name"])
            return out
        for t in types:
            if t["method_start"] <= row < t["method_end"]:
                out.update(owner_kind="TypeDef", owner_row=t["token"] & 0xFFFFFF,
                           owner_name=t["name"], verdict="internal-ctor")
                break
        else:
            out["note"] = "owner TypeDef not found for MethodDef row %d" % row
        return out
    if table == 10:                                   # MemberRef
        if not (1 <= row <= len(tables["rows"][10])):
            out["note"] = "MemberRef row %d outside table" % row
            return out
        ref = tables["rows"][10][row - 1]
        out["name"] = ref["Name"]
        if ref["Name"] != ".ctor":
            out.update(verdict="rejected", note="MemberRef %s is not .ctor" % ref["Name"])
            return out
        parent, prow = _memberref_class(tables, row)
        if parent == 2:                                # TypeDef in this module
            tok2, nm = _owner_of_type(types, prow) if prow <= len(types) else (0, "")
            out.update(owner_kind="TypeDef", owner_row=prow, owner_name=nm,
                       owner_token=tok2, verdict="internal-type-ctor")
        elif parent == 1:                              # TypeRef (external assembly)
            tr = tables["rows"][1][prow - 1]
            scope, srow = cli_tables.decode_resolution_scope(tr["ResolutionScope"])
            asm = ""
            if scope == 35 and srow <= len(tables["rows"].get(35, [])):
                asm = tables["rows"][35][srow - 1]["Name"]
            elif scope == 0 and srow <= len(tables["rows"].get(0, [])):
                asm = "this-module"
            out.update(owner_kind="TypeRef", owner_row=prow,
                       owner_name="%s.%s" % (tr["TypeNamespace"], tr["TypeName"]),
                       verdict="external-ctor", assembly=asm)
        elif parent == 27:                             # TypeSpec (generic instantiation)
            asm, nm = cli_tables.typespec_name(data, tables, prow) if data else ("", "TypeSpec#%d" % prow)
            out.update(owner_kind="TypeSpec", owner_row=prow, owner_name=nm, assembly=asm,
                       verdict="external-ctor",
                       note="TypeSpec#%d GENERICINST -> %s" % (prow, nm))
        elif parent == 26:                             # ModuleRef
            mr = tables["rows"][26][prow - 1]
            out.update(owner_kind="ModuleRef", owner_row=prow, owner_name=mr["Name"],
                       verdict="module-ctor")
        elif parent == 6:
            out.update(owner_kind="MethodDef", owner_row=prow, verdict="vararg-ctor")
        else:
            out["note"] = "unknown MemberRefParent tag"
        return out
    out["note"] = "token table %d is not MethodDef/MemberRef" % table
    return out


def scan(data, pe, tables, meta):
    sites = []
    for m in meta["methods"]:
        if m["flavor"] != "IL" or not m["rva"]:
            continue
        body = il_disasm.body(data, pe.filepos, m["rva"])
        for off, name, operand, size in il_disasm.decode(body):
            if name != "newobj":
                continue
            tok = int(operand.split()[0], 16)
            info = resolve(tables, meta, tok, data)
            info.update(caller_token=m["token"], caller_name=m["name"], caller_rva=m["rva"],
                        offset=off, opcode="0x73", size=size)
            sites.append(info)
    return sites


def self_test(tables, meta):
    """Negative controls for newobj token classification."""
    results = []
    # 1. opcode 0x28 (call) is not a newobj site
    body = bytes([0x28, 0x01, 0x00, 0x00, 0x06, 0x2A])
    got = [x for x in il_disasm.decode(body) if x[1] == "newobj"]
    results.append(("opcode 0x28 call is not newobj", len(got) == 0))
    # 2. MethodDef that is not .ctor is rejected
    nonctor = next(m for m in meta["methods"] if m["name"] != ".ctor")
    r = resolve(tables, meta, nonctor["token"])
    results.append(("non-.ctor MethodDef rejected", r["verdict"] == "rejected"))
    # 3. MemberRef whose name is not .ctor is rejected
    bad = next((i for i, r in enumerate(tables["rows"][10], start=1) if r["Name"] != ".ctor"), None)
    if bad is not None:
        r = resolve(tables, meta, cli_tables.token(10, bad))
        results.append(("non-.ctor MemberRef rejected", r["verdict"] == "rejected"))
    # 4. out-of-range token is unresolved, not guessed
    r = resolve(tables, meta, 0x0AFFFF)
    results.append(("out-of-range token unresolved", r["verdict"] == "unresolved"))
    # 5. TypeRef token is not a ctor
    r = resolve(tables, meta, 0x01000001)
    results.append(("TypeRef token unresolved", r["verdict"] == "unresolved"))
    return results
