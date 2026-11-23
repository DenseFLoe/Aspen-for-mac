# NATIVE-340 s57 逐项核对（脚本生成）

基线：#450 head `53bdbfa4685c80e41ed90a0f08e3528608ea0265`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 截短夹具（原始错误文本）

| 夹具 | 结果 | 输出 |
| --- | --- | --- |
| full | OK | `OK: 10 data sections` |
| raw | ERROR | `ValueError: data section at 0x1134 (size 28) overruns the RAW range of .text (raw end 0x114c): first invalid RVA 0x114c` |
| virtual | ERROR | `ValueError: data section at 0x1134 (size 28) overruns the VIRTUAL range of .text (virtual end 0x114c): first invalid RVA 0x114c` |
| file | ERROR | `ValueError: data section at 0x1134 (size 28) overruns the FILE bytes (file length 0x114c): first invalid offset 0x114c` |
| successor | ERROR | `ValueError: section at 0x1134 declares a successor but RVA 0x1150 is outside every section` |

## 2. EH 逐节（25 节）

| 方法 | 节 | 头 kind | 头 size | 单子句宽度 | 负载 | 子句 | 类型 | more | raw_end | virt_end | file |
| --- | ---: | --- | ---: | ---: | ---: | ---: | --- | --- | --- | --- | ---: |
| 0x0600000B | 0 | 0x41 | 52 | 24 | 48 | 2 | fault,fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600000C | 0 | 0x41 | 28 | 24 | 24 | 1 | fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600000F | 0 | 0x41 | 28 | 24 | 24 | 1 | fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000013 | 0 | 0x41 | 28 | 24 | 24 | 1 | fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000019 | 0 | 0x41 | 28 | 24 | 24 | 1 | fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600001F | 0 | 0x41 | 52 | 24 | 48 | 2 | fault,fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000030 | 0 | 0x41 | 28 | 24 | 24 | 1 | catch | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000032 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000033 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000048 | 0 | 0x41 | 52 | 24 | 48 | 2 | finally,finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600004D | 0 | 0x41 | 52 | 24 | 48 | 2 | catch,catch | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000050 | 0 | 0x41 | 76 | 24 | 72 | 3 | finally,catch,catch | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000051 | 0 | 0x41 | 28 | 24 | 24 | 1 | fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000056 | 0 | 0x41 | 28 | 24 | 24 | 1 | filter | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000057 | 0 | 0x41 | 28 | 24 | 24 | 1 | filter | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000058 | 0 | 0x41 | 28 | 24 | 24 | 1 | filter | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000059 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600005B | 0 | 0x41 | 28 | 24 | 24 | 1 | filter | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600006B | 0 | 0x41 | 76 | 24 | 72 | 3 | catch,catch,finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000071 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000091 | 0 | 0x41 | 52 | 24 | 48 | 2 | fault,fault | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x06000094 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x0600009A | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x060000B3 | 0 | 0x41 | 28 | 24 | 24 | 1 | finally | False | 0x4A00 | 0x4A00 | 0x1A228 |
| 0x060000B6 | 0 | 0x41 | 52 | 24 | 48 | 2 | finally,finally | False | 0x4A00 | 0x4A00 | 0x1A228 |

子句回读 35 条：catch 7、fault 11、filter 4、finally 13（逐条见 code/s57-clauses.csv）。

## 3. 分支三态（原件 + 两项单变量注入）

| 运行 | jcc | taken | al@目标 | al@落空 | al_for_slot | slot_skipped |
| --- | --- | --- | ---: | ---: | ---: | --- |
| original | jge | False | 1 | 0 | 0 | True |
| jge->jl | jl | True | 1 | 0 | 1 | False |
| al=1->2 | jge | False | 2 | 0 | 0 | True |

## 4. 控制项（11）

- PASS：fixture full raw/virtual/file reads all sections
- PASS：fixture raw reports an explicit error
- PASS：fixture virtual reports an explicit error
- PASS：fixture file reports an explicit error
- PASS：fixture successor reports an explicit error
- PASS：real image: 25 sections, all in raw/virtual/file range
- PASS：real image: 35 clauses read back
- PASS：payload == clause_width * clauses for every section
- PASS：branch: original jge falls through to al=0 and skips
- PASS：branch: jge->jl takes the branch with al=1 and does not skip
- PASS：branch: al=1->2 keeps the fall-through but changes the immediate

