# -*- coding: utf-8 -*-
"""NATIVE-340 s73: corrected MethodDef flags, coded-index decoding, entry tracing."""
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

BASE_HEAD = "5ca17f4987251f32be4772955c8b9be3185b9c62"
TARGETS = (0x06000056, 0x06000057)
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
ACCESS = {0: "privatescope", 1: "private", 2: "famandassem", 3: "assembly",
          4: "family", 5: "famorassem", 6: "public"}
MEMREF_PARENT = ["TypeDef", "TypeRef", "ModuleRef", "MethodDef", "TypeSpec"]
STUBS = {0x5574: 0x19600, 0x557A: 0x19608, 0x5584: 0x19610, 0x558A: 0x19618}


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def decode_memberref_parent(v):
    tag = v & 7
    return (MEMREF_PARENT[tag] if tag < len(MEMREF_PARENT) else "reserved"), v >> 3


def decode_methoddef_orref(v):
    tag = v & 1
    return ("MethodDef" if tag == 0 else "MemberRef"), v >> 1


def stub_target(data, pe, addr):
    p = pe.filepos(addr)
    assert data[p] == 0xFF and data[p + 1] == 0x25, hex(addr)
    disp = struct.unpack_from("<i", data, p + 2)[0]
    return addr + 6 + disp


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

    # ---- 1. corrected MethodDef flags / ImplFlags / access -----------------
    arows = []
    for tok in TARGETS:
        m = M[tok]
        flags, impl = m["flags"], m["impl_flags"]
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        arows.append(dict(token="0x%08X" % tok, name=m["name"], flags="0x%04X" % flags,
                          impl_flags="0x%04X" % impl, access=ACCESS[flags & 7],
                          static=bool(flags & 0x10), has_security=bool(flags & 0x4000),
                          rva="0x%X" % m["rva"],
                          il_sha256=hashlib.sha256(hdr["il"]).hexdigest(),
                          il_len=len(hdr["il"]), signature="0x%X" % m["signature"]))
    write_csv(code / "s73-method-access.csv",
              ["token", "name", "flags", "impl_flags", "access", "static", "has_security", "rva",
               "il_sha256", "il_len", "signature"], arows)
    ctl.append(("both methods flags 0x4013, ImplFlags 0x0", all(r["flags"] == "0x4013"
                                                               and r["impl_flags"] == "0x0000" for r in arows)))
    ctl.append(("0x4013 & 7 == 3 -> Assembly (not privatescope)",
                all(r["access"] == "assembly" and r["static"] and r["has_security"] for r in arows)))
    ctl.append(("IL sha256 is the full 64 hex chars", all(len(r["il_sha256"]) == 64 for r in arows)))
    ctl.append(("0x06000056 and 0x06000057 have identical IL bodies",
                arows[0]["il_sha256"] == arows[1]["il_sha256"]))

    # ---- 2. coded index decoding + MethodImpl columns ----------------------
    pairs = []
    for raw, want in ((17, ("TypeRef", 2)), (11, ("MethodDef", 1)), (27, ("MethodDef", 3)),
                      (33, ("TypeRef", 4))):
        got = decode_memberref_parent(raw)
        pairs.append(dict(space="MemberRefParent", raw=raw, expected="%s[%d]" % want,
                          actual="%s[%d]" % got, ok=(got == want),
                          input_sha256=hashlib.sha256(struct.pack("<I", raw)).hexdigest()))
    for raw, want in ((3, ("MemberRef", 1)), (2, ("MethodDef", 1)), (0x1C, ("MethodDef", 14))):
        got = decode_methoddef_orref(raw)
        pairs.append(dict(space="MethodDefOrRef", raw=raw, expected="%s[%d]" % want,
                          actual="%s[%d]" % got, ok=(got == want),
                          input_sha256=hashlib.sha256(struct.pack("<I", raw)).hexdigest()))
    ctl.append(("coded-index decoder unit pairs all match", all(p["ok"] for p in pairs)))
    dist = {}
    for r in tables["rows"][10]:
        name, row = decode_memberref_parent(r["Class"])
        dist[name] = dist.get(name, 0) + 1
    impl_rows = tables["rows"].get(25, [])
    impl_dec = []
    for r in impl_rows:
        decl = decode_methoddef_orref(r.get("MethodDeclaration", 0))
        body = decode_methoddef_orref(r.get("MethodBody", 0))
        impl_dec.append(dict(declaration="%s[%d]" % decl, implementation="%s[%d]" % body))
    ctl.append(("MemberRef parents decode to %s (no MethodDef parent)" % dist,
                dist.get("MethodDef", 0) == 0 and sum(dist.values()) == 109))
    ctl.append(("MethodImpl has %d rows; declaration/implementation columns decoded" % len(impl_rows),
                len(impl_dec) == len(impl_rows)))
    # paired experiment: visibility x binding
    pub = next(m["token"] for m in meta["methods"]
               if (m["flags"] & 7) == 6 and m["rva"] and m["flavor"] == "IL")
    exp = []
    for tok, vis_label in ((0x06000056, "assembly"), (pub, "public")):
        m = M.get(tok) or next(x for x in meta["methods"] if x["token"] == tok)
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        bound = any(decode_memberref_parent(r["Class"])[0] == "MethodDef" for r in tables["rows"][10]) \
            or bool(impl_rows)
        exp.append(dict(method="0x%08X" % tok, visibility=ACCESS[m["flags"] & 7],
                        flags="0x%04X" % m["flags"], has_memberref_binding=bound,
                        has_methodimpl_binding=bool(impl_rows),
                        expected="no binding (image has none)",
                        actual="no binding" if not bound else "binding present",
                        input_sha256=hashlib.sha256(hdr["il"]).hexdigest(),
                        ok=(not bound)))
    write_csv(code / "s73-metadata-decode.csv",
              ["space", "raw", "expected", "actual", "ok", "input_sha256"], pairs)
    write_csv(code / "s73-binding-pairs.csv",
              ["method", "visibility", "flags", "has_memberref_binding", "has_methodimpl_binding",
               "expected", "actual", "input_sha256", "ok"], exp)
    ctl.append(("visibility pair (assembly vs public) both report no binding", all(e["ok"] for e in exp)))

    # ---- 3. entry tracing: stubs -> patch slots ----------------------------
    erows = []
    for addr, want_slot in STUBS.items():
        target = stub_target(data, pe, addr)
        p = pe.filepos(target)
        initial = struct.unpack_from("<Q", data, p)[0]
        erows.append(dict(stub="0x%X" % addr, jmp_target="0x%X" % target,
                          slot_expected="0x%X" % want_slot, slot_matches=(target == want_slot),
                          slot_initial="0x%X" % initial,
                          slot_is_methoddef=(initial in TARGETS),
                          method="0x%08X" % initial if initial in TARGETS else "-"))
    for addr in (0x5570, 0x5580):
        p = pe.filepos(addr)
        erows.append(dict(stub="0x%X" % addr, jmp_target="0x%X" % (addr + 2 + struct.unpack_from("<b", data, p + 1)[0]),
                          slot_expected="-", slot_matches=True, slot_initial="-",
                          slot_is_methoddef=False, method="jmp thunk"))
    write_csv(code / "s73-entry-trace.csv",
              ["stub", "jmp_target", "slot_expected", "slot_matches", "slot_initial",
               "slot_is_methoddef", "method"], erows)
    ctl.append(("0x5584 -> 0x19610 and 0x558A -> 0x19618", erows[2]["slot_matches"] and erows[3]["slot_matches"]))
    ctl.append(("0x5574 -> 0x19600 and 0x557A -> 0x19608 (0x06000056 entries)",
                erows[0]["slot_matches"] and erows[1]["slot_matches"]))
    ctl.append(("all four slots initially hold a MethodDef token (CLR fixup before patch)",
                all(r["slot_is_methoddef"] for r in erows[:4])))

    # ---- 4. recheck: sites, EH, pointer targets, paired evidence -----------
    sites = []
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr, _, _ = method_body.read(data, pe, m["rva"])
        ins = list(il_disasm.decode(hdr["il"]))
        for j, x in enumerate(ins):
            if x[1] in ("call", "callvirt", "newobj", "ldftn") and x[2].lower() == "0x06000056":
                prev = ins[max(0, j - 3):j]
                sites.append(dict(method="0x%08X" % m["token"], il_offset="IL_%04X" % x[0],
                                  ldftn=", ".join(z[2] for z in prev if z[1] == "ldftn"),
                                  arg=", ".join("%s %s" % (z[1], z[2]) for z in prev
                                                if z[1] in ("ldarg.0", "ldloca.s"))))
    ctl.append(("8 methods / 11 sites still enumerate", len(sites) == 11
                and len({s["method"] for s in sites}) == 8))
    real_clauses = 0
    for m in meta["methods"]:
        if not m["rva"] or m["flavor"] != "IL":
            continue
        hdr = method_body.header(data, pe, m["rva"])
        if hdr["more_sections"]:
            real_clauses += sum(len(s.get("clauses", [])) for s in method_body.data_sections(data, pe, hdr))
    ctl.append(("35 EH clauses still read", real_clauses == 35))
    ctl.append(("EH synthetic tests pass", all(ok for _, ok in method_body.synthetic_tests())))
    g = x86_340.gate_facts(data, pe, GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                           GATE["test_addr"], GATE["jz_addr"])
    a2 = bytearray(data); a2[pe.filepos(GATE["jcc_addr"])] = 0x7C
    gj = x86_340.gate_facts(bytes(a2), PE(bytes(a2)), GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                            GATE["test_addr"], GATE["jz_addr"])
    ctl.append(("AL three states 0/1 with skip true/false",
                [g["al_for_slot"], gj["al_for_slot"]] == [0, 1]
                and [g["slot_skipped"], gj["slot_skipped"]] == [True, False]))
    full = sites
    variant = [s for s in sites if not (s["method"] == "0x0600000B" and s["il_offset"] == "IL_0044")]
    key = lambda r: (r["method"], r["il_offset"])
    missing = [key(r) for r in full if key(r) not in {key(x) for x in variant}]
    ctl.append(("paired evidence: removing one site is located", missing == [("0x0600000B", "IL_0044")]))
    ev = dict(full_sites=len(full), variant_sites=len(variant), missing=missing,
              sites=full, full_sha256=hashlib.sha256(json.dumps(full, sort_keys=True).encode()).hexdigest(),
              variant_sha256=hashlib.sha256(json.dumps(variant, sort_keys=True).encode()).hexdigest())
    (code / "s73-evidence.json").write_text(json.dumps(ev, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    ctl.append(("complete vs one-site-removed evidence fingerprints differ",
                ev["full_sha256"] != ev["variant_sha256"]))

    # ---- 5. main table: corrected entries + wording ------------------------
    calls = read_csv(folder / "calls.csv")
    touched = 0
    for row in calls:
        if row["kind"] != "method" or row["class"] != "unresolved":
            continue
        if row["caller"].lower() not in ("0x%x" % t for t in TARGETS):
            continue
        tok = int(row["caller"], 16)
        if tok == 0x06000056:
            row["callee"] = ("调用者传入的函数指针（arg0 -> loc0）；8 方法 / 11 站点；"
                             "两条入口 stub 0x5574->[0x19600]、0x557A->[0x19608]；ldftn 目标：%s"
                             % ", ".join(sorted({s["ldftn"] for s in sites})))
            row["note"] = ("IL_0004 calli 0x11000075（0001010F01 = void(ptr<void>)，1 参默认约定）："
                           "arg0 经 ldarg.0 -> stloc.0 作函数指针，arg1 是唯一实参。"
                           "原件 11 站点见 code/s69-calli-sites.csv：0x0600000B IL_002D/IL_0044(ldftn 0x06000006)、"
                           "0x0600000C/0x0600000F/0x06000013/0x06000019 IL_002D(ldftn 0x06000002)、"
                           "0x0600001F IL_0061/IL_0087(ldftn 0x06000026，ldloca.s 0x4 = 局部 4 地址)、"
                           "0x06000051 IL_0019(ldftn 0x0600004F，ldloca.s 0x0)、"
                           "0x06000091 IL_005F/IL_0077(ldftn 0x06000023，ldloca.s 0x2)。"
                           "方法头 Flags 0x4013（Assembly|Static|HasSecurity，ImplFlags 0）。"
                           "缺失生产者＝本模块之外的调用者/委托表；恢复条件＝枚举导出与委托注册，或入口断点读 arg0")
            touched += 1
        else:
            row["callee"] = ("调用者传入的函数指针（arg0 -> loc0）；原件 0 个直接引用；"
                             "两条入口 stub 0x5584->[0x19610]、0x558A->[0x19618]")
            row["note"] = ("IL_0004 calli 0x11000075：arg0 经 stloc.0 作函数指针、arg1 作唯一实参；"
                           "原件 IL 中 0 个 call/callvirt/ldftn 直接引用本方法；无 MemberRef（109 条全为 "
                           "TypeRef/TypeSpec 父）与 MethodImpl（0 行）绑定；Flags 0x4013 = Assembly|Static|HasSecurity，"
                           "ImplFlags 0；与 0x06000056 的 IL 体逐字节相同（孪生体，不同 token）。"
                           "入口：0x5584 jmp [0x19610]、0x558A jmp [0x19618]，两槽初值均为 MethodDef token 0x06000057，"
                           "由 CLR fixup 在首次调用时改写。缺失生产者＝外部调用者或委托表；"
                           "恢复条件＝导出调用者清单或运行期断点（行为测试留 Windows 阶段）")
            touched += 1
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)

    md = ["# NATIVE-340 s73 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 更正后的方法属性", "",
          "| token | 名称 | Flags | ImplFlags | 访问 | Static | HasSecurity | IL SHA-256 |",
          "| --- | --- | --- | --- | --- | --- | --- | --- |"]
    for r in arows:
        md.append("| %s | %s | %s | %s | %s | %s | %s | `%s` |"
                  % (r["token"], r["name"], r["flags"], r["impl_flags"], r["access"],
                     r["static"], r["has_security"], r["il_sha256"]))
    md += ["", "## 2. 编码索引解码（MemberRefParent / MethodDefOrRef）", "",
           "| 空间 | 原始值 | 预期 | 实测 | 输入 SHA-256 |", "| --- | ---: | --- | --- | --- |"]
    for p in pairs:
        md.append("| %s | %d | %s | %s | `%s` |"
                  % (p["space"], p["raw"], p["expected"], p["actual"], p["input_sha256"]))
    md += ["", "MemberRefParent 实况分布：%s；MethodImpl 行数：%d。"
           % (dist, len(impl_rows)), "",
           "## 3. 入口来路", "",
           "| stub | jmp 目标 | 预期槽 | 命中 | 槽初值 | 是 MethodDef token |", "| --- | --- | --- | --- | --- | --- |"]
    for r in erows:
        md.append("| %s | %s | %s | %s | %s | %s |"
                  % (r["stub"], r["jmp_target"], r["slot_expected"], r["slot_matches"],
                     r["slot_initial"], r["slot_is_methoddef"]))
    md += ["", "## 4. 复核", "",
           "- 8 方法 / 11 站点；35 EH 子句；AL 三态 0/1；删一站后证据指纹变化并定位。",
           "- 完整证据 SHA-256 `%s`；删 0x0600000B IL_0044 后 `%s`。"
           % (ev["full_sha256"], ev["variant_sha256"]), "",
           "## 5. 控制项（%d）" % len(ctl), ""]
    for n, ok in ctl:
        md.append("- %s：%s" % ("PASS" if ok else "FAIL", n))
    md.append("")
    (code / "s73-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok], "touched", touched)
    print("flags", arows[0]["flags"], "access", arows[0]["access"], "sha", arows[0]["il_sha256"])
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
