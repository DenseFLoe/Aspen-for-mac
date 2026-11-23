# NATIVE-340 s77 提交

- 分支：tietoumiao/native-340-s33（前移 #450，不新开 PR）
- 上轮固定 head：#450 @ 3b440bf0a4bf207d479eccc148232062a7f1a6a0；主干基线 `581aa65b`
- 本轮 head：见 #13

## ① 列宽规则（编码标记位）

规则（ECMA-335 II.24.2.6）：简单索引在 `count < 2**16` 时 2 字节、否则 4 字节；编码索引带
`tag_bits` 位 tag，整合行空间 `count << tag_bits`，故 2 字节形式在 `count < 2**(16 - tag_bits)` 时成立。

| 配对 | tag_bits | 边界 | 结果 |
| --- | ---: | --- | --- |
| 8191 / 8192 | 3 (MemberRefParent) | 0x1FFF / 0x2000 | **2 / 4 字节** |
| 16383 / 16384 | 2 (TypeDefOrRef) | 0x3FFF / 0x4000 | **2 / 4 字节** |
| 32767 / 32768 | 1 (MethodDefOrRef) | 0x7FFF / 0x8000 | **2 / 4 字节** |
| 65535 / 65536 | 0 (普通索引) | 0xFFFF / 0x10000 | **2 / 4 字节** |

真件：MemberRefParent(tag 3) 最大 563 行、TypeDefOrRef(tag 2) 563、MethodDefOrRef(tag 1) 188 → 全部 2 字节（`code/s77-real-widths.csv`）。

## ② MethodImpl 同型两方法正负绑定

真件 `MethodImpl` 表 0 行，故用同型样本（同签名）做正负配对：声明列/实现列按 **MethodDefOrRef** 解码。

| 方法 | 形状 | 绑定 |
| --- | --- | --- |
| 0x06000100 | same-shape | 无（未被声明） |
| 0x06000101 | same-shape | **有（声明 0x06000100 → 实现 0x06000101）** |
| 0x06000102 | same-shape | 无 |

## ③ 每 token 完整 IL 指纹

`code/s77-il-fingerprints.csv`：**167 个 IL token** 全部重算完整 64 位 SHA-256（不是抽样），同表带
`access = ACCESS[flags & 0x7]`。0x06000056 与 0x06000057 指纹相同：
cf6b47445b3281297d160b230f3d5a4c08006679b0b937098c432073b5ee0b0d。

## ④ VTableFixups 四个修补槽

CLI header VTableFixups 目录 = **0x16600 / 0x768**，共 **237** 条 `{RVA, Count, Flags}`：

| 槽 | 条目 | 块 RVA | Count | **dwFlags** | 位含义 | 初值 |
| --- | ---: | --- | ---: | --- | --- | --- |
| 0x19600 | 168 | 0x19600 | 1 | **0x2** | COR_VTABLE_64BIT | 0x06000056 |
| 0x19608 | 167 | 0x19608 | 1 | **0xA** | 64BIT\|CALL_MOST_DERIVED | 0x06000056 |
| 0x19610 | 170 | 0x19610 | 1 | **0x2** | COR_VTABLE_64BIT | 0x06000057 |
| 0x19618 | 169 | 0x19618 | 1 | **0xA** | 64BIT\|CALL_MOST_DERIVED | 0x06000057 |

本模块可追踪的生产者＝VTableFixups 目录本身（CLR 加载/首次调用时把槽改写为方法入口）；
未见模块内 IL 写入者；恢复条件＝运行期槽读写断点或 CLR fixup 跟踪（行为测试留 Windows 阶段）。

## 保留与判定

11 站点、35 个 EH 子句、双审计、两套指纹（receipt 与 round）从新 head 重跑。

```
check-native-coverage.py  exit 2   1105 / 354 / 559 / 0（未决 13 托管 + 15 原生）
pwsh check-s29-446.ps1    exit 0
preflight（L1+L2）        exit 2（L1）+ 0 defects
```
