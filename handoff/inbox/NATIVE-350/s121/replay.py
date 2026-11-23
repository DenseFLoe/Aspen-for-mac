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
        if name not in (".text", ".pdata", ".xdata"):
            continue
        relocations = [struct.unpack_from("<IIH", obj, rel + index * 10) for index in range(n_rel)]
        yield name, bytearray(obj[raw:raw + size]), [(off, names[symbol], kind) for off, symbol, kind in relocations]


def match_sections(obj, image, originals, bases):
    records = {}
    for name, data, relocations in coff_sections(obj):
        matched = {}
        for off, symbol, kind in relocations:
            target = int(symbol[4:], 16) if symbol.startswith("rva_") else bases[symbol]
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
    start, end, unwind, unwind_size = spec["bounds"]
    assert sha256(image[start:end]).hexdigest() == spec["range_sha256"]
    entry, = (e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION if e.struct.BeginAddress == start)
    assert (entry.EndAddress, entry.UnwindData) == (end, unwind)
    pos = entry.get_file_offset()
    sources = {".text": image[start:end], ".pdata": raw[pos:pos + 12], ".xdata": image[unwind:unwind + unwind_size]}
    assert sources[".pdata"] == struct.pack("<III", start, end, unwind)
    with TemporaryDirectory() as temp:
        obj = Path(temp) / "scope.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
                        "-c", str(here / spec["source"]), "-o", str(obj)], check=True)
        match = match_sections(obj.read_bytes(), image, sources, {".text": start, ".pdata": pos, ".xdata": unwind})
    dis = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    dis.detail = True
    body = list(dis.disasm(image[start:end], start))
    assert sum(i.size for i in body) == end - start
    locations = {}
    for ins in body:
        if ins.mnemonic == "call" and ins.operands[0].type == X86_OP_IMM:
            locations[ins.address + ins.imm_offset] = ins.operands[0].imm
        for op in ins.operands:
            if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                locations[ins.address + ins.disp_offset] = ins.address + ins.size + op.mem.disp
    assert {off: entry[0] for off, entry in match[".text"]["relocations"].items()} == locations
    evidence = {}
    for address, data in spec["evidence_bytes"].items():
        at, expected = int(address, 16), bytes.fromhex(data)
        assert image[at:at + len(expected)] == expected, address
        evidence[address] = [f"{i.mnemonic} {i.op_str}".strip() for i in dis.disasm(expected, at)]
    scopes = []
    exception = spec.get("exception")
    if exception:
        unwind_data = sources[".xdata"]
        assert unwind_data[0] >> 3 == 1
        codes = 4 + 2 * ((unwind_data[2] + 1) & ~1)
        handler, count_scopes = struct.unpack_from("<II", unwind_data, codes)
        scopes = [list(map(hex, row)) for row in struct.iter_unpack("<IIII", unwind_data[codes + 8:])]
        assert hex(handler) == exception["handler"] and len(scopes) == count_scopes
        assert scopes == exception["scopes"]
    pointers = {}
    for slot_hex, target_hex in spec.get("pointer_slots", {}).items():
        slot, target = int(slot_hex, 16), int(target_hex, 16)
        va, = struct.unpack_from("<Q", image, slot)
        assert va - pe.OPTIONAL_HEADER.ImageBase == target
        assert any(r.rva == slot and r.type == 10 for b in pe.DIRECTORY_ENTRY_BASERELOC for r in b.entries)
        assert pe.get_section_by_rva(target).Characteristics & 0x20000000
        pointers[slot_hex] = {"file_rva": target_hex, "base_relocation": "DIR64"}
    callback = spec["callback_range"]
    begin_site, end_site = (int(site, 16) for site in callback["bound_sites"])
    bound_begin, bound_end = (int(addr, 16) for addr in callback["bounds"])
    instructions = {i.address: i for i in body}
    for site, expected in ((begin_site, bound_begin), (end_site, bound_end)):
        lea = instructions[site]
        assert lea.mnemonic == "lea" and lea.operands[1].mem.base == X86_REG_RIP
        assert lea.address + lea.size + lea.operands[1].mem.disp == expected
    branch = instructions[int(callback["branch_site"], 16)]
    assert branch.mnemonic == "jb" and branch.operands[0].imm == int(callback["loop_target"], 16)
    slot = int(callback["dispatch_slot"], 16)
    assert pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer == pe.OPTIONAL_HEADER.ImageBase + slot
    assert callback["dispatch_slot"] in pointers
    call = instructions[int(callback["dispatch_call"], 16)]
    assert call.mnemonic == "call" and call.operands[0].mem.base == X86_REG_RIP
    assert call.address + call.size + call.operands[0].mem.disp == slot
    assert not any(i.address - pe.OPTIONAL_HEADER.ImageBase == slot for group in pe.DIRECTORY_ENTRY_IMPORT for i in group.imports)
    crt = {"bounds": callback["bounds"], "empty_at_linked_addresses": bound_begin == bound_end,
           "loop_branch": branch.mnemonic, "dispatch_load_config_field": "GuardCFDispatchFunctionPointer",
           "dispatch_slot": callback["dispatch_slot"]}
    import_slots = {i.address - pe.OPTIONAL_HEADER.ImageBase: [group.dll.decode(), i.name.decode()]
                    for group in pe.DIRECTORY_ENTRY_IMPORT for i in group.imports if i.name}
    for slot, imported in spec.get("iat_slots", {}).items():
        assert import_slots[int(slot, 16)] == imported
    imports = {}
    for thunk_hex, (slot_hex, dll, name) in spec.get("imports", {}).items():
        thunk, slot = int(thunk_hex, 16), int(slot_hex, 16)
        jump = next(dis.disasm(image[thunk:thunk + 6], thunk))
        assert jump.mnemonic == "jmp" and jump.operands[0].mem.base == X86_REG_RIP
        assert thunk + jump.size + jump.operands[0].mem.disp == slot
        assert import_slots[slot] == [dll, name]
        imports[thunk_hex] = [slot_hex, dll, name]
    zero_fill = spec.get("zero_fill_slot")
    if zero_fill:
        slot = int(zero_fill, 16)
        sec = pe.get_section_by_rva(slot)
        offset = slot - sec.VirtualAddress
        assert sec.Characteristics & 0x80000000
        assert sec.SizeOfRawData <= offset and offset + 8 <= sec.Misc_VirtualSize
        assert image[slot:slot + 8] == bytes(8)
        assert not any(slot <= r.rva < slot + 8 and r.type
                       for b in pe.DIRECTORY_ENTRY_BASERELOC for r in b.entries)
    if listing:
        listing.write_text("".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip() + "\n"
                                   for i in body), encoding="utf-8", newline="\n")
    return {"original_sha256": spec["original_sha256"], "range_sha256": spec["range_sha256"],
            "range": list(map(hex, (start, end))), "instruction_count": len(body), "sections": match,
            "unwind_rva": hex(unwind), "scopes": scopes, "unwind_bytes": sources[".xdata"].hex(),
            "additional_original_instructions": evidence, "pointer_slots": pointers,
            "crt_callback_range": crt, "imports": imports, "iat_slots": spec.get("iat_slots", {}), "zero_fill_qword": zero_fill}


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
