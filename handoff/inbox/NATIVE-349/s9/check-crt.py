"""Compare archived source, call and control evidence for two CRT lifecycle hosts."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile

import capstone as cs
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_REG_RIP
import pefile

HERE=Path(__file__).resolve().parent
UNIT=HERE.parent
sys.path.insert(0,str(UNIT))
import reassemble


def rows(path):
    with path.open(encoding='utf-8-sig',newline='') as f:
        return list(csv.DictReader(f))


def compare_storage(obj,image):
    arch,sections,_,symbols,nsyms,opt,_=struct.unpack_from('<HHIIIHH',obj)
    assert arch==0x8664 and opt==0
    headers=[struct.unpack_from('<8sIIIIIIHHI',obj,20+40*i) for i in range(sections)]
    widths={0x34900:4,0x34930:4,0x34941:1,0x34948:24,0x34960:24,0x29e90:16}
    idx=0; result={}
    while idx<nsyms:
        offset=symbols+18*idx
        name=obj[offset:offset+8]
        if not any(name[:4]):
            p=symbols+18*nsyms+int.from_bytes(name[4:],'little')
            name=obj[p:obj.index(b'\0',p)]
        rank,sec,_,_,aux=struct.unpack_from('<IhHBB',obj,offset+8)
        idx+=aux+1
        if sec<=0 or not name.startswith(b'rva_'):
            continue
        addr=int(name.rstrip(b'\0')[4:],16)
        width=widths[addr]
        section,_,_,size,raw,_,_,nrel,_,_=headers[sec-1]
        assert rank+width<=size and not nrel
        content=bytes(width) if not raw else obj[raw+rank:raw+rank+width]
        assert content==image[addr:addr+width]
        result[hex(addr)]=dict(size=width,coff_section=section.rstrip(b'\0').decode(),initial_bytes=content.hex())
    assert len(result)==len(widths)
    return result


def check(original,compiler):
    raw=original.read_bytes()
    digest=hashlib.sha256(raw).hexdigest()
    assert digest==reassemble.ORIGINAL
    assert subprocess.check_output([str(compiler.resolve()),'version'],text=True).strip()=='0.13.0'
    pe=pefile.PE(data=raw);image=pe.get_memory_mapped_image()
    md=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64);md.detail=True
    pdata={e.struct.BeginAddress:e.struct for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    all_bodies=json.loads(subprocess.check_output([sys.executable,'-B',UNIT/'reassemble.py',original,compiler]))
    earlier=[]
    for path in [UNIT/'reassembly.json',UNIT/'s5/reassembly-delta.json']:
        earlier+=json.loads(path.read_text(encoding='utf-8-sig'))['matches']
    added=json.loads((HERE/'reassembly-delta.json').read_text())['matches']
    assert all_bodies['matches']==sorted(earlier+added,key=lambda r:int(r['rva'],0))
    assert (len(earlier),sum(r['bytes'] for r in earlier),sum(len(r['relocations']) for r in earlier))==(185,145008,5322)
    assert (all_bodies['bodies'],all_bodies['bytes'],all_bodies['relocations'])==(187,145279,5347)

    previous_children={}
    for start in (0x2ee0,0x22da0):
        subset=[r for r in rows(UNIT/'s5/host-flow.csv') if int(r['owner'],0)==start]
        for r in subset:
            a=int(r['instruction'],0)
            ins=next(md.disasm(image[a:a+15],a,count=1))
            assert r['bytes']==ins.bytes.hex()
            if r['entry_kind']=='CHAININFO':
                info=pdata[a].UnwindData
                assert image[info]>>3&4
                tail=info+4+4*((image[info+2]+1)//2)
                assert struct.unpack_from('<III',image,tail)==(start,pdata[start].EndAddress,pdata[start].UnwindData)
                previous_children[hex(a)]=hex(start)
    assert len(previous_children)==4

    current={r['key']:r for r in rows(UNIT/'coverage.csv')}
    previous_gaps=[r['entry'] for r in rows(UNIT/'s5/prior-gaps.csv') if r['current_state']=='gap']
    assert len(previous_gaps)==17
    gap_status={k:dict(state=current[k]['state'],source=current[k]['source'],listing=current[k]['listing'],
                       note=current[k]['note']) for k in previous_gaps}
    assert {k for k,v in gap_status.items() if v['state']=='covered'}=={'0x244c4','0x24ab0'}
    assert sum(r['state']=='gap' for r in current.values())==15
    calls=rows(UNIT/'calls.csv')
    assert hashlib.sha256((UNIT/'calls.csv').read_bytes()).hexdigest()=='e338ffd0ab438b802af8564f4081497226688874e28e05cdd2bcebace383dcfe'
    carried=rows(UNIT/'s5/prior-indirect.csv')
    key=lambda r:(r['caller'],r['listing'],r['callee'])
    assert {key(r) for r in calls if r['class']=='unresolved'}=={(r['owner'],r['listing'],r['operand']) for r in carried}
    assert len(carried)==15 and len(calls)==3947
    flow={}
    transfer_table=rows(UNIT/'direct-transfers.csv')
    for start,stop in ((0x244c4,0x24548),(0x24ab0,0x24b3b)):
        assert pdata[start].EndAddress==stop
        body=list(md.disasm(image[start:stop],start))
        assert body[-1].address+body[-1].size==stop
        instructions={i.address for i in body}
        records=[];edges=set();links={}
        for i in body:
            target=None;successors=[];rip=None
            if i.group(cs.CS_GRP_JUMP) or i.group(cs.CS_GRP_CALL):
                assert i.operands[0].type==X86_OP_IMM
                target=i.operands[0].imm
                edges.add((hex(i.address),i.mnemonic,hex(target)))
                if i.group(cs.CS_GRP_JUMP):
                    assert target in instructions
                    successors.append(target)
            if not i.group(cs.CS_GRP_RET) and i.mnemonic not in ('jmp','int3'):
                successors.append(i.address+i.size)
            for op in i.operands:
                if op.type==X86_OP_MEM and op.mem.base==X86_REG_RIP:
                    rip=i.address+i.size+op.mem.disp
            assert all(s in instructions for s in successors)
            links[i.address]=successors
            records.append(dict(at=hex(i.address),bytes=i.bytes.hex(),insn=(i.mnemonic+' '+i.op_str).strip(),
                                target=hex(target) if target is not None else None,
                                rip=hex(rip) if rip is not None else None,
                                successors_if_calls_return=list(map(hex,successors))))
        assert edges=={(r['site'],r['operation'],r['target']) for r in transfer_table if r['owner']==hex(start)}
        seen=set();pending=[start]
        while pending:
            a=pending.pop()
            if a not in seen:
                seen.add(a);pending.extend(links[a])
        assert seen==instructions
        assert body[-1].mnemonic=='int3'
        flow[hex(start)]=records
    assert image[0x24545:0x24548].hex()=='9090cc' and image[0x24b3a]==0xcc
    slot=0x26150
    imports={s.address-pe.OPTIONAL_HEADER.ImageBase:m.dll.decode()+'!'+s.name.decode()
             for m in pe.DIRECTORY_ENTRY_IMPORT for s in m.imports if s.name}
    assert imports[slot]=='api-ms-win-crt-runtime-l1-1-0.dll!_initialize_onexit_table'
    thunk=next(md.disasm(image[0x2548c:0x25492],0x2548c))
    assert thunk.mnemonic=='jmp' and thunk.address+thunk.size+thunk.operands[0].mem.disp==slot
    for a,table in ((0x24ad3,0x34948),(0x24ae3,0x34960)):
        lea,call=next(i for i in flow['0x24ab0'] if i['at']==hex(a)),next(i for i in flow['0x24ab0'] if i['at']==hex(a+7))
        assert lea['rip']==hex(table) and lea['insn'].startswith('lea rcx, ') and call['target']=='0x2548c'
    with tempfile.TemporaryDirectory() as tmp:
        obj=Path(tmp)/'storage.obj';reassemble.compile_bodies(HERE/'crt-data.c',compiler,obj)
        storage=compare_storage(obj.read_bytes(),image)
    return dict(original_sha256=digest,compiler='Zig 0.13.0',capstone=cs.__version__,pefile=pefile.__version__,
                previous_verified=[185,145008,5322],added_verified=[2,271,25],previous_chaininfo=previous_children,
                hosts=flow,original_data=storage,exit_table_import=[hex(slot),imports[slot]],prior_gap_disposition=gap_status,
                unchanged_indirect_sites=[{'owner':r['owner'],'site':r['site'],'listing':r['listing'],'state':r['status']} for r in carried])


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('original',type=Path);p.add_argument('compiler',type=Path);p.add_argument('--output',type=Path)
    args=p.parse_args();result=json.dumps(check(args.original,args.compiler),indent=2)+'\n'
    if args.output:
        args.output.write_bytes(result.encode())
    else:
        print(result,end='')
