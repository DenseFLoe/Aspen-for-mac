"""Relate Ghidra functions, PE exception entries and byte-matched source to the original."""
import argparse
from collections import defaultdict, deque
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

import capstone as cs
from capstone import x86
import pefile

SHA = "bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011"
ROOT = Path(__file__).resolve().parent


def read_table(name):
    with (ROOT/name).open(encoding="utf-8",newline="") as f:
        return list(csv.DictReader(f))


def write_table(name, fields, rows):
    with (ROOT/name).open("w",encoding="utf-8",newline="") as f:
        out = csv.writer(f,lineterminator="\n")
        out.writerow(fields.split())
        out.writerows(rows)


def save_json(name, data):
    (ROOT/name).write_bytes((json.dumps(data,ensure_ascii=False,indent=2)+"\n").encode())


def recover(data):
    if hashlib.sha256(data).hexdigest() != SHA:
        raise ValueError("Wrong original SHA-256")
    pe=pefile.PE(data=data)
    im=pe.get_memory_mapped_image()
    base=pe.OPTIONAL_HEADER.ImageBase
    md=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64)
    md.detail=True
    spans=defaultdict(list)
    for r in read_table("body-ranges.csv"):
        k,lo,hi=(int(r[n],0) for n in ("owner","start","inclusive_end"))
        spans[k].append((lo,hi+1))
    gh={int(r["rva"],0):r for r in read_table("decompiler-functions.csv")}
    assert gh.keys()==spans.keys()
    code=[(s.VirtualAddress,s.VirtualAddress+s.Misc_VirtualSize) for s in pe.sections
          if s.Characteristics&0x20000000]
    def is_code(rva):
        return any(lo<=rva<hi for lo,hi in code)
    exports={s.address:s.name.decode() for s in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    slots={s.address-base:d.dll.decode()+"!"+(s.name.decode() if s.name else f"#{s.ordinal}")
           for kind in ("DIRECTORY_ENTRY_IMPORT","DIRECTORY_ENTRY_DELAY_IMPORT")
           for d in getattr(pe,kind,[]) for s in d.imports}
    pdata={e.struct.BeginAddress:(e.struct.EndAddress,e.struct.UnwindData) for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    # Both CRT bodies have a verified suffix after the last instruction Ghidra assigned.
    # A returning final call reaches that suffix and ends at the original INT3.
    for owner in (0x244c4, 0x24ab0):
        assert len(spans[owner]) == 1 and spans[owner][0][0] == owner
        spans[owner] = [(owner, pdata[owner][0])]
    parent={}
    ranges=[]
    for k,(end,info) in sorted(pdata.items()):
        flags=im[info]>>3
        tail=info+4+4*((im[info+2]+1)//2)
        dest=None
        if flags&4:
            dest,pend,punwind=struct.unpack_from("<III",im,tail)
            if pdata.get(dest)!=(pend,punwind):
                raise ValueError(f"Broken CHAININFO at {info:#x}")
            parent[k]=dest
        ranges.append([hex(k),hex(end),hex(info),hex(flags),hex(dest) if dest is not None else ""])
    write_table("runtime-ranges.csv","rva end unwind_info flags immediate_parent",ranges)
    def primary(k):
        seen=set()
        while k in parent:
            if k in seen: raise ValueError("cyclic unwind")
            seen.add(k)
            k=parent[k]
        return k
    assert im[0xa65d:0xa696].hex()=="8b842488000000ffc88984248800000083bc24880000000f0f878b2b00004863842488000000488d0d7659ffff8b8481f0d600004803c1ffe0"
    assert im[0x21a60:0x21a85].hex()=="4883ec28ffc183f90c0f87d90400004863c1488d1587e5fdff8b8c82501f02004803caffe1"
    switches={0xa694:(0xd6f0,16,1,0xd206),0x21a83:(0x21f50,13,-1,0x21f48)}
    dispatched={}
    cases=[]
    for site,(table,count,first,default) in switches.items():
        destinations=struct.unpack_from(f"<{count}I",im,table)
        discovered={int(r["resolved_target"],0) for r in read_table("indexed-flow.csv") if int(r["site"],0)==site}
        assert set(destinations)==discovered
        dispatched[site]=destinations
        for i,d in enumerate(destinations):
            assert is_code(d)
            cases.append([hex(site),i+first,i,hex(table+4*i),hex(d),hex(default)])
    write_table("dispatch-tables.csv","site selector zero_based_index entry target default",cases)
    anchors=set(pdata)|set(exports)|{pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    entries=anchors|set(spans)
    pending=deque(sorted(entries))
    insns={}
    observations=defaultdict(list)
    direct_edges=set()
    allsites=defaultdict(list)
    def one(a):
        return next(md.disasm(im[a:a+15],a,count=1),None)
    def rip(ins):
        for operand in ins.operands:
            if operand.type==x86.X86_OP_MEM and operand.mem.base==x86.X86_REG_RIP:
                return ins.address+ins.size+operand.mem.disp
        return None
    def import_thunk(a):
        if is_code(a):
            at=one(a)
            if at and at.mnemonic=="jmp":
                return slots.get(rip(at))
        return None
    while pending:
        owner=pending.popleft()
        region=spans.get(owner)
        if not region:
            hi=pdata[owner][0] if owner in pdata else min(x for x in [k for k in entries if k>owner]+[z for _,z in code if z>owner])
            region=[(owner,hi)]
        blocks=[owner]
        instructions={}
        while blocks:
            pos=blocks.pop()
            while pos not in instructions:
                hi=next((z for a,z in region if a<=pos<z),None)
                if hi is None:
                    observations[owner].append(f"outside recorded body at {pos:#x}")
                    break
                i=one(pos)
                if not i or pos+i.size>hi:
                    observations[owner].append(f"decode limit {pos:#x}")
                    break
                instructions[pos]=i
                ptr=rip(i)
                if i.group(cs.CS_GRP_JUMP) or i.mnemonic=="call":
                    op=i.operands[0]
                    if op.type==x86.X86_OP_IMM:
                        t=op.imm
                        direct_edges.add((owner,pos,i.mnemonic,t))
                        if i.mnemonic in ("call","jmp"):
                            ext=import_thunk(t)
                            if ext:
                                allsites[owner,pos].append(("external",ext,f"via import thunk {t:#x}"))
                            if i.mnemonic=="call" and is_code(t) and t not in entries:
                                entries.add(t)
                                pending.append(t)
                        if i.group(cs.CS_GRP_JUMP) and any(a<=t<z for a,z in region):
                            blocks.append(t)
                        elif i.group(cs.CS_GRP_JUMP) and t not in entries:
                            observations[owner].append(f"cross-range target {pos:#x}->{t:#x}")
                    elif pos in dispatched:
                        for t in dispatched[pos]:
                            direct_edges.add((owner,pos,"switch",t))
                            if any(a<=t<z for a,z in region):blocks.append(t)
                        table=switches[pos][0]
                        allsites[owner,pos].append(("data",f"table {table:#x}","bounded DWORD RVA dispatch, see dispatch-tables.csv"))
                    elif ptr in slots:
                        allsites[owner,pos].append(("external",slots[ptr],f"IAT {ptr:#x}"))
                    else:
                        detail="recover incoming register or memory values"
                        if ptr is not None:
                            p=struct.unpack_from("<Q",im,ptr)[0]
                            if base<=p<base+len(im):
                                detail+=f"; initial pointer at {ptr:#x} -> {p-base:#x}"
                        allsites[owner,pos].append(("unresolved",i.op_str,detail))
                        observations[owner].append(f"indirect transfer {pos:#x}")
                if ptr is not None and not (i.mnemonic in {"call","jmp"} and ptr in slots):
                    sec=pe.get_section_by_rva(ptr)
                    section=sec.Name.rstrip(b"\0").decode() if sec else "image base/header"
                    allsites[owner,pos].append(("data",slots.get(ptr,f"RVA {ptr:#x}"),f"RIP-relative {section} reference {ptr:#x}"))
                if i.mnemonic in ("jmp","int3","ud2") or i.group(cs.CS_GRP_RET):break
                pos+=i.size
        insns[owner]=instructions
    verified = json.loads((ROOT/"reassembly.json").read_text(encoding="utf-8-sig"))
    matches={int(r["rva"],0):r for r in verified["matches"]}
    previous = ROOT/"reassembly.json"
    for path in (ROOT/"s5/reassembly-delta.json", ROOT/"s9/reassembly-delta.json"):
        delta = json.loads(path.read_text(encoding="utf-8"))
        assert delta["original_sha256"] == SHA
        assert delta["previous_sha256"] == hashlib.sha256(previous.read_bytes()).hexdigest()
        for row in delta["matches"]:
            entry = int(row["rva"], 0)
            if entry in matches:
                raise ValueError(f"Duplicate reassembled entry {entry:#x}")
            assert hashlib.sha256(im[entry:entry+row["bytes"]]).hexdigest() == row["sha256"]
            matches[entry] = row
        previous = path
    source={}
    for part in sorted((ROOT/"code").glob("verified-*.h")):
        lines=part.read_text().splitlines()
        for index,line in enumerate(lines):
            mark=re.fullmatch(r"/\* body (0x[0-9a-f]+) until (0x[0-9a-f]+) \*/",line)
            if mark:
                start,end=map(lambda x:int(x,0),mark.groups())
                assert matches[start]["bytes"]==end-start
                last=lines.index("}",index)+1
                source[start]=f"code/{part.name}#L{index+1}-L{last}"
    assert source.keys()==matches.keys()
    all_positions=sorted({p for owner,body in insns.items() for p in body
                          if p in entries or (owner,p) in allsites or owner==0x44a0})
    listing={}
    part=[]
    def flush(n):
        (ROOT/"code"/f"references-{n:02d}.asm").write_bytes(("\n".join(part)+"\n").encode())
    for index,pos in enumerate(all_positions):
        n=index//2500+1
        if index and index%2500==0:
            flush(n-1)
            part=[]
        i=one(pos)
        part.append(f"{pos:08x} {i.bytes.hex(' ')}  {i.mnemonic} {i.op_str}".rstrip())
        listing[pos]=f"code/references-{n:02d}.asm#L{len(part)}"
    flush(n)
    rows=[]
    native=[]
    for owner,b in sorted(insns.items()):
        root=primary(owner)
        model=owner if owner in source else root if root in source and owner in insns[root] else None
        if model is not None:
            tag="covered"
            note=(f"entire editable body reassembled at {model:#x}" if model==owner else
                  f"CHAININFO to reassembled owner {model:#x}, instruction starts at {owner:#x}")
            ref=source[model]
        else:
            tag="gap"
            ref=gh.get(owner,{}).get("source","")
            note=f"Compare editable body, ABI and data at {owner:#x}"
            if owner!=root:note+=f"; CHAININFO primary {root:#x}"
            if observations[owner]:note+="; "+", ".join(dict.fromkeys(observations[owner]))[:220]
            if not ref and root in gh:note+="; compare parent "+gh[root]["source"]
        rows.append(["native",hex(owner),tag,im[owner:owner+8].hex(),listing[owner],ref,note])
        native.append([hex(owner),exports.get(owner,gh.get(owner,{}).get("name",f"entry_{owner:x}")),
                       "+".join(n for n,y in [("PE",owner in anchors),("Ghidra",owner in gh)] if y) or "direct call",len(b)])
    write_table("native-functions.csv","rva name origin decoded_instructions",native)
    write_table("coverage.csv","kind key state first_bytes listing source note",rows)
    calls=[]
    # Preserve every proven owner association; a PE fragment may have a Ghidra parent.
    for (owner,pos),records in sorted(allsites.items()):
        for cat,callee,note in records:
            calls.append(["native",hex(owner),callee,cat,listing[pos],f"site {pos:#x}, {note}"])
    write_table("calls.csv","kind caller callee class listing note",calls)
    write_table("direct-transfers.csv","owner site operation target",[(hex(o),hex(p),m,hex(t)) for o,p,m,t in sorted(direct_edges)])
    write_table("imports.csv","slot import",[(hex(k),v) for k,v in sorted(slots.items())])
    identities=[]
    for typ in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for obj in typ.directory.entries:
            for lang in obj.directory.entries:
                d=lang.data.struct
                payload=pe.get_data(d.OffsetToData,d.Size)
                assert len(payload)==d.Size
                identities.append({"type":typ.id,"id":obj.id,"lang":lang.id,"rva":hex(d.OffsetToData),
                                   "size":d.Size,"sha256":hashlib.sha256(payload).hexdigest()})
    version=pe.VS_FIXEDFILEINFO[0]
    ver=[version.FileVersionMS>>16,version.FileVersionMS&65535,version.FileVersionLS>>16,version.FileVersionLS&65535]
    save_json("pe.json",{"original_sha256":SHA,"file_version":ver,"resources":identities,"exports":{hex(k):v for k,v in exports.items()},
                         "sections":[{"name":s.Name.decode().rstrip("\0"),"rva":hex(s.VirtualAddress),"virtual_size":s.Misc_VirtualSize,
                                      "raw_size":s.SizeOfRawData} for s in pe.sections]})
    save_json("run.json",dict(original_sha256=SHA,native_reported_count=len(entries),
              tool_version=f"Ghidra 12.2, Capstone {cs.__version__}, pefile {pefile.__version__}, Zig 0.13.0",
              command="Ghidra ExportIkc.java and ExportIkcFlow.java; python reassemble.py ORIGINAL ZIG; python recover.py ORIGINAL",
              scope="Union of original PE entries and recorded Ghidra functions, direct call expansion, call/reference and CHAININFO relation, byte comparison of certified editable source after applying COFF relocations.",
              limitations="Outstanding items require independent resolution of source coverage, transfers and data relationships. Reachable-instruction traversal follows two byte-verified switch tables. Overlapping ownership can produce multiple rows for one site. Static evidence only.",
              original_anchors=len(anchors),ghidra=len(gh),decompiled=sum(bool(r["source"]) for r in gh.values()),
              single_assembly_bodies=len(source),covered_rows=sum(r[2]=="covered" for r in rows),
              declared_gaps=sum(r[2]=="gap" for r in rows),indexed_sites=len(cases),
              unresolved_sites=len({pos for (_,pos),rs in allsites.items() if any(r[0]=="unresolved" for r in rs)}),
              reference_rows=len(calls),distinct_references=len({(p,c,t) for (_,p),rs in allsites.items() for c,t,_ in rs}),
              classes={cls:sum(c[3]==cls for c in calls) for cls in ("external","data","unresolved")}))


if __name__=="__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    recover(parser.parse_args().original.read_bytes())
