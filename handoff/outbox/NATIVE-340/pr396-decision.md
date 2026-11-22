# WrapSaveMergeNNFiles.dll 候选 #396 补查

上游退回 [PR #396](https://github.com/DenseFLoe/Aspen-for-mac/pull/396) 的第五号分配重出件，head 为 `467cf06eaa15c40695635db8f3571f7f17594965`。#13 的 7077613866 报告了这个 head，候选继续使用 s5 开工和交付回执。第五轮已按 #393 完成裁定，当前第九号分配仍归 tietoumiao。整件静态验收未通过。[第九号任务卡](../../assignments/NATIVE-340-s9.md)

核验基准是主干 `f1ed621740bf27fabf86b4780d9fdcb75df279ca`、已收交付 `a0b8a11853f70d32870b9d0aa15267572c1ffb0a` 与固定原件 `64670801de54e990f975aaeda06e89340c0e4e08` 的 issue-materials/340/WrapSaveMergeNNFiles.dll。原件 107,048 字节，SHA-256 为 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件>`，输出 `checked 877 coverage rows, 126 tool-native entries, 290 call records, 0 declared gaps`，退出 2。候选提交回执 SHA-256 为 `7f7c55bd8ccd007ddd4b303f824741fcc360cb12374f41fdc42b8104bce9dc8d`。

- 从 167 个原始 IL 方法体按操作码和 token 重查，61 条托管到原生的直接调用与 15 处 calli 都有登记。新清单保留原有的 162 条 IL 外部调用，563 个类型下的 188 个方法子项与原件成员索引对应。仍缺全部 16 处外部构造调用。例如 0x0600001B 的 IL_003B 是 `newobj 0x0A000027`，该行能在新 methods.il 中找到，calls.csv 未登记。
- 从原件 RVA 0x16600 的 CLR VTableFixups 表读出各槽并核对跳转指令，126 个已知原生到托管目标均可确定。候选调用表未关联其中任何一项，反汇编仅保留其中 4 处。另有 11 处已知间接转移在新反汇编中能定位，在调用表中均缺失。请从已核实的 #393 基线增补覆盖。
- 19 个非空 TypeDef 标题的 MethodList 两端仍分别少一。例如 WrapCall 的子项是 A1–A2，标题仍写 A0–A1。types.cs 的 WrapperSaveMergennFiles 仍声明无参数，原签名有两个显式参数。请用实际子 token 生成范围，并区分成员索引与可编辑声明。
- RVA 0x3660 的 14 个原件字节解出两次加载和返回。先取 GS:[0x30] 得当前 TEB，再读该地址偏移 8 的 StackBase。候选 C 第 1213 行只作 Self + 8 的读取，全件未见 Self 的来源声明。请恢复旧版两次加载并纠正语义，同时保留汇编操作数。候选汇编两行均只有 MOV RAX。
- 对照旧清单 1,462 和候选 1,254 处原件指令位置。原生覆盖从 256 项缩至 126 项，共缺 141 个旧地址，另增 11 项。原先 51 处直接 IAT 仅保留 48 处，例如 0x4894 指向 memcpy。s5-submission.md 仍同时声称 256 和 126 个函数，需以同一版本的证据同步口径。

请按第九号任务卡补交 s9-started.md、s9-submission.md 和新 head，在原件上复验。[172 项逐项核对](pr396-addresses.csv) · [原件、候选与差集指纹](pr396-evidence.json)
