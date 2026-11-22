"""Assemble the editable initializer and compare it to the fixed original PE."""

from argparse import ArgumentParser
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
RANGE = "0e4c94c415e043053d0da33538058bc9cf4b5bb51638726ffc32969dfa7d9e38"
START, END = 0x14910, 0x14cab
VENDOR, TABLE, RECORDS, COOKIE, COOKIE_CHECK = 0x1a160, 0x1a170, 0x235f0, 0x221c0, 0x18110
VENDOR_BYTES, TABLE_BYTES, RECORD_BYTES = 16, 255 * 8, 4 * 16


def digest(payload):
    return sha256(payload).hexdigest()


def require_equal(actual, expected, label):
    if actual != expected:
        raise ValueError(f"{label} mismatch")


def decode_at(decoder, image, rva):
    instruction = next(decoder.disasm(image[rva:rva + 15], rva, 1))
    assert instruction.address == rva
    return instruction


def rip_operand(instruction):
    return next(
        (operand for operand in instruction.operands
         if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP),
        None,
    )


def build(zig, filename, output):
    subprocess.run(
        [str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
         "-c", str(HERE / filename), "-o", str(output)],
        check=True,
    )
    return output.read_bytes()


def replay_text(code, region, references):
    text, symbols, relocations = objects(code)
    start = symbols["initialize_capability_records"]
    end = symbols["initialize_capability_records_end"]
    require_equal(end - start, len(region), "initializer size")
    expected = {row["field"]: row for row in references}
    named_rvas = {
        "security_cookie": COOKIE, "intel_vendor_signature": VENDOR,
        "cache_descriptors": TABLE, "capability_records": RECORDS,
        "security_check_cookie": COOKIE_CHECK,
    }
    applied = []
    for offset, symbol, kind in relocations:
        site = START + offset - start
        assert start <= offset <= end - 4 and kind == 4
        ref = expected.pop(site)
        addend = struct.unpack_from("<i", text, offset)[0]
        displacement = named_rvas[symbol] + addend - (site + kind)
        target = ref["end"] + displacement
        require_equal(target, ref["target"], f"initializer relocation at {site:#x}")
        struct.pack_into("<i", text, offset, displacement)
        applied.append({"site": hex(ref["site"]), "field_rva": hex(site),
                        "symbol": symbol, "addend": addend, "target_rva": hex(target),
                        "access": ref["access"], "operand_bytes": ref["width"]})
    require_equal(expected, {}, "unbound text references")
    require_equal(text[start:end], region, "initializer text")
    return applied


def replay_unwind(code, image, original, runtime):
    unwind, _, unwind_relocs = objects(code, b".xdata")
    directory, _, directory_relocs = objects(code, b".pdata")
    require_equal(unwind_relocs, [], "unwind relocations")
    require_equal(len(unwind), 28, "unwind size")
    unw_rva = runtime.UnwindData
    require_equal(unwind, image[unw_rva:unw_rva + len(unwind)], "initializer xdata")
    require_equal(directory_relocs, [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)],
                  "runtime-function relocations")
    for offset, section_rva in ((0, START), (4, START), (8, unw_rva)):
        addend = struct.unpack_from("<I", directory, offset)[0]
        struct.pack_into("<I", directory, offset, section_rva + addend)
    offset = runtime.get_file_offset()
    require_equal(directory, original[offset:offset + 12], "initializer pdata")
    return {"rva": hex(unw_rva), "xdata": unwind.hex(), "pdata": directory.hex(),
            "pdata_relocations": len(directory_relocs)}


def replay_data(code, image, pe):
    rdata, rdata_symbols, rdata_relocs = objects(code, b".rdata")
    bss, bss_symbols, bss_relocs = objects(code, b".bss")
    require_equal(rdata_relocs + bss_relocs, [], "capability storage relocations")
    sections = (
        (rdata, rdata_symbols["intel_vendor_signature"], VENDOR, VENDOR_BYTES, "vendor signature"),
        (rdata, rdata_symbols["cache_descriptors"], TABLE, TABLE_BYTES, "descriptor table"),
        (bss, bss_symbols["capability_records"], RECORDS, RECORD_BYTES, "capability zero-fill"),
    )
    matched = {}
    for payload, offset, rva, size, label in sections:
        original = image[rva:rva + size]
        require_equal(payload[offset:offset + size], original, label)
        matched[label] = {"rva": hex(rva), "bytes": size, "sha256": digest(original)}
    section = pe.get_section_by_rva(RECORDS)
    assert section.Name.rstrip(b"\x00") == b".data" and section.Characteristics & 0x80000000
    raw_end = section.VirtualAddress + section.SizeOfRawData
    virtual_end = section.VirtualAddress + section.Misc_VirtualSize
    assert raw_end <= RECORDS < RECORDS + RECORD_BYTES <= virtual_end
    require_equal(bytes(bss), bytes(RECORD_BYTES), "capability initial state")
    require_equal(image[VENDOR:VENDOR + VENDOR_BYTES], b"GenuineIntel\x00\x00\x00\x00",
                  "vendor identity")
    return matched


def check_reference_targets(instructions):
    references = []
    transfers = []
    for instruction in instructions:
        address = instruction.address
        memory = rip_operand(instruction)
        if memory is not None:
            target = address + instruction.size + memory.mem.disp
            access = "address" if instruction.mnemonic == "lea" else (
                "write" if memory.access & capstone.CS_AC_WRITE else "read")
            references.append({"site": address, "field": address + instruction.disp_offset,
                               "end": address + instruction.size,
                               "target": target, "access": access, "width": memory.size})
        if instruction.group(capstone.CS_GRP_JUMP) or instruction.group(capstone.CS_GRP_CALL):
            operand = instruction.operands[0]
            assert operand.type == X86_OP_IMM, hex(address)
            transfers.append({"site": hex(address), "target": hex(operand.imm),
                              "mnemonic": instruction.mnemonic})
            if instruction.group(capstone.CS_GRP_CALL):
                references.append({"site": address, "field": address + instruction.imm_offset,
                                   "end": address + instruction.size,
                                   "target": operand.imm, "access": "call execute", "width": 4})
            else:
                assert START <= operand.imm < END, hex(address)
    return references, transfers


def replay(original, zig, destination):
    source = original.read_bytes()
    require_equal(digest(source), ORIGINAL, "original SHA-256")
    pe = pefile.PE(data=source)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    require_equal(digest(region), RANGE, "initializer SHA-256")
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = list(decoder.disasm(region, START))
    require_equal(sum(ins.size for ins in instructions), len(region), "decoded bytes")
    require_equal([(ins.address, ins.size) for ins in instructions],
                  [(ins.ip, ins.len) for ins in Decoder(64, region, ip=START)], "instruction boundaries")
    ins = {instruction.address: instruction for instruction in instructions}
    references, transfers = check_reference_targets(instructions)

    require_equal(ins[0x14946].operands[1].imm, 0x200000, "EFLAGS ID mask")
    require_equal(ins[0x14951].operands[0].imm, 0x1495b, "EFLAGS unchanged branch")
    require_equal(ins[0x14962].operands[0].imm, 0x14c80, "CPUID availability gate")
    for site, registers, branch in zip((0x1498e, 0x14993, 0x14998),
                                       ("ebx", "edx", "ecx"), (0x14991, 0x14996, 0x1499b)):
        require_equal(ins[site].op_str.split(", ")[1], registers, "CPUID vendor register")
        require_equal(ins[branch].operands[0].imm, 0x149aa, "vendor mismatch branch")
    require_equal(ins[0x149c0].operands[1].imm, 4, "leaf 4 threshold")
    require_equal(ins[0x149c3].operands[0].imm, 0x14ab0, "skip leaf 4 branch")
    require_equal(ins[0x14a08].operands[1].imm, 8, "leaf 4 subleaf limit")
    require_equal(ins[0x14abd].operands[1].imm, 2, "leaf 2 threshold")
    require_equal(ins[0x14b8d].operands[1].imm, 0xff, "descriptor sentinel")
    require_equal(ins[0x14b94].operands[0].imm, 0x14c68, "record-clear branch")
    require_equal(ins[0x14c80].operands[1].imm, 1, "published readiness")
    require_equal({row["site"]: row["target"] for row in references}[0x14c80],
                  RECORDS + 12, "readiness address")
    require_equal(ins[0x14c91].operands[0].imm, COOKIE_CHECK, "stack-cookie check target")
    for site in (0x148ea, 0x14cd3):
        caller = decode_at(decoder, image, site)
        assert caller.group(capstone.CS_GRP_CALL) and caller.operands[0].imm == START

    exception_entries = {
        record.struct.BeginAddress: record.struct for record in pe.DIRECTORY_ENTRY_EXCEPTION
    }
    runtime = exception_entries[START]
    require_equal((runtime.EndAddress, runtime.UnwindData), (END, 0x1c390), "runtime function")
    with TemporaryDirectory() as temporary:
        work = Path(temporary)
        code = build(zig, "initialize-capability-records.c", work / "code.obj")
        storage = build(zig, "initializer-data.c", work / "data.obj")
    applied = replay_text(code, region, references)
    unwind = replay_unwind(code, image, source, runtime)
    matched_data = replay_data(storage, image, pe)
    next_rva = 0x14cb0
    next_end = exception_entries[next_rva].EndAddress
    if destination is not None:
        destination.mkdir(parents=True, exist_ok=True)
        (destination / "instructions.lst").write_text(
            "".join(f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() + "\n"
                    for ins in instructions),
            encoding="utf-8", newline="\n",
        )
    return {
        "original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": RANGE,
        "matched_bytes": len(region), "instructions": len(instructions),
        "coff_text_relocations": applied, "unwind": unwind,
        "direct_transfers": transfers, "incoming_calls": ["0x148ea", "0x14cd3"],
        "matched_storage": matched_data,
        "next_range": {"start_rva": hex(next_rva), "end_rva": hex(next_end),
                       "unwind_rva": hex(exception_entries[next_rva].UnwindData),
                       "sha256": digest(image[next_rva:next_end]), "size": next_end - next_rva},
    }


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(replay(args.original, args.zig, args.evidence_dir), indent=2))
