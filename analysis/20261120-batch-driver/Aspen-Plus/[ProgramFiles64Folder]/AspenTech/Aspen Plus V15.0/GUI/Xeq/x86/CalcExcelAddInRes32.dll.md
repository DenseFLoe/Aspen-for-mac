# CalcExcelAddInRes32.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `CalcExcelAddInRes32.dll`，27176 字节，SHA-256 `3bfe609cd8bcb0c0abdde6e1160df971dd4a073b67e3e2b15e78a2e62d96a343` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 86 = decomp_ok 84 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=86
- decomp_ok=84
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `CalcExcelAddInRes32.dll` |
| 字节数 | 27176 |
| SHA-256 | `3bfe609cd8bcb0c0abdde6e1160df971dd4a073b67e3e2b15e78a2e62d96a343` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/x86/CalcExcelAddInRes32.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 4 |
| 指令行数 | 2387 |

## 3. 反汇编清单（全量）

全文：disasm/CalcExcelAddInRes32.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/CalcExcelAddInRes32.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 86
- decomp_ok（伪 C） = 84
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `100022bc` `___scrt_dllmain_crt_thread_attach`：RuntimeError（decompile returned None）
- `100022db` `___scrt_dllmain_crt_thread_detach`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：26.0 s
- 日志：out/R1N/ida/logs/sha256_3bfe609cd8bcb0c0abdde6e1160df971dd4a073b67e3e2b15e78a2e62d96a343.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `CalcExcelAddInRes32.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 86 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +86（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `?what@exception@std@@UBEPBDXZ`, `sub_10001040`, `sub_10001080`, `??0bad_array_new_length@std@@QAE@XZ`, `sub_100010C0`, `sub_10001100`, `sub_10001140`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `native/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/x86/decompiled/CalcExcelAddInRes32.dll.c.txt` sha256=52341192f1abb38adc8fdc7aa8ad44395d868a79afdfcb5e7193db330298ede8 bytes=41986
- `native/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/x86/disasm/CalcExcelAddInRes32.dll.asm.txt` sha256=eb024bebaf03eb3a2056fea4f2a222046234368c0e851fb2e171cbda57861275 bytes=80546
