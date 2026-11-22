"""Reconcile original-verified instruction addresses with a pinned earlier listing."""
from bisect import bisect_left, bisect_right
import csv
from hashlib import sha256
from io import StringIO
import re
import struct


# These named imports select the ABI of language-specific data in the original PE.
HANDLER_MODULES = {
    "__C_specific_handler": {"ntdll.dll", "msvcrt.dll", "vcruntime140.dll", "vcruntime140d.dll"},
    "__CxxFrameHandler4": {"vcruntime140_1.dll", "vcruntime140_1d.dll"},
}


def eh_continuations(original, pe, x86, decode, mapped, iat, slot_of, proven_starts):
    """Read AMD64 continuation RVAs from the original, using the identified CRT handler's ABI."""
    functions = getattr(pe, "DIRECTORY_ENTRY_EXCEPTION", ())
    if not functions:
        return {}

    def data_region(rva, size, *, allow_writable=False):
        # The whole metadata span must map to one original file-backed section.
        if rva < 0 or size < 1 or rva + size > 2**32:
            return None
        regions = []
        for section in pe.sections:
            start = section.VirtualAddress
            end = start + (section.Misc_VirtualSize or section.SizeOfRawData)
            if rva < end and start < rva + size:
                offset = section.PointerToRawData + rva - start
                if (rva < start or rva + size > min(end, start + section.SizeOfRawData)
                        or section.Characteristics & 0x20000000 or not section.Characteristics & 0x40000000
                        or section.Characteristics & 0x80000000 and not allow_writable
                        or not section.PointerToRawData or offset + size > len(original)):
                    return None
                limit = min(offset + end - rva, section.PointerToRawData + section.SizeOfRawData, len(original))
                regions.append((offset, limit))
        return regions[0] if len(regions) == 1 else None

    def read(rva, size):
        region = data_region(rva, size)
        if region:
            offset, _ = region
            return original[offset:offset + size]
        return None

    def read_metadata(rva, size):
        data = read(rva, size)
        if data is None:
            raise ValueError("Exception metadata is not uniquely mapped in original read-only data")
        return data

    def type_descriptor_size(rva):
        # The MSVC x64 static descriptor holds a vftable VA, a spare pointer and an inline type name.
        region = data_region(rva, 17, allow_writable=True)
        if not region:
            return None
        raw, limit = region
        vftable, spare = struct.unpack_from("<QQ", original, raw)
        if not vftable or spare or not data_region(vftable - pe.OPTIONAL_HEADER.ImageBase, 8, allow_writable=True):
            return None
        nul = original.find(b"\0", raw + 16, limit)
        if nul <= raw + 16 or any(byte < 32 or byte > 126 for byte in original[raw + 16:nul]):
            return None
        size = nul + 1 - raw
        return size if data_region(rva, size, allow_writable=True) else None

    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
    if directory.Size != 12 * len(functions) or directory.VirtualAddress % 4:
        return {}
    table = read(directory.VirtualAddress, directory.Size)
    if not table:
        return {}
    ranges = list(struct.iter_unpack("<III", table))
    previous_end = 0
    for begin, end, unwind in ranges:
        if begin < previous_end or begin >= end or unwind % 4:
            return {}
        previous_end = end

    continuations = {}
    metadata_starts = sorted({u for _, _, u in ranges} | {directory.VirtualAddress})
    runtime_starts = set()
    for item, (begin, end, unwind) in zip(functions, ranges):
        region = mapped(begin)
        if (region and end - begin <= region[1] and unwind and read(unwind, 4)
                and getattr(item, "unwindinfo", None) and item.struct.BeginAddress == begin
                and item.struct.EndAddress == end and item.struct.UnwindData == unwind):
            runtime_starts.add(begin)
    for item, (begin, end, unwind) in zip(functions, ranges):
        info = getattr(item, "unwindinfo", None)
        if (begin not in runtime_starts or info.Version != 1 or info.Flags not in (1, 3)
                or not hasattr(info, "ExceptionHandler")):
            continue
        # UNWIND_INFO v1 stores the handler after an even number of 2-byte unwind-code slots.
        handler_offset = 4 + ((info.CountOfCodes + 1) & ~1) * 2
        next_metadata = bisect_right(metadata_starts, unwind)
        metadata_end = metadata_starts[next_metadata] if next_metadata < len(metadata_starts) else 2**32
        language_data = unwind + handler_offset + 4
        if language_data + 4 > metadata_end:
            continue
        header = read(unwind, handler_offset + 8)
        if not header:
            continue
        handler, first = struct.unpack_from("<II", header, handler_offset)
        thunk = decode(handler)
        if (handler != info.ExceptionHandler or not thunk or thunk.is_invalid
                or thunk.code != x86.Code.JMP_RM64 or thunk.memory_base != x86.Register.RIP):
            continue
        slot = slot_of(thunk)
        ident = iat.get(slot)
        if not ident or ident[0] not in HANDLER_MODULES.get(ident[1], ()):
            continue
        evidence = {"runtime_function_rva": hex(begin), "unwind_rva": hex(unwind), "handler_thunk_rva": hex(handler),
                    "iat_rva": hex(slot), "handler_import": "!".join(ident)}
        if ident[1] == "__CxxFrameHandler4":
            if __package__:
                from .fh4 import continuations as fh4_continuations
            else:
                from fh4 import continuations as fh4_continuations
            try:
                targets = fh4_continuations(read_metadata, first, begin, end, runtime_starts,
                                            type_descriptor_size=type_descriptor_size)
            except ValueError:
                continue
            for target, funclets in sorted(targets.items()):
                if begin <= target < end:
                    for funclet in sorted(funclets):
                        continuations.setdefault(target, []).append(dict(evidence, target_rva=hex(target), info_rva=hex(first),
                                                                        funclet_rva=hex(funclet), prerequisite_rva=hex(funclet)))
            continue
        count, records_rva = first, language_data + 4
        if not count or records_rva + 16 * count > metadata_end:
            continue
        data = read(unwind, records_rva - unwind + 16 * count)
        if not data:
            continue
        candidates = []
        for index, (lo, hi, filter_rva, target) in enumerate(struct.iter_unpack("<IIII", data[records_rva - unwind:])):
            # JumpTarget == 0 denotes a termination handler, not a continuation. An exception
            # filter can be the constant EXCEPTION_EXECUTE_HANDLER or an independently rooted instruction.
            if (not begin <= lo < hi <= end or not (filter_rva in proven_starts or (filter_rva == 1 and target))
                    or target and not begin <= target < end):
                break
            if target:
                candidates.append((target, dict(evidence, target_rva=hex(target), filter_value=hex(filter_rva),
                                                prerequisite_rva=None if filter_rva == 1 else hex(filter_rva),
                                                scope_record_rva=hex(records_rva + 16 * index))))
        else:
            for target, evidence in candidates:
                continuations.setdefault(target, []).append(evidence)
    return continuations


def read_baseline(data):
    rows = csv.reader(StringIO(data.decode("ascii")), strict=True)
    if next(rows, None) != ["rva", "bytes"]:
        raise ValueError("Unexpected historical instruction table header")
    for rva, blob in rows:
        if not re.fullmatch(r"[0-9a-f]{1,8}", rva) or not re.fullmatch(r"(?:[0-9a-f]{2}){1,15}", blob):
            raise ValueError("Invalid historical instruction row")
        yield int(rva, 16), bytes.fromhex(blob)


def compare(data, pe, x86, decode, instructions, proven_lengths, report):
    result = {"reference_sha256": sha256(data).hexdigest(), "status": "inconclusive",
              "duplicate_rows": 0, "byte_matched_rows": 0, "verified_baseline_instructions": 0,
              "unverified_identity_rows": [], "unproven_boundaries": [],
              "missing_nonpadding": [], "missing_nop_or_int3": []}
    try:
        rows = list(read_baseline(data))
        if not rows:
            raise ValueError("Historical instruction table is empty")
    except (UnicodeError, ValueError, csv.Error) as exc:
        report("inconclusive", "historical_instruction_baseline", str(exc))
        return result
    unique = sorted(set(rows))
    result["duplicate_rows"] = len(rows) - len(unique)
    starts = sorted(proven_lengths)
    padding = {x86.Mnemonic.NOP, x86.Mnemonic.INT3}
    identities = result["unverified_identity_rows"]
    for address, raw in unique:
        row = {"rva": hex(address), "bytes": raw.hex(" ")}
        ins = decode(address)
        if ins is None or ins.is_invalid or ins.len != len(raw) or pe.get_data(address, len(raw)) != raw:
            identities.append(row)
            continue
        result["byte_matched_rows"] += 1
        row["instruction"] = str(ins)
        if proven_lengths.get(address) != len(raw):
            row.update(listed=address in instructions, nop_or_int3=ins.mnemonic in padding,
                       reason="no_independent_original_path")
            index = bisect_left(starts, address + len(raw)) - 1
            if index >= 0 and starts[index] + proven_lengths[starts[index]] > address:
                row.update(reason="overlaps_verified_instruction", verified_start_rva=hex(starts[index]))
            result["unproven_boundaries"].append(row)
            continue
        result["verified_baseline_instructions"] += 1
        if address in instructions:
            continue
        key = "missing_nop_or_int3" if ins.mnemonic in padding else "missing_nonpadding"
        result[key].append(row)
    missing = result["missing_nonpadding"]
    unproven = result["unproven_boundaries"]
    result["status"] = "fail" if missing else "inconclusive" if identities or unproven else "pass"
    if identities:
        report("inconclusive", "historical_instruction_identity",
               f"{len(identities)} historical rows do not match one original instruction at their claimed address.",
               int(identities[0]["rva"], 16))
    if unproven:
        report("inconclusive", "historical_instruction_boundary",
               f"{len(unproven)} historical rows match original bytes but lack an independent instruction boundary.",
               int(unproven[0]["rva"], 16))
    if missing:
        report("fail", "historical_instruction_missing",
               f"{len(missing)} verified historical instruction starts are absent from the submitted listing.",
               int(missing[0]["rva"], 16))
    return result
