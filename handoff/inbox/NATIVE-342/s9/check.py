"""Replay the two ApwnIPShell.dll bodies and audit the four runtime ranges."""
import argparse
import hashlib
import json
from pathlib import Path
import runpy
import struct
import tempfile

import capstone
from capstone import x86
import pefile

ROOT = Path(__file__).resolve().parent
ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
BODIES = {0x11f0: 0x12a0, 0x1570: 0x1671}
RANGES = {0x11f0: 0x12a0, 0x1570: 0x15ab, 0x15ab: 0x15f6, 0x15f6: 0x1671}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def decode_bodies(image, disassembler):
    instructions = {}
    for start, stop in BODIES.items():
        span = list(disassembler.disasm(image[start:stop], start))
        indexed = {i.address: i for i in span}
        require(span and span[-1].address + span[-1].size == stop, f"Decoder stops in body {start:#x}")
        pending = [start]
        seen = set()
        while pending:
            site = pending.pop()
            if site in seen:
                continue
            require(site in indexed, f"Branch enters non-instruction at {site:#x}")
            instruction = indexed[site]
            seen.add(site)
            if instruction.group(capstone.CS_GRP_JUMP):
                target = instruction.operands[0]
                require(target.type == x86.X86_OP_IMM, f"Unknown jump at {site:#x}")
                if start <= target.imm < stop:
                    pending.append(target.imm)
                else:
                    require(site == 0x129b and target.imm == 0x354a4, f"Unexpected exit at {site:#x}")
            if not instruction.group(capstone.CS_GRP_RET) and instruction.mnemonic != "jmp":
                pending.append(site + instruction.size)
        require(seen == set(indexed), f"Some code at {start:#x} is unreachable")
        instructions.update(indexed)
    return instructions


def unwind_ranges(pe, image, instructions):
    entries = {r.struct.BeginAddress: (r.struct.EndAddress, r.struct.UnwindData)
               for r in pe.DIRECTORY_ENTRY_EXCEPTION}
    table = []
    for start, stop in RANGES.items():
        actual_stop, unwind_rva = entries[start]
        require(actual_stop == stop and start in instructions, f"Incorrect runtime range at {start:#x}")
        version_flags, _, codes, _ = image[unwind_rva:unwind_rva + 4]
        require(version_flags & 7 == 1, "Unsupported unwind version")
        flags = version_flags >> 3
        parent = None
        if flags & 4:
            payload = unwind_rva + 4 + 2 * ((codes + 1) & ~1)
            parent_tuple = struct.unpack_from("<III", image, payload)
            parent = parent_tuple[0]
            require(entries[parent] == parent_tuple[1:], "Chained unwind tuple does not match .pdata")
        expected_parent = 0x1570 if start in (0x15ab, 0x15f6) else None
        require(parent == expected_parent, f"Unexpected unwind owner for {start:#x}")
        span = image[start:stop]
        table.append({"rva": hex(start), "end": hex(stop), "unwind": hex(unwind_rva),
                      "flags": flags, "parent": hex(parent) if parent else None,
                      "instructions": sum(start <= i < stop for i in instructions),
                      "sha256": hashlib.sha256(span).hexdigest()})
    require(instructions[0x15a4].address + instructions[0x15a4].size == 0x15ab, "Expected fallthrough")
    require(instructions[0x15a2].operands[0].imm == 0x15f6, "Expected null-branch target")
    require(instructions[0x15f4].operands[0].imm == 0x1634, "Expected shared epilogue")
    return table


def callback_seed(pe, image, instructions):
    base = pe.OPTIONAL_HEADER.ImageBase
    relocations = {entry.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for entry in block.entries
                   if entry.type == 10}

    def pointer(slot):
        require(slot in relocations, f"Missing DIR64 pointer at {slot:#x}")
        return struct.unpack_from("<Q", image, slot)[0] - base

    def rip_rva(site):
        instruction = instructions[site]
        memory, = [o.mem for o in instruction.operands if o.type == x86.X86_OP_MEM]
        require(memory.base == x86.X86_REG_RIP, "Expected RIP-relative address")
        return site + instruction.size + memory.disp

    begin, limit = (rip_rva(site) for site in (0x124a, 0x1251))
    first, end = pointer(begin), pointer(limit)
    require(end - first == 8, "Expected one initial callback descriptor")
    descriptor = pointer(first)
    invoke = instructions[0x126e]
    operand = invoke.operands[0]
    require(invoke.mnemonic == "call" and operand.type == x86.X86_OP_MEM and
            operand.mem.base == x86.X86_REG_RAX, "Expected indirect call through descriptor")
    callback_slot = descriptor + operand.mem.disp
    target = pointer(callback_slot)
    require(pe.get_section_by_rva(target).Characteristics & 0x20000000, "Callback seed must be executable")
    require(all(pe.get_section_by_rva(rva).Characteristics & 0x80000000 for rva in (begin, limit)),
            "Expected writable bounds")
    return {"site": "0x126e", "bounds": [hex(begin), hex(limit)], "initial_begin": hex(first),
            "initial_end": hex(end), "descriptor": hex(descriptor), "slot": hex(callback_slot),
            "on_disk_target": hex(target), "target_at_runtime_proven": False}


def named_exports(pe, image, instructions):
    base = pe.OPTIONAL_HEADER.ImageBase
    imports = {imp.address - base: (dll.dll, imp.name) for dll in pe.DIRECTORY_ENTRY_IMPORT
               for imp in dll.imports}

    def operand_rva(site):
        ins = instructions[site]
        memory, = [o.mem for o in ins.operands if o.type == x86.X86_OP_MEM]
        require(memory.base == x86.X86_REG_RIP, "Expected RIP-relative operand")
        return site + ins.size + memory.disp

    def literal(site):
        at = operand_rva(site)
        return image[at:image.index(0, at)].decode("ascii")

    handle_import = imports[operand_rva(0x1596)]
    require(handle_import == (b"KERNEL32.dll", b"GetModuleHandleA"), "Wrong module lookup")
    module = literal(0x158f)
    require(instructions[0x159c].op_str == "rsi, rax", "Missing handle preservation")
    for at, expected in ((0x15b3, "rcx, rax"), (0x15c3, "rcx, rsi"), (0x15d6, "rcx, rsi")):
        require(instructions[at].op_str == expected, f"Unexpected module argument at {at:#x}")
    result = []
    for site, name_at, lookup_at, reg, saved_at in (
            (0x15e2, 0x15cf, 0x15dc, "rax", None),
            (0x15e6, 0x15bc, 0x15c9, "rbx", 0x15d9),
            (0x15ea, 0x15a4, 0x15b6, "rdi", 0x15c6)):
        require(imports[operand_rva(lookup_at)] == (b"KERNEL32.dll", b"GetProcAddress"),
                f"Wrong symbol lookup at {lookup_at:#x}")
        require(instructions[site].mnemonic == "call" and instructions[site].op_str == reg,
                f"Wrong result register at {site:#x}")
        if saved_at is not None:
            require(instructions[saved_at].op_str == f"{reg}, rax", "Wrong saved result register")
        result.append({"site": hex(site), "module_string": module, "symbol": literal(name_at),
                       "lookup": hex(lookup_at), "result_register": reg})
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    args = parser.parse_args()
    data = args.original.read_bytes()
    require(hashlib.sha256(data).hexdigest() == ORIGINAL, "Original SHA-256 differs")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    disassembler.detail = True
    instructions = decode_bodies(image, disassembler)
    ranges = unwind_ranges(pe, image, instructions)
    callback = callback_seed(pe, image, instructions)
    external = named_exports(pe, image, instructions)

    listing = [f"{a:#x}  {i.bytes.hex():22s}  {i.mnemonic} {i.op_str}".rstrip()
               for a, i in instructions.items()]
    require((ROOT / "instructions.asm").read_text(encoding="utf-8").splitlines() == listing,
            "Recorded instruction listing differs")
    prior = runpy.run_path(str(ROOT.parent / "s5/reassemble.py"))
    with tempfile.TemporaryDirectory() as directory:
        obj = Path(directory) / "s9.obj"
        prior["compile_bodies"](ROOT / "verified.c", args.compiler, obj)
        matches = prior["compare"](obj.read_bytes(), image, {a: b - a for a, b in BODIES.items()})
    require(matches.keys() == BODIES.keys(), "One or more assembled bodies differ")
    result = {"original_sha256": ORIGINAL, "instructions": len(instructions),
              "bytes": sum(x["bytes"] for x in matches.values()),
              "relocations": sum(len(x["relocations"]) for x in matches.values()),
              "ranges": ranges, "matches": list(matches.values()),
              "callback_seed": callback, "external_lookups": external}
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
