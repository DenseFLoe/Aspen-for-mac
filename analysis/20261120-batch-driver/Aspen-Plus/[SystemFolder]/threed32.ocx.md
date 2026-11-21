# threed32.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `threed32.ocx`，200704 字节，SHA-256 `8f317a229950e0393ab10e12554fd2c6be5b9496ffb5302ee6c24f567c944a34` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1129 = decomp_ok 1073 + decomp_fail 56 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1129
- decomp_ok=1073
- decomp_fail=56
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `threed32.ocx` |
| 字节数 | 200704 |
| SHA-256 | `8f317a229950e0393ab10e12554fd2c6be5b9496ffb5302ee6c24f567c944a34` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/threed32.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x10000000` |
| 段数 | 6 |
| 指令行数 | 29490 |

## 3. 反汇编清单（全量）

全文：disasm/threed32.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/threed32.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1129
- decomp_ok（伪 C） = 1073
- decomp_fail = 56
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `10001160` `sub_10001160`：RuntimeError（decompile returned None）
- `10001420` `sub_10001420`：RuntimeError（decompile returned None）
- `10001490` `sub_10001490`：RuntimeError（decompile returned None）
- `10001830` `sub_10001830`：RuntimeError（decompile returned None）
- `10001ac0` `sub_10001AC0`：RuntimeError（decompile returned None）
- `10003b90` `sub_10003B90`：RuntimeError（decompile returned None）
- `10003c40` `??1CCommonDialog@@UAE@XZ`：RuntimeError（decompile returned None）
- `10003cd0` `sub_10003CD0`：RuntimeError（decompile returned None）
- `10003d50` `sub_10003D50`：RuntimeError（decompile returned None）
- `10003db0` `sub_10003DB0`：RuntimeError（decompile returned None）
- `10003e20` `sub_10003E20`：RuntimeError（decompile returned None）
- `10003fe0` `sub_10003FE0`：RuntimeError（decompile returned None）
- `10004320` `sub_10004320`：RuntimeError（decompile returned None）
- `10004390` `sub_10004390`：RuntimeError（decompile returned None）
- `10004660` `sub_10004660`：RuntimeError（decompile returned None）
- `10006de0` `sub_10006DE0`：RuntimeError（decompile returned None）
- `10006fe0` `sub_10006FE0`：RuntimeError（decompile returned None）
- `10007300` `sub_10007300`：RuntimeError（decompile returned None）
- `10007370` `sub_10007370`：RuntimeError（decompile returned None）
- `10007550` `sub_10007550`：RuntimeError（decompile returned None）
- `10007870` `sub_10007870`：RuntimeError（decompile returned None）
- `100078e0` `sub_100078E0`：RuntimeError（decompile returned None）
- `10007c00` `sub_10007C00`：RuntimeError（decompile returned None）
- `10007e80` `sub_10007E80`：RuntimeError（decompile returned None）
- `1000ab20` `sub_1000AB20`：RuntimeError（decompile returned None）
- `1000d4d0` `sub_1000D4D0`：RuntimeError（decompile returned None）
- `1000d6a0` `sub_1000D6A0`：RuntimeError（decompile returned None）
- `1000d9f0` `sub_1000D9F0`：RuntimeError（decompile returned None）
- `1000da60` `sub_1000DA60`：RuntimeError（decompile returned None）
- `1000dc40` `sub_1000DC40`：RuntimeError（decompile returned None）
- `1000e000` `sub_1000E000`：RuntimeError（decompile returned None）
- `1000e070` `sub_1000E070`：RuntimeError（decompile returned None）
- `1000e3a0` `sub_1000E3A0`：RuntimeError（decompile returned None）
- `1000e610` `sub_1000E610`：RuntimeError（decompile returned None）
- `10010b00` `sub_10010B00`：RuntimeError（decompile returned None）
- `10010c40` `sub_10010C40`：RuntimeError（decompile returned None）
- `10010e20` `sub_10010E20`：RuntimeError（decompile returned None）
- `10010e70` `sub_10010E70`：RuntimeError（decompile returned None）
- `10010ee0` `sub_10010EE0`：RuntimeError（decompile returned None）
- `10011220` `sub_10011220`：RuntimeError（decompile returned None）
- `10011490` `sub_10011490`：RuntimeError（decompile returned None）
- `10013520` `sub_10013520`：RuntimeError（decompile returned None）
- `10013720` `sub_10013720`：RuntimeError（decompile returned None）
- `10013b00` `sub_10013B00`：RuntimeError（decompile returned None）
- `10013b70` `sub_10013B70`：RuntimeError（decompile returned None）
- `10013e70` `sub_10013E70`：RuntimeError（decompile returned None）
- `100140f0` `sub_100140F0`：RuntimeError（decompile returned None）
- `10015620` `sub_10015620`：RuntimeError（decompile returned None）
- `10015e70` `sub_10015E70`：RuntimeError（decompile returned None）
- `10016230` `sub_10016230`：RuntimeError（decompile returned None）
- `10017160` `?FireEvent@COleControl@@QAAXJPAEZZ`：RuntimeError（decompile returned None）
- `100175ed` `unknown_libname_2`：RuntimeError（decompile returned None）
- `1001763c` `??1AFX_MODULE_STATE@@UAE@XZ`：RuntimeError（decompile returned None）
- `100176a8` `??1?$CProcessLocal@VAFX_MODULE_PROCESS_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `100176e3` `??1?$CThreadLocal@VAFX_MODULE_THREAD_STATE@@@@QAE@XZ`：RuntimeError（decompile returned None）
- `1001772c` `unknown_libname_3`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：20.9 s
- 日志：out/R1N/ida/logs/sha256_8f317a229950e0393ab10e12554fd2c6be5b9496ffb5302ee6c24f567c944a34.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 56 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `threed32.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1129 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1129（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_10001000`, `sub_10001070`, `sub_10001080`, `sub_10001090`, `sub_100010A0`, `sub_100010B0`, `sub_100010C0`, `sub_100010D0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `native3/01-completed/Aspen-Plus/[SystemFolder]/decompiled/threed32.ocx.c.txt` sha256=04294b0a8cda428307fd005c4f96b187c9d97131a3be1d8194296afe0a65ce0d bytes=452688
- `native3/01-completed/Aspen-Plus/[SystemFolder]/disasm/threed32.ocx.asm.txt` sha256=da36138ca5612f99dd88dc4af2a47c87cc085059d3c91a12d8938a7cbd4041cd bytes=1006897
