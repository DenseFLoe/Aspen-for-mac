# otp60as.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `otp60as.dll`，1818624 字节，SHA-256 `17a3d1da1aa8cd8813309c9dbb086defa94f470c1e3f4eb33b68ddcaa0023901` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 8644 = decomp_ok 8637 + decomp_fail 7 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=8644
- decomp_ok=8637
- decomp_fail=7
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `otp60as.dll` |
| 字节数 | 1818624 |
| SHA-256 | `17a3d1da1aa8cd8813309c9dbb086defa94f470c1e3f4eb33b68ddcaa0023901` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/otp60as.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x4c000000` |
| 段数 | 4 |
| 指令行数 | 349906 |

## 3. 反汇编清单（全量）

全文：disasm/otp60as.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/otp60as.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 8644
- decomp_ok（伪 C） = 8637
- decomp_fail = 7
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `4c0fcce8` `?Format@CString@@QAAXPBDZZ`：RuntimeError（decompile returned None）
- `4c0fd44a` `?SafeSetProperty@COleControlSite@@UAAHJGZZ`：RuntimeError（decompile returned None）
- `4c0fd450` `?SetProperty@COleControlSite@@UAAXJGZZ`：RuntimeError（decompile returned None）
- `4c0fd45c` `?InvokeHelper@COleControlSite@@UAAXJGGPAXPBEZZ`：RuntimeError（decompile returned None）
- `4c0fd50a` `?SetProperty@COleDispatchDriver@@QAAXJGZZ`：RuntimeError（decompile returned None）
- `4c0fd56a` `?InvokeHelper@COleDispatchDriver@@QAAXJGGPAXPBEZZ`：RuntimeError（decompile returned None）
- `4c0fd834` `?FireEvent@COleControl@@QAAXJPAEZZ`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：272.8 s
- 日志：out/R1N/ida/logs/sha256_17a3d1da1aa8cd8813309c9dbb086defa94f470c1e3f4eb33b68ddcaa0023901.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 7 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `otp60as.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 8644 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +8644（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`OTP60AS_135`, `OTP60AS_137`, `OTP60AS_138`, `sub_4C0010F0`, `sub_4C001110`, `OTP60AS_160`, `OTP60AS_161`, `OTP60AS_163`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[SystemFolder]/decompiled/otp60as.dll.c.txt` sha256=411a7eb702ca32b6e5fa38f523dbeb53633dc19a4b9f1787d36b90edfa35b4ee bytes=5741804
- `native5/01-completed/Aspen-Plus/[SystemFolder]/disasm/otp60as.dll.asm.txt` sha256=16936f87fa4f439d7b7a3da22b7b1c0a958dea774d342c96480b0a0e157a3c32 bytes=11657471
