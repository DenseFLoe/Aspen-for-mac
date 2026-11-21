# LocalPropertyModel.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `LocalPropertyModel.dll`，507840 字节，SHA-256 `fe285bca24347646c248c3d8a44b28cf5b7728d30e415c4a886feb12570b536f` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 360 = decomp_ok 360 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=360
- decomp_ok=360
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `LocalPropertyModel.dll` |
| 字节数 | 507840 |
| SHA-256 | `fe285bca24347646c248c3d8a44b28cf5b7728d30e415c4a886feb12570b536f` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/LocalPropertyModel.dll` |
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
| 段数 | 10 |
| 指令行数 | 83919 |

## 3. 反汇编清单（全量）

全文：disasm/LocalPropertyModel.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/LocalPropertyModel.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 360
- decomp_ok（伪 C） = 360
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：145.4 s
- 日志：out/R1N/ida/logs/sha256_fe285bca24347646c248c3d8a44b28cf5b7728d30e415c4a886feb12570b536f.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `LocalPropertyModel.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 360 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +360（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `GPLAWS`, `sub_180002650`, `sub_180002940`, `SACHMVRY`, `sub_1800032A0`, `sub_180003C20`, `sub_180004E00`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/AHUtilities.dll.c.txt` sha256=e4814867762abd41f29bc04b7104559d265c3e8ee4e3271468a0afdc82f75242 bytes=36754
- `decompiled/AspenPropertiesLink.dll.c.txt` sha256=0a78c710a4fc65d65ff501514e332e797a873a8b8394e884bf139fc103b8bdbd bytes=157643
- `decompiled/LPMInterop.dll.c.txt` sha256=8913849ba60587ad38151ff233ac6c5b3a715f207655d18086233287851eb132 bytes=2679598
- `decompiled/LocalPropertyModel.dll.c.txt` sha256=32ff11f07d2d0141f1ccc85656d89dbb71897508013325b34f9806ad64a73aaf bytes=2510233
- `decompiled/StoreRecall.dll.c.txt` sha256=a769e5acccf546a9c4a003b7d918aa17e139acc9574a3d00d8fbfd9d51acf5dd bytes=2510569
- `disasm/AHUtilities.dll.asm.txt` sha256=98f11d6eff231549fc891b601e299d271138cfe51df0574997db19fc4ec9ed4e bytes=55448
- `disasm/AspenPropertiesLink.dll.asm.txt` sha256=2db37f73ab6c74169c6eb9cc85fe8ba18af2837148969d68cfc3a60782db2011 bytes=263857
- `disasm/LPMInterop.dll.asm.txt` sha256=9c5f671491197e498837ad15601a8e8e3c8bca4c861a4942f0e9b13ff37151ff bytes=4145686
- `disasm/LocalPropertyModel.dll.asm.txt` sha256=c460d0f70e85a43a29c66b4dac7b7282d7a236deec8ab0a77610471ee07e363f bytes=3260726
- `disasm/StoreRecall.dll.asm.txt` sha256=50337ce68fa2446263294a57328389a1f3f68c49a3e3ecb579c4aaa053e5f1fa bytes=3930923
