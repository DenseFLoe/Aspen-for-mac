# -*- coding: utf-8 -*-
"""Two fingerprint sets for NATIVE-340, runnable from a fixed commit.

  --set receipt : product hashes used by the upstream checker (path it reads:
                  code/s29-fingerprints.json).  Excludes receipts and other
                  fingerprint files so it stays stable across rounds.
  --set round   : the round receipt, includes receipts and the audit page, and
                  records the fixed base head it was produced from.
"""
import argparse, hashlib, json
from pathlib import Path


def collect(unit, include_receipts):
    out = {}
    for p in sorted(unit.rglob("*")):
        if not p.is_file() or "fingerprints" in p.name:
            continue
        if not include_receipts and ("-submission.md" in p.name or "-started.md" in p.name):
            continue
        out[p.relative_to(unit).as_posix()] = hashlib.sha256(p.read_bytes()).hexdigest()
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--set", choices=("receipt", "round"), required=True)
    ap.add_argument("--unit", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--base-head", default="")
    ap.add_argument("--rules-out", default="")
    a = ap.parse_args()
    files = collect(Path(a.unit), include_receipts=(a.set == "round"))
    if a.set == "receipt":
        # the upstream checker reads this file as a flat {path: sha256} map
        doc = files
    else:
        doc = dict(base_head=a.base_head, count=len(files), files=files)
    Path(a.out).write_text(json.dumps(doc, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    if a.rules_out:
        lines = ["# 指纹文件选择规则（脚本生成）", "",
                 "## 规则", "",
                 "- 范围：`--unit` 目录下的全部常规文件（递归）。",
                 "- 排除：文件名含 `fingerprints` 的文件（指纹 JSON 与其规则索引都不自引用）。",
                 "- `--set receipt`（上游脚本读取的扁平映射）：额外排除 `*-started.md` 与 `*-submission.md`，"
                 "本轮回执不进入该集，保证跨轮稳定。",
                 "- `--set round`（当轮回执）：纳入开工/提交回执与审计页，并把 `base_head` 记在文件头部。",
                 "- 哈希：SHA-256，按路径字典序；路径相对 `--unit`。",
                 "- `code/README.md` 属于常规文件，两套都在集内。", "",
                 "## 纳入路径（%d 个，set=%s，base_head=%s）" % (len(files), a.set, a.base_head or "-"), "",
                 "| 路径 | SHA-256 |", "| --- | --- |"]
        for path, digest in files.items():
            lines.append("| `%s` | `%s` |" % (path, digest))
        Path(a.rules_out).write_text("\n".join(lines) + "\n", encoding="utf-8")
        print("rules -> %s" % a.rules_out)
    print("%s: %d files -> %s" % (a.set, len(files), a.out))


if __name__ == "__main__":
    main()
