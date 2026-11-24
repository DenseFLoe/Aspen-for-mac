# -*- coding: utf-8 -*-
"""det_access_prose (t13 fragment): the access-level MAPPING ITSELF must match ECMA-335.

Report prose that states an access mapping (e.g. "1 Public", "0x3 Assembly") is checked
against the ACCESS constant.  A prose table that disagrees with the code is a defect even
when no Flags value is claimed, which is exactly what det_access_flags misses.

ECMA-335 II.23.1.10 MemberAccessMask:
    0 CompilerControlled (privatescope)   1 Private        2 FamANDAssem
    3 Assembly                            4 Family         5 FamORAssem      6 Public

Fragment contract (see qa/gate.py, owner t16):
    REGISTRY = {name: fn} with fn(task, item_dir, original, ctx) -> (hits, stats)
"""
import os
import re

ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
ALIASES = {"privatescope": "CompilerControlled", "public": "Public", "private": "Private",
           "assembly": "Assembly", "family": "Family", "famandassem": "FamANDAssem",
           "famorassem": "FamORAssem", "compilercontrolled": "CompilerControlled"}

MAP_RE = re.compile(r"(?:^|[\s(（,，|])(0x[0-9a-fA-F]+|\d{1,2})\s*(?:\||[=:：]\s*(?:→|->|=)?)?\s*"
                    r"(public|private|assembly|family|famandassem|famorassem|privatescope|compilercontrolled)\b",
                    re.I)


def _norm(word):
    return ALIASES.get(word.strip().lower(), word.strip())


def scan(text):
    hits = []
    for line in text.splitlines():
        for num, word in MAP_RE.findall(line):
            value = int(num, 16) if num.lower().startswith("0x") else int(num, 10)
            # only values in the MemberAccessMask narrowing range can be access claims; flags
            # words (0x4013) and MethodDef tokens (0x0600xxxx) are not claims and are skipped.
            if value > 0xFF:
                continue
            if value not in ACCESS:
                hits.append("mapping value %s is outside MemberAccessMask (0..6)" % num)
                continue
            want, got = ACCESS[value], _norm(word)
            if want != got:
                hits.append("prose says %s=%s but ACCESS says %s" % (num, got, want))
    return hits


def det_access_prose(task, item_dir, original, ctx):
    """l1_covers: no

    L1 never reads report prose.  Any stated access mapping must agree with ACCESS.
    """
    hits = []
    docs = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            if fn.endswith(".md") and re.search(r"submission|audit|notes|preflight", fn, re.I):
                docs.append(os.path.join(dirpath, fn))
    for path in sorted(docs):
        text = open(path, encoding="utf-8", errors="replace").read()
        for msg in scan(text):
            hits.append({"severity": "defect", "locator": os.path.basename(path), "evidence": msg})
    return hits, {"documents_checked": len(docs), "mask": "0..6 MemberAccessMask"}


REGISTRY = {"det_access_prose": det_access_prose}

if __name__ == "__main__":
    import sys
    target = sys.argv[1] if len(sys.argv) > 1 else "handoff/inbox/NATIVE-337"
    h, s = det_access_prose("NATIVE-337", target, "", {})
    for x in h:
        print("DEFECT", x["locator"], x["evidence"])
    print("stats", s, "defects", len(h))
    sys.exit(0 if not h else 1)
