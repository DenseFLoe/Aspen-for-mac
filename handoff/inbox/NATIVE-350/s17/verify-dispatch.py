"""Reassemble the four zedstwu.dll dispatch ranges and verify both cache selections."""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
from iced_x86 import Decoder


HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects


RANGES = {0xCC00: 0xCC13, 0xCC20: 0xCCAE, 0xCCD0: 0xCCE3, 0xCCF0: 0xCD7B}
ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"


def verify(original, zig):
    data = original.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ORIGINAL
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    exports = {e.struct.BeginAddress: e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    assert {k: exports[k] for k in (0xCC20, 0xCCF0)} == {0xCC20: 0xCCAE, 0xCCF0: 0xCD7B}
    assert image[0xCC13:0xCC20] == image[0xCCE3:0xCCF0] == bytes([0xCC])*13

    def decode(rva):
        return next(decoder.disasm(image[rva:rva+15], rva, count=1))

    def rip(ins):
        return next(ins.address + ins.size + op.mem.disp for op in ins.operands
                    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)

    def report(ins):
        return {"rva": hex(ins.address), "bytes": ins.bytes.hex(), "asm": f"{ins.mnemonic} {ins.op_str}".strip()}

    reports = []
    with tempfile.TemporaryDirectory() as work:
        for start, end in RANGES.items():
            original_text = image[start:end]
            lines = list(decoder.disasm(original_text, start))
            independent = list(Decoder(64, original_text, ip=start))
            assert not any(i.is_invalid for i in independent)
            assert [(i.address, i.size) for i in lines] == [(i.ip, i.len) for i in independent]
            directive = {i.address-start+i.disp_offset: rip(i) for i in lines
                         if any(o.type == X86_OP_MEM and o.mem.base == X86_REG_RIP for o in i.operands)}
            directive.update({i.address-start+i.imm_offset: i.operands[0].imm for i in lines
                              if (i.group(cs.CS_GRP_CALL) or i.group(cs.CS_GRP_JUMP))
                              and i.operands[0].type == X86_OP_IMM
                              and not start <= i.operands[0].imm < end})
            source = HERE / f"sub_1800{start:X}.c"
            obj = Path(work) / source.with_suffix(".obj").name
            subprocess.run([str(zig), "cc", "-target", "x86_64-windows-gnu", "-O2", "-g0",
                            "-fno-stack-protector", "-fno-asynchronous-unwind-tables", "-c",
                            str(source), "-o", str(obj)], check=True)
            rebuilt, _, relocations = objects(obj.read_bytes())
            actual = {}
            for offset, name, kind in relocations:
                m = re.search(r"_rva_([0-9a-f]+)$", name)
                assert m and 4 <= kind <= 9
                target = int(m[1], 16)
                addend = struct.unpack_from("<i", rebuilt, offset)[0]
                struct.pack_into("<i", rebuilt, offset, target+addend-(start+offset+kind))
                actual[offset] = target
            assert actual == directive and rebuilt == original_text
            reports.append({"start": hex(start), "end": hex(end), "matched_bytes": len(rebuilt),
                            "instructions": len(lines), "relocations": len(relocations),
                            "text_sha256": hashlib.sha256(rebuilt).hexdigest()})
    imports = {s.address-base: f"{d.dll.decode()}!{s.name.decode()}"
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports if s.name}
    results = []
    for entry, cache, callers, sites in [
            (0xCC00, 0x22D10, (0x2DF5,),
             (0xCC0A,0xCC10,0xCC27,0xCC40,0xCC58,0xCC65,0xCC77,0xCC89,0xCC8B,0xCC92,0xCC99,0xCC9D,0xCCAB)),
            (0xCCD0, 0x22D18, (0x4C3D,0x4C4F),
             (0xCCDA,0xCCE0,0xCCF7,0xCD10,0xCD27,0xCD34,0xCD45,0xCD56,0xCD58,0xCD5F,0xCD66,0xCD6A,0xCD78))]:
        zero, cached, feature, highmask, high, midmask, mid, lowmask, fallback, fallback_import, cmove, store, jump = sites
        assert all(decode(rva).mnemonic == "call" and decode(rva).operands[0].imm == entry for rva in callers)
        assert rip(decode(entry)) == rip(decode(store)) == cache and image[cache:cache+8] == bytes(8)
        assert decode(zero).mnemonic == "je" and decode(zero).operands[0].imm == entry+0x20
        assert rip(decode(feature)) == 0x22D30
        assert decode(highmask).operands[1].imm == 0x7189D9FEE
        assert decode(midmask).operands[1].imm == 0x9D9FEE
        assert decode(lowmask).operands[1].imm == 0x6E and decode(cmove).mnemonic == "cmove"
        assert all(decode(s).op_str == "rax" for s in (cached, jump))
        targets = []
        for callsite in (high, mid):
            getter = decode(callsite).operands[0].imm
            lea = decode(getter)
            assert lea.mnemonic == "lea" and decode(getter+lea.size).mnemonic == "ret"
            targets.append(rip(lea))
        targets += [rip(decode(fallback)), rip(decode(fallback_import))]
        import_target = imports[rip(decode(targets[-1]))]
        assert import_target.lower() == ("vcruntime140.dll!memcpy" if entry == 0xCC00 else "vcruntime140.dll!memset")
        results.append({
            "entry": hex(entry), "callers": [hex(rva) for rva in callers], "cache_slot": hex(cache),
            "cache_write": hex(store), "cached_jump": hex(cached), "initializer_jump": hex(jump),
            "feature_word": "0x22d30", "ordered_masks": ["0x7189d9fee", "0x9d9fee", "0x6e"],
            "ordered_targets": [hex(target) for target in targets], "last_target_import": import_target,
            "instructions": [report(decode(i)) for i in sites],
        })
    return {"original_sha256": ORIGINAL, "zig": subprocess.check_output([str(zig), "version"], text=True).strip(),
            "ranges": reports, "dispatch": results}


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("original", type=Path)
    ap.add_argument("zig", type=Path)
    args = ap.parse_args()
    print(json.dumps(verify(args.original, args.zig), indent=2))
