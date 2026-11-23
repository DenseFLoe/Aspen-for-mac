# NATIVE-340 s89 逐项核对（脚本生成）

基线：#450 @ bde39b4630809020fd972211e9b64010e13410d7（主干 2cb8a177）。

## 1. 真实表流路径的列宽（85 列）

parser 用 stream=#~、HeapSizes=0x00（从流头读）。

| 表 | 列 | 宽度 | 行数 | 规则 |
| --- | --- | ---: | ---: | --- |
| Module | Generation | 2 | 1 | fixed 2 |
| Module | Name | 2 | 1 | heap S -> 2 (HeapSizes 0x00) |
| Module | Mvid | 2 | 1 | heap G -> 2 (HeapSizes 0x00) |
| Module | EncId | 2 | 1 | heap G -> 2 (HeapSizes 0x00) |
| Module | EncBaseId | 2 | 1 | heap G -> 2 (HeapSizes 0x00) |
| TypeRef | ResolutionScope | 2 | 80 | coded tag 2 bits, max rows 80 < 2**14 -> 2 |
| TypeRef | TypeName | 2 | 80 | heap S -> 2 (HeapSizes 0x00) |
| TypeRef | TypeNamespace | 2 | 80 | heap S -> 2 (HeapSizes 0x00) |
| TypeDef | Flags | 4 | 563 | fixed 4 |
| TypeDef | TypeName | 2 | 563 | heap S -> 2 (HeapSizes 0x00) |
| TypeDef | TypeNamespace | 2 | 563 | heap S -> 2 (HeapSizes 0x00) |
| TypeDef | Extends | 2 | 563 | coded tag 2 bits, max rows 563 < 2**14 -> 2 |
| TypeDef | FieldList | 2 | 563 | table 4 rows 698 < 65536 -> 2 |
| TypeDef | MethodList | 2 | 563 | table 6 rows 188 < 65536 -> 2 |
| Field | Flags | 2 | 698 | fixed 2 |
| Field | Name | 2 | 698 | heap S -> 2 (HeapSizes 0x00) |
| Field | Signature | 2 | 698 | heap B -> 2 (HeapSizes 0x00) |
| MethodDef | RVA | 4 | 188 | fixed 4 |
| MethodDef | ImplFlags | 2 | 188 | fixed 2 |
| MethodDef | Flags | 2 | 188 | fixed 2 |
| ... | ... | ... | ... | 全表 85 列见 code/s89-column-widths.csv |

## 2. 三类阈值配对

| 空间 | tag 位 | 低 | 宽 | 高 | 宽 |
| --- | ---: | ---: | ---: | ---: | ---: |
| MemberRefParent | 3 | 8191 | 2 | 8192 | 4 |
| TypeDefOrRef | 2 | 16383 | 2 | 16384 | 4 |
| MethodDefOrRef | 1 | 32767 | 2 | 32768 | 4 |

## 3. IL 摘要四类差异

| 类别 | 数量 | 样例 |
| --- | ---: | --- |
| missing | 0 | - |
| extra | 0 | - |
| duplicate | 0 | - |
| content_diff | 0 | - |

167 条摘要带行号（code/s89-il-digests.csv），建字典前先查重复。

## 4. 控制项（14）

- PASS：parser stream #~, HeapSizes=0x00 read from the stream header
- PASS：all heap indexes are 2 bytes
- PASS：layout exposes 85 columns / 25 tables
- PASS：MethodDef row size equals the column sum
- PASS：MemberRef row size equals the column sum
- PASS：CustomAttribute row size equals the column sum
- PASS：8191/8192 -> 2/4
- PASS：16383/16384 -> 2/4
- PASS：32767/32768 -> 2/4
- PASS：digest table keeps row identity
- PASS：no duplicate token before building the map
- PASS：four categories all zero
- PASS：11 sites preserved
- PASS：35 EH clauses preserved

