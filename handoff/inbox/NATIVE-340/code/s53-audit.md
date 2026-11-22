# NATIVE-340 s53 逐项核对（脚本生成）

基线：#450 head `ac9d6b69cdcfe99f9b2147e0c8c12f01787bae93`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. EH 各节逐节对照（25 节，全部 in_range）

| 方法 | 节 | RVA | size | entry | clauses | more | 所在节 | 节末 |
| --- | ---: | --- | ---: | ---: | ---: | --- | --- | --- |
| 0x0600000B | 0 | 0x11F0 | 52 | 48 | 2 | False | .text | 0x4A00 |
| 0x0600000C | 0 | 0x117C | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x0600000F | 0 | 0x1294 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000013 | 0 | 0x12F4 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000019 | 0 | 0x1368 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x0600001F | 0 | 0x17B8 | 52 | 48 | 2 | False | .text | 0x4A00 |
| 0x06000030 | 0 | 0x34EC | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000032 | 0 | 0x3568 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000033 | 0 | 0x35F4 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000048 | 0 | 0x3BF0 | 52 | 48 | 2 | False | .text | 0x4A00 |
| 0x0600004D | 0 | 0x3C64 | 52 | 48 | 2 | False | .text | 0x4A00 |
| 0x06000050 | 0 | 0x3D34 | 76 | 72 | 3 | False | .text | 0x4A00 |
| 0x06000051 | 0 | 0x3DB4 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000056 | 0 | 0x3E30 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000057 | 0 | 0x3E74 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000058 | 0 | 0x3EBC | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000059 | 0 | 0x3FC0 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x0600005B | 0 | 0x3F60 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x0600006B | 0 | 0x42C8 | 76 | 72 | 3 | False | .text | 0x4A00 |
| 0x06000071 | 0 | 0x44BC | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x06000091 | 0 | 0x1878 | 52 | 48 | 2 | False | .text | 0x4A00 |
| 0x06000094 | 0 | 0x1900 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x0600009A | 0 | 0x196C | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x060000B3 | 0 | 0x3360 | 28 | 24 | 1 | False | .text | 0x4A00 |
| 0x060000B6 | 0 | 0x33EC | 52 | 48 | 2 | False | .text | 0x4A00 |

## 2. 控制项（12）

- PASS：real image: all 25 EH sections are inside their PE section mapping
- PASS：real image: size == 4 + entry*clauses for every section
- PASS：real image: one section per EH method (25/25)
- PASS：positive 9-section chain: RVA/size/clauses/more all match
- PASS：positive 10-section chain: RVA/size/clauses/more all match
- PASS：negative: 4 bytes past the section mapping raises
- PASS：negative: chain that leaves the mapped section raises
- PASS：mixed fat|0x80 + small: 2 sections, entries 24/12, clauses 1/1, more True/False
- PASS：mixed small|0x80 + fat: 2 sections, entries 12/24, clauses 1/1, more True/False
- PASS：injection jge->jl: cc/taken/al/skip change
- PASS：injection imm 1->2 reaches the table
- PASS：baseline: skip on the writable .data slot

## 3. 分支事实（由解码生成）

| 字段 | 基线 | jge→jl | imm 1→2 |
| --- | --- | --- | --- |
| jcc_cc | jge | jl | jge |
| jcc_taken | False | True | False |
| al_for_slot | 0 | 1 | 0 |
| slot_skipped | True | False | True |

