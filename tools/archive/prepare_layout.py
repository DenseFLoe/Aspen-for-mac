"""Install the verified document and Git blob mappings on the dedicated staging branch."""
import gzip
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import subprocess
import tempfile

BRANCH = "codex/organize-reverse-20261121"
PLAN = Path("项目资料/整理清单/发布包")

def git(*args, data=None, env=None):
    return subprocess.run(["git", *args], input=data, env=env, capture_output=True, check=True).stdout

def main():
    if os.getenv("GITHUB_REPOSITORY") != "DenseFLoe/Aspen-for-mac" or os.getenv("GITHUB_REF_NAME") != BRANCH:
        raise RuntimeError("Unexpected repository or branch")
    head = git("rev-parse","HEAD").decode().strip()
    branch_ref = "refs/heads/"+BRANCH
    if git("ls-remote","origin",branch_ref).decode().split()[0] != head:
        raise RuntimeError("The working branch has advanced")
    plain = gzip.decompress((PLAN/"layout.jsonl.gz").read_bytes())
    summary = json.loads((PLAN/"summary.json").read_bytes())
    if hashlib.sha256(plain).hexdigest()!=summary["layout_sha256"]:
        raise ValueError("Layout digest mismatch")
    original = {}
    for line in git("ls-tree","-r","-z",head).split(b"\0"):
        if line:
            meta,p=line.split(b"\t",1)
            original[p.decode()]=meta.split()[2].decode()
    known = set(original.values())
    index_rows = []
    checked = {}
    rows = [json.loads(line) for line in plain.splitlines()]
    if len(rows)!=summary["paths"]:
        raise ValueError("Layout entry count mismatch")
    for r in rows:
        path = r["path"]
        parts = PurePosixPath(path).parts
        if path.startswith("/") or any(p in ("..",".git") for p in parts) or "\0" in path or "\\" in path:
            raise ValueError("Invalid archive path")
        if r["mode"] != "100644" or r["type"]!="blob" or path in checked:
            raise ValueError("Duplicate or non-file record")
        if "content" in r:
            sha = git("hash-object","-w","--stdin",data=r["content"].encode("utf-8")).decode().strip()
            known.add(sha)
        else:
            sha = r["sha"]
        checked[path]=sha
    if set(checked.values())-known:
        raise ValueError("The layout refers to an unknown blob")
    for path,sha in checked.items():
        if original.get(path)!=sha:
            index_rows.append(f"100644 {sha}\t{path}\0".encode())
    if not index_rows:
        print("Existing classified tree verified")
        return
    with tempfile.TemporaryDirectory() as tmp:
        env={**os.environ,"GIT_INDEX_FILE":str(Path(tmp)/"index")}
        git("read-tree",head,env=env)
        git("update-index","-z","--index-info",data=b"".join(index_rows),env=env)
        tree=git("write-tree",env=env).decode().strip()
    after = {}
    for line in git("ls-tree","-r","-z",tree).split(b"\0"):
        if line:
            meta,p=line.split(b"\t",1)
            after[p.decode()]=meta.split()[2].decode()
    if after != {**original,**checked}:
        raise RuntimeError("Candidate tree differs from the reviewed paths")
    commit=git("commit-tree",tree,"-p",head,"-m","逐件归档已验收成果、已有批次与报告").decode().strip()
    git("push","origin",f"{commit}:{branch_ref}")
    git("update-ref","HEAD",commit,head)
    print(f"Verified {len(checked)} paths; published {commit} on the work branch")

if __name__=="__main__":
    main()
