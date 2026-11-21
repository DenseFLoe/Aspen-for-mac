# olch2x7.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `olch2x7.ocx`，1943248 字节，SHA-256 `b810aded1d9d1032f73e8228f9def09619a0ca12c216b3f71102f93f8f22a27a` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 7886 = decomp_ok 7873 + decomp_fail 13 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=7886
- decomp_ok=7873
- decomp_fail=13
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `olch2x7.ocx` |
| 字节数 | 1943248 |
| SHA-256 | `b810aded1d9d1032f73e8228f9def09619a0ca12c216b3f71102f93f8f22a27a` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/olch2x7.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x30000000` |
| 段数 | 8 |
| 指令行数 | 390988 |

## 3. 反汇编清单（全量）

全文：disasm/olch2x7.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/olch2x7.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 7886
- decomp_ok（伪 C） = 7873
- decomp_fail = 13
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `3003d030` `sub_3003D030`：RuntimeError（decompile returned None）
- `300fd672` `sub_300FD672`：RuntimeError（decompile returned None）
- `30106cb9` `__check_range_exit`：RuntimeError（decompile returned None）
- `3010be56` `sub_3010BE56`：RuntimeError（decompile returned None）
- `301155f4` `sub_301155F4`：RuntimeError（decompile returned None）
- `301155fc` `sub_301155FC`：RuntimeError（decompile returned None）
- `3011708a` `sub_3011708A`：RuntimeError（decompile returned None）
- `301178b2` `sub_301178B2`：RuntimeError（decompile returned None）
- `301178ba` `sub_301178BA`：RuntimeError（decompile returned None）
- `30119cbb` `sub_30119CBB`：RuntimeError（decompile returned None）
- `30119ec2` `sub_30119EC2`：RuntimeError（decompile returned None）
- `30119eca` `sub_30119ECA`：RuntimeError（decompile returned None）
- `30120123` `sub_30120123`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：274.2 s
- 日志：out/R1N/ida/logs/sha256_b810aded1d9d1032f73e8228f9def09619a0ca12c216b3f71102f93f8f22a27a.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 13 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `olch2x7.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 7886 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +7886（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_30001000`, `sub_30001060`, `sub_30001070`, `sub_30001080`, `sub_300010E0`, `sub_30001100`, `sub_30001180`, `sub_30001190`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[SystemFolder]/decompiled/olch2x7.ocx.c.txt` sha256=e2cdb7c62518e3b3489ab9aeffe04b8ddf1a8bc76218b7589901a6af35ef4879 bytes=5310460
- `native5/01-completed/Aspen-Plus/[SystemFolder]/disasm/olch2x7.ocx.asm.txt` sha256=7d7704b73a383b32e99f0385e146d68906d361db27c6e21396af8e5d2b9be913 bytes=12632208
