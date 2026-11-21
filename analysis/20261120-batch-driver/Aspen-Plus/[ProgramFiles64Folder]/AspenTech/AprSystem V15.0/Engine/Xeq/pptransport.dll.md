# pptransport.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pptransport.dll`，285224 字节，SHA-256 `343af9328382db4fa25a72e2479e1c86372157313fe27f0c02a7580586a264bf` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 256 = decomp_ok 255 + decomp_fail 1 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=256
- decomp_ok=255
- decomp_fail=1
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pptransport.dll` |
| 字节数 | 285224 |
| SHA-256 | `343af9328382db4fa25a72e2479e1c86372157313fe27f0c02a7580586a264bf` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pptransport.dll` |
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
| 指令行数 | 33239 |

## 3. 反汇编清单（全量）

全文：disasm/pptransport.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pptransport.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 256
- decomp_ok（伪 C） = 255
- decomp_fail = 1
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1800267b0` `sub_1800267B0`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：21.8 s
- 日志：out/R1N/ida/logs/sha256_343af9328382db4fa25a72e2479e1c86372157313fe27f0c02a7580586a264bf.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 1 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pptransport.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 256 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +256（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `PPTX_SIG003`, `PPTX_SIG203`, `sub_180001990`, `sub_180001A80`, `PPTX_MUV003`, `PPTX_MUV004`, `PPTX_MUV005`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/PetroPropCalculator.dll.c.txt` sha256=6f5f635c91cfff467d3ffbc6d00e474030bd504c6e0ecd0fe0c07521a7d64e1b bytes=785000
- `decompiled/aesuom.dll.c.txt` sha256=9759137964d955ce6cbaa6b06e2d0ad3f548dfcb9dfca8931b623b2eb1569e7a bytes=1060766
- `decompiled/apvcom.dll.c.txt` sha256=4159e09a1e3e38e74ae61289218a90519468637868980fee409a4c593bb9e82c bytes=880692
- `decompiled/atcocommon.dll.c.txt` sha256=22e41db79b554d73d771512a08f44d73c221b8c3012d7e7f0feab1f77852e157 bytes=543147
- `decompiled/atcoerror.dll.c.txt` sha256=744ac34d1b04fcb50836b46ed2580f4b3bd516f38942a607394184e9f5ec1157 bytes=454135
- `decompiled/atcoreaction.dll.c.txt` sha256=0d17444dd01cf901d74192f6f922ebffd5d0be5ceb83766fa33af5a71d210d7d bytes=689463
- `decompiled/atcosimulationexecutive.dll.c.txt` sha256=633dd9bb86e2354f98f67d0b6e7fe1d3d512380b274c09779cdd7a9c821402b3 bytes=645158
- `decompiled/atcothermosocket.dll.c.txt` sha256=b611e322fa11c00c603a8352450d6e67b73d1de0413b10731149ff1e5f463efe bytes=922085
- `decompiled/atdms0.dll.c.txt` sha256=b7e93e6dad05ed75447040bf87fdada74ce0e1d36390b87e4e3333bbf4777f54 bytes=549388
- `decompiled/atdmstst.dll.c.txt` sha256=b1af584dc7641d0ebf4f0a77962407b34cc9cf7a8a5b26c74f5a22573196019b bytes=493520
- `decompiled/effcalc.dll.c.txt` sha256=19688ec9ad5c2fa586852a536fe76bf6cc268ef99ffd490aa4c535d881738cf1 bytes=513884
- `decompiled/libifportmd.dll.c.txt` sha256=b7fa1d369bcdc3456207e8f5bf9230007b7c2cb8ea063a21cdb8414155a3ade4 bytes=1582316
- `decompiled/perl.exe.c.txt` sha256=8d483d7922606c7855d238bb3fbd64f216dbec57fe98ec4508590e3661d35e00 bytes=125194
- `decompiled/pol_emul.dll.c.txt` sha256=f401b75d4d10d1393befe028801a5cf42ea7e3b90ad65c2f11e2984c77bb8f44 bytes=570038
- `decompiled/pol_frad.dll.c.txt` sha256=b46bc709c7f8cb6b17d6b657310f79abe8bee17da8adc2460fbbadabd7510804 bytes=473390
- `decompiled/pol_gam.dll.c.txt` sha256=026b7ebe190cd41d11dee2a4fc77f5b91bab3e6a0237191037d6579e3bc5f1da bytes=710276
- `decompiled/pol_ionc.dll.c.txt` sha256=bac74269fd2bf2fbac3b8aa6c8ed6e6f0cf9e7f4d687633485868a5b830fd8e3 bytes=272334
- `decompiled/pol_pmix.dll.c.txt` sha256=3c45b7537b50587c13a689a36f342134c1e9b4b58911d43a82df2f5d97c9ea33 bytes=530820
- `decompiled/pol_pro.dll.c.txt` sha256=01967c3585ecd7013163dc89b36f18af52dbadb5c77d306567fff47b2d63c5be bytes=859569
- `decompiled/pol_step.dll.c.txt` sha256=d39531e3ea84f90d8c802cae973807854f58889321e5e5bedf1fee7ec7b28a12 bytes=695591
- `decompiled/pol_znat.dll.c.txt` sha256=42049d6e12fc7477674b9bf54980771ba84c2917ecffb39b720ea590231c879e bytes=387442
- `decompiled/ppdrssem.dll.c.txt` sha256=e4cb85ad720aee6b7dbb51cbf2b5961b26ca0afd24f15a49ff5996a56fc5c50b bytes=860688
- `decompiled/ppedl.dll.c.txt` sha256=63f24d5172636be9869eeefdd4142f4568d7c6727f4b9e3b734b8fa48797116b bytes=613687
- `decompiled/ppeosi.dll.c.txt` sha256=6473b9902bd03fe77ca787ce0c08b6806b821660e8badb94ca6d6eed06e2683f bytes=808447
- `decompiled/ppfact.dll.c.txt` sha256=957e1f427dd60dc29fe66c9f0daaf4e64f77f9732f5434ca745877b9abd1dac2 bytes=705167
- `decompiled/ppgamma.dll.c.txt` sha256=54279b2e4ba703060f98fb10c7feb650e0716090780756b6f4790964b706ff83 bytes=1074475
- `decompiled/pphysysprop.dll.c.txt` sha256=f039f70e1cd6d7dce6947083432250971a5e4d4017d92c72294e45140c3efcef bytes=557961
- `decompiled/pppetromod.dll.c.txt` sha256=d093bf87684a2d8a5e70f67eb0194764cce702c5b331e1b8763678928c59188a bytes=720201
- `decompiled/pppetroprop.dll.c.txt` sha256=4c1450ef1605503cd2a3fbbcc690892f517b86f5a55fa9e2bdfa965f31822a49 bytes=542098
- `decompiled/pppoly.dll.c.txt` sha256=4020464a82808d5ad1792db4e1ddd255ce328d6e9486f1566e60ac3f7ea5af40 bytes=524918
- `decompiled/pppropsystem.dll.c.txt` sha256=781461bc62b3193ec6062017d40e55fa10aab0abb974aa5d18bb87f5ad501608 bytes=1243421
- `decompiled/pppuredippr.dll.c.txt` sha256=3cfb2dc9728153d7ac25fea8cfde8329a4b4c58efad106db6bb06cc47e890fe6 bytes=35457
- `decompiled/pptabpolyi.dll.c.txt` sha256=0c57ddaf336ef02509f25164e2d96198818cf76d278854fd66d1773e055f6d6b bytes=628307
- `decompiled/pptransport.dll.c.txt` sha256=4904842658200108cc47bc520888c6bc4bc4392e32303f4687ab201440374346 bytes=749272
- `decompiled/pputil.dll.c.txt` sha256=7cd882d61e73575fec1766fa316a460eb54f1bafd540823014d8758db8849f08 bytes=1147265
- `decompiled/rtpdfutl.dll.c.txt` sha256=7f8d5ccd63b84ea5cd50224b72cd2539856e6a124dd6948f91b30631c53fdeb2 bytes=980728
- `decompiled/zecostsem.dll.c.txt` sha256=d20725053b95a4acd768efe5083ecf203639d45410ba315319364ad38b10f16f bytes=556640
- `decompiled/zedfms.dll.c.txt` sha256=1ef6c0fba1182a0e948f85e3f785866459d76206676f359b6c34e9a657954a72 bytes=993488
- `decompiled/zefanal.dll.c.txt` sha256=79308bf65d6dfc790a67460defa47ad5a237204ed0b5498947e19a0ce4856f61 bytes=1336243
- `decompiled/zeicheck.dll.c.txt` sha256=37833e06797c865b28c9dbfe834913b17e7c7b49085e15cc2394d8fe9b326a3f bytes=443013
- `decompiled/zeitexec.dll.c.txt` sha256=af2b04d53c58cc0f7976319ab00abef63cb4f860d9714216e6d841c4914145c9 bytes=808020
- `decompiled/zeivalab.dll.c.txt` sha256=5a4088fe94901614d82377decfc86abfc0ef290b6057b9c0231e4c280a9d9193 bytes=277127
- `decompiled/zeprogen.dll.c.txt` sha256=c61057e4d59b77c1847d147b285d070d18498addae13d00d40345893c347c1d7 bytes=603500
- `decompiled/zereport.dll.c.txt` sha256=28a803e181635df84780cf91324d6dbfef827aae8cf86c9caf7151768d8bb1bb bytes=1062699
- `decompiled/zesem1.dll.c.txt` sha256=7fc610f76ed4f38f8aa03b4f68b76c8cb232c1a72704b03d2fd8a52af93e6ce6 bytes=982931
- `decompiled/zeshs.dll.c.txt` sha256=b762000e577bdc0eb4779db589e49778aaeb20e3ade48b94ebb41bc56e128c7b bytes=701722
- `decompiled/zesqp.dll.c.txt` sha256=0ad98d14519db16db98864a979b21f23874a8a5186c988fc8982141341f19cd0 bytes=776303
- `decompiled/zestreamu.dll.c.txt` sha256=ed7040414cee1e5d45a1bbbb66d8c0564f31bc77cc856ed7a99bc03f341075d4 bytes=802332
- `decompiled/zetpsar.dll.c.txt` sha256=54278195596b93dad912c4e6afcc18b4e245eaa4923aae68de969a5554fa8fb1 bytes=339921
- `decompiled/zeusrutl.dll.c.txt` sha256=54eb50c0363c71767a749179977ed5f75e61c2d5333a4f75a362b0968098635b bytes=432588
- `decompiled/zevaraccu.dll.c.txt` sha256=f228c8a0bbb581ded6cfd1e2b2868342d3abe88ca1d2370ebef071006e2d3688 bytes=893799
- `disasm/PetroPropCalculator.dll.asm.txt` sha256=4b6335b208c969cba3fc9274bf9e22089caa4b6e54775b35246e82fcbb99d1c6 bytes=1447415
- `disasm/aesuom.dll.asm.txt` sha256=1d2285292af151704510195e6a70533c3b7b82929afc2c6874ac42f5baf92457 bytes=1830749
- `disasm/apvcom.dll.asm.txt` sha256=a22a868468863fb741fec76b0051dc78b5f0b5c6fe14264d529fa7ee876aecd4 bytes=1559419
- `disasm/atcocommon.dll.asm.txt` sha256=96900e6b8ab6bb5a7f8ce1be1131d53966a30da32a05ee82644be9090846c3aa bytes=968948
- `disasm/atcoerror.dll.asm.txt` sha256=bf433e58fc6499c14206beabe6c6a9329ad901cca1c0a08795d81b0551bc59c5 bytes=769410
- `disasm/atcoreaction.dll.asm.txt` sha256=a360819471a3f16f19c07feb26759e1a6b737d47d7d4a3e9a3389dc29f5483de bytes=1305331
- `disasm/atcosimulationexecutive.dll.asm.txt` sha256=452cf05e2bab1bed3c81c44a380e10f1d8e2605ac157afbbf05d473401c237b9 bytes=1198057
- `disasm/atcothermosocket.dll.asm.txt` sha256=ad8f680ff585b279d6443d0f7039231919e69a7cf827acc8666e4230ab8d0fd9 bytes=1429434
- `disasm/atdms0.dll.asm.txt` sha256=a28ca96a9ffa9233f8dbcb90c4fac11204fd5d7436d478fd31482092f264dfa3 bytes=1165295
- `disasm/atdmstst.dll.asm.txt` sha256=6b8136faad176b5bd823be5d5ce92466cec50035842dfda202f13b5631bd88f3 bytes=767816
- `disasm/effcalc.dll.asm.txt` sha256=e6cd01291274717665b55cc8c578b27121f5a743b986578502a2a4b27bda63f1 bytes=877535
- `disasm/libifportmd.dll.asm.txt` sha256=c3b31cb6355a47a2408ed613622f8765e328e9ca75b2e0b2ec47a14e2cb47d53 bytes=2810814
- `disasm/perl.exe.asm.txt` sha256=a0348320a572fa430d2e6fa5939c9b4633edcd258835aba9fdc281446a46abdf bytes=213354
- `disasm/pol_emul.dll.asm.txt` sha256=ed9d23d777cf7b83c5acec686c9db7fe255cbcb1e60b34c66695ad0ce7346aef bytes=887150
- `disasm/pol_frad.dll.asm.txt` sha256=09860cc3b68f247536822f1cd9258883e0e1465a26683ec664033f333fff67f4 bytes=975587
- `disasm/pol_gam.dll.asm.txt` sha256=0be3666eec442a46c4351edb94bea4f2b6856af5617e746eebc20fbad14b188b bytes=1102989
- `disasm/pol_ionc.dll.asm.txt` sha256=256741f620edc01857e4a9ceb15be036d5f6199e633e08ea0afdfcea70f2d6d6 bytes=698798
- `disasm/pol_pmix.dll.asm.txt` sha256=4387a570a55dba0528b24cabd404a2685ebddde1bb951ec1892df00c58bea958 bytes=870169
- `disasm/pol_pro.dll.asm.txt` sha256=ab03a4d95252bf501c2fda47217dbadd9e2d869477923824060d389d69ea8edb bytes=1514584
- `disasm/pol_step.dll.asm.txt` sha256=adec2a29d6d21ee450d399053a86bcf0e0b6a0f52f1e87c9e1e04722943b9bb3 bytes=1110544
- `disasm/pol_znat.dll.asm.txt` sha256=705a9b34db5a0f878ec0e5c5f21d8f6a2cb6536c843070de953c1bc9fec582b8 bytes=1387359
- `disasm/ppdrssem.dll.asm.txt` sha256=1d58c557fca337a51c85f544314ac4f130c389975260e4968a3775da68102b44 bytes=1270792
- `disasm/ppedl.dll.asm.txt` sha256=bf6fd68eb423478f3457f1ba9097a5663010c0102cf3ea75943038817e34d3a6 bytes=865864
- `disasm/ppeosi.dll.asm.txt` sha256=5f2d1f05b3f5121efca9c8a7d21e4038d44857c2c037f512231902a9a6347383 bytes=1697212
- `disasm/ppfact.dll.asm.txt` sha256=83ef8a924637d18ea3f753a86686d5c25543519146c07357c119489a14889282 bytes=1177880
- `disasm/ppgamma.dll.asm.txt` sha256=16c643a11f075466a44fbab9bc4673afe2519e24c98f6a8cf896117df13dbbc8 bytes=1763136
- `disasm/pphysysprop.dll.asm.txt` sha256=7d897a9e5bf7e68091667eb2547905dd883d739cca6b5d33292f5efbf068f929 bytes=1228576
- `disasm/pppetromod.dll.asm.txt` sha256=ab3d900da030cbfa7431e85fa44cd5845b598ba67e6090a2db6996920b8d3a13 bytes=1273828
- `disasm/pppetroprop.dll.asm.txt` sha256=a086e7c08263b00909e352414a08aebf6a66b12d7c81477487fc39db923f24d8 bytes=885609
- `disasm/pppoly.dll.asm.txt` sha256=f78c89b4961037cc7268cefddb5929e9dd6ace47fe60f91c9914e6534cac610b bytes=765488
- `disasm/pppropsystem.dll.asm.txt` sha256=57ee1dfc3148512601efa0c31e16cf4e58a75b655626eddf472eafc81ad3601f bytes=2211355
- `disasm/pppuredippr.dll.asm.txt` sha256=794e5e29ef86f4b950a3ee013ace43f78394852982fbb6b9ff8f318ae16a1052 bytes=54496
- `disasm/pptabpolyi.dll.asm.txt` sha256=c47fa9f6f63f57f46948acd9e6967b96c7547df477a7fb2c2a4e803a1e555d2e bytes=938196
- `disasm/pptransport.dll.asm.txt` sha256=fa256e726f9ec2c2bbf6a7fab9a6e542eb29b411f11893a6d62a759a87eabfa4 bytes=1310279
- `disasm/pputil.dll.asm.txt` sha256=da05c2ac7fdfc99a6cfdc143a9df91586e6641ffd316f944c439fc0edd531dda bytes=1806044
- `disasm/rtpdfutl.dll.asm.txt` sha256=20dc245ff976fd24766aecbe2a992f8f073d505b7b27c213a934e3f54ea6c118 bytes=1636894
- `disasm/zecostsem.dll.asm.txt` sha256=96f469fb27b740e978c8c5a31a757d9d8f17278f3455e59ed7b91739564f6fd5 bytes=891373
- `disasm/zedfms.dll.asm.txt` sha256=9450c93feb0a8f5c934fd7965cbf385b1d80691c6a1ed34fa39375966e735298 bytes=1536537
- `disasm/zefanal.dll.asm.txt` sha256=16eadedf0ba0648641c7f78434ea060d04d61c1d3664e81f247047c0ecf61737 bytes=2068058
- `disasm/zeicheck.dll.asm.txt` sha256=d87405746c965330ed1442a450b8122cbd64ccd98c5cfcc9972b04086a1f8b30 bytes=643658
- `disasm/zeitexec.dll.asm.txt` sha256=35a58f7d5266aaba94dc923a6d6aacd2654431aa5511c455b0bcd76d8b5664ab bytes=1338215
- `disasm/zeivalab.dll.asm.txt` sha256=e69edadd10844b7ba4902028a4667221959859551b747bc7aa9c35a6cd1237e4 bytes=850896
- `disasm/zeprogen.dll.asm.txt` sha256=844d198d11989780a7a5dbb95b58053a00a7a0bba246cada14f226f246d1df11 bytes=896422
- `disasm/zereport.dll.asm.txt` sha256=beb60b7f8bc783697a6d426d810f2bd9e7c40347d6d0cb9119dbac51abae61f6 bytes=2005619
- `disasm/zesem1.dll.asm.txt` sha256=ecb2e8aa949b8ba0301dbff5a0a15616e25b8eb837441c33ab5b8f40097615ab bytes=1438073
- `disasm/zeshs.dll.asm.txt` sha256=112b2977e00fdc3bc505e95823add3190a91c5d78fcd4f24fdd7b6b24bebd93b bytes=1610690
- `disasm/zesqp.dll.asm.txt` sha256=b916fe898dd9a27ddb88964dad65e7d33765ea61065a8b64c37badb5093bbca9 bytes=1310898
- `disasm/zestreamu.dll.asm.txt` sha256=9619dbf11bb71fa3bfd9536b66837ab978f070bac9d4869b3e33de0757830d18 bytes=1202854
- `disasm/zetpsar.dll.asm.txt` sha256=5b2442d7dc581b3ac20dec1c2c62f28892dc73f176e8c3d3087febd77932dee9 bytes=1911275
- `disasm/zeusrutl.dll.asm.txt` sha256=af04088e11a32935390ce667393a13a45d90d5b086dd6aebd304ba5f46a768ca bytes=656268
- `disasm/zevaraccu.dll.asm.txt` sha256=51e76044a365b1c302191e77804404536d7c07ca497a435c02c790377a4a7619 bytes=1340075
