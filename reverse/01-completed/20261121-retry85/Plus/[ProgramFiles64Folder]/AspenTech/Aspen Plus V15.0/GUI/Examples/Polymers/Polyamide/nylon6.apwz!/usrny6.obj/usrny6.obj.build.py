"""Assemble the recovered USRNY6 routine and reproduce its COFF metadata."""

import argparse
from dataclasses import dataclass
import hashlib
from pathlib import Path
import shutil
import struct
import subprocess
import tempfile


ORIGINAL_SHA256 = "92efb7c09dffeb1ef3cbb0798ca65d9469725ec66d328b18fe0bbb3bb9cbba25"
FUNCTION_SYMBOLS = ("USRNY6", "SHS_FIPOLM", "DMS_LOCATI", "USR002", "__ImageBase")
SECTION_HEADER = struct.Struct("<8sIIIIIIHHI")
SYMBOL = struct.Struct("<8sIhHBB")
RELOCATION = struct.Struct("<IIH")


def require(condition, message):
    if not condition:
        raise ValueError(message)


@dataclass
class Section:
    name: str
    header: int
    size: int
    data: int
    relocations: int
    relocation_count: int
    flags: int


@dataclass
class Symbol:
    name: str
    index: int
    offset: int
    value: int
    section: int
    kind: int
    storage_class: int
    aux: bytes


class Coff:
    def __init__(self, data):
        self.data = data
        machine, count, _, symbols, count_symbols, optional, self.flags = (
            struct.unpack_from("<HHIIIHH", data)
        )
        require(machine == 0x8664 and optional == 0, "Expected a Windows AMD64 COFF object")
        self.sections = {}
        for index in range(count):
            offset = 20 + SECTION_HEADER.size * index
            name, virtual_size, virtual_address, size, start, relocs, lines, count_relocs, count_lines, flags = (
                SECTION_HEADER.unpack_from(data, offset)
            )
            name = name.rstrip(b"\0").decode("ascii")
            require((virtual_size, virtual_address, lines, count_lines) == (0, 0, 0, 0),
                    f"{name}: unexpected virtual fields or COFF line records")
            self.sections[name] = Section(name, offset, size, start, relocs, count_relocs, flags)

        self.symbols = {}
        self.symbol_by_index = {}
        string_table = symbols + SYMBOL.size * count_symbols
        index = 0
        while index < count_symbols:
            offset = symbols + SYMBOL.size * index
            name, value, section, kind, storage_class, aux_count = SYMBOL.unpack_from(data, offset)
            if name[:4] == bytes(4):
                start = string_table + int.from_bytes(name[4:], "little")
                name = data[start:data.index(0, start)]
            name = name.rstrip(b"\0").decode("ascii")
            aux_start = offset + SYMBOL.size
            aux_end = aux_start + SYMBOL.size * aux_count
            symbol = Symbol(name, index, offset, value, section, kind, storage_class,
                            bytes(data[aux_start:aux_end]))
            self.symbols[name] = symbol
            self.symbol_by_index[index] = symbol
            index += 1 + aux_count

    def relocations(self, section):
        for index in range(section.relocation_count):
            record = section.relocations + RELOCATION.size * index
            offset, target, kind = RELOCATION.unpack_from(self.data, record)
            yield record, offset, self.symbol_by_index[target].name, kind

    def section_name(self, index):
        return tuple(self.sections)[index - 1] if index > 0 else index

    def section_bytes(self, section):
        return self.data[section.data:section.data + section.size] if section.data else b""


def restore_metadata(data):
    obj = Coff(data)
    for name in FUNCTION_SYMBOLS:
        symbol = obj.symbols[name]
        require(symbol.storage_class == 2 and symbol.kind in (0, 0x20),
                f"{name}: unexpected assembler symbol attributes")
        struct.pack_into("<H", data, symbol.offset + 14, 0x20)

    for name in (".pdata", ".xdata"):
        section = obj.sections[name]
        struct.pack_into("<I", data, section.header + 36, section.flags & ~0x40)

    # NASM emits REL32 with a -1 addend for CMP's disp32 followed by imm8.
    # The original encodes the same address with REL32_1 and addend 0.
    text = obj.sections[".text"]
    cmp_offset = obj.symbols["USRNY6.check_polymer_directory"].value
    disp_offset = cmp_offset + 3
    require(data[text.data + cmp_offset:text.data + disp_offset] == b"\x48\x83\x3d",
            "The polymer-directory CMP no longer has the expected encoding")
    matches = [(record, kind) for record, offset, target, kind in obj.relocations(text)
               if offset == disp_offset and target == ".bss"]
    require(len(matches) == 1, "Missing polymer-directory relocation")
    record, kind = matches[0]
    addend, = struct.unpack_from("<i", data, text.data + disp_offset)
    require((kind, addend) in ((4, -1), (5, 0)), "Unexpected polymer-directory relocation")
    struct.pack_into("<i", data, text.data + disp_offset, 0)
    struct.pack_into("<H", data, record + 8, 5)

    # Keep the original .pdata symbol binding for both code boundaries.
    entry = obj.symbols["USRNY6"]
    require(entry.value == 0 and obj.section_name(entry.section) == ".text",
            "USRNY6 must be at the start of .text")
    pdata = tuple(obj.relocations(obj.sections[".pdata"]))
    require(len(pdata) == 3 and pdata[2][1:] == (8, ".xdata", 3), "Unexpected unwind references")
    for expected_offset, (record, offset, target, kind) in zip((0, 4), pdata[:2]):
        require(offset == expected_offset and target in (".text", "USRNY6") and kind == 3,
                "Unexpected unwind code reference")
        struct.pack_into("<I", data, record + 4, entry.index)
    return data


def verify_original(original, rebuilt):
    require(hashlib.sha256(original).hexdigest() == ORIGINAL_SHA256, "Original SHA-256 mismatch")
    left, right = Coff(original), Coff(rebuilt)
    require(left.flags == right.flags, "Different COFF file characteristics")
    require(left.sections.keys() == right.sections.keys(), "Different section inventory")
    for name, a in left.sections.items():
        b = right.sections[name]
        require((a.size, a.flags, bool(a.data), left.section_bytes(a)) ==
                (b.size, b.flags, bool(b.data), right.section_bytes(b)), f"{name}: section mismatch")
        require(sorted(record[1:] for record in left.relocations(a)) ==
                sorted(record[1:] for record in right.relocations(b)), f"{name}: relocation mismatch")
        print(f"{name}: {a.size} bytes, flags=0x{a.flags:08x}, {a.relocation_count} relocations")
    for name, original_symbol in left.symbols.items():
        candidate = right.symbols.get(name)
        require(candidate is not None, f"Missing symbol: {name}")
        require((original_symbol.value, left.section_name(original_symbol.section),
                 original_symbol.kind, original_symbol.storage_class, original_symbol.aux) ==
                (candidate.value, right.section_name(candidate.section), candidate.kind,
                 candidate.storage_class, candidate.aux), f"{name}: symbol metadata mismatch")

    extra = right.symbols.keys() - left.symbols.keys()
    require(all(right.symbols[name].storage_class in (3, 103) for name in extra),
            "Unexpected public symbols")
    print(f"Original symbols matched: {len(left.symbols)}; extra local records: {len(extra)}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--nasm", default="nasm", help="path to NASM 2.16.03")
    parser.add_argument("--out", required=True, type=Path, help="new COFF output path")
    parser.add_argument("--original", type=Path, help="hash-checked original for static comparison")
    args = parser.parse_args()
    assembler = shutil.which(args.nasm)
    require(assembler is not None, f"NASM executable not found: {args.nasm}")
    source = Path(__file__).with_name("usrny6.obj.asm")
    require(not args.out.exists(), "The output path already exists")
    with tempfile.TemporaryDirectory(prefix="usrny6-", dir=args.out.resolve().parent) as folder:
        scratch_source = Path(folder) / source.name
        shutil.copyfile(source, scratch_source)
        scratch = Path(folder) / "usrny6.nasm.obj"
        subprocess.run([str(Path(assembler).resolve()), "-f", "win64", "-Werror", "--reproducible",
                        "-o", scratch.name, scratch_source.name], cwd=folder, check=True)
        recovered = restore_metadata(bytearray(scratch.read_bytes()))
        if args.original is not None:
            verify_original(args.original.read_bytes(), recovered)
        with args.out.open("xb") as output:
            output.write(recovered)
        print("Rebuilt SHA-256:", hashlib.sha256(recovered).hexdigest())


if __name__ == "__main__":
    main()
