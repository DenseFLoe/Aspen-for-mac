# NATIVE-340 s45 反例注入与 EH 扩展（脚本生成）

基线：#450 head `106eb83d05ac50c9e14e7eb079014857a9117ab3`；原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。

## 1. 反例注入（同一输入，改一个字节）

| 注入 | 条件码 | 取跳 | 目标 | AL 立即数 | al_for_slot | 消费端跳过 |
| --- | --- | --- | --- | --- | --- | --- |
| 基线 | `jge` | False | `0x28FD` | `{"0x28F9": 0, "0x28FD": 1}` | 0 | **True** |
| 条件码 jge→jl | `jl` | True | `0x28FD` | `{"0x28F9": 0, "0x28FD": 1}` | 1 | **False** |
| 返回立即数 1→2 | `jge` | False | `0x28FD` | `{"0x28F9": 0, "0x28FD": 2}` | 0 | **True** |

结论：条件码、比较操作数、两条分支的 AL 返回值都由字节解出；改 0x28F7 的 opcode 或 0x28FE 的立即数，证据表随之变化，说明生成器没有把结论写死。

## 2. PE 节头 Characteristics ≠ 进程内存页保护

- `Characteristics` = 文件内节属性（本件 `0xC0000040`，符号位置位）；判据读的是它。
- `页保护` = 运行期 `PAGE_*`（VirtualProtect/VirtualQuery），文件里没有编码；本条只对文件属性与静态分支下结论，不对运行期页保护下结论。

## 3. EH 读器扩展（ECMA-335）

- small（12B `u2/u2/u1/u2/u1/u4`）与 fat（24B）两种子句布局；两处 MoreSects 位分属不同结构——方法头 flags 的 CorILMethod_MoreSects=**0x8**（是否有数据节），数据节 kind 字节的 COR_ILMETHOD_SECT MoreSects=**0x80**（是否还有下一节），0x40=FatFormat；逐个读取已声明的节；
- 校验 try/handler 范围必须落在 IL 内，越界拒绝；
- 遇到支持范围外的节类型，抛 `UnsupportedSection` 并报出具体 RVA/kind/size，该件停止判定。

合成测试 9 项 + 真件 5 项 + 注入断言 10 项，共 26 条控制：全部 PASS

## 4. 计数

| 指标 | 值 |
| --- | --- |
| external / boundary / unresolved | 228 / 303 / 28 |
| 未决托管 / 原生 | 13 / 15 |

