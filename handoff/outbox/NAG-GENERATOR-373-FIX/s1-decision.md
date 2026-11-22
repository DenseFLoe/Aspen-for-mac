# NAG-GENERATOR-373-FIX 第一次修订复验

任务 NAG-GENERATOR-373-FIX，执行方 tietoumiao，assigned_seq=1。上游裁定为 **returned**。候选为 [#401 的完整提交](https://github.com/DenseFLoe/Aspen-for-mac/commit/a33cf8764c14fe76e43c961ebfb7cdfc84d910ec)，受测代码提交为 `95d5d096213de613bfee7cc12424e8e60948fa29`。主干的规则与检查器固定在 `773260c1033e524cebe000699409f5708bebfda0`。依照 generator-guard.v1 和 generator-revision.v1，固定用例通过。下列生产路径会误删源码或放过裸诊断，原 PR 保留待修。

## 已经复现的修复

上游在 Windows 实跑主干命令 `python -I -B handoff/assignments/check-generator-revision.py --inbox <提交的任务目录> --expected-head a33cf8764c14fe76e43c961ebfb7cdfc84d910ec`，退出 0。经网络取得两个提交的三份源码，SHA-256 均与申报一致。

| 路径 | SHA-256 |
| --- | --- |
| tool/b2_wave.py | 615e67f0b8766da9571b8810f81daf84556426b8e5d8f4685b300b6585d43969 |
| tool/batch_reverse.py | 5d8df77940b57d8231bccbce93bfa1ce28ab02145972eed8337d53ba4f1a853a |
| tool/check_cs_clean.py | c6751f1a3b6ac426b998f4cfa8e41fd000be05ae06288fba79fdab96c2b6fb8c |

独立回放直接从两份候选源码读取 `run_clr_one` 和 `decompile`。受控子进程按夹具发送 stdout，生产函数两次分别写入新的 Windows 目录，完整候选扫描器另起进程检查文件。原版 10 个用例 × 两入口，20/20 组逐字节、存在性和门禁结果均符合。归档 ILSpy 9.1.0.7988 的 1,439 字节真实工件在两个入口均稳定得到 1,317 字节，SHA-256 为 `17564b44f55a10b21387cbf528a82a392fcf6a7384810bb0a94eb17e3222fe1e`，扫描结果均由 1 变 0。

## 退回依据

下表的三种输入各经两个生产入口重复写入，两端结果一致。输入正文、两次实得字节数与指纹、门禁期望与实得值见[Windows 观测记录](s1-windows-results.json)。

| 输入 | 应有结果 | 实测 |
| --- | --- | --- |
| 合法 C# 逐字字符串。末两行包含提示文字，第二行以字符串结束引号及分号收尾 | 保留 157 字节，门禁 0 | 两次都余 33 字节，字符串及结束引号已被截去，门禁仍为 0 |
| 合法正文后追加第一行完整提示，第二行仅有 `Latest version is`，缺版本信息 | 保留 94 字节，写前写后门禁均为 1 | 两次都余 11 字节，写后门禁变为 0 |
| UTF-8 BOM 后立即出现未配对的裸诊断行 | 保留 69 字节，写前写后门禁均为 1 | 字节保留，写前写后门禁均为 0 |

前两例定位于 `tool/b2_wave.py` 的 `strip_tool_nag`（第 43 行起）和 `tool/batch_reverse.py` 同名函数（第 275 行起），均仅以末两行的前缀决定删除。第三例定位于 `tool/check_cs_clean.py` 的 `scan`、`has_nag`，首行的 BOM 留在匹配文本前。另实测 B2 在 ILSpy 返回 1 并向 stderr 写入 `fixture error` 时，于错误分支拼接文本和 bytes 产生 TypeError，调用方得不到既有的 `failed_analyze` 返回。

## 续修与证据回放

判定完整的已知两行提示，保留字符串内的同文和残缺版本行。扫描时识别首行 BOM，错误分支统一 stderr 类型。用本次三个输入、子进程失败的用例和既有十组重新运行两个正式入口。同步更新 `s1-submission.md`、`review.md` 和回放程序输出的代码提交。当前两份说明仍写 `PENDING_MAIN_AGENT`，候选回放脚本会把 `results.json.pr_head` 重新写成该占位符。实际已提交的 results.json 指纹为 `4426c34e650a39de3b15dfed2b19ecb3d44da56dc04139948234d630732d43a5`。PR 共改 18 个路径，含 6 份另案的原生分析工具。下次提交划清这些工具的来源与交付范围。

将主干规则及初次回放器放入普通目录 MAIN，将上述候选的三个 tool 文件及该件 inbox 放入 CANDIDATE。用 [上游回放程序](s1-replay.py) 运行 `python -I -B s1-replay.py --main-tree MAIN --candidate-tree CANDIDATE --output observed.json`。复验程序 SHA-256 为 `56c23514c85af5c513730fec97b716ecbdf1ae9c664a788674af819ced54e195`，观测 JSON 为 `e5b1b54edafc1a6f0fbc552e6fdc558b48a9924d1e04d0bf435a9b0efabc18ae`。本次范围为新生成文件，455 份存量单文件交付维持独立验收。
