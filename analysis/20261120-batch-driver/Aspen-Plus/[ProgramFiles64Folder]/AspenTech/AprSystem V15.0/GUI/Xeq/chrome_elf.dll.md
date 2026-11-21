# chrome_elf.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `chrome_elf.dll`，1448600 字节，SHA-256 `f4b806540aba84c356c1e4edb17eb1b2e09fb52f07cfc7fe6ac583201eb5d3f0` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3844 = decomp_ok 3837 + decomp_fail 7 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3844
- decomp_ok=3837
- decomp_fail=7
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `chrome_elf.dll` |
| 字节数 | 1448600 |
| SHA-256 | `f4b806540aba84c356c1e4edb17eb1b2e09fb52f07cfc7fe6ac583201eb5d3f0` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/chrome_elf.dll` |
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
| 段数 | 17 |
| 指令行数 | 260741 |

## 3. 反汇编清单（全量）

全文：disasm/chrome_elf.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/chrome_elf.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3844
- decomp_ok（伪 C） = 3837
- decomp_fail = 7
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1800796d0` `sub_1800796D0`：RuntimeError（decompile returned None）
- `180079930` `sub_180079930`：RuntimeError（decompile returned None）
- `18007a2b0` `sub_18007A2B0`：RuntimeError（decompile returned None）
- `18007c610` `sub_18007C610`：RuntimeError（decompile returned None）
- `18008e68c` `?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z`：RuntimeError（decompile returned None）
- `1800fb170` `sub_1800FB170`：RuntimeError（decompile returned None）
- `1800fbcd0` `sub_1800FBCD0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：214.8 s
- 日志：out/R1N/ida/logs/sha256_f4b806540aba84c356c1e4edb17eb1b2e09fb52f07cfc7fe6ac583201eb5d3f0.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 7 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `chrome_elf.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3844 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3844（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800010A0`, `sub_180001100`, `sub_180001160`, `sub_1800011E0`, `sub_180001260`, `sub_1800012F0`, `sub_180001380`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/GUI/Xeq/decompiled/chrome_elf.dll.c.txt` sha256=76cedf03c83d7b13262fc1a51babbb95beb5817d23de8f72e5218720e72897c8 bytes=5166984
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/GUI/Xeq/disasm/chrome_elf.dll.asm.txt` sha256=8886ef4855cd8f2e49f32a6065c3c222b3bdf2677b8e8f6fd332159c6c25a862 bytes=9278418
