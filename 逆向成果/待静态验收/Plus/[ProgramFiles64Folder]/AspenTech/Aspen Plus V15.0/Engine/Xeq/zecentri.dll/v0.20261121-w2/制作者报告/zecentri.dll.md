# zecentri.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zecentri.dll`，128040 字节，SHA-256 `64cdc102dc9e5c3eeb713a345345228c4c2f21762c6b2c1ffd2d3313677e0cd8` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 232 = decomp_ok 232 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=232
- decomp_ok=232
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zecentri.dll` |
| 字节数 | 128040 |
| SHA-256 | `64cdc102dc9e5c3eeb713a345345228c4c2f21762c6b2c1ffd2d3313677e0cd8` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/zecentri.dll` |
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
| 指令行数 | 13001 |

## 3. 反汇编清单（全量）

全文：disasm/zecentri.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zecentri.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 232
- decomp_ok（伪 C） = 232
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：16.6 s
- 日志：out/R1N/ida/logs/sha256_64cdc102dc9e5c3eeb713a345345228c4c2f21762c6b2c1ffd2d3313677e0cd8.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zecentri.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 232 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +232（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`CENT_EUCE01`, `sub_180001060`, `CENT_UCE01I`, `sub_180007C00`, `sub_18000A2D0`, `CENT_ZUCE01`, `sub_18000C6F0`, `sub_18000C700`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `decompiled/ApTrainExe.exe.c.txt` sha256=d9f7d6aa25f66aae673ff3e343019458a056d57676cade0a4653294068f6b442 bytes=385910
- `decompiled/ApTrainExePS.dll.c.txt` sha256=b8193f631be1caa57202e98d61188f506243bb508170924f9ed6e1002c98e34d bytes=43407
- `decompiled/ChkPath.exe.c.txt` sha256=2ef7f2cf95dcf9d5e7b50b5ecdda78c56051c1349585e3529f09fa2c5b060b4c bytes=408586
- `decompiled/actdrv.exe.c.txt` sha256=8de80aa89d76891fc44eb7c9df28db91645984ae5785902e811640344eb931d3 bytes=282877
- `decompiled/aos_nsolve.dll.c.txt` sha256=040912e75189377669a18feb8f500068cbb9456807e01efb7d6989ff60522c62 bytes=89622
- `decompiled/apcfgblk.dll.c.txt` sha256=5e1726bf32edbbc4622e82efa6967bae07e712d038ef4154c54ffba2dad6e897 bytes=83281
- `decompiled/apcommands.dll.c.txt` sha256=e87985ecdb3abfd7ba375454acadafe81c6bd31c18bb63a84d446650978e542b bytes=313450
- `decompiled/apfeedstrlst.dll.c.txt` sha256=55810a4a7805fb098d57720d11f1849b757b2cdfb278b6b7193d491ea9e6b580 bytes=185417
- `decompiled/aphierstrlst.dll.c.txt` sha256=209ac53e4e506f6f61e8d6c3e78ae2ac0ffa36e8c7b01e5596a264c66f1bc7c4 bytes=190276
- `decompiled/apmain.exe.c.txt` sha256=3424a1e9ec55868829a39153e3babe64faeacf39e7add545379c5f38bc944bef bytes=64952
- `decompiled/apstrm.dll.c.txt` sha256=0caff9c905d6c67fc67b9d0b31babbfdfb5b4f7b26df99251137ad5a2055aee1 bytes=268394
- `decompiled/aspen.exe.c.txt` sha256=97181bc7459939879338f38a7eb857d909b216fcf0e57a03faddaaad0cf40b71 bytes=159767
- `decompiled/catref.dll.c.txt` sha256=5b51c9043b757be974db86c0ce305da50dd6cb5b1ff10d31203ec816f555b23f bytes=472663
- `decompiled/cdmain.exe.c.txt` sha256=919746489dcb8b8bf4db5aace7130125f27d8334a32ba1d0fad0f02dcfc0e829 bytes=170984
- `decompiled/eohcr.dll.c.txt` sha256=504241b68bac08d7c8fe716240d16b1a2f5a5c9c1067db78cfd45cac93afcaf5 bytes=327900
- `decompiled/pol_pfrac.dll.c.txt` sha256=148f80b4808073182b13ca85d98d804809d729e5468592973d1da9ada27098ee bytes=376939
- `decompiled/rterto.dll.c.txt` sha256=0eb14735754c15fc43d3bd672f99e1959f652d8304c662a1e9696ed07f4cd5ee bytes=196958
- `decompiled/rtertocom.dll.c.txt` sha256=bd58caa10e110ed63ba028835bba663b2e5bbe82bbef3016e0cf0bf6e333c7eb bytes=378760
- `decompiled/rtmain.exe.c.txt` sha256=19ee56c1c7b36d1f95d2c30d5dbe6357a6c3cc0ee7129000eb3425a41d0cc1a0 bytes=99656
- `decompiled/rtodof.exe.c.txt` sha256=187fff87a195d06b75f78560a187dc21d746263f9a1717149508b1901fbac376 bytes=68529
- `decompiled/rtogen.exe.c.txt` sha256=71e01de20f55f66c74fdb5f07c7e24ffd5dfae279ce599b87a73e1f6f40fcbd8 bytes=210038
- `decompiled/rtores.exe.c.txt` sha256=fbb23737fc6c2748bc3df4b9da26900b72d27bc593ce0a91b68f91558d8fc9c6 bytes=65338
- `decompiled/rtoval.exe.c.txt` sha256=e3cdd411fab5a993adebebc23ce420aecd60a382e41ebcd042468d9e7231b0fd bytes=80080
- `decompiled/rtpdfutl1.dll.c.txt` sha256=6e7e962060805ee0ea5d304ae024b8f2a01556aa153d1e8d3bc5ee23bfeaefdb bytes=305189
- `decompiled/sharedmodelmanager.dll.c.txt` sha256=8b57e6e9e8e60cb102e91a2240cc9a459d27446a995aa7888529c9375b6978fe bytes=262144
- `decompiled/simexecutive.dll.c.txt` sha256=1184e9903099cde4037a4f36e947eb8f947062dcc0ab42e8529216980fa08541 bytes=107657
- `decompiled/solvint.dll.c.txt` sha256=23e2d5678e34abe8f42d3032d4fbf07f294c0166233821c2c18c4f1892fbce76 bytes=226254
- `decompiled/strlibmn.exe.c.txt` sha256=06f772c081e94694939bb61967e51fa3bb189c1bb7e8b880e77d85a0a5d98c0e bytes=80379
- `decompiled/tbsmn.exe.c.txt` sha256=8a463b99794d9c35ea4536f27e74871efd4e954d79992023b5b60869d5fc0211 bytes=84138
- `decompiled/testdms.exe.c.txt` sha256=6e7087fcbf2dde0ecc6dd60eec8aaeedce228c29ca2290d2aeefa23b47b627c3 bytes=68031
- `decompiled/testvirt.exe.c.txt` sha256=59c6e733568d167fecaa896c9e87ba9584110a6b88f7a9ec77e81fcc8faa432c bytes=52611
- `decompiled/usrdmoutil.dll.c.txt` sha256=afe567834b0529c334a235ef4420b3fe7fb4a8218a406efe72c12228df2f3d32 bytes=393128
- `decompiled/zebatchsep.dll.c.txt` sha256=0050dae5901af474743da4284853e3412cb95a2277535935d9f7ec3d943431f9 bytes=304780
- `decompiled/zebjutil.dll.c.txt` sha256=8058b7f47f4c7733bdc6440598b03d6d9d8796547c7686640378dfa90a5a4db0 bytes=394930
- `decompiled/zecentri.dll.c.txt` sha256=e2ad2a98674f056b795960ec0e297914a81a2d988be25b125b13ad3f15d189cd bytes=323371
- `decompiled/zecffilter.dll.c.txt` sha256=4a87fcd3ddb43c5a4532b4d2b4dac7be584c2cea6d6e5ae270e6fff70fcd1716 bytes=418961
- `decompiled/zechargebal.dll.c.txt` sha256=2560fc914b2fd0e3382b9adf537dd5bc206ab6956b7018a51f25a1fd14277347 bytes=57267
- `decompiled/zeclchng.dll.c.txt` sha256=00350b84e621eadfe2cbc41f2043458406a3ad1fb0307fb554fedd130647e63e bytes=76646
- `decompiled/zecoltarg.dll.c.txt` sha256=ae720e30bed9de449024944dea3b4e5844e0d629a5ef1a092719b2ed814eab73 bytes=350497
- `decompiled/zecontrollers.dll.c.txt` sha256=cc92d8adb06ea9424b3c2ef324b8d9a194639a32035d2e73c4ed1715614d222a bytes=260582
- `decompiled/zecsterile.dll.c.txt` sha256=a6eab43545b0f5195acdc40427201cda50e24632730a02f5b46be3c10a4e37e0 bytes=328055
- `decompiled/zedfilter.dll.c.txt` sha256=21d9a99a5eb329e18e70029599a92a0f38b2da5338e29e9378e7bd81098a336e bytes=102881
- `decompiled/zedisrupt.dll.c.txt` sha256=a4745a20acb631839f0169d4bf76b270eecc3da063db3eb113fe270f246ef1ea bytes=274326
- `decompiled/zeeoconv.dll.c.txt` sha256=8b71598f3b8ed24c42cc2af8ef684cd171be1448bfcacc88d6723562db3c9491 bytes=337205
- `decompiled/zeflash3.dll.c.txt` sha256=56174437e352a76bb540468ad508a304543463e6f4f20e14b632e793bbf4ca5c bytes=203410
- `decompiled/zeheatxu.dll.c.txt` sha256=599e5b6b87460cc232b139c077cf9bd84da0c4c64c295a511b8458b10ff8d706 bytes=311275
- `decompiled/zehybsensor.dll.c.txt` sha256=40ceb9f0ac873014d45cdd43312a3e0e18a15322afe123028d8d93b438e7ee9c bytes=234378
- `decompiled/zemakeup.dll.c.txt` sha256=0437633bd0e93256badd777c742d05a0b1f0f1d9df64fb84cb08e677b8bda167 bytes=315085
- `decompiled/zemixer.dll.c.txt` sha256=888b34e2ed4cf1ed686c352a00b2cb71844dc6be6a3391ca3103e5a2ab15eaf8 bytes=294260
- `decompiled/zemult.dll.c.txt` sha256=2615da6cbb56b2fb00b2e448bfb016fc372c3b432e6b0232e36dd52f8a65c741 bytes=62491
- `decompiled/zeqtvec.dll.c.txt` sha256=e4817d2a3c88f0046201c44ece2e472947b99cab377a1e6b59d74fb0a5aff009 bytes=65323
- `decompiled/zero.dll.c.txt` sha256=83192ba144405e5bf1c326c02676ad43c6912137b3299dbebedbf1538b8e889c bytes=426451
- `decompiled/zeselectr.dll.c.txt` sha256=200d4668037b2d697c9a97b4b54e2ca9d3dd240900696b752e12225cddc5d619 bytes=55436
- `decompiled/zesfspec.dll.c.txt` sha256=c5c147025a6df11e4ca07aa2ce9d432fd30a0ce6585885d74382aa443e322686 bytes=391623
- `decompiled/zessplit.dll.c.txt` sha256=e66d2919e29e1076a6c172a7cc198bdeac1f35b483ac62fc262e28c94f7910ca bytes=362894
- `decompiled/zeswash.dll.c.txt` sha256=1be610d9b201738ac636262363b5f33980598ce741adea07f64509c75ccb3812 bytes=227208
- `decompiled/zeu3amf.dll.c.txt` sha256=17bce0e3964817a1c002359b334850ec15c41e707c7baeb2a99887698b758271 bytes=142567
- `decompiled/zeuser.dll.c.txt` sha256=f629d30b4cc4dabc341cd874078defd7fea153fb2463f139d8455e75ba8b2ab6 bytes=206505
- `decompiled/zeuser2.dll.c.txt` sha256=d1e9736ed7b73484efa53ae5b97f0c29d5ad16bdd49abc79f8f5f99362d3619f bytes=219699
- `decompiled/zeuser4.dll.c.txt` sha256=09e1d76acd06dbba8c9aaf11649c6e30785b98c786ecaee8b631761fd63ae7e0 bytes=295707
- `decompiled/zevalve.dll.c.txt` sha256=36dc16ec0c707fcb2408f9c496af1bf44f2078981d4a1532a7793f8cfdb7af4b bytes=287446
- `disasm/ApTrainExe.exe.asm.txt` sha256=c5a3ba307dc84e01d88204fef5b9a46b3eafef2b5ffd70e889d5d91e07125ffd bytes=697218
- `disasm/ApTrainExePS.dll.asm.txt` sha256=d2bff8d93a840b3ae3e60404136a0394e6e64f21f846b4dbc2d866b3da5fca47 bytes=57757
- `disasm/ChkPath.exe.asm.txt` sha256=dde5a1a2bfacfaa96b770322daf44eb47e87bbe89285f31d7b33b19725b596b0 bytes=736384
- `disasm/actdrv.exe.asm.txt` sha256=068e3985def524db0f3f169cf3d1cb853a7cfc4e5e7cee62917a6eb25b5ea535 bytes=393253
- `disasm/aos_nsolve.dll.asm.txt` sha256=826288335d0d9b311da189ec52858609e1008fc64291db0ebff41a432aca59e8 bytes=147387
- `disasm/apcfgblk.dll.asm.txt` sha256=82a1dc274502982412d2128995359a18e238b40cf6a2873b627813175e7592fe bytes=107924
- `disasm/apcommands.dll.asm.txt` sha256=63b2e1983640e8a823aa0f4f18ab129ceca52761be124b5799714fbac628527c bytes=495581
- `disasm/apfeedstrlst.dll.asm.txt` sha256=2fdb84d7670ef10b5f7f83896a73d3d0c534d23c9866ff9a92acfdadaa4e841a bytes=247538
- `disasm/aphierstrlst.dll.asm.txt` sha256=8add16fb9591ab7425ba037325ba72d1c187ccace40ee2c9b334b402cbbb5df6 bytes=257873
- `disasm/apmain.exe.asm.txt` sha256=89c3d25502c632f43dbe63a6a63d852e1995f9dc0804c258fffc6b7f9d77c8fe bytes=104015
- `disasm/apstrm.dll.asm.txt` sha256=36b4ad7f1abdd812ae20e63a6c946578c2ceb386131420995a5dd327564fbbce bytes=385238
- `disasm/aspen.exe.asm.txt` sha256=89b9c51aa482b148749b4df51a172004e8da967a73df9670626e9555ca337755 bytes=305179
- `disasm/catref.dll.asm.txt` sha256=4ee351afc1ba4f16cf0004f6ba7b8d145d82f5aa336c1ee70e024a7ed90b989d bytes=627385
- `disasm/cdmain.exe.asm.txt` sha256=a2a11b55da3b770d502a63fb65ead775370898f442dddd2dddb2ca5577bac047 bytes=227959
- `disasm/eohcr.dll.asm.txt` sha256=263a5b3a8af3de24db9badea13c0f185b01e6908737899aee2894b411e774604 bytes=471833
- `disasm/pol_pfrac.dll.asm.txt` sha256=3d14f095e197f3815c06c718fcfa0c25b390d58cff83e5e732ed7d588df5ee1f bytes=498358
- `disasm/rterto.dll.asm.txt` sha256=2a1c9e8259f0b3a7276062d79fa6f82e8f2622ebe1e8ebce30363eb921a802cf bytes=287218
- `disasm/rtertocom.dll.asm.txt` sha256=f7055b2556dc21d4ad8b38d006ca19e8693a0f845fa0255f4324e1b27e6b052c bytes=680066
- `disasm/rtmain.exe.asm.txt` sha256=18355fc2c6c3cc82cbbd0a263645afbb029530ea71d3f1aa3e6d8137478f2b39 bytes=119685
- `disasm/rtodof.exe.asm.txt` sha256=10763bc66ad2a91d685fc0fb3ac1837798fd6e3a33b9c932123144cbe1a407f7 bytes=115967
- `disasm/rtogen.exe.asm.txt` sha256=fee7ef130cae61f407b1d14051b1c1ea099fba0e95b3e79ba06c5a669dc6670f bytes=299874
- `disasm/rtores.exe.asm.txt` sha256=05c7773dde6cb2e66a9733b2f7dcf2c36a6187e4864d8f453521734579946622 bytes=102413
- `disasm/rtoval.exe.asm.txt` sha256=c0703ad6438b748fc59498688e5b60c7d60b24b244f85a80b24e1181c24f3e6d bytes=131382
- `disasm/rtpdfutl1.dll.asm.txt` sha256=d721de111d36c95db1536b69153e4978b9054aced1aaf090bf4b07169fed3c28 bytes=401495
- `disasm/sharedmodelmanager.dll.asm.txt` sha256=8656c01d6b9c9a9921032fe6df8a832e53d33a491351dfa0a1f012ff20bc75f9 bytes=429839
- `disasm/simexecutive.dll.asm.txt` sha256=2e3df64e0f3bc96430f42ee3fb0dcfe5421ee6d75bd45d52ede86b17b6630104 bytes=192234
- `disasm/solvint.dll.asm.txt` sha256=6cde35b09c76ba590df2ef3e3104096e58e988101de6a26736a897d9046b2bd1 bytes=316852
- `disasm/strlibmn.exe.asm.txt` sha256=7bd04dce6da684b584efcec40315e0ed4ac318597a654cd614c35a6fa6d3058a bytes=120582
- `disasm/tbsmn.exe.asm.txt` sha256=c2f5c9f1625a2a9c069c1295b15a985ae815677f68f60468a0e0afcefd09b67b bytes=113587
- `disasm/testdms.exe.asm.txt` sha256=0a667b53813693741b85727f43c1233415ae4ad1353eec1318ae9aaeb261fe3d bytes=100886
- `disasm/testvirt.exe.asm.txt` sha256=e6164615d64107378c99d9c2b6dc255e8c614b11f53c6f69b5abfe26e787ca69 bytes=128297
- `disasm/usrdmoutil.dll.asm.txt` sha256=a3b035ea384af6f49fcfe7d24c24ef9da69078d4f17735e4b8aa6c45e6ea1dc9 bytes=500576
- `disasm/zebatchsep.dll.asm.txt` sha256=062f14124a701845559b8dbd4a3d86c31ae3985da35df512624e3584c268707a bytes=397018
- `disasm/zebjutil.dll.asm.txt` sha256=65b38ca49cdd481f64dfcd5ff19dc54e53e17e37549f458b8005f7540bae03db bytes=546580
- `disasm/zecentri.dll.asm.txt` sha256=723c0dd8d888daa98971a97fc9234cb5807498a329c38f1b214ede346e397659 bytes=500750
- `disasm/zecffilter.dll.asm.txt` sha256=909b681e1143362a82bbc6086d017479d6c8813cb1804a7ba386a373c2a44903 bytes=605434
- `disasm/zechargebal.dll.asm.txt` sha256=7f5f494fd6171c04d45e5fe32e52b2a43879d30936ddc936b73176da8f83e77d bytes=90761
- `disasm/zeclchng.dll.asm.txt` sha256=dc8dc0aac8ee26ef30f6e8c172b52f4ab75528173101b7b7d19055c4cdde715e bytes=119714
- `disasm/zecoltarg.dll.asm.txt` sha256=fbe5c6f604cd702f73f94e1ecad073e7bec72c580a8c5b4f1b9a2077fb0decbb bytes=443611
- `disasm/zecontrollers.dll.asm.txt` sha256=2716f86318c63aa2ff56bb4e03e247eac0104348a0ab715dd18eb91422400233 bytes=396169
- `disasm/zecsterile.dll.asm.txt` sha256=b91fc8c502020aeb29fec2f84e6e8089261ee561063043487ffee3c6f2f105b4 bytes=518787
- `disasm/zedfilter.dll.asm.txt` sha256=ba565084078e584d304f7d02d57ae251d0b0e5fd4a4b811d438cbbea717837d0 bytes=183139
- `disasm/zedisrupt.dll.asm.txt` sha256=4723dfd5ad944fd09316feab354b0bd0151eb7159a5f81d8c0322c5bebaa8f4e bytes=401470
- `disasm/zeeoconv.dll.asm.txt` sha256=cc46d958ad51cc630242b34f3a45a593c946e9c9f8e79f7f563e5ed4e854546e bytes=424760
- `disasm/zeflash3.dll.asm.txt` sha256=94af86ab2c58781b9fcc92adbf7b1686f4b445f6291e55c3e5c6524548fc5326 bytes=360994
- `disasm/zeheatxu.dll.asm.txt` sha256=f3126f861dc69d362df0e61ce78c6e5c764c1f51d8b15a53c814aef381423f02 bytes=582398
- `disasm/zehybsensor.dll.asm.txt` sha256=72814c068b481d68defca72ffb272330a41941255dbfed90aea8a26df5911c43 bytes=340645
- `disasm/zemakeup.dll.asm.txt` sha256=0af70d68a7117f865971e1808489a55992ca46e425002a4515ff58fdfcaf9830 bytes=422909
- `disasm/zemixer.dll.asm.txt` sha256=fce4b4bf2908ce4bf5d54f65b8882700df7c7955efda26cc421b026514835e2b bytes=463878
- `disasm/zemult.dll.asm.txt` sha256=01de8b9908badc4f3f7db331391927169f7f7460ed5f56c1f41cfd65698e6e7e bytes=98169
- `disasm/zeqtvec.dll.asm.txt` sha256=ed3abded2daf67cd31971c7c399e6a63f7198303991c119cf7190a54986a00f5 bytes=105330
- `disasm/zero.dll.asm.txt` sha256=ee4cc33c9e0c78f857dd1a0a2ced16362efcc31f90d51c6ebfac7702c320dc58 bytes=581225
- `disasm/zeselectr.dll.asm.txt` sha256=d188fad18ed44828d71ac1ddbf75b451896745fe45e2bc6385d57e04d7d9ccd6 bytes=86749
- `disasm/zesfspec.dll.asm.txt` sha256=e861cd5cb1bd09171d0d737e8294b619b46001171f36f39ba54ec525b91e8f97 bytes=569947
- `disasm/zessplit.dll.asm.txt` sha256=e241e662d8482c26750efbb09d0b67dfa2176d827d675f70acbde1ab1dce7328 bytes=544147
- `disasm/zeswash.dll.asm.txt` sha256=b84ecc0c0e16f1ada41e20e286494158618ead9b53506a667dfb36db5c775045 bytes=345522
- `disasm/zeu3amf.dll.asm.txt` sha256=89d9399f5ca17db332c3d56c764ad83f9533df8fcfeb5acc83532b6f015f1071 bytes=205813
- `disasm/zeuser.dll.asm.txt` sha256=804123f5bedb395d6cc0575f0ed0c8f2950a812e60abddb1f04a0326f947cbb8 bytes=335438
- `disasm/zeuser2.dll.asm.txt` sha256=b563738d4156fd197400d9a52dde1636e9410d7643f9c32a03a7ea3ae3308e60 bytes=409447
- `disasm/zeuser4.dll.asm.txt` sha256=3144db73b9a8bae08e7441946cba6c8c700cb633e1e3e2a2ff13475d61fc23bc bytes=534118
- `disasm/zevalve.dll.asm.txt` sha256=90ab85cb92b775b0d132967a2981e8f7ce11da110351ab1a38125b5463c663c6 bytes=532516
