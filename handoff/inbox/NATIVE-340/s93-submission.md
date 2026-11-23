# NATIVE-340 s93 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定候选：#450 @ 05917da0d1002cc17640c123cf67cd684117863e；主干基线 `54d8dd1d`
- 本轮 head：见 #13

## ① parser 三处编码列（在实际 `cli_tables.read` 路径修）

新增 `CODED_COLUMNS`（按 **表+列** 键，不再只按表）与 `decode_column()`；
`read()` 解析时给每行挂 `_decoded`。读表对照：

| 位置 | 原始值 | parser 解码 | PEReader |
| --- | ---: | --- | --- |
| MemberRef[1].Class | 17 | TypeRef[2] | TypeReference[2] |
| CustomAttribute[1].Type | 18 | MemberRef[2] | MemberReference[2] |
| AspenHelper MethodImpl[1].MethodBody | 8 | MethodDef[4] | MethodDefinition[4] |
| AspenHelper MethodImpl[1].MethodDeclaration | 31 | MemberRef[15] | MemberReference[15] |

关键点：`CustomAttribute` 的 `Parent`(5 位) 与 `Type`(3 位, 2=MethodDef/3=MemberRef) 是不同编码，按表键会串味。

## ② 只读摘要复验入口

`tool/verify_il_digests.py --binary <原件> --table code/s89-il-digests.csv`：保留行身份逐行比对原件。

- 正常：`checked 167 rows, mismatches 0`，exit 0。
- 单改一条（row=4 / token=0x06000004）：`MISMATCH row=4 token=0x06000004 digest differs from original`，`mismatches 1`，**exit 1**（定位到行 + token 并拒绝）。

## ③ 19 条原生 IAT 转移逐站补齐

按 gate 的 19 条缺陷逐站补：`code/native.asm` 增 19 行（EA + 真实字节 + `JMP qword ptr [RIP+...]`），
`calls.csv` 增 19 行（`class=external`，`listing=code/native.asm#L...`，note 写 IAT thunk 槽位）；
`metrics.json` 的 `external` 228→247、`calls_sha256`/`coverage_sha256` 重算；calls.csv 559→578 行，coverage 仍 1105 行。

`omitted-sites`：**fail(19) → pass**（inputs=319、defects=0，native 67/67、VTableFixups 237/237、calli 15/15）。
gate 全量：`units pass=13 fail=0 not-applicable=0 error=0`；L1 exit 2（1105 coverage / 354 native / **578 call** / 0 gaps）。

## ④ 保留

`HeapSizes=0x00`（`#~` 流头）、两套清单、167 个 IL 摘要；PEReader 工程（`_t14/pereader`）与
`0x06000057` arg0 的静态恢复条件（缺外部调用者/委托表，需入口断点或导出清单）不变。
