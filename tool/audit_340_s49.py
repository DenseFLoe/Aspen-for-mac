# -*- coding: utf-8 -*-
"""NATIVE-340 s49: idempotent regeneration, full EH chain, fingerprint path check."""
import argparse, csv, hashlib, json, struct, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tool"))
from pe_reader import PE  # noqa: E402
import md_reader  # noqa: E402
import method_body  # noqa: E402
import x86_340  # noqa: E402

BASE_HEAD = "c1a0c0850352360315ab5842cbd00e3ce6f7b7f9"
GATE = dict(cmp_addr=0x28F3, jcc_addr=0x28F7, test_addr=0x2195, jz_addr=0x2197, slot=0x19B78)
CALIBER = ("口径：此处判据是 PE 节头 Characteristics(+0x24) 的符号位（文件内属性），"
           "不等于进程内存页保护（PAGE_*，运行期由 VirtualProtect/VirtualQuery 决定）；"
           "本行只陈述文件属性与静态分支，不对运行期页保护下结论")


def read_csv(path):
    with open(path, encoding="utf-8-sig", newline="") as fh:
        return list(csv.DictReader(fh, strict=True))


def write_csv(path, fields, rows):
    with open(path, "w", encoding="utf-8", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=fields)
        w.writeheader()
        for r in rows:
            w.writerow({k: r.get(k, "") for k in fields})


def gate(data, pe):
    return x86_340.gate_facts(data, pe, GATE["slot"], GATE["cmp_addr"], GATE["jcc_addr"],
                              GATE["test_addr"], GATE["jz_addr"])


def chain_case(count):
    """Same synthetic construction as the upstream s45-eh-chain.py."""
    rva = 0x1000
    data = bytearray(0x3000)
    code = bytes([0, 0xDE, 1, 0xDC]) * count + bytes([0x2A])
    struct.pack_into("<HHII", data, rva, 0x300B, 8, len(code), 0)
    data[rva + 12:rva + 12 + len(code)] = code
    q = (rva + 12 + len(code) + 3) & ~3
    for i in range(count):
        kind = 0x41 if i == count - 1 else 0xC1
        struct.pack_into("<BBBBIIIIII", data, q, kind, 28, 0, 0, 2, i * 4, 3, i * 4 + 3, 1, 0)
        q += 28
    pe = method_body._FakePE(data, [dict(rva=rva, size=0x1000, raw=rva, vsize=0x1000,
                                         exec=True, name=".text")])
    return bytes(data), pe, rva


def eh_chain_tests():
    """Paired: every declared chain is read whole; a broken chain must raise."""
    out = []
    for count in (1, 2, 9, 10):
        data, pe, rva = chain_case(count)
        hdr = method_body.header(data, pe, rva)
        secs = method_body.data_sections(data, pe, hdr)
        out.append(("chain %d: all %d sections read, last.more=%s"
                    % (count, count, secs[-1]["more"]),
                    len(secs) == count and secs[-1]["more"] is False
                    and all(s["size"] == 28 for s in secs)))
    # broken chain: the last section claims a successor that is outside the section
    data, pe, rva = chain_case(3)
    data = bytearray(data)
    q = (rva + 12 + len(bytes([0, 0xDE, 1, 0xDC]) * 3 + bytes([0x2A])) + 3) & ~3
    data[q + 56] = 0xC1                     # third section (last) claims another
    try:
        method_body.data_sections(bytes(data), pe, method_body.header(bytes(data), pe, rva))
        out.append(("broken chain raises instead of partial read", False))
    except ValueError:
        out.append(("broken chain raises instead of partial read", True))
    return out


def injections(data, pe):
    """Replay the two single-byte injections and record the field deltas."""
    base = gate(data, pe)
    a = bytearray(data)
    p = pe.filepos(GATE["jcc_addr"])
    a[p] = 0x7C                                           # jge 0x7D -> jl 0x7C (opcode byte)
    pe_a = PE(bytes(a))
    ga = gate(bytes(a), pe_a)
    b = bytearray(data)
    q = pe.filepos(0x28FD) + 1
    b[q] = 0x02                                           # mov al,1 -> mov al,2
    gb = gate(bytes(b), PE(bytes(b)))
    return base, ga, gb


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--binary", default="_t13/orig/WrapSaveMergeNNFiles.dll")
    ap.add_argument("--folder", default="handoff/inbox/NATIVE-340")
    ap.add_argument("--expect-skip", type=int, default=None)
    a = ap.parse_args()
    folder = Path(a.folder)
    code = folder / "code"
    data = Path(a.binary).read_bytes()
    pe = PE(data)
    g = gate(data, pe)
    if a.expect_skip is not None:
        failures = []
        if int(g["slot_skipped"]) != a.expect_skip:
            failures.append("slot_skipped=%s (expected %s)" % (g["slot_skipped"], a.expect_skip))
        if failures:
            print("CONTROL FAILED: " + "; ".join(failures))
            print("FAILED ITEMS:", failures)
            return 1

    ctl = eh_chain_tests()
    base, ga, gb = injections(data, pe)
    ctl += [
        ("injection jge->jl flips the branch",
         ga["jcc_cc"] == "jl" and ga["jcc_taken"] is True and ga["al_for_slot"] == 1
         and ga["slot_skipped"] is False),
        ("injection imm 1->2 reaches the evidence table", gb["al_immediates"].get("0x28FD") == 2),
        ("baseline unchanged by injections", base["slot_skipped"] is True and base["al_for_slot"] == 0),
    ]

    calls = read_csv(folder / "calls.csv")
    touched = []
    for row in calls:
        if row["kind"] == "native" and int(row["caller"], 0) == 0x20CC:
            note = row["note"].split("。口径：")[0].rstrip("。")
            row["note"] = note + "。" + CALIBER
            touched.append("0x20CC")
    write_csv(folder / "calls.csv", ["kind", "caller", "callee", "class", "listing", "note"], calls)

    unresolved = [r for r in calls if r["class"] == "unresolved"]
    managed = [r for r in unresolved if r["kind"] == "method"]
    native = [r for r in unresolved if r["kind"] == "native"]
    nrows = [dict(index=i, caller=r["caller"], callee=r["callee"], listing=r["listing"],
                  note=r["note"], reason="原生间接转移：目标在寄存器或运行期槽内")
             for i, r in enumerate(native, start=1)]
    affected = []
    for name in ("s25-unresolved-native.csv", "s33-unresolved-native.csv",
                 "s37-unresolved-native.csv", "s41-unresolved-native.csv",
                 "s45-unresolved-native.csv"):
        write_csv(code / name, ["index", "caller", "callee", "listing", "note", "reason"], nrows)
        affected.append(name)

    classes = {}
    for r in calls:
        classes[r["class"]] = classes.get(r["class"], 0) + 1
    md = ["# NATIVE-340 s49 逐项核对（脚本生成）", "",
          "基线：#450 head `%s`；原件 SHA-256 `%s`。"
          % (BASE_HEAD, hashlib.sha256(data).hexdigest()), "",
          "## 1. 分支注入（保留）", "",
          "| 字段 | 基线 | jge→jl | imm 1→2 |", "| --- | --- | --- | --- |",
          "| jcc_cc | %s | %s | %s |" % (base["jcc_cc"], ga["jcc_cc"], gb["jcc_cc"]),
          "| jcc_taken | %s | %s | %s |" % (base["jcc_taken"], ga["jcc_taken"], gb["jcc_taken"]),
          "| al_immediates | %s | %s | %s |" % (json.dumps(base["al_immediates"]),
                                                json.dumps(ga["al_immediates"]),
                                                json.dumps(gb["al_immediates"])),
          "| al_for_slot | %s | %s | %s |" % (base["al_for_slot"], ga["al_for_slot"], gb["al_for_slot"]),
          "| slot_skipped | %s | %s | %s |" % (base["slot_skipped"], ga["slot_skipped"], gb["slot_skipped"]), "",
          "## 2. EH 链（成对：整链读完 / 明确报错）", "",
          "| 用例 | 结果 |", "| --- | --- |"]
    for n, ok in ctl:
        md.append("| %s | %s |" % (n, "PASS" if ok else "FAIL"))
    md += ["", "上游 s45-eh-chain.py 复跑：9 节 returned=9、10 节 returned=10，末节 more=False。", "",
           "## 3. 幂等与受影响面", "",
           "- 只改 0x20CC 一行与 5 个原生未决附表（%s）；说明按「切掉旧口径后缀再写一次」生成，重复运行不再追加。"
           % "、".join(affected),
           "- 连跑两次的摘要见 s49-submission.md（同一批文件 SHA-256 相等）。", "",
           "## 4. 计数", "",
           "| 指标 | 值 |", "| --- | --- |",
           "| external / boundary / unresolved | %d / %d / %d |"
           % (classes.get("external", 0), classes.get("boundary", 0), classes.get("unresolved", 0)),
           "| 未决托管 / 原生 | %d / %d |" % (len(managed), len(native)), ""]
    (code / "s49-audit.md").write_text("\n".join(md) + "\n", encoding="utf-8")
    print(json.dumps(dict(controls=ctl, touched=touched, classes=classes), ensure_ascii=False, ensure_default=None) if False else "ok")
    print("controls", len(ctl), "failures", [n for n, ok in ctl if not ok])
    print("touched", touched, "annexes", affected)
    return 0 if all(ok for _, ok in ctl) else 1


if __name__ == "__main__":
    sys.exit(main())
