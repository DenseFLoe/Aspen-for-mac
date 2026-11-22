"""Check the PPEXEC_PPROY data symbol across its producer and an independently pinned consumer."""
import argparse
import hashlib
import json
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_MEM, X86_REG_RIP
import pefile


def check_image(path, expected):
    raw = path.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == expected
    return pefile.PE(data=raw)


def verify(producer, consumer):
    source_hash = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
    client_hash = "09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b"
    source = check_image(producer, source_hash)
    client = check_image(consumer, client_hash)
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    md.detail = True

    def at(pe, pos):
        return next(md.disasm(pe.get_data(pos, 15), pos, count=1))

    def target(i):
        return next(i.address+i.size+op.mem.disp for op in i.operands
                    if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP)

    exports = {s.name: s.address for s in source.DIRECTORY_ENTRY_EXPORT.symbols}
    slot = next(s.address-client.OPTIONAL_HEADER.ImageBase for d in client.DIRECTORY_ENTRY_IMPORT
                if d.dll.lower() == b"ppexec.dll" for s in d.imports if s.name == b"PPEXEC_PPROY")
    assert target(at(source,0x7b4c)) == exports[b"PPEXEC_PPROY"] == 0x21f60
    assert target(at(client,0x9327)) == slot == 0x19308
    checks = [(source,0x7b4a,"xor eax, eax"),(source,0x7b60,"mov qword ptr [rax + rcx], r12"),
              (source,0x7b64,"add rax, 8"),(source,0x7b68,"cmp rax, 0x48"),(source,0x7b6c,"jne 0x7b60"),
              (client,0x932e,"movsd xmm0, qword ptr [rax]"),(client,0x9360,"mulsd xmm0, xmm2")]
    for pe, pos, expected in checks:
        i = at(pe,pos)
        assert i.mnemonic + " " + i.op_str == expected
    interval = list(md.disasm(client.get_data(0x9327,0x9364-0x9327),0x9327))
    assert interval[-1].address == 0x9360
    assert not any(i.reg_name(r) == "xmm0" for i in interval if 0x932e<i.address<0x9360 for r in i.regs_access()[1])
    return {"producer_sha256": source_hash,"consumer_sha256":client_hash,
            "symbol":"ppexec.dll!PPEXEC_PPROY","producer_export_rva":hex(exports[b"PPEXEC_PPROY"]),
            "producer_store_offsets":list(range(0,0x48,8)),"producer_store_width":8,
            "consumer":"zedstwu.dll!DSWU_UDL01I","consumer_iat_rva":hex(slot),
            "consumer_load_rva":"0x932e","consumer_arithmetic_rva":"0x9360",
            "result":"The first field is read and multiplied as binary64. The producer writes 72 consecutive bytes. Total object extent and the types of the remaining fields require declarations or additional consumers."}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("producer",type=Path)
    parser.add_argument("consumer",type=Path)
    args = parser.parse_args()
    print(json.dumps(verify(args.producer,args.consumer),indent=2))
