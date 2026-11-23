"""Check the delay-load wrapper against the pinned PE and its rebuilt AMD64 COFF."""

from argparse import ArgumentParser
from hashlib import sha256
import json
from pathlib import Path
from runpy import run_path
import struct
import sys
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "s5"))
from reassemble import ORIGINAL, compare, compile_bodies
inspect_unwind_sections = run_path(str(HERE.parent / "s21/check-release-shell.py"))["inspect_unwind_sections"]

START, UNWIND_END, END = 0x33C33, 0x33CAA, 0x33CAC
RANGE_SHA = "87b725fd5792c416ea82a6a2cb11b5318097b65171ec325027e1c55487cee1dc"


def compare_frame(obj, pe, image, original):
    runtime, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION
                if entry.struct.BeginAddress == START)
    assert (runtime.EndAddress, runtime.UnwindData) == (UNWIND_END, 0x48E58)
    assert not any(entry.struct.BeginAddress <= UNWIND_END < entry.struct.EndAddress
                   for entry in pe.DIRECTORY_ENTRY_EXCEPTION)
    sections = inspect_unwind_sections(obj)
    pdata, links = sections[".pdata"]
    assert links == [(0, ".text"), (4, ".text"), (8, ".xdata")]
    for field, address in ((0, START), (4, START), (8, runtime.UnwindData)):
        addend, = struct.unpack_from("<I", pdata, field)
        struct.pack_into("<I", pdata, field, address + addend)
    offset = runtime.get_file_offset()
    assert pdata == original[offset:offset + 12]
    unwind, fixups = sections[".xdata"]
    assert not fixups and unwind == image[runtime.UnwindData:runtime.UnwindData + 8]
    version_flags, prologue, slots, frame, operation_offset, operation = unwind[:6]
    assert (version_flags, prologue, slots, frame, operation_offset, operation & 15) == (1, 24, 1, 0, 24, 2)
    allocation = (operation >> 4) * 8 + 8
    return {"pdata_file_offset": hex(offset), "pdata_bytes": pdata.hex(), "pdata_addr32nb": len(links),
            "function_rvas": [hex(START), hex(runtime.EndAddress)], "xdata_rva": hex(runtime.UnwindData),
            "xdata_bytes": unwind.hex(), "code": "UWOP_ALLOC_SMALL", "allocation": allocation,
            "prologue_bytes": prologue, "tail_rva_outside_runtime_function": hex(UNWIND_END)}


def decode_image(pe, image):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    body = list(decoder.disasm(image[START:END], START))
    assert sum(instruction.size for instruction in body) == END - START

    def decode(address, count=1):
        return list(decoder.disasm(image[address:address + count * 15], address, count))

    def rip_target(instruction, operand):
        memory = instruction.operands[operand]
        assert memory.type == X86_OP_MEM and memory.mem.base == X86_REG_RIP
        return instruction.address + instruction.size + memory.mem.disp

    def require(instruction, mnemonic, operands):
        assert (instruction.mnemonic, instruction.op_str) == (mnemonic, operands), hex(instruction.address)

    stack = {}
    integer_registers = ("rcx", "rdx", "r8", "r9")
    require(body[4], "sub", "rsp, 0x68")
    require(body[9], "mov", "rdx, rax")
    for i, reg in enumerate(integer_registers):
        incoming = 8 * (i + 1)
        require(body[i], "mov", f"qword ptr [rsp + {hex(incoming) if incoming >= 10 else incoming}], {reg}")
        require(body[16 + i], "mov", f"{reg}, qword ptr [rsp + {incoming + 0x68:#x}]")
        stack[reg] = {"incoming_rsp_offset": incoming, "frame_rsp_offset": incoming + 0x68}
    for i in range(4):
        xmm_slot = 0x20 + i * 16
        register = f"xmm{i}"
        require(body[5 + i], "movdqa", f"xmmword ptr [rsp + {xmm_slot:#x}], {register}")
        require(body[12 + i], "movdqa", f"{register}, xmmword ptr [rsp + {xmm_slot:#x}]")
        stack[register] = {"frame_rsp_offset": xmm_slot}
    require(body[20], "add", "rsp, 0x68")
    require(body[21], "jmp", hex(UNWIND_END))
    require(body[22], "jmp", "rax")
    descriptor_rva = rip_target(body[10], 1)
    helper_rva = body[11].operands[0].imm
    assert (body[10].mnemonic, body[10].reg_name(body[10].operands[0].reg), descriptor_rva) == ("lea", "rcx", 0x49320)
    assert (body[11].mnemonic, body[11].operands[0].type, helper_rva) == ("call", X86_OP_IMM, 0x366E0)
    assert pe.OPTIONAL_HEADER.DATA_DIRECTORY[13].VirtualAddress == descriptor_rva
    entry, = (dll for dll in pe.DIRECTORY_ENTRY_DELAY_IMPORT
              if pe.get_rva_from_offset(dll.struct.get_file_offset()) == descriptor_rva)
    fields = dict(zip(("attrs", "name", "module", "iat", "int", "bound", "unload", "timestamp"),
                      struct.unpack_from("<8I", image, descriptor_rva)))
    assert (entry.dll, fields["attrs"]) == (b"HAPP.dll", 1)
    assert image[fields["name"]:fields["name"] + 9] == b"HAPP.dll\0"
    module = fields["module"]
    section = pe.get_section_by_rva(module)
    assert section.Characteristics & 0x80000000
    assert section.VirtualAddress + section.SizeOfRawData <= module < section.VirtualAddress + section.Misc_VirtualSize

    # Confirm the original IAT addends, each thunk's slot parameter, and the common native wrapper.
    base = pe.OPTIONAL_HEADER.ImageBase
    dir64 = {rel.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for rel in block.entries if rel.type == 10}
    imports = []
    for index, item in enumerate(entry.imports):
        slot = item.address - base
        assert slot == fields["iat"] + index * 8 and slot in dir64
        initial_value, = struct.unpack_from("<Q", image, slot)
        name_value, = struct.unpack_from("<Q", image, fields["int"] + index * 8)
        assert name_value == (1 << 63) | item.ordinal
        thunk = initial_value - base
        load_slot, forward = decode(thunk, 2)
        assert load_slot.mnemonic == "lea" and load_slot.reg_name(load_slot.operands[0].reg) == "rax"
        assert rip_target(load_slot, 1) == slot
        require(forward, "jmp", hex(START))
        imports.append({"slot_rva": hex(slot), "int_rva": hex(fields["int"] + index * 8),
                        "ordinal": item.ordinal, "initial_thunk_rva": hex(thunk),
                        "wrapper_jump_rva": hex(forward.address)})
    assert len(imports) == 31
    assert imports[0]["ordinal"] == 58 and imports[0]["initial_thunk_rva"] == "0x33cac"
    require(decode(0x366FF)[0], "mov", "r12, rdx")
    require(decode(0x36702)[0], "mov", "r14, rcx")
    require(decode(0x36965)[0], "mov", "qword ptr [r12], rbx")
    require(decode(0x36995)[0], "mov", "rax, rbx")
    return body, {
        "preserved_arguments": stack,
        "descriptor": {"directory": "IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT", "rva": hex(descriptor_rva),
                       "name": entry.dll.decode(), "raw": image[descriptor_rva:descriptor_rva + 32].hex(),
                       "sha256": sha256(image[descriptor_rva:descriptor_rva + 32]).hexdigest(),
                       "fields": {key: hex(value) for key, value in fields.items()},
                       "module_handle_initial": "zero-filled writable tail"},
        "descriptor_slot_bindings": imports,
        "helper": {"site": hex(body[11].address), "rva": hex(helper_rva), "rcx": "descriptor RVA 0x49320",
                   "rdx": "entry RAX (delay IAT slot address)", "slot_write_site": "0x36965",
                   "rax_result_site": "0x36995", "returns_selected_pointer": True,
                   "runtime_pointer": "unresolved; module resolver and hook paths are outside this wrapper"},
    }


def verify(original, compiler, source, listing):
    data = original.read_bytes()
    if sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("Original SHA-256 differs")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    if sha256(image[START:END]).hexdigest() != RANGE_SHA:
        raise ValueError("Original wrapper scope differs")
    with TemporaryDirectory() as directory:
        obj = Path(directory) / "delay-wrapper.obj"
        compile_bodies(source, compiler, obj)
        payload = obj.read_bytes()
        rebuilt = compare(payload, image, {START: END - START}).get(START)
        if rebuilt is None:
            raise ValueError("Reassembled delay-load wrapper differs from original .text")
        unwind = compare_frame(payload, pe, image, data)
    assert rebuilt["relocations"] == [["0x33c69", "0x49320", 4], ["0x33c6e", "0x366e0", 4]]
    body, bindings = decode_image(pe, image)
    if listing:
        listing.write_text("".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}\n" for i in body),
                           encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "instructions": len(body),
            "reassembly": rebuilt, "unwind": unwind, **bindings}


if __name__ == "__main__":
    parser = ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("compiler", type=Path)
    parser.add_argument("--source", type=Path, default=HERE / "delay-load-wrapper.c")
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    try:
        print(json.dumps(verify(args.original, args.compiler, args.source, args.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
