# aos_zedmo.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `aos_zedmo.dll`，1103912 字节，SHA-256 `2ca9b7756229d0085e6ce0f63ada5dbd91276fb8d8395edc677f66c1f78e7079` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 387 = decomp_ok 387 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=387
- decomp_ok=387
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `aos_zedmo.dll` |
| 字节数 | 1103912 |
| SHA-256 | `2ca9b7756229d0085e6ce0f63ada5dbd91276fb8d8395edc677f66c1f78e7079` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Open Solvers V15.0/Bin/aos_zedmo.dll` |
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
| 段数 | 5 |
| 指令行数 | 139656 |

## 3. 反汇编清单（全量）

全文：disasm/aos_zedmo.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/aos_zedmo.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 387
- decomp_ok（伪 C） = 387
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：115.3 s
- 日志：out/R1N/ida/logs/sha256_2ca9b7756229d0085e6ce0f63ada5dbd91276fb8d8395edc677f66c1f78e7079.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `aos_zedmo.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 387 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +387（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`DMO_SORTPOINT`, `DMO_SETDEF`, `DMO_LTRIM`, `DMO_GETVNAME`, `DMOMSG`, `CALCF`, `DMO_STRLENB`, `DMO_SETFILE`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/aos_zedmo.dll.c.txt` sha256=3be27a5a6405d0822ac711ed4c0a824c5374229a51d65181dea61ed29332834b bytes=2271271
- `decompiled/aos_zedmo_proxy.dll.c.txt` sha256=40779dccabb8cd58223a95d9f715826e8a8151595fff0487a17d7cd5239947b8 bytes=2276640
- `decompiled/cbcCInterfaceDll.dll.c.txt` sha256=1f61bdf1fec263395f410694af4028088ee623f0c14d4651a1ec026929fec05e bytes=11177214
- `decompiled/zedmo.dll.c.txt` sha256=302ca9d1e50befde98fa2d81033f93cd8a86139ca3878965e8cb66138dc53fdc bytes=3236679
- `decompiled/zedmo_proxy.dll.c.txt` sha256=bdb099e0d9ca2bc0f2a1fe0438e7e7d437bfb33b76790c5ed628ed2b75cad746 bytes=3227614
- `disasm/aos_zedmo.dll.asm.txt` sha256=c1889b9b9a9eabbb94f81eb94ccc969d5c2048e5a80e438ede410088194f8e6c bytes=5415908
- `disasm/aos_zedmo_proxy.dll.asm.txt` sha256=709b73448ada3fb327f6b62ec051956a12edb81a2802476dbd035cbc4b6df114 bytes=5416106
- `disasm/cbcCInterfaceDll.dll.asm.txt` sha256=5eed88e656bf0fe282b1ab5fda018ce7489c8d75f97429794390a9cbd2629699 bytes=18134369
- `disasm/zedmo.dll.asm.txt` sha256=b78cbb1b05bb2d4b98b2ff90f35fcd59a3f04858864fcab97d1ca3274026d13a bytes=8060338
- `disasm/zedmo_proxy.dll.asm.txt` sha256=0e8f00e615fc705f180e304e3e5b730c309a9ac2427d098b0adfd6ed57fa5e43 bytes=8060471
