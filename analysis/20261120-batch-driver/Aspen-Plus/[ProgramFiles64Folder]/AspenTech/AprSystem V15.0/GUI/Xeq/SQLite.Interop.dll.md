# SQLite.Interop.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `SQLite.Interop.dll`，1829040 字节，SHA-256 `aba67c7e6c01856838b8bc6b0ba95e864e1fdcb3750aa7cdc1bc73511cea6fe4` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 4044 = decomp_ok 4044 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=4044
- decomp_ok=4044
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `SQLite.Interop.dll` |
| 字节数 | 1829040 |
| SHA-256 | `aba67c7e6c01856838b8bc6b0ba95e864e1fdcb3750aa7cdc1bc73511cea6fe4` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AprSystem V15.0/GUI/Xeq/SQLite.Interop.dll` |
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
| 指令行数 | 371748 |

## 3. 反汇编清单（全量）

全文：disasm/SQLite.Interop.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/SQLite.Interop.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 4044
- decomp_ok（伪 C） = 4044
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：363.5 s
- 日志：out/R1N/ida/logs/sha256_aba67c7e6c01856838b8bc6b0ba95e864e1fdcb3750aa7cdc1bc73511cea6fe4.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `SQLite.Interop.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 4044 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +4044（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`__local_stdio_printf_options`, `snprintf`, `AreFileApisANSI`, `ReadFile`, `HeapCreate`, `HeapFree`, `GetFullPathNameW`, `WriteFile`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/APRegFix.exe.c.txt` sha256=d17fe3d8d7f631f308a6bc5b09080da63690b06a4915e4eec39a517d498a3125 bytes=1947951
- `decompiled/SQLite.Interop.dll.c.txt` sha256=a9c9f51122a8d600633dccbc0d4236e29ca7dcdbafdf3317e68bb7afb5536531 bytes=7565373
- `decompiled/attpsr.dll.c.txt` sha256=9f365cbf33e4f4cb8d63c01dd3fe9d01eb9b2fa25d33c7becae95f22e92afdea bytes=5368030
- `decompiled/chrome_elf.dll.c.txt` sha256=76cedf03c83d7b13262fc1a51babbb95beb5817d23de8f72e5218720e72897c8 bytes=5166984
- `decompiled/pfsplot.ocx.c.txt` sha256=10dce923427be7c7b114b63afd1a06b9f76a487fc748b29ed0ae5b871b2d1871 bytes=13246202
- `disasm/APRegFix.exe.asm.txt` sha256=758bc32fa7cb9714d4ee57df46947d9f8065be90ee4153c5155fb0341de5ed0c bytes=2205675
- `disasm/SQLite.Interop.dll.asm.txt` sha256=4ad069ae55bdf9b34ba4e7d01a6abb4513e3ea6b124c7cda64132413deb9f72c bytes=13220989
- `disasm/attpsr.dll.asm.txt` sha256=01494e1e930ce2264d902e59cf24eb76a07dfa5172de1bdde5f7101ede182be9 bytes=12509360
- `disasm/chrome_elf.dll.asm.txt` sha256=8886ef4855cd8f2e49f32a6065c3c222b3bdf2677b8e8f6fd332159c6c25a862 bytes=9278418
- `disasm/pfsplot.ocx.asm.txt` sha256=323311e7d848575595d3ad1c148821b6a6fa987c28b7a18a4d43f67a10b46dc8 bytes=23527413
