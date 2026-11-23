# NATIVE-340 s81 逐项核对（脚本生成）

基线：#450 @ `858a23f9070d0a99555b695082d4dc57a4c13258`（主干 6f39d818）。

## 1. VTableFixups 位名（ECMA）

| 槽 | 条目 | dwFlags | 位名 | token |
| --- | ---: | --- | --- | --- |
| 0x19600 | 168 | 0x2 | COR_VTABLE_64BIT | 0x06000056 |
| 0x19608 | 167 | 0xA | COR_VTABLE_64BIT | COR_VTABLE_CALL_MOST_DERIVED | 0x06000056 |
| 0x19610 | 170 | 0x2 | COR_VTABLE_64BIT | 0x06000057 |
| 0x19618 | 169 | 0xA | COR_VTABLE_64BIT | COR_VTABLE_CALL_MOST_DERIVED | 0x06000057 |

## 2. 真实 MethodImpl 样本

| 文件 | 行 | Declaration | Body | Body 名 | 往返 |
| --- | ---: | --- | --- | --- | --- |
| dl/053_AspenHelper.dll | 1 | MemberRef[16] (raw 31) | MethodDef[5] (raw 8) | Save | True |

## 3. 列宽推导（按编码定义）

HeapSizes 字节 = 0x01：#Strings 4 字节, #GUID 2 字节, #Blob 2 字节。

| 列 | tag 位 | 阈值 | 最大行数 | 宽度 | 推导 |
| --- | ---: | ---: | ---: | ---: | --- |
| MemberRefParent | 3 | 8192 | 563 | 2 | count < 2**(16-3)=8192 -> 2 bytes |
| TypeDefOrRef | 2 | 16384 | 563 | 2 | count < 2**(16-2)=16384 -> 2 bytes |
| MethodDefOrRef | 1 | 32768 | 188 | 2 | count < 2**(16-1)=32768 -> 2 bytes |
| CustomAttributeType | 3 | 8192 | 188 | 2 | count < 2**(16-3)=8192 -> 2 bytes |
| plain index (e.g. TypeDef.FieldList) | 0 | 65536 | 786 | 2 | count < 2**16=65536 -> 2 bytes |

## 4. 每 token IL 指纹（从原件重算）

167 个 token，全部 64 位；与 s77 声明表逐条比对全部一致（比对不是信任来源）。

## 5. 控制项（13）

- PASS：0x02 is COR_VTABLE_64BIT and 0x08 is COR_VTABLE_CALL_MOST_DERIVED
- PASS：four slots keep raw 0x2/0xA/0x2/0xA and tokens 0x56/0x56/0x57/0x57
- PASS：0xA renders as 64BIT|CALL_MOST_DERIVED
- PASS：MethodImpl sample row decodes to Declaration=MemberRef[16]
- PASS：MethodImpl sample row decodes to Body=MethodDef[5] (Save)
- PASS：one-based RIDs round-trip through the encoder
- PASS：HeapSizes byte is 0x01: only #Strings is a 4-byte index
- PASS：coded-index widths follow count < 2**(16-tag_bits)
- PASS：167 IL tokens recomputed from the binary
- PASS：every recomputed root is 64 hex chars
- PASS：recomputed roots equal the declared s77 table (167/167)
- PASS：11 sites preserved
- PASS：35 EH clauses preserved

