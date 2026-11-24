
# -*- coding: utf-8 -*-
"""Fetch a candidate item directory for a repository head, for preflight --head.

The public tree API lists paths (one request), then every file under the task's inbox is
pulled from raw.githubusercontent.com in parallel.  No tarball, no auth required for a
public repository (a token is used when GH_TOKEN/GITHUB_TOKEN is present).
"""
import concurrent.futures as cf
import hashlib
import json
import os
import re
import tempfile
import urllib.request
from urllib.parse import quote

DEFAULT_REPO = "DenseFLoe/Aspen-for-mac"


ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def _token():
    """env first, then the workspace credential helper, then anonymous (60 req/h)."""
    for key in ("GH_TOKEN", "GITHUB_TOKEN"):
        v = os.environ.get(key)
        if v:
            return v.strip()
    helper = os.path.join(ROOT, "_cred.py")
    if os.path.isfile(helper):
        try:
            import subprocess
            import sys
            out = subprocess.run([sys.executable, helper], capture_output=True, text=True, timeout=60)
            if out.returncode == 0 and out.stdout.strip():
                return out.stdout.strip()
        except Exception:
            pass
    return None


def _get(url, token=None, timeout=90):
    headers = {"User-Agent": "dsh-preflight"}
    if token:
        headers["Authorization"] = "Bearer " + token
    req = urllib.request.Request(url, headers=headers)
    with urllib.request.urlopen(req, timeout=timeout) as r:
        return r.read()


FULL_SHA = re.compile(r"[0-9a-fA-F]{40}")


def _safe_part(value):
    return (value not in ("", ".", "..") and not any(c in value for c in "\\:\0")
            and not (os.name == "nt" and os.path.isreserved(value)))


def cache_key(repo, head, task):
    if not FULL_SHA.fullmatch(head):
        raise ValueError("--head must be a full 40-character Git SHA")
    if not re.fullmatch(r"[A-Za-z0-9_-]+/[A-Za-z0-9_.-]+", repo) or not all(
            _safe_part(part) for part in repo.split("/")):
        raise ValueError("--repo must be owner/repository")
    if not re.fullmatch(r"[A-Za-z0-9_-]+", task) or not _safe_part(task):
        raise ValueError("invalid task: %s" % task)
    return (*repo.lower().split("/"), head.lower(), task)


def git_blob_sha1(data):
    h = hashlib.sha1()
    h.update(b"blob %d\0" % len(data))
    h.update(data)
    return h.hexdigest()


def list_item_files(head, task, repo=DEFAULT_REPO, token=None):
    url = "https://api.github.com/repos/%s/git/trees/%s?recursive=1" % (repo, head)
    body = json.loads(_get(url, token).decode("utf-8"))
    if body.get("truncated"):
        raise RuntimeError("git tree for %s is truncated; fetch by subtree instead" % head[:12])
    prefix = "handoff/inbox/%s/" % task
    files = {}
    for entry in body["tree"]:
        path = entry["path"]
        if entry["type"] != "blob" or not path.startswith(prefix):
            continue
        rel, sha = path[len(prefix):], entry["sha"]
        if not all(_safe_part(part) for part in rel.split("/")) or rel in files or not FULL_SHA.fullmatch(sha):
            raise RuntimeError("invalid git tree entry: %r" % path)
        files[rel] = sha.lower()
    return files


def _verify_item_files(item_dir, files):
    def require_unlinked(path):
        if os.path.islink(path) or os.path.normcase(os.path.realpath(path)) != os.path.normcase(path):
            raise RuntimeError("unexpected link in cache: %s" % path)

    def walk_error(exc):
        raise exc

    require_unlinked(item_dir)
    have = {}
    for parent, dirs, names in os.walk(item_dir, onerror=walk_error):
        for name in dirs + names:
            require_unlinked(os.path.join(parent, name))
        for name in names:
            path = os.path.join(parent, name)
            have[os.path.relpath(path, item_dir).replace(os.sep, "/")] = path
    if have.keys() != files.keys():
        raise RuntimeError("cache file paths differ: missing=%s extra=%s" % (
            sorted(files.keys() - have.keys()), sorted(have.keys() - files.keys())))
    for rel, path in have.items():
        if not os.path.isfile(path):
            raise RuntimeError("not a regular cache file: %s" % rel)
        with open(path, "rb") as f:
            if git_blob_sha1(f.read()) != files[rel]:
                raise RuntimeError("cache blob differs: %s" % rel)


def fetch_head(head, task, dest, repo=DEFAULT_REPO, workers=8, token=None):
    owner, name, head, task = cache_key(repo, head, task)
    repo = "%s/%s" % (owner, name)
    token = token or _token()
    files = list_item_files(head, task, repo, token)
    if not files:
        raise RuntimeError("no files under handoff/inbox/%s at %s" % (task, head))
    parent, name = os.path.split(os.path.abspath(dest))
    parent = os.path.realpath(parent)
    dest = os.path.join(parent, name)
    suffix = ("handoff", "inbox", task)
    item_dir = os.path.join(dest, *suffix)
    if os.path.lexists(dest):
        _verify_item_files(item_dir, files)
        return item_dir

    os.makedirs(parent, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=parent) as tmp:
        staged = os.path.join(tmp, "delivery")
        staged_item = os.path.join(staged, *suffix)

        def one(rel):
            target = os.path.join(staged_item, *rel.split("/"))
            os.makedirs(os.path.dirname(target), exist_ok=True)
            url = "https://raw.githubusercontent.com/%s/%s/handoff/inbox/%s/%s" % (repo, head, task, quote(rel))
            data = _get(url, token)
            with open(target, "xb") as f:
                f.write(data)

        with cf.ThreadPoolExecutor(max_workers=workers) as pool:
            list(pool.map(one, files))
        _verify_item_files(staged_item, files)
        os.rename(staged, dest)
    return item_dir
