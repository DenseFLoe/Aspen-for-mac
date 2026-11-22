"""Map every prior coverage key and every new Ghidra function onto the actual indexed body."""
import argparse
from collections import Counter
import csv
import hashlib
import json
from pathlib import Path
import re
import struct

def run(original,prior,d):
    raw=original.read_bytes()
    digest=hashlib.sha256(raw).hexdigest()
    assert digest=='ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b'
    assert hashlib.sha256(prior.read_bytes()).hexdigest()=='04e4256a144586eca0cc4a51d12a166223538cbba2194c0867a93bb76f69b255'
    assert (d/'ghidra/version.txt').read_text().splitlines()==['12.2',digest]
    p=struct.unpack_from('<I',raw,60)[0]
    sections=struct.unpack_from('<H',raw,p+6)[0]
    sec=p+24+struct.unpack_from('<H',raw,p+20)[0]
    spans=[struct.unpack_from('<III',raw,sec+40*n+12) for n in range(sections)]
    def off(r): return next(at+r-b for b,n,at in spans if b<=r<b+n)
    with prior.open(encoding='utf-8',newline='') as f:
        old={int(x['key'],16):x for x in csv.DictReader(f)}
    gh={}
    chunks={}
    ranges=[]
    with (d/'ghidra/functions.tsv').open(encoding='utf-8',newline='') as f:
        for row in csv.DictReader(f,delimiter='\t'):
            key=int(row['rva'],16)
            assert key not in gh
            gh[key]=row
            spans_gh=[tuple(int(x,16) for x in s.split('-')) for s in row['ranges_inclusive'].split()]
            assert any(lo<=key<=hi for lo,hi in spans_gh)
            assert sum(hi-lo+1 for lo,hi in spans_gh)==int(row['bytes'])
            for lo,hi in spans_gh:
                assert 0<=off(lo)<=off(hi)<len(raw)
                ranges.append((lo,hi,key))
            if not row['listing']:
                assert row['state']=='missing'
                continue
            m=re.fullmatch(r's5/(ghidra/part-[0-9]+\.c)#L(\d+)-L(\d+)',row['listing'])
            assert m
            fname,lo,hi=m.groups()
            if fname not in chunks: chunks[fname]=(d/fname).read_text(encoding='utf-8').splitlines()
            assert 1<=int(lo)<=int(hi)<=len(chunks[fname])
            assert chunks[fname][int(lo)-1]==f'/* RVA {key:#x} */'
    rows=[]
    state=Counter()
    old_gap_mapping=Counter()
    for key in sorted(old.keys()|gh.keys()):
        raw8=raw[off(key):off(key)+8].hex()
        previous=old.get(key,{}).get('state','new')
        if key in old: assert old[key]['first_bytes']==raw8
        owners={o for lo,hi,o in ranges if lo<=key<=hi}
        assert len(owners)<=1
        owner=next(iter(owners),None)
        mapping='entry' if key in gh else 'inside-body' if owner is not None else 'unmapped'
        g=gh.get(owner,{})
        state[mapping]+=1
        if previous=='gap': old_gap_mapping[mapping]+=1
        rows.append((hex(key),raw8,previous,mapping,hex(owner) if owner is not None else '',g.get('state',''),g.get('listing','')))
    with (d/'address-map.csv').open('w',encoding='utf-8',newline='') as f:
        writer=csv.writer(f,lineterminator='\n')
        writer.writerow(['rva','first_bytes','prior_state','mapping','ghidra_owner','decompiler_state','code'])
        writer.writerows(rows)
    result=dict(original_sha256=digest,prior_count=len(old),prior_gaps=sum(r['state']=='gap' for r in old.values()),
                prior_covered=sum(r['state']=='covered' for r in old.values()),ghidra_entries=len(gh),
                ghidra_new=len(gh.keys()-old.keys()),union=len(rows),mapping=dict(state),
                old_gaps_by_mapping=dict(old_gap_mapping),decompiler_states=dict(Counter(r['state'] for r in gh.values())),
                source_parts=len(chunks))
    assert result['prior_gaps']==801 and result['prior_covered']==12
    return result

if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    for arg in ('original','prior','folder'): parser.add_argument(arg,type=Path)
    args=parser.parse_args()
    print(json.dumps(run(args.original,args.prior,args.folder),indent=2))
