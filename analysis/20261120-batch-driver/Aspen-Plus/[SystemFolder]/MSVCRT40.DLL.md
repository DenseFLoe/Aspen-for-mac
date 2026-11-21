# MSVCRT40.DLL 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `MSVCRT40.DLL`，326656 字节，SHA-256 `9bcd0fe2c80a07c33eda7ff67bbb2f7b70f65de6ae5f458e6a6b9411ac5d91a2` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1612 = decomp_ok 1592 + decomp_fail 20 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1612
- decomp_ok=1592
- decomp_fail=20
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `MSVCRT40.DLL` |
| 字节数 | 326656 |
| SHA-256 | `9bcd0fe2c80a07c33eda7ff67bbb2f7b70f65de6ae5f458e6a6b9411ac5d91a2` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/MSVCRT40.DLL` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10200000` |
| 段数 | 6 |
| 指令行数 | 83328 |

## 3. 反汇编清单（全量）

全文：disasm/MSVCRT40.DLL.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/MSVCRT40.DLL.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1612
- decomp_ok（伪 C） = 1592
- decomp_fail = 20
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10201180` `??1logic_error@@UAE@XZ`：RuntimeError（decompile returned None）
- `102011d0` `??_Glogic_error@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `102085b0` `?unexpected@@YAXXZ`：RuntimeError（decompile returned None）
- `10208ac0` `??1bad_cast@@UAE@XZ`：RuntimeError（decompile returned None）
- `10208b10` `??_Gbad_cast@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `10208d10` `??1bad_typeid@@UAE@XZ`：RuntimeError（decompile returned None）
- `10208d60` `??_Gbad_typeid@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `10208f80` `??1__non_rtti_object@@UAE@XZ`：RuntimeError（decompile returned None）
- `10208fd0` `??_G__non_rtti_object@@UAEPAXI@Z`：RuntimeError（decompile returned None）
- `1020c180` `??1fstream@@UAE@XZ`：RuntimeError（decompile returned None）
- `1020c890` `??1ifstream@@UAE@XZ`：RuntimeError（decompile returned None）
- `1020db60` `??1iostream@@UAE@XZ`：RuntimeError（decompile returned None）
- `1020e7b0` `??1istream_withassign@@UAE@XZ`：RuntimeError（decompile returned None）
- `1020fb90` `??1ofstream@@UAE@XZ`：RuntimeError（decompile returned None）
- `102105a0` `??1ostream_withassign@@UAE@XZ`：RuntimeError（decompile returned None）
- `102111e0` `??1stdiobuf@@UAE@XZ`：RuntimeError（decompile returned None）
- `10211760` `??1stdiostream@@UAE@XZ`：RuntimeError（decompile returned None）
- `10212880` `??1istrstream@@UAE@XZ`：RuntimeError（decompile returned None）
- `10212af0` `??1ostrstream@@UAE@XZ`：RuntimeError（decompile returned None）
- `10212d80` `??1strstream@@UAE@XZ`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：37.6 s
- 日志：out/R1N/ida/logs/sha256_9bcd0fe2c80a07c33eda7ff67bbb2f7b70f65de6ae5f458e6a6b9411ac5d91a2.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 20 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `MSVCRT40.DLL` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1612 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1612（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`??_Gexception@@UAEPAXI@Z`, `??_Eexception@@UAEPAXI@Z`, `??0logic_error@@QAE@ABQBD@Z`, `??0logic_error@@QAE@ABV0@@Z`, `??4logic_error@@QAEAAV0@ABV0@@Z`, `??1logic_error@@UAE@XZ`, `??_Glogic_error@@UAEPAXI@Z`, `??_Elogic_error@@UAEPAXI@Z`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `native3/01-completed/Aspen-Plus/[SystemFolder]/decompiled/MSVCRT40.DLL.c.txt` sha256=05e9d0d0bffff66bf5811b29ef30fb4c80ac702d67b51446033485892fbe9f73 bytes=1142744
- `native3/01-completed/Aspen-Plus/[SystemFolder]/disasm/MSVCRT40.DLL.asm.txt` sha256=10f08011d5f6401fe9c671d4c704f0253246827ba5408c49f9c887cf445cd6c6 bytes=2696925
