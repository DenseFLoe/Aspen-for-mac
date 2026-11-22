# #400 函数统计口径补件复验

十份缺件已齐，统计和两个原件样例通过复算。批量规则仍退回修改。候选为 `847e92010814d5ca1d6ea6178675213c9060f227`，上轮收件为 `b70a344d8e662ecc8f64d18382b9e0614616719c`。本次只核对 #371 口径修订。候选 PR 还含六个原生工具文件，这些文件另有交付范围。[候选规则及复算程序](https://github.com/DenseFLoe/Aspen-for-mac/tree/847e92010814d5ca1d6ea6178675213c9060f227/handoff/policies) · [输入、产物指纹和复跑输出](pr400-recheck.json)

## 已核实

从规则指定的历史根树 `f7959f39fd631692f14ecbbdfbf2496f543362b3` 恢复 `analysis/20261120-batch-driver/` 子树 `ad2548fb4fcae4e57f3a46c2baca384a65a9f515`。读取子树内的 `index.csv` 作为程序的 `--index`，其 SHA-256 与回执一致。1,346 份 Markdown 的 Git blob 全部吻合。独立逐份提取函数字段，再用候选程序模式 A 复跑，生成的修订台账与交付逐字节相同。[固定子树下载](https://codeload.github.com/DenseFLoe/Aspen-for-mac/zip/ad2548fb4fcae4e57f3a46c2baca384a65a9f515)

| 统计范围 | N/A | 数值 | 无字段 |
| --- | ---: | ---: | ---: |
| 全部 1,346 份文档 | 567 | 777 | 2 |
| 索引映射的 1,315 个不同原件 | 558 | 757 | 0 |
| 余下 31 份文档 | 9 | 20 | 2 |

558 件含 470 个 CLR、86 个 nonPE、2 个原生文件。固定混合件 WrapSaveMergeNNFiles.dll 与 COFF 原件 BFDYLD.obj 均重验了 SHA-256，并实际重跑两份候选解析器，标准输出与交付逐行一致。混合件有 188 个 MethodDef，含 167 个 IL 体、19 个原生实现、2 个零 RVA。COFF 有 7 节、51 条符号表记录（含辅助记录），代码节 1,792 字节、59 条重定位。规则对非 PE 文件要求按真实容器列出未恢复成员，对工具超时单列缺口，这两项符合前次裁定。此处计数仅用于核对报告字段。

## 采纳前须修正

1. 修正 §2.2、§2.3 的元数据判据。Runtime 在 MethodImplAttributes 的 CodeType 位，值为 3。§2.2 将其写为 MethodAttributes 的 `0x3000`。§2.3 只引用 PreserveSig 解释两条声明。上游用 PEReader 回查，零 RVA 的两条是 DecodePointer、EncodePointer，MethodAttributes 均为 `0x6016`，ImplAttributes 均为 `0x0080`，具备 PInvoke 标志和对应的 Import 记录。请把这份依据写进样例。
2. 修正 §2.4 的原生分母。19 是有原生实现的 MethodDef 数。本次用受信主干检查器对同一原件独立枚举出 75 个原生锚点。应分列该 19 项、原件锚点及分析器发现的入口，处理重复及函数片段后再给函数数。按 §2.4 直接将 `functions` 填为 19 会遗漏 §2.2 S4 要求分析的其他原生范围。
3. 让指纹和台账差异影响复算结论。对模式 A 使用完全相同的实际报告，把输入树内一个期望 blob 改错，同时将修订台账 TOTAL 的 N/A 从 567 改成 566。程序输出 `ok=1345 bad=1`、`LEDGER_DEFECT TOTAL.md_functions_na`，仍以 `RESULT PASS` 和退出 0 结束。请校验固定输入身份、拒绝不一致的报告和修订台账。核对旧台账时只允许已知的 UNMAPPED_MD 缺字段 0→2。模式 B 若用于投递，还须提供可恢复的明细文件并验证其完整指纹。模式 A 已有可恢复输入。

修复后，用相同的原件、报告子树和索引再次比较。固定资料应通过，单独更改一处报告指纹或修订台账数值都应失败。本次沿用既有逐件状态与阶段 2 单文件交付。
