"""Check the Ikc2Bkp s17 runtime ranges, guarded dispatch and slot values."""
import argparse
import csv
import hashlib
import json
import re
import struct
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_RIP

ORIGINAL = "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011"
DISPATCH = 0x26268
RANGES = {
    0x249c0: 0x24a20, 0x24f00: 0x24f3c, 0x24f3c: 0x24f78, 0x24fc8: 0x25002,
    0x25004: 0x25022, 0x25024: 0x2505b, 0x2505c: 0x25077, 0x25118: 0x2516b,
    0x2516c: 0x251bc, 0x25560: 0x25562, 0x25580: 0x25586,
}
CALLS = {
    0x249f8: (0x249c0, DISPATCH, 0x249d4, 0x249f5, "r9"),
    0x24f22: (0x24f00, DISPATCH, 0x24f1a, None, "qword ptr [rbx]"),
    0x24f5e: (0x24f3c, DISPATCH, 0x24f56, None, "qword ptr [rbx]"),
    0x24ffb: (0x24fc8, None, 0x24ff4, None, "0x26280"),
    0x2501b: (0x25004, None, 0x25014, None, "0x26280"),
    0x25050: (0x25024, DISPATCH, 0x25044, None, "0x34980"),
    0x2506c: (0x2505c, DISPATCH, 0x25060, None, "0x34980"),
    0x25164: (0x25118, None, 0x2515d, None, "0x26280"),
    0x251b1: (0x2516c, DISPATCH, 0x251a5, None, "0x34980"),
    0x25560: (0x25560, None, None, None, "rax"),
    0x25580: (0x25580, DISPATCH, None, None, "rax"),
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def inspect(path, unit):
    raw = path.read_bytes()
    assert digest(raw) == ORIGINAL
    pe = pefile.PE(data=raw)
    base = pe.OPTIONAL_HEADER.ImageBase
    image = pe.get_memory_mapped_image()
    load_config = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    assert load_config.GuardCFDispatchFunctionPointer == base + DISPATCH
    assert struct.unpack_from("<Q", image, DISPATCH)[0] == base + 0x25560
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True

    def rip_address(instruction, index):
        operand = instruction.operands[index]
        assert operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP
        return instruction.address + instruction.size + operand.mem.disp

    def direct_target(instruction):
        assert instruction.operands[0].type == X86_OP_IMM
        return instruction.operands[0].imm

    unwind = {item.struct.BeginAddress: item.struct.EndAddress
              for item in pe.DIRECTORY_ENTRY_EXCEPTION}
    decoded = {}
    sections = []
    for begin, end in RANGES.items():
        assert unwind[begin] == end
        data = image[begin:end]
        instructions = list(decoder.disasm(data, begin))
        assert sum(ins.size for ins in instructions) == len(data)
        decoded.update((ins.address, ins) for ins in instructions)
        sections.append({"rva": hex(begin), "exclusive_end": hex(end),
                         "instructions": len(instructions), "bytes": len(data),
                         "sha256": digest(data)})
    delta = json.loads((unit / "s17/reassembly-delta.json").read_text(encoding="utf-8"))
    assert set(RANGES) == {int(row["rva"], 0) for row in delta["matches"]}
    assert {row["rva"]: (row["sha256"], row["bytes"]) for row in sections} == {
        row["rva"]: (row["sha256"], row["bytes"]) for row in delta["matches"]
    }
    for begin, init, bound, enter, test, step, loop, exit_, target in (
        (0x24f00, 0x24f0a, 0x24f11, 0x24f18, 0x24f2c, 0x24f28, 0x24f2f, 0x24f31, 0x2a600),
        (0x24f3c, 0x24f46, 0x24f4d, 0x24f54, 0x24f68, 0x24f64, 0x24f6b, 0x24f6d, 0x2a610),
    ):
        assert decoded[init].op_str.startswith("rbx,") and rip_address(decoded[init], 1) == target
        assert decoded[bound].op_str.startswith("rdi,") and rip_address(decoded[bound], 1) == target
        assert decoded[enter].mnemonic == "jmp" and direct_target(decoded[enter]) == test
        assert decoded[test].mnemonic == "cmp" and decoded[test].op_str == "rbx, rdi"
        assert decoded[step].mnemonic == "add" and decoded[step].op_str == "rbx, 8"
        assert decoded[loop].mnemonic == "jb" and direct_target(decoded[loop]) < test
        assert decoded[loop].address + decoded[loop].size == exit_
    slot_values = {}
    for slot in (DISPATCH, 0x26280, 0x34980):
        segment = next(s for s in pe.sections if s.VirtualAddress <= slot <
                       s.VirtualAddress + s.Misc_VirtualSize)
        value = struct.unpack_from("<Q", image, slot)[0]
        assert value == (base + 0x25560 if slot == DISPATCH else 0)
        slot_values[hex(slot)] = {
            "initial_va": hex(value), "section": segment.Name.rstrip(b"\0").decode(),
            "section_writable": bool(segment.Characteristics & 0x80000000),
            "backed_by_file": slot - segment.VirtualAddress < segment.SizeOfRawData,
        }
    with (unit / "calls.csv").open(encoding="utf-8-sig", newline="") as stream:
        unresolved = {int(re.search(r"site (0x[0-9a-f]+)", row["note"])[1], 16): row
                      for row in csv.DictReader(stream) if row["class"] == "unresolved"}
    assert len(unresolved) == 15
    sites = []
    for site, (owner, slot, source, copy, value) in CALLS.items():
        ins = decoded[site]
        assert int(unresolved[site]["caller"], 0) == owner
        assert ins.mnemonic == ("jmp" if site >= 0x25560 else "call")
        if slot is not None:
            assert rip_address(ins, 0) == slot
        else:
            assert ins.operands[0].type == X86_OP_REG and ins.op_str == "rax"
        if source and value.startswith("0x"):
            assert decoded[source].mnemonic == "mov"
            assert decoded[source].op_str.startswith("rax,") and rip_address(decoded[source], 1) == int(value, 0)
        elif source is not None:
            if copy is not None:
                assert decoded[source].op_str == "rdi, r9" and decoded[copy].op_str == "rax, rdi"
            else:
                assert decoded[source].op_str == f"rax, {value}"
        sites.append({
            "owner": hex(owner), "site": hex(site), "bytes": ins.bytes.hex(),
            "operand": ins.op_str, "dispatch_slot": hex(slot) if slot is not None else None,
            "value_source": value, "source_rva": hex(source) if source else None,
            "copy_rva": hex(copy) if copy else None,
            "reachability_from_entry": (
                "first unsigned loop condition is false with identical bounds"
                if site in (0x24f22, 0x24f5e) else "depends on caller or current process state"),
        })
    return {"original_sha256": ORIGINAL, "guard_flags": hex(load_config.GuardFlags),
            "ranges": sections, "slots": slot_values, "sites": sites,
            "same_bounds": {"0x24f00": "0x2a600", "0x24f3c": "0x2a610"},
            "other_unresolved": [hex(site) for site in sorted(unresolved.keys() - CALLS.keys())]}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    args = parser.parse_args()
    print(json.dumps(inspect(args.original, Path(__file__).resolve().parents[1]), indent=2))
