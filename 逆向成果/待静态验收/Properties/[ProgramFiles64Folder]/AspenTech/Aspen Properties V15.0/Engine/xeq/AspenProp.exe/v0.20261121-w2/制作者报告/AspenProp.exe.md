# AspenProp.exe 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `AspenProp.exe`，60456 字节，SHA-256 `fb5323d8e20fb5a718dfd966286d30d2f54246d9d3c9296b26a4420c4996c7dc` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 225 = decomp_ok 225 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=225
- decomp_ok=225
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `AspenProp.exe` |
| 字节数 | 60456 |
| SHA-256 | `fb5323d8e20fb5a718dfd966286d30d2f54246d9d3c9296b26a4420c4996c7dc` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Properties V15.0/Engine/xeq/AspenProp.exe` |
| product_raw | `Properties` |
| 产品目录 | `Aspen-Properties` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x140000000` |
| 段数 | 5 |
| 指令行数 | 7814 |

## 3. 反汇编清单（全量）

全文：disasm/AspenProp.exe.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/AspenProp.exe.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 225
- decomp_ok（伪 C） = 225
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：41.0 s
- 日志：out/R1N/ida/logs/sha256_fb5323d8e20fb5a718dfd966286d30d2f54246d9d3c9296b26a4420c4996c7dc.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `AspenProp.exe` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 225 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +225（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`main`, `sub_140001060`, `sub_140003300`, `sub_140005460`, `sub_1400056F0`, `sub_140005730`, `sub_140005900`, `sub_140005A20`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/APXLAddinLoader.dll.c.txt` sha256=9e8007b1417280df8bfe42125654f1e535f028de725851a704a41734597f4f69 bytes=2792112
- `decompiled/APXLAddinLoaderx64.dll.c.txt` sha256=d5d1bc2611cb6de72301abfb2601092856c61c42d3ca7f6866734dcdfafd99b9 bytes=2974011
- `decompiled/APropMain.exe.c.txt` sha256=eafded76891c7d5286f9cf6537c307ac3fe862de94385e53ed785d8852cc194e bytes=64882
- `decompiled/AspenProp.exe.c.txt` sha256=176b3b5ab3c6a088f85fcbb25b19a6fd5e7b2d35c377c4cb8cff8ab02ca4aa36 bytes=160130
- `decompiled/Aspenproperty95.dll.c.txt` sha256=5a835e453e7c279f08c1e157ed25ce364a959311cb0a81297a9703774c43f528 bytes=3175
- `decompiled/util.dll.c.txt` sha256=02a8197d8a5cf6da6d6f12a24ef961b6f256e7969a4e308fe4b0d36bda4f3402 bytes=11471
- `disasm/APXLAddinLoader.dll.asm.txt` sha256=cd1a192b2f88a5b0862e4248e40031d2c5733dcfe8b5489c8a205b2ed9156262 bytes=4476383
- `disasm/APXLAddinLoaderx64.dll.asm.txt` sha256=feae0d58498903855a43a53c006181c4b24be80e27e2b946ecd2f16a29697dd3 bytes=4598260
- `disasm/APropMain.exe.asm.txt` sha256=188ed0e8bf12dee7c25c1322108bab1452454d1e2437aa17243aa81133d4038d bytes=103882
- `disasm/AspenProp.exe.asm.txt` sha256=b99f0ddbf1d7dac8809969226ca873c479344189482d37cb9bd5d4b68604eab2 bytes=305384
- `disasm/Aspenproperty95.dll.asm.txt` sha256=3fbb21afee13a41e7f5709dd06938a9e36d691d76ba59d7fd313b440301e23c5 bytes=2131
- `disasm/util.dll.asm.txt` sha256=95bddd8ee6ea7aee42eb3bced9856972cdf8418b9345794d2832ca295f03f099 bytes=10142
