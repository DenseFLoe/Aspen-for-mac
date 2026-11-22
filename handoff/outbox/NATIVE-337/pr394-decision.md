# FindComponent.dll 候选 #394 补查

上游退回 [PR #394](https://github.com/DenseFLoe/Aspen-for-mac/pull/394) 的固定 head `1f072367ef38daaa0fe49395c8f86daca84db593`。交付沿用第五号分配的回执文件。第五轮已按 #392 的固定 head 裁定，第九号分配继续由 tietoumiao 执行。本次补查未触发新一轮正式状态变更。[第九号任务卡](../../assignments/NATIVE-337-s9.md)

主干判据固定于 `f1ed621740bf27fabf86b4780d9fdcb75df279ca`。用固定原件 `64670801de54e990f975aaeda06e89340c0e4e08` 的 FindComponent.dll，82,984 字节，SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original <原件>`，输出 `checked 280 coverage rows, 280 tool-native entries, 502 call records, 0 declared gaps`，退出 2。提交回执 SHA-256 为 `85ae70552189f4960a94c4093af3aeb5f3fc33fbf31f7a28b5de52b1c476a449`。

- 上游逐址对照旧清单 5,082 处和新清单 5,001 处的指令字节，并经原件导入目录验证 355 个已登记 IAT 位置的目标。首轮漏掉的 197 处可确认为 190 条 call 和 7 条 jmp。metrics.json 所列三份表的 SHA-256 已全部复现，旧有 29 个数据引用位置在新表中均可定位。
- 新清单漏掉已核实的 8 处直接 IAT 转移，函数覆盖减少 20 个旧地址。例如 0x11c3 访问 0x70e0，对应 OLEAUT32.dll 的序号 6。请保留 300 个已登记覆盖地址、363 个已知直接 IAT 位置，逐址说明分析器边界差异。生成前后在同一份缩小的清单内计数相等，无法检查这类丢失。
- 13 个要求补报的间接转移全有原件指令。新表将其中 12 个登记成字符串数据，0x6050 的间接跳转没有调用记录。64 处 COM 调用均保留为未决，没有写出已知成员、工厂与运行时待定部分。161 个调用方到导入跳板的关联均未登记。新清单收录其中 153 个调用位置，可直接补关联。
- 新增导出器 ExportEvidence.java 第 119 行只输出第一个操作数，例如 0x1004 导出的文本仅为 `LEA RDX`。请保留全部操作数，并用原指令核对生成清单。修订后按第九号任务卡提供 s9 开工、交付回执与固定 head，再对同一输入复验。

逐址清单含三组全部 238 处与候选分类。汇总附八处 IAT 差集、二十个覆盖地址差集和原件、判定器及三份候选表的指纹。[逐址补查](pr394-addresses.csv) · [复核汇总](pr394-evidence.json)
