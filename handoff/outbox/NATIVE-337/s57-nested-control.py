"""Move the same split listing to a valid relative subdirectory and replay."""
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parent

def digest(path):
    return sha256(path.read_bytes()).hexdigest()

def run(folder, output):
    fixed = ROOT / "fixed"
    result = subprocess.run(
        [sys.executable, "-B", str(fixed / "tool/s37_two_hop.py"),
         "--folder", str(folder), "--binary", str(fixed / "_t13/orig/FindComponent.dll"),
         "--out", str(output)], check=True, capture_output=True, text=True)
    with output.open(encoding="utf-8", newline="") as stream:
        rows = {row["site"]: row for row in csv.DictReader(stream)}
    pinned = {p.relative_to(folder).as_posix(): digest(p) for p in sorted(folder.rglob("*")) if p.is_file()}
    return {"exit": result.returncode, "count": len(rows), "output_sha256": digest(output),
            "inputs": pinned, "sites": {rv: rows.get(rv) for rv in ("0x106C", "0x12DA")}}


def main():
    flat = ROOT / "split"
    nested = ROOT / "nested"
    shutil.copytree(flat, nested, dirs_exist_ok=True, ignore=shutil.ignore_patterns("out.csv"))
    part = nested / "code/native-part.asm"
    new_part = nested / "code/fragment/native-part.asm"
    new_part.parent.mkdir(parents=True, exist_ok=True)
    part.replace(new_part)
    calls = nested / "calls.csv"
    old_ref, new_ref = b"code/native-part.asm#L", b"code/fragment/native-part.asm#L"
    original = (flat / "calls.csv").read_bytes()
    assert old_ref in original
    calls.write_bytes(original.replace(old_ref, new_ref))
    baseline = run(flat, ROOT / "flat-control.csv")
    baseline["inputs"].pop("out.csv", None)
    variant = run(nested, ROOT / "nested-control.csv")
    assert digest(new_part) == digest(flat / "code/native-part.asm")
    lost = baseline["count"] - variant["count"]
    assert baseline["count"] == 161 and baseline["sites"]["0x12DA"]["calls_row"] == "528"
    report = {"head": "fdad14b1ab1e3a4ed59c58a79c6b9337a69dc586", "flat": baseline, "nested": variant,
              "lost_sites": lost, "expected": {"count": 161, "sites": {"0x106C": "525", "0x12DA": "528"}}}
    (ROOT / "nested-layout.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2))


if __name__ == "__main__":
    main()
