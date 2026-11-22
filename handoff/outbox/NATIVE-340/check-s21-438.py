"""Check CLR slot jumps and independently recompile the constrained tail-stub sources."""
import argparse
import csv
import hashlib
import json
import re
import runpy
import struct
import subprocess
from collections import Counter
from pathlib import Path

import capstone
import pefile

ORIGINAL = "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"
SOURCE_FORM = re.compile(
    r"\s*extern unsigned char fixup_slot_([0-9A-Fa-f]{8})\[\];\s*"
    r"__attribute__\(\(naked, used, noinline\)\) void fixup_stub_([0-9A-Fa-f]{8})\(void\)\s*"
    r'{\s*__asm__ __volatile__\("jmp \*fixup_slot_\1\(%rip\)"\);\s*}'
)
SOURCES = ("code/native-fixup-sites.c", "code/native-fixup-sites-s21.c")


def rows(path):
    with path.open(encoding="utf-8-sig",newline="") as stream:
        return list(csv.DictReader(stream))


def read_coff(obj):
    machine, count, _, sym_ptr, sym_count, optional, _ = struct.unpack_from("<HHIIIHH",obj)
    assert machine == 0x8664 and optional == 0
    labels = {}
    index = 0
    while index < sym_count:
        offset = sym_ptr + index * 18
        label=obj[offset:offset+8]
        if label[:4] == b"\0"*4:
            begin = sym_ptr + 18*sym_count + struct.unpack_from("<I",label,4)[0]
            name = obj[begin:obj.index(0,begin)].decode()
        else:
            name=label.rstrip(b"\0").decode()
        value, section, _, _, auxiliary = struct.unpack_from("<IhHBB",obj,offset+8)
        labels[index] = (name,value,section)
        index += 1+auxiliary
    sections = {}
    for i in range(count):
        _, _, _, size, raw, reloc, _, nrel, _, _ = struct.unpack_from("<8sIIIIIIHHI",obj,20+40*i)
        sections[i+1] = (obj[raw:raw+size], {at:(sym,kind) for at,sym,kind in
                            (struct.unpack_from("<IIH",obj,reloc+10*j) for j in range(nrel))})
    return labels, sections


def verify_stubs(unit, zig, work, original_jumps):
    results = []
    sites = set()
    for index,path in enumerate(SOURCES):
        source=unit/path
        raw=source.read_text(encoding="utf-8-sig")
        clean=re.sub(r"/\*.*?\*/","",raw,flags=re.S)
        declarations=SOURCE_FORM.findall(clean)
        assert declarations and not SOURCE_FORM.sub("",clean).strip(), path
        assert len({name for _,name in declarations}) == len(declarations)
        declared={int(name,16):int(slot,16) for slot,name in declarations}
        assert not declared.keys() & sites
        sites.update(declared)
        objpath=work/f"stubs-{index}.obj"
        subprocess.run([str(zig),"cc","-target","x86_64-windows-gnu","-O2","-c",
                        str(source),"-o",str(objpath)],check=True,capture_output=True)
        obj=objpath.read_bytes()
        labels,sections=read_coff(obj)
        matched={}
        for _,(name,off,section) in labels.items():
            if not name.startswith("fixup_stub_"):
                continue
            site=int(name.removeprefix("fixup_stub_"),16)
            slot=declared[site]
            body,reloc=sections[section]
            encoded=body[off:off+6]
            assert encoded == b"\xff\x25\x00\x00\x00\x00",name
            symbol,kind=reloc[off+2]
            target,_,defined=labels[symbol]
            assert kind == 4 and defined == 0 and int(target.removeprefix("fixup_slot_"),16) == slot
            linked=encoded[:2]+struct.pack("<i",slot-site-6)
            assert original_jumps[site][0] == linked
            matched[site]=slot
        assert declared == matched
        results.append({"path":path,"functions":len(matched),"sha256":hashlib.sha256(obj).hexdigest()})
    return results,sites


def review(original, unit, checker, zig, work):
    data=original.read_bytes()
    assert hashlib.sha256(data).hexdigest() == ORIGINAL
    records, position, image_base=runpy.run_path(str(checker))["inspect"](data)
    methods={r["key"]:r for r in records if r["kind"]=="method"}
    pe=pefile.PE(data=data)
    cli=pe.OPTIONAL_HEADER.DATA_DIRECTORY[14].VirtualAddress
    table,size=struct.unpack_from("<II",data,position(cli)+48)
    slots={}
    for offset in range(table,table+size,8):
        slot,count,flags=struct.unpack_from("<IHH",data,position(offset))
        token=struct.unpack_from("<Q",data,position(slot))[0]
        assert count == 1 and token in methods
        slots[slot]=(token,flags)
    nep=next(s for s in pe.sections if s.Name.rstrip(b"\0")==b".nep")
    decoder=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_64)
    instructions={i.address:i for i in decoder.disasm(nep.get_data()[:nep.Misc_VirtualSize],nep.VirtualAddress)}
    jumps={}
    for site,insn in instructions.items():
        raw=bytes(insn.bytes)
        if insn.mnemonic=="jmp" and raw[:2]==b"\xff\x25":
            slot=site+6+struct.unpack_from("<i",raw,2)[0]
            token,flags=slots[slot]
            jumps[site]=(raw,slot,token,flags)
    assert len(jumps)==len(slots)==237 and set(slots)=={r[1] for r in jumps.values()}

    extras=rows(unit/"code/s21-extra-sites.csv")
    assert len(extras)==111 and Counter(r["disposition"] for r in extras)=={"missing":106,"unresolved":5}
    for row in extras:
        site, pred = (int(row[k],0) for k in ("site_rva","predecessor_rva"))
        raw,slot,token,flags=jumps[site]
        assert raw.hex()==row["instruction"] and bytes(instructions[pred].bytes)==b"\xeb\x08"
        assert pred+10==site==int(row["predecessor_target"],0)
        assert [int(row[k],0) for k in ("slot_rva","method_token","flags","method_rva")]==[slot,token,flags,methods[token]["rva"]]
    calls=rows(unit/"calls.csv")
    listings={f:(unit/f).read_text(encoding="utf-8-sig").splitlines() for f in
              ("code/native-fixup-sites.asm","code/native-fixup-sites-s21.asm","code/native.asm")}
    registered={}
    for row in calls:
        match=re.fullmatch(r"(.+)#L(\d+)-L\2",row["listing"])
        if row["class"]!="boundary" or not match or match[1] not in listings:
            continue
        line=listings[match[1]][int(match[2])-1]
        address=re.match(r"\s*([0-9a-fA-F]{8})\s+",line)
        if not address or (site:=int(address[1],16)) not in jumps:
            continue
        assert site not in registered
        raw,slot,token,flags=jumps[site]
        assert raw.hex(" ").upper() in line.upper() and f"0x{image_base+slot:x}" in line.lower()
        assert int(row["caller"],0)==site
        assert all(x in row["callee"].lower() for x in (hex(slot), f"0x{token:08x}",hex(methods[token]["rva"])))
        registered[site]=row
    assert set(registered)==set(jumps)
    assert data[position(0x3660):position(0x3660)+14].hex()=="65488b042530000000488b4008c3"
    assert "PEB" not in "\n".join((unit/"code/native.c").read_text(encoding="utf-8-sig").splitlines()[1208:1214])
    work.mkdir(exist_ok=True,parents=True)
    built,source_sites=verify_stubs(unit,zig,work,jumps)
    assert sum(r["functions"] for r in built)==228
    metrics=json.loads((unit/"metrics.json").read_text(encoding="utf-8-sig"))
    return {"original_sha256":ORIGINAL,"nep_size":nep.Misc_VirtualSize,"verified_slots":len(registered),
            "methoddef_targets":len({r[2] for r in jumps.values()}),"extra_predecessors":len(extras),
            "recompiled":built,"call_table":dict(Counter(r["class"] for r in calls)),
            "metrics_fixup_edges_ok":metrics["fixup_edges_ok"],
            "metrics_fixup_edges_verified":metrics["fixup_edges_verified"],
            "remaining_targets":[{"caller":r["caller"],"callee":r["callee"],"listing":r["listing"]}
                                 for r in calls if r["class"]=="unresolved"],
            "verified_source_site_count":len(source_sites)}


if __name__=="__main__":
    parser=argparse.ArgumentParser(description=__doc__)
    for option in ("original","unit","checker","zig","work"):
        parser.add_argument(option,type=Path)
    print(json.dumps(review(**vars(parser.parse_args())),ensure_ascii=True,indent=2))
