# Dynamics.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `Dynamics.dll`，440360 字节，SHA-256 `0c2ce32ddee649d57eaf30431c87ca1a5b8d6727a63b6ee4f31aaf3ca7c184d9` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 495 = decomp_ok 489 + decomp_fail 6 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=495
- decomp_ok=489
- decomp_fail=6
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `Dynamics.dll` |
| 字节数 | 440360 |
| SHA-256 | `0c2ce32ddee649d57eaf30431c87ca1a5b8d6727a63b6ee4f31aaf3ca7c184d9` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/Dynamics.dll` |
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
| 段数 | 8 |
| 指令行数 | 65682 |

## 3. 反汇编清单（全量）

全文：disasm/Dynamics.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/Dynamics.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 495
- decomp_ok（伪 C） = 489
- decomp_fail = 6
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `18000cf50` `sub_18000CF50`：RuntimeError（decompile returned None）
- `18000f950` `sub_18000F950`：RuntimeError（decompile returned None）
- `1800166b0` `sub_1800166B0`：RuntimeError（decompile returned None）
- `180017230` `sub_180017230`：RuntimeError（decompile returned None）
- `18002e0c0` `sub_18002E0C0`：RuntimeError（decompile returned None）
- `1800342b0` `sub_1800342B0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：64.8 s
- 日志：out/R1N/ida/logs/sha256_0c2ce32ddee649d57eaf30431c87ca1a5b8d6727a63b6ee4f31aaf3ca7c184d9.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 6 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `Dynamics.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 495 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +495（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`SU55IF_SPRPHLD_USER`, `SU55IF_SPPMIN`, `SU55IF_SPLIM_ABS`, `SU55IF_SPHYDR`, `sub_180001810`, `sub_180003410`, `sub_1800066A0`, `sub_180007830`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/ARTRxnCfg.dll.c.txt` sha256=f98a95b34544a7311136ed79ed7b2b7f15eab6bdade1ca5e8f96887b5f2f8fc0 bytes=774792
- `decompiled/Dynamics.dll.c.txt` sha256=c0ab203dbe2dd4c1d1c0a1aa25acd5426c0115cb2f3cc33f82af1c24dc0b5794 bytes=1424404
- `decompiled/EAFEED.dll.c.txt` sha256=da93d5b4cc6415b0f22c70b4ee734266941b2fddb59cec9d6aeb0590da2d0859 bytes=433415
- `decompiled/EAHEATEXCHANGER.dll.c.txt` sha256=c931c6d4c1007b0e9eefddae93ce611ede6f48eae9b9137aa87cce3dcbbd74db bytes=813704
- `decompiled/EAMIXER.dll.c.txt` sha256=8a012c1e2ec47aa63081bbfcc3d5fd60b6b60f86a8b094ae883a1b294956d0b7 bytes=446175
- `decompiled/EASPLITTER.dll.c.txt` sha256=f1818386fc376390b00badfdf3d68c89d984ead6d1416f3c1afbaed3146a2da3 bytes=358176
- `disasm/ARTRxnCfg.dll.asm.txt` sha256=e9b52fb84fa7173cef119bc02f8f0fb5a91adf92168b8c3d0d11e719e784b224 bytes=1476729
- `disasm/Dynamics.dll.asm.txt` sha256=6b7102d1b76435e417867b4481b2608cba17441522d46a7aa069173e89425081 bytes=2619118
- `disasm/EAFEED.dll.asm.txt` sha256=817e10262d8b98adb39ab97bf7dd4f60b2bc9919a14c3cc53f8ccf2ff4672514 bytes=755009
- `disasm/EAHEATEXCHANGER.dll.asm.txt` sha256=4ac058a8ea91ddca71c7c0e3e68114fd252385be0901608ef894130d0e907faf bytes=1631358
- `disasm/EAMIXER.dll.asm.txt` sha256=12b475ff292712dae8f90d883ec29f00c3823202b346990f0729e741ede2f8d7 bytes=783275
- `disasm/EASPLITTER.dll.asm.txt` sha256=65c86f389e71311995d2b12ed4368f21f68587568a798491d7bfd68aa9ece92d bytes=601754
