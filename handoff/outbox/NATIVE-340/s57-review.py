"""Recheck the fixed s57 EH tables, branch facts, and clipped EH headers."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import json
from pathlib import Path
import struct
import sys


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


class Section:
    def __init__(self, rva, raw_size, virtual_size):
        self.secs = [dict(rva=rva, raw=0, size=raw_size, vsize=virtual_size,
                          exec=True, name=".text")]

    def filepos(self, rva):
        start = self.secs[0]["rva"]
        if not start <= rva < start + self.secs[0]["size"]:
            raise ValueError("RVA is outside the raw data")
        return rva - start


def fixture(kinds):
    il = bytes([0, 0xDE, 1, 0xDC]) * len(kinds) + b"\x2a"
    data = bytearray(struct.pack("<HHII", 0x300B, 8, len(il), 0) + il)
    data += bytes(-len(data) % 4)
    for i, kind in enumerate(kinds):
        fields = (2, 4 * i, 3, 4 * i + 3, 1, 0)
        clause = struct.pack("<IIIIII" if kind & 0x40 else "<HHBHBI", *fields)
        data += bytes([kind, 4 + len(clause), 0, 0]) + clause
    return bytes(data)


def inspect(method_body, kinds, raw_trim=0, virtual_trim=0, file_trim=0):
    rva = 0x2400
    full = fixture(kinds)
    data = full[:len(full)-file_trim]
    raw, virtual = len(full)-raw_trim, len(full)-virtual_trim
    pe = Section(rva, raw, virtual)
    record = dict(sha256=sha256(data).hexdigest(), raw_size=raw,
                  virtual_size=virtual, file_size=len(data))
    try:
        header = method_body.header(data, pe, rva)
        result = method_body.data_sections(data, pe, header)
        record.update(sections=len(result), more=[s["more"] for s in result],
                      widths=[s["size"]-4 for s in result])
    except (ValueError, IndexError, struct.error) as exc:
        record.update(exception=type(exc).__name__, error=str(exc))
    return record


def compare_original(data, pe, md_reader, code):
    methods = {}
    cli, _ = pe.directory(14)
    md_rva = struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0]
    meta = md_reader.parse(data, pe.filepos(md_rva))
    for m in meta["methods"]:
        if m["rva"] and m["flavor"] == "IL":
            methods[m["token"]] = m["rva"]
    inventory = []
    clauses = []
    for token, rva in methods.items():
        pos = pe.filepos(rva)
        flags = struct.unpack_from("<H", data, pos)[0]
        if flags & 3 != 3 or not flags & 8:
            continue
        il_size = struct.unpack_from("<I", data, pos + 4)[0]
        section_rva = (rva + (flags >> 12) * 4 + il_size + 3) & ~3
        index = 0
        while True:
            pos = pe.filepos(section_rva)
            kind = data[pos]
            assert kind & 0x3F == 1
            fat = bool(kind & 0x40)
            size = int.from_bytes(data[pos+1:pos+(4 if fat else 2)], "little")
            width = 24 if fat else 12
            count, tail = divmod(size - 4, width)
            assert tail == 0
            sec = next(s for s in pe.secs if s["rva"] <= section_rva < s["rva"] + s["size"])
            raw_end = sec["rva"] + sec["size"]
            virt_end = sec["rva"] + sec["vsize"]
            assert section_rva + size <= min(raw_end, virt_end) and pos + size <= len(data)
            inventory.append((token,index,kind,size,width,count,raw_end,virt_end))
            for i in range(count):
                fields = struct.unpack_from("<IIIIII" if fat else "<HHBHBI", data,
                                            pos + 4 + i * width)
                clauses.append((token, section_rva, i, *fields))
            if not kind & 0x80:
                break
            index += 1
            section_rva += size
    table = rows(code / "s57-eh-sections.csv")
    declared = [(int(r["method"],0),int(r["index"]),int(r["header_kind"],0),
                 int(r["header_size"]),int(r["clause_width"]),int(r["clauses"]),
                 int(r["raw_end"],0),int(r["virt_end"],0)) for r in table]
    table_clauses = rows(code / "s57-clauses.csv")
    fields = ("method","section","index","flags","try_offset","try_length",
              "handler_offset","handler_length","class_token")
    expected_types = {0:"catch",1:"filter",2:"finally",4:"fault"}
    assert clauses == [tuple(int(r[f],0) for f in fields) for r in table_clauses]
    assert all(r["type"] == expected_types[int(r["flags"], 0)] for r in table_clauses)
    diff = [{"method": f"0x{b[0]:08X}", "raw_end": f"0x{a[6]:X}",
             "declared_virt_end": f"0x{a[7]:X}", "actual_virt_end": f"0x{b[7]:X}"}
            for a,b in zip(declared, inventory) if a[7] != b[7]]
    assert [r[:-1] for r in declared] == [r[:-1] for r in inventory]
    assert len(inventory) == 25 and len(clauses) == 35
    return {"sections": len(inventory), "clauses":len(clauses),
            "clause_types":dict(Counter(r["type"] for r in table_clauses)),
            "virtual_end_differences":diff}


def branch_control(data, pe, unit):
    def read(rva, length):
        pos = pe.filepos(rva)
        return data[pos:pos + length]
    assert read(0x28F3, 4) == bytes.fromhex("83 7a 24 00")
    assert read(0x28F7, 4) == bytes.fromhex("7d 04 32 c0")
    assert read(0x28FD, 2) == bytes.fromhex("b0 01")
    assert read(0x2195, 4) == bytes.fromhex("84 c0 74 18")
    section = next(s for s in pe.secs if s["rva"] <= 0x19B78 < s["rva"] + s["vsize"])
    signed = struct.unpack_from("<i", data, section["hdr"] + 36)[0]
    assert signed < 0
    truth = [
        ("original", "jge", False, 1, 0, True, None, None),
        ("jge->jl", "jl", True, 1, 1, False, 0x28F7, 0x7C),
        ("al=1->2", "jge", False, 2, 0, True, 0x28FE, 2),
    ]
    assert len(rows(unit / "code/s57-branch-facts.csv")) == 3
    result = []
    for expected, row in zip(truth, rows(unit / "code/s57-branch-facts.csv")):
        tag,cc,taken,target,selected,skipped,change_at,change_to = expected
        actual = (row["run"], row["jcc_cc"], row["jcc_taken"] == "True",
                  int(row["al_at_target"]), int(row["al_for_slot"]), row["slot_skipped"] == "True")
        assert actual == expected[:6] and int(row["al_at_fallthrough"]) == 0
        changed = bytearray(data)
        if change_at is not None:
            changed[pe.filepos(change_at)] = change_to
        result.append(dict(run=tag, condition=cc, taken=taken, target_al=target,
                           effective_al=selected, skipped=skipped,
                           sha256=sha256(changed).hexdigest()))
    bad = "注入 al=1->2 落空 al=2 跳过"
    paths = ["calls.csv"] + [f"code/s{seq}-unresolved-native.csv" for seq in (25,33,37,41,45)]
    contradiction = [str(path) for path in paths if any(
        bad in r["note"] for r in rows(unit / path) if r["caller"] == "0x20CC")]
    return dict(decoded=result, false_note=bad, contradicted_tables=contradiction)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", type=Path)
    ap.add_argument("--original", required=True, type=Path)
    args = ap.parse_args()
    sys.path.insert(0, str(args.candidate_root.resolve() / "tool"))
    import md_reader
    import method_body
    from pe_reader import PE
    unit = args.candidate_root / "handoff/inbox/NATIVE-340"
    original = args.original.read_bytes()
    normal = [0x81,0xC1] * 4 + [0x81,0x41]
    results = {
        "original_sha256": sha256(original).hexdigest(),
        "eh_cases": {
            "mixed_small_then_fat": inspect(method_body, [0x81,0x41]),
            "mixed_fat_then_small": inspect(method_body, [0xC1,0x01]),
            "mixed_nine": inspect(method_body, normal[:8] + [0x01]),
            "mixed_ten": inspect(method_body, normal),
            "last_clause_raw_short": inspect(method_body, normal, raw_trim=4),
            "last_clause_virtual_short": inspect(method_body, normal, virtual_trim=4),
            "last_clause_file_short": inspect(method_body, normal, file_trim=4),
            "last_header_raw_short": inspect(method_body, normal, raw_trim=26),
            "last_header_virtual_short": inspect(method_body, normal, virtual_trim=26),
            "last_header_file_short": inspect(method_body, normal, file_trim=26),
            "missing_successor": inspect(method_body, normal[:-1] + [0xC1]),
        },
        "synthetic_test_failures": [name for name, ok in method_body.synthetic_tests() if not ok],
        "eh_original": compare_original(original, PE(original), md_reader, unit / "code"),
        "branch": branch_control(original, PE(original), unit),
    }
    print(json.dumps(results, indent=2, ensure_ascii=True))


if __name__ == "__main__":
    main()

