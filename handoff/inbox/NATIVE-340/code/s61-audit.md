# NATIVE-340 s61 逐项核对（脚本生成）

基线：#450 head `817183580e8e59b82c3389a2cdf0a01c6ecb1e96`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 276 字节夹具（RVA 0x2400，交替 small/fat）

| 用例 | raw | virtual | file | 节数 | 错误 |
| --- | ---: | ---: | ---: | ---: | --- |
| full | 276 | 276 | 276 | 10 | `-` |
| raw_trim26 | 250 | 276 | 276 | 0 | `ValueError: EH section header at 0x24f8 (4 bytes) overruns the RAW range of .text (raw end 0x24fa): first invalid RVA 0x24fa` |
| virtual_trim26 | 276 | 250 | 276 | 0 | `ValueError: EH section header at 0x24f8 (4 bytes) overruns the VIRTUAL range of .text (virtual end 0x24fa): first invalid RVA 0x24fa` |
| file_trim26 | 276 | 276 | 250 | 0 | `ValueError: EH section header at 0x24f8 (4 bytes) overruns the FILE bytes (file length 0xfa): first invalid offset 0xfa` |

## 2. 原件 0x0600000B

| raw_end | virt_end | 单子句宽度 | 子句数 | 负载 |
| --- | --- | ---: | ---: | ---: |
| 0x4A00 | 0x4968 | 24 | 2 | 48 |

25 节 / 35 条子句：catch 7、fault 11、filter 4、finally 13。

## 3. 分支三态（候选路径值 vs 实际值）

| 运行 | jcc | taken | 候选 al | 落空 al | 实际 al | 跳过 |
| --- | --- | --- | ---: | ---: | ---: | --- |
| original | jge | False | 1 | 0 | 0 | True |
| jge->jl | jl | True | 1 | 0 | 1 | False |
| al=1->2 | jge | False | 2 | 0 | 0 | True |

## 4. 控制项（11）

- PASS：full 276 bytes reads 10 sections, last RVA 0x24F8
- PASS：file 250 bytes -> FILE error at offset 0xFA
- PASS：raw 250 bytes -> RAW error, first invalid RVA 0x24FA
- PASS：virtual 250 bytes -> VIRTUAL error, first invalid RVA 0x24FA
- PASS：real image: 25 sections / 35 clauses
- PASS：0x0600000B reports raw_end 0x4A00 and virt_end 0x4968
- PASS：0x0600000B reports clause width 24 and 2 clauses
- PASS：every section inside raw/virtual/file
- PASS：branch three states: actual AL 0/1/0
- PASS：branch three states: skipped true/false/true
- PASS：imm injection keeps candidate AL 2 but actual AL 0

