"""Rebuild the original zedstwu.dll high-capability copy and verify its indexed transfers."""
import argparse
import csv
from hashlib import sha256
import io
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

import capstone as cs
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_RIP
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

ORIGINAL_SHA = '09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b'
BODY_SHA = '86177c7f8c319b6bfcfd11f4a4499c414db8fd18d7df16401ed7ff2ab844cfea'
START, TABLE_START, EPILOGUE, END = 0xe5c0, 0xeac0, 0x100c0, 0x100c2
TABLES = {0xeac0: 64, 0xecc0: 512, 0xfcc0: 128}
# Dispatch, table LEA, indexed SUB, original table RVA, index register, minimum, maximum.
JUMPS = (
    (0xe5e4, 0xe5c4, 0xe5e0, 0xfcc0, 'r8', 0, 127),
    (0xe611, 0xe5e7, 0xe60d, 0xeac0, 'rsi', 1, 63),
    (0xe951, 0xe946, 0xe94d, 0xecc0, 'r8', 0, 511),
    (0xe9c1, 0xe9b6, 0xe9bd, 0xecc0, 'rsi', 0, 63),
)
THRESHOLD = 0x22238


def textual(ins):
    return f'{ins.mnemonic} {ins.op_str}'.rstrip()


def rip_operand(ins):
    return next((ins.address + ins.size + op.mem.disp for op in ins.operands
                 if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP), None)


def csv_text(rows):
    output = io.StringIO(newline='')
    writer = csv.DictWriter(output, fieldnames=list(rows[0]), lineterminator='\n')
    writer.writeheader()
    writer.writerows(rows)
    return output.getvalue()


def decode(pe, decoder, start, end):
    raw = pe.get_data(start, end-start)
    instructions = list(decoder.disasm(raw, start))
    independent = list(Decoder(64, raw, ip=start))
    assert len(raw) == sum(ins.size for ins in instructions) == end-start
    assert [(i.address, i.size) for i in instructions] == [(i.ip, i.len) for i in independent]
    assert all(not i.is_invalid for i in independent)
    return instructions


def check_guards(index):
    guards = {
        0xe5c0: 'push rsi', 0xe5c1: 'mov rax, rcx', 0xe5cb: 'cmp r8, 0x80',
        0xe5d2: 'jge 0xe5e7', 0xe5ee: 'mov rsi, rcx', 0xe5f1: 'neg rsi',
        0xe5f4: 'add rsi, 0x40', 0xe5f8: 'and rsi, 0x3f', 0xe5fc: 'je 0xe61a',
        0xe5fe: 'sub r8, rsi', 0xe614: 'add rcx, rsi', 0xe617: 'add rdx, rsi',
        0xe61a: 'cmp r8, 0x200', 0xe621: 'jl 0xe927', 0xe62e: 'jae 0xe701',
        0xe694: 'sub r8, 0x200', 0xe6ef: 'cmp r8, 0x200', 0xe6f6: 'jge 0xe634',
        0xe6fc: 'jmp 0xe927',
        0xe802: 'sub r8, 0x200', 0xe85d: 'cmp r8, 0x200', 0xe864: 'jge 0xe7a2',
        0xe86a: 'sfence', 0xe86d: 'jmp 0xe927',
        0xe927: 'mov r10, rcx', 0xe92a: 'add r10, r8', 0xe92d: 'mov rsi, r10',
        0xe930: 'add rcx, r8', 0xe933: 'and rcx, 0xffffffffffffffc0',
        0xe93d: 'sub rsi, rcx', 0x100c0: 'pop rsi', 0x100c1: 'ret',
    }
    for address, expected in guards.items():
        assert textual(index[address]) == expected, hex(address)
    assert index[0xe627].mnemonic == 'cmp' and index[0xe627].op_str.startswith('r8, qword ptr')
    assert {i.mnemonic for i in index.values()} >= {'vmovdqu64', 'vmovaps', 'vmovntdq'}
    return {hex(address): text for address, text in guards.items()}


def check_tables(pe, index):
    targets, rows = {}, []
    expected_end = TABLE_START
    base_relocations = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC
                        for entry in block.entries if entry.type != 0}
    for base, count in TABLES.items():
        assert base == expected_end
        offsets = struct.unpack(f'<{count}Q', pe.get_data(base, count*8))
        targets[base] = [base-offset for offset in offsets]
        for idx, (offset, target) in enumerate(zip(offsets, targets[base])):
            slot = base + idx*8
            assert target in index and START <= target < TABLE_START and slot not in base_relocations
            rows.append(dict(table=hex(base),index=idx,slot=hex(slot),difference=hex(offset),target=hex(target)))
        expected_end = base + count*8
    assert expected_end == EPILOGUE
    jumps = []
    for site, load, read, base, reg, low, high in JUMPS:
        dispatch, lea, ins = index[site], index[load], index[read]
        assert textual(dispatch) == 'jmp r9' and dispatch.address == ins.address + ins.size
        assert lea.mnemonic == 'lea' and lea.op_str.startswith('r9, ') and rip_operand(lea) == base
        assert ins.mnemonic == 'sub' and ins.operands[0].type == X86_OP_REG
        assert ins.reg_name(ins.operands[0].reg) == 'r9' and ins.operands[1].type == X86_OP_MEM
        mem = ins.operands[1].mem
        assert (ins.reg_name(mem.base), ins.reg_name(mem.index), mem.scale, mem.disp) == ('r9', reg, 8, 0)
        assert 0 <= low <= high < len(targets[base])
        jumps.append(dict(site=hex(site),table_lea=hex(load),indexed_sub=hex(read),index=reg,
                          first_index=low,last_index=high,table=hex(base),
                          targets=[hex(addr) for addr in sorted(set(targets[base][low:high+1]))]))
    # Destination alignment after the optional prefix makes length and the
    # unaligned end's low six bits refer to the same tail case family.
    tail = targets[0xecc0]
    assert all(0xe954 <= tail[index] < 0xe9b6 for index in range(64, 512))
    assert all(0xe9c4 <= tail[index] < TABLE_START for index in range(64))
    return jumps, rows


def verify(original, zig):
    file_bytes = original.read_bytes()
    assert sha256(file_bytes).hexdigest() == ORIGINAL_SHA
    pe = pefile.PE(data=file_bytes)
    assert {(r.struct.BeginAddress, r.struct.EndAddress) for r in pe.DIRECTORY_ENTRY_EXCEPTION} >= {(START, END)}
    expected = pe.get_data(START, END-START)
    assert sha256(expected).hexdigest() == BODY_SHA
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    instructions = decode(pe, decoder, START, TABLE_START) + decode(pe, decoder, EPILOGUE, END)
    index = {ins.address: ins for ins in instructions}
    guards = check_guards(index)
    jumps, slots = check_tables(pe, index)
    indexed_tables = {int(row['site'], 0): row['table'] for row in jumps}
    assert rip_operand(index[0xe627]) == THRESHOLD
    assert {rip_operand(ins) for ins in instructions} - {None} == set(TABLES) | {THRESHOLD}
    threshold_section = pe.get_section_by_rva(THRESHOLD)
    assert threshold_section.Name.rstrip(b'\0') == b'.data' and threshold_section.Characteristics & 0x80000000
    threshold_initial = struct.unpack('<Q', pe.get_data(THRESHOLD, 8))[0]
    assert threshold_initial == 65536
    initialized = decode(pe, decoder, 0xcc58, 0xcc5d)
    getter = decode(pe, decoder, 0xcbf0, 0xcbf8)
    assert textual(initialized[0]) == 'call 0xcbf0' and rip_operand(getter[0]) == START
    assert textual(getter[1]) == 'ret'

    references = []
    for ins in instructions:
        assert not ins.group(cs.CS_GRP_CALL)
        target = rip_operand(ins)
        if target is not None:
            role, value = 'RIP-relative address or data', hex(target)
        elif ins.group(cs.CS_GRP_JUMP):
            if ins.operands[0].type == X86_OP_IMM:
                assert ins.operands[0].imm in index
                role, value = 'direct branch', hex(ins.operands[0].imm)
            else:
                role, value = 'indexed jump', indexed_tables[ins.address]
        elif ins.mnemonic != 'nop' and any(op.type == X86_OP_MEM for op in ins.operands):
            role, value = 'register-relative memory or address', ins.op_str
        else:
            continue
        references.append(dict(owner=hex(START),site=hex(ins.address),role=role,
                               operand_or_target=value,instruction=textual(ins)))

    compiler = str(zig.resolve())
    with tempfile.TemporaryDirectory() as work:
        obj = Path(work) / 'copy-high.obj'
        subprocess.run([compiler, 'cc', '-target', 'x86_64-windows-gnu', '-O2', '-g0',
                        '-fno-stack-protector', '-fno-asynchronous-unwind-tables',
                        '-c', str(HERE / 'copy-high.c'), '-o', str(obj)], check=True)
        rebuilt, symbols, relocs = objects(obj.read_bytes())
    offset = index[0xe627].address + index[0xe627].disp_offset - START
    symbol = 'stream_threshold_rva_22238'
    assert symbols['copy_high'] == 0 and relocs == [(offset, symbol, 4)]
    assert rebuilt[offset:offset+4] == bytes(4)
    displacement = THRESHOLD - (START + offset + 4)
    struct.pack_into('<i', rebuilt, offset, displacement)
    assert rebuilt == expected
    executable = sum(ins.size for ins in instructions)
    report = dict(original_sha256=ORIGINAL_SHA, start=hex(START), end=hex(END), range_sha256=BODY_SHA,
                  compiler=subprocess.check_output([compiler, 'version'], text=True).strip(),
                  matched_bytes=len(rebuilt), instructions=len(instructions), instruction_bytes=executable,
                  table_bytes=len(rebuilt)-executable, table_slots=len(slots), alignment_nops=sum(
                      ins.mnemonic == 'nop' for ins in instructions), indexed_jumps=jumps, guards=guards,
                  relocation=dict(kind='IMAGE_REL_AMD64_REL32', operand_rva=hex(START + offset),
                                  symbol=symbol, target=hex(THRESHOLD), displacement=displacement),
                  threshold=dict(rva=hex(THRESHOLD), width=8, initial_value=threshold_initial),
                  initializer=dict(site='0xcc58', getter='0xcbf0', target=hex(START)),
                  bounds_domain='Nonnegative Windows user-mode copy lengths below the signed 64-bit limit.')
    listing = [f'{ins.address:08x}  {ins.bytes.hex(" ")}  {textual(ins)}' for ins in instructions]
    return {'rebuild.json': json.dumps(report, indent=2)+'\n', 'instructions.lst': '\n'.join(listing)+'\n',
            'references.csv': csv_text(references), 'table-slots.csv': csv_text(slots)}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path)
    parser.add_argument('zig', type=Path)
    parser.add_argument('--write', action='store_true', help='regenerate the four evidence files')
    args = parser.parse_args()
    for name, content in verify(args.original, args.zig).items():
        output = HERE / name
        if args.write:
            output.write_bytes(content.encode('utf-8'))
        else:
            assert output.read_bytes() == content.encode('utf-8'), name
    print('Verified the 6,914-byte range, one COFF REL32 relocation and 704 symbolic slots for four jumps.')
