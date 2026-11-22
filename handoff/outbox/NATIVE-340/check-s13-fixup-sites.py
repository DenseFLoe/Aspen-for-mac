"""Distinguish native transfer sites from CLR fixup slots and MethodDef identities."""

import argparse
import csv
import hashlib
import json
import struct
from collections import Counter
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_OP_MEM, X86_REG_RIP


ORIGINAL = "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"


def check(original, listing):
    raw = original.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == ORIGINAL
    pe = pefile.PE(data=raw)
    cli = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
    fixup_rva, size = struct.unpack("<II", pe.get_data(cli + 0x30, 8))
    assert (fixup_rva, size) == (0x16600, 0x768)
    assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[15].VirtualAddress == pe.OPTIONAL_HEADER.DATA_DIRECTORY[15].Size == 0
    slots = {}
    types = Counter()
    for rva in range(fixup_rva, fixup_rva + size, 8):
        first, count, flags = struct.unpack("<IHH", pe.get_data(rva, 8))
        types[hex(flags)] += 1
        width = 8 if flags & 2 else 4
        for index in range(count):
            slot = first + index * width
            assert slot not in slots
            slots[slot] = (int.from_bytes(pe.get_data(slot, width), "little"), flags)
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    with listing.open(encoding="utf-8", newline="") as stream:
        rows = list(csv.DictReader(stream))
    for row in rows:
        rva = int(row["site_rva"], 0)
        instruction = next(decoder.disasm(pe.get_data(rva, 15), rva, count=1))
        assert instruction.mnemonic in {"call", "jmp"}
        operand = instruction.operands[0]
        assert operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP
        slot = rva + instruction.size + operand.mem.disp
        assert slot == int(row["fixup_slot_rva"], 0)
        assert slots[slot] == (int(row["method_token"], 0), int(row["flags"], 0))
    sites = len({row["site_rva"] for row in rows})
    assert sites == len(rows) == 126
    return {
        "original_sha256": ORIGINAL, "directory_entries": size // 8, "directory_slot_count": len(slots),
        "directory_methoddefs": len({token for token, _ in slots.values()}), "directory_flags": dict(types),
        "matched_native_sites": sites, "matched_slot_count": len({row["fixup_slot_rva"] for row in rows}),
        "matched_methoddefs": len({row["method_token"] for row in rows}), "site_mnemonics": dict(Counter(
            next(decoder.disasm(pe.get_data(int(row["site_rva"], 0), 15), int(row["site_rva"], 0), count=1)).mnemonic
            for row in rows)),
    }


if __name__ == "__main__":
    cli = argparse.ArgumentParser(description=__doc__)
    cli.add_argument("original", type=Path)
    cli.add_argument("listing", type=Path)
    args = cli.parse_args()
    print(json.dumps(check(args.original, args.listing), indent=2))
