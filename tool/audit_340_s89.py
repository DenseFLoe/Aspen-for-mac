# -*- coding: utf-8 -*-
"""NATIVE-340 s89: widths from the real parse path, IL digest identity, dependencies."""
import argparse, csv, hashlib, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "bde39b4630809020fd972211e9b64010e13410d7"
MAIN_HEAD = "2cb8a177"


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    a = ap.parse_args()
    folder = Path(a.folder); code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    tables = cli_tables.read(data, md_off)
    ctl = []

    layout = tables["layout"]
    write_csv(code / "s89-column-widths.csv",
              ["table", "column", "width", "rows", "row_size", "rule"], layout)
    row_sizes = {}
    for l in layout:
        row_sizes.setdefault(l["table"], l["row_size"])
    ctl += [("parser stream %s, HeapSizes=0x%02X read from the stream header"
             % (tables["stream"], tables["heap_sizes"]), tables["stream"] in ("#~", "#-")),
            ("all heap indexes are 2 bytes", all(l["width"] == 2 for l in layout
                                                 if l["rule"].startswith("heap"))),
            ("layout exposes %d columns / %d tables" % (len(layout), len(row_sizes)), len(layout) > 50)]
    for tname in ("MethodDef", "MemberRef", "CustomAttribute"):
        total = sum(l["width"] for l in layout if l["table"] == tname)
        ctl.append(("%s row size equals the column sum" % tname,
                    row_sizes.get(tname) == total and total > 0))

    pairs = []
    for name, bits, lo, hi in (("MemberRefParent", 3, 8191, 8192),
                               ("TypeDefOrRef", 2, 16383, 16384),
                               ("MethodDefOrRef", 1, 32767, 32768)):
        pairs.append(dict(space=name, tag_bits=bits, low_rows=lo,
                          low_width=cli_tables.coded_width(bits, lo),
                          high_rows=hi, high_width=cli_tables.coded_width(bits, hi),
                          derivation="threshold 2**(16-%d)=%d" % (bits, 1 << (16 - bits))))
    write_csv(code / "s89-threshold-pairs.csv",
              ["space", "tag_bits", "low_rows", "low_width", "high_rows", "high_width", "derivation"], pairs)
    ctl += [("8191/8192 -> 2/4", pairs[0]["low_width"] == 2 and pairs[0]["high_width"] == 4),
            ("16383/16384 -> 2/4", pairs[1]["low_width"] == 2 and pairs[1]["high_width"] == 4),
            ("32767/32768 -> 2/4", pairs[2]["low_width"] == 2 and pairs[2]["high_width"] == 4)]

    meta = md_reader.parse(data, md_off)
    digests = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        digests.append(dict(row=len(digests) + 1, token="0x%08X" % m["token"], name=m["name"],
                            rva="0x%X" % m["rva"], il_len=len(hdr["il"]),
                            sha256=hashlib.sha256(hdr["il"]).hexdigest()))
    write_csv(code / "s89-il-digests.csv",
              ["row", "token", "name", "rva", "il_len", "sha256"], digests)
    tokens = [d["token"] for d in digests]
    dup_tokens = sorted({t for t in tokens if tokens.count(t) > 1})
    declared = read_csv(code / "s77-il-fingerprints.csv")
    declared_by_token = {}
    declared_dup = []
    for r in declared:
        if r["token"] in declared_by_token:
            declared_dup.append(r["token"])
        declared_by_token[r["token"]] = r["il_sha256"]
    mine = {d["token"]: d["sha256"] for d in digests}
    missing = sorted(set(declared_by_token) - set(mine))
    extra = sorted(set(mine) - set(declared_by_token))
    content = sorted(t for t in mine if t in declared_by_token and mine[t] != declared_by_token[t])
    drows = [dict(category="missing", count=len(missing), sample=",".join(missing[:3])),
             dict(category="extra", count=len(extra), sample=",".join(extra[:3])),
             dict(category="duplicate", count=len(dup_tokens) + len(declared_dup),
                  sample=",".join((dup_tokens + declared_dup)[:3])),
             dict(category="content_diff", count=len(content), sample=",".join(content[:3]))]
    write_csv(code / "s89-digest-diffs.csv", ["category", "count", "sample"], drows)
    ctl += [("digest table keeps row identity", len({d["row"] for d in digests}) == len(digests) == 167),
            ("no duplicate token before building the map", not dup_tokens and not declared_dup),
            ("four categories all zero", all(r["count"] == 0 for r in drows))]

    deps = ["# NATIVE-340 s89 re-run dependencies", "",
            "| dep | version / source | use |", "| --- | --- | --- |",
            "| Python | 3.13 | all scripts |",
            "| pefile | 2024.8.26 | qa gate IAT/byte checks |",
            "| .NET SDK | 9.0.302 | PEReader endpoint check |",
            "| System.Reflection.Metadata | in-box .NET 9 | PEReader |",
            "| capstone | qa gate dependency | linear disassembly census |", "",
            "Commands:", "",
            "python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission handoff/inbox/NATIVE-340",
            "cd _tools/qa/27007e5a && PYTHONPATH=<repo>/.local/pylibs python -B -m qa.gate --task NATIVE-340 --head HEAD",
            "dotnet run -c Release -- ORIGINAL    # _t14/pereader project",
            "python -B tool/audit_340_s89.py --binary ORIGINAL --folder handoff/inbox/NATIVE-340", ""]
    (code / "s89-dependencies.md").write_text("\n".join(deps), encoding="utf-8")

    sites = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        for x in il_disasm.decode(hdr["il"]):
            if x[1] in ("call", "callvirt", "newobj", "ldftn") and x[2].lower() == "0x06000056":
                sites += 1
    clauses = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if hdr["more_sections"]:
            clauses += sum(len(s.get("clauses", [])) for s in method_body.data_sections(data, pe, hdr))
    ctl += [("11 sites preserved", sites == 11), ("35 EH clauses preserved", clauses == 35)]

    md = ["# NATIVE-340 s89 逐项核对（脚本生成）", "",
          "基线：#450 @ %s（主干 %s）。" % (BASE_HEAD, MAIN_HEAD), "",
          "## 1. 真实表流路径的列宽（%d 列）" % len(layout), "",
          "parser 用 stream=%s、HeapSizes=0x%02X（从流头读）。" % (tables["stream"], tables["heap_sizes"]), "",
          "| 表 | 列 | 宽度 | 行数 | 规则 |", "| --- | --- | ---: | ---: | --- |"]
    for l in layout[:20]:
        md.append("| %s | %s | %d | %d | %s |" % (l["table"], l["column"], l["width"], l["rows"], l["rule"]))
    md.append("| ... | ... | ... | ... | 全表 %d 列见 code/s89-column-widths.csv |" % len(layout))
    md += ["", "## 2. 三类阈值配对", "", "| 空间 | tag 位 | 低 | 宽 | 高 | 宽 |",
           "| --- | ---: | ---: | ---: | ---: | ---: |"]
    for r in pairs:
        md.append("| %s | %d | %d | %d | %d | %d |" % (r["space"], r["tag_bits"], r["low_rows"],
                                                      r["low_width"], r["high_rows"], r["high_width"]))
    md += ["", "## 3. IL 摘要四类差异", "", "| 类别 | 数量 | 样例 |", "| --- | ---: | --- |"]
    for r in drows:
        md.append("| %s | %d | %s |" % (r["category"], r["count"], r["sample"] or "-"))
    md += ["", "167 条摘要带行号（code/s89-il-digests.csv），建字典前先查重复。", "",
           "## 4. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s89-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("heap", hex(tables["heap_sizes"]), "columns", len(layout))
    print("pairs", [(p["space"], p["low_width"], p["high_width"]) for p in pairs])
    print("digest diffs", [(r["category"], r["count"]) for r in drows])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
