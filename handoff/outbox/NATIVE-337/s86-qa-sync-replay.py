"""Replay the pinned QA sync and independently reconcile the s86 file fingerprint list."""
from concurrent.futures import ThreadPoolExecutor
from hashlib import sha1, sha256
from importlib.util import module_from_spec, spec_from_file_location
import json
from pathlib import Path, PurePosixPath
from tempfile import TemporaryDirectory
from urllib.parse import quote
from urllib.request import Request, urlopen

REPO = "DenseFLoe/Aspen-for-mac"
QA = "13fe04a534dfaad3c896e2230d0139f6c1533a0a"
QA_TREE = "c57b6cc0a54450cff7407fa0a9af9485e620e3e3"
CANDIDATE = "a93daa5523ab7865228ce73c279bc69f2d3e020c"
CANDIDATE_TREE = "cc56b2a6b3126ceca4c0286b8d6fa56395318b30"
INBOX = "handoff/inbox/NATIVE-337/"
MANIFEST = INBOX + "s86-fingerprints.json"
MANIFEST_BLOB = "4277578659818fdb325346ed9b88a704d51a96f6"
API = "https://api.github.com/repos/" + REPO + "/"
RAW = "https://raw.githubusercontent.com/" + REPO + "/"


def get(url):
    for attempt in range(3):
        try:
            with urlopen(Request(url, headers={"User-Agent": "aspen-handoff-audit"}), timeout=25) as response:
                return response.read()
        except OSError:
            if attempt == 2:
                raise


def digest(data):
    return sha256(data).hexdigest()


def blob(data):
    return sha1(f"blob {len(data)}\0".encode() + data).hexdigest()


def list_tree(tree):
    root = json.loads(get(API + f"git/trees/{tree}?recursive=1"))
    assert root["sha"] == tree and not root["truncated"]
    return root


def read_blob(ref, row, cache=None):
    path = PurePosixPath(row["path"])
    assert not path.is_absolute() and ".." not in path.parts and row["mode"] == "100644"
    for base in cache or []:
        local = base.joinpath(*path.parts)
        if local.is_file():
            data = local.read_bytes()
            if (len(data), blob(data)) == (row["size"], row["sha"]):
                return data
    data = get(RAW + ref + "/" + quote(row["path"]))
    assert (len(data), blob(data)) == (row["size"], row["sha"]), row["path"]
    return data


def manifest_recheck(cache):
    rows = {r["path"]: r for r in list_tree(CANDIDATE_TREE)["tree"] if r["type"] == "blob"}
    pin = rows[MANIFEST]
    assert pin["sha"] == MANIFEST_BLOB
    source = read_blob(CANDIDATE, pin, cache)
    expected = json.loads(source)
    def check(item):
        name, want = item
        data = read_blob(CANDIDATE, rows[INBOX + name], cache)
        assert digest(data) == want, name
        return (name, want)
    with ThreadPoolExecutor(max_workers=8) as pool:
        checked = dict(pool.map(check, expected.items()))
    return {"sha256": digest(source), "count": len(checked), "files": checked}


def audit_sync(root):
    tree = list_tree(QA_TREE)
    rows = [r for r in tree["tree"] if r["type"] == "blob"]
    with ThreadPoolExecutor(max_workers=8) as pool:
        payloads = dict(zip((r["path"] for r in rows), pool.map(lambda r: read_blob(QA, r), rows)))
    assert blob(payloads["qa/sync.py"]) == "cd212bdcd9d5fb6680886c2e43b890923e020f02"
    source = root / "sync.py"
    source.write_bytes(payloads["qa/sync.py"])
    spec = spec_from_file_location("fixed_qa_sync", source)
    mod = module_from_spec(spec)
    spec.loader.exec_module(mod)
    mod.api = lambda path, _token: tree if path == f"/repos/{REPO}/git/trees/{QA}?recursive=1" else None
    mod.get = lambda url, **_: payloads[url.removeprefix(RAW + QA + "/")]
    mod.token = lambda: None
    results = []
    for name in ("first", "second"):
        target = root / name
        replay = mod.sync(QA, str(target))
        manifest = json.loads((target / "MANIFEST.json").read_bytes())
        layout = {p.relative_to(target).as_posix() for p in target.rglob("*") if p.is_file()}
        assert layout - {"MANIFEST.json"} == payloads.keys()
        assert manifest["files"] == [{"path": path, "sha256": digest(data), "bytes": len(data)}
                                     for path, data in sorted(payloads.items())]
        assert all((target / path).read_bytes() == data for path, data in payloads.items())
        stable = json.dumps(manifest["files"], ensure_ascii=False, sort_keys=True, separators=(",", ":")).encode()
        results.append({"files": replay["files"], "generated_at": manifest["generated_at"],
                        "manifest_sha256": replay["manifest_sha256"], "file_records_sha256": digest(stable),
                        "unexpected_paths": []})
    assert results[0]["manifest_sha256"] != results[1]["manifest_sha256"]
    assert results[0]["file_records_sha256"] == results[1]["file_records_sha256"]
    return {"head": QA, "tree": QA_TREE, "sync_sha256": digest(payloads["qa/sync.py"]), "runs": results}


if __name__ == "__main__":
    with TemporaryDirectory() as temp:
        result = {"sync": audit_sync(Path(temp)), "candidate": CANDIDATE,
                  "candidate_tree": CANDIDATE_TREE, "fingerprints": manifest_recheck([])}
    print(json.dumps(result, ensure_ascii=False, indent=2))
