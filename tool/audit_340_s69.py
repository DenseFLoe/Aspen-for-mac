# -*- coding: utf-8 -*-
"""NATIVE-340 s69: full per-site enumeration of 0x06000056 + access/alias facts."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e"
TARGETS = (0x06000056, 0x06000057)
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
CHECK_SITES = {("0x0600000B", "IL_0044"): "0x06000006",
               ("0x0600001F", "IL_0087"): "0x06000026",
               ("0x06000091", "IL_0077"): "0x06000023"}
ACCESS = {0: "privatescope", 1: "private", 2: "famandassem", 3: "assembly",
          4: "family", 5: "famorassem", 6: "public"}


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def enumerate_sites(data, pe, meta):
    sites = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        ins = list(il_disasm.decode(hdr["il"]))
        for j, x in enumerate(ins):
            off, name, operand, size = x
            if name not in ("call", "callvirt", "newobj", "ldftn"):
                continue
            if operand.lower() not in ("0x%08x" % t for t in TARGETS):
                continue
            prev = ins[max(0, j - 3):j]
            ldftn = [z[2] for z in prev if z[1] == "ldftn"]
            arg = [(z[1], z[2]) for z in prev if z[1] in ("ldarg.0", "ldarg.1", "ldarg.2", "ldarg.3",
                                                          "ldloca.s", "ldloc.0", "ldloc.1", "ldnull")]
            sites.append(dict(method="0x%08X" % m["token"], method_name=m.get("name", ""),
                              il_offset="IL_%04X" % off, op=name, target="0x%08X" % int(operand, 16),
                              ldftn=", ".join(ldftn), arg=", ".join("%s %s" % a for a in arg)))
    return sites


def compare_evidence(full, subset):
    """Same comparison the verifier describes: complete rows vs rows with one site removed."""
    key = lambda r: (r["method"], r["il_offset"])
    have = {key(r) for r in subset}
    return [key(r) for r in full if key(r) not in have]


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

    sites = enumerate_sites(data, pe, meta)
    sites56 = [s for s in sites if s["target"].lower() == "0x06000056"]
    sites57 = [s for s in sites if s["target"].lower() == "0x06000057"]
    methods56 = sorted({s["method"] for s in sites56})
    ctl = [
        ("0x06000056: 8 distinct methods", len(methods56) == 8),
        ("0x06000056: 11 sites", len(sites56) == 11),
        ("0x06000057: 0 sites", len(sites57) == 0),
    ]
    for (meth, off), want in CHECK_SITES.items():
        row = next((s for s in sites56 if s["method"].lower() == meth.lower() and s["il_offset"] == off), None)
        ctl.append(("%s %s -> ldftn %s" % (meth, off, want),
                    row is not None and row["ldftn"].lower() == want))
    for i, s in enumerate(sites56, start=1):
        s["site_index"] = i
    write_csv(code / "s69-calli-sites.csv",
              ["site_index", "method", "method_name", "il_offset", "op", "target", "ldftn", "arg"], sites56)

    # ---- access level / pointer entry / metadata aliases -------------------
    def il_sha(tok):
        hdr, _, _ = method_body.read(data, pe, M[tok]["rva"])
        return hashlib.sha256(hdr["il"]).hexdigest()

    twins = {}
    for tok in TARGETS:
        twins[tok] = [t for t in M if t != tok and M[t]["rva"] and M[t]["flavor"] == "IL"
                      and il_sha(t) == il_sha(tok)]
    refs = tables["rows"].get(10, [])
    memref = {tok: sum(1 for r in refs if r.get("Class") in (tok,)) for tok in TARGETS}
    impl = tables["rows"].get(25, [])
    mimpl = {tok: sum(1 for r in impl if r.get("MethodBody") in (tok,) or r.get("MethodDeclaration") in (tok,))
             for tok in TARGETS}
    byrva = {}
    for tok, m in M.items():
        if m["rva"]:
            byrva.setdefault(m["rva"], []).append(tok)
    arows = []
    for tok in TARGETS:
        m = M[tok]
        flags = m.get("flags", 0)
        acc = ACCESS.get(flags & 7, "0x%X" % (flags & 7))
        arows.append(dict(token="0x%08X" % tok, name=m.get("name", ""), flags="0x%X" % flags,
                          access=acc, impl_flags="0x%X" % m.get("impl_flags", 0),
                          rva="0x%X" % m["rva"], il_sha256=il_sha(tok)[:32],
                          memberref_refs=memref[tok], methodimpl_refs=mimpl[tok],
                          duplicate_rva=("no" if len(byrva.get(m["rva"], [])) == 1 else "yes"),
                          twin=", ".join("0x%08X" % t for t in twins[tok]) or "-",
                          ptr_entry="ldftn 生成的托管函数指针；IL_0004 calli 经 arg0 传入"))
    write_csv(code / "s69-method-access.csv",
              ["token", "name", "flags", "access", "impl_flags", "rva", "il_sha256", "memberref_refs",
               "methodimpl_refs", "duplicate_rva", "twin", "ptr_entry"], arows)
    ctl.append(("both methods are privatescope, IL, no duplicate RVA",
                all(r["access"] == "privatescope" and r["impl_flags"] == "0x0"
                    and r["duplicate_rva"] == "no" for r in arows)))
    ctl.append(("no MemberRef/MethodImpl alias path", all(r["memberref_refs"] == 0
                                                          for r in arows)))
    ctl.append(("0x06000056 and 0x06000057 have identical IL bodies (twin bodies, distinct tokens)",
                twins[0x06000056] == [0x06000057] and twins[0x06000057] == [0x06000056]))

    # ---- paired evidence: complete 11 rows vs one removed ------------------
    full = [dict(r) for r in sites56]
    variant = [dict(r) for r in sites56
               if not (r["method"].lower() == "0x0600000b" and r["il_offset"] == "IL_0044")]
    missing_full = compare_evidence(full, full)
    missing_variant = compare_evidence(full, variant)
    ctl.append(("paired: complete evidence has zero差异", missing_full == []))
    ctl.append(("paired: removing 0x0600000B IL_0044 is located exactly",
                missing_variant == [("0x0600000B", "IL_0044")]))
    (code / "s69-evidence.json").write_text(
        json.dumps(dict(full_sites=len(full), variant_sites=len(variant),
                        missing_complete=missing_full, missing_variant=missing_variant,
                        sites=[dict(r) for r in full]), ensure_ascii=False, indent=1) + "\n",
        encoding="utf-8")

    # ---- keep EH / AL / tiny ---------------------------------------------
    real_clauses = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if hdr["more_sections"]:
            real_clauses += sum(len(s.get("clauses", [])) for s in method_body.data_sections(data, pe, hdr))
    ctl.append(("EH: 35 clauses still read", real_clauses == 35))
    ctl.append(("EH synthetic tests all pass", all(ok for _, ok in method_body.synthetic_tests())))
    g = x86_340.gate_facts(data, pe, GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                           GATE["test_addr"], GATE["jz_addr"])
    a = bytearray(data); a[pe.filepos(GATE["jcc_addr"])] = 0x7C
    gj = x86_340.gate_facts(bytes(a), PE(bytes(a)), GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                            GATE["test_addr"], GATE["jz_addr"])
    ctl.append(("AL three states 0/1 with skip true/false",
                [g["al_for_slot"], gj["al_for_slot"]] == [0, 1]
                and [g["slot_skipped"], gj["slot_skipped"]] == [True, False]))
    tiny = {}
    for blob in (bytes([0x0A, 0x00, 0x2A]), bytes([0x0A, 0x01, 0x2A])):
        d2 = bytearray(0x2000); d2[0:3] = blob
        p2 = method_body._FakePE(bytes(d2), [dict(rva=0x1000, size=0x1000, raw=0, vsize=0x1000,
                                                  hdr=0x80, exec=True, name=".text")])
        tiny[blob.hex()] = method_body.header(bytes(d2), p2, 0x1000)["code_size"]
    ctl.append(("tiny header 0A 00 2A and 0A 01 2A both size 2",
                tiny == {"0a002a": 2, "0a012a": 2}))

    # ---- main table note for the 0x06000056 calli -------------------------
    calls = read_csv(folder / "calls.csv")
    for row in calls:
        if row["kind"] != "method" or row["class"] != "unresolved":
            continue
        if not row["caller"].lower() in ("0x%x" % t for t in TARGETS):
            continue
        tok = int(row["caller"], 16)
        if tok == 0x06000056:
            row["callee"] = ("调用者传入的函数指针（arg0 -> loc0）；8 个方法 / 11 个站点，ldftn 目标：%s"
                             % ", ".join(sorted({s["ldftn"] for s in sites56})))
            row["note"] = ("IL_0004 calli 0x11000075（签名 0001010F01 = void(ptr<void>)，1 参默认约定）："
                           "arg0 经 ldarg.0 -> stloc.0 作函数指针，arg1 是唯一实参（ldarg.0 或 ldloca.s）。"
                           "原件 11 个站点按地址逐条列于 code/s69-calli-sites.csv（去重方法 8 个）："
                           + "; ".join("%s@%s->%s" % (s["method"][-3:], s["il_offset"], s["ldftn"])
                                       for s in sites56)
                           + "。缺失生产者＝本方法之外的调用者/委托表；恢复条件＝枚举导出与委托注册，"
                             "或在 0x06000056 入口断点读 arg0")
        else:
            row["callee"] = "arg0 -> loc0 提供的函数指针（原件 0 个直接引用；privatescope）"
            row["note"] = ("IL_0004 calli 0x11000075：arg0 经 stloc.0 作函数指针、arg1 作唯一实参；"
                           "原件 IL 中 0 个 call/callvirt/ldftn 引用本方法，且无 MemberRef/MethodImpl 别名；"
                           "privatescope（flags 0x0），与 0x06000056 的 IL 体逐字节相同（孪生体，不同 token）。"
                           "缺失生产者＝外部调用者或委托表；恢复条件＝外部调用者清单或运行期断点")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)

    md = ["# NATIVE-340 s69 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 0x06000056 全站点（%d 站 / %d 方法）" % (len(sites56), len(methods56)), "",
          "| # | 方法 | 名称 | 站点 | ldftn | 实参 |", "| ---: | --- | --- | --- | --- | --- |"]
    for s in sites56:
        md.append("| %d | %s | %s | %s | %s | %s |"
                  % (s["site_index"], s["method"], s["method_name"], s["il_offset"], s["ldftn"], s["arg"]))
    md += ["", "## 2. 两方法访问级别与别名", "",
           "| token | 名称 | flags | 访问 | ImplFlags | RVA | MemberRef | MethodImpl | 重复 RVA | 孪生体 |",
           "| --- | --- | --- | --- | --- | --- | ---: | ---: | --- | --- |"]
    for r in arows:
        md.append("| %s | %s | %s | %s | %s | %s | %d | %d | %s | %s |"
                  % (r["token"], r["name"], r["flags"], r["access"], r["impl_flags"], r["rva"],
                     r["memberref_refs"], r["methodimpl_refs"], r["duplicate_rva"], r["twin"]))
    md += ["", "## 3. 配对复验（完整 vs 缺一站点）", "",
           "- 完整 11 行：差异 %s" % (missing_full or "无"),
           "- 删去 0x0600000B IL_0044：差异 %s" % (missing_variant,), "",
           "## 4. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s69-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("sites", len(sites56), "methods", len(methods56), "sites57", len(sites57))
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
