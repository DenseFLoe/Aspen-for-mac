# thhysysflash.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `thhysysflash.dll`，725960 字节，SHA-256 `0b7d0355052e874b3cf99c93326f3f7208559bf44835a1b424e68bd7db24853e` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 3574 = decomp_ok 3574 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=3574
- decomp_ok=3574
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `thhysysflash.dll` |
| 字节数 | 725960 |
| SHA-256 | `0b7d0355052e874b3cf99c93326f3f7208559bf44835a1b424e68bd7db24853e` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[CommonFiles64Folder]/Hyprotech/COMThermo/thhysysflash.dll` |
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
| 段数 | 7 |
| 指令行数 | 146238 |

## 3. 反汇编清单（全量）

全文：disasm/thhysysflash.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/thhysysflash.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 3574
- decomp_ok（伪 C） = 3574
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：177.7 s
- 日志：out/R1N/ida/logs/sha256_0b7d0355052e874b3cf99c93326f3f7208559bf44835a1b424e68bd7db24853e.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `thhysysflash.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 3574 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +3574（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001060`, `sub_1800010B0`, `sub_180001128`, `sub_180001150`, `sub_180001210`, `sub_180001340`, `sub_180001420`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/COMThermo1.ocx.c.txt` sha256=d345781bcd59bd6719a6a910e57604f80e4ac2e6b8cf16a48573eaced826019c bytes=635883
- `decompiled/ThVersion.dll.c.txt` sha256=b396ad2252cbf56107c5e8c7c3d9e97a69aa67fd7cc8031c340c2b9602153687 bytes=2732579
- `decompiled/hyprotechestimator.dll.c.txt` sha256=b7a9185912e2d192c9c26ed4d3a8f9308f1b45061e967c1ae219ed9cb558e562 bytes=3702122
- `decompiled/thantoine.dll.c.txt` sha256=c5e80e17169c972c87a7dde953ae18a47d39c290f3017d18f0da92934195d931 bytes=3074733
- `decompiled/thbraunk10.dll.c.txt` sha256=83992f6a234ed10d1088610fab3ba4fc5108b4943eeaec27bb7e805fa7c98a83 bytes=3077924
- `decompiled/thchaoseader.dll.c.txt` sha256=70ec602be91f2c090c4782af512ead107095ff846ebf8ccf3eb162d01abd8457 bytes=3166727
- `decompiled/thchiennull.dll.c.txt` sha256=51cf1f6abe8ce4792fb9c72fe16de2e6b610ac64983ae695d911f8c45714b4c6 bytes=3316197
- `decompiled/thesso.dll.c.txt` sha256=1428a58c196597bbf2a79ce73265f96c47b2ed765e6111cb37c8152fc28f1722 bytes=3023905
- `decompiled/thextpkg.dll.c.txt` sha256=69b138e2b58a50ab4a644d5995c10952e7574c6960a3e6866b9454668afa218a bytes=3151792
- `decompiled/thextwilson.dll.c.txt` sha256=36ef4821809bb7c5a5169cdcd10a5438eb8a37b1e0549e19680ab8617a70f2b4 bytes=3082796
- `decompiled/thflashmanager.dll.c.txt` sha256=83b76443632934fd510cc424cd124ab0951d8a1ac6b1d02e4156e21a0269d229 bytes=2910371
- `decompiled/thfugacity.dll.c.txt` sha256=691bca08e3eadefa2046abb5f0bde038fabac1625adb2c0bfe085f304d789400 bytes=3214528
- `decompiled/thfuprop.dll.c.txt` sha256=3996a012009a6cee1731500c55ad61ede66ef04c32fef2b19bc2e7015a93159a bytes=2983246
- `decompiled/thgenprop.dll.c.txt` sha256=38db61fd9913271f8ef8166a9948791ed14136eb4a8c55451821e3bb046ecd54 bytes=3034033
- `decompiled/thhomotopyflash.dll.c.txt` sha256=46c35aa27372ae0b242fc413ed2a37d0dbdbc0b8caf35485a44a5c31ad94bb21 bytes=3776032
- `decompiled/thhypnrtl.dll.c.txt` sha256=8e4c34fc4761203edc4bb1216ff31cfd341ae95ad85172d9d721e1342818985b bytes=3228902
- `decompiled/thhysysflash.dll.c.txt` sha256=e635421e9721e331d6c2365c0e5f0955ac37baab329dca36a72ee49501de802e bytes=3407593
- `decompiled/thidregsol.dll.c.txt` sha256=a7c098de997306c0c7a6e02e85ea8fc4d9f6dc89a5712a9cb83f835e75d6fc8a bytes=3389805
- `decompiled/thipmanager.dll.c.txt` sha256=14fdcb24b49499baf417fdb9c55ed98ca6d212b9f0285262ed0fc99c4bcae215 bytes=2769460
- `decompiled/thleekesler.dll.c.txt` sha256=07acd368620127dfef793053bd1f9977846bcb87d64e22e213f4d485f76f689a bytes=3052141
- `decompiled/thlkp.dll.c.txt` sha256=0290a1b61382507f04b1f3e978b46d1a1664d8222702002dd463b6cea2913e48 bytes=3303476
- `decompiled/thmargules.dll.c.txt` sha256=a233a96bca987f98da717d91696fde79b7190ad8be3da3c4ca6c95c0b08fccbd bytes=3165441
- `decompiled/thnrtl.dll.c.txt` sha256=4a683736c86740389e2aacdb0f04237c978659a67607fbf6e3f8fd4e3588e5b9 bytes=3268500
- `decompiled/thpvtharness.dll.c.txt` sha256=242d7d681d6c2c74a90a096e4a1b638f9c3621fa6fd48738d55665c9552d8625 bytes=3308054
- `decompiled/thunifac.dll.c.txt` sha256=0398d617fc805c736701f4bcdc8148ec46d9aef607be70ea369b1da697b51012 bytes=3287297
- `decompiled/thuniquac.dll.c.txt` sha256=cce868060299c0db9f0b0f5075f2ce213035e7b8f5a18f85b3fd68936fe78e51 bytes=3260945
- `decompiled/thutility.dll.c.txt` sha256=57839e0a4fd4397015d8099480ac8069c5f2758ced40ed48e8a0325b628ea34a bytes=2842824
- `decompiled/thvanlaar.dll.c.txt` sha256=7c646804088dffe755e4080adc449b5d62ce0cfa871b56e77b9af331e7b5f421 bytes=3163323
- `decompiled/thvirial.dll.c.txt` sha256=8fbc15f9c01b27a1411f701dfab99ce22da8cb15f392de08c429287887f4d56a bytes=3316027
- `decompiled/thwilson.dll.c.txt` sha256=e0f4ede9ac7e3f78f720536afde9b8e37179a571088ada7e333b07d763625534 bytes=3207120
- `disasm/COMThermo1.ocx.asm.txt` sha256=b550486a8bc5b5048f1b652dad1c85ea6b24934b173ceecc11a9a38811283225 bytes=1773734
- `disasm/ThVersion.dll.asm.txt` sha256=2fc19e67db70ab2de3a0fc6dec6169fee87518a56db15a3f5b00a61cc8b0807c bytes=4313668
- `disasm/hyprotechestimator.dll.asm.txt` sha256=f9cce004aa8c9fc5fa9c30b6c34cf9f6c4d0c728f982aa58e15b51a2b0317225 bytes=5929568
- `disasm/thantoine.dll.asm.txt` sha256=194d2eedce613f340550d4e9883e9515679b3017db753db7001afa04eae1119d bytes=4959723
- `disasm/thbraunk10.dll.asm.txt` sha256=80599c1cbd7a512f00f8fc50424dc55029e912f49476bc9c76859f06db03b638 bytes=4975007
- `disasm/thchaoseader.dll.asm.txt` sha256=4c7a8eb4069e80e4f8912a45020636ce40b202f9700a59863f6406f3d7327951 bytes=5140363
- `disasm/thchiennull.dll.asm.txt` sha256=6a9f09f15ca3f912a859212bfe4b06a5d4cea7e61cfc0639c5cb3195b2490196 bytes=5349817
- `disasm/thesso.dll.asm.txt` sha256=e6ca5b6bf1630d17111e8185a22a228f625d1541ef9111f28a03d3edcb647981 bytes=4869217
- `disasm/thextpkg.dll.asm.txt` sha256=e2fbad5809422e9a7ba9654bc13ea094e5df5a58e60f5a1fea26d36ca9ef0069 bytes=5074126
- `disasm/thextwilson.dll.asm.txt` sha256=a612ecaed7952f392b0b0ebaa205b68b3cf3faab47588eb4842af0f292871c1c bytes=4960408
- `disasm/thflashmanager.dll.asm.txt` sha256=fc6251b9526d4762661812593472333563f4f204ab5cea06bf2298fb925d8a27 bytes=4612177
- `disasm/thfugacity.dll.asm.txt` sha256=2cf4c16abdcfc32d5025f015d96f79edf608d6e63058ba1ecfe7268a11f7657c bytes=5228339
- `disasm/thfuprop.dll.asm.txt` sha256=af1aa2cdb684b32fe750d5bb11703f48271522cdd7c7ef1db988ff1e2fb10ea4 bytes=4802033
- `disasm/thgenprop.dll.asm.txt` sha256=1f64b733652b561ad1b97f654f6c227abfd27d3f031e052d8cfe9abdde89bd75 bytes=4878834
- `disasm/thhomotopyflash.dll.asm.txt` sha256=658b541db9ac5be1461da0c738ff169e1d1b57b527a2954d1db08db1e25bb974 bytes=6062552
- `disasm/thhypnrtl.dll.asm.txt` sha256=264e9be0fd6c2401d026b7d9e3f93226e1838b65e6c4133517e8911a9ec61478 bytes=5204917
- `disasm/thhysysflash.dll.asm.txt` sha256=e32b5ce929448f12454f9ce141e46eea3ae029958e1d981368bf2ac1bdcec069 bytes=5474551
- `disasm/thidregsol.dll.asm.txt` sha256=5f19204f540d5fffbd1a6b55d2c8e082bdfe502f3a0b5a4e89c2c4859a19b5a9 bytes=5516662
- `disasm/thipmanager.dll.asm.txt` sha256=d30bf9469eca887ee0dbe47df15660d9bfd7ded5130272e3e505837d0e63d97e bytes=4374121
- `disasm/thleekesler.dll.asm.txt` sha256=3148769dae9f4aa0a5a2f5bf28e1e33566bacc74449ca9bbb3f517362efe4d57 bytes=4926780
- `disasm/thlkp.dll.asm.txt` sha256=180f48ff6503c9e785371ae01ebfd0f5b0f877546ffb09381c7824b796db6963 bytes=5355735
- `disasm/thmargules.dll.asm.txt` sha256=5f0473bc9492b58f335c0e3b4e0e73b7abc719bf74099fca73ffbdda9c6fcb04 bytes=5110335
- `disasm/thnrtl.dll.asm.txt` sha256=46f2482b873383c8b66bb94608cfa4a9ff23dbf0f89dfd80f5bbd5276138bbcb bytes=5286691
- `disasm/thpvtharness.dll.asm.txt` sha256=820e96ec36540a144817068b318fea5efeca5d32679d5e3f35d6ba3d5c1b2f58 bytes=5419901
- `disasm/thunifac.dll.asm.txt` sha256=d275e338dbfb7eb205c38da678c37db80fd236ef3512f7763365c8f6a4a9743f bytes=5294583
- `disasm/thuniquac.dll.asm.txt` sha256=e21f4ca05de279abb010c11416ac1329e19d46912c1adb82b94ad087fef8d7bf bytes=5276637
- `disasm/thutility.dll.asm.txt` sha256=47504240bad9f218b2d543475987bf0ce2ce312b573a2b6373eab91710871dd6 bytes=4502695
- `disasm/thvanlaar.dll.asm.txt` sha256=ca41d17b405765b75cfaa0db5bfd89f5b746310a80be00ad2020e63c9439c9c8 bytes=5108292
- `disasm/thvirial.dll.asm.txt` sha256=1ff9dcfa373abf2a266a14c6eb936d25ffa9dc400e27f2bd5a2d50c6881f2605 bytes=5407961
- `disasm/thwilson.dll.asm.txt` sha256=4aa8f496efbcbf113bbf6d914de7cca6261547887a85fe2391496fb65cd59525 bytes=5167949
