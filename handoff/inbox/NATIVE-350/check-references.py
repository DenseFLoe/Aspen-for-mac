"""Independently check scopes, instruction evidence and the s1 transfer index."""
import argparse
from collections import Counter
import csv
import hashlib
from pathlib import Path
import re
import json
from capstone import Cs,CS_ARCH_X86,CS_MODE_64
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_REG_RIP
import pefile

ROOT=Path(__file__).resolve().parent

def rows(name):
    with (ROOT/name).open(encoding="utf-8-sig",newline="") as stream:
        return list(csv.DictReader(stream))

def verify(original,asm,cfile):
    for source,sha in [(original,"09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"),(asm,"fdce8c9db94517169eebc1104dc1a05f595cdf28425ba0027494ed8df0bdda6a"),(cfile,"1e1e448a9fde6212ba7cbcfccc286f92b77f9e1d85bed92f7ea56bb3615d479b")]:
        assert hashlib.sha256(source.read_bytes()).hexdigest()==sha
    pe=pefile.PE(str(original));image=pe.get_memory_mapped_image();base=pe.OPTIONAL_HEADER.ImageBase
    md=Cs(CS_ARCH_X86,CS_MODE_64);md.detail=True
    old=asm.read_text(encoding="utf-8-sig").splitlines();c=cfile.read_text(encoding="utf-8-sig").splitlines()
    ordinary={};heads=[]
    for line in old:
        if line.startswith("FUNC "):
            _,v,name=line.split(maxsplit=2);owner=int(v,16)-base;heads.append(owner)
        elif m:=re.match(r"^  ([0-9a-fA-F]+):\s+(.+)",line):
            site=int(m[1],16)-base
            if re.match(r"align\b|d[bwdq]\b",m[2],re.I) and site!=0x15bda:continue
            ordinary[site]=owner
    assert 0x180c0 not in ordinary;ordinary[0x180c0]=0x180c0
    meta=rows("legacy-functions.csv")
    assert len(meta)==len(heads)
    for r in meta:
        addr=int(r["rva"],0)
        assert old[int(r["prior_asm_line"])-1].lower()==f"FUNC {addr+base:x} {r['name']}".lower()
        assert c[int(r["prior_c_line"])-1].lower()==f"// FUNC {addr+base:x} {r['name']}".lower()
    iat={s.address-base:d.dll.decode()+"!"+(s.name.decode() if s.name else f"#{s.ordinal}")
         for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports}
    instructions={}
    def rip(x):
        return next((x.address+x.size+op.mem.disp for op in x.operands if op.type==X86_OP_MEM and op.mem.base==X86_REG_RIP),None)
    for site in ordinary:
        instructions[site]=next(md.disasm(image[site:site+15],site,count=1))
    known={x.address:rip(x) for x in instructions.values() if x.mnemonic in ("jmp","bnd jmp") and rip(x) in iat}
    tables={0x16583:0x26040,0x165b3:0x26040,0x165c5:0x26000,0x16e90:0x26600,
        0x16eb3:0x26680,0x17379:0x26040,0x173e3:0x26680,0x17466:0x26040,
        0x174df:0x26040,0x175b4:0x26040}
    listings={}
    for path in sorted((ROOT/"code").glob("evidence-*.asm")):
        for line,txt in enumerate(path.read_text(encoding="utf-8").splitlines(),1):
            if txt.startswith(";"):continue
            addr,raw,_=txt.split("  ",2)
            site=int(addr,16)
            assert bytes.fromhex(raw)==instructions[site].bytes
            listings[f"code/{path.name}#L{line}"]=site
    submitted=set()
    counts=Counter()
    for r in rows("calls.csv"):
        site=listings[r["listing"]];x=instructions[site];slot=rip(x);target=r["callee"];kind=r["class"]
        assert int(r["caller"],0)==ordinary[site] and site not in submitted
        op=x.operands[0] if x.operands else None
        if kind=="external":
            if slot not in iat:
                assert op.type==X86_OP_IMM and op.imm in known
                slot=known[op.imm]
            assert iat[slot]==target
        elif kind=="data":
            if site in tables: assert op.type==X86_OP_MEM and int(target,0)==tables[site]
            else: assert slot is not None and target==iat.get(slot,hex(slot))
        else:
            assert kind=="unresolved" and op.type!=X86_OP_IMM and site not in tables and slot not in iat
        submitted.add(site);counts[kind]+=1
    links=rows("internal-transfers.csv")
    for row in links:
        site=int(row["site"],0);target=int(row["target"],0)
        assert ordinary[site]==int(row["owner"],0) and ordinary[target]==int(row["target_owner"],0)
        assert instructions[site].operands[0].imm==target
    cov=rows("coverage.csv")
    assert set(heads)|{0x180c0}=={int(r["key"],0) for r in cov}
    return dict(decoded=len(instructions),legacy_function_pairs=len(meta),byte_checked_listings=len(listings),
                indexed_references=dict(sorted(counts.items())),direct_transfer_rows=len(links),
                coverage=dict(Counter(r["state"] for r in cov)))

if __name__=="__main__":
    p=argparse.ArgumentParser(description=__doc__)
    for n in ("original","asm","cfile"):p.add_argument(n,type=Path)
    print(json.dumps(verify(**vars(p.parse_args())),sort_keys=True))
