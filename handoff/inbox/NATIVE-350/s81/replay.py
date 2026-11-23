"""Rebuild the zedstwu AMD64 PE section test and its SEH scope."""

import argparse
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from iced_x86 import Decoder, FlowControl
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

START, END, UNWIND = 0x15BDC, 0x15C74, 0x1C1AC
ORIGINAL_SHA = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE_SHA = "81780160b17c32a33bbbc2558815727294f8c1e334451a70b9c2bfeec2c823e7"


def compare(start, rebuilt, original, section):
    if len(rebuilt) != len(original):
        raise ValueError(f"{section} length differs: {len(rebuilt)} vs {len(original)}")
    for offset, (actual, expected) in enumerate(zip(rebuilt, original)):
        if actual != expected:
            raise ValueError(f"Reassembled {section} byte differs at RVA {start + offset:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")


def match_text(obj, original):
    text, symbols, relocations = objects(obj)
    assert (symbols["is_current_image_readonly_address"],
            symbols["is_current_image_readonly_address_end"]) == (0, END - START)
    assert relocations == [(15, "image_dos_header", 4), (24, "image_lfanew", 4), (31, "image_dos_header", 4)]
    symbols = {"image_dos_header": 0, "image_lfanew": 0x3C}
    bindings = []
    for offset, name, kind in relocations:
        target = symbols[name]
        addend, = struct.unpack_from("<i", text, offset)
        assert addend == 0
        struct.pack_into("<i", text, offset, target - (START + offset + 4))
        bindings.append({"site": hex(START + offset), "target": hex(target), "symbol": name, "coff_type": kind})
    compare(START, text, original, ".text")
    return bindings


def match_unwind(obj, image, host_record):
    pdata, _, pdata_relocs = objects(obj, b".pdata")
    assert len(pdata) == 12 and pdata_relocs == [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)]
    pdbases = {".text": START, ".xdata": UNWIND}
    for offset, name, _ in pdata_relocs:
        value, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, value + pdbases[name])
    assert pdata == host_record.__pack__()
    assert struct.unpack("<III", pdata) == (START, END, UNWIND)

    xdata, _, xdata_relocs = objects(obj, b".xdata")
    assert len(xdata) == 32
    assert xdata_relocs == [(8, "c_specific_handler_thunk", 3), (16, ".text", 3), (20, ".text", 3),
                            (24, "image_section_exception_filter", 3), (28, ".text", 3)]
    xdbases = {"c_specific_handler_thunk": 0x18066, ".text": START, "image_section_exception_filter": 0x186F3}
    for offset, name, _ in xdata_relocs:
        value, = struct.unpack_from("<I", xdata, offset)
        struct.pack_into("<I", xdata, offset, value + xdbases[name])
    compare(UNWIND, xdata, image[UNWIND:UNWIND + len(xdata)], ".xdata")
    assert xdata[:8] == bytes.fromhex("0904010004220000")
    handler, count, protect_begin, protect_end, filter_rva, jump = struct.unpack_from("<IIIIII", xdata, 8)
    assert (handler, count, protect_begin, protect_end, filter_rva, jump) == (
        0x18066, 1, 0x15BE3, 0x15C6D, 0x186F3, 0x15C6D)
    scope = {"handler_thunk": hex(handler), "record_count": count,
             "protected_range": [hex(protect_begin), hex(protect_end)],
             "exception_filter": hex(filter_rva), "continuation": hex(jump)}
    return {"pdata": pdata.hex(), "xdata_rva": hex(UNWIND), "xdata": xdata.hex(),
            "stack_allocation": 24, "prologue_length": 4, "handler_scope": scope}


def match_image_references(pe, image, decoded, scope):
    assert [decoded[site].ip_rel_memory_address for site in (0x15BE8, 0x15BF1, 0x15BF8)] == [0, 0x3C, 0]
    pe_header, = struct.unpack_from("<i", image, 0x3C)
    assert pe_header == pe.DOS_HEADER.e_lfanew
    assert (pe.DOS_HEADER.e_magic, pe.NT_HEADERS.Signature, pe.OPTIONAL_HEADER.Magic) == (0x5A4D, 0x4550, 0x20B)
    assert [decoded[site].near_branch_target for site in (0x15BEF, 0x15C08, 0x15C13)] == [0x15C69] * 3
    section_table = pe_header + 0x18 + pe.FILE_HEADER.SizeOfOptionalHeader
    assert len(pe.sections) == pe.FILE_HEADER.NumberOfSections
    assert [section.get_file_offset() for section in pe.sections] == [
        section_table + index * 0x28 for index in range(len(pe.sections))]
    assert [section.get_field_relative_offset(field) for field in ("Misc", "VirtualAddress", "Characteristics")
            for section in pe.sections[:1]] == [8, 12, 36]
    assert [decoded[site].near_branch_target for site in (0x15C36, 0x15C3E, 0x15C48, 0x15C4E, 0x15C5F)] == [
        0x15C50, 0x15C4A, 0x15C52, 0x15C2F, 0x15C65]
    assert image[0x15C5B:0x15C5F] == bytes.fromhex("837a2400")
    assert image[0x15C65:0x15C67] == bytes.fromhex("b001")
    continuation = int(scope["continuation"], 16)
    assert image[continuation:continuation + 2] == bytes.fromhex("32c0")

    handler = int(scope["handler_thunk"], 16)
    thunk = Decoder(64, image[handler:handler + 6], ip=handler).decode()
    assert thunk.flow_control == FlowControl.INDIRECT_BRANCH and thunk.is_ip_rel_memory_operand
    iat = thunk.ip_rel_memory_address
    imports = [(entry.dll.decode(), symbol.name.decode()) for entry in pe.DIRECTORY_ENTRY_IMPORT
               for symbol in entry.imports if symbol.name and symbol.address - pe.OPTIONAL_HEADER.ImageBase == iat]
    assert iat == 0x190B0 and imports == [("VCRUNTIME140.dll", "__C_specific_handler")]
    return {"image_base": hex(pe.OPTIONAL_HEADER.ImageBase), "pe_header_rva": hex(pe_header),
            "section_table_rva": hex(section_table), "section_count": len(pe.sections),
            "section_stride": 0x28, "virtual_size_offset": 8, "virtual_address_offset": 12,
            "characteristics_offset": 36, "writable_bit": "0x80000000",
            "handler_iat": hex(iat), "handler_import": "!".join(imports[0])}


def save_listing(path, instructions, image, scope):
    text = [f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() for ins in instructions]
    for offset, item in ((8, "handler_thunk"), (24, "exception_filter"), (28, "continuation")):
        address = UNWIND + offset
        text.append(f"{address:#x} {image[address:address + 4].hex()} dd {scope[item]} ; {item}")
    for index, target in enumerate(scope["protected_range"]):
        address = UNWIND + 16 + 4 * index
        name = ("begin", "end")[index]
        text.append(f"{address:#x} {image[address:address + 4].hex()} dd {target} ; protected {name}")
    path.write_text("\n".join(text) + "\n", encoding="utf-8", newline="\n")


def replay(original, zig, listing):
    binary = original.read_bytes()
    assert sha256(binary).hexdigest() == ORIGINAL_SHA
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    assert sha256(region).hexdigest() == RANGE_SHA
    host, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION if entry.struct.BeginAddress == START)
    with TemporaryDirectory() as folder:
        path = Path(folder) / "image-section-host.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "image-section-host.c"), "-o", str(path)], check=True)
        obj = path.read_bytes()
    relocations = match_text(obj, region)
    unwind = match_unwind(obj, image, host)
    decoded = {ins.ip: ins for ins in Decoder(64, region, ip=START)}
    disassembler = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions = list(disassembler.disasm(region, START))
    assert sum(ins.size for ins in instructions) == len(region)
    assert [(ins.address, ins.size) for ins in instructions] == [(ins.ip, ins.len) for ins in decoded.values()]
    assert decoded[END - 1].flow_control == FlowControl.RETURN
    image_references = match_image_references(pe, image, decoded, unwind["handler_scope"])
    if listing:
        save_listing(listing, instructions, image, unwind["handler_scope"])
    return {"original_sha256": ORIGINAL_SHA, "range_sha256": RANGE_SHA, "range": [hex(START), hex(END)],
            "matched_bytes": len(region), "instructions": len(instructions), "relocations": relocations,
            "unwind": unwind, "image_references": image_references}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--listing", type=Path)
    options = parser.parse_args()
    try:
        print(json.dumps(replay(options.original, options.zig, options.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
