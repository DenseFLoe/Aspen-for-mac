# -*- coding: utf-8 -*-
"""access-flags detector (module split out of tool/preflight.py).

l1_covers: no
"""
import glob
import json
import os
import re

from preflight_common import *  # noqa: F401,F403
import preflight_common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "access-flags"

# ECMA-335 II.23.1.10 MemberAccessMask: 0 CompilerControlled, 1 Private, 2 FamANDAssem,
# 3 Assembly, 4 Family, 5 FamORAssem, 6 Public
ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
ACCESS_WORDS = ("public", "private", "assembly", "family", "privatescope", "compilercontrolled")

# Full-table self check (ECMA-335 II.23.1.10).  The mapping is easy to write from memory in
# the wrong order -- it already shipped inverted once -- so every value 0..6 is asserted.
_ECMA = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
         4: "Family", 5: "FamORAssem", 6: "Public"}
for _v, _name in _ECMA.items():
    assert ACCESS.get(_v) == _name, "MemberAccessMask %d must be %s, table says %r" % (_v, _name, ACCESS.get(_v))
assert len(ACCESS) == 7, "MemberAccessMask table must have exactly 7 entries"
assert ACCESS == _ECMA, "MemberAccessMask table diverges from ECMA-335 II.23.1.10"


def detect(task, item_dir, original, ctx):
    """l1_covers: no

    L1 never reads method access properties.  A claimed access level must come with the
    raw Flags value, and flags&7 must map to the claimed level.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    files = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            if fn.endswith(".md") and re.search(r"submission|audit|notes", fn, re.I):
                p = os.path.join(dirpath, fn)
                if is_current(item_dir, p):
                    files.append(p)
    for p in files:
        rel = os.path.relpath(p, item_dir)
        low = read_text(p).lower()
        claimed = [w for w in ACCESS_WORDS if w in low]
        if claimed and not re.search(r"flags\s*[=:]\s*(0x)?[0-9a-f]+", low):
            hits.append({"severity": "defect", "locator": rel,
                         "evidence": "claims access level %s without the raw Flags value" % ",".join(claimed)})
        for m in re.finditer(r"flags\s*[=:]\s*(0x)?([0-9a-fA-F]+)[^\n]*?(public|private|assembly|family|privatescope)", low):
            flags = int(m.group(2), 16)
            claimed_word = m.group(3)
            truth = ACCESS.get(flags & 7, "?").lower()
            if truth != claimed_word:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "flags=%#x maps to %s but the text says %s" % (flags, truth, claimed_word)})
    # data tables: a claimed access literal must equal ACCESS[original Flags & 0x7].  The
    # original MethodDef is re-read from the binary, so a stale or hand-written literal fails.
    tables = []
    code_dir = os.path.join(item_dir, "code")
    if os.path.isdir(code_dir):
        tables = sorted(glob.glob(os.path.join(code_dir, "s*-method-access.csv")))
    try:
        import struct
        from md_reader import parse as md_parse
        from pe_reader import PE
        data = open(original, "rb").read()
        pe = PE(data)
        cli = pe.directory(14)[0]
        md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
        methods = {m["token"]: m for m in md_parse(data, md_off)["methods"]}
    except Exception as exc:
        return hits, {"documents_checked": len(files), "tables_checked": 0,
                      "skipped": "methoddef reader unavailable: %s" % exc}
    table_rows = 0
    for path in tables:
        if not is_current(item_dir, path):
            continue
        for row in csv.DictReader(open(path, encoding="utf-8")):
            table_rows += 1
            rel = os.path.relpath(path, item_dir)
            try:
                tok = int(row["token"], 16)
            except Exception:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "unparseable token %r" % row.get("token")})
                continue
            m = methods.get(tok)
            if m is None:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "token %s is not a MethodDef of the original" % row["token"]})
                continue
            truth = derive_method_access(m["flags"], m["impl_flags"])
            if "flags" in row and int(row["flags"], 16) != m["flags"]:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "%s flags %s but original 0x%04X" % (row["token"], row["flags"], m["flags"])})
            claimed = (row.get("access") or "").strip()
            if ACCESS_ALIASES.get(claimed.lower(), claimed).lower() != truth["access"].lower():
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "%s claims %r but flags&0x7=%d -> %s"
                                         % (row["token"], claimed, m["flags"] & 7, truth["access"])})
            if "impl_flags" in row and int(row["impl_flags"], 16) != m["impl_flags"]:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "%s impl_flags %s but original 0x%04X"
                                         % (row["token"], row["impl_flags"], m["impl_flags"])})
            for key, want in (("static", truth["static"]), ("has_security", truth["has_security"])):
                if key in row and str(row[key]).strip().lower() != str(want).lower():
                    hits.append({"severity": "defect", "locator": rel,
                                 "evidence": "%s %s=%s but derived %s" % (row["token"], key, row[key], want)})
            sha = (row.get("il_sha256") or "").strip()
            if sha and len(sha) != 64:
                hits.append({"severity": "defect", "locator": rel,
                             "evidence": "%s il_sha256 has %d chars, need 64" % (row["token"], len(sha))})
    return hits, {"documents_checked": len(files), "tables_checked": len(tables),
                  "table_rows": table_rows}
