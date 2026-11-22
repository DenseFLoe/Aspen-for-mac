# FindComponent.dll 第三十三号复验

裁定 returned。原件 SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。固定候选经任务目录 48 个 blob 和相对 #442 唯一变动的工具 blob 核实。整件仍未通过静态验收。 [#445 候选](https://github.com/DenseFLoe/Aspen-for-mac/tree/bd362e3f3493abdda0d5aa3171a25fae5f6f14c7/handoff/inbox/NATIVE-337)

- 上游覆盖检查输出 `307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps`，退出 2。原件清单 5,055 条指令字节一致，主表 524 条外部、48 条数据、112 条未决，363 处直接 IAT 全部命中。三份主表指纹与 metrics.json 一致。提交回执的 IAT 计数仍写 0，s33 更新附表缺本轮回执指纹，回执引用的 `tool/s33_rebuild.py` 在候选树中缺失。
- 161 条二跳均可从原件重放，主表符号和新版附表 ASM 引用逐条吻合。新版附表仍缺 17 个首跳、18 个 IAT 和 18 个符号。举例，`0x44b3` 原件跳至 `0x4d31`，再经 IAT `0x7228` 指向 `mfc140.dll!#1087`，候选三列为空。 `0x5c78` 已填首跳 `0x1080`，后两列应为 `0x7030` 和 `KERNEL32.dll!InitializeCriticalSectionEx`。二跳附表新增的 calls_row 列全部为空。
- `0x12da` 的原件异常宿主为 `0x11e0–0x1319`。候选 ASM 第 208 行位于 `0x12bd` 子清单，calls.csv 第 528 行承接该转移。两个 s33 附表把候选宿主误写为 `0x11e0`。
- 16 条展开片段对象槽及 64 条 COM 的新两列行号全对，六处 COM 成员修正均正确。展开片段 `0x4706–0x4988` 和父函数链 `0x4690 → 0x4706 → 0x93c8` 已复核。三组 Factory 44/12/8 处均匹配原件的接口取得路径，实际实现地址继续列未决。

补正时从固定原件逐址生成二跳，校验首跳、IAT 槽、导入符号与当前主表行。修正 `0x12da` 的两个 s33 附表。新版生成脚本和附表回执应随提交回读且能复跑。复用本轮核实的两份行号附表，保留过去轮次的收据。原件合法复用同一 thunk，例如 `0x4ac7` 服务 39 个站点，逐址核证可以覆盖这些调用。

脚本及报告用法见 [check-s33.py](check-s33.py) 和 [s33-recheck.json](s33-recheck.json)。`check-s29.py` 针对历史 s29 附表，退出 2 的代码分支仍遇到首跳与宿主差异。保留 s25/s29 的固定收据，随新轮另建证据指纹并使用新轮比对入口。
