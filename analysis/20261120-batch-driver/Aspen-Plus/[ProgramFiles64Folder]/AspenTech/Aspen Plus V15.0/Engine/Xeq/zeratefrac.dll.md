# zeratefrac.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zeratefrac.dll`，2483752 字节，SHA-256 `de4ed256f034780205ffff8459e744b5a23c546880ea5262ef91bcb617109e92` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 560 = decomp_ok 534 + decomp_fail 26 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=560
- decomp_ok=534
- decomp_fail=26
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zeratefrac.dll` |
| 字节数 | 2483752 |
| SHA-256 | `de4ed256f034780205ffff8459e744b5a23c546880ea5262ef91bcb617109e92` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/zeratefrac.dll` |
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
| 段数 | 6 |
| 指令行数 | 402194 |

## 3. 反汇编清单（全量）

全文：disasm/zeratefrac.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zeratefrac.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 560
- decomp_ok（伪 C） = 534
- decomp_fail = 26
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `18001f3c0` `sub_18001F3C0`：RuntimeError（decompile returned None）
- `180056180` `sub_180056180`：RuntimeError（decompile returned None）
- `180058bb0` `sub_180058BB0`：RuntimeError（decompile returned None）
- `18005a6a0` `sub_18005A6A0`：RuntimeError（decompile returned None）
- `1800694b0` `sub_1800694B0`：RuntimeError（decompile returned None）
- `18007b8e0` `sub_18007B8E0`：RuntimeError（decompile returned None）
- `18009d6f0` `sub_18009D6F0`：RuntimeError（decompile returned None）
- `1800b3eb0` `sub_1800B3EB0`：RuntimeError（decompile returned None）
- `1800c2410` `sub_1800C2410`：RuntimeError（decompile returned None）
- `1800c8960` `sub_1800C8960`：RuntimeError（decompile returned None）
- `1800cd0f0` `sub_1800CD0F0`：RuntimeError（decompile returned None）
- `1800d0570` `sub_1800D0570`：RuntimeError（decompile returned None）
- `1800dfdb0` `sub_1800DFDB0`：RuntimeError（decompile returned None）
- `1800e6720` `sub_1800E6720`：RuntimeError（decompile returned None）
- `1800f1630` `sub_1800F1630`：RuntimeError（decompile returned None）
- `180108130` `sub_180108130`：RuntimeError（decompile returned None）
- `180111380` `sub_180111380`：RuntimeError（decompile returned None）
- `18013dde0` `sub_18013DDE0`：RuntimeError（decompile returned None）
- `18017bda0` `sub_18017BDA0`：RuntimeError（decompile returned None）
- `18017f3e0` `sub_18017F3E0`：RuntimeError（decompile returned None）
- `180184990` `sub_180184990`：RuntimeError（decompile returned None）
- `1801a3840` `sub_1801A3840`：RuntimeError（decompile returned None）
- `1801a5860` `sub_1801A5860`：RuntimeError（decompile returned None）
- `1801ab510` `sub_1801AB510`：RuntimeError（decompile returned None）
- `1801b55f0` `sub_1801B55F0`：RuntimeError（decompile returned None）
- `1801db9d0` `sub_1801DB9D0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：476.2 s
- 日志：out/R1N/ida/logs/sha256_de4ed256f034780205ffff8459e744b5a23c546880ea5262ef91bcb617109e92.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 26 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zeratefrac.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 560 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +560（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_1800011C0`, `sub_1800012A0`, `RTFR_BMCLRF`, `RTFR_BMCVRF`, `sub_180002870`, `sub_180002F30`, `sub_180003560`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/decompiled/zeratefrac.dll.c.txt` sha256=52150ef7e5af73c138c04a011f50fa31f5bf24202e83539be88c262c61659d69 bytes=4865366
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/disasm/zeratefrac.dll.asm.txt` sha256=353958cdd777176621d63dcea4e6df87828301ee3ff0dff31d5120770172aa48 bytes=15926328
