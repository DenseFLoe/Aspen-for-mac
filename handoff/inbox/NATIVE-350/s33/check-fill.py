"""Compare the editable AVX-512 fill leaf, dispatch tables, and shared RET."""
from argparse import ArgumentParser
import csv
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE = "b2867ed240cf8150fc69c936aaf2a674ef890589b727b40df23dcf04afd3d33b"
START, TEXT_END, RETURN, END = 0x13000, 0x132c0, 0x148c0, 0x148c1
TABLES = {0x132c0:64, 0x134c0:512, 0x144c0:128}
DISPATCH = (
    (0x13035, 0x13015, 0x13031, 0x144c0, "r8", 0, 127),
    (0x1305b, 0x13037, 0x13057, 0x132c0, "r11", 1, 63),
    (0x131aa, 0x1319f, 0x131a6, 0x134c0, "r8", 0, 511),
    (0x131ef, 0x131e4, 0x131eb, 0x134c0, "r8", 0, 63),
)


def rip_target(ins):
    memory = next(op.mem for op in ins.operands if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
    return ins.address + ins.size + memory.disp


def evidence(original, zig, destination):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == RANGE
    assert not any(r.struct.BeginAddress <= START < r.struct.EndAddress for r in pe.DIRECTORY_ENTRY_EXCEPTION)

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = {}
    for lo, hi in ((START, TEXT_END), (RETURN, END)):
        span = list(decoder.disasm(image[lo:hi], lo))
        assert sum(i.size for i in span) == hi-lo
        assert [(i.address,i.size) for i in span] == [(i.ip,i.len) for i in Decoder(64, image[lo:hi], ip=lo)]
        instructions.update((i.address,i) for i in span)
    assert instructions[RETURN].mnemonic == "ret" and instructions[RETURN].size == 1
    guards = {
        0x13022: ("cmp", "r8, 0x80"), 0x13029: ("jge", "0x13037"),
        0x13048: ("and", "r11, 0x3f"), 0x1304c: ("je", "0x13060"),
        0x13060: ("cmp", "r8, 0x200"), 0x13067: ("jl", "0x13192"),
        0x13098: ("sub", "r8, 0x200"), 0x130bb: ("cmp", "r8, 0x200"),
        0x130c2: ("jge", "0x13076"), 0x130eb: ("sub", "r8, 0x200"),
        0x1310e: ("cmp", "r8, 0x200"), 0x13115: ("jge", "0x130c9"),
        0x13117: ("sfence", ""), 0x131e0: ("and", "r8, 0x3f"),
    }
    for site, expected in guards.items():
        i = instructions[site]
        assert (i.mnemonic,i.op_str) == expected, hex(site)

    slots = {base: [base-struct.unpack_from("<q", image, base+index*8)[0]
                    for index in range(count)] for base,count in TABLES.items()}
    assert all(target in instructions for table in slots.values() for target in table)
    dispatch = []
    for jump, load, access, table, index_reg, low, high in DISPATCH:
        assert rip_target(instructions[load]) == table
        access_ins = instructions[access]
        op = access_ins.operands[1]
        assert access_ins.mnemonic == "sub" and op.type == X86_OP_MEM and op.size == 8
        assert access_ins.reg_name(op.mem.base) == "rdx" and access_ins.reg_name(op.mem.index) == index_reg
        assert op.mem.scale == 8 and op.mem.disp == 0
        assert (instructions[jump].mnemonic,instructions[jump].op_str) == ("jmp","rdx")
        dispatch.append({"site":hex(jump), "table":hex(table), "index_register":index_reg,
                         "min_index":low, "max_index":high,
                         "distinct_targets":[hex(v) for v in sorted(set(slots[table][low:high+1]))]})
    direct = {hex(i.address):hex(i.operands[0].imm) for i in instructions.values()
              if i.group(capstone.CS_GRP_JUMP) and i.operands[0].type == X86_OP_IMM}
    assert all(int(target,16) in instructions for target in direct.values())

    read = instructions[0x1306d]
    threshold = rip_target(read)
    assert read.mnemonic == "cmp" and read.operands[1].size == 8 and threshold == 0x22250
    assert pe.get_section_by_rva(threshold).Characteristics & 0x80000000
    field_rva = read.address+read.disp_offset
    with TemporaryDirectory() as temp:
        obj = Path(temp) / "fill.obj"
        command = [str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
                   "-c", str(HERE/"avx512-fill.c"), "-o", str(obj)]
        subprocess.run(command, check=True)
        text, symbols, relocs = objects(obj.read_bytes())
    start = symbols["avx512_fill"]
    end = symbols["avx512_fill_end"]
    assert symbols["avx512_shared_return"] - start == RETURN - START
    field = start+field_rva-START
    assert relocs == [(field, "rva_22250", 4)] and struct.unpack_from("<i", text, field)[0] == 0
    struct.pack_into("<i", text, field, threshold-field_rva-4)
    assert text[start:end] == region

    pick = {i.address:i for i in decoder.disasm(image[0xcd0a:0xcd4a], 0xcd0a)}
    select = {i.address:i for i in decoder.disasm(image[0xccc0:0xccc8], 0xccc0)}
    assert (pick[0xcd10].mnemonic,pick[0xcd10].operands[1].imm) == ("movabs",0x7189d9fee)
    assert (pick[0xcd1a].mnemonic,pick[0xcd1a].op_str) == ("test","r9, r10")
    assert (pick[0xcd1d].mnemonic,pick[0xcd1d].operands[0].imm) == ("jne",0xcd2e)
    assert (pick[0xcd27].mnemonic,pick[0xcd27].operands[0].imm) == ("call",0xccc0)
    assert rip_target(select[0xccc0]) == START and select[0xccc7].mnemonic == "ret"

    if destination:
        destination.mkdir(parents=True, exist_ok=True)
        listing = "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip()+"\n"
                          for i in instructions.values())
        (destination/"instructions.lst").write_text(listing, encoding="utf-8", newline="\n")
        with (destination/"table-slots.csv").open("w", encoding="utf-8", newline="") as f:
            writer = csv.writer(f, lineterminator="\n")
            writer.writerow(("table_rva","index","slot_rva","target_rva","reachable_dispatches"))
            for base, targets in slots.items():
                for index, target in enumerate(targets):
                    reachable = ";".join(hex(jump) for jump,_,_,table,_,low,high in DISPATCH
                                         if table == base and low <= index <= high)
                    writer.writerow((hex(base),index,hex(base+8*index),hex(target),reachable))

    return {
        "original_sha256": ORIGINAL, "range_sha256": RANGE, "range": [hex(START),hex(END)],
        "matched_bytes": len(region), "instructions": len(instructions),
        "alignment_nops": sum(i.mnemonic == "nop" for i in instructions.values()),
        "leaf_unwind_entry": None, "shared_ret": hex(RETURN),
        "tables": {hex(base):count for base,count in TABLES.items()},
        "dispatches": dispatch, "direct_branches": direct,
        "threshold": {"field_rva":hex(field_rva), "target_rva":hex(threshold),
                      "relocation":"AMD64 REL32", "initial_u64":struct.unpack_from("<Q",image,threshold)[0]},
        "selector": {"test_mask":"0x7189d9fee","call_site":"0xcd27","selector_rva":"0xccc0","selected_rva":hex(START)},
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    inputs = parser.parse_args()
    print(json.dumps(evidence(inputs.original, inputs.zig, inputs.evidence_dir), indent=2))
