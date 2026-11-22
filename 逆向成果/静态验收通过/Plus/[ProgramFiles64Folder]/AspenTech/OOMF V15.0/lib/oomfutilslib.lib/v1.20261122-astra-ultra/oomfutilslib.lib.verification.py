"""Compare two oomfutilslib.lib archives and describe every function's static coverage.

Usage: python oomfutilslib.lib.verification.py original.lib rebuilt.lib report.json
Requires Python 3 and Capstone 5. This program is independent of the assembler.
"""
import argparse
from hashlib import sha256
import json
from pathlib import Path
import struct
import sys

import capstone as cs

EXPECTED = "5b4fdd8b8728e16ba802f472c356613456625f0d400122b3503d03b5e920a23c"


def check(ok, message):
    if not ok:
        raise ValueError(message)


def digest(buf):
    return sha256(buf).hexdigest()


def archive(blob):
    check(blob.startswith(b"!<arch>\n"), "missing archive signature")
    pos = 8
    records = []
    while pos < len(blob):
        head = blob[pos:pos + 60]
        check(len(head) == 60 and head[58:] == b"\x60\n", "bad archive header")
        size = int(head[48:58])
        records.append((head[:16].decode("ascii").strip(), pos, blob[pos + 60:pos + 60 + size]))
        pos += 60 + size + size % 2
    check(pos == len(blob) and [r[0] for r in records[:3]] == ["/", "/", "//"], "bad special members")
    first, second, longnames = (r[2] for r in records[:3])
    n = struct.unpack_from(">I", first)[0]
    first_offsets = struct.unpack_from(f">{n}I", first, 4)
    first_names = first[4 + 4 * n:].rstrip(b"\0").split(b"\0")
    m = struct.unpack_from("<I", second)[0]
    members = struct.unpack_from(f"<{m}I", second, 4)
    second_count = struct.unpack_from("<I", second, 4 + 4 * m)[0]
    indices = struct.unpack_from(f"<{second_count}H", second, 8 + 4 * m)
    second_names = second[8 + 4 * m + 2 * second_count:].rstrip(b"\0").split(b"\0")
    check(len(first_names) == len(second_names) == n == second_count, "index count")
    check(list(members) == [r[1] for r in records[3:]], "index member offsets")
    check(sorted(zip(first_names, first_offsets)) == [(name, members[i - 1]) for name, i in zip(second_names, indices)], "index mapping")
    result = {}
    for ref, offset, body in records[3:]:
        start = int(ref[1:])
        name = longnames[start:longnames.index(b"\0", start)].decode("ascii")
        check(name not in result, "duplicate member name")
        result[name] = (offset, body, [s.decode("ascii") for s, o in zip(first_names, first_offsets) if o == offset])
    return result


def coff(buf):
    machine, count, stamp, table, slots, opt, flags = struct.unpack_from("<HHIIIHH", buf)
    check(machine == 0x8664 and opt == 0, "not AMD64 COFF")
    st = table + slots * 18
    check(st + struct.unpack_from("<I", buf, st)[0] == len(buf), "wrong string pool length")
    symbols = {}
    i = 0
    while i < slots:
        name, value, sec, typ, storage, aux = struct.unpack_from("<8sIhHBB", buf, table + i * 18)
        if name[:4] == bytes(4):
            start = st + struct.unpack_from("<I", name, 4)[0]
            name = buf[start:buf.index(b"\0", start)]
        symbols[i] = (name.rstrip(b"\0").decode("ascii"), sec, value, typ, storage)
        i += 1 + aux
    sections = {}
    for i in range(count):
        name, _, _, size, off, rp, _, nr, _, attrs = struct.unpack_from("<8sIIIIIIHHI", buf, 20 + 40 * i)
        name = name.rstrip(b"\0").decode("ascii")
        refs = {}
        for j in range(nr):
            addr, idx, kind = struct.unpack_from("<IIH", buf, rp + 10 * j)
            check(addr not in refs and addr + 4 <= size, "relocation field")
            refs[addr] = (symbols[idx][0], kind, struct.unpack_from("<i", buf, off + addr)[0])
        sections[name] = (i + 1, size, attrs, buf[off:off + size] if off else b"", refs)
    return symbols, sections


def inspect(name, left, right, decoder, owners):
    offset, orig, indexed = left
    _, rebuilt, _ = right
    check(orig == rebuilt, f"{name}: object mismatch")
    symbols, sections = coff(orig)
    check((symbols, sections) == coff(rebuilt), f"{name}: logical COFF mismatch")
    by_name = {s[0]: s for s in symbols.values()}
    text_id, _, _, code, text_refs = sections[".text"]
    pdata, p_refs = sections[".pdata"][3:]
    insns = list(decoder.disasm(code, 0))
    check(sum(i.size for i in insns) == len(code), "undecoded text")
    starts = {i.address for i in insns}
    covered = set()
    used_refs = set()
    funcs = []
    for p in range(0, len(pdata), 12):
        entry, name2, xname = (p_refs[p + d][0] for d in (0, 4, 8))
        check(entry == name2 and xname == ".xdata", "unwind target")
        check(all(p_refs[p+d][1] == 3 for d in (0,4,8)), "unwind relocation type")
        start = by_name[entry][2] + p_refs[p][2]
        end = by_name[name2][2] + p_refs[p+4][2]
        unwind = p_refs[p+8][2]
        check(start in starts and end in starts | {len(code)}, "function boundary")
        body = [i for i in insns if start <= i.address < end]
        jumps, calls, data_refs = [], [], []
        check(start < end <= len(code) and not covered.intersection(range(start,end)), "overlap")
        covered.update(range(start, end))
        for i in body:
            if i.group(cs.CS_GRP_JUMP):
                target = i.operands[0].imm
                check(target in starts, f"{entry}: branch to non-instruction")
                jumps.append((i.address, target))
            for field in (i.disp_offset, i.imm_offset):
                addr = i.address + field
                if not field or addr not in text_refs:
                    continue
                check(addr not in used_refs, "duplicated relocation")
                used_refs.add(addr)
                target, kind, addend = text_refs[addr]
                check(kind == 4 + i.address + i.size - addr - 4, "REL32 suffix")
                if i.group(cs.CS_GRP_CALL):
                    calls.append((i.address, target))
                else:
                    data_refs.append((i.address, target, addend, kind))
        funcs.append(dict(name=entry, text_offset=start, end_exclusive=end, unwind_offset=unwind,
                          sha256=digest(code[start:end]), instructions=len(body),
                          branch_count=len(jumps), branches=jumps, calls=calls, data_references=data_refs))
    check({f["name"] for f in funcs} == {s[0] for s in symbols.values() if s[1] == text_id and s[3] == 32},
          "COFF function symbols vs .pdata")
    check(set(text_refs) == used_refs, "unaccounted text relocations")
    padding = [i for i in range(len(code)) if i not in covered]
    check(all(code[i] == 0x90 for i in padding), "unaccounted code")
    local = {s[0] for s in symbols.values() if s[1] > 0}
    calls = {target for f in funcs for _, target in f["calls"]}
    cross_member = {t: owners[t] for t in sorted(calls - local) if t in owners}
    return dict(name=name, archive_offset=offset, bytes=len(orig), original_sha256=digest(orig),
                rebuilt_sha256=digest(rebuilt), identical=True, archive_index=indexed, symbols=len(symbols),
                sections=[dict(name=n, size=s[1], flags=hex(s[2]), file_bytes=len(s[3]),
                               raw_sha256=digest(s[3]) if s[3] else None, relocations=len(s[4])) for n,s in sections.items()],
                common_bytes={s[0]:s[2] for s in symbols.values() if s[1] == 0 and s[2]},
                initialized_or_bss_symbols={s[0]:[list(sections)[s[1]-1],s[2]] for s in symbols.values()
                                           if s[1] > 0 and s[3] != 32 and s[0] not in sections},
                external_call_targets=sorted(calls - local - owners.keys()), cross_member_calls=cross_member,
                text_bytes=len(code), instruction_count=len(insns), non_function_nop_offsets=padding, functions=funcs)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ("original", "rebuilt", "report"):
        parser.add_argument(name, type=Path)
    args = parser.parse_args()
    orig, rebuilt = args.original.read_bytes(), args.rebuilt.read_bytes()
    check(digest(orig) == EXPECTED and len(orig) == 118808, "original identity")
    left, right = archive(orig), archive(rebuilt)
    check(list(left) == list(right), "member identities or order")
    decoder = cs.Cs(cs.CS_ARCH_X86, cs.CS_MODE_64)
    decoder.detail = True
    owners = {sym: name for name, (_, _, indexed) in left.items() for sym in indexed}
    members = [inspect(n, v, right[n], decoder, owners) for n,v in left.items()]
    check(orig == rebuilt, "archive-level mismatch")
    funcs = [f for m in members for f in m["functions"]]
    totals = dict(object_members=len(members), archive_special_members=3, archive_symbols=len(owners),
                  coff_symbols=sum(m["symbols"] for m in members),
                  sections=sum(len(m["sections"]) for m in members), functions=len(funcs),
                  unwind_entries=len(funcs), instructions_with_padding=sum(m["instruction_count"] for m in members),
                  text_bytes=sum(m["text_bytes"] for m in members),
                  padding_bytes=sum(len(m["non_function_nop_offsets"]) for m in members),
                  relocations=sum(s["relocations"] for m in members for s in m["sections"]),
                  direct_calls=sum(len(f["calls"]) for f in funcs),
                  local_branches=sum(f["branch_count"] for f in funcs),
                  text_data_relocations=sum(len(f["data_references"]) for f in funcs))
    report = dict(status="passed", bytes=len(orig), original_sha256=digest(orig), rebuilt_sha256=digest(rebuilt),
                  bytes_equal=True, python=sys.version.split()[0], capstone=cs.__version__, totals=totals,
                  record_fields=dict(branches=["instruction_offset","target_offset"],
                                     calls=["instruction_offset","COFF_symbol"],
                                     data_references=["instruction_offset","COFF_symbol","addend","relocation_type"]),
                  offset_units="bytes, relative to this member's .text unless marked otherwise", members=members)
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8", newline="\n")
    print(json.dumps(totals))


if __name__ == "__main__":
    main()
