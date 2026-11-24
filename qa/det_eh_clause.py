
# -*- coding: utf-8 -*-
"""Exception-handling clause semantics detector.

l1_covers: no

L1 never decodes CLI EH clauses, so a clause table whose type-token column holds an IL
offset, whose handler kind disagrees with the raw flags, or whose offsets/lengths do not
match the original method body is invisible to it.

Truth is recomputed from the pinned original: MethodDef table -> method body -> chained
data sections -> clauses.  Only tables belonging to the current round are judged.
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "clause-semantics"

KINDS = {0: "catch", 1: "filter", 2: "finally", 4: "fault"}
TOKEN_MIN = 0x01000000


def _truth(original):
    import eh as method_body
    import pe as pe_reader
    data = open(original, "rb").read()
    pe = pe_reader.PE(data)
    out = {}
    errors = []
    for token, rva, impl in C.cli_methods(data):
        if not rva or (impl & 3) != 0:      # only IL bodies carry EH sections
            continue
        try:
            hdr, _eh, clauses = method_body.read(data, pe, rva)
        except Exception as exc:
            errors.append("0x%08X: %s" % (token, exc))
            continue
        if clauses:
            out[int(token)] = {"rva": rva, "code_size": hdr["code_size"], "clauses": clauses}
    return out, len(errors)


def _is_clause_table(header):
    cols = [c.lower() for c in header]
    has_method = any(c in ("method", "methoddef", "token", "method_token") for c in cols)
    has_kind = any(c in ("type", "kind", "handler_type", "clause_type") for c in cols)
    has_off = any("offset" in c for c in cols)
    return has_method and has_kind and has_off


def _int(v, base=0):
    v = (v or "").strip()
    if not v:
        return None
    try:
        return int(v, 0) if v.lower().startswith("0x") else int(v, base or 10)
    except ValueError:
        return None


MUTATED_FIXTURE = ("mutated", "fixture", "synthetic", ".mutated.")


def _is_fixture(name):
    low = name.lower()
    return any(tok in low for tok in MUTATED_FIXTURE)


def detect(task, item_dir, original, ctx):
    hits = []
    truth, decode_errors = _truth(original)
    if not truth:
        return [], {"skipped": "no EH clauses decoded from the original"}
    rows_checked = 0
    tables = 0
    found = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in sorted(fns):
            if not fn.endswith(".csv"):
                continue
            p = os.path.join(dirpath, fn)
            try:
                rows = C.read_csv(p)
            except Exception:
                continue
            if not rows or not _is_clause_table(list(rows[0].keys())):
                continue
            found.append((C.round_of(os.path.relpath(p, item_dir)) or 0, p, rows))
            continue
    newest = max([f[0] for f in found], default=0)
    for rnd, p, rows in [f for f in found if f[0] == newest]:
            tables += 1
            rel = os.path.relpath(p, item_dir)
            cols = {c.lower(): c for c in rows[0].keys()}
            mcol = next((cols[c] for c in ("method", "methoddef", "method_token", "token") if c in cols), None)
            kcol = next((cols[c] for c in ("type", "kind", "handler_type", "clause_type") if c in cols), None)
            tcol = next((cols[c] for c in ("class_token", "filter_offset", "catch_type", "token_type") if c in cols), None)
            for i, row in enumerate(rows, 2):
                token = _int(row.get(mcol))
                kind = (row.get(kcol) or "").strip().lower()
                if token is None or not kind:
                    continue
                rows_checked += 1
                loc = "%s:L%d" % (rel, i)
                flags = _int(row.get(cols.get("flags", ""), ""))
                if flags is not None and (flags & ~7):
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "clause flags %#x carry reserved bits outside 0..7" % flags})
                want = KINDS.get((flags if flags is not None else -1) & 7) if flags is not None else None
                if want and kind != want:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "flags %#x mean %s but the row says %s" % (flags, want, kind)})
                if kind == "filter" and tcol:
                    value = _int(row.get(tcol))
                    if value is not None and value < TOKEN_MIN:
                        hits.append({"severity": "defect", "locator": loc,
                                     "evidence": "%s=%#x is an IL offset, not a metadata token, in the "
                                                 "type-token column" % (tcol, value)})
                ref = truth.get(token)
                if not ref:
                    continue
                idx = _int(row.get(cols.get("index", ""), ""))
                match = ref["clauses"][idx] if idx is not None and 0 <= idx < len(ref["clauses"]) else None
                if match is None:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "method 0x%08X has %d clause(s) in the original; row index %s "
                                             "does not exist" % (token, len(ref["clauses"]), idx)})
                    continue
                for field, key in (("try_offset", "try_offset"), ("try_length", "try_length"),
                                   ("handler_offset", "handler_offset"), ("handler_length", "handler_length")):
                    got = _int(row.get(cols.get(field, ""), ""))
                    if got is not None and got != match[key]:
                        hits.append({"severity": "defect", "locator": loc,
                                     "evidence": "%s=%d but the original clause has %d"
                                                 % (field, got, match[key])})
                got_tok = _int(row.get(tcol)) if tcol else None
                if kind != "filter" and got_tok is not None and got_tok != match["class_token"]:
                    hits.append({"severity": "defect", "locator": loc,
                                 "evidence": "class_token %#x but the original clause has %#x"
                                             % (got_tok, match["class_token"])})
    return hits, {"clause_tables": tables, "rows_checked": rows_checked,
                  "methods_with_eh": len(truth), "decode_errors": decode_errors}
