"""Check three straight-line initializers against export RVAs in the pinned ppexec.dll."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone
import pefile
from capstone.x86 import X86_REG_RIP


def verify(original):
    raw = original.read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    if digest != "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a":
        raise ValueError("original SHA-256")
    pe = pefile.PE(data=raw)
    exports = {s.name.decode(): s.address for s in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True
    paths = []
    for begin, end in [(0x85e1, 0x8649), (0x8832, 0x889a), (0x8946, 0x89ae)]:
        instructions = list(md.disasm(pe.get_data(begin, end-begin), begin))
        assert instructions[-1].address + instructions[-1].size == end
        assert (instructions[0].mnemonic, instructions[0].op_str) == ("lea", "rdx, [rcx - 1]")
        pos = 1
        stores = []
        for n in range(1, 11):
            if n > 1:
                assert (instructions[pos].mnemonic, instructions[pos].op_str) == ("add", "rcx, rax")
                pos += 1
            if n == 2:
                assert (instructions[pos].mnemonic, instructions[pos].op_str) == ("dec", "rcx")
                pos += 1
            i = instructions[pos]
            dst, src = i.operands
            assert i.mnemonic == "mov" and dst.mem.base == X86_REG_RIP and dst.size == 8
            assert i.reg_name(src.reg) == ("rdx" if n == 1 else "rcx")
            target = i.address + i.size + dst.mem.disp
            name = f"PPEXEC_WNC{n}"
            assert target == exports[name]
            stores.append({"name": name, "site": hex(i.address), "target": hex(target),
                           "bytes": i.bytes.hex(), "rax_multiplier": n-1})
            pos += 1
        assert pos == len(instructions)
        paths.append({"start": hex(begin), "end_exclusive": hex(end), "stores": stores})
    return {"original_sha256": digest, "value_u64": "RCX_at_start - 1 + rax_multiplier * RAX_at_start",
            "paths": paths}


if __name__ == "__main__":
    cli = argparse.ArgumentParser(description=__doc__)
    cli.add_argument("original", type=Path)
    print(json.dumps(verify(cli.parse_args().original), indent=2))
