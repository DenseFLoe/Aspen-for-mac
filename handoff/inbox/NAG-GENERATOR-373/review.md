# PR #373 的 Windows 写入与扫描复验

#373 的提交 `8f5034f02722916e442881a6bd112baef419d1a7` 有 12/20 组未达到 generator-guard.v1，共触发 24 条判定差异。上游复跑两次，结果与日志指纹相同。受信命令 `python handoff/assignments/check-generator-373.py` 退出 1。每组包括首次、二次实际输出字节和写入前、后两次扫描退出码。[固定任务卡](https://github.com/DenseFLoe/Aspen-for-mac/blob/7f909cc1e03e785e1165c110ac857a6ba9a3888a/handoff/assignments/NAG-GENERATOR-373.md)

## 两处生产路径

- `b2_wave.py:309–312` 用文本模式捕获 ILSpy stdout，要求 `stdout.strip()` 非空，随后用系统换行写出。第 48–50 行剥提示后追加一个换行。Windows 上 LF 输入转为 CRLF，空输入跳过创建目标，仅提示输入首次写出 CRLF，再次写入到新目录时跳过创建。[B2 写入口](https://github.com/DenseFLoe/Aspen-for-mac/blob/8f5034f02722916e442881a6bd112baef419d1a7/tool/b2_wave.py#L289-L324)
- `batch_reverse.py:568–579` 将正式 C# 输出路径传入 `decompile`。第 292–296 行把 stdout 直接写入二进制文件。第 278–284 行按文本读取并用 LF 重写匹配文件，使 CRLF 变 LF，仅提示时剩 LF。含 BOM 的夹具保留了 BOM。[生成调用](https://github.com/DenseFLoe/Aspen-for-mac/blob/8f5034f02722916e442881a6bd112baef419d1a7/tool/batch_reverse.py#L568-L579) · [写入和剥离](https://github.com/DenseFLoe/Aspen-for-mac/blob/8f5034f02722916e442881a6bd112baef419d1a7/tool/batch_reverse.py#L275-L299)
- `check_cs_clean.py:15–24,42–46` 扫描末三行，只要匹配任一前缀就报错。合法原始字符串中保留两行同文时，该扫描器在两处写入口都产生误报。它能拒绝本次未配对裸提示用例。[扫描器](https://github.com/DenseFLoe/Aspen-for-mac/blob/8f5034f02722916e442881a6bd112baef419d1a7/tool/check_cs_clean.py#L15-L46)

| 固定用例 | b2_wave | batch_reverse |
| --- | --- | --- |
| clean-no-final-newline | 符合 | 符合 |
| clean-trailing-empty-lines | LF 变 CRLF | 符合 |
| empty-source | 目标缺失，写后门禁 2，预期为 0 | 符合 |
| known-lf | 正文 LF 变 CRLF | 符合 |
| known-crlf-bom | 符合 | 正文 CRLF 变 LF |
| known-no-final-newline | 正文 LF 变 CRLF | 符合 |
| notice-only | 首次 2 字节 CRLF，再写缺失，预期两次均为零字节文件 | 两次各残留 1 字节 LF |
| source-string | LF 变 CRLF，前后门禁均为 1，预期为 0 | 前后门禁均为 1，预期为 0 |
| source-string-and-notice | LF 变 CRLF，写后门禁 1，预期为 0 | 写后门禁 1，预期为 0 |
| incomplete-notice | 裸提示保留，LF 变 CRLF | 符合 |

各例原输入见 [fixtures.json](fixtures.json)，首次和二次结果按 Base64 原样保存在 [results.json](results.json)。其中 `*_present=false` 表示未生成文件，Base64 空串记录该次没有输出字节。门禁读取实际目标目录，因此无文件时真实返回 2。[逐次测量日志](run.log)

## 原始 stdout 及可复现性

既有分支交付 `Interop.appinitLib.dll.cs.txt` 为 1,439 字节，SHA-256 为 `2ceba82a4d3bb35449fb475d8946274afa91dd04f5914f2fd245f09d75336886`。末两行为已知提示及版本行，记录 ILSpy 9.1.0.7988、提示更新到 11.2.0.10050，行尾为 LF。精确删除后 1,317 字节。实际再走 batch 写入口为 1,317 字节，SHA-256 为 `17564b44f55a10b21387cbf528a82a392fcf6a7384810bb0a94eb17e3222fe1e`；B2 在 Windows 生成 1,353 字节，两者扫描均为 0。[固定来源工件](https://github.com/DenseFLoe/Aspen-for-mac/blob/a9ea5dfcc5ba8c12ac306e73f79fa02e30e7ea04/analysis/20261120-batch-driver/Aspen-Plus/%5BCommonFiles64Folder%5D/AspenTech%20Shared/Aspen%20CXS%20V15.0/SummaryGrid/decompiled/Interop.appinitLib.dll.cs.txt)

在 Windows 10.0.20348、Python 3.12.14 实跑。独立工作目录按原路径放置任务卡所列三份程序、主干受信判定器与本目录，把上述原始工件的原始字节放根目录 `sample.cs.txt`。运行 `python -I -B handoff/inbox/NAG-GENERATOR-373/replay.py`，再运行受信判定器。仅缺夹具时先用判定器的 `--emit-fixtures handoff/inbox/NAG-GENERATOR-373/fixtures.json` 创建。回放器先核对三份程序和实际工件 SHA-256。它提取已审阅的实际函数，以子进程字节输出替代 ILSpy，保留生产端的文本捕获或二进制重定向、实际文件写入及独立扫描进程。IL 清单和外围报告以测试替身处理。每次写入新目录，复写时以首次观测到的字节作为输入。[回放程序](replay.py)
