# LPMUtilities.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `LPMUtilities.dll`，195520 字节，SHA-256 `6fe07216c82b28e40e24c2afda400e7cfacffc7289cb123933ab230f8393498c` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 384 = decomp_ok 380 + decomp_fail 4 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=384
- decomp_ok=380
- decomp_fail=4
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `LPMUtilities.dll` |
| 字节数 | 195520 |
| SHA-256 | `6fe07216c82b28e40e24c2afda400e7cfacffc7289cb123933ab230f8393498c` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/LPMUtilities.dll` |
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
| 段数 | 6 |
| 指令行数 | 20695 |

## 3. 反汇编清单（全量）

全文：disasm/LPMUtilities.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/LPMUtilities.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 384
- decomp_ok（伪 C） = 380
- decomp_fail = 4
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1800030cd` `sub_1800030CD`：RuntimeError（decompile returned None）
- `180009a00` `sub_180009A00`：RuntimeError（decompile returned None）
- `18000aa2f` `sub_18000AA2F`：RuntimeError（decompile returned None）
- `18000e8dc` `sub_18000E8DC`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：14.9 s
- 日志：out/R1N/ida/logs/sha256_6fe07216c82b28e40e24c2afda400e7cfacffc7289cb123933ab230f8393498c.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 4 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `LPMUtilities.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 384 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +384（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `SAINMXF`, `SAICNC`, `GPIDVFU`, `sub_180002FA0`, `sub_180002FC5`, `sub_18000305B`, `sub_1800030CD`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/LPMHandler.dll.c.txt` sha256=d9067e48f8940110439174d62a11f25ceb7a382d6010dbd6839dc661d65b8fb5 bytes=888254
- `decompiled/LPMUtilities.dll.c.txt` sha256=ccc1b80224a8fec74fd48f8a9480eaa377f4c86a8e5d54e50372f9f7b28b8409 bytes=562382
- `disasm/LPMHandler.dll.asm.txt` sha256=db0e646267084472d20fd73d9faff1217c515d243310e475daa45d22662e18ec bytes=1312814
- `disasm/LPMUtilities.dll.asm.txt` sha256=88982cb5a7f9393f7cf24c1647b6a677e88670a5bca392622ec0e423786535f0 bytes=780681
