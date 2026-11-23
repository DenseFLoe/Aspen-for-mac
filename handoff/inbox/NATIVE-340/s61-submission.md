# NATIVE-340 s61 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 817183580e8e59b82c3389a2cdf0a01c6ecb1e96
- 本轮 head：见 #13

## 1. 读取顺序（先头后节）

`method_body.data_sections()` 现在先校验 **4 字节节头**的 raw / virtual / file 三条边界（各自独立报错并给首个失效位置），
再读 kind/size，最后按**申报长度**复核同一组边界。文件截到节头中间时不再 `IndexError`，而是有定位的 FILE 错误。

## 2. 五个预期值（逐条命中）

| 项 | 预期 | 实测 |
| --- | --- | --- |
| 276 字节完整夹具 | 10 节 | **10 节**（末节 RVA `0x24F8`，宽度 12/24 交替，末节 more=False） |
| 物理文件 250 字节 | FILE 位置 `0xFA` | `EH section header at 0x24f8 (4 bytes) overruns the FILE bytes (file length 0xfa): first invalid offset 0xfa` |
| 单减 raw | 首个失效 RVA `0x24FA` | `... overruns the RAW range of .text (raw end 0x24fa): first invalid RVA 0x24fa` |
| 单减 virtual | 首个失效 RVA `0x24FA` | `... overruns the VIRTUAL range of .text (virtual end 0x24fa): first invalid RVA 0x24fa` |
| 原件 `0x0600000B` | raw_end `0x4A00`、virt_end `0x4968`、宽 24、2 条 | raw_end **0x4A00**、virt_end **0x4968**、宽度 **24**、子句 **2**（payload 48 = 24×2） |

## 3. 分支三态（候选路径值 / 实际值分列）

`code/s57-branch-facts.csv`（上游读取的规范名）与 `code/s61-branch-facts.csv` 同数据：

| 运行 | jcc | taken | 候选 al（目标路径） | 落空 al | 实际 al | 跳过 |
| --- | --- | --- | ---: | ---: | ---: | --- |
| original | jge | False | 1 | 0 | **0** | **真** |
| jge->jl | jl | True | 1 | 0 | **1** | **假** |
| al=1->2 | jge | False | 2 | 0 | **0** | **真** |

主表 0x20CC 与 5 份原生附表同源 note：三态按“候选路径 al=2、实际 al=0、跳过=真”表述，
不再出现“落空 al=2 跳过”这类把候选值当实际值的句子（上游 `contradicted_tables` 为空）。

## 4. 保留项

9/10 节链（`mixed_nine=9`、`mixed_ten=10`）、两种混排（2 节、宽度 12/24）、
连续两次审计哈希一致、两套指纹从新 head 重跑逐项一致；25 节 / 35 条子句（13 finally、11 fault、7 catch、4 filter）。

## 5. 判定（真实退出码）

```
python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original <原件> --submission handoff/inbox/NATIVE-340
checked 1105 coverage rows, 354 tool-native entries, 559 call records, 0 declared gaps
exit code: 2

pwsh -NoProfile -File handoff/outbox/NATIVE-340/check-s29-446.ps1 -Original <原件> -Unit handoff/inbox/NATIVE-340
exit code: 0

PYTHONPATH=.local/pylibs python -B handoff/outbox/NATIVE-340/s57-review.py . --original <原件>
exit code: 0
```
