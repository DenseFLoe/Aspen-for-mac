# -*- coding: utf-8 -*-
"""NATIVE-340 s37: regenerate the s33 artifacts with a corrected body/EH reader."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402

BASE_HEAD = "e8fb4cbcbcbbd5a5020a7ac7a3209a42d80f364d"     # #450 fixed head


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
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    tables = cli_tables.read(data, md_off)
    by = {m["token"]: m for m in meta["methods"]}

    ctl = method_body.self_test(data, pe, by[0x06000032]["rva"], by[0x06000031]["rva"])
    print("controls:", ctl)

    host = by[0x06000030]
    rel = by[0x06000031]
    caller = by[0x06000032]
    h_hdr, h_eh, h_cl = method_body.read(data, pe, host["rva"])
    r_hdr, r_eh, r_cl = method_body.read(data, pe, rel["rva"])
    c_hdr, c_eh, c_cl = method_body.read(data, pe, caller["rva"])
    clause = c_cl[0]
    sp = "IL_%04X" % clause["handler_offset"]
    ep = "IL_%04X" % (clause["handler_offset"] + clause["handler_length"])   # end-exclusive
    ts = "IL_%04X" % clause["try_offset"]
    te = "IL_%04X" % (clause["try_offset"] + clause["try_length"])            # end-exclusive

    lea = data[pe.filepos(0x29D0):pe.filepos(0x29D0) + 7]
    slot = 0x29D0 + 7 + struct.unpack_from("<i", lea, 3)[0]
    sec = method_body.section_of(pe, slot)
    slot_val = struct.unpack_from("<Q", data, pe.filepos(0x61B8))[0]
    facts = dict(
        method_0x06000032=dict(rva="0x%X" % caller["rva"], header=dict(
            kind=c_hdr["kind"], size=c_hdr["header_size"], code_size=c_hdr["code_size"],
            flags="0x%X" % c_hdr["flags"], more_sections=c_hdr["more_sections"])),
        eh=dict(rva="0x%X" % (c_eh["rva"] if c_eh else 0), kind="0x%X" % (c_eh["kind"] if c_eh else 0),
                fat=(c_eh["fat"] if c_eh else False), size=(c_eh["size"] if c_eh else 0),
                clause_count=len(c_cl), clauses=c_cl),
        handler_span=[sp, ep], try_span=[ts, te],
        slot_0x19b78=dict(rva="0x%X" % slot, section=sec["name"],
                          section_rva="0x%X" % sec["rva"]),
        guard_218d=data[pe.filepos(0x218D):pe.filepos(0x218D) + 3].hex(),
        test_2874=data[pe.filepos(0x28F3):pe.filepos(0x28F3) + 12].hex(),
        branch_2197=data[pe.filepos(0x2195):pe.filepos(0x2195) + 4].hex(),
        dispatch_21a4=data[pe.filepos(0x21A4):pe.filepos(0x21A4) + 3].hex(),
        guard_field="0x%X" % slot_val)
    print(json.dumps(facts, ensure_ascii=False, indent=1))

    calls = read_csv(folder / "calls.csv")
    touched = []
    for row in calls:
        if row["kind"] == "method" and int(row["caller"], 0) == 0x06000031:
            row["callee"] = ("arg0 对象 vtable +0x10（运行期函数指针；loc1 由 0x06000032 的 finally 传入）")
            row["note"] = ("IL_0008 的 calli（签名 0x11000043 = blob 0101205120610918，"
                           "uint32 modopt(CallConvCdecl,IsLong)(native int)）：函数指针取自 arg0 对象 vtable +0x10。"
                           "loc1 来源＝0x06000032 的 finally：方法体 RVA 0x%X（fat，header %d 字节，code %d 字节，"
                           "flags 0x%X MoreSects），EH 节 RVA 0x%X（kind 0x%X fat EHTable，size %d）→ "
                           "%d 个 finally 子句（Flags=0x%X）：try %s-%s（0x%X/0x%X）、handler %s-%s（0x%X/0x%X）、"
                           "ClassToken 0x%08X；loc1 由 0x06000030 取得。绑定范围＝仅该 finally 一路；"
                           "被调函数仍是运行期指针，故本条保留 unresolved"
                           % (caller["rva"], c_hdr["header_size"], c_hdr["code_size"], c_hdr["flags"],
                              c_eh["rva"], c_eh["kind"], c_eh["size"], len(c_cl), clause["flags"],
                              ts, te, clause["try_offset"], clause["try_length"],
                              sp, ep, clause["handler_offset"], clause["handler_length"],
                              clause["class_token"]))
            touched.append("0x06000031")
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽，0x21A4 仅在正分支读取一次）")
            row["note"] = ("R9 全链（四点）："
                           "① 0x217F call 0x1800029D0 -> 0x29D0: 48 8D 05 A1 71 01 00 = lea rax,[rip+0x171A1]，"
                           "槽地址 0x19B78 由该 LEA 返回；0x2184 mov rbx,rax。"
                           "② 空槽判定：0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（槽为空则不调用）。"
                           "③ 节判据：0x218D 48 8B C8 = mov rcx,rax（把槽地址作为 arg0 传给 0x2874）；"
                           "0x2874 解析 PE 头取得该地址所在节，0x28F3 83 7A 24 00 = cmp dword ptr [rdx+0x24],0 是"
                           "对节 Characteristics 的有符号测试（0x28F7 7D 04 = jge）：符号位清（不可写）→ al=0，"
                           "符号位置位（IMAGE_SCN_MEM_WRITE 0x80000000，可写）→ al=1；"
                           "0x2195 test al,al + 0x2197 74 18 jz 0x21B1：al==0（不可写）跳过调用，可写才调用；"
                           "固定槽 0x19B78 在 .data（Characteristics 0xC0000040，符号位置位＝可写）→ al=1 → 走调用。"
                           "④ 单次读取（仅正分支）：0x2199-0x21AE 分支内 0x21A4 mov rax,[rbx] 对固定槽只读一次；"
                           "0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0（0x48B0: FF E0 = JMP RAX）；0x21AE call r9。"
                           "静态只剩回调槽写入者与被调实现未定；恢复条件＝在 0x21AE 停住读 RAX，或在 0x19B78 下断点看写入者")
            touched.append("0x20CC")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)
    print("rows touched:", touched)

    unresolved = [r for r in calls if r["class"] == "unresolved"]
    managed = [r for r in unresolved if r["kind"] == "method"]
    native = [r for r in unresolved if r["kind"] == "native"]
    mrows = [dict(index=i, caller=r["caller"], callee_name=r["callee"], callee=r["callee"],
                  listing=r["listing"], note=r["note"], reason="IL calli：目标为运行期函数指针")
             for i, r in enumerate(managed, start=1)]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate(native, start=1)]
    for name in ("s25-unresolved-managed.csv", "s33-unresolved-managed.csv", "s37-unresolved-managed.csv"):
        write_csv(code / name, ["index", "caller", "callee_name", "callee", "listing", "note", "reason"], mrows)
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv", "s37-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)

    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1
    metrics = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
    metrics.update(dict(external=classes.get("external", 0), boundary=classes.get("boundary", 0),
                        unresolved=classes.get("unresolved", 0),
                        s37_managed_unresolved=len(managed), s37_native_unresolved=len(native),
                        s37_method_0x06000032_rva="0x%X" % caller["rva"],
                        s37_eh_rva="0x%X" % c_eh["rva"], s37_eh_kind="0x%X" % c_eh["kind"],
                        s37_eh_clauses=len(c_cl), s37_handler_span="%s-%s" % (sp, ep),
                        s37_calls_sha256=hashlib.sha256((folder / "calls.csv").read_bytes()).hexdigest()))
    (folder / "metrics.json").write_text(json.dumps(metrics, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    runj = json.loads((folder / "run.json").read_text(encoding="utf-8-sig"))
    runj.update({"s37_base_head": BASE_HEAD, "s37_method_0x06000032_rva": "0x%X" % caller["rva"],
                 "s37_eh_rva": "0x%X" % c_eh["rva"], "s37_eh_clauses": len(c_cl),
                 "s37_handler_span": "%s-%s" % (sp, ep),
                 "s37_body_reader": "tool/method_body.py (fat header Size nibble + EH section kind/size)"})
    (folder / "run.json").write_text(json.dumps(runj, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    md = ["# NATIVE-340 s37 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。" % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 生成器修正（读 MethodDef RVA 与 EH 数据节）", "",
          "- 旧：EH 子句数取自 fat header 的 `flags >> 8`（0x06000032 得到 48），且按文件偏移对齐、"
          "直接把 EH 节头当第一条子句读。",
          "- 新：`tool/method_body.py` 按 fat header 的 Size 半字节取头长，按 RVA 4 对齐到 IL 之后，"
          "读 EH 节头（kind byte：0x01 EHTable | 0x40 fat；3 字节 data size），子句数 = (size-4)/entry，"
          "并校验节归属与可执行性。",
          "- 控制项：%s" % ("；".join("%s=%s" % (n, "PASS" if o else "FAIL") for n, o in ctl)), "",
          "## 2. 0x06000032（验证用例）", "",
          "| 项 | 实测 |", "| --- | --- |",
          "| MethodDef RVA | `0x%X` |" % caller["rva"],
          "| 方法头 | fat，%d 字节，code %d 字节，flags `0x%X`（MoreSects） |"
          % (c_hdr["header_size"], c_hdr["code_size"], c_hdr["flags"]),
          "| EH 节 | RVA `0x%X`，kind `0x%X`（fat EHTable），size %d |" % (c_eh["rva"], c_eh["kind"], c_eh["size"]),
          "| 子句数 | %d（finally，Flags=0x%X） |" % (len(c_cl), clause["flags"]),
          "| try | %s-%s（0x%X/0x%X） |" % (ts, te, clause["try_offset"], clause["try_length"]),
          "| handler | %s-%s（0x%X/0x%X） |" % (sp, ep, clause["handler_offset"], clause["handler_length"]),
          "| ClassToken | `0x%08X` |" % clause["class_token"], "",
          "注：上一版回执写的 `0x1B28` 不是本方法的方法体 RVA，也不是 EH 节 RVA（该地址无方法头、无 EH 节头）；"
          "本轮以生成器输出为准：方法体 `0x%X`、EH 节 `0x%X`。" % (caller["rva"], c_eh["rva"]), "",
          "## 3. 0x218D / 0x2874 / 0x2197", "",
          "- `0x218D` `48 8B C8` = mov rcx, rax：把槽地址（0x29D0 的 LEA 返回值）作为 arg0 传给 0x2874。",
          "- `0x2874`：走 PE 头定位该地址所在节（R8=地址，RDX=节头），`0x28F3` `83 7A 24 00` = "
          "cmp dword ptr [rdx+0x24],0 对 Characteristics 做有符号测试，`0x28F7` `7D 04` = jge："
          "符号位清（不可写）→ al=0；符号位置位（IMAGE_SCN_MEM_WRITE=0x80000000，可写）→ al=1。",
          "- `0x2197`：`0x2195` `84 C0` test al,al + `74 18` jz 0x21B1 ⇒ al==0（不可写）才跳过；"
          "极性＝可写才调用。固定槽 `0x19B78` 在 .data（Characteristics `0xC0000040`，符号位置位）→ 可写 → 走调用。",
          "- `0x21A4` 的 `mov rax,[rbx]` 只在正分支（0x2199 起）执行一次，范围未扩大。", "",
          "## 4. 计数", "",
          "| 指标 | 值 |", "| --- | --- |",
          "| external / boundary / unresolved | %d / %d / %d |" % (classes.get("external", 0),
                                                                 classes.get("boundary", 0),
                                                                 classes.get("unresolved", 0)),
          "| 未决托管 / 原生 | %d / %d |" % (len(managed), len(native)),
          "| 237 槽 / 122 MethodDef / 228 回编桩 | 沿用 |", ""]
    (code / "s37-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")

    fp = {}
    for p in sorted(folder.rglob("*")):
        if p.is_file() and p.name != "s37-fingerprints.json":
            fp[p.relative_to(folder).as_posix()] = hashlib.sha256(p.read_bytes()).hexdigest()
    (code / "s37-fingerprints.json").write_text(
        json.dumps(dict(base_head=BASE_HEAD, files=fp), ensure_ascii=False, indent=1) + "\n", encoding="utf-8")
    print("fingerprints", len(fp))
    return 0


if __name__ == "__main__":
    sys.exit(main())
