"""Reassemble the zedstwu message selector and check its bounded PE evidence."""
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

START, END = 0x15000, 0x15176
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
SPAN = "e3a5b4ddb8c8dd30d9e7899520b6e29e574c73d09882bf8de1d72dfb7737ca58"
BINDINGS = {
    "security_cookie": 0x221C0,
    "resource_attempted": 0x23A58,
    "imp_get_thread_locale": 0x19090,
    "resource_path_format": 0x1AD7C,
    "resource_dll_name": 0x1AD70,
    "build_resource_path": 0x18550,
    "imp_load_library_ex_a": 0x19098,
    "resource_module": 0x23A60,
    "resource_available": 0x23A5C,
    "fallback_records": 0x1A990,
    "imp_format_message_a": 0x190A0,
    "strlen_thunk": 0x180E4,
    "localized_message": 0x23A70,
    "strncpy_thunk": 0x180EA,
    "empty_message": 0x1A98B,
    "localized_message_last": 0x23C6F,
    "imp_local_free": 0x19010,
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
    equal((symbols["select_diagnostic_message"], symbols["select_diagnostic_message_end"]),
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
    equal((runtime.EndAddress, runtime.UnwindData), (END, 0x1C3D0), "exception-directory entry")
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


def cstring(data, offset):
    return data[offset:data.index(0, offset) + 1]


def check_storage(obj, pe, image):
    ro, symbols, relocs = objects(obj, b".rdata")
    table = BINDINGS["fallback_records"]
    start, end = (symbols[n] for n in ("fallback_records", "fallback_records_end"))
    equal(end - start, 0x1AD70 - table, "fallback table extent")
    pointers = {off: (name, kind) for off, name, kind in relocs}
    equal(len(pointers), (end - start) // 16, "COFF fallback pointer count")
    base = pe.OPTIONAL_HEADER.ImageBase
    base_relocs = {i.rva: i.type for block in pe.DIRECTORY_ENTRY_BASERELOC for i in block.entries}
    records = []
    for offset in range(start, end, 16):
        row_rva = table + offset - start
        idx, kind, address = struct.unpack_from("<IIQ", image, row_rva)
        name, relocation_type = pointers[offset + 8]
        equal(relocation_type, 1, f"ADDR64 relocation for fallback row {idx}")
        equal(name, f"fallback_message_{idx}", f"fallback symbol for row {idx}")
        equal(base_relocs.get(row_rva + 8), 10, f"PE DIR64 relocation for fallback row {idx}")
        equal(struct.unpack_from("<Q", ro, offset + 8)[0], 0, f"COFF addend for fallback row {idx}")
        target = address - base
        literal = cstring(ro, symbols[name])
        equal(literal, cstring(image, target), f"fallback string at RVA {target:#x}")
        struct.pack_into("<Q", ro, offset + 8, base + target)
        records.append({"index": idx, "kind": kind, "record": hex(row_rva), "string": hex(target),
                        "length": len(literal), "sha256": sha256(literal).hexdigest()})
    equal(ro[start:end], image[table:table + (end - start)], "fallback table bytes")
    literals = []
    for name in ("empty_message", "resource_dll_name", "resource_path_format"):
        rva = BINDINGS[name]
        literal = cstring(ro, symbols[name])
        equal(literal, cstring(image, rva), name)
        literals.append({"symbol": name, "rva": hex(rva), "bytes": literal.hex()})

    zero, symbols, relocs = objects(obj, b".bss")
    equal(relocs, [], ".bss relocations")
    zero_start = BINDINGS["resource_attempted"]
    zero_end = BINDINGS["localized_message_last"] + 1
    equal(symbols["localized_message_end"], len(zero), "COFF resource-state extent")
    for name in ("resource_attempted", "resource_available", "resource_module",
                 "localized_message", "localized_message_last"):
        equal(symbols[name], BINDINGS[name] - zero_start, f"{name} data offset")
    section = pe.get_section_by_rva(zero_start)
    if not (section.VirtualAddress + section.SizeOfRawData <= zero_start
            < zero_end <= section.VirtualAddress + section.Misc_VirtualSize):
        raise ValueError("resource storage leaves the PE zero-fill tail")
    equal(zero, image[zero_start:zero_end], "resource storage bytes")
    return {"records": records, "table_sha256": sha256(ro[start:end]).hexdigest(),
            "literals": literals, "zero_fill": {"range": [hex(zero_start), hex(zero_end)],
                                               "bytes": len(zero)}}


def check_imports(pe, image, relocations):
    imports = {s.address - pe.OPTIONAL_HEADER.ImageBase: (d.dll.decode(), s.name.decode())
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    expected = {
        "imp_get_thread_locale": ("KERNEL32.dll", "GetThreadLocale"),
        "imp_load_library_ex_a": ("KERNEL32.dll", "LoadLibraryExA"),
        "imp_format_message_a": ("KERNEL32.dll", "FormatMessageA"),
        "imp_local_free": ("KERNEL32.dll", "LocalFree"),
        "strlen_thunk": ("api-ms-win-crt-string-l1-1-0.dll", "strlen"),
        "strncpy_thunk": ("api-ms-win-crt-string-l1-1-0.dll", "strncpy"),
    }
    entries = []
    for ref in relocations:
        label, target = ref["symbol"], int(ref["target"], 16)
        if label not in expected:
            continue
        if label.endswith("_thunk"):
            thunk = Decoder(64, image[target:target + 6], ip=target).decode()
            equal((image[target:target + 2], thunk.len), (b"\xff\x25", 6), f"{label} IAT jump")
            iat = thunk.ip_rel_memory_address
        else:
            iat = target
        equal(imports[iat], expected[label], f"{label} decoded import")
        entries.append({"site": ref["site"], "iat": hex(iat), "import": "!".join(imports[iat])})
    equal(len(entries), 7, "import call sites")
    incoming = Decoder(64, image[0x151A3:0x151A8], ip=0x151A3).decode()
    equal((image[0x151A3], incoming.near_branch_target, image[0x151A8:0x151AB]),
          (0xE8, START, b"\x48\x89\xc6"), "diagnostic reporter call and RAX consumer")
    return entries


def replay(original, compiler, evidence):
    binary = original.read_bytes()
    equal(sha256(binary).hexdigest(), ORIGINAL, "original SHA-256")
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    equal(sha256(region).hexdigest(), SPAN, "range SHA-256")
    instructions, fields, transfers = decode(region)
    with TemporaryDirectory() as tmp:
        obj = build(compiler, "select-diagnostic-message.c", Path(tmp) / "code.obj")
        storage = build(compiler, "message-data.c", Path(tmp) / "data.obj")
    relocations = check_text(obj, region, fields)
    unwind = check_unwind(obj, pe, image)
    storage = check_storage(storage, pe, image)
    imports = check_imports(pe, image, relocations)
    if evidence:
        evidence.mkdir(parents=True, exist_ok=True)
        (evidence / "instructions.lst").write_text(
            "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
                    for i in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": SPAN,
            "matched_bytes": len(region), "instructions": len(instructions),
            "coff_text_relocations": relocations, "direct_transfers": transfers, "unwind": unwind,
            "storage": storage, "imports": imports, "incoming": {"site": "0x151a3", "consume": "0x151a8"}}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(replay(args.original, args.zig, args.evidence_dir), indent=2))
