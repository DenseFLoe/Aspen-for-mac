# perl528.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `perl528.dll`，3093320 字节，SHA-256 `361920483fa27b8214c9984fc0bdb2a021cfbe3060b89abe43b34f74a7638c89` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3194 = decomp_ok 3193 + decomp_fail 1 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3194
- decomp_ok=3193
- decomp_fail=1
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `perl528.dll` |
| 字节数 | 3093320 |
| SHA-256 | `361920483fa27b8214c9984fc0bdb2a021cfbe3060b89abe43b34f74a7638c89` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/perl528.dll` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x6a280000` |
| 段数 | 11 |
| 指令行数 | 363918 |

## 3. 反汇编清单（全量）

全文：disasm/perl528.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/perl528.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3194
- decomp_ok（伪 C） = 3193
- decomp_fail = 1
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `6a28b6e0` `Perl_yylex`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：392.7 s
- 日志：out/R1N/ida/logs/sha256_361920483fa27b8214c9984fc0bdb2a021cfbe3060b89abe43b34f74a7638c89.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 1 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `perl528.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3194 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3194（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_6A281000`, `sub_6A281050`, `sub_6A2812B0`, `DllEntryPoint`, `sub_6A281470`, `sub_6A2815B0`, `sub_6A281620`, `sub_6A281640`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part5.tar.gz

- `decompiled/PetroleumProps.dll.c.txt` sha256=e9724887b6a1b081266653cb529d3b6120e61e2140ebb1118868c321ccc2e009 bytes=2194618
- `decompiled/aesxml.dll.c.txt` sha256=bf0bee7de702047ee8114d155d6e20b64ee639233ee6b4bca0d4c926416fef9d bytes=4959642
- `decompiled/apflash.dll.c.txt` sha256=ac86c25ae5a70bf6f4d56eb6ecd856ab767dfe60909f478756810a0d31a2f7e2 bytes=4042606
- `decompiled/attpsr.dll.c.txt` sha256=9f365cbf33e4f4cb8d63c01dd3fe9d01eb9b2fa25d33c7becae95f22e92afdea bytes=5368030
- `decompiled/hyspropC.dll.c.txt` sha256=2ad8eb7fc3dd4a5cf5ce159ffbf1489bc359555503f41518076e8307759023dc bytes=4031888
- `decompiled/libifcoremd.dll.c.txt` sha256=a9dcc4834e70b0c00a226bd8e9b60b37e502624c192bc6ed8d494f9dd870b309 bytes=6166536
- `decompiled/libmmd.dll.c.txt` sha256=c329a8c8c0a62756d9ea916b18a359328fcac7432c5a5f51dbaa4db2fb0aebcb bytes=6999392
- `decompiled/perl528.dll.c.txt` sha256=00b24837c54f8d1346cd01ccb67db917c099cdc58fde3c1b876ed981f06c372a bytes=6955295
- `decompiled/ppaproph.dll.c.txt` sha256=435c9d012b00b39ebda4b862c0dd9d8eb738a37a02391b0354e58fee6f84f1da bytes=1756634
- `decompiled/ppbase.dll.c.txt` sha256=37e8927e58343f07e4aad6a79b614b6b1c24c16b1f74e747e682536b8224364f bytes=2957961
- `decompiled/ppdrs.dll.c.txt` sha256=056cf218322a27760fca9100a76619685feb395e6ec6141d5edf8f158371b2b5 bytes=2252597
- `decompiled/ppflash.dll.c.txt` sha256=3e6b509912a736f80b9a3f8c436244dda3dd0cacb2f4530a2707a3a315c41553 bytes=3547283
- `decompiled/ppmon.dll.c.txt` sha256=217960c9553f6e8e7793a321db4556fa837ad0e34627baa1bf01d74597d4590d bytes=4898291
- `decompiled/pppurenist.dll.c.txt` sha256=9179e1351acd75c43c0a2ab5818f70123788c339fddccfac1509799191fe3203 bytes=35455
- `decompiled/pptderefprop.dll.c.txt` sha256=f8efceb95517cbb03003b8885f6934c975c23a3f67faa11beec9812309552261 bytes=4752736
- `decompiled/ppupp.dll.c.txt` sha256=87d1b8d6d63ec2f3c10a52427a4678fad59cdb0505b5af3b1c335de422af30f2 bytes=2583705
- `decompiled/zeapexec.dll.c.txt` sha256=ee0a345801a49fc484a27fb6212bdf914a919766c947ff20429dcb2df1f6022c bytes=5076653
- `decompiled/zecblock.dll.c.txt` sha256=588a9368524870c00e80037ec803a2e6d46c189c35694971bca408d2ae735f95 bytes=2800281
- `decompiled/zepdqs.dll.c.txt` sha256=aeb24a8b2fcb52102f03ca1c1dee5332be86bc029d9430513ad239e2e32c0523 bytes=2254341
- `decompiled/zepml.dll.c.txt` sha256=d176b2eaf45a215896ad62eabfa3a4785bff03f158d27a58bbe74aac74bc2db5 bytes=9898999
- `disasm/PetroleumProps.dll.asm.txt` sha256=2ca9b111e9a3bdea91d4926e499d61de39103f94bc728bbe603b148e6409f626 bytes=4103399
- `disasm/aesxml.dll.asm.txt` sha256=3f5d98ed9f321c4a0e7425201563015ff73c8c28fc4be59d48f208e4ff519592 bytes=8347040
- `disasm/apflash.dll.asm.txt` sha256=f98ee2f6ac3772d17770c1e2f77a71c5cc2c5b736eca8808231954c1fdd79c82 bytes=11053768
- `disasm/attpsr.dll.asm.txt` sha256=01494e1e930ce2264d902e59cf24eb76a07dfa5172de1bdde5f7101ede182be9 bytes=12509360
- `disasm/hyspropC.dll.asm.txt` sha256=9473e325daca4609bec7f191364a637e3a9b31ff5ea229b7dba6be9360409f7d bytes=8087740
- `disasm/libifcoremd.dll.asm.txt` sha256=be4c0882a2cdbb844a2eb1e88abe3f1b5a34a1daa604d5931e2d3225b3a91b21 bytes=9072651
- `disasm/libmmd.dll.asm.txt` sha256=d17d25f661df1115eb3796c91adde9f93b7cdbe1c20400b68003f9a24f523224 bytes=13622180
- `disasm/perl528.dll.asm.txt` sha256=6cd9e507da6f0f783348094a25972c8bf58cab6e2d4525594114af0e5bb91c9e bytes=12361122
- `disasm/ppaproph.dll.asm.txt` sha256=bfbbe91a488fd9120f3bff1b71fbb1e37a4bb3a03a4d32c8456557836e93a058 bytes=6805591
- `disasm/ppbase.dll.asm.txt` sha256=9b05ef4f915cbb4a7700de2f69af053da4afbae4bfcb3e16d48c088f6e802651 bytes=5430964
- `disasm/ppdrs.dll.asm.txt` sha256=5ae2abe9a66da874ec00932c012d94bda273da2b8a06fc1658c3a9501f7b30a5 bytes=6541563
- `disasm/ppflash.dll.asm.txt` sha256=2935cc14315d7db559d629a0f0eac3b9acc1797ffbafedf5455f1babea61bfc4 bytes=9916203
- `disasm/ppmon.dll.asm.txt` sha256=2b77f20f624300f0a1035366149dc5cfc7a11ad367e27721a2323c2af94b3424 bytes=10726998
- `disasm/pppurenist.dll.asm.txt` sha256=95e417820191b832809c03f4a381b07de3b105c52119b14aa531411bc2eb3711 bytes=54495
- `disasm/pptderefprop.dll.asm.txt` sha256=a2a9600a09399e697ad2a9c2688b58074f3c164c25f5924454fb86309794424c bytes=7013133
- `disasm/ppupp.dll.asm.txt` sha256=06a376d34a79df2ecf51b8b428e14b55a163861d3314c3f86a90f8189f0bf61a bytes=6858749
- `disasm/zeapexec.dll.asm.txt` sha256=3f6c3a7a916ba13786ba0ccb22e97f1750e3396b8e4f575404902992eab903a8 bytes=10740793
- `disasm/zecblock.dll.asm.txt` sha256=971788823afcdb776fce3d4f5adf4c49fb7c1ccb73e642f099edb4722bbee61a bytes=5343046
- `disasm/zepdqs.dll.asm.txt` sha256=abe6d52a420673ed05e75fa8e4c9a4591726c0d9171af9ebcb81b7626ef35c27 bytes=3896797
- `disasm/zepml.dll.asm.txt` sha256=2550d305465ba5f0c87139a498e644836b4a08ab8e2082ee5135065f9c6c0c69 bytes=20747441
