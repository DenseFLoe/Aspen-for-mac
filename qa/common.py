
# -*- coding: utf-8 -*-
"""Shared helpers for preflight detectors (no detection logic, no L1 knowledge)."""
import csv
import hashlib
import json
import os
import re

def _find_repo_root(start):
    """Walk up to the workspace root so the toolkit works from tool/, qa/ or a
    synced copy under _tools/qa/<head8>/qa/."""
    cur = os.path.abspath(start)
    for _ in range(8):
        if any(os.path.exists(os.path.join(cur, m)) for m in
               (".git", "_t13", "handoff", "issue-materials", "out")):
            return cur
        parent = os.path.dirname(cur)
        if parent == cur:
            break
        cur = parent
    return os.path.dirname(os.path.abspath(start))


ROOT = _find_repo_root(os.path.dirname(os.path.abspath(__file__)))


def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def read_text(path):
    with open(path, encoding="utf-8-sig", errors="replace") as f:
        return f.read()


def read_json(path):
    with open(path, encoding="utf-8-sig") as f:
        return json.load(f)


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as f:
        return list(csv.DictReader(f))


def find_one(item_dir, *names):
    for n in names:
        p = os.path.join(item_dir, n)
        if os.path.isfile(p):
            return p
    return None


ROUND_TAG = re.compile(r"(?:^|[^0-9a-z])s(\d+)[-_]", re.I)
ROUND_RECEIPT = re.compile(r"s(\d+)-(?:submission|receipt)\.md", re.I)
ROUND_MANIFEST = re.compile(r"s(\d+)-(?:fingerprints?|manifest|blobs|receipt)\.json", re.I)
ROUND_AUDIT = re.compile(r"s(\d+)-audit\.md", re.I)


def round_of(name):
    for part in reversed(re.split(r"[\\/]", name)):
        match = ROUND_TAG.search(part)
        if match:
            return int(match.group(1))
    return None


def current_round(item_dir, ctx=None):
    root = os.path.abspath(item_dir)
    key = ("submission_round", os.path.normcase(root))
    if ctx is not None and key in ctx:
        return ctx[key]

    receipt = metadata = 0
    for dirpath, dirs, names in os.walk(root):
        dirs[:] = [name for name in dirs if name.lower() != "work"]
        for name in names:
            if dirpath == root and (match := ROUND_RECEIPT.fullmatch(name)):
                receipt = max(receipt, int(match.group(1)))
            elif ((dirpath == root and (match := ROUND_MANIFEST.fullmatch(name)))
                  or (match := ROUND_AUDIT.fullmatch(name))):
                metadata = max(metadata, int(match.group(1)))
    top = receipt or metadata
    if ctx is not None:
        ctx[key] = top
    return top


def is_current(item_dir, path, ctx=None):
    top = current_round(item_dir, ctx)
    r = round_of(os.path.relpath(path, item_dir))
    return r is None or not top or r == top


def path_is_within(root, path):
    try:
        return os.path.normcase(os.path.commonpath([root, path])) == os.path.normcase(root)
    except ValueError:
        return False


def resolve_ref(item_dir, ref):
    """Resolve 'file#Lfirst[-Llast]' strictly inside item_dir.

    Containment is decided on real paths, not on a string prefix: '/x/ab' must not accept
    '/x/abc', and './file' must still resolve to file rather than being rejected.
    """
    m = re.fullmatch(r"(.+?)#L(\d+)(?:-L?(\d+))?", (ref or "").strip())
    if not m:
        return None
    name, first, last = m.group(1), int(m.group(2)), int(m.group(3) or m.group(2))
    root = os.path.realpath(item_dir)
    path = os.path.realpath(os.path.join(item_dir, name))
    try:
        if os.path.commonpath([root, path]) != root:
            return None
    except ValueError:
        return None
    return path, first, last


def asm_line_rva(asm_path):
    """line number -> RVA.  A single-byte instruction at end of line must parse too, so the
    byte run is not required to be followed by whitespace."""
    out = {}
    if not asm_path or not os.path.isfile(asm_path):
        return out
    for i, line in enumerate(read_text(asm_path).splitlines(), 1):
        m = re.match(r"\s*(?:0x)?([0-9A-Fa-f]{6,16})\s+((?:[0-9A-Fa-f]{2}(?:\s|$))+)", line)
        if m:
            out[i] = int(m.group(1), 16)
    return out


def prepared_pe(data):
    import pefile
    pe = pefile.PE(data=data, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    return pe


def iat_slots(pe):
    slots = {}
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) or []:
        dll = entry.dll.decode("ascii", "replace")
        for imp in entry.imports:
            if imp.address is None:
                continue
            rva = imp.address - pe.OPTIONAL_HEADER.ImageBase
            name = imp.name.decode("ascii", "replace") if imp.name else "#%s" % imp.ordinal
            slots[rva] = "%s!%s" % (dll, name)
    return slots


def executable_ranges(pe):
    out = []
    for s in pe.sections:
        if s.Characteristics & 0x20000000:
            out.append((s.VirtualAddress,
                        s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData),
                        s.PointerToRawData, s.SizeOfRawData))
    return out


def iat_call_sites(data, pe, slots):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.skipdata = True  # keep walking past data-in-code bytes
    md.detail = True
    sites = {}
    for va, vend, raw, rawsize in executable_ranges(pe):
        chunk = data[raw:raw + min(rawsize, vend - va)]
        for insn in md.disasm(chunk, va):
            if insn.mnemonic not in ("call", "jmp") or not insn.operands:
                continue
            op = insn.operands[0]
            if op.type != 3 or op.mem.base != 0x29 or op.mem.index:  # X86_OP_MEM, RIP
                continue
            target = insn.address + insn.size + op.mem.disp
            if target in slots:
                raw = bytes(insn.bytes)
                # a thunk may carry REX/operand/segment prefixes before FF 25/FF 15.
                # capstone already reports the instruction address at the first prefix byte,
                # which is why a pattern scan starting at "ff 25" would be off by one.
                lead = raw[0] if raw else 0
                prefixed = lead in (0x48, 0x4C, 0x49, 0x4D, 0x66, 0x67, 0xF2, 0xF3, 0x2E, 0x3E, 0x64, 0x65)
                sites.setdefault(insn.address, {"rva": insn.address, "slot": target,
                                                "symbol": slots[target],
                                                "size": len(raw), "prefix": prefixed,
                                                "lead": lead})
    return [sites[k] for k in sorted(sites)]


def candidate_site_rvas(item_dir, calls, cache):
    out = {}
    for row in calls:
        if (row.get("class") or "").strip() == "data":
            continue
        ref = resolve_ref(item_dir, row.get("listing", ""))
        if not ref:
            continue
        path, first, last = ref
        if path not in cache:
            cache[path] = asm_line_rva(path)
        for i in range(first, last + 1):
            if i in cache[path]:
                out.setdefault(cache[path][i], row)
    return out


def cli_methods(data):
    """[(token, rva, flags_impl)] from the CLI metadata MethodDef table, via cli_tables."""
    import struct
    import cli as cli_tables
    pe = prepared_pe(data)
    opt = pe.OPTIONAL_HEADER
    dd = opt.DATA_DIRECTORY[14]
    if not dd.VirtualAddress:
        return []
    off = pe.get_offset_from_rva(dd.VirtualAddress)
    meta_rva = struct.unpack_from("<I", data, off + 8)[0]
    tables = cli_tables.read(data, pe.get_offset_from_rva(meta_rva))
    out = []
    for row in tables["rows"].get(6, []):
        out.append((row.get("_token") or row.get("_row"), row.get("RVA"), row.get("ImplFlags")))
    return out


def parse_asm(path):
    """[(line_no, rva, bytes, rest)] from a listing such as
    '00001000  48 83 EC 28  SUB RSP'.  Vendored so the toolkit has no tool/ dependency."""
    out = []
    if not os.path.isfile(path):
        return out
    for i, line in enumerate(read_text(path).splitlines(), 1):
        m = re.match(r"\s*(?:0x)?([0-9A-Fa-f]{6,16})\s+((?:[0-9A-Fa-f]{2}\s)+)\s*(.*)", line)
        if not m:
            continue
        out.append((i, int(m.group(1), 16), bytes.fromhex(m.group(2).replace(" ", "")), m.group(3)))
    return out


def cli_methoddefs(data):
    """[{token, rva, flags, impl}] straight from the CLI MethodDef table."""
    import struct
    import cli as cli_tables
    pe = prepared_pe(data)
    dd = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
    if not dd.VirtualAddress:
        return []
    off = pe.get_offset_from_rva(dd.VirtualAddress)
    meta_rva = struct.unpack_from("<I", data, off + 8)[0]
    tables = cli_tables.read(data, pe.get_offset_from_rva(meta_rva))
    out = []
    for i, row in enumerate(tables["rows"].get(6, [])):
        out.append({"token": 0x06000001 + i, "rva": row.get("RVA"),
                    "flags": row.get("Flags"), "impl": row.get("ImplFlags")})
    return out
