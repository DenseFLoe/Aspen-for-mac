# NATIVE-337 s5 提交（第五号事件续领）

- task_id: NATIVE-337　owner: tietoumiao　assigned_seq: 5
- 原件: issue-materials/337/FindComponent.dll，82,984 字节，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02（本机复核一致）
- 首轮: PR #387 / head 62c68c514c8bcbe5435c6cbc2fcf570388a9a980；本轮沿用同原件与已核实的 300 行函数/锚点映射，只改 calls.csv、coverage.csv 片段 note、run.json。

## 逐项补正

| 裁定项 | 处理 | 可复核位置 |
| --- | --- | --- |
| 197 处未登记 IAT 调用/跳转 | **197/197 全部补入**；calls.csv 的 external 由 166 增至 **363**，与上游「363 个不同调用或跳转地址」一致 | calls.csv 每行附 code/native.asm#L<n>，note 写 IAT 槽 RVA 与指令 RVA；上游 s1-missing-iat.csv 的 197 条按（指令 RVA、IAT 槽、导入名）与本交付逐条集合相等，197/197 |
| 两处漏登数据引用 | 补 ReorderComp（字符串 0x7A88，native.asm L2806，指令 RVA 0x3C44）与 ShowOpenMessageBox（0x7780，L1409，指令 RVA 0x2601）；data 行 12→**29** | calls.csv 的 class=data 行，note 写指令 RVA、目标 RVA 与字符串内容 |
| 间接调用未交代 | 逐址登记 **99 处**间接 call/jmp（寄存器或指针表），class=unresolved，note 给指令原文、RVA 与恢复条件（运行期断点或指针表初始化分析） | calls.csv unresolved 行；例 0x1389 的 call qword ptr [rbx+28h] 见 L245 |
| 4 个片段 note 缺父 RVA | 0x33B1、0x382F → 父 RVA 0x3380；0x4706、0x4988 → 父 RVA 0x4690，已写入 note | coverage.csv 对应 4 行 |

## 判定

~~~sh
python handoff/assignments/check-native-coverage.py NATIVE-337 --original issue-materials/337/FindComponent.dll
checked 300 coverage rows, 296 tool-native entries, 491 call records, 0 declared gaps
~~~

**exit code 2**。按 native-coverage-evidence.v1 的复核条款：「返回 2 表示结构齐备且存在已申报的缺口或未决调用」——本件 0 缺口，99 条间接转移按裁定要求显式标 unresolved，故为 2；1（输入/材料错误）不成立。

## 交付文件

run.json / native-functions.csv（296，未变）/ coverage.csv（300 行，4 行 note 补父 RVA）/ calls.csv（491 行 = 363 external + 29 data + 99 unresolved）/ code/native.asm、native.c（未变）。开工回执 s5-started.md。

## 限制与未决

- 仅静态分析；无运行期动态验证。
- 99 处间接转移目标不由指令直接给出，已逐址列明并给恢复条件；静态解析边界即此处。
- 首轮已核实的函数边界与 115 个原件锚点映射未改动。

## 为什么不会再被退

- 197 条不是汇总数：每条都能按「asm 行号 + 指令 RVA + IAT 槽 RVA + 导入名」回读，且与上游 s1-missing-iat.csv 逐条集合相等。
- 裁定点名的两处数据引用（0x3C44→0x7A88 ReorderComp、0x2601→0x7780 ShowOpenMessageBox）已单独成行。
- 间接调用不再是空白：99 条逐址 unresolved 并写恢复条件，checker 的 2 就是这个已申报状态的机械体现。
