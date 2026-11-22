"""Verify the recovered copy path, thunk bodies, pointer tables, version and fail-fast call."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import pefile
from iced_x86 import Decoder, FlowControl
from version import encode_version


ROOT=Path(__file__).resolve().parent
DIGEST="09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"


def objects(data,section=b".text"):
    arch, n, _, symtab, count, opt, _ = struct.unpack_from("<HHIIIHH",data)
    assert arch==0x8664 and opt==0
    syms={}
    i=0
    while i<count:
        p=symtab+18*i
        name=data[p:p+8]
        if not any(name[:4]):
            a=symtab+18*count+int.from_bytes(name[4:],"little")
            name=data[a:data.index(b"\0",a)]
        val, sec, _, _, aux = struct.unpack_from("<IhHBB",data,p+8)
        syms[i]=name.rstrip(b"\0").decode(),val,sec
        i+=aux+1
    for i in range(n):
        name,_,_,size,raw,rel,_,nrel,_,_=struct.unpack_from("<8sIIIIIIHHI",data,20+40*i)
        if name.rstrip(b"\0")==section:
            byname={name:pos for name,pos,sec in syms.values() if sec==i+1}
            payload=bytearray(data[raw:raw+size]) if raw else bytearray(size)
            return payload,byname,[(p,syms[t][0],k) for p,t,k in (struct.unpack_from("<IIH",data,rel+10*j) for j in range(nrel))]
    raise ValueError(f"COFF section missing: {section!r}")


def verify(original,compiler):
    binary=original.read_bytes()
    assert hashlib.sha256(binary).hexdigest()==DIGEST
    pe=pefile.PE(data=binary); img=pe.get_memory_mapped_image(); base=pe.OPTIONAL_HEADER.ImageBase
    with tempfile.TemporaryDirectory() as tmp:
        obj=Path(tmp)/"zedstwu.obj"
        subprocess.run([str(compiler.resolve()),"cc","-target","x86_64-windows-gnu","-g0","-O2","-c",str(ROOT/"code/zedstwu.c"),"-o",str(obj)],check=True)
        text,symbols,relocations=objects(obj.read_bytes())
        static=Path(tmp)/"copy-data.obj"
        subprocess.run([str(compiler.resolve()),"cc","-target","x86_64-windows-gnu","-g0","-O2","-c",str(ROOT/"code/copy-data.c"),"-o",str(static)],check=True)
        storage=static.read_bytes()
    thunks={v:int(k[6:],16) for k,v in symbols.items() if k.startswith("thunk_")}
    labels={v:int(k[4:],16) for k,v in symbols.items() if k.startswith("loc_")}
    start=symbols["copy_body"]; finish=symbols["copy_end"]
    for pos,name,kind in relocations:
        assert re.fullmatch("rva_[0-9a-f]+",name) and 4<=kind<=9
        if start<=pos<finish:
            site=0x16560+pos-start
        else:
            site=thunks[pos-2]+2
        delta=int(name[4:],16)+struct.unpack_from("<i",text,pos)[0]-(site+4+kind-4)
        struct.pack_into("<i",text,pos,delta)
    mismatched=[(hex(rva),hex(0x16560+pos-start)) for pos,rva in sorted(labels.items()) if rva!=0x16560+pos-start]
    if mismatched: raise ValueError(f"instruction label drift: {mismatched[:6]}")
    body=text[start:finish]
    expected=img[0x16560:0x1760a]
    errors=[(hex(0x16560+i),hex(a),hex(b)) for i,(a,b) in enumerate(zip(body,expected)) if a!=b]
    if errors or len(body)!=len(expected): raise ValueError(f"copy assembly {len(body)}/{len(expected)} bytes, differences: {errors[:25]}")
    for pos,site in thunks.items():
        assert text[pos:pos+6]==img[site:site+6],hex(site)
    assert len(thunks)==128
    imports={s.address-base:(d.dll.decode(),s.name.decode() if s.name else f"#{s.ordinal}") for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports}
    new=Decoder(64,img[0x180c0:0x180cf],ip=0x180c0).decode()
    assert 0x180c0 in thunks.values() and new.ip_rel_memory_address==0x19150 and imports[0x19150][1]=="_crt_at_quick_exit"
    assert Decoder(64,img[0x15d08:0x15d16],ip=0x15d08).decode().near_branch_target==0x180c0
    rr={r.rva for block in pe.DIRECTORY_ENTRY_BASERELOC for r in block.entries if r.type==10}
    populations={}
    with (ROOT/"copy-tables.csv").open(encoding="utf-8",newline="") as f:
        for row in csv.DictReader(f):
            table=int(row["table_rva"],0); slot=int(row["slot_rva"],0); target=int(row["target_rva"],0); ix=int(row["index"])
            assert ix==populations.get(table,0) and slot==table+ix*8 and slot in rr and target in labels.values()
            assert struct.pack("<Q",base+target)==img[slot:slot+8]
            populations[table]=ix+1
    assert populations=={0x26000:8,0x26040:184,0x26600:16,0x26680:9}
    pointers, groups, ptr_reloc=objects(storage,b".rdata")
    count=0
    for pos,sym,kind in ptr_reloc:
        assert kind==1 and re.fullmatch("loc_[0-9a-f]+",sym) and sym in symbols
        table,start=next((t,groups[f"rva_{t:x}"]) for t,n in populations.items() if groups[f"rva_{t:x}"]<=pos<groups[f"rva_{t:x}"]+n*8)
        assert pos%8==0 and pointers[pos:pos+8]==bytes(8)
        address=base+int(sym[4:],16); assert struct.pack("<Q",address)==img[table+pos-start:table+pos-start+8]
        count+=1
    assert count==sum(populations.values()) and len({p for p,_,_ in ptr_reloc})==count
    for section,symbol,size,site in [(b".data","rva_22238",8,0x22238),(b".bss","rva_23630",4,0x23630)]:
        payload,offsets,rrs=objects(storage,section)
        off=offsets[symbol]
        assert not rrs and payload[off:off+size]==img[site:site+size]
    data=json.loads((ROOT/"copy-data.json").read_text(encoding="utf-8"))
    for rec in data["globals"]:
        at=int(rec["rva"],0)
        assert int.from_bytes(img[at:at+rec["size"]],"little")==rec["initial_value"]
        assert all(Decoder(64,img[r:r+15],ip=r).decode().ip_rel_memory_address==at for r in (int(x,0) for x in rec["references"]))
    version=encode_version(json.loads((ROOT/"version.json").read_text(encoding="utf-8")))
    r=pe.DIRECTORY_ENTRY_RESOURCE.entries
    assert len(r)==1 and r[0].id==16
    ids=r[0].directory.entries; assert len(ids)==1 and ids[0].id==1
    langs=ids[0].directory.entries; assert len(langs)==1 and langs[0].id==1033
    v=langs[0].data.struct
    assert v.OffsetToData==0x28060 and v.Size==800 and version==img[0x28060:0x28380]
    assert hashlib.sha256(version).hexdigest()=="c8340abd3cf535ddffe9bd79f46dc167df48ee78d02d5378639c7505e67f9ccf"
    assert img[0x15bd0:0x15bd5]==bytes.fromhex("b905000000") and img[0x15bda]==0xcc
    f=Decoder(64,img[0x15bd5:0x15be0],ip=0x15bd5).decode()
    assert f.flow_control==FlowControl.CALL and f.near_branch_target==0x15d48
    return dict(original_sha256=DIGEST,compiler="Zig "+subprocess.check_output([str(compiler.resolve()),"version"],text=True).strip(),
                source_span=["0x16560","0x1760a"],source_labels=len(labels),source_span_bytes=len(body),
                span_sha256=hashlib.sha256(body).hexdigest(),import_thunks=len(thunks),import_thunk_bytes=len(thunks)*6,
                code_relocations=len(relocations),switch_tables={hex(k):v for k,v in populations.items()},
                switch_entries=sum(populations.values()),table_coff_addr64=count,compiled_globals=2,verified_version_bytes=len(version),
                fastfail_call_rva="0x15bd5",fastfail_target_rva="0x15d48",after_call="INT3 at 0x15bda")


if __name__=="__main__":
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("original",type=Path);p.add_argument("compiler",type=Path)
    args=p.parse_args()
    print(json.dumps(verify(args.original,args.compiler),sort_keys=True))
