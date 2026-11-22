"""Check native/mixed coverage evidence for the SHA-pinned repair inputs."""
import argparse
import csv
import hashlib
import json
import re
import struct
import sys
from pathlib import Path
from urllib.request import urlopen


ROOT = Path(__file__).resolve().parents[2]
BASE = "https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/64670801de54e990f975aaeda06e89340c0e4e08/issue-materials"
INPUTS = {
    "NATIVE-350": (
        "https://raw.githubusercontent.com/DenseFLoe/Aspen-for-mac/ad53650f6071f83b133ede7bf847bc5096cd3b56/%E7%AD%89%E5%BE%85%E9%93%81%E5%A4%B4%E7%8C%AB/Plus/%5BProgramFiles64Folder%5D/AspenTech/Aspen%20Plus%20V15.0/Engine/Xeq/zedstwu.dll",
        "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b",
    ),
    "NATIVE-349": ("349/Ikc2Bkp.dll", "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011"),
    "NATIVE-337": ("337/FindComponent.dll", "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"),
    "NATIVE-338": ("338/Happ.dll", "7d4964f25cee38127a0b68fd3c0360c79c030f4c6ed24aa2d2e50b68e008936a"),
    "NATIVE-341": ("341/mmstruct.dll", "bb9a2422bffe3a6aaa6c2a533ef7b4ef25d14092560d519bc93b94e216ce4870"),
    "NATIVE-342": ("342/ApwnIPShell.dll", "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"),
    "NATIVE-346": ("346/ppexec.dll", "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"),
    "NATIVE-344": ("344/Simdll.dll", "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601"),
    "NATIVE-340": ("340/WrapSaveMergeNNFiles.dll", "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"),
}


def require(ok, why):
    if not ok:
        raise ValueError(why)


def integer(data, offset, size=4):
    return int.from_bytes(data[offset:offset + size], "little")


def cstring(data, start):
    return data[start:data.index(b"\0", start)].decode("utf-8")


def metadata(data, offset):
    """Decode TypeDef and MethodDef from this pinned CLI compressed tables stream."""
    require(data[offset:offset + 4] == b"BSJB", "CLI metadata signature")
    pos = offset + 16 + integer(data, offset + 12)
    streams = {}
    count = integer(data, pos + 2, 2)
    pos += 4
    for _ in range(count):
        rel, size = struct.unpack_from("<II", data, pos)
        name = cstring(data, pos + 8)
        streams[name] = data[offset + rel:offset + rel + size]
        pos += 8 + ((len(name) + 4) // 4) * 4
    table, strings = streams["#~"], streams["#Strings"]
    heaps = table[6]
    s, g, b = [4 if heaps & bit else 2 for bit in (1, 2, 4)]
    valid = integer(table, 8, 8)
    counts = [0] * 64
    pos = 24
    for i in range(64):
        if valid & (1 << i):
            counts[i] = integer(table, pos)
            pos += 4
    def index(i):
        return 4 if counts[i] >= 65536 else 2
    def coded(bits, tables):
        return 4 if max(counts[i] for i in tables) >= (1 << (16 - bits)) else 2
    sizes = [2 + s + g * 3, coded(2, [0, 26, 35, 1]) + s * 2,
             4 + s * 2 + coded(2, [2, 1, 27]) + index(4) + index(6),
             index(4), 2 + s + b, index(6), 8 + s + b + index(8)]
    starts = []
    for i, size in enumerate(sizes):
        starts.append(pos)
        pos += counts[i] * size
    require(not counts[5], "Unexpected MethodPtr table")
    records = []
    for i in range(counts[2]):
        pos = starts[2] + i * sizes[2]
        name = cstring(strings, integer(table, pos + 4, s))
        namespace = cstring(strings, integer(table, pos + 4 + s, s))
        token = 0x02000001 + i
        records.append(dict(kind="type", key=token, name=(namespace + "." if namespace else "") + name))
    for i in range(counts[6]):
        pos = starts[6] + i * sizes[6]
        rva = integer(table, pos)
        flavor = ("IL", "native", "OPTIL", "runtime")[integer(table, pos + 4, 2) & 3]
        name = cstring(strings, integer(table, pos + 8, s))
        records.append(dict(kind="method", key=0x06000001 + i, name=name, rva=rva, flavor=flavor))
    return records


def inspect(data):
    header = integer(data, 60)
    optional = header + 24
    require(data[header:header + 4] == b"PE\0\0" and integer(data, header + 4, 2) == 0x8664, "Expected AMD64 PE")
    require(integer(data, optional, 2) == 0x20b, "Expected PE32+")
    sections = []
    start = optional + integer(data, header + 20, 2)
    for i in range(integer(data, header + 6, 2)):
        pos = start + 40 * i
        rva, size, raw = struct.unpack_from("<III", data, pos + 12)
        sections.append((rva, size, raw, bool(integer(data, pos + 36) & 0x20000000)))
    def filepos(rva, executable=False):
        for base, size, raw, is_code in sections:
            if base <= rva < base + size and (not executable or is_code):
                return raw + rva - base
        raise ValueError(f"RVA {rva:#x} is outside requested file-backed sections")
    def directory(i):
        return struct.unpack_from("<II", data, optional + 112 + i * 8)
    anchors = {}
    def mark(address, reason):
        filepos(address, True)
        anchors.setdefault(address, []).append(reason)
    mark(integer(data, optional + 16), "PE entry")
    unwind, size = directory(3)
    require(size % 12 == 0, "AMD64 exception directory size")
    pos = filepos(unwind)
    for off in range(pos, pos + size, 12):
        begin, end = struct.unpack_from("<II", data, off)
        mark(begin, f".pdata end={end:#x}")
    export, size = directory(0)
    if export:
        pos = filepos(export)
        ordinal, n, names, functions, strings, ordinals = struct.unpack_from("<IIIIII", data, pos + 16)
        labels = {}
        for i in range(names):
            idx = integer(data, filepos(ordinals) + i * 2, 2)
            name = cstring(data, filepos(integer(data, filepos(strings) + i * 4)))
            labels.setdefault(idx, []).append(name)
        for i in range(n):
            target = integer(data, filepos(functions) + 4 * i)
            if any(base <= target < base + length and code for base, length, _, code in sections):
                mark(target, "export " + "/".join(labels.get(i, [f"#{ordinal+i}"])))
    cli, _ = directory(14)
    records = []
    if cli:
        pos = filepos(cli)
        records = metadata(data, filepos(integer(data, pos + 8)))
        for row in records:
            if row.get("flavor") == "native" and row["rva"]:
                mark(row["rva"], f"native MethodDef {row['key']:#010x}")
    records.extend(dict(kind="native", key=k, name="; ".join(v)) for k, v in sorted(anchors.items()))
    return records, filepos, integer(data, optional + 24, 8)


def table(folder, name, required):
    with (folder / name).open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream, strict=True)
        fields = reader.fieldnames or []
        require(len(fields) == len(set(fields)) and set(required) <= set(fields), f"{name}: required {required}")
        rows = list(reader)
    for row in rows:
        require(None not in row and None not in row.values(), f"{name}: malformed row")
    return rows


def check_indirect_attachment(folder, calls, excerpt, extensions, imagebase):
    """Cross-check the optional row/line index used by the native submissions."""
    index = folder / "code" / "indirect.csv"
    if not index.is_file():
        return
    fields = {"kind", "caller", "listing"}
    with index.open(encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream, strict=True)
        if not fields.issubset(reader.fieldnames or []):
            print("indirect.csv uses another layout; review its sites against calls.csv manually")
            return
        attachment = list(reader)

    def identity(row):
        kind, owner = row["kind"], int(row["caller"], 0)
        ref = row["listing"]
        lines = excerpt(ref, extensions)
        if kind == "method":
            pattern = r"^\s*IL_([0-9a-f]+):\s*(?:call[\w.]*|jmp)\b"
        else:
            pattern = r"^\s*(?:0x)?([0-9a-f]+)[:\s]+(?:[0-9a-f]{2}\s+)+(?:(?:bnd|notrack)\s+)?(?:call\w*|jmp\w*)\b"
        positions = re.findall(pattern, lines, re.I | re.M)
        # The exact listing reference is also valid for a different disassembler layout.
        location = None
        if len(positions) == 1:
            position = int(positions[0], 16)
            if kind == "native" and position >= imagebase:
                position -= imagebase
            location = kind, owner, position
        return (kind, owner, ref), location

    registered_refs, registered_positions, ambiguous_owners = set(), set(), set()
    for row in calls:
        if row["class"] == "data":
            continue
        ref, position = identity(row)
        registered_refs.add(ref)
        if position is None:
            ambiguous_owners.add(ref[:2])
        else:
            registered_positions.add(position)
    missing, manual = [], 0
    for row in attachment:
        ref, position = identity(row)
        if ref in registered_refs or (position and position in registered_positions):
            continue
        if position is None or ref[:2] in ambiguous_owners:
            manual += 1
        else:
            missing.append(row["listing"])
    if manual:
        print(f"indirect.csv: {manual} sites need manual comparison of listing ranges")
    require(not missing, f"indirect.csv: {len(missing)} transfer sites missing from calls.csv; first={missing[:3]}")

def verify(folder, data, digest, records, filepos, imagebase):
    expected = {(r["kind"], r["key"]): r for r in records}
    report = json.loads((folder / "run.json").read_text(encoding="utf-8-sig"))
    require(report["original_sha256"].lower() == digest, "run.json original_sha256")
    require(all(str(report.get(k, "")).strip() for k in ["tool_version", "command", "scope", "limitations"]), "run.json provenance")
    tool = table(folder, "native-functions.csv", ["rva", "name"])
    seen = set()
    for row in tool:
        addr = int(row["rva"], 0)
        filepos(addr, True)
        require(addr not in seen and row["name"].strip(), "duplicate or unnamed native tool entry")
        seen.add(addr)
        expected.setdefault(("native", addr), dict(kind="native", key=addr, name=row["name"]))
    require(len(seen) > 0 and report["native_reported_count"] == len(seen), "native tool function count mismatch")
    cache = {}
    def excerpt(ref, extensions):
        match = re.fullmatch(r"(.+)#L([1-9][0-9]*)(?:-L([1-9][0-9]*))?", ref)
        require(match, f"bad evidence reference {ref!r}")
        name, first, last = match.groups()
        path = (folder / name).resolve()
        require(path.is_relative_to(folder) and path.suffix.lower() in extensions, f"external or wrong-type evidence: {ref}")
        if path not in cache:
            cache[path] = path.read_text(encoding="utf-8-sig").splitlines()
        start, end = int(first), int(last or first)
        require(start <= end <= len(cache[path]), f"evidence lines outside file: {ref}")
        lines = "\n".join(cache[path][start-1:end]).strip()
        require(lines, f"empty evidence {ref}")
        return lines
    def has_address(lines, values):
        return any(re.search(r"(?<![A-Za-z0-9])(?:0x)?0*" + format(v, "x") + r"(?![A-Za-z0-9])", lines, re.I) for v in values)
    asm = {".asm", ".il", ".txt", ".lst"}
    is_mixed = any(r["kind"] == "method" for r in records)
    native_source = {".c", ".cpp", ".h", ".hpp"}
    completed = set()
    gaps = []
    rows = table(folder, "coverage.csv", ["kind", "key", "state", "first_bytes", "listing", "source", "note"])
    for row in rows:
        kind, key, state = row["kind"], int(row["key"], 0), row["state"]
        tag = (kind, key)
        require(tag in expected and tag not in completed, f"unknown or duplicate {kind} {key:#x}")
        completed.add(tag)
        detail = expected[tag]
        if state == "gap":
            require(row["note"].strip(), f"missing recovery condition {tag}")
            gaps.append(tag)
            continue
        declaration = kind == "method" and not detail["rva"]
        require(state == ("declaration" if declaration else "covered"), f"invalid evidence state {tag}")
        lines = excerpt(row["listing"], asm)
        require(has_address(lines, (key, imagebase + key) if kind == "native" else (key,)), f"listing lacks address/token {tag}")
        code = excerpt(row["source"], native_source if kind == "native" else native_source | {".cs", ".il"})
        require(len(code.split()) >= 2, f"empty source declaration/body {tag}")
        if kind == "native":
            pos = filepos(key, True)
            require(row["first_bytes"].lower() == data[pos:pos+8].hex(), f"entry bytes differ {key:#x}")
            start_line = rf"^\s*(?:0x)?0*(?:{key:x}|{imagebase+key:x})[\s:]+{data[pos]:02x}"
            require(re.search(start_line, lines, re.I | re.M), f"missing original address and first byte in listing {tag}")
    missing = expected.keys() - completed
    require(not missing, f"missing {len(missing)} coverage rows, first={sorted(missing)[:3]}")
    calls = table(folder, "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"])
    require(calls, "empty calls.csv")
    call_classes = set()
    call_sites = set()
    for row in calls:
        caller = (row["kind"], int(row["caller"], 0))
        require(caller in expected and caller[0] in {"method","native"}, f"unknown call owner {caller}")
        category = row["class"]
        require(category in {"external", "boundary", "data", "unresolved"} and row["callee"].strip() and row["note"].strip(), "incomplete call/reference")
        lines = excerpt(row["listing"], asm)
        if category != "data":
            require(re.search(r"\b(call[a-z.]*|jmp[a-z.]*)\b", lines, re.I), "call site reference lacks instruction")
        site = (caller, row["listing"], row["callee"])
        require(site not in call_sites, f"duplicate call site {site}")
        call_sites.add(site)
        call_classes.add(category)
    check_indirect_attachment(folder, calls, excerpt, asm, imagebase)
    require("external" in call_classes, "no external call evidence")
    if is_mixed:
        require("boundary" in call_classes or "unresolved" in call_classes, "missing mixed boundary evidence")
    else:
        require("data" in call_classes or "unresolved" in call_classes, "missing native data reference evidence")
    print(f"checked {len(expected)} coverage rows, {len(tool)} tool-native entries, {len(calls)} call records, {len(gaps)} declared gaps")
    return 2 if gaps or "unresolved" in call_classes else 0


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("task", choices=INPUTS)
    parser.add_argument("--original", type=Path, help="use this exact binary instead of downloading")
    parser.add_argument("--submission", type=Path, help="directory containing the task's evidence")
    parser.add_argument("--inventory", action="store_true", help="report original anchors/metadata only")
    args = parser.parse_args()
    rel, digest = INPUTS[args.task]
    if args.original:
        data = args.original.read_bytes()
    else:
        url = rel if rel.startswith("https://") else BASE + "/" + rel
        with urlopen(url, timeout=60) as stream:
            data = stream.read()
    require(hashlib.sha256(data).hexdigest() == digest, "original SHA-256 mismatch")
    records, filepos, imagebase = inspect(data)
    if args.inventory:
        print(json.dumps({"original_sha256": digest, "records":records}, ensure_ascii=True))
        return 0
    folder = (args.submission or ROOT / "handoff" / "inbox" / args.task).resolve()
    return verify(folder, data, digest, records, filepos, imagebase)


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (ValueError, OSError, KeyError, UnicodeError, csv.Error) as exc:
        sys.exit(str(exc))
