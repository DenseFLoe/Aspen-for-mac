"""Rebuild the four zedstwu AMD64 business exports and compare relocated COFF text to the original.

Usage: python -B check-business.py ORIGINAL ZIG [--first-round PREVIOUS_UNIT_DIR]
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile
from collections import Counter

import capstone as cs
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_REG_RIP
import pefile

HERE=Path(__file__).resolve().parent
DIGEST='09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b'
NAMES=['DSWU_EUDL01','DSWU_IUDL01','DSWU_UDL01I','DSWU_ZUDL01']


def first_round_reader(unit):
    sys.path.insert(0,str(unit))
    spec=importlib.util.spec_from_file_location('zedstwu_first_round',unit/'verify.py')
    module=importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module.objects


def load_targets(pe,image,md):
    base=pe.OPTIONAL_HEADER.ImageBase
    iat={s.address-base:d.dll.decode()+'!'+(s.name.decode() if s.name else '#'+str(s.ordinal))
         for d in pe.DIRECTORY_ENTRY_IMPORT for s in d.imports}
    def external(target):
        thunk=next(md.disasm(image[target:target+15],target,count=1))
        if thunk.mnemonic!='jmp' or thunk.operands[0].type!=X86_OP_MEM or thunk.operands[0].mem.base!=X86_REG_RIP:
            return None
        slot=thunk.address+thunk.size+thunk.operands[0].mem.disp
        return {'iat_rva':hex(slot),'import':iat[slot]} if slot in iat else None
    return external


def check(original,zig,unit):
    data=original.read_bytes()
    assert hashlib.sha256(data).hexdigest()==DIGEST
    pe=pefile.PE(data=data)
    image=pe.get_memory_mapped_image()
    exports={s.name.decode():s.address for s in pe.DIRECTORY_ENTRY_EXPORT.symbols}
    assert set(exports)==set(NAMES)
    ends={e.struct.BeginAddress:e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    decoder=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64)
    decoder.detail=True
    objects=first_round_reader(unit)
    compiler=subprocess.check_output([str(zig.resolve()),'version'],text=True).strip()
    assert compiler=='0.13.0'
    resolve_external=load_targets(pe,image,decoder)
    results={}
    for name in NAMES:
        lo=exports[name]
        if name=='DSWU_IUDL01':
            assert lo not in ends
            for insn in decoder.disasm(image[lo:lo+4096],lo):
                if insn.mnemonic=='ret':
                    end=insn.address+insn.size
                    break
                assert insn.mnemonic=='mov' and insn.operands[0].type==X86_OP_MEM
        else:
            end=ends[lo]
        source=HERE/(name+'.c')
        with tempfile.TemporaryDirectory() as tmp:
            obj=Path(tmp)/'business.obj'
            subprocess.run([str(zig.resolve()),'cc','-target','x86_64-windows-gnu','-O2','-g0',
                            '-fno-stack-protector','-fno-asynchronous-unwind-tables','-c',
                            str(source),'-o',str(obj)],check=True)
            payload,symbols,relocs=objects(obj.read_bytes())
        assert symbols[name]==0
        for pos,label,kind in relocs:
            assert re.fullmatch('rva_[0-9a-f]+',label) and 4<=kind<=9
            addend=struct.unpack_from('<i',payload,pos)[0]
            delta=int(label[4:],16)+addend-(lo+pos+kind)
            struct.pack_into('<i',payload,pos,delta)
        expected=image[lo:end]
        actual=bytes(payload[:len(expected)])
        for n,(x,y) in enumerate(zip(actual,expected)):
            if x!=y:
                left=next(i for i in decoder.disasm(expected,lo) if i.address<=lo+n<i.address+i.size)
                right=next(decoder.disasm(actual[left.address-lo:],left.address))
                raise ValueError(f'{name} {lo+n:#x}: original {left.mnemonic} {left.op_str} {left.bytes.hex()}, reassembly {right.mnemonic} {right.op_str} {right.bytes.hex()}')
        assert actual==expected and len(payload)==end-lo,(name,len(payload),end-lo)
        instructions=list(decoder.disasm(expected,lo))
        assert instructions[-1].address+instructions[-1].size==end
        calls=[]
        refs=[]
        branches=Counter()
        writes=[]
        starts={i.address for i in instructions}
        for i in instructions:
            if i.group(cs.CS_GRP_JUMP) or i.group(cs.CS_GRP_CALL):
                assert i.operands[0].type==X86_OP_IMM
                target=i.operands[0].imm
                if i.group(cs.CS_GRP_CALL):
                    calls.append(dict(site=hex(i.address),target=hex(target),external=resolve_external(target)))
                else:
                    branches[i.mnemonic]+=1
                    if lo<=target<end:
                        assert target in starts
            for operand in i.operands:
                if operand.type==X86_OP_MEM and operand.mem.base==X86_REG_RIP:
                    target=i.address+i.size+operand.mem.disp
                    refs.append((hex(i.address),hex(target)))
                    if name=='DSWU_IUDL01':
                        assert i.operands[0].size==8 and i.operands[1].type==X86_OP_IMM
                        writes.append((hex(i.address),hex(target),i.operands[1].imm))
        results[name]=dict(entry=hex(lo),exclusive_end=hex(end),matching_bytes=end-lo,
                           original_text_sha256=hashlib.sha256(expected).hexdigest(),
                           source_sha256=hashlib.sha256(source.read_bytes()).hexdigest(),rel32=len(relocs),
                           instructions=len(instructions),jumps=dict(sorted(branches.items())),
                           calls=calls,rip_operands=refs)
        if writes:
            assert len({t for _,t,_ in writes})==len(writes)==63
            assert sorted(int(t,0) for _,t,_ in writes)==list(range(0x241e0,0x243d8,8))
            assert image[0x241e0:0x243d8]==bytes(504)
            results[name]['ordered_u64_stores']=writes
            results[name]['mapped_zero_initialized_data']={'begin':'0x241e0','end':'0x243d8','bytes':504}
    return dict(original_sha256=DIGEST,compiler='Zig '+compiler,capstone=cs.__version__,
                matching_bytes=sum(r['matching_bytes'] for r in results.values()),exports=results)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('original',type=Path)
    p.add_argument('zig',type=Path)
    p.add_argument('--first-round',type=Path,default=HERE.parent)
    p.add_argument('--output',type=Path)
    a=p.parse_args()
    content=json.dumps(check(a.original,a.zig,a.first_round),indent=2)+'\n'
    if a.output:
        a.output.write_bytes(content.encode())
    else:
        print(content,end='')
