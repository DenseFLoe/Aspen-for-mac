"""Copy the fixed s33 input and apply the prior original-verified two-hop control."""

import argparse
import csv
import re
import shutil
from collections import defaultdict
from pathlib import Path


parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("candidate", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
source = args.candidate
positive = args.output


def read_csv(name):
    with (positive / name).open(encoding="utf-8-sig", newline="") as stream:
        return list(csv.DictReader(stream))


def write_csv(name, rows):
    with (positive / name).open("w", encoding="utf-8", newline="") as stream:
        writer = csv.DictWriter(stream, fieldnames=list(rows[0].keys()))
        writer.writeheader()
        writer.writerows(rows)


shutil.copytree(source, positive)
lookup = defaultdict(list)
for line, row in enumerate(read_csv("calls.csv"), 2):
    if row["class"] == "external":
        asm = re.sub(r"-L\d+$", "", row["listing"])
        lookup[asm, row["callee"]].append(line)

controls = {int(row["rva"], 16): row for row in read_csv("code/s21-two-hop.csv")}
rows = read_csv("code/s33-two-hop.csv")
for row in rows:
    site = int(row["site"], 16)
    control = controls[site]
    start, slot, symbol = re.fullmatch(r"(0x\w+) -> IAT (0x\w+) -> (.+)", control["detail"]).groups()
    row.update(first_hop=start, iat_slot=slot, import_symbol=symbol)
    call_line, = lookup[row["asm"], symbol]
    row["calls_row"] = call_line
    if site == 0x12da:
        row["candidate_owner"] = "0x12bd"
        call_12da = call_line
write_csv("code/s33-two-hop.csv", rows)

hosts = read_csv("code/s33-dual-host.csv")
for row in hosts:
    if int(row["site"], 16) == 0x12da:
        row.update(candidate_owner="0x12bd", calls_row=call_12da)
write_csv("code/s33-dual-host.csv", hosts)

history = positive / "s33-submission.md"
history.write_bytes(history.read_bytes().replace(
    "| IAT 调用/跳转站点 | 0 |".encode(), "| IAT 调用/跳转站点 | 363 |".encode(),
))

