"""Replay one listing and its equivalent two-file layout against the fixed generator."""

import csv
from hashlib import sha256
import json
from pathlib import Path
import re
import shutil
import subprocess
import sys


ROOT = Path(__file__).resolve().parent
FIXED = ROOT / (sys.argv[1] if len(sys.argv) == 2 else "fixed")
BASE = FIXED / "handoff/inbox/NATIVE-337"
BINARY = FIXED / "_t13/orig/FindComponent.dll"
GENERATOR = FIXED / "tool/s37_two_hop.py"
SINGLE = ROOT / "single"
SPLIT = ROOT / "split"


def read_table(path):
    with path.open(encoding="utf-8", newline="") as stream:
        return list(csv.DictReader(stream))


def fingerprint(path):
    return sha256(path.read_bytes()).hexdigest()


def run(folder):
    result = subprocess.run(
        [sys.executable, "-B", str(GENERATOR), "--folder", str(folder),
         "--binary", str(BINARY), "--out", str(folder / "out.csv")],
        capture_output=True, text=True,
    )
    result.check_returncode()
    return result, {entry["site"]: entry for entry in read_table(folder / "out.csv")}


for folder in (SINGLE, SPLIT):
    (folder / "code").mkdir(parents=True, exist_ok=True)
shutil.copyfile(BASE / "calls.csv", SINGLE / "calls.csv")
shutil.copyfile(BASE / "code/native.asm", SINGLE / "code/native.asm")
asm = (BASE / "code/native.asm").read_bytes().splitlines(keepends=True)
head = next(n for n, line in enumerate(asm, 1) if line.startswith(b"; FUNC 000012BD-"))
end = next(n for n, line in enumerate(asm, 1) if n > head and line.startswith(b"; FUNC "))
move = next(n for n, line in enumerate(asm, 1) if line.startswith(b"000012DA "))
stay = next(n for n, line in enumerate(asm, 1) if line.startswith(b"0000106C "))
delta = stay - move
assert 0 < head + delta < stay < head <= move < end
(SPLIT / "code/native.asm").write_bytes(
    b"".join(asm[:head - 1] + [b"; moved to native-part.asm\n"] * (end - head) + asm[end - 1:]))
(SPLIT / "code/native-part.asm").write_bytes(b"; layout padding\n" * (head + delta - 1)
                                            + b"".join(asm[head - 1:end - 1]))
rows = read_table(BASE / "calls.csv")
for row in rows:
    span = re.fullmatch(r"code/native.asm#L(\d+)(?:-L(\d+))?", row["listing"])
    if span and head <= int(span[1]) < end:
        first = int(span[1]) + delta
        last = f"-L{int(span[2]) + delta}" if span[2] else ""
        row["listing"] = f"code/native-part.asm#L{first}{last}"
with (SPLIT / "calls.csv").open("w", encoding="utf-8", newline="") as stream:
    writer = csv.DictWriter(stream, list(rows[0]))
    writer.writeheader()
    writer.writerows(rows)
output = {"layout_check_command": f"python -B s57-layout.py {FIXED.name}",
          "original_sha256": fingerprint(BINARY), "generator_sha256": fingerprint(GENERATOR),
          "reader_sha256": fingerprint(GENERATOR.with_name("pe_reader.py"))}
single, original = run(SINGLE)
split, rearranged = run(SPLIT)
assert original.keys() == rearranged.keys()
for name, folder, result, entries in (("single", SINGLE, single, original), ("split", SPLIT, split, rearranged)):
    output[name] = {
        "exit": result.returncode, "sites": len(entries),
        "inputs": {p.relative_to(folder).as_posix(): fingerprint(p)
                   for p in sorted(folder.rglob("*")) if p.is_file() and p.name != "out.csv"},
        "output_sha256": fingerprint(folder / "out.csv"),
        "first_site": entries["0x106C"], "moved_site": entries["0x12DA"],
    }
output["expected"] = {"moved_site_calls_row": original["0x12DA"]["calls_row"],
                      "moved_site_listing": f"code/native-part.asm#L{stay}",
                      "sites": len(original)}
output["mismatched_main_rows"] = [
    {"site": site, "expected": before["calls_row"], "actual": rearranged[site]["calls_row"]}
    for site, before in original.items() if before["calls_row"] != rearranged[site]["calls_row"]
]
assert rearranged["0x12DA"]["asm"] == output["expected"]["moved_site_listing"]
assert rearranged["0x12DA"]["original_host"] == original["0x12DA"]["original_host"]
assert rearranged["0x12DA"]["candidate_owner"] == original["0x12DA"]["candidate_owner"]
assert rows[int(original["0x12DA"]["calls_row"]) - 2]["listing"].startswith("code/native-part.asm#")
assert rows[int(original["0x106C"]["calls_row"]) - 2]["listing"].startswith("code/native.asm#")
print(json.dumps(output, indent=2))
