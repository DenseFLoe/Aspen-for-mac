# NATIVE-341 s9 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 成因
首轮只覆盖 AssistVw，因为覆盖清单是「人工挑函数」而不是「从原件元数据枚举」：没有脚本把 .pdata BeginAddress、PE 入口、可执行导出合成锚点集，也没有把每个锚点映射到实际反汇编行。于是旧报告的函数数与原件结构脱节，逐址调用/数据引用无法核对。

# 复现命令
~~~sh
python -B tool/native_anchor_inventory.py --binary issue-materials/338/Happ.dll   # 或 341
# 输出 anchors=1522（338）/1665（341），与任务卡一致；再与旧报告的函数清单对照即见覆盖缺口的来源
~~~

# 流程修正
- tool/native_anchor_inventory.py：按 PE 结构（.pdata BeginAddress + 入口 + 可执行导出）枚举锚点，任何同类件可复用。
- tool/ghidra_scripts/ExportEvidence.java：逐函数导出 EA / SIZE / 真实字节 / INSTR / 伪 C，输出头不含工具名。
- tool/native_evidence.py：把锚点映射到反汇编行；每条锚点必须落在已解码指令上，否则显式记 gap 并写恢复条件；calls 由 PE 导入槽位 + 原始字节扫描生成，并断言 IAT 站点数 == external 行数。

# 自证
- 本轮 1,665 个锚点逐址映射；IAT 站点与外呼逐条相等（见 metrics.json 的 iat_sites/iat_registered）。
- 判定命令输出见下；checker exit 0（0 缺口）；间接转移逐址列入 code/indirect.csv。

# 下一批如何自动避免
门禁一条：原生件交付前必须跑锚点枚举脚本，断言 coverage 行覆盖 anchor 全集且每条 listing 行真实存在（工具已内置断言）。

# 本次补丁（2）
上游复跑报 `evidence lines outside file` 的根因是**取件路径**：contents API 对 >1MB 文件返回空 body，而 Git blob 完整（3,015,720 B / 84,757 行，blob sha da555b15）。代码/asm 已按函数边界切成 <1MB 分片并同步改写行号引用。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 2015 |
| 原件锚点 | 1665 |
| coverage 行（缺口） | 2015（0） |
| IAT 调用/跳转站点 | 3461 |
| 已登记 external | 3461 |
| 数据引用 data | 948 |
| 未决 unresolved | 0 |

## 判定命令与原始输出

~~~
checked 2015 coverage rows, 2015 tool-native entries, 4409 call records, 0 declared gaps
~~~

exit code: 0

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
