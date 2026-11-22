"""Check both sides of the PPEXEC_PPROY data import and survey known incoming stub references."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

import capstone as cs
from capstone.x86 import X86_OP_IMM,X86_OP_MEM,X86_REG_RIP
import pefile


def run(consumer,provider,original_listing):
    inputs=[(consumer,'09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b'),
            (provider,'d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a'),
            (original_listing,'fdce8c9db94517169eebc1104dc1a05f595cdf28425ba0027494ed8df0bdda6a')]
    for path,digest in inputs:
        assert hashlib.sha256(path.read_bytes()).hexdigest()==digest
    pe=pefile.PE(str(consumer));supplier=pefile.PE(str(provider))
    data=pe.get_memory_mapped_image();base=pe.OPTIONAL_HEADER.ImageBase
    symbol=next(s for s in supplier.DIRECTORY_ENTRY_EXPORT.symbols if s.name==b'PPEXEC_PPROY')
    section=supplier.get_section_by_rva(symbol.address)
    assert section.Name.rstrip(b'\0')==b'.data' and not section.IMAGE_SCN_MEM_EXECUTE
    iat=next(s.address-base for mod in pe.DIRECTORY_ENTRY_IMPORT if mod.dll.lower()==b'ppexec.dll'
             for s in mod.imports if s.name==symbol.name)
    assert iat==0x19308
    entries={0x180c0}
    for line in original_listing.read_text(encoding='utf-8-sig').splitlines():
        m=re.match(r'^  ([a-fA-F0-9]+):\s+(.+)',line)
        if m:
            site=int(m[1],16)-base
            if site==0x15bda or not re.match(r'align\b|d[bwdq]\b',m[2],re.I):
                entries.add(site)
    decoder=cs.Cs(cs.CS_ARCH_X86,cs.CS_MODE_64);decoder.detail=True
    stub=0x153ca
    references=[];incoming=[];reads=[]
    for site in sorted(entries):
        i=next(decoder.disasm(data[site:site+15],site,count=1))
        if (i.group(cs.CS_GRP_JUMP) or i.group(cs.CS_GRP_CALL)) and i.operands[0].type==X86_OP_IMM and i.operands[0].imm==stub:
            incoming.append([hex(site),i.mnemonic])
        for o in i.operands:
            if o.type==X86_OP_MEM and o.mem.base==X86_REG_RIP:
                target=i.address+i.size+o.mem.disp
                if target==stub:
                    references.append([hex(site),i.mnemonic])
                if target==iat:
                    reads.append([hex(site),i.mnemonic,i.op_str])
    ptrs=[hex(e.rva) for block in pe.DIRECTORY_ENTRY_BASERELOC for e in block.entries
          if e.type==10 and struct.unpack_from('<Q',data,e.rva)[0]==base+stub]
    assert len(entries)==14091
    assert [r[0] for r in reads]==['0x9327','0x153ca']
    trace=[[hex(i.address),i.bytes.hex(),i.mnemonic,i.op_str] for i in decoder.disasm(data[0x9327:0x933a],0x9327)]
    assert [x[2] for x in trace]==['mov','movsd','movsd'] and trace[1][3]=='xmm0, qword ptr [rax]'
    dst=next(decoder.disasm(data[0x9332:0x9341],0x9332)).operands[0]
    assert dst.mem.disp+0x933a==0x22840
    return dict(consumer_sha256=inputs[0][1],provider_sha256=inputs[1][1],legacy_asm_sha256=inputs[2][1],
                symbol=symbol.name.decode(),provider_export_rva=hex(symbol.address),provider_section='.data',
                provider_section_executable=False,consumer_iat=hex(iat),consumer_double_load_and_store=trace,
                directly_referenced_destination='0x22840',iat_instruction_sites=reads,
                consumer_import_stub=hex(stub),consumer_decoded_instruction_sites=len(entries),
                direct_call_or_jump_to_stub=incoming,rip_relative_refs_to_stub=references,
                relocated_absolute_pointers_to_stub=ptrs,
                stub_is_export=any(s.address==stub for s in pe.DIRECTORY_ENTRY_EXPORT.symbols),
                stub_is_unwind_entry=any(e.struct.BeginAddress==stub for e in pe.DIRECTORY_ENTRY_EXCEPTION))


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    for k in ('consumer','provider','original_listing'):
        p.add_argument(k,type=Path)
    p.add_argument('--output',type=Path)
    args=p.parse_args(); result=json.dumps(run(args.consumer,args.provider,args.original_listing),indent=2)+'\n'
    if args.output:
        args.output.write_bytes(result.encode())
    else:
        print(result,end='')
