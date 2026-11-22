"""Cross-check indexed reference operands with iced-x86 and original PE import tables."""
import argparse
import csv
import hashlib
import json
import re
from pathlib import Path
import struct
from collections import Counter
from iced_x86 import Decoder, FlowControl, OpKind

SHA = "9b762caf68ad02f296eb3d98d9995af91adbd572f7c00acb88f4afc5fe88d601"

def verify(original, folder):
    data = original.read_bytes()
    assert hashlib.sha256(data).hexdigest() == SHA
    u16 = lambda p: struct.unpack_from('<H',data,p)[0]
    u32 = lambda p: struct.unpack_from('<I',data,p)[0]
    u64 = lambda p: struct.unpack_from('<Q',data,p)[0]
    pe = u32(0x3c)
    assert data[pe:pe+4] == b'PE\0\0' and u16(pe+4) == 0x8664
    opt = pe+24
    base = u64(opt+24)
    secs = []
    for n in range(u16(pe+6)):
        p = opt+u16(pe+20)+40*n
        secs.append((u32(p+12),u32(p+16),u32(p+20)))
    def off(r):
        return next(p+r-b for b,size,p in secs if b <= r < b+size)
    def string(r):
        p=off(r)
        return data[p:data.index(0,p)].decode('ascii')
    imports = {}
    for directory in [1,13]:
        table, size=struct.unpack_from('<II',data,opt+112+8*directory)
        if not table: continue
        width = 20 if directory==1 else 32
        for desc in range(off(table),off(table)+size-width+1,width):
            words = struct.unpack_from('<'+'I'*(width//4),data,desc)
            if not any(words): break
            if directory==1:
                names,_,_,dll,iat=words
                names=names or iat
            else:
                attr,dll,_,iat,names,*_=words
                assert attr&1
            index=0
            while (name:=u64(off(names+8*index))):
                symbol=f'#{name & 0xffff}' if name>>63 else string(name+2)
                imports[iat+8*index]=string(dll)+'!'+symbol
                index+=1
    def ins(r):
        p=off(r)
        return Decoder(64,data[p:p+15],ip=base+r).decode()
    direct={OpKind.NEAR_BRANCH16,OpKind.NEAR_BRANCH32,OpKind.NEAR_BRANCH64}
    totals=Counter()
    unique=set()
    with (folder/'references.csv').open(encoding='utf-8',newline='') as f:
        for row in csv.DictReader(f):
            kind,target=row['kind'],row['target']
            for pair in row['owner_rva:instruction_rva_hex'].split():
                owner,rva=(int(x,16) for x in pair.split(':'))
                x=ins(rva)
                if kind=='thunk':
                    assert x.op0_kind in direct
                    thunk=ins(x.near_branch_target-base)
                    assert thunk.flow_control==FlowControl.INDIRECT_BRANCH and thunk.is_ip_rel_memory_operand
                    assert imports[thunk.ip_rel_memory_address-base]==target,(hex(rva),imports[thunk.ip_rel_memory_address-base],target)
                elif kind=='iat':
                    assert x.is_ip_rel_memory_operand and x.flow_control in (FlowControl.INDIRECT_BRANCH,FlowControl.INDIRECT_CALL)
                    assert imports[x.ip_rel_memory_address-base]==target,(hex(rva),imports[x.ip_rel_memory_address-base],target)
                elif kind=='call' or kind=='range-branch':
                    assert x.op0_kind in direct and x.near_branch_target-base==int(target,16)
                    if kind=='call': assert x.flow_control==FlowControl.CALL
                elif kind=='data':
                    assert x.is_ip_rel_memory_operand and imports.get(x.ip_rel_memory_address-base,hex(x.ip_rel_memory_address-base))==target
                elif kind=='indirect':
                    assert x.flow_control in (FlowControl.INDIRECT_BRANCH,FlowControl.INDIRECT_CALL)
                elif kind=='switch':
                    assert rva==0x22a8d and x.flow_control==FlowControl.INDIRECT_BRANCH and int(target,16)==0x22b4c
                else: raise ValueError(kind)
                totals[kind]+=1
                unique.add((kind,rva))
    assert dict(totals) == json.loads((folder/'run.json').read_text(encoding='utf-8'))['references']
    report = dict(indexed=sum(totals.values()),unique_kind_and_site=len(unique),by_kind=dict(sorted(totals.items())))
    gh_index=folder/'ghidra/functions.tsv'
    if gh_index.is_file():
        marks=Counter()
        parts={}
        named={}
        with gh_index.open(encoding='utf-8',newline='') as f:
            rows=list(csv.DictReader(f,delimiter='\t'))
        for row in rows:
            start=int(row['rva'],16)
            spans=[tuple(int(x,16) for x in v.split('-')) for v in row['ranges_inclusive'].split()]
            assert sum(hi-lo+1 for lo,hi in spans)==int(row['bytes'])
            assert any(lo<=start<=hi for lo,hi in spans)
            for lo,hi in spans:
                assert 0<=off(lo)<=off(hi)<len(data)
            loc=row['listing']
            if not loc:
                assert row['state']=='missing'
                continue
            m=re.fullmatch(r'(ghidra/part-[0-9]+\.c)#L(\d+)-L(\d+)',loc)
            assert m
            name,lo,hi=m.groups()
            if name not in parts: parts[name]=(folder/name).read_text(encoding='utf-8').splitlines()
            lines=parts[name]
            assert 1<=int(lo)<=int(hi)<=len(lines)
            assert lines[int(lo)-1]==f'/* RVA {hex(start)} */'
            body='\n'.join(lines[int(lo):int(hi)])
            for token in ('WARNING','halt_baddata','unaff_','in_stack_','Could not recover jumptable'):
                if token in body: marks[token]+=1
            if start in (0x39c00,0x109c0,0x22a50): named[hex(start)]=loc
        assert set(named)=={'0x39c00','0x109c0','0x22a50'}
        report['ghidra']=dict(functions=len(rows),source_parts=len(parts),markers=dict(marks),focus=named)
    return report

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original',type=Path)
    parser.add_argument('folder',type=Path)
    args=parser.parse_args()
    print(json.dumps(verify(args.original,args.folder)))
