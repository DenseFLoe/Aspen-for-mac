"""Rebuild the three copy ranges and verify their data, instruction and control references."""
import argparse
import csv
import hashlib
import io
import json
import re
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import capstone as cs
from capstone.x86 import X86_OP_IMM, X86_OP_MEM, X86_OP_REG, X86_REG_RIP
from iced_x86 import Decoder
import pefile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
from verify import objects

ORIGINAL = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
PARTS = {
    0xcbe0: ("get_copy_avx.c", 0xcbe8, "d740376f069513192c97c0dbdda6e5c39eedd1360a62c58fe60ce92d91d43fb8"),
    0xcbf0: ("get_copy_high.c", 0xcbf8, "8e76d8faea7a668fed332a38927d8ebcb47e2f8484cdebe053e9e3cf10e846ea"),
    0xcd80: ("copy_avx.c", 0xe589, "72586b05df77ea74f39bcc554d92941fe99e1e417afeb70728e4a4dec746d58b"),
}
TABLES = {0xd470:32, 0xd570:256, 0xdd70:257}
# Jump site, table-address load, indexed read, index register, first and last reachable slot
JUMPS = {
    0xcd9f: (0xcd94,0xcd9b,"r8",0,256),
    0xcdda: (0xcdb0,0xcdd6,"r14",1,31),
    0xd084: (0xd079,0xd080,"r8",0,255),
    0xd0fd: (0xd0ef,0xd0f9,"r14",0,31),
}
sha = lambda b: hashlib.sha256(b).hexdigest()


def csv_text(rows):
    buf = io.StringIO(newline="")
    writer = csv.DictWriter(buf, fieldnames=list(rows[0]), lineterminator="\n")
    writer.writeheader()
    writer.writerows(rows)
    return buf.getvalue()


def verify(original, zig):
    data = original.read_bytes()
    assert sha(data) == ORIGINAL
    pe = pefile.PE(data=data)
    anchors = {e.struct.BeginAddress:e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    assert anchors[0xcd80] == 0xe589 and all(addr not in anchors for addr in (0xcbe0,0xcbf0))
    cs64 = cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64)
    cs64.detail = True

    def decode(start,end):
        raw = pe.get_data(start,end-start)
        primary = list(cs64.disasm(raw,start))
        independent = list(Decoder(64,raw,ip=start))
        assert sum(i.size for i in primary) == len(raw) == end-start
        assert not any(i.is_invalid for i in independent)
        assert [(i.address,i.size) for i in primary] == [(i.ip,i.len) for i in independent]
        return primary

    def rip(ins):
        return next((ins.address+ins.size+op.mem.disp for op in ins.operands
                     if op.type==X86_OP_MEM and op.mem.base==X86_REG_RIP), None)

    def instruction_summary(ins):
        return f"{ins.mnemonic} {ins.op_str}".strip()

    info,listing,references,table_rows = [],[],[],[]
    indexed = {}
    for start,(name,end,digest) in PARTS.items():
        expected = pe.get_data(start,end-start)
        assert sha(expected)==digest
        code = decode(start,end) if start!=0xcd80 else decode(start,0xd470)+decode(0xe578,end)
        indexed.update({i.address:i for i in code})
        extern = {}
        for ins in code:
            asm = instruction_summary(ins)
            listing.append(f"{ins.address:08x}  {ins.bytes.hex(' ')}  {asm}")
            target = rip(ins)
            if target is not None and target not in TABLES:
                extern[ins.address+ins.disp_offset-start]=target
            role,ref = "", ""
            if target is not None:
                role,ref = "RIP-relative address or data",hex(target)
            elif ins.group(cs.CS_GRP_CALL):
                raise AssertionError("Unexpected call in the three assigned ranges")
            elif ins.group(cs.CS_GRP_JUMP):
                if ins.operands[0].type==X86_OP_IMM:
                    role,ref = "direct branch",hex(ins.operands[0].imm)
                else:
                    assert ins.address in JUMPS
                    role,ref = "indexed jump",hex(rip(indexed[JUMPS[ins.address][0]]))
            elif ins.mnemonic!="nop" and any(op.type==X86_OP_MEM for op in ins.operands):
                role,ref = "register-relative memory or address",ins.op_str
            if role:
                references.append(dict(owner=hex(start),site=hex(ins.address),role=role,
                                       operand_or_target=ref,instruction=asm))
        with tempfile.TemporaryDirectory() as work:
            obj = Path(work)/"copy.obj"
            subprocess.run([str(zig.resolve()),"cc","-target","x86_64-windows-gnu","-O2","-g0",
                            "-fno-stack-protector","-fno-asynchronous-unwind-tables","-c",
                            str(HERE/name),"-o",str(obj)],check=True)
            buf,_,relocs = objects(obj.read_bytes())
        bindings=[]
        for offset,symbol,kind in relocs:
            suffix=re.search(r"_rva_([0-9a-f]+)$",symbol)
            assert suffix and kind==4
            target=int(suffix[1],16)
            assert extern.pop(offset)==target and buf[offset:offset+4]==bytes(4)
            disp=target-(start+offset+4)
            struct.pack_into("<i",buf,offset,disp)
            bindings.append({"operand_rva":hex(start+offset),"symbol":symbol,
                             "target":hex(target),"kind":"IMAGE_REL_AMD64_REL32","displacement":disp})
        assert not extern and buf==expected
        info.append(dict(start=hex(start),end=hex(end),source=name,matched_bytes=len(buf),
                         instruction_bytes=sum(i.size for i in code),instructions=len(code),
                         table_bytes=len(buf)-sum(i.size for i in code),sha256=digest,relocations=bindings))
    for ins in indexed.values():
        if ins.group(cs.CS_GRP_JUMP) and ins.operands[0].type==X86_OP_IMM:
            assert ins.operands[0].imm in indexed
    # Guard originals and the register definitions used for switch bounds.
    guards = {0xcd8b:"cmp r8, 0x100",0xcd92:"ja 0xcdb0",0xcdba:"and r14, 0x1f",
              0xcdbe:"je 0xcde6",0xcdc0:"neg r14",0xcdc3:"add r14, 0x20",0xcdc7:"sub r8, r14",
              0xcde6:"cmp r8, 0x100",0xcded:"jl 0xd060",0xce8c:"sub r8, 0x100",
              0xce93:"cmp r8, 0x100",0xce9a:"jae 0xce10",0xcea0:"jmp 0xd060",
              0xcd85:"mov rax, rcx",0xd060:"add r10, r8",0xd063:"mov r11, r10",0xd066:"mov r14, r11",
              0xd069:"and r10, 0xffffffffffffffe0",0xd073:"sub r14, r10",0xd0f6:"mov r8, r14"}
    for site,asm in guards.items():
        assert instruction_summary(indexed[site])==asm,(hex(site),instruction_summary(indexed[site]))
    target_maps={}
    for base,count in TABLES.items():
        slots=struct.unpack(f"<{count}Q",pe.get_data(base,count*8))
        dests=[base-offset for offset in slots]
        assert all(t in indexed and 0xcd80<=t<0xd470 for t in dests)
        target_maps[base]=dests
        for ix,(offset,target) in enumerate(zip(slots,dests)):
            table_rows.append(dict(table=hex(base),index=ix,slot=hex(base+ix*8),
                                   difference=hex(offset),target=hex(target)))
    jumps=[]
    for site,(load,read,reg,low,high) in JUMPS.items():
        base=rip(indexed[load])
        assert base in TABLES and instruction_summary(indexed[site])=="notrack jmp r9"
        ins=indexed[read]
        assert ins.mnemonic=="sub" and ins.reg_name(ins.operands[0].reg)=="r9"
        mem=ins.operands[1].mem
        assert ins.reg_name(mem.base)=="r9" and ins.reg_name(mem.index)==reg and mem.scale==8 and mem.disp==0
        dests=target_maps[base][low:high+1]
        jumps.append(dict(site=hex(site),table_lea=hex(load),indexed_sub=hex(read),index=reg,
                          first_index=low,last_index=high,table=hex(base),targets=sorted({hex(t) for t in dests})))
    assert {rip(indexed[r]) for r in [0xcd94,0xcdb0,0xcdf3,0xceb0,0xd079,0xd0ef]}==set(TABLES)|{0x22248,0x22238}
    shared={hex(r):dict(width=8,initial_value=struct.unpack("<Q",pe.get_data(r,8))[0])
            for r in (0x22248,0x22238)}
    for call,getter,target in [(0xcc58,0xcbf0,0xe5c0),(0xcc77,0xcbe0,0xcd80)]:
        ins=decode(call,call+5)[0]
        assert ins.mnemonic=="call" and ins.operands[0].imm==getter and rip(indexed[getter])==target
        assert indexed[getter+7].mnemonic=="ret" and pe.get_data(getter+8,8)==bytes([0xcc])*8
        references.append(dict(owner="0xcc20",site=hex(call),role="initializer call",operand_or_target=hex(getter),
                               instruction=instruction_summary(ins)))
    report=dict(original_sha256=ORIGINAL,compiler=subprocess.check_output([str(zig.resolve()),"version"],text=True).strip(),
                ranges=info,table_entries=sum(TABLES.values()),indexed_jumps=jumps,shared_data=shared,
                original_call_instructions_in_assigned_ranges=0,
                bounds_domain="Valid Windows user-mode copy ranges; the original signed JL at 0xcded is retained.")
    return {"rebuild.json":json.dumps(report,indent=2)+"\n","instructions.lst":"\n".join(listing)+"\n",
            "references.csv":csv_text(references),"table-slots.csv":csv_text(table_rows)}


if __name__=="__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    parser.add_argument("zig",type=Path)
    parser.add_argument("--write",action="store_true",help="write the four derived evidence files")
    args=parser.parse_args()
    for name,content in verify(args.original,args.zig).items():
        if args.write:
            (HERE/name).write_bytes(content.encode("utf-8"))
        else:
            assert (HERE/name).read_bytes()==content.encode("utf-8"),name
    print("Verified the three original ranges, all four COFF REL32 relocations and 545 symbolic table slots.")
