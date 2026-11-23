"""Reproduce the s61 layout and main-table association checks on a pinned copy."""
import argparse
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def read_table(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream))


def invoke(fixed, *args):
    result = subprocess.run([sys.executable, "-B", *map(str, args)], cwd=fixed,
                            capture_output=True, text=True, encoding="utf-8")
    return {"exit": result.returncode, "stdout": result.stdout.strip(), "stderr": result.stderr.strip()}


def generator(fixed, original, folder, out):
    run = invoke(fixed, "tool/s37_two_hop.py", "--folder", folder, "--binary", original, "--out", out)
    assert run["exit"] == 0, run
    rows = {r["site"]: r for r in read_table(out)}
    for ref in (row["asm"] for row in rows.values()):
        path, line = ref.split("#L")
        assert 0 < int(line) <= len((folder / path).read_text(encoding="utf-8").splitlines())
    return {"run": run, "count": len(rows), "output_sha256": digest(out),
            "sites": {address: rows[address] for address in ("0x106C", "0x12DA")}}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--fixed", type=Path, required=True)
    parser.add_argument("--original", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    fixed, original = args.fixed.resolve(), args.original.resolve()
    task = fixed / "handoff/inbox/NATIVE-337"
    original_sha = digest(original)
    assert original_sha == "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
    suite = invoke(fixed, "tool/s45_tests.py")
    assert suite["exit"] == 0, suite
    declared = json.loads((task / "work/s61-layouts.json").read_text(encoding="utf-8"))
    checker = "handoff/assignments/check-native-coverage.py"
    report = {
        "head": "6a611c74f437d5031e0b6d2dfc3c6a1ce0e3b1c1",
        "original_sha256": original_sha, "suite": suite,
        "files": {p: digest(fixed / p) for p in
                  [checker, "tool/s37_two_hop.py", "tool/s45_tests.py", "tool/pe_reader.py"]},
        "coverage": invoke(fixed, checker, "NATIVE-337", "--original", original),
        "layouts": {},
    }
    with tempfile.TemporaryDirectory(prefix="aspen-recheck-s61-") as tmp:
        work = Path(tmp)
        for name, declaration in declared.items():
            folder = fixed / declaration["dir"].replace("\\", "/")
            sources = {p.relative_to(folder).as_posix(): digest(p) for p in sorted(folder.rglob("*"))
                       if p.is_file() and p.name not in {"out.csv", "out2.csv", "out3.csv"}}
            replay = generator(fixed, original, folder, work / f"{name}.csv")
            assert replay["count"] == 161
            assert replay["sites"]["0x106C"]["calls_row"] == "525"
            assert replay["sites"]["0x12DA"]["calls_row"] == "528"
            assert replay["output_sha256"] == declaration["out_sha"]
            replay["inputs"] = sources
            replay["declared_inputs_sha256"] = declaration["inputs_sha"]
            report["layouts"][name] = replay

        missing = work / "missing"
        shutil.copytree(task, missing)
        unlinked = (missing / "calls.csv").read_bytes().splitlines(keepends=True)
        del unlinked[524]
        (missing / "calls.csv").write_bytes(b"".join(unlinked))
        report["missing_main_row"] = generator(fixed, original, missing, work / "missing.csv")
        report["missing_main_row"]["calls_sha256"] = digest(missing / "calls.csv")

        competing = work / "competing"
        shutil.copytree(task, competing)
        calls_path = competing / "calls.csv"
        all_calls = calls_path.read_bytes().splitlines(keepends=True)
        original_row = all_calls[524]
        assert b"mfc140.dll!#2344" in original_row
        calls_path.write_bytes(b"".join(all_calls + [original_row]))
        report["duplicate_main_row"] = generator(fixed, original, competing, work / "duplicate.csv")
        report["duplicate_main_row"]["calls_sha256"] = digest(calls_path)

        wrong = work / "wrong"
        shutil.copytree(task, wrong)
        calls_path = wrong / "calls.csv"
        all_calls[524] = original_row.replace(b"mfc140.dll!#2344", b"OLEAUT32.dll!#313", 1)
        calls_path.write_bytes(b"".join(all_calls))
        report["wrong_main_callee"] = generator(fixed, original, wrong, work / "wrong.csv")
        report["wrong_main_callee"]["calls_sha256"] = digest(calls_path)
        report["wrong_main_callee"]["expected_original_import"] = "mfc140.dll!#2344"
        report["wrong_main_callee"]["declared_wrong_import"] = "OLEAUT32.dll!#313"
        report["wrong_main_callee"]["coverage"] = invoke(
            fixed, checker, "NATIVE-337", "--original", original, "--submission", wrong)
    args.output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
