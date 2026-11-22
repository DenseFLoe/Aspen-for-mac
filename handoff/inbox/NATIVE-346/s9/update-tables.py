"""Recreate the three current control-flow tables from the archived fifth-round snapshot."""
import argparse
import csv
import json
import re
from pathlib import Path


def rows(path):
    with path.open(encoding="utf-8-sig", newline="") as src:
        return list(csv.DictReader(src))


def write(path, data):
    with path.open("w", encoding="utf-8", newline="") as dest:
        out = csv.DictWriter(dest, fieldnames=list(data[0]), lineterminator="\n")
        out.writeheader()
        out.writerows(data)


def update(old, out, here):
    selectors = json.loads((here/"selector-bounds.json").read_text())["selectors"]
    callbacks = {r["site"]:r for r in json.loads((here/"callbacks.json").read_text())["sites"]}
    issues = {}
    for r in rows(old/"control-gaps.csv"):
        site = r["site_rva"]
        if site in callbacks:
            item = callbacks[site]
            if item["state"] == "inactive-in-image":
                continue
            issues[site] = item["basis"] + " See s9/callbacks.json."
        elif selectors[site]["status"] == "caller_length_declaration_required":
            issues[site] = "Normal length bounds verified. Obtain caller length declaration; see s9/selector-evidence.md."
    assert len(issues) == 15
    gaps = [dict(r, observation=issues[r["site_rva"]]) for r in rows(old/"control-gaps.csv") if r["site_rva"] in issues]
    calls = []
    for r in rows(old/"calls.csv"):
        if r["class"] == "unresolved":
            site = re.match(r"site (0x[0-9a-f]+),",r["note"]).group(1)
            if site not in issues:
                continue
            r["note"] = f"site {site}, {issues[site]}"
        calls.append(r)
    assert sum(r["class"] == "unresolved" for r in calls) == len(gaps)
    tables = {}
    for path in (old/"s5").glob("table-*.csv"):
        for r in rows(path):
            tables.setdefault(r["table_rva"], {})[int(r["index"])] = r["target_rva"]
    edges = []
    for edge in rows(old/"internal-transfers.csv"):
        site = edge["site_rva"]
        if site in selectors:
            s = selectors[site]
            valid = {tables[s["table"]][k] for a,b in s["normal_index_inclusive"] for k in range(a,b+1)}
            if edge["target_rva"] not in valid:
                continue
            edge["basis"] = "Normal routine entry and table index range verified in s9/selector-bounds.json"
        elif site in callbacks and callbacks[site]["state"] == "inactive-in-image":
            continue
        edges.append(edge)
    edges.append(dict(owner_rva="0x12188",site_rva="0x121c0",target_rva="0x11b24",
                      basis="Callback passed by the direct caller at 0x14e06; see s9/callbacks.json"))
    write(out/"calls.csv", calls)
    write(out/"control-gaps.csv", gaps)
    write(out/"internal-transfers.csv", edges)
    print(f"{len(calls)} references, {len(gaps)} unresolved, {len(edges)} internal edges")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("s5_unit",type=Path,help="NATIVE-346 at the pinned fifth-round candidate")
    parser.add_argument("output",type=Path,help="existing output directory")
    args = parser.parse_args()
    update(args.s5_unit,args.output,Path(__file__).resolve().parent)
