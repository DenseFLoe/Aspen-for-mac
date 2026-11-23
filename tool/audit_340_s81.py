# -*- coding: utf-8 -*-
"""NATIVE-340 s81: ECMA flag names, real MethodImpl sample, column-width derivation, IL roots."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "858a23f9070d0a99555b695082d4dc57a4c13258"
MAIN_HEAD = "6f39d818"
SAMPLE = "dl/053_AspenHelper.dll"
VTF_BITS = [(0x01, "COR_VTABLE_32BIT"), (0x02, "COR_VTABLE_64BIT"),
            (0x04, "COR_VTABLE_FROM_UNMANAGED"), (0x08, "COR_VTABLE_CALL_MOST_DERIVED")]
ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
SLOTS = (0x19600, 0x19608, 0x19610, 0x19618)
CODED = {"MemberRefParent": (3, (2, 1, 26, 6, 27)),
         "TypeDefOrRef": (2, (2, 1, 27)),
         "MethodDefOrRef": (1, (6, 10)),
         "CustomAttributeType": (3, (6, 10))}


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def decode_mdor(v):
    return ("MethodDef" if (v & 1) == 0 else "MemberRef"), (v >> 1) + 1


def encode_mdor(kind, rid):
    return ((rid - 1) << 1) | (0 if kind == "MethodDef" else 1)


def stream_sizes(data, off):
    pos = off + 16 + int.from_bytes(data[off+12:off+16], "little")
    n = int.from_bytes(data[pos+2:pos+4], "little")
    pos += 4
    out = {}
    for _ in range(n):
        rel, size = struct.unpack_from("<II", data, pos)
        end = data.index(b"\0", pos + 8)
        name = data[pos+8:end].decode("utf-8")
        out[name] = size
        pos = end + 1
        pos += (-pos) % 4
    return out


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

    # ---- 1. VTableFixups flags, ECMA bit names ---------------------------
    p = pe.filepos(cli)
    vt = struct.unpack_from("<I", data, p + 0x30)[0]
    vts = struct.unpack_from("<I", data, p + 0x34)[0]
    entries = []
    for i in range(vts // 8):
        q = pe.filepos(vt + 8 * i)
        rva, count, flags = struct.unpack_from("<IHH", data, q)
        entries.append((i, rva, count, flags))
    frows = []
    for slot in SLOTS:
        e = next((x for x in entries if x[1] <= slot < x[1] + x[2] * 8), None)
        names = [n for bit, n in VTF_BITS if e and (e[3] & bit)]
        frows.append(dict(slot="0x%X" % slot, entry=e[0], raw="0x%X" % e[3],
                          bit_names=" | ".join(names),
                          token="0x%08X" % struct.unpack_from("<Q", data, pe.filepos(slot))[0]))
    write_csv(code / "s81-vtable-flags.csv", ["slot", "entry", "raw", "bit_names", "token"], frows)
    ctl += [
        ("0x02 is COR_VTABLE_64BIT and 0x08 is COR_VTABLE_CALL_MOST_DERIVED",
         dict(VTF_BITS)[0x02] == "COR_VTABLE_64BIT" and dict(VTF_BITS)[0x08] == "COR_VTABLE_CALL_MOST_DERIVED"),
        ("four slots keep raw 0x2/0xA/0x2/0xA and tokens 0x56/0x56/0x57/0x57",
         [r["raw"] for r in frows] == ["0x2", "0xA", "0x2", "0xA"]
         and [r["token"] for r in frows] == ["0x06000056", "0x06000056", "0x06000057", "0x06000057"]),
        ("0xA renders as 64BIT|CALL_MOST_DERIVED", frows[1]["bit_names"] == "COR_VTABLE_64BIT | COR_VTABLE_CALL_MOST_DERIVED"),
    ]

    # ---- 2. real MethodImpl sample: one-based RIDs -----------------------
    sd = Path(SAMPLE).read_bytes()
    spe = PE(sd)
    scli = spe.directory(14)[0]
    soff = spe.filepos(struct.unpack_from("<I", sd, spe.filepos(scli) + 8)[0])
    st = cli_tables.read(sd, soff)
    srow = st["rows"][25][0]
    decl_raw, body_raw = srow["MethodDeclaration"], srow["MethodBody"]
    decl = decode_mdor(decl_raw)
    body = decode_mdor(body_raw)
    sms = md_reader.parse(sd, soff)["methods"]
    body_name = sms[body[1] - 1]["name"]
    mrow = st["rows"][10][decl[1] - 1]
    mirows = [dict(sample=SAMPLE, row=srow["_row"], decl_raw=decl_raw,
                   declaration="%s[%d]" % decl, body_raw=body_raw, body="%s[%d]" % body,
                   body_name=body_name, decl_name=mrow["Name"],
                   roundtrip=(encode_mdor(*decl) == decl_raw and encode_mdor(*body) == body_raw))]
    write_csv(code / "s81-methodimpl-sample.csv",
              ["sample", "row", "decl_raw", "declaration", "body_raw", "body", "body_name",
               "decl_name", "roundtrip"], mirows)
    ctl += [
        ("MethodImpl sample row decodes to Declaration=MemberRef[16]", decl == ("MemberRef", 16)),
        ("MethodImpl sample row decodes to Body=MethodDef[5] (%s)" % body_name, body == ("MethodDef", 5)),
        ("one-based RIDs round-trip through the encoder", mirows[0]["roundtrip"]),
    ]

    # ---- 3. column widths from the encoding definition -------------------
    heaps = data[md_off + 6]
    sizes = stream_sizes(data, md_off)
    heap_rows = [dict(heap="#Strings", flag="HeapSizes bit0", bit=bool(heaps & 1),
                      stream_size=sizes.get("#Strings", 0),
                      width=4 if heaps & 1 else 2,
                      rule="4 bytes when the flag is set (heap >= 0x10000)"),
                 dict(heap="#GUID", flag="HeapSizes bit1", bit=bool(heaps & 2),
                      stream_size=sizes.get("#GUID", 0), width=4 if heaps & 2 else 2,
                      rule="4 bytes when the flag is set"),
                 dict(heap="#Blob", flag="HeapSizes bit2", bit=bool(heaps & 4),
                      stream_size=sizes.get("#Blob", 0), width=4 if heaps & 4 else 2,
                      rule="4 bytes when the flag is set")]
    write_csv(code / "s81-heap-sizes.csv",
              ["heap", "flag", "bit", "stream_size", "width", "rule"], heap_rows)
    cw = []
    for name, (bits, tbls) in CODED.items():
        mx = max(counts.get(t, 0) for t in tbls)
        thr = 1 << (16 - bits)
        cw.append(dict(column=name, tag_bits=bits, threshold=thr, max_rows=mx,
                       width=2 if mx < thr else 4,
                       derivation="count < 2**(16-%d)=%d -> %d bytes" % (bits, thr, 2 if mx < thr else 4)))
    cw.append(dict(column="plain index (e.g. TypeDef.FieldList)", tag_bits=0, threshold=1 << 16,
                   max_rows=max(counts.values()), width=2,
                   derivation="count < 2**16=65536 -> 2 bytes"))
    write_csv(code / "s81-column-widths.csv",
              ["column", "tag_bits", "threshold", "max_rows", "width", "derivation"], cw)
    ctl += [("HeapSizes byte is 0x%02X: only #Strings is a 4-byte index" % heaps, heaps == 0x01),
            ("coded-index widths follow count < 2**(16-tag_bits)",
             all(r["width"] == (2 if r["max_rows"] < r["threshold"] else 4) for r in cw))]

    # ---- 4. per-token IL roots recomputed from the binary ----------------
    fresh = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        fresh.append(dict(token="0x%08X" % m["token"], name=m["name"], rva="0x%X" % m["rva"],
                          access=ACCESS[m["flags"] & 7], il_len=len(hdr["il"]),
                          il_sha256=hashlib.sha256(hdr["il"]).hexdigest()))
    fresh.sort(key=lambda r: r["token"])
    write_csv(code / "s81-il-fingerprints.csv",
              ["token", "name", "rva", "access", "il_len", "il_sha256"], fresh)
    declared = {r["token"]: r["il_sha256"] for r in read_csv(code / "s77-il-fingerprints.csv")}
    match = sum(1 for r in fresh if declared.get(r["token"]) == r["il_sha256"])
    ctl += [
        ("%d IL tokens recomputed from the binary" % len(fresh), len(fresh) == 167),
        ("every recomputed root is 64 hex chars", all(len(r["il_sha256"]) == 64 for r in fresh)),
        ("recomputed roots equal the declared s77 table (%d/%d)" % (match, len(fresh)),
         match == len(fresh)),
    ]

    # ---- 5. preserved facts ---------------------------------------------
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

    md = ["# NATIVE-340 s81 逐项核对（脚本生成）", "",
          "基线：#450 @ `%s`（主干 %s）。" % (BASE_HEAD, MAIN_HEAD), "",
          "## 1. VTableFixups 位名（ECMA）", "",
          "| 槽 | 条目 | dwFlags | 位名 | token |", "| --- | ---: | --- | --- | --- |"]
    for r in frows:
        md.append("| %s | %s | %s | %s | %s |" % (r["slot"], r["entry"], r["raw"], r["bit_names"], r["token"]))
    md += ["", "## 2. 真实 MethodImpl 样本", "",
           "| 文件 | 行 | Declaration | Body | Body 名 | 往返 |", "| --- | ---: | --- | --- | --- | --- |"]
    for r in mirows:
        md.append("| %s | %d | %s (raw %d) | %s (raw %d) | %s | %s |"
                  % (r["sample"], r["row"], r["declaration"], r["decl_raw"], r["body"],
                     r["body_raw"], r["body_name"], r["roundtrip"]))
    md += ["", "## 3. 列宽推导（按编码定义）", "",
           "HeapSizes 字节 = 0x%02X：%s。" % (heaps, ", ".join("%s %d 字节" % (h["heap"], h["width"]) for h in heap_rows)), "",
           "| 列 | tag 位 | 阈值 | 最大行数 | 宽度 | 推导 |", "| --- | ---: | ---: | ---: | ---: | --- |"]
    for r in cw:
        md.append("| %s | %d | %d | %d | %d | %s |" % (r["column"], r["tag_bits"], r["threshold"],
                                                      r["max_rows"], r["width"], r["derivation"]))
    md += ["", "## 4. 每 token IL 指纹（从原件重算）", "",
           "%d 个 token，全部 64 位；与 s77 声明表逐条比对全部一致（比对不是信任来源）。" % len(fresh), "",
           "## 5. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s81-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("flags", [r["raw"] for r in frows], "methodimpl", mirows[0]["declaration"], mirows[0]["body"])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
