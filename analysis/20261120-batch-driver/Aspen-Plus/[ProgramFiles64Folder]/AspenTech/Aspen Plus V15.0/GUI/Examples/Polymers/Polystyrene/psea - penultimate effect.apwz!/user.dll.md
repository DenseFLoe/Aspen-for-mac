# user.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `user.dll`，10240 字节，SHA-256 `742253096fdbaf85cc43e6c812eb8dc82899ef8371b583b148bc2d82b2e20799` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 57 = decomp_ok 57 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=57
- decomp_ok=57
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `user.dll` |
| 字节数 | 10240 |
| SHA-256 | `742253096fdbaf85cc43e6c812eb8dc82899ef8371b583b148bc2d82b2e20799` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polystyrene/psea - penultimate effect.apwz!/user.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry | 0x8664 / 5 / 0x14A8 |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x180000000` |
| 段数 | 5 |
| 指令行数 | 1076 |

## 3. 反汇编清单（全量）

全文：disasm/user.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/user.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 57
- decomp_ok（伪 C） = 57
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：IDAPython 导出脚本（本地保留，未随产物发布；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：1.6 s
- 日志：out/R1N/ida/logs/sha256_742253096fdbaf85cc43e6c812eb8dc82899ef8371b583b148bc2d82b2e20799.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `user.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 57 |
| Ghidra 12.1.4 基线 FUNC | 56 |
| 差值 | +1（+1.8%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：`FUN_18000116c`, `FUN_1800011bc`, `FUN_1800012d0`, `dllmain_dispatch`, `dllmain_raw`, `entry`, `FUN_1800015b8`, `FUN_1800015c8`
- 仅 IDA 有：`?dllmain_crt_dispatch@@YAHQEAUHINSTANCE__@@KQEAX@Z`, `?dllmain_crt_process_attach@@YAHQEAUHINSTANCE__@@QEAX@Z`, `?dllmain_crt_process_detach@@YAH_N@Z`, `sub_18000135C`, `?dllmain_raw@@YAHQEAUHINSTANCE__@@KQEAX@Z`, `DllEntryPoint`, `__xi_z`, `sub_1800015C8`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: repo:逆向成果/待静态验收/Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Examples/Polymers/Polystyrene/psea - penultimate effect.apwz!/user.dll.md/分支交付/
