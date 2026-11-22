"""Trace the ppexec.dll callback slots against the verified original code ranges."""

import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP


ORIGINAL = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
TABLES = {0x8EA0: (0x9590, 0xA698), 0xA6C0: (0xABC0, 0xC1C0),
          0xE040: (0xE3E0, 0xF0F0), 0xF100: (0xF3C0, 0x109C0)}
INTEREST = {0x12188, 0x11B24, 0x1283C, 0x12450, 0x14C40, 0x14C60, 0x15D18, 0x20A80, 0x22148}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def instruction_references(insn):
    for operand in insn.operands:
        if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
            yield insn.address + insn.size + operand.mem.disp
        if operand.type == X86_OP_IMM and (insn.group(cs.CS_GRP_CALL) or insn.group(cs.CS_GRP_JUMP)):
            yield operand.imm


def describe(insn):
    return {"rva": hex(insn.address), "bytes": insn.bytes.hex(),
            "instruction": (insn.mnemonic + " " + insn.op_str).strip()}


def scan(image, unit):
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    spans = json.loads((unit / "reassembly.json").read_text(encoding="utf-8"))["matches"]
    spans += json.loads((unit / "s5/reassembly.json").read_text(encoding="utf-8"))
    instructions = {}
    references = defaultdict(list)
    require(len(spans) == 532, "expected 532 verified code ranges")
    for item in spans:
        start = int(item["rva"], 16)
        end = start + item["bytes"]
        require(hashlib.sha256(image[start:end]).hexdigest() == item["sha256"], f"range hash {start:#x}")
        ranges = [(start, end)]
        if start in TABLES:
            left, right = TABLES[start]
            ranges = [(start, left), (right, end)]
        for lo, hi in ranges:
            for insn in decoder.disasm(image[lo:hi], lo):
                require(insn.address not in instructions, f"overlapping decoded range at {insn.address:#x}")
                instructions[insn.address] = insn
                for dest in set(instruction_references(insn)) & INTEREST:
                    references[dest].append(insn.address)
    require(len(instructions) == 12498, "decoded instruction count differs")
    return instructions, references


def trace(original, unit):
    raw = original.read_bytes()
    require(hashlib.sha256(raw).hexdigest() == ORIGINAL, "original SHA-256 differs")
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    instructions, refs = scan(image, unit)
    require(refs[0x12188] == [0x14E06], "private helper has another visible caller or address reference")
    require(refs[0x12450] == [0x11C27] and refs[0x22148] == [0x12450], "optional slot references differ")
    require(not refs[0x1283C], "registration helper has a new direct reference")
    require(set(refs[0x20A80]) == {0x127E8, 0x12804, 0x1283C, 0x12941}, "registration slot references differ")
    exports = {e.address: e.name.decode() for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.address in INTEREST}
    require(not exports, "an internal callback dependency is exported")

    cfg = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    require(cfg.GuardCFFunctionTable == cfg.GuardCFFunctionCount == 0, "unexpected Guard CF target membership")
    require(cfg.GuardCFDispatchFunctionPointer - base == 0x15D00, "CFG dispatch slot differs")
    require(cfg.GuardXFGDispatchFunctionPointer - base == 0x15D08
            and cfg.GuardXFGTableDispatchFunctionPointer - base == 0x15D10, "XFG dispatch slots differ")
    require(cfg.CastGuardOsDeterminedFailureMode - base == 0x15D18, "CastGuard hook slot differs")
    require(all(image[rva:rva+8] == bytes(8) for rva in (0x15D18, 0x20A80, 0x22148)), "slot initializer differs")
    require(describe(instructions[0x14C40])["instruction"] == "jmp rax", "expected JMP RAX fallback")
    require(list(instruction_references(instructions[0x14C60])) == [0x15D00], "XFG fallback forwarding differs")
    relocations = []
    for block in pe.DIRECTORY_ENTRY_BASERELOC:
        for entry in block.entries:
            if entry.type != 10:
                continue
            dest = int.from_bytes(image[entry.rva:entry.rva + 8], "little") - base
            if dest in INTEREST:
                relocations.append((entry.rva, dest))
    require(sorted(relocations) == [(0x15D00, 0x14C40), (0x15D08, 0x14C60), (0x15D10, 0x14C60), (0x19A80, 0x15D18)],
            f"original DIR64 references differ: {relocations!r}")

    flow = {
        0x14DF4: "lea r9, [rip - 0x32d7]", 0x14DFB: "mov r8, qword ptr [rbp + 0x70]",
        0x14DFF: "mov edx, dword ptr [rbp + 0x68]", 0x14E02: "mov rcx, qword ptr [rbp + 0x60]",
        0x14E06: "call 0x12188", 0x1219C: "mov rdi, r9", 0x1219F: "mov rsi, r8",
        0x121A2: "mov ebx, edx", 0x121A4: "mov rbp, rcx", 0x121A7: "call 0x12c64",
        0x121AC: "test eax, eax", 0x121AE: "jne 0x121c6", 0x121B0: "cmp ebx, 1",
        0x121B3: "jne 0x121c6", 0x121B5: "mov r8, rsi", 0x121B8: "xor edx, edx",
        0x121BA: "mov rcx, rbp", 0x121BD: "mov rax, rdi", 0x121C0: "call qword ptr [rip + 0x3b3a]",
        0x1283C: "xchg qword ptr [rip + 0xe23d], rcx", 0x12843: "mov rax, rcx", 0x12846: "ret",
    }
    for site, expected in flow.items():
        require(describe(instructions[site])["instruction"] == expected, f"callback flow differs at {site:#x}")
    return {
        "original_sha256": ORIGINAL, "range_count": 532, "decoded_instructions": len(instructions),
        "local_callback": {"caller": "0x14e06", "helper": "0x12188", "site": "0x121c0",
                           "target": "0x11b24", "dispatch_slot": "0x15d00"},
        "references": {hex(target): [describe(instructions[rva]) for rva in sorted(refs[target])]
                       for target in sorted(INTEREST)},
        "dir64_relocations": [{"slot": hex(rva), "destination": hex(dest)} for rva, dest in relocations],
        "flow": [describe(instructions[rva]) for rva in flow],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("unit", type=Path)
    args = parser.parse_args()
    print(json.dumps(trace(args.original, args.unit), indent=2))


if __name__ == "__main__":
    main()
