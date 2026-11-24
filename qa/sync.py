
#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Materialise the qa gate toolkit from its branch into _tools/qa/<head8>/.

Usage
    python qa/sync.py                 # newest head of tietoumiao/preflight
    python qa/sync.py --head <sha>    # pin an exact head
    python qa/sync.py --print-only    # report head + version hash, write nothing

Layout
    _tools/qa/<head8>/qa/*.py
    _tools/qa/<head8>/MANIFEST.json

Reproducibility: the version hash is computed over the canonically serialised, sorted
file list (path + sha256 + bytes) only.  generated_at is recorded but never hashed, so any
two people syncing the same head get the same version string:

    qa gate <head8> (MANIFEST files sha256 <version_sha256>)
"""
import argparse
import concurrent.futures as cf
import datetime
import hashlib
import json
import os
import sys
import urllib.request

REPO = "DenseFLoe/Aspen-for-mac"
BRANCH = "tietoumiao/preflight"
ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEST_ROOT = os.path.join(ROOT, "_tools", "qa")
TRUNCATED = ("eadme", "et_", "li.py", "ommon", "egistry", "ync", "ortic")  # mangled-name shapes


def token():
    for key in ("GH_TOKEN", "GITHUB_TOKEN"):
        v = os.environ.get(key)
        if v:
            return v.strip()
    helper = os.path.join(ROOT, "_cred.py")
    if os.path.isfile(helper):
        try:
            out = __import__("subprocess").run([sys.executable, helper],
                                               capture_output=True, text=True, timeout=60)
            if out.returncode == 0 and out.stdout.strip():
                return out.stdout.strip()
        except Exception:
            pass
    return None


def get(url, tok=None, raw=False):
    headers = {"User-Agent": "dsh-qa-sync"}
    if tok and not raw:
        headers["Authorization"] = "Bearer " + tok
    req = urllib.request.Request(url, headers=headers)
    with urllib.request.urlopen(req, timeout=120) as r:
        return r.read()


def api(path, tok=None):
    return json.loads(get("https://api.github.com" + path, tok).decode("utf-8"))


def branch_head(tok, branch=BRANCH, repo=REPO):
    return api("/repos/%s/git/ref/heads/%s" % (repo, branch), tok)["object"]["sha"]


def sha256_bytes(data):
    return hashlib.sha256(data).hexdigest()


def normalize(rel):
    """Strip at most ONE leading 'qa/' and normalise separators.

    Never slice a fixed number of characters: applying the strip twice is exactly how a
    synced tree ends up with README.md and EADME.md next to each other.
    """
    p = rel.replace("\\", "/").lstrip("/")
    while p.startswith("./"):
        p = p[2:]
    parts = [c for c in p.split("/") if c]
    if parts and parts[0] == "qa":
        parts = parts[1:]
    return "/".join(parts)


def version_sha(files):
    """Deterministic version hash: sorted path/sha256/bytes only, no timestamps."""
    canon = json.dumps([{k: f[k] for k in ("path", "sha256", "bytes")}
                        for f in sorted(files, key=lambda x: x["path"])],
                       sort_keys=True, separators=(",", ":"), ensure_ascii=False)
    return hashlib.sha256(canon.encode("utf-8")).hexdigest()


def verify_tree(dest, files):
    """Post-sync self check: count and shapes must match the manifest exactly."""
    problems = []
    base = os.path.join(dest, "qa")
    seen = []
    for dirpath, _dirs, fns in os.walk(base):
        for fn in fns:
            rel = os.path.relpath(os.path.join(dirpath, fn), dest).replace(os.sep, "/")
            seen.append(rel)
            if fn.lower().startswith(TRUNCATED) or fn.lower() in ("eadme.md", "li.py", "ommon.py"):
                problems.append("truncated or duplicated file name: " + rel)
    if len(seen) != len(files):
        problems.append("file count %d on disk != %d in MANIFEST" % (len(seen), len(files)))
    want = {f["path"] for f in files}
    for rel in seen:
        if rel not in want:
            problems.append("file not declared in MANIFEST: " + rel)
    return problems


def sync(head, dest, repo=REPO, branch=BRANCH, tok=None, print_only=False):
    tok = tok or token()
    tree = api("/repos/%s/git/trees/%s?recursive=1" % (repo, head), tok)
    if tree.get("truncated"):
        raise SystemExit("tree is truncated for head %s" % head[:12])
    blobs = [e for e in tree.get("tree", []) if e.get("type") == "blob"]
    if print_only:
        return {"head": head, "files": len(blobs)}
    os.makedirs(dest, exist_ok=True)
    entries = []

    def one(entry):
        rel = entry["path"]
        local = normalize(rel)
        target = os.path.join(dest, "qa", local.replace("/", os.sep))
        if not os.path.normpath(target).startswith(os.path.normpath(os.path.join(dest, "qa"))):
            raise SystemExit("refusing to write outside the toolkit dir: " + rel)
        os.makedirs(os.path.dirname(target), exist_ok=True)
        url = "https://raw.githubusercontent.com/%s/%s/%s" % (repo, head, rel)
        data = get(url, raw=True)
        with open(target, "wb") as f:
            f.write(data)
        return {"path": "qa/" + local, "sha256": sha256_bytes(data), "bytes": len(data)}

    with cf.ThreadPoolExecutor(max_workers=8) as pool:
        for item in pool.map(one, blobs):
            entries.append(item)
    entries.sort(key=lambda e: e["path"])
    vsha = version_sha(entries)
    manifest = {"toolkit": "qa gate", "repo": repo, "branch": branch, "head": head,
                "head8": head[:8],
                "generated_at": datetime.datetime.now(datetime.timezone.utc).isoformat(),
                "generated_at_note": "not part of the version hash",
                "version_sha256": vsha,
                "file_count": len(entries), "files": entries}
    mpath = os.path.join(dest, "MANIFEST.json")
    with open(mpath, "w", encoding="utf-8") as f:
        json.dump(manifest, f, ensure_ascii=False, indent=1)
        f.write("\n")
    problems = verify_tree(dest, entries)
    return {"head": head, "head8": head[:8], "dest": dest, "manifest": mpath,
            "version_sha256": vsha, "files": len(entries), "problems": problems}


def main(argv=None):
    ap = argparse.ArgumentParser(description="sync the qa gate toolkit from its branch")
    ap.add_argument("--head", help="exact head sha; default is the branch head")
    ap.add_argument("--branch", default=BRANCH)
    ap.add_argument("--repo", default=REPO)
    ap.add_argument("--dest", default=None, help="default _tools/qa/<head8>/")
    ap.add_argument("--print-only", action="store_true")
    a = ap.parse_args(argv)
    tok = token()
    head = a.head or branch_head(tok, a.branch, a.repo)
    dest = a.dest or os.path.join(DEST_ROOT, head[:8])
    if a.print_only:
        info = sync(head, dest, a.repo, a.branch, tok, print_only=True)
        print("head=%s files=%d (nothing written)" % (info["head"], info["files"]))
        return 0
    info = sync(head, dest, a.repo, a.branch, tok)
    print("qa gate %s synced to %s" % (info["head8"], info["dest"]))
    print("files   : %d" % info["files"])
    print("manifest: %s" % info["manifest"])
    print("version : qa gate %s (MANIFEST files sha256 %s)"
          % (info["head8"], info["version_sha256"]))
    if info["problems"]:
        for p in info["problems"]:
            print("SELF-CHECK FAIL:", p)
        return 1
    print("self-check: file count and names match MANIFEST")
    return 0


if __name__ == "__main__":
    sys.exit(main())
