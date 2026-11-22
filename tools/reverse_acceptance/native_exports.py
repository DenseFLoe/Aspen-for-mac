"""Rebuild restricted AMD64 inline-assembly C exports and compare their original PE ranges."""
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import tempfile

if __package__:
    from .coff import ZIG_SHA256
else:
    from coff import ZIG_SHA256


SCOPE = ("Named AMD64 PE export ranges with restricted inline-assembly C sources. "
         "Fresh COFF bytes and REL32 operands; manifest instruction counts, jumps, call sites, "
         "one-hop import thunks, RIP operands and declared initialization data.")
# Reviewed register-forms.h defines the fixed NAKED, START and END C macros.
HEADER_SHA256 = "9cfb9b139e9fb4364b0857f024f6507bdcc47c898ccc08af255845dcd41a8eb3"
IDENT = re.compile(r"[A-Za-z_][A-Za-z0-9_]*")
WRAPPER = re.compile(
    r'\A#include "register-forms\.h"\n[ \t\n]*'
    r'(?:/\* [A-Za-z0-9_:. ()-]+ \*/\n[ \t\n]*)?'
    r'NAKED void (?P<name>[A-Za-z_]\w*)\(void\) \{\n[ \t]*__asm__\(START\n'
    r'(?P<body>(?:[ \t]*"[^"\n]+\\n"[ \t]*\n)+)'
    r'[ \t]*END\);\n\}[ \t\n]*\Z', re.ASCII)


def _digest(data):
    return hashlib.sha256(data).hexdigest()


def _unique_keys(pairs):
    data = dict(pairs)
    if len(data) != len(pairs):
        raise ValueError("Duplicate key in export manifest")
    return data


def _read(root, relative, limit):
    path = (root / relative).resolve(strict=True)
    if not path.is_relative_to(root) or not path.is_file():
        raise ValueError("Input outside delivery or not a regular file")
    with path.open("rb") as stream:
        data = stream.read(limit + 1)
    if len(data) > limit:
        raise ValueError(f"Input exceeds size limit: {relative}")
    return data


def _source_supported(source, export, x86):
    text = source.decode("ascii").replace("\r\n", "\n")
    match = WRAPPER.fullmatch(text)
    if not match or match["name"] != export:
        return False
    for line in match["body"].splitlines():
        asm = line.strip()[1:-3]  # strip quotes and the C newline escape
        if re.fullmatch(r"\.L[A-Za-z_0-9]+:", asm):
            continue
        if re.fullmatch(r"\.byte 0x[0-9a-f]{1,2}(?:, 0x[0-9a-f]{1,2}){0,14} # alignment nop", asm):
            raw = bytes(int(n, 16) for n in re.findall(r"0x([0-9a-f]+)", asm))
            nop = x86.Decoder(64, raw).decode()
            if nop.mnemonic == x86.Mnemonic.NOP and nop.len == len(raw):
                continue
        # A single mnemonic and plain operands. Excludes additional statements,
        # assembler directives, escapes, comments, C interpolation and macro calls.
        op = re.fullmatch(r"([a-z][a-z0-9]*)(?: [a-zA-Z0-9_., +*\[\]-]+)?", asm)
        if (not op or op[1] in {"db", "dw", "dd", "dq"}
                or not (op[1] == "movabs" or hasattr(x86.Mnemonic, op[1].upper()))):
            return False
    return True


def _coff(data, export):
    machine, count, _, symbols, nsyms, optional, _ = struct.unpack_from("<HHIIIHH", data)
    if machine != 0x8664 or optional or not 0 < count <= 96:
        raise ValueError("Unsupported COFF header")
    end = symbols + nsyms * 18
    table_size, = struct.unpack_from("<I", data, end)
    if table_size < 4 or end + table_size > len(data):
        raise ValueError("Incomplete COFF string table")
    strings = data[end:end + table_size]
    sections = [struct.unpack_from("<8sIIIIIIHHI", data, 20 + i * 40) for i in range(count)]
    text, = [i for i, hdr in enumerate(sections, 1) if hdr[0].rstrip(b"\0") == b".text"]
    _, _, _, size, start, rel, _, nr, _, flags = sections[text - 1]
    if (flags & 0x20000020 != 0x20000020 or flags & 0x01001000 or
            start + size > len(data) or rel + nr * 10 > len(data)):
        raise ValueError("Unsupported COFF code or relocation range")
    externals = {}
    definitions = []
    i = 0
    while i < nsyms:
        raw, value, sec, typ, storage, aux = struct.unpack_from("<8sIhHBB", data, symbols + 18 * i)
        if raw[:4] == bytes(4):
            ptr = int.from_bytes(raw[4:], "little")
            if ptr < 4 or ptr >= len(strings):
                raise ValueError("Invalid COFF symbol name offset")
            raw = strings[ptr:strings.index(b"\0", ptr)]
        name = raw.rstrip(b"\0").decode("ascii")
        if sec == text and storage == 2:
            definitions.append((name, value, typ))
        if sec == 0 and storage == 2 and value == 0 and not aux:
            externals[i] = name
        i += 1 + aux
    if i != nsyms or definitions != [(export, 0, 0x20)]:
        raise ValueError("COFF .text must contain the single named function at offset zero")
    rows = []
    occupied = set()
    for pos, sym, kind in struct.iter_unpack("<IIH", data[rel:rel + nr * 10]):
        label = externals.get(sym, "")
        field = range(pos, pos + 4)
        if (not 4 <= kind <= 9 or pos + 4 > size or occupied.intersection(field)
                or not re.fullmatch(r"rva_[0-9a-fA-F]{1,8}", label)):
            raise ValueError("Unsupported COFF symbol, relocation type or field")
        occupied.update(field)
        rows.append((pos, label, kind))
    return data[start:start + size], rows


def _extent(pe, entry, anchors, unwind, x86):
    sections = [s for s in pe.sections if s.Characteristics & 0x20000000
                and s.VirtualAddress <= entry < s.VirtualAddress + min(s.SizeOfRawData, s.Misc_VirtualSize)]
    if len(sections) != 1:
        raise ValueError("Export lacks a unique file-backed executable section")
    section = sections[0]
    cap = min(section.VirtualAddress + min(section.SizeOfRawData, section.Misc_VirtualSize),
              next((a for a in anchors if a > entry), 1 << 32))
    matches = [(lo, hi) for lo, hi in unwind if lo <= entry < hi]
    if matches:
        if len(matches) != 1 or matches[0][0] != entry or matches[0][1] > cap:
            raise ValueError("Ambiguous PE unwind range")
        return matches[0][1], "PE exception directory"
    # Without unwind metadata, prove a contiguous leaf only up to the first
    # ordinary RET, with no branch, call or invalid instruction along the path.
    decoder = x86.Decoder(64, pe.get_data(entry, min(cap - entry, 65536)), ip=entry)
    for ins in decoder:
        if ins.mnemonic == x86.Mnemonic.RET:
            return ins.next_ip, "straight-line leaf through RET"
        if ins.is_invalid or ins.flow_control != x86.FlowControl.NEXT:
            break
    raise ValueError("Leaf end not independently established")


def _compare(raw, rebuilt, rows, entry, x86):
    """Map each fixup back to its original decoded operand, then compare all bytes."""
    if len(raw) != len(rebuilt):
        return {"code": "export_size", "rva": hex(entry + min(len(raw), len(rebuilt))),
                "original": len(raw), "rebuilt": len(rebuilt)}
    decoded = x86.Decoder(64, raw, ip=entry)
    fields = {}
    required = set()
    for ins in decoded:
        if ins.is_invalid:
            raise ValueError(f"Cannot decode original instruction at {ins.ip:#x}")
        co = decoded.get_constant_offsets(ins)
        if ins.is_ip_rel_memory_operand and co.displacement_size == 4:
            pos, target = co.displacement_offset, ins.ip_rel_memory_address
        elif ins.op0_kind in (x86.OpKind.NEAR_BRANCH64, x86.OpKind.NEAR_BRANCH32) and co.immediate_size == 4:
            pos, target = co.immediate_offset, ins.near_branch_target
        else:
            continue
        offset = ins.ip - entry + pos
        fields[offset] = (ins.next_ip, target)
        if not entry <= target < entry + len(raw):
            required.add(offset)
    payload = bytearray(rebuilt)
    for pos, label, kind in rows:
        addend, = struct.unpack_from("<i", payload, pos)
        rva = entry + pos
        delta = int(label[4:], 16) + addend - (rva + kind)
        original_disp, = struct.unpack_from("<i", raw, pos)
        details = {"rva": hex(rva), "symbol": label, "addend": addend, "relocation_type": kind}
        if pos not in fields:
            return {"code": "export_relocation_field", **details,
                    "original": "no decoded REL32 operand", "rebuilt": label}
        following, target = fields[pos]
        if delta != original_disp or following + delta != target:
            return {"code": "export_relocation_target", **details,
                    "original": hex(target), "rebuilt": hex(following + delta),
                    "original_displacement": original_disp, "rebuilt_displacement": delta}
        # In this source format rva_X names the referenced RVA itself. Check
        # symbol and addend independently even when two errors cancel in bytes.
        expected_addend = rva + kind - following
        if int(label[4:], 16) != target or addend != expected_addend:
            return {"code": "export_relocation_symbol", **details, "original": hex(target),
                    "rebuilt": hex(int(label[4:], 16)), "expected_addend": expected_addend}
        required.discard(pos)
        struct.pack_into("<i", payload, pos, delta)
    if required:
        first = min(required)
        return {"code": "export_missing_relocation", "rva": hex(entry + first),
                "original": hex(fields[first][1]), "rebuilt": None}
    for i, (a, b) in enumerate(zip(raw, payload)):
        if a != b:
            return {"code": "export_code_byte", "rva": hex(entry + i),
                    "original": f"{a:02x}", "rebuilt": f"{b:02x}"}
    return None


def _import_slots(pe):
    slots = {}
    for index, attr in ((1, "DIRECTORY_ENTRY_IMPORT"), (13, "DIRECTORY_ENTRY_DELAY_IMPORT")):
        directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if index < len(directories) and directories[index].VirtualAddress and not hasattr(pe, attr):
            raise ValueError("Original import directory could not be decoded")
        for dll in getattr(pe, attr, ()):
            for imp in dll.imports:
                name = f"#{imp.ordinal}" if imp.import_by_ordinal else imp.name.decode("ascii")
                slot = imp.address - pe.OPTIONAL_HEADER.ImageBase
                ident = dll.dll.decode("ascii") + "!" + name
                if slot in slots and slots[slot] != ident:
                    raise ValueError(f"Conflicting original import entries at {slot:#x}")
                slots[slot] = ident
    return slots


def _call_operand(pe, ins, slots, x86):
    # A direct target can be an executable jump thunk. Its destination must
    # be the original IAT slot. A data read by the caller is not a call.
    direct = ins.op0_kind in (x86.OpKind.NEAR_BRANCH16, x86.OpKind.NEAR_BRANCH32, x86.OpKind.NEAR_BRANCH64)
    target = ins.near_branch_target if direct else None
    operand = ins
    if direct:
        section = pe.get_section_by_rva(target)
        if section is None or not section.Characteristics & 0x20000000:
            operand = None
        else:
            end = section.VirtualAddress + min(section.Misc_VirtualSize, section.SizeOfRawData)
            size = min(15, end - target)
            thunk = x86.Decoder(64, pe.get_data(target, size), ip=target).decode() if size > 0 else None
            operand = thunk if thunk and thunk.mnemonic == x86.Mnemonic.JMP else None
    external = None
    if (operand and operand.op0_kind == x86.OpKind.MEMORY and operand.is_ip_rel_memory_operand
            and operand.segment_prefix not in (x86.Register.FS, x86.Register.GS)):
        slot = operand.ip_rel_memory_address
        if slot in slots:
            external = {"iat_rva": hex(slot), "import": slots[slot]}
    return {"site": hex(ins.ip), "target": hex(target) if direct else None, "external": external}


def _zero_range(pe, stores):
    offsets = sorted(int(store[1], 16) for store in stores)
    if not offsets or any(b - a != 8 for a, b in zip(offsets, offsets[1:])):
        raise ValueError("Stores do not identify one contiguous initializer range")
    lo, end = offsets[0], offsets[-1] + 8
    covering = [s for s in pe.sections if s.VirtualAddress <= lo and
                end <= s.VirtualAddress + s.Misc_VirtualSize]
    if len(covering) != 1:
        raise ValueError("Initializer lacks a unique mapped PE section")
    section, = covering
    # The loader zero-fills the virtual suffix beyond SizeOfRawData.
    backed = max(0, min(end, section.VirtualAddress + section.SizeOfRawData) - lo)
    stored = pe.get_data(lo, backed) if backed else b""
    if len(stored) != backed:
        raise ValueError("Truncated original section containing initializer data")
    actual = {"begin": hex(lo), "end": hex(end), "bytes": end - lo}
    first = next((i for i, value in enumerate(stored) if value), None)
    return actual, (lo + first, stored[first]) if first is not None else None


def _facts(raw, entry, pe, x86):
    slots = _import_slots(pe)
    fmt = x86.Formatter(x86.FormatterSyntax.INTEL)
    flows = x86.FlowControl
    jumps = Counter()
    calls, refs, stores = [], [], []
    count = 0
    for ins in x86.Decoder(64, raw, ip=entry):
        if ins.is_invalid:
            raise ValueError(f"Cannot decode original instruction at {ins.ip:#x}")
        count += 1
        if ins.flow_control in (flows.CONDITIONAL_BRANCH, flows.UNCONDITIONAL_BRANCH, flows.INDIRECT_BRANCH):
            jumps[fmt.format_mnemonic(ins)] += 1
        elif ins.mnemonic == x86.Mnemonic.CALL:
            calls.append(_call_operand(pe, ins, slots, x86))
        if ins.is_ip_rel_memory_operand:
            refs.append([hex(ins.ip), hex(ins.ip_rel_memory_address)])
            if (ins.mnemonic == x86.Mnemonic.MOV and ins.op0_kind == x86.OpKind.MEMORY and
                    ins.op1_kind in (x86.OpKind.IMMEDIATE64, x86.OpKind.IMMEDIATE32TO64) and
                    x86.MemorySizeExt.size(ins.memory_size) == 8 and
                    ins.segment_prefix not in (x86.Register.FS, x86.Register.GS)):
                stores.append([*refs[-1], ins.immediate(1)])
    return {"instructions": count, "jumps": dict(jumps), "calls": calls,
            "rip_operands": refs, "ordered_u64_stores": stores}


def _difference(actual, declared, path):
    """Return the first typed difference and its path without echoing an entire manifest."""
    if type(actual) is type(declared):
        if isinstance(actual, dict):
            # Jump mnemonic counts form a closed set. Other objects may carry
            # supplementary notes beyond the machine-verifiable fields.
            keys = actual.keys() | declared.keys() if path == ["jumps"] else actual.keys()
            for key in sorted(keys):
                if key not in actual or key not in declared:
                    return path + [key], actual.get(key), declared.get(key)
                diff = _difference(actual[key], declared[key], path + [key])
                if diff:
                    return diff
            return None
        if isinstance(actual, list):
            for i, (left, right) in enumerate(zip(actual, declared)):
                diff = _difference(left, right, path + [i])
                if diff:
                    return diff
            i = min(len(actual), len(declared))
            if len(actual) != len(declared):
                return path + [i], actual[i] if i < len(actual) else None, declared[i] if i < len(declared) else None
            return None
        if actual == declared:
            return None
        if (isinstance(actual, str) and re.fullmatch(r"0x[0-9a-f]+", actual)
                and re.fullmatch(r"0[xX][0-9a-fA-F]{1,16}", declared) and int(actual, 16) == int(declared, 16)):
            return None
        if (path[0] == "ordered_u64_stores" and path[-1] == 2 and isinstance(actual, int)
                and -(1 << 63) <= declared < 0 and (declared & ((1 << 64) - 1)) == actual):
            return None
        if path[-1] == "import" and isinstance(actual, str):
            dll, sep, symbol = actual.partition("!")
            other, sep2, other_symbol = declared.partition("!")
            if sep and sep2 and dll.casefold() == other.casefold() and symbol == other_symbol:
                return None
    return path, actual, declared


def _site(record):
    if isinstance(record, dict):
        return record.get("site")
    if isinstance(record, list) and record:
        return record[0]
    return None


def _indirect_claims(actual, declared):
    """Preserve unresolved runtime destinations separately from decoded call operands."""
    unresolved = {int(c["site"], 16): c for c in actual if c["target"] is None}
    checked = [dict(c) if isinstance(c, dict) else c for c in declared]
    unverified = []
    for record in checked:
        original = unresolved.get(int(_site(record), 16))
        if original is None or not isinstance(record, dict):
            continue
        for field in ("target", "external"):
            if original[field] is None and record.get(field) is not None:
                unverified.append((original["site"], field, record[field]))
                record[field] = None
    return checked, unverified


def _check_facts(raw, entry, pe, x86, claim, row, name, issue):
    facts = _facts(raw, entry, pe, x86)
    primary = ("instructions", "jumps", "calls", "rip_operands")
    row["decoded"] = {"instructions": facts["instructions"], "jumps": facts["jumps"],
                      "calls": len(facts["calls"]), "iat_calls": sum(c["external"] is not None for c in facts["calls"]),
                      "rip_operands": len(facts["rip_operands"])}
    row["unreported_fields"] = [field for field in primary if field not in claim]
    if row["unreported_fields"] and row["manifest_status"] != "fail":
        row["manifest_status"] = "inconclusive"
    if "mapped_zero_initialized_data" in claim:
        try:
            region, nonzero = _zero_range(pe, facts["ordered_u64_stores"])
            facts["mapped_zero_initialized_data"] = region
            row["decoded"]["initializer_range"] = {**region, "zero_initialized": nonzero is None}
            if nonzero is not None:
                addr, value = nonzero
                row["manifest_status"] = "fail"
                issue("fail", "export_initializer_nonzero", "Original mapped initializer contains nonzero data",
                      export=name, rva=hex(addr), field=["mapped_zero_initialized_data"], original=value, reported=0)
        except ValueError as exc:
            issue("inconclusive", "export_initializer_range", str(exc), export=name, rva=hex(entry))
            if row["manifest_status"] != "fail":
                row.update(status="inconclusive", manifest_status="inconclusive")
    if "ordered_u64_stores" in claim:
        row["decoded"]["ordered_u64_stores"] = len(facts["ordered_u64_stores"])
    for field, actual in facts.items():
        if field not in claim:
            continue
        declared = claim[field]
        if field in ("calls", "rip_operands") and isinstance(declared, list):
            # Those fields describe site registrations. A delivery can list them
            # out of address order. Preserve order and multiplicity for store sequences.
            if all(isinstance(_site(record), str) and re.fullmatch(r"0[xX][0-9a-fA-F]{1,16}", _site(record))
                   for record in declared):
                declared = sorted(declared, key=lambda record: int(_site(record), 16))
                if field == "calls":
                    declared, unverified = _indirect_claims(actual, declared)
                    for address, detail, value in unverified:
                        issue("inconclusive", "export_indirect_destination",
                              "Indirect destination requires evidence beyond this instruction",
                              export=name, rva=address, field=["calls", detail], reported=value)
                    if unverified and row["manifest_status"] != "fail":
                        row.update(status="inconclusive", manifest_status="inconclusive")
        mismatch = _difference(actual, declared, [field])
        if mismatch:
            path, left, right = mismatch
            rva = hex(entry)
            if len(path) > 1 and isinstance(path[1], int):
                idx = path[1]
                record = actual[idx] if idx < len(actual) else declared[idx]
                candidate = _site(record)
                if isinstance(candidate, str) and re.fullmatch(r"0[xX][0-9a-fA-F]{1,16}", candidate):
                    rva = hex(int(candidate, 16))
            if field == "mapped_zero_initialized_data":
                rva = actual["begin"]
            row["manifest_status"] = "fail"
            issue("fail", "export_manifest_mismatch", f"Incorrect {field} in evidence", export=name,
                  rva=rva, field=path, original=left, reported=right)


def _build(compiler, source, header, name):
    with tempfile.TemporaryDirectory(prefix="aspen-export-") as directory:
        tmp = Path(directory)
        (tmp / "register-forms.h").write_bytes(header)
        (tmp / "export.c").write_bytes(source)
        env = {k: v for k, v in os.environ.items() if k.upper() in
               {"SYSTEMROOT", "WINDIR", "LOCALAPPDATA", "USERPROFILE", "TEMP", "TMP"}}
        run = subprocess.run([str(compiler), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
                              "-fno-stack-protector", "-fno-asynchronous-unwind-tables", "-c",
                              "export.c", "-o", "export.obj"], cwd=tmp, env=env, stdin=subprocess.DEVNULL,
                             capture_output=True, timeout=90)
        if run.returncode:
            raise ValueError("Compiler rejected source: " + run.stderr[-1200:].decode("utf-8", "replace"))
        return _coff((tmp / "export.obj").read_bytes(), name)


def _manifest_values(checked, claim, name, row, issue):
    for field, actual in checked.items():
        reported = claim.get(field)
        if type(actual) is not type(reported) or actual != reported:
            row["manifest_status"] = "fail"
            issue("fail", "export_manifest_mismatch", f"Incorrect {field} in evidence", export=name,
                  rva=row["entry"], field=[field], original=actual, reported=reported, rebuilt=reported)


def check(original: bytes, delivery: Path, assembler: Path | None) -> dict:
    metrics = {"exports": {}, "matching_bytes": 0, "relocations": 0, "original_sha256": _digest(original)}
    findings = []
    result = {"status": "inconclusive", "scope": SCOPE, "metrics": metrics, "findings": findings}

    def issue(status, code, message, **extra):
        findings.append({"severity": status, "code": code, "message": message, **extra})

    try:
        import iced_x86 as x86
        import pefile
    except ImportError as exc:
        issue("inconclusive", "dependency", str(exc))
        return result
    try:
        root = Path(delivery).resolve(strict=True)
        evidence = json.loads(_read(root, "s5/business-evidence.json", 16 << 20),
                              object_pairs_hook=_unique_keys)
        claims = evidence["exports"]
        if not isinstance(claims, dict) or not isinstance(evidence.get("original_sha256"), str):
            raise ValueError("Invalid evidence manifest")
        if evidence["original_sha256"] != metrics["original_sha256"]:
            result["status"] = "fail"
            issue("fail", "export_original_hash", "Manifest identifies a different original",
                  original=metrics["original_sha256"], rebuilt=evidence["original_sha256"])
            return result
        pe = pefile.PE(data=original, fast_load=True)
        if pe.FILE_HEADER.Machine != 0x8664 or pe.OPTIONAL_HEADER.Magic != 0x20b:
            raise ValueError("Requires AMD64 PE32+")
        pe.parse_data_directories(directories=[0, 1, 3, 13])
        symbols = getattr(getattr(pe, "DIRECTORY_ENTRY_EXPORT", None), "symbols", [])
        if not symbols:
            raise ValueError("Missing original export directory")
        exports = {}
        for sym in symbols:
            key = sym.name.decode("ascii") if sym.name else f"#{sym.ordinal}"
            if key in exports:
                raise ValueError("Ambiguous original export name")
            exports[key] = sym
        unwind = [(u.struct.BeginAddress, u.struct.EndAddress)
                  for u in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", [])]
        exception_dir = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        if exception_dir.Size != len(unwind) * 12:
            raise ValueError("Incomplete original exception directory")
        anchors = sorted({s.address for s in symbols} | {lo for lo, hi in unwind})
    except (OSError, ValueError, KeyError, TypeError, RuntimeError, pefile.PEFormatError) as exc:
        issue("inconclusive", "export_prerequisite", str(exc))
        return result

    try:
        header = _read(root, "s5/register-forms.h", 1 << 20)
        if _digest(header) != HEADER_SHA256:
            raise ValueError("Unsupported inline-assembly macro header")
        if assembler is None:
            raise ValueError("Supply reviewed Windows Zig 0.13.0 with --assembler")
        compiler = Path(assembler).resolve(strict=True)
        if compiler.name.lower() != "zig.exe" or compiler.is_relative_to(root):
            raise ValueError("Supply the reviewed compiler outside the delivery")
        with compiler.open("rb") as stream:
            metrics["assembler_sha256"] = hashlib.file_digest(stream, "sha256").hexdigest()
        if metrics["assembler_sha256"] != ZIG_SHA256:
            raise ValueError("Compiler does not match the reviewed Zig SHA-256")
    except (OSError, ValueError, RuntimeError) as exc:
        compiler = None
        issue("inconclusive", "export_prerequisite", str(exc))

    for name in sorted(claims.keys() - exports.keys()):
        issue("fail", "export_absent", "Claimed name absent from original export table", export=name)
    counted = set()
    for name, sym in sorted(exports.items()):
        entry = sym.address
        row = {"status": "inconclusive", "rebuild_status": "inconclusive", "manifest_status": "inconclusive",
               "original_facts_status": "inconclusive", "entry": hex(entry), "matching_bytes": 0, "relocations": 0}
        metrics["exports"][name] = row
        if name not in claims or sym.forwarder or not IDENT.fullmatch(name):
            issue("inconclusive", "export_unchecked", "Export lacks a supported named source claim", export=name)
            continue
        first_finding = len(findings)
        try:
            end, basis = _extent(pe, entry, anchors, unwind, x86)
            row.update(exclusive_end=hex(end), boundary=basis)
            raw = pe.get_data(entry, end - entry)
            if len(raw) != end - entry:
                raise ValueError("Original PE range truncated")
            claim = claims[name] if isinstance(claims[name], dict) else {}
            row["manifest_status"] = "pass"
            _manifest_values({"entry": hex(entry), "exclusive_end": hex(end), "original_text_sha256": _digest(raw)},
                             claim, name, row, issue)
            try:
                _check_facts(raw, entry, pe, x86, claim, row, name, issue)
            except (ValueError, struct.error, pefile.PEFormatError) as exc:
                if row["manifest_status"] != "fail":
                    row["manifest_status"] = "inconclusive"
                issue("inconclusive", "export_facts_unverified", str(exc), export=name, rva=hex(entry))
            row["original_facts_status"] = row["manifest_status"]
            if compiler is None:
                continue
            source = _read(root, f"s5/{name}.c", 2 << 20)
            row["source_sha256"] = _digest(source)
            if not _source_supported(source, name, x86):
                raise ValueError("Unsupported editable source form")
            rebuilt, fixups = _build(compiler, source, header, name)
            mismatch = _compare(raw, rebuilt, fixups, entry, x86)
            if mismatch:
                row.update(status="fail", rebuild_status="fail")
                issue("fail", mismatch.pop("code"), "Rebuilt export differs from original", export=name, **mismatch)
                continue
            row.update(rebuild_status="pass", matching_bytes=len(raw), relocations=len(fixups))
            if entry not in counted:
                counted.add(entry)
                metrics["matching_bytes"] += len(raw)
                metrics["relocations"] += len(fixups)
            _manifest_values({"source_sha256": row["source_sha256"], "matching_bytes": len(raw),
                              "rel32": len(fixups)}, claim, name, row, issue)
        except FileNotFoundError as exc:
            row.update(status="fail", rebuild_status="fail")
            issue("fail", "export_file_missing", str(exc), export=name)
        except (OSError, ValueError, struct.error, RuntimeError, subprocess.TimeoutExpired) as exc:
            issue("inconclusive", "export_unverified", str(exc), export=name, rva=hex(entry))
        finally:
            if row["rebuild_status"] != "pass" and row["manifest_status"] != "fail":
                row["manifest_status"] = "inconclusive"
            severities = {f["severity"] for f in findings[first_finding:]}
            if "fail" in severities:
                row["status"] = "fail"
            elif row["rebuild_status"] == "pass" and "inconclusive" not in severities:
                row["status"] = "pass"
    total = evidence.get("matching_bytes")
    all_rebuilt = metrics["exports"] and all(r["rebuild_status"] == "pass" for r in metrics["exports"].values())
    if all_rebuilt and (type(total) is not int or total != metrics["matching_bytes"]):
        issue("fail", "export_manifest_total", "Incorrect total for verified original ranges",
              original=metrics["matching_bytes"], reported=total, rebuilt=total)
    if any(f["severity"] == "fail" for f in findings):
        result["status"] = "fail"
    elif not findings and metrics["exports"]:
        result["status"] = "pass"
    return result
