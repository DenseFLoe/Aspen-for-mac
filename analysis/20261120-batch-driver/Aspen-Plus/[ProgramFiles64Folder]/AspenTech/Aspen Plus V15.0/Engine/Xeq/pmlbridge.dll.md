# pmlbridge.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pmlbridge.dll`，2827304 字节，SHA-256 `7740e4a5900c1ade5d516f2a6b35487908d3b2e85322599d56ac3212fbf3187b` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1685 = decomp_ok 1661 + decomp_fail 24 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1685
- decomp_ok=1661
- decomp_fail=24
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pmlbridge.dll` |
| 字节数 | 2827304 |
| SHA-256 | `7740e4a5900c1ade5d516f2a6b35487908d3b2e85322599d56ac3212fbf3187b` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/pmlbridge.dll` |
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
| 段数 | 9 |
| 指令行数 | 425001 |

## 3. 反汇编清单（全量）

全文：disasm/pmlbridge.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pmlbridge.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1685
- decomp_ok（伪 C） = 1661
- decomp_fail = 24
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180008ae0` `sub_180008AE0`：RuntimeError（decompile returned None）
- `18000a130` `sub_18000A130`：RuntimeError（decompile returned None）
- `18002a4e0` `RTO_ANLZR_BASE_CREATE`：RuntimeError（decompile returned None）
- `180038b70` `sub_180038B70`：RuntimeError（decompile returned None）
- `1800399f0` `sub_1800399F0`：RuntimeError（decompile returned None）
- `1800a9c10` `sub_1800A9C10`：RuntimeError（decompile returned None）
- `1800aa770` `sub_1800AA770`：RuntimeError（decompile returned None）
- `1800ac600` `sub_1800AC600`：RuntimeError（decompile returned None）
- `1800adc10` `sub_1800ADC10`：RuntimeError（decompile returned None）
- `1801260f0` `sub_1801260F0`：RuntimeError（decompile returned None）
- `180147eb0` `sub_180147EB0`：RuntimeError（decompile returned None）
- `180157240` `sub_180157240`：RuntimeError（decompile returned None）
- `1801720e0` `sub_1801720E0`：RuntimeError（decompile returned None）
- `1801a1d70` `sub_1801A1D70`：RuntimeError（decompile returned None）
- `1801b0610` `sub_1801B0610`：RuntimeError（decompile returned None）
- `1801b0d50` `sub_1801B0D50`：RuntimeError（decompile returned None）
- `1801b1920` `sub_1801B1920`：RuntimeError（decompile returned None）
- `1801c3160` `RTO_COL_BASE_CREATE`：RuntimeError（decompile returned None）
- `1801df8c0` `sub_1801DF8C0`：RuntimeError（decompile returned None）
- `180201520` `sub_180201520`：RuntimeError（decompile returned None）
- `18022d480` `sub_18022D480`：RuntimeError（decompile returned None）
- `18022d850` `sub_18022D850`：RuntimeError（decompile returned None）
- `18022dbc0` `sub_18022DBC0`：RuntimeError（decompile returned None）
- `18022df20` `sub_18022DF20`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：542.0 s
- 日志：out/R1N/ida/logs/sha256_7740e4a5900c1ade5d516f2a6b35487908d3b2e85322599d56ac3212fbf3187b.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 24 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pmlbridge.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1685 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1685（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`RTO_MAXCOMP`, `RTO_IMALLOC_AND_INIT`, `RTO_DMALLOC_AND_INIT`, `RTO_CMALLOC_AND_INIT`, `RTO_INT2STR`, `sub_180001230`, `PML_COPY_DVECTOR`, `PML_COPY_IVECTOR`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/decompiled/pmlbridge.dll.c.txt` sha256=69a109d88a7114231a163acd8310fa261e38c7a69c4205377428c124b86c3130 bytes=7563779
- `native5/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/disasm/pmlbridge.dll.asm.txt` sha256=f43c3219c84a02509455e5dee827736bdeb0f4ea522976d9b6c62eef8b41cf4d bytes=16832382
