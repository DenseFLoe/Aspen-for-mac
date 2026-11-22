"""Recheck the source and condition of the fourteen non-table callback sites."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone as cs
import pefile
from capstone.x86 import X86_OP_MEM, X86_REG_RIP


def inspect(original):
    raw = original.read_bytes()
    digest = hashlib.sha256(raw).hexdigest()
    assert digest == "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
    pe = pefile.PE(data=raw)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    md = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    md.detail = True

    def ins(rva):
        return next(md.disasm(image[rva:rva+15], rva, count=1))

    def rip(rva):
        i = ins(rva)
        return next(i.address+i.size+op.mem.disp for op in i.operands
                    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)

    def expect(rva, text):
        i = ins(rva)
        assert (i.mnemonic + " " + i.op_str).strip() == text, hex(rva)

    cfg = pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    assert cfg.GuardCFDispatchFunctionPointer-base == 0x15d00
    assert cfg.CastGuardOsDeterminedFailureMode-base == 0x15d18
    assert int.from_bytes(image[0x15d00:0x15d08],"little") == base+0x14c40
    assert cfg.DynamicValueRelocTable == cfg.DynamicValueRelocTableSection == 0
    assert image[0x17c58:0x17c60] == bytes(8)
    assert not (pe.get_section_by_rva(0x17c58).Characteristics & 0x80000000)
    assert all(not (0x17c51 <= r.rva < 0x17c60) for b in pe.DIRECTORY_ENTRY_BASERELOC for r in b.entries if r.type)
    for directory_name in ("DIRECTORY_ENTRY_IMPORT", "DIRECTORY_ENTRY_DELAY_IMPORT"):
        assert all(s.address-base != 0x17c58 for d in getattr(pe,directory_name,[]) for s in d.imports)
    rows = []

    def add(site, state, detail, evidence):
        rows.append({"site":hex(site),"state":state,"basis":detail,"evidence":[
            {"rva":hex(k),"bytes":ins(k).bytes.hex(),"asm":(ins(k).mnemonic+" "+ins(k).op_str).strip()}
            for k in dict.fromkeys(evidence+[site])]})

    for load,test,branch,site,taken in [(0x11d49,0x11d50,0x11d53,0x11d5a,True),
            (0x11dbd,0x11dc4,0x11dc7,0x11dd1,False),(0x11df7,0x11dfe,0x11e01,0x11e10,True),
            (0x11e34,0x11e3b,0x11e3e,0x11e46,True)]:
        assert rip(load) == 0x17c58 and ins(load).op_str.startswith("rax, qword ptr")
        assert rip(site) == 0x15d00
        expect(test, "test rax, rax")
        jump = ins(branch)
        assert jump.mnemonic == ("jne" if taken else "je")
        target = jump.operands[0].imm
        if taken:
            assert branch < target <= site
            # The zero arm returns or jumps past the guarded transfer.
            stop = list(md.disasm(image[branch+jump.size:target],branch+jump.size))[-1]
            assert stop.mnemonic == "ret" or (stop.mnemonic == "jmp" and stop.operands[0].imm > site)
        else:
            assert target > site
        add(site,"inactive-in-image","Read-only unrelocated zero at RVA 0x17c58; nonzero condition is false.",
            [load,test,branch])

    assert rip(0x12450) == 0x22148 and ins(0x12450).mnemonic == "lea"
    expect(0x12457,"ret")
    expect(0x11c27,"call 0x12450")
    expect(0x11c2c,"mov rbx, rax")
    expect(0x11c2f,"cmp qword ptr [rax], 0")
    expect(0x11c33,"je 0x11c59")
    expect(0x11c4c,"mov rax, qword ptr [rbx]")
    assert rip(0x11c4f) == 0x15d00
    expect(0x11c56,"call r9")
    add(0x11c56,"unresolved","Optional slot 0x22148, zero initialized in writable storage. Need registration contract.",
        [0x12450,0x12457,0x11c27,0x11c2c,0x11c2f,0x11c33,0x11c38,0x11c3f,0x11c4c,0x11c4f])
    assert rip(0x14df4) == 0x11b24 and ins(0x14df4).op_str.startswith("r9,")
    expect(0x14e06,"call 0x12188")
    expect(0x1219c,"mov rdi, r9")
    expect(0x121bd,"mov rax, rdi")
    assert rip(0x121c0) == 0x15d00
    add(0x121c0,"known-caller","Caller 0x14e06 passes internal function 0x11b24 as argument four. Additional callers must supply the same callback ABI.",
        [0x14df4,0x14e06,0x1219c,0x121a7,0x121ac,0x121ae,0x121b0,0x121b3,0x121b5,0x121b8,0x121ba,0x121bd])
    for load,test,branch,site in [(0x1279c,0x127a3,0x127a6,0x127a8),(0x127b4,0x127bb,0x127be,0x127c0),
                                  (0x128f5,0x128fc,0x128ff,0x12901)]:
        assert rip(load) == 0x15d18
        expect(test,"test rax, rax")
        assert ins(branch).mnemonic == "je" and ins(branch).operands[0].imm > site
        expect(site,"call rax")
        add(site,"unresolved","Optional named PE load-configuration callback, zero on disk. Target depends on the loader.",
            [load,test,branch])
    assert image[0x15d18:0x15d20] == image[0x20a80:0x20a88] == image[0x22148:0x22150] == bytes(8)
    assert ins(0x1283c).mnemonic == "xchg" and rip(0x1283c) == 0x20a80 and ins(0x1283c).op_str.endswith(", rcx")
    for load,test,branch,site in [(0x127e8,0x127ef,0x127f2,0x127f4),
                        (0x12804,0x1280b,0x1280e,0x12810),(0x12941,0x12948,0x1294b,0x1294d)]:
        assert rip(load) == 0x20a80 and rip(site) == 0x15d00
        expect(test,"test rax, rax")
        assert ins(branch).mnemonic == "je" and ins(branch).operands[0].imm > site
        add(site,"unresolved","Registered callback in RVA 0x20a80; 0x1283c exchanges incoming RCX with the previous value. Need registering caller.",
            [0x1283c,load,test,branch])
    expect(0x14c40,"jmp rax")
    assert rip(0x14c60) == 0x15d00 and ins(0x14c60).mnemonic == "jmp"
    for site in [0x14c40,0x14c60]:
        add(site,"unresolved","Forwarding routine. The functional target is supplied by each incoming caller.",[0x14c40])
    assert len({r["site"] for r in rows}) == 14
    return {"original_sha256": digest,"sites": sorted(rows,key=lambda r:int(r["site"],16))}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    print(json.dumps(inspect(parser.parse_args().original),indent=2))
