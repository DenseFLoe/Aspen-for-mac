# NATIVE-340 s49 逐项核对（脚本生成）

基线：#450 head `c1a0c0850352360315ab5842cbd00e3ce6f7b7f9`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 分支注入（保留）

| 字段 | 基线 | jge→jl | imm 1→2 |
| --- | --- | --- | --- |
| jcc_cc | jge | jl | jge |
| jcc_taken | False | True | False |
| al_immediates | {"0x28FD": 1, "0x28F9": 0} | {"0x28FD": 1, "0x28F9": 0} | {"0x28FD": 2, "0x28F9": 0} |
| al_for_slot | 0 | 1 | 0 |
| slot_skipped | True | False | True |

## 2. EH 链（成对：整链读完 / 明确报错）

| 用例 | 结果 |
| --- | --- |
| chain 1: all 1 sections read, last.more=False | PASS |
| chain 2: all 2 sections read, last.more=False | PASS |
| chain 9: all 9 sections read, last.more=False | PASS |
| chain 10: all 10 sections read, last.more=False | PASS |
| broken chain raises instead of partial read | PASS |
| injection jge->jl flips the branch | PASS |
| injection imm 1->2 reaches the evidence table | PASS |
| baseline unchanged by injections | PASS |

上游 s45-eh-chain.py 复跑：9 节 returned=9、10 节 returned=10，末节 more=False。

## 3. 幂等与受影响面

- 只改 0x20CC 一行与 5 个原生未决附表（s25-unresolved-native.csv、s33-unresolved-native.csv、s37-unresolved-native.csv、s41-unresolved-native.csv、s45-unresolved-native.csv）；说明按「切掉旧口径后缀再写一次」生成，重复运行不再追加。
- 连跑两次的摘要见 s49-submission.md（同一批文件 SHA-256 相等）。

## 4. 计数

| 指标 | 值 |
| --- | --- |
| external / boundary / unresolved | 228 / 303 / 28 |
| 未决托管 / 原生 | 13 / 15 |

