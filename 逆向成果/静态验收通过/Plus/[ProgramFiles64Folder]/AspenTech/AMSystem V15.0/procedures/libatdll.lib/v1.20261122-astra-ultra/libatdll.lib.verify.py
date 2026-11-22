"""Compare libatdll.lib against a rebuild, including x64 code, static data and both COFF indices."""
import argparse
from collections import Counter
import hashlib
import json
import struct
from pathlib import Path

import capstone
from capstone.x86 import X86_OP_IMM, X86_OP_MEM

EXPECTED = "aa423ce85b3c9a4bb16ae0c42ea8b939d4fe8f4c78ab98c9086ae4db9fea518f"


def digest(data):
    return hashlib.sha256(data).hexdigest()


def fail_unless(condition, reason):
    if not condition:
        raise ValueError(reason)


def read_archive(data):
    fail_unless(data.startswith(b"!<arch>\n"), "archive signature")
    members = []
    position = 8
    while position < len(data):
        header = data[position:position + 60]
        fail_unless(len(header) == 60 and header[58:] == b"\x60\n", "member header")
        size = int(header[48:58])
        body = data[position + 60:position + 60 + size]
        fail_unless(len(body) == size, "member length")
        members.append((position, header[:16].rstrip().decode(), body))
        position += 60 + size + (size % 2)
    fail_unless(position == len(data) and [n for _, n, _ in members[:3]] == ["/", "/", "//"], "archive bounds and indices")
    first, second, names = (m[2] for m in members[:3])
    count = struct.unpack_from(">I", first)[0]
    offsets = struct.unpack_from(f">{count}I", first, 4)
    first_names = first[4 + 4 * count:].split(b"\0")
    fail_unless(len(first_names) == count + 1 and first_names[-1] == b"", "first index strings")
    first_map = dict(zip(first_names, offsets))
    nobj = struct.unpack_from("<I", second)[0]
    objpos = struct.unpack_from(f"<{nobj}I", second, 4)
    obj_indexes = 4 + 4 * nobj
    nsyms = struct.unpack_from("<I", second, obj_indexes)[0]
    selectors = struct.unpack_from(f"<{nsyms}H", second, obj_indexes + 4)
    second_names = second[obj_indexes + 4 + 2 * nsyms:].split(b"\0")
    fail_unless(len(second_names) == nsyms + 1 and second_names[-1] == b"", "second index strings")
    fail_unless(tuple(m[0] for m in members[3:]) == objpos and all(1 <= s <= nobj for s in selectors), "second index offsets")
    second_map = dict(zip(second_names, (objpos[s - 1] for s in selectors)))
    fail_unless(count == nsyms == len(second_map) and first_map == second_map, "index disagreement")
    named = []
    for offset, label, obj in members[3:]:
        start = int(label[1:])
        name = names[start:names.index(0, start)].decode("ascii")
        named.append((name, offset, obj))
    return named, second_map, [digest(x[2]) for x in members[:3]]


def coff(data):
    machine, count, _, sympos, nsym, optlen, _ = struct.unpack_from("<HHIIIHH", data)
    fail_unless(machine == 0x8664 and optlen == 0, "AMD64 COFF header")
    strings = data[sympos + 18 * nsym:]
    fail_unless(struct.unpack_from("<I", strings)[0] == len(strings), "string table size")
    symbols = {}
    i = 0
    while i < nsym:
        field, value, section, kind, storage, aux = struct.unpack_from("<8sIhHBB", data, sympos + 18 * i)
        if field[:4] == bytes(4):
            pos = int.from_bytes(field[4:], "little")
            name = strings[pos:strings.index(0, pos)].decode("ascii")
        else:
            name = field.rstrip(b"\0").decode("ascii")
        symbols[i] = (name, value, section, kind, storage)
        i += 1 + aux
    fail_unless(i == nsym, "auxiliary symbol count")
    sections = []
    for n in range(count):
        header = struct.unpack_from("<8sIIIIIIHHI", data, 20 + 40 * n)
        field, _, _, size, ptr, relptr, _, nrel, _, flags = header
        records = [struct.unpack_from("<IIH", data, relptr + 10 * j) for j in range(nrel)]
        for loc, symbol, _ in records:
            fail_unless(loc < size and symbol in symbols, "relocation symbol or offset")
        sections.append({"name": field.rstrip(b"\0").decode(), "size": size, "flags": flags,
                         "body": data[ptr:ptr + size] if ptr else b"", "relocs": records})
    return symbols, sections, nsym


def code_section(decoder, member, n, section, symbols):
    data = section["body"]
    bypos = {loc: (idx, typ) for loc, idx, typ in section["relocs"]}
    definitions = [(i, s) for i, s in symbols.items() if s[2] == n and s[3] == 0x20]
    end = len(data)
    table = {}
    if any(s[0] == "ACM_Print" for _, s in definitions):
        lookup = {s[0]: s[1] for s in symbols.values() if s[2] == n}
        start = lookup["$LN120"]
        selectors = lookup["$LN119"]
        fail_unless(selectors - start == 6 * 4 and len(data) - selectors == 52, "switch table layout")
        cases = []
        for k in range(6):
            index, typ = bypos[start + k * 4]
            label, target, target_section, _, _ = symbols[index]
            fail_unless(typ == 3 and target_section == n and target < start, "switch RVA")
            cases.append({"symbol": label, "offset": target,
                          "characters": "".join(chr(0x45 + j) for j, v in enumerate(data[selectors:]) if v == k)})
        fail_unless(all(v < len(cases) for v in data[selectors:]), "switch selector")
        end = start
        table = {"case_rvas_offset": start, "selectors_offset": selectors, "selector_count": 52, "cases": cases}
    instructions = list(decoder.disasm(data[:end], 0))
    starts = {i.address for i in instructions}
    fail_unless(sum(i.size for i in instructions) == end, f"decode {member} section {n}")
    fail_unless(all(s[1] in starts for _, s in definitions), "function entry in instruction body")
    direct = 0
    refs = []
    indirect = []
    for ins in instructions:
        has_target = ins.group(capstone.CS_GRP_JUMP) or ins.group(capstone.CS_GRP_CALL)
        if has_target and ins.operands[0].type == X86_OP_IMM and ins.address + ins.imm_offset not in bypos:
            fail_unless(ins.operands[0].imm in starts, f"branch {member} {n} +{ins.address:x}")
            direct += 1
        elif has_target and ins.operands[0].type != X86_OP_IMM:
            indirect.append([ins.address, ins.mnemonic, ins.op_str])
        for slot in (ins.imm_offset, ins.disp_offset):
            if slot and ins.address + slot in bypos:
                idx, typ = bypos[ins.address + slot]
                refs.append([ins.address, ins.address + slot, typ, idx, symbols[idx][0]])
    fail_unless({r[1] for r in refs} == {loc for loc in bypos if loc < end}, "unaccounted code relocation")
    if table:
        fail_unless(all(case["offset"] in starts for case in table["cases"]), "invalid switch target")
    return {"section": n, "instructions": len(instructions), "decoded_bytes": end, "table_bytes": len(data) - end,
            "entries": [[i, s[0], s[1]] for i, s in definitions], "local_direct_edges_checked": direct,
            "indirect_transfers": indirect, "instruction_references": refs, "switch": table}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--original", type=Path, required=True)
    parser.add_argument("--rebuilt", type=Path, required=True)
    parser.add_argument("--audit", type=Path, required=True, help="new JSON output")
    args = parser.parse_args()
    original, rebuilt = args.original.read_bytes(), args.rebuilt.read_bytes()
    fail_unless(digest(original) == EXPECTED, "input SHA-256")
    old, index, special = read_archive(original)
    new, new_index, new_special = read_archive(rebuilt)
    fail_unless(len(old) == len(new) and index == new_index and special == new_special, "archive metadata")
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    result = {"original_sha256": digest(original), "rebuilt_sha256": digest(rebuilt), "bytes": len(original),
              "format": "MS COFF archive / AMD64", "capstone": capstone.__version__, "linker_index_entries_each": len(index),
              "index1_index2_longnames_sha256": special, "members": []}
    indexed = {}
    for (member, off, obj), (new_name, new_off, other) in zip(old, new):
        fail_unless((member, off) == (new_name, new_off), "archive member identity")
        symbols, sections, nsym = coff(obj)
        new_symbols, new_sections, other_nsym = coff(other)
        fail_unless(symbols == new_symbols and nsym == other_nsym and sections == new_sections, "COFF member structures")
        item = {"member": member, "archive_header_offset": off, "bytes": len(obj), "original_sha256": digest(obj),
                "rebuilt_sha256": digest(other), "coff_symbol_records_including_aux": nsym,
                "symbols_excluding_aux": len(symbols), "indexed_symbols": sum(v == off for v in index.values()),
                "sections": [], "executable": [], "relocation_counts": {}}
        reltypes = Counter()
        for idx, sec in enumerate(sections, start=1):
            r = sec["relocs"]
            reltypes.update(t for _, _, t in r)
            item["sections"].append([idx, sec["name"], sec["size"], f"0x{sec['flags']:08x}", len(r),
                                     digest(sec["body"]) if sec["body"] else None])
            if sec["flags"] & 0x20:
                item["executable"].append(code_section(decoder, member, idx, sec, symbols))
        item["relocation_counts"] = dict(sorted(reltypes.items()))
        for name, _, section, _, storage in symbols.values():
            if section > 0 and storage == 2:
                indexed.setdefault(name.encode("ascii"), off)
        fail_unless(obj == other, f"complete member bytes: {member}")
        result["members"].append(item)
    fail_unless(indexed == index, "export definitions do not reproduce the two linker indices")
    fail_unless(original == rebuilt, "complete archive byte comparison")
    result["identical"] = True
    with args.audit.open("x", encoding="utf-8") as stream:
        json.dump(result, stream, indent=1, ensure_ascii=True)
        stream.write("\n")
    print(f"{len(old)} members, {len(index)} index entries, {len(original)} identical bytes; {digest(original)}")


if __name__ == "__main__":
    main()