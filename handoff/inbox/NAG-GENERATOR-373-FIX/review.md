# NAG-GENERATOR-373-FIX · 修订复验（生成端字节保真 + 扫描门禁）

输入为 PR #373 原代码提交 `8f5034f02722916e442881a6bd112baef419d1a7` 的固定十组输入（夹具来源主干 `7f909cc1e03e785e1165c110ac857a6ba9a3888a`）；受验代码为本机 `_work/wf-20261120-aspen-batch/tool/` 下的三份修订文件。实际代码提交由主 agent 统一推送，`results.json` 的 `pr_head` 暂填 `PENDING_MAIN_AGENT`，推送后须回填该 SHA 并按新提交复跑。

## 受验字节（实际代码树指纹）

| 文件 | 新 SHA-256 | 原版 SHA-256 |
| --- | --- | --- |
| tool/b2_wave.py | `615e67f0b8766da9571b8810f81daf84556426b8e5d8f4685b300b6585d43969` | `627fc3becb7cd89f2bf90027b68047f28fa5f20e06514c0a1f274b3fbb4956b3` |
| tool/batch_reverse.py | `5d8df77940b57d8231bccbce93bfa1ce28ab02145972eed8337d53ba4f1a853a` | `2a33353dbb07e24f15b2a4f30c8d69883ef29688f849ad327d723f1102c6534e` |
| tool/check_cs_clean.py | `c6751f1a3b6ac426b998f4cfa8e41fd000be05ae06288fba79fdab96c2b6fb8c` | `f6989df348c2d3052337f9483b40489dd7512eb20afeb98a83b15eb15c291b85` |

`fixtures.json` = `bdfc2ae821e1d202e227ecace50656c34b879e055c35124a33d7b1a04e3aeb11`（与旧审核夹具逐字节相同，1795 字节）。`run.log` = `94bc917cf60a161ae4f82a25915e2fe72bb2330c7834d66598ae9f9ed1ac9b11`，`results.json` 内 `run_log_sha256` 与之一致。

## 三处修订

- `tool/b2_wave.py:43-61`：`strip_tool_nag` 改为 bytes 入/bytes 出，按原始行（含 `\r\n`）判断末两行，只删「完整两行提示」；`run_clr_one`（`tool/b2_wave.py:321-324`）改用二进制捕获 ILSpy stdout 后 `write_bytes`，不再经文本模式（Windows 上 LF→CRLF）或 `write_text`，且退出码为 0 时即使剥完是零字节也落盘。
- `tool/batch_reverse.py:275-300`：`strip_tool_nag` 改为 `read_bytes`/`write_bytes` 原地改写，BOM、CRLF/LF、末尾空行逐字节保留，同样支持「末行无换行」与「仅有提示→零字节」。`decompile`（`tool/batch_reverse.py:303-315`）仍以真实二进制 stdout 句柄写目标文件，随后在同一路径上做字节级剥离。
- `tool/check_cs_clean.py:16-105`：新增 C# 字面量区间扫描（`"""` 原始字符串、`@"`、普通字符串/字符、`//` 与 `/* */`），只有落在字符串/注释之外的终端提示或未配对裸诊断才计为命中；合法源码字符串内的同文不再误报。退出码语义不变：0 干净、1 命中、2 无文件。

## 二十组实得（预期 = 旧基准 CASES 的字节与退出码）

| 用例 | 预期 SHA-256（once==twice） | 字节 | 实得 SHA-256（b2 与 batch 的 once==twice） | 门禁 raw/after（预期） | 门禁 raw/after（实得，b2 与 batch 相同） | present once/twice（b2/batch） |
| --- | --- | --- | --- | --- | --- | --- |
| clean-no-final-newline | `a4127100c72e204a2e27f5a8d29310899744c2e16642591e4656add6b9fac96a` | 10 | `a4127100c72e204a2e27f5a8d29310899744c2e16642591e4656add6b9fac96a` | 0/0 | 0/0 | true/true/true/true |
| clean-trailing-empty-lines | `a81d58d209e8c4c1d4d4f36a597ef279f1862333b2ee9a50e04029005dc12531` | 13 | `a81d58d209e8c4c1d4d4f36a597ef279f1862333b2ee9a50e04029005dc12531` | 0/0 | 0/0 | true/true/true/true |
| empty-source | `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` | 0 | `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` | 0/0 | 0/0 | true/true/true/true |
| known-lf | `8a7eaee3a2ed1ded2f10c111143f7629820f78b4e63210aebe6b9986850db4ac` | 11 | `8a7eaee3a2ed1ded2f10c111143f7629820f78b4e63210aebe6b9986850db4ac` | 1/0 | 1/0 | true/true/true/true |
| known-crlf-bom | `0507b40bcf3a50597d16a60d5760adfe7725eb16bcf9cd69c36a6a49787fb507` | 27 | `0507b40bcf3a50597d16a60d5760adfe7725eb16bcf9cd69c36a6a49787fb507` | 1/0 | 1/0 | true/true/true/true |
| known-no-final-newline | `8a7eaee3a2ed1ded2f10c111143f7629820f78b4e63210aebe6b9986850db4ac` | 11 | `8a7eaee3a2ed1ded2f10c111143f7629820f78b4e63210aebe6b9986850db4ac` | 1/0 | 1/0 | true/true/true/true |
| notice-only | `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` | 0 | `e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855` | 1/0 | 1/0 | true/true/true/true |
| source-string | `03669e7b8e8f34ab265949473d557405d1d76f739c39b4cd428de01bbab58576` | 150 | `03669e7b8e8f34ab265949473d557405d1d76f739c39b4cd428de01bbab58576` | 0/0 | 0/0 | true/true/true/true |
| source-string-and-notice | `03669e7b8e8f34ab265949473d557405d1d76f739c39b4cd428de01bbab58576` | 150 | `03669e7b8e8f34ab265949473d557405d1d76f739c39b4cd428de01bbab58576` | 1/0 | 1/0 | true/true/true/true |
| incomplete-notice | `1d120d5196506f8109c6ea049bfb9fca2372aec75f99053435ef776432c1258e` | 76 | `1d120d5196506f8109c6ea049bfb9fca2372aec75f99053435ef776432c1258e` | 1/1 | 1/1 | true/true/true/true |

二十组（2 个写入口 x 10 个用例）的首次与二次输出字节、文件存在性、写入前/后门禁退出码全部与旧基准一致。特别是 `empty-source` 与 `notice-only` 两次都真实存在零字节目标（`present=true`），`incomplete-notice` 保留裸提示且门禁仍为 1，`source-string` 前后门禁均为 0，`source-string-and-notice` 写后门禁为 0。

旧复验的 12/20 组差异已全部清零：b2 的 `clean-trailing-empty-lines`/`known-lf`/`known-no-final-newline` LF→CRLF、`empty-source` 目标缺失、`notice-only` 残留 CRLF 与二次缺失、`source-string`/`source-string-and-notice` 门禁误报；batch 的 `known-crlf-bom` 正文 CRLF→LF、`notice-only` 残留 1 字节 LF、`source-string`/`source-string-and-notice` 误报。`incomplete-notice` 的 b2 少写 2 字节（76 vs 78）也随字节保真消失。

## 工件回放（固定 ILSpy 工件）

`sample.cs.txt` = `2ceba82a4d3bb35449fb475d8946274afa91dd04f5914f2fd245f09d75336886`，1439 字节，CRLF=0，LF=38，末两行为 ILSpy 升级提示（11.2.0.10050 / 当前 9.1.0.7988，LF 行尾）。两个修订入口回放一致：清除提示后 1317 字节，SHA-256 `17564b44f55a10b21387cbf528a82a392fcf6a7384810bb0a94eb17e3222fe1e`，二次写入同值，门禁 1→0。（旧 b2 因文本模式得到 1353 字节，现已与 batch 相同。）

## 复现命令与原始 stdout

在 `_work/wf-20261120-aspen-batch` 下执行：

```
python -I -B handoff/inbox/NAG-GENERATOR-373-FIX/replay.py     # 真实写入 + 真实扫描，写 run.log/results.json
python -B handoff/assignments/check-generator-revision.py      # 受信判定器，当前 exit 2（仅 pr_head 未定）
python -B handoff/inbox/NAG-GENERATOR-373-FIX/verify-local.py  # 同一 check() + 本地摘要 + 占位 head，证明 20 组零差异
```

`run.log` 逐用例记录源入口、实际目标路径（`target=`）、字节数、SHA-256 与扫描退出码。`replay.py` 只用真实子进程回放固定 stdout 字节，其余生产函数（b2 `run_clr_one`、batch `decompile`）与修订后的 `strip_tool_nag` 均为未改写的真实代码，门禁为独立进程调用完整 `tool/check_cs_clean.py`。

## 限制

- 无法 push/commit 到远端：`pr_head` 只能是 `PENDING_MAIN_AGENT`；受信判定器在 `commit_id()` 校验处先失败返回 2，其余输入/指纹/行为断言已由本地等价校验证明为零差异（见 s1-submission.md）。
- 未调用真实 ILSpy/.NET：`dotnet` 由真实子进程按固定字节回放 stdout 替代（与旧审核同一方法），不执行原始 DLL。
- 本机 Windows 10.0.26200 + Python 3.13.5；旧审核为 Windows 10.0.20348 + Python 3.12.14，字节结果一致。
- 若主 agent 推送的最终代码与上表三个 SHA-256 不一致，须以新提交重新跑 replay.py 并按新字节更新 results.json（含 run_log_sha256）后复验。
