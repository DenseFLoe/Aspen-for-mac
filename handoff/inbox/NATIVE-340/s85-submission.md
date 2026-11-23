# NATIVE-340 s85 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定候选：#450 @ f8470240a320318bd82ef58f9f0e84e311022be1；主干基线 `0554621e`
- 本轮 head：见 #13

## ① 四槽位名（corhdr.h，已更正）

| 位 | 名称 |
| --- | --- |
| 0x01 | COR_VTABLE_32BIT |
| 0x02 | COR_VTABLE_64BIT |
| 0x04 | COR_VTABLE_FROM_UNMANAGED |
| **0x08** | **COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN** |
| **0x10** | **COR_VTABLE_CALL_MOST_DERIVED** |

| 槽 | dwFlags | 位名 | token |
| --- | --- | --- | --- |
| 0x19600 | 0x2 | COR_VTABLE_64BIT | 0x06000056 |
| 0x19608 | 0xA | COR_VTABLE_64BIT \| COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN | 0x06000056 |
| 0x19610 | 0x2 | COR_VTABLE_64BIT | 0x06000057 |
| 0x19618 | 0xA | COR_VTABLE_64BIT \| COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN | 0x06000057 |

`code/s81-vtable-flags.csv` 已按此改正（上轮把 0xA 写成 CALL_MOST_DERIVED、且称「没有 0x10 位」是错的）。

## ② 真实 MethodImpl 样本 + 一基 RID（raw >> tag_bits）

样本 `dl/053_AspenHelper.dll`，SHA-256 `5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f`。

| 列 | 原始 | tag_bits | RID = raw >> tag | PEReader |
| --- | ---: | ---: | ---: | --- |
| MethodBody | 8 | 1 | **4** | MethodDefinition[4]（Finalize） |
| MethodDeclaration | 31 | 1 | **15** | MemberReference[15]（Finalize） |

## ③ PEReader 端点核对（不用互逆公式作唯一证据）

用 `System.Reflection.Metadata.PEReader`（.NET 9，独立实现）读同一份字节：

- 样本 SHA-256 双方一致（`5b6e3444…`）；MethodImpl 行 1：body=MethodDefinition[4]、decl=MemberReference[15]，与自建解码 `raw >> 1` 完全一致。
- 上一轮用 `encode(decode(raw))==raw` 往返自证——该法对互逆的错误公式同样成立；本轮改为**独立实现对照**，并暴露出我上轮的 RID 公式多加了 1（曾报 MemberRef[16]/MethodDef[5]）。

## ④ 三种编码边界 + 四类 token 差异

`code/s85-column-widths.csv` 逐列计算（HeapSizes 从 `#~` 流头读，非代码常量）：本件 HeapSizes=0x01（仅 #Strings 4 字节），coded 阈值 8192/16384/32768，全部 2 字节。

| 空间 | 本侧行数 | PEReader 行数 | 额外 | 缺失 | 重复 | 摘要不符 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| MemberRefParent | 109 | 109 | 0 | 0 | 0 | 0 |
| MethodDefOrRef（样本） | 1 | 1 | 0 | 0 | 0 | 0 |
| CustomAttributeType | 786 | 786 | 0 | 0 | 0 | 0 |

## ⑤ 保留

167 个 IL 摘要（从原件重算）、11 处调用、35 条 EH 子句、arg0（`ldarg.0 → stloc.0` 函数指针）的恢复条件。

## 判定

qa gate 3517b5ed 三档计数与逐条 defect 见 #13。

## qa gate 5ea02b3e（新版，29 文件 / MANIFEST 93f33962…）

`omitted-sites` 报 19 条清单缺失，属**历史遗留**（原件有 thunk、清单无边），本轮未新增；修复需补反汇编而非改 calls.csv。

复核：`rva=0x4711` 原件为 `ff 25 e9 18 00 00`（jmp qword [riprel] -> IAT 0x6000 = KERNEL32!QueryPerformanceCounter），`code/native.asm` 中无该地址行、`calls.csv` 无该 RVA 行 -> 19 条同源。

gate 读数：inputs=319（native 67 期望/48 已登记/19 缺失；VTableFixups 237/237；托管 calli 15/15），`units pass=12 fail=1(omitted-sites, 19) not-applicable=0 error=0`，L1 exit 2。
