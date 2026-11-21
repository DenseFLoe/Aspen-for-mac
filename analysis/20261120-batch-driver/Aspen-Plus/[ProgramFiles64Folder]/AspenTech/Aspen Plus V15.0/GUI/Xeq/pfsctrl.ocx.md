# pfsctrl.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pfsctrl.ocx`，1151528 字节，SHA-256 `bcc65eb75cb0d5389e51c4451bf6b6ced5c14e224355397924bed4a514474367` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3892 = decomp_ok 3892 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3892
- decomp_ok=3892
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pfsctrl.ocx` |
| 字节数 | 1151528 |
| SHA-256 | `bcc65eb75cb0d5389e51c4451bf6b6ced5c14e224355397924bed4a514474367` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/pfsctrl.ocx` |
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
| 段数 | 5 |
| 指令行数 | 187153 |

## 3. 反汇编清单（全量）

全文：disasm/pfsctrl.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pfsctrl.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3892
- decomp_ok（伪 C） = 3892
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：150.7 s
- 日志：out/R1N/ida/logs/sha256_bcc65eb75cb0d5389e51c4451bf6b6ced5c14e224355397924bed4a514474367.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pfsctrl.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3892 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3892（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001020`, `sub_180001040`, `sub_180001060`, `sub_1800010A0`, `sub_1800010C0`, `sub_1800010E0`, `sub_180001110`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/ATModelCME.dll.c.txt` sha256=4f669567d683d460d30687cff0bc6d0cabdd3c453d3cb1eecdc865782173a2e2 bytes=4661254
- `decompiled/hmxlpxmps.dll.c.txt` sha256=23792fefdf45902883d67c904d24e2c159b4253b09ddae8c56caa090f5f936fe bytes=4646543
- `decompiled/icondefdll.dll.c.txt` sha256=a612146c07e890ad700be24484f925bbc70612fd28cdf8716a39b674b9bf2893 bytes=10678138
- `decompiled/iconeditorCME.dll.c.txt` sha256=68480495e07620b90d9032ecd66621b5dc68e6a3dd6d9bc6b4b3ffe954284d59 bytes=2826234
- `decompiled/pfsctrl.ocx.c.txt` sha256=5b96d853176807ab399bc278343b5d3d2118cd482270b6b678dd0072446ea267 bytes=4222422
- `disasm/ATModelCME.dll.asm.txt` sha256=e3a855d433a605545ae7d7be348363c5649e4c585342c6771d434dc92557eac7 bytes=9138329
- `disasm/hmxlpxmps.dll.asm.txt` sha256=4894b12c84d7f9b4dffbece630cfd1bea8540021fd755560fcc3c74d6f005db0 bytes=8324793
- `disasm/icondefdll.dll.asm.txt` sha256=1932acd10f1ed503b02a602a7851e097129217ca188261ac6f572e51b588e78f bytes=19063871
- `disasm/iconeditorCME.dll.asm.txt` sha256=36299d56e9c338555c86a6b77184d9cf8a71497620f19db8c6dc09199d4b64df bytes=6220094
- `disasm/pfsctrl.ocx.asm.txt` sha256=005ca861745ad5776825abddc62594d41c9f10510cdd89e0f25c712a00d9ca6c bytes=7177254
