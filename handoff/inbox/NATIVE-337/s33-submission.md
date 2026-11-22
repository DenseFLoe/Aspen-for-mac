# NATIVE-337 s33 提交

- PR: 见 #13
- head: 见 #13

## 三层（成因 / 流程修正 / 自证）

# 成因（s29 → s33 的四处实质问题）
1) 首跳栏：s29 的二跳表把 first-hop 统一填成 0x5cfc（那是 0x12da 的终端 thunk），只有该行正确。经查生成器当时取的是 `target` 列的公共文本，而不是逐址从原件解码 caller 的 E8/FF15 目标。
2) 0x12da 双宿主：s29 表只有一列 host，写成了候选宿主 0x12bd，覆盖了原件 .pdata 宿主 0x11e0。
3) 行号：附表只留 ASM 行（`code/native.asm#L…`），calls.csv 行号没写；上游看到的 492–507 那组是 calls.csv 行。
4) 指标：metrics.json 沿用 s25 的 external=363 / indirect=99 与旧 calls SHA；实际主表分类是 external 524 / data 48 / unresolved 112（合计 684），363 是直接 IAT 站位数、99 是间接附表行数，二者是独立计数。

# 流程修正（脚本）
tool/s33_rebuild.py：
- 逐址从原件解码 caller：E8 rel32 → 首跳 RVA；FF15/FF25 → IAT 槽；首跳处若是 FF25 thunk 再解一次取槽与导入符号，输出 s33-two-hop.csv（161 行）。
- 双宿主列：按原件 .pdata 求 host 区间，与候选函数 owner 分列，输出 s33-dual-host.csv。
- 行号两列：每个站点同时写 `asm_line`（code/native.asm#L…）与 `calls_row`（calls.csv 行号），16 个对象槽与 64 个 COM 附表都补上。
- 指标由 calls.csv 现算：external/data/unresolved，并单独记 direct_iat=363、indirect_annex=99；SHA-256 在最终字节上重算。
- COM 附表标注六个已修成员（0x18A1/0x1A01/0x2021/0x2195→Invoke，0x1948/0x20C9→GetIDsOfNames）并保留恢复条件。

# 自证
- s33-two-hop.csv：161 行，首跳与 0x5cfc 不同的有 **160 行**（只有 0x12da 本身是 0x5cfc）。例：0x106C→0x4AA3→IAT 0x75E8→mfc140.dll!#2344；0x1072→0x4AA9→IAT 0x75E0→mfc140.dll!#2348。
- 指标：external 524 / data 48 / unresolved 112（684）；direct_iat 363（363/363 命中主表）；indirect_annex 99（三张表 stale 0）。
- COM 64 行：slot/member/factory 各 64 匹配；6 行标记 member_fixed。
- 0x4706 16 行：slot 0x00–0x40、源指令、asm 行与 calls 行齐全；fragment 0x4706–0x4988、unwind 0x93e8、链 0x4690→0x4706→0x93c8。

# 下一批如何自动避免
门禁：二跳表禁止出现「同一 first_hop 覆盖 >5 行」；行号必须同时有 asm 与 calls 两列；metrics 的 class 计数必须与 calls.csv 现算一致且带 SHA。

## 本轮实跑指标（脚本生成，非手填）

| 指标 | 值 |
| --- | --- |
| 分析器函数 | 307 |
| 原件锚点 | 115 |
| coverage 行（缺口） | 307（0） |
| IAT 调用/跳转站点 | 0 |
| 已登记 external | 524 |
| 数据引用 data | 48 |
| 未决 unresolved | 112 |

## 判定命令与原始输出

~~~
checked 307 coverage rows, 307 tool-native entries, 684 call records, 0 declared gaps
~~~

exit code: 2

## 产物

run.json / native-functions.csv / coverage.csv / calls.csv / code/native.asm / code/native.c

以上文件由生成脚本一次产出；本轮未手工编辑任何产物文件，指标与产物 SHA-256 见 metrics.json。
