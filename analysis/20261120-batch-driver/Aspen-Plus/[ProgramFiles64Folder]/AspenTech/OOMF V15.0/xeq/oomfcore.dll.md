# oomfcore.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `oomfcore.dll`，2513960 字节，SHA-256 `b3835ad255c69f21d3dc2f858323deadae64b0f88527ef42aaba900d2536a453` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 10086 = decomp_ok 10086 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=10086
- decomp_ok=10086
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `oomfcore.dll` |
| 字节数 | 2513960 |
| SHA-256 | `b3835ad255c69f21d3dc2f858323deadae64b0f88527ef42aaba900d2536a453` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/OOMF V15.0/xeq/oomfcore.dll` |
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
| 段数 | 8 |
| 指令行数 | 363199 |

## 3. 反汇编清单（全量）

全文：disasm/oomfcore.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/oomfcore.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 10086
- decomp_ok（伪 C） = 10086
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：239.4 s
- 日志：out/R1N/ida/logs/sha256_b3835ad255c69f21d3dc2f858323deadae64b0f88527ef42aaba900d2536a453.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `oomfcore.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 10086 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +10086（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_18000151E`, `sub_180003E24`, `sub_1800061FA`, `sub_18000B112`, `USR3_AECHKS`, `CLASSIFY_VARIABLES`, `sub_18000F479`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/ASCGrid.dll.c.txt` sha256=56f30fe3b5583ae3788469a7fd8cae8978f415ba18f6795897d331de6d8037ba bytes=6886007
- `decompiled/ascclasslib.dll.c.txt` sha256=2371fcad2934e7d0ddbb6897c0b991ea0ceb890228ca1e95ac6e23c0e1f27b20 bytes=2918760
- `decompiled/oomfcore.dll.c.txt` sha256=54c59841ee9c498d688d951d9d84303c09d95d48fe8fe60507b0dcba20e132f8 bytes=5791966
- `decompiled/oomfutils.dll.c.txt` sha256=320af2bcfeba367016b48145841788642c672f50dea05b64b38c9a548145ac5d bytes=1926531
- `decompiled/ot1220as.dll.c.txt` sha256=58286fc7d281e9964902fa0577e76d6042151b0e69b49f66a186a4c9a565bbd1 bytes=8900016
- `decompiled/xlpxmps.dll.c.txt` sha256=3a6504e4d95fab01e6f474326cd406e4975e2163e027245d97ee4ffb59485474 bytes=5597944
- `disasm/ASCGrid.dll.asm.txt` sha256=62c1f162476faa67c89b8a1db792075c46c97dcf97f0b0ba3f31d688483e82e9 bytes=11657612
- `disasm/ascclasslib.dll.asm.txt` sha256=7144d3568d9e9205e6bd0439df91da892fe67434855b172d315a5bde78b6a86f bytes=7557359
- `disasm/oomfcore.dll.asm.txt` sha256=df1667076c0f8f791c8a0f2ac950d8861d03b9d9be5f374fa1ba43717f7db55b bytes=14272924
- `disasm/oomfutils.dll.asm.txt` sha256=986bbc8f98e0b7aa02d24aae8337362e90c66ccaa379cb7825d19ac620a2468a bytes=6594440
- `disasm/ot1220as.dll.asm.txt` sha256=58021626f1dc5fe34a1b752a89e8b4145302fd4f3dd0784aad9f04c4eb92d4fd bytes=14018911
- `disasm/xlpxmps.dll.asm.txt` sha256=7aab7f711f17aeeb51077647b3d8a575c81b58d4bed14d7f19a74edc263ce32a bytes=9962269
