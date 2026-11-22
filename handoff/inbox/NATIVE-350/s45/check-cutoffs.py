"""Build the editable Windows AMD64 cutoff routine and compare its sections to the PE."""
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

START, END = 0x14CB0, 0x14F6D
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
RANGE = "5728fad0d29bfcee9a0e69875d0c7a3742a17ab40da0b123c3329b2e3fc3b50e"
BINDINGS = {
    "security_cookie": 0x221C0, "cache_ready": 0x235FC,
    "initialize_capability_records": 0x14910, "intel_vendor_match": 0x235F0,
    "max_basic_leaf": 0x235F4, "debug_variable_name": 0x1A970,
    "getenv_thunk": 0x180D2, "exit_thunk": 0x180D8, "check_security_cookie": 0x18110,
    "report_helper": 0x15180, "selected_product": 0x23638,
    "feature_class_a": 0x23630, "feature_class_b": 0x23640,
}
for slot in range(0x22230, 0x22270, 8):
    BINDINGS[f"cutoff_{slot:x}"] = slot
for index in range(3):
    for offset, name in ((0, "capacity"), (4, "field4"), (8, "field8")):
        BINDINGS[f"cache{index + 1}_{name}"] = 0x23600 + 16 * index + offset


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
    starts = {i.address for i in instructions}
    references = {}
    transfers = []
    for i in instructions:
        next_ip = i.address + i.size
        for op in i.operands:
            if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                access = "address" if i.mnemonic == "lea" else (
                    "write" if op.access & capstone.CS_AC_WRITE else "read")
                references[i.address + i.disp_offset] = (
                    i.address, next_ip, next_ip + op.mem.disp, op.size, access)
        if i.group(capstone.CS_GRP_CALL) or i.group(capstone.CS_GRP_JUMP):
            equal(i.operands[0].type, X86_OP_IMM, "direct transfer operand")
            target = i.operands[0].imm
            transfers.append({"site": hex(i.address), "mnemonic": i.mnemonic, "target": hex(target)})
            if i.group(capstone.CS_GRP_CALL):
                references[i.address + i.imm_offset] = (i.address, next_ip, target, i.imm_size, "call")
            elif target not in starts:
                raise ValueError(f"branch target {target:#x} is not an instruction boundary")
    return instructions, references, transfers


def check_text(obj, region, references):
    text, symbols, relocs = objects(obj)
    equal((symbols["configure_cache_cutoffs"], symbols["configure_cache_cutoffs_end"]),
          (0, len(region)), "reassembled span")
    equal(len(text), len(region), "text size")
    fields = dict(references)
    applied = []
    for offset, name, kind in relocs:
        field = START + offset
        site, next_ip, expected, width, access = fields.pop(field)
        if not 4 <= kind <= 9:
            raise ValueError(f"unexpected REL32 relocation type {kind}")
        addend = struct.unpack_from("<i", text, offset)[0]
        displacement = BINDINGS[name] + addend - (field + kind)
        equal(next_ip + displacement, expected, f"relocation target at {site:#x}")
        struct.pack_into("<i", text, offset, displacement)
        applied.append({"site": hex(site), "field": hex(field), "symbol": name, "kind": kind,
                        "addend": addend, "target": hex(expected), "width": width, "access": access})
    equal(fields, {}, "missing original references")
    equal(text, region, "relocated .text")
    return applied


def check_unwind(obj, pe, image):
    runtime = next(r.struct for r in pe.DIRECTORY_ENTRY_EXCEPTION if r.struct.BeginAddress == START)
    equal((runtime.EndAddress, runtime.UnwindData), (END, 0x1C3AC), "exception-directory entry")
    xdata, _, xr = objects(obj, b".xdata")
    equal(xr, [], ".xdata relocations")
    equal(xdata, image[runtime.UnwindData:runtime.UnwindData + 16], "unwind info")
    pdata, _, pr = objects(obj, b".pdata")
    equal(pr, [(0, ".text", 3), (4, ".text", 3), (8, ".xdata", 3)], "ADDR32NB relocations")
    for offset, name, _ in pr:
        addend = struct.unpack_from("<I", pdata, offset)[0]
        rva = runtime.UnwindData if name == ".xdata" else START
        struct.pack_into("<I", pdata, offset, rva + addend)
    equal(pdata, runtime.__pack__(), "runtime function bytes")
    return {"pdata_rva": hex(pe.get_rva_from_offset(runtime.get_file_offset())),
            "pdata": pdata.hex(), "pdata_relocations": len(pr),
            "xdata_rva": hex(runtime.UnwindData), "xdata": xdata.hex()}


def check_storage(obj, image):
    matched = []
    for section, symbol, start, length in ((b".data", "initial_cache_cutoffs", 0x22230, 64),
                                          (b".rdata", "debug_variable_name", 0x1A970, 21)):
        data, symbols, relocations = objects(obj, section)
        equal(relocations, [], f"{symbol} relocations")
        location = symbols[symbol]
        payload = data[location:location + length]
        equal(payload, image[start:start + length], symbol)
        matched.append({"symbol": symbol, "rva": hex(start), "bytes": length,
                        "sha256": sha256(payload).hexdigest()})
    return matched


def check_imports(pe, image, transfers):
    imports = {s.address - pe.OPTIONAL_HEADER.ImageBase: (d.dll.decode(), s.name.decode())
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    calls = {int(t["site"], 16): int(t["target"], 16) for t in transfers if t["mnemonic"] == "call"}
    result = []
    for site, thunk, slot, dll, name in (
        (0x14F02, 0x180D2, 0x19108, "api-ms-win-crt-environment-l1-1-0.dll", "getenv"),
        (0x14F67, 0x180D8, 0x19128, "api-ms-win-crt-runtime-l1-1-0.dll", "exit"),
    ):
        equal(calls[site], thunk, "call to import thunk")
        ins = Decoder(64, image[thunk:thunk + 6], ip=thunk).decode()
        equal((image[thunk:thunk+2], ins.len, ins.ip_rel_memory_address), (b"\xff\x25", 6, slot),
              "indirect jump to IAT")
        equal(imports[slot], (dll, name), "import name")
        result.append({"site": hex(site), "thunk": hex(thunk), "iat": hex(slot), "import": dll+"!"+name})
    return result


def replay(original, compiler, destination):
    binary = original.read_bytes()
    equal(sha256(binary).hexdigest(), ORIGINAL, "original SHA-256")
    pe = pefile.PE(data=binary)
    image = pe.get_memory_mapped_image()
    region = image[START:END]
    equal(sha256(region).hexdigest(), RANGE, "range SHA-256")
    instructions, refs, transfers = decode(region)
    with TemporaryDirectory() as directory:
        obj = build(compiler, "configure-cache-cutoffs.c", Path(directory) / "code.obj")
        data = build(compiler, "cutoff-data.c", Path(directory) / "data.obj")
    applied = check_text(obj, region, refs)
    unwind = check_unwind(obj, pe, image)
    storage = check_storage(data, image)
    imports = check_imports(pe, image, transfers)
    if destination:
        destination.mkdir(parents=True, exist_ok=True)
        (destination / "instructions.lst").write_text(
            "".join(f"{i.address:#x} {i.bytes.hex()} {i.mnemonic} {i.op_str}".rstrip()+"\n"
                    for i in instructions), encoding="utf-8", newline="\n")
    return {"original_sha256": ORIGINAL, "range": [hex(START), hex(END)], "range_sha256": RANGE,
            "matched_bytes": len(region), "instructions": len(instructions),
            "coff_text_relocations": applied, "direct_transfers": transfers, "unwind": unwind,
            "storage": storage, "imports": imports}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("zig", type=Path)
    parser.add_argument("--evidence-dir", type=Path)
    args = parser.parse_args()
    print(json.dumps(replay(args.original, args.zig, args.evidence_dir), indent=2))

