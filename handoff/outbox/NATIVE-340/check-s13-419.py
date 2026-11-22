"""Compare the fixed NATIVE-340 s13 tables with the matching PE and CLI bytes."""
import argparse
import csv
import hashlib
import json
import re
import runpy
import struct
from collections import Counter
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_OP_MEM, X86_REG_RIP


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as source:
        return list(csv.DictReader(source))


def locations(lines, pattern):
    return {int(match[1], 16): n for n, line in enumerate(lines, 1)
            if (match := pattern.match(line))}


def type_method_ranges(data, metadata_offset):
    size = struct.unpack_from("<I", data, metadata_offset + 12)[0]
    header = metadata_offset + 16 + size
    stream_count = struct.unpack_from("<H", data, header + 2)[0]
    header += 4
    streams = {}
    for _ in range(stream_count):
        off, size = struct.unpack_from("<II", data, header)
        end = data.index(b"\0", header + 8)
        streams[data[header+8:end]] = data[metadata_offset+off:metadata_offset+off+size]
        header += 8 + ((end - header - 8 + 4) // 4) * 4
    table = streams[b"#~"]
    valid = struct.unpack_from("<Q", table, 8)[0]
    count_values = iter(struct.unpack_from(f"<{valid.bit_count()}I", table, 24))
    counts = [next(count_values) if valid >> i & 1 else 0 for i in range(64)]
    heap = table[6]
    s, g = (4 if heap & flag else 2 for flag in (1, 2))
    index = lambda t: 4 if counts[t] >= 65536 else 2
    coded = lambda ts: 4 if max(counts[t] for t in ts) >= 16384 else 2
    first_type = (24 + 4 * valid.bit_count() + counts[0] * (2 + s + 3*g)
                  + counts[1] * (coded((0, 26, 35, 1)) + 2*s))
    method_offset = 4 + s*2 + coded((1, 2, 27)) + index(4)
    method_width = index(6)
    type_width = method_offset + method_width
    starts = [int.from_bytes(table[p:p+method_width], "little") for p in
              (first_type + i*type_width + method_offset for i in range(counts[2]))]
    return {0x02000001+i: (0x06000000 + left, 0x06000000 + right - 1)
            for i, (left, right) in enumerate(zip(starts, starts[1:] + [counts[6]+1]))
            if left < right}


def examine(original, unit, trusted, baseline):
    data = original.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    assert digest == "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
    checker = runpy.run_path(str(trusted / "assignments/check-native-coverage.py"))
    records, pos, imagebase = checker["inspect"](data)
    methods = {r["key"]: r for r in records if r["kind"] == "method"}
    pe = pefile.PE(data=data)
    directory = pe.OPTIONAL_HEADER.DATA_DIRECTORY
    table, table_size = struct.unpack_from("<II", data, pos(directory[14].VirtualAddress) + 0x30)
    assert (directory[15].VirtualAddress, directory[15].Size) == (0, 0)
    slots = {}
    slot_types = Counter()
    for off in range(pos(table), pos(table) + table_size, 8):
        start, count, flags = struct.unpack_from("<IHH", data, off)
        width = {1: 4, 2: 8}[flags & 3]
        for slot in range(start, start + count * width, width):
            token = int.from_bytes(data[pos(slot):pos(slot)+width], "little")
            assert token in methods and slot not in slots
            slots[slot] = token, flags
            slot_types[flags] += 1
    declared = {int(r["rva"], 0) + int(r["slot"]) * int(r["width"]):
                (int(r["token"], 0), int(r["type"], 0))
                for r in rows(unit / "code/vtable-fixups.csv")}
    assert declared == slots
    calls = rows(unit / "calls.csv")
    asm = (unit / "code/native.asm").read_text(encoding="utf-8-sig").splitlines()
    asm_lines = locations(asm, re.compile(r"^\s*([0-9a-fA-F]{8})\b(?!-)"))
    il_lines = (unit / "code/methods.il").read_text(encoding="utf-8-sig").splitlines()
    called_lines = {r["listing"] for r in calls}
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    fixup_comparison = []
    for row in rows(trusted / "outbox/NATIVE-340/s5-native-fixup-targets.csv"):
        site, slot, token = (int(row[name], 0) for name in ("site_rva", "fixup_slot_rva", "method_token"))
        ins = next(decoder.disasm(pe.get_data(site, 15), site, count=1))
        assert ins.mnemonic == "jmp"
        operand = ins.operands[0]
        assert operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP
        assert site + ins.size + operand.mem.disp == slot and slots[slot][0] == token
        assert methods[token]["rva"] == int(row["method_rva"], 0)
        line = asm_lines.get(site)
        matches = [r for r in calls if line and r["listing"] == f"code/native.asm#L{line}-L{line}"]
        fixup_comparison.append(dict(site=hex(site), bytes=ins.bytes.hex(), slot=hex(slot),
                                     token=hex(token), original_method_rva=hex(methods[token]["rva"]),
                                     method_flavor=methods[token]["flavor"],
                                     candidate_listing_line=line,
                                     candidate_call_rows=matches))
    assert len({r["site"] for r in fixup_comparison}) == 126
    listed_newobj = {}
    for n, line in enumerate(il_lines, 1):
        if header := re.match(r"^// MethodDef (0x[0-9a-f]+)", line, re.I):
            method = int(header[1], 0)
        if ins := re.search(r"\bIL_([0-9a-f]+):\s+newobj\b.*?(0x[0-9a-f]{8})", line, re.I):
            listed_newobj[method, int(ins[1], 16)] = (int(ins[2], 0), n)
    newobj = []
    for row in rows(unit / "code/newobj.csv"):
        caller = int(row["caller_token"], 0)
        offset = int(row["il_offset"][3:], 16)
        token = int(row["token"], 0)
        method_rva = methods[caller]["rva"]
        assert method_rva == int(row["caller_rva"], 0)
        start = pos(method_rva)
        header_size = 1 if data[start] & 3 == 2 else (struct.unpack_from("<H", data, start)[0] >> 12) * 4
        assert struct.unpack_from("<BI", data, start + header_size + offset) == (0x73, token)
        assert listed_newobj[caller, offset][0] == token
        n = listed_newobj[caller, offset][1]
        newobj.append(dict(caller=hex(caller), offset=hex(offset), token=hex(token),
                           classification=row["verdict"], listed=f"code/methods.il#L{n}-L{n}",
                           in_calls=f"code/methods.il#L{n}-L{n}" in called_lines))
    assert len(newobj) == len(listed_newobj) == 21
    metadata_rows = rows(unit / "code/typedef-ranges.csv")
    cli = pos(directory[14].VirtualAddress)
    metadata = pos(struct.unpack_from("<I", data, cli + 8)[0])
    type_ranges = type_method_ranges(data, metadata)
    declared_ranges = {int(r["type_token"], 0): (int(r["method_list_start"], 0),
                       int(r["method_list_end"], 0)) for r in metadata_rows}
    owners = [token for r in metadata_rows
              for token in range(int(r["method_list_start"], 0), int(r["method_list_end"], 0) + 1)]
    asm_3660 = list(decoder.disasm(pe.get_data(0x3660, 14), 0x3660))
    baseline_bytes = (baseline / "code/native.c").read_bytes()
    one_body = re.search(r"FUNC 00003660.*?\n\}", (unit / "code/native.c").read_text(encoding="utf-8"), re.S)[0]
    return {
        "original_sha256": digest,
        "directory_entries": table_size // 8,
        "directory_slots": len(slots),
        "directory_methoddefs": len({t for t, _ in slots.values()}),
        "directory_slot_types": {hex(k): v for k, v in sorted(slot_types.items())},
        "fixup_sites": fixup_comparison,
        "newobj": newobj,
        "typedef_nonempty_ranges": len(metadata_rows),
        "typedef_method_count": len(owners),
        "typedef_matches_method_table": set(owners) == set(methods) and len(set(owners)) == len(owners),
        "typedef_ranges_match_by_token": declared_ranges == type_ranges,
        "candidate_calls_by_class": dict(Counter(r["class"] for r in calls)),
        "code_3660_original": [f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}" for i in asm_3660],
        "code_3660_candidate": one_body,
        "code_native_c_matches_predecessor": baseline_bytes == (unit / "code/native.c").read_bytes(),
    }


if __name__ == "__main__":
    cli = argparse.ArgumentParser(description=__doc__)
    for name in ("original", "unit", "trusted", "baseline"):
        cli.add_argument(name, type=Path)
    args = cli.parse_args()
    print(json.dumps(examine(**vars(args)), indent=2, ensure_ascii=False))
