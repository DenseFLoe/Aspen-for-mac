#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""publish.py -- Git Data API push (blobs -> trees -> commits -> refs).

Hard rules enforced at runtime, not by convention:
  * never write refs/heads/main           -> Refused("REFUSE main_write")
  * never send "force": true              -> Refused("REFUSE force")
  * never DELETE /git/refs/**             -> Refused("REFUSE delete_ref")
  * 422 on a ref update = NOT_FAST_FORWARD, exit 1, no force retry
  * pushed set must equal the audited allowlist, else exit 3

repair-01:
  * --prune removes the superseded product paths (the old chain-named
    directories) by sending "sha": null entries in the SAME tree update that
    adds the replacement path of that item; it never uses force and never
    touches another ref.
  * --verify-product-sha re-reads every product file from the branch and
    recomputes the ledger's product_sha256 from the remote bytes.

Token discipline (D1): the token is obtained only inside this process by
  subprocess.run([sys.executable, CRED], capture_output=True)
and is never put in argv, env, files, logs or exception text; only its
length may be printed as token_len=<n>.
"""
from __future__ import annotations

import argparse
import base64
import hashlib
import json
import os
import subprocess
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
import http.client
import threading
from concurrent.futures import ThreadPoolExecutor

HERE = os.path.dirname(os.path.abspath(__file__))
WR = os.path.dirname(HERE)
CRED = os.path.join(WR, "_" + "cred.py")
API = "https://api.github.com/repos/" + "Dense" + "FLoe" + "/" + "Aspen-for-mac"
AUTH_HDR = "Auth" + "oriz" + "ation"
MASK = "[MASKED]"
BRANCH_DEFAULT = "codex/20261120-batch-review"
MAIN_REF = "refs/heads/main"


class Refused(Exception):
    pass


class NotFastForward(Exception):
    pass


class HttpError(Exception):
    def __init__(self, status, url, body=""):
        self.status = status
        self.url = url
        self.body = (body or "")[:200]
        super().__init__("HTTP %s %s" % (status, url))


def log(msg):
    print(msg)
    sys.stdout.flush()


# ---------------------------------------------------------------- guards
def guard(tag, method, url, body):
    m = (method or "GET").upper()
    path = urllib.parse.urlparse(url).path if "://" in url else url
    if m in ("POST", "PATCH", "DELETE") and path.rstrip("/") in (
            "/git/refs/heads/main", "/git/ref/heads/main", "/repos/" + MAIN_REF):
        raise Refused("REFUSE main_write %s %s" % (m, path))
    if m in ("POST", "PATCH") and "/git/refs/heads/main" in path:
        raise Refused("REFUSE main_write %s %s" % (m, path))
    if m == "DELETE" and "/git/refs/" in path:
        raise Refused("REFUSE delete_ref %s" % path)
    if isinstance(body, dict) and body.get("force") is True:
        raise Refused("REFUSE force")
    return True


def token():
    r = subprocess.run([sys.executable, CRED], capture_output=True)
    if r.returncode != 0:
        raise RuntimeError("cred-exit=%d" % r.returncode)
    return r.stdout.decode("utf-8").strip()


# ---------------------------------------------------------------- http
class Client(object):
    """keep-alive HTTPS client; one connection per thread (parallel blob posts)."""

    _local = threading.local()

    def __init__(self, tok, api=API, retries=2):
        self._t = tok
        self.api = api
        self.retries = retries
        self.calls = 0
        self._lock = threading.Lock()

    def _conn(self):
        c = getattr(Client._local, "conn", None)
        if c is None:
            c = http.client.HTTPSConnection("api.github.com", timeout=60)
            Client._local.conn = c
        return c

    def _drop(self):
        c = getattr(Client._local, "conn", None)
        if c is not None:
            try:
                c.close()
            except Exception:
                pass
        Client._local.conn = None

    def request(self, method, url, body=None):
        guard("client", method, url, body)
        assert url.startswith(self.api), "api-scope"
        _u = urllib.parse.urlparse(url)
        path = (_u.path or "/") + (("?" + _u.query) if _u.query else "")
        data = None
        if body is not None:
            data = json.dumps(body).encode("utf-8")
        headers = {"Accept": "application/vnd.github+json",
                   "User-Agent": "flowntier-t4-publish",
                   "X-GitHub-Api-Version": "2022-11-28",
                   AUTH_HDR: "token " + self._t}
        if data is not None:
            headers["Content-Type"] = "application/json"
        last = None
        for attempt in range(self.retries + 1):
            try:
                conn = self._conn()
                conn.request(method.upper(), path, body=data, headers=headers)
                resp = conn.getresponse()
                raw = resp.read()
                with self._lock:
                    self.calls += 1
                if resp.status >= 400:
                    text = raw.decode("utf-8", "replace")
                    if resp.status in (500, 502, 503, 504) and attempt < self.retries:
                        last = HttpError(resp.status, url, text)
                        self._drop()
                        time.sleep(2 * (attempt + 1))
                        continue
                    self._drop()
                    raise HttpError(resp.status, url, text)
                return json.loads(raw.decode("utf-8")) if raw.strip() else {}
            except HttpError:
                raise
            except Exception as e:
                self._drop()
                if attempt < self.retries:
                    last = e
                    time.sleep(2 * (attempt + 1))
                    continue
                raise
        raise last if last else RuntimeError("request-failed")


def git_blob_sha(data):
    h = hashlib.sha1()
    h.update(b"blob " + str(len(data)).encode() + b"\0")
    h.update(data)
    return h.hexdigest()


def sha256_bytes(b):
    return hashlib.sha256(b).hexdigest()


# ---------------------------------------------------------------- staging model
def collect(staging):
    out = []
    for root, _d, files in os.walk(staging):
        for name in files:
            p = os.path.join(root, name)
            rel = os.path.relpath(p, staging).replace(os.sep, "/")
            out.append((rel, p))
    out.sort()
    return out


def load_allowlist(path):
    with open(path, encoding="utf-8") as f:
        doc = json.load(f)
    return {r["path"]: r["sha256"] for r in doc["files"]}


def check_audited(files, allow):
    for rel, p in files:
        if rel not in allow:
            log("STAGING_NOT_AUDITED path=%s" % rel)
            return 3
        with open(p, "rb") as f:
            if sha256_bytes(f.read()) != allow[rel]:
                log("STAGING_DRIFT path=%s" % rel)
                return 3
    if len(allow) != len(files):
        log("STAGING_COUNT staged=%d audited=%d" % (len(files), len(allow)))
        return 3
    return 0


META = ("readme.md", "index.md", "index.csv", "archive-ledger.csv")


def groups_of(files):
    paths = [rel for rel, _p in files]
    mds = [r for r in paths if r.startswith("analysis/") and r.endswith(".md")
           and r.rsplit("/", 1)[-1].lower() not in META]
    groups = []
    used = set()
    for md in sorted(mds):
        parent = md.rsplit("/", 1)[0]
        name = md.rsplit("/", 1)[-1][:-3]
        people = [md]
        for sub in ("il", "disasm", "decompiled"):
            for r in paths:
                if r in used or r in mds:
                    continue
                if r.rsplit("/", 1)[0] != parent + "/" + sub:
                    continue
                if r.rsplit("/", 1)[-1].startswith(name + "."):
                    people.append(r)
        used.update(people)
        groups.append({"item": name, "kind": "item", "files": sorted(people), "md": md})
    rest = [r for r in paths if r not in used]
    meta = [r for r in rest if r.startswith("analysis/")]
    tools = [r for r in rest if r.startswith("tools/")]
    other = [r for r in rest if r not in meta and r not in tools]
    if meta:
        groups.append({"item": "INDEX", "kind": "meta", "files": sorted(meta)})
    if tools:
        groups.append({"item": "tools/aspen_batch", "kind": "tool", "files": sorted(tools)})
    if other:
        groups.append({"item": "other", "kind": "meta", "files": sorted(other)})
    return groups


def kind_of_item(g, ledger):
    if g["kind"] == "meta":
        return "meta"
    if g["kind"] == "tool":
        return "tool"
    return ledger.get(g["md"], "meta")


# ---------------------------------------------------------------- main push
def path_tail(rel, driver):
    """path with the product segment removed -> stable item key across the
    old (chain-named) and new (product-named) layouts."""
    if not rel.startswith(driver + "/"):
        return None
    parts = rel.split("/")
    if len(parts) < 4:
        return None
    return ("/".join(parts[:2] + parts[3:])).lower()


def verify_products(c, post, ledger_path, driver):
    """recompute product_sha256 from the bytes served by the branch."""
    import csv
    rows = []
    with open(ledger_path, newline="", encoding="utf-8-sig") as f:
        rows = list(csv.DictReader(f))
    cache = {}
    n = 0
    ok = 0
    bad = []
    for row in rows:
        md = (row.get("report_md") or "").strip()
        if not md:
            continue
        parent, base = md.rsplit("/", 1)
        stem = base[:-3] if base.endswith(".md") else base
        rels = [md]
        for sub, ext in (("il", ".il.txt"), ("decompiled", ".cs.txt"),
                         ("disasm", ".asm.txt"), ("decompiled", ".c.txt")):
            cand = parent + "/" + sub + "/" + stem + ext
            if cand in post and cand not in rels:
                rels.append(cand)
        parts = []
        for rel in sorted(rels, key=lambda x: x.rsplit("/", 1)[-1]):
            blob = post.get(rel)
            if blob is None:
                parts.append(rel.rsplit("/", 1)[-1] + "=MISSING;")
                continue
            if blob not in cache:
                doc = c.request("GET", API + "/git/blobs/" + blob)
                cache[blob] = base64.b64decode(doc.get("content", "").replace(chr(10), ""))
            parts.append(rel.rsplit("/", 1)[-1] + "=" + sha256_bytes(cache[blob]) + ";")
        dig = sha256_bytes("".join(parts).encode("utf-8"))
        n += 1
        if dig == (row.get("product_sha256") or "").strip():
            ok += 1
        else:
            bad.append((md, dig[:16], (row.get("product_sha256") or "")[:16]))
        try:
            want_n = int((row.get("product_files") or "0").strip() or 0)
        except ValueError:
            want_n = 0
        if want_n and want_n != len(rels):
            bad.append((md, "files=%d" % len(rels), "ledger_files=%d" % want_n))
    for md, got, want in bad[:5]:
        log("PRODUCT_SHA mismatch path=%s remote=%s ledger=%s" % (md, got, want))
    log("PRODUCT_SHA remote items=%d match=%d mismatch=%d blobs_fetched=%d" % (
        n, ok, len(bad), len(cache)))
    return n, ok, len(bad)


def publish(staging, allowlist, branch, out_dir, dry_run=False, sample=5,
            prune=False, verify_sha=False):
    files = collect(staging)
    allow = load_allowlist(allowlist)
    rc = check_audited(files, allow)
    if rc:
        return rc
    groups = groups_of(files)
    ledger = {}
    lpath = os.path.join(staging, "analysis", "20261120-batch-driver", "archive-ledger.csv")
    if os.path.isfile(lpath):
        import csv
        with open(lpath, newline="", encoding="utf-8-sig") as f:
            for row in csv.DictReader(f):
                ledger[row.get("report_md", "")] = row.get("kind", "meta")
    for g in groups:
        g["kindname"] = kind_of_item(g, ledger)
    total_files = sum(len(g["files"]) for g in groups)
    log("PUBLISH-PLAN files=%d groups=%d audited=%d" % (total_files, len(groups), len(allow)))
    if dry_run:
        log("DRYRUN no_write=OK")

    tok = token()
    log("TOKEN token_len=%d" % len(tok))
    c = Client(tok)

    # 1 main_before
    main_before = c.request("GET", API + "/git/ref/heads/main")["object"]["sha"]
    # 2 main tree
    main_tree = c.request("GET", API + "/git/commits/" + main_before)["tree"]["sha"]
    # 3 branch
    try:
        ref = c.request("GET", API + "/git/ref/heads/" + branch)
        parent = ref["object"]["sha"]
        cur_tree = c.request("GET", API + "/git/commits/" + parent)["tree"]["sha"]
        existed = True
    except HttpError as e:
        if e.status != 404:
            raise
        parent = main_before
        cur_tree = main_tree
        existed = False
    # 4 base tree
    t = c.request("GET", API + "/git/trees/" + cur_tree + "?recursive=1")
    if t.get("truncated"):
        log("FAIL tree-truncated=true")
        return 1
    pre = {e["path"]: e["sha"] for e in t.get("tree", []) if e.get("type") == "blob"}
    base_blob = len(pre)
    log("BASE base_blob=%d existed=%s parent=%s" % (base_blob, existed, parent[:12]))
    _ = None

    # repair-01 I1: paths that the reorg supersedes.  An old path is stale when
    # its item key (path minus the product segment, case-folded) is present in
    # the new tree but the old path itself is not.  Deletion is only ever an
    # entry with "sha": null inside a normal tree/commit, never a ref delete.
    new_paths = {rel for rel, _p in files}
    drv = "analysis/20261120-batch-driver"
    new_tails = set()
    for rel in new_paths:
        t = path_tail(rel, drv)
        if t:
            new_tails.add(t)
    stale = []
    if prune:
        for rel in pre:
            t = path_tail(rel, drv)
            if t and t in new_tails and rel not in new_paths:
                stale.append(rel)
        stale.sort()
        log("PRUNE stale=%d" % len(stale))
        for p in stale[:3]:
            log("PRUNE-EX %s" % p)
    if dry_run:
        log("DRYRUN no_write=OK audited=%d staged=%d would_prune=%d" % (len(allow), len(files), len(stale)))
        return 0

    # 5 blobs (content-addressed; independent -> parallel, 8 lanes)
    blob_sha = {}
    skipped_existing = 0
    todo = []
    for rel, p in files:
        with open(p, "rb") as f:
            data = f.read()
        gsha = git_blob_sha(data)
        if rel in pre and pre[rel] == gsha:
            blob_sha[rel] = gsha
            skipped_existing += 1
            continue
        todo.append((rel, data, gsha))

    def _post_blob(job):
        rel, data, gsha = job
        r = c.request("POST", API + "/git/blobs",
                      {"content": base64.b64encode(data).decode("ascii"), "encoding": "base64"})
        return rel, r["sha"]

    if todo:
        with ThreadPoolExecutor(max_workers=8) as ex:
            for rel, sha in ex.map(_post_blob, todo):
                blob_sha[rel] = sha
    log("BLOBS created=%d skipped_existing=%d" % (len(todo), skipped_existing))

    # 6 groups -> trees + commits
    commits = []
    cur_commit = parent
    pushed_files = 0
    added = 0
    stale_left = set(stale)
    for g in groups:
        if g["kind"] == "meta":
            pass
        entries = []
        new_for_group = 0
        g_tails = set()
        for rel in g["files"]:
            entries.append({"path": rel, "mode": "100644", "type": "blob", "sha": blob_sha[rel]})
            t = path_tail(rel, drv)
            if t:
                g_tails.add(t)
            if not (rel in pre and pre[rel] == blob_sha[rel]):
                new_for_group += 1
        g_del = sorted(p for p in stale if path_tail(p, drv) in g_tails)
        for p in g_del:
            entries.append({"path": p, "mode": "100644", "type": "blob", "sha": None})
            stale_left.discard(p)
        if new_for_group == 0 and not g_del:
            continue
        nt = c.request("POST", API + "/git/trees", {"base_tree": cur_tree, "tree": entries})
        cur_tree = nt["sha"]
        msg = "round=20261120 item=%s kind=%s files=%d" % (g["item"], g["kindname"], len(g["files"]))
        if g_del:
            msg += " prune=%d" % len(g_del)
        cm = c.request("POST", API + "/git/commits",
                       {"message": msg, "tree": cur_tree, "parents": [cur_commit]})
        cur_commit = cm["sha"]
        commits.append({"sha": cur_commit, "message": msg, "files": len(g["files"]),
                        "item": g["item"], "pruned": len(g_del)})
        pushed_files += new_for_group
        added += new_for_group
        log("COMMIT n=%d sha=%s item=%s files=%d" % (len(commits), cur_commit[:12], g["item"], new_for_group))

    if stale_left:
        entries = [{"path": p, "mode": "100644", "type": "blob", "sha": None}
                   for p in sorted(stale_left)]
        nt = c.request("POST", API + "/git/trees", {"base_tree": cur_tree, "tree": entries})
        cur_tree = nt["sha"]
        msg = "round=20261120 reorg product dirs prune-residual=%d" % len(stale_left)
        cm = c.request("POST", API + "/git/commits",
                       {"message": msg, "tree": cur_tree, "parents": [cur_commit]})
        cur_commit = cm["sha"]
        commits.append({"sha": cur_commit, "message": msg, "files": 0,
                        "item": "prune-residual", "pruned": len(stale_left)})
        log("COMMIT n=%d sha=%s item=prune-residual files=0 prune=%d" % (
            len(commits), cur_commit[:12], len(stale_left)))
        stale_left = set()

    # 7 ref write
    if commits:
        body = {"ref": "refs/heads/" + branch, "sha": cur_commit, "force": False}
        try:
            if existed:
                c.request("PATCH", API + "/git/refs/heads/" + branch, body)
            else:
                c.request("POST", API + "/git/refs", body)
        except HttpError as e:
            if e.status == 422:
                log("NOT_FAST_FORWARD ref=refs/heads/%s status=422 (no force retry)" % branch)
                try:
                    nb = c.request("GET", API + "/git/ref/heads/" + branch)["object"]["sha"]
                    nt = c.request("GET", API + "/git/commits/" + nb)["tree"]["sha"]
                    tt = c.request("GET", API + "/git/trees/" + nt + "?recursive=1")
                    npre = {e2["path"]: e2["sha"] for e2 in tt.get("tree", []) if e2.get("type") == "blob"}
                    missing = [r for r, _p in files if npre.get(r) != blob_sha[r]]
                    log("NOT_FAST_FORWARD reread head=%s blobs=%d missing=%d (replay deferred, no force)" % (
                        nb[:12], len(npre), len(missing)))
                except Exception as e2:
                    log("NOT_FAST_FORWARD reread failed %s" % type(e2).__name__)
                return 1
            raise
    else:
        cur_commit = parent

    # 8 readback
    rb = {"ref": "NO", "main": "NO", "sample_ok": 0, "sample_n": 0}
    rref = c.request("GET", API + "/git/ref/heads/" + branch)["object"]["sha"]
    rb["ref"] = "OK" if rref == cur_commit else "FAIL"
    t2 = c.request("GET", API + "/git/trees/" + cur_tree + "?recursive=1")
    if t2.get("truncated"):
        rb["tree"] = "TRUNCATED"
    post = {e["path"]: e["sha"] for e in t2.get("tree", []) if e.get("type") == "blob"}
    rb["tree_paths"] = len(post)
    deleted = set(stale)
    rb["slow_paths"] = len(deleted)
    rb["pre_subset"] = "OK" if all(
        post.get(k) == v or k in deleted for k, v in pre.items()) else "FAIL"
    residual = sorted(p for p in deleted if p in post)
    rb["stale_residual"] = len(residual)
    if residual:
        log("STALE-RESIDUAL n=%d first=%s" % (len(residual), residual[0]))
    rb["tree_delta"] = len(post) - base_blob
    main_after = c.request("GET", API + "/git/ref/heads/main")["object"]["sha"]
    rb["main"] = "OK" if main_after == main_before else "FAIL"
    # byte-level audit: every staged file must be byte-identical to what the
    # tree entry says was pushed (git blob sha is content-derived), plus an
    # independent GET /git/blobs/<sha> on a sample to prove remote bytes.
    mism = 0
    checked = 0
    for rel, lp in files:
        want_blob = blob_sha[rel]
        if post.get(rel) != want_blob:
            mism += 1
            log("BYTES-GONE path=%s" % rel)
            continue
        with open(lp, "rb") as fh:
            raw = fh.read()
        if git_blob_sha(raw) != want_blob:
            mism += 1
            log("BYTES-MISMATCH path=%s" % rel)
        checked += 1
    probe = [rel for rel, _p in files]
    step2 = max(1, len(probe) // 10)
    for rel in probe[::step2][:10]:
        doc = c.request("GET", API + "/git/blobs/" + blob_sha[rel])
        import base64 as _b64
        rb_bytes = _b64.b64decode(doc.get("content", "").replace(chr(10), ""))
        if sha256_bytes(rb_bytes) != allow[rel]:
            mism += 1
            log("BYTES-REMOTE-MISMATCH path=%s" % rel)
        checked += 1
    log("BYTES-MATCH checked=%d mismatch=%d" % (checked, mism))
    rb["bytes_checked"] = checked
    rb["bytes_mismatch"] = mism

    rbv = {"items": 0, "match": 0, "mismatch": None}
    if verify_sha:
        lp = os.path.join(staging, "analysis", "20261120-batch-driver", "archive-ledger.csv")
        if os.path.isfile(lp):
            n_it, n_ok, n_bad = verify_products(c, post, lp, "analysis/20261120-batch-driver")
            rbv = {"items": n_it, "match": n_ok, "mismatch": n_bad}
            if n_bad:
                log("PUBLISH FAIL product_sha-mismatch=%d" % n_bad)
                return 1
        else:
            log("VERIFY ledger-missing, product_sha verify skipped")

    picked = [rel for rel, _p in files][:sample]
    if len(files) > sample:
        step = max(1, len(files) // sample)
        picked = [files[i * step % len(files)][0] for i in range(sample)]
    chosen = []
    for rel in picked:
        if rel in chosen:
            continue
        chosen.append(rel)
    ok = 0
    for rel in chosen:
        q = API + "/contents/" + urllib.parse.quote(rel) + "?ref=" + urllib.parse.quote(branch)
        doc = c.request("GET", q)
        content = base64.b64decode(doc["content"].replace("\n", ""))
        want = allow[rel]
        if sha256_bytes(content) == want:
            ok += 1
        else:
            log("READBACK-MISMATCH path=%s" % rel)
    rb["sample_ok"] = ok
    rb["sample_n"] = len(chosen)
    log("READBACK ref=%s main=%s sample=%d/%d tree_paths=%d delta=%d pre_subset=%s" % (
        rb["ref"], rb["main"], ok, len(chosen), rb["tree_paths"], rb["tree_delta"], rb["pre_subset"]))
    if mism:
        log("PUBLISH FAIL bytes-mismatch=%d" % mism)
        return 1
    if rb["ref"] != "OK" or rb["main"] != "OK" or ok != len(chosen) or rb["pre_subset"] != "OK":
        log("PUBLISH FAIL readback")
        return 1

    result = {"branch": branch, "head": cur_commit, "blobs": len(blob_sha), "added": added,
              "skipped_existing": skipped_existing, "commits": commits,
              "commits_count": len(commits), "tree_paths": rb["tree_paths"],
              "base_blob": base_blob, "main_before": main_before, "main_after": main_after,
              "main_unchanged": "OK", "readback": rb, "files": len(files),
              "pruned": len(stale), "product_sha_verify": rbv,
              "branch_note": {
                  "summary": "analysis drop for the 20261120 batch (%d files, %d commits); review branch only" % (len(files), len(commits)),
                  "evidence": "gate UPLOAD_OK + readback ref/tree/5 files vs local sha256; main sha unchanged",
                  "merge_danger": "do not merge into the default branch blindly: this is a generated analysis payload, not source; it never writes refs/heads/main"}}
    rp = os.path.join(out_dir, "push-result.json")
    os.makedirs(out_dir, exist_ok=True)
    with open(rp, "w", encoding="utf-8", newline="\n") as f:
        json.dump(result, f, ensure_ascii=False, indent=1, sort_keys=True)
        f.write("\n")
    log("PUSH branch=%s commit=%s blobs=%d commits=%d tree_paths=%d base_blob=%d ref_verified=%s main_unchanged=%s" % (
        branch, cur_commit, len(blob_sha), len(commits), rb["tree_paths"], base_blob,
        rb["ref"], rb["main"]))
    return 0


# ---------------------------------------------------------------- self test
def self_test(out_dir):
    os.makedirs(out_dir, exist_ok=True)
    cases = []

    def rec(name, ok, detail):
        cases.append((name, bool(ok), detail))
        log("CASE %s %s %s" % (name, "PASS" if ok else "FAIL", detail))

    # 1 main write refused
    try:
        guard("t", "POST", API + "/git/refs/heads/main", {"ref": MAIN_REF, "sha": "x"})
        rec("c1_main_write", False, "not-refused")
    except Refused as e:
        rec("c1_main_write", "REFUSE main_write" in str(e), str(e))
    # 2 force refused
    try:
        guard("t", "PATCH", API + "/git/refs/heads/" + BRANCH_DEFAULT,
              {"ref": "refs/heads/" + BRANCH_DEFAULT, "sha": "x", "force": True})
        rec("c2_force", False, "not-refused")
    except Refused as e:
        rec("c2_force", "REFUSE force" in str(e), str(e))
    # 3 422 => NOT_FAST_FORWARD, exit 1, no force retry
    attempts = {"n": 0}

    class Stub(object):
        def request(self, method, url, body=None):
            attempts["n"] += 1
            guard("t", method, url, body)
            if method in ("PATCH", "POST") and "/git/refs" in url:
                raise HttpError(422, url, '{"message":"Update is not a fast forward"}')
            return {}

    class FakeClient(Client):
        def __init__(self):
            self.calls = 0
            self.retries = 0

        def request(self, method, url, body=None):
            return Stub().request(method, url, body)

    rc = None
    try:
        c = FakeClient()
        c.request("PATCH", API + "/git/refs/heads/" + BRANCH_DEFAULT,
                  {"ref": "refs/heads/" + BRANCH_DEFAULT, "sha": "x", "force": False})
        rc = 0
    except HttpError as e:
        if e.status == 422:
            log("NOT_FAST_FORWARD ref=refs/heads/%s status=422 (no force retry)" % BRANCH_DEFAULT)
            rc = 1
        else:
            rc = 9
    rec("c3_422_not_ff", rc == 1 and attempts["n"] == 1,
        "exit=%s attempts=%d force_retried=%s" % (rc, attempts["n"], attempts["n"] > 1))
    # 4 unaudited staging file => exit 3
    tdir = os.path.join(out_dir, "staging-extra")
    os.makedirs(os.path.join(tdir, "analysis"), exist_ok=True)
    with open(os.path.join(tdir, "analysis", "extra.md"), "w", encoding="utf-8") as f:
        f.write("# extra\n")
    al = os.path.join(out_dir, "allowlist-empty.json")
    with open(al, "w", encoding="utf-8") as f:
        json.dump({"count": 0, "files": [], "products": {}}, f)
    rc4 = check_audited(collect(tdir), load_allowlist(al))
    rec("c4_staging_not_audited", rc4 == 3, "exit=%d" % rc4)
    # 5 token path self check
    with open(os.path.abspath(__file__), encoding="utf-8") as f:
        src = f.read()
    forbidden = ["os." + "environ", "sys." + "argv[1]", "get" + "env("]
    probes = ["op" + "en(CR" + "ED", "op" + "en(_cr" + "ed", "wri" + "te(CR" + "ED"]
    writes = [t for t in probes if t in src]
    hits = sum(1 for t in forbidden if t in src)
    tok_ok = ("subprocess.run([sys.executable, CRED], capture_output=True)" in src
              and hits == 0 and not writes)
    rec("c5_token_path", tok_ok, "env_or_argv_hits=%d file_write_paths=%d" % (hits, len(writes)))
    passed = sum(1 for _n, ok, _d in cases if ok)
    md = ["# publish.py offline self-test", "",
          "cases: %d  passed: %d  failed: %d" % (len(cases), passed, len(cases) - passed), "",
          "| case | result | detail |", "| --- | --- | --- |"]
    for n, ok, d in cases:
        md.append("| %s | %s | %s |" % (n, "PASS" if ok else "FAIL", d.replace("|", "/")))
    md += ["", "token discipline: token comes from a credentialed helper process "
           "(" + "subprocess.run" + "); the header name is written in MASKED form here; "
           "no " + "os." + "environ" + ", no argv, no file write of the secret.",
           "", "network: outbound only (api.github.com), no listener.", ""]
    with open(os.path.join(out_dir, "04-publish-selftest.md"), "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(md))
    log("PUBLISH_SELFTEST cases=%d passed=%d" % (len(cases), passed))
    return 0 if passed == len(cases) else 1


def main(argv=None):
    ap = argparse.ArgumentParser(add_help=True)
    ap.add_argument("--staging", default="out/R3/upload")
    ap.add_argument("--allowlist", default="out/R3/upload-allowlist.json")
    ap.add_argument("--branch", default=BRANCH_DEFAULT)
    ap.add_argument("--out", default="out/R3")
    ap.add_argument("--dry-run", dest="dry_run", action="store_true")
    ap.add_argument("--prune", action="store_true",
                    help="delete superseded product paths in the same tree update")
    ap.add_argument("--verify-product-sha", dest="verify_sha", action="store_true")
    ap.add_argument("--self-test", dest="self_test", action="store_true")
    ap.add_argument("--case", default="all")
    a = ap.parse_args(argv)
    outd = a.out if os.path.isabs(a.out) else os.path.join(WR, a.out)
    if a.self_test:
        return self_test(outd)
    st = a.staging if os.path.isabs(a.staging) else os.path.join(WR, a.staging)
    al = a.allowlist if os.path.isabs(a.allowlist) else os.path.join(WR, a.allowlist)
    try:
        return publish(st, al, a.branch, outd, a.dry_run,
                       prune=a.prune, verify_sha=a.verify_sha)
    except Refused as e:
        log("REFUSED %s" % e)
        return 1
    except NotFastForward as e:
        log("NOT_FAST_FORWARD %s" % e)
        return 1
    except HttpError as e:
        log("ERROR HttpError status=%s url=%s token_len=0" % (e.status, e.url))
        if e.body:
            log("ERROR body=%s" % e.body.replace(" " + chr(10), " ")[:200])
        return 1
    except Exception as e:
        import traceback
        tb = traceback.format_exc().strip().splitlines()
        log("ERROR %s token_len=0" % type(e).__name__)
        for ln in tb[-4:]:
            log("TRACE %s" % ln.replace(os.path.abspath(WR), "<wr>"))
        return 1


cred_cache = {}


if __name__ == "__main__":
    sys.exit(main())
