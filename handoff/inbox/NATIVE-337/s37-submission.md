# NATIVE-337 s37 提交

- 基线 #445 @ bd362e3f；本轮把 161 条二跳按「原件 + 现主表」整体重生成。

## 计数（由实际表生成）

| 项 | 值 |
| --- | --- |
| 覆盖行 | 307 |
| calls.csv 行 | 684 |
| external / data / unresolved | 524 / 48 / 112 |
| 直接 IAT 站点 | 363 |
| 二跳附表行 | 161 |
| COM 附表行 | 64 |
| 0x4706 分派行 | 16 |

## 161 条重生成

- 首跳补 17、IAT+导入符号补 18、calls_row 补 161；四列同源（原件解码 → 主表行号）。
- 0x12da：原件宿主 0x11E0 / 候选宿主 0x12BD（两份附表均已改为 0x12BD，两列并列）。

## 指纹

calls.csv d6f82133e5187d15efbaf5f3d2e87944cb6d5b60088516b3fa140eabbe569c04
coverage.csv 3afe1c2a87c9e70c95a8a9216d5f68798fd14e934ff75fa8dc49d41fee00fb43
s37-two-hop.csv 72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf

## 未决

112 条 unresolved 保留各自恢复条件；申报入口缺口 0 ≠ 去重后无待核。
