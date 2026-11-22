"""Build the editable nl2sol x64 library with Python 3 and an x86_64-w64-mingw32 GNU as."""
import argparse
from pathlib import Path, PureWindowsPath
import json
import re
import struct
import subprocess
import tempfile
import zlib

SOURCE = Path(__file__).resolve().parent
pack = struct.pack
unpack = struct.unpack_from


def symbol_label(prefix, index, name):
    safe = re.sub("[^a-zA-Z0-9_]", "_", name).strip("_") or "symbol"
    return f"{prefix}_{index}_{safe}"


def read_gas_object(data):
    """Read symbol positions, section payloads and linker fixups produced by GAS."""
    _, nsec, _, sym_at, count, _, _ = unpack("<HHIIIHH", data)
    strings = data[sym_at + 18*count:]
    symbols = {}
    positions = {}
    idx = 0
    while idx < count:
        name, value, sec, _, _, aux = unpack("<8sIhHBB", data, sym_at + 18*idx)
        if name[:4] == bytes(4):
            pos = unpack("<I", name, 4)[0]
            name = strings[pos:strings.index(0, pos)]
        name = name.rstrip(b"\0").decode("ascii")
        symbols[idx] = name
        positions[name] = (sec, value)
        idx += 1 + aux
    sections = {}
    for i in range(nsec):
        name, _, _, size, pos, reloc_at, _, nr, _, _ = unpack("<8sIIIIIIHHI",data,20+40*i)
        relocs = []
        for j in range(nr):
            at, target, kind = unpack("<IIH", data, reloc_at+10*j)
            relocs.append((at, symbols[target], kind))
        sections[name.rstrip(b"\0").decode("ascii")] = (i+1, data[pos:pos+size], relocs)
    return sections, positions


def declarations(rows):
    result = []
    idx = 0
    for name, sec, kind, storage, *options in rows:
        info = options[0] if options else None
        aux = (isinstance(info, int) or isinstance(info, str))
        common_size = info["common_size"] if isinstance(info, dict) else 0
        result.append((idx, name, sec, kind, storage, info, aux, common_size))
        idx += 1 + int(aux)
    return result


def intel_coff(config, assembled):
    sections, positions = read_gas_object(assembled)
    defs = declarations(config["symbols"])
    index = {symbol_label("ref", i, name): i for i,name,*_ in defs}
    # GAS cannot express distinct COFF sections with identical names and arbitrary
    # Intel COMDAT/auxiliary records. Use its real bytes and relocations under the
    # original section identities. End labels remove GAS's implicit trailing alignment.
    headers = bytearray()
    contents = bytearray()
    sec_stats = {}
    section_numbers = {}
    data_start = 20 + 40*len(config["sections"])
    for n, (name, flags) in enumerate(config["sections"], 1):
        gas_num, data, relocs = sections[f".s{n}"]
        section_numbers[n] = gas_num
        end_num, size = positions[f"end_s{n}"]
        if end_num != gas_num or size > len(data):
            raise ValueError(f"Invalid end label in section {n}")
        data = data[:size]
        bss = name == ".bss"
        if bss and any(data):
            raise ValueError("Initialized data in .bss")
        raw_at = 0 if bss else data_start + len(contents)
        if not bss:
            contents.extend(data)
        reloc_at = data_start + len(contents) if relocs else 0
        for at, target, kind in relocs:
            if kind == 2 and name in (".pdata", ".rdata"):
                # GNU as .long gives ADDR32. Runtime-function fields are image RVAs.
                # The switch slots carry the explicitly declared REL32-based addends.
                kind = 3 if name == ".pdata" else 4
            elif (name,kind) != (".text",4):
                raise ValueError(f"Unexpected COFF relocation {name} {kind}")
            if at+4 > size:
                raise ValueError("Fixup outside member section")
            contents.extend(pack("<IIH", at, index[target], kind))
        headers.extend(pack("<8sIIIIIIHHI", name.encode(), 0,0,size,raw_at,
                            reloc_at,0,len(relocs),0,int(flags,16)))
        crc = zlib.crc32(data, 0xffffffff) ^ 0xffffffff
        sec_stats[n] = size, len(relocs), crc

    strings = bytearray(4)
    for value in config["strings"]:
        strings.extend(value.encode()+b"\0")
    symtab = bytearray()
    exports = []
    for idx, name, sec, kind, storage, info, aux, common_size in defs:
        if sec > 0:
            gas_num, value = positions[symbol_label("def", idx, name)]
            if gas_num != section_numbers[sec]:
                raise ValueError(f"Definition {name} moved to an undeclared section")
        else:
            value = common_size
        if storage == 2 and (sec > 0 or common_size):
            exports.append(name)
        nameb = name.encode()
        if len(nameb) > 8:
            ptr = strings.find(nameb+b"\0",4)
            if ptr < 0:
                ptr = len(strings)
                strings.extend(nameb+b"\0")
            nameb = pack("<II",0,ptr)
        symtab.extend(pack("<8sIhHBB",nameb,value,sec,kind,storage,int(aux)))
        if aux and isinstance(info,str):
            symtab.extend(pack("<18s",info.encode()))
        elif aux:
            size, nr, crc = sec_stats[sec]
            symtab.extend(pack("<IHHIhBBh",size,nr,0,crc,sec,info,0,0))
    struct.pack_into("<I",strings,0,len(strings))
    header = pack("<HHIIIHH",0x8664,len(config["sections"]),0,data_start+len(contents),
                  len(symtab)//18,0,0)
    return header + headers + contents + symtab + strings, sorted(exports)


def ar_member(name, timestamp, mode, data):
    header = f"{name:<16}{timestamp:<12}{'':12}{mode:<8}{len(data):<10}" + chr(96) + "\n"
    return header.encode("ascii") + data + (b"\n" if len(data)%2 else b"")


def archive(config, objects):
    entries = []
    names = bytearray()
    owners = {}
    for i, ((data,exports), m) in enumerate(zip(objects,config["members"])):
        name_at = len(names)
        names.extend(m["path"].encode()+b"\0")
        entries.append(ar_member(f"/{name_at}",m["timestamp"],"100666",data))
        for name in exports:
            owners.setdefault(name,i)
    ordered = sorted(owners)
    timestamp = config["index_timestamp"]
    names_record = ar_member("//",timestamp,"0",names)

    def indexes(offsets):
        first = bytearray(pack(">I",len(owners)))
        second = bytearray(pack("<I",len(entries)))
        for i in owners.values():
            first.extend(pack(">I",offsets[i]))
        for offset in offsets:
            second.extend(pack("<I",offset))
        second.extend(pack("<I",len(ordered)))
        for n in ordered:
            second.extend(pack("<H",owners[n]+1))
        first.extend(b"".join(n.encode()+b"\0" for n in owners))
        second.extend(b"".join(n.encode()+b"\0" for n in ordered))
        return ar_member("/",timestamp,"0",first)+ar_member("/",timestamp,"0",second)
    offsets = []
    location = 8 + len(indexes([0]*len(entries))) + len(names_record)
    for entry in entries:
        offsets.append(location)
        location += len(entry)
    return b"!<arch>\n" + indexes(offsets) + names_record + b"".join(entries)


def build(assembler, out, work):
    config = json.loads((SOURCE/"nl2sol.lib.layout.json").read_text(encoding="utf8"))
    source = (SOURCE/"nl2sol.lib.s").read_text(encoding="utf8")
    chunks = re.split(r"^# MEMBER ([\w.-]+)\n", source, flags=re.MULTILINE)
    members = config["members"]
    if chunks[1::2] != [PureWindowsPath(m["path"]).name for m in members]:
        raise ValueError("Assembly members differ from the COFF declarations")
    compiled = []
    for name, asm, m in zip(chunks[1::2],chunks[2::2],members):
        input_path = work/(name+".s")
        obj_path = work/(name+".gas.obj")
        input_path.write_text(asm,encoding="ascii")
        subprocess.run([assembler,"--64","-o",str(obj_path),str(input_path)],check=True)
        result = intel_coff(m, obj_path.read_bytes())
        (work/name).write_bytes(result[0])
        compiled.append(result)
    out.write_bytes(archive(config,compiled))


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--assembler",default="x86_64-w64-mingw32-as")
    parser.add_argument("--output",type=Path,required=True)
    parser.add_argument("--work",type=Path,help="retain individual COFF objects in this directory")
    opts = parser.parse_args()
    if opts.work:
        opts.work.mkdir(parents=True,exist_ok=True)
        build(opts.assembler,opts.output,opts.work)
    else:
        with tempfile.TemporaryDirectory() as tmp:
            build(opts.assembler,opts.output,Path(tmp))

