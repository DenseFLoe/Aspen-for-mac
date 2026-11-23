"""Reassemble a scoped AMD64 body and compare its original code and unwind."""
import argparse
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
from tempfile import TemporaryDirectory

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile


def coff_sections(obj):
    machine, count, _, symbols, n_symbols, optional, _ = struct.unpack_from("<HHIIIHH", obj)
    assert (machine, optional) == (0x8664, 0)
    names = {}
    index = 0
    while index < n_symbols:
        pos = symbols + index * 18
        name = obj[pos:pos + 8]
        if not any(name[:4]):
            start = symbols + n_symbols * 18 + struct.unpack_from("<I", name, 4)[0]
            name = obj[start:obj.index(0, start)]
        names[index] = name.rstrip(b"\0").decode("ascii")
        index += 1 + obj[pos + 17]
    for index in range(count):
        name, _, _, size, raw, rel, _, n_rel, _, _ = struct.unpack_from("<8sIIIIIIHHI", obj, 20 + index * 40)
        name = name.rstrip(b"\0").decode("ascii")
        if name not in (".text", ".pdata", ".xdata") or not size:
            continue
        relocations = [struct.unpack_from("<IIH", obj, rel + index * 10) for index in range(n_rel)]
        yield name, bytearray(obj[raw:raw + size]), [(off, names[symbol], kind) for off, symbol, kind in relocations]


def match_sections(obj, originals, bases):
    records = {}
    for name, data, relocations in coff_sections(obj):
        matched = {}
        for off, symbol, kind in relocations:
            target = int(symbol[4:], 16) if symbol.startswith("rva_") else bases[".text"] if symbol.startswith("scope_") else bases[symbol]
            addend, = struct.unpack_from("<i", data, off)
            if name == ".text":
                assert 4 <= kind <= 9
                struct.pack_into("<i", data, off, target + addend - (bases[name] + off + kind))
            else:
                assert kind == 3
                struct.pack_into("<I", data, off, target + addend)
            matched[bases[name] + off] = (target + addend, kind)
        original = originals[name]
        if len(data) != len(original):
            raise ValueError(f"{name} size {len(data)} differs from {len(original)}")
        for offset, (actual, expected) in enumerate(zip(data, original)):
            if actual != expected:
                raise ValueError(f"{name} first difference at {bases[name] + offset:#x}: {actual:#04x} instead of {expected:#04x}")
        records[name] = {"bytes": len(data), "sha256": sha256(data).hexdigest(), "relocations": matched}
    assert set(records) == set(originals)
    return records


def replay(original, zig, listing):
    here = Path(__file__).resolve().parent
    spec = json.loads((here / "scope.json").read_bytes())
    raw = original.read_bytes()
    assert sha256(raw).hexdigest() == spec["original_sha256"]
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    exception = {e.struct.BeginAddress: e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    relocations = {r.rva: r.type for b in pe.DIRECTORY_ENTRY_BASERELOC for r in b.entries if r.type}
    iat = {i.address - base: (group.dll.decode("ascii"), i.name.decode("ascii") if i.name else i.ordinal)
           for group in pe.DIRECTORY_ENTRY_IMPORT for i in group.imports}
    dis = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    dis.detail = True
    matches, decoded = {}, []
    with TemporaryDirectory() as temp:
        for index, item in enumerate(spec["entries"]):
            start, end = item["range"]
            segment = image[start:end]
            assert sha256(segment).hexdigest() == item["sha256"]
            assert pe.get_section_by_rva(start).Characteristics & 0x20000000
            sources, bases = {".text": segment}, {".text": start}
            unwind_info = item.get("unwind")
            if unwind_info:
                unwind, unwind_hex = unwind_info
                e = exception[start]
                assert (e.EndAddress, e.UnwindData) == (end, unwind)
                pdata = e.get_file_offset()
                xdata = image[unwind:unwind + len(bytes.fromhex(unwind_hex))]
                assert xdata.hex() == unwind_hex
                sources.update({".pdata": raw[pdata:pdata + 12], ".xdata": xdata})
                bases.update({".pdata": pe.get_rva_from_offset(pdata), ".xdata": unwind})
                assert sources[".pdata"] == struct.pack("<III", start, end, unwind)
            else:
                assert all(e.EndAddress <= start or e.BeginAddress >= end for e in exception.values())
            obj = Path(temp) / "scope.obj"
            subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
                            f"-DPART={index}", "-c", str(here / spec["source"]), "-o", str(obj)], check=True)
            sections = match_sections(obj.read_bytes(), sources, bases)
            instructions = list(dis.disasm(segment, start))
            assert sum(i.size for i in instructions) == end - start
            references = {}
            for ins in instructions:
                decoded.append(f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip())
                for operand in ins.operands:
                    if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                        references[ins.address + ins.disp_offset] = ins.address + ins.size + operand.mem.disp
                    if operand.type == X86_OP_IMM and (ins.group(capstone.CS_GRP_CALL) or ins.group(capstone.CS_GRP_JUMP)):
                        target = operand.imm
                        if target < start or target >= end:
                            references[ins.address + ins.imm_offset] = target
            assert {off: entry[0] for off, entry in sections[".text"]["relocations"].items()} == references
            matches[hex(start)] = {"instruction_count": len(instructions), "sha256": item["sha256"],
                                   "sections": sections, "unwind": unwind_info}
    slots = {}
    for raw_slot, record in spec["slots"].items():
        slot = int(raw_slot, 16)
        value = int.from_bytes(image[slot:slot + 8], "little")
        section = pe.get_section_by_rva(slot)
        assert section is not None and slot not in iat
        data = {"disk_qword": f"{value:#018x}", "sha256": sha256(image[slot:slot + 8]).hexdigest(),
                "section": section.Name.rstrip(b"\0").decode("ascii")}
        if record.get("load_config"):
            assert getattr(pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct, record["load_config"]) == base + slot
            assert value == base + int(record["target"], 16) and relocations.get(slot) == 10
            target = value - base
            entry = next(dis.disasm(image[target:target + 15], target))
            assert (entry.mnemonic, entry.op_str) == ("jmp", "rax")
            data.update(load_config=record["load_config"], target=record["target"], relocation="DIR64")
        else:
            assert value == 0 and slot not in relocations
        slots[raw_slot] = data
    if listing:
        listing.write_text("\n".join(decoded) + "\n", encoding="utf-8", newline="\n")
    imports = {}
    for address, (slot, dll, name) in spec["imports"].items():
        rva, slot_rva = int(address, 16), int(slot, 16)
        chain = []
        while rva not in chain:
            chain.append(rva)
            ins = next(dis.disasm(image[rva:rva + 15], rva))
            assert ins.mnemonic in ("jmp", "call") and len(ins.operands) == 1
            operand = ins.operands[0]
            if ins.mnemonic == "jmp" and operand.type == X86_OP_IMM:
                rva = operand.imm
                continue
            assert operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP
            assert ins.address + ins.size + operand.mem.disp == slot_rva
            actual = iat.get(slot_rva)
            if actual != (dll, name):
                raise ValueError(f"Import {address} at IAT {slot} resolves to {actual!r} instead of {(dll, name)!r}")
            break
        else:
            raise ValueError(f"Cyclic import transfer beginning at {address}")
        imports[address] = {"slot": slot, "dll": dll, "name": name, "chain": [hex(rva) for rva in chain]}
    return {"original_sha256": spec["original_sha256"], "entries": matches, "slots": slots,
            "imports": imports}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--listing", type=Path)
    args = parser.parse_args()
    try:
        print(json.dumps(replay(args.original, args.zig, args.listing), indent=2))
    except (AssertionError, ValueError) as error:
        parser.exit(1, f"Replay comparison failed: {error}\n")
