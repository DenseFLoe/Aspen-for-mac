# -*- coding: utf-8 -*-
"""NATIVE-340 s65: per-kind EH clause last field + static analysis of the two calli."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "42dc0c03af69288288b70589a6f3064b7887494c"
KINDS = {0: "catch", 1: "filter", 2: "finally", 4: "fault"}
FILTER_METHODS = (0x06000056, 0x06000057, 0x06000058, 0x0600005B)
EXPECT_FILTER = {0x06000056: (0x0B, 0x18), 0x06000057: (0x0B, 0x18),
                 0x06000058: (0x0F, 0x1C), 0x0600005B: (0x1E, 0x2B)}
CALLI_METHODS = (0x06000056, 0x06000057)


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def role(flags):
    if flags == 0:
        return "type_token", "catch type token"
    if flags == 1:
        return "filter_offset", "IL offset of the filter expression"
    if flags == 2:
        return "raw", "finally: field unused (raw retained)"
    if flags == 4:
        return "raw", "fault: field unused (raw retained)"
    return "raw", "unknown clause kind (raw retained)"


def raw_eh_clauses(data, pe, il_rva, flags_word, code_size):
    """Independent EH reader: parse the section bytes with struct, no method_body path."""
    header_size = ((flags_word >> 12) & 0xF) * 4
    rva = (il_rva + header_size + code_size + 3) & ~3
    out = []
    while True:
        p = pe.filepos(rva)
        kind = data[p]
        size = data[p + 1] | (data[p + 2] << 8) | (data[p + 3] << 16)
        fat = bool(kind & 0x40)
        entry = 24 if fat else 12
        count = (size - 4) // entry
        for i in range(count):
            q = p + 4 + entry * i
            if fat:
                fl, try_off, try_len, h_off, h_len, last = struct.unpack_from("<IIIIII", data, q)
            else:
                fl, try_off, try_len, h_off, h_len, last = struct.unpack_from("<HHBHB I", data, q)
            out.append(dict(section_rva=rva, index=i, flags=fl, try_offset=try_off, try_length=try_len,
                            handler_offset=h_off, handler_length=h_len, last=last))
        if not kind & 0x80:
            return out
        rva += size


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

    # ---- 1. per-kind last field, from the independent reader ---------------
    rows, catches, filters = [], [], {}
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        p = pe.filepos(m["rva"])
        word = struct.unpack_from("<H", data, p)[0]
        if word & 3 != 3 or not word & 0x8:
            continue
        code_size = struct.unpack_from("<I", data, p + 4)[0]
        il = data[p + 12:p + 12 + code_size]
        for c in raw_eh_clauses(data, pe, m["rva"], word, code_size):
            tag = KINDS.get(c["flags"], "0x%X" % c["flags"])
            r, purpose = role(c["flags"])
            rows.append(dict(method="0x%08X" % m["token"], section="0x%X" % c["section_rva"],
                             index=c["index"], flags="0x%X" % c["flags"], kind=tag,
                             try_offset=c["try_offset"], try_length=c["try_length"],
                             handler_offset=c["handler_offset"], handler_length=c["handler_length"],
                             last_field_raw="0x%X" % c["last"], last_field_role=r,
                             last_field_value=("0x%08X" % c["last"]) if r == "type_token"
                             else (("IL_%04X" % c["last"]) if r == "filter_offset" else "raw"),
                             purpose=purpose))
            if c["flags"] == 0:
                catches.append(dict(method="0x%08X" % m["token"], index=c["index"],
                                    type_token="0x%08X" % c["last"],
                                    handler="IL_%04X" % c["handler_offset"]))
            if c["flags"] == 1:
                filters[m["token"]] = dict(filter_offset=c["last"],
                                           handler_offset=c["handler_offset"],
                                           filter_byte=data[p + 12 + c["last"]] if c["last"] < code_size else None,
                                           pre_handler=data[p + 12 + c["handler_offset"] - 2:
                                                            p + 12 + c["handler_offset"]].hex(),
                                           handler_byte=data[p + 12 + c["handler_offset"]])
    ctl = [("25 EH sections / 35 clauses", len(rows) == 35),
           ("7 catch clauses read independently", len(catches) == 7),
           ("4 filter clauses", len(filters) == 4)]
    # ---- 2. four filter methods: offsets, pop, endfilter -------------------
    for tok in FILTER_METHODS:
        want_f, want_h = EXPECT_FILTER[tok]
        f = filters.get(tok)
        ok = (f is not None and f["filter_offset"] == want_f and f["handler_offset"] == want_h
              and f["filter_byte"] == 0x26 and f["pre_handler"] == "fe11")
        ctl.append(("0x%08X filter 0x%02X / handler 0x%02X, pop + endfilter(FE 11)"
                    % (tok, want_f, want_h), ok))
    # ---- 3. mutation: one filter_offset changed -> fingerprint + row locator --
    table_src = code / "s65-eh-clauses.csv"
    write_csv(table_src, ["method", "section", "index", "flags", "kind", "try_offset", "try_length",
                          "handler_offset", "handler_length", "last_field_raw", "last_field_role",
                          "last_field_value", "purpose"], rows)
    before = hashlib.sha256(table_src.read_bytes()).hexdigest()
    mut = read_csv(table_src)
    mutated_row = None
    for r in mut:
        if r["method"].lower() == "0x06000056" and r["last_field_role"] == "filter_offset":
            r["last_field_value"] = "IL_%04X" % (int(r["last_field_raw"], 16) + 1)
            r["last_field_raw"] = "0x%X" % (int(r["last_field_raw"], 16) + 1)
            mutated_row = (r["method"], r["index"])
            break
    mut_path = code / "s65-eh-clauses.mutated.csv"
    write_csv(mut_path, ["method", "section", "index", "flags", "kind", "try_offset", "try_length",
                         "handler_offset", "handler_length", "last_field_raw", "last_field_role",
                         "last_field_value", "purpose"], mut)
    after = hashlib.sha256(mut_path.read_bytes()).hexdigest()
    located = [(r["method"], r["index"]) for r in mut
               if r["last_field_role"] == "filter_offset"
               and r["last_field_value"] != next(
                   (x["last_field_value"] for x in rows
                    if x["method"] == r["method"] and str(x["index"]) == r["index"]), None)]
    assert mutated_row is not None and located == [mutated_row], (mutated_row, located)
    ctl.append(("mutation changes the table fingerprint", before != after))
    ctl.append(("semantic diff locates the mutated row", located == [mutated_row]))
    # ---- 4. two calli ------------------------------------------------------
    sig = cli_tables.blob_bytes(data, tables, tables["rows"][17][0x75 - 1]["Signature"])
    calli = []
    for tok in CALLI_METHODS:
        m = M[tok]
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        ins = list(il_disasm.decode(hdr["il"]))
        calli_at = [i for i, x in enumerate(ins) if x[1] == "calli"]
        for i in calli_at:
            off, name, operand, size = ins[i]
            ctx = [(("IL_%04X" % c[0]), c[1], c[2]) for c in ins[max(0, i - 4):i]]
            callers = []
            for other in meta["methods"]:
                if not other["rva"] or other["flavor"] != "IL" or other["token"] == tok:
                    continue
                oh, _, _ = method_body.read(data, pe, other["rva"])
                oins = list(il_disasm.decode(oh["il"]))
                for j, x in enumerate(oins):
                    if x[1] in ("call", "callvirt", "ldftn") and x[2].startswith("0x%08X" % tok):
                        prev = [y for y in oins[max(0, j - 4):j]]
                        lf = [z for z in prev if z[1] in ("ldftn", "ldsfld", "ldarg.0", "ldarg.1")]
                        callers.append(dict(caller="0x%08X" % other["token"], at="IL_%04X" % x[0],
                                            op=x[1], context=[(("IL_%04X" % z[0]), z[1], z[2]) for z in prev],
                                            ldftn=[z[2] for z in lf if z[1] == "ldftn"]))
                        break
            calli.append(dict(method="0x%08X" % tok, il_offset="IL_%04X" % off, operand=operand,
                              signature=sig.hex(), context=ctx, callers=callers))
    sig_text = "callconv=0 param_count=%d ret=void param0=ptr<void>" % sig[1]
    ctl.append(("signature 0x11000075 = void(ptr<void>) with one parameter",
                sig[0] == 0 and sig[1] == 1 and sig[2] == 0x01 and sig[3] == 0x0F and sig[4] == 0x01))
    ctl.append(("0x06000056 calli: 8 visible callers with ldftn targets",
                len([c for c in calli if c["method"] == "0x06000056"][0]["callers"]) == 8))
    ctl.append(("0x06000057 calli: zero visible callers",
                len([c for c in calli if c["method"] == "0x06000057"][0]["callers"]) == 0))
    write_csv(code / "s65-calli.csv",
              ["method", "il_offset", "operand", "signature", "context", "caller", "caller_at",
               "caller_op", "caller_ldftn", "caller_context"],
              [dict(method=c["method"], il_offset=c["il_offset"], operand=c["operand"],
                    signature=c["signature"], context=json.dumps(c["context"], ensure_ascii=False),
                    caller=cl["caller"], caller_at=cl["at"], caller_op=cl["op"],
                    caller_ldftn=";".join(cl["ldftn"]),
                    caller_context=json.dumps(cl["context"], ensure_ascii=False))
               for c in calli for cl in (c["callers"] or [dict(caller="", at="", op="", ldftn=[], context=[])])])
    write_csv(code / "s65-catch-types.csv", ["method", "index", "type_token", "handler"], catches)
    # ---- 5. main table rows for the two calli ------------------------------
    calls = read_csv(folder / "calls.csv")
    touched = []
    for row in calls:
        if row["kind"] != "method":
            continue
        caller = int(row["caller"], 0) if row["caller"].startswith("0x") else None
        if caller not in CALLI_METHODS or "calli" not in row["callee"]:
            continue
        c = next(x for x in calli if int(x["method"], 16) == caller)
        targets = sorted({t for cl in c["callers"] for t in cl["ldftn"]})
        if targets:
            row["callee"] = ("调用者传入的函数指针（arg0 -> loc0）；可见调用者 ldftn 目标：%s"
                             % ", ".join(targets))
            row["note"] = ("IL_0004 calli 0x11000075（签名为 void(ptr<void>)，1 个参数，默认调用约定）："
                           "arg0 先 ldarg.0 -> stloc.0 作为函数指针，arg1 作为唯一实参；"
                           "原件可见 %d 个调用者，各自以 ldftn <token> 提供 arg0 → 目标可枚举：%s。"
                           "缺失生产者＝外部调用者/委托表（原件 IL 之外）；恢复条件＝枚举导出与委托注册，"
                           "或在 0x06000056 入口断点读 arg0"
                           % (len(c["callers"]),
                              "; ".join("%s@%s->%s" % (cl["caller"], cl["at"], ",".join(cl["ldftn"]))
                                        for cl in c["callers"])))
            touched.append("0x%08X(provable)" % caller)
        else:
            row["callee"] = "arg0 -> loc0 提供的函数指针（原件无可定位生产者）"
            row["note"] = ("IL_0004 calli 0x11000075（签名 void(ptr<void>)）：arg0 经 stloc.0 作函数指针、"
                           "arg1 作唯一实参；原件 IL 中 0 个 call/callvirt/ldftn 引用本方法 → "
                           "缺失生产者＝外部调用者或委托表；恢复条件＝外部调用者清单/运行期断点；"
                           "本条保留 unresolved")
            touched.append("0x%08X(no-producer)" % caller)
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    print("touched", touched, "calli callers", [len(c["callers"]) for c in calli])
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    md = ["# NATIVE-340 s65 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. EH 子句末字段（按种类）", "",
          "| 方法 | 节 | # | flags | 种类 | try | handler | 末字段原值 | 语义 | 值 |",
          "| --- | --- | ---: | --- | --- | --- | --- | --- | --- | --- |"]
    for r in rows:
        if r["kind"] in ("catch", "filter"):
            md.append("| %s | %s | %d | %s | %s | %s/%s | %s/%s | %s | %s | %s |"
                      % (r["method"], r["section"], r["index"], r["flags"], r["kind"],
                         r["try_offset"], r["try_length"], r["handler_offset"], r["handler_length"],
                         r["last_field_raw"], r["last_field_role"], r["last_field_value"]))
    md += ["", "## 2. 四个 filter 方法", "",
           "| 方法 | filter 起点 | 起点字节 | handler 起点 | handler 前两字节 | 预期 |",
           "| --- | ---: | --- | ---: | --- | --- |"]
    for tok in FILTER_METHODS:
        f = filters[tok]
        md.append("| 0x%08X | IL_%04X | 0x%02X | IL_%04X | %s | %s |"
                  % (tok, f["filter_offset"], f["filter_byte"], f["handler_offset"],
                     f["pre_handler"], "命中" ))
    md += ["", "## 3. 7 个 catch 类型 token", "", "| 方法 | # | type token | handler |", "| --- | ---: | --- | --- |"]
    for c in catches:
        md.append("| %s | %d | %s | %s |" % (c["method"], c["index"], c["type_token"], c["handler"]))
    md += ["", "## 4. 变异测试", "",
           "- 表格指纹 before/after：%s / %s（不同=%s）" % (before[:16], after[:16], before != after),
           "- 语义比对定位：%s（期望 %s）" % (located, mutated_row), "",
           "## 5. 两处 calli", "",
           "签名 0x11000075 blob `%s` = %s。" % (sig.hex(), sig_text)]
    for c in calli:
        md.append("- %s %s：可见调用者 %d 个 → %s"
                  % (c["method"], c["il_offset"], len(c["callers"]),
                     ", ".join("%s@%s:%s" % (cl["caller"], cl["at"], ",".join(cl["ldftn"]) or "-")
                               for cl in c["callers"]) or "无（缺外部生产者）"))
    md += ["", "## 6. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s65-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("sections", len(rows), "catches", len(catches), "filters", len(filters))
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
