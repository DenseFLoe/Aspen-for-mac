
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Equivalence check between the pinned L1 checker and our own parsers.

Both sides are run on the same candidate.  Only quantities that both sides publish are
compared: coverage rows, tool-native entries, call records, declared gaps.  Differences
are allowed to exist, but every one must carry an "explained_by" note, and the note is
stored in out/backtest/equiv_baseline.json so later runs can be diffed against it.
"""
import argparse
import csv
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "qa"))
import gate as pf  # noqa: E402

PUBLIC = {
    "coverage_rows": re.compile(r"checked\s+(\d+)\s+coverage rows"),
    "tool_native": re.compile(r"(\d+)\s+tool-native entries"),
    "call_records": re.compile(r"(\d+)\s+call records"),
    "declared_gaps": re.compile(r"(\d+)\s+declared gaps"),
}


def ours(item_dir):
    out = {}
    for key, name in (("coverage_rows", "coverage.csv"), ("tool_native", "native-functions.csv"),
                      ("call_records", "calls.csv")):
        p = pf.find_one(item_dir, name)
        out[key] = len(pf.read_csv(p)) if p else None
    p = pf.find_one(item_dir, "coverage.csv")
    out["declared_gaps"] = (sum(1 for r in pf.read_csv(p) if (r.get("state") or "").strip() == "gap")
                            if p else None)
    return out


def l1_inventory(task, original, l1_path=None):
    """L1 --inventory publishes the expected record set for the pinned original."""
    path = l1_path or os.path.join(ROOT, pf.L1_PIN["path"])
    proc = subprocess.run([sys.executable, "-B", path, task, "--original", original, "--inventory"],
                          capture_output=True, text=True)
    if proc.returncode != 0:
        return None
    try:
        return json.loads(proc.stdout)
    except Exception:
        return None


def ours_anchors(original):
    """Independent anchor census: PE entry, .pdata starts, exports that land in code."""
    import pefile
    data = open(original, "rb").read()
    pe = pefile.PE(data=data, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_EXPORT"]])
    code = [(s.VirtualAddress, s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData))
            for s in pe.sections if s.Characteristics & 0x20000000]
    def in_code(rva):
        return any(a <= rva < b for a, b in code)
    anchors = set()
    if in_code(pe.OPTIONAL_HEADER.AddressOfEntryPoint):
        anchors.add(pe.OPTIONAL_HEADER.AddressOfEntryPoint)
    for entry in getattr(pe, "DIRECTORY_ENTRY_EXPORT", None).symbols if getattr(pe, "DIRECTORY_ENTRY_EXPORT", None) else []:
        if in_code(entry.address):
            anchors.add(entry.address)
    try:
        import struct
        d = pe.OPTIONAL_HEADER.DATA_DIRECTORY[3]
        if d.VirtualAddress:
            off = pe.get_offset_from_rva(d.VirtualAddress)
            for i in range(d.Size // 12):
                begin, _end = struct.unpack_from("<II", data, off + i * 12)
                if in_code(begin):
                    anchors.add(begin)
    except Exception:
        pass
    return len(anchors)


def compare(task, item_dir, original, l1_path=None):
    l1 = pf.run_l1(task, item_dir, original, l1_path)
    theirs = {}
    for key, rx in PUBLIC.items():
        m = rx.search(l1.get("stdout") or "")
        theirs[key] = int(m.group(1)) if m else None
    mine = ours(item_dir)
    inv = l1_inventory(task, original, l1_path)
    if inv is not None:
        native_recs = sum(1 for r in inv.get("records", []) if r.get("kind") == "native")
        theirs["original_anchors"] = native_recs
        try:
            mine["original_anchors"] = ours_anchors(original)
        except Exception as exc:
            mine["original_anchors"] = None
            print("anchor census unavailable:", exc)
    diffs = []
    for key in PUBLIC:
        if theirs[key] is None or mine[key] is None:
            diffs.append({"quantity": key, "l1": theirs[key], "ours": mine[key],
                          "kind": "unpublished", "explained_by": "one side does not publish this quantity"})
            continue
        if theirs[key] != mine[key]:
            diffs.append({"quantity": key, "l1": theirs[key], "ours": mine[key], "kind": "mismatch",
                          "explained_by": None})
    return {"task": task, "item_dir": os.path.abspath(item_dir), "l1_exit": l1.get("exit"),
            "l1_sha256": l1.get("sha256"), "l1_pin_ok": l1.get("pin_ok"),
            "quantities": {"l1": theirs, "ours": mine}, "diffs": diffs}


def main(argv=None):
    ap = argparse.ArgumentParser()
    ap.add_argument("--task", default="NATIVE-337")
    ap.add_argument("--item-dir", action="append", required=True)
    ap.add_argument("--original")
    ap.add_argument("--explain", help="JSON file mapping 'item_dir:quantity' to an explanation")
    ap.add_argument("--json", default="out/backtest/equiv_baseline.json")
    ap.add_argument("--update", action="store_true", help="write the baseline file")
    a = ap.parse_args(argv)
    original = a.original or os.path.join(ROOT, pf.TASKS[a.task]["original"])
    explains = {}
    if a.explain and os.path.isfile(a.explain):
        explains = json.load(open(a.explain, encoding="utf-8"))
    results = []
    unexplained = 0
    for d in a.item_dir:
        rep = compare(a.task, d, original)
        for diff in rep["diffs"]:
            key = "%s:%s" % (os.path.basename(os.path.dirname(d)) or d, diff["quantity"])
            if not diff.get("explained_by"):
                diff["explained_by"] = explains.get(key) or explains.get(diff["quantity"])
            if diff["kind"] == "mismatch" and not diff.get("explained_by"):
                unexplained += 1
        results.append(rep)
        print("%-46s diffs=%d unexplained=%d" % (d[-46:], len(rep["diffs"]),
                                                sum(1 for x in rep["diffs"] if not x.get("explained_by"))))
        for diff in rep["diffs"]:
            print("   %-14s l1=%-6s ours=%-6s %-11s %s" % (diff["quantity"], diff["l1"], diff["ours"],
                                                            diff["kind"], (diff.get("explained_by") or "")[:70]))
    doc = {"generated_by": "qa/equiv.py", "results": results,
           "unexplained_mismatches": unexplained}
    if a.update:
        os.makedirs(os.path.dirname(a.json), exist_ok=True)
        json.dump(doc, open(a.json, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
        print("wrote", a.json)
    print("unexplained mismatches:", unexplained)
    return 0 if unexplained == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
