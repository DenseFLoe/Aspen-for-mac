"""Reassemble the zedstwu resource formatter and check its bounded PE evidence."""
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

START, END = 0x18550, 0x185A6
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN = "48838f1e44a19a9df9b6312e94bc9c7a4fc6acaaac53037e3a59289946d53351"
BINDINGS = {"security_cookie": 0x221C0, "format_buffer": 0x18620, "check_security_cookie": 0x18110}


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
    iced = {ins.ip: ins for ins in Decoder(64, region, ip=START)}
    equal([(i.address, i.size) for i in instructions],
          [(i.ip, i.len) for i in iced.values()], "instruction boundaries")
    fields, transfers = {}, []
    for ins in instructions:
        next_ip = ins.address + ins.size
        if ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP):
            op = ins.operands[0]
            if op.type == X86_OP_IMM:
                equal(op.imm, iced[ins.address].near_branch_target, f"transfer at {ins.address:#x}")
                transfers.append({"site": hex(ins.address), "mnemonic": ins.mnemonic,
                                  "target": hex(op.imm)})
                if not START <= op.imm < END:
                    if not ins.group(capstone.CS_GRP_CALL):
                        raise ValueError(f"branch leaves the routine at {ins.address:#x}")
                    fields[ins.address + ins.imm_offset] = (ins.address, next_ip, op.imm, "call")
                elif op.imm not in iced:
                    raise ValueError(f"branch lands inside an instruction at {op.imm:#x}")
        for operand in ins.operands:
            if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                target = next_ip + operand.mem.disp
                equal(target, iced[ins.address].ip_rel_memory_address, f"RIP operand at {ins.address:#x}")
                if ins.group(capstone.CS_GRP_CALL):
                    access = "import"
                elif ins.mnemonic == "lea":
                    access = "address"
                elif operand.access & capstone.CS_AC_WRITE:
                    access = "write"
                else:
                    access = "read"
                fields[ins.address + ins.disp_offset] = (ins.address, next_ip, target, access)
    return instructions, fields, transfers


def check_text(obj, region, fields):
    text, symbols, relocs = objects(obj)
    equal((symbols["format_resource_path"], symbols["format_resource_path_end"]),
          (0, len(region)), "reassembled span")
    equal(len(text), len(region), "text size")
    pending = dict(fields)
    applied = []
    for offset, symbol, kind in relocs:
        field = START + offset
        site, next_ip, target, access = pending.pop(field)
        if not 4 <= kind <= 9:
            raise ValueError(f"unsupported REL32 kind {kind} at {site:#x}")
        addend = struct.unpack_from("<i", text, offset)[0]
        displacement = BINDINGS[symbol] + addend - (field + kind)
        equal(next_ip + displacement, target, f"relocation target at {site:#x}")
        struct.pack_into("<i", text, offset, displacement)
        applied.append({"site": hex(site), "field": hex(field), "symbol": symbol,
                        "kind": kind, "addend": addend, "target": hex(target), "access": access})
    equal(pending, {}, "missing relocations")
    for offset, (actual, expected) in enumerate(zip(text, region)):
        if actual != expected:
            raise ValueError(f"relocated .text differs at RVA {START + offset:#x}: "
                             f"assembled {actual:#04x}, original {expected:#04x}")
    return applied


def check_unwind(obj, pe, image):
    runtime = next(r.struct for r in pe.DIRECTORY_ENTRY_EXCEPTION if r.struct.BeginAddress == START)
    equal((runtime.EndAddress, runtime.UnwindData), (END, 0x1C3BC), "exception-directory entry")
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


def check_edges(pe, image):
    expected = {
        0x1503B: (7, "lea", 0x1AD7C),
        0x15042: (7, "lea", 0x1AD70),
        0x15054: (5, "call", START),
        0x1863F: (5, "call", 0x158D8),
        0x1865E: (5, "call", 0x180DE),
        0x180DE: (6, "jmp", 0x19188),
        0x18110: (7, "cmp", 0x221C0),
    }
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    for site, (length, mnemonic, target) in expected.items():
        ins = next(decoder.disasm(image[site:site+15], site, 1))
        equal((ins.size, ins.mnemonic), (length, mnemonic), f"edge at {site:#x}")
        operand = next((op for op in ins.operands if op.type == X86_OP_IMM
                        or (op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)), None)
        actual = operand.imm if operand.type == X86_OP_IMM else site + length + operand.mem.disp
        equal(actual, target, f"edge target at {site:#x}")

    imports = {s.address - pe.OPTIONAL_HEADER.ImageBase: (d.dll.decode(), s.name.decode())
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    printf = ("api-ms-win-crt-stdio-l1-1-0.dll", "__stdio_common_vsprintf")
    equal(imports[0x19188], printf, "printf import slot")
    equal(image[0x1AD70:0x1AD7C], b"irc_msg.dll\0", "resource name")
    equal(image[0x1AD7C:0x1AD83], b"%lu/%s\0", "resource path format")
    return {"original_edges": {hex(k): hex(v[2]) for k, v in expected.items()},
            "format": "%lu/%s", "resource": "irc_msg.dll", "format_iat": "!".join(printf),
            "cookie_original_bytes": image[0x221C0:0x221C8].hex()}


def replay(original, compiler, evidence):
    binary = original.read_bytes()
    equal(sha256(binary).hexdigest(), ORIGINAL, "original SHA-256")
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    equal(sha256(region).hexdigest(), SPAN, "range SHA-256")
    instructions, fields, transfers = decode(region)
    with TemporaryDirectory() as tmp:
        obj = build(compiler, "format-resource-path.c", Path(tmp) / "code.obj")
    relocations = check_text(obj, region, fields)
    unwind = check_unwind(obj, pe, image)
    edges = check_edges(pe, image)
    if evidence:
        evidence.mkdir(parents=True, exist_ok=True)
        (evidence / "instructions.lst").write_text(
            "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
                    for i in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": SPAN,
            "matched_bytes": len(region), "instructions": len(instructions),
            "coff_text_relocations": relocations, "direct_transfers": transfers,
            "unwind": unwind, "data_and_calls": edges}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(replay(args.original, args.zig, args.evidence_dir), indent=2))
