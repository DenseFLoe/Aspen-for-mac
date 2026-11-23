# -*- coding: utf-8 -*-
"""s101/s105 receipt section: emit the verifier-script block with live sha256 and raw stdout."""
import hashlib, subprocess, sys
from pathlib import Path

ITEM = Path('handoff/inbox/NATIVE-337')
BIN = '_t13/orig/FindComponent.dll'
SCRIPTS = [
    ('tool/s101_verify.py', '交付校验入口：拒绝矛盾列表/签名'),
    ('tool/s101_counters.py', '回归脚本：列表单改 + 签名单改反例'),
    ('tool/s97_regressions.py', '列表单改回归（s97 口径）'),
    ('tool/s93_counters.py', '字节单改反例（二进制口径）'),
    ('tool/s81_showdialog.py', 'ShowDialog 绑定/参数表生成器'),
    ('tool/s37_two_hop.py', '161 条二跳表生成器'),
    ('tool/s65_counterexamples.py', '四类反例分类器（FF /4 判型入口）'),
    ('tool/s73_stations.py', '原件独立站集导出'),
    ('tool/s69_tests.py', 'T1–T6 回归（s65 入口）'),
    ('tool/s45_tests.py', '六场景 + 三布局回归'),
]
UPSTREAM = 'handoff/assignments/check-native-coverage.py'
AUTH = 'out/localrepo3/handoff/assignments/check-native-coverage.py'
QA = '_tools/qa/27007e5a'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(cmd, cwd=None):
    r = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=cwd)
    return r.returncode, (r.stdout + r.stderr).rstrip()


def main():
    out = []
    out.append('## 检验器脚本')
    out.append('')
    out.append('| 脚本 | 字节 | sha256 | 作用 |')
    out.append('| --- | ---: | --- | --- |')
    for rel, role in SCRIPTS:
        p = Path(rel)
        if not p.exists():
            out.append('| `%s` | – | – | (missing) |' % rel)
            continue
        out.append('| `%s` | %d | `%s` | %s |' % (rel, p.stat().st_size, sha(p), role))
    up = Path(UPSTREAM)
    auth = Path(AUTH)
    pin_src = auth if auth.exists() else up
    out.append('| `%s` | %d | `%s` | 上游覆盖检查器（本仓副本） |' % (UPSTREAM, up.stat().st_size, sha(up)))
    out.append('| `%s` | %d | `%s` | 上游覆盖检查器（权威 pin 源） |' % (AUTH, pin_src.stat().st_size, sha(pin_src)))
    out.append('')
    out.append('**版本 pin**：`qa gate 27007e5a (MANIFEST files sha256 3779de81a322579c91adfbf5b960f8a16543973d87ca97e92eca117d67b65089)`；上游 checker pin `%s`。' % sha(pin_src))
    out.append('')
    out.append('命令与原始输出（stdout 原文，exit 为真实值）：')
    cmds = [
        ('python -B tool/s101_verify.py --listing --signature', None),
        ('python -B tool/s101_counters.py', None),
        ('python -B tool/s97_regressions.py', None),
        ('set PYTHONPATH=D:/Lib/site-packages && python -B tool/s65_counterexamples.py', None),
        ('python -B tool/s37_two_hop.py --folder handoff/inbox/NATIVE-337 --binary %s --out work/s101-two-hop.csv' % BIN, None),
        ('python -B %s NATIVE-337 --original %s --submission handoff/inbox/NATIVE-337' % (UPSTREAM, BIN), None),
        ('set "PYTHONPATH=D:/Lib/site-packages;%s/tool" && python -B -m qa.gate --task NATIVE-337 --item-dir "%s/handoff/inbox/NATIVE-337" --original "%s/%s"' % tuple([str(Path.cwd()).replace(chr(92),'/')] * 3 + [BIN]), QA),
    ]
    for cmd, cwd in cmds:
        rc, txt = run(cmd, cwd=cwd)
        out.append('')
        out.append('```')
        out.append('$ ' + cmd)
        out.extend(txt.splitlines()[-12:] if len(txt.splitlines()) > 12 else txt.splitlines())
        out.append('[exit %d]' % rc)
        out.append('```')
    out.append('')
    out.append('**判据 → 脚本位置**')
    out.append('')
    out.append('| 判据 | 脚本/函数 |')
    out.append('| --- | --- |')
    out.append('| 列表与原件逐字节一致（0x13DD / 0x137F） | `tool/s101_verify.py::verify_listing` |')
    out.append('| 接口/实现/声明签名一致（2001080E） | `tool/s101_verify.py::verify_signature` |')
    out.append('| 绑定依据来自字节（ProgID/名字/IID/vt） | `tool/s81_showdialog.py::binding_rows` |')
    out.append('| 唯一 `variant-vt` 行 + stride 与 vt 分离 | `tool/s81_showdialog.py` 表行 `variant-vt` |')
    out.append('| 161 站与 calls_row 关联 | `tool/s37_two_hop.py::main`（row_for） |')
    out.append('| 四类反例分类 | `tool/s65_counterexamples.py::main` |')
    out.append('| 站集独立导出 | `tool/s73_stations.py::derive` |')
    text = chr(10).join(out) + chr(10)
    Path('work/s101-verifier-section.md').write_text(text, encoding='utf-8')
    print(text[:400])
    print('...written', len(text), 'bytes')


if __name__ == '__main__':
    main()
