# -*- coding: utf-8 -*-
"""Generate the verifier-script section from the head tree (not local files)."""
import argparse, base64, hashlib, subprocess, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
sys.path.insert(0, str(ROOT / "tool"))
FENCE = chr(96) * 3

SCRIPTS = [
    ("tool/cli_tables.py", "解析（read 调 layout_for，ImplMap 1 位）"),
    ("tool/s101_width_fixtures.py", "夹具 A/B/C/D + 双负向"),
    ("tool/s101_layout_check.py", "1c/1d 逐键比对"),
    ("tool/s101_layout_baseline.py", "基线重生成"),
    ("tool/s93-width-controls.py", "列宽 + 紧邻列控制"),
    ("tool/s97-site-owners.py", "站点归属 + 正反例"),
    ("tool/s105-site-evidence.py", "站点四样比对（字节/位移/符号/半开区间）"),
    ("tool/verify_il_digests.py", "167 条 IL 摘要只读复验"),
]
RUNS = [
    ("python -B tool/s101_width_fixtures.py", "夹具与双负向"),
    ("python -B tool/s101_layout_check.py", "1c/1d 逐键（1d 唯一差异已解释）"),
    ("python -B tool/s97-site-owners.py .", "站点归属"),
    ("python -B tool/verify_il_digests.py --binary _t13/orig/WrapSaveMergeNNFiles.dll "
     "--table handoff/inbox/NATIVE-340/code/s89-il-digests.csv", "167 条摘要"),
]
GATE = ("cd _t14/qa/93bf962c && set PYTHONPATH=%CD%/../../.local/pylibs && python -B -m qa.gate "
        "--task NATIVE-340 --item-dir %CD%/../../handoff/inbox/NATIVE-340 "
        "--original %CD%/../../_t13/orig/WrapSaveMergeNNFiles.dll")


def tree_map(head):
    import gh
    tree = gh.call("GET", "/repos/%s/git/trees/%s?recursive=1" % (gh.REPO, head))
    want = {path for path, _ in SCRIPTS}
    out = {}
    for t in tree["tree"]:
        if t["type"] != "blob" or t["path"] not in want:
            continue
        bl = gh.call("GET", "/repos/%s/git/blobs/%s" % (gh.REPO, t["sha"]))
        raw = base64.b64decode(bl["content"])
        out[t["path"]] = (len(raw), hashlib.sha256(raw).hexdigest())
    return out


def run(cmd):
    p = subprocess.run(cmd, shell=True, cwd=str(ROOT), capture_output=True, text=True,
                       encoding="utf-8", errors="replace")
    return ((p.stdout or "") + (p.stderr or "")).strip(), p.returncode


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--head", required=True)
    ap.add_argument("--receipt", default="handoff/inbox/NATIVE-340/s101-submission.md")
    a = ap.parse_args()
    tm = tree_map(a.head)
    lines = ["## 检验器脚本", "", "| 脚本 | 字节 | sha256 | 用途 |", "| --- | ---: | --- | --- |"]
    local_only = []
    for path, use in SCRIPTS:
        if path in tm:
            size, sha = tm[path]
            lines.append("| %s | %s B | %s | %s |" % (path, format(size, ","), sha, use))
        else:
            local_only.append((path, use))
    if local_only:
        lines += ["", "### 本地未入库（不参与判据）", ""]
        for path, use in local_only:
            lines.append("- %s：%s" % (path, use))
    lines += ["", "运行命令（Windows 可直接复制，仓库根执行）：", "", FENCE]
    lines += [c for c, _ in RUNS] + [GATE]
    lines += [FENCE, "", "原始输出与真实 exit：", "", FENCE]
    for cmd, _ in RUNS:
        out, rc = run(cmd)
        lines.append("> " + cmd)
        lines += [l for l in out.splitlines() if l.strip()]
        lines.append("exit %d" % rc)
        lines.append("")
    out, rc = run(GATE)
    lines += [l for l in out.splitlines() if l.strip()][-40:]
    lines.append("exit %d" % rc)
    lines += [FENCE, "", "判据映射：", "", "| 判据 | 脚本位置 |", "| --- | --- |",
              "| 夹具 A/B/C/D 两列逐格 | tool/s101_width_fixtures.py main() 的 cases |",
              "| 破坏取宽必非零 | 同文件 ct.coded_width = lambda *a: 2 段 |",
              "| read == layout_for | tool/s101_layout_check.py 的 keyed() 1c 段 |",
              "| 新版 == 基线 | 同文件 1d 段（按键名比对） |",
              "| 站点/owner/listing | tool/s97-site-owners.py 的 site 比较 |",
              "| 167 条摘要 | tool/verify_il_digests.py 的 truth/bad |", "",
              "版本 pin：qa gate 93bf962c (MANIFEST files sha256 "
              "0f8be7a96e6dfa528116f28663d182b83ae60481896e1796975d27a398394c81)。", ""]
    section = "\n".join(lines)
    p = Path(a.receipt)
    t = p.read_text(encoding="utf-8")
    body = t.split("## 检验器脚本")[0].rstrip()
    body = body.replace("本轮 head：见 #13", "本轮 head：%s" % a.head)
    p.write_text(body + "\n\n" + section, encoding="utf-8")
    print("section bytes", len(section), "local_only", len(local_only))


if __name__ == "__main__":
    sys.exit(main())
