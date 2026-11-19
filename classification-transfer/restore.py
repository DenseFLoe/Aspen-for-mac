"""One-time restore of the reviewed, metadata-only classification snapshot."""
import base64
import gzip
import hashlib
import json
from pathlib import Path
import subprocess

BASE = "309441c0ab484ccfe62b424c623198d56f2959e1"
TREE = "d50ad4f34678d191f19c7c834a4cc0c015d3a1b2"
PACKED_SHA256 = "bf86246cf2070eb2aa9b536cf1604bb10f6b01f8a24a8b81aaee42a65d33e84f"
ROOT = Path.cwd().resolve()
ALLOWED_FIXED = {
    ".gitattributes", "AGENTS.md", "README.md",
    "docs/aspen-plus-classification.md", "docs/aspen-properties-classification.md",
    "docs/development-requirements.md", "docs/plus-properties-inventory.md",
    "docs/plus-properties-shared-files.md", "tools/verify_published_classification.py",
}


def git(*args):
    return subprocess.check_output(["git", *args], text=True).strip()


def main():
    if git("rev-parse", "HEAD^") != BASE:
        raise ValueError("Unexpected transfer parent")
    parts = sorted((ROOT / "classification-transfer").glob("part-*.b64"))
    if len(parts) != 10:
        raise ValueError("Unexpected transfer part count")
    packed = b"".join(base64.b64decode(path.read_text().strip(), validate=True) for path in parts)
    if hashlib.sha256(packed).hexdigest() != PACKED_SHA256:
        raise ValueError("Transfer checksum mismatch")
    payload = json.loads(gzip.decompress(packed))
    if payload["base"] != BASE or payload["expected_tree"] != TREE or len(payload["files"]) != 29:
        raise ValueError("Unexpected snapshot")
    paths = set()
    for entry in payload["files"]:
        path = Path(entry["path"])
        target = (ROOT / path).resolve()
        if (path.as_posix() not in ALLOWED_FIXED
                and not path.as_posix().startswith("inventories/2026-11-19/")):
            raise ValueError("Path outside upload scope")
        if not target.is_relative_to(ROOT) or path.as_posix() in paths or entry["mode"] != "100644":
            raise ValueError("Unsafe or duplicate path")
        if path.suffix not in {".md", ".csv", ".json", ".py"} and path.name != ".gitattributes":
            raise ValueError("Non-metadata file")
        raw = entry["content"].encode("utf-8")
        blob = b"blob " + str(len(raw)).encode() + b"\0" + raw
        if hashlib.sha1(blob).hexdigest() != entry["sha"]:
            raise ValueError("Blob checksum mismatch")
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(raw)
        paths.add(path.as_posix())
    subprocess.run(["python", "tools/verify_published_classification.py"], check=True)
    subprocess.run(["git", "add", "--", *sorted(paths)], check=True)
    subprocess.run(["git", "rm", "-r", "--", "classification-transfer",
                    ".github/workflows/import-classification.yml"], check=True)
    if git("write-tree") != TREE:
        raise ValueError("Restored tree differs from reviewed local tree")
    subprocess.run(["git", "diff", "--cached", "--check"], check=True)
    print("Restored and verified all 29 reviewed files; final tree:", TREE)


if __name__ == "__main__":
    main()
