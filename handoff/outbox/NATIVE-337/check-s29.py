"""Recheck FindComponent s29 tables from original bytes and candidate lines.

Run beside the published check-s21.py with ORIGINAL CANDIDATE_ITEM_DIR.
Exit 2 denotes evidence differences in this s29 comparison.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
from importlib.util import module_from_spec, spec_from_file_location
import json
from pathlib import Path
import platform
import re
import struct

import capstone
from capstone import x86
import pefile


spec = spec_from_file_location("earlier", Path(__file__).with_name("check-s21.py"))
earlier = module_from_spec(spec)
spec.loader.exec_module(earlier)


def compare(original, item):
    controls = earlier.verify(original, item)
    pe = pefile.PE(str(original))
    image = pe.get_memory_mapped_image()
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    addresses, owners = earlier.listing(item / "code/native.asm", image)
    row_number = {site: number for number, site in addresses.items()}
    imports = {}
    for library in pe.DIRECTORY_ENTRY_IMPORT:
        for symbol in library.imports:
            name = f"#{symbol.ordinal}" if symbol.import_by_ordinal else symbol.name.decode()
            imports[symbol.address - pe.OPTIONAL_HEADER.ImageBase] = library.dll.decode() + "!" + name

    def decode(site):
        return next(decoder.disasm(image[site:site + 16], site, count=1))

    def table(name):
        return earlier.rows(item / name)

    def asm_site(reference):
        match = re.fullmatch(r"code/native\.asm#L(\d+)(?:-L\d+)?", reference)
        return addresses.get(int(match[1])) if match else None

    by_site = defaultdict(list)
    for number, row in enumerate(table("calls.csv"), 2):
        by_site[asm_site(row["listing"])].append((number, row))

    indirect = {int(row["callee"].split("@")[1], 16): number
                for records in by_site.values() for number, row in records
                if row["callee"].startswith("indirect@")}
    binds = {int(row["rva"], 16): row for row in table("code/s21-com-binding.csv")}
    com = {}
    for name in ["s25-idispatch-slots.csv", "s29-idispatch.csv"]:
        counts = Counter()
        flags = Counter()
        sites = set()
        for row in table("code/" + name):
            site = int(row["site"], 16)
            slot = decode(site).operands[0].mem.disp
            factory, via = re.search(r"factory (0x\w+) via (0x\w+)", binds[site]["detail"]).groups()
            assert decode(int(via, 16)).operands[0].imm == int(factory, 16)
            sites.add(site)
            counts["rows"] += 1
            counts["matching_slot_and_member"] += int(row["disp"], 16) == slot and row["member"] == earlier.MEMBERS[slot]
            counts["matching_factory"] += factory in row["object_need"]
            counts["references_to_asm"] += asm_site(row["main_table_line"]) == site
            if "member_fixed" in row:
                flags[row["member_fixed"]] += 1
        assert sites == binds.keys()
        com[name] = {**counts, "member_fixed_flags": dict(flags)}

    chain_controls = {int(row["rva"], 16) for row in table("code/s21-two-hop.csv")}
    seen = set()
    two_counts = Counter()
    examples = []
    targets = Counter()
    for row in table("code/s29-two-hop.csv"):
        site = int(row["site"], 16)
        seen.add(site)
        transfer = decode(site)
        assert transfer.operands[0].type == x86.X86_OP_IMM
        thunk = transfer.operands[0].imm
        tail = decode(thunk)
        slot = earlier.rip_target(tail)
        assert tail.mnemonic == "jmp" and slot in imports
        symbol = imports[slot]
        claimed = int(re.search(r"0x[\da-fA-F]+", row["target"])[0], 16)
        targets[hex(claimed)] += 1
        host = next((u.struct.BeginAddress for u in pe.DIRECTORY_ENTRY_EXCEPTION
                     if u.struct.BeginAddress <= site < u.struct.EndAddress), 0)
        matched = [(n, r) for n, r in by_site[site] if r["class"] == row["main_class"] == "external"
                   and r["callee"] == row["main_callee"] == symbol]
        two_counts["rows"] += 1
        two_counts["match_main_class_and_symbol"] += bool(matched)
        two_counts["match_asm_reference"] += asm_site(row["listing"]) == site
        two_counts["match_first_thunk"] += claimed == thunk
        two_counts["match_original_pdata"] += int(row["original_host"], 16) == host
        two_counts["match_candidate_listing_owner"] += int(row["candidate_owner"], 16) == owners[site]
        if site in (0x106c, 0x1072, 0x12da) or int(row["candidate_owner"], 16) != owners[site]:
            examples.append(dict(site=hex(site), thunk=hex(thunk), iat=hex(slot), symbol=symbol,
                                 submitted_thunk=hex(claimed), pdata=hex(host), owner=hex(owners[site]),
                                 submitted_owner=row["candidate_owner"], calls_lines=[n for n, r in matched]))
    assert seen == chain_controls and len(seen) == two_counts["rows"]

    memory = []
    for row in table("code/s29-owner-notes.csv"):
        if row["kind"] != "mem-dispatch":
            continue
        site = int(row["site"], 16)
        source = int(row["source_insn"].split()[0], 16)
        dispatch, load = decode(site), decode(source)
        dest, read = load.operands
        assert load.mnemonic == "mov" and dest.reg == x86.X86_REG_RAX and read.type == x86.X86_OP_MEM
        assert dispatch.mnemonic == "call" and dispatch.operands[0].mem.base == x86.X86_REG_RAX
        assert int(row["slot"], 16) == dispatch.operands[0].mem.disp and source < site
        assert not any(x86.X86_REG_RAX in decode(p).regs_access()[1] for p in row_number if source < p < site)
        memory.append(dict(site=hex(site), source=hex(source), object_load=load.op_str,
                           slot=row["slot"], submitted_line=row["main_table_line"],
                           asm_line=row_number[site], calls_line=indirect[site]))
    fragment = next(u for u in pe.DIRECTORY_ENTRY_EXCEPTION if u.struct.BeginAddress == 0x4706)
    unwind = fragment.unwindinfo
    assert unwind.Flags & 4
    parent_pos = fragment.struct.UnwindData + 4 + 2 * ((unwind.CountOfCodes + 1) & ~1)
    parent = list(map(hex, struct.unpack_from("<III", image, parent_pos)))

    def receipt_differences(path):
        lines = (item / path).read_text(encoding="utf-8-sig").splitlines()
        hashes = [re.fullmatch(r"- ([a-zA-Z0-9_./-]+) ([a-f0-9]{64})", line) for line in lines]
        differences = []
        for match in filter(None, hashes):
            name, digest = match.groups()
            actual = hashlib.sha256((item / name).read_bytes()).hexdigest()
            if digest != actual:
                differences.append([name, digest, actual])
        return {"entries": sum(bool(match) for match in hashes), "differences": differences}

    return {
        "versions": {"python": platform.python_version(), "capstone": capstone.__version__, "pefile": pefile.__version__},
        "original_sha256": controls["original_sha256"], "listing_rows": controls["listing_rows_checked"],
        "main_counts": controls["call_classes"], "direct_iat": controls["direct_iat"],
        "indirect_refs": controls["indirect_listing_refs"], "s29_com": com,
        "original_com": controls["com"], "s29_two_hop": dict(two_counts), "claimed_thunks": dict(targets),
        "two_hop_examples": examples, "memory_dispatches": memory,
        "fragment": [hex(fragment.struct.BeginAddress), hex(fragment.struct.EndAddress),
                     hex(fragment.struct.UnwindData)], "chained_parent": parent,
        "metrics_json": controls["submitted_metrics"], "s25_receipt": receipt_differences("s25-submission.md"),
        "s29_receipt": receipt_differences("s29-submission.md"),
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path)
    parser.add_argument("candidate", type=Path)
    args = parser.parse_args()
    report = compare(args.original, args.candidate)
    print(json.dumps(report, indent=2, ensure_ascii=True))
    counts = report["s29_two_hop"]
    raise SystemExit(2 if counts["match_first_thunk"] != counts["rows"] or
                     counts["match_candidate_listing_owner"] != counts["rows"] else 0)
