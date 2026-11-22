"""Compare a submitted CLR VTableFixups inventory with on-disk slots and MethodDefs."""
import csv
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

if __package__:
    from . import native_sites
else:
    import native_sites


TABLE = "code/vtable-fixups.csv"
EDGES = "code/indirect-native.csv"
SCOPE = "clr_vtable_fixups"
NUMERIC = ("rva", "count", "type", "width", "token", "method_rva")
FIELDS = {"entry", "slot", "method", "state", *NUMERIC}
EDGE_FIELDS = {"kind", "addr", "slot", "slot_value", "target", "line"}
TARGET = re.compile(r"MethodDef (0x[0-9a-fA-F]+) (.+) RVA (0x[0-9a-fA-F]+)")

# Feed only the original metadata stream to the platform's existing CLR reader.
# MethodDefinitions enumerates physical MethodDef row IDs starting at one.
READ_METHODS = r"""
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)
$bytes = [IO.MemoryStream]::new()
[Console]::OpenStandardInput().CopyTo($bytes)
$bytes.Position = 0
$provider = [Reflection.Metadata.MetadataReaderProvider]::FromMetadataStream($bytes)
$reader = $provider.GetMetadataReader([Reflection.Metadata.MetadataReaderOptions]::None)
$methods = @(foreach ($handle in $reader.MethodDefinitions) {
    $method = $reader.GetMethodDefinition($handle)
    ,@($reader.GetString($method.Name), $method.RelativeVirtualAddress)
})
ConvertTo-Json -Compress -Depth 3 -InputObject $methods
"""


def method_defs(metadata):
    shell = shutil.which("pwsh")
    if not shell:
        raise ValueError("PowerShell 7 CLR metadata reader unavailable")
    proc = subprocess.run([shell, "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", READ_METHODS],
                          input=metadata, capture_output=True, timeout=120, check=False)
    if proc.returncode:
        raise ValueError("CLR metadata reader could not read the original MethodDef table")
    return json.loads(proc.stdout.decode("utf-8-sig"))


def raw(original, pe, address, length, *, executable=False):
    """Map a file-backed RVA range without borrowing raw padding or an adjacent section."""
    if address <= 0 or length <= 0 or address + length > 1 << 32:
        raise ValueError(f"invalid RVA range {address:#x}+{length:#x}")
    sections = []
    for section in pe.sections:
        start = section.VirtualAddress
        end = start + (section.Misc_VirtualSize or section.SizeOfRawData)
        if start < address + length and address < end:
            sections.append(section)
    if len(sections) != 1:
        raise ValueError(f"no unique section for RVA {address:#x}+{length:#x}")
    section, = sections
    delta = address - section.VirtualAddress
    offset = section.PointerToRawData + delta
    if (delta < 0 or delta + length > min(section.Misc_VirtualSize or section.SizeOfRawData, section.SizeOfRawData)
            or offset + length > len(original) or (executable and not section.Characteristics & 0x20000000)):
        raise ValueError(f"original range unavailable at RVA {address:#x}+{length:#x}")
    return original[offset:offset + length]


def inventory(original, pe):
    directories = pe.OPTIONAL_HEADER.DATA_DIRECTORY
    if len(directories) <= 14 or directories[14].Size < 72:
        raise ValueError("missing complete IMAGE_COR20_HEADER")
    header = raw(original, pe, directories[14].VirtualAddress, 72)
    header_size, = struct.unpack_from("<I", header)
    if not 72 <= header_size <= directories[14].Size:
        raise ValueError("invalid IMAGE_COR20_HEADER size")
    table, size = struct.unpack_from("<II", header, 0x30)
    if not table and not size:
        return 0, {}
    if not size or size % 8:
        raise ValueError("invalid CLR VTableFixups directory size")
    descriptors = raw(original, pe, table, size)
    metadata, metadata_size = struct.unpack_from("<II", header, 8)
    methods = method_defs(raw(original, pe, metadata, metadata_size))
    entries = list(struct.iter_unpack("<IHH", descriptors))
    ranges = []
    widths = []
    for entry, (rva, count, flags) in enumerate(entries):
        width = {1: 4, 2: 8}.get(flags & 3)
        if not width or not count or rva % width or flags & ~0x1f:
            raise ValueError(f"unsupported CLR fixup descriptor {entry}")
        widths.append(width)
        ranges.append((rva, rva + count * width))
    ranges.sort()
    if any(left[1] > right[0] for left, right in zip(ranges, ranges[1:])):
        raise ValueError("original VTableFixups slot ranges overlap")
    slots = {}
    for entry, ((rva, count, flags), width) in enumerate(zip(entries, widths)):
        values = raw(original, pe, rva, count * width)
        for slot, (token,) in enumerate(struct.iter_unpack("<I" if width == 4 else "<Q", values)):
            rid = token & 0xffffff
            if token >> 24 != 6 or not 1 <= rid <= len(methods):
                raise ValueError(f"original slot {rva + slot * width:#x} lacks a valid MethodDef token")
            name, method_rva = methods[rid - 1]
            slots[entry, slot] = dict(rva=rva, count=count, type=flags, width=width, token=token,
                                      method=name, method_rva=method_rva, state="resolved")
    return size // 8, slots


def slot_rva(key, row):
    return row["rva"] + key[1] * row["width"]


def compare_table(root, slots, result):
    metrics, findings = result["metrics"], result["findings"]
    seen, matched = set(), set()
    for line, row in native_sites.csv_rows(root, TABLE, FIELDS, numbered=True):
        try:
            key = int(row["entry"], 0), int(row["slot"], 0)
        except ValueError as exc:
            findings.append(dict(status="fail", code="clr_fixup_invalid_slot_key", path=TABLE, line=line, message=str(exc)))
            continue
        where = dict(path=TABLE, line=line, entry=key[0], slot=key[1])
        if key in seen or key not in slots:
            code = "clr_fixup_duplicate_slot" if key in seen else "clr_fixup_unexpected_slot"
            findings.append(dict(status="fail", code=code, **where))
            matched.discard(key)
            continue
        seen.add(key)
        orig = slots[key]
        try:
            candidate = {field: int(row[field], 0) for field in NUMERIC}
        except ValueError as exc:
            findings.append(dict(status="fail", code="clr_fixup_invalid_slot_value",
                                 slot_rva=hex(slot_rva(key, orig)), message=str(exc), **where))
            continue
        candidate.update(method=row["method"], state=row["state"])
        differences = {}
        for field, value in candidate.items():
            if orig[field] != value:
                before, after = orig[field], value
                if field in {"rva", "type", "method_rva", "token"}:
                    fmt = "#010x" if field == "token" else "#x"
                    before, after = format(before, fmt), format(after, fmt)
                differences[field] = dict(original=before, submitted=after)
        if differences:
            findings.append(dict(status="fail", code="clr_fixup_slot_mismatch",
                                 slot_rva=hex(slot_rva(key, orig)), differences=differences, **where))
        else:
            matched.add(key)
    for key in sorted(slots.keys() - seen):
        findings.append(dict(status="fail", code="clr_fixup_missing_slot", path=TABLE,
                             entry=key[0], slot=key[1], slot_rva=hex(slot_rva(key, slots[key]))))
    metrics["verified_slots"] = len(matched)
    metrics["verified_methoddefs"] = len({slots[k]["token"] for k in matched})
    metrics["verified_entries"] = len({key[0] for key in matched} - {key[0] for key in slots.keys() - matched})


def compare_edges(original, pe, root, slots, result):
    """Check only explicit vtable-slot rows, at the site supplied by each row."""
    if not native_sites.safe_path(root, EDGES).is_file():
        return
    edges = [(line, row) for line, row in native_sites.csv_rows(root, EDGES, EDGE_FIELDS, numbered=True)
             if row["kind"] == "vtable-slot"]
    metrics = result["metrics"]
    metrics["submitted_transfer_rows"] = len(edges)
    if not edges:
        return
    import iced_x86 as x86
    if (pe.FILE_HEADER.Machine, pe.OPTIONAL_HEADER.Magic) != (0x8664, 0x20b):
        result["findings"].append(dict(status="inconclusive", code="clr_fixup_edge_architecture_unsupported"))
        return
    asm = native_sites.safe_path(root, "code/native.asm").read_text(encoding="utf-8-sig").splitlines()
    by_rva = {slot_rva(key, row): row for key, row in slots.items()}
    base = pe.OPTIONAL_HEADER.ImageBase
    seen = set()
    for line, row in edges:
        site, number = int(row["addr"], 0), int(row["line"])
        where = dict(path=EDGES, line=line, site_rva=hex(site), listing_line=number)
        try:
            if site in seen:
                raise ValueError("duplicate transfer site")
            seen.add(site)
            listing = native_sites.LINE.match(asm[number - 1]) if 1 <= number <= len(asm) else None
            if not listing or int(listing[1], 16) not in (site, base + site):
                raise ValueError("listing line does not identify this site")
            displayed = bytes.fromhex(listing[2])
            if not 1 <= len(displayed) <= 15:
                raise ValueError("invalid displayed instruction length")
            source = raw(original, pe, site, len(displayed), executable=True)
            ins = x86.Decoder(64, source, ip=base + site).decode()
            if (displayed != source or ins.is_invalid or ins.len != len(source) or
                    ins.flow_control not in (x86.FlowControl.INDIRECT_CALL, x86.FlowControl.INDIRECT_BRANCH) or
                    ins.op0_kind != x86.OpKind.MEMORY or not ins.is_ip_rel_memory_operand or
                    ins.segment_prefix in (x86.Register.FS, x86.Register.GS)):
                raise ValueError("original does not support the displayed RIP-relative indirect transfer")
            slot = ins.ip_rel_memory_address - base
            dst = by_rva.get(slot)
            if (not dst or ins.ip_rel_memory_address != int(row["slot"], 0)
                    or x86.MemorySizeExt.size(ins.memory_size) != dst["width"]):
                raise ValueError(f"decoded slot RVA {slot:#x} disagrees with registered fixup")
            target = TARGET.fullmatch(row["target"])
            if (not target or int(row["slot_value"], 0) != dst["token"] or
                    (int(target[1], 16), target[2], int(target[3], 16)) !=
                    (dst["token"], dst["method"], dst["method_rva"])):
                raise ValueError(f"submitted target disagrees with original slot RVA {slot:#x}")
            metrics["verified_transfer_rows"] += 1
        except ValueError as exc:
            result["findings"].append(dict(status="fail", code="clr_fixup_edge_mismatch", message=str(exc), **where))


def check(original: bytes, delivery: Path) -> dict:
    result = dict(scope=SCOPE, status="inconclusive", findings=[], metrics=dict(
        verified_entries=0, verified_slots=0, verified_methoddefs=0, submitted_transfer_rows=0, verified_transfer_rows=0))
    try:
        import pefile
        pe = pefile.PE(data=original, fast_load=True)
    except ImportError as exc:
        result["findings"].append(dict(status="inconclusive", code="clr_fixup_tool_unavailable", message=str(exc)))
        return result
    except pefile.PEFormatError as exc:
        result["findings"].append(dict(status="inconclusive", code="clr_fixup_original_unreadable", message=str(exc)))
        return result
    with pe:
        try:
            entries, slots = inventory(original, pe)
        except (ValueError, OSError, struct.error, subprocess.TimeoutExpired) as exc:
            result["findings"].append(dict(status="inconclusive", code="clr_fixup_original_unreadable", message=str(exc)))
            return result
        result["metrics"].update(original_entries=entries, original_slots=len(slots),
                                 original_methoddefs=len({row["token"] for row in slots.values()}))
        try:
            root = Path(delivery).resolve()
            compare_table(root, slots, result)
            compare_edges(original, pe, root, slots, result)
        except (ValueError, OSError, csv.Error) as exc:
            result["findings"].append(dict(status="fail", code="clr_fixup_invalid_submission", message=str(exc)))
        except ImportError as exc:
            result["findings"].append(dict(status="inconclusive", code="clr_fixup_tool_unavailable", message=str(exc)))
    levels = {finding["status"] for finding in result["findings"]}
    result["status"] = "fail" if "fail" in levels else "inconclusive" if "inconclusive" in levels else "pass"
    return result
