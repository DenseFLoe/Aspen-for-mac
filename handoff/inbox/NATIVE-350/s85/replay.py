"""Reassemble zedstwu's AMD64 startup lock release and verify its evidence."""

import argparse
import csv
from hashlib import sha256
import json
from pathlib import Path
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory

import capstone
from iced_x86 import Decoder, FlowControl, Mnemonic, Register
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

START, END, UNWIND = 0x15C74, 0x15C98, 0x1C1DC
PREDICATE, PREDICATE_END = 0x1654C, 0x16558
ACQUIRE, ACQUIRE_END = 0x159A8, 0x159E1
LOCK, UCRT_FLAG = 0x22CB8, 0x22270
ORIGINAL_SHA = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE_SHA = "601c3b9783b84859e5612bf54a500539f69f2005c8e71d70ba2fdb20992f42cc"


def compare(start, rebuilt, original, section):
    if len(rebuilt) != len(original):
        raise ValueError(f"{section} length differs: {len(rebuilt)} vs {len(original)}")
    for offset, (actual, expected) in enumerate(zip(rebuilt, original)):
        if actual != expected:
            raise ValueError(f"Reassembled {section} byte differs at RVA {start + offset:#x}: "
                             f"{actual:#04x} instead of {expected:#04x}")


def match_sections(obj, image, function):
    text, symbols, relocations = objects(obj)
    assert (symbols["release_startup_lock"], symbols["release_startup_lock_end"]) == (0, END - START)
    assert relocations == [(9, "is_ucrt_dll_in_use", 4), (26, "startup_lock", 4)]
    targets = {"is_ucrt_dll_in_use": PREDICATE, "startup_lock": LOCK}
    bindings = []
    for offset, name, kind in relocations:
        target = targets[name]
        assert struct.unpack_from("<i", text, offset) == (0,)
        struct.pack_into("<i", text, offset, target - (START + offset + 4))
        bindings.append({"site": hex(START + offset), "target": hex(target), "symbol": name, "coff_type": kind})
    compare(START, text, image[START:END], ".text")

    pdata, _, relocs = objects(obj, b".pdata")
    assert relocs == [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)]
    bases = {".text": START, ".xdata": UNWIND}
    for offset, symbol, _ in relocs:
        value, = struct.unpack_from("<I", pdata, offset)
        struct.pack_into("<I", pdata, offset, value + bases[symbol])
    assert pdata == function.__pack__() == struct.pack("<III", START, END, UNWIND)
    xdata, _, relocs = objects(obj, b".xdata")
    assert not relocs and xdata == bytes.fromhex("0106020006320230")
    compare(UNWIND, xdata, image[UNWIND:UNWIND + len(xdata)], ".xdata")
    return bindings, {"pdata": pdata.hex(), "xdata_rva": hex(UNWIND), "xdata": xdata.hex(),
                      "prologue_length": 6, "stack_allocation": 32, "saved_register": "RBX"}


def decode_spans(image):
    disasm = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    instructions, decoded = [], {}
    for start, end in ((START, END), (PREDICATE, PREDICATE_END), (ACQUIRE, ACQUIRE_END)):
        chunk = image[start:end]
        span = list(disasm.disasm(chunk, start))
        independent = list(Decoder(64, chunk, ip=start))
        assert sum(ins.size for ins in span) == end - start
        assert [(ins.address, ins.size) for ins in span] == [(ins.ip, ins.len) for ins in independent]
        instructions.extend(span)
        decoded.update((ins.ip, ins) for ins in independent)
    return instructions, decoded


def check_atomic_slot(pe, image, decoded, calls):
    section = pe.get_section_by_rva(LOCK)
    assert section.Name.rstrip(b"\0") == b".data" and section.Characteristics & 0x80000000
    offset = LOCK - section.VirtualAddress
    assert section.SizeOfRawData <= offset and offset + 8 <= section.Misc_VirtualSize
    assert image[LOCK:LOCK + 8] == bytes(8)
    assert all(not LOCK <= entry.rva < LOCK + 8 or not entry.type
               for block in pe.DIRECTORY_ENTRY_BASERELOC for entry in block.entries)

    acquire, release = decoded[0x159CB], decoded[0x15C8B]
    assert acquire.mnemonic == Mnemonic.CMPXCHG and acquire.has_lock_prefix and acquire.op1_register == Register.RCX
    assert release.mnemonic == Mnemonic.XCHG and release.op1_register == Register.RDX
    assert acquire.ip_rel_memory_address == release.ip_rel_memory_address == LOCK
    with calls.open(encoding="utf-8", newline="") as handle:
        rows = list(csv.DictReader(handle))
    for caller, site in ((ACQUIRE, acquire), (START, release), (PREDICATE, decoded[0x1654E])):
        found = [row for row in rows if row["kind"] == "native" and int(row["caller"], 0) == caller
                 and row["class"] == "data" and row["note"].split(";", 1)[0] == f"RVA {site.ip:#x}"]
        expected = site.ip_rel_memory_address
        if len(found) != 1:
            raise ValueError(f"Expected one data reference at RVA {site.ip:#x}; got {len(found)}")
        declared = int(found[0]["callee"], 0)
        if declared != expected:
            raise ValueError(f"Data reference at RVA {site.ip:#x} declares {declared:#x}; original targets {expected:#x}")

    raw_matches = []
    for sec in pe.sections:
        if not sec.Characteristics & 0x20000000:
            continue
        base = sec.VirtualAddress
        code = image[base:base + min(sec.SizeOfRawData, sec.Misc_VirtualSize)]
        for i in range(len(code)):
            ins = Decoder(64, code[i:i + 15], ip=base + i).decode()
            if ins.is_ip_rel_memory_operand and ins.ip_rel_memory_address == LOCK:
                raw_matches.append(ins.ip)
    assert [site for site in raw_matches if site in decoded] == [acquire.ip, release.ip]
    aliases = [site for site in raw_matches if site not in decoded]
    assert all(any(ins.ip < site < ins.next_ip for ins in (acquire, release)) for site in aliases)
    return {"rva": hex(LOCK), "section": ".data", "initialization": "loader zero fill", "size": 8,
            "direct_ip_relative_sites": {hex(acquire.ip): "lock cmpxchg", hex(release.ip): "xchg"},
            "overlapping_suffixes": [hex(site) for site in aliases],
            "scope": "Executable raw-byte RIP-relative operands; computed addresses and runtime writes are outside this proof."}


def replay(original, zig, calls, listing):
    binary = original.read_bytes()
    assert sha256(binary).hexdigest() == ORIGINAL_SHA
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    assert sha256(image[START:END]).hexdigest() == RANGE_SHA
    function, = (entry.struct for entry in pe.DIRECTORY_ENTRY_EXCEPTION if entry.struct.BeginAddress == START)
    with TemporaryDirectory() as folder:
        path = Path(folder) / "startup-lock-release.obj"
        subprocess.run([str(zig.resolve()), "cc", "-target", "x86_64-windows-gnu", "-g0", "-O2",
                        "-c", str(HERE / "startup-lock-release.c"), "-o", str(path)], check=True)
        obj = path.read_bytes()
    relocations, unwind = match_sections(obj, image, function)
    instructions, decoded = decode_spans(image)
    call = decoded[0x15C7C]
    assert call.flow_control == FlowControl.CALL and call.near_branch_target == PREDICATE
    assert image[0x15C7A:0x15C7C] == bytes.fromhex("8ad9")  # Retain incoming CL across the call.
    assert image[0x15C81:0x15C8B] == bytes.fromhex("33d285c0740b84db7507")
    assert [decoded[site].near_branch_target for site in (0x15C85, 0x15C89)] == [0x15C92] * 2
    assert image[PREDICATE:PREDICATE_END] == bytes.fromhex("33c039051cbd00000f95c0c3")
    assert decoded[0x1654E].ip_rel_memory_address == UCRT_FLAG
    slot = check_atomic_slot(pe, image, decoded, calls)
    if listing:
        lines = [f"{ins.address:#x} {ins.bytes.hex()} {ins.mnemonic} {ins.op_str}".rstrip() for ins in instructions]
        listing.write_text("\n".join(lines) + "\n", encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL_SHA, "range_sha256": RANGE_SHA, "range": [hex(START), hex(END)],
            "matched_bytes": END - START, "instructions": sum(START <= site < END for site in decoded),
            "relocations": relocations, "unwind": unwind, "startup_lock": slot,
            "predicate": {"entry": hex(PREDICATE), "reads": hex(UCRT_FLAG), "argument_reads": [],
                          "eax": "1 if the referenced DWORD is nonzero, otherwise 0"},
            "release_condition": "UCRT predicate nonzero and incoming CL zero"}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--calls", type=Path, default=HERE.parent / "calls.csv")
    parser.add_argument("--listing", type=Path)
    options = parser.parse_args()
    try:
        print(json.dumps(replay(options.original, options.zig, options.calls, options.listing), indent=2))
    except ValueError as error:
        parser.exit(1, f"{error}\n")
