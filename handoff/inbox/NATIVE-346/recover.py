"""Recover ppexec entry coverage and call/reference locations from the pinned PE."""
import argparse
from collections import deque
import csv
import hashlib
import json
import re
import struct
from pathlib import Path

import capstone
import pefile
from capstone import Cs, CS_ARCH_X86, CS_MODE_64, CS_GRP_JUMP, CS_GRP_RET
from capstone.x86 import X86_OP_MEM, X86_OP_IMM, X86_REG_RIP

ORIGINAL = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"


def write_text(path, lines):
    path.write_bytes(("\n".join(lines) + "\n").encode("utf-8"))


def write_table(path, fields, rows):
    with path.open("w", encoding="utf-8", newline="") as out:
        writer = csv.writer(out, lineterminator="\n")
        writer.writerow(fields)
        writer.writerows(rows)


def recover(path, folder):
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("original SHA-256 mismatch")
    pe = pefile.PE(data=data)
    image = pe.get_memory_mapped_image()
    base = pe.OPTIONAL_HEADER.ImageBase
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.detail = True
    bounds = {e.struct.BeginAddress: e.struct.EndAddress for e in pe.DIRECTORY_ENTRY_EXCEPTION}
    code = [(s.VirtualAddress, s.VirtualAddress+s.Misc_VirtualSize) for s in pe.sections
            if s.Characteristics & 0x20000000]
    def executable(addr):
        return any(lo <= addr < hi for lo,hi in code)
    exports = {s.address: s.name.decode("ascii") for s in pe.DIRECTORY_ENTRY_EXPORT.symbols
               if s.name and executable(s.address)}
    models = {address:name.removeprefix("PPEXEC_") for address,name in exports.items()}
    if len(models)!=21:
        raise ValueError("export set no longer matches the reassembled bodies")
    model_source = (folder/"code"/"ppexec.c").read_text(encoding="utf-8")
    for mark in re.findall(r"^/\* (SUB_([0-9a-f]+)) begin \*/$",model_source,re.M):
        address = int(mark[1],16)
        if address not in bounds or address in models:
            raise ValueError("internal source does not match a unique original runtime record")
        models[address] = mark[0]
    sections = []
    for sec in pe.sections:
        sections.append(dict(name=sec.Name.rstrip(b"\0").decode(),rva=hex(sec.VirtualAddress),
                             virtual_size=sec.Misc_VirtualSize,raw_size=sec.SizeOfRawData))
    export_inventory = []
    for sym in pe.DIRECTORY_ENTRY_EXPORT.symbols:
        sec = pe.get_section_by_rva(sym.address)
        export_inventory.append(dict(name=sym.name.decode() if sym.name else "",ordinal=sym.ordinal,
                                     rva=hex(sym.address),section=sec.Name.rstrip(b"\0").decode(),
                                     kind="code" if executable(sym.address) else "data"))
    resources = []
    for typ in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for ident in typ.directory.entries:
            for language in ident.directory.entries:
                info = language.data.struct
                payload = pe.get_data(info.OffsetToData,info.Size)
                assert len(payload)==info.Size
                resources.append(dict(type=typ.id,id=ident.id,language=language.id,rva=hex(info.OffsetToData),
                                      size=info.Size,sha256=hashlib.sha256(payload).hexdigest()))
    vinfo=pe.VS_FIXEDFILEINFO[0]
    version=[vinfo.FileVersionMS >> 16, vinfo.FileVersionMS & 0xffff, vinfo.FileVersionLS >> 16, vinfo.FileVersionLS & 0xffff]
    folder.mkdir(parents=True,exist_ok=True)
    write_text(folder/"pe-surface.json",[json.dumps(dict(original_sha256=ORIGINAL,file_version=version,
                                                         sections=sections,exports=export_inventory,
                                                         resources=resources),indent=2)])
    # PPEXEC_PHCCIN compares two eight-byte keys and dispatches indices 0..178.
    if image[0x178b:0x17a7].hex()!="4181f8b200000077ab4489c1488d152246010048630c8a4801d1ffe1":
        raise ValueError("indexed dispatch guard, lookup or branch changed")
    table_base = 0x15dc0
    jumps = [table_base+d for d in struct.unpack_from("<179i",image,table_base)]
    if not all(0x1560<=dest<0x2b76 for dest in jumps):
        raise ValueError("switch target outside owner")
    switch = []
    for i,dest in enumerate(jumps):
        key = 0x160b0+16*i
        switch.append((i,hex(key),image[key:key+8].hex(),image[key+8:key+16].hex(),
                       hex(table_base+4*i),dest-table_base,hex(dest)))
    write_table(folder/"phccin-switch.csv",["index","key_rva","key1_le_bytes","key2_le_bytes",
                                            "offset_rva","signed_offset","target_rva"],switch)
    imports = {}
    for table in ("DIRECTORY_ENTRY_IMPORT","DIRECTORY_ENTRY_DELAY_IMPORT"):
        for d in getattr(pe,table,[]):
            for sym in d.imports:
                name = sym.name.decode("ascii") if sym.name else f"ordinal_{sym.ordinal}"
                imports[sym.address-base] = d.dll.decode("ascii")+"!"+name
    def first_insn(pos):
        return next(md.disasm(image[pos:pos+15],base+pos,count=1),None)
    def rip(ins):
        for operand in ins.operands:
            if operand.type == X86_OP_MEM and operand.mem.base == X86_REG_RIP:
                return ins.address-base+ins.size+operand.mem.disp
        return None
    def thunk(pos):
        ins = first_insn(pos)
        if ins and ins.mnemonic == "jmp" and bytes(ins.bytes[:2]) == b"\xff\x25":
            slot = rip(ins)
            if slot in imports:
                return slot
        return None
    entry = pe.OPTIONAL_HEADER.AddressOfEntryPoint
    seeds = set(bounds)|set(exports)|{entry}
    labels = {k: exports.get(k, f"runtime_{k:x}") for k in seeds}
    ghidra = {}
    decompiled = folder/"decompiler-functions.csv"
    if decompiled.is_file():
        with decompiled.open(encoding="utf-8",newline="") as stream:
            for row in csv.DictReader(stream):
                address = int(row["rva"],0)
                if not executable(address) or address in ghidra:
                    raise ValueError("duplicate or non-code Ghidra entry")
                ghidra[address] = row
                labels.setdefault(address,row["name"])
    work = deque(sorted(labels))
    bodies = {}
    problems = {}
    sites = {}
    edges = set()
    while work:
        start = work.popleft()
        if start in bodies:
            continue
        stop = bounds.get(start, min((x for x in seeds if x>start),default=code[-1][1]))
        # A direct call target can sit inside a runtime-function record.
        containing = [hi for lo,hi in bounds.items() if lo<start<hi]
        if containing:
            stop = min(stop,min(containing))
        blocks = [start]
        instructions = {}
        unresolved = []
        while blocks:
            pos = blocks.pop()
            while start <= pos < stop and pos not in instructions:
                ins = first_insn(pos)
                if ins is None or pos+ins.size>stop:
                    unresolved.append(f"decode/boundary {pos:#x}")
                    break
                instructions[pos] = ins
                op = ins.operands[0] if ins.operands else None
                direct = op.imm-base if op and op.type == X86_OP_IMM else None
                dest = rip(ins)
                listings = []
                if ins.mnemonic == "call" or ins.group(CS_GRP_JUMP):
                    if direct is not None:
                        if ins.mnemonic in {"call","jmp"}:
                            slot = thunk(direct) if executable(direct) else None
                            if slot is not None:
                                listings.append(("external",imports[slot],f"via thunk {direct:#x}, IAT {slot:#x}"))
                            if ins.mnemonic == "call" or slot is not None:
                                edges.add((start,pos,direct))
                                if executable(direct) and direct not in labels:
                                    labels[direct] = f"target_{direct:x}"
                                    work.append(direct)
                        if ins.group(CS_GRP_JUMP) and start <= direct < stop:
                            blocks.append(direct)
                        elif ins.group(CS_GRP_JUMP) and direct not in seeds:
                            if not (executable(direct) and thunk(direct) is not None):
                                unresolved.append(f"out-of-range branch {pos:#x}->{direct:#x}")
                    elif start==0x1560 and pos==0x17a5:
                        blocks.extend(jumps)
                        edges.update((start,pos,target) for target in jumps)
                    elif dest in imports:
                        listings.append(("external",imports[dest],f"IAT {dest:#x}"))
                    else:
                        listings.append(("unresolved",ins.op_str,"bind register/table value on incoming paths"))
                        unresolved.append(f"indirect {pos:#x}")
                elif dest is not None:
                    what = "materialized code address" if executable(dest) and ins.mnemonic=="lea" else "RIP-relative operand"
                    listings.append(("data",imports.get(dest,f"RVA {dest:#x}"),f"{what} {dest:#x}"))
                if listings:
                    sites[start,pos] = listings
                if ins.mnemonic in {"jmp","int3","ud2"} or ins.group(CS_GRP_RET):
                    break
                pos += ins.size
        bodies[start] = instructions
        if unresolved:
            problems[start] = unresolved
    code_dir=folder/"code"
    code_dir.mkdir(parents=True,exist_ok=True)
    listing=[]
    functions=[]
    coverage=[]
    callrows=[]
    source=["/* AMD64 Windows import veneers. Compile with Clang in GNU mode.",
            "   Each extern denotes the named eight-byte IAT slot at the indicated original RVA.",
            "   Naked tail jumps preserve the caller's arguments, return address and ABI. */"]
    entrylines={}
    src={}
    mdl=model_source.splitlines()
    for start, instructions in sorted(bodies.items()):
        slot=thunk(start)
        description = exports.get(start,imports[slot]+" import thunk" if slot else labels[start])
        first=len(listing)+1
        listing.append(f"; owner {start:#x} {description}")
        for pos,ins in sorted(instructions.items()):
            if start not in models and pos!=start and (start,pos) not in sites:
                continue
            listing.append(f"{pos:08x}  {ins.bytes.hex(' ')}  {ins.mnemonic} {ins.op_str}".rstrip())
            for category,name,note in sites.get((start,pos),[]):
                callrows.append(["native",hex(start),name,category,
                                 f"code/references.asm#L{len(listing)}",f"site {pos:#x}, {note}"])
        ref=f"code/references.asm#L{first+1}-L{len(listing)}"
        entrylines[start]=ref
        if slot is not None:
            n=len(source)+1
            source += [f"/* {start:#x} -> {imports[slot]}. */",
                       f"__attribute__((naked, used)) void thunk_{start:x}(void)",
                       "{", f'    __asm__("jmpq *iat_{slot:x}(%rip)");', "}",""]
            src[start]=f"code/import_thunks.c#L{n}-L{n+4}"
        elif start in models:
            n=mdl.index("/* "+models[start]+" begin */")+1
            last=mdl.index("/* "+models[start]+" end */")+1
            src[start]=f"code/ppexec.c#L{n}-L{last}"
        origin = "+".join(x for x,found in (("PE",start in seeds),("Ghidra",start in ghidra)) if found)
        functions.append([hex(start),description,origin or "direct transfer",
                          len(instructions),hex(bounds[start]) if start in bounds else ""])
        why="; ".join(problems.get(start,[])[:4])
        if start in src:
            state="covered"
            note="AMD64 body at original RVA; rebuilt bytes and code/data relocations compared" if start in models else f"AMD64 tail transfer through {slot:#x}"
        else:
            state="gap"
            note=f"Recover and check control flow/ABI at {start:#x}, {len(instructions)} reachable instructions"
            if start in ghidra and ghidra[start]["source"]:
                note+="; audit decompiler output "+ghidra[start]["source"]
            if why:
                note+="; "+why
        coverage.append(["native",hex(start),state,image[start:start+8].hex(),ref,src.get(start,""),note])
    write_text(code_dir/"references.asm",listing)
    write_text(code_dir/"import_thunks.c",source)
    write_table(folder/"native-functions.csv",["rva","name","origin","reachable_instructions","runtime_end"],functions)
    write_table(folder/"coverage.csv",["kind","key","state","first_bytes","listing","source","note"],coverage)
    write_table(folder/"calls.csv",["kind","caller","callee","class","listing","note"],callrows)
    write_table(folder/"control-gaps.csv",["owner_rva","observation"],
                [(hex(start),detail) for start,items in sorted(problems.items()) for detail in dict.fromkeys(items)])
    write_table(folder/"internal-transfers.csv",["owner_rva","site_rva","target_rva"],
                [(hex(owner),hex(site),hex(target)) for owner,site,target in sorted(edges)])
    target="atdms.dll!DMS_ASGOPN"
    dms=[r for r in callrows if r[2]==target]
    print("ASGOPN",dms)
    print("Counts",len(seeds),len(bounds),len(exports),len(bodies),len(src),len(callrows))
    print("DMS import",[(hex(k),n) for k,n in imports.items() if n==target])
    run=dict(original_sha256=ORIGINAL, native_reported_count=len(bodies),
             tool_version=f"Capstone {capstone.__version__}; pefile {pefile.__version__}",
             command="python recover.py <original> <submission folder containing code/ppexec.c>",
             scope="PE entry/export/runtime function seeds, any supplied Ghidra native entries, recursive direct branches/call targets and indexed PPEXEC_PHCCIN dispatch. All 21 named code exports have editable AMD64 code; import tail thunks bind to exact slots.",
             limitations="Remaining gap rows need original-level cross-checks for control flow, calls, ABI and necessary data. Runtime-function records can be fragments. Unresolved indirect branches may have additional targets. No Windows behavior/ABI test.",
             original_anchors=len(seeds),runtime_ranges=len(bounds),code_exports=len(exports),import_slots=len(imports),
             ghidra_functions=len(ghidra),ghidra_decompiled=sum(bool(x["source"]) for x in ghidra.values()),
             code_export_models=len(exports),internal_models=len(models)-len(exports),
             import_thunk_models=len(src)-len(models),declared_gaps=len(bodies)-len(src),
             indirect_sites=sum(r[3]=='unresolved' for r in callrows),
             direct_calls_to_asgopn=[r for r in dms if "via thunk" in r[-1]])
    write_text(folder/"run.json",[json.dumps(run,indent=2,ensure_ascii=False)])


if __name__=="__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    parser.add_argument("folder",type=Path)
    args=parser.parse_args()
    recover(args.original,args.folder)

