"""Audit length-indexed ppexec dispatch from each of the six ordinary routine entries.

Usage: python -B check-selector-bounds.py ORIGINAL S5_DIRECTORY > selector-bounds.json
Dependencies: pefile and Capstone 5. Reads the fifth-round table inventory, then
checks every slot and the address calculation at each transfer against the PE.
The fixed-point analysis covers ordinary copy/fill lengths, 0..INT64_MAX.
Bounds are conservative inclusions. Some sites require a caller size declaration.
"""
import argparse
import csv
import hashlib
import json
import struct
from collections import deque
from pathlib import Path

import capstone as cs
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile

DIGEST = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
SIGN = 1 << 63
MOD = 1 << 64
MAX = MOD - 1
ALL = ((0, SIGN - 1), (SIGN, MAX))
END = {0x8ea0: 0xa6a9, 0xa6c0: 0xc1c2, 0xe040: 0xf0f8, 0xf100: 0x109c1,
       0x12c70: 0x13d1a, 0x13d20: 0x14704}
# Non-R8 alignment selectors from fifth-round register proofs. At the two
# quotient selectors the input to the straight-line sequence is retained until
# the jump; (n >> 4) selects the slot and (n & 15) reaches the target.
ALIGN = {0x8efa: (1,31), 0x921d: (0,31), 0xa711: (1,63), 0xaac1: (0,63),
         0xe0a4: (1,31), 0xf15b: (1,63), 0x12cd5: (0,7), 0x135a0: (0,15),
         0x13d91: (1,7), 0x1403f: (0,15)}
SUB_ALIGN = {0x8ee7: (1,31), 0xa6fe: (1,63), 0xe097: (1,31), 0xf14e: (1,63),
             0x13d8e: (1,7), 0x1403c: (0,15)}
QUOTIENT = {0x135c3: 0x135ab, 0x13af3: 0x13ad8}
# A comparison may be followed by SSE moves, LEAs, a return path (13d36),
# or other flag-preserving instructions. All pairs refer to the fixed original.
GUARD = {0x8eb2:0x8eab,0x8f0d:0x8f06,0x8fba:0x8fb3,0x9096:0x908f,
         0xa6d2:0xa6cb,0xa721:0xa71a,0xa7f6:0xa7ef,0xa964:0xa95d,
         0xe06c:0xe065,0xe0ba:0xe0b3,0xe11f:0xe118,
         0xf129:0xf122,0xf167:0xf160,0xf1c2:0xf1bb,0xf215:0xf20e,
         0x12c77:0x12c70,0x12c8b:0x12c87,0x12cb7:0x12cb0,
         0x13acf:0x13aad,0x13b67:0x13b34,0x13bde:0x13bb2,0x13c5d:0x13c59,
         0x13d27:0x13d20,0x13d36:0x13d20,0x13d5a:0x13d53,0x13d74:0x13d70,
         0x140a9:0x140a2,0x145e9:0x145c7,0x1464c:0x14645,
         0x1469b:0x14683,0x146f3:0x146dc,
         0x13617:0x135f4}
GUARD.update({0x13667+i*0x50: 0x13663+i*0x50 for i in range(14)})
WANTED = {0x91a4,0xa6e4,0xaa51,0xe215,0xf135,0xf2aa,0x12c93,0x12cc3,
          0x135c3,0x13a89,0x13af3,0x13b76,0x13bef,0x13cc4,0x13d63,0x140b2,
          0x145f5,0x1465b,0x146a8,0x14700}
CALLER_CONTRACT = {0x91a4,0xa6e4,0xe215,0xf135,0x12c93}
THRESHOLDS = sorted({0,1,2,7,8,9,15,16,31,32,63,64,127,128,167,168,175,
                     176,177,255,256,257,511,512,767,768,1024,SIGN-1,SIGN,MAX})


def split(intervals):
    """One conservative hull per sign, with wrap handled by the caller."""
    result = []
    for first,last in ALL:
        pieces = [(max(a,first),min(b,last)) for a,b in intervals if a<=last and first<=b and a<=b]
        if pieces:
            result.append((min(p[0] for p in pieces),max(p[1] for p in pieces)))
    return tuple(result)


def overlap(intervals, low, high):
    return split([(max(a,low),min(b,high)) for a,b in intervals])


def subtract(intervals, low, high):
    output = []
    for a,b in intervals:
        a,b = a-high,b-low
        if a < 0:
            output.append((max(0,a+MOD),min(MAX,b+MOD)))
        output.append((max(0,a),b))
    return split(output)


def restrict(intervals, op, imm, taken):
    if op in ('je','jne'):
        if taken == (op=='je'):
            return overlap(intervals,imm,imm)
        return split(overlap(intervals,0,imm-1) + overlap(intervals,imm+1,MAX))
    signed = op in ('jg','jge','jl','jle')
    offset = op in ('jg','ja','jle','jbe')
    cut = imm + offset
    below = taken == (op in ('jl','jle','jb','jbe'))
    result = []
    for a,b in intervals:
        shift = MOD if signed and a>=SIGN else 0
        if below:
            result.append((a,min(b,cut-1+shift)))
        else:
            result.append((max(a,cut+shift),b))
    return split(result)


def quotient(intervals):
    return split([(a>>4,b>>4) for a,b in intervals])


def residue(intervals, mask):
    return split([(a&mask,b&mask) if a//(mask+1)==b//(mask+1) else (0,mask)
                  for a,b in intervals])


def read_csv(path):
    with path.open(encoding="utf-8-sig",newline="") as f:
        return list(csv.DictReader(f))


def load_original(original,s5):
    raw = original.read_bytes()
    assert hashlib.sha256(raw).hexdigest()==DIGEST
    pe = pefile.PE(data=raw)
    im = pe.get_memory_mapped_image()
    reloc = {e.rva for b in pe.DIRECTORY_ENTRY_BASERELOC for e in b.entries if e.type==10}
    decoder = cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64)
    decoder.detail = True
    table,sites,items,owner_at = {},{},{},{}
    for owner,end in END.items():
        spans = {}
        for row in read_csv(s5/f"table-{owner:x}.csv"):
            base,idx,slot = (int(row[k],0) for k in ("table_rva","index","slot_rva"))
            assert slot==base+8*idx
            val = struct.unpack_from("<Q",im,slot)[0]
            assert val==int(row["stored"],0)
            if base<0x24000:
                target=base-val
            else:
                target=val-pe.OPTIONAL_HEADER.ImageBase if val else None
                assert (slot in reloc)==bool(val)
            assert target==(int(row["target_rva"],0) if row['target_rva'] else None)
            targets=table.setdefault(base,[])
            assert len(targets)==idx
            targets.append(target)
            spans[base]=slot+8
        areas=[(owner,end)]
        if min(spans)<end:
            areas=[(owner,min(spans)),(max(spans.values())+(8 if owner==0xe040 else 0),end)]
        for low,high in areas:
            seq=list(decoder.disasm(im[low:high],low))
            assert seq[-1].address+seq[-1].size==high
            items.update((i.address,i) for i in seq)
            owner_at.update((i.address,owner) for i in seq)
        for base in spans:
            assert all(t is None or owner_at.get(t)==owner for t in table[base])
    for row in read_csv(s5/'dispatch.csv'):
        site,lea,fetch,base = (int(row[k],0) for k in ('site_rva','base_lea_rva','fetch_rva','table_rva'))
        j,l,r = items[site],items[lea],items[fetch]
        assert j.mnemonic.endswith('jmp') and l.mnemonic=='lea'
        assert l.operands[1].mem.base==X86_REG_RIP and base==lea+l.size+l.operands[1].mem.disp
        assert r.operands[-1].type==X86_OP_MEM and r.operands[-1].mem.scale==8
        assert r.operands[-1].mem.base==l.operands[0].reg
        if site!=fetch:
            assert r.address+r.size==site and r.mnemonic=='sub' and r.operands[0].reg==j.operands[0].reg==l.operands[0].reg
        index=r.reg_name(r.operands[-1].mem.index)
        assert index==row['index'] and base in table and site not in sites
        sites[site]=(base,index)
    assert len(sites)==34 and len(table)==20 and sum(map(len,table.values()))==2946
    for site,begin in QUOTIENT.items():
        seq=[i.mnemonic+' '+i.op_str for loc,i in items.items() if begin<=loc<site and i.mnemonic!='sfence']
        assert seq==['mov r9, r8','shr r9, 4','shl r9, 4','add rcx, r9','add rdx, r9','sub r8, r9','shr r9, 4']
        # No direct branch or physical table entry may bypass a part of the folded sequence.
        assert not any(begin<t<=site for values in table.values() for t in values if t is not None)
        assert not any(i.group(cs.CS_GRP_JUMP) and i.operands[0].type==X86_OP_IMM and begin<i.operands[0].imm<=site for i in items.values())
    for jump,compare in GUARD.items():
        j,c=items[jump],items[compare]
        assert j.mnemonic in ('jne','je','ja','jae','jl','jle','jg','jge') and c.mnemonic=='cmp'
        assert c.op_str.startswith('r8, ') and c.operands[1].type==X86_OP_IMM
        assert not any(i.reg_name(reg)=='rflags' for loc,i in items.items() if compare<loc<jump
                       for reg in i.regs_access()[1])
    return items,sites,table,owner_at


def check_incoming(original,s5,items,table,owners):
    """Look for alternate static entrances to the disconnected block."""
    pe=pefile.PE(str(original))
    im=pe.get_memory_mapped_image()
    imagebase=pe.OPTIONAL_HEADER.ImageBase
    lo,hi=0x135a4,0x135c7
    decoder=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64)
    decoder.detail=True
    primary=json.loads((s5.parent/'reassembly.json').read_text())['matches']
    later=json.loads((s5/'reassembly.json').read_text())
    matched=sorted((int(row['rva'],0),row['bytes'],row['sha256']) for row in primary+later)
    static_sources=[]
    other_entries=[]
    previous=0
    count=0
    for begin,size,fingerprint in matched:
        assert previous<=begin and hashlib.sha256(im[begin:begin+size]).hexdigest()==fingerprint
        previous=begin+size
        if begin in END:
            instructions=(i for i in items.values() if owners[i.address]==begin)
        else:
            instructions=list(decoder.disasm(im[begin:begin+size],begin))
            assert instructions and instructions[-1].address+instructions[-1].size==begin+size
        for i in instructions:
            count+=1
            direct=(i.group(cs.CS_GRP_JUMP) or i.group(cs.CS_GRP_CALL)) and i.operands[0].type==X86_OP_IMM
            if direct:
                target=i.operands[0].imm
                if lo<=target<hi:
                    static_sources.append(['direct',hex(i.address),hex(target)])
                if target in owners and begin!=owners[target] and target!=owners[target]:
                    other_entries.append([hex(begin),hex(i.address),hex(target)])
            for operand in i.operands:
                if operand.type==X86_OP_MEM and operand.mem.base==X86_REG_RIP:
                    target=i.address+i.size+operand.mem.disp
                    if lo<=target<hi:
                        static_sources.append(['rip-relative',hex(i.address),hex(target)])
    for block in pe.DIRECTORY_ENTRY_BASERELOC:
        for reloc in block.entries:
            if reloc.type==10:
                target=struct.unpack_from('<Q',im,reloc.rva)[0]-imagebase
                if lo<=target<hi:
                    static_sources.append(['DIR64',hex(reloc.rva),hex(target)])
    anchors={pe.OPTIONAL_HEADER.AddressOfEntryPoint}
    anchors.update(e.address for e in pe.DIRECTORY_ENTRY_EXPORT.symbols)
    anchors.update(e.struct.BeginAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION)
    guard=pe.DIRECTORY_ENTRY_LOAD_CONFIG.struct
    assert guard.GuardCFFunctionCount==0 and guard.GuardEHContinuationCount==0
    anchors.update(int(r['rva'],0) for r in read_csv(s5.parent/'native-functions.csv'))
    for target in anchors:
        if lo<=target<hi:
            static_sources.append(['entry',None,hex(target)])
    for base,targets in table.items():
        for k,target in enumerate(targets):
            if target is not None and lo<=target<hi:
                static_sources.append(['table',hex(base+k*8),hex(target)])
    assert len(matched)==532 and count==12498
    return dict(search_half_open=[hex(lo),hex(hi)],verified_text_spans=len(matched),
                decoded_instruction_count=count,static_references=static_sources,
                cross_routine_direct_edges_to_six_interiors=other_entries)


def analyze(items,sites,table,entry_state):
    state={}
    queue=deque()
    def push(pc,span,back=False):
        if pc not in items or not span:
            return
        old=state.get(pc,())
        new=split(old+span)
        if old==new:
            return
        if back and old:
            widened=[]
            for a,b in new:
                same=next(((x,y) for x,y in old if (x<SIGN)==(a<SIGN)),None)
                if same and a<same[0]:
                    a=max(t for t in THRESHOLDS if t<=a)
                if same and b>same[1]:
                    b=min(t for t in THRESHOLDS if t>=b)
                widened.append((a,b))
            new=split(widened)
        state[pc]=new
        queue.append(pc)
    for owner in END:
        push(owner,entry_state)
    while queue:
        pc=queue.popleft()
        i=items[pc]
        value=state[pc]
        if pc in sites:
            base,reg=sites[pc]
            idx=(ALIGN[pc],) if pc in ALIGN else quotient(value) if pc in QUOTIENT else value
            assert reg=='r8' or pc in ALIGN or pc in QUOTIENT
            for k,target in enumerate(table[base]):
                if target is not None and any(a<=k<=b for a,b in idx):
                    residual=( (k,k), ) if reg=='r8' else residue(value,15) if pc in QUOTIENT else value
                    push(target,residual,back=target<=pc)
            continue
        if i.group(cs.CS_GRP_RET):
            continue
        nxt=pc+i.size
        if i.group(cs.CS_GRP_JUMP):
            assert i.operands[0].type==X86_OP_IMM
            target=i.operands[0].imm
            if pc in GUARD:
                bound=items[GUARD[pc]].operands[1].imm
                taken=restrict(value,i.mnemonic,bound,True)
                fall=restrict(value,i.mnemonic,bound,False)
            else:
                taken=fall=value
            push(target,taken,back=target<=pc)
            if i.mnemonic!='jmp':
                push(nxt,fall)
            continue
        if 'r8' in [i.reg_name(reg) for reg in i.regs_access()[1]]:
            if pc in SUB_ALIGN:
                assert i.mnemonic=='sub' and i.op_str.startswith('r8, ')
                value=subtract(value,*SUB_ALIGN[pc])
            elif pc in (0x135bc,0x13ae9):
                pass  # Sequence folded at the jump, verified by load_original.
            elif i.mnemonic in ('dec','sub','lea'):
                dec=1 if i.mnemonic=='dec' else i.operands[1].imm if i.mnemonic=='sub' else -i.operands[1].mem.disp
                assert i.mnemonic!='lea' or (i.reg_name(i.operands[1].mem.base)=='r8' and not i.operands[1].mem.index)
                assert 0<dec<=512
                value=subtract(value,dec,dec)
            elif i.mnemonic=='and':
                value=residue(value,i.operands[1].imm)
            elif i.mnemonic=='mov' and pc in (0x9216,0xe258,0xf2dd):
                value=ALL
            else:
                raise ValueError((hex(pc),i.mnemonic,i.op_str))
        push(nxt,value)
    return state


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original',type=Path)
    parser.add_argument('s5_directory',type=Path)
    args=parser.parse_args()
    items,sites,table,owners=load_original(args.original,args.s5_directory)
    incoming=check_incoming(args.original,args.s5_directory,items,table,owners)
    state=analyze(items,sites,table,((0,SIGN-1),))
    rows={}
    for site in sorted(WANTED|{0x1403f}):
        base,reg=sites[site]
        val=state.get(site,())
        idx=quotient(val) if site in QUOTIENT else (ALIGN[site],) if site in ALIGN and val else val
        assert all(0<=a<=b<len(table[base]) for a,b in idx)
        targets={table[base][k] for a,b in idx for k in range(a,b+1)}
        assert None not in targets
        status='caller_length_declaration_required' if site in CALLER_CONTRACT else 'bounded_from_entry'
        if not idx:
            assert site==0x135c3 and not incoming['static_references'] and not incoming['cross_routine_direct_edges_to_six_interiors']
            status='no_path_from_known_entries'
        rows[hex(site)]=dict(owner=hex(owners[site]),index_register=reg,table=hex(base),
                            slots=len(table[base]),normal_index_inclusive=idx,status=status,
                            distinct_targets_within_bound=len(targets))
    print(json.dumps(dict(original_sha256=DIGEST,capstone=cs.__version__,pefile=pefile.__version__,
                          known_entries=list(map(hex,END)),alternate_entry_scan=incoming,
                          domain='ordinary nonnegative byte count representable by the signed length comparisons',
                          additional_previously_checked_site='0x1403f',selectors=rows),indent=2))


if __name__=='__main__':
    main()
