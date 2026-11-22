# NATIVE-337 第一轮覆盖证据复验

任务归属 tietoumiao，assigned_seq=1。裁定 **returned**。FindComponent.dll 的原件级静态验收仍未通过。

原件来自提交 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/337/FindComponent.dll`，82,984 字节，SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。证据固定于 PR #387 head `62c68c514c8bcbe5435c6cbc2fcf570388a9a980`，采用 main `7f909cc1e03e785e1165c110ac857a6ba9a3888a` 的任务卡、native-coverage-evidence.v1 和检查器。

## 已核实的结果

上游从原始字节运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original issue-materials/337/FindComponent.dll`。退出 0，输出 `checked 300 coverage rows, 296 tool-native entries, 178 call records, 0 declared gaps`。115 个原件锚点和 296 个分析器函数合并为 300 个地址。反汇编和 C 均有 296 个函数段。反汇编清单可解析的 5,082 行指令字节逐行与原件核对一致。覆盖表把 gxElectrolyteWizard（RVA 0x31d0）关联至 native.c 第 1611–1637 行，把 gxReorderComp（0x3bf0）关联至第 2043–2073 行。四个异常片段的地址位于各自父函数引用范围内。

## 退回依据

- 用原件 PE 导入表建立 192 个 IAT 槽位，再从清单指令原始字节解出 RIP 相对的间接 call/jmp，以“指令末 RVA + 有符号 disp32”确定目标。在交付清单内可独立证实 363 个不同调用或跳转地址直接指向原件 IAT 槽。calls.csv 的 166 条 external 均能按行号和 IAT 槽重现，另有 **197 处未登记**。例如 native.asm 第 76、90 行分别从 RVA 0x112e、0x1161 调用 KERNEL32.dll!MultiByteToWideChar，目标槽均为 0x7050。逐址明细含原件字节、指令位置、目标槽与导入名或序号。[197 处漏项](s1-missing-iat.csv)
- 12 条 data 之外还有能影响导出行为的数据引用。gxReorderComp 在 native.asm 第 2806 行（RVA 0x3c44）取字符串 ReorderComp 的地址 0x7a88。第 1409 行取 ShowOpenMessageBox 的地址。这两处在 calls.csv 中均无记录。
- 交付未交代间接调用的恢复情况。例 native.asm 第 245 行（0x1389）通过寄存器中的表调用偏移 0x28 的目标。应说明调用方、查明的对象/成员或静态解析的边界，对仍无法确定的调用按标准标 unresolved。
- 补正时请为四条异常片段的 note 加上父 RVA。0x33b1、0x382f 的父入口为 0x3380，0x4706、0x4988 的父入口为 0x4690。

## 恢复条件

原 owner 在同一原件上增补逐址外部调用、相关重要数据和间接调用，列明所有未决项和可执行的恢复条件。沿用已核实的函数与原件映射，提交新回执和固定 head。上游用原件重新对账外部调用缺项，复核补充行及未决项，再依原标准裁定。原件的完整源码、数据、资源及行为等价仍待后续逐件判断。

开工回执 SHA-256 `93293df227937d48c1ea5886300cc8e380be9e02c079281086882aaa1c3ba0c1`。交付回执 SHA-256 `4ef88008dbee7678c1c24173b8e11c678816d7f778884c3fdbe8215397b0ddeb`。漏项表 SHA-256 `3ed07eebbc0662fe688aca4ab9bff35cb9f5fb06f2c74a9a7b261e21833a4a88`。
