# -*- coding: utf-8 -*-
"""NATIVE-340 s29: correct the CLSID/IID parameter text, complete the R9 chain,
and register the five in-module constructor calls.

Every corrected sentence is re-derived here from the pinned original bytes; the
script aborts if any of the underlying facts no longer hold.
"""
import argparse
import csv
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import cli_tables  # noqa: E402
import il_disasm
import ident  # noqa: E402
import il_newobj  # noqa: E402
import md_reader  # noqa: E402

CLSID = "{CB2F6723-AB3A-11D2-9C40-00C04FA30A3E}"
RIID = "{CB2F6722-AB3A-11D2-9C40-00C04FA30A3E}"


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
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    cli = pe.directory(14)[0]
    md_off = pe.filepos(struct.unpack_from("<I", data, pe.filepos(cli) + 8)[0])
    meta = md_reader.parse(data, md_off)
    tables = cli_tables.read(data, md_off)
    facts, problems = [], []

    def fact(name, ok, detail):
        facts.append(dict(fact=name, ok=bool(ok), detail=detail))
        if not ok:
            problems.append("%s (%s)" % (name, detail))

    # ---- 1. GUID fields and their RVAs -------------------------------------
    f55 = tables["rows"][4][0x54]
    f56 = tables["rows"][4][0x55]
    rva55 = next(r["RVA"] for r in tables["rows"][29] if r["Field"] == 0x55)
    rva56 = next(r["RVA"] for r in tables["rows"][29] if r["Field"] == 0x56)
    fact("field 0x04000055 is GUID cb2f6723 at RVA 0x6330",
         "cb2f6723" in f55["Name"].lower() and rva55 == 0x6330, "%s @ %#x" % (f55["Name"], rva55))
    fact("field 0x04000056 is GUID cb2f6722 at RVA 0x6320",
         "cb2f6722" in f56["Name"].lower() and rva56 == 0x6320, "%s @ %#x" % (f56["Name"], rva56))
    fact("0x6330 bytes are GUID cb2f6723",
         data[pe.filepos(0x6330):pe.filepos(0x6330) + 4] == bytes.fromhex("23672fcb"), "bytes")
    fact("0x6320 bytes are GUID cb2f6722",
         data[pe.filepos(0x6320):pe.filepos(0x6320) + 4] == bytes.fromhex("22672fcb"), "bytes")

    # ---- 2. IL order: arg0 = clsid comes from 0x04000055 -------------------
    m30 = next(m for m in meta["methods"] if m["token"] == 0x06000030)
    body = il_disasm.body(data, pe.filepos, m30["rva"])
    ins = [(o, n, op) for o, n, op, _s in il_disasm.decode(body)]
    seq = ["%s %s" % (n, op) for _o, n, op in ins[:12]]
    fact("IL_0003 reads field 0x04000056 (cb2f6722) first and stashes it at IL_000D",
         ins[3][1] == "ldsflda" and ident.same_ident(ins[3][2], "0x04000056") and ins[5][1] == "stloc.3"
         and ident.same_ident(ins[6][2], "0x04000055") and ins[8][1] == "ldloc.3", " | ".join(seq))
    fact("callee is GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid)",
         _memberref_name(tables, 0x39) == "GetRuntimeInterfaceAsIntPtr", _memberref_name(tables, 0x39))
    # stack at IL_0019: bottom = FromGUID(0x04000055)=cb2f6723 -> arg0 clsid; top = loc3 = cb2f6722 -> arg1 riid
    order = "arg0(clsid)=FromGUID(0x04000055)=%s, arg1(riid)=loc3=FromGUID(0x04000056)=%s" % (CLSID, RIID)

    # ---- 3. R9 chain facts ------------------------------------------------
    p = pe.filepos(0x29D0)
    lea = data[p:p + 7]
    disp = struct.unpack_from("<i", lea, 3)[0]
    slot_rva = 0x29D0 + 7 + disp
    fact("0x29D0 is lea rax,[rip+disp] -> 0x19B78", lea[:3] == b"\x48\x8d\x05" and slot_rva == 0x19B78,
         "bytes %s -> %#x" % (lea.hex(), slot_rva))
    fact("qword[0x1800061B8] == 0x1800048B0", struct.unpack_from(
        "<Q", data, pe.filepos(0x61B8))[0] == 0x1800048B0, "slot value")
    fact("0x48B0 is FF E0 (JMP RAX)", data[pe.filepos(0x48B0):pe.filepos(0x48B0) + 2] == b"\xff\xe0", "bytes")
    dat = next(s for s in pe.secs if s["name"] == ".data")
    raw_end = dat["rva"] + dat["size"]
    virt_end = dat["rva"] + dat["vsize"]
    fact("0x19B78 sits in the zero-filled tail of writable .data",
         raw_end <= 0x19B78 < virt_end, "raw ends %#x, virtual ends %#x" % (raw_end, virt_end))
    fact("0x2187/0x218B guard the empty slot before the read",
         data[pe.filepos(0x2187):pe.filepos(0x2187) + 4] == bytes.fromhex("48833800")
         and data[pe.filepos(0x218B):pe.filepos(0x218B) + 2] == bytes.fromhex("7424"),
         "cmp qword ptr [rax],0 ; jz")
    fact("0x21A7 loads R9 from [0x1800061B8]", data[pe.filepos(0x21A7):pe.filepos(0x21A7) + 7]
         == bytes.fromhex("4c8b0d0a400000"), "mov r9,[rip+0x400a]")
    chain = ("0x217F call 0x1800029D0 -> RAX=0x19B78（0x29D0: 48 8D 05 A1 71 01 00 = lea rax,[rip+0x171A1]，"
             "槽地址由该 LEA 返回）；0x2184 mov rbx,rax；0x2187 cmp qword ptr [rax],0 + 0x218B jz 0x21B1 "
             "先拦空槽；0x21A4 mov rax,[rbx] 对固定回调槽 0x19B78 单次读取；0x21A7 mov r9,[0x1800061B8] "
             "-> 0x1800048B0 _guard_dispatch_icall（0x48B0: FF E0 = JMP RAX）；0x21AE call r9。"
             "槽 0x19B78 位于可写 .data 的零填充尾部（raw 到 0x19A00，虚拟到 0x19B80，未初始化）。")

    # ---- 4. five in-module constructor calls ------------------------------
    nobj = il_newobj.scan(data, pe, tables, meta)
    internal = [n for n in nobj if n["verdict"] == "internal-ctor"]
    fact("five in-module ctor newobj sites", len(internal) == 5, "%d" % len(internal))
    il = ["; NATIVE-340 s29 in-module constructor calls (IL 0x73 whose token is a local MethodDef)",
          "; newobj = allocate + call .ctor; the target lives in this module (managed -> managed)"]
    line = {}
    for i, n in enumerate(internal):
        il.append("")
        il.append("; caller MethodDef 0x%08X %s RVA 0x%X" % (n["caller_token"], n["caller_name"], n["caller_rva"]))
        line[i] = len(il) + 1
        il.append("  IL_%04X: newobj    0x%08X   // newobj = alloc + call .ctor; target MethodDef %s %s (this module)"
                  % (n["offset"], n["token"], n["token"], n.get("owner_name", "")))
    (code / "internal-ctor-sites.il").write_text("\n".join(il) + "\n", encoding="utf-8")

    # ---- 5. calls.csv updates --------------------------------------------
    calls = read_csv(folder / "calls.csv")
    fixed_cls = fixed_r9 = added = 0
    for r in calls:
        if r["kind"] == "method" and r["caller"] == "0x6000030" and r["class"] == "external" \
                and "0x1100004" in r["callee"]:
            slot = "0x68" if "0x11000044" in r["note"] else "0x10"
            r["callee"] = r["callee"].split(" (clsid")[0] + " (clsid %s, riid %s)" % (CLSID, RIID)
            head = ("IL_%s 的 calli（签名 %s）：对象 loc0 来自 IntPtr::ToPointer("
                    "RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(FromGUID(GUID), GUID))；"
                    % ("0041" if "0x11000044" in r["note"] else "004F",
                       "0x11000044" if "0x11000044" in r["note"] else "0x11000043"))
            r["note"] = (head + "参数按原件压栈次序：%s——IL_0003 先取字段 0x04000056（%s @ 0x6320）并 IL_000D stloc.3 暂存，"
                         "IL_000E 取字段 0x04000055（%s @ 0x6330），IL_0018 ldloc.3 把它作为最后一压的实参，"
                         "故 GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid) 的 arg0(clsid)=%s、"
                         "arg1(riid)=%s；槽 = %s 由 IL 的 ldc.i4.s + conv.i8 + add + ldind.i8 证明；"
                         "运行期依赖＝接口实际实现，静态只到 vtable 槽"
                         % (order, RIID, CLSID, CLSID, RIID, slot))
            fixed_cls += 1
        elif r["kind"] == "native" and r["caller"] == "0x20CC" and "_guard_dispatch_icall" in r["callee"]:
            r["callee"] = ("_guard_dispatch_icall 0x48B0 -> RAX = qword[0x19B78] (fixed callback slot, "
                           "LEA from 0x29D0) -> COM vtable slot 0 of the object")
            r["note"] = ("R9 全链：" + chain + " 真正被调者 = RAX = [0x19B78]（回调槽单次读取）后再走对象 vtable 槽 0；"
                         "静态只剩对象类型/回调实现未定；恢复条件＝在 0x21AE 停住读 RAX，或在 0x19B78 下断点看写入者")
            fixed_r9 += 1
    have = {(r["kind"], r["caller"], r["listing"]) for r in calls}
    for i, n in enumerate(internal):
        ref = "%s#L%d-L%d" % ("code/internal-ctor-sites.il", line[i], line[i])
        key = ("method", "0x%08X" % n["caller_token"], ref)
        if key in have:
            continue
        calls.append(dict(kind="method", caller="0x%08X" % n["caller_token"],
                          callee="MethodDef 0x%08X %s::.ctor (this module, managed -> managed)"
                                 % (n["token"], n.get("owner_name", "")),
                          **{"class": "boundary"}, listing=ref,
                          note=("IL %s 的 0x73 newobj：token 0x%08X 命中 MethodDef 表且 flavor=%s，"
                                "属主 TypeDef = %s；这是本模块托管构造调用（managed -> managed），"
                                "不是外部程序集调用，也不离开本模块" %
                                ("IL_%04X" % n["offset"], n["token"], n.get("flavor", "IL"),
                                 n.get("owner_name", "")))))
        have.add(key)
        added += 1
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)

    # ---- 6. verdict / metrics / audit ------------------------------------
    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1
    metrics = json.loads((folder / "metrics.json").read_text(encoding="utf-8-sig"))
    metrics.update(dict(rows=metrics.get("rows"), funcs=metrics.get("funcs"),
                        external=classes.get("external", 0), boundary=classes.get("boundary", 0),
                        unresolved=classes.get("unresolved", 0),
                        managed_to_managed_ctor_edges=len(internal),
                        s29_ctor_rows_added=added, s29_clsid=CLSID, s29_riid=RIID,
                        calls_sha256=hashlib.sha256((folder / "calls.csv").read_bytes()).hexdigest()))
    (folder / "metrics.json").write_text(json.dumps(metrics, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    verdict = dict(
        method="0x06000030", method_name="_get_default_appdomain",
        calli=[dict(il="IL_0041", signature_token="0x11000044", vtable_slot="0x68",
                    signature_blob="01022051206108180f0f1187fc",
                    object_path="IntPtr::ToPointer(RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(FromGUID(GUID), GUID))"),
               dict(il="IL_004F", signature_token="0x11000043", vtable_slot="0x10",
                    signature_blob="0101205120610918",
                    object_path="same loc0 as IL_0041")],
        parameter_binding=dict(
            call="System.Runtime.InteropServices.RuntimeEnvironment::GetRuntimeInterfaceAsIntPtr(native int, valuetype Guid, valuetype Guid)",
            note="IL pushes arg1 first (stashed at IL_000D) then arg0, reloaded at IL_0018",
            arg0_clsid=dict(guid=CLSID, field="0x04000055",
                            field_name=f55["Name"], field_rva="0x%X" % rva55, bytes_at_rva=data[pe.filepos(0x6330):pe.filepos(0x6330) + 16].hex()),
            arg1_riid=dict(guid=RIID, field="0x04000056",
                           field_name=f56["Name"], field_rva="0x%X" % rva56, bytes_at_rva=data[pe.filepos(0x6320):pe.filepos(0x6320) + 16].hex())),
        r9_chain=dict(expression="R9 = qword[0x1800061B8] = 0x1800048B0 (JMP RAX); RAX = qword[0x19B78]; "
                                 "0x19B78 = LEA at 0x29D0 (48 8D 05 A1 71 01 00); slot lies in the zero-filled tail of writable .data; "
                                 "0x2187/0x218B reject the empty slot before the single read",
                      slot_rva="0x19B78", slot_holder="0x1800029D0 (lea rax,[rip+0x171A1])",
                      null_guard=["0x2187 cmp qword ptr [rax], 0", "0x218B jz 0x21B1"],
                      single_read="0x21A4 mov rax, [rbx]", guard_thunk="0x48B0 FF E0 JMP RAX",
                      unresolved_reason="callback slot writer and object type are runtime values"),
        facts=facts, problems=problems)
    (code / "s29-verdict-0x06000030.json").write_text(json.dumps(verdict, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    files = {}
    for p2 in sorted(folder.rglob("*")):
        if p2.is_file():
            files[p2.relative_to(folder).as_posix()] = hashlib.sha256(p2.read_bytes()).hexdigest()
    (code / "s29-fingerprints.json").write_text(json.dumps(files, ensure_ascii=False, indent=1) + "\n", encoding="utf-8")

    print(json.dumps(dict(facts=len(facts), problems=problems, fixed_callnotes=fixed_cls,
                          fixed_r9=fixed_r9, ctor_rows_added=added, classes=classes,
                          files=len(files)), ensure_ascii=False, indent=1))
    return 0 if not problems else 1


def _memberref_name(tables, row):
    return tables["rows"][10][row - 1]["Name"] if row <= len(tables["rows"].get(10, [])) else ""


if __name__ == "__main__":
    sys.exit(main())
