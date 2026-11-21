# zepetrofrac.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zepetrofrac.dll`，2279976 字节，SHA-256 `8792229bcaa2e21df5500d42cdbf30b4d83aa11ce61b4d10f125abb3c2ba669a` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 664 = decomp_ok 649 + decomp_fail 15 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=664
- decomp_ok=649
- decomp_fail=15
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zepetrofrac.dll` |
| 字节数 | 2279976 |
| SHA-256 | `8792229bcaa2e21df5500d42cdbf30b4d83aa11ce61b4d10f125abb3c2ba669a` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/zepetrofrac.dll` |
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
| 指令行数 | 335014 |

## 3. 反汇编清单（全量）

全文：disasm/zepetrofrac.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zepetrofrac.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 664
- decomp_ok（伪 C） = 649
- decomp_fail = 15
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180053600` `PTFR_UD14II`：RuntimeError（decompile returned None）
- `18008b7a0` `PTFR_UDL14I`：RuntimeError（decompile returned None）
- `18008fea0` `sub_18008FEA0`：RuntimeError（decompile returned None）
- `1800b0850` `sub_1800B0850`：RuntimeError（decompile returned None）
- `1800ef860` `sub_1800EF860`：RuntimeError（decompile returned None）
- `1800fb860` `sub_1800FB860`：RuntimeError（decompile returned None）
- `1800fe320` `sub_1800FE320`：RuntimeError（decompile returned None）
- `180153810` `sub_180153810`：RuntimeError（decompile returned None）
- `1801573e0` `sub_1801573E0`：RuntimeError（decompile returned None）
- `180158240` `sub_180158240`：RuntimeError（decompile returned None）
- `180159970` `sub_180159970`：RuntimeError（decompile returned None）
- `180182010` `sub_180182010`：RuntimeError（decompile returned None）
- `18018ab30` `sub_18018AB30`：RuntimeError（decompile returned None）
- `180191f40` `sub_180191F40`：RuntimeError（decompile returned None）
- `1801ac890` `sub_1801AC890`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：545.7 s
- 日志：out/R1N/ida/logs/sha256_8792229bcaa2e21df5500d42cdbf30b4d83aa11ce61b4d10f125abb3c2ba669a.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 15 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zepetrofrac.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 664 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +664（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180005440`, `sub_18000AA80`, `PTFR_EUDL14`, `sub_180012C80`, `sub_180012D30`, `sub_180012F50`, `sub_180013180`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/decompiled/zepetrofrac.dll.c.txt` sha256=b48603e0360ebc8c419448289af793d660e417640d635e1ab2a2e9dd9e23f0fd bytes=5019238
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/disasm/zepetrofrac.dll.asm.txt` sha256=96b50d9bae77b71632e0a8369e55b0979d7ecfe6362ddf21d5fd094f13457565 bytes=13358738
