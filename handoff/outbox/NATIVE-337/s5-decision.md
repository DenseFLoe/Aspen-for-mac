# NATIVE-337 第五号分配的复验裁定

**returned**。固定交付的 5 份修改可归档为补证。FindComponent.dll 仍为静态验收未通过。执行方为 tietoumiao，assigned_seq=5。[产物 PR #392](https://github.com/DenseFLoe/Aspen-for-mac/pull/392)

候选提交为 `a180dcfd1b6bd39072a4a03b94b908408e6da426`。本轮使用 main `e7f800d9aecad9cab1f14f3bec4852d36ee3ca3f` 的任务卡、原生覆盖标准和检查器。固定原件提交 `64670801de54e990f975aaeda06e89340c0e4e08` 中的 `issue-materials/337/FindComponent.dll` 实测 82,984 字节，SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。[续领卡](../../assignments/NATIVE-337-s5.md) · [首轮裁定](s1-decision.md)

## 已核实的补正

从仓库根运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original issue-materials/337/FindComponent.dll`，退出 2。输出为 `checked 300 coverage rows, 296 tool-native entries, 491 call records, 0 declared gaps`。99 个调用点填为 unresolved，检查器据此退出 2。

- 上游用 pefile 读取原件 IAT，并用 Capstone 复核交付反汇编的 5,082 行原件字节。363 条直接经 IAT 调用或跳转的指令，均与交付的调用者、行号、槽位及导入名或序号对应。首轮所列的 197 处全部补齐。
- 原件 RVA 0x2601 和 0x3c44 的指令分别指向 0x7780 的 ShowOpenMessageBox 和 0x7a88 的 ReorderComp。两处 UTF-16 字符串、引用地址和证据行均匹配。
- 覆盖表只改了 4 个片段的说明。0x33b1、0x382f 已指向父函数 0x3380，0x4706、0x4988 已指向父函数 0x4690。

## 剩余缺口与恢复条件

1. 在同一份反汇编中逐条解码 call/jmp，按操作数属于直接地址、原件 IAT 或其他间接方式划分，共有 112 处非 IAT 间接转移。交付登记 99 处，另 13 处缺行。请按所附行号和原件字节补齐，能识别中转槽的写明中转层，最终目标仍依赖运行态的可标 unresolved。[13 处逐址清单](s5-omitted-transfers.csv)
2. 99 行均只写 indirect 和相同的断点或指针表恢复说明。原件至少能静态定位其中 64 处的 COM 接口成员。三个工厂 0x2330、0x2410、0x24e0 调用 CoCreateInstance 时使用相同的 riid，原件 0x8308 的 16 字节解作 IID_IDispatch `00020400-0000-0000-c000-000000000046`。16 个包装函数对返回对象调用 vtable，按 64 位 IDispatchVtbl 排列可区分 16 处 GetIDsOfNames、16 处 Invoke 和 32 处 Release。例如 0x1389 用槽 0x28 解析 ShowDialog，0x1444 用槽 0x30 调用所取 DISPID。请逐址写入已知接口成员及工厂来源，具体 COM 实现的运行时地址仍可保留为未决。[64 处接口证据](s5-dispatch-sites.csv)
3. 同一清单还可从调用方直接定位 161 个通过单个导入跳板调用或跳转的地址。各条所到跳板均从自身首条指令跳向原件 IAT。现有 363 行只列直接触及槽位的指令。请在引用证据中关联调用方、跳板与已有 IAT 记录，保留两种地址的计数口径。[161 处调用方对照](s5-import-callers.csv)
4. `run.json` 的 scope 写有 13 处重要数据引用；本轮 `calls.csv` 实有 29 条 data，提交说明也写 29。请同步运行记录。

按以上差异提交修订，复用已核实的 300 行函数映射和 363 条 IAT 引用。原件和静态材料已足以修复上述证据缺口。整件结论仍需依据静态验收标准对实现、必要数据和资源作出判断。

## 本轮 SHA-256

| 文件 | SHA-256 |
| --- | --- |
| 当前主干判定器 | `6e21abd6043b2905eccbce2cdf2a21a8c773ff31070938fdf27cc5bb7c9d7241` |
| s5-started.md | `1cec0177be7237298fc3fc73cf3a94c9c016b3e719ae0850605661ca952706c2` |
| s5-submission.md | `a8a538f4bf635a05a2cd9546a7471a340c828e4eedeb07287a4a3dc4a451d6be` |
| calls.csv | `8769b468adb52960070db4417fea4dada8b993265928b7e245b0ae4a9606523f` |
| coverage.csv | `6138cc90064a660738db88e2eb391eb72207e48444265f84c9e68d882b3f0246` |
| run.json | `c163c6f67f0d52bcd0377e1f16ce1af7c45e2ddb20206359aef53965968a7b75` |
| code/native.asm | `15597b0272cf688b4c245174096f1b6d0728e2bb615fed9984121c27bb085214` |
| s5-omitted-transfers.csv | `9987137bfaafa528488f93861e147b66d30c22fb1957d067c3b63d4c5238a1e0` |
| s5-dispatch-sites.csv | `0eafaf4ec6d09f08ceeacbe9ad6e5a43fe0ab632d14edd37998f73224cfd9fc3` |
| s5-import-callers.csv | `90a7c89a332e800247ca15c45ccdee4c1c759f8713c81f1f03985a9cd9347703` |
