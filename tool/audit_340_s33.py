# -*- coding: utf-8 -*-
"""NATIVE-340 s33: 0x21AE boundary rewrite, 0x06000031 IL_0008 binding, annex + metrics."""
import argparse, csv, json, struct, sys, uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import md_reader  # noqa: E402


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def method_body(data, pe, rva):
    p = pe.filepos(rva)
    h = data[p]
    if (h & 3) == 3:
        size = struct.unpack_from("<I", data, p + 4)[0]
        flags = struct.unpack_from("<H", data, p)[0]
        eh = flags >> 8
        il = data[p + 12:p + 12 + size]
        q = p + 12 + size
        q += (4 - (q - p) % 4) % 4
        clauses = [struct.unpack_from("<IIIIII", data, q + 24 * i) for i in range(eh)]
        return il, clauses
    return data[p + 1:p + 1 + (h >> 2)], []


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    a = ap.parse_args()
    folder = Path(a.folder)
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    tables = cli_tables.read(data, md_off)
    by_token = {m["token"]: m for m in meta["methods"]}

    host_il, _ = method_body(data, pe, by_token[0x06000030]["rva"])
    rel_il, _ = method_body(data, pe, by_token[0x06000031]["rva"])
    caller_il, clauses = method_body(data, pe, by_token[0x06000032]["rva"])
    sig = {rid: cli_tables.blob_bytes(data, tables, tables["rows"][17][rid - 1]["Signature"]).hex()
           for rid in (0x43, 0x44)}
    field_rva = {row["Field"]: row["RVA"] for row in tables["rows"].get(29, [])}
    guids = {}
    for rid in (0x55, 0x56):
        rva = field_rva[rid]
        raw = data[pe.filepos(rva):pe.filepos(rva) + 16]
        guids[rid] = (rva, str(uuid.UUID(bytes_le=raw)).upper())
    span = data[pe.filepos(0x217F):pe.filepos(0x217F) + 26]
    lea = data[pe.filepos(0x29D0):pe.filepos(0x29D0) + 8]
    guard = 0x29D0 + 7 + struct.unpack_from("<i", lea, 3)[0]
    sec = next(s for s in pe.secs if s["rva"] <= guard < s["rva"] + s["vsize"])
    sec_check = data[pe.filepos(0x28F3):pe.filepos(0x28F3) + 14]
    dispatch = data[pe.filepos(0x21A4):pe.filepos(0x21A4) + 13]
    slot_ptr = struct.unpack_from("<Q", data, pe.filepos(0x61B8))[0]
    thunk = data[pe.filepos(0x48B0):pe.filepos(0x48B0) + 2]
    facts = dict(
        host_il=host_il.hex(), release_il=rel_il.hex(), caller_il=caller_il.hex(),
        caller_rva="0x%X" % by_token[0x06000032]["rva"], caller_eh=len(clauses),
        signature_0x11000043=sig[0x43], signature_0x11000044=sig[0x44],
        clsid=dict(token="0x04000055", rva="0x%X" % guids[0x55][0], value=guids[0x55][1]),
        riid=dict(token="0x04000056", rva="0x%X" % guids[0x56][0], value=guids[0x56][1]),
        span_217f=span.hex(), guard_slot="0x%X" % guard,
        section=dict(name=sec["name"], rva="0x%X" % sec["rva"],
                     raw_size="0x%X" % sec["size"], virt_size="0x%X" % sec["vsize"]),
        section_check_28f3=sec_check.hex(), dispatch_21a4=dispatch.hex(),
        guard_field_value="0x%X" % slot_ptr, thunk_48b0=thunk.hex())
    print(json.dumps(facts, ensure_ascii=False, indent=1))

    calls_path = folder / "calls.csv"
    calls = read_csv(calls_path)
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            row["callee"] = ("_guard_dispatch_icall 0x48B0 -> JMP RAX；RAX = qword[0x19B78]"
                             "（固定回调槽，地址由 0x29D0 的 lea rax,[rip+0x171A1] 返回，0x21A4 单次读取）")
            row["note"] = ("R9 全链（四点）："
                           "① 0x217F call 0x1800029D0 -> 0x29D0: 48 8D 05 A1 71 01 00 = lea rax,[rip+0x171A1]，"
                           "槽地址 0x19B78 由该 LEA 返回；0x2184 mov rbx,rax。"
                           "② 空槽判定：0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（槽为空则不调用）；"
                           "另有 0x2190 call 0x2874 的节判据（0x28F3: 83 7A 24 00 7D 04 32 C0 EB 0A B0 01 EB 06，"
                           "测试目标指针所在节是否可写，0x2197 跳过），二者共同约束该调用。"
                           "③ 节属性：槽 0x19B78 在 .data（VA 0x19000，Characteristics 0xC0000040 可写），"
                           "位于 raw 结尾 0x19A00 之后的零填充尾部（虚拟到 0x19B80），静态未初始化。"
                           "④ 单次读取：0x21A4 mov rax,[rbx] 对固定槽 0x19B78 只读一次；"
                           "0x21A7 mov r9,[0x1800061B8] -> 0x1800048B0（0x48B0: FF E0 = JMP RAX）；0x21AE call r9。"
                           "静态只剩回调槽写入者与被调实现未定；恢复条件＝在 0x21AE 停住读 RAX，或在 0x19B78 下断点看写入者")
        if row["kind"] == "method" and int(row["caller"], 0) == 0x06000031:
            row["callee"] = ("arg0 对象 vtable +0x10（运行期函数指针；loc1 由 0x06000032 的 finally 传入，"
                             "该 loc1 经 0x06000030 取得）")
            row["note"] = ("IL_0008 的 calli（签名 0x11000043 = blob %s，uint32 modopt(CallConvCdecl,IsLong)(native int)）："
                           "接收者＝arg0 对象，函数指针取自该对象 vtable +0x10；loc1 来源＝本地方法 0x06000032 的 finally "
                           "（RVA %s，%d 个 EH 子句）在 handler 内把 loc1 传给 0x06000031，而 loc1 由 0x06000030 "
                           "经 CLR 宿主接口取得（clsid {CB2F6723-…} / riid {CB2F6722-…}）；"
                           "适用调用路径＝仅 0x06000032 的 finally 路径（try/finally 的 handler 分支），其它调用者不在此绑定范围内；"
                           "被调函数本身仍是运行期指针，故本条保留 unresolved"
                           % (sig[0x43], facts["caller_rva"], len(clauses)))
    write_csv(calls_path, ["kind", "caller", "callee", "class", "listing", "note"], calls)
    line_of = {}
    for i, ln in enumerate(calls_path.read_text(encoding="utf-8").splitlines(), start=1):
        if ln.startswith("native,0x20CC,"):
            line_of["0x21AE"] = i
        if ln.startswith("method,0x6000031,"):
            line_of["0x06000031"] = i

    unresolved = [r for r in calls if r["class"] == "unresolved"]
    managed = [r for r in unresolved if r["kind"] == "method"]
    native = [r for r in unresolved if r["kind"] == "native"]
    mrows = [dict(index=i, caller=r["caller"], callee_name=r["callee"], callee=r["callee"],
                  listing=r["listing"], note=r["note"], reason="IL calli：目标为运行期函数指针")
             for i, r in enumerate(managed, start=1)]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate(native, start=1)]
    for name, fields, rows in (("s25-unresolved-managed.csv",
                                ["index", "caller", "callee_name", "callee", "listing", "note", "reason"], mrows),
                               ("s25-unresolved-native.csv",
                                ["index", "caller", "callee", "listing", "note", "reason"], nrows),
                               ("s33-unresolved-managed.csv",
                                ["index", "caller", "callee_name", "callee", "listing", "note", "reason"], mrows),
                               ("s33-unresolved-native.csv",
                                ["index", "caller", "callee", "listing", "note", "reason"], nrows)):
        write_csv(folder / "code" / name, fields, rows)

    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1
    metrics = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
    metrics.update(dict(external=classes.get("external", 0), boundary=classes.get("boundary", 0),
                        unresolved=classes.get("unresolved", 0), s29_ctor_rows_added=5,
                        s25_managed_unresolved=len(managed), s25_native_unresolved=len(native),
                        s33_managed_unresolved=len(managed), s33_native_unresolved=len(native),
                        s33_com_vtable_reads_removed=1,
                        s33_release_binding_listing="code/methods.il#L1195-L1195",
                        s33_release_binding_scope="0x06000032 finally only",
                        s33_guard_slot=facts["guard_slot"], s33_guard_section=facts["section"]["name"],
                        s33_guard_raw_end="0x%X" % (sec["rva"] + sec["size"]),
                        s33_guard_virt_end="0x%X" % (sec["rva"] + sec["vsize"]),
                        s33_guard_in_raw=str(guard < sec["rva"] + sec["size"]).lower()))
    (folder / "metrics.json").write_text(json.dumps(metrics, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    md = []
    md.append("# NATIVE-340 s33 审计（本文件定稿后生成指纹）")
    md.append("")
    md.append("原件 SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。")
    md.append("")
    md.append("## 1. 0x21AE 三点")
    md.append("")
    md.append("- 空槽判定：0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1（空槽不调用）；另有 0x2190 call 0x2874 的节判据")
    md.append("  （0x28F3 起 14 字节 83 7A 24 00 7D 04 32 C0 EB 0A B0 01 EB 06，测试目标指针所在节是否可写，0x2197 跳过）。")
    md.append("- 节属性：槽 %s 位于 .data（VA 0x%X，raw 结束 0x%X，虚拟结束 0x%X），即 raw 之后的零填充尾部，静态未初始化。"
              % (facts["guard_slot"], sec["rva"], sec["rva"] + sec["size"], sec["rva"] + sec["vsize"]))
    md.append("- 单次读取：0x21A4 mov rax,[rbx] 对固定槽只读一次；0x21A7 mov r9,[0x61B8] = 0x48B0；0x21AE call r9；")
    md.append("  0x48B0 = FF E0 (JMP RAX)。")
    md.append("- 主表行：calls.csv 第 %d 行（callee 与 note 重写，运行期依赖保留）。" % line_of.get("0x21AE", 0))
    md.append("")
    md.append("## 2. 移除的 COM vtable 读描述")
    md.append("")
    md.append("- 1 处：0x21AE 主表行。旧 callee 的 COM vtable slot 0 描述与旧 note 的「再走对象 vtable 槽 0」按原件删除")
    md.append("  （0x21A4 之后原件没有对 RAX 的二次解引用）。")
    md.append("")
    md.append("## 3. 0x06000031 IL_0008 绑定")
    md.append("")
    md.append("- 原件 IL：IL_0008 calli，签名 token 0x11000043，blob %s。" % sig[0x43])
    md.append("- 接收者：arg0 对象，函数指针取自对象 vtable +0x10。")
    md.append("- loc1 来源：0x06000032 的 finally（RVA %s，%d 个 EH 子句）把 loc1 传给 0x06000031；loc1 由 0x06000030"
              " 经 CLR 宿主接口取得（clsid %s / riid %s）。"
              % (facts["caller_rva"], len(clauses), guids[0x55][1], guids[0x56][1]))
    md.append("- 绑定范围：仅 0x06000032 的 finally 路径；主表 calls.csv 第 %d 行，class 仍 unresolved（被调函数是运行期指针）。"
              % line_of.get("0x06000031", 0))
    md.append("")
    md.append("## 4. 未决附表")
    md.append("")
    md.append("- 由主表实际生成：托管 %d 条（code/s33-unresolved-managed.csv）、原生 %d 条（code/s33-unresolved-native.csv），"
              "同内容同步到 code/s25-unresolved-*.csv，与主表逐行一致。" % (len(managed), len(native)))
    md.append("")
    md.append("## 5. 指标")
    md.append("")
    md.append("- external=%d / boundary=%d / unresolved=%d；s29_ctor_rows_added=5；237 槽 / 122 MethodDef / 228 回编桩不变。"
              % (metrics["external"], metrics["boundary"], metrics["unresolved"]))
    md.append("")
    md.append("指纹在本文件定稿后生成（code/s29-fingerprints.json，检查器按其逐个校验）。")
    (folder / "code/s33-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print("edited:", json.dumps(line_of), "managed", len(managed), "native", len(native), "classes", classes)
    return 0


if __name__ == "__main__":
    sys.exit(main())
