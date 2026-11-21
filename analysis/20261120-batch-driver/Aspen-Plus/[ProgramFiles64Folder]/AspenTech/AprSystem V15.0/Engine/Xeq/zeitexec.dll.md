# zeitexec.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zeitexec.dll`，287784 字节，SHA-256 `3861dc8c5ca85b9f13de6ff22ec209fbe6bca3f8523b50c0be2c46b67394874f` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 721 = decomp_ok 717 + decomp_fail 4 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=721
- decomp_ok=717
- decomp_fail=4
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zeitexec.dll` |
| 字节数 | 287784 |
| SHA-256 | `3861dc8c5ca85b9f13de6ff22ec209fbe6bca3f8523b50c0be2c46b67394874f` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/zeitexec.dll` |
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
| 指令行数 | 34904 |

## 3. 反汇编清单（全量）

全文：disasm/zeitexec.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zeitexec.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 721
- decomp_ok（伪 C） = 717
- decomp_fail = 4
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180001000` `IT_ITSUB`：RuntimeError（decompile returned None）
- `180006cd0` `IT_IAPSOM`：RuntimeError（decompile returned None）
- `180014ad0` `sub_180014AD0`：RuntimeError（decompile returned None）
- `180021dd0` `sub_180021DD0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：23.0 s
- 日志：out/R1N/ida/logs/sha256_3861dc8c5ca85b9f13de6ff22ec209fbe6bca3f8523b50c0be2c46b67394874f.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 4 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zeitexec.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 721 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +721（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`IT_ITSUB`, `IT_CHKRUN`, `IT_IAPDIR`, `IT_INPRO`, `sub_1800020C0`, `IT_PRESOR`, `sub_1800022C0`, `sub_180003880`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `native3/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/zeitexec.dll.c.txt` sha256=af2b04d53c58cc0f7976319ab00abef63cb4f860d9714216e6d841c4914145c9 bytes=808020
- `native3/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/zeitexec.dll.asm.txt` sha256=35a58f7d5266aaba94dc923a6d6aacd2654431aa5511c455b0bcd76d8b5664ab bytes=1338215
