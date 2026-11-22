"""Compare the editable AMD64 exit callback and document its original references."""
from argparse import ArgumentParser
from hashlib import sha256
import json
from pathlib import Path
import struct
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies

START, END = 0x397c0, 0x3980e
RANGE_SHA256 = "bd270f5ab561e9e801385f5289f0496648d6219bceb4e269f0c9dc483ddacad6"


def evidence(original, zig, destination):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == RANGE_SHA256
    entry, = [r.struct for r in pe.DIRECTORY_ENTRY_EXCEPTION if r.struct.BeginAddress == START]
    assert (entry.EndAddress, entry.UnwindData) == (END, 0x44660)
    unwind = image[entry.UnwindData:entry.UnwindData+8]
    assert unwind == bytes.fromhex("0106020006320230")

    with TemporaryDirectory() as temp:
        obj = Path(temp) / "exit-callback.obj"
        compile_bodies(HERE / "exit-callback.c", zig, obj)
        matched = compare(obj.read_bytes(), image, {START: END-START})[START]

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = {i.address: i for i in decoder.disasm(image[START:END], START)}
    assert sum(i.size for i in instructions.values()) == END-START
    reads = {
        i.address: i.address+i.size+op.mem.disp
        for i in instructions.values() for op in i.operands
        if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP
    }
    assert reads == {0x397c6:0x527b0, 0x397cd:0x527b8, 0x397ed:0x527b8, 0x397fd:0x540e0}
    assert (instructions[0x397e8].mnemonic, instructions[0x397e8].op_str) == ("xor", "ecx, ecx")
    call = instructions[0x397ea]
    assert call.mnemonic == "call" and call.op_str == "qword ptr [rax + 0x38]"
    tail = instructions[0x39809]
    assert tail.mnemonic == "jmp" and tail.operands[0].imm == 0x33ac0

    registration = {i.address:i for i in decoder.disasm(image[0x1288:0x12a0], 0x1288)}
    reg = registration[0x1288]
    assert reg.mnemonic == "lea" and reg.address+reg.size+reg.operands[1].mem.disp == START
    assert registration[0x129b].mnemonic == "jmp" and registration[0x129b].operands[0].imm == 0x354a4

    image_base = pe.OPTIONAL_HEADER.ImageBase
    links = {site: struct.unpack_from("<Q", image, site)[0] - image_base
             for site in (0x527b0, 0x527b8, 0x49310, 0x40ac8)}
    assert links == {0x527b0:0x49310, 0x527b8:0x49318, 0x49310:0x40a90, 0x40ac8:0x12e0}
    relocations = {e.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for e in block.entries if e.type == 10}
    assert links.keys() <= relocations
    assert all(pe.get_section_by_rva(site).Characteristics & 0x80000000 for site in (0x527b0, 0x527b8))
    assert all(not pe.get_section_by_rva(site).Characteristics & 0x80000000 for site in (0x49310, 0x40ac8))

    if destination:
        destination.mkdir(parents=True, exist_ok=True)
        listing = "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip()+"\n"
                          for i in instructions.values())
        (destination / "instructions.lst").write_text(listing, encoding="utf-8", newline="\n")
    return {
        "original_sha256": ORIGINAL,
        "range": [hex(START), hex(END)],
        "instructions": len(instructions), "unwind_rva": hex(entry.UnwindData),
        "unwind_bytes": unwind.hex(), "reassembly": matched,
        "registration": {"argument_site":"0x1288", "atexit_tail":"0x129b", "atexit_rva":"0x354a4"},
        "rip_references": {hex(k):hex(v) for k,v in reads.items()},
        "indirect": {"site":"0x397ea", "offset":"0x38", "arg0":0, "runtime_target":"unresolved"},
        "initial_dir64_links": {hex(k):hex(v) for k,v in links.items()},
        "direct_tail": {"site":"0x39809", "target":"0x33ac0", "arg0_address":"0x540e0"},
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    inputs = parser.parse_args()
    print(json.dumps(evidence(inputs.original, inputs.zig, inputs.evidence_dir), indent=2))
