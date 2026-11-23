"""Replay real ordinal and VARIANT evidence controls against NATIVE-337 s89."""
import csv
from hashlib import sha256
import json
from pathlib import Path
import shutil
import subprocess
import sys
from tempfile import TemporaryDirectory

ORIGINAL_SHA = "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"
TOOLS = {
    "s65_counterexamples.py": "26a94ce2c081fe4a2e838354993e2ebcbf74f4be9be98e7ef258aaf921d01cfa",
    "s37_two_hop.py": "8913f0902d0cdd46115c046007892da69490c432546e58749bb17c7510354819",
    "s81_showdialog.py": "04e5eabb32e3abb5c8bc0fe56f61514ec090c05a86c3d441f8b3790ba19d1e1c",
    "pe_reader.py": "5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367",
}


def digest(path):
    return sha256(path.read_bytes()).hexdigest()


def read_csv(path):
    with path.open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def run(cwd, script, *args):
    result = subprocess.run([sys.executable, "-B", str(script), *map(str, args)],
                            cwd=cwd, capture_output=True, text=True, encoding="utf-8",
                            errors="replace")
    if result.returncode or result.stderr.strip():
        raise ValueError((result.returncode, result.stdout, result.stderr))
    return result.stdout.strip()


def classify(fixed, unit, original, output):
    classes, links = output / "classes.csv", output / "links.csv"
    calls = ["--binary", original, "--folder", unit]
    run(fixed, fixed / "tool/s65_counterexamples.py", *calls, "--out", classes)
    run(fixed, fixed / "tool/s37_two_hop.py", *calls, "--out", links)
    return classes, links


def main(fixed, original):
    fixed, original = fixed.resolve(), original.resolve()
    assert digest(original) == ORIGINAL_SHA
    for name, value in TOOLS.items():
        assert digest(fixed / "tool" / name) == value
    unit = fixed / "handoff/inbox/NATIVE-337"
    listing = unit / "code/native.asm"
    data = (unit / "calls.csv").read_bytes()
    results = {"original_sha256": ORIGINAL_SHA, "tools": TOOLS}
    with TemporaryDirectory() as tmp:
        root = Path(tmp)
        original_cases, original_links = classify(fixed, unit, original, root)
        at = next(row for row in read_csv(original_cases) if int(row["site"], 16) == 0x106C)
        marker = f"mfc140.dll!#2344,external,{at['asm']}-".encode()
        assert data.count(marker) == 1
        mutated = root / "ordinal"
        (mutated / "code").mkdir(parents=True)
        shutil.copy2(listing, mutated / "code/native.asm")
        (mutated / "calls.csv").write_bytes(data.replace(marker, marker.replace(b"2344", b"2348")))
        changed_cases, changed_links = classify(fixed, mutated, original, mutated)
        results["ordinal"] = {"original_table_sha256": digest(unit / "calls.csv"),
            "changed_table_sha256": digest(mutated / "calls.csv"),
            "original_links_sha256": digest(original_links), "changed_links_sha256": digest(changed_links),
            "baseline_conflicts": [r for r in read_csv(original_cases) if r["category"] != "ok"],
            "changed_conflicts": [r for r in read_csv(changed_cases) if r["category"] != "ok"]}

        generator = root / "generator"
        script = generator / "tool"
        script.mkdir(parents=True)
        for name in ("s81_showdialog.py", "pe_reader.py"):
            shutil.copy2(fixed / "tool" / name, script / name)
        local_original = generator / "_t13/orig/FindComponent.dll"
        local_original.parent.mkdir(parents=True)
        shutil.copy2(original, local_original)
        target = generator / "handoff/inbox/NATIVE-337/code/native.asm"
        target.parent.mkdir(parents=True)
        raw = listing.read_bytes()
        before = b"000013DD  B8 08 00 00 00"
        after = b"000013DD  B8 03 00 00 00"
        assert raw.count(before) == 1
        for name, contents in (("baseline", raw), ("changed", raw.replace(before, after))):
            target.write_bytes(contents)
            run(generator, script / "s81_showdialog.py")
            entries = read_csv(target.with_name("s81-showdialog.csv"))
            results["variant_" + name] = {"listing_sha256": digest(target),
                "row": next(r for r in entries if r["item"] == "variant-vt")}
    print(json.dumps(results, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main(*map(Path, sys.argv[1:]))
