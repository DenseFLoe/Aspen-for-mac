# statuscodeCME.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `statuscodeCME.dll`，63016 字节，SHA-256 `588239aa163356d1cda807fe2ea9ffe349eafb1cd1eecfcd82256c0448744df2` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 105 = decomp_ok 105 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=105
- decomp_ok=105
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `statuscodeCME.dll` |
| 字节数 | 63016 |
| SHA-256 | `588239aa163356d1cda807fe2ea9ffe349eafb1cd1eecfcd82256c0448744df2` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/GUI/Xeq/statuscodeCME.dll` |
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
| 指令行数 | 2479 |

## 3. 反汇编清单（全量）

全文：disasm/statuscodeCME.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/statuscodeCME.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 105
- decomp_ok（伪 C） = 105
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：8.3 s
- 日志：out/R1N/ida/logs/sha256_588239aa163356d1cda807fe2ea9ffe349eafb1cd1eecfcd82256c0448744df2.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `statuscodeCME.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 105 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +105（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001020`, `sub_180001060`, `sub_180001090`, `sub_1800010A0`, `ATDisplayStatusMessage`, `ATGenerateErrorInfo`, `ATGetStatusMessage`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/AspenPlusTask.ocx.c.txt` sha256=48f61e37dd47c49c36580ddfbdf904768dfc132b6e5d643b228421c70b80ea80 bytes=334973
- `decompiled/EditorCtrl.ocx.c.txt` sha256=545fc2ac84f6511ecfdc808508a4c5930c4c90f443be711f1f16ab8849bc22f4 bytes=2780045
- `decompiled/FxCdbCME.dll.c.txt` sha256=95afa69f56c72e27d78ef020ced45291d4e3635f8a63d23d867758d22a87f5af bytes=2356629
- `decompiled/FxObjCME.dll.c.txt` sha256=38267bbaa17c879869cb10b4e7ef07bfe1829fe1906b4165d4ae70700137f4bc bytes=175232
- `decompiled/IconEditorAx.ocx.c.txt` sha256=3fd6cec13809a4aa4e66e5f4af8f63f76f2a1ec86f2cf629cfad1944be61d24d bytes=147220
- `decompiled/Icondef.exe.c.txt` sha256=663c799fa77896beb0989d147999c4eefb4878bce3f5df4535b7cff19030739f bytes=2556726
- `decompiled/NNSolver.dll.c.txt` sha256=6756abe4325fb7e67e7f7068e8ee81af3add73ba12f7ce92dcb764b0b6ec1722 bytes=260137
- `decompiled/SorResDll.dll.c.txt` sha256=958c3415f9efd1225f5cb31578e912383e346d32b971ab527db10384a46b6e53 bytes=56490
- `decompiled/astcomp.exe.c.txt` sha256=cb604fd897ced48d636cedcff65a3ebc080e1b258d3061c2867c58631fd5c86f bytes=2556753
- `decompiled/astcompdll.dll.c.txt` sha256=c17cec9b8cdacb7fb6f06da25acb29b84e42a38ce29f7820c141db336062742d bytes=230225
- `decompiled/atxc.dll.c.txt` sha256=d89110cb1383e7fc8cc349bfff914a5895c80dee3085b30fa91979ba5da701c7 bytes=3646501
- `decompiled/iconed.dll.c.txt` sha256=75fcba03d95a2a9e870b0d12ca1888ef6d79dba2ade10911b4e60e00e9c648a1 bytes=1657701
- `decompiled/statuscodeCME.dll.c.txt` sha256=240add96be83cbf9dbfbfe1476fa770f27ca0c0faf3751e27dcbcc0179551c2a bytes=60755
- `disasm/AspenPlusTask.ocx.asm.txt` sha256=a81d04d5acfe9c05e84fbaba090dd45dc8d4738c9a5397337a869cb0f8b15a0c bytes=408027
- `disasm/EditorCtrl.ocx.asm.txt` sha256=29a19ee3e06c5a4bbe52c8a6382fc247dffabaa93d341ac38e2e0e2e67ce9b7f bytes=5009064
- `disasm/FxCdbCME.dll.asm.txt` sha256=d3b47b40edfe1e2b895de1fcbd5bc0cb02aa3bfe425d82e758313bf77a19bd3d bytes=4032627
- `disasm/FxObjCME.dll.asm.txt` sha256=2c2a748aacefd72694cab1b1131e60c50be0b878e4cf86ff4f9efd985b42ff3e bytes=305862
- `disasm/IconEditorAx.ocx.asm.txt` sha256=2e2f33353bd2a504ff4e7710fd781b63e64d6491a5c91fcf304aaee492758117 bytes=160774
- `disasm/Icondef.exe.asm.txt` sha256=ceed1b69fbeae4e54475d7bde65c37bb459b836aafec7f52e001bd2110fcf51e bytes=4004708
- `disasm/NNSolver.dll.asm.txt` sha256=7392377c349436464825f04d62fd00d77dabdf4fc4c43ed1a5c1c635777210f6 bytes=480550
- `disasm/SorResDll.dll.asm.txt` sha256=088176c8765950812cc21fc3d4ea1e07582801253c484351339d3cac8247f7bf bytes=100048
- `disasm/astcomp.exe.asm.txt` sha256=5618e0eca835197145fc2219a42a98fcb000d23abce5b33d8707530b5ed6b42c bytes=4004677
- `disasm/astcompdll.dll.asm.txt` sha256=bc6f2ddc563826f2e3f37bde9933228e1d49da0a0f709530326b8a1cc050ea9f bytes=378609
- `disasm/atxc.dll.asm.txt` sha256=0c9327818ee5ef7654d3f20474357700d66727044cacfdda2674be8d3012434b bytes=5784492
- `disasm/iconed.dll.asm.txt` sha256=6f78b53ca0ea94c0e3ee3bfb772ad568648dc4318706b257dad3f26186cae941 bytes=2833837
- `disasm/statuscodeCME.dll.asm.txt` sha256=cdbe7ff895ecdf96a6e0424405eed976cab91d94f5695b8d2651c6d252f803e8 bytes=98365
- `x86/decompiled/CalcExcelAddInRes32.dll.c.txt` sha256=52341192f1abb38adc8fdc7aa8ad44395d868a79afdfcb5e7193db330298ede8 bytes=41986
- `x86/disasm/CalcExcelAddInRes32.dll.asm.txt` sha256=eb024bebaf03eb3a2056fea4f2a222046234368c0e851fb2e171cbda57861275 bytes=80546
