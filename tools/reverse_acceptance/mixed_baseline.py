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
SOURCE = "code/native.c"
NEWOBJ = "code/newobj.csv"
CALLS = "calls.csv"
# handoff/outbox/NATIVE-340/s5-native-fixup-targets.csv at d9c836dad07901f72448844ec2be7f363757e372.
# Key = original SHA-256. Value = historical table SHA-256. No verdict or expected totals.
BASELINES = {
    "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec":
        "c5b93ac648c941b5a788ac856af8f96c232dd230d09830d8b81664b6c18d33f3",
}


def issue(result, code, status="fail", **where):
    result["findings"].append(dict(code=code, status=status, **where))


def baseline(original_sha):
    path = Path(__file__).parent / "baselines" / (original_sha + ".csv")
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != BASELINES[original_sha]:
        raise ValueError("trusted historical site table digest mismatch")
    return list(csv.DictReader(io.StringIO(data.decode("utf-8-sig")), strict=True))


def listings(root, name):
    return native_sites.safe_path(root, name).read_text(encoding="utf-8-sig").splitlines()


def check_thunks(original, pe, historical, listing, calls, result):
    """The historical table supplies boundaries. Resolve jumps, slots and tokens in the original again."""
    _, slots = clr_fixups.inventory(original, pe)
    by_slot = {clr_fixups.slot_rva(key, row): row for key, row in slots.items()}
    base = pe.OPTIONAL_HEADER.ImageBase
    indexed = defaultdict(list)
    for line, text in enumerate(listing, 1):
        match = native_sites.LINE.match(text)
        if match:
            addr = int(match[1], 16)
            indexed[addr - base if addr >= base else addr].append((line, bytes.fromhex(match[2])))
    refs = defaultdict(list)
    callers = set()
    for row in calls:
        if row["kind"] != "native":
            continue
        try:
            callers.add(int(row["caller"], 0))
        except ValueError:
            issue(result, "mixed_invalid_native_caller", listing=row["listing"])
            continue
        ref = native_sites.parse_ref(row["listing"])
        if ref and ref[0] == ASM and ref[1] == ref[2]:
            refs[ref[1]].append(row)
    seen = set()
    metrics = result["metrics"]
    import iced_x86 as x86
    for row in historical:
        site, slot, token, target, flags = (int(row[k], 0) for k in
                                            ("site_rva", "fixup_slot_rva", "method_token", "method_rva", "flags"))
        if site in seen:
            raise ValueError(f"duplicate trusted baseline site {site:#x}")
        seen.add(site)
        # The historical profile attests six-byte x64 RIP-relative jmp instructions.
        code = clr_fixups.raw(original, pe, site, 6, executable=True)
        ins = x86.Decoder(64, code, ip=base + site).decode()
        dst = by_slot.get(slot)
        if (ins.code != x86.Code.JMP_RM64 or ins.len != len(code) or
                ins.op0_kind != x86.OpKind.MEMORY or not ins.is_ip_rel_memory_operand or
                ins.segment_prefix != x86.Register.NONE or ins.ip_rel_memory_address != base + slot or
                not dst or (dst["width"], dst["type"], dst["token"], dst["method_rva"], dst["method"]) !=
                (8, flags, token, target, row["method_name"])):
            issue(result, "baseline_original_target_disagrees", "inconclusive", site_rva=hex(site))
            continue
        metrics["verified_baseline_thunks"] += 1
        entries = indexed[site]
        listed = len(entries) == 1 and entries[0][1] == code
        line = entries[0][0] if listed else None
        calls_at = refs.get(line, [])
        recorded = False
        if len(calls_at) == 1:
            row = calls_at[0]
            m = re.fullmatch(r"vtable slot (0x[\da-f]+) -> MethodDef (0x[\da-f]+) (.+) RVA (0x[\da-f]+)",
                             row["callee"], flags=re.I)
            recorded = bool(m and int(row["caller"], 0) == site and
                            (int(m[1], 16), int(m[2], 16), m[3], int(m[4], 16)) ==
                            (base + slot, token, dst["method"], target))
        if listed and recorded:
            metrics["baseline_thunks_with_listing_and_call"] += 1
        else:
            if not entries and site not in callers:
                metrics["baseline_thunks_missing_both"] += 1
            issue(result, "baseline_thunk_missing_or_incorrect_evidence", site_rva=hex(site), slot_rva=hex(slot),
                  token=f"{token:#010x}", original_bytes=code.hex(), listing_line=line, matching_call=recorded)


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


def check_newobj(constructors, listing, table, calls, result):
    headers = re.compile(r"^// MethodDef (0x[\da-f]+)\b", re.I)
    instruction = re.compile(r"^\s*IL_([\da-f]+):\s+newobj\s+(0x[\da-f]{8})\b", re.I)
    current = None
    listed, submitted = defaultdict(list), defaultdict(list)
    for line, text in enumerate(listing, 1):
        if match := headers.match(text):
            current = int(match[1], 16)
        if match := instruction.match(text):
            listed[current, int(match[1], 16)].append((line, int(match[2], 16)))
    for line, row in table:
        offset = re.fullmatch(r"IL_([\da-f]+)", row["il_offset"], re.I)
        if not offset:
            raise ValueError(f"invalid {NEWOBJ} IL offset at line {line}")
        key = int(row["caller_token"], 0), int(offset[1], 16)
        submitted[key].append((int(row["caller_rva"], 0), int(row["opcode"], 0), int(row["token"], 0)))
    call_refs = defaultdict(list)
    for row in calls:
        ref = native_sites.parse_ref(row["listing"])
        if row["kind"] == "method" and ref and ref[0] == IL and ref[1] == ref[2]:
            call_refs[ref[1]].append(row)
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
        records = call_refs[lines[0][0]] if listing_ok else []
        exact = False
        if len(records) == 1:
            row = records[0]
            match = re.match(r"^\s*(?:(?:token|MemberRef|MethodDef)\s+)?(0x[\da-f]+)\b", row["callee"], re.I)
            exact = bool(match and int(match[1], 16) == token and int(row["caller"], 0) == caller)
        if not records and listing_ok and inventory_ok:
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
C_COMMENTS = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)


def check_load_witness(root, pe, token, rva, original_code, asm, result):
    filename = f"code/loads-{rva:x}.csv"
    if not native_sites.safe_path(root, filename).is_file():
        issue(result, "mixed_mode_missing_artifact", path=filename)
        return
    rows = [row for row in native_sites.csv_rows(root, filename, {"view", "rva", "bytes", "method", "data_dir14", "evidence"})
            if row["view"] == "CLI"]
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
    if len(rows) == 1:
        row, = rows
        fields = tuple(int(v, 0) for v in row["data_dir14"].split("/"))
        ref = native_sites.parse_ref(row["evidence"])
        if ref and ref[0] == ASM and ref[2] <= len(asm) and ref[2] - ref[1] == 2:
            lines = [native_sites.LINE.match(s) for s in asm[ref[1]-1:ref[2]]]
            if all(lines):
                actual = [(int(m[1], 16), bytes.fromhex(m[2])) for m in lines]
                want = [(rva, original_code[:9]), (rva + 9, original_code[9:13]), (rva + 13, original_code[13:])]
                if (actual == want and fields == (directory.VirtualAddress, directory.Size) and int(row["rva"], 0) == rva
                        and int(row["method"], 0) == token and bytes.fromhex(row["bytes"]) == original_code):
                    return
    issue(result, "segment_load_witness_mismatch", path=filename, site_rva=hex(rva))


def check_source(original, pe, native, source, result, *, root=None, asm=()):
    headers = list(FUNCTION.finditer(source))
    blocks = defaultdict(list)
    for i, hdr in enumerate(headers):
        end = headers[i + 1].start() if i + 1 < len(headers) else len(source)
        blocks[int(hdr[1], 16)].append(C_COMMENTS.sub("", source[hdr.end():end]).strip())
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
                check_load_witness(root, pe, token, rva, code, asm, result)
            except (ValueError, OSError, csv.Error) as exc:
                issue(result, "segment_load_witness_mismatch", site_rva=hex(rva), message=str(exc))
        seg, = struct.unpack_from("<I", code, 5)
        disp, = struct.unpack_from("<b", code, 12)
        where = dict(method=f"{token:#010x}", site_rva=hex(rva), segment="gs", segment_offset=hex(seg),
                     field_offset=disp, original_bytes=code.hex(), path=SOURCE)
        bodies = blocks.get(rva, [])
        if len(bodies) != 1 or "{" not in bodies[0]:
            issue(result, "segment_load_source_missing_or_ambiguous", **where)
            continue
        signature, separator, body = bodies[0].partition("{")
        matched = RETURN_LOAD.fullmatch(separator + body)
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


def check(original, delivery):
    root = Path(delivery).resolve()
    digest = hashlib.sha256(original).hexdigest()
    pinned = digest in BASELINES
    result = dict(scope=SCOPE, status="inconclusive", findings=[], metrics=dict(
        verified_baseline_thunks=0, baseline_thunks_missing_both=0, baseline_thunks_with_listing_and_call=0,
        verified_newobj=0, newobj_missing_calls=0, source_missing_segment_base=0, verified_segment_load_source=0))
    required = {CALLS, NEWOBJ, IL}
    if pinned:
        required.update({ASM, SOURCE, clr_fixups.TABLE})
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
        if pinned:
            try:
                if (pe.FILE_HEADER.Machine, pe.OPTIONAL_HEADER.Magic) != (0x8664, 0x20b):
                    raise ValueError("trusted baseline requires x64")
                historical = baseline(digest)
                result["metrics"]["baseline_sha256"] = BASELINES[digest]
                assembly = [] if ASM in missing else listings(root, ASM)
                check_thunks(original, pe, historical, assembly, calls, result)
            except (csv.Error, ValueError, OSError, ImportError, struct.error, subprocess.TimeoutExpired) as exc:
                issue(result, "baseline_evidence_unavailable", "inconclusive", message=str(exc))
        try:
            constructors, native = original_methods(original)
            result["metrics"]["original_newobj"] = len(constructors)
        except (OSError, ValueError, struct.error, subprocess.TimeoutExpired) as exc:
            issue(result, "mixed_method_bodies_unavailable", "inconclusive", message=str(exc))
        else:
            try:
                il = [] if IL in missing else listings(root, IL)
                table = [] if NEWOBJ in missing else native_sites.csv_rows(
                    root, NEWOBJ, {"il_offset", "caller_rva", "caller_token", "opcode", "token"}, numbered=True)
                check_newobj(constructors, il, table, calls, result)
            except (ValueError, OSError, csv.Error) as exc:
                issue(result, "mixed_invalid_constructor_evidence", message=str(exc))
            if pinned:
                try:
                    source = "" if SOURCE in missing else "\n".join(listings(root, SOURCE))
                    asm = [] if ASM in missing else listings(root, ASM)
                    check_source(original, pe, native, source, result, root=root, asm=asm)
                except (ValueError, OSError, csv.Error) as exc:
                    issue(result, "mixed_invalid_source_evidence", message=str(exc))
    levels = {finding["status"] for finding in result["findings"]}
    result["status"] = "fail" if "fail" in levels else "inconclusive" if "inconclusive" in levels else "pass"
    return result
