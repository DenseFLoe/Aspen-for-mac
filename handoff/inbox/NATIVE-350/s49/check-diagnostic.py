"""Reassemble the diagnostic helper and compare COFF code and data to the PE."""
import argparse
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

START, END = 0x15180, 0x15220
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE = "3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef"
BINDINGS = {
    "security_cookie": 0x221C0,
    "message_for_index": 0x15000,
    "stdio_options_address": 0x158D8,
    "diagnostic_buffer": 0x23850,
    "common_vsprintf_thunk": 0x180DE,
    "message_format": 0x1A987,
    "newline_format": 0x1A985,
    "write_diagnostic": 0x185B0,
    "check_security_cookie": 0x18110,
}


def equal(actual, expected, label):
    if actual != expected:
        raise ValueError(f"{label} differs")


def build(compiler, source, output):
    subprocess.run([str(compiler.resolve()), "cc", "-target", "x86_64-windows-gnu",
                    "-g0", "-O2", "-c", str(HERE / source), "-o", str(output)], check=True)
    return output.read_bytes()


def decode(region):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    instructions = list(decoder.disasm(region, START))
    equal(sum(i.size for i in instructions), len(region), "decoded length")
    equal([(i.address, i.size) for i in instructions],
          [(i.ip, i.len) for i in Decoder(64, region, ip=START)], "instruction boundaries")
    sites = {i.address for i in instructions}
    refs, transfers = {}, []
    for ins in instructions:
        next_ip = ins.address + ins.size
        for op in ins.operands:
            if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                refs[ins.address + ins.disp_offset] = (
                    ins.address, next_ip, next_ip + op.mem.disp, op.size,
                    "address" if ins.mnemonic == "lea" else "read")
        if ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP):
            equal(ins.operands[0].type, X86_OP_IMM, "direct transfer operand")
            target = ins.operands[0].imm
            transfers.append({"site": hex(ins.address), "mnemonic": ins.mnemonic, "target": hex(target)})
            if ins.group(capstone.CS_GRP_CALL):
                refs[ins.address + ins.imm_offset] = (
                    ins.address, next_ip, target, ins.imm_size, "call")
            elif target not in sites:
                raise ValueError(f"local branch does not land on an instruction at {target:#x}")
    return instructions, refs, transfers


def check_text(obj, region, refs):
    text, symbols, relocs = objects(obj)
    equal((symbols["report_diagnostic"], symbols["report_diagnostic_end"]),
          (0, len(region)), "reassembled span")
    equal(len(text), len(region), "text size")
    pending = dict(refs)
    applied = []
    for offset, symbol, kind in relocs:
        field = START + offset
        site, next_ip, target, width, access = pending.pop(field)
        if not 4 <= kind <= 9:
            raise ValueError(f"unsupported REL32 kind {kind} at {site:#x}")
        addend = struct.unpack_from("<i", text, offset)[0]
        displacement = BINDINGS[symbol] + addend - (field + kind)
        equal(next_ip + displacement, target, f"relocation target at {site:#x}")
        struct.pack_into("<i", text, offset, displacement)
        applied.append({"site": hex(site), "field": hex(field), "symbol": symbol,
                        "kind": kind, "addend": addend, "target": hex(target),
                        "width": width, "access": access})
    equal(pending, {}, "missing relocations")
    for offset, (actual, expected) in enumerate(zip(text, region)):
        if actual != expected:
            raise ValueError(f"relocated .text differs at RVA {START + offset:#x}: "
                             f"assembled {actual:#04x}, original {expected:#04x}")
    return applied


def check_unwind(obj, pe, image):
    runtime = next(r.struct for r in pe.DIRECTORY_ENTRY_EXCEPTION if r.struct.BeginAddress == START)
    equal((runtime.EndAddress, runtime.UnwindData), (END, 0x1C3DC), "exception-directory entry")
    metadata, _, relocs = objects(obj, b".xdata")
    equal(relocs, [], ".xdata relocations")
    header = image[runtime.UnwindData:runtime.UnwindData + 4]
    unwind_size = 4 + ((header[2] + 1) // 2) * 4
    equal(metadata, image[runtime.UnwindData:runtime.UnwindData + unwind_size], ".xdata")
    pdata, _, relocs = objects(obj, b".pdata")
    equal(relocs, [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)], ".pdata relocations")
    for offset, symbol, _ in relocs:
        addend = struct.unpack_from("<I", pdata, offset)[0]
        base = runtime.UnwindData if symbol == ".xdata" else START
        struct.pack_into("<I", pdata, offset, base + addend)
    equal(pdata, runtime.__pack__(), ".pdata")
    return {"pdata_rva": hex(pe.get_rva_from_offset(runtime.get_file_offset())),
            "pdata": pdata.hex(), "xdata_rva": hex(runtime.UnwindData), "xdata": metadata.hex()}


def check_storage(obj, pe, image):
    records = []
    for section, symbol, rva, size in (
        (b".rdata", "newline_format", 0x1A985, 2),
        (b".rdata", "message_format", 0x1A987, 4),
        (b".bss", "diagnostic_buffer", 0x23850, 0x200),
    ):
        data, symbols, relocs = objects(obj, section)
        equal(relocs, [], f"{symbol} relocations")
        start = symbols[symbol]
        reconstructed = data[start:start + size]
        if section == b".bss":
            equal(len(data) - start, size, "compiled diagnostic buffer extent")
            pe_section = pe.get_section_by_rva(rva)
            zero_fill = pe_section.VirtualAddress + pe_section.SizeOfRawData
            virtual_end = pe_section.VirtualAddress + pe_section.Misc_VirtualSize
            if not zero_fill <= rva < rva + size <= virtual_end:
                raise ValueError("diagnostic buffer range is outside the PE zero-fill tail")
        equal(reconstructed, image[rva:rva + size], symbol)
        records.append({"symbol": symbol, "rva": hex(rva), "size": size,
                        "sha256": sha256(reconstructed).hexdigest()})
    return records


def check_calls(pe, image, refs):
    thunk, slot = 0x180DE, 0x19188
    call = next(r for r in refs if r["site"] == "0x151e6")
    equal(int(call["target"], 16), thunk, "vsprintf thunk target")
    ins = Decoder(64, image[thunk:thunk + 6], ip=thunk).decode()
    equal((image[thunk:thunk + 2], ins.len, ins.ip_rel_memory_address),
          (b"\xff\x25", 6, slot), "vsprintf IAT slot")
    imports = {s.address - pe.OPTIONAL_HEADER.ImageBase: (d.dll.decode(), s.name.decode())
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    equal(imports[slot], ("api-ms-win-crt-stdio-l1-1-0.dll", "__stdio_common_vsprintf"), "vsprintf import")
    for site in (0x14F3C, 0x14F4E, 0x14F5D):
        incoming = Decoder(64, image[site:site + 5], ip=site).decode()
        equal((image[site], incoming.len, incoming.near_branch_target), (0xE8, 5, START),
              f"incoming call {site:#x}")
    return {"site": call["site"], "thunk": hex(thunk), "iat": hex(slot),
            "import": "!".join(imports[slot])}


def replay(original, compiler, evidence):
    binary = original.read_bytes()
    equal(sha256(binary).hexdigest(), ORIGINAL, "original SHA-256")
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    equal(sha256(region).hexdigest(), RANGE, "range SHA-256")
    instructions, refs, transfers = decode(region)
    with TemporaryDirectory() as tmp:
        obj = build(compiler, "report-diagnostic.c", Path(tmp) / "code.obj")
        data = build(compiler, "diagnostic-data.c", Path(tmp) / "data.obj")
    relocations = check_text(obj, region, refs)
    unwind = check_unwind(obj, pe, image)
    storage = check_storage(data, pe, image)
    imported = check_calls(pe, image, relocations)
    if evidence:
        evidence.mkdir(parents=True, exist_ok=True)
        (evidence / "instructions.lst").write_text(
            "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
                    for i in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": RANGE,
            "matched_bytes": len(region), "instructions": len(instructions),
            "coff_text_relocations": relocations, "direct_transfers": transfers, "unwind": unwind,
            "storage": storage, "import": imported}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(replay(args.original, args.zig, args.evidence_dir), indent=2))
