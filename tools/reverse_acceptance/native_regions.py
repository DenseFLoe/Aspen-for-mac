"""Rebuild declared internal AMD64 PE ranges from supported inline assembly deliveries."""
from collections import Counter
import json
from pathlib import Path
import re
import struct
import subprocess

if __package__:
    from . import native_exports as build
else:
    import native_exports as build

HOST_MANIFEST = "s13/callee-evidence.json"
DELTA_MANIFEST = "s13/reassembly-delta.json"
# Macro definitions are executable compiler input. Accept reviewed versions only.
HOST_HEADER = "d6c8d9ecdc38d7dff3e1a1eeb94651c6dfc48cc57f93ca91531bccf188f3b28d"
CHUNK_PRELUDE = "a41be1a4c411efff7a7031dc52e7b13b0b7c850d2c6b988d25507080733728d9"
CHUNK_MACRO = "7bbf88429c210afd45c0fe6d9a2be181f5e4f609c24cd9bdd1bd9959c0c169d8"
INCLUDE = re.compile(r'#include "(verified-[0-9]+\.h)"\n')
RVA = re.compile(r"0x[0-9a-f]{1,8}", re.I)
COMMENT = re.compile(r" /\* [0-9a-fA-F]{4,8} \*/$")
LABEL = re.compile(r"\.L[A-Za-z0-9_]+")
INSTRUCTION = re.compile(r"([a-z][a-z0-9]*)(?: [a-zA-Z0-9_., +*\[\]-]+)?")
HOST_MACRO = re.compile(r"S9_(?:(?:JMP|JA|JBE|JE|JGE|JLE|JNE)32\(\.L[A-Za-z0-9_]+\)|NOP(?:2|4|5|6|7|8|10|11|12|14))")
REG_PAIR = r"reg_[A-Za-z0-9]+, reg_[A-Za-z0-9]+"
CHUNK_CALL = re.compile(rf"(?:ikc_(?:mov64|xor8|xor32)_load {REG_PAIR}|ikc_s13_reg 0x[0-9a-f]{{1,2}}, (?:32|64), {REG_PAIR})")


def _rva(value):
    if not isinstance(value, str) or not RVA.fullmatch(value):
        raise ValueError("Expected an RVA in hexadecimal")
    return int(value, 16)


def _block(body, x86, chunk=False):
    """Re-emit single assembly statements, excluding comments and other source text."""
    lines = []
    for raw in body.splitlines():
        line = COMMENT.sub("", raw.strip())
        if not line:
            continue
        if not chunk and HOST_MACRO.fullmatch(line):
            lines.append(line)
            continue
        if not line.startswith('"') or not line.endswith('\\n"'):
            raise ValueError("Unsupported statement in reviewed inline assembly wrapper")
        statement = line[1:-3].strip()
        op = INSTRUCTION.fullmatch(statement)
        if (not (LABEL.fullmatch(statement.removesuffix(":")) and statement.endswith(":"))
                and not (chunk and CHUNK_CALL.fullmatch(statement))
                and not (op and op[1] not in {"db", "dw", "dd", "dq"}
                         and (op[1] == "movabs" or hasattr(x86.Mnemonic, op[1].upper())))):
            raise ValueError("Unsupported inline assembly statement: " + statement[:100])
        lines.append(f'"{statement}\\n"')
    if not lines:
        raise ValueError("Empty inline assembly body")
    return "\n".join(lines)


def _host_source(root, name, entry, x86):
    header = build._read(root, "s13/host-encoding.h", 1 << 20)
    if build._digest(header) != HOST_HEADER:
        raise ValueError("Unsupported host-encoding macro header")
    src = build._read(root, f"s13/{name}.c", 2 << 20)
    text = src.decode("ascii").replace("\r\n", "\n")
    # Verify the original alias syntax, then compile only the named body.
    wrapper = re.fullmatch(
        r'#include "host-encoding\.h"\n\s*(?:/\* [A-Za-z0-9_:., ()-]+ \*/\s*)?'
        r'__asm__\("\.globl (rva_[0-9a-f]+)\\n\.set \1, ([A-Za-z_]\w*)\\n"\);\n'
        r'NAKED void \2\(void\) \{\n[ \t]*__asm__\(START\n(?P<body>.*?)^[ \t]*END\);\n\}\s*',
        text, re.ASCII | re.DOTALL | re.MULTILINE)
    if not wrapper or wrapper[1] != f"rva_{entry:x}" or wrapper[2] != name:
        raise ValueError("Unsupported host source wrapper or entry alias")
    body = _block(wrapper["body"], x86)
    source = f'NAKED void {name}(void) {{\n__asm__(START\n{body}\nEND);\n}}\n'
    return f"s13/{name}.c", src, ("#include \"register-forms.h\"\n" + source).encode("ascii"), header


def _chunk_sources(root):
    unit = build._read(root, "code/verified.c", 1 << 20).decode("ascii").replace("\r\n", "\n")
    prelude, sep, tail = unit.partition("#include ")
    includes = INCLUDE.findall(sep + tail)
    if (build._digest(prelude.encode("ascii")) != CHUNK_PRELUDE or not includes or len(includes) > 64
            or len(set(includes)) != len(includes) or INCLUDE.sub("", sep + tail).strip()):
        raise ValueError("Unsupported verified.c macro prelude or include list")
    return prelude, {
        name: build._read(root, f"code/{name}", 4 << 20).decode("ascii").replace("\r\n", "\n")
        for name in includes}


def _chunk_source(chunks, name, entry, end, x86):
    prelude, includes = chunks
    wrapper = re.compile(
        rf"/\* body (0x[0-9a-f]+) until (0x[0-9a-f]+) \*/\nBODY void {re.escape(name)}\(void\) \{{\n"
        r"[ \t]*__asm__\(INTEL\n(?P<body>.*?)^[ \t]*END\);\n\}", re.DOTALL | re.MULTILINE)
    found = [(file, text, match) for file, text in includes.items() for match in wrapper.finditer(text)]
    if len(found) != 1:
        raise ValueError("Expected one editable chunk body at the submitted RVA")
    file, text, match = found[0]
    if (_rva(match[1]), _rva(match[2])) != (entry, end):
        raise ValueError("Chunk body comment disagrees with the original PE extent")
    macro = text.partition("/* body ")[0]
    if build._digest(macro.encode("ascii")) != CHUNK_MACRO:
        raise ValueError("Unsupported chunk macro prelude")
    body = _block(match["body"], x86, chunk=True)
    source = f"{prelude}{macro}BODY void {name}(void) {{\n__asm__(INTEL\n{body}\nEND);\n}}\n"
    return f"code/{file}", match[0].encode("ascii"), source.encode("ascii"), None


def _claims(doc, delta):
    if not delta:
        rows = doc["hosts"]
        if not isinstance(rows, dict):
            raise ValueError("hosts must map symbols to their claims")
        return [(name, match, _rva(match["entry"])) for name, match in rows.items()]
    rows = doc["matches"]
    if not isinstance(rows, list):
        raise ValueError("matches must be an array")
    entries = [(_rva(match["rva"]), match) for match in rows]
    return [(f"ikc_{entry:x}", match, entry) for entry, match in entries]


def _fields(claim, expected):
    for key, value in expected.items():
        given = claim.get(key)
        if type(given) is not type(value) or given != value:
            yield {"field": key, "original": value, "reported": given}


def check(original: bytes, delivery: Path, assembler: Path | None) -> dict:
    metrics = {"original_sha256": build._digest(original), "matching_bytes": 0,
               "matching_instructions": 0, "relocations": 0, "regions": []}
    findings = []
    result = {"status": "inconclusive", "scope": "Internal AMD64 PE ranges rebuilt from declared editable assembly",
              "metrics": metrics, "findings": findings}

    def issue(severity, code, message, **detail):
        findings.append(dict(severity=severity, code=code, message=message, **detail))

    try:
        import iced_x86 as x86
        import pefile
    except ImportError as exc:
        issue("inconclusive", "dependency", str(exc))
        return result
    root = delivery.resolve()
    paths = [name for name in (HOST_MANIFEST, DELTA_MANIFEST) if (root / name).is_file()]
    manifests = {}
    pending = []
    for path in paths:
        try:
            doc = json.loads(build._read(root, path, 4 << 20), object_pairs_hook=build._unique_keys)
            if doc["original_sha256"] != metrics["original_sha256"]:
                issue("fail", "region_original_hash", "Manifest identifies a different original", listing=path,
                      original=metrics["original_sha256"], reported=doc["original_sha256"])
                continue
            claims = _claims(doc, path == DELTA_MANIFEST)
            if not 0 < len(claims) <= 128:
                raise ValueError("Expected between 1 and 128 declared internal functions")
            pending.extend((path, *claim) for claim in claims)
            manifests[path] = doc
        except (OSError, ValueError, KeyError, TypeError, RuntimeError) as exc:
            issue("fail", "region_manifest_invalid", str(exc), listing=path)
    if not pending:
        if findings:
            result["status"] = "fail"
        return result

    try:
        pe = pefile.PE(data=original, fast_load=True)
        if (pe.FILE_HEADER.Machine, pe.OPTIONAL_HEADER.Magic) != (0x8664, 0x20b):
            raise ValueError("Requires AMD64 PE32+")
        pe.parse_data_directories(directories=[3, 5])
        unwind = [(u.struct.BeginAddress, u.struct.EndAddress)
                  for u in getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())]
        dirs = pe.OPTIONAL_HEADER.DATA_DIRECTORY
        if len(dirs) <= 5 or dirs[3].Size != len(unwind) * 12 or not unwind:
            raise ValueError("Incomplete original exception directory")
        relocs = getattr(pe, "DIRECTORY_ENTRY_BASERELOC", ())
        if dirs[5].VirtualAddress and sum(block.struct.SizeOfBlock for block in relocs) != dirs[5].Size:
            raise ValueError("Incomplete original PE base relocation directory")
        loader_patches = {rel.rva for block in relocs for rel in block.entries if rel.type}
        anchors = sorted({lo for lo, _ in unwind})
    except (ValueError, RuntimeError, pefile.PEFormatError) as exc:
        issue("inconclusive", "region_original_unverified", str(exc))
        if any(f["severity"] == "fail" for f in findings):
            result["status"] = "fail"
        return result
    try:
        compiler = build._reviewed_compiler(assembler, root, metrics)
    except (OSError, ValueError, RuntimeError) as exc:
        compiler = None
        issue("inconclusive", "region_compiler_unverified", str(exc))

    occurrences = Counter(entry for _, _, _, entry in pending)
    grouped = {p: [] for p in manifests}
    try:
        chunks = _chunk_sources(root) if DELTA_MANIFEST in manifests else None
    except (OSError, ValueError, RuntimeError) as exc:
        chunks = None
        issue("inconclusive", "region_chunk_source_unverified", str(exc), listing=DELTA_MANIFEST)
    for path, name, claim, entry in sorted(pending, key=lambda record: (record[3], record[1])):
        delta = path == DELTA_MANIFEST
        row = dict(name=name, entry=hex(entry), listing=path, status="inconclusive", rebuild_status="inconclusive",
                   matching_bytes=0, relocations=0)
        metrics["regions"].append(row)
        grouped[path].append(row)
        location = dict(region=name, listing=path)
        if occurrences[entry] != 1 or not build.IDENT.fullmatch(name):
            row["status"] = "fail"
            issue("fail", "region_identity", "Duplicate entry or invalid symbol in the manifest", rva=hex(entry), **location)
            continue
        begin = len(findings)
        try:
            if entry not in anchors:
                raise ValueError("Claimed entry lacks an original RUNTIME_FUNCTION record")
            end, basis = build._extent(pe, entry, anchors, unwind, x86)
            row.update(exclusive_end=hex(end), boundary=basis)
            if not 0 < end - entry <= 1 << 20:
                raise ValueError("Original function extent is empty or exceeds the supported size")
            if any(entry - 7 <= rva < end for rva in loader_patches):
                raise ValueError("Original range overlaps a PE loader relocation")
            raw = pe.get_data(entry, end - entry)
            if len(raw) != end - entry:
                raise ValueError("Original extent lacks file bytes")
            instructions = list(x86.Decoder(64, raw, ip=entry))
            if any(i.is_invalid for i in instructions):
                raise ValueError("Original range contains an undecodable instruction")
            count = len(instructions)
            original_hash = build._digest(raw)
            expected = (dict(bytes=len(raw), sha256=original_hash) if delta else
                        dict(exclusive_end=hex(end), original_text_sha256=original_hash, instructions=count))
            row.update(original_text_sha256=original_hash, instructions=count)
            for difference in _fields(claim, expected):
                issue("fail", "region_manifest_fact", "Declared original range evidence differs", **difference, **location)
            if compiler is None or delta and chunks is None:
                continue
            file, src, source, header = (_chunk_source(chunks, name, entry, end, x86) if delta else
                                         _host_source(root, name, entry, x86))
            row.update(source=file, compiled_input_sha256=build._digest(source))
            if delta:
                row["source_slice_sha256"] = build._digest(src)
            else:
                row.update(source_sha256=build._digest(src), macro_header_sha256=build._digest(header))
            rebuilt, rels = build._build(compiler, source, header, name, build.QUALIFIED_RVA_SYMBOL)
            mismatch = build._compare(raw, rebuilt, rels, entry, x86)
            if mismatch:
                row["rebuild_status"] = "fail"
                code = mismatch.pop("code").replace("export_", "region_", 1)
                issue("fail", code, "Rebuilt internal range differs from the original", **mismatch, **location)
                continue
            actual_relocs = [[hex(entry + offset), hex(int(symbol.rsplit("rva_", 1)[1], 16)), kind]
                             for offset, symbol, kind in sorted(rels)]
            row.update(rebuild_status="pass", matching_bytes=len(raw), relocations=len(rels),
                       relocation_fields=actual_relocs)
            metrics["matching_bytes"] += len(raw)
            metrics["matching_instructions"] += count
            metrics["relocations"] += len(rels)
            production = (dict(relocations=actual_relocs) if delta else
                          dict(source_sha256=row["source_sha256"], rebuilt_text_sha256=original_hash,
                               matching_bytes=len(raw), rel32=len(rels)))
            for difference in _fields(claim, production):
                issue("fail", "region_manifest_fact", "Declared rebuild evidence differs", **difference, **location)
        except FileNotFoundError as exc:
            issue("fail", "region_source_missing", str(exc), **location)
        except (ValueError, OSError, RuntimeError, struct.error, subprocess.TimeoutExpired) as exc:
            issue("inconclusive", "region_unverified", str(exc), rva=hex(entry), **location)
        finally:
            levels = {finding["severity"] for finding in findings[begin:]}
            if "fail" in levels:
                row["status"] = "fail"
            elif row["rebuild_status"] == "pass" and not levels:
                row["status"] = "pass"

    for path, rows in grouped.items():
        if rows and all(r["rebuild_status"] == "pass" for r in rows):
            size = sum(r["matching_bytes"] for r in rows)
            relocs = sum(r["relocations"] for r in rows)
            expected = (dict(bytes=size, relocations=relocs, bodies=len(rows)) if path == DELTA_MANIFEST else
                        dict(matched_bytes=size, checked_rel32=relocs, matched_instructions=sum(r["instructions"] for r in rows)))
            for difference in _fields(manifests[path], expected):
                issue("fail", "region_manifest_total", "Declared total differs from verified ranges",
                      listing=path, **difference)
    if any(f["severity"] == "fail" for f in findings):
        result["status"] = "fail"
    elif not findings and all(r["status"] == "pass" for r in metrics["regions"]):
        result["status"] = "pass"
    return result
