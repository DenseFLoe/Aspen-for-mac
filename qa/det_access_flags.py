
# -*- coding: utf-8 -*-
"""access-flags detector: declared member access must match the original MethodDef.

l1_covers: no

L1 never reads method access properties.  There are two independent ways to be wrong:

  * the table's raw flags column disagrees with the MethodDef Flags in the pinned
    original (one delivery wrote 0x0 / privatescope where the original says 0x4013);
  * the access literal disagrees with ECMA-335 MemberAccessMask for its own flags.

inputs_checked is the number of table rows examined, not 1.
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "access-flags"

# ECMA-335 II.23.1.10 MemberAccessMask: 0 CompilerControlled, 1 Private, 2 FamANDAssem,
# 3 Assembly, 4 Family, 5 FamORAssem, 6 Public
ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
_ECMA = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
         4: "Family", 5: "FamORAssem", 6: "Public"}
for _v, _name in _ECMA.items():
    assert ACCESS.get(_v) == _name, "MemberAccessMask %d must be %s, table says %r" % (
        _v, _name, ACCESS.get(_v))
assert len(ACCESS) == 7, "MemberAccessMask table must have exactly 7 entries"
assert ACCESS == _ECMA, "MemberAccessMask table diverges from ECMA-335 II.23.1.10"

ACCESS_WORDS = ("public", "private", "assembly", "family", "privatescope", "compilercontrolled")
ALIAS = {"privatescope": "compilercontrolled", "internal": "assembly",
         "protected": "family", "protected internal": "famorassem"}
FLAG_COLS = ("flags", "method_flags", "methodflags", "member_flags")
ACCESS_COLS = ("access", "accessibility", "visibility", "member_access", "access_level")


def _int(v):
    v = (v or "").strip()
    if not v:
        return None
    try:
        return int(v, 0) if v.lower().startswith("0x") else int(v, 16)
    except ValueError:
        return None


def _norm(word):
    raw = (word or "").strip().lower()
    return ALIAS.get(raw, raw.replace(" ", ""))


def _pick(cols, cands):
    low = {c.lower(): c for c in cols}
    for c in cands:
        if c in low:
            return low[c]
    return None


def _tables(item_dir):
    out = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in sorted(fns):
            if not fn.lower().endswith(".csv") or _is_fixture(fn):
                continue
            p = os.path.join(dirpath, fn)
            try:
                rows = C.read_csv(p)
            except Exception:
                continue
            if not rows:
                continue
            cols = list(rows[0].keys())
            if _pick(cols, FLAG_COLS) and _pick(cols, ACCESS_COLS):
                out.append((p, rows, C.round_of(os.path.relpath(p, item_dir)) or 0))
    return out


MUTATED_FIXTURE = ("mutated", "fixture", "synthetic", ".mutated.")


def _is_fixture(name):
    low = name.lower()
    return any(tok in low for tok in MUTATED_FIXTURE)


def detect(task, item_dir, original, ctx):
    hits = []
    checked = 0
    data = open(original, "rb").read()
    try:
        pe = C.prepared_pe(data)
        dd = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
    except Exception as exc:
        return hits, {"error": "PE optional header unreadable: %s" % exc}
    if not dd.VirtualAddress or not dd.Size:
        # a native-only image has no member access to check: that is not a failure, and it
        # is not a pass either
        return hits, {"skipped": "no CLI metadata (native-only image)"}
    tables = _tables(item_dir)
    if not tables:
        return hits, {"skipped": "no method-access table with flags+access columns"}
    newest = max(t[2] for t in tables)
    try:
        methods = {m["token"]: m for m in C.cli_methoddefs(data)}
        by_rva = {m["rva"]: m for m in methods.values() if m.get("rva")}
        if not methods:
            return hits, {"error": "CLI directory present but the MethodDef table is empty"}
    except Exception as exc:
        return hits, {"error": "CLI present but the MethodDef reader failed: %s" % exc}
    for path, rows, rnd in tables:
        if rnd < newest:
            continue  # frozen historical table; the newest one describes this delivery
        rel = os.path.relpath(path, item_dir)
        cols = list(rows[0].keys())
        fcol, acol = _pick(cols, FLAG_COLS), _pick(cols, ACCESS_COLS)
        tcol = _pick(cols, ("token", "methoddef", "method", "method_token"))
        rcol = _pick(cols, ("rva", "method_rva"))
        for i, row in enumerate(rows, 2):
            checked += 1
            loc = "%s:L%d" % (rel, i)
            flags = _int(row.get(fcol))
            token = _int(row.get(tcol)) if tcol else None
            rva = _int(row.get(rcol)) if rcol else None
            orig = methods.get(token) if token else (by_rva.get(rva) if rva else None)
            access = _norm(row.get(acol))
            if flags is not None and orig and orig.get("flags") is not None:
                if int(flags) != int(orig["flags"]):
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "declares flags=%#x but the original MethodDef 0x%08X has %#x"
                                             % (flags, orig["token"], orig["flags"])})
            if access and flags is not None:
                want = ACCESS.get(int(flags) & 7)
                if want and _norm(want) != access:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "access=%s but flags=%#x map to %s"
                                             % (row.get(acol), flags, want)})
            if access and orig and orig.get("flags") is not None:
                want_orig = ACCESS.get(int(orig["flags"]) & 7)
                if want_orig and _norm(want_orig) != access:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "access=%s but the original MethodDef 0x%08X has flags %#x = %s"
                                             % (row.get(acol), orig["token"], orig["flags"], want_orig)})
    return hits, {"method_access_tables": len(tables), "rows_checked": checked,
                  "methods_in_original": len(methods)}
