"""Read-only CLR/native evidence extraction. Never load or execute Aspen assemblies.

Dependencies: dnfile, dncil, pefile, capstone. Output must be a NEW directory
under this checkout's .local/wizard-logic-analysis-* tree. Vendor disassembly
and decompilation stay local; publish authored findings and symbol locations.
"""
from __future__ import annotations

import argparse
import bisect
import hashlib
import json
import re
from pathlib import Path

import capstone
import dnfile
import pefile
from dncil.cil.body.reader import read_method_body_from_bytes

ROOT = Path(__file__).resolve().parents[2]


def new_output(value: str) -> Path:
    out = Path(value).resolve()
    rel = out.relative_to(ROOT / ".local")
    if not rel.parts or not rel.parts[0].startswith("wizard-logic-analysis-"):
        raise ValueError("Output must be under .local/wizard-logic-analysis-*")
    out.mkdir(parents=True, exist_ok=False)
    return out


def dump(path: Path, value):
    path.write_text(json.dumps(value, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def identity(path, pe):
    return {"file": str(path), "sha256": hashlib.sha256(path.read_bytes()).hexdigest(),
            "size": path.stat().st_size, "machine": hex(pe.FILE_HEADER.Machine),
            "image_base": hex(pe.OPTIONAL_HEADER.ImageBase)}


def managed(path, pattern, out):
    pe = dnfile.dnPE(str(path))
    if pe.net is None:
        raise ValueError("No CLR metadata")
    tables = pe.net.mdtables
    owners = {}
    for t in tables.TypeDef:
        name = f"{t.TypeNamespace}.{t.TypeName}".lstrip(".")
        for member in list(t.MethodList) + list(t.FieldList):
            owners[id(member.row)] = name

    def resolve(token):
        kind, rid = token >> 24, token & 0xffffff
        if kind == 0x70:
            val = str(pe.net.user_strings.get(rid).value)
            # Do not emit arbitrary constants (database client literals etc.).
            return val if val.startswith(("Top.", "@main", "gx")) else "<string>"
        table = {0x01: "TypeRef", 0x02: "TypeDef", 0x04: "Field", 0x06: "MethodDef",
                 0x0a: "MemberRef", 0x1b: "TypeSpec", 0x2b: "MethodSpec"}.get(kind)
        if table is None:
            return f"token:{token:08x}"
        row = getattr(tables, table)[rid-1]
        if table == "MethodSpec":
            row = row.Method.row
        if hasattr(row, "Class"):
            parent = row.Class.row
            owner = f"{getattr(parent, 'TypeNamespace', '')}.{getattr(parent, 'TypeName', '')}".strip(".")
        else:
            owner = owners.get(id(row), "")
        return (owner + "::" + str(row.Name)) if hasattr(row, "Name") else str(getattr(row, "TypeName", table))

    methods, errors = [], []
    for rid, method in enumerate(tables.MethodDef, 1):
        name = owners.get(id(method), "") + "::" + str(method.Name)
        if not pattern.search(name):
            continue
        record = {"name": name, "token": f"0x{0x06000000+rid:08x}", "rva": hex(method.Rva),
                  "native": bool(method.ImplFlags.miNative), "calls": [], "branches": [], "il": []}
        if method.Rva and method.ImplFlags.miIL:
            try:
                body = read_method_body_from_bytes(pe.get_data(method.Rva))
                record["code_size"] = body.code_size
                record["header_size"] = body.header_size
                for ins in body.instructions:
                    op = ins.operand
                    is_branch = ins.opcode.name != "break" and ins.opcode.name.startswith(
                        ("br", "beq", "bne", "bge", "bgt", "ble", "blt", "switch", "leave"))
                    if is_branch:
                        # dncil includes the method header in both instruction
                        # offsets and branch targets. Normalize both together.
                        operand = ([hex(v-body.header_size) for v in op]
                                   if isinstance(op, list) else hex(op-body.header_size))
                    elif hasattr(op, "value"):
                        operand = resolve(op.value)
                    elif isinstance(op, list):
                        operand = op
                    else:
                        operand = str(op) if op is not None else ""
                    item = {"offset": hex(ins.offset-body.header_size), "op": str(ins.opcode), "operand": operand}
                    record["il"].append(item)
                    if str(ins.opcode) in ("call", "callvirt", "newobj", "ldftn", "ldvirtftn"):
                        record["calls"].append(item)
                    if is_branch:
                        record["branches"].append(item)
            except Exception as exc:
                record["parse_error"] = str(exc)
                errors.append({"method": name, "error": str(exc)})
        methods.append(record)
    dump(out / "managed.json", {**identity(path, pe), "methods": methods, "errors": errors})
    dump(out / "locations.json", {**identity(path, pe), "methods": [
        {k: v for k, v in m.items() if k not in ("il", "branches", "calls")} for m in methods]})
    print(json.dumps({"methods": len(methods), "errors": len(errors), "out": str(out)}))


def native(path, pattern, out, entries=()):
    pe = pefile.PE(str(path))
    base = pe.OPTIONAL_HEADER.ImageBase
    if pe.FILE_HEADER.Machine != 0x8664:
        raise ValueError("Native analyzer currently supports x64 only")
    export_dir = getattr(pe, "DIRECTORY_ENTRY_EXPORT", None)
    exports = {base + s.address: s.name.decode(errors="replace")
               for s in (export_dir.symbols if export_dir else []) if s.name and not s.forwarder}
    for rva in entries:
        exports[base+rva] = f"sub_{rva:x}"
    imports = {i.address: d.dll.decode() + "!" + (i.name.decode(errors="replace") if i.name else f"ordinal:{i.ordinal}")
               for d in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) for i in d.imports}
    extents = sorted((e.struct.BeginAddress, e.struct.EndAddress)
                     for e in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", []))
    starts = [a for a, _ in extents]
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    x86 = capstone.x86_const
    chained = {}
    for entry in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", []):
        info = entry.unwindinfo
        if getattr(info, "UNW_FLAG_CHAININFO", False):
            chained[entry.struct.BeginAddress] = info.FunctionEntry

    def owner(rva):
        seen = set()
        while rva in chained and rva not in seen:
            seen.add(rva)
            rva = chained[rva]
        return rva

    def target_name(va):
        if va in exports:
            return exports[va]
        try:
            thunk = next(md.disasm(pe.get_data(va-base, 6), va))
            if thunk.mnemonic == "jmp" and thunk.operands[0].type == x86.X86_OP_MEM:
                mem = thunk.operands[0].mem
                if mem.base == x86.X86_REG_RIP:
                    return imports.get(va+thunk.size+mem.disp, hex(va-base))
        except (StopIteration, pefile.PEFormatError):
            pass
        return hex(va-base)

    def string_at(rva):
        try:
            data = pe.get_data(rva, 240)
        except Exception:
            return None
        for enc, sep in (("ascii", b"\0"), ("utf-16-le", b"\0\0")):
            try:
                if enc == "ascii":
                    s = data.split(sep)[0].decode(enc)
                else:
                    end = next(i for i in range(0, len(data)-1, 2) if data[i:i+2] == sep)
                    s = data[:end].decode(enc)
                if 3 <= len(s) < 120 and all(c.isprintable() for c in s):
                    return s
            except (ValueError, UnicodeError, StopIteration):
                pass
        return None

    functions = []
    for va, name in exports.items():
        if not pattern.search(name):
            continue
        rva = va-base
        pos = bisect.bisect_right(starts, rva)-1
        exact = pos >= 0 and extents[pos][0] == rva
        if exact:
            chunks = [(a, b) for a, b in extents if owner(a) == owner(rva)]
        else:
            # Leaf exports may lack .pdata. Bound by next export; label explicitly.
            end = min([a-base for a in exports if a > va] + [a for a in starts if a > rva] + [rva+4096])
            chunks = [(rva, end)]
        instructions, calls, strings = [], [], []
        decoded = [ins for a, b in chunks for ins in md.disasm(pe.get_data(a, b-a), base+a)]
        for ins in decoded:
            refs = []
            for op in ins.operands:
                if op.type == x86.X86_OP_IMM and ins.mnemonic.startswith(("call", "j")):
                    target = op.imm
                    refs.append(target_name(target))
                elif op.type == x86.X86_OP_MEM and op.mem.base == x86.X86_REG_RIP:
                    target = ins.address+ins.size+op.mem.disp
                    if target in imports:
                        refs.append(imports[target])
                    else:
                        s = string_at(target-base)
                        if s:
                            refs.append("string:"+s)
                            strings.append({"at": hex(ins.address-base), "rva": hex(target-base), "value": s})
            item = {"rva": hex(ins.address-base), "mnemonic": ins.mnemonic, "operands": ins.op_str, "refs": refs}
            instructions.append(item)
            if ins.mnemonic in ("call", "jmp"):
                calls.append(item)
        functions.append({"name": name, "rva": hex(rva), "chunks": [[hex(a), hex(b)] for a,b in chunks],
                          "extent": "pdata-with-chaininfo" if exact else "bounded-linear-scan",
                          "calls": calls, "strings": strings, "instructions": instructions})
    dump(out / "native.json", {**identity(path, pe), "functions": functions,
                               "limits": "Linear disassembly of selected export extents; indirect virtual calls and transitive callees require separate analysis."})
    print(json.dumps({"functions": len(functions), "out": str(out)}))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("mode", choices=("managed", "native"))
    ap.add_argument("input", type=Path)
    ap.add_argument("--match", required=True, help="Type/method or exported symbol regex")
    ap.add_argument("--out", required=True)
    ap.add_argument("--entry", action="append", default=[], type=lambda v: int(v, 0), help="Additional native RVA")
    args = ap.parse_args()
    path = args.input.resolve(strict=True)
    pattern = re.compile(args.match)
    out = new_output(args.out)
    if args.mode == "managed":
        managed(path, pattern, out)
    else:
        native(path, pattern, out, args.entry)


if __name__ == "__main__":
    main()
