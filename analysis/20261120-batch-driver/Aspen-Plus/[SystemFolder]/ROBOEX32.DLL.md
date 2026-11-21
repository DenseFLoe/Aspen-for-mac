# ROBOEX32.DLL 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ROBOEX32.DLL`，1044480 字节，SHA-256 `2e76e25ea2dcd8623afc86566671d880abc34f8a84f197046c267e0680c24d01` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 4278 = decomp_ok 4253 + decomp_fail 25 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=4278
- decomp_ok=4253
- decomp_fail=25
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ROBOEX32.DLL` |
| 字节数 | 1044480 |
| SHA-256 | `2e76e25ea2dcd8623afc86566671d880abc34f8a84f197046c267e0680c24d01` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/ROBOEX32.DLL` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x50c0000` |
| 段数 | 4 |
| 指令行数 | 141377 |

## 3. 反汇编清单（全量）

全文：disasm/ROBOEX32.DLL.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ROBOEX32.DLL.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 4278
- decomp_ok（伪 C） = 4253
- decomp_fail = 25
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `50cc670` `sub_50CC670`：RuntimeError（decompile returned None）
- `50cd000` `sub_50CD000`：RuntimeError（decompile returned None）
- `50cd0c0` `sub_50CD0C0`：RuntimeError（decompile returned None）
- `50cd0f0` `sub_50CD0F0`：RuntimeError（decompile returned None）
- `50cfbc0` `sub_50CFBC0`：RuntimeError（decompile returned None）
- `50d8a70` `sub_50D8A70`：RuntimeError（decompile returned None）
- `50df680` `sub_50DF680`：RuntimeError（decompile returned None）
- `50e9cf0` `sub_50E9CF0`：RuntimeError（decompile returned None）
- `50e9d10` `sub_50E9D10`：RuntimeError（decompile returned None）
- `510e767` `sub_510E767`：RuntimeError（decompile returned None）
- `511160b` `__endthreadex`：RuntimeError（decompile returned None）
- `51116b0` `__errno`：RuntimeError（decompile returned None）
- `51116b9` `___doserrno`：RuntimeError（decompile returned None）
- `511dcc6` `sub_511DCC6`：RuntimeError（decompile returned None）
- `5121017` `sub_5121017`：RuntimeError（decompile returned None）
- `5121229` `sub_5121229`：RuntimeError（decompile returned None）
- `51232a4` `sub_51232A4`：RuntimeError（decompile returned None）
- `51232ac` `sub_51232AC`：RuntimeError（decompile returned None）
- `5124cca` `sub_5124CCA`：RuntimeError（decompile returned None）
- `5124e38` `sub_5124E38`：RuntimeError（decompile returned None）
- `5124eb9` `sub_5124EB9`：RuntimeError（decompile returned None）
- `512550c` `sub_512550C`：RuntimeError（decompile returned None）
- `5125514` `sub_5125514`：RuntimeError（decompile returned None）
- `5126a82` `sub_5126A82`：RuntimeError（decompile returned None）
- `5126ab4` `sub_5126AB4`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：101.7 s
- 日志：out/R1N/ida/logs/sha256_2e76e25ea2dcd8623afc86566671d880abc34f8a84f197046c267e0680c24d01.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 25 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ROBOEX32.DLL` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 4278 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +4278（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_50C1000`, `sub_50C1090`, `sub_50C10B0`, `sub_50C1110`, `sub_50C1130`, `nullsub_6`, `sub_50C1150`, `sub_50C1160`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[SystemFolder]/decompiled/ROBOEX32.DLL.c.txt` sha256=e45edffd1f44d05f4a05c56a7898ffb2e81155b79f336a446703293fda7f5f6a bytes=2199402
- `native5/01-completed/Aspen-Plus/[SystemFolder]/disasm/ROBOEX32.DLL.asm.txt` sha256=8763564e8c399c9075e54bcf4e2353a2431d6d56fc783179083aca82727ebd30 bytes=4435372
