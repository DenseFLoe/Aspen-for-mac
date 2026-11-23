"""Reproduce s65 classification against a fixed PR head and verified original."""
import argparse
from collections import Counter
import csv
from hashlib import sha256
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile


HEAD = "25ecf96494ed0c27ba46b4181dec2cd526053a77"
MAIN = "d29e63566fa3969bc38837b38fddcb1f9ff5c044"
ORIGINAL = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
CLASSIFIER = "tool/s65_counterexamples.py"
COVERAGE = "handoff/assignments/check-native-coverage.py"
FOCUS = "0x106C"


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def run(fixed, *args):
    result = subprocess.run([sys.executable, "-B", *map(str, args)], cwd=fixed,
                            env={**os.environ, "PYTHONUTF8": "1"}, capture_output=True,
                            text=True, encoding="utf-8")
    return {"exit": result.returncode, "stdout": result.stdout.strip(), "stderr": result.stderr.strip()}


def classify(fixed, original, folder, out):
    invocation = run(fixed, CLASSIFIER, "--folder", folder, "--binary", original, "--out", out)
    assert invocation["exit"] == 0, invocation
    with out.open(encoding="utf-8", newline="") as stream:
        rows = list(csv.DictReader(stream))
    sites = {row["site"]: row for row in rows}
    assert len(sites) == len(rows)
    return {
        "run": invocation, "rows": len(rows), "categories": dict(Counter(r["category"] for r in rows)),
        "sites": {rva: sites.get(rva) for rva in (FOCUS, "0x12DA")}, "output_sha256": digest(out),
        "call_table_sha256": digest(folder / "calls.csv"),
        "listing_sha256": {
            path.relative_to(folder).as_posix(): digest(path)
            for path in sorted((folder / "code").rglob("native*.asm"))
        },
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--fixed", type=Path, required=True)
    parser.add_argument("--original", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    fixed, original = args.fixed.resolve(), args.original.resolve()
    task = fixed / "handoff/inbox/NATIVE-337"
    assert digest(original) == ORIGINAL
    submission = task / "code/s65-counterexamples.csv"
    suite = run(fixed, "tool/s45_tests.py")
    self_test = run(fixed, CLASSIFIER, "--self-test")
    coverage = run(fixed, COVERAGE, "NATIVE-337", "--original", original)
    assert suite["exit"] == self_test["exit"] == 0 and coverage["exit"] == 2
    report = {
        "head": HEAD, "trusted_main": MAIN, "original_sha256": ORIGINAL,
        "tool_sha256": {tool: digest(fixed / tool) for tool in
                        (CLASSIFIER, COVERAGE, "tool/s37_two_hop.py", "tool/s45_tests.py", "tool/pe_reader.py")},
        "six_scenarios": suite, "submission_self_test": self_test, "coverage": coverage,
        "submission_output_sha256": digest(submission),
    }
    layouts = json.loads((task / "work/s61-layouts.json").read_text(encoding="utf-8"))
    with tempfile.TemporaryDirectory(prefix="aspen-s65-recheck-") as temp:
        work = Path(temp)
        control = classify(fixed, original, task, work / "baseline.csv")
        assert control["output_sha256"] == digest(submission), control
        report["baseline"] = control
        report["layouts"] = {}
        for name, declaration in layouts.items():
            layout = fixed / declaration["dir"].replace("\\", "/")
            evidence = classify(fixed, original, layout, work / f"{name}.csv")
            assert evidence["categories"] == {"ok": 161}, evidence
            assert evidence["sites"][FOCUS]["calls_row"] == "525", evidence
            assert evidence["sites"]["0x12DA"]["calls_row"] == "528", evidence
            report["layouts"][name] = evidence

        bad_targets = {
            "existing_wrong_import": b"OLEAUT32.dll!#313",
            "ordinal_with_valid_prefix": b"mfc140.dll!#23440",
        }
        for name, target in bad_targets.items():
            folder = shutil.copytree(task, work / name)
            calls_path = folder / "calls.csv"
            lines = calls_path.read_bytes().splitlines(keepends=True)
            row = lines[524]
            expected = b"mfc140.dll!#2344"
            assert re.search(rb"(^|,)" + re.escape(expected) + rb",", row), row
            lines[524] = row.replace(expected, target, 1)
            calls_path.write_bytes(b"".join(lines))
            evidence = classify(fixed, original, folder, work / f"{name}.csv")
            evidence["changed_input"] = "calls.csv row 525, callee only"
            evidence["declared_callee"] = target.decode()
            evidence["expected_category"] = "contradiction"
            evidence["coverage"] = run(fixed, COVERAGE, "NATIVE-337", "--original", original,
                                       "--submission", folder)
            report[name] = evidence

        folder = shutil.copytree(task, work / "unlisted_site")
        listing = folder / "code/native.asm"
        lines = listing.read_bytes().splitlines(keepends=True)
        assert b"106C" in lines[27].upper(), lines[27]
        lines[27] = b"; omitted original instruction in this control" + (b"\r\n" if lines[27].endswith(b"\r\n") else b"\n")
        listing.write_bytes(b"".join(lines))
        evidence = classify(fixed, original, folder, work / "unlisted_site.csv")
        evidence["changed_input"] = "code/native.asm row 28, replaced one instruction by a comment"
        evidence["expected_category"] = "missing-evidence for original site 0x106C"
        evidence["coverage"] = run(fixed, COVERAGE, "NATIVE-337", "--original", original,
                                   "--submission", folder)
        report["unlisted_site"] = evidence

    args.output.write_text(json.dumps(report, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


if __name__ == "__main__":
    main()
