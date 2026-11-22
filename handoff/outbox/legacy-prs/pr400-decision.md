# #400 函数统计口径修订复验

复验结论为退回补件。固定候选为 `b70a344d8e662ecc8f64d18382b9e0614616719c`，#13 首报为 `32a29959b0e1d554fcb93ed7158122e5cb411ca7`。复验基准为 `773260c1033e524cebe000699409f5708bebfda0` 的 `handoff/outbox/legacy-prs/review-20261122.md` 内 #371 裁定。所引规则覆盖四项要求：纯托管证明、混合件交叉核实、非 PE 的真实格式、全部与逐件计数的可复现性。

当前 head 的 `handoff/inbox/FUNC-NA-371/s1-submission.md`（Git blob `752b28cdb4275fefd20d51a78dd2aebdbd99a326`）列出十份交付。使用 GitHub Contents 按路径逐个读取 `handoff/policies/` 下的 functions-na.v1.md、recount-nan.py、ledger-counts.csv、ledger-counts.fixed.csv、recount-nan.out.txt、recount-nan.modeB.out.txt、parse-native340-methoddefs.py、parse-native340.out.txt、parse-bfdyld-coff.py、parse-bfdyld-coff.out.txt，十项均为 HTTP 404。另核 PR 正文所述 `tool/policies/recount-nan.py`、`tool/policies/parse-native340-methoddefs.py` 同样为 404。当前变更清单共八份：两份回执、六个原生和 IL 源码工具。PR 本身的复算入口无法运行；说明中的 RESULT PASS 不能用于核定实际统计结果或采纳新规则。

上游另对两件固定原件直接复算，以下两组样例数已核实。

| 原件 | SHA-256 | 独立复算 |
| --- | --- | --- |
| WrapSaveMergeNNFiles.dll | `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec` | .NET PEReader 读取全部 188 个 MethodDef；按 RVA 和 ImplAttributes 的 CodeType 分得 167 个 IL、19 个 native、2 个零 RVA。 |
| BFDYLD.obj | `194e88b44801eb787ccd0964ef43f869a7d355a2ea905a0f679d173f91703ec0` | 直接解析小端 COFF 文件头、节表及符号表。机器 0x8664、7 节、51 个符号表记录含辅助记录、.text 1,792 字节。BFDYLD 位于第一节偏移 0，类型 0x20，存储类 2。 |

请将修订后的规则原文、复算程序及其实际读取的带指纹输入一并发布。模式 B 所用的 ledger-counts-detail.csv 可以提供固定仓库路径和完整 SHA-256；也可提供从指定仓库快照恢复模式 A 输入的可执行路径。提交真正的两个原件解析脚本、修订台账及相应可复跑输出。在新 head 按公开命令复核 1,346 文档口径、1,315 件口径和 31 份未映射文档中 2 份无字段的分解，再核查规则逐条落点。既有逐件状态和阶段 2 单文件交付保持原记录。
