"""Reassemble the additional ppexec AMD64 implementations, then check table operands and code boundaries."""
import argparse
import csv
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile

import capstone
from capstone.x86 import X86_REG_RIP, X86_OP_MEM, X86_OP_IMM
import iced_x86
import pefile

HERE = Path(__file__).resolve().parent
UNIT = HERE.parent
DIGEST = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
# Each tuple gives the table start in the original and its number of physical entries.
# Bounded indexing and the tables' storage are distinguished in dispatch.csv.
TABLES = {
    0x8ea0: [(0x9590,32), (0x9690,256), (0x9e90,257)],
    0xa6c0: [(0xabc0,64), (0xadc0,512), (0xbdc0,128)],
    0xe040: [(0xe3e0,32), (0xe4e0,256), (0xece0,129)],
    0xf100: [(0xf3c0,64), (0xf5c0,512), (0x105c0,128)],
    0x12c70: [(0x24000,8),(0x24040,184),(0x24600,16),(0x24680,14)],
    0x13d20: [(0x246f0,8),(0x24730,136),(0x24b70,18),(0x24c00,192)],
}
# Original RVAs of the indexed transfer and its supplying LEA.
SITES = {
    0x8ea0:[(0x8ebf,0x8eb4),(0x8efa,0x8ed0),(0x91a4,0x9199),(0x921d,0x920f)],
    0xa6c0:[(0xa6e4,0xa6c4),(0xa711,0xa6e7),(0xaa51,0xaa46),(0xaac1,0xaab6)],
    0xe040:[(0xe078,0xe059),(0xe0a4,0xe080),(0xe215,0xe20a),(0xe26a,0xe25f)],
    0xf100:[(0xf135,0xf115),(0xf15b,0xf137),(0xf2aa,0xf29f),(0xf2ef,0xf2e4)],
    0x12c70:[(0x12c93,0x12c80),(0x12cc3,0x12ca9),(0x12cd5,0x12cc7),(0x135a0,0x13577),
             (0x135c3,0x135a4),(0x13a89,0x13a79),(0x13af3,0x13ad1),(0x13b76,0x13b69),
             (0x13bef,0x13be0),(0x13cc4,0x13cb7)],
    0x13d20:[(0x13d63,0x13d4c),(0x13d91,0x13d76),(0x1403f,0x1401d),(0x140b2,0x1409b),
             (0x145f5,0x145eb),(0x1465b,0x14651),(0x146a8,0x1469d),(0x14700,0x146f5)],
}
def decode_ranges(owner,end):
    if owner not in TABLES or TABLES[owner][0][0]>=end:
        return [(owner,end)]
    tables=TABLES[owner]
    start,count=tables[-1]
    # One extra non-indexed word separates the bounded table from the return path.
    return [(owner,tables[0][0]),(start+8*count+(8 if owner==0xe040 else 0),end)]

def run(original,compiler):
    raw=original.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==DIGEST
    pe=pefile.PE(data=raw)
    image=pe.get_memory_mapped_image()
    md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
    md.detail=True
    spec=importlib.util.spec_from_file_location("ppexec_rebuild",UNIT/"rebuild.py")
    rebuild=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(rebuild)
    bounds={}
    sources=sorted((UNIT/"code").glob("runtime-s5-*.c"))
    for source in sources:
        for match in re.finditer(r"/\* (0x[\da-f]+)\.\.(0x[\da-f]+), Windows AMD64\. \*/",source.read_text()):
            lo,hi=map(lambda v:int(v,16),match.groups())
            assert lo not in bounds and lo<hi
            bounds[lo]=hi

    rows=[]
    version=subprocess.check_output([str(compiler),"version"],text=True).strip()
    assert version=="0.13.0"
    with tempfile.TemporaryDirectory() as temp:
        for source in sources:
            obj=Path(temp)/(source.stem+".obj")
            subprocess.run([str(compiler),"cc","-target","x86_64-windows-gnu","-O2","-g0",
                            "-fno-stack-protector","-fno-asynchronous-unwind-tables","-c",str(source),
                            "-o",str(obj)],check=True)
            rows.extend(rebuild.coff_functions(obj.read_bytes(),{},image,bounds))
    assert {int(r["rva"],16) for r in rows}==set(bounds) and len(rows)==len(bounds)
    text_sec=next(sec for sec in pe.sections if sec.Name.rstrip(b"\0")==b".text")
    prior=json.loads((UNIT/"reassembly.json").read_text())["matches"]
    spans=sorted((int(r["rva"],16),int(r["rva"],16)+r["bytes"]) for r in rows+prior)
    cursor=text_sec.VirtualAddress
    pad=[]
    for lo,end in spans+[(cursor+text_sec.Misc_VirtualSize,0)]:
        assert lo>=cursor
        if lo>cursor:
            decoded=list(md.disasm(image[cursor:lo],cursor))
            assert decoded and decoded[-1].address+decoded[-1].size==lo
            assert all(i.mnemonic in ("nop","int3") for i in decoded)
            pad.append(dict(begin=hex(cursor),end=hex(lo),sha256=hashlib.sha256(image[cursor:lo]).hexdigest()))
        cursor=end

    relocs={e.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for e in block.entries if e.type==10}
    tables=[]
    decisions=[]
    decoded_count=0
    for owner,end in bounds.items():
        items={}
        for lo,hi in decode_ranges(owner,end):
            seq=list(md.disasm(image[lo:hi],lo))
            iced=list(iced_x86.Decoder(64,image[lo:hi],ip=lo))
            assert [(i.address,i.size) for i in seq]==[(i.ip,i.len) for i in iced]
            assert seq and seq[-1].address+seq[-1].size==hi
            items.update((i.address,i) for i in seq)
        decoded_count+=len(items)
        for table,count in TABLES.get(owner,[]):
            absolute=table>=0x24000
            for k in range(count):
                slot=table+8*k
                value=struct.unpack_from("<Q",image,slot)[0]
                target=value-pe.OPTIONAL_HEADER.ImageBase if absolute else table-value
                if absolute and slot not in relocs:
                    assert value==0 and slot in (0x246c8,0x24bf8)
                    target=None
                else:
                    assert target in items
                tables.append((hex(owner),hex(table),k,hex(slot),hex(value),hex(target) if target is not None else "",
                               "DIR64" if absolute and target is not None else "null" if absolute else "table_minus_target"))
        for site,lea_rva in SITES.get(owner,[]):
            ins=items[site]
            lea=items[lea_rva]
            assert ins.mnemonic.endswith("jmp") and len(ins.operands)==1 and lea.mnemonic=="lea"
            operand=lea.operands[1]
            assert operand.type==X86_OP_MEM and operand.mem.base==X86_REG_RIP
            table=lea.address+lea.size+operand.mem.disp
            assert table in dict(TABLES[owner])
            load=ins if table>=0x24000 else next(i for i in items.values() if i.address+i.size==site)
            if table<0x24000:
                assert load.mnemonic=="sub" and load.operands[0].reg==ins.operands[0].reg==lea.operands[0].reg
            assert load.operands[-1].mem.scale==8 and load.operands[-1].mem.base==lea.operands[0].reg
            decisions.append((hex(owner),hex(site),hex(lea_rva),hex(table),md.reg_name(load.operands[-1].mem.index),
                              ins.bytes.hex(),hex(load.address),load.bytes.hex()))
    summary=dict(original_sha256=DIGEST,compiler="Zig "+version,additional_spans=len(rows),
                 additional_bytes=sum(r["bytes"] for r in rows),additional_rel32=sum(len(r["relocations"]) for r in rows),
                 total_spans=len(spans),total_bytes=sum(hi-lo for lo,hi in spans),padding_bytes=sum(int(r["end"],16)-int(r["begin"],16) for r in pad),
                 text_virtual_bytes=text_sec.Misc_VirtualSize,additional_instructions=decoded_count,
                 tables=len({r[1] for r in tables}),table_slots=len(tables),null_storage=sum(r[-1]=="null" for r in tables),
                 indexed_transfer_sites=len(decisions))
    return summary,rows,pad,tables,decisions

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("original",type=Path)
    p.add_argument("compiler",type=Path)
    p.add_argument("--write",type=Path,help="write reproduced detail files to this folder")
    a=p.parse_args()
    summary,rows,pad,tables,decisions=run(a.original,a.compiler.resolve())
    if a.write:
        a.write.mkdir(parents=True,exist_ok=True)
        for file,data in (("reassembly.json",rows),("padding.json",pad),("summary.json",summary)):
            (a.write/file).write_bytes((json.dumps(data,indent=2)+"\n").encode())
        def table_file(name,header,values):
            with (a.write/name).open("w",encoding="utf-8",newline="") as f:
                w=csv.writer(f,lineterminator="\n");w.writerow(header);w.writerows(values)
        table_file("dispatch.csv",["owner_rva","site_rva","base_lea_rva","table_rva","index","jump_bytes","fetch_rva","fetch_bytes"],decisions)
        for owner,_ in TABLES.items():
            table_file("table-"+format(owner,"x")+".csv",["owner_rva","table_rva","index","slot_rva","stored","target_rva","encoding"],
                       [r for r in tables if int(r[0],16)==owner])
    print(json.dumps(summary,indent=2))
if __name__=="__main__":
    main()
