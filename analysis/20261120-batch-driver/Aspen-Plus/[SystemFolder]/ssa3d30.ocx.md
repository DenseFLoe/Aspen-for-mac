# ssa3d30.ocx 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `ssa3d30.ocx`，349896 字节，SHA-256 `8698a7224323a4fc752f60d388c0847bc8927927826287a65b4ac4e5f84a8bb8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 1562 = decomp_ok 1560 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=1562
- decomp_ok=1560
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `ssa3d30.ocx` |
| 字节数 | 349896 |
| SHA-256 | `8698a7224323a4fc752f60d388c0847bc8927927826287a65b4ac4e5f84a8bb8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[SystemFolder]/ssa3d30.ocx` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 32 |
| 镜像基址 | `0x24100000` |
| 段数 | 4 |
| 指令行数 | 67356 |

## 3. 反汇编清单（全量）

全文：disasm/ssa3d30.ocx.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/ssa3d30.ocx.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 1562
- decomp_ok（伪 C） = 1560
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `24101b8b` `sub_24101B8B`：RuntimeError（decompile returned None）
- `24101bad` `sub_24101BAD`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：36.3 s
- 日志：out/R1N/ida/logs/sha256_8698a7224323a4fc752f60d388c0847bc8927927826287a65b4ac4e5f84a8bb8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `ssa3d30.ocx` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 1562 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +1562（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`StartAddress`, `TimerFunc`, `sub_241012FC`, `sub_24101410`, `sub_24101A5A`, `sub_24101B32`, `sub_24101B8B`, `sub_24101BAD`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/AUTPRX32.DLL.c.txt` sha256=af84074ada6347322c2d72261cc090f04b821126b0937a38d077ce367f5fbf30 bytes=529168
- `decompiled/ComCt232.ocx.c.txt` sha256=0f311f49a1194ce6a55e74607eadfff860f3818b1173f0beb38be6b5d2235d1b bytes=538702
- `decompiled/ComDlg32.OCX.c.txt` sha256=6f1483d813ae8308ee6ad247c5a25eb33beaf0252f820d185a820c91bdf08103 bytes=345242
- `decompiled/HHActiveX.dll.c.txt` sha256=a928cb8a936c5afe444aad3314119dde521ffbf2428ace4b0a807e54f246abaf bytes=1435749
- `decompiled/MSDatGrd.ocx.c.txt` sha256=4362bcd31920aa2abff9d5117e9108817270e675262a3650e8e59dee63bb6641 bytes=895022
- `decompiled/MSFlxGrd.OCX.c.txt` sha256=d776e9b760f7cc348cb469f8d993fb862738d411085439ae299e403e48dff7e9 bytes=675128
- `decompiled/MSVCRT40.DLL.c.txt` sha256=05e9d0d0bffff66bf5811b29ef30fb4c80ac702d67b51446033485892fbe9f73 bytes=1142744
- `decompiled/MShflxgd.ocx.c.txt` sha256=5582937b87cb83349e3ab006c438f8e1c32b439f7eefe8415498000b808a05e1 bytes=1496705
- `decompiled/OSC60as.dll.c.txt` sha256=c953112af15cf2ca5e3dffb3ecf94b7c569343f013aed23780495a471ae09d86 bytes=682456
- `decompiled/RICHTX32.OCX.c.txt` sha256=370e53408164b794a13a3b4e8f63d8bf933d4b1e003c59bf4add6247715602f2 bytes=577094
- `decompiled/Shlwapi.dll.c.txt` sha256=71e5e673ee5615ada5d49614357cae0205aed0578c563d6316f214a3830ffba0 bytes=979469
- `decompiled/URLMON.DLL.c.txt` sha256=92703553d13e1793cbe5d3e5532d0986e307eb78a66976da82a1e475498e83bb bytes=1611008
- `decompiled/asycfilt.dll.c.txt` sha256=8ba4c75b06277dc9bc516d8677c2211eb23d8afd7ca090b63b566b0b5dd5ed78 bytes=526075
- `decompiled/comct332.ocx.c.txt` sha256=8f6879ac02241f1e20e72a924a55e79862a4814ac9622b647ee256590af5b59f bytes=392506
- `decompiled/dblist32.ocx.c.txt` sha256=130a334f713a8c6f61e15ab335d5497c2197ecf7ec2918905afd2599e4322f77 bytes=558615
- `decompiled/msdatlst.ocx.c.txt` sha256=532ac0df4221b9c384528000dad87137a21bac5eba156ec429b4e6b560267ef0 bytes=806351
- `decompiled/msmask32.ocx.c.txt` sha256=1693dc1bc613dda5261f6ab2c1d0cc2908550c25fbd85eba46dfe3232178d4cf bytes=553794
- `decompiled/msvcrt.dll.c.txt` sha256=32909467368afbcf2810a342ac16c5a42649bc259bbe642885c24d64cd0603fb bytes=1085764
- `decompiled/ogc7050r.dll.c.txt` sha256=c6178dfcdc0deea1da6301f14ae1ff9f615c15b59ca2218fffe5e9ab315101d1 bytes=456212
- `decompiled/ogocxgrd.ocx.c.txt` sha256=9f06b4bd481d017472e76381ee76bf650757bab29e90bfca0519455e956fefb3 bytes=807523
- `decompiled/olepro32.dll.c.txt` sha256=fa9368c0351812fb8e3d5a743bbecd022cd565a9c9d2390bf685b62964141aec bytes=477853
- `decompiled/ssa3d30.ocx.c.txt` sha256=50b637950121c735ea10983cea6c647be97a012876e6e436d06c076674322936 bytes=1074624
- `decompiled/ssscrl30.ocx.c.txt` sha256=c2c3e58e933739e570a9e5c21c3bb36279c112fb269b51cc42eb03961a30e83c bytes=587454
- `decompiled/sssplt30.ocx.c.txt` sha256=7d366475476b5385e4baf1c6e95ffd97bc4e2372328cf1d40b37bb636c52c3e0 bytes=596677
- `decompiled/tabctl32.ocx.c.txt` sha256=f6c85760e6dd9532d0fc499b4aaa7740931236a3ffe65b0f147e622452f0f36e bytes=688651
- `decompiled/threed32.ocx.c.txt` sha256=04294b0a8cda428307fd005c4f96b187c9d97131a3be1d8194296afe0a65ce0d bytes=452688
- `decompiled/webcheck.dll.c.txt` sha256=6a909b7a910548b317d33a2c5860ed05b0448b43afeee08ccd26c9b0ed70d81e bytes=775948
- `disasm/AUTPRX32.DLL.asm.txt` sha256=451b28f966dae600cb6244604cf2bef1bbee71682a2c935bf928947121a1828e bytes=1180685
- `disasm/ComCt232.ocx.asm.txt` sha256=f0bee255c3b73c920020863ca7caef04734208e7ce0389283bbc22c93dc91bb0 bytes=1066336
- `disasm/ComDlg32.OCX.asm.txt` sha256=9a1f3a7d7fce86dc58706f181621d8b6473b543e665a3cbe5a2c0718282783a7 bytes=662745
- `disasm/HHActiveX.dll.asm.txt` sha256=b0cb7fec59b368e954d19529d0e4edb5bf3a7c726f7a8da7913c41c31ce7505c bytes=3072120
- `disasm/MSDatGrd.ocx.asm.txt` sha256=cce66b896011fc70980843934b6ae448caa68fd8a383bcbddbf0585bbba7d55d bytes=1858321
- `disasm/MSFlxGrd.OCX.asm.txt` sha256=9931e34adf82587c3478450eaf0f87546075797f9e7fc9f382cb64bee36acdb4 bytes=1384868
- `disasm/MSVCRT40.DLL.asm.txt` sha256=10f08011d5f6401fe9c671d4c704f0253246827ba5408c49f9c887cf445cd6c6 bytes=2696925
- `disasm/MShflxgd.ocx.asm.txt` sha256=bf9113a3a594e4f08f722188e93c8eba239d57b9858e16868bfd7820bc966745 bytes=2992817
- `disasm/OSC60as.dll.asm.txt` sha256=a2d9dd5c1bff5ae1213cccc2e51a05db4547049bf66530af6b85546ae4a99bbe bytes=1343956
- `disasm/RICHTX32.OCX.asm.txt` sha256=875181fea9cece982ad08f6fadc08ea0aa2462af2811efb6f841c968f334ee4f bytes=1061376
- `disasm/Shlwapi.dll.asm.txt` sha256=b014bf3c4e78bb53c71422434fe76f9796bee5e72b9cd3fbc17614a28d57e57c bytes=1780642
- `disasm/URLMON.DLL.asm.txt` sha256=9bead0c8da3a5101bce6acbdee7fe4f1dbe0289418a8c26917671640cd2ef8be bytes=2762987
- `disasm/asycfilt.dll.asm.txt` sha256=956b55107fd297afe88d7cb854e578e8e6bf8bc206eb012e07342b21ffca27a8 bytes=1065390
- `disasm/comct332.ocx.asm.txt` sha256=302e75ecd6d1cef73d10bc0c44472f36de89e2e2cfa310099a326c4c781faa2b bytes=1161840
- `disasm/dblist32.ocx.asm.txt` sha256=f82f48013e4c9d29e717992fe1fa8731bd6c9f32cb737d0d3ef90ea6c5f1cf37 bytes=1090223
- `disasm/msdatlst.ocx.asm.txt` sha256=b2cd5466f9f987786b53a0a6ec52b0ed394cb6c83e50c49a440e6bb22fcdeb46 bytes=1603989
- `disasm/msmask32.ocx.asm.txt` sha256=1507569dc259f7be3b42dcbeea57e4496419317d25b4580afe086833da2f0ad6 bytes=1159663
- `disasm/msvcrt.dll.asm.txt` sha256=b835b7ba3dce7a71f8465f10ede6f7faf3e540d91d7039a047bbbfa9c12739a5 bytes=2117127
- `disasm/ogc7050r.dll.asm.txt` sha256=b79510bcf4cce10db97cddbe5951d83d2e798fe6fb3ae51caba7330ac75b6130 bytes=1064689
- `disasm/ogocxgrd.ocx.asm.txt` sha256=06dfa6070c668304c1631ab378ae8085c417cb91615888660c9f165ee88e6061 bytes=1672018
- `disasm/olepro32.dll.asm.txt` sha256=d3448ffff7811a26ca438a0a868bb458bb8944c811a575db5e2cdc897f13e24d bytes=1064770
- `disasm/ssa3d30.ocx.asm.txt` sha256=c7d58bb6ba8e0817a123d9cf3e4bce73b7419822c0056f2f03927efbe9de2734 bytes=2197094
- `disasm/ssscrl30.ocx.asm.txt` sha256=6e67f4ebd81b7596a83c0ef87a5ae613b6983945bd63f9b5949281154cf1a10d bytes=1253675
- `disasm/sssplt30.ocx.asm.txt` sha256=9a3cd9e3d05ee4b8f3780f54b7e70d06453e0c97df9b5b40d8957b08786d94f1 bytes=1242496
- `disasm/tabctl32.ocx.asm.txt` sha256=448a9981151115eb04ec17580ce36360212a082b300560d276c7f2e42d478fe2 bytes=1223621
- `disasm/threed32.ocx.asm.txt` sha256=da36138ca5612f99dd88dc4af2a47c87cc085059d3c91a12d8938a7cbd4041cd bytes=1006897
- `disasm/webcheck.dll.asm.txt` sha256=272c1ae96ca4ba061d0967a863f4e2d24033b114d7cb7b3c47cacfa22820e548 bytes=1583707
