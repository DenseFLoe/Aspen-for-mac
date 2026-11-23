# -*- coding: utf-8 -*-
"""Synthetic #~ fixtures: widths must follow the encoding, and break must fail loudly."""
import importlib.util, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LIB = ROOT / "tool" / "cli_tables.py"


def load():
    spec = importlib.util.spec_from_file_location("cli_tables_fixture", LIB)
    mod = importlib.util.module_from_spec(spec)
    sys.modules["cli_tables_fixture"] = mod
    spec.loader.exec_module(mod)
    return mod


def build(type_refs, method_defs):
    """Minimal metadata root + #~ header with the requested row counts (data zero-filled)."""
    tables = [(1, type_refs), (6, method_defs), (10, 1), (25, 1)]
    valid = 0
    for tid, _ in tables:
        valid |= 1 << tid
    body = struct.pack("<4sBBBB", b"\0\0\0\0", 2, 0, 0x00, 1)
    body += struct.pack("<Q", valid) + struct.pack("<Q", 0)
    body += b"".join(struct.pack("<I", rows) for _, rows in tables)
    sizes = {1: 2 + 2 + 2 + 2, 6: 4 + 2 + 2 + 2 + 2 + 2, 10: 2 + 2 + 2, 25: 2 + 2 + 2}
    stream = body + b"\0" * sum(rows * sizes[t] for t, rows in tables)
    strings = b"\0"

    ver = b"v4.0.30319\0"
    root = b"BSJB" + struct.pack("<HHII", 1, 1, 0, len(ver)) + ver + struct.pack("<HH", 0, 2)
    hdrs = b""
    for name in ("#~", "#Strings"):
        padded = name.encode() + b"\0"
        padded += b"\0" * ((4 - len(padded) % 4) % 4)
        hdrs += struct.pack("<II", 0, 0) + padded
    base = len(root) + len(hdrs)
    payload = root
    data = b""
    for name, blob in (("#~", stream), ("#Strings", strings)):
        padded = name.encode() + b"\0"
        padded += b"\0" * ((4 - len(padded) % 4) % 4)
        payload += struct.pack("<II", base + len(data), len(blob)) + padded
        data += blob
    blob = payload + data
    return blob


def main():
    ct = load()
    cases = [("A", 8191, 8191, 2, 2), ("B", 8192, 32768, 4, 4),
             ("C", 8192, 32767, 4, 2), ("D", 100, 8192, 4, 2)]
    bad = []
    for name, refs, defs, want_mrp, want_mdor in cases:
        L = ct.layout_for(build(refs, defs), 0)
        mrp = dict(L["columns"][10])["Class"]
        mdor = dict(L["columns"][25])["MethodBody"]
        print("fixture %s: MemberRefParent=%d MethodDefOrRef=%d" % (name, mrp, mdor))
        if (mrp, mdor) != (want_mrp, want_mdor):
            bad.append("%s: expected (%d,%d) got (%d,%d)" % (name, want_mrp, want_mdor, mrp, mdor))
    # negative: break the actual width rule -> fixture B must mismatch
    ct.coded_width = lambda *a: 2
    L = ct.layout_for(build(8192, 32768), 0)
    Ld = ct.layout_for(build(100, 8192), 0)
    mrp = dict(L["columns"][10])["Class"]
    if mrp != 4:
        print("NEGATIVE detected: MemberRefParent expected 4 got %d" % mrp)
        print("NEGATIVE(D) detected: MemberRefParent expected 4 got %d"
              % dict(Ld["columns"][10])["Class"])
    else:
        bad.append("negative: broken coded_width was not detected")
    print("width-fixtures: cases=%d failures=%d" % (len(cases), len(bad)))
    for b_ in bad:
        print("FAIL", b_)
    return 0 if not bad else 1


if __name__ == "__main__":
    sys.exit(main())
