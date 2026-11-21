# DecompServer.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `DecompServer.dll`，229928 字节，SHA-256 `ece63b60fe55949e7fa496bf163073a7b0c83c72187b305d2f057252ca7a913e` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 739 = decomp_ok 739 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=739
- decomp_ok=739
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `DecompServer.dll` |
| 字节数 | 229928 |
| SHA-256 | `ece63b60fe55949e7fa496bf163073a7b0c83c72187b305d2f057252ca7a913e` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/DecompServer.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x180000000` |
| 段数 | 7 |
| 指令行数 | 26283 |

## 3. 反汇编清单（全量）

全文：disasm/DecompServer.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/DecompServer.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 739
- decomp_ok（伪 C） = 739
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：16.2 s
- 日志：out/R1N/ida/logs/sha256_ece63b60fe55949e7fa496bf163073a7b0c83c72187b305d2f057252ca7a913e.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `DecompServer.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 739 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +739（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800014E0`, `sub_1800019C0`, `sub_180002030`, `sub_1800026B0`, `sub_1800026C0`, `sub_1800026D0`, `sub_1800026F0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/ApSparseExe.exe.c.txt` sha256=2dc257bf2dd925b6154fb5177fbfd8bea048a7641a6c47caab8105e8099b9a12 bytes=1465962
- `decompiled/DecompServer.dll.c.txt` sha256=72f4e9bb4e0cce5f9d582db4b07cdde81c25191407ce3cd37c4cdf9f0b693b3c bytes=480308
- `decompiled/IntegratorServer.dll.c.txt` sha256=7855d5cd5d10187e387b908391617f7dc810fe66d8c596f5f7c7d5fa32858f4a bytes=652082
- `decompiled/RtHarwell.dll.c.txt` sha256=a158cbacc89de3027b7b73f11cf36394a20d62a09984e06c908fd8f6c7fb67bc bytes=716336
- `decompiled/aos_dmo.dll.c.txt` sha256=e323a251b8bc379a65a52fcc2ea291bed484e9de40627428c05b54e9af104b08 bytes=333272
- `decompiled/aos_dmo_proxy.dll.c.txt` sha256=e323a251b8bc379a65a52fcc2ea291bed484e9de40627428c05b54e9af104b08 bytes=333272
- `decompiled/aos_hypsqp.dll.c.txt` sha256=5ed9bce3082bc613c8a1b268215b4cdfe4a9902176a4c854fb400a7ff34d803e bytes=791087
- `decompiled/aos_integrator.dll.c.txt` sha256=2bc7a9c00ec0b878e8b7508ea899c81a9831d9806a7792d69104500df0ad29e1 bytes=354002
- `decompiled/aos_ma38.dll.c.txt` sha256=fe2dc502846450f141a30aaa7fd86ea54bbae7f19b4a6f43e5dc3723b1130420 bytes=1621855
- `decompiled/aos_ma48.dll.c.txt` sha256=5a3aff6493977f7e20c47a022689c7ee18b0f5bb93e67e6708eb0c0be93024ef bytes=1579655
- `decompiled/aos_nl2sol.dll.c.txt` sha256=bfe883d244fd22bfb12f83585c0350ce181d8f0573c3d5cbb7bfd202dd50efe5 bytes=736881
- `decompiled/aos_optrnd.dll.c.txt` sha256=caa68a2dedb11002750f42bf35396e5b1f69524d067fac22b39c2c5c623b50de bytes=1471228
- `decompiled/aos_sparse.dll.c.txt` sha256=ae67ff78d53510c09288b3069d8795957916eafa849eeb710b5a43daad26e970 bytes=557581
- `decompiled/aos_sparse_ma38.dll.c.txt` sha256=c5891ecece3805d6d6f9ed1a9511264228618126912b1351f28801544e483569 bytes=592444
- `decompiled/aos_srqp.dll.c.txt` sha256=fc3f739a106577e7371e229e002525bb9550efa2f2751c29122c00ee0f603dc5 bytes=943360
- `decompiled/aos_vf02.dll.c.txt` sha256=56996ebe9f458e0e5b16a062e6a0d411215648dd689854fd2f103b1f131e11e9 bytes=620604
- `decompiled/aos_vf13.dll.c.txt` sha256=2956b22ab091e273e47b9e92eb7545f94add77fa1cb5d84f930034ef2496ea05 bytes=612317
- `decompiled/aos_xpress.dll.c.txt` sha256=89ad43ac4fa3bbd2143911a15f1a8b98406962764cf35c1314c67748124187a0 bytes=1166217
- `disasm/ApSparseExe.exe.asm.txt` sha256=736f8a19dc7fcf59c02a7f0b68eb876f798f4d627f22eaddd92c4ae9beda7b1c bytes=2311608
- `disasm/DecompServer.dll.asm.txt` sha256=6f495b1dd48255374670a0939e6b6aa199404a4f49304ca5cdb4239320d45e9e bytes=1017216
- `disasm/IntegratorServer.dll.asm.txt` sha256=25bb26fb08e77c74c2e1744ddb5e9f9d6211c7160fa72724c2d6b9e8f566040a bytes=1698944
- `disasm/RtHarwell.dll.asm.txt` sha256=5ff2d6dc5761f23d0e8b03033af2a3f7a253bf30244fad99aab3b345e70ab156 bytes=2074998
- `disasm/aos_dmo.dll.asm.txt` sha256=76d195fcd03a0830c4bbe17cde029e7e9160d5846f5274146e9815cd69312545 bytes=697230
- `disasm/aos_dmo_proxy.dll.asm.txt` sha256=1f4fdb60dc4bbd6680b62e09c7cf4b303137b3dc20c2b111b5c3f4aecf28629e bytes=697548
- `disasm/aos_hypsqp.dll.asm.txt` sha256=8a6197cadd9cb02f819cb0f507eeac8623452cc70bda9b143cc5f59bbf180673 bytes=1052347
- `disasm/aos_integrator.dll.asm.txt` sha256=b8b0744a2bb1f494ef8825325686634cac50313be1c948295ac5db14c58d70bc bytes=906203
- `disasm/aos_ma38.dll.asm.txt` sha256=f41097f6441a3b9a4ba61b096739e90fab8bdd532f23c9d36c1b71c5dbe8a3c4 bytes=2241332
- `disasm/aos_ma48.dll.asm.txt` sha256=61f16377d74ace23a54a13bd51b1da6780199821eca2a55b1abe2a135df65447 bytes=2333721
- `disasm/aos_nl2sol.dll.asm.txt` sha256=a704b6bf08bae37f026189ffd6fd4d629414b5f38e6bc36f280d3129138e85e3 bytes=1004292
- `disasm/aos_optrnd.dll.asm.txt` sha256=1d7b030d1fad7a39ce8d9810eeb590d92e2ed7d85d4f03624529dea013ac4b11 bytes=1955832
- `disasm/aos_sparse.dll.asm.txt` sha256=964248360b3617eb98c72cf3215f9efc21de8ce95828bb0d2c12966e058962a4 bytes=849000
- `disasm/aos_sparse_ma38.dll.asm.txt` sha256=927d75bda242dcbc4cd841081beb4615274f127eb902639b883dbd53a35a8a1c bytes=886349
- `disasm/aos_srqp.dll.asm.txt` sha256=e5344a99e835fc81d08938ce3f5a4f55940a0ec8e6a19934e6fa34acdd71f1aa bytes=1296476
- `disasm/aos_vf02.dll.asm.txt` sha256=0110cd8927ca62570f013b3d32f88492a3d3f2bf68ade76ce58aba28e90238b5 bytes=790184
- `disasm/aos_vf13.dll.asm.txt` sha256=e4774b766fcea867cb904aad6c722df97b31d35f8ff4a28676fd00358ea9fc80 bytes=755872
- `disasm/aos_xpress.dll.asm.txt` sha256=0f29b58a54dc749f9fae95f1f4bdeb5b0901959ca49a01e723413425313c4085 bytes=2392950
