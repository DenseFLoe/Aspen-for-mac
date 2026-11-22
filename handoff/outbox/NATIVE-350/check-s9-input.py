"""Locate the two unverified business helpers called by the repaired DSWU_UDL01I export."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile


def check(original):
    data = original.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    assert digest == "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    ends = {e.struct.BeginAddress:e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    exp = next(e.address for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name == b"DSWU_UDL01I")
    imports = {s.address-pe.OPTIONAL_HEADER.ImageBase:(d.dll.decode(),s.name.decode() if s.name else str(s.ordinal))
               for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports}
    body = {i.address:i for i in decoder.disasm(image[exp:ends[exp]],exp)}
    helpers = []
    for call,entry in [(0x7a9a,0x9c40),(0x889a,0x2640)]:
        i = body[call]
        assert i.mnemonic == "call" and i.operands[0].type == X86_OP_IMM and i.operands[0].imm == entry
        end = ends[entry]
        code = list(decoder.disasm(image[entry:end],entry))
        assert code[-1].address+code[-1].size == end
        known = []
        for ins in code:
            if ins.mnemonic != "call" or ins.operands[0].type != X86_OP_IMM:
                continue
            target = ins.operands[0].imm
            thunk = next(decoder.disasm(image[target:target+15],target,count=1))
            if thunk.mnemonic != "jmp" or thunk.operands[0].type != X86_OP_MEM or thunk.operands[0].mem.base != X86_REG_RIP:
                continue
            slot = thunk.address+thunk.size+thunk.operands[0].mem.disp
            if slot in imports:
                known.append({"call":hex(ins.address),"via":hex(target),"symbol":"!".join(imports[slot])})
        helpers.append({"caller":hex(call),"entry":hex(entry),"end":hex(end),"bytes":end-entry,
                        "instructions":len(code),"sha256":hashlib.sha256(image[entry:end]).hexdigest(),
                        "import_calls":len(known),"first_three_import_calls":known[:3]})
    return {"original_sha256":digest,"source_export":hex(exp),"helpers":helpers}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    print(json.dumps(check(parser.parse_args().original),indent=2))
