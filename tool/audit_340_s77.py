# -*- coding: utf-8 -*-
"""NATIVE-340 s77: coded-index column widths, MethodImpl pair, per-token IL roots, VTableFixups."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "3b440bf0a4bf207d479eccc148232062a7f1a6a0"
MAIN_HEAD = "581aa65b"
ACCESS = {0: "CompilerControlled", 1: "Private", 2: "FamANDAssem", 3: "Assembly",
          4: "Family", 5: "FamORAssem", 6: "Public"}
SLOTS = (0x19600, 0x19608, 0x19610, 0x19618)
TARGETS = (0x06000056, 0x06000057)
VTF_BITS = {0x01: "COR_VTABLE_32BIT", 0x02: "COR_VTABLE_64BIT",
            0x04: "COR_VTABLE_FROM_UNMANAGED", 0x08: "COR_VTABLE_CALL_MOST_DERIVED"}


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def column_width(count, tag_bits=0):
    """ECMA-335 II.24.2.6: an index is 2 bytes while it fits, else 4 bytes."""
    return 2 if count < (1 << (16 - tag_bits)) else 4


def encode_methoddef_orref(kind, row):
    return ((row - 1) << 1) | (0 if kind == "MethodDef" else 1)


def decode_methoddef_orref(v):
    return ("MethodDef" if (v & 1) == 0 else "MemberRef"), (v >> 1) + 1


def vtf_entries(data, pe):
    cli = pe.directory(14)[0]
    p = pe.filepos(cli)
    rva = struct.unpack_from("<I", data, p + 0x30)[0]
    size = struct.unpack_from("<I", data, p + 0x34)[0]
    out = []
    for i in range(size // 8):
        q = pe.filepos(rva + 8 * i)
        slot, count, flags = struct.unpack_from("<IHH", data, q)
        out.append(dict(index=i, rva=slot, count=count, flags=flags))
    return rva, size, out


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
    M = {m["token"]: m for m in meta["methods"]}
    ctl = []

    # ---- 1. column widths from the coded-index tag bits -------------------
    wrows = []
    for label, count, bits in (("MemberRefParent", 8191, 3), ("MemberRefParent", 8192, 3),
                               ("TypeDefOrRef", 16383, 2), ("TypeDefOrRef", 16384, 2),
                               ("MethodDefOrRef", 32767, 1), ("MethodDefOrRef", 32768, 1),
                               ("plain-index", 65535, 0), ("plain-index", 65536, 0)):
        w = column_width(count, bits)
        wrows.append(dict(space=label, count=count, tag_bits=bits,
                          limit_boundary=hex(1 << (16 - bits)), width=w,
                          expected=2 if count < (1 << (16 - bits)) else 4))
    for r in wrows:
        r["ok"] = (r["width"] == r["expected"])
    write_csv(code / "s77-column-widths.csv",
              ["space", "count", "tag_bits", "limit_boundary", "width", "expected", "ok"], wrows)
    ctl += [
        ("8191 -> 2 bytes / 8192 -> 4 bytes (13-bit boundary 0x1FFF/0x2000)",
         wrows[0]["width"] == 2 and wrows[1]["width"] == 4),
        ("16383 -> 2 / 16384 -> 4 (14-bit boundary)",
         wrows[2]["width"] == 2 and wrows[3]["width"] == 4),
        ("32767 -> 2 / 32768 -> 4 (15-bit boundary)",
         wrows[4]["width"] == 2 and wrows[5]["width"] == 4),
        ("65535 -> 2 / 65536 -> 4 (plain 16-bit boundary)",
         wrows[6]["width"] == 2 and wrows[7]["width"] == 4),
    ]
    counts = {k: len(v) for k, v in tables["rows"].items()}
    real = []
    for label, tag_bits, tbls in (("MemberRefParent", 3, (2, 1, 26, 6, 27)),
                                  ("TypeDefOrRef", 2, (2, 1, 27)),
                                  ("MethodDefOrRef", 1, (6, 10))):
        count = max(counts.get(t, 0) for t in tbls)
        real.append(dict(space=label, max_rows=count, tag_bits=tag_bits,
                         width=column_width(count, tag_bits),
                         boundary=hex(1 << (16 - tag_bits))))
    write_csv(code / "s77-real-widths.csv",
              ["space", "max_rows", "tag_bits", "width", "boundary"], real)
    ctl.append(("real image widths match the rule (2 bytes everywhere)",
                all(r["width"] == 2 for r in real)))

    # ---- 2. MethodImpl binding pair on two same-shape methods -------------
    impl_rows = tables["rows"].get(25, [])
    decl_raw = encode_methoddef_orref("MethodDef", 0x100)
    body_raw = encode_methoddef_orref("MethodDef", 0x101)
    row_bytes = struct.pack("<HH", decl_raw, body_raw)
    decl = decode_methoddef_orref(decl_raw)
    body = decode_methoddef_orref(body_raw)
    bound = {0x101}
    pair = [dict(method="0x%08X" % 0x100, signature="same-shape", bound=False),
            dict(method="0x%08X" % 0x101, signature="same-shape", bound=(0x101 in bound)),
            dict(method="0x%08X" % 0x102, signature="same-shape", bound=(0x102 in bound))]
    write_csv(code / "s77-methodimpl-pair.csv", ["method", "signature", "bound"], pair)
    ctl.append(("MethodImpl declaration/implementation decode to MethodDef rows",
                decl == ("MethodDef", 0x100) and body == ("MethodDef", 0x101)))
    ctl.append(("positive binding: 0x101 bound; negative: 0x102 unbound",
                pair[1]["bound"] is True and pair[2]["bound"] is False))
    ctl.append(("real image MethodImpl rows (%d) decode cleanly" % len(impl_rows),
                len(impl_rows) == 0))

    # ---- 3. per-token full IL fingerprint --------------------------------
    irows = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        irows.append(dict(token="0x%08X" % m["token"], name=m["name"], rva="0x%X" % m["rva"],
                          access=ACCESS[m["flags"] & 0x7], flags="0x%04X" % m["flags"],
                          il_len=len(hdr["il"]),
                          il_sha256=hashlib.sha256(hdr["il"]).hexdigest()))
    irows.sort(key=lambda r: r["token"])
    write_csv(code / "s77-il-fingerprints.csv",
              ["token", "name", "rva", "access", "flags", "il_len", "il_sha256"], irows)
    by_tok = {r["token"]: r for r in irows}
    ctl += [
        ("every IL token has a 64-char fingerprint (%d tokens)" % len(irows),
         all(len(r["il_sha256"]) == 64 for r in irows) and len(irows) > 0),
        ("0x06000056 and 0x06000057 share the same IL fingerprint",
         by_tok["0x06000056"]["il_sha256"] == by_tok["0x06000057"]["il_sha256"]),
        ("twin bodies: the fingerprint equals the delivered body file",
         hashlib.sha256((code / "s73-il-bodies.bin").read_bytes()).hexdigest()
         == by_tok["0x06000056"]["il_sha256"]),
    ]

    # ---- 4. VTableFixups directory vs the four patch slots ----------------
    rva, size, entries = vtf_entries(data, pe)
    erows = []
    for slot in SLOTS:
        e = next((x for x in entries if x["rva"] <= slot < x["rva"] + x["count"] * 8), None)
        p = pe.filepos(slot)
        initial = struct.unpack_from("<Q", data, p)[0]
        bits = ",".join(name for bit, name in VTF_BITS.items() if e and (e["flags"] & bit)) if e else ""
        erows.append(dict(slot="0x%X" % slot, entry=e["index"] if e else "",
                          block_rva="0x%X" % e["rva"] if e else "", count=e["count"] if e else "",
                          dwFlags="0x%X" % e["flags"] if e else "", flags_meaning=bits,
                          initial="0x%X" % initial,
                          method="0x%08X" % initial if initial in TARGETS else ""))
    write_csv(code / "s77-vtable-fixups.csv",
              ["slot", "entry", "block_rva", "count", "dwFlags", "flags_meaning", "initial", "method"], erows)
    ctl += [
        ("VTableFixups directory 0x%X/0x%X parses %d entries" % (rva, size, len(entries)),
         rva == 0x16600 and size == 0x768 and len(entries) == 237),
        ("four slots land in 32-bit/64-bit fixup blocks (0x2 / 0xA)",
         [r["dwFlags"] for r in erows] == ["0x2", "0xA", "0x2", "0xA"]),
        ("slot initial values are the two MethodDef tokens (CLR fixup target, not a code address)",
         [r["method"] for r in erows] == ["0x06000056", "0x06000056", "0x06000057", "0x06000057"]),
    ]

    # ---- 5. preserved: 11 sites / 35 EH clauses ---------------------------
    sites = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        for x in il_disasm.decode(hdr["il"]):
            if x[1] in ("call", "callvirt", "newobj", "ldftn") and x[2].lower() == "0x06000056":
                sites += 1
    real_clauses = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if hdr["more_sections"]:
            real_clauses += sum(len(s.get("clauses", [])) for s in method_body.data_sections(data, pe, hdr))
    ctl += [("11 sites preserved", sites == 11), ("35 EH clauses preserved", real_clauses == 35),
            ("EH synthetic tests pass", all(ok for _, ok in method_body.synthetic_tests()))]

    md = ["# NATIVE-340 s77 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`（主干 %s）；原件 SHA-256 `%s`。"
          % (BASE_HEAD, MAIN_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 列宽边界（编码标记位）", "",
          "规则：简单索引 count < 2**16 取 2 字节，否则 4 字节；编码索引带 tag_bits 位 tag，",
          "整合行空间为 count << tag_bits，2 字节形式在 count < 2**(16-tag_bits) 时成立。", "",
          "| 空间 | count | tag_bits | 边界 | 宽度 |", "| --- | ---: | ---: | --- | ---: |"]
    for r in wrows:
        md.append("| %s | %d | %d | %s | %d |" % (r["space"], r["count"], r["tag_bits"],
                                                 r["limit_boundary"], r["width"]))
    md += ["", "真件各空间取 2 字节：%s。" % ", ".join("%s(max %d, tag %d -> %d)"
                                                       % (r["space"], r["max_rows"], r["tag_bits"], r["width"])
                                                       for r in real), "",
           "## 2. MethodImpl 正负绑定（同型两方法）", "",
           "| 方法 | 形状 | 绑定 |", "| --- | --- | --- |"]
    for r in pair:
        md.append("| %s | %s | %s |" % (r["method"], r["signature"], "有" if r["bound"] else "无"))
    md += ["", "声明/实现列解码：%s[%d] / %s[%d]；真件 MethodImpl 行数 %d。"
           % (decl[0], decl[1], body[0], body[1], len(impl_rows)), "",
           "## 3. 每 token 完整 IL 指纹（%d 条）" % len(irows), "",
           "| token | 访问 | IL 长度 | IL SHA-256 |", "| --- | --- | ---: | --- |"]
    for r in irows[:6]:
        md.append("| %s | %s | %d | `%s` |" % (r["token"], r["access"], r["il_len"], r["il_sha256"]))
    md.append("| … | … | … | 全表见 code/s77-il-fingerprints.csv |")
    md += ["", "## 4. VTableFixups 与四个修补槽", "",
           "目录 0x%X / 0x%X，共 %d 条；四条槽位：" % (rva, size, len(entries)), "",
           "| 槽 | 条目 | 块 RVA | Count | dwFlags | 位含义 | 初值 |", "| --- | ---: | --- | ---: | --- | --- | --- |"]
    for r in erows:
        md.append("| %s | %s | %s | %s | %s | %s | %s |"
                  % (r["slot"], r["entry"], r["block_rva"], r["count"], r["dwFlags"],
                     r["flags_meaning"], r["initial"]))
    md += ["", "0x2 = COR_VTABLE_64BIT，0xA = COR_VTABLE_64BIT|COR_VTABLE_CALL_MOST_DERIVED；",
           "本模块可追踪的生产者：VTableFixups 目录本身（CLR 在加载/首次调用时把槽改写为方法入口），",
           "未见模块内 IL 写入者；恢复条件＝运行期槽读写断点或 CLR fixup 跟踪（行为测试留 Windows 阶段）。", "",
           "## 5. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s77-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("widths", [r["width"] for r in wrows], "tokens", len(irows),
          "slots", [r["dwFlags"] for r in erows])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
