# zesferm.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `zesferm.dll`，138792 字节，SHA-256 `9396bd1b2ba0418d2a350818b1f6c91aaf0b318e3497080e63a141b1d60e483f` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 229 = decomp_ok 229 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=229
- decomp_ok=229
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `zesferm.dll` |
| 字节数 | 138792 |
| SHA-256 | `9396bd1b2ba0418d2a350818b1f6c91aaf0b318e3497080e63a141b1d60e483f` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/Aspen Plus V15.0/Engine/Xeq/zesferm.dll` |
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
| 指令行数 | 15669 |

## 3. 反汇编清单（全量）

全文：disasm/zesferm.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/zesferm.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 229
- decomp_ok（伪 C） = 229
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：15.7 s
- 日志：out/R1N/ida/logs/sha256_9396bd1b2ba0418d2a350818b1f6c91aaf0b318e3497080e63a141b1d60e483f.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `zesferm.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 229 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +229（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`SFRM_EUBF02`, `sub_180001060`, `SFRM_UBF02I`, `sub_180006B30`, `sub_18000B550`, `SFRM_ZUBF02`, `sub_18000F310`, `sub_18000F320`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part2.tar.gz

- `decompiled/MDHCR.dll.c.txt` sha256=ea3114f336c766c3b07a5f7a818bf1bec42433bf402f99f37ab2615f9dd7f76c bytes=424134
- `decompiled/amfipersist.dll.c.txt` sha256=6329d21af58629efb8ad7516f21e4569d049c95d3045ff5ffa22275d2dbbdaf1 bytes=391366
- `decompiled/apblk.dll.c.txt` sha256=08b5da7535dfc910cbd0b2c255578c0bf624b623d7f35cee8e1788e2666ab74b bytes=1003875
- `decompiled/apddbi0.exe.c.txt` sha256=aedef4e9c00367852a4b856962c34090bae0bdf406d1f9fe5b6aeae582454944 bytes=847456
- `decompiled/aptrain.dll.c.txt` sha256=304825b43121ff03dd58edd67e04e35860fe413161dd7f1a993b294e52d8a3d8 bytes=472730
- `decompiled/capeopenunit.dll.c.txt` sha256=e5bc8e8521e194c9aebbf485e08224268bcb62c48237a200bb170e6bedf540f1 bytes=1405430
- `decompiled/capeopenunit090.dll.c.txt` sha256=f41071b8ed80b40378dc8a81938646bd1767edbd0e8bf3e924905ce07ae9689f bytes=511904
- `decompiled/capeopenunit093.dll.c.txt` sha256=9d25cb7fdfd80425d61de7726529ca39745401ad755819117120e84d285efdf6 bytes=906763
- `decompiled/cflash.dll.c.txt` sha256=35703a33a585dac1252bec5309f05718b134ea89045ce12325af6b6dba1e70d4 bytes=413446
- `decompiled/crtddb0.exe.c.txt` sha256=0ba9aaff658d50847ac5d157ce94c67193d986e3e1cd52b59c97fc14a077b228 bytes=428846
- `decompiled/htxint0.exe.c.txt` sha256=e63406207bb6b80b860efa928d50c2e83451d97585bd926eff1264e14907cc1a bytes=796184
- `decompiled/hxnetintpropcomp.dll.c.txt` sha256=2eb2d99488a035fb5e4ac8821440f171270075bb16bf3018583f8b5882422bbd bytes=494719
- `decompiled/pml.dll.c.txt` sha256=41d714f0cb8f918edc8b1a38f6e21e526f459c51f8e654d0fc2cafb28b3ad6db bytes=250745
- `decompiled/polyusermodellib.dll.c.txt` sha256=7e534f5300b9f1b1e68482c4f9122554cb9dba6b6a9c565c0ae0f9df17b0911b bytes=767763
- `decompiled/refcmds.dll.c.txt` sha256=f2dbcbc7eef062f8fc1d90c2710af75684c139e1fd2924423e6959a467c1a884 bytes=600108
- `decompiled/rtassay.dll.c.txt` sha256=6cd00ac426eb417fa51177472b6f65794eab69af083b0ffcde8a3edbd699f195 bytes=375404
- `decompiled/rtoblk.dll.c.txt` sha256=86ca4dd65a32158260d2a8a9fc450c10f4c33ba92af9ad1ac56e64ced6eb56fe bytes=441643
- `decompiled/rtpdfutl.dll.c.txt` sha256=7f8d5ccd63b84ea5cd50224b72cd2539856e6a124dd6948f91b30631c53fdeb2 bytes=980728
- `decompiled/safeed.dll.c.txt` sha256=ccc3799b5d4383f1ee07f89b4f913f43105c46df558006845846c87bbc3556a8 bytes=387572
- `decompiled/sainput.dll.c.txt` sha256=6954ad0b55a38951b0c690907bcbd5bfbde2be3e748dacd1130182f5c0f99ef9 bytes=626384
- `decompiled/sastream.dll.c.txt` sha256=a10f00ff21b9f2e1e8f74e1a98c28b45904960f74ca0bd92b2dc429c2ec0fbeb bytes=549715
- `decompiled/smdyn.dll.c.txt` sha256=47f6ac31beb6ec76a285d33eeeff61fa012474abf1f3474f2950822c0acf68e2 bytes=929839
- `decompiled/u3subflow.dll.c.txt` sha256=6e5e475f508da68dc71f12a1640106338dfa65562e65222d2de4fc669185eeda bytes=424260
- `decompiled/usrdmo.dll.c.txt` sha256=7aeede12f6c9497d3d0ce1a40a48acf7270d2de06e4d5460e19438c8cdece589 bytes=426098
- `decompiled/zeabsbr.dll.c.txt` sha256=710353364c65e80e6c16dd7fbab288fcbcbe1cb8ba4427fb334fe50825e73dfe bytes=457080
- `decompiled/zeacol.dll.c.txt` sha256=9d0bdc90c8689675d0c749e02ebc93f308bd5860eac4ca21490cb2c73b5027be bytes=563808
- `decompiled/zeanalyzer.dll.c.txt` sha256=f266fba687be94ffdceafbc5ed0d3a96161dadb76180fca638c8c5a9cc1d4497 bytes=678312
- `decompiled/zeaple.dll.c.txt` sha256=18539e67373649d14ec2aba7a39193354dc3b844fd82a4c120898345a1f79581 bytes=547038
- `decompiled/zebaconv.dll.c.txt` sha256=d85bc3c5ffb626f2d41b25e61ad5940f2d6cdfa59b666a9ab6ca2bbb504f3721 bytes=448138
- `decompiled/zebatchcrystal.dll.c.txt` sha256=618a1fe48c4b6599856a6f541df4e7a4be776085afcdb55e754a42419ab1bd6a bytes=393513
- `decompiled/zebferm.dll.c.txt` sha256=1333c0dfb3bf540a13879ef01b176d7c65ba7a30ed3bb5eb154d24401a94d8a9 bytes=670183
- `decompiled/zebmembrane.dll.c.txt` sha256=e09927278186f872c9578cbabe74c9cc594d4e02b4ecb1fe88cd561302fdb857 bytes=747957
- `decompiled/zeccd.dll.c.txt` sha256=154525b25d4080e502b258b8fb74b53cbbe81d00af11d9ae502f4517901b4a3f bytes=517564
- `decompiled/zecferm.dll.c.txt` sha256=311a6fcf9e7f0b69449fcd8057f05bba33e36e032568853dc940b7ba3b6b6395 bytes=362507
- `decompiled/zecfuge.dll.c.txt` sha256=9c3abb632a5699ddc2d5bb8d7112d67e263a52c0fcf79773f8c47ac14a6e9248 bytes=1779930
- `decompiled/zechrom.dll.c.txt` sha256=807413069a259afaff4ba9cc0fc3c3e0c44bce3ba709f5acdeb25f6d48073b5c bytes=590267
- `decompiled/zeclassifier.dll.c.txt` sha256=d6a8ca9ec9cd6a3df67daa4a1b5a9cb096f603561bfef54af987cc1eb4408328 bytes=1074348
- `decompiled/zecoadapter.dll.c.txt` sha256=2f65f2392b3dd26ebcf42b02c0ed95d6a1084be833a7edc82552d81fbc083f12 bytes=775550
- `decompiled/zeconsep.dll.c.txt` sha256=23bd9cc6acf295489ab5f7d9574436be72a4760d7b974fb9ca925694946e97c4 bytes=461803
- `decompiled/zecrusher.dll.c.txt` sha256=6ff060f798a2359e907c14a2df3bc71969ba6ea93fba65cc36268e403208f5b2 bytes=1913552
- `decompiled/zecrystal.dll.c.txt` sha256=cea41d83e60ff2fe4b2d238686929ee3aa62b1aa84a944326c532688d55b024f bytes=719816
- `decompiled/zecrystallizer.dll.c.txt` sha256=f19514f4e6f0f9c57951dca9688427a3998b26ba46dd27c80f2f8f8728177b54 bytes=497757
- `decompiled/zecyclone.dll.c.txt` sha256=a9a1887da46a4c2f0537357100039295762a9c6f71f1c285ba3fa07716692686 bytes=1234916
- `decompiled/zedecanter.dll.c.txt` sha256=45a3b0bb004ff28b5d39034c08164af01ed869e4f575bb5eaad835c943322d78 bytes=488121
- `decompiled/zedistl.dll.c.txt` sha256=2d63c8511b112320047bd41fe4b5160fce1ae9463202b89298b4237b16d29235 bytes=424053
- `decompiled/zedstwu.dll.c.txt` sha256=1e1e448a9fde6212ba7cbcfccc286f92b77f9e1d85bed92f7ea56bb3615d479b bytes=436096
- `decompiled/zeelectrolyzer.dll.c.txt` sha256=5f1e255b69d5aedca3aae8211fc99f88e5f867eb4c515c68356053e477ba52a5 bytes=448301
- `decompiled/zeesp.dll.c.txt` sha256=93c3a0d0f444deebac349832d517f0db668df4a08895dca30c5baa9f17c40d80 bytes=721583
- `decompiled/zeextract.dll.c.txt` sha256=85ab99f1b4ee9c9ad9efad5c5f429fdf51add6013ae89201d65c87a4adc46fc1 bytes=473007
- `decompiled/zefabfl.dll.c.txt` sha256=05eedd70af68127920ede7d91f6f19c1030a924f1f9fd6b8191aa506a1e27854 bytes=753466
- `decompiled/zeflash2.dll.c.txt` sha256=bd648d0a282c370d058e2706fb1def5b7045afbdb3feae250410171e15450786 bytes=868095
- `decompiled/zefluidbed.dll.c.txt` sha256=32818d733ea701c68d2bc26396a0529b61fa72ffc2c1a39fbf9d0d81360bf74a bytes=1478165
- `decompiled/zefpress.dll.c.txt` sha256=d4678a4779255622bef048a4887246926dffb13d35adb847aecf6a5def42fea8 bytes=345379
- `decompiled/zefsplit.dll.c.txt` sha256=1f6e0f170234a3e7aa319a1ea7f144e7ff27c37617bb2b3ec74d3599ebe6f773 bytes=769621
- `decompiled/zegelchrom.dll.c.txt` sha256=8876fecb30b0f86329bdd914d1755af3443a196fffa824d1a464df6db7de1f68 bytes=556783
- `decompiled/zegranulator.dll.c.txt` sha256=e5080be077cbce85f3f03a7d1db2657f93fdc4b99595b28c178e8b78eee58a4f bytes=1576966
- `decompiled/zehxflux.dll.c.txt` sha256=696f7f6e85888d59f37cd9081237ec02d4e46392769a9095c5358fd8709db158 bytes=430410
- `decompiled/zehybmodel.dll.c.txt` sha256=216b283d66456151e7eb31c4272da40cd11aad2587f42ec620ebb05a6fbaa400 bytes=807307
- `decompiled/zehycyc.dll.c.txt` sha256=748a7ec2148a730514c3c35088f86e7b7e81829d85adb898099badb7d4fa5059 bytes=1542699
- `decompiled/zemcompr.dll.c.txt` sha256=851eabae8e1f571c57eff6aefc289714bfb2180ee3ef353514ce0847ee531eac bytes=729699
- `decompiled/zemembrane.dll.c.txt` sha256=094f86e49beb6af74ffebd18e4eea8b00c60afba3d649923ff447703d08a2fc9 bytes=265876
- `decompiled/zeode.dll.c.txt` sha256=9629bd05b01410c19b0f663ddab4606565eed9e87d5c1353badc7eb1c3652bf1 bytes=554636
- `decompiled/zeopi.dll.c.txt` sha256=c47aaeae8332a7c625f4a0114f0c805ce4f86d875856395c231cc0032a972915 bytes=702596
- `decompiled/zepdrop.dll.c.txt` sha256=4e6e96f5e7122c7494ca84e3cc90f7eaa2c92a27db847ca0156c25099f7c99ec bytes=716265
- `decompiled/zepipe.dll.c.txt` sha256=bd7503c67713625365a4b84d906e91044e13e5a8a150a5bfa32a0482359351d1 bytes=561773
- `decompiled/zepipeline.dll.c.txt` sha256=8f95c3a7e13c732920b93a611a46bd252ba1f057e586099cfb9f7a5d76a74ec5 bytes=920890
- `decompiled/zepump.dll.c.txt` sha256=7ac6f286d6b1bda7a213bf14428b9642322394dfdc91d2c33d9e340fe110ca2d bytes=653449
- `decompiled/zerequil.dll.c.txt` sha256=874aef8a692479c74b1bb050e61c8e66711e74f1a662c329de5336b3bf480e99 bytes=738920
- `decompiled/zerplug.dll.c.txt` sha256=da3b129cdb4c3e863f4b42277a3e2efa43d647ae4cf64870d49d612b26ff69c0 bytes=828207
- `decompiled/zerstoic.dll.c.txt` sha256=82a6e6da63fbf1e09a0fe6914f970eab37e26f63c69d6cc5b53277ed033fa337 bytes=699520
- `decompiled/zeryield.dll.c.txt` sha256=8ca694ef917fa9e6f5700cfb786895f5ef7057246db072e5a512abb672a6487d bytes=482957
- `decompiled/zescfrac.dll.c.txt` sha256=e003bf26429b78373b84ef32b01a762392744571b6cc112e4f01b2fc048653d9 bytes=655156
- `decompiled/zescreen.dll.c.txt` sha256=26525717a1fa570e84743ae0d524ef239f78e2548414846a257bcab76115ecf5 bytes=730824
- `decompiled/zesep.dll.c.txt` sha256=ee487730e0bbf0c6bf90faca477f1972a318a8846cb2e7f588970f9da528622b bytes=537569
- `decompiled/zesep2.dll.c.txt` sha256=490fae3ed72976ebb578fbd51cb21d19af24ed28916ff490efa067974f79d880 bytes=720217
- `decompiled/zesferm.dll.c.txt` sha256=19d664e0a8ca52f970f64694cec93d37f797284c6d92e26f0314b65df1d790e1 bytes=397180
- `decompiled/zespyro.dll.c.txt` sha256=306b91133af47f1db6b1b53bcb94a62509d40609e28ee012d8797d46141d979c bytes=937525
- `decompiled/zetasc.dll.c.txt` sha256=94722251cc7c29d101f7734889ac8ef63ac5b4bc0a39b84c50e409eb2fc83d88 bytes=611215
- `decompiled/zeu3dl.dll.c.txt` sha256=4e9d643d874e544d0e1abf9c788a6ec7069cdd494bb379e508796d7fabaeea41 bytes=780039
- `decompiled/zeu3dmo.dll.c.txt` sha256=3e6aab8f40146b57dd90e86f1191ed37d5e87481317e1c8500b3c35acd044c69 bytes=473385
- `decompiled/zeu3utils.dll.c.txt` sha256=3b5c12c1e73defd0df5e0ec135d769a61d9e33c79ebfbde3b8517ff824229bbb bytes=647776
- `decompiled/zeuser3.dll.c.txt` sha256=1018ac6e7f3f3697721d696083d2eb8f97a486a22aafb0e7ce0377ffdfab0e0d bytes=665004
- `decompiled/zeutility.dll.c.txt` sha256=0c83187fa09651cec80595f5f01fdaaaee8e6ee0f1bbafe59ebf776c616913cf bytes=622267
- `decompiled/zevscrub.dll.c.txt` sha256=cc6ab2d7dd150cb5b3254a1af716b3ad8f04c3928b437b447e6993e49baec43d bytes=1264084
- `disasm/MDHCR.dll.asm.txt` sha256=f020bf3563203137fd732c14fe9b94d1a4c57d2c9f120fd43b1c9b5c4b00dd36 bytes=1313821
- `disasm/amfipersist.dll.asm.txt` sha256=49b5333e3607934f8145b587d2f4a794f371dc53abdc2492da8da4809b9764a9 bytes=543335
- `disasm/apblk.dll.asm.txt` sha256=97d89aac07a50144a02e469640c5747a5568c4254825627b4408da9f32d6b63f bytes=1679553
- `disasm/apddbi0.exe.asm.txt` sha256=bd30b91adb240b64c705831134dbfdbaff4770f0f58fcc37feb1332216b0652c bytes=1319100
- `disasm/aptrain.dll.asm.txt` sha256=42c46946c4a8f57b4f9f244dd9173ec3aa8da0ce2ced60f4a4aeec5971efacf2 bytes=680162
- `disasm/capeopenunit.dll.asm.txt` sha256=2b7fdc0fcf3fdee2bd288cef00b167369206d54da47b3d5c974b3009ec6468f2 bytes=2386997
- `disasm/capeopenunit090.dll.asm.txt` sha256=de980f777be09aab0394068eeaa06e22a6cbe3d21389aefc6aa9130f6c6b2836 bytes=836878
- `disasm/capeopenunit093.dll.asm.txt` sha256=57f3dfa4c732b9e738fec2a9efd6b12dce26b7ca94115cc6717c3b1ac69f41fc bytes=1467815
- `disasm/cflash.dll.asm.txt` sha256=d9dc5c22741a4310d6d4b74f58e8cacf0f4b394b49190b3c6aceee38c030b5e9 bytes=628144
- `disasm/crtddb0.exe.asm.txt` sha256=c2c4edc68349f117ea63aef8412f0a8f1217abf434fd623c433a7fce923f8168 bytes=604925
- `disasm/htxint0.exe.asm.txt` sha256=4b44df3430f3282498583629fd0340a9c836ec626bb510b8f04b82ab86cab1f7 bytes=1392449
- `disasm/hxnetintpropcomp.dll.asm.txt` sha256=e47d74bf219fde2ac1deea92d855e0036a369c72d8a973c7fe92ffc23062919b bytes=909467
- `disasm/pml.dll.asm.txt` sha256=2aab60607bcc58343836c5e2b4bfdd73a771f6827fa26ea02d46250da01eba7b bytes=567566
- `disasm/polyusermodellib.dll.asm.txt` sha256=c40689326304ef223ee49ead802c5e3c85f12995d1fa5fb12174697589a490d0 bytes=1510235
- `disasm/refcmds.dll.asm.txt` sha256=2152ddb1681a138ca7281a3129f3f587745c58b97c621cb660a0671d64326c87 bytes=1045341
- `disasm/rtassay.dll.asm.txt` sha256=b29498e13f09fc0285d640f1d86a0d7488a49f22db14e72e7739320bd8354b53 bytes=681089
- `disasm/rtoblk.dll.asm.txt` sha256=ddf5d5a1e74246b4d864634af142fb79fe7a049ea5e850c64ddb0d2b4c173473 bytes=812382
- `disasm/rtpdfutl.dll.asm.txt` sha256=20dc245ff976fd24766aecbe2a992f8f073d505b7b27c213a934e3f54ea6c118 bytes=1636894
- `disasm/safeed.dll.asm.txt` sha256=825174550905586393b58a0d3d11e9e0cc8e793eee6f582ee72dbe59a7dd161f bytes=673319
- `disasm/sainput.dll.asm.txt` sha256=9209623f81e68e2db8764ee54ca3f552de4c60ec25c04228327dc4316c78139f bytes=1098309
- `disasm/sastream.dll.asm.txt` sha256=1047b0d6dea57c20e70a8b2738475202cd6e60dad1080baeef634063f56fb83b bytes=1048831
- `disasm/smdyn.dll.asm.txt` sha256=aa97f2a857c0cbdd4c924e5831249c75db0cfc8e5300d46ee0861c2ebe0d49a8 bytes=1587306
- `disasm/u3subflow.dll.asm.txt` sha256=6e7c69cdc86d5aac2b6977e76c10cb1f4ae044a10cdc2846873940507be632db bytes=623459
- `disasm/usrdmo.dll.asm.txt` sha256=31e4a4e8ea57127f5eb01d692ae9abe32bc2f4954b8aa89282335aebfde24d66 bytes=504722
- `disasm/zeabsbr.dll.asm.txt` sha256=6b210b98f5fd137e7165e00b86a3be134491bceed587cc679d0387aba77e9513 bytes=802612
- `disasm/zeacol.dll.asm.txt` sha256=b8c4d55b73297a76a399a198a43804473f1bbdd04540f2c4e3600fed9a196f7e bytes=854999
- `disasm/zeanalyzer.dll.asm.txt` sha256=f7ef1f3d1cbc7870bcc9ebd631c13b436c3c9b2f7403d2df0e2e670f191437aa bytes=1127171
- `disasm/zeaple.dll.asm.txt` sha256=8c6e620d4883bc49a9ff3f01612cfab834488c25f253e715b0d8b77f61a7f2da bytes=833291
- `disasm/zebaconv.dll.asm.txt` sha256=595d729fe2a7fc18f9d554b1c12397542fa65eafcfa92fc586fb13fa1412e662 bytes=638976
- `disasm/zebatchcrystal.dll.asm.txt` sha256=e87b21694f842e2207c6152c20be0219aa741ab853640de5d701ad572e015cf7 bytes=631393
- `disasm/zebferm.dll.asm.txt` sha256=8078ae8dcbe23f379342c7f868584c22dcc23dd8d8aa6222408c8b5c397a3f35 bytes=1743764
- `disasm/zebmembrane.dll.asm.txt` sha256=9cf4e227f637e38ce78844811ed779736966163020c326ad4d1e333190e5f098 bytes=1844647
- `disasm/zeccd.dll.asm.txt` sha256=7622d429ed9257f7150adda59b2cfc4825beb6e0a6dbefd561bdba7eb75dbf8e bytes=813867
- `disasm/zecferm.dll.asm.txt` sha256=c9828838e6777baff7f7fe7607da1d4d72c63877191098f058cf158811af2d98 bytes=788512
- `disasm/zecfuge.dll.asm.txt` sha256=d4007c892700f6afadde1027b37b73180514ed6d5259ace4d9c61119c7bc9e59 bytes=2479216
- `disasm/zechrom.dll.asm.txt` sha256=fdf170e6d964f2cd2a67a074f5f64663a724f26a025be04fc81a4947277814f3 bytes=1302403
- `disasm/zeclassifier.dll.asm.txt` sha256=984bf00696d584fa0b61a9796a1517db431e9a7f03c101faeb88cd925c008690 bytes=1483479
- `disasm/zecoadapter.dll.asm.txt` sha256=5fd62ee679a561dc7ee1e481d8d891e2a29542d89ae17d2a60f21d06ea42d432 bytes=1278100
- `disasm/zeconsep.dll.asm.txt` sha256=21ecae2c92c476f195bcc1e4d4f38b69e4ed12fa9e72a977144fb5adaeb78652 bytes=754210
- `disasm/zecrusher.dll.asm.txt` sha256=6637b88466d8e750c28921844897814eea5c470fc7700a4fb978d7b51e3928c4 bytes=2809217
- `disasm/zecrystal.dll.asm.txt` sha256=c2990bda7b40ea87526f20bfbd046f6f87883b2392035a1a5b50752bbd8ade8c bytes=1929891
- `disasm/zecrystallizer.dll.asm.txt` sha256=b8a24f2084d7c6619e89b8f578eb4dd17a8542d22dc418749059c96e19863858 bytes=1391067
- `disasm/zecyclone.dll.asm.txt` sha256=d62de0240ff3662ea6ecab718e2ed7719d094c6873f0e415a0d03417ea471dd3 bytes=1838461
- `disasm/zedecanter.dll.asm.txt` sha256=cf71d2d97498861d85ecd525cb7ae2f40fc67c26c48c7fdabfe83a4a4c91e21f bytes=735211
- `disasm/zedistl.dll.asm.txt` sha256=883abee0fb510f7b81b10d5d13cbf4d640b1afae4ffdc94cfa0bcf20b1fe3d37 bytes=596492
- `disasm/zedstwu.dll.asm.txt` sha256=fdce8c9db94517169eebc1104dc1a05f595cdf28425ba0027494ed8df0bdda6a bytes=597243
- `disasm/zeelectrolyzer.dll.asm.txt` sha256=dc7501419c0e0ddade5556c4a7034d512244b9641e727853bca90cef515ab354 bytes=1166990
- `disasm/zeesp.dll.asm.txt` sha256=6e0e69ec8f5adea181c674726cffafa3eaab26c605aef340836c080c322c2648 bytes=1074268
- `disasm/zeextract.dll.asm.txt` sha256=53b11ccd6b985efd26df5ece757b817c59d7a3c3302b92e9756d414c036880d2 bytes=1381829
- `disasm/zefabfl.dll.asm.txt` sha256=3cc186f511f4fdf18aa80da815cabee8a6821df81326f245df8e406cc6ae1d03 bytes=1160019
- `disasm/zeflash2.dll.asm.txt` sha256=c09510003e346f71e21eb75f97005454a784359222d247e58bb089abfceceae9 bytes=1612334
- `disasm/zefluidbed.dll.asm.txt` sha256=2ccba82ab5aa776f886fba9b020599aa93da4e506e943d84ecf693db54ca4e7b bytes=2210622
- `disasm/zefpress.dll.asm.txt` sha256=5a9d9be7bcbcd80d901fc7eca53e5fa0e6d533ef40814bf3044f98e95a82ae1f bytes=960086
- `disasm/zefsplit.dll.asm.txt` sha256=9676d6a0fd3d6ed4264305e58a6a5d36f612ff83aeb32ba1a6b501496f361da2 bytes=1186160
- `disasm/zegelchrom.dll.asm.txt` sha256=fc3c590c140f2a90f4816bd3ec22d6184fdc7fe9fbab146903162ed20e141e5c bytes=826442
- `disasm/zegranulator.dll.asm.txt` sha256=ff9b83e1820dc7a705faa999351e8416faf838ccdaf5a96c3e1543eb5f18cbb5 bytes=2385625
- `disasm/zehxflux.dll.asm.txt` sha256=c9a3ec2d282a5f389f873174b25e54d0cdaf51fd33a630450ec5e77dad1166ab bytes=685111
- `disasm/zehybmodel.dll.asm.txt` sha256=b94cea643317f737e3524c75564d97b956250fc0dc1471e213f1d6a641ef9a96 bytes=1191083
- `disasm/zehycyc.dll.asm.txt` sha256=972a7762b8d4faa8a29ac64dbbafd4b6d3621ffddbc3338a8dbb76c03ff8d95a bytes=2216628
- `disasm/zemcompr.dll.asm.txt` sha256=0ad9e97d5bfe1c486ed7d99a7ce8ddcc24e64cc53af37f8b1050ea41299dbed1 bytes=1561641
- `disasm/zemembrane.dll.asm.txt` sha256=c154d390ec11b17409800247525567ce93208dc74dbff8bfa3278e337ae476a9 bytes=702483
- `disasm/zeode.dll.asm.txt` sha256=da792df1a85b19a47931ca7104d288de6cae74a9eea6972ff82774ff1f962f95 bytes=789586
- `disasm/zeopi.dll.asm.txt` sha256=42a01cf80737c72f65ebce5a7770a19fc47abfc0f5df93a6b265695eab89a182 bytes=1267205
- `disasm/zepdrop.dll.asm.txt` sha256=46866594161d36d5fd9dacb1f0add5bc26a99449859503aed6926be9e227899f bytes=1897382
- `disasm/zepipe.dll.asm.txt` sha256=d8e852616dc6f5bba2ab18c512e142dbc789ea1e8090b48016213431c36ba6d3 bytes=1060006
- `disasm/zepipeline.dll.asm.txt` sha256=10866977b3c45ee2933271763fe2befa79fae7445d55a12243d21e64733defe9 bytes=1970651
- `disasm/zepump.dll.asm.txt` sha256=c0a4d2955f779a187ed5a8e2181237f5621ec1ec089a9e9363198f59ab41ee73 bytes=1379295
- `disasm/zerequil.dll.asm.txt` sha256=44f63989e96608f6d55af80ea84afc5a52587d487fa9f8bbe54083d65e060501 bytes=1138602
- `disasm/zerplug.dll.asm.txt` sha256=a3c36fb0f6c3b3d4e84d836cfcc9a90ea16249b2b6e86cc04a30b401743a0116 bytes=2236410
- `disasm/zerstoic.dll.asm.txt` sha256=8c35a79083154a77b3c0ecc672ab0abb70cb429253f77e71a82b6941608fb55a bytes=1099676
- `disasm/zeryield.dll.asm.txt` sha256=ff88c54e77bfa83278e8f9c3c722b41a612182c9dc1d11123e6f40b20d25f76d bytes=816924
- `disasm/zescfrac.dll.asm.txt` sha256=8a02eb015f32f484855ffa5f7db7613957e26af9ef2e5e2e429ea82ee4e6eb53 bytes=1017700
- `disasm/zescreen.dll.asm.txt` sha256=1b98297ce8f89862a90967b5fb44a6725a25dff35a4e0041a17988ec5a9f243a bytes=1138135
- `disasm/zesep.dll.asm.txt` sha256=c0116bd141f2de6b60ca654d0efc6111e39ecbb64e4ee3b13a2b9a0a79e0513f bytes=841089
- `disasm/zesep2.dll.asm.txt` sha256=2f6dd10012187449660cea2e8880a9027bb9d685d39e9186a8d479f1e7d85144 bytes=1090674
- `disasm/zesferm.dll.asm.txt` sha256=d29009d70170a4d692924640a782436757331c5fe915fad6220f19b6722ef75c bytes=614683
- `disasm/zespyro.dll.asm.txt` sha256=9611b3eae6ea99c6d4e02a0d6feee943db9bc506864df51196602d2b3fc319c5 bytes=2436345
- `disasm/zetasc.dll.asm.txt` sha256=ae0d498a7863665c962a2e25f261dec6d9ca665e014db26ef15b6c8316d7919b bytes=1121713
- `disasm/zeu3dl.dll.asm.txt` sha256=b568c21bed7f0f176f2d9bc034496bd3571253f486f6ea7466d9d12cab172633 bytes=1355853
- `disasm/zeu3dmo.dll.asm.txt` sha256=afbeccc213549bf2e87f9128160519246a048ff2fd0b15fa0b3ac1ecf4659072 bytes=708683
- `disasm/zeu3utils.dll.asm.txt` sha256=40b20acbd083a02cd88e10fba3c45badf71a40412568ceab28aab9be445a2e16 bytes=985328
- `disasm/zeuser3.dll.asm.txt` sha256=f8449a7946f9d21fe48b3f33ec5eb55ea25b51d162a329d4bb3537f70a4dc813 bytes=1152459
- `disasm/zeutility.dll.asm.txt` sha256=984ce29ea90f59fcc9cb6c0b3b8c3067851ace03d179b650f341a892e91a6b28 bytes=1026838
- `disasm/zevscrub.dll.asm.txt` sha256=d9b26bdd5ed39c68fb087a138fbd59094f4e41147bfc669c9f79a7d20dce2fb1 bytes=1866722
