
# -*- coding: utf-8 -*-
"""omitted-sites detector.

l1_covers: no

L1 validates only the rows a submission declares; it never enumerates the sites the
original binary actually contains.  Two censuses:

  NATIVE-337 (native x64): every direct RIP-relative call/jmp that lands on an import slot.

  NATIVE-340 (mixed mode): three sources, counted separately --
    * native x64 IAT sites (same rule as above);
    * VTableFixups directory entries: each slot is a callable entry the runtime rewrites,
      so the directory itself is the expected registry;
    * managed calli sites: calli (0x29) in a MethodDef body, whose target comes from a
      managed function pointer.

Runtime-produced pointers (values materialised after load) are outside a static census;
the unit says so in its stats instead of padding inputs.
"""
import json
import os
import re

from common import *  # noqa: F401,F403
import common as C

try:
    import cli_vtable as V
except Exception:  # qa/ ships the same helper as vtable.py
    try:
        import vtable as V
    except Exception:
        V = None
try:
    import il_disasm as IL
except Exception:
    try:
        import il as IL
    except Exception:
        IL = None
try:
    import pe as PE_MOD          # qa/ ships the vendored adapter as pe.py
except Exception:
    try:
        import pe_reader as PE_MOD  # tool/ keeps the original name
    except Exception:
        PE_MOD = None

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "omitted-sites"

HEXCELL = re.compile(r"^0x[0-9a-fA-F]{2,16}$")
FIXTURE = ("mutated", "fixture", "synthetic")


def _is_fixture(name):
    low = name.lower()
    return any(tok in low for tok in FIXTURE)


def _csv_cells(item_dir, ctx):
    """(path, row) for every current-round CSV row, fixtures excluded."""
    out = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in sorted(fns):
            if not fn.lower().endswith(".csv") or _is_fixture(fn):
                continue
            p = os.path.join(dirpath, fn)
            if not C.is_current(item_dir, p, ctx):
                continue
            try:
                rows = C.read_csv(p)
            except Exception:
                continue
            for r in rows:
                out.append((os.path.relpath(p, item_dir), r))
    return out


def _native_sites(data, pe, slots):
    return C.iat_call_sites(data, pe, slots)


def _vtable_expected(data, pe, methods=None):
    if V is None or PE_MOD is None:
        return None
    try:
        # token resolution needs a flavour/name map this detector does not build;
        # slots are enumerable without it, which is what the census needs
        doc = V.read(data, PE_MOD.PE(data), None)
    except Exception:
        return None
    expected = []
    for entry in doc.get("entries", []):
        if not entry.get("width"):
            continue
        for i in range(entry.get("count", 0)):
            slot = entry["rva"] + i * entry["width"]
            token = None
            toks = entry.get("tokens") or []
            if i < len(toks):
                token = toks[i]
            expected.append({"slot": slot, "token": token, "entry": entry["index"]})
    return expected


def _calli_expected(data, pe, methods):
    if IL is None or PE_MOD is None:
        return None
    pe2 = PE_MOD.PE(data)
    out = []
    for m in methods:
        rva = m.get("rva")
        if not rva:
            continue
        try:
            code = IL.body(data, pe2.filepos, rva)
        except Exception:
            continue
        try:
            for off, mn, _op, _size in IL.decode(code):
                if mn == "calli":
                    out.append({"token": m["token"], "offset": off})
        except Exception:
            continue
    return out


def _declared_ints(item_dir, cells):
    decl = set()
    for _rel, row in cells:
        for v in row.values():
            s = (v or "").strip()
            if HEXCELL.match(s):
                try:
                    decl.add(int(s, 16))
                except ValueError:
                    pass
    return decl


def detect(task, item_dir, original, ctx):
    hits = []
    data = open(original, "rb").read()
    try:
        pe = C.prepared_pe(data)
        slots = C.iat_slots(pe)
    except Exception as exc:
        return hits, {"error": "PE/import reader failed: %s" % exc}
    cells = _csv_cells(item_dir, ctx)
    declared = _declared_ints(item_dir, cells)

    native = []
    if task == "NATIVE-337" or slots:
        native = _native_sites(data, pe, slots)
    calls_path = C.find_one(item_dir, "calls.csv")
    calls = C.read_csv(calls_path) if calls_path else []
    declared_rva = C.candidate_site_rvas(item_dir, calls, {})
    native_missing = [s for s in native if s["rva"] not in declared_rva]
    for s in native_missing:
        hits.append({"severity": "defect", "locator": "rva=0x%X" % s["rva"],
                     "evidence": "original calls %s through IAT slot 0x%X; calls.csv declares no row at this RVA"
                                 % (s["symbol"], s["slot"]),
                     "symbol": s["symbol"], "slot": "0x%X" % s["slot"]})

    prefixed = [x for x in native if x.get("prefix")]
    stats = {"native_expected": len(native), "native_missing": len(native_missing),
             "prefixed_thunks": len(prefixed),
             "sources": {"native": {"expected": len(native), "missing": len(native_missing),
                                    "prefixed": len(prefixed)}},
             "source": "native-x64"}
    if task == "NATIVE-337":
        stats["census"] = len(native)
        stats["declared_matched"] = len(native) - len(native_missing)
        stats["iat_slots"] = len(slots)
        return hits, stats

    # ---- mixed mode -------------------------------------------------------
    methods = []
    try:
        methods = C.cli_methoddefs(data)
    except Exception as exc:
        stats["cli_error"] = str(exc)
    vt_expected = _vtable_expected(data, pe, {m['token']: m for m in methods} if methods else None)
    calli_expected = _calli_expected(data, pe, methods) if methods else None

    stats["source"] = "mixed"
    stats["sources"]["native"]["prefixed"] = len(prefixed)
    stats["cli_methods"] = len(methods)
    stats["vtablefixups_expected"] = None if vt_expected is None else len(vt_expected)
    stats["calli_expected"] = None if calli_expected is None else len(calli_expected)

    if vt_expected:
        missing = [e for e in vt_expected if e["slot"] not in declared]
        stats["sources"]["vtablefixups"] = {"expected": len(vt_expected), "missing": len(missing)}
        stats["vtablefixups_missing"] = len(missing)
        for e in missing:
            hits.append({"severity": "defect", "locator": "vtablefixups entry %d slot 0x%X"
                                                  % (e["entry"], e["slot"]),
                         "evidence": "the VTableFixups directory lists this slot%s but no current-round "
                                     "table registers it" %
                                     (" (token 0x%08X)" % e["token"] if e["token"] else "")})
    if calli_expected:
        # rows can register a calli by (token, offset) cells, or by pointing at the IL line
        il_lines = {}
        for _rel, row in cells:
            ref = C.resolve_ref(item_dir, row.get("listing", "") or row.get("site", ""))
            if not ref:
                continue
            path, first, last = ref
            if path not in il_lines:
                il_lines[path] = {}
            try:
                body = C.read_text(path).splitlines()
            except Exception:
                continue
            for n in range(first, last + 1):
                if 1 <= n <= len(body):
                    il_lines[path][n] = body[n - 1]
        listing_offsets = set()
        for _rel, row in cells:
            ref = C.resolve_ref(item_dir, row.get("listing", "") or "")
            if not ref:
                continue
            text = il_lines.get(ref[0], {}).get(ref[1], "")
            m = re.search(r"IL_([0-9a-fA-F]{4})", text or "")
            if m:
                listing_offsets.add(int(m.group(1), 16))
        pairs = []
        for _rel, row in cells:
            vals = [(v or "").strip().lower() for v in row.values()]
            toks = set()
            offs = set()
            for v in vals:
                if v.startswith("0x0600") and len(v) <= 10:
                    toks.add(v)
                elif v.isdigit():
                    offs.add(int(v))
                elif v.startswith("0x") and len(v) <= 6:
                    try:
                        offs.add(int(v, 16))
                    except ValueError:
                        pass
            for t in toks:
                for o in offs:
                    pairs.append((t, o))
        declared_pairs = set(pairs)
        missing = []
        for c in calli_expected:
            tok8 = "0x%08x" % c["token"]
            if c["offset"] in listing_offsets:
                continue
            if any(t.replace("0x", "").lstrip("0") == ("%08x" % c["token"]).lstrip("0")
                   and o == c["offset"] for t, o in declared_pairs):
                continue
            missing.append(c)
        stats["calli_missing"] = len(missing)
        stats["sources"]["calli"] = {"expected": len(calli_expected), "missing": len(missing)}
        for c in missing[:40]:
            hits.append({"severity": "defect",
                         "locator": "method 0x%08X IL_%04X" % (c["token"], c["offset"]),
                         "evidence": "calli site in the original has no registered row in the current tables"})
    total = len(native) + (len(vt_expected) if vt_expected else 0) + (len(calli_expected) if calli_expected else 0)
    stats["census"] = total
    stats["declared_matched"] = total - len(native_missing) - stats.get("vtablefixups_missing", 0) - stats.get("calli_missing", 0)
    stats["iat_slots"] = len(slots)
    stats["boundary"] = ("runtime-produced function pointers are outside a static census; "
                         "the three sources above are what can be proven from the file")
    return hits, stats
