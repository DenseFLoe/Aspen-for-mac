"""Reproduce the s53 EH parser and audit evidence without editing the candidate."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import json
from pathlib import Path
import struct
import sys


def fixture(kinds):
    rva = 0x2400
    il = bytes([0, 0xDE, 1, 0xDC]) * len(kinds) + b"\x2a"
    data = bytearray(struct.pack("<HHII", 0x300B, 8, len(il), 0) + il)
    data += bytes(-len(data) % 4)
    for i, kind in enumerate(kinds):
        fields = (2, 4 * i, 3, 4 * i + 3, 1, 0)
        clause = struct.pack("<IIIIII" if kind & 0x40 else "<HHBHBI", *fields)
        data += bytes([kind, 4 + len(clause), 0, 0]) + clause
    return rva, data


class Section:
    def __init__(self, rva, raw_size, virtual_size):
        self.secs = [dict(rva=rva, raw=0, size=raw_size, vsize=virtual_size,
                          exec=True, name=".text")]

    def filepos(self, rva):
        section = self.secs[0]
        offset = rva - section["rva"]
        if not 0 <= offset < section["size"]:
            raise ValueError("RVA is outside the raw data")
        return offset


def inspect_case(method_body, kinds, raw_trim=0, virtual_trim=0, file_trim=0):
    rva, data = fixture(kinds)
    raw_size = len(data) - raw_trim
    virtual_size = len(data) - virtual_trim
    data = data[:len(data) - file_trim]
    section = Section(rva, raw_size, virtual_size)
    check = dict(sha256=sha256(data).hexdigest(), raw_size=raw_size,
                 virtual_size=virtual_size, file_size=len(data))
    try:
        _, eh, clauses = method_body.read(data, section, rva)
        check.update(status="accepted", sections=eh["section_count"],
                     offsets=[c["try_offset"] for c in clauses])
    except (ValueError, IndexError, struct.error) as exc:
        check.update(status="rejected", kind=type(exc).__name__, error=str(exc))
    return check


def check_table(candidate, data, pe):
    path = candidate / "handoff/inbox/NATIVE-340/code/s53-eh-sections.csv"
    with path.open(encoding="utf-8-sig", newline="") as stream:
        rows = list(csv.DictReader(stream))
    clauses_per_section = Counter()
    clause_flags = Counter()
    misplaced_entry_size = []
    for row in rows:
        method_rva, eh_rva = int(row["method_rva"], 0), int(row["rva"], 0)
        method_offset = pe.filepos(method_rva)
        flags, _, il_size, _ = struct.unpack_from("<HHII", data, method_offset)
        assert flags & 8 and ((method_rva + (flags >> 12) * 4 + il_size + 3) & ~3) == eh_rva
        eh_offset = pe.filepos(eh_rva)
        kind = data[eh_offset]
        if kind & 0x40:
            length = int.from_bytes(data[eh_offset + 1:eh_offset + 4], "little")
            entry, flags_format = 24, "<I"
        else:
            length, entry, flags_format = data[eh_offset + 1], 12, "<H"
        assert kind & 0x3F == 1 and not kind & 0x80
        assert kind == int(row["kind"], 0) and length == int(row["size"])
        clause_count, trailing = divmod(length - 4, entry)
        assert not trailing and clause_count == int(row["clauses"])
        section = next(s for s in pe.secs if s["rva"] <= eh_rva < s["rva"] + s["size"])
        assert eh_rva + length <= section["rva"] + section["size"] and eh_offset + length <= len(data)
        clauses_per_section[clause_count] += 1
        for index in range(clause_count):
            clause_flags[struct.unpack_from(flags_format, data, eh_offset + 4 + index * entry)[0]] += 1
        if int(row["entry"]) != entry:
            misplaced_entry_size.append({"method": row["method"], "rva": row["rva"],
                                         "declared": int(row["entry"]), "expected": entry,
                                         "sectionsize": length, "clauses": clause_count})
    return {"sections_checked": len(rows), "clauses_by_section": dict(clauses_per_section),
            "clause_flags": dict(clause_flags), "wrong_entry_width_rows": misplaced_entry_size}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidate_root", type=Path)
    ap.add_argument("--original", type=Path)
    args = ap.parse_args()
    sys.path.insert(0, str(args.candidate_root.resolve() / "tool"))
    import audit_340_s53
    import method_body
    kinds = [0x81, 0xC1] * 4 + [0x81, 0x41]
    cases = {
        "small_then_fat": inspect_case(method_body, [0x81, 0x41]),
        "fat_then_small": inspect_case(method_body, [0xC1, 0x01]),
        "mixed_9": inspect_case(method_body, kinds[:8] + [0x01]),
        "mapped_276": inspect_case(method_body, kinds),
        "mapped_272": inspect_case(method_body, kinds, raw_trim=4, virtual_trim=4),
        "raw_272_virtual_276": inspect_case(method_body, kinds, raw_trim=4),
        "file_272_mapped_276": inspect_case(method_body, kinds, file_trim=4),
        "successor_missing": inspect_case(method_body, kinds[:-1] + [0xC1]),
    }
    # Run the actual claimed successor-control input and observe normal return.
    data, section, rva, _ = audit_340_s53.chain_case([0xC1, 0xC1, 0x41])
    data = bytearray(data)
    pos = (rva + 12 + 7 + 3) & ~3
    struct.pack_into("<I", data, pos + 2 * 28 + 1, 28)
    header = method_body.header(data, section, rva)
    try:
        candidate_control = {"sections_returned": len(method_body.data_sections(data, section, header))}
    except ValueError as exc:
        candidate_control = {"raised": str(exc)}
    result = {
        "cases": cases, "candidate_successor_control": candidate_control,
        "legacy_failures": [name for name, passed in method_body.synthetic_tests() if not passed],
    }
    if args.original is not None:
        from pe_reader import PE
        original = args.original.read_bytes()
        pe = PE(original)
        result["true_image_eh_table"] = check_table(args.candidate_root.resolve(), original, pe)
        result["branch_note"] = {}
        for label, addr, value in (("original", None, None), ("jl", 0x28F7, 0x7C),
                                   ("immediate2", 0x28FE, 2)):
            data = bytearray(original)
            if addr is not None:
                data[pe.filepos(addr)] = value
            data = bytes(data)
            facts = audit_340_s53.gate(data, PE(data))
            facts["_caliber"] = audit_340_s53.CALIBER
            result["branch_note"][label] = {
                "sha256": sha256(data).hexdigest(), "facts": facts,
                "note": audit_340_s53.branch_note(facts),
            }
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
