"""Generate fifth-round coverage and references from the pinned PE, function ranges and compared code."""
import argparse
from collections import Counter, defaultdict
import csv
import hashlib
import json
from pathlib import Path
import re
import capstone as cp
from capstone import x86
import pefile

ORIGINAL="ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"

def table(path, delim=","):
    with path.open(encoding="utf-8-sig",newline="") as f:
        return list(csv.DictReader(f,delimiter=delim))

def save(path, header, rows):
    with path.open("w",encoding="utf-8",newline="") as f:
        w=csv.writer(f,lineterminator="\n")
        w.writerow(header);w.writerows(rows)

def generate(dll, folder):
    data=dll.read_bytes()
    assert hashlib.sha256(data).hexdigest()==ORIGINAL
    s5=folder/"s5"
    pe=pefile.PE(data=data)
    img=pe.get_memory_mapped_image()
    md=cp.Cs(cp.CS_ARCH_X86,cp.CS_MODE_64);md.detail=True
    slots={i.address-pe.OPTIONAL_HEADER.ImageBase:
           d.dll.decode()+"!"+(i.name.decode() if i.name else f"#{i.ordinal}")
           for d in [*pe.DIRECTORY_ENTRY_IMPORT,*getattr(pe,"DIRECTORY_ENTRY_DELAY_IMPORT",[])] for i in d.imports}
    def section(rva):
        s=pe.get_section_by_rva(rva)
        return s.Name.rstrip(b"\0").decode() if s else "image headers"
    def slot(ins):
        if len(ins.operands)==1:
            o=ins.operands[0]
            if o.type==x86.X86_OP_MEM and o.mem.base==x86.X86_REG_RIP:
                return ins.address+ins.size+o.mem.disp
    functions={int(r["rva"],16):r for r in table(s5/"ghidra/functions.tsv","\t")}
    mapping={int(r["rva"],16):r for r in table(s5/"address-map.csv")}
    matches={int(r["rva"],16):r for r in json.loads((s5/"reassembly.json").read_text())["matches"]}
    switches={int(t["site"],16):t for t in json.loads((s5/"switch-review.json").read_text())["tables"]}
    hosts={int(t["owner"],16) for t in switches.values()}
    body={}
    raw_source=(s5/"code/verified.c").read_text().splitlines()
    for line_no,line in enumerate(raw_source,1):
        if line.startswith("/* body "):
            k=int(line.split()[2],16)
            assert k not in body
            first=line_no
        if line=="}":
            body[k]=(first,line_no)
    assert body.keys()==matches.keys()
    bounds={e.struct.BeginAddress:e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    owners={}
    instructions={}
    stops=[]
    for k,row in functions.items():
        for item in row["ranges_inclusive"].split():
            a,end=(int(n,16) for n in item.split("-"));end+=1
            pos=a
            for ins in md.disasm(img[a:end],a):
                p=ins.address
                assert p not in owners
                instructions[p]=ins;owners[p]=k
                pos=p+ins.size
            if pos!=end:stops.append((hex(k),hex(pos),hex(end)))
    def thunk(rva):
        seen=set()
        while rva not in seen and rva in instructions:
            seen.add(rva)
            i=instructions[rva]
            if i.mnemonic!="jmp":return
            if slot(i) in slots:return slot(i)
            if i.operands[0].type!=x86.X86_OP_IMM:return
            rva=i.operands[0].imm
    listing=[];references=[];transfers=[];hostrefs=[];counts=Counter();site_refs={}
    def loc(i):
        p=i.address
        if p not in site_refs:
            listing.append(f"0x{p:x}  {i.bytes.hex()}  {i.mnemonic} {i.op_str}".rstrip())
            site_refs[p]=f"s5/code/references.asm#L{len(listing)}"
        return site_refs[p]
    gaps=defaultdict(list)
    for k in mapping:
        i=next(md.disasm(img[k:k+15],k,count=1))
        assert img[k:k+8].hex()==mapping[k]["first_bytes"]
        loc(i)
    for p,i in sorted(instructions.items()):
        k=owners[p]
        def ref(target,cat,note):
            item=("native",hex(k),target,cat,loc(i),f"{p:#x}: {note}")
            references.append(item)
            counts[cat]+=1
            if k in hosts:hostrefs.append((hex(k),hex(p),cat,target,note))
        iscall=i.mnemonic=="call"
        isjump=i.group(cp.CS_GRP_JUMP)
        if iscall or isjump:
            o=i.operands[0]
            if o.type==x86.X86_OP_IMM:
                target=o.imm
                if iscall or (isjump and not (target in owners and owners[target]==k)):
                    sl=thunk(target)
                    if sl is not None:
                        ref(slots[sl],"external",f"direct transfer to {target:#x}, jump chain ends at IAT {sl:#x}")
                    else:
                        transfers.append((hex(k),hex(p),i.mnemonic,hex(target),hex(owners[target]) if target in owners else ""))
                        if k in hosts:hostrefs.append((hex(k),hex(p),"internal",hex(target),"direct target"))
            elif p in switches:
                for target in sorted({int(v,16) for v in switches[p]["index_to_target_rvas"]}):
                    transfers.append((hex(k),hex(p),"switch",hex(target),hex(owners[target]) if target in owners else ""))
            elif slot(i) in slots:
                sl=slot(i)
                ref(slots[sl],"external",f"instruction references PE import slot {sl:#x}")
            else:
                ref(i.op_str,"unresolved","indirect transfer requires receiver or runtime pointer identity")
                gaps[k].append(hex(p))
        for o in i.operands:
            if o.type!=x86.X86_OP_MEM or o.mem.base!=x86.X86_REG_RIP:continue
            target=p+i.size+o.mem.disp
            if (iscall or isjump) and target in slots:continue
            ref(f"RVA {target:#x}","data",f"RIP-relative operand into {section(target)}")
    assert len({(r[1],r[2],r[4]) for r in references})==len(references)
    coverage=[];cert=Counter()
    for k,r in mapping.items():
        owner=int(r["ghidra_owner"],16)
        code="";status="gap"
        note=f"Bind referenced calls/data and compare editable body {r['code']} at owner {owner:#x}."
        if k in matches:
            status="covered"
            a,b=body[k]
            code=f"s5/code/verified.c#L{a}-L{b}"
            m=matches[k]
            note=f"COFF relocation and byte comparison confirmed {m['bytes']} bytes at own original RVA."
            cert["reassembled"]+=1
        elif r["mapping"]=="inside-body":
            if owner in matches and k in instructions and owners[k]==owner and k in bounds and bounds[k]<=owner+matches[owner]["bytes"]:
                status="covered"
                a,b=body[owner];code=f"s5/code/verified.c#L{a}-L{b}"
                note=f"Runtime entry {k:#x}..{bounds[k]:#x} lies entirely in byte-compared body {owner:#x}; starts at an instruction boundary."
                cert["contained_runtime"]+=1
            else:
                note=f"Interior key {k:#x} maps to {owner:#x}, listing {r['code']}; establish fragment entry/extent and separate ABI using unwind records and callers."
        elif r["prior_state"]=="covered":
            # All earlier verified leaf functions must also receive an independent COFF match.
            raise ValueError(f"Prior leaf {k:#x} did not receive a new match")
        if k in gaps:
            note+=" Indirect sites "+", ".join(gaps[k])+"."
        coverage.append(("native",hex(k),status,r["first_bytes"],site_refs[k],code,note))
    (s5/"code/references.asm").write_bytes(("\n".join(listing)+"\n").encode())
    save(folder/"native-functions.csv",["rva","name"],[(hex(k),functions[k]["name"] if k in functions else f"fragment_{k:x}") for k in mapping])
    save(folder/"coverage.csv",["kind","key","state","first_bytes","listing","source","note"],coverage)
    save(folder/"calls.csv",["kind","caller","callee","class","listing","note"],references)
    save(s5/"direct-transfers.csv",["owner","site","instruction","target","target_owner"],transfers)
    save(s5/"five-host-references.csv",["owner","site","kind","target","basis"],hostrefs)
    summary={"original_sha256":ORIGINAL,"tool_version":f"Ghidra 12.2; Capstone {cp.__version__}; pefile {pefile.__version__}; Zig 0.13.0 cc",
             "command":"python -B handoff/inbox/NATIVE-342/s5/refresh.py <ApwnIPShell.dll> <handoff/inbox/NATIVE-342>",
             "scope":"Union of original/prior 813 entries and 898 Ghidra entries. Decode declared Ghidra ranges, check five PE switch hosts, direct import thunks/callers and all RIP-relative operands in decoded ranges. Reassemble proven bodies at original RVAs.",
             "limitations":"Unverified source bodies, interior entries, indirect receiver identities, non RIP-relative data and resource/layout coverage remain open. No Windows runtime execution.",
             "native_reported_count":len(mapping),"pe_exception_entries":len(bounds),"ghidra_entries":len(functions),"unique_decoded_instructions":len(instructions),
             "decoder_stops":stops,"covered":sum(r[2]=="covered" for r in coverage),"gap":sum(r[2]=="gap" for r in coverage),"certification":dict(cert),
             "old_gaps_now_covered":sum(r[2]=="covered" and mapping[int(r[1],0)]["prior_state"]=="gap" for r in coverage),
             "new_entries_now_covered":sum(r[2]=="covered" and mapping[int(r[1],0)]["prior_state"]=="new" for r in coverage),
             "calls":dict(counts),"direct_transfers":len(transfers),"five_hosts":{hex(k):dict(Counter(r[2] for r in hostrefs if int(r[0],16)==k)) for k in sorted(hosts)}}
    (folder/"run.json").write_bytes((json.dumps(summary,indent=2)+"\n").encode())
    print(json.dumps(summary,indent=2))

if __name__=="__main__":
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("original",type=Path);p.add_argument("folder",type=Path)
    a=p.parse_args();generate(a.original,a.folder)
