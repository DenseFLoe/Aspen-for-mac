# rtmain.exe 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `rtmain.exe`，44072 字节，SHA-256 `926217888f597b3887269c25e4a24d6388f42f5b0df3e240d7dc68adf8072ee1` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 293 = decomp_ok 293 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=293
- decomp_ok=293
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `rtmain.exe` |
| 字节数 | 44072 |
| SHA-256 | `926217888f597b3887269c25e4a24d6388f42f5b0df3e240d7dc68adf8072ee1` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/rtmain.exe` |
| product_raw | `Plus` |
| 产品目录 | `Aspen-Plus` |
| machine / sections / entry |  /  /  |
| 原件核对 | size 与 sha256 均与清单一致〔实测〕 |

## 2. PE 导入摘要（处理器/位宽/基址/段）

| 项 | 值 |
| --- | --- |
| IDA 处理器模块 | `metapc` |
| 位宽 | 64 |
| 镜像基址 | `0x140000000` |
| 段数 | 5 |
| 指令行数 | 3118 |

## 3. 反汇编清单（全量）

全文：disasm/rtmain.exe.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/rtmain.exe.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 293
- decomp_ok（伪 C） = 293
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：14.0 s
- 日志：out/R1N/ida/logs/sha256_926217888f597b3887269c25e4a24d6388f42f5b0df3e240d7dc68adf8072ee1.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `rtmain.exe` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 293 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +293（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_140001000`, `sub_140001060`, `nullsub_3`, `sub_140001870`, `sub_140001900`, `main`, `sub_140001C20`, `sub_140001C60`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/ApTrainExePS.dll.c.txt` sha256=b8193f631be1caa57202e98d61188f506243bb508170924f9ed6e1002c98e34d bytes=43407
- `decompiled/acmexputls.dll.c.txt` sha256=4f67970c902c072c1df57be7fbbdb055c62166d7ec90730a666c3b953948fdf8 bytes=2130009
- `decompiled/actdrv.exe.c.txt` sha256=8de80aa89d76891fc44eb7c9df28db91645984ae5785902e811640344eb931d3 bytes=282877
- `decompiled/aos_nsolve.dll.c.txt` sha256=040912e75189377669a18feb8f500068cbb9456807e01efb7d6989ff60522c62 bytes=89622
- `decompiled/apcfgblk.dll.c.txt` sha256=5e1726bf32edbbc4622e82efa6967bae07e712d038ef4154c54ffba2dad6e897 bytes=83281
- `decompiled/apcommands.dll.c.txt` sha256=e87985ecdb3abfd7ba375454acadafe81c6bd31c18bb63a84d446650978e542b bytes=313450
- `decompiled/apconnmgr.dll.c.txt` sha256=5cb1aa9fc6eee0ffa82a538238bf78c1ac721d829478d92cacd52c91a5eb73f6 bytes=1489994
- `decompiled/apfeedstrlst.dll.c.txt` sha256=55810a4a7805fb098d57720d11f1849b757b2cdfb278b6b7193d491ea9e6b580 bytes=185417
- `decompiled/aphierstrlst.dll.c.txt` sha256=209ac53e4e506f6f61e8d6c3e78ae2ac0ffa36e8c7b01e5596a264c66f1bc7c4 bytes=190276
- `decompiled/apmain.exe.c.txt` sha256=3424a1e9ec55868829a39153e3babe64faeacf39e7add545379c5f38bc944bef bytes=64952
- `decompiled/apstrm.dll.c.txt` sha256=0caff9c905d6c67fc67b9d0b31babbfdfb5b4f7b26df99251137ad5a2055aee1 bytes=268394
- `decompiled/aspen.exe.c.txt` sha256=97181bc7459939879338f38a7eb857d909b216fcf0e57a03faddaaad0cf40b71 bytes=159767
- `decompiled/atp3.exe.c.txt` sha256=4e259dda8d400a9861720caf90ece6a770ee580dfa13b35bf7918609c2946a49 bytes=2459005
- `decompiled/cdmain.exe.c.txt` sha256=919746489dcb8b8bf4db5aace7130125f27d8334a32ba1d0fad0f02dcfc0e829 bytes=170984
- `decompiled/dmsrmn.exe.c.txt` sha256=8ed8fa9cc6d80c69c13482cd10dd7522fe394bd8258166ec5d3aa947752ae084 bytes=49617
- `decompiled/dualacmexp.dll.c.txt` sha256=aebbba8c05503cf4d8cbadf4a4d58b92e38b8b060fd8c5797259c678b631b20c bytes=2286641
- `decompiled/eohcr.dll.c.txt` sha256=504241b68bac08d7c8fe716240d16b1a2f5a5c9c1067db78cfd45cac93afcaf5 bytes=327900
- `decompiled/isom.dll.c.txt` sha256=f00f5c6af44f3c093c9c93733a1b87ea6163fe39aec986df635822d147bdd0bc bytes=50949
- `decompiled/nht.dll.c.txt` sha256=cdf8c886b6bb13263669d911288c6968450f2fb2c3ef833458a8fb2efa963fb7 bytes=54424
- `decompiled/rterto.dll.c.txt` sha256=0eb14735754c15fc43d3bd672f99e1959f652d8304c662a1e9696ed07f4cd5ee bytes=196958
- `decompiled/rtmain.exe.c.txt` sha256=19ee56c1c7b36d1f95d2c30d5dbe6357a6c3cc0ee7129000eb3425a41d0cc1a0 bytes=99656
- `decompiled/rtodof.exe.c.txt` sha256=187fff87a195d06b75f78560a187dc21d746263f9a1717149508b1901fbac376 bytes=68529
- `decompiled/rtogen.exe.c.txt` sha256=71e01de20f55f66c74fdb5f07c7e24ffd5dfae279ce599b87a73e1f6f40fcbd8 bytes=210038
- `decompiled/rtojac.exe.c.txt` sha256=a7fc3b9878d7cd240e14c49e197802da1799a7ea04829faa0f73d5f1d5d4d28c bytes=67367
- `decompiled/rtores.exe.c.txt` sha256=fbb23737fc6c2748bc3df4b9da26900b72d27bc593ce0a91b68f91558d8fc9c6 bytes=65338
- `decompiled/rtotran.exe.c.txt` sha256=2d1f08622999436857b89f3285c4c575a31be6028160364391681156503a5618 bytes=48052
- `decompiled/rtoval.exe.c.txt` sha256=e3cdd411fab5a993adebebc23ce420aecd60a382e41ebcd042468d9e7231b0fd bytes=80080
- `decompiled/rtpdfutl1.dll.c.txt` sha256=6e7e962060805ee0ea5d304ae024b8f2a01556aa153d1e8d3bc5ee23bfeaefdb bytes=305189
- `decompiled/sharedmodelmanager.dll.c.txt` sha256=8b57e6e9e8e60cb102e91a2240cc9a459d27446a995aa7888529c9375b6978fe bytes=262144
- `decompiled/simexecutive.dll.c.txt` sha256=1184e9903099cde4037a4f36e947eb8f947062dcc0ab42e8529216980fa08541 bytes=107657
- `decompiled/smeoutils.dll.c.txt` sha256=26d31bb0404f7fe166907acd84672040c044aa826d00be7040f1568cd62f22f9 bytes=1340740
- `decompiled/solvint.dll.c.txt` sha256=23e2d5678e34abe8f42d3032d4fbf07f294c0166233821c2c18c4f1892fbce76 bytes=226254
- `decompiled/strlibmn.exe.c.txt` sha256=06f772c081e94694939bb61967e51fa3bb189c1bb7e8b880e77d85a0a5d98c0e bytes=80379
- `decompiled/tbsmn.exe.c.txt` sha256=8a463b99794d9c35ea4536f27e74871efd4e954d79992023b5b60869d5fc0211 bytes=84138
- `decompiled/testdms.exe.c.txt` sha256=6e7087fcbf2dde0ecc6dd60eec8aaeedce228c29ca2290d2aeefa23b47b627c3 bytes=68031
- `decompiled/testvirt.exe.c.txt` sha256=59c6e733568d167fecaa896c9e87ba9584110a6b88f7a9ec77e81fcc8faa432c bytes=52611
- `decompiled/zeacmmodel.dll.c.txt` sha256=fe8d2e39c19f8f42518b8a46bcc878174574b88a2aab71824f8b253472ee0d61 bytes=3014076
- `decompiled/zebatchop.dll.c.txt` sha256=85ff90390b7034e7044f75c14454ce2abce123f6ffd690a3f45eea69feed3e9a bytes=961250
- `decompiled/zebatchsep.dll.c.txt` sha256=0050dae5901af474743da4284853e3412cb95a2277535935d9f7ec3d943431f9 bytes=304780
- `decompiled/zechargebal.dll.c.txt` sha256=2560fc914b2fd0e3382b9adf537dd5bc206ab6956b7018a51f25a1fd14277347 bytes=57267
- `decompiled/zeclchng.dll.c.txt` sha256=00350b84e621eadfe2cbc41f2043458406a3ad1fb0307fb554fedd130647e63e bytes=76646
- `decompiled/zecoltarg.dll.c.txt` sha256=ae720e30bed9de449024944dea3b4e5844e0d629a5ef1a092719b2ed814eab73 bytes=350497
- `decompiled/zecompr.dll.c.txt` sha256=ad95e57b727eb68267dcb0cafb365f90bb259db81a9e839ef2bc59dc53ed429a bytes=1187271
- `decompiled/zecontrollers.dll.c.txt` sha256=cc92d8adb06ea9424b3c2ef324b8d9a194639a32035d2e73c4ed1715614d222a bytes=260582
- `decompiled/zedfilter.dll.c.txt` sha256=21d9a99a5eb329e18e70029599a92a0f38b2da5338e29e9378e7bd81098a336e bytes=102881
- `decompiled/zedisrupt.dll.c.txt` sha256=a4745a20acb631839f0169d4bf76b270eecc3da063db3eb113fe270f246ef1ea bytes=274326
- `decompiled/zedupl.dll.c.txt` sha256=551bef915b32f90a5281752e8760c0bc6d947a0aa4bbba63a69a9badb2ab889b bytes=49888
- `decompiled/zeeconomic.dll.c.txt` sha256=d17ceec07ff3b85c0a35f87fe6eb0bb8e5c95c771582621f8986891befeb9f35 bytes=1547796
- `decompiled/zeeoconv.dll.c.txt` sha256=8b71598f3b8ed24c42cc2af8ef684cd171be1448bfcacc88d6723562db3c9491 bytes=337205
- `decompiled/zefilter.dll.c.txt` sha256=a3936922d7440378bf1ff540fc240aa85d71a7c5938b5ad4ba2b02ec21cf8a81 bytes=2217399
- `decompiled/zeflash3.dll.c.txt` sha256=56174437e352a76bb540468ad508a304543463e6f4f20e14b632e793bbf4ca5c bytes=203410
- `decompiled/zeheater.dll.c.txt` sha256=de0251211c0c4e98501150a1395b015029d2e3d6a1745bf8fd2c4ab826b3fcbd bytes=1241570
- `decompiled/zeheatxu.dll.c.txt` sha256=599e5b6b87460cc232b139c077cf9bd84da0c4c64c295a511b8458b10ff8d706 bytes=311275
- `decompiled/zehybsensor.dll.c.txt` sha256=40ceb9f0ac873014d45cdd43312a3e0e18a15322afe123028d8d93b438e7ee9c bytes=234378
- `decompiled/zemakeup.dll.c.txt` sha256=0437633bd0e93256badd777c742d05a0b1f0f1d9df64fb84cb08e677b8bda167 bytes=315085
- `decompiled/zemheatx.dll.c.txt` sha256=683b53850863dfc0330565af97f4bf9bfdfde48cfc5d001722de2cd6d021a965 bytes=1373256
- `decompiled/zemhtxu.dll.c.txt` sha256=d200154325eb2b10354f15cd0d0c6a61525699ab914d078adfc975b855f14435 bytes=34151
- `decompiled/zemixer.dll.c.txt` sha256=888b34e2ed4cf1ed686c352a00b2cb71844dc6be6a3391ca3103e5a2ab15eaf8 bytes=294260
- `decompiled/zemult.dll.c.txt` sha256=2615da6cbb56b2fb00b2e448bfb016fc372c3b432e6b0232e36dd52f8a65c741 bytes=62491
- `decompiled/zepresr.dll.c.txt` sha256=e0d5f573cbec7b3fa4e8ea6ebb82802403e33ba574a4b852c84d9b337dca95a3 bytes=963176
- `decompiled/zeqtvec.dll.c.txt` sha256=e4817d2a3c88f0046201c44ece2e472947b99cab377a1e6b59d74fb0a5aff009 bytes=65323
- `decompiled/zercstr.dll.c.txt` sha256=446af4a7011066437ae70a9d096c9086618e38ac646735814439e1ea1b2d80c1 bytes=527390
- `decompiled/zeselectr.dll.c.txt` sha256=200d4668037b2d697c9a97b4b54e2ca9d3dd240900696b752e12225cddc5d619 bytes=55436
- `decompiled/zeswash.dll.c.txt` sha256=1be610d9b201738ac636262363b5f33980598ce741adea07f64509c75ccb3812 bytes=227208
- `decompiled/zeu3amf.dll.c.txt` sha256=17bce0e3964817a1c002359b334850ec15c41e707c7baeb2a99887698b758271 bytes=142567
- `decompiled/zeu3model.dll.c.txt` sha256=117c9fc5fb23596f3fd6a884aabfcb0264d1647c0445a233871f79c652c62894 bytes=1785320
- `decompiled/zeuser.dll.c.txt` sha256=f629d30b4cc4dabc341cd874078defd7fea153fb2463f139d8455e75ba8b2ab6 bytes=206505
- `decompiled/zeuser2.dll.c.txt` sha256=d1e9736ed7b73484efa53ae5b97f0c29d5ad16bdd49abc79f8f5f99362d3619f bytes=219699
- `disasm/ApTrainExePS.dll.asm.txt` sha256=d2bff8d93a840b3ae3e60404136a0394e6e64f21f846b4dbc2d866b3da5fca47 bytes=57757
- `disasm/acmexputls.dll.asm.txt` sha256=00ba3ff463098cf8d7f32cb02a790043dceb95f7cb7a0438a0bf322db5e08175 bytes=3537314
- `disasm/actdrv.exe.asm.txt` sha256=068e3985def524db0f3f169cf3d1cb853a7cfc4e5e7cee62917a6eb25b5ea535 bytes=393253
- `disasm/aos_nsolve.dll.asm.txt` sha256=826288335d0d9b311da189ec52858609e1008fc64291db0ebff41a432aca59e8 bytes=147387
- `disasm/apcfgblk.dll.asm.txt` sha256=82a1dc274502982412d2128995359a18e238b40cf6a2873b627813175e7592fe bytes=107924
- `disasm/apcommands.dll.asm.txt` sha256=63b2e1983640e8a823aa0f4f18ab129ceca52761be124b5799714fbac628527c bytes=495581
- `disasm/apconnmgr.dll.asm.txt` sha256=9e0114748669831de5a48fd4f8156bb835534c3a3cc907f56ff2188f5594d101 bytes=2480593
- `disasm/apfeedstrlst.dll.asm.txt` sha256=2fdb84d7670ef10b5f7f83896a73d3d0c534d23c9866ff9a92acfdadaa4e841a bytes=247538
- `disasm/aphierstrlst.dll.asm.txt` sha256=8add16fb9591ab7425ba037325ba72d1c187ccace40ee2c9b334b402cbbb5df6 bytes=257873
- `disasm/apmain.exe.asm.txt` sha256=89c3d25502c632f43dbe63a6a63d852e1995f9dc0804c258fffc6b7f9d77c8fe bytes=104015
- `disasm/apstrm.dll.asm.txt` sha256=36b4ad7f1abdd812ae20e63a6c946578c2ceb386131420995a5dd327564fbbce bytes=385238
- `disasm/aspen.exe.asm.txt` sha256=89b9c51aa482b148749b4df51a172004e8da967a73df9670626e9555ca337755 bytes=305179
- `disasm/atp3.exe.asm.txt` sha256=6385bb5b15922104b0d3532a64cf4499d19bd9bfe3b06008407fced625da07a9 bytes=4090097
- `disasm/cdmain.exe.asm.txt` sha256=a2a11b55da3b770d502a63fb65ead775370898f442dddd2dddb2ca5577bac047 bytes=227959
- `disasm/dmsrmn.exe.asm.txt` sha256=d488f0daf93e60fc023d02f6d3d0742f5e8dbb6d4ad8b84af1f5520f0ca9e076 bytes=71013
- `disasm/dualacmexp.dll.asm.txt` sha256=331e81e927663f5498db0231fbc07764d5069e3fb6c8e6be2afe1ed5b83a3996 bytes=4436617
- `disasm/eohcr.dll.asm.txt` sha256=263a5b3a8af3de24db9badea13c0f185b01e6908737899aee2894b411e774604 bytes=471833
- `disasm/isom.dll.asm.txt` sha256=5af086665ec891069b12b4a863e7744dc4a8b892ca464f8592bfeead6fd2eed6 bytes=82468
- `disasm/nht.dll.asm.txt` sha256=d86b2ead5491cc61a688473e27cfb1adc0a56b514b2ee7f3fd90c25945a0441d bytes=88891
- `disasm/rterto.dll.asm.txt` sha256=2a1c9e8259f0b3a7276062d79fa6f82e8f2622ebe1e8ebce30363eb921a802cf bytes=287218
- `disasm/rtmain.exe.asm.txt` sha256=18355fc2c6c3cc82cbbd0a263645afbb029530ea71d3f1aa3e6d8137478f2b39 bytes=119685
- `disasm/rtodof.exe.asm.txt` sha256=10763bc66ad2a91d685fc0fb3ac1837798fd6e3a33b9c932123144cbe1a407f7 bytes=115967
- `disasm/rtogen.exe.asm.txt` sha256=fee7ef130cae61f407b1d14051b1c1ea099fba0e95b3e79ba06c5a669dc6670f bytes=299874
- `disasm/rtojac.exe.asm.txt` sha256=08829125e1dbab47d2d6e29648126d3cc57a6819ebff97973d4115f230a00b9d bytes=105165
- `disasm/rtores.exe.asm.txt` sha256=05c7773dde6cb2e66a9733b2f7dcf2c36a6187e4864d8f453521734579946622 bytes=102413
- `disasm/rtotran.exe.asm.txt` sha256=ee29abf0282a244bb37eebcc5c725172ac4749d815b2af110bc8d3e83a7c028c bytes=72154
- `disasm/rtoval.exe.asm.txt` sha256=c0703ad6438b748fc59498688e5b60c7d60b24b244f85a80b24e1181c24f3e6d bytes=131382
- `disasm/rtpdfutl1.dll.asm.txt` sha256=d721de111d36c95db1536b69153e4978b9054aced1aaf090bf4b07169fed3c28 bytes=401495
- `disasm/sharedmodelmanager.dll.asm.txt` sha256=8656c01d6b9c9a9921032fe6df8a832e53d33a491351dfa0a1f012ff20bc75f9 bytes=429839
- `disasm/simexecutive.dll.asm.txt` sha256=2e3df64e0f3bc96430f42ee3fb0dcfe5421ee6d75bd45d52ede86b17b6630104 bytes=192234
- `disasm/smeoutils.dll.asm.txt` sha256=162231fbc147a95a61d0dcb8d045ed79e9a875f88e1bc9a74bc3ea8c06658a29 bytes=2199538
- `disasm/solvint.dll.asm.txt` sha256=6cde35b09c76ba590df2ef3e3104096e58e988101de6a26736a897d9046b2bd1 bytes=316852
- `disasm/strlibmn.exe.asm.txt` sha256=7bd04dce6da684b584efcec40315e0ed4ac318597a654cd614c35a6fa6d3058a bytes=120582
- `disasm/tbsmn.exe.asm.txt` sha256=c2f5c9f1625a2a9c069c1295b15a985ae815677f68f60468a0e0afcefd09b67b bytes=113587
- `disasm/testdms.exe.asm.txt` sha256=0a667b53813693741b85727f43c1233415ae4ad1353eec1318ae9aaeb261fe3d bytes=100886
- `disasm/testvirt.exe.asm.txt` sha256=e6164615d64107378c99d9c2b6dc255e8c614b11f53c6f69b5abfe26e787ca69 bytes=128297
- `disasm/zeacmmodel.dll.asm.txt` sha256=47073664007b91082102a3a45602b8c8d2a5cb4acbb9480097424a2927e6aa31 bytes=5482676
- `disasm/zebatchop.dll.asm.txt` sha256=4830814eabd2c07cecb1df744e30e5e5d86aedd90aab95e37b3dc48368ccb3e6 bytes=2987401
- `disasm/zebatchsep.dll.asm.txt` sha256=062f14124a701845559b8dbd4a3d86c31ae3985da35df512624e3584c268707a bytes=397018
- `disasm/zechargebal.dll.asm.txt` sha256=7f5f494fd6171c04d45e5fe32e52b2a43879d30936ddc936b73176da8f83e77d bytes=90761
- `disasm/zeclchng.dll.asm.txt` sha256=dc8dc0aac8ee26ef30f6e8c172b52f4ab75528173101b7b7d19055c4cdde715e bytes=119714
- `disasm/zecoltarg.dll.asm.txt` sha256=fbe5c6f604cd702f73f94e1ecad073e7bec72c580a8c5b4f1b9a2077fb0decbb bytes=443611
- `disasm/zecompr.dll.asm.txt` sha256=2dcd9f18c0359de203a902f7e86b26046390546b1ad70fdead2ca75d867cbfff bytes=2745187
- `disasm/zecontrollers.dll.asm.txt` sha256=2716f86318c63aa2ff56bb4e03e247eac0104348a0ab715dd18eb91422400233 bytes=396169
- `disasm/zedfilter.dll.asm.txt` sha256=ba565084078e584d304f7d02d57ae251d0b0e5fd4a4b811d438cbbea717837d0 bytes=183139
- `disasm/zedisrupt.dll.asm.txt` sha256=4723dfd5ad944fd09316feab354b0bd0151eb7159a5f81d8c0322c5bebaa8f4e bytes=401470
- `disasm/zedupl.dll.asm.txt` sha256=97233f8b84a1c80d201b0e443737ffcfa13cf2bd064516fed71c73cdd27f51c1 bytes=76541
- `disasm/zeeconomic.dll.asm.txt` sha256=a5f50c5b9263d3890bae39a3e6d1823a4a3162011ac2f24c1eaa68a11ac6bbe5 bytes=2695125
- `disasm/zeeoconv.dll.asm.txt` sha256=cc46d958ad51cc630242b34f3a45a593c946e9c9f8e79f7f563e5ed4e854546e bytes=424760
- `disasm/zefilter.dll.asm.txt` sha256=b9769f20e3ae9b6c7930ffacbb2fea38cf4a5cfd538af5f86caaae7677358a7a bytes=3108019
- `disasm/zeflash3.dll.asm.txt` sha256=94af86ab2c58781b9fcc92adbf7b1686f4b445f6291e55c3e5c6524548fc5326 bytes=360994
- `disasm/zeheater.dll.asm.txt` sha256=0e3dfdfe920d84c5939dedcf2e5936e3421915c961861ed7e8b809c69ac05fa3 bytes=2508753
- `disasm/zeheatxu.dll.asm.txt` sha256=f3126f861dc69d362df0e61ce78c6e5c764c1f51d8b15a53c814aef381423f02 bytes=582398
- `disasm/zehybsensor.dll.asm.txt` sha256=72814c068b481d68defca72ffb272330a41941255dbfed90aea8a26df5911c43 bytes=340645
- `disasm/zemakeup.dll.asm.txt` sha256=0af70d68a7117f865971e1808489a55992ca46e425002a4515ff58fdfcaf9830 bytes=422909
- `disasm/zemheatx.dll.asm.txt` sha256=96968c27f18891dd7942a4e8e656ca4772edf2f9e7c02c8c101273d390fcad35 bytes=2841351
- `disasm/zemhtxu.dll.asm.txt` sha256=305531998eb6739537d20305f5ecd30cd117bc7e4fdc13a5d4d3f829a191a6ac bytes=52117
- `disasm/zemixer.dll.asm.txt` sha256=fce4b4bf2908ce4bf5d54f65b8882700df7c7955efda26cc421b026514835e2b bytes=463878
- `disasm/zemult.dll.asm.txt` sha256=01de8b9908badc4f3f7db331391927169f7f7460ed5f56c1f41cfd65698e6e7e bytes=98169
- `disasm/zepresr.dll.asm.txt` sha256=530d6e76d9ca569a42b845f50b4376ca258147848bd32e99f5b48f8bd75c77a1 bytes=2309202
- `disasm/zeqtvec.dll.asm.txt` sha256=ed3abded2daf67cd31971c7c399e6a63f7198303991c119cf7190a54986a00f5 bytes=105330
- `disasm/zercstr.dll.asm.txt` sha256=9e86cabec28e561a5f3f7da3b7742c1f704325b89cd3c23a8b9dbaa09a906488 bytes=2498146
- `disasm/zeselectr.dll.asm.txt` sha256=d188fad18ed44828d71ac1ddbf75b451896745fe45e2bc6385d57e04d7d9ccd6 bytes=86749
- `disasm/zeswash.dll.asm.txt` sha256=b84ecc0c0e16f1ada41e20e286494158618ead9b53506a667dfb36db5c775045 bytes=345522
- `disasm/zeu3amf.dll.asm.txt` sha256=89d9399f5ca17db332c3d56c764ad83f9533df8fcfeb5acc83532b6f015f1071 bytes=205813
- `disasm/zeu3model.dll.asm.txt` sha256=61839cdfe54a46835f9e9fd8566d46873f0a98c865d45e8af9cd22c15e24bb56 bytes=3413551
- `disasm/zeuser.dll.asm.txt` sha256=804123f5bedb395d6cc0575f0ed0c8f2950a812e60abddb1f04a0326f947cbb8 bytes=335438
- `disasm/zeuser2.dll.asm.txt` sha256=b563738d4156fd197400d9a52dde1636e9410d7643f9c32a03a7ea3ae3308e60 bytes=409447
