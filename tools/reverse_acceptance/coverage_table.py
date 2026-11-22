"""Validate the project's existing coverage.csv and its evidence references."""
import csv
from bisect import bisect_right
import importlib.util
import re
import struct
from pathlib import Path

LEGACY = Path(__file__).resolve().parents[2] / "handoff/assignments/check-native-coverage.py"
FIELDS = {"kind", "key", "state", "first_bytes", "listing", "source", "note"}
REF = re.compile(r"(.+)#L([1-9]\d*)(?:-L([1-9]\d*))?")
INST = re.compile(r"^\s*(?:0x)?([\da-fA-F]{4,16})\s*:?\s+([\da-fA-F]{2})(?=\s|$)")
GROUP = re.compile(r"^\s*(?:;\s*(?:FUNC|owner)|/\*\s*-+\s*FUNC)\s+(?:0x)?([\da-fA-F]+)\b", re.I)
C_LEX = re.compile(r"""//[^\n]*|/\*[\s\S]*?(?:\*/|\Z)|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'""")


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
    except (UnicodeError, ValueError, csv.Error) as exc:
        return dict(scope="handoff_coverage", status="fail", findings=[dict(code="invalid_coverage_csv", message=str(exc))], metrics={})
    expected = {}
    filepos = None
    imagebase = 0
    try:
        spec = importlib.util.spec_from_file_location("aspen_repo_anchors", LEGACY)
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
        records, filepos, imagebase = module.inspect(original)
        expected = {(r["kind"], r["key"]): r for r in records}
    except (ValueError, OSError, ImportError, KeyError, IndexError, UnicodeError, struct.error) as exc:
        note("inconclusive", "original_anchor_profile_unavailable", message=str(exc))

    buffers = {}
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

    def evidence(ref, allowed, column, kind, key, first_byte):
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
                    m = INST.match(line)
                    if m:
                        index.setdefault(int(m[1], 16), []).append((num, m[2].lower()))
                asm_index[name] = index
            matches = [num for addr in {key, imagebase + key} for num, byte in asm_index[name].get(addr, ())
                       if start <= num <= end and byte == first_byte]
            if not matches:
                return "range lacks the stated original instruction address and byte"
            listing_owners.update(owner_at(name, num) for num in matches)
        if column == "listing" and kind in {"type", "method"}:
            excerpt = "\n".join(lines[start-1:end])
            if not re.search(rf"(?<![a-zA-Z0-9])(?:0x)?0*{key:x}(?![a-zA-Z0-9])", excerpt, re.I):
                return "range lacks the stated CLR token"
        if column == "source":
            excerpt = "\n".join(lines[start-1:end])
            suffix = Path(name).suffix.lower()
            code = C_LEX.sub(lambda m: "" if m[0].startswith(("//", "/*")) else m[0], excerpt)
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
        if kind == "native" and filepos:
            try:
                pos = filepos(key, True)
                if len(original[pos:pos+8]) != 8 or original[pos:pos+8].hex() != row["first_bytes"].lower():
                    note("fail", "original_anchor_bytes_differ", **detail)
            except ValueError as exc:
                note("fail", "invalid_native_rva", message=str(exc), **detail)
        listing_owners = set()
        for column, suffixes in (("listing", {".asm", ".il", ".txt", ".lst"}),
                                 ("source", {".c", ".cpp", ".h", ".hpp", ".cs", ".il", ".s", ".asm"})):
            reason = evidence(row[column], suffixes, column, kind, key, row["first_bytes"].lower()[:2])
            if reason:
                note("fail", "coverage_reference_invalid", column=column, ref=row[column], message=reason, **detail)
    for kind, key in sorted(expected.keys() - seen):
        note("fail", "original_anchor_missing", kind=kind, key=hex(key))
    statuses = {f["status"] for f in findings}
    return dict(scope="handoff_coverage_keys_original_anchor_bytes_and_evidence_ranges",
                status="fail" if "fail" in statuses else "inconclusive" if statuses else "pass",
                findings=findings, metrics=dict(rows=len(rows), unique_keys=len(seen), original_anchors=len(expected),
                                                matched_marked_source_owners=owners_checked))
