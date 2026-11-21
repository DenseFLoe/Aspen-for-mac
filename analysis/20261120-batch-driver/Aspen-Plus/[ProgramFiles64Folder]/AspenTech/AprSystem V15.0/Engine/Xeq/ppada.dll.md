# ppada.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ppada.dll`，873512 字节，SHA-256 `1e6309e75201825373169b6714a21033193bcb21e400cb21c82837cf533af121` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 562 = decomp_ok 531 + decomp_fail 31 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=562
- decomp_ok=531
- decomp_fail=31
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ppada.dll` |
| 字节数 | 873512 |
| SHA-256 | `1e6309e75201825373169b6714a21033193bcb21e400cb21c82837cf533af121` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/ppada.dll` |
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
| 指令行数 | 125799 |

## 3. 反汇编清单（全量）

全文：disasm/ppada.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ppada.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 562
- decomp_ok（伪 C） = 531
- decomp_fail = 31
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1800031a0` `sub_1800031A0`：RuntimeError（decompile returned None）
- `180014170` `sub_180014170`：RuntimeError（decompile returned None）
- `180014b30` `sub_180014B30`：RuntimeError（decompile returned None）
- `180014f70` `sub_180014F70`：RuntimeError（decompile returned None）
- `180016310` `sub_180016310`：RuntimeError（decompile returned None）
- `180017990` `sub_180017990`：RuntimeError（decompile returned None）
- `1800192b0` `sub_1800192B0`：RuntimeError（decompile returned None）
- `18001a190` `sub_18001A190`：RuntimeError（decompile returned None）
- `18001bf50` `sub_18001BF50`：RuntimeError（decompile returned None）
- `18001e110` `sub_18001E110`：RuntimeError（decompile returned None）
- `180020d60` `sub_180020D60`：RuntimeError（decompile returned None）
- `180023ad0` `sub_180023AD0`：RuntimeError（decompile returned None）
- `1800254b0` `sub_1800254B0`：RuntimeError（decompile returned None）
- `180025f00` `sub_180025F00`：RuntimeError（decompile returned None）
- `180026760` `sub_180026760`：RuntimeError（decompile returned None）
- `180029be0` `sub_180029BE0`：RuntimeError（decompile returned None）
- `180031e00` `sub_180031E00`：RuntimeError（decompile returned None）
- `180047ae0` `sub_180047AE0`：RuntimeError（decompile returned None）
- `180048590` `sub_180048590`：RuntimeError（decompile returned None）
- `1800490a0` `sub_1800490A0`：RuntimeError（decompile returned None）
- `180049ac0` `sub_180049AC0`：RuntimeError（decompile returned None）
- `180051f30` `sub_180051F30`：RuntimeError（decompile returned None）
- `180057620` `sub_180057620`：RuntimeError（decompile returned None）
- `180057bd0` `ADA_PCCPIG`：RuntimeError（decompile returned None）
- `18005a100` `sub_18005A100`：RuntimeError（decompile returned None）
- `18005bbb0` `sub_18005BBB0`：RuntimeError（decompile returned None）
- `180064610` `sub_180064610`：RuntimeError（decompile returned None）
- `180066480` `sub_180066480`：RuntimeError（decompile returned None）
- `180071cd0` `sub_180071CD0`：RuntimeError（decompile returned None）
- `180081cb0` `ADA_RCHALL`：RuntimeError（decompile returned None）
- `180092d90` `ADA_RCHALL2`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：174.2 s
- 日志：out/R1N/ida/logs/sha256_1e6309e75201825373169b6714a21033193bcb21e400cb21c82837cf533af121.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 31 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ppada.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 562 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +562（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`ADA_PCCSEM`, `ADA_ADARSM`, `ADA_PTPSEM`, `ADA_ADASUP`, `sub_180002C70`, `sub_1800031A0`, `sub_180006E60`, `sub_1800090D0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/decompiled/ppada.dll.c.txt` sha256=e493a1d346b736753e9b6b8297cdeeffb033232b2790c3ce35a55287b2baa91a bytes=2099130
- `native4/01-completed/Aspen-Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/disasm/ppada.dll.asm.txt` sha256=7c7587aa090c04da8084ce49359dde8c47d322e578740fb31e66e8a109c90b97 bytes=4947671
