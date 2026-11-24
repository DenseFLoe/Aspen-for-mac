
# -*- coding: utf-8 -*-
"""fingerprint-pathset detector.

l1_covers: no

L1 has no notion of declared deliverable/fingerprint path sets.  This unit judges, for the
current round only:

  * every declared (path, sha256) pair -- from fingerprint JSON, from manifest/blob JSON,
    and from markdown receipt tables or list lines -- must exist and match on disk;
  * a declared digest shorter than 64 hex characters cannot identify a file;
  * a declared set that SHRANK relative to the previous round is surfaced as advisory,
    because a set that shrinks together with the disk can look self-consistent.

Both prefixed keys (code/x.csv) and top-level keys (calls.csv, metrics.json,
sNN-submission.md) are judged; the two are counted separately so that 109 and 58 are never
compared as if they were the same measurement.
"""
import os
import posixpath
import re

import common as C

SOURCE = "t16"
L1_COVERS = "no"
CATEGORY = "fingerprint-pathset"

# Directories that belong to the delivery REPOSITORY (or to the machine workspace), not to
# the submission tree.  A path under one of these cannot be verified from the item tree
# alone, so it is advisory rather than a defect.  "qa" is the gate toolkit itself, and the
# _tNN directories are workspace scratch trees.
REPO_DIRS = {"tool", "handoff", "issue-materials", "analysis", ".github", "qa"}
REPO_SCRATCH = re.compile(r"^_[A-Za-z0-9]+$")
HEX = re.compile(r"^[0-9a-fA-F]+$")
BT = chr(96)  # backtick, kept out of literals for tooling friendliness
PREFIXED = re.compile(r"^(?:[A-Za-z0-9_.\-]+/)+[A-Za-z0-9_.\-]+\.(csv|json|asm|c|il|md|ps1|py|txt)$")
TOPLEVEL = re.compile(r"^[A-Za-z0-9_.\-]+\.(csv|json|asm|c|il|md|ps1|py|txt)$")


def _kind(key):
    k = key.replace("\\", "/")
    if PREFIXED.match(k):
        return "with_prefix"
    if TOPLEVEL.match(k):
        return "top_level"
    return None


def _declared_json(doc):
    stack = [doc]
    while stack:
        node = stack.pop()
        if isinstance(node, dict):
            for key, value in node.items():
                if isinstance(value, str) and _kind(key):
                    yield key, value
                elif isinstance(value, (dict, list)):
                    stack.append(value)
        elif isinstance(node, list):
            stack.extend(node)


def _fingerprint_files(item_dir):
    out = []
    for dirpath, _dirs, fns in os.walk(item_dir):
        for fn in sorted(fns):
            low = fn.lower()
            if low.endswith(".json") and re.search(r"fingerprint|manifest|blobs|receipt", low):
                out.append(os.path.join(dirpath, fn))
    out.sort(key=lambda p: C.round_of(os.path.relpath(p, item_dir)) or 0)
    return out


def _declared_receipt(path):
    """Yield (key, digest, context) for declarations in a markdown receipt.

    Rules, in order:
      * fenced code blocks are skipped wholesale (a snippet is not a declaration);
      * tool readback lines (readback: path=X algo=sha256 value=<hex>) are skipped -- that
        is this gate's own truncated output, not a claim about the tree;
      * function-call fragments (sha256(...), hexdigest(), hashlib.*) are skipped;
      * in a table row the digest is the cell that is exactly 64 hex characters.  A row may
        carry a size column (| path | bytes | sha256 | note |); a bare number is a size and
        is never read as a digest;
      * a short 8..63 hex cell that is not a plain number is treated as a truncated digest
        and handed on with the full line as context, so the defect can quote it;
      * a row with the path but no digest cell is a declaration without a digest.
    """
    fence = re.compile(r"^\s*(" + BT * 3 + r"|~~~)")
    readback = re.compile(r"^\s*readback\s*:", re.I)
    call = re.compile(r"sha256\s*\(|hexdigest\s*\(|hashlib\.", re.I)
    in_fence = False
    for line in C.read_text(path).splitlines():
        if fence.match(line):
            in_fence = not in_fence
            continue
        if in_fence:
            continue
        stripped = line.strip()
        if not stripped:
            continue
        # A table row is judged by its cells: a note cell that mentions sha256(...) must not
        # disqualify the row.  The prose filters below apply to non-table lines only.
        if not stripped.startswith("|") and (readback.match(stripped) or call.search(stripped)):
            continue
        if stripped.startswith("|"):
            cells = [c.strip().strip(BT).strip() for c in stripped.strip("|").split("|")]
            key = next((c for c in cells if _kind(c)), None)
            if not key:
                continue
            full = [c for c in cells if re.fullmatch(r"[0-9a-fA-F]{64}", c)]
            if full:
                yield key, full[0], None
                continue
            shortish = [c for c in cells
                        if re.fullmatch(r"[0-9a-fA-F]{4,63}", c) and re.search(r"[a-fA-F]", c)]
            if shortish:
                yield key, shortish[0], stripped
                continue
            yield key, None, None
            continue
        match = re.fullmatch(r"[-*]\s+" + BT + r"?([^\s" + BT + r"]+)" + BT + r"?\s*", stripped)
        if match and _kind(match.group(1)):
            yield match.group(1), None, None


def detect(task, item_dir, original, ctx):
    hits, errors = [], []
    md_files = []
    for dirpath, dirs, fns in os.walk(item_dir):
        dirs.sort()
        for fn in sorted(fns):
            low = fn.lower()
            if low.endswith(".md") and re.search(r"submission|receipt|audit|notes", low):
                md_files.append(os.path.join(dirpath, fn))

    def rel(path):
        return os.path.relpath(path, item_dir)

    def file_round(path):
        return C.round_of(rel(path)) or 0

    top = C.current_round(item_dir, ctx)
    jfiles = _fingerprint_files(item_dir)
    current = [p for p in jfiles if C.is_current(item_dir, p, ctx)]
    previous = [p for p in jfiles if 0 < file_round(p) < top]
    item_root = os.path.realpath(item_dir)
    declared, verified, unverified = set(), set(), set()
    fingerprints = comparisons = parsed = receipt_rows = 0

    def judge(where, key, digest, context=None):
        nonlocal fingerprints, comparisons
        key = key.replace("\\", "/")
        declared.add(key)
        if digest is not None:
            fingerprints += 1
        severity = "defect"
        if digest is not None and (len(digest) != 64 or not HEX.fullmatch(digest)):
            evidence = "algo=sha256 declared digest has %d chars; expected 64 hex characters" % len(digest)
            if context:
                # never guess which fragment was meant: quote the whole declaration line
                evidence += " | line: " + context[:200]
        else:
            target = os.path.realpath(os.path.join(item_root, key))
            if not C.path_is_within(item_root, target):
                severity = "advisory"
                evidence = "declared path resolves outside the submission tree"
            elif (posixpath.normpath(key).split("/")[0] in REPO_DIRS
                  or REPO_SCRATCH.fullmatch(posixpath.normpath(key).split("/")[0])):
                severity = "advisory"
                evidence = "declared path is repository-relative and cannot be checked from the item tree alone"
            elif not os.path.isfile(target):
                evidence = "declared path is absent from the submission tree"
            elif digest is None:
                return
            else:
                real = C.sha256_file(target)
                comparisons += 1
                if real == digest.lower():
                    verified.add(key)
                    return
                severity = "advisory" if target.lower().endswith(".md") else "defect"
                evidence = "algo=sha256 declared %s..., disk %s..." % (digest[:16], real[:16])
        unverified.add(key)
        hits.append({"severity": severity, "locator": "%s:%s" % (where, key), "evidence": evidence})

    for p in current:
        try:
            doc = C.read_json(p)
        except (OSError, ValueError, RecursionError) as exc:
            errors.append("%s: %s" % (rel(p), exc))
            continue
        parsed += 1
        for key, digest in _declared_json(doc):
            judge(rel(p), key, digest, None)

    for p in md_files:
        if C.is_current(item_dir, p, ctx):
            for key, digest, context in _declared_receipt(p):
                receipt_rows += 1
                judge(rel(p), key, digest, context)

    if not fingerprints and not errors:
        if current:
            # a this-round table exists but declares no digest: a defect
            hits.append({"severity": "defect", "locator": "s%d" % top if top else "fingerprint declarations",
                         "evidence": "current submission is missing fingerprint declarations"})
        elif previous:
            # earlier rounds did ship tables, so their absence now is a regression
            last = max(map(file_round, previous))
            hits.append({"severity": "defect", "locator": "s%d" % top,
                         "evidence": "missing fingerprint declarations: round s%d ships no "
                                     "table although s%d did" % (top, last)})
        elif top:
            # early rounds legitimately ship no table; say so without failing the gate
            hits.append({"severity": "advisory", "locator": "s%d" % top,
                         "evidence": "this round ships no fingerprint table; nothing to compare"})

    dropped = []
    history = previous + [p for p in md_files if 0 < file_round(p) < top]
    if history and not errors:
        last_round = max(map(file_round, history))
        prev_set = set()
        sources = sorted(p for p in history if file_round(p) == last_round)
        for p in sources:
            try:
                pairs = _declared_receipt(p) if p in md_files else _declared_json(C.read_json(p))
                prev_set.update(t[0].replace("\\", "/") for t in pairs)
            except (OSError, ValueError, RecursionError):
                continue  # Historical evidence is advisory only.
        dropped = sorted(prev_set - declared)
        if dropped:
            hits.append({"severity": "advisory", "locator": rel(sources[0]),
                         "evidence": "algo=sha256 declared set shrank: %d previous vs %d current; dropped=%s"
                                     % (len(prev_set), len(declared), dropped[:8])})

    with_prefix = sum(_kind(key) == "with_prefix" for key in declared)
    stats = {"fingerprint_files": len(current), "files_parsed": parsed, "comparisons": comparisons,
             "previous_tables": len(previous), "declared_paths": len(declared),
             "verified_paths": len(verified - unverified), "with_prefix": with_prefix,
             "top_level": len(declared) - with_prefix, "receipt_rows": receipt_rows,
             "shrank_paths": len(dropped)}
    if errors:
        stats["error"] = "; ".join(errors)
    return hits, stats
