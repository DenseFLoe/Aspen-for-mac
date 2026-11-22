"""Independently check dispatch bytes, table values and reachable switch targets."""
import argparse
import csv
import hashlib
import json
import struct
from pathlib import Path
from iced_x86 import Decoder, FlowControl, Mnemonic

ORIGINAL='ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b'
TABLES='d09896f9e748b357a6ec14f378de7f3667b3dfb839322f6d75cc6ecf066e1b2c'

def verify(original,recovery,ghidra_folder=None):
    data=original.read_bytes()
    assert hashlib.sha256(data).hexdigest()==ORIGINAL
    report=recovery.read_bytes()
    assert hashlib.sha256(report).hexdigest()==TABLES
    tables=json.loads(report)['tables']
    p=struct.unpack_from('<I',data,0x3c)[0]
    assert data[p:p+4]==b'PE\0\0'
    num=struct.unpack_from('<H',data,p+6)[0]
    opt=p+24
    n=opt+struct.unpack_from('<H',data,p+20)[0]
    base=struct.unpack_from('<Q',data,opt+24)[0]
    sections=[struct.unpack_from('<III',data,n+i*40+12) for i in range(num)]
    def offset(rva):
        return next(start+rva-r for r,length,start in sections if r<=rva<r+length)
    def raw(rva,size):
        start=offset(rva)
        return data[start:start+size]
    def ins(rva):
        return Decoder(64,raw(rva,15),ip=base+rva).decode()
    switches={}
    if ghidra_folder:
        with (ghidra_folder/'switches.tsv').open(encoding='utf-8',newline='') as f:
            switches={int(r['site'],16):r for r in csv.DictReader(f,delimiter='\t')}
    results=[]
    known={}
    masked=[]
    for t in tables:
        signed=[(int(row.split()[0],16),bytes.fromhex(row.split()[1])) for row in t['dispatch']]
        seq=[ins(r) for r,b in signed]
        assert all(raw(r,len(b))==b and i.len==len(b) for (r,b),i in zip(signed,seq))
        assert all(a.next_ip==b.ip for a,b in zip(seq,seq[1:]))
        assert seq[0].mnemonic==Mnemonic.CMP and seq[0].immediate(1)+1==t['input_count']
        assert seq[1].mnemonic==Mnemonic.JA and seq[1].near_branch_target-base==int(t['default'],16)
        assert seq[-1].flow_control==FlowControl.INDIRECT_BRANCH
        lo,hi=int(t['function_rva'],16),int(t['runtime_end'],16)
        assert hashlib.sha256(raw(lo,hi-lo)).hexdigest()==t['range_sha256']
        tab=int(t['rva_table'],16)
        targets=list(struct.unpack('<'+'I'*len(t['target_rvas']),raw(tab,4*len(t['target_rvas']))))
        assert targets==[int(x,16) for x in t['target_rvas']]
        end=tab+4*len(targets)
        masked.append((tab,end))
        if t['selector_table']:
            tab2=int(t['selector_table'],16)
            selectors=raw(tab2,t['input_count'])
            assert selectors.hex()==t['selector_bytes'] and max(selectors)<len(targets)
            masked.append((tab2,tab2+len(selectors)))
            first=[targets[x] for x in selectors]
        else:
            first=targets
        assert len(first)==t['input_count']
        assert all(lo<=x<hi for x in targets)
        site=signed[-1][0]
        known[site]=set(first)
        result={'site':hex(site),'owner':hex(lo),'end':hex(hi),'default':t['default'],
                'input_count':len(first),'distinct_computed_destinations':len(set(first)),
                'index_to_target_rvas':[hex(k) for k in first]}
        if switches:
            g=switches[site]
            gh={int(x,16) for x in g['flows'].split()}
            result.update(ghidra_owner=g['owner'],ghidra_instruction=g['instruction'],
                          ghidra_flow_count=len(gh),ghidra_table_type=g['table_type'],
                          ghidra_selector_type=g['selector_type'],
                          missing_ghidra_flows=sorted(hex(x) for x in set(first)-gh),
                          extra_ghidra_flows=sorted(hex(x) for x in gh-set(first)))
        results.append(result)
    roots={}
    indirect={FlowControl.INDIRECT_BRANCH}
    terminal={FlowControl.RETURN,FlowControl.EXCEPTION,FlowControl.INTERRUPT}
    for t in tables:
        lo,hi=int(t['function_rva'],16),int(t['runtime_end'],16)
        if hex(lo) in roots: continue
        seen=set()
        reached=set()
        unknown=set()
        exits=set()
        queue=[lo]
        while queue:
            rva=queue.pop()
            if rva in seen: continue
            if not lo<=rva<hi:
                exits.add(rva)
                continue
            assert not any(a<=rva<b for a,b in masked)
            i=ins(rva)
            assert not i.is_invalid and i.len>0
            assert not any(rva<b and rva+i.len>a for a,b in masked)
            seen.add(rva)
            if rva in known:
                reached.add(rva)
                queue.extend(known[rva])
            elif i.flow_control==FlowControl.CONDITIONAL_BRANCH:
                queue.extend([i.next_ip-base,i.near_branch_target-base])
            elif i.flow_control==FlowControl.UNCONDITIONAL_BRANCH: queue.append(i.near_branch_target-base)
            elif i.flow_control in indirect: unknown.add(rva)
            elif i.flow_control not in terminal: queue.append(i.next_ip-base)
        stop=int(t['s1_linear_stop'],16)
        assert any(a<=stop<b for a,b in masked)
        expected={int(v['site'],16) for v in results if int(v['owner'],16)==lo}
        assert reached==expected
        roots[hex(lo)]=dict(reachable_instructions=len(seen),
                            resolved_dispatches=sorted(hex(v) for v in reached),
                            other_indirect_jumps=sorted(hex(v) for v in unknown),
                            transfers_outside_runtime_range=sorted(hex(v) for v in exits),
                            all_reachable_instructions_disjoint_from_known_tables=True)
    return dict(original_sha256=ORIGINAL,recovery_sha256=TABLES,tables=results,functions=roots)

if __name__=='__main__':
    arg=argparse.ArgumentParser(description=__doc__)
    arg.add_argument('original',type=Path)
    arg.add_argument('recovery',type=Path)
    arg.add_argument('--ghidra-folder',type=Path)
    opts=arg.parse_args()
    print(json.dumps(verify(opts.original,opts.recovery,opts.ghidra_folder),indent=2))
