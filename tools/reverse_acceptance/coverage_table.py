"""Validate the project's existing coverage.csv and its evidence references."""
import csv
from bisect import bisect_right
import importlib.util
import json
import re
import struct
from pathlib import Path

if __package__:
    from .native_sites import LINE as INSTRUCTION
else:
    from native_sites import LINE as INSTRUCTION

LEGACY = Path(__file__).resolve().parents[2] / "handoff/assignments/check-native-coverage.py"
FIELDS = {"kind", "key", "state", "first_bytes", "listing", "source", "note"}
REF = re.compile(r"(.+)#L([1-9]\d*)(?:-L([1-9]\d*))?")
GROUP = re.compile(r"^\s*(?:;\s*(?:FUNC|owner)|/\*\s*-+\s*FUNC)\s+(?:0x)?([\da-fA-F]+)\b", re.I)
C_LEX = re.compile(r"""//[^\n]*|/\*[\s\S]*?(?:\*/|\Z)|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'""")


def executable_ranges(data):
    # The legacy anchor reader maps by raw section size, including file-alignment padding.
    pe = struct.unpack_from("<I", data, 0x3c)[0]
    count = struct.unpack_from("<H", data, pe + 6)[0]
    optional_size = struct.unpack_from("<H", data, pe + 20)[0]
    sections = []
    for index in range(count):
        header = pe + 24 + optional_size + 40 * index
        virtual_size, rva, raw_size, offset = struct.unpack_from("<IIII", data, header + 8)
        flags = struct.unpack_from("<I", data, header + 36)[0]
        if flags & 0x20000000:
            length = min(virtual_size or raw_size, raw_size, max(0, len(data) - offset))
            sections.append((rva, rva + length, offset))
    return sections


def entry_window(data, key, filepos, sections):
    pos = filepos(key, True)
    ends = [end for start, end, offset in sections
            if start <= key < end and offset + key - start == pos]
    if len(ends) != 1:
        raise ValueError(f"RVA {key:#x} has no unique file-backed executable mapping")
    length = min(15, ends[0] - key)
    for delta in range(1, length):
        try:
            if filepos(key + delta, True) != pos + delta:
                length = delta
                break
        except ValueError:
            length = delta
            break
    return data[pos:pos + length]


def check(original, files):
    findings = []
    def note(status, code, **detail):
        findings.append(dict(status=status, code=code, **detail))

    try:
        with files["coverage.csv"].open(encoding="utf-8-sig", newline="") as f:
            reader = csv.DictReader(f, strict=True)
            header = reader.fieldnames or []
            if len(header) != len(set(header)) or not FIELDS <= set(header):
                raise ValueError("coverage.csv does not have the handoff coverage columns")
            rows = list(reader)
        if not rows:
            note("fail", "empty_coverage")
    except (OSError, UnicodeError, ValueError, csv.Error) as exc:
        return dict(scope="handoff_coverage", status="fail", findings=[dict(status="fail", code="invalid_coverage_csv", message=str(exc))], metrics={})
    expected = {}
    filepos = None
    imagebase = 0
    try:
        spec = importlib.util.spec_from_file_location("aspen_repo_anchors", LEGACY)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        records, original_filepos, imagebase = module.inspect(original)
        sections = executable_ranges(original)
        filepos = original_filepos
        expected = {(r["kind"], r["key"]): r for r in records}
    except (ValueError, OSError, ImportError, KeyError, IndexError, UnicodeError, struct.error) as exc:
        note("inconclusive", "original_anchor_profile_unavailable", message=str(exc))

    tool_keys = set()
    if "native-functions.csv" in files:
        try:
            with files["native-functions.csv"].open(encoding="utf-8-sig", newline="") as stream:
                reader = csv.DictReader(stream, strict=True)
                fields = reader.fieldnames or []
                if len(fields) != len(set(fields)) or not {"rva", "name"} <= set(fields):
                    raise ValueError("required native-functions.csv columns: rva, name")
                for line, row in enumerate(reader, 2):
                    if None in row or None in row.values() or not row["name"].strip():
                        raise ValueError(f"invalid native-functions.csv row {line}")
                    addr = int(row["rva"], 0)
                    if addr < 0 or ("native", addr) in tool_keys:
                        raise ValueError(f"invalid or duplicate native-functions.csv RVA {addr:#x} at line {line}")
                    if filepos:
                        filepos(addr, True)
                    tool_keys.add(("native", addr))
            if not tool_keys:
                note("fail", "empty_native_discovery")
            if "run.json" in files:
                run = json.loads(files["run.json"].read_text(encoding="utf-8-sig"))
                count = run.get("native_reported_count") if isinstance(run, dict) else None
                if type(count) is not int or count != len(tool_keys):
                    note("fail", "native_discovery_count_mismatch", declared=count, registered=len(tool_keys))
        except (OSError, UnicodeError, ValueError, csv.Error) as exc:
            note("fail", "invalid_native_discovery", message=str(exc))
    elif any(r["kind"] == "native" for r in rows) or any(k[0] == "native" for k in expected):
        note("fail", "missing_native_discovery", path="native-functions.csv")

    decoder = None
    if filepos and any(r["kind"] == "native" and r["state"] == "covered" for r in rows):
        try:
            from iced_x86 import Decoder
            decoder = Decoder
        except ImportError as exc:
            note("inconclusive", "instruction_decoder_unavailable", message=str(exc))

    buffers = {}
    source_lines = {}
    asm_index = {}
    groups = {}
    owners_checked = 0
    def owner_rows(name):
        if name not in groups:
            marks = [(i, int(m[1], 16)) for i, line in enumerate(buffers[name], 1) if (m := GROUP.match(line))]
            groups[name] = ([i for i, _ in marks], [rva for _, rva in marks])
        return groups[name]

    def owner_at(name, line):
        positions, owners = owner_rows(name)
        index = bisect_right(positions, line) - 1
        return owners[index] if index >= 0 else None

    def evidence(ref, allowed, column, kind, key, entry_bytes):
        nonlocal owners_checked
        match = REF.fullmatch(ref)
        if match is None:
            return "malformed line reference"
        name, first, last = match.groups()
        name = name.replace("\\", "/")
        if name not in files or Path(name).suffix.lower() not in allowed:
            return "missing or wrong evidence file"
        if name not in buffers:
            buffers[name] = files[name].read_text(encoding="utf-8-sig").splitlines()
        lines = buffers[name]
        start, end = int(first), int(last or first)
        if not 1 <= start <= end <= len(lines):
            return "line range outside file"
        if not any(line.strip() for line in lines[start-1:end]):
            return "empty evidence range"
        if column == "listing" and kind == "native":
            if name not in asm_index:
                index = {}
                for num, line in enumerate(lines, 1):
                    m = INSTRUCTION.match(line)
                    if m:
                        index.setdefault(int(m[1], 16), []).append((num, bytes.fromhex(m[2])))
                asm_index[name] = index
            matches = [(num, raw) for addr in {key, imagebase + key} for num, raw in asm_index[name].get(addr, ())
                       if start <= num <= end]
            if not matches:
                return "range lacks the stated original instruction address and bytes"
            for num, raw in matches:
                if entry_bytes is not None:
                    length = min(len(raw), len(entry_bytes))
                    if raw[:length] != entry_bytes[:length]:
                        offset = next(i for i in range(length) if raw[i] != entry_bytes[i])
                        return (f"{name}#L{num} at RVA {key + offset:#x}: displayed {raw[offset]:02x}, "
                                f"{'original' if filepos else 'coverage table'} {entry_bytes[offset]:02x}")
                    if filepos:
                        if not raw or len(raw) > len(entry_bytes):
                            return f"{name}#L{num} exceeds original instruction bytes"
                        if decoder:
                            instruction = decoder(64, entry_bytes, ip=key).decode()
                            if instruction.is_invalid or instruction.len != len(raw):
                                return f"{name}#L{num} does not display exactly one original instruction"
                listing_owners.add(owner_at(name, num))
        if column == "listing" and kind in {"type", "method"}:
            excerpt = "\n".join(lines[start-1:end])
            if not re.search(rf"(?<![a-zA-Z0-9])(?:0x)?0*{key:x}(?![a-zA-Z0-9])", excerpt, re.I):
                return "range lacks the stated CLR token"
        if column == "source":
            suffix = Path(name).suffix.lower()
            if name not in source_lines:
                # A reference may begin inside a block comment. Preserve original line numbers.
                cleaned = C_LEX.sub(lambda m: " " + "\n" * m[0].count("\n")
                                    if m[0].startswith(("//", "/*")) else m[0], "\n".join(lines))
                source_lines[name] = cleaned.split("\n")
            code = "\n".join(source_lines[name][start-1:end])
            if suffix in {".il", ".asm", ".s"}:
                code = "\n".join(line for line in code.splitlines() if not line.lstrip().startswith((";", "# ")))
            if not code.strip() or not any(ch.isalnum() for ch in code):
                return "range contains only comments, punctuation or whitespace"
            # When both existing artifacts mark functions, compare their actual ranges.
            # Interior unwind anchors may legitimately share their parent's implementation.
            if kind == "native" and listing_owners - {None} and owner_rows(name)[0]:
                source_owner = owner_at(name, end)
                first_owner = owner_at(name, start)
                if first_owner != source_owner or source_owner not in listing_owners - {None}:
                    return "source range does not belong to the function containing the listed anchor"
                owners_checked += 1
        return None

    seen = set()
    for line, row in enumerate(rows, 2):
        if None in row or None in row.values():
            note("fail", "malformed_coverage_row", line=line)
            continue
        kind, state = row["kind"], row["state"]
        try:
            key = int(row["key"], 0)
            if kind not in {"native", "type", "method"} or key < 0:
                raise ValueError
        except ValueError:
            note("fail", "invalid_coverage_key", line=line)
            continue
        tag = (kind, key)
        detail = dict(kind=kind, key=hex(key), line=line)
        if tag in seen:
            note("fail", "duplicate_coverage_key", **detail)
        seen.add(tag)
        if kind == "native" and filepos and "native-functions.csv" in files and tag not in expected and tag not in tool_keys:
            note("fail", "unregistered_native_coverage_key", **detail)
        if state == "gap":
            note("fail", "declared_coverage_gap", detail=row["note"], **detail)
            continue
        if state not in {"declaration", "covered"}:
            note("fail", "invalid_coverage_state", **detail)
            continue
        if state == "declaration" and (kind != "method" or expected.get(tag, {}).get("rva")):
            note("fail", "declaration_conflicts_with_body", **detail)
        if tag in expected and kind == "method" and not expected[tag]["rva"] and state != "declaration":
            note("fail", "body_claim_for_declaration", **detail)
        if kind in {"type", "method"} and filepos and tag not in expected:
            note("fail", "unexpected_metadata_token", **detail)
        entry_bytes = None
        if kind == "native" and filepos:
            try:
                entry_bytes = entry_window(original, key, filepos, sections)
                claimed = row["first_bytes"].lower()
                if not re.fullmatch(r"[0-9a-f]{16}", claimed) or not claimed.startswith(entry_bytes[:8].hex()):
                    note("fail", "original_anchor_bytes_differ", **detail)
                elif len(entry_bytes) < 8:
                    note("inconclusive", "original_anchor_window_short", required_bytes=8,
                         mapped_bytes=len(entry_bytes), **detail)
            except ValueError as exc:
                note("fail", "invalid_native_rva", message=str(exc), **detail)
        elif kind == "native" and re.fullmatch(r"(?:[0-9a-fA-F]{2}){1,8}", row["first_bytes"]):
            entry_bytes = bytes.fromhex(row["first_bytes"])
        listing_owners = set()
        for column, suffixes in (("listing", {".asm", ".il", ".txt", ".lst"}),
                                 ("source", {".c", ".cpp", ".h", ".hpp", ".cs", ".il", ".s", ".asm"})):
            reason = evidence(row[column], suffixes, column, kind, key, entry_bytes)
            if reason:
                note("fail", "coverage_reference_invalid", column=column, ref=row[column], message=reason, **detail)
    for kind, key in sorted(expected.keys() - seen):
        note("fail", "original_anchor_missing", kind=kind, key=hex(key))
    for kind, key in sorted(tool_keys - seen - expected.keys()):
        note("fail", "discovered_native_entry_missing", kind=kind, key=hex(key), path="native-functions.csv")
    statuses = {f["status"] for f in findings}
    return dict(scope="handoff_coverage_keys_original_anchor_bytes_and_evidence_ranges",
                status="fail" if "fail" in statuses else "inconclusive" if statuses else "pass",
                findings=findings, metrics=dict(rows=len(rows), unique_keys=len(seen), original_anchors=len(expected),
                                                discovered_native_entries=len(tool_keys),
                                                additional_discovered_native_entries=len(tool_keys - expected.keys()),
                                                declared_entry_gaps=sum(f["code"] == "declared_coverage_gap" and
                                                                        f.get("kind") == "native" for f in findings),
                                                matched_marked_source_owners=owners_checked))
