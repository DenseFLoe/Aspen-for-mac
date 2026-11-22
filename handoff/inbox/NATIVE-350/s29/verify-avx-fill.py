"""Reassemble the s29 AVX fill source and compare it with the pinned PE."""
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

ORIGINAL_SHA256 = '09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b'
RANGE_SHA256 = '49645f46662948f2a0070f7264f5409d006755c2340866023174e70a88ce98fc'
START, TABLE_START, EPILOGUE, END = 0x11F40, 0x122E0, 0x12FF0, 0x12FF8
TABLES = {0x122E0: 32, 0x123E0: 256, 0x12BE0: 130}
DISPATCH = (
    (0x11F78, 0x11F59, 0x11F74, 0x12BE0, 'r8', 0, 128),
    (0x11FA4, 0x11F80, 0x11FA0, 0x122E0, 'rcx', 1, 31),
    (0x12115, 0x1210A, 0x12111, 0x123E0, 'r8', 0, 255),
    (0x1216A, 0x1215F, 0x12166, 0x123E0, 'r8', 0, 31)
)


def rip_target(instruction):
    mem = next(op.mem for op in instruction.operands
               if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)
    return instruction.address + instruction.size + mem.disp


def evidence(original, zig):
    data = original.read_bytes()
    assert sha256(data).hexdigest() == ORIGINAL_SHA256
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == RANGE_SHA256
    records = [r.struct for r in pe.DIRECTORY_ENTRY_EXCEPTION if r.struct.BeginAddress == START]
    assert len(records) == 1 and records[0].EndAddress == END

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = {}
    for lo, hi in ((START, TABLE_START), (EPILOGUE, END)):
        cap = {i.address:i for i in decoder.disasm(image[lo:hi], lo)}
        iced = [(i.ip, i.len) for i in Decoder(64, image[lo:hi], ip=lo)]
        assert list((i.address, i.size) for i in cap.values()) == iced
        assert sum(i.size for i in cap.values()) == hi-lo
        instructions.update(cap)

    actual_listing = ''.join(f'{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}'.rstrip()+'\n'
                             for i in instructions.values())
    assert (HERE/'instructions.lst').read_text(encoding='utf-8') == actual_listing
    symbols = {0x22240: 'shared_fill_threshold_rva_22240'}
    with TemporaryDirectory() as tmp:
        obj = Path(tmp)/'avx-fill.obj'
        subprocess.run([str(zig.resolve()), 'cc', '-target', 'x86_64-windows-gnu', '-O2', '-g0',
                        '-fno-stack-protector', '-fno-asynchronous-unwind-tables', '-c',
                        str(HERE/'avx-fill.c'), '-o', str(obj)], check=True)
        payload, labels, relocs = objects(obj.read_bytes())

    start = labels['avx_fill']
    finish = labels['avx_fill_end']
    read = instructions[0x11FC0]
    reloc_rva = read.address + read.disp_offset
    target = rip_target(read)
    expected_rel = (start+reloc_rva-START, symbols[target], 4)
    assert relocs == [expected_rel] and target == 0x22240
    offset, _, _ = expected_rel
    addend = struct.unpack_from('<i', payload, offset)[0]
    assert addend == 0
    struct.pack_into('<i', payload, offset, target-reloc_rva-4)
    rebuilt = payload[start:finish]
    assert len(rebuilt) == len(region)
    if rebuilt != region:
        address = next(i for i,(actual, expected) in enumerate(zip(rebuilt, region)) if actual != expected)
        raise ValueError(f'First replay mismatch at RVA {START+address:#x}')

    section = pe.get_section_by_rva(target)
    shared = int.from_bytes(image[target:target+8], 'little')
    assert section.Name.rstrip(b'\0') == b'.data' and section.Characteristics & 0x80000000
    assert read.mnemonic == 'mov' and read.operands[1].size == 8

    table_targets = {base:[base-struct.unpack_from('<Q', image, base+index*8)[0]
                           for index in range(count)] for base,count in TABLES.items()}
    assert all(site in instructions for slots in table_targets.values() for site in slots)
    guards = {
        0x11F65: ('cmp', 'r8, 0x80'), 0x11F6C: ('ja', '0x11f80'),
        0x11F8A: ('and', 'rcx, 0x1f'), 0x11F8E: ('je', '0x11fb3'),
        0x11F90: ('neg', 'rcx'), 0x11F93: ('add', 'rcx, 0x20'),
        0x11FB3: ('cmp', 'r8, 0x100'), 0x11FBA: ('jl', '0x120f0'),
        0x11FC7: ('mov', 'rdi, rcx'), 0x11FCA: ('shr', 'rcx, 4'),
        0x11FCE: ('sub', 'rdi, rcx'), 0x11FD1: ('cmp', 'r8, rdi'), 0x11FD4: ('jae', '0x12030'),
        0x11FF9: ('sub', 'r8, 0x100'), 0x12018: ('cmp', 'r8, 0x100'), 0x1201F: ('jge', '0x11fdb'),
        0x1215B: ('and', 'r8, 0x1f')
    }
    for site, expected in guards.items():
        ins = instructions[site]
        assert (ins.mnemonic, ins.op_str) == expected, hex(site)

    indexed = []
    for jump, lea, access, table, index, lo, hi in DISPATCH:
        assert rip_target(instructions[lea]) == table
        fetch = instructions[access]
        op = fetch.operands[1]
        assert fetch.mnemonic == 'sub' and op.type == X86_OP_MEM and op.size == 8
        assert fetch.reg_name(op.mem.base) == 'rdx' and fetch.reg_name(op.mem.index) == index and op.mem.scale == 8
        final = instructions[jump]
        assert final.mnemonic == 'notrack jmp' and final.op_str == 'rdx'
        indexed.append(dict(site=hex(jump), table_address_instruction=hex(lea), slot_read=hex(access),
                            table=hex(table), index_register=index, index_min=lo, index_max=hi,
                            distinct_targets=[hex(t) for t in sorted(set(table_targets[table][lo:hi+1]))]))

    with (HERE/'table-slots.csv').open(encoding='utf-8', newline='') as f:
        actual_slots = list(csv.reader(f))
    expected_slots = [['table_rva','slot_index','slot_rva','target_rva','reachable_from']]
    for base, values in table_targets.items():
        for index, addr in enumerate(values):
            reachable = ';'.join(hex(jump) for jump,_,_,t,_,lo,hi in DISPATCH if t == base and lo <= index <= hi)
            expected_slots.append([hex(base),str(index),hex(base+index*8),hex(addr),reachable])
    assert actual_slots == expected_slots

    upstream = {i.address:i for i in decoder.disasm(image[0xCCB0:0xCD7B],0xCCB0)}
    assert rip_target(upstream[0xCCB0]) == START and upstream[0xCCB7].mnemonic == 'ret'
    assert upstream[0xCD10].operands[1].imm == 0x7189D9FEE
    assert upstream[0xCD34].mnemonic == 'test' and upstream[0xCD34].operands[1].imm == 0x9D9FEE
    assert upstream[0xCD45].mnemonic == 'call' and upstream[0xCD45].operands[0].imm == 0xCCB0
    assert upstream[0xCD78].mnemonic == 'jmp' and upstream[0xCD78].op_str == 'rax'

    direct = {hex(i.address):hex(i.operands[0].imm) for i in instructions.values()
              if i.group(capstone.CS_GRP_JUMP) and i.operands[0].type == X86_OP_IMM}
    assert {int(t,16) for t in direct.values()} <= instructions.keys()
    return {
        'original_sha256':ORIGINAL_SHA256, 'range':[hex(START),hex(END)], 'range_sha256':RANGE_SHA256,
        'unwind_rva':hex(records[0].UnwindData), 'matched_bytes':len(rebuilt),
        'compiler':'Zig '+subprocess.check_output([str(zig.resolve()),'version'],text=True).strip(),
        'instruction_count':len(instructions),
        'alignment_nops':sum(i.mnemonic == 'nop' for i in instructions.values()),
        'instruction_bytes':sum(i.size for i in instructions.values()),
        'table_storage_slots':sum(TABLES.values()), 'table_bytes':EPILOGUE-TABLE_START,
        'table_populations':{hex(base):count for base,count in TABLES.items()},
        'direct_branches':direct, 'indexed_jumps':indexed,
        'relocation':dict(kind='AMD64 REL32', field_rva=hex(reloc_rva), target_rva=hex(target), addend=addend),
        'shared_threshold':dict(read_rva=hex(read.address), storage_rva=hex(target), section='.data',
                                width=read.operands[1].size, initial_value=shared,
                                initial_effective_cutoff=shared-(shared>>4)),
        'upstream_dispatch':dict(mask='0x9d9fee', test_rva='0xcd34', call_rva='0xcd45',
                                 helper_rva='0xccb0', cached_jump_rva='0xcd78', selected_fill_rva=hex(START))
    }


if __name__ == '__main__':
    parser = ArgumentParser(description=__doc__)
    parser.add_argument('original',type=Path)
    parser.add_argument('zig',type=Path)
    args = parser.parse_args()
    print(json.dumps(evidence(args.original,args.zig),indent=2,sort_keys=True))
