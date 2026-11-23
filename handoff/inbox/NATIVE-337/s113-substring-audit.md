# NATIVE-337 收尾：子串判等写死（s113 前置）

## ① 扫描结果
扫 `tool/*.py` 中「对**标识符**（RVA / token / 序号 / 符号名 / 路径）使用 `in`、`startswith`、`endswith`」的比较，命中 5 处，处理如下：

| 位置 | 原比较 | 处理 |
| --- | --- | --- |
| `tool/audit_340_s65.py:176` | `x[2].startswith("0x%08X" % tok)` | **改为** `ident.same_ident(x[2], "0x%08X" % tok)`（token 整值） |
| `tool/audit_340_s29.py:83-84` | `ins[3][2].startswith("0x04000056")` 等 2 处 | **改为** `ident.same_ident(...)`（字段 token 整值） |
| `tool/s109_verify.py:137` | `got.startswith(orig)`（清单字节 vs 原件字节） | **改为** `got != orig` 精确整串（该指令字节全等） |
| `tool/det_symbol_substring.py` | 前缀比较本身 | **保留**并注明理由：该文件的职责就是**报告**前缀关系的符号（前缀即判据） |
| `tool/det_wrong_symbol.py` | `re.match("^0x")` | **保留**并注明：只用于判断「是不是 RVA 字面量」，不承担身份判等 |

新增 `tool/ident.py`：`same_ident()` / `hex_equal()` 作为唯一判等入口（整值或数值比较）。

## ② 自检脚本 `tool/s113_substring_audit.py`
两层：行为层喂构造样本；静态层扫 `tool/*.py` 的标识符前缀比较（allowlist 内需注明理由）。
~~~
behaviour: pairs=10 conflations=0
statics: allowlisted=3 hits=0
SUITE : PASS
~~~
差异样本（必须判不同）：`A848` vs `A8480`、`0xA848` vs `0xA8480`、`#2344` vs `#23440`、`2001080E` vs `2001080E0`、`0x106C` vs `0x106C0`、`mfc140.dll!#2344` vs `mfc140.dll!#23440`。
同值样本（必须判相同）：`A848` vs `a848`、`0xA848` vs `A848`、`#2344` vs `#2344`、`2001080E` vs `2001080e`。
任何一对被误判即 exit 1；静态命中未 allowlist 也 exit 1。

## ③ 清单是否含 `tool/*.py`
**不含**：`s109-fingerprints.json` 的 110 项里 `tool/*.py` 计数为 **0**，原因是生成器只遍历交付目录 `handoff/inbox/NATIVE-337`（`tool/` 在它之外），所以脚本改动不会引起清单抖动。
为防止将来规则漂移，仍在 `PATTERNS` 里显式加了 `tool/*`（附注释），并补齐 `work/*-exclusions.txt`；当前排除规则：
~~~
  s*-fingerprints.json
  s*-submission.md
  work/*-gate.txt
  work/*-exclusions.txt
  tool/*
  s*-audit.md
~~~
清单因此从 110 项收敛到 **108 项**（并新增 `s*-audit.md` 排除，避免本说明自身引起抖动），两次生成哈希一致：`012053f5c8213585a18f0a5e16958652ec1121bb487e30c66557e373c20e5c9a`。

## ④ 排除项补偿控制（X1/X2/X3）
`s*-audit.md` 之前排除后既不在清单、也无反向固定——已补方案 1：
- `work/s109-audit-pins.txt` 逐个列出本轮 audit 页的 **sha256 + 字节数**，而该 pins 文件**本身在清单里**（109 项）；
- 因此改 audit 页会让 pins 与清单不一致，可被发现。

本轮 audit 页的 sha256 与字节数见 `work/s109-audit-pins.txt`（由脚本对文件现算，避免自引用）。

全部六条排除项现均在 `work/s109-exclusions.txt` 里写明 **pattern / reason / compensation**（X3），其中两条运行产物明确标注「不覆盖，理由：运行日志，可由回执命令复现」。

## ⑤ `tool/ident.py` 判等语义（文首）
```
SEMANTICS (read before comparing anything by hand):
  same_ident(a, b)
    * compares the WHOLE value; no substring, prefix or suffix logic;
    * hex-ish values ("A848", "0xA848", 0xA848) are parsed as integers and compared numerically,
      so a leading "0x" is insignificant and "A848" != "A8480";
    * non-hex strings (symbols such as "mfc140.dll!#2344") are compared case-insensitively
      after stripping surrounding whitespace: "mfc140.dll!#2344" == "MFC140.DLL!#2344";
    * an int and a string are never equal unless both normalise to an int;
    * paths are NOT handled here: compare them as-is (case-sensitive) after os.path.normpath.

DO NOT compare identifiers with ==, in, startswith or endswith anywhere else: call this module.
tool/s113_substring_audit.py fails the build when a substring comparison on an identifier reappears.
```
