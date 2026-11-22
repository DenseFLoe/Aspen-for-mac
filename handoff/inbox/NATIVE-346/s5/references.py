"""Index the reassembled PE text with uniform call, data and table evidence."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

import capstone
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_REG_RIP
import pefile
from verify import DIGEST, HERE, UNIT, SITES, TABLES, decode_ranges

# Bounds established at these transfers by unsigned fall-through or an alignment mask.
# Other indexed transfers retain an unresolved index bound even when every stored
# table value itself has been decoded. The maximum is inclusive.
PROVEN={
    0x8ebf:(0,256),0x8efa:(1,31),0x921d:(0,31),0xa711:(1,63),
    0xe078:(0,128),0xe0a4:(1,31),0xe26a:(0,31),0xf15b:(1,63),0xf2ef:(0,63),
    0xaac1:(0,63),0x12cd5:(0,7),0x135a0:(0,15),0x13d91:(1,7),0x1403f:(0,15),
}
SELECTORS={
    0x8d30:(0x20a90,[0xa6c0,0x8ea0,0x12c70,0x1479a]),
    0x8dcb:(0x20a90,[0xa6c0,0x8ea0,0x12c70,0x1479a]),
    0x8e00:(0x20a98,[0xf100,0xe040,0x13d20,0x14794]),
    0x8e98:(0x20a98,[0xf100,0xe040,0x13d20,0x14794]),
}
def load_table(path):
    with path.open(encoding="utf-8-sig",newline="") as src:
        return list(csv.DictReader(src))

def write_csv(path,fields,rows):
    with path.open("w",encoding="utf-8",newline="") as out:
        writer=csv.DictWriter(out,fieldnames=fields,lineterminator="\n")
        writer.writeheader()
        writer.writerows(rows)

def run(original,out):
    raw=original.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==DIGEST
    pe=pefile.PE(data=raw)
    image=pe.get_memory_mapped_image()
    base=pe.OPTIONAL_HEADER.ImageBase
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64);md.detail=True
    iat={s.address-base:d.dll.decode()+"!"+(s.name.decode() if s.name else str(s.ordinal))
         for name in ("DIRECTORY_ENTRY_IMPORT","DIRECTORY_ENTRY_DELAY_IMPORT")
         for d in getattr(pe,name,[]) for s in d.imports}
    def rip(i):
        return next((i.address+i.size+o.mem.disp for o in i.operands if o.type==X86_OP_MEM and o.mem.base==X86_REG_RIP),None)
    prior=json.loads((UNIT/"reassembly.json").read_text())["matches"]
    supplement=json.loads((HERE/"reassembly.json").read_text())
    spans=sorted((int(r["rva"],16),int(r["rva"],16)+r["bytes"]) for r in prior+supplement)
    areas={k:[i for a,b in decode_ranges(k,e) for i in md.disasm(image[a:b],a)] for k,e in spans}
    starts={i.address for seq in areas.values() for i in seq}
    thunk={k:rip(seq[0]) for k,seq in areas.items() if len(seq)==1 and seq[0].mnemonic=="jmp" and rip(seq[0]) in iat}
    tables={int(r["site_rva"],16):int(r["table_rva"],16) for r in load_table(HERE/"dispatch.csv")}
    values={int(r["table_rva"],16):{} for f in HERE.glob("table-*.csv") for r in load_table(f)}
    for f in HERE.glob("table-*.csv"):
        for r in load_table(f):
            if r["target_rva"]: values[int(r["table_rva"],16)][int(r["index"])]=int(r["target_rva"],16)
    rels=[]; calls=[]; unknown=[]; owners=[]; entry_listing={}
    out.mkdir(parents=True,exist_ok=True)
    dt=out/"s5";dt.mkdir(exist_ok=True)
    part=0;lines=[];written=[]
    def flush():
        if lines:
            (dt/name).write_bytes(("\n".join(lines)+"\n").encode())
    assert pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct.GuardCFDispatchFunctionPointer-base==0x15d00
    guard=struct.unpack_from("<Q",image,0x15d00)[0]-base
    assert guard==0x14c40 and image[guard:guard+2]==b"\xff\xe0"
    empty={}
    for owner,left,right,slot,site in [(0x126b4,0x126be,0x126c5,0x1a000,0x126d6),
                                      (0x126f0,0x126fa,0x12701,0x1a010,0x12712)]:
        idx={i.address:i for i in areas[owner]}
        assert idx[left].mnemonic==idx[right].mnemonic=="lea" and rip(idx[left])==rip(idx[right])==slot
        go=idx[right+idx[right].size]
        assert go.mnemonic=="jmp"
        cmp=idx[go.operands[0].imm]
        branch=idx[cmp.address+cmp.size]
        assert cmp.mnemonic=="cmp" and cmp.op_str=="rbx, rdi" and branch.mnemonic=="jb" and branch.operands[0].imm<site
        empty[site]=slot
    write_sites={slot:[] for slot in (0x20a90,0x20a98)}
    for owner,seq in areas.items():
        if not lines or sum(map(len,lines))>70000:
            flush();part+=1;name=f"references-{part:02}.asm";lines=[]
        for i in seq:
            p=i.address;target=rip(i)
            if target in write_sites and i.operands[0].type==X86_OP_MEM and i.operands[0].access & capstone.CS_AC_WRITE:
                write_sites[target].append(p)
            transfer=i.group(capstone.CS_GRP_JUMP) or i.group(capstone.CS_GRP_CALL)
            direct=i.operands[0].imm if transfer and i.operands[0].type==X86_OP_IMM else None
            if p!=owner and not transfer and target is None:continue
            lines.append(f"{p:08x}  {i.bytes.hex(' ')}  {i.mnemonic} {i.op_str}".rstrip())
            if direct in thunk and i.mnemonic not in ("jmp","call"):
                veneer=areas[direct][0]
                lines[-1]+=f" ; if taken: {direct:#x} {veneer.bytes.hex()} {veneer.mnemonic} {veneer.op_str}"
            ref=f"s5/{name}#L{len(lines)}"
            if p==owner:entry_listing[owner]=ref
            def edge(t,basis):
                assert t in starts
                rels.append(dict(owner_rva=hex(owner),site_rva=hex(p),target_rva=hex(t),basis=basis))
            def record(t,group,note):
                calls.append(dict(kind="native",caller=hex(owner),callee=t,**{"class":group},listing=ref,note=f"site {p:#x}, {note}"))
                if group=="unresolved":unknown.append(dict(owner_rva=hex(owner),site_rva=hex(p),observation=note))
            if target is not None:
                data_name=f"IAT {target:#x} ({iat[target]})" if target in iat else f"RVA {target:#x}"
                record(data_name,"data",f"RIP-relative operand, RVA {target:#x}")
            if not transfer:continue
            if direct is not None:
                edge(direct,"direct")
                if direct in thunk:
                    slot=thunk[direct]
                    record(iat[slot],"external",f"via import veneer {direct:#x}, IAT {slot:#x}")
            elif target in iat:
                record(iat[target],"external",f"transfer through IAT {target:#x}")
            elif p==0x17a5:
                for j in range(179):
                    edge(0x15dc0+struct.unpack_from("<i",image,0x15dc0+4*j)[0],"179-case table indexed after unsigned guard")
            elif p in SELECTORS:
                slot,targets=SELECTORS[p]
                for t in targets:edge(t,f"cache {slot:#x}, three CPU masks plus fallback")
            elif p in empty:
                edge(guard,f"GuardCFDispatch slot; static call is unreachable: iterator endpoints both {empty[p]:#x}, unsigned JB is false")
            elif p in tables:
                table=tables[p];domain=PROVEN.get(p)
                basis=f"table {table:#x}, "
                if domain:
                    lo,hi=domain
                    targets={values[table][j] for j in range(lo,hi+1)}
                    basis+=f"guard/mask index {lo}..{hi}"
                else:
                    targets=set(values[table].values())
                    basis+="materialized non-null entries, index path constraint not certified"
                    record(f"{i.op_str} via table {table:#x}","unresolved",
                           f"verify caller size and loop/index bounds on every incoming path; physical targets in s5/table-{owner:x}.csv")
                for t in sorted(targets):edge(t,basis)
            else:
                detail=f"trace incoming {i.op_str} value and callback argument definition"
                if target==0x15d00 or p==0x11c56:
                    edge(guard,"load-config GuardCFDispatch slot 0x15d00, on-disk initial value")
                    detail="GuardCFDispatch slot 0x15d00 initially leads to 0x14c40 then RAX; verify the callback value and loader-selected dispatcher"
                elif p in (0x127a8,0x127c0,0x12901):
                    detail="RAX loaded from load-config CastGuardOsDeterminedFailureMode slot 0x15d18; null on disk; loader supplies non-null value"
                elif p==0x14c40:
                    detail="initial GuardCFDispatch relay; resolve RAX on each incoming call path"
                record(i.op_str,"unresolved",detail)
    flush()
    assert write_sites=={0x20a90:[0x8dbd],0x20a98:[0x8e8a]}
    assert len({(r['caller'],r['listing'],r['callee'],r['class']) for r in calls})==len(calls)
    write_csv(out/"calls.csv",calls[0].keys(),calls)
    write_csv(out/"control-gaps.csv",["owner_rva","site_rva","observation"],unknown)
    write_csv(out/"internal-transfers.csv",rels[0].keys(),rels)
    (dt/"entry-references.json").write_bytes((json.dumps({hex(k):v for k,v in entry_listing.items()},indent=2)+"\n").encode())
    print(json.dumps(dict(spans=len(spans),external=sum(r["class"]=="external" for r in calls),
                data=sum(r["class"]=="data" for r in calls),unresolved=len(unknown),internal_edges=len(rels),
                scans=len(starts),remaining_table_domains=len(tables)-len(PROVEN)),indent=2))
if __name__=="__main__":
    p=argparse.ArgumentParser(description=__doc__);p.add_argument("original",type=Path);p.add_argument("--write",type=Path,required=True)
    a=p.parse_args();run(a.original,a.write)

