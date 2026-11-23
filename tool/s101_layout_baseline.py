# -*- coding: utf-8 -*-
"""Regenerate the pre-merge layout baseline from a committed head (self-describing JSON)."""
import argparse, base64, hashlib, importlib.util, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tool"))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--head", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--original", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--task", default="NATIVE-340")
    a = ap.parse_args()
    import gh
    from pe_reader import PE
    data = Path(a.original).read_bytes()
    try:
        pe = PE(data)
        cli = pe.directory(14)[0]
    except Exception:
        cli = 0
    if not cli:
        print("%s: not-applicable (no CLI metadata)" % a.task)
        Path(a.out).write_text(json.dumps({"task": a.task, "original": a.original,
                                           "status": "not-applicable (no CLI metadata)"},
                                          ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
        return 0
    off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    tree = gh.call("GET", "/repos/%s/git/trees/%s?recursive=1" % (gh.REPO, a.head))
    blob = {t["path"]: t["sha"] for t in tree["tree"] if t["type"] == "blob"}["tool/cli_tables.py"]
    raw = base64.b64decode(gh.call("GET", "/repos/%s/git/blobs/%s" % (gh.REPO, blob))["content"])
    sha = hashlib.sha256(raw).hexdigest()
    tmp = ROOT / "_t14" / "old_head" / ("cli_tables_%s.py" % a.head[:8])
    tmp.parent.mkdir(parents=True, exist_ok=True)
    tmp.write_bytes(raw)
    spec = importlib.util.spec_from_file_location("old_cli_" + a.head[:8], tmp)
    mod = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = mod
    spec.loader.exec_module(mod)
    T = mod.read(data, off)
    doc = {
        "head": a.head,
        "source_file": "tool/cli_tables.py",
        "source_sha256": sha,
        "original": Path(a.original).name,
        "original_sha256": hashlib.sha256(data).hexdigest(),
        "stream": T["stream"],
        "heap_sizes": T["heap_sizes"],
        "columns": len(T["layout"]),
        "command": "python -B tool/s101_layout_baseline.py --head %s --out <path>" % a.head[:8],
        "layout": T["layout"],
    }
    Path(a.out).write_text(json.dumps(doc, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("baseline: head %s columns %d stream %s heap 0x%02X -> %s"
          % (a.head[:8], len(T["layout"]), T["stream"], T["heap_sizes"], a.out))
    return 0


if __name__ == "__main__":
    sys.exit(main())
