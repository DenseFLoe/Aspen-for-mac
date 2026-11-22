"""Recover the exported-base accesses and the three straight-line offset initializers."""
import argparse
import hashlib
import json
from collections import defaultdict
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_MEM, X86_OP_REG, X86_REG_RIP


ORIGINAL = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
TABLE_HOLES = {0x8ea0: (0x9590, 0xa698), 0xa6c0: (0xabc0, 0xc1c0),
               0xe040: (0xe3e0, 0xf0f0), 0xf100: (0xf3c0, 0x109c0)}


def direct_target(ins, op):
    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
        return ins.address + ins.size + op.mem.disp
    return None


def make_report(original, unit):
    raw = original.read_bytes()
    if hashlib.sha256(raw).hexdigest() != ORIGINAL:
        raise ValueError("original SHA-256")
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    exports = {e.address: e.name.decode() for e in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    data = {rva: name for rva, name in exports.items()
            if pe.get_section_by_rva(rva).Name.rstrip(b"\0") == b".data"}
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    md.detail = True
    spans = json.loads((unit / "reassembly.json").read_text())["matches"]
    spans += json.loads((unit / "s5/reassembly.json").read_text())
    access = defaultdict(list)
    instructions = {}
    for item in spans:
        start = int(item["rva"], 16)
        end = start + item["bytes"]
        ranges = [(start, end)]
        if start in TABLE_HOLES:
            left, right = TABLE_HOLES[start]
            ranges = [(start, left), (right, end)]
        for lo, hi in ranges:
            for ins in md.disasm(image[lo:hi], lo):
                assert ins.address not in instructions
                instructions[ins.address] = ins
                for op in ins.operands:
                    dest = direct_target(ins, op)
                    if dest not in data:
                        continue
                    mode = "address" if ins.mnemonic == "lea" else {
                        cs.CS_AC_READ: "read", cs.CS_AC_WRITE: "write",
                        cs.CS_AC_READ | cs.CS_AC_WRITE: "read/write"}[op.access]
                    access[dest].append({"site": hex(ins.address), "owner": hex(start),
                                         "mode": mode, "width": 0 if mode == "address" else op.size,
                                         "instruction": ins.mnemonic + " " + ins.op_str})
    assert len(instructions) == 12498 and len(data) == 26
    flows = []
    for start, end, expected in [(0x85b5, 0x8653, "PPEXEC_INTPP"),
                                 (0x8806, 0x88a4, "PPEXEC_UPDRTN"),
                                 (0x8922, 0x89b4, "PPEXEC_ALLOCRTN")]:
        owner = max(int(s["rva"], 16) for s in spans if int(s["rva"], 16) <= start)
        assert exports[owner] == expected
        regs, stores, inputs = {}, [], []
        pc = start
        # Coefficients in (integer-workspace base, stride, workspace base, constant).
        while pc < end:
            ins = instructions[pc]
            d, *rest = ins.operands
            src = rest[0] if rest else None
            reg = ins.reg_name(d.reg) if d.type == X86_OP_REG else None
            if ins.mnemonic == "mov" and reg and src.type == X86_OP_MEM:
                sym = len(inputs)
                assert sym < 3 and src.size == 8
                location = direct_target(ins, src)
                inputs.append({"site": hex(pc), "source": hex(location) if location else ins.op_str})
                regs[reg] = tuple(int(i == sym) for i in range(4))
            elif ins.mnemonic == "lea":
                mem = src.mem
                assert mem.disp == -1 and mem.scale == 1
                a = regs[ins.reg_name(mem.base)]
                b = regs[ins.reg_name(mem.index)] if mem.index else (0, 0, 0, 0)
                regs[reg] = tuple(x+y-(i == 3) for i, (x, y) in enumerate(zip(a, b)))
            elif ins.mnemonic == "add":
                regs[reg] = tuple(x+y for x,y in zip(regs[reg], regs[ins.reg_name(src.reg)]))
            elif ins.mnemonic == "dec":
                a,b,c,d0 = regs[reg]
                regs[reg] = a,b,c,d0-1
            elif ins.mnemonic == "mov" and d.type == X86_OP_MEM:
                target = direct_target(ins, d)
                assert d.size == 8 and src.type == X86_OP_REG
                stores.append({"site": hex(pc), "target": data[target] if target else ins.op_str.split(",")[0],
                               "coefficients": regs[ins.reg_name(src.reg)]})
            else:
                raise ValueError(f"unexpected instruction at {pc:#x}")
            pc += ins.size
        assert pc == end
        assert [s["coefficients"] for s in stores] == ([(1,0,0,-1),(1,1,0,-1)] +
                     [(0,n,1,-1) for n in range(11)])
        assert [s["target"] for s in stores[2:12]] == [f"PPEXEC_WNC{n}" for n in range(1,11)]
        flows.append({"export": expected, "rva": hex(owner), "inputs": inputs, "stores": stores})
    return {"original_sha256": ORIGINAL, "instruction_count": len(instructions),
            "coefficient_order": ["integer_base", "stride", "workspace_base", "constant"],
            "arithmetic": "modulo 2^64", "initializers": flows,
            "direct_export_base_uses": {name: sorted(access[rva], key=lambda r: int(r["site"],16))
                                        for rva, name in sorted(data.items())}}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("unit", type=Path, help="NATIVE-346 directory containing reassembly.json and s5/")
    args = parser.parse_args()
    print(json.dumps(make_report(args.original, args.unit), indent=2))
