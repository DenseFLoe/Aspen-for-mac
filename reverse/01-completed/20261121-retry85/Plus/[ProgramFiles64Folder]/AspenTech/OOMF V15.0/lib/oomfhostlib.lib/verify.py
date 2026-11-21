"""Compare the two archives, normalizing only COFF layout and proven AMD64 encodings."""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path, PureWindowsPath
import re
import struct

from iced_x86 import Decoder, Formatter, FormatterSyntax, Mnemonic, OpKind, Register
from inspect_coff import parse_archive


AMD64_REL32 = 4
AMD64_ADDR32NB = 3
REG_DIRECTION_OPS = {0x09, 0x0b, 0x29, 0x2b, 0x31, 0x33, 0x39, 0x3b}
DS_BASES = {Register.R8, Register.R9, Register.R10, Register.R11}
FORMATTER = Formatter(FormatterSyntax.NASM)
FORMATTER.rip_relative_addresses = True
FORMATTER.show_branch_size = True


def section_by_index(obj):
    return {section["index"]: section["name"] for section in obj["sections"]}


def normalized_relocations(obj, section):
    raw = bytearray.fromhex(section["data"])
    sections = section_by_index(obj)
    result = {}
    for rel in section["relocations"]:
        offset = rel["offset"]
        assert rel["type"] in {AMD64_REL32, AMD64_ADDR32NB}
        assert offset not in result
        symbol = obj["symbols"][rel["symbol_index"]]
        addend, = struct.unpack_from("<i", raw, offset)
        raw[offset:offset + 4] = b"\0" * 4
        section_index = symbol["section"]
        if section_index > 0:
            destination = (sections[section_index], symbol["value"] + addend)
        else:
            assert section_index == 0 and symbol["storage"] == 2 and symbol["value"] == 0
            destination = ("external", symbol["name"], addend)
        result[offset] = (rel["type"], destination)
    return bytes(raw), result


def external_symbols(obj):
    sections = section_by_index(obj)
    return {sym["name"]: (sections.get(sym["section"]), sym["value"], sym["type"], sym["aux"])
            for sym in obj["symbols"].values() if sym["storage"] == 2}


def opcode(data):
    return data[1] if 0x40 <= data[0] <= 0x4f else data[0]


def compare_text(left, right):
    counters = Counter()
    variants = []
    functions = set()
    for original, rebuilt in zip(Decoder(64, left), Decoder(64, right), strict=True):
        assert not original.is_invalid and not rebuilt.is_invalid
        assert (original.ip, original.len) == (rebuilt.ip, rebuilt.len), hex(original.ip)
        off, end = original.ip, original.next_ip
        counters["decoded_instructions_including_padding"] += 1
        functions.add(off)
        first = left[off:end]
        second = right[off:end]
        if first == second:
            continue
        before, after = map(FORMATTER.format, (original, rebuilt))
        if original.op_count == rebuilt.op_count == 2 and all(
            item.op_kind(i) == OpKind.REGISTER for item in (original, rebuilt) for i in range(2)
        ) and before == after and opcode(first) in REG_DIRECTION_OPS and (opcode(first) ^ opcode(second)) == 2:
            variation = "register_opcode_direction"
        elif (original.code == rebuilt.code
              and original.segment_prefix == rebuilt.segment_prefix == Register.NONE
              and original.memory_index_scale == rebuilt.memory_index_scale == 1
              and original.memory_displacement == rebuilt.memory_displacement
              and original.memory_base == rebuilt.memory_index and original.memory_index == rebuilt.memory_base
              and {original.memory_base, original.memory_index} <= DS_BASES):
            adjusted = rebuilt.copy()
            adjusted.memory_base = original.memory_base
            adjusted.memory_index = original.memory_index
            assert before == FORMATTER.format(adjusted), (hex(off), before, after)
            variation = "address_base_index_order"
        else:
            raise AssertionError((hex(off), before, after, first.hex(), second.hex()))
        counters[variation] += 1
        variants.append({"text_offset": hex(off), "type": variation, "instruction": before,
                         "original_normalized": first.hex(), "rebuilt_normalized": second.hex()})
    return dict(counters), variants, functions


def coverage_from_ghidra(folder, filename, member, functions):
    text = (folder / (filename + ".txt")).read_text(encoding="utf-8")
    block = re.search(r"^BLOCK \.text ([0-9a-f]+)\.\.([0-9a-f]+)", text, re.M)
    external = re.search(r"^BLOCK EXTERNAL ([0-9a-f]+)\.\.([0-9a-f]+)", text, re.M)
    origin, text_end = (int(value, 16) for value in block.groups())
    ext_start, ext_end = (int(value, 16) for value in external.groups())
    native, externals = [], []
    sections = member["sections"]
    section = next(s for s in sections if s["name"] == ".text")
    raw = bytes.fromhex(section["data"])
    assert text_end - origin + 1 == len(raw)
    reloc_slots = {rel["offset"] + byte for rel in section["relocations"] for byte in range(4)}
    covered = set()
    for match in re.finditer(r"^FUNCTION ([0-9a-f]+) (\S+) ([^\n]*)\n(.*?)(?=^FUNCTION|^RELOC|\Z)", text, re.M | re.S):
        address = int(match[1], 16)
        name = match[2]
        body_line = match[3]
        listing = match[4]
        if name not in functions:
            assert ext_start <= address <= ext_end
            assert any(sym["name"] == name and sym["section"] == 0 for sym in member["symbols"].values())
            externals.append(name)
            continue
        offset = address - origin
        assert functions[name][1] == offset
        assert "DECOMPILATION FAILED" not in listing and listing.strip()
        function_bytes = 0
        for ins in re.finditer(r"^([0-9a-f]{8}) ([0-9a-f]+)\s+\S", listing, re.M):
            start = int(ins[1], 16) - origin
            assembled = bytes.fromhex(ins[2])
            assert 0 <= start < start + len(assembled) <= len(raw)
            for pos, val in enumerate(assembled, start):
                assert pos not in covered
                assert pos in reloc_slots or raw[pos] == val, (name, hex(pos))
                covered.add(pos)
            function_bytes += len(assembled)
        assert function_bytes and offset in covered, name
        native.append(dict(name=name, text_offset=hex(offset), ghidra_address=hex(address),
                           body=body_line, listing_bytes=function_bytes))
    assert {entry["name"] for entry in native} == set(functions)
    padding = []
    for instruction in Decoder(64, raw):
        span = set(range(instruction.ip, instruction.next_ip))
        if not span & covered:
            assert instruction.mnemonic == Mnemonic.NOP, (filename, hex(instruction.ip))
            padding.append(dict(offset=hex(instruction.ip), length=instruction.len))
        else:
            assert span <= covered
    assert len(covered) + sum(x["length"] for x in padding) == len(raw)
    return dict(functions=native, gap_nops=padding, external_thunks=externals,
                loader_relocation_failures=re.findall(r"^RELOC ([0-9a-f]+ FAILURE .*?)$", text, re.M))


def compare_archives(original, rebuilt, ghidra):
    original = parse_archive(original, None)
    rebuilt = parse_archive(rebuilt, None)
    def indexed_names(archive):
        members = {obj["archive_offset"]: obj["name"] for obj in archive["members"]}
        return {symbol: members[off] for symbol, off in archive["index"].items()}
    assert indexed_names(original) == indexed_names(rebuilt)
    members = []
    for first, second in zip(original["members"], rebuilt["members"], strict=True):
        for key in ("name", "machine", "flags"):
            assert first[key] == second[key], key
        symbols = external_symbols(first)
        assert symbols == external_symbols(second)
        checks = []
        for left, right in zip(first["sections"], second["sections"], strict=True):
            for field in ("index", "name", "flags", "size"):
                assert left[field] == right[field], (first["name"], left["name"], field)
            a, a_rel = normalized_relocations(first, left)
            b, b_rel = normalized_relocations(second, right)
            assert a_rel == b_rel, (first["name"], left["name"], "relocation target or addend")
            check = dict(section=left["name"], flags=left["flags"], size=left["size"],
                         relocation_count=len(a_rel), relocation_targets=[
                             {"offset": hex(offset), "type": kind, "destination": destination}
                             for offset, (kind, destination) in sorted(a_rel.items())])
            if left["name"] == ".text":
                counts, variants, instruction_starts = compare_text(a, b)
                assert all(off in instruction_starts for section, off, _, _ in symbols.values() if section == ".text")
                check.update(counts=counts, encoding_variants=variants)
            else:
                assert a == b, (first["name"], left["name"], "contents")
            check["original_section_sha256"] = hashlib.sha256(bytes.fromhex(left["data"])).hexdigest() if left["raw_offset"] else None
            check["rebuilt_section_sha256"] = hashlib.sha256(bytes.fromhex(right["data"])).hexdigest() if right["raw_offset"] else None
            checks.append(check)
        record = dict(member=first["name"], original_offset=hex(first["archive_offset"]),
                      original_sha256=first["sha256"], rebuilt_sha256=second["sha256"],
                      symbols=symbols, sections=checks)
        if ghidra:
            record["ghidra"] = coverage_from_ghidra(ghidra, PureWindowsPath(first["name"]).name, first,
                                                   {name: details for name, details in symbols.items() if details[0] == ".text"})
        members.append(record)
    return dict(original_sha256=original["archive_sha256"], rebuilt_sha256=rebuilt["archive_sha256"],
                index=indexed_names(original), members=members)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("rebuilt", type=Path)
    parser.add_argument("result", type=Path)
    parser.add_argument("--ghidra", type=Path)
    args = parser.parse_args()
    result = compare_archives(args.original.read_bytes(), args.rebuilt.read_bytes(), args.ghidra)
    args.result.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    for obj in result["members"]:
        print(obj["member"], sum(s["relocation_count"] for s in obj["sections"]))
        print(next(s["counts"] for s in obj["sections"] if s["section"] == ".text"))
