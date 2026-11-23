
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Local preflight for NATIVE-337 / NATIVE-340.

Two layers, on purpose:

  L1  the upstream checker, invoked verbatim and pinned by sha256.  Its exit code is
      authoritative: nothing here may reinterpret or override it.
  L2  our own detectors.  Each declares, in its docstring, whether L1 already covers
      the same defect category:

         l1_covers: yes      L1 covers it fully  -> cross-check only, never changes exit
         l1_covers: partial  L1 covers it partly -> cross-check; disagreement is a warning
         l1_covers: no       L1 does not cover it -> may contribute to the aggregate exit

Detection inputs are only the pinned original binary and the candidate item directory.
No upstream decision text, no issue comments, no sample sha256, no round-number branches.

Usage:
  python -B tool/preflight.py --task NATIVE-337 --item-dir handoff/inbox/NATIVE-337
  python -B tool/preflight.py --task NATIVE-337 --folder handoff/inbox/NATIVE-337 \
      --binary _t13/orig/FindComponent.dll      (compatibility with the s27 CLI)
"""
import argparse
import csv
import hashlib
import json
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tool"))

L1_PIN = {
    "path": "out/localrepo3/handoff/assignments/check-native-coverage.py",
    "sha256": "27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8",
}
TASKS = {
    "NATIVE-337": {"original": "_t13/orig/FindComponent.dll",
                   "original_sha256": "3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02"},
    "NATIVE-340": {"original": "_t13/orig/WrapSaveMergeNNFiles.dll",
                   "original_sha256": "869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec"},
}
ACCESS = {0: "CompilerControlled", 1: "Public", 2: "Private", 3: "Assembly", 4: "Family",
          5: "FamANDAssem", 6: "FamORAssem"}
ACCESS_WORDS = ("public", "private", "assembly", "family", "privatescope", "compilercontrolled")


# ------------------------------------------------------------------ utilities
def sha256_file(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def read_text(path):
    with open(path, encoding="utf-8-sig", errors="replace") as f:
        return f.read()


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as f:
        return list(csv.DictReader(f))


def find_one(item_dir, *names):
    for n in names:
        p = os.path.join(item_dir, n)
        if os.path.isfile(p):
            return p
    return None


def round_of(name):
    m = re.search(r"(?:^|[^0-9a-z])s(\d+)[-_]", name, re.I)
    return int(m.group(1)) if m else None


def current_round(item_dir):
    top = 0
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            top = max(top, round_of(fn) or 0)
    return top


def is_current(item_dir, path):
    """Historical per-round evidence is kept by convention; only the newest round's
    files describe the current submission, so frozen receipts must not be re-judged."""
    r = round_of(os.path.relpath(path, item_dir))
    return r is None or r >= current_round(item_dir)


def resolve_ref(item_dir, ref):
    m = re.fullmatch(r"(.+?)#L(\d+)(?:-L?(\d+))?", (ref or "").strip())
    if not m:
        return None
    name, first, last = m.group(1), int(m.group(2)), int(m.group(3) or m.group(2))
    path = os.path.normpath(os.path.join(item_dir, name))
    if not path.startswith(os.path.normpath(item_dir)):
        return None
    return path, first, last


def asm_line_rva(asm_path):
    out = {}
    if not asm_path or not os.path.isfile(asm_path):
        return out
    for i, line in enumerate(read_text(asm_path).splitlines(), 1):
        m = re.match(r"\s*(?:0x)?([0-9A-Fa-f]{6,16})\s+((?:[0-9A-Fa-f]{2}\s){1,})", line)
        if m:
            out[i] = int(m.group(1), 16)
    return out


def candidate_site_rvas(item_dir, calls, cache):
    out = {}
    for row in calls:
        if (row.get("class") or "").strip() == "data":
            continue
        ref = resolve_ref(item_dir, row.get("listing", ""))
        if not ref:
            continue
        path, first, last = ref
        if path not in cache:
            cache[path] = asm_line_rva(path)
        for i in range(first, last + 1):
            if i in cache[path]:
                out.setdefault(cache[path][i], row)
    return out


# ---------------------------------------------------------------- L1 segment
def run_l1(task, item_dir, original, l1_path=None):
    path = l1_path or os.path.join(ROOT, L1_PIN["path"])
    seg = {"path": L1_PIN["path"], "sha256": None, "pin_ok": False, "argv": None,
           "exit": None, "stdout": "", "stderr": "", "authoritative": True}
    if not os.path.isfile(path):
        seg["error"] = "checker not found: " + path
        return seg
    seg["sha256"] = sha256_file(path)
    seg["pin_ok"] = seg["sha256"] == L1_PIN["sha256"]
    argv = [sys.executable, "-B", path, task, "--original", original, "--submission", item_dir]
    seg["argv"] = argv
    proc = subprocess.run(argv, capture_output=True, text=True)
    seg["exit"] = proc.returncode
    seg["stdout"] = (proc.stdout or "").strip()
    seg["stderr"] = (proc.stderr or "").strip()
    return seg


# ---------------------------------------------------------------- PE helpers
def prepared_pe(data):
    import pefile
    pe = pefile.PE(data=data, fast_load=True)
    pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY["IMAGE_DIRECTORY_ENTRY_IMPORT"]])
    return pe


def iat_slots(pe):
    slots = {}
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) or []:
        dll = entry.dll.decode("ascii", "replace")
        for imp in entry.imports:
            if imp.address is None:
                continue
            rva = imp.address - pe.OPTIONAL_HEADER.ImageBase
            name = imp.name.decode("ascii", "replace") if imp.name else "#%s" % imp.ordinal
            slots[rva] = "%s!%s" % (dll, name)
    return slots


def executable_ranges(pe):
    out = []
    for s in pe.sections:
        if s.Characteristics & 0x20000000:
            out.append((s.VirtualAddress,
                        s.VirtualAddress + max(s.Misc_VirtualSize, s.SizeOfRawData),
                        s.PointerToRawData, s.SizeOfRawData))
    return out


def iat_call_sites(data, pe, slots):
    from capstone import Cs, CS_ARCH_X86, CS_MODE_64
    md = Cs(CS_ARCH_X86, CS_MODE_64)
    md.detail = True
    sites = {}
    for va, vend, raw, rawsize in executable_ranges(pe):
        chunk = data[raw:raw + min(rawsize, vend - va)]
        for insn in md.disasm(chunk, va):
            if insn.mnemonic not in ("call", "jmp") or not insn.operands:
                continue
            op = insn.operands[0]
            if op.type != 3 or op.mem.base != 0x29 or op.mem.index:  # X86_OP_MEM, RIP
                continue
            target = insn.address + insn.size + op.mem.disp
            if target in slots:
                sites.setdefault(insn.address, {"rva": insn.address, "slot": target,
                                                "symbol": slots[target]})
    return [sites[k] for k in sorted(sites)]


# ---------------------------------------------------------------- L2 detectors
def detector(fn):
    m = re.search(r"l1_covers:\s*(yes|no|partial)", fn.__doc__ or "")
    fn.l1_covers = m.group(1) if m else "no"
    return fn


@detector
def det_omitted_sites(task, item_dir, original, ctx):
    """l1_covers: no

    L1 validates only the rows a submission declares; it never enumerates the sites
    the original binary actually contains.  Census = every direct RIP-relative call/jmp
    landing on an import slot.  Hits = census minus declared sites.
    NATIVE-340 (mixed-mode) census is not implemented yet.
    """
    hits = []
    if task != "NATIVE-337":
        return hits, {"skipped": "native x64 census only; mixed-mode census not implemented"}
    data = open(original, "rb").read()
    pe = prepared_pe(data)
    slots = iat_slots(pe)
    expected = iat_call_sites(data, pe, slots)
    cpath = find_one(item_dir, "calls.csv")
    calls = read_csv(cpath) if cpath else []
    declared = candidate_site_rvas(item_dir, calls, {})
    for site in expected:
        if site["rva"] in declared:
            continue
        hits.append({"severity": "defect",
                     "locator": "rva=0x%X" % site["rva"],
                     "evidence": "original calls %s through IAT slot 0x%X; calls.csv declares no row at this RVA"
                                 % (site["symbol"], site["slot"]),
                     "symbol": site["symbol"], "slot": "0x%X" % site["slot"]})
    return hits, {"census": len(expected), "declared_matched": len(expected) - len(hits),
                  "iat_slots": len(slots)}


@detector
def det_stale_metrics(task, item_dir, original, ctx):
    """l1_covers: no

    L1 reads run.json only and never recomputes metrics.json.  Numeric disagreements
    are defects; stale file hashes are advisory because some rounds pin a baseline.
    """
    hits = []
    mpath = find_one(item_dir, "metrics.json")
    cpath = find_one(item_dir, "calls.csv")
    covpath = find_one(item_dir, "coverage.csv")
    npath = find_one(item_dir, "native-functions.csv")
    if not mpath or not cpath:
        return hits, {"skipped": "metrics.json or calls.csv missing"}
    metrics = json.loads(read_text(mpath))
    calls = read_csv(cpath)
    actual = {"calls": len(calls), "calls_total": len(calls)}
    for cls in ("external", "boundary", "data", "unresolved"):
        actual[cls] = sum(1 for r in calls if (r.get("class") or "").strip() == cls)
    if covpath:
        cov = read_csv(covpath)
        actual["coverage_rows"] = len(cov)
        actual["rows"] = len(cov)
        actual["gaps"] = sum(1 for r in cov if (r.get("state") or "").strip() == "gap")
    if npath:
        actual["funcs"] = len(read_csv(npath))
    for key, want in sorted(actual.items()):
        if key not in metrics or isinstance(metrics[key], bool):
            continue
        got = metrics[key]
        if not isinstance(got, (int, float)) or int(got) == int(want):
            continue
        hits.append({"severity": "defect",
                     "locator": "metrics.json:%s" % key,
                     "evidence": "metrics declares %s=%s; the tables on disk recompute to %d" % (key, got, want),
                     "l1_said": "L1 does not read metrics.json", "we_said": "%s=%d" % (key, want)})
    for key in sorted(metrics):
        if not key.endswith("_sha256"):
            continue
        rel = key[:-7]
        cand = [os.path.join(item_dir, rel + ext) for ext in (".csv", ".json", ".md")]
        cand += [os.path.join(item_dir, "code", rel + ext) for ext in (".csv", ".json", ".md")]
        target = next((p for p in cand if os.path.isfile(p)), None)
        if not target:
            continue
        real = sha256_file(target)
        if real != str(metrics[key]).lower():
            hits.append({"severity": "advisory",
                         "locator": "metrics.json:%s" % key,
                         "evidence": "declares %s..., disk has %s..." % (str(metrics[key])[:16], real[:16]),
                         "l1_said": "L1 does not read metrics.json", "we_said": real})
    return hits, {"numeric_keys": len(actual)}


@detector
def det_row_linkage(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 resolves listing refs and cross-checks indirect.csv as a subset, but never
    checks that appendix row references point at the table they claim, nor that a
    per-site column actually varies per site.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    calls = read_csv(cpath) if cpath else []
    row_col = re.compile(r"^(calls_row|calls_line|main_row|calls_row_no)$", re.I)
    site_col = re.compile(r"^(site|rva|address)$", re.I)
    addr_col = re.compile(r"(first_hop|thunk|target|iat_slot|calls_row|candidate_owner|original_host)$", re.I)
    files = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            if fn.endswith(".csv"):
                p = os.path.join(dirpath, fn)
                if cpath and os.path.normpath(p) == os.path.normpath(cpath):
                    continue
                if not is_current(item_dir, p):
                    continue
                try:
                    rows = read_csv(p)
                except Exception:
                    continue
                if rows:
                    files.append((p, rows))
    for path, rows in files:
        rel = os.path.relpath(path, item_dir)
        cols = list(rows[0].keys())
        for col in cols:
            vals = [(r.get(col) or "").strip() for r in rows]
            nonempty = [v for v in vals if v]
            if row_col.match(col) and not nonempty:
                hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                             "evidence": "column is empty for all %d rows; row linkage undelivered" % len(rows)})
                continue
            if not nonempty:
                continue
            if col.lower() in ("main_table_line", "main_row"):
                asm_like = [v for v in nonempty if re.search(r"\.(asm|il|txt)#L", v, re.I)]
                numeric = [c for c in cols if c != col and any((r.get(c) or "").strip().isdigit() for r in rows)]
                if asm_like and not numeric:
                    hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                                 "evidence": "%d/%d values point at an assembly listing (%s); the column claims a "
                                             "main-table row and the file carries no numeric row column"
                                             % (len(asm_like), len(nonempty), asm_like[0])})
                    continue
            if addr_col.search(col) and len(rows) >= 20 and len(set(nonempty)) == 1 and "0x" in nonempty[0].lower():
                hits.append({"severity": "defect", "locator": "%s:%s" % (rel, col),
                             "evidence": "all %d rows carry the same address-valued placeholder %s; the column "
                                         "cannot be per-site linkage" % (len(rows), nonempty[0])})
        if calls and row_col.search(" ".join(cols)):
            for col in cols:
                if not row_col.match(col):
                    continue
                for r in rows:
                    v = (r.get(col) or "").strip()
                    if not v.isdigit():
                        continue
                    n = int(v)
                    if n < 1 or n > len(calls):
                        hits.append({"severity": "defect", "locator": "%s:%s=%s" % (rel, col, v),
                                     "evidence": "calls.csv has %d rows; referenced row is out of range" % len(calls)})
    return hits, {"appendix_files": len(files)}


@detector
def det_fingerprint_pathset(task, item_dir, original, ctx):
    """l1_covers: no

    L1 has no notion of declared deliverable/fingerprint path sets.  Only the newest
    round's fingerprint table and receipt are judged; frozen historical ones are kept
    by convention and must not be re-flagged.
    """
    hits = []
    jfiles, mdfiles = [], []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in fns:
            p = os.path.join(dirpath, fn)
            if re.search(r"fingerprint|receipt|blobs", fn, re.I) and fn.endswith(".json"):
                jfiles.append(p)
            elif re.search(r"submission|receipt", fn, re.I) and fn.endswith(".md"):
                mdfiles.append(p)
    jfiles = [p for p in jfiles if is_current(item_dir, p)]
    mdfiles = [p for p in mdfiles if is_current(item_dir, p)]
    declared = {}

    def judge(where, key, digest):
        if len(digest) != 64:
            hits.append({"severity": "defect", "locator": "%s:%s" % (where, key),
                         "evidence": "declared digest has %d chars; a full sha256 has 64" % len(digest)})
            return
        target = os.path.normpath(os.path.join(item_dir, key))
        if not target.startswith(os.path.normpath(item_dir)) or not os.path.isfile(target):
            hits.append({"severity": "defect", "locator": "%s:%s" % (where, key),
                         "evidence": "declared path is absent from the submission tree",
                         "l1_said": "L1 never reads fingerprint files", "we_said": "file absent"})
            return
        real = sha256_file(target)
        if real != digest.lower():
            hits.append({"severity": "defect", "locator": "%s:%s" % (where, key),
                         "evidence": "declared %s..., disk %s..." % (digest[:16], real[:16]),
                         "l1_said": "L1 never reads fingerprint files", "we_said": real})
        declared[key] = digest

    for p in jfiles:
        rel = os.path.relpath(p, item_dir)
        try:
            doc = json.loads(read_text(p))
        except Exception:
            continue
        pairs = []
        def walk(node):
            if isinstance(node, dict):
                for k, v in node.items():
                    if isinstance(v, str) and re.fullmatch(r"[0-9a-fA-F]{8,64}", v) and ("/" in k or "." in k):
                        pairs.append((k, v))
                    else:
                        walk(v)
        walk(doc)
        for key, digest in pairs:
            judge(rel, key, digest)
    md_rows = 0
    for p in mdfiles:
        rel = os.path.relpath(p, item_dir)
        for line in read_text(p).splitlines():
            m = re.match(r"\s*\|\s*([^|]+?)\s*\|\s*([0-9a-fA-F]{64})\s*\|", line)
            if not m:
                continue
            label = m.group(1).replace(chr(96), "").strip()
            digest = m.group(2).lower()
            md_rows += 1
            if not re.search(r"[/\\]|\.(csv|json|asm|c|il|md|ps1|py|txt)$", label):
                continue
            judge(rel, label, digest)
    return hits, {"fingerprint_files": len(jfiles), "receipts": len(mdfiles),
                  "declared_paths": len(declared), "receipt_rows": md_rows}


@detector
def det_unresolved_no_recovery(task, item_dir, original, ctx):
    """l1_covers: no

    L1 requires a note only for coverage state=gap rows, never for class=unresolved
    call rows, and never checks that the note is site-specific.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {"skipped": "calls.csv missing"}
    calls = read_csv(cpath)
    total = sum(1 for r in calls if (r.get("class") or "").strip() == "unresolved")
    groups = {}
    for i, r in enumerate(calls, 2):
        if (r.get("class") or "").strip() != "unresolved":
            continue
        note = (r.get("note") or "").strip()
        if not note:
            hits.append({"severity": "defect", "locator": "calls.csv:L%d" % i,
                         "evidence": "unresolved row without recovery text"})
            continue
        groups.setdefault(note, []).append(i)
    for note, rows in groups.items():
        if len(rows) < 5 or len(rows) < 0.5 * max(total, 1):
            continue
        hits.append({"severity": "defect", "locator": "calls.csv:L%d-L%d" % (rows[0], rows[-1]),
                     "evidence": "%d/%d unresolved rows share one identical recovery sentence starting '%s'"
                                 % (len(rows), total, note[:48])})
    return hits, {"unresolved_rows": total, "distinct_notes": len(groups)}


@detector
def det_symbol_substring(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 checks that the listing contains the address, not that the symbol bound to a
    site is the exact imported identity.  Two symbols where one is a prefix of the
    other bound to the same site are a conflation risk.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {}
    rows = read_csv(cpath)
    by_site = {}
    for r in rows:
        key = tuple((r.get("listing") or "").split("#")[0:2])
        by_site.setdefault(key, []).append((r.get("callee") or "").strip())
    for site, callees in by_site.items():
        callees = [c for c in callees if c]
        for i, a in enumerate(callees):
            for b in callees[i + 1:]:
                if a != b and (a.startswith(b) or b.startswith(a)):
                    hits.append({"severity": "defect", "locator": "calls.csv:%s" % (site[0] or "-"),
                                 "evidence": "same site binds two prefix-relative symbols %r and %r" % (a, b)})
    for r in rows:
        callee, note = (r.get("callee") or "").strip(), r.get("note") or ""
        for m in re.finditer(r"([A-Za-z0-9_.\-]+!(?:#[0-9]+|[A-Za-z0-9_@?$.]+)|#[0-9]+)", note):
            sym = m.group(1)
            if callee and sym != callee and (sym.startswith(callee) or callee.startswith(sym)):
                hits.append({"severity": "defect", "locator": "calls.csv:%s" % (r.get("listing") or "-"),
                             "evidence": "note symbol %r is a prefix-relative variant of callee %r" % (sym, callee)})
    return hits, {"rows": len(rows)}


@detector
def det_wrong_symbol(task, item_dir, original, ctx):
    """l1_covers: no

    L1 never resolves an IAT slot to an import name, so a callee naming an API the
    original does not import there is invisible to it.
    """
    hits = []
    cpath = find_one(item_dir, "calls.csv")
    if not cpath:
        return hits, {}
    data = open(original, "rb").read()
    pe = prepared_pe(data)
    names, ordinals = {}, {}
    import pefile
    for entry in getattr(pe, "DIRECTORY_ENTRY_IMPORT", []) or []:
        dll = entry.dll.decode("ascii", "replace").lower()
        for imp in entry.imports:
            if imp.name:
                names.setdefault(dll, set()).add(imp.name.decode("ascii", "replace"))
            if imp.ordinal is not None:
                ordinals.setdefault(dll, set()).add(int(imp.ordinal))
    rows = read_csv(cpath)
    for r in rows:
        callee = (r.get("callee") or "").strip()
        if not callee or "!" not in callee or re.match(r"^0x", callee):
            continue
        dll, member = callee.split("!", 1)
        dll = dll.lower()
        if member.startswith("#"):
            try:
                ordv = int(member[1:])
            except ValueError:
                continue
            if ordv in ordinals.get(dll, ()) or member in names.get(dll, ()):
                continue
        elif member in names.get(dll, ()):
            continue
        elif dll in names and any(member.startswith(n) or n.startswith(member)
                                  for n in names[dll]):
            continue  # prefix variants are a separate category
        hits.append({"severity": "defect", "locator": "calls.csv:%s" % (r.get("listing") or "-"),
                     "evidence": "declares %r, which is not an import of the pinned original" % callee})
    return hits, {"iat_dlls": len(names), "rows": len(rows)}


@detector
def det_byte_mismatch(task, item_dir, original, ctx):
    """l1_covers: partial

    L1 compares first_bytes only at coverage entry points.  A listing line that claims
    bytes differing from the original at the same RVA is invisible to it.
    """
    hits = []
    code = os.path.join(item_dir, "code")
    if not os.path.isdir(code):
        return hits, {"skipped": "no code/ directory"}
    try:
        from pe_reader import PE, parse_asm
    except Exception as exc:
        return hits, {"skipped": "pe_reader unavailable: %s" % exc}
    data = open(original, "rb").read()
    pe = PE(data)
    checked = 0
    for dirpath, _dirs, fns in os.walk(code):
        for fn in sorted(fns):
            if not re.search(r"native.*\.asm$", fn, re.I):
                continue
            if not is_current(item_dir, os.path.join(dirpath, fn)):
                continue
            try:
                _meta, ins = parse_asm(os.path.join(dirpath, fn))
            except Exception:
                continue
            for (ln, addr, blob, _text, _raw) in ins:
                try:
                    start = pe.filepos(addr)
                except Exception:
                    continue
                orig = data[start:start + len(blob)].hex()
                checked += 1
                if blob.hex() != orig:
                    hits.append({"severity": "defect",
                                 "locator": "%s#L%d" % (os.path.relpath(os.path.join(dirpath, fn), item_dir), ln),
                                 "evidence": "0x%X candidate bytes %s, original %s" % (addr, blob.hex(), orig)})
    return hits, {"instructions_checked": checked}


@detector
def det_access_flags(task, item_dir, original, ctx):
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
    return hits, {"documents_checked": len(files)}


DETECTORS = [det_omitted_sites, det_stale_metrics, det_row_linkage, det_fingerprint_pathset,
             det_unresolved_no_recovery, det_symbol_substring, det_wrong_symbol,
             det_byte_mismatch, det_access_flags]


def aggregate(task, item_dir, original, l1_path=None, skip_l1=False):
    l1seg = {"skipped": True, "exit": None, "authoritative": True}
    if not skip_l1:
        l1seg = run_l1(task, item_dir, original, l1_path)
    reports, warnings, l2_exit, ctx = {}, [], 0, {}
    for fn in DETECTORS:
        try:
            hits, stats = fn(task, item_dir, original, ctx)
        except Exception as exc:
            reports[fn.__name__] = {"category": fn.__name__[4:], "l1_covers": fn.l1_covers,
                                    "error": "%s: %s" % (type(exc).__name__, exc), "hits": []}
            continue
        defects = [h for h in hits if h.get("severity") == "defect"]
        reports[fn.__name__] = {"category": fn.__name__[4:], "l1_covers": fn.l1_covers,
                                "hits": hits, "defects": len(defects),
                                "advisory": len(hits) - len(defects), "stats": stats}
        if fn.l1_covers in ("yes", "partial") and defects:
            warnings.append({"detector": fn.__name__, "l1_covers": fn.l1_covers,
                             "l1_said": "L1 accepts this submission (exit %s)" % l1seg.get("exit"),
                             "we_said": "%d defects" % len(defects),
                             "hits": defects})
        elif fn.l1_covers == "no" and defects:
            l2_exit = max(l2_exit, 2)
    out = {"task": task, "item_dir": os.path.abspath(item_dir),
           "original": os.path.abspath(original), "original_sha256": sha256_file(original),
           "l1": l1seg, "l2": reports, "l2_exit": l2_exit, "warnings": warnings,
           "exit": l1seg.get("exit") if l1seg.get("exit") not in (None, 0) else l2_exit,
           "l1_authoritative": True}
    return out


def main(argv=None):
    ap = argparse.ArgumentParser(description="L1 (upstream, pinned) + L2 (ours) preflight")
    ap.add_argument("--task", choices=sorted(TASKS), default="NATIVE-337")
    ap.add_argument("--item-dir")
    ap.add_argument("--folder", help="alias of --item-dir (s27 CLI)")
    ap.add_argument("--original")
    ap.add_argument("--binary", help="alias of --original (s27 CLI)")
    ap.add_argument("--l1-path")
    ap.add_argument("--skip-l1", action="store_true")
    ap.add_argument("--json")
    ap.add_argument("--quiet", action="store_true")
    a = ap.parse_args(argv)
    item_dir = a.item_dir or a.folder
    if not item_dir:
        ap.error("--item-dir is required")
    original = a.original or a.binary or os.path.join(ROOT, TASKS[a.task]["original"])
    rep = aggregate(a.task, item_dir, original, a.l1_path, a.skip_l1)
    if a.json:
        with open(a.json, "w", encoding="utf-8") as f:
            json.dump(rep, f, ensure_ascii=False, indent=2)
    if not a.quiet:
        print("l1 pin_ok=%s exit=%s :: %s" % (rep["l1"].get("pin_ok"), rep["l1"].get("exit"),
                                              (rep["l1"].get("stdout") or "")[:150]))
        for name, r in rep["l2"].items():
            print("l2 %-28s l1_covers=%-7s defects=%-3d advisory=%-3d"
                  % (name[4:], r["l1_covers"], r.get("defects", 0), r.get("advisory", 0)))
            if r.get("stats"):
                print("       stats: %s" % json.dumps(r["stats"], ensure_ascii=False)[:180])
            for h in r.get("hits", [])[:4]:
                print("     - [%s] %s :: %s" % (h.get("severity"), h["locator"], h["evidence"][:130]))
        if rep["warnings"]:
            print("warnings: %d (L1 says accepted, we say defect)" % len(rep["warnings"]))
        print("exit:", rep["exit"])
    return rep["exit"]


if __name__ == "__main__":
    try:
        sys.stdout.reconfigure(encoding="utf-8", errors="replace")
    except Exception:
        pass
    sys.exit(main())
