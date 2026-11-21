"""Publish one indexed release asset on the archive work branch in GitHub Actions."""

import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import tarfile
import tempfile
import time
from collections import defaultdict
from urllib.parse import quote
from urllib.request import Request, urlopen


REPO = "DenseFLoe/Aspen-for-mac"
BRANCH = "codex/organize-reverse-20261121"
REF = "refs/heads/" + BRANCH
TAG = "v0.20261121-w2"
PLANS = "项目资料/整理清单/发布包"
RECEIPTS = PLANS + "/核对"
STATES = {"静态验收通过", "静态验收未通过", "待静态验收", "未成功"}
CHUNK = 48 * 1024**2
BUFFER = 1024**2
SUFFIX = re.compile(r"\.(?:c|asm|cs|il)\.txt\Z", re.I)
HASH = re.compile(r"[a-f0-9]{64}\Z")
# These exact ledgers were produced by the per-artifact publication review of
# release v0.20261121-w2. Changed bytes, destinations or new files require a
# fresh review and new pinned ledger hashes before the publisher will run.
REVIEWED_ASSETS_SHA256 = "9d354cf691bce7fb95cae4a10dee15aa59205640b9c691d89a12c837ecf1572b"
REVIEWED_PLANS = {
    1: "1d0a4edc652d3276300bb9111b8cbccf9512448377f08bf295a302e08200e86b",
    2: "52f4a2c8d2c4fcf6314cc39b8b428a2497ec56c9f9f11304b6c2f62f95bbf7b4",
    3: "34d359842632ff850b1230cd2cbbb7c2fb17fb57937037c9a356c7d4894b6dd0",
    4: "e9b25688e513119c4490736499412424effa2d0d54225f06ef5793935cd5fc1b",
    5: "231e8a2c11da3f6a80e62ee8f307702f151052e75187e0cc0c8c67d277e5f377",
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def dump(record):
    return (json.dumps(record, ensure_ascii=False, separators=(",", ":")) + "\n").encode()


def parts(path):
    require(isinstance(path, str) and path and "\\" not in path and ":" not in path, "invalid path")
    segments = path.split("/")
    require(all(s and not s.startswith(".") and not any(ord(c) < 32 or c == "\x7f" for c in s)
                for s in segments), "unsafe path component")
    return segments


def validate_target(path):
    p = parts(path)
    require(len(p) >= 7 and p[0] == "逆向成果" and p[1] in STATES and p[-3] == TAG
            and p[-2] in {"正式导出", "阶段导出"} and SUFFIX.search(p[-1]), "unexpected output path")
    return path


def member_name(name):
    while name.startswith("./"):
        name = name[2:]
    parts(name)
    return name


def read_plan(raw, asset):
    rows = []
    for line in raw.splitlines():
        if not line.strip():
            continue
        row = json.loads(line)
        require(row["asset"] == asset["name"] and type(row["size"]) is int and row["size"] >= 0,
                "invalid member metadata")
        require(HASH.fullmatch(row["artifact_sha256"]) and HASH.fullmatch(row["original_sha256"]),
                "invalid manifest hash")
        row["member"] = member_name(row["member"])
        require(SUFFIX.search(row["member"]), "unexpected asset member type")
        if row.get("target"):
            validate_target(row["target"])
        else:
            require(bool(row.get("skip_reason")), "indexed exclusion needs a reason")
        rows.append(row)
    require(rows, "empty part index")
    return rows


class HashReader:
    def __init__(self, stream, limit):
        self.stream = stream
        self.sha = hashlib.sha256()
        self.size = 0
        self.limit = limit

    def read(self, size):
        data = self.stream.read(size)
        self.size += len(data)
        require(self.size <= self.limit, "asset exceeds published size")
        self.sha.update(data)
        return data


def git(*args, data=None, env=None):
    return subprocess.run(["git", *args], input=data, env=env, stdout=subprocess.PIPE, check=True).stdout


def git_blob(data):
    return git("hash-object", "-w", "--stdin", data=data).decode().strip()


def describe_blob_set(stream, size, chunk_size=CHUNK, writer=git_blob):
    result = []
    stream.seek(0)
    while block := stream.read(chunk_size):
        result.append({"git_blob_sha": writer(block), "size": len(block),
                       "sha256": hashlib.sha256(block).hexdigest()})
    require(sum(p["size"] for p in result) == size, "temporary file size mismatch")
    return result


def named_outputs(blob_set, row, writer):
    target = row["target"]
    if len(blob_set) == 1:
        return [dict(blob_set[0], path=target)]
    directory = target + ".分片/"
    outputs = [dict(part, path=directory + f"{n:04d}.part.txt") for n, part in enumerate(blob_set, 1)]
    readme = (
        f"# 大文件分片\n\n原文件名为 `{target.rsplit('/', 1)[-1]}`，共 {row['size']} 字节。\n\n"
        f"按四位数字文件名从小到大拼接各片的原始字节即可恢复。"
        f"在此目录运行 `cat [0-9][0-9][0-9][0-9].part.txt > restored.txt`。\n\n"
        f"完整文件的 SHA-256 为 `{row['artifact_sha256']}`。\n"
    ).encode()
    outputs.append({"path": directory + "README.md", "git_blob_sha": writer(readme), "size": len(readme),
                    "sha256": hashlib.sha256(readme).hexdigest()})
    return outputs


def inspect_asset(stream, asset, rows, writer=git_blob, chunk_size=CHUNK):
    pending = defaultdict(list)
    for row in rows:
        pending[row["member"]].append(row)
    receipts = []
    outputs = {}
    cached = {}
    reader = HashReader(stream, asset["size"])
    with tarfile.open(fileobj=reader, mode="r|gz", bufsize=128 * 1024) as archive:
        for entry in archive:
            if entry.isdir() and entry.name.rstrip("/") in {".", ""}:
                continue
            name = member_name(entry.name.rstrip("/") if entry.isdir() else entry.name)
            if entry.isdir():
                continue
            require(entry.isfile() and not entry.issparse(), "archive contains an unsupported member type")
            choices = pending.get(name)
            require(choices and any(r["size"] == entry.size for r in choices), "unindexed member or size mismatch")
            with archive.extractfile(entry) as content, tempfile.TemporaryFile() as temp:
                sha = hashlib.sha256()
                size = 0
                save = any(r.get("target") and r["artifact_sha256"] not in cached for r in choices)
                while block := content.read(BUFFER):
                    size += len(block)
                    sha.update(block)
                    if save:
                        temp.write(block)
                digest = sha.hexdigest()
                row = next((r for r in choices if r["artifact_sha256"] == digest and r["size"] == size), None)
                require(row is not None, "indexed member SHA-256 mismatch")
                choices.remove(row)
                if not choices:
                    del pending[name]
                reason = row.get("skip_reason") or ""
                item = {"member": name, "size": size, "artifact_sha256": digest,
                        "original_sha256": row["original_sha256"], "target": row.get("target")}
                if reason:
                    item["skip_reason"] = reason
                else:
                    if digest not in cached:
                        cached[digest] = describe_blob_set(temp, size, chunk_size, writer)
                    item["outputs"] = named_outputs(cached[digest], row, writer)
                    for o in item["outputs"]:
                        old = outputs.setdefault(o["path"], o["git_blob_sha"])
                        require(old == o["git_blob_sha"], "output path collision")
                receipts.append(item)
    while reader.read(BUFFER):
        pass
    require(not pending and len(receipts) == len(rows), "archive member count mismatch")
    require(reader.size == asset["size"] and reader.sha.hexdigest() == asset["sha256"], "asset hash or size mismatch")
    return outputs, receipts


def read_ref():
    git("fetch", "--no-tags", "origin", REF)
    return git("rev-parse", "FETCH_HEAD").decode().strip()


def object_names(commit):
    entries = {}
    for line in git("ls-tree", "-r", "-z", "--full-tree", commit).split(b"\0"):
        if line:
            header, path = line.split(b"\t", 1)
            mode, _, sha = header.decode().split(" ")
            entries[path.decode()] = (mode, sha)
    return entries


def check_existing(existing, outputs):
    for path, sha in outputs.items():
        if path in existing:
            require(existing[path] == ("100644", sha), "a target already has different content or mode")
        ancestor = path
        while "/" in ancestor:
            ancestor = ancestor.rsplit("/", 1)[0]
            require(ancestor not in existing and ancestor not in outputs, "file/directory collision")
    for path in existing:
        ancestor = path
        while "/" in ancestor:
            ancestor = ancestor.rsplit("/", 1)[0]
            require(ancestor not in outputs, "a target would replace an existing directory")


def publish(part, base, inputs, outputs):
    for attempt in range(4):
        latest = read_ref()
        git("merge-base", "--is-ancestor", base, latest)
        for path, blob in inputs.items():
            require(git("rev-parse", f"{latest}:{path}").decode().strip() == blob, "work-branch input changed")
        existing = object_names(latest)
        check_existing(existing, outputs)
        add = {p: oid for p, oid in outputs.items() if p not in existing}
        if not add:
            git("update-ref", "HEAD", latest)
            print(f"Part {part}: verified existing files and receipt.")
            return
        with tempfile.TemporaryDirectory() as tmp:
            env = dict(os.environ, GIT_INDEX_FILE=str(Path(tmp) / "index"))
            git("read-tree", latest, env=env)
            records = b"".join(b"100644 " + oid.encode() + b"\t" + p.encode() + b"\0" for p, oid in sorted(add.items()))
            git("update-index", "-z", "--index-info", data=records, env=env)
            tree = git("write-tree", env=env).decode().strip()
            commit = git("commit-tree", tree, "-p", latest, "-m", f"归档已核对的发布包第 {part} 部分").decode().strip()
        pushed = subprocess.run(["git", "push", "origin", f"{commit}:{REF}"], check=False)
        if pushed.returncode == 0:
            git("update-ref", "HEAD", commit)
            print(f"Part {part}: {len(add)} paths committed as {commit}.")
            return
        if attempt < 3:
            time.sleep(2 ** attempt)
    raise RuntimeError("normal push failed after retry")


def run(part):
    require(os.environ.get("GITHUB_ACTIONS") == "true" and os.environ.get("GITHUB_REPOSITORY", "").lower() == REPO.lower(),
            "run this publisher in the Aspen GitHub Actions repository")
    branch = subprocess.run(["git", "symbolic-ref", "-q", "HEAD"], capture_output=True, text=True).stdout.strip()
    require(branch == REF or (not branch and os.environ.get("GITHUB_REF") == REF), "wrong working branch")
    base = read_ref()
    prefix = f"{RECEIPTS}/part{part}"
    plan_path = f"{PLANS}/part{part}.jsonl"
    asset_path = f"{PLANS}/assets.json"
    script_path = "tools/archive/unpack_release.py"
    inputs = {p: git("rev-parse", f"{base}:{p}").decode().strip() for p in (plan_path, asset_path, script_path)}
    require(git("hash-object", script_path).decode().strip() == inputs[script_path], "publisher differs from work branch")
    raw_plan = git("cat-file", "blob", inputs[plan_path])
    raw_assets = git("cat-file", "blob", inputs[asset_path])
    require(hashlib.sha256(raw_assets).hexdigest() == REVIEWED_ASSETS_SHA256, "release asset list changed since review")
    require(hashlib.sha256(raw_plan).hexdigest() == REVIEWED_PLANS[part], "part index changed since publication review")
    assets = json.loads(raw_assets)
    name = f"dumps-w2-part{part}.tar.gz"
    matches = [a for a in assets if a["name"] == name]
    require(len(matches) == 1, "expected one indexed asset for this part")
    asset = matches[0].copy()
    asset["sha256"] = asset.get("sha256") or asset.get("digest", "").removeprefix("sha256:")
    require(HASH.fullmatch(asset["sha256"]) and type(asset["size"]) is int and asset["size"] > 0, "invalid asset metadata")
    require(asset["url"] == f"https://github.com/{REPO}/releases/download/{TAG}/{quote(name)}", "unexpected download URL")
    rows = read_plan(raw_plan, asset)
    request = Request(asset["url"], headers={"User-Agent": "Aspen archive verification", "Accept-Encoding": "identity"})
    with urlopen(request, timeout=180) as response:
        outputs, receipts = inspect_asset(response, asset, rows)
    summary = {"asset": name, "sha256": asset["sha256"], "size": asset["size"],
               "plan_sha256": hashlib.sha256(raw_plan).hexdigest(), "members": len(receipts),
               "published_members": sum("outputs" in r for r in receipts), "distinct_output_paths": len(outputs),
               "excluded_members": sum("skip_reason" in r for r in receipts)}
    outputs[prefix + ".jsonl"] = git_blob(b"".join(dump(r) for r in receipts))
    outputs[prefix + ".json"] = git_blob(dump(summary))
    publish(part, base, inputs, outputs)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--part", type=int, choices=range(1, 6), required=True)
    run(parser.parse_args().part)
