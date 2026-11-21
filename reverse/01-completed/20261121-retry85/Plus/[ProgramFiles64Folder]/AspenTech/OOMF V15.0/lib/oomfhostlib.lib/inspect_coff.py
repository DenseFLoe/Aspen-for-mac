import argparse
import hashlib
import json
from pathlib import Path, PureWindowsPath
import struct


def read_string(data, offset):
    return data[offset:data.index(b"\0", offset)].decode("ascii")


def read_strings(data, offset, count):
    strings = []
    for _ in range(count):
        end = data.index(b"\0", offset)
        strings.append(data[offset:end].decode("ascii"))
        offset = end + 1
    assert not any(data[offset:])
    return strings


def parse_object(data):
    machine, section_count, stamp, table, count, optional, flags = struct.unpack_from("<HHIIIHH", data)
    assert machine == 0x8664 and optional == 0
    strings = data[table + count * 18:]
    assert struct.unpack_from("<I", strings)[0] == len(strings)
    symbols = {}
    i = 0
    while i < count:
        pos = table + i * 18
        raw_name, value, section, kind, storage, aux = struct.unpack_from("<8sIhHBB", data, pos)
        name = (read_string(strings, struct.unpack_from("<I", raw_name, 4)[0])
                if raw_name[:4] == b"\0" * 4 else raw_name.rstrip(b"\0").decode("ascii"))
        records = [data[pos + j * 18:pos + (j + 1) * 18].hex() for j in range(1, aux + 1)]
        symbols[i] = dict(name=name, value=value, section=section, type=kind, storage=storage, aux=records)
        i += 1 + aux
    assert i == count
    sections = []
    for i in range(section_count):
        short, _, _, size, raw, reloc, _, reloc_count, line_count, characteristics = struct.unpack_from(
            "<8s6IHHI", data, 20 + 40 * i)
        name = short.rstrip(b"\0").decode("ascii")
        if name.startswith("/"):
            name = read_string(strings, int(name[1:]))
        assert line_count == 0 and (not raw or raw + size <= table)
        assert not reloc_count or reloc + 10 * reloc_count <= table
        contents = data[raw:raw + size] if raw else b""
        entries = []
        for j in range(reloc_count):
            offset, symbol, kind = struct.unpack_from("<IIH", data, reloc + 10 * j)
            assert offset < size
            entries.append(dict(offset=offset, symbol_index=symbol, symbol=symbols[symbol]["name"], type=kind))
        sections.append(dict(index=i+1, name=name, size=size, flags=hex(characteristics), raw_offset=raw,
                             data=contents.hex(), relocations=entries))
    return dict(machine=hex(machine), timestamp=stamp, flags=hex(flags), symbol_count=count,
                symbols=symbols, sections=sections)


def parse_archive(data, extract):
    assert data[:8] == b"!<arch>\n"
    offset = 8
    link = []
    longnames = None
    objects = []
    while offset < len(data):
        header = data[offset:offset + 60]
        assert len(header) == 60 and header[58:] == b"`\n"
        tag = header[:16].strip().decode("ascii")
        size = int(header[48:58])
        member = data[offset + 60:offset + 60 + size]
        assert len(member) == size
        if tag == "/":
            link.append(member)
        elif tag == "//":
            assert longnames is None
            longnames = member
        else:
            name = read_string(longnames, int(tag[1:])) if tag.startswith("/") else tag.rstrip("/")
            obj = parse_object(member)
            if extract:
                extract.mkdir(parents=True, exist_ok=True)
                (extract / PureWindowsPath(name).name).write_bytes(member)
            objects.append(dict(name=name, archive_offset=offset, size=size, sha256=hashlib.sha256(member).hexdigest(), **obj))
        if size % 2:
            assert data[offset + 60 + size:offset + 61 + size] == b"\n"
        offset += 60 + size + size % 2
    assert offset == len(data) and len(link) == 2
    first, second = link
    count, = struct.unpack_from(">I", first)
    offsets = struct.unpack_from(f">{count}I", first, 4)
    index1 = dict(zip(read_strings(first, 4 + 4 * count, count), offsets, strict=True))
    n_objects, = struct.unpack_from("<I", second)
    offsets2 = struct.unpack_from(f"<{n_objects}I", second, 4)
    assert list(offsets2) == [obj["archive_offset"] for obj in objects]
    pos = 4 + n_objects * 4
    count2, = struct.unpack_from("<I", second, pos)
    indices = struct.unpack_from(f"<{count2}H", second, pos + 4)
    index2 = dict(zip(read_strings(second, pos + 4 + count2 * 2, count2), [offsets2[i - 1] for i in indices], strict=True))
    assert count == count2 == len(index1) and index1 == index2
    for obj in objects:
        external = {symbol["name"] for symbol in obj["symbols"].values()
                    if symbol["storage"] == 2 and symbol["section"] > 0}
        assert external == {symbol for symbol, location in index2.items() if location == obj["archive_offset"]}
    return dict(archive_sha256=hashlib.sha256(data).hexdigest(), archive_size=len(data),
                index=index2, members=objects)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("archive", type=Path)
    parser.add_argument("inventory", type=Path)
    parser.add_argument("--extract", type=Path)
    args = parser.parse_args()
    contents = parse_archive(args.archive.read_bytes(), args.extract)
    args.inventory.write_text(json.dumps(contents, indent=2) + "\n", encoding="utf-8")
    for obj in contents["members"]:
        print(obj["name"], obj["sha256"])
        print("Sections:", [(s["name"], s["size"], len(s["relocations"])) for s in obj["sections"]])
        print("Definitions:", [s["name"] for s in obj["symbols"].values() if s["section"] > 0 and s["storage"] == 2])
        print("Undefined:", [s["name"] for s in obj["symbols"].values() if s["section"] == 0 and s["storage"] == 2])
