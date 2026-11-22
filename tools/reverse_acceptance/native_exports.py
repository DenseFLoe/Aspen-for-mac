"""Rebuild restricted AMD64 inline-assembly C exports and compare their original PE ranges."""
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
         "Verifies fresh COFF code and REL32 operands; whole-file coverage is assessed separately.")
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
        pe.parse_data_directories(directories=[0, 3])
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
    except (OSError, ValueError, KeyError, TypeError, RuntimeError, pefile.PEFormatError) as exc:
        issue("inconclusive", "export_prerequisite", str(exc))
        return result

    for name in sorted(claims.keys() - exports.keys()):
        issue("fail", "export_absent", "Claimed name absent from original export table", export=name)
    counted = set()
    for name, sym in sorted(exports.items()):
        entry = sym.address
        row = {"status": "inconclusive", "entry": hex(entry), "matching_bytes": 0, "relocations": 0}
        metrics["exports"][name] = row
        if name not in claims or sym.forwarder or not IDENT.fullmatch(name):
            issue("inconclusive", "export_unchecked", "Export lacks a supported named source claim", export=name)
            continue
        try:
            end, basis = _extent(pe, entry, anchors, unwind, x86)
            row.update(exclusive_end=hex(end), boundary=basis)
            raw = pe.get_data(entry, end - entry)
            if len(raw) != end - entry:
                raise ValueError("Original PE range truncated")
            source = _read(root, f"s5/{name}.c", 2 << 20)
            row["source_sha256"] = _digest(source)
            if not _source_supported(source, name, x86):
                raise ValueError("Unsupported editable source form")
            rebuilt, fixups = _build(compiler, source, header, name)
            mismatch = _compare(raw, rebuilt, fixups, entry, x86)
            if mismatch:
                row["status"] = "fail"
                issue("fail", mismatch.pop("code"), "Rebuilt export differs from original", export=name, **mismatch)
                continue
            row.update(status="pass", matching_bytes=len(raw), relocations=len(fixups))
            if entry not in counted:
                counted.add(entry)
                metrics["matching_bytes"] += len(raw)
                metrics["relocations"] += len(fixups)
            checked = {"entry": hex(entry), "exclusive_end": hex(end), "source_sha256": _digest(source),
                       "original_text_sha256": _digest(raw), "matching_bytes": len(raw), "rel32": len(fixups)}
            claim = claims[name]
            for field, actual in checked.items():
                reported = claim.get(field) if isinstance(claim, dict) else None
                if type(actual) is not type(reported) or actual != reported:
                    row["status"] = "fail"
                    issue("fail", "export_manifest_mismatch", f"Incorrect {field} in evidence", export=name,
                          rva=hex(entry), original=actual, rebuilt=reported)
        except FileNotFoundError as exc:
            row["status"] = "fail"
            issue("fail", "export_file_missing", str(exc), export=name)
        except (OSError, ValueError, struct.error, RuntimeError, subprocess.TimeoutExpired) as exc:
            issue("inconclusive", "export_unverified", str(exc), export=name, rva=hex(entry))
    if not findings and evidence.get("matching_bytes") != metrics["matching_bytes"]:
        issue("fail", "export_manifest_total", "Incorrect total for verified original ranges",
              original=metrics["matching_bytes"], rebuilt=evidence.get("matching_bytes"))
    if any(f["severity"] == "fail" for f in findings):
        result["status"] = "fail"
    elif not findings and metrics["exports"]:
        result["status"] = "pass"
    return result
