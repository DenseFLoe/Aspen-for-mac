# NATIVE-340 s81 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定候选：#450 @ 858a23f9070d0a99555b695082d4dc57a4c13258；主干基线 `6f39d818`
- 本轮 head：见 #13

## ① VTableFixups 位名（ECMA）

| 位 | 名称 |
| --- | --- |
| 0x01 | COR_VTABLE_32BIT |
| **0x02** | **COR_VTABLE_64BIT** |
| 0x04 | COR_VTABLE_FROM_UNMANAGED |
| **0x08** | **COR_VTABLE_CALL_MOST_DERIVED** |

四槽原值与 token 不变（`code/s81-vtable-flags.csv`）：

| 槽 | dwFlags | 位名 | token |
| --- | --- | --- | --- |
| 0x19600 | 0x2 | COR_VTABLE_64BIT | 0x06000056 |
| 0x19608 | 0xA | COR_VTABLE_64BIT \| COR_VTABLE_CALL_MOST_DERIVED | 0x06000056 |
| 0x19610 | 0x2 | COR_VTABLE_64BIT | 0x06000057 |
| 0x19618 | 0xA | COR_VTABLE_64BIT \| COR_VTABLE_CALL_MOST_DERIVED | 0x06000057 |

## ② 真实 MethodImpl 样本（一基 RID）

样本 `dl/053_AspenHelper.dll`，MethodImpl 表 1 行：

| 列 | 原始 | 解码 |
| --- | ---: | --- |
| MethodDeclaration | 31 | **MemberRef[16]**（`.ctor`） |
| MethodBody | 8 | **MethodDef[5]**（`Save`，token 0x06000005） |

RID 从 1 起；编码器往返 `encode(decode(raw)) == raw` 通过（`code/s81-methodimpl-sample.csv`）。
真件 `WrapSaveMergeNNFiles.dll` 的 MethodImpl 表仍为 0 行，故用该真实含 MethodImpl 的样本验证解码。

## ③ 列宽推导（按编码定义，不只结论）

`HeapSizes` 字节 = **0x01**：仅 `#Strings` 为 4 字节索引（bit0 置位，流 ≥ 0x10000）；`#GUID`/`#Blob` 为 2 字节。

编码索引：2 字节形式在 `count < 2**(16 - tag_bits)` 时成立，否则 4 字节。

| 列 | tag 位 | 阈值 | 本件最大行数 | 宽度 | 推导 |
| --- | ---: | ---: | ---: | ---: | --- |
| MemberRefParent | 3 | 8192 | 563 | 2 | 563 < 2^13 |
| TypeDefOrRef | 2 | 16384 | 563 | 2 | 563 < 2^14 |
| MethodDefOrRef | 1 | 32768 | 188 | 2 | 188 < 2^15 |
| CustomAttributeType | 3 | 8192 | 786 | 2 | 786 < 2^13 |
| 普通索引（如 FieldList） | 0 | 65536 | 786 | 2 | 786 < 2^16 |

## ④ 每 token 完整 IL 指纹（从原件重算）

`code/s81-il-fingerprints.csv`：167 个 IL token 全部从原件方法体重算 64 位 SHA-256（不是比对表里已有值）；
与 s77 声明表逐条比对 167/167 一致（比对只作一致性检查，取值来源是原件）。

## ⑤ 保留

11 个 `0x06000056` 站点、35 条 EH 子句、arg0（`ldarg.0 -> stloc.0` 函数指针）的恢复条件不变。

## ⑥ qa gate 3517b5ed

三档计数与逐条 defect 见 #13；`advisory declared set shrank` 若无出现则记「本轮无收缩告警」。
