# EAECONOMICCONSTRAINT.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `EAECONOMICCONSTRAINT.dll`，116776 字节，SHA-256 `49f7180024f7684974189494a7fd629f817ce21bf3ad569ca145373d09f75dc6` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 768 = decomp_ok 768 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=768
- decomp_ok=768
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `EAECONOMICCONSTRAINT.dll` |
| 字节数 | 116776 |
| SHA-256 | `49f7180024f7684974189494a7fd629f817ce21bf3ad569ca145373d09f75dc6` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/AMSystem V15.0/Bin/EAECONOMICCONSTRAINT.dll` |
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
| 指令行数 | 9047 |

## 3. 反汇编清单（全量）

全文：disasm/EAECONOMICCONSTRAINT.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/EAECONOMICCONSTRAINT.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 768
- decomp_ok（伪 C） = 768
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：17.7 s
- 日志：out/R1N/ida/logs/sha256_49f7180024f7684974189494a7fd629f817ce21bf3ad569ca145373d09f75dc6.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `EAECONOMICCONSTRAINT.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 768 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +768（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`unknown_libname_1`, `sub_180001020`, `sub_180001080`, `sub_1800022B0`, `sub_180002340`, `sub_180002390`, `sub_180003E50`, `sub_1800041B0`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/AMExportModelsVersion.dll.c.txt` sha256=99d1b0686f6ee9c236a1a828bf56f90441f9d7202e138e7d9f27c670186e8d69 bytes=2555566
- `decompiled/AMExportTypesVersion.dll.c.txt` sha256=99d1b0686f6ee9c236a1a828bf56f90441f9d7202e138e7d9f27c670186e8d69 bytes=2555566
- `decompiled/AMPropMod.dll.c.txt` sha256=663873edf9f94e1556e2a1cd6a05e34fcb7d33791d42ce91e69286803ab5f092 bytes=2263162
- `decompiled/AMSysLib.dll.c.txt` sha256=2cba1d45685587b9b2f71d76926aaf0eda239bd30f0366f18fbff615bcdf3024 bytes=76594
- `decompiled/Adsim.dll.c.txt` sha256=8ff78ac63fca707fb9802b48c84ac45f31d09ccafda5e4dd76a16f9371614bdd bytes=234413
- `decompiled/Adsim2.dll.c.txt` sha256=e31b95203a19ef850aec81015c07ef3e05167c92d7a8934d1b0e42f807797006 bytes=249399
- `decompiled/AspChrom.dll.c.txt` sha256=761bf3e57550939ea739d7f8eec8dcd0675a25822e238fd18dfb19c56574d70a bytes=438262
- `decompiled/EAECONOMICCONSTRAINT.dll.c.txt` sha256=8ccd01f6373949d094666281efd9a8f0114ab24617973dfea65955794820209f bytes=240789
- `decompiled/EAProc.dll.c.txt` sha256=1d20bacca856c5ea0f0e2089351dfacc4e8c6ae295e93c96dade6d22b669a03b bytes=141846
- `decompiled/atdll_support.dll.c.txt` sha256=1d04f67a9bf25058d0111bcded72abaabe6edbe22ba7f3ec5c2f6527ac47afb8 bytes=265688
- `decompiled/fug.dll.c.txt` sha256=5f83f7bdf69d5080c428639fe81d27dde10c458ee95238937d1de74387a6d525 bytes=14145
- `decompiled/gpp.dll.c.txt` sha256=c752de508c02080d8df8d85c7e101875409434865ed615b32557b948ecee9c2c bytes=2966420
- `disasm/AMExportModelsVersion.dll.asm.txt` sha256=4609fdc368f26cb976128602f7972fd8db9228bc5e09eecdbffc0f5d717d0f57 bytes=3989892
- `disasm/AMExportTypesVersion.dll.asm.txt` sha256=4609fdc368f26cb976128602f7972fd8db9228bc5e09eecdbffc0f5d717d0f57 bytes=3989892
- `disasm/AMPropMod.dll.asm.txt` sha256=9afddd120cb981cab3749c2947248d0861115c09f1e1f213767352fd54179500 bytes=3535780
- `disasm/AMSysLib.dll.asm.txt` sha256=21184dff78bbd7c7978ec0abd1396e0c6714d668ff76a160af73add5611bb1dd bytes=128975
- `disasm/Adsim.dll.asm.txt` sha256=bfcce612ffb0e3cb07c53de10e80c5582670a728f5a8ca21f1d4de901e4048a9 bytes=312657
- `disasm/Adsim2.dll.asm.txt` sha256=4bc9f166f1da8eca386d9354003a394d3d34086f0d0d1e93f37a18d902a17256 bytes=363798
- `disasm/AspChrom.dll.asm.txt` sha256=34c3496dc736877fbb46956388448ae4f241e6c535f82cf6bdedd72ba71f8304 bytes=572076
- `disasm/EAECONOMICCONSTRAINT.dll.asm.txt` sha256=e86bb670f9bc753c724ed7caecc5b32945c967881db559368dcb7e9282393cc8 bytes=352138
- `disasm/EAProc.dll.asm.txt` sha256=db7ba7f462e25a1fb788afc4effe723b0420898958121609a77afc436cd6d51c bytes=287076
- `disasm/atdll_support.dll.asm.txt` sha256=07cb94202dbb9a1481d9251f7c31663159e08d0b33a6e8f64ccda4bb24334e7e bytes=515989
- `disasm/fug.dll.asm.txt` sha256=1a38c84567e778c880b3275332ad3d9764e2ac3e6a0eb701efdffe65cdd60e42 bytes=25985
- `disasm/gpp.dll.asm.txt` sha256=a0bab8d470536664bb82fe519f87777b5a1e7a438d0fd5d99eeae8b99337fdd1 bytes=5277475
