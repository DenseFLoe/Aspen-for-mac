"""Replay the NATIVE-337 s77 candidate against the pinned original."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys
from tempfile import TemporaryDirectory
import uuid

import capstone
from capstone.x86_const import X86_OP_MEM, X86_REG_RIP
import pefile


ORIGINAL_SHA = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
CHECKER = "handoff/assignments/check-native-coverage.py"
CHECKER_SHA = "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
CLASSIFIER = "tool/s65_counterexamples.py"


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def table(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream))


def trace(original, unit):
    pe = pefile.PE(str(original))
    base = pe.OPTIONAL_HEADER.ImageBase
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    imports = {
        entry.address - base: f"{descriptor.dll.decode()}!{entry.name.decode() if entry.name else entry.ordinal}"
        for descriptor in pe.DIRECTORY_ENTRY_IMPORT for entry in descriptor.imports
    }

    def instruction(rva):
        return next(decoder.disasm(pe.get_data(rva, 15), rva, count=1))

    def describe(rva):
        ins = instruction(rva)
        return {"rva": f"0x{rva:X}", "bytes": ins.bytes.hex(), "instruction": f"{ins.mnemonic} {ins.op_str}"}

    import_rows = []
    for rva in (0x2388, 0x23A0, 0x23C8):
        ins = instruction(rva)
        assert ins.mnemonic == "call" and ins.operands[0].type == X86_OP_MEM
        operand = ins.operands[0].mem
        assert operand.base == X86_REG_RIP
        slot = ins.address + ins.size + operand.disp
        import_rows.append({**describe(rva), "iat_slot": f"0x{slot:X}", "import_symbol": imports[slot]})

    iid_load = instruction(0x23B4)
    iid_address = iid_load.address + iid_load.size + iid_load.operands[1].mem.disp
    iid = str(uuid.UUID(bytes_le=pe.get_data(iid_address, 16)))
    progid_load = instruction(0x2375)
    progid_address = progid_load.address + progid_load.size + progid_load.operands[1].mem.disp
    progid = pe.get_data(progid_address, 96).split(b"\0", 1)[0].decode("ascii")
    assert iid == "00020400-0000-0000-c000-000000000046"
    calls = []
    for address, load in ((0x1389, 0x1354), (0x1396, 0x1390), (0x1444, 0x1400), (0x1457, 0x1451)):
        row = next(r for r in table(unit / "code/s73-four-calls.csv") if int(r["site"], 16) == address)
        ins = instruction(address)
        assert row["bytes"] == ins.bytes.hex()
        assert int(row["slot"], 16) == ins.operands[0].mem.disp
        calls.append({"call": describe(address), "vtable_load": describe(load), "slot": row["slot"],
                      "declared_member": row["member"], "declared_init_path": row["init_path"]})
    jump_targets = Counter(instruction(int(row["first_hop"], 16)).mnemonic
                           for row in table(unit / "code/s73-stations.csv"))
    return {"original_first_hop_mnemonics": dict(jump_targets), "imports": import_rows, "iid": iid, "iid_rva": f"0x{iid_address:X}",
            "progid": progid, "progid_rva": f"0x{progid_address:X}", "four_calls": calls,
            "return_chain": [describe(rva) for rva in (0x1338, 0x133D, 0x1340, 0x1343, 0x1399, 0x23A8, 0x23AC, 0x23B0, 0x23B4, 0x23BB,
                                                       0x23C0, 0x23C4, 0x23CE, 0x23D0, 0x23D2, 0x23D8)]}


def trace_host(original):
    pe = pefile.PE(str(original))
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    relevant = [(0x1320, 0x1483), (0x2330, 0x23EB)]
    results = {}
    for begin, end in relevant:
        result = []
        for ins in decoder.disasm(pe.get_data(begin, end - begin), begin):
            row = {"rva": hex(ins.address), "bytes": ins.bytes.hex(),
                   "text": f"{ins.mnemonic} {ins.op_str}"}
            for op in ins.operands:
                if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                    target = ins.address + ins.size + op.mem.disp
                    row["rip_rva"] = hex(target)
                    row["head_bytes"] = pe.get_data(target, 40).hex()
            result.append(row)
        results[hex(begin)] = result
    return results


def thunk_form_control(fixed):
    """Keep an identical RIP displacement and change only the x86 opcode extension."""
    sys.path.insert(0, str(fixed / "tool"))
    import s73_stations
    import s65_counterexamples

    class SyntheticSection:
        def filepos(self, rva):
            assert rva == 0x1000
            return 0

    report = {}
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    for modrm in (0x25, 0x05):
        code = bytes((0xFF, modrm)) + struct.pack("<i", 0x2000 - 0x1006)
        ins = next(decoder.disasm(code, 0x1000, count=1))
        report[ins.mnemonic] = {"bytes": code.hex(), "instruction": f"{ins.mnemonic} {ins.op_str}",
            "expected_slot": 0x2000 if ins.mnemonic == "jmp" else None,
            "station_deriver_slot": s73_stations.thunk_slot(code, SyntheticSection(), 0x1000),
            "classifier_slot": s65_counterexamples.thunk_slot(code, SyntheticSection(), 0x1000)}
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("fixed", type=Path)
    parser.add_argument("original", type=Path)
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    fixed, original = args.fixed.resolve(), args.original.resolve()
    unit = fixed / "handoff/inbox/NATIVE-337"
    assert digest(original) == ORIGINAL_SHA and digest(fixed / CHECKER) == CHECKER_SHA
    labels = [(str(original), "ORIGINAL"), (str(fixed), "FIXED")]

    def run(*argv):
        result = subprocess.run([sys.executable, "-B", *map(str, argv)], cwd=fixed,
                                text=True, encoding="utf-8", capture_output=True)
        def portable(text):
            for path, label in labels:
                text = text.replace(path, label)
            return text.strip()
        return {"command": portable(subprocess.list2cmdline(["python", "-B", *map(str, argv)])),
                "exit": result.returncode, "stdout": portable(result.stdout), "stderr": portable(result.stderr)}

    def coverage(folder):
        return run(CHECKER, "NATIVE-337", "--original", original, "--submission", folder)

    tools_file = unit / "work/s77-tools.txt"
    fingerprints = {name: digest(fixed / name) for _, name in (line.split() for line in tools_file.read_text().splitlines())}
    assert all(fingerprints[name] == value for value, name in (line.split() for line in tools_file.read_text().splitlines()))
    report = {
        "candidate_head": "44fcb193b159bfef5566ce1109c4d14808198d14",
        "upstream_main": "0efdc367513b4850841dff1d13ebd78cb5cea67a",
        "original_sha256": ORIGINAL_SHA, "checker_sha256": CHECKER_SHA, "tool_sha256": fingerprints,
        "dependencies": {"capstone": capstone.__version__, "pefile": pefile.__version__},
        "unresolved": sum(row["class"] == "unresolved" for row in table(unit / "calls.csv")),
        "baseline": coverage(unit), "five_cases": run("tool/s69_tests.py"), "six_cases": run("tool/s45_tests.py"),
        "factory": trace(original, unit), "paired_suite": run("tool/s77_tests.py"),
        "scope": trace_host(original), "thunk_form_control": thunk_form_control(fixed),
    }
    with TemporaryDirectory(prefix="aspen-s77-review-") as folder:
        work = Path(folder)
        labels.append((str(work), "CONTROL"))
        stations = work / "stations.csv"
        station_run = run("tool/s73_stations.py", "--binary", original, "--csv", stations,
                          "--json", work / "stations.json")
        assert station_run["exit"] == 0
        assert digest(stations) == digest(unit / "code/s73-stations.csv")
        report["station_rebuild"] = {"run": station_run, "count": len(table(stations)), "sha256": digest(stations)}

        def classify(candidate, station_file, name):
            output = work / f"{name}.csv"
            check = run(CLASSIFIER, "--folder", candidate, "--binary", original, "--stations", station_file,
                        "--reference", work / "absent.csv", "--out", output)
            rows = table(output) if output.exists() else []
            return {"run": check, "station_sha256": digest(station_file) if station_file.exists() else None,
                    "counts": dict(Counter(row["category"] for row in rows)),
                    "selected": [row for row in rows if row["site"] == "0x106C"]}

        report["layouts"] = {}
        for layout in ("single", "split", "subdir"):
            result = classify(fixed / f"work/s49-layout-{layout}", stations, layout)
            assert result["counts"] == {"ok": 161} and result["selected"][0]["calls_row"] == "525"
            report["layouts"][layout] = result

        copy = shutil.copytree(unit, work / "candidate")
        listing = copy / "code/native.asm"
        valid = listing.read_bytes()
        mutation, count = re.subn(rb"(?m)^(0000106C  E8 )32( 3A 00 00  CALL 0x180004aa3)",
                                  rb"\g<1>33\g<2>", valid)
        assert count == 1
        listing.write_bytes(mutation)
        report["displacement"] = {"listing_sha256": digest(listing), "baseline_listing_sha256": sha256(valid).hexdigest(),
                                  "expected": "byte-mismatch at 0x106C",
                                  "coverage": coverage(copy), "classifier": classify(copy, stations, "changed")}
        missing, count = re.subn(rb"(?m)^0000106C[^\r\n]+", b"; omitted 0x106C", valid)
        assert count == 1
        listing.write_bytes(missing)
        report['uncached_missing_listing'] = run(CLASSIFIER, '--folder', copy, '--binary', original, '--out', work / 'uncached.csv')
        assert report['uncached_missing_listing']['exit'] == 0
        report['uncached_missing_listing']['rows'] = [row for row in table(work / 'uncached.csv') if row['site'] == '0x106C']
        shortened = work / "stations-shortened.csv"
        shortened.write_bytes(b"".join(line for line in stations.read_bytes().splitlines(keepends=True)
                                     if not line.startswith(b"0x106C,")))
        assert len(table(shortened)) + 1 == len(table(stations))
        report["station_table_control"] = {
            "listing_sha256": digest(listing),
            "expected": "report missing 0x106C with complete stations; reject incomplete baseline or retain missing 0x106C",
            "coverage": coverage(copy), "complete": classify(copy, stations, "complete"),
            "shortened": classify(copy, shortened, "shortened"),
            "missing_baseline": classify(copy, work / "absent.csv", "missing-baseline"),
        }
    args.report.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
