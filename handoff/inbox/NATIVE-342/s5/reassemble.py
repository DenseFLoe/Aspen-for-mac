"""Assemble certified bodies, apply COFF REL32 relocations, compare the pinned PE."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import tempfile

import pefile

ORIGINAL = "ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b"
ROOT = Path(__file__).resolve().parent


def compile_bodies(source, compiler, obj):
    command = [str(compiler.resolve())]
    if compiler.stem.lower() == "zig":
        command.append("cc")
    command.extend(["-target", "x86_64-windows-gnu", "-O2", "-g0", "-fno-stack-protector",
                    "-fno-asynchronous-unwind-tables", "-c", str(source), "-o", str(obj)])
    subprocess.run(command, check=True, capture_output=True)


def compare(obj, image, lengths):
    machine, nsec, _, syms, count, optional, _ = struct.unpack_from("<HHIIIHH", obj)
    if (machine, optional) != (0x8664, 0):
        raise ValueError("Expected an AMD64 COFF object")
    entries = {}
    index = 0
    while index < count:
        pos = syms + index * 18
        name = obj[pos:pos+8]
        if not any(name[:4]):
            start = syms + count * 18 + struct.unpack_from("<I", name, 4)[0]
            name = obj[start:obj.index(0, start)]
        value, sec, typ, _, aux = struct.unpack_from("<IhHBB", obj, pos + 8)
        entries[index] = (name.rstrip(b"\0").decode("ascii"), value, sec, typ)
        index += 1 + aux
    result = {}
    for section in range(nsec):
        name, _, _, size, raw, reloc, _, nrel, _, _ = struct.unpack_from("<8sIIIIIIHHI", obj, 20+40*section)
        if name.rstrip(b"\0") != b".text":
            continue
        text = obj[raw:raw+size]
        relocations = [struct.unpack_from("<IIH", obj, reloc + 10*i) for i in range(nrel)]
        funcs = sorted((offset,int(label[4:],16)) for label,offset,sec,typ in entries.values()
                       if sec == section+1 and typ == 32 and re.fullmatch("apw_[0-9a-f]+", label))
        for i,(offset,rva) in enumerate(funcs):
            span = lengths[rva]
            next_offset = funcs[i+1][0] if i+1<len(funcs) else size
            body = bytearray(text[offset:min(next_offset,offset+span)])
            targets = []
            for loc,idx,typ in relocations:
                if not offset <= loc < next_offset:
                    continue
                sym = entries[idx][0]
                if not re.fullmatch("rva_[0-9a-f]+",sym) or not 4 <= typ <= 9:
                    raise ValueError(f"Unexpected relocation {typ} to {sym}")
                loc -= offset
                if loc+4 > len(body):
                    body.clear()
                    break
                dest = int(sym[4:],16)
                addend = struct.unpack_from("<i",body,loc)[0]
                struct.pack_into("<i",body,loc,dest+addend-(rva+loc+4+(typ-4)))
                targets.append([hex(rva+loc),hex(dest),typ])
            if body == image[rva:rva+span]:
                result[rva] = {"rva":hex(rva),"bytes":span,"sha256":hashlib.sha256(body).hexdigest(),
                               "relocations":targets}
    return result


def main():
    cmd = argparse.ArgumentParser(description=__doc__)
    cmd.add_argument("original",type=Path)
    cmd.add_argument("compiler",type=Path)
    args = cmd.parse_args()
    data = args.original.read_bytes()
    if hashlib.sha256(data).hexdigest() != ORIGINAL:
        raise ValueError("Original SHA-256 differs")
    image = pefile.PE(data=data).get_memory_mapped_image()
    source = ROOT / "code" / "verified.c"
    spans = {int(a,16):int(b,16)-int(a,16) for a,b in
             re.findall(r"/\* body (0x[0-9a-f]+) until (0x[0-9a-f]+) \*/",source.read_text())}
    with tempfile.TemporaryDirectory() as directory:
        obj = Path(directory)/"verified.obj"
        compile_bodies(source,args.compiler,obj)
        matches = compare(obj.read_bytes(),image,spans)
    if not spans or matches.keys() != spans.keys():
        raise ValueError(f"Unmatched code sections: {sorted(spans.keys()-matches.keys())}")
    print(json.dumps({"original_sha256":ORIGINAL,"bodies":len(matches),
                      "bytes":sum(x["bytes"] for x in matches.values()),
                      "relocations":sum(len(x["relocations"]) for x in matches.values()),
                      "matches":[matches[k] for k in sorted(matches)]},indent=2))


if __name__ == "__main__":
    main()
