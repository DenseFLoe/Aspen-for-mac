"""Cross-check a reviewer-pinned CLR thunk inventory and mixed-mode source evidence."""
import csv
from collections import defaultdict
import hashlib
import io
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

if __package__:
    from . import clr_fixups, native_sites
else:
    import clr_fixups, native_sites


SCOPE = "mixed_baseline"
ASM = "code/native.asm"
IL = "code/methods.il"
NEWOBJ = "code/newobj.csv"
CALLS = "calls.csv"
NEWOBJ_FIELDS = {"il_offset", "caller_rva", "caller_token", "opcode", "token"}
BASELINE_FIELDS = {"site_rva", "fixup_slot_rva", "flags", "method_token", "method_name", "method_rva"}
PREDECESSOR_FIELDS = {"site_rva", "slot_rva", "instruction", "flags", "method_token", "method_name", "method_rva",
                      "predecessor_rva", "predecessor_bytes", "predecessor_target"}
LOAD_FIELDS = {"view", "rva", "bytes", "method", "data_dir14", "evidence"}


def issue(result, code, status="fail", **where):
    result["findings"].append(dict(code=code, status=status, **where))


def baseline(data):
    reader = csv.DictReader(io.StringIO(data.decode("utf-8-sig")), strict=True)
    fields = reader.fieldnames or []
    if len(fields) != len(set(fields)) or not BASELINE_FIELDS <= set(fields):
        raise ValueError("invalid explicit historical site table header")
    rows = list(reader)
    if not rows or any(None in row or any(v is None for v in row.values()) for row in rows):
        raise ValueError("empty or incomplete historical site table")
    return rows


def referenced_listings(root, calls, kind, suffix):
    files = {}
    for row in calls:
        ref = native_sites.parse_ref(row["listing"])
        if row["kind"] == kind and ref and ref[0].lower().endswith(suffix) and ref[0] not in files:
            if native_sites.safe_path(root, ref[0]).is_file():
                files[ref[0]] = listings(root, ref[0])
    return files


def tables_with_fields(root, fields):
    for file in sorted(root.rglob("*.csv")):
        name = file.relative_to(root).as_posix()
        with native_sites.safe_path(root, name).open(encoding="utf-8-sig", newline="") as stream:
            try:
                header = next(csv.reader(stream), [])
            except (csv.Error, UnicodeError):
                continue
        if fields <= set(header):
            yield name


def listings(root, name):
    return native_sites.safe_path(root, name).read_text(encoding="utf-8-sig").splitlines()


def original_thunk_section(original, pe, by_slot):
    """Recognize a dedicated dispatch section by its decoded contents and original slots."""
    import iced_x86 as x86
    candidates = []
    for section in pe.sections:
        if not section.Characteristics & 0x20000000 or not section.Misc_VirtualSize:
            continue
        start = section.VirtualAddress
        size = min(section.Misc_VirtualSize, section.SizeOfRawData)
        if size != section.Misc_VirtualSize:
            continue
        code = clr_fixups.raw(original, pe, start, size, executable=True)
        jumps, predecessors, starts = {}, defaultdict(list), set()
        for ins in x86.Decoder(64, code, ip=start):
            starts.add(ins.ip)
            raw = code[ins.ip - start:ins.next_ip - start]
            if ins.code in (x86.Code.JMP_REL8_64, x86.Code.JMP_REL32_64):
                predecessors[ins.near_branch_target].append((ins.ip, raw))
            elif raw[:2] == b"\xff\x25" and len(raw) == 6 and ins.code == x86.Code.JMP_RM64:
                slot = ins.ip_rel_memory_address
                if slot not in by_slot or by_slot[slot]["width"] != 8:
                    break
                jumps[ins.ip] = (slot, raw)
            elif raw not in (b"\x0f\x0b", b"\xcc", b"\xcd\x03") and ins.mnemonic != x86.Mnemonic.NOP:
                break
        else:
            if (jumps and predecessors.keys() <= starts and len(jumps) == len(by_slot)
                    and {slot for slot, _ in jumps.values()} == by_slot.keys()):
                candidates.append((section.Name.rstrip(b"\0").decode("ascii", "replace"), jumps, predecessors))
    return candidates[0] if len(candidates) == 1 else (None, {}, {})


def matches_thunk_target(callee, base, slot, dst):
    old = re.fullmatch(r"vtable slot (0x[\da-f]+) -> MethodDef (0x[\da-f]+) (.+) RVA (0x[\da-f]+)", callee, re.I)
    if old:
        identity = int(old[1], 16) - base, int(old[2], 16), old[3], int(old[4], 16)
    else:
        new = re.fullmatch(r"MethodDef (0x[\da-f]+) (.+) \(managed, RVA (0x[\da-f]+)\) via fixup slot (0x[\da-f]+)",
                           callee, re.I)
        if not new:
            return False
        identity = int(new[4], 16), int(new[1], 16), new[2], int(new[3], 16)
    return identity == (slot, dst["token"], dst["method"], dst["method_rva"])


def check_extra_sites(root, jumps, predecessors, by_slot, result, paths):
    submitted = defaultdict(list)
    for name in paths:
        for line, row in native_sites.csv_rows(root, name, PREDECESSOR_FIELDS, numbered=True):
            submitted[int(row["site_rva"], 0)].append((name, line, row))
    for site, rows in sorted(submitted.items()):
        if len(rows) == 1 and site in jumps:
            name, line, row = rows[0]
            slot, code = jumps[site]
            dst = by_slot[slot]
            actual = tuple(int(row[k], 0) for k in ("slot_rva", "flags", "method_token", "method_rva", "predecessor_target"))
            if (actual == (slot, dst["type"], dst["token"], dst["method_rva"], site)
                    and bytes.fromhex(row["instruction"]) == code and row["method_name"] == dst["method"]
                    and (int(row["predecessor_rva"], 0), bytes.fromhex(row["predecessor_bytes"])) in predecessors.get(site, ())):
                result["metrics"]["verified_extra_predecessors"] += 1
                continue
        issue(result, "nep_predecessor_missing_or_incorrect", site_rva=hex(site),
              references=[f"{name}#L{line}" for name, line, _ in rows])


def check_thunks(original, pe, historical, listing, calls, result, *, root):
    _, slots = clr_fixups.inventory(original, pe)
    by_slot = {clr_fixups.slot_rva(key, row): row for key, row in slots.items()}
    base = pe.OPTIONAL_HEADER.ImageBase
    files = referenced_listings(root, calls, "native", ".asm")
    files[ASM] = listing
    indexed = defaultdict(list)
    for name, lines in files.items():
        for line, text in enumerate(lines, 1):
            if match := native_sites.LINE.match(text):
                addr = int(match[1], 16)
                indexed[addr - base if addr >= base else addr].append((name, line, bytes.fromhex(match[2]), text[match.end():]))

    callers, call_refs = defaultdict(list), defaultdict(list)
    for row in calls:
        if row["kind"] == "native":
            try:
                callers[int(row["caller"], 0)].append(row)
                ref = native_sites.parse_ref(row["listing"])
                if ref and ref[0] in files and ref[1] == ref[2]:
                    call_refs[ref[:2]].append(row)
            except ValueError:
                issue(result, "mixed_invalid_native_caller", listing=row["listing"])

    metrics = result["metrics"]
    trusted = {}
    for row in historical:
        site = int(row["site_rva"], 0)
        if site in trusted:
            raise ValueError(f"duplicate trusted baseline site {site:#x}")
        trusted[site] = row
    claimed = {site for site, rows in callers.items() if any(
        re.search(r"\b(?:vtable|fixup) slot\b", row["callee"], re.I) for row in rows)}
    if not by_slot and not trusted and not claimed:
        return
    section, jumps, predecessors = original_thunk_section(original, pe, by_slot)
    section_sites = set(jumps)
    if section is not None:
        metrics["original_nep_thunks"] = len(jumps)
        metrics["original_thunk_section"] = section
        metrics["original_thunks_with_direct_predecessors"] = len(section_sites & predecessors.keys())
    else:
        issue(result, "mixed_complete_thunk_inventory_unavailable", "inconclusive", original_slots=len(by_slot))
    for site in sorted((claimed | trusted.keys()) - jumps.keys()):
        try:
            code = clr_fixups.raw(original, pe, site, 6, executable=True)
            slot = site + 6 + struct.unpack_from("<i", code, 2)[0]
            if code[:2] != b"\xff\x25" or slot not in by_slot or by_slot[slot]["width"] != 8:
                raise ValueError("original does not encode a six-byte jump to a CLR slot")
        except ValueError as exc:
            if site in trusted:
                issue(result, "baseline_original_target_disagrees", "inconclusive", site_rva=hex(site), message=str(exc))
            else:
                issue(result, "nep_thunk_missing_or_incorrect_evidence", site_rva=hex(site), message=str(exc))
            continue
        jumps[site] = (slot, code)
    try:
        check_extra_sites(root, jumps, predecessors, by_slot, result, tables_with_fields(root, PREDECESSOR_FIELDS))
    except (csv.Error, ValueError, OSError) as exc:
        issue(result, "nep_predecessor_table_invalid", message=str(exc))

    for site, (slot, code) in jumps.items():
        dst = by_slot.get(slot)
        if site in trusted:
            row = trusted[site]
            values = tuple(int(row[k], 0) for k in ("fixup_slot_rva", "flags", "method_token", "method_rva"))
            if (code[:2] != b"\xff\x25" or not dst or dst["width"] != 8 or dst["method"] != row["method_name"] or
                    values != (slot, dst["type"], dst["token"], dst["method_rva"])):
                issue(result, "baseline_original_target_disagrees", "inconclusive", site_rva=hex(site))
                continue
            metrics["verified_baseline_thunks"] += 1
        entries = indexed[site]
        records = callers[site]
        ref = native_sites.parse_ref(records[0]["listing"]) if len(records) == 1 else None
        recorded = False
        cited = [entry for entry in entries if ref and entry[:2] == ref[:2]]
        if ref and ref[1] == ref[2] and len(cited) == 1 and len(call_refs[ref[:2]]) == 1:
            _, _, displayed, assembly = cited[0]
            operand = re.fullmatch(r"\s*jmp\s+qword ptr \[0x([\da-f]+)\]\s*", assembly, re.I)
            recorded = (displayed == code and operand and int(operand[1], 16) == base + slot
                        and matches_thunk_target(records[0]["callee"], base, slot, dst))
        if recorded:
            if site in section_sites:
                metrics["nep_thunks_with_listing_and_call"] += 1
            else:
                metrics["matched_transfers_outside_section"] += 1
            if site in trusted:
                metrics["baseline_thunks_with_listing_and_call"] += 1
        else:
            if site in trusted and not entries and not records:
                metrics["baseline_thunks_missing_both"] += 1
            finding = "baseline_thunk_missing_or_incorrect_evidence" if site in trusted else "nep_thunk_missing_or_incorrect_evidence"
            issue(result, finding, site_rva=hex(site), slot_rva=hex(slot), token=f"{dst['token']:#010x}",
                  original_bytes=code.hex(), listing_line=entries[0][1] if len(entries) == 1 else None,
                  listing_paths=[entry[0] for entry in entries], matching_call=False)


# The runtime metadata reader treats the original as bytes and never loads it as an assembly.
READ_IL = r"""
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
$stream = [IO.MemoryStream]::new()
[Console]::OpenStandardInput().CopyTo($stream)
$stream.Position = 0
$pe = [Reflection.PortableExecutable.PEReader]::new($stream)
$r = [Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
$ops = @{}
foreach ($f in [Reflection.Emit.OpCodes].GetFields()) {
    $op = $f.GetValue($null)
    if ($op.OpCodeType.ToString() -ne 'Nternal') { $ops[[string]([int]$op.Value -band 65535)] = $op.OperandType.ToString() }
}
$rid = 0
$methods = @(foreach ($h in $r.MethodDefinitions) {
    $rid++
    $m = $r.GetMethodDefinition($h)
    $rva = $m.RelativeVirtualAddress
    if (!$rva) { continue }
    $kind = [int]$m.ImplAttributes -band 3
    $body = ''
    if ($kind -eq 0) {
        $b = [Reflection.Metadata.PEReaderExtensions]::GetMethodBody($pe, $rva)
        $body = [Convert]::ToBase64String($b.GetILBytes())
    }
    ,@((0x06000000 + $rid), $rva, $kind, $body)
})
ConvertTo-Json -Compress -Depth 4 -InputObject @{ops=$ops; methods=$methods}
"""


def original_methods(original):
    import base64
    shell = shutil.which("pwsh")
    if not shell:
        raise ValueError("PowerShell 7 CLR reader unavailable")
    proc = subprocess.run([shell, "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", READ_IL],
                          input=original, capture_output=True, timeout=120, check=False)
    if proc.returncode:
        raise ValueError("CLR reader could not decode original MethodDef bodies")
    data = json.loads(proc.stdout.decode("utf-8-sig"))
    constructors, native = {}, {}
    operations = {int(k): v for k, v in data["ops"].items()}
    for token, rva, kind, body in data["methods"]:
        if kind == 1:
            native[token] = rva
        if kind == 0:
            for offset, target in decode_newobj(base64.b64decode(body, validate=True), operations):
                constructors[token, offset] = rva, target
    return constructors, native


WIDTHS = {
    "InlineNone": 0, "ShortInlineVar": 1, "ShortInlineI": 1, "ShortInlineBrTarget": 1, "InlineVar": 2,
    "InlineI": 4, "ShortInlineR": 4, "InlineBrTarget": 4, "InlineMethod": 4, "InlineField": 4, "InlineType": 4,
    "InlineSig": 4, "InlineTok": 4, "InlineString": 4, "InlineI8": 8, "InlineR": 8,
}


def decode_newobj(body, operations):
    pos = 0
    while pos < len(body):
        start = pos
        op = body[pos]
        pos += 1
        if op == 0xfe and pos < len(body):
            op = 0xfe00 + body[pos]
            pos += 1
        kind = operations.get(op)
        if kind == "InlineSwitch":
            count, = struct.unpack_from("<I", body, pos)
            size = 4 + 4 * count
        elif kind in WIDTHS:
            size = WIDTHS[kind]
        else:
            raise ValueError(f"unsupported original CIL opcode at offset {start:#x}")
        if pos + size > len(body):
            raise ValueError(f"truncated CIL operand at offset {start:#x}")
        if op == 0x73:
            token, = struct.unpack_from("<I", body, pos)
            yield start, token
        pos += size


def check_newobj(constructors, listing, table, calls, result, *, annexes=None):
    headers = re.compile(r"^// MethodDef (0x[\da-f]+)\b", re.I)
    annex_header = re.compile(r"^; caller MethodDef (0x[\da-f]+) .+ RVA (0x[\da-f]+)\s*$", re.I)
    instruction = re.compile(r"^\s*IL_([\da-f]+):\s+newobj\s+(0x[\da-f]{8})(?:\s+\.ctor)?\s*(?://.*)?$", re.I)
    listed, submitted = defaultdict(list), defaultdict(list)
    references = defaultdict(list)
    files = dict(annexes or {})
    files[IL] = listing
    for name, lines in files.items():
        current, rva, primary = None, None, name == IL
        for line, text in enumerate(lines, 1):
            if match := headers.match(text):
                current, primary = int(match[1], 16), True
            elif text.lower().startswith("; caller"):
                hdr = annex_header.match(text)
                current, rva = (int(hdr[1], 16), int(hdr[2], 16)) if hdr else (None, None)
                primary = False
            if match := instruction.match(text):
                key = current, int(match[1], 16)
                token = int(match[2], 16)
                if primary:
                    listed[key].append((line, token))
                elif constructors.get(key) != (rva, token):
                    issue(result, "newobj_annex_original_mismatch", path=name, line=line)
                    continue
                references[key].append((name, line, token))
    for line, row in table:
        offset = re.fullmatch(r"IL_([\da-f]+)", row["il_offset"], re.I)
        if not offset:
            raise ValueError(f"invalid {NEWOBJ} IL offset at line {line}")
        key = int(row["caller_token"], 0), int(offset[1], 16)
        submitted[key].append((int(row["caller_rva"], 0), int(row["opcode"], 0), int(row["token"], 0)))
    call_refs = defaultdict(list)
    for row in calls:
        ref = native_sites.parse_ref(row["listing"])
        if row["kind"] == "method" and ref and ref[0] in files and ref[1] == ref[2]:
            call_refs[ref[:2]].append(row)
    m = result["metrics"]
    for caller, offset in sorted(constructors):
        rva, token = constructors[caller, offset]
        where = dict(caller=f"{caller:#010x}", il_offset=hex(offset), target=f"{token:#010x}", caller_rva=hex(rva))
        key = caller, offset
        lines = listed[key]
        listing_ok = len(lines) == 1 and lines[0][1] == token
        inventory_ok = submitted[key] == [(rva, 0x73, token)]
        if listing_ok and inventory_ok:
            m["verified_newobj"] += 1
        else:
            issue(result, "newobj_listing_or_inventory_mismatch", **where)
        records = [row for name, line, operand in references[key] if operand == token for row in call_refs[name, line]]
        exact = False
        if len(records) == 1:
            row = records[0]
            match = re.match(r"^\s*(?:(?:token|MemberRef|MethodDef)\s+)?(0x[\da-f]+)\b", row["callee"], re.I)
            if not match and token >> 24 == 0x0a:
                match = re.fullmatch(r".+::\.ctor \(MemberRef (0x[\da-f]{8}), external\)", row["callee"], re.I)
            exact = bool(match and int(match[1], 16) == token and int(row["caller"], 0) == caller)
        if exact:
            m["newobj_registered_calls"] += 1
        elif not records and listing_ok and inventory_ok:
            m["newobj_missing_calls"] += 1
        if not exact:
            issue(result, "newobj_call_missing_or_incorrect", listing_line=lines[0][0] if listing_ok else None, **where)
    for key in (set(listed) | set(submitted)) - constructors.keys():
        issue(result, "newobj_unexpected_site", caller=hex(key[0]) if key[0] else None, il_offset=hex(key[1]))

# Strictly bounded matcher for one x64 get-current-thread-field idiom. Other C expressions
# are inconclusive: this is deliberately not a general C equivalence checker.
FUNCTION = re.compile(r"^/\*\s*-+ FUNC ([\da-f]+)\b.*?\*/\s*$", re.I | re.M)
RETURN_LOAD = re.compile(
    r"\{\s*return\s*\*\s*\(\s*(?:undefined8|uint64_t|unsigned\s+long\s+long)\s*\*\s*\)\s*"
    r"\(\s*(?:\(\s*(?:longlong|uintptr_t|uint64_t)\s*\)\s*)?"
    r"(?P<base>Self|__readgsqword\(\s*(?:0[xX][\da-fA-F]+|\d+)\s*\))\s*\+\s*"
    r"(?P<disp>0[xX][\da-fA-F]+|\d+)\s*\)\s*;\s*\}", re.S)
LOCAL_RETURN_LOAD = re.compile(
    r"\{\s*unsigned\s+char\s*\*\s*(?P<local>[a-zA-Z_]\w*)\s*=\s*"
    r"\(\s*unsigned\s+char\s*\*\s*\)\s*(?P<base>__readgsqword\(\s*(?:0[xX][\da-fA-F]+|\d+)\s*\))\s*;\s*"
    r"return\s*\*\s*\(\s*(?:undefined8|uint64_t|unsigned\s+long\s+long)\s*\*\s*\)\s*"
    r"\(\s*(?P=local)\s*\+\s*(?P<disp>0[xX][\da-fA-F]+|\d+)\s*\)\s*;\s*\}", re.S)
C_COMMENTS = re.compile(r"/\*.*?(?:\*/|\Z)|//[^\n]*", re.S)


def check_load_witness(root, pe, token, rva, original_code, asm, result, filename):
    if not native_sites.safe_path(root, filename).is_file():
        issue(result, "mixed_mode_missing_artifact", path=filename)
        return
    rows = [row for row in native_sites.csv_rows(root, filename, LOAD_FIELDS)
            if row["view"] == "CLI" and (int(row["rva"], 0) == rva or int(row["method"], 0) == token)]
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
    if not rows:
        return
    if len(rows) == 1:
        row, = rows
        fields = tuple(int(v, 0) for v in row["data_dir14"].split("/"))
        ref = native_sites.parse_ref(row["evidence"])
        if ref and ref[0] != ASM and ref[0].lower().endswith(".asm"):
            asm = listings(root, ref[0])
        if ref and ref[0].lower().endswith(".asm") and ref[2] <= len(asm) and ref[2] - ref[1] == 2:
            lines = [native_sites.LINE.match(s) for s in asm[ref[1]-1:ref[2]]]
            if all(lines):
                actual = [(int(m[1], 16), bytes.fromhex(m[2])) for m in lines]
                want = [(rva, original_code[:9]), (rva + 9, original_code[9:13]), (rva + 13, original_code[13:])]
                if (actual == want and fields == (directory.VirtualAddress, directory.Size) and int(row["rva"], 0) == rva
                        and int(row["method"], 0) == token and bytes.fromhex(row["bytes"]) == original_code):
                    return
    issue(result, "segment_load_witness_mismatch", path=filename, site_rva=hex(rva))


def check_source(original, pe, native, sources, result, *, root=None, asm=()):
    blocks = defaultdict(list)
    for path, source in sources.items():
        headers = list(FUNCTION.finditer(source))
        for i, hdr in enumerate(headers):
            end = headers[i + 1].start() if i + 1 < len(headers) else len(source)
            blocks[int(hdr[1], 16)].append((path, C_COMMENTS.sub("", source[hdr.end():end]).strip()))
    for token, rva in native.items():
        try:
            code = clr_fixups.raw(original, pe, rva, 14, executable=True)
        except ValueError:
            continue
        # mov rax, gs:[abs32]; mov rax, [rax+signed disp8]; ret
        if not (code[:5] == b"\x65\x48\x8b\x04\x25" and code[9:12] == b"\x48\x8b\x40" and code[13] == 0xc3):
            continue
        if root is not None:
            try:
                for filename in tables_with_fields(root, LOAD_FIELDS):
                    check_load_witness(root, pe, token, rva, code, asm, result, filename)
            except (ValueError, OSError, csv.Error) as exc:
                issue(result, "segment_load_witness_mismatch", site_rva=hex(rva), message=str(exc))
        seg, = struct.unpack_from("<I", code, 5)
        disp, = struct.unpack_from("<b", code, 12)
        where = dict(method=f"{token:#010x}", site_rva=hex(rva), segment="gs", segment_offset=hex(seg),
                     field_offset=disp, original_bytes=code.hex())
        bodies = blocks.get(rva, [])
        if len(bodies) != 1 or "{" not in bodies[0][1]:
            issue(result, "segment_load_source_missing_or_ambiguous", **where)
            continue
        path, block = bodies[0]
        source = sources[path]
        where["path"] = path
        signature, separator, body = block.partition("{")
        matched = RETURN_LOAD.fullmatch(separator + body) or LOCAL_RETURN_LOAD.fullmatch(separator + body)
        preprocessed = re.search(r"^\s*#", C_COMMENTS.sub("", source), re.M)
        if not matched or preprocessed or not re.fullmatch(r"\s*[\w\s*]+\(\s*void\s*\)\s*", signature):
            issue(result, "segment_load_source_requires_review", "inconclusive", **where)
            continue
        value = matched["base"]
        if value == "Self":
            # A declaration/alias elsewhere could bind this identifier. For that case require
            # human source review instead of asserting that the submitted source lost the load.
            if re.search(r"(?:\b(?:extern|typedef|static|struct|union|volatile|const|\w+_t|undefined\d*|longlong|void|int)\s+[\s\w*]*\bSelf\b\s*[;=,{\[])|(?:\bSelf\s*=)", C_COMMENTS.sub("", source)):
                issue(result, "segment_load_alias_requires_review", "inconclusive", **where)
            else:
                result["metrics"]["source_missing_segment_base"] += 1
                issue(result, "source_missing_segment_base", submitted_expression=matched.group().strip(), **where)
        elif int(re.search(r"\((.*?)\)", value)[1], 0) != seg or int(matched["disp"], 0) != disp:
            issue(result, "segment_load_offset_mismatch", **where)
        else:
            result["metrics"]["verified_segment_load_source"] += 1


def check(original, delivery, trusted_baseline=None):
    """trusted_baseline is optional CSV bytes whose fingerprint was verified by the caller."""
    root = Path(delivery).resolve()
    result = dict(scope=SCOPE, status="inconclusive", findings=[], metrics=dict(
        verified_baseline_thunks=0, baseline_thunks_missing_both=0, baseline_thunks_with_listing_and_call=0,
        nep_thunks_with_listing_and_call=0, matched_transfers_outside_section=0, verified_extra_predecessors=0, verified_newobj=0,
        newobj_missing_calls=0, newobj_registered_calls=0, source_missing_segment_base=0, verified_segment_load_source=0))
    required = {CALLS}
    missing = {name for name in required if not native_sites.safe_path(root, name).is_file()}
    for name in sorted(missing):
        issue(result, "mixed_mode_missing_artifact", path=name)
    try:
        import pefile
        pe = pefile.PE(data=original, fast_load=True)
    except (ImportError, OSError) as exc:
        issue(result, "mixed_original_reader_unavailable", "inconclusive", message=str(exc))
        result["status"] = "fail" if missing else "inconclusive"
        return result
    except pefile.PEFormatError as exc:
        issue(result, "mixed_original_unreadable", "inconclusive", message=str(exc))
        result["status"] = "fail" if missing else "inconclusive"
        return result
    with pe:
        try:
            calls = [] if CALLS in missing else list(native_sites.csv_rows(root, CALLS, {"kind", "caller", "callee", "listing"}))
        except (csv.Error, ValueError, OSError) as exc:
            calls = []
            issue(result, "mixed_invalid_call_table", message=str(exc))
        is_x64 = (pe.FILE_HEADER.Machine, pe.OPTIONAL_HEADER.Magic) == (0x8664, 0x20b)
        assembly = []
        if is_x64:
            try:
                if native_sites.safe_path(root, ASM).is_file():
                    assembly = listings(root, ASM)
                historical = []
                if trusted_baseline is not None:
                    result["metrics"]["baseline_sha256"] = hashlib.sha256(trusted_baseline).hexdigest()
                    historical = baseline(trusted_baseline)
                check_thunks(original, pe, historical, assembly, calls, result, root=root)
            except (csv.Error, ValueError, OSError, ImportError, struct.error, subprocess.TimeoutExpired) as exc:
                issue(result, "baseline_evidence_unavailable", "inconclusive", message=str(exc))
        elif trusted_baseline is not None:
            issue(result, "baseline_evidence_unavailable", "inconclusive", message="CLR thunk decoder requires x64")
        try:
            constructors, native = original_methods(original)
            result["metrics"]["original_newobj"] = len(constructors)
        except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as exc:
            issue(result, "mixed_method_bodies_unavailable", "inconclusive", message=str(exc))
        else:
            try:
                tables = list(tables_with_fields(root, NEWOBJ_FIELDS))
                table = (record for name in tables for record in native_sites.csv_rows(root, name, NEWOBJ_FIELDS, numbered=True))
                if constructors and not tables:
                    issue(result, "mixed_mode_missing_artifact", path=NEWOBJ)
                annexes = referenced_listings(root, calls, "method", ".il")
                if native_sites.safe_path(root, IL).is_file():
                    il = listings(root, IL)
                else:
                    il = []
                    for file in root.rglob("*.il"):
                        name = file.relative_to(root).as_posix()
                        if name not in annexes:
                            annexes[name] = listings(root, name)
                check_newobj(constructors, il, table, calls, result, annexes=annexes)
            except (ValueError, OSError, csv.Error) as exc:
                issue(result, "mixed_invalid_constructor_evidence", message=str(exc))
            if is_x64 and native:
                try:
                    sources = {}
                    for file in root.rglob("*.c"):
                        name = file.relative_to(root).as_posix()
                        source = native_sites.safe_path(root, name).read_text(encoding="utf-8-sig")
                        if FUNCTION.search(source):
                            sources[name] = source
                    check_source(original, pe, native, sources, result, root=root, asm=assembly)
                except (ValueError, OSError, csv.Error) as exc:
                    issue(result, "mixed_invalid_source_evidence", message=str(exc))
    levels = {finding["status"] for finding in result["findings"]}
    result["status"] = "fail" if "fail" in levels else "inconclusive" if "inconclusive" in levels else "pass"
    return result
