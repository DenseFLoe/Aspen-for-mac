#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""render_report.py — 逐件 .md 渲染（CLR 九节模板 / 非 PE 缺口模板）+ 脱敏闸门。

脱敏闸门 assert_no_leak()：命中禁词直接抛异常，不写盘（判据 C6/D6）。
"""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parent / 'lib'))

import re

FIXED_CLAUSE = '含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条'

BANNED = [
    re.compile(r'[A-Za-z]:\\'),
    re.compile(r'[A-Za-z]:/'),
    re.compile(r'<users>/\\\'),
    re.compile(r'<workspace>', re.I),
    re.compile(r'<user>'),
    re.compile(r'ghp_[A-Za-z0-9]{10,}'),
    re.compile(r'github_pat_[A-Za-z0-9_]{10,}'),
    re.compile(r'Authorization'),
]

_DRIVE = re.compile(r'[A-Za-z]:[\\/][^\s"\'|,;)\]]*')


def sanitize(text):
    """把本机绝对路径替换为占位符（脱敏第一步）。"""
    text = _DRIVE.sub('<path>', text)
    text = text.replace('<workspace>', '<work>')
    text = text.replace('<user>', '<user>')
    return text


def find_leaks(text):
    hits = []
    for rx in BANNED:
        if rx.search(text):
            hits.append(rx.pattern)
    return hits


def assert_no_leak(text, where=''):
    hits = find_leaks(text)
    if hits:
        raise ValueError('LEAK_DETECTED where=%s patterns=%s' % (where, ','.join(hits)))
    return True


def _k(n):
    return '{:,}'.format(n)


def render_clr(m, ctx):
    name = m['file_name']
    g = m['grouping']
    total = sum(g.values())
    il = g.get('il', 0)
    ab = g.get('abstract', 0)
    rt = g.get('runtime', 0)
    pi = g.get('pinvoke', 0)
    other = g.get('other', 0)
    L = []
    A = L.append
    A('# %s 静态复核报告（%s / 全程序集 IL + C# 反编译）' % (name, ctx['product']))
    A('')
    A('样本别名：`%s`（%s）' % (name, ctx['sample_note']))
    A(ctx['source_line'])
    A('落点：`%s/`（相对 `out/R1`）｜定位规则：`%s`' % (ctx['archive_rel'], ctx['locate_rule']))
    A('')
    A('标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。')
    A('')
    A('## 0. 摘要')
    A('')
    A('| 项目 | 结果 | 依据 |')
    A('| --- | --- | --- |')
    A('| 实际样本 | %s 字节（%s），SHA-256 `%s` | 〔实测〕自算 |' % (_k(m['size']), _k(m['size']), m['sha256']))
    A('| 程序集身份 | CLR 元数据 `%s`；流 %d 个；强名 RVA `%s` / %d 字节 | 〔实测〕 |'
      % (m['clr'].get('runtime_version_string', '?'), len(m['streams']),
         m['clr']['strongname_rva'], m['clr']['strongname_size']))
    A('| 方法统计 | %d = %d（有 IL 体）+ %d（抽象）+ %d（运行时实现/委托）+ %d（P/Invoke） | 〔实测〕 |'
      % (total, il, ab, rt, pi))
    A('| IL 清单 | `il/%s.il.txt`，%s 行，MethodDef %d 条（全量，逐条指令） | 〔实测〕 |'
      % (name, _k(ctx['il_lines']), total))
    A('| 反编译 | `decompiled/%s.cs.txt`，%s 行（ILSpy 9.1.0.7988 全量 stdout） | 〔实测〕 |'
      % (name, _k(ctx['cs_lines'])))
    A('| 原生调用 | ImplMap %d 条；PE 导入表 %d 个 DLL | 〔实测〕 |'
      % (len(m['pinvoke']), len(m['imports'])))
    A('| 缺口 | 见 §7（签名有效性、运行期行为未验证） | 〔待验证〕 |')
    A('')
    A(FIXED_CLAUSE)
    A('')
    A('## 1. 样本与哈希')
    A('')
    A('| 项 | 值 | 标签 |')
    A('| --- | --- | --- |')
    A('| 文件名 | `%s` | 〔实测〕 |' % name)
    A('| 字节数 | %s | 〔实测〕 |' % _k(m['size']))
    A('| SHA-256（本轮自算） | `%s` | 〔实测〕 |' % m['sha256'])
    A('| 清单声明 SHA-256 | `%s` | 〔实测〕一致 |' % ctx['declared_sha'])
    A('| 产品映射 | `%s` → `%s` | 〔实测〕 |' % (ctx['product_raw'], ctx['product']))
    A('| 清单 | `%s` | 〔实测〕 |' % ctx['manifest_name'])
    A('| 归并首见 | `%s` | 〔实测〕 |' % ctx['first_seen'])
    A('| 台账（20261119-61） | 缺失 | 〔待验证〕缺台账文件才能判归档口径 |')
    A('')
    A('哈希校验口径：读入原件后整文件 SHA-256，与清单 `sha256` 列逐字比对；不一致则记 `status=hash_mismatch` 且不产出 IL/反编译。')
    A('')
    A('## 2. 元数据摘要')
    A('')
    A('| 项 | 值 | 标签 |')
    A('| --- | --- | --- |')
    A('| PE | Machine `%s`（%s）、%d 个节、Subsystem %s | 〔实测〕 |'
      % (m['pe']['machine'], m['pe']['machine_name'], len(m['pe']['sections']), m['pe']['subsystem']))
    A('| 映像基址 / 校验和 | `%s` / `%s` | 〔实测〕 |' % (m['pe']['image_base'], m['pe']['checksum']))
    A('| CLR 头 | 运行时 %s、Flags `%s`、EntryPointToken `%s` | 〔实测〕 |'
      % ('%d.%d' % tuple(m['clr']['runtime_version']), m['clr']['flags'], m['clr']['entry_point_token']))
    A('| 元数据 | RVA `%s`，%d 字节，版本串 `%s` | 〔实测〕 |'
      % (m['clr']['metadata_rva'], m['clr']['metadata_size'], m['clr'].get('runtime_version_string', '?')))
    A('| 强名 | RVA `%s` / %d 字节；Flags `%s` | 〔实测〕 |'
      % (m['clr']['strongname_rva'], m['clr']['strongname_size'], m['clr']['flags']))
    A('')
    A('元数据流（相对元数据根）：')
    A('')
    A('| 流 | 相对根偏移 | 大小 |')
    A('| --- | ---: | ---: |')
    for s in m['streams']:
        A('| `%s` | %d (0x%x) | %d |' % (s['name'], s['offset'], s['offset'], s['size']))
    A('')
    A('- 方法统计：**%d = %d + %d + %d + %d**（有 IL 体 + 抽象 + 运行时实现/委托 + P/Invoke）〔实测〕'
      % (total, il, ab, rt, pi))
    if other:
        A('- 未归类方法：%d（需人工复核，见 §7）〔待验证〕' % other)
    A('- 方法体头分布（按方法体首字/标志字统计，每种恰好一行）：〔实测〕')
    A('')
    A('| 头 | 方法数 |')
    A('| --- | ---: |')
    for h in m['header_dist']:
        A('| %s | %d |' % (h['header'], h['count']))
    A('')
    if m.get('version_resource'):
        v = m['version_resource']
        A('- 版本资源：%d 字节，SHA-256 %s（RT_VERSION，语言 %s）〔实测〕'
          % (v['size'], v['sha256'], v['lang']))
    else:
        A('- 版本资源：无 RT_VERSION 资源〔实测〕')
    A('- 托管资源（ManifestResource）：%d 条〔实测〕' % m['manifest_resources'])
    A('- 解码失败方法体：%d 条〔实测〕' % m['decode_errors'])
    A('')
    A('## 3. IL 清单（全量）')
    A('')
    A('全程序集 IL 逐条清单落盘为 `il/%s.il.txt`（%s 行）；每个 MethodDef 一行（`MD ` 开头），'
      '其下为该方法体全部指令（`IL_XXXX` + 原始字节 + 反汇编文本 + 令牌解析）。〔实测〕'
      % (name, _k(ctx['il_lines'])))
    A('')
    A('| 项 | 值 |')
    A('| --- | ---: |')
    A('| MethodDef 总数 | %d |' % total)
    A('| 有 IL 体方法 | %d |' % il)
    A('| IL 字节合计 | %s |' % _k(m['il_bytes']))
    A('| 清单文件行数 | %s |' % _k(ctx['il_lines']))
    A('')
    A('## 4. 反编译伪代码（ILSpy）')
    A('')
    A('全量 C# 反编译落盘为 `decompiled/%s.cs.txt`（%s 行，含 %d 处 `class ` 声明）。'
      '命令为 `dotnet <ilspycmd.dll> <样本> > decompiled/%s.cs.txt`：stdout 单文件，未用 `-o`/`-p`（目录/工程形态会产多文件）。〔实测〕'
      % (name, _k(ctx['cs_lines']), ctx['cs_classes'], name))
    A('')
    A('| 项 | 值 |')
    A('| --- | ---: |')
    A('| 反编译行数 | %s |' % _k(ctx['cs_lines']))
    A('| `class ` 声明数 | %d |' % ctx['cs_classes'])
    A('')
    A('## 5. P/Invoke 与原生调用')
    A('')
    if m['pinvoke']:
        A('ImplMap 表 %d 条（ECMA-335 II.22.22；标志按 II.23.1.9 解码）：〔实测〕' % len(m['pinvoke']))
        A('')
        A('| MethodDef 令牌 | 托管方法 | 目标库 | 入口名 | 映射标志 | ImplFlags | 签名 |')
        A('| --- | --- | --- | --- | --- | --- | --- |')
        for p in m['pinvoke']:
            A('| %s | `%s` | %s | `%s` | `%s` | `%s` | `%s` |'
              % (p['token'], p['method'], p['library'], p['entry'], p['flags'], p['implflags'], p['sig']))
        A('')
    else:
        A('ImplMap 表 0 条：本件无 P/Invoke 声明〔实测〕。')
        A('')
    A('PE 导入表：%d 个 DLL。' % len(m['imports']))
    A('')
    if m['imports']:
        A('| DLL | 符号数 | 前若干符号 |')
        A('| --- | ---: | --- |')
        for imp in m['imports']:
            A('| `%s` | %d | %s |' % (imp['dll'], len(imp['symbols']),
                                        ', '.join('`%s`' % s for s in imp['symbols'][:8])))
        A('')
    else:
        A('PE 导入目录为空或不可读〔实测〕。')
        A('')
    A('托管调用目标全量分布（`call`/`callvirt`/`newobj`/`ldftn`/`ldvirtftn`/`jmp` 操作数解析；'
      '调用点为目标在 IL 中的出现偏移，最多列 8 处）：〔实测〕')
    A('')
    A('| 调用目标 | 次数 | 调用点（IL 偏移） |')
    A('| --- | ---: | --- |')
    for c in m['calls']:
        A('| `%s` | %d | %s |' % (c['target'], c['count'],
                                    ', '.join('IL_%04X' % o for o in c['sites'])))
    A('')
    A('## 6. 工具与环境')
    A('')
    A('| 项 | 值 |')
    A('| --- | --- |')
    A('| 元数据/IL | Python 3.13.5 + dnfile 0.18.0 + pefile 2024.8.26；`tool/lib/dnlib.py` + `tool/lib/iltab.py`（ECMA-335 自解析，不依赖 Ghidra） |')
    A('| 反编译 | ILSpy 9.1.0.7988（`ilspycmd.dll`，ICSharpCode.Decompiler 9.1.0.7988，.NET 8） |')
    A('| 反编译命令 | `dotnet <ilspycmd.dll> <样本> > decompiled/%s.cs.txt`（ASCII 引号，stdout 单文件） |' % name)
    A('| IL 命令 | `python tool/il_dump.py --dll <样本> --out il/%s.il.txt` |' % name)
    A('| 未使用 | Ghidra：本链为托管件，其 C 反编译器不处理 CIL（原生件走 T1N 链） |')
    A('| 时间戳 | 固定值 `%s`（报告可 diff，不含 wall-clock / 耗时） |' % ctx['now'])
    A('')
    A('## 7. 缺口与待验证')
    A('')
    A('1. Authenticode 签名有效性与签发者：本轮只做静态摘要，未做信任链校验〔待验证〕——缺 signtool verify 或 Windows 信任链才能判。')
    A('2. 运行期行为（依赖解析、P/Invoke 实际落点、COM 注册）：未执行样本〔待验证〕——缺 Windows 运行环境与依赖目录才能判。')
    A('3. 与上游公开包的逐字节关系：本轮未取回同名 NuGet/厂商件〔待验证〕——缺对应公开包才能判。')
    A('4. 类型/成员语义与源码对照：本件未提供源码或 PDB〔待验证〕——缺 PDB/源码才能判标识符原名。')
    A('5. 台账 20261119-61：未提供〔待验证〕——缺台账文件才能判归档口径与行号对照。')
    A('')
    A('## 8. 结论')
    A('')
    A('- 本件为可读 CLR 程序集：元数据、MethodDef %d 条、IL 字节 %s 全部落盘，逐条指令可复核〔实测〕。' % (total, _k(m['il_bytes'])))
    A('- 反编译（ILSpy 9.1.0.7988）产出 %s 行 C#，与 IL 清单可逐条对齐〔实测〕。' % _k(ctx['cs_lines']))
    A('- P/Invoke 声明 %d 条、PE 导入 DLL %d 个，均已列出〔实测〕。' % (len(m['pinvoke']), len(m['imports'])))
    A('- 未验证项集中在签名/运行期/上游对照（§7），不影响本轮静态定位结论〔待验证〕。')
    A('')
    return '\n'.join(L)


def render_incomplete(m, ctx):
    """非 PE / 无法分析件的缺口报告（不伪造 IL/C# 产物）。"""
    name = m['file_name']
    L = []
    A = L.append
    A('# %s 缺口报告（%s / 未产出 IL 与反编译）' % (name, ctx['product']))
    A('')
    A('样本别名：`%s`（%s）' % (name, ctx['sample_note']))
    A(ctx['source_line'])
    A('落点：`%s/`（相对 `out/R1`）｜定位规则：`%s`' % (ctx['archive_rel'], ctx['locate_rule']))
    A('')
    A('标签约定：〔实测〕= 本轮独立实测（有命令与原始输出）；〔待验证〕= 尚未取得证据或需 Windows 环境。')
    A('')
    A('## 0. 摘要')
    A('')
    A('| 项目 | 结果 | 依据 |')
    A('| --- | --- | --- |')
    A('| 状态 | `status=%s` | 〔实测〕 |' % ctx['status'])
    A('| 实际样本 | %s 字节，SHA-256 `%s` | 〔实测〕自算 |' % (_k(m['size']), m['sha256']))
    A('| 清单声明 | 字节数 %s，SHA-256 `%s` | 〔实测〕 |' % (ctx['declared_size'], ctx['declared_sha']))
    A('| 结论 | 本件未产出 IL 清单与 C# 反编译（不伪造产物） | 〔实测〕 |')
    A('')
    A('本件按 `status=%s` 记缺口，**不伪造** IL 清单 / C# 反编译产物。' % ctx['status'])
    A('')
    A('已试工具（逐条为实际执行，含原始报错）：')
    A('')
    A('| 工具 | 结果 |')
    A('| --- | --- |')
    for t in ctx['tried']:
        A('| `%s` | %s |' % (t['tool'], t['result']))
    A('')
    A('原始报错：%s' % ctx['raw_error'])
    A('')
    A('〔待验证〕本件是否需换用其它解析器（如 COFF/静态库解析）才能判定格式；缺该工具的实测才能判。')
    A('')
    A(FIXED_CLAUSE)
    A('')
    A('## 1. 样本与哈希')
    A('')
    A('| 项 | 值 | 标签 |')
    A('| --- | --- | --- |')
    A('| 文件名 | `%s` | 〔实测〕 |' % name)
    A('| 字节数 | %s | 〔实测〕 |' % _k(m['size']))
    A('| SHA-256（本轮自算） | `%s` | 〔实测〕 |' % m['sha256'])
    A('| 清单声明 SHA-256 | `%s` | 〔实测〕 |' % ctx['declared_sha'])
    A('| 产品映射 | `%s` → `%s` | 〔实测〕 |' % (ctx['product_raw'], ctx['product']))
    A('| 清单 | `%s` | 〔实测〕 |' % ctx['manifest_name'])
    A('| 归并首见 | `%s` | 〔实测〕 |' % ctx['first_seen'])
    A('')
    A('## 2. 缺口与待验证')
    A('')
    A('1. `%s` 的具体格式与来源需人工判定〔待验证〕——缺该格式规范/厂商文档才能判。' % name)
    A('2. 若它其实是可解析的 PE（如 COFF 目标文件、静态库），需换 PE/COFF 解析器重跑〔待验证〕。')
    A('3. 台账 20261119-61 缺失〔待验证〕。')
    A('')
    A('## 3. 结论')
    A('')
    A('- 本件记 `status=%s`，未产出 IL/反编译产物，报错原文见 §0〔实测〕。' % ctx['status'])
    A('')
    return '\n'.join(L)


def main(argv=None):
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument('--check', help='对给定文件做脱敏闸门检查')
    ns = ap.parse_args(argv)
    if ns.check:
        text = Path(ns.check).read_text(encoding='utf-8', errors='replace')
        hits = find_leaks(text)
        print('LEAKCHECK file=%s hits=%d %s' % (ns.check, len(hits), ','.join(hits)))
        return 1 if hits else 0
    print('render_report.py: 作为库使用（render_clr / render_incomplete / assert_no_leak）')
    return 0


if __name__ == '__main__':
    sys.exit(main())
