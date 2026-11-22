"""Build the five original-format AMD64 COFF members and their Microsoft archive."""
import argparse
import hashlib
import json
import re
import struct
import subprocess
import tempfile
from pathlib import Path

HERE = Path(__file__).resolve().parent
FIXUP = {"ADDR64": 1, "ADDR32NB": 3, "REL32": 4, "REL32_1": 5,
         "REL32_4": 8, "SECTION": 10, "SECREL": 11}


def read_json(suffix):
    return json.loads((HERE / ("libatdll.lib." + suffix + ".json")).read_text("utf-8"))


def decimal_field(number, width):
    return str(number).encode("ascii").ljust(width)


def zstring(name):
    return name.encode("ascii") + b"\0"


def read_assembly(path):
    """Read named GNU as subsections, symbol positions and unresolved references."""
    obj = path.read_bytes()
    machine, count, _, sympos, nsyms, optlen, _ = struct.unpack_from("<HHIIIHH", obj)
    if machine != 0x8664 or optlen:
        raise ValueError("GNU as must target AMD64 Windows COFF")
    strings = obj[sympos + nsyms * 18:]
    symbols = {}
    positions = {}
    i = 0
    while i < nsyms:
        field, value, section, _, _, naux = struct.unpack_from("<8sIhHBB", obj, sympos + i * 18)
        if field[:4] == bytes(4):
            off = int.from_bytes(field[4:], "little")
            name = strings[off:strings.index(0, off)].decode("ascii")
        else:
            name = field.rstrip(b"\0").decode("ascii")
        symbols[i] = name
        positions[name] = section, value
        i += 1 + naux

    sections = {}
    for i in range(count):
        offset = 20 + i * 40
        field = obj[offset:offset + 8].rstrip(b"\0").decode("ascii")
        if not re.fullmatch(r"a\d+", field):
            continue
        number = int(field[1:])
        size, start, relptr, _, nrel = struct.unpack_from("<IIIIH", obj, offset + 16)
        sec, end = positions[f"end_{number}"]
        if sec != i + 1 or end > size or positions[f"begin_{number}"] != (sec, 0):
            raise ValueError(f"assembly bounds for {field}")
        body = bytearray(obj[start:start + end])
        relocs = []
        for j in range(nrel):
            addr, symid, assembler_type = struct.unpack_from("<IIH", obj, relptr + j * 10)
            target = symbols[symid]
            matched = re.fullmatch(r"R(\d+)_(\w+?)_S(\d+)_(\w+)", target)
            if not matched:
                raise ValueError(f"unmapped relocation {target}")
            dest_type, spelling, original_symbol, short_name = matched.groups()
            dest_type = int(dest_type)
            if FIXUP[spelling] != dest_type:
                raise ValueError(f"relocation spelling {target}")
            # GAS represents REL32_n as REL32 with a negative trailing-byte bias.
            # Address expressions embedded in SIB instructions can use ADDR32 for RVA.
            allowed = {1: {1}, 3: {2, 3, 17}, 4: {4}, 5: {4}, 8: {4}}
            if assembler_type not in allowed[dest_type]:
                raise ValueError(f"unexpected assembler relocation {assembler_type} for {target}")
            if dest_type in (5, 8):
                value = struct.unpack_from("<i", body, addr)[0]
                struct.pack_into("<i", body, addr, value + dest_type - 4)
            relocs.append((addr, int(original_symbol), dest_type, short_name))
        sections[number] = (bytes(body), relocs)
    return sections, {name: value for name, (_, value) in positions.items()}


def codeview_section(info):
    data = bytearray(struct.pack("<I", info["signature"]))
    if "pdb" in info:
        payload = (bytes.fromhex(info["type_server_guid"]) + struct.pack("<I", info["age"])
                   + zstring(info["pdb"]) + bytes.fromhex(info["record_tail"]))
        data += struct.pack("<HH", len(payload) + 2, 0x1515) + payload
        return bytes(data)
    for block in info["subsections"]:
        if "symbols" in block:
            body = bytearray()
            for kind, payload in block["symbols"]:
                record = bytes.fromhex(payload)
                body += struct.pack("<HH", len(record) + 2, int(kind, 16)) + record
        elif "strings" in block:
            body = b"\0".join(s.encode("latin1") for s in block["strings"])
        else:
            body = bytes.fromhex(block["data"])
        data += struct.pack("<II", int(block["kind"], 16), len(body)) + body
        data += bytes.fromhex(block["padding"])
    return bytes(data)


def string_table(names):
    data = bytearray()
    offsets = {}
    for name in names:
        offsets[name] = 4 + len(data)
        data += zstring(name)
    return struct.pack("<I", len(data) + 4) + data, offsets


def symbol_table(symbols, sections, positions, offsets):
    body = bytearray()
    for sym in symbols:
        index = len(body) // 18
        if sym.get("long_name"):
            field = struct.pack("<II", 0, offsets[sym["name"]])
        else:
            field = sym["name"].encode("ascii")
            if len(field) > 8:
                raise ValueError(f"short COFF symbol #{index}")
        aux = b""
        if "weak" in sym:
            aux = struct.pack("<II10x", *sym["weak"])
        if "section_aux" in sym:
            a = sym["section_aux"]
            length, nrel = sections[sym["section"] - 1]
            aux = struct.pack("<IHHIhBBh", length, nrel, 0, int(a["checksum"], 16),
                              a["association"], a["selection"], 0, 0)
        value = positions.get(f"symbol_{index}", sym["value"])
        body += struct.pack("<8sIhHBB", field, value, sym["section"], sym["type"],
                            sym["class"], int(bool(aux))) + aux
    return body


def make_member(assembler, temp, model, debug):
    assembly = HERE / model["assembly"]
    intermediate = temp / (assembly.stem + ".obj")
    subprocess.run([assembler, "--64", "-o", str(intermediate), str(assembly)], check=True)
    assembled, positions = read_assembly(intermediate)
    headers = bytearray()
    bodies = bytearray()
    sizes = []
    digests = []
    sections = model["sections"]
    first = 20 + 40 * len(sections)
    symbol_names = {}
    for sym in model["symbols"]:
        idx = len(symbol_names)
        symbol_names[idx] = sym["name"]
        if "section_aux" in sym or "weak" in sym:
            symbol_names[idx + 1] = None
    for i, section in enumerate(sections, start=1):
        name = section["name"]
        fixups = []
        if "uninitialized" in section:
            data = b""
            size = section["uninitialized"]
        elif "debug" in section:
            data = codeview_section(debug[section["debug"]])
            size = len(data)
            fixups = [(pos, symbol, FIXUP[kind]) for pos, kind, symbol in section.get("fixups", [])]
        elif name == ".chks64":
            if i != len(sections):
                raise ValueError("expected the per-section digest table last")
            data = b"".join(digests + [bytes(8)])
            size = len(data)
        else:
            data, refs = assembled[i]
            size = len(data)
            for pos, sym, kind, tag in refs:
                decoded = re.sub("[^a-zA-Z0-9_]+", "_", symbol_names[sym]).strip("_")[:95] or "member"
                if decoded != tag:
                    raise ValueError(f"check the symbol index for {tag}")
                fixups.append((pos, sym, kind))
        digests.append(hashlib.sha256(data).digest()[:8] if data else bytes(8))
        raw_at = first + len(bodies) if data else 0
        bodies += data
        reloc_at = first + len(bodies) if fixups else 0
        for pos, symbol, kind in sorted(fixups):
            bodies += struct.pack("<IIH", pos, symbol, kind)
        headers += struct.pack("<8sIIIIIIHHI", name.encode("ascii"), 0, 0, size, raw_at,
                               reloc_at, 0, len(fixups), 0, int(section["flags"], 16))
        sizes.append((size, len(fixups)))
    strings, offsets = string_table(model["strings"])
    symbols = symbol_table(model["symbols"], sizes, positions, offsets)
    header = struct.pack("<HHIIIHH", 0x8664, len(sections), model["timestamp"],
                         first + len(bodies), len(symbols) // 18, 0, 0)
    return header + headers + bodies + symbols + strings


def archive_record(name, data, timestamp, mode):
    header = (name.encode("ascii").ljust(16) + decimal_field(timestamp, 12)
              + b" " * 12 + decimal_field(mode, 8) + decimal_field(len(data), 10) + b"\x60\n")
    return header + data + (b"\n" if len(data) & 1 else b"")


def archive(models, objects):
    longnames = bytearray()
    labels = []
    exports = {}
    for i, model in enumerate(models):
        labels.append(f"/{len(longnames)}")
        longnames += zstring(model["member"])
        for sym in model["symbols"]:
            if sym["class"] == 2 and sym["section"] > 0:
                exports.setdefault(sym["name"], i)
    first = sorted(exports, key=lambda s: (exports[s], s))
    second = sorted(exports)
    def indices(addresses):
        a = bytearray(struct.pack(">I", len(first)))
        for n in first:
            a += struct.pack(">I", addresses[exports[n]])
        a += b"".join(map(zstring, first))
        b = bytearray(struct.pack("<I", len(objects)))
        for addr in addresses:
            b += struct.pack("<I", addr)
        b += struct.pack("<I", len(second))
        for n in second:
            b += struct.pack("<H", exports[n] + 1)
        b += b"".join(map(zstring, second))
        return a, b
    def index_records(addresses):
        a, b = indices(addresses)
        timestamp = 1744402947
        return b"".join(archive_record(n, d, timestamp, 0)
                        for n, d in (("/", a), ("/", b), ("//", longnames)))
    prefix = b"!<arch>\n"
    offset = len(prefix) + len(index_records([0] * len(objects)))
    addresses, parts = [], []
    for label, obj, model in zip(labels, objects, models):
        addresses.append(offset)
        part = archive_record(label, obj, model["timestamp"], 100666)
        parts.append(part)
        offset += len(part)
    return prefix + index_records(addresses) + b"".join(parts)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--as", dest="assembler", default="as", help="Windows AMD64 GNU as")
    parser.add_argument("--out", type=Path, required=True, help="new archive output path")
    parser.add_argument("--temp", type=Path, help="existing parent directory for temporary assembly files")
    args = parser.parse_args()
    models = read_json("coff")
    debug = read_json("codeview")
    with tempfile.TemporaryDirectory(dir=args.temp) as d:
        objects = [make_member(args.assembler, Path(d), m, debug[m["member"]]) for m in models]
    result = archive(models, objects)
    with args.out.open("xb") as stream:
        stream.write(result)
    print(f"{hashlib.sha256(result).hexdigest()}  {args.out}  ({len(result)} bytes)")


if __name__ == "__main__":
    main()