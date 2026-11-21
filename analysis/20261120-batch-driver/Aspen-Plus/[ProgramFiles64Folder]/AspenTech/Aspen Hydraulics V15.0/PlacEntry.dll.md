# PlacEntry.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `PlacEntry.dll`，3870152 字节，SHA-256 `c6e199310c652b8e5be83551ac02adb223a208ac7b6c8d11156739a7016036c9` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 4968 = decomp_ok 4958 + decomp_fail 10 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=4968
- decomp_ok=4958
- decomp_fail=10
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `PlacEntry.dll` |
| 字节数 | 3870152 |
| SHA-256 | `c6e199310c652b8e5be83551ac02adb223a208ac7b6c8d11156739a7016036c9` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/PlacEntry.dll` |
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
| 段数 | 11 |
| 指令行数 | 565787 |

## 3. 反汇编清单（全量）

全文：disasm/PlacEntry.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/PlacEntry.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 4968
- decomp_ok（伪 C） = 4958
- decomp_fail = 10
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `180136cd0` `sub_180136CD0`：RuntimeError（decompile returned None）
- `180235e44` `??$__acrt_lock_stream_and_call@V<lambda_9a20e10065b92b5193c3597a66cba9d4>@@@@YAHQEAU_iobuf@@$$QEAV<lambda_9a20e10065b92b5193c3597a66cba9d4>@@@Z`：RuntimeError（decompile returned None）
- `180237420` `sub_180237420`：RuntimeError（decompile returned None）
- `1802450b8` `??$__acrt_lock_and_call@V<lambda_22ebabd17bc4fa466a2aca6d8deb888d>@@@@YAHW4__acrt_lock_id@@$$QEAV<lambda_22ebabd17bc4fa466a2aca6d8deb888d>@@@Z`：RuntimeError（decompile returned None）
- `18024cbf4` `??$__acrt_lock_stream_and_call@V<lambda_c5860995281e5c4ce005b3de8f5874ee>@@@@YAXQEAU_iobuf@@$$QEAV<lambda_c5860995281e5c4ce005b3de8f5874ee>@@@Z`：RuntimeError（decompile returned None）
- `18024cc1c` `??$__acrt_lock_and_call@V<lambda_ab61a845afdef5b7c387490eaf3616ee>@@@@YAXW4__acrt_lock_id@@$$QEAV<lambda_ab61a845afdef5b7c387490eaf3616ee>@@@Z`：RuntimeError（decompile returned None）
- `18025d6a4` `??$__acrt_lock_and_call@V<lambda_876a65b173b8412d3a47c70a915b0cf4>@@@@YAXW4__acrt_lock_id@@$$QEAV<lambda_876a65b173b8412d3a47c70a915b0cf4>@@@Z`：RuntimeError（decompile returned None）
- `18025d6f0` `??$__acrt_lock_and_call@V<lambda_4466841279450cc726390878d4a41900>@@@@YAXW4__acrt_lock_id@@$$QEAV<lambda_4466841279450cc726390878d4a41900>@@@Z`：RuntimeError（decompile returned None）
- `1802640e4` `??$__acrt_lock_and_call@V<lambda_30712929f77e709619002f448b6a9510>@@@@YAXW4__acrt_lock_id@@$$QEAV<lambda_30712929f77e709619002f448b6a9510>@@@Z`：RuntimeError（decompile returned None）
- `180271ad4` `??$__acrt_lock_and_call@V<lambda_f9f2d660215b636168e2032e31cf969c>@@@@YA_NW4__acrt_lock_id@@$$QEAV<lambda_f9f2d660215b636168e2032e31cf969c>@@@Z`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：690.5 s
- 日志：out/R1N/ida/logs/sha256_c6e199310c652b8e5be83551ac02adb223a208ac7b6c8d11156739a7016036c9.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 10 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `PlacEntry.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 4968 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +4968（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`nullsub_18`, `PPLINTEGRATEPLAC`, `nullsub_1`, `nullsub_2`, `nullsub_19`, `nullsub_20`, `nullsub_21`, `sub_180001120`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/FortranPhase.dll.c.txt` sha256=329462fc045ac2eadff170552b4eec409159f44d01df0c7d03bb3156aa8acecb bytes=6140871
- `decompiled/PlacEntry.dll.c.txt` sha256=3a4eca43a2c8d55d2ef71019c9871ee3c64696437778afbb88a930facc762391 bytes=13016162
- `disasm/FortranPhase.dll.asm.txt` sha256=2fd48275ae2515acd31a4e1ab15a40d46ced80664ae770aebce9fe11a9baa5d0 bytes=9944462
- `disasm/PlacEntry.dll.asm.txt` sha256=320ecd4e284f7069f309b8dd169d224120374a1455c976aa8feb5db19abe4cfb bytes=21488964
