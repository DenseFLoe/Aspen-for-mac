"""Assemble source, apply each AMD64 COFF REL32 at its original RVA and compare bytes."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import tempfile

import pefile

ORIGINAL = "d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a"
SOURCE = Path(__file__).resolve().parent / "code"


def coff_functions(obj, exports, image, bounds):
    machine, sections, _, sym_offset, count, optional, _ = struct.unpack_from("<HHIIIHH", obj)
    if (machine, optional) != (0x8664, 0):
        raise ValueError("expected AMD64 COFF")
    symbols = {}
    index = 0
    while index < count:
        pos = sym_offset+index*18
        name = obj[pos:pos+8]
        if not any(name[:4]):
            offset = sym_offset+18*count+struct.unpack_from("<I",name,4)[0]
            name = obj[offset:obj.index(0,offset)]
        value, sec, typ, _, aux = struct.unpack_from("<IhHBB",obj,pos+8)
        symbols[index] = (name.rstrip(b"\0").decode("ascii"),value,sec,typ)
        index += 1+aux
    result = []
    for index in range(sections):
        name, _, _, size, raw, rel, _, nrel, _, _ = struct.unpack_from("<8sIIIIIIHHI",obj,20+40*index)
        if name.rstrip(b"\0") != b".text":
            continue
        text = obj[raw:raw+size]
        relocs = [struct.unpack_from("<IIH",obj,rel+10*i) for i in range(nrel)]
        funcs = [(val,n) for n,val,sec,typ in symbols.values() if sec == index+1 and typ==32]
        consumed = set()
        for offset,name in sorted(funcs):
            if name.startswith("thunk_"):
                rva = int(name.removeprefix("thunk_"),16)
                length = 6
            elif name.startswith("internal_"):
                rva = int(name.removeprefix("internal_"),16)
                length = bounds[rva]-rva
            else:
                rva = exports[name]
                length = bounds.get(rva, rva+12)-rva
            body = bytearray(text[offset:offset+length])
            relocated = []
            for pos, target_idx, typ in relocs:
                if not offset<=pos<offset+length:
                    continue
                target = symbols[target_idx][0]
                if not target.startswith(("iat_","rva_")) or not 4<=typ<=9:
                    raise ValueError(f"bad relocation {typ}: {target}")
                dest = int(target.split("_")[1],16)
                loc = pos-offset
                extra = typ-4
                addend = struct.unpack_from("<i",body,loc)[0]
                struct.pack_into("<i",body,loc,dest+addend-(rva+loc+4+extra))
                consumed.add(pos)
                relocated.append((hex(rva+loc),target))
            expected = image[rva:rva+length]
            if body != expected:
                first = next(i for i,(a,b) in enumerate(zip(body,expected)) if a!=b)
                raise ValueError(f"{name} mismatch at {rva+first:#x}: {body.hex()} vs {expected.hex()}")
            result.append(dict(name=name,rva=hex(rva),bytes=length,
                               sha256=hashlib.sha256(body).hexdigest(),relocations=relocated))
        if len(consumed)!=nrel:
            raise ValueError("relocations outside compared bodies")
    return result


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original",type=Path)
    parser.add_argument("compiler",type=Path,help="clang, or zig with its cc driver")
    args=parser.parse_args()
    data=args.original.read_bytes()
    if hashlib.sha256(data).hexdigest()!=ORIGINAL:
        raise ValueError("original SHA-256 mismatch")
    pe=pefile.PE(data=data)
    image=pe.get_memory_mapped_image()
    exports={e.name.decode():e.address for e in pe.DIRECTORY_ENTRY_EXPORT.symbols if e.name}
    bounds={r.struct.BeginAddress:r.struct.EndAddress for r in pe.DIRECTORY_ENTRY_EXCEPTION}
    rows=[]
    with tempfile.TemporaryDirectory() as temp:
        for src in ("ppexec.c","import_thunks.c"):
            command=[str(args.compiler.resolve())]
            if args.compiler.stem.lower()=="zig":
                command.append("cc")
            obj=Path(temp)/(src+".obj")
            command+=["-target","x86_64-windows-gnu","-O2","-g0","-fno-stack-protector",
                      "-fno-asynchronous-unwind-tables","-c",str(SOURCE/src),"-o",str(obj)]
            subprocess.run(command,check=True)
            rows+=coff_functions(obj.read_bytes(),exports,image,bounds)
    assert len({r["rva"] for r in rows})==len(rows)
    print(json.dumps(dict(original_sha256=ORIGINAL, bodies=len(rows),
                          bytes=sum(r["bytes"] for r in rows),
                          relocations=sum(len(r["relocations"]) for r in rows),
                          matches=rows),indent=2))


if __name__=="__main__":
    main()

