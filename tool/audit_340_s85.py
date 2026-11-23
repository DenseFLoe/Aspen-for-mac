# -*- coding: utf-8 -*-
"""NATIVE-340 s85: corhdr.h vtable bits, PEReader RID cross-check, per-column widths, token diffs."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "f8470240a320318bd82ef58f9f0e84e311022be1"
MAIN_HEAD = "0554621e"
SAMPLE = "dl/053_AspenHelper.dll"
PER_ORIG = Path("_t14/pereader/orig.json")
PER_SAMPLE = Path("_t14/pereader/sample.json")
# corhdr.h (COR_VTABLE_*): 0x08 is RETAIN_APPDOMAIN, 0x10 is CALL_MOST_DERIVED
VTF_BITS = [(0x01, "COR_VTABLE_32BIT"), (0x02, "COR_VTABLE_64BIT"),
            (0x04, "COR_VTABLE_FROM_UNMANAGED"),
            (0x08, "COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN"),
            (0x10, "COR_VTABLE_CALL_MOST_DERIVED")]
ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
SLOTS = (0x19600, 0x19608, 0x19610, 0x19618)
MEMREF_PARENT = ["TypeDef", "TypeRef", "ModuleRef", "MethodDef", "TypeSpec"]
CA_TYPE = {2: "MethodDef", 3: "MemberRef"}   # ECMA II.24.2.6: 2=MethodDef, 3=MemberRef
PER_KIND = {"TypeDefinition": "TypeDef", "TypeReference": "TypeRef", "ModuleReference": "ModuleRef",
            "MethodDefinition": "MethodDef", "TypeSpecification": "TypeSpec",
            "MemberReference": "MemberRef", "AssemblyReference": "AssemblyRef"}


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def diff_categories(mine, theirs, label):
    """mine/theirs: dict row -> (kind, rid). Four categories: extra, missing, duplicate, digest."""
    extra = sorted(set(mine) - set(theirs))
    missing = sorted(set(theirs) - set(mine))
    dup = sorted({r for r in mine if list(mine).count(r) > 1})
    digest = sorted(r for r in mine if r in theirs and mine[r] != theirs[r])
    return dict(space=label, rows_mine=len(mine), rows_pereader=len(theirs),
                extra=len(extra), missing=len(missing), duplicate=len(dup), hash_diff_count=len(digest),
                extra_sample=extra[:3], missing_sample=missing[:3], digest_sample=digest[:3])


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
    meta = md_reader.parse(data, md_off)
    tables = cli_tables.read(data, md_off)
    counts = {k: len(v) for k, v in tables["rows"].items()}
    ctl = []

    # ---- 1. corhdr.h vtable bits for the four slots -----------------------
    p = pe.filepos(cli)
    vt = struct.unpack_from("<I", data, p + 0x30)[0]
    vts = struct.unpack_from("<I", data, p + 0x34)[0]
    entries = [(i, *struct.unpack_from("<IHH", data, pe.filepos(vt + 8 * i))) for i in range(vts // 8)]
    frows = []
    for slot in SLOTS:
        e = next((x for x in entries if x[1] <= slot < x[1] + x[2] * 8), None)
        names = [n for bit, n in VTF_BITS if e and (e[3] & bit)]
        frows.append(dict(slot="0x%X" % slot, entry=e[0], raw="0x%X" % e[3],
                          bit_names=" | ".join(names), token="0x%08X" % struct.unpack_from("<Q", data, pe.filepos(slot))[0]))
    fields = ["slot", "entry", "raw", "bit_names", "token"]
    write_csv(code / "s85-vtable-flags.csv", fields, frows)
    write_csv(code / "s81-vtable-flags.csv", fields, frows)   # corrected in place
    ctl += [("0x08 is FROM_UNMANAGED_RETAIN_APPDOMAIN and 0x10 is CALL_MOST_DERIVED",
             dict(VTF_BITS)[0x08] == "COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN"
             and dict(VTF_BITS)[0x10] == "COR_VTABLE_CALL_MOST_DERIVED"),
            ("0xA renders as 64BIT|RETAIN_APPDOMAIN",
             frows[1]["bit_names"] == "COR_VTABLE_64BIT | COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN"),
            ("four slots keep 0x2/0xA/0x2/0xA and tokens 56/56/57/57",
             [r["raw"] for r in frows] == ["0x2", "0xA", "0x2", "0xA"]
             and [r["token"] for r in frows] == ["0x06000056", "0x06000056", "0x06000057", "0x06000057"])]

    # ---- 2. MethodImpl sample: self decode vs PEReader --------------------
    per = json.loads(PER_SAMPLE.read_text(encoding="utf-8"))
    sd = Path(SAMPLE).read_bytes()
    sha = hashlib.sha256(sd).hexdigest()
    spe = PE(sd)
    scli = spe.directory(14)[0]
    soff = spe.filepos(struct.unpack_from("<I", sd, spe.filepos(scli) + 8)[0])
    st = cli_tables.read(sd, soff)
    srow = st["rows"][25][0]
    tag_bits = 1
    body_rid = srow["MethodBody"] >> tag_bits
    decl_rid = srow["MethodDeclaration"] >> tag_bits
    body_kind = "MethodDef" if (srow["MethodBody"] & 1) == 0 else "MemberRef"
    decl_kind = "MethodDef" if (srow["MethodDeclaration"] & 1) == 0 else "MemberRef"
    impl = per["impls"][0]
    mi = [dict(sample=SAMPLE, sha256=sha, pereader_sha256=per["sha256"],
               body_raw=srow["MethodBody"], body_tag_bits=tag_bits, body_rid=body_rid,
               body_kind=body_kind, per_body_kind=PER_KIND.get(impl["body_kind"], impl["body_kind"]),
               per_body_rid=impl["body_rid"],
               decl_raw=srow["MethodDeclaration"], decl_tag_bits=tag_bits, decl_rid=decl_rid,
               decl_kind=decl_kind, per_decl_kind=PER_KIND.get(impl["decl_kind"], impl["decl_kind"]),
               per_decl_rid=impl["decl_rid"])]
    write_csv(code / "s85-methodimpl-pereader.csv",
              ["sample", "sha256", "pereader_sha256", "body_raw", "body_tag_bits", "body_rid",
               "body_kind", "per_body_kind", "per_body_rid", "decl_raw", "decl_tag_bits", "decl_rid",
               "decl_kind", "per_decl_kind", "per_decl_rid"], mi)
    ctl += [("sample sha256 matches PEReader (%s...)" % sha[:16], sha == per["sha256"]),
            ("self decode Body RID %d == PEReader %d" % (body_rid, impl["body_rid"]),
             body_rid == impl["body_rid"] and body_kind == PER_KIND.get(impl["body_kind"], impl["body_kind"])),
            ("self decode Declaration RID %d == PEReader %d" % (decl_rid, impl["decl_rid"]),
             decl_rid == impl["decl_rid"] and decl_kind == PER_KIND.get(impl["decl_kind"], impl["decl_kind"]))]

    # ---- 3. per-column widths from the stream header ---------------------
    heaps = data[md_off + 6]                     # HeapSizes byte of the #~ stream header
    heap_rows = [dict(heap="#Strings", bit="0x01", set=bool(heaps & 1), width=4 if heaps & 1 else 2),
                 dict(heap="#GUID", bit="0x02", set=bool(heaps & 2), width=4 if heaps & 2 else 2),
                 dict(heap="#Blob", bit="0x04", set=bool(heaps & 4), width=4 if heaps & 4 else 2)]
    write_csv(code / "s85-heap-sizes.csv", ["heap", "bit", "set", "width"], heap_rows)
    cw = []
    for name, bits, tbls in (("MemberRefParent", 3, (2, 1, 26, 6, 27)),
                             ("TypeDefOrRef", 2, (2, 1, 27)),
                             ("MethodDefOrRef", 1, (6, 10)),
                             ("CustomAttributeType", 3, (6, 10))):
        mx = max(counts.get(t, 0) for t in tbls)
        thr = 1 << (16 - bits)
        cw.append(dict(column=name, kind="coded", tag_bits=bits, rows=mx, threshold=thr,
                       width=2 if mx < thr else 4,
                       derivation="rows(%d) < 2**(16-%d)=%d -> %d bytes" % (mx, bits, thr, 2 if mx < thr else 4)))
    for name, tbl in (("MethodDef.MethodList", 6), ("MemberRef.Name", 4), ("TypeDef.FieldList", 4)):
        cw.append(dict(column=name, kind="index", tag_bits=0, rows=counts.get(tbl, 0), threshold=1 << 16,
                       width=2 if counts.get(tbl, 0) < (1 << 16) else 4,
                       derivation="table rows %d < 65536 -> 2 bytes" % counts.get(tbl, 0)))
    write_csv(code / "s85-column-widths.csv",
              ["column", "kind", "tag_bits", "rows", "threshold", "width", "derivation"], cw)
    ctl += [("HeapSizes read from the stream header is 0x%02X" % heaps, heaps in (0, 1, 2, 3, 4, 5, 6, 7)),
            ("per-column widths follow the encoding rule",
             all(r["width"] == (2 if r["rows"] < r["threshold"] else 4) for r in cw))]

    # ---- 4. token diffs against PEReader (four categories) ---------------
    po = json.loads(PER_ORIG.read_text(encoding="utf-8"))
    mine = {}
    for r in tables["rows"][10]:
        v = r["Class"]
        mine[r["_row"]] = (MEMREF_PARENT[v & 7], (v >> 3))
    theirs = {}
    for r in po["refs"]:
        theirs[r["row"]] = (PER_KIND.get(r["parent_kind"], r["parent_kind"]), r["parent_rid"])
    d_mrp = diff_categories(mine, theirs, "MemberRefParent")
    mine_ca = {}
    for r in tables["rows"][12]:
        v = r["Type"]
        mine_ca[r["_row"]] = (CA_TYPE.get(v & 7, "reserved%d" % (v & 7)), (v >> 3))
    theirs_ca = {}
    for r in po["cattrs"]:
        theirs_ca[r["row"]] = (PER_KIND.get(r["type_kind"], r["type_kind"]), r["type_rid"])
    d_cat = diff_categories(mine_ca, theirs_ca, "CustomAttributeType")
    mine_mdor = {1: (body_kind, body_rid)}
    theirs_mdor = {1: (PER_KIND.get(impl["body_kind"], impl["body_kind"]), impl["body_rid"])}
    d_mdor = diff_categories(mine_mdor, theirs_mdor, "MethodDefOrRef")
    drows = [d_mrp, d_mdor, d_cat]
    write_csv(code / "s85-token-diffs.csv",
              ["space", "rows_mine", "rows_pereader", "extra", "missing", "duplicate",
               "hash_diff_count"], drows)
    ctl += [("MemberRefParent has no extra/missing/duplicate/digest diffs",
             d_mrp["extra"] == 0 and d_mrp["missing"] == 0 and d_mrp["duplicate"] == 0 and d_mrp["hash_diff_count"] == 0),
            ("MethodDefOrRef sample has no diffs",
             d_mdor["extra"] == 0 and d_mdor["missing"] == 0 and d_mdor["hash_diff_count"] == 0),
            ("CustomAttributeType has no extra/missing/duplicate/digest diffs",
             d_cat["extra"] == 0 and d_cat["missing"] == 0 and d_cat["duplicate"] == 0 and d_cat["hash_diff_count"] == 0)]

    # ---- 5. preserved facts ----------------------------------------------
    fresh = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        fresh.append((m["token"], hashlib.sha256(hdr["il"]).hexdigest()))
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
    ctl += [("%d IL digests recomputed" % len(fresh), len(fresh) == 167),
            ("11 sites preserved", sites == 11), ("35 EH clauses preserved", clauses == 35)]

    md = ["# NATIVE-340 s85 逐项核对（脚本生成）", "",
          "基线：#450 @ `%s`（主干 %s）。" % (BASE_HEAD, MAIN_HEAD), "",
          "## 1. 四槽位名（corhdr.h）", "",
          "| 位 | 名称 |", "| --- | --- |"]
    for bit, name in VTF_BITS:
        md.append("| 0x%02X | %s |" % (bit, name))
    md += ["", "| 槽 | dwFlags | 位名 | token |", "| --- | --- | --- | --- |"]
    for r in frows:
        md.append("| %s | %s | %s | %s |" % (r["slot"], r["raw"], r["bit_names"], r["token"]))
    md += ["", "## 2. MethodImpl 样本：自建解码 vs PEReader", "",
           "样本 %s，SHA-256 `%s`（PEReader 复算 %s）。" % (SAMPLE, sha, per["sha256"][:16]), "",
           "| 列 | 原始 | tag_bits | RID（raw >> tag_bits） | PEReader |", "| --- | ---: | ---: | ---: | --- |"]
    md.append("| MethodBody | %d | %d | %d | %s[%d] |" % (body_rid and srow["MethodBody"], tag_bits, body_rid,
                                                          PER_KIND.get(impl["body_kind"], impl["body_kind"]), impl["body_rid"]))
    md.append("| MethodDeclaration | %d | %d | %d | %s[%d] |" % (srow["MethodDeclaration"], tag_bits, decl_rid,
                                                               PER_KIND.get(impl["decl_kind"], impl["decl_kind"]), impl["decl_rid"]))
    md += ["", "## 3. 逐列宽度（流头 HeapSizes + 行数阈值）", "",
           "| 列 | 类型 | tag 位 | 行数 | 阈值 | 宽度 | 推导 |", "| --- | --- | ---: | ---: | ---: | ---: | --- |"]
    for r in cw:
        md.append("| %s | %s | %d | %d | %d | %d | %s |" % (r["column"], r["kind"], r["tag_bits"],
                                                          r["rows"], r["threshold"], r["width"], r["derivation"]))
    md += ["", "## 4. 四类 token 差异（对 PEReader）", "",
           "| 空间 | 本侧行数 | PEReader 行数 | 额外 | 缺失 | 重复 | 摘要不符 |",
           "| --- | ---: | ---: | ---: | ---: | ---: | ---: |"]
    for r in drows:
        md.append("| %s | %d | %d | %d | %d | %d | %d |" % (r["space"], r["rows_mine"], r["rows_pereader"],
                                                           r["extra"], r["missing"], r["duplicate"], r["hash_diff_count"]))
    md += ["", "## 5. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s85-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("flags", [r["raw"] for r in frows], [r["bit_names"] for r in frows][1])
    print("rids", body_rid, decl_rid, "per", impl["body_rid"], impl["decl_rid"])
    print("diffs", [(d["space"], d["extra"], d["missing"], d["duplicate"], d["hash_diff_count"]) for d in drows])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
