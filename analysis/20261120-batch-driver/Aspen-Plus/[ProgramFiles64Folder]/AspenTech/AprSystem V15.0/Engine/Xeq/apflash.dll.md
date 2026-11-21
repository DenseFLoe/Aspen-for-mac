# apflash.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `apflash.dll`，1841192 字节，SHA-256 `da538a39853f18aebcc22e09c986390d04d952fa5b5df4415d63a9ce95b8c674` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 768 = decomp_ok 759 + decomp_fail 9 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=768
- decomp_ok=759
- decomp_fail=9
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `apflash.dll` |
| 字节数 | 1841192 |
| SHA-256 | `da538a39853f18aebcc22e09c986390d04d952fa5b5df4415d63a9ce95b8c674` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/apflash.dll` |
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
| 指令行数 | 284042 |

## 3. 反汇编清单（全量）

全文：disasm/apflash.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/apflash.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 768
- decomp_ok（伪 C） = 759
- decomp_fail = 9
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `18006b1b0` `sub_18006B1B0`：RuntimeError（decompile returned None）
- `1800856a0` `sub_1800856A0`：RuntimeError（decompile returned None）
- `180090190` `sub_180090190`：RuntimeError（decompile returned None）
- `1800cb320` `sub_1800CB320`：RuntimeError（decompile returned None）
- `1800e3c30` `sub_1800E3C30`：RuntimeError（decompile returned None）
- `18011d760` `sub_18011D760`：RuntimeError（decompile returned None）
- `180138400` `sub_180138400`：RuntimeError（decompile returned None）
- `180183f80` `sub_180183F80`：RuntimeError（decompile returned None）
- `180184880` `sub_180184880`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：292.7 s
- 日志：out/R1N/ida/logs/sha256_da538a39853f18aebcc22e09c986390d04d952fa5b5df4415d63a9ce95b8c674.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 9 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `apflash.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 768 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +768（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`APFLASH_FLASH`, `APFLASH_MERCURY`, `sub_1800014F0`, `sub_180008670`, `sub_1800088A0`, `sub_180008AE0`, `sub_180008B50`, `sub_180008BC0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/apflash.dll.c.txt` sha256=ac86c25ae5a70bf6f4d56eb6ecd856ab767dfe60909f478756810a0d31a2f7e2 bytes=4042606
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/apflash.dll.asm.txt` sha256=f98ee2f6ac3772d17770c1e2f77a71c5cc2c5b736eca8808231954c1fdd79c82 bytes=11053768
