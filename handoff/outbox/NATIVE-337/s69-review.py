"""Replay the fixed s69 handoff and compare the cited instruction with the PE."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile

import capstone
from capstone.x86_const import X86_OP_IMM, X86_OP_MEM, X86_REG_RIP
import pefile


ORIGINAL = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
CHECKER = "handoff/assignments/check-native-coverage.py"
CHECKER_SHA = "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
CLASSIFIER = "tool/s65_counterexamples.py"


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def table(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream))


def original_sites(original, unit):
    pe = pefile.PE(str(original))
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    iat = {entry.address - pe.OPTIONAL_HEADER.ImageBase:
           library.dll.decode() + "!" + (f"#{entry.ordinal}" if entry.import_by_ordinal else entry.name.decode())
           for library in pe.DIRECTORY_ENTRY_IMPORT for entry in library.imports}
    result = {}

    def scan(start, end):
        for op in decoder.disasm(pe.get_data(start, end - start), start):
            if op.mnemonic not in {"call", "jmp"} or op.operands[0].type != X86_OP_IMM:
                continue
            target = op.operands[0].imm
            if not 0 <= target < pe.OPTIONAL_HEADER.SizeOfImage:
                continue
            thunk = next(decoder.disasm(pe.get_data(target, 15), target, count=1), None)
            if not thunk or thunk.mnemonic not in {"call", "jmp"} or thunk.operands[0].type != X86_OP_MEM:
                continue
            memory = thunk.operands[0].mem
            slot = thunk.address + thunk.size + memory.disp
            if memory.base == X86_REG_RIP and slot in iat:
                result[op.address] = (target, slot, iat[slot], op.bytes.hex())

    for entry in pe.DIRECTORY_ENTRY_EXCEPTION:
        scan(entry.struct.BeginAddress, entry.struct.EndAddress)
    from_unwind = len(result)
    spans = sorted(int(row["rva"], 0) for row in table(unit / "native-functions.csv"))
    for section in pe.sections:
        if not section.Characteristics & 0x20000000:
            continue
        end = section.VirtualAddress + min(section.Misc_VirtualSize, section.SizeOfRawData)
        starts = [rva for rva in spans if section.VirtualAddress <= rva < end]
        for start, stop in zip(starts, starts[1:] + [end]):
            scan(start, stop)
    return from_unwind, result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("fixed", type=Path)
    parser.add_argument("original", type=Path)
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    fixed, original = args.fixed.resolve(), args.original.resolve()
    unit = fixed / "handoff/inbox/NATIVE-337"
    assert digest(original) == ORIGINAL and digest(fixed / CHECKER) == CHECKER_SHA

    def run(*argv):
        result = subprocess.run([sys.executable, "-B", *map(str, argv)], cwd=fixed,
                                text=True, encoding="utf-8", capture_output=True)
        return {"command": subprocess.list2cmdline(["python", "-B", *map(str, argv)]),
                "exit": result.returncode, "stdout": result.stdout.strip(),
                "stderr": result.stderr.strip()}

    def coverage(folder):
        return run(CHECKER, "NATIVE-337", "--original", original, "--submission", folder)

    reference = unit / "code/s37-two-hop.csv"
    from_unwind, derived = original_sites(original, unit)
    supplied = {int(r["site"], 16): (int(r["first_hop"], 16), int(r["iat_slot"], 16), r["import_symbol"])
                for r in table(reference)}
    assert {rva: values[:3] for rva, values in derived.items()} == supplied
    report = {
        "head": "12bca3ef1f92a7f3bc9ec9f575caff37bf62a610",
        "main": "7ce64a251d9c5210041903988c016a53b3f85287",
        "original_sha256": ORIGINAL, "from_unwind": from_unwind, "original_decoded_sites": len(derived),
        "libraries": {"capstone": capstone.__version__, "pefile": pefile.__version__},
        "fingerprints": {p: digest(fixed / p) for p in (
            CHECKER, CLASSIFIER, "tool/s37_two_hop.py", "tool/pe_reader.py", "tool/s45_tests.py", "tool/s69_tests.py"
        )},
        "reference_sha256": digest(reference), "baseline_coverage": coverage(unit),
        "six_cases": run("tool/s45_tests.py"), "three_cases": run("tool/s69_tests.py"),
    }
    assert [report[k]["exit"] for k in ("baseline_coverage", "six_cases", "three_cases")] == [2, 0, 0]
    with tempfile.TemporaryDirectory(prefix="aspen-s69-review-") as tmp:
        work = Path(tmp)

        def classify(folder, name, ref=reference):
            output = work / f"{name}.csv"
            check = run(CLASSIFIER, "--folder", folder, "--binary", original, "--reference", ref, "--out", output)
            assert check["exit"] == 0, check
            rows = table(output)
            selected = {r["site"]: r for r in rows if r["site"] in {"0x106C", "0x12DA"}}
            return {"run": check, "counts": dict(Counter(row["category"] for row in rows)),
                    "selected": selected, "output_sha256": digest(output)}

        report["layouts"] = {}
        for layout in ("single", "split", "subdir"):
            result = classify(fixed / f"work/s49-layout-{layout}", layout)
            assert result["counts"] == {"ok": len(derived)}
            assert [result["selected"][site]["calls_row"] for site in ("0x106C", "0x12DA")] == ["525", "528"]
            report["layouts"][layout] = result

        candidate = shutil.copytree(unit, work / "changed")
        listing = candidate / "code/native.asm"
        before = listing.read_bytes()
        edit = rb"(?m)^(0000106C  E8 )32( 3A 00 00  CALL 0x180004aa3)"
        changed, count = re.subn(edit, rb"\g<1>33\g<2>", before)
        assert count == 1 and derived[0x106C][3] == "e8323a0000"
        listing.write_bytes(changed)
        report["changed_displacement"] = {
            "expected": "reject the listing bytes at RVA 0x106C (original encodes 0x4AA3)",
            "evidence": "code/native.asm row 28; E8 32 3A 00 00 -> E8 33 3A 00 00 (encodes 0x4AA4)",
            "original_listing_sha256": sha256(before).hexdigest(),
            "changed_listing_sha256": digest(listing), "coverage": coverage(candidate),
            "classifier": classify(candidate, "changed"),
        }
        removed, count = re.subn(rb"(?m)^0000106C[^\r\n]+", b"; omitted instruction at 0x106C", before)
        assert count == 1
        listing.write_bytes(removed)
        without = classify(candidate, "without-old-table", work / "nonexistent.csv")
        with_reference = classify(candidate, "with-old-table")
        report["no_reference"] = {
            "expected": "derive 0x106C from the original even without a historical site list",
            "changed_listing_sha256": digest(listing), "coverage": coverage(candidate),
            "with_reference": with_reference, "without_reference": without,
        }
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
