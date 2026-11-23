# NATIVE-340 s85 逐项核对（脚本生成）

基线：#450 @ `f8470240a320318bd82ef58f9f0e84e311022be1`（主干 0554621e）。

## 1. 四槽位名（corhdr.h）

| 位 | 名称 |
| --- | --- |
| 0x01 | COR_VTABLE_32BIT |
| 0x02 | COR_VTABLE_64BIT |
| 0x04 | COR_VTABLE_FROM_UNMANAGED |
| 0x08 | COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN |
| 0x10 | COR_VTABLE_CALL_MOST_DERIVED |

| 槽 | dwFlags | 位名 | token |
| --- | --- | --- | --- |
| 0x19600 | 0x2 | COR_VTABLE_64BIT | 0x06000056 |
| 0x19608 | 0xA | COR_VTABLE_64BIT | COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN | 0x06000056 |
| 0x19610 | 0x2 | COR_VTABLE_64BIT | 0x06000057 |
| 0x19618 | 0xA | COR_VTABLE_64BIT | COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN | 0x06000057 |

## 2. MethodImpl 样本：自建解码 vs PEReader

样本 dl/053_AspenHelper.dll，SHA-256 `5b6e34442388e8a193fd1d2a44f345e3310690c76ea7e83192fa97455728ff4f`（PEReader 复算 5b6e34442388e8a1）。

| 列 | 原始 | tag_bits | RID（raw >> tag_bits） | PEReader |
| --- | ---: | ---: | ---: | --- |
| MethodBody | 8 | 1 | 4 | MethodDef[4] |
| MethodDeclaration | 31 | 1 | 15 | MemberRef[15] |

## 3. 逐列宽度（流头 HeapSizes + 行数阈值）

| 列 | 类型 | tag 位 | 行数 | 阈值 | 宽度 | 推导 |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| MemberRefParent | coded | 3 | 563 | 8192 | 2 | rows(563) < 2**(16-3)=8192 -> 2 bytes |
| TypeDefOrRef | coded | 2 | 563 | 16384 | 2 | rows(563) < 2**(16-2)=16384 -> 2 bytes |
| MethodDefOrRef | coded | 1 | 188 | 32768 | 2 | rows(188) < 2**(16-1)=32768 -> 2 bytes |
| CustomAttributeType | coded | 3 | 188 | 8192 | 2 | rows(188) < 2**(16-3)=8192 -> 2 bytes |
| MethodDef.MethodList | index | 0 | 188 | 65536 | 2 | table rows 188 < 65536 -> 2 bytes |
| MemberRef.Name | index | 0 | 698 | 65536 | 2 | table rows 698 < 65536 -> 2 bytes |
| TypeDef.FieldList | index | 0 | 698 | 65536 | 2 | table rows 698 < 65536 -> 2 bytes |

## 4. 四类 token 差异（对 PEReader）

| 空间 | 本侧行数 | PEReader 行数 | 额外 | 缺失 | 重复 | 摘要不符 |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| MemberRefParent | 109 | 109 | 0 | 0 | 0 | 0 |
| MethodDefOrRef | 1 | 1 | 0 | 0 | 0 | 0 |
| CustomAttributeType | 786 | 786 | 0 | 0 | 0 | 0 |

## 5. 控制项（14）

- PASS：0x08 is FROM_UNMANAGED_RETAIN_APPDOMAIN and 0x10 is CALL_MOST_DERIVED
- PASS：0xA renders as 64BIT|RETAIN_APPDOMAIN
- PASS：four slots keep 0x2/0xA/0x2/0xA and tokens 56/56/57/57
- PASS：sample sha256 matches PEReader (5b6e34442388e8a1...)
- PASS：self decode Body RID 4 == PEReader 4
- PASS：self decode Declaration RID 15 == PEReader 15
- PASS：HeapSizes read from the stream header is 0x01
- PASS：per-column widths follow the encoding rule
- PASS：MemberRefParent has no extra/missing/duplicate/digest diffs
- PASS：MethodDefOrRef sample has no diffs
- PASS：CustomAttributeType has no extra/missing/duplicate/digest diffs
- PASS：167 IL digests recomputed
- PASS：11 sites preserved
- PASS：35 EH clauses preserved

