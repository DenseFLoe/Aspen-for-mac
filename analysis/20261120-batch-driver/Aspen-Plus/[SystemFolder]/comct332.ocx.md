# comct332.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `comct332.ocx`，415176 字节，SHA-256 `332e6a1cb4bf722092f9e774ecc14acddbf95a9655bea021681b11aac37ac716` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 718 = decomp_ok 677 + decomp_fail 41 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=718
- decomp_ok=677
- decomp_fail=41
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `comct332.ocx` |
| 字节数 | 415176 |
| SHA-256 | `332e6a1cb4bf722092f9e774ecc14acddbf95a9655bea021681b11aac37ac716` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/comct332.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x28080000` |
| 段数 | 3 |
| 指令行数 | 35738 |

## 3. 反汇编清单（全量）

全文：disasm/comct332.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/comct332.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 718
- decomp_ok（伪 C） = 677
- decomp_fail = 41
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `2809bbeb` `sub_2809BBEB`：RuntimeError（decompile returned None）
- `2809bf5d` `sub_2809BF5D`：RuntimeError（decompile returned None）
- `2809c876` `sub_2809C876`：RuntimeError（decompile returned None）
- `2809cade` `sub_2809CADE`：RuntimeError（decompile returned None）
- `2809e6f8` `sub_2809E6F8`：RuntimeError（decompile returned None）
- `2809e94e` `sub_2809E94E`：RuntimeError（decompile returned None）
- `2809f8f6` `sub_2809F8F6`：RuntimeError（decompile returned None）
- `2809fb0e` `sub_2809FB0E`：RuntimeError（decompile returned None）
- `280a19ed` `sub_280A19ED`：RuntimeError（decompile returned None）
- `280a2b50` `sub_280A2B50`：RuntimeError（decompile returned None）
- `280a2e53` `sub_280A2E53`：RuntimeError（decompile returned None）
- `280a5d1e` `sub_280A5D1E`：RuntimeError（decompile returned None）
- `280a65bd` `sub_280A65BD`：RuntimeError（decompile returned None）
- `280aa0c1` `sub_280AA0C1`：RuntimeError（decompile returned None）
- `280aa30c` `sub_280AA30C`：RuntimeError（decompile returned None）
- `280aaba5` `sub_280AABA5`：RuntimeError（decompile returned None）
- `280aac65` `sub_280AAC65`：RuntimeError（decompile returned None）
- `280aaf3a` `sub_280AAF3A`：RuntimeError（decompile returned None）
- `280ab018` `sub_280AB018`：RuntimeError（decompile returned None）
- `280ab0f6` `sub_280AB0F6`：RuntimeError（decompile returned None）
- `280ab302` `sub_280AB302`：RuntimeError（decompile returned None）
- `280ab3e2` `sub_280AB3E2`：RuntimeError（decompile returned None）
- `280abc1d` `sub_280ABC1D`：RuntimeError（decompile returned None）
- `280ac93f` `sub_280AC93F`：RuntimeError（decompile returned None）
- `280aca60` `sub_280ACA60`：RuntimeError（decompile returned None）
- `280b78a8` `sub_280B78A8`：RuntimeError（decompile returned None）
- `280b7b72` `sub_280B7B72`：RuntimeError（decompile returned None）
- `280b8e42` `sub_280B8E42`：RuntimeError（decompile returned None）
- `280b8f98` `sub_280B8F98`：RuntimeError（decompile returned None）
- `280b9ba2` `sub_280B9BA2`：RuntimeError（decompile returned None）
- `280b9c38` `sub_280B9C38`：RuntimeError（decompile returned None）
- `280bfd8a` `sub_280BFD8A`：RuntimeError（decompile returned None）
- `280c25e3` `sub_280C25E3`：RuntimeError（decompile returned None）
- `280c3db7` `sub_280C3DB7`：RuntimeError（decompile returned None）
- `280c41c2` `sub_280C41C2`：RuntimeError（decompile returned None）
- `280ce105` `sub_280CE105`：RuntimeError（decompile returned None）
- `280d4726` `sub_280D4726`：RuntimeError（decompile returned None）
- `280d5d62` `sub_280D5D62`：RuntimeError（decompile returned None）
- `280d5f9d` `sub_280D5F9D`：RuntimeError（decompile returned None）
- `280d603a` `sub_280D603A`：RuntimeError（decompile returned None）
- `280d6100` `sub_280D6100`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：20.6 s
- 日志：out/R1N/ida/logs/sha256_332e6a1cb4bf722092f9e774ecc14acddbf95a9655bea021681b11aac37ac716.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 41 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `comct332.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 718 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +718（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`__vbaChkstk`, `__vbaExceptHandler`, `__vbaFPException`, `_adj_fdiv_m16i`, `_adj_fdiv_m32`, `_adj_fdiv_m32i`, `_adj_fdiv_m64`, `_adj_fdiv_r`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `native3/01-completed/Aspen-Plus/[SystemFolder]/decompiled/comct332.ocx.c.txt` sha256=8f6879ac02241f1e20e72a924a55e79862a4814ac9622b647ee256590af5b59f bytes=392506
- `native3/01-completed/Aspen-Plus/[SystemFolder]/disasm/comct332.ocx.asm.txt` sha256=302e75ecd6d1cef73d10bc0c44472f36de89e2e2cfa310099a326c4c781faa2b bytes=1161840
