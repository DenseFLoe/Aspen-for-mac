"""Read NATIVE-337 evidence from the original and replay independent paired cases."""
from collections import Counter
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys

import capstone
from capstone.x86_const import X86_OP_MEM, X86_REG_RIP
import pefile


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def read_rows(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def trace_host(pe):
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    result = []
    for ins in decoder.disasm(pe.get_data(0x1320, 0x163), 0x1320):
        row = {"rva": hex(ins.address), "bytes": ins.bytes.hex(), "text": f"{ins.mnemonic} {ins.op_str}"}
        for op in ins.operands:
            if op.type == X86_OP_MEM and op.mem.base == X86_REG_RIP:
                row["rip_rva"] = hex(ins.address + ins.size + op.mem.disp)
        result.append(row)
    return result


def thunk_form_control(fixed):
    sys.path.insert(0, str(fixed / "tool"))
    import s65_counterexamples
    import s73_stations

    class SyntheticSection:
        def filepos(self, rva):
            assert rva == 0x1000
            return 0

    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    report = {}
    for modrm, expected in ((0x25, 0x2000), (0x05, None)):
        code = bytes((0xFF, modrm)) + struct.pack("<i", 0x2000 - 0x1006)
        ins = next(decoder.disasm(code, 0x1000, count=1))
        report[ins.mnemonic] = {"bytes": code.hex(), "instruction": f"{ins.mnemonic} {ins.op_str}",
            "expected_slot": expected, "station_deriver_slot": s73_stations.thunk_slot(code, SyntheticSection(), 0x1000),
            "classifier_slot": s65_counterexamples.thunk_slot(code, SyntheticSection(), 0x1000)}
    return report


def main():
    root = Path(sys.argv[1]).resolve()
    base = Path(sys.argv[2]).resolve()
    original = Path(sys.argv[3]).resolve()
    report_path = Path(sys.argv[4]).resolve()
    fixed = root / "fixed"
    unit = fixed / "handoff/inbox/NATIVE-337"
    checker = base / "handoff/assignments/check-native-coverage.py"
    assert digest(original) == "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
    assert digest(checker) == "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8"
    manifest = json.loads((root / "fixed-manifest.json").read_bytes())

    def run(*args):
        full = ["python", "-B", *map(str, args)]
        result = subprocess.run([sys.executable, *full[1:]], cwd=fixed, text=True,
                                encoding="utf-8", capture_output=True)
        def portable(value):
            return value.replace(str(original), "ORIGINAL").replace(str(fixed), "FIXED").replace(
                str(base), "BASE").replace(str(root), "REVIEW")
        return {"command": portable(subprocess.list2cmdline(full)), "exit": result.returncode,
                "stdout": portable(result.stdout.strip()), "stderr": portable(result.stderr.strip())}

    tools = {name: {"declared": sha, "actual": digest(fixed / name)}
             for sha, name in (line.split() for line in (unit / "work/s81-tools.txt").read_text().splitlines())}
    assert all(item["declared"] == item["actual"] for item in tools.values())
    tools.update({name: digest(fixed / name) for name in
                  ("tool/preflight.py", "tool/preflight_backtest.py", "tool/s73_stations.py")})
    pe = pefile.PE(str(original))
    scope = trace_host(pe)
    by_site = {int(row["rva"], 16): row for row in scope}
    assert by_site[0x1345]["rip_rva"] == "0x7820"
    assert pe.get_data(0x7820, 22).decode("utf-16-le") == "ShowDialog\0"
    assert by_site[0x137F]["rip_rva"] == by_site[0x1433]["rip_rva"] == "0x82f8"
    assert pe.get_data(0x82F8, 16) == bytes(16)
    appendix = read_rows(unit / "code/s81-showdialog.csv")
    assert all(by_site[int(row["rva"], 16)]["bytes"] == row["bytes"] for row in appendix)
    tests = {key: run(path) for key, path in (("jmp", "tool/s81_jmp_pair.py"),
                                              ("five", "tool/s69_tests.py"), ("six", "tool/s45_tests.py"),
                                              ("preflight_backtest", "tool/preflight_backtest.py"))}
    station = root / "stations.csv"
    station_run = run("tool/s73_stations.py", "--binary", original, "--csv", station,
                      "--json", root / "stations.json")
    assert station_run["exit"] == 0 and digest(station) == digest(unit / "code/s73-stations.csv")
    layouts = {}
    for layout in ("single", "split", "subdir"):
        output = root / f"{layout}.csv"
        result = run("tool/s65_counterexamples.py", "--folder", fixed / f"work/s49-layout-{layout}",
                     "--binary", original, "--stations", station, "--reference", root / "absent.csv", "--out", output)
        assert result["exit"] == 0
        rows = read_rows(output)
        assert Counter(row["category"] for row in rows) == {"ok": 161}
        layouts[layout] = {row["site"]: row["calls_row"] for row in rows if row["site"] in ("0x106C", "0x12DA")}

    control = root / "wrong-existing-import"
    shutil.copytree(unit, control, dirs_exist_ok=True)
    calls = control / "calls.csv"
    before = calls.read_bytes()
    old = b"KERNEL32.dll!GetUserDefaultLCID,external,code/native.asm#L242-L242"
    new = b"KERNEL32.dll!MultiByteToWideChar,external,code/native.asm#L242-L242"
    assert before.count(old) == 1
    calls.write_bytes(before.replace(old, new))
    iat = {entry.name.decode(): entry.address - pe.OPTIONAL_HEADER.ImageBase
           for desc in pe.DIRECTORY_ENTRY_IMPORT if desc.dll.lower() == b"kernel32.dll"
           for entry in desc.imports if entry.name}
    assert iat["GetUserDefaultLCID"] == 0x7060 and iat["MultiByteToWideChar"] == 0x7050
    detector = fixed / "tool/preflight.py"
    def compare(folder, label):
        result_path = root / f"preflight-{label}.json"
        result = run(detector, "--task", "NATIVE-337", "--item-dir", folder, "--original", original,
                     "--l1-path", checker, "--json", result_path)
        payload = json.loads(result_path.read_bytes())
        assert payload["l1"]["pin_ok"] and result["exit"] == payload["l1"]["exit"]
        return {"run": result, "l1_exit": payload["l1"]["exit"],
                "l2_wrong_symbol": payload["l2"]["det_wrong_symbol"],
                "l2_byte_mismatch": payload["l2"]["det_byte_mismatch"],
                "l2_receipts": payload["l2"]["det_fingerprint_pathset"],
                "calls_sha256": digest(folder / "calls.csv")}

    baseline = compare(unit, "baseline")
    mutated = compare(control, "wrong-import")
    assert baseline["l2_wrong_symbol"]["defects"] == mutated["l2_wrong_symbol"]["defects"]
    sys.path.insert(0, str(fixed / "tool"))
    import preflight
    access_pair = {}
    for label, flags in (("private", 0x0001), ("public", 0x0006)):
        folder = root / f"flags-{label}"
        folder.mkdir(exist_ok=True)
        evidence = folder / "submission.md"
        evidence.write_text(f"flags=0x{flags:04x} {label}\n", encoding="utf-8")
        hits, stats = preflight.det_access_flags("NATIVE-340", str(folder), str(original), {})
        access_pair[label] = {"flags": flags, "expected_hits": 0, "hits": hits, "input_sha256": digest(evidence)}
        assert not hits and stats["documents_checked"] == 1

    pair = thunk_form_control(fixed)
    assert pair["jmp"]["expected_slot"] == pair["jmp"]["classifier_slot"] == 0x2000
    assert pair["inc"]["expected_slot"] is None and pair["inc"]["classifier_slot"] == 0x2000
    result = {
        "head": manifest["head"], "original_sha256": digest(original), "checker_sha256": digest(checker),
        "dependencies": {"capstone": capstone.__version__, "pefile": pefile.__version__},
        "tools": tools, "tests": tests, "scope": scope, "appendix_instruction_bytes_match": len(appendix),
        "station_run": station_run, "station_count": len(read_rows(station)), "layouts": layouts,
        "unresolved": sum(row["class"] == "unresolved" for row in read_rows(unit / "calls.csv")),
        "rip_indirect_pair": pair, "access_pair": access_pair,
        "import_pair": {"original_slot_rva": "0x7060", "replacement_name_slot_rva": "0x7050",
                        "call_site": "0x1357", "old": old.decode(), "new": new.decode(),
                        "expected": "unchanged row accepted, altered import identity reported at 0x1357",
                        "baseline": baseline, "mutated": mutated},
    }
    report_path.write_text(json.dumps(result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print({key: value["exit"] for key, value in tests.items()}, layouts, pair,
          baseline["l1_exit"], mutated["l1_exit"], baseline["l2_wrong_symbol"]["defects"])


if __name__ == "__main__":
    main()
