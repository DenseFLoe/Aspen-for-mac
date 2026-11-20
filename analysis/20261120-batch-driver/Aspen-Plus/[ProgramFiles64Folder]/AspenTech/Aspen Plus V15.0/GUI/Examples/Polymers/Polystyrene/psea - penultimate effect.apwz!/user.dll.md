# user.dll 静态复核报告（native / T1N）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `user.dll`，10240 字节，SHA-256 `742253096fdbaf85cc43e6c812eb8dc82899ef8371b583b148bc2d82b2e20799` |
| 链 | T1N（native，Ghidra 全函数反汇编 + 全函数伪 C） |
| 函数 | FUNC 56 = //FUNC 56 + //DECOMP-FAIL 0 |
| 证据等级 | 〔实测〕analyzeHeadless 单件跑通，正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

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

## 2. PE 导入摘要（语言/基址/块）

| 项 | 值 |
| --- | --- |
| Ghidra 语言 id | `x86:LE:64:default` |
| 镜像基址 | `0x180000000` |
| 函数块数（# BLOCKS） | 56 |
| 指令行数 | 1062 |

## 3. 反汇编清单（全量）

全文：disasm/user.dll.asm.txt（逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，无抽样）。

## 4. 反编译伪 C（Ghidra）

全文：decompiled/user.dll.c.txt（逐函数 // FUNC <addr> <name> + C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（FUNC 数 = //FUNC 数 + //DECOMP-FAIL 数）

- FUNC（asm） = 56
- // FUNC（伪 C） = 56
- // DECOMP-FAIL = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- Ghidra 12.1.4 PUBLIC headless（support/analyzeHeadless，bash 调），JDK 21，-analysisTimeoutPerFile 600
- 脚本：tool/ghidra_scripts/ExportAll.java（本仓从零写）
- 单件耗时（含 JVM 启动）：42.1 s
- 日志：__raw/sha256_742253096fdbaf85cc43e6c812eb8dc82899ef8371b583b148bc2d82b2e20799/import.log

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `user.dll` 全函数反汇编与全函数伪 C 已落盘，FUNC == //FUNC + //DECOMP-FAIL 成立。
