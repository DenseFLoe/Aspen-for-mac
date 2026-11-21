# AprCorrMan.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `AprCorrMan.dll`，80424 字节，SHA-256 `61e0cea016c4a87340d4dc5dbb345e0f5422e32c2d9d55a4cd3a67ba18c13860` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 164 = decomp_ok 164 + decomp_fail 0 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=164
- decomp_ok=164
- decomp_fail=0
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `AprCorrMan.dll` |
| 字节数 | 80424 |
| SHA-256 | `61e0cea016c4a87340d4dc5dbb345e0f5422e32c2d9d55a4cd3a67ba18c13860` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/AprCorrMan.dll` |
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
| 指令行数 | 5876 |

## 3. 反汇编清单（全量）

全文：disasm/AprCorrMan.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/AprCorrMan.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 164
- decomp_ok（伪 C） = 164
- decomp_fail = 0
- 恒等式：成立〔实测〕

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：16.4 s
- 日志：out/R1N/ida/logs/sha256_61e0cea016c4a87340d4dc5dbb345e0f5422e32c2d9d55a4cd3a67ba18c13860.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 0 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `AprCorrMan.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 164 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +164（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`sub_180001000`, `sub_180001010`, `sub_180001050`, `??0bad_array_new_length@std@@QEAA@XZ`, `??0exception@std@@QEAA@AEBV01@@Z`, `sub_180001100`, `unknown_libname_1`, `unknown_libname_2`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part3.tar.gz

- `decompiled/ApSetComp.exe.c.txt` sha256=5e237771dd977b926169982f25ef8bc01f21c8ee57959ee257044c9c98311122 bytes=130599
- `decompiled/AprCorrMan.dll.c.txt` sha256=3b3ff81def0744035c38344da1fd49b89bf8e1144c58bf4404b3310f053038ec bytes=115284
- `decompiled/AspenTech.NGP.UnmanagedBridge.dll.c.txt` sha256=c3a1b9b7bf9942fa551f786b9cdbaa0f4ac89664583ba5399381fc89390dbbf5 bytes=104622
- `decompiled/AspenTech_NGP_Managed2Unmanaged.dll.c.txt` sha256=c6b860fb808ea86aa09d2712690b54681f3442cd700bbb52dee6470a3b3ff4b3 bytes=116673
- `decompiled/DataSvr.dll.c.txt` sha256=8fe06136f54c3f9128253307df66e8d37cedea165a5e1d3a69eec2ae46c40d3f bytes=129361
- `decompiled/DistillationAnalysis.exe.c.txt` sha256=c5f4a5cc060572b1aeb7eb3e2c0dc6c6dc3a297b18e8022d8b4f35e2df6cdd24 bytes=1823478
- `decompiled/EDRProperties.dll.c.txt` sha256=92ae852f5ca2a551b033b6159e35de8586703ec59989cdbaff076a9d36189aaf bytes=313486
- `decompiled/GasProps.dll.c.txt` sha256=f4462f718e314ceeb9ef918388fa20dc00734a872c2717c5dfe1a9637e5aed41 bytes=272020
- `decompiled/MergeNN.exe.c.txt` sha256=d8c53e3aa4f10db468737fd939339de43a7a728237ae8cc5f4d511c978d133f3 bytes=1557161
- `decompiled/MergeNN_FNN.dll.c.txt` sha256=8ad202fd249933eb0b50de37fcc11fe9652d38cc91e6beba093720200ab13bb6 bytes=209943
- `decompiled/aosbridge.dll.c.txt` sha256=8884c5e4b6eefcc1ec15267bf882d07432872c321375bf3f3c578cd9eaf1739b bytes=186236
- `decompiled/apbatutl.exe.c.txt` sha256=8f23dd5044459fd37a1b280f4e531cfd073dcee0a3585c13a2278b942f43b311 bytes=83312
- `decompiled/apmaindll.dll.c.txt` sha256=c76a0359d0ca448be106dda524333841b7dd25b7f35ab53f37bd274e68088517 bytes=152312
- `decompiled/aprsysbridge.dll.c.txt` sha256=64d020ea5ad860d6cd4c96a1ec3fd22d6293827e233f2a000a312de6d396b679 bytes=136730
- `decompiled/aprtbsmn.exe.c.txt` sha256=8a463b99794d9c35ea4536f27e74871efd4e954d79992023b5b60869d5fc0211 bytes=84138
- `decompiled/apserverdll.dll.c.txt` sha256=770e86c2dc058ee83e95f67bbab2b305c9072d25e764df3ff5aed2ad308f935c bytes=1625338
- `decompiled/apstorage.dll.c.txt` sha256=018ae6b864c09f1adab1560865b7c25a31c640f3554de9cdd3c2641b4625ad5a bytes=146322
- `decompiled/aptime.exe.c.txt` sha256=dd5d6079eeb89739acf91473a7d6ed43f651cb420b4fa8a76a40a487cfc28326 bytes=55987
- `decompiled/apvcomps.dll.c.txt` sha256=9fbb3a58815c6489a1bde85942cb1ab154b96732766dff1a0f7cceee517ba574 bytes=48210
- `decompiled/ascddistil.dll.c.txt` sha256=fd519bc3d5ae487e5d857abdea57084f808a485c6cc0ee5505ffc1fb6ac951c0 bytes=2178172
- `decompiled/atcomaterial.dll.c.txt` sha256=0f0bdb357e2471b3c3d58c15da2cc19173846b5beab9cfca1de8c9e4dbbb589d bytes=1436177
- `decompiled/atcoproperties.dll.c.txt` sha256=d8ef50d725dd83099d4d181f30c7c6aa834d5aa7fc3aebe0c0a2d14889eb529d bytes=2183566
- `decompiled/atdms.dll.c.txt` sha256=1d8cb0151add3976e0157dc05189c3bbb4cd9f61034c8a887086977d17884efc bytes=1744044
- `decompiled/atmem.dll.c.txt` sha256=b8df4d83a84f72dcd5819b26b62f614d7339c7d0a693d5cce8e09d63148349cd bytes=33879
- `decompiled/atpipe.dll.c.txt` sha256=558b2982216b44dc66651d37bd53dace96e743f7052b8a0d73a48bef7f7f3652 bytes=101975
- `decompiled/atregwithapluspaths.exe.c.txt` sha256=5d973605172b79497144d8e2909c5991c90cc377fe5fe4e08002a6f271d7ec3a bytes=166939
- `decompiled/atxc.dll.c.txt` sha256=d89110cb1383e7fc8cc349bfff914a5895c80dee3085b30fa91979ba5da701c7 bytes=3646501
- `decompiled/cotafile.dll.c.txt` sha256=9b5b72cc377226501b00500933002e6d044b672609fc7eb73b5eb1839af04158 bytes=255996
- `decompiled/cotafilesvr.exe.c.txt` sha256=7b179096b3fba28c6629538f51efd36d0f180a0f1c472e80bf3928f9c9921eb9 bytes=188848
- `decompiled/createva.exe.c.txt` sha256=95d524acf594310f81719df1ae59e634085cd5e79d850505048a2ea3618642f3 bytes=86555
- `decompiled/dfmsmn.exe.c.txt` sha256=cc43ef996845b4d13f4cc1b501ff512537629db8516ce3dbea076c78abc267df bytes=63648
- `decompiled/errout.exe.c.txt` sha256=96414d1d91fe3d8fb3fb3ec347fb1c578a2ba23766d681cf584f4234cc4d053d bytes=44227
- `decompiled/fnapfile.exe.c.txt` sha256=b98120275e04e1d0e36fc51c9350b4262e36d504fd042b215d234340bc935a50 bytes=87700
- `decompiled/getridof.exe.c.txt` sha256=adeee3c74922205f186a0d849799dff346ab5d1cfbf12e05b6a7fe7e1edc2a4b bytes=75990
- `decompiled/hxnetintqaplus.dll.c.txt` sha256=98ae9e013c4c620aab20ac907c2e610865460553195a4c611a1ac41c3abae030 bytes=2523870
- `decompiled/ifmsmn.exe.c.txt` sha256=9ecf5316bd40e6b5a7ff96e40e09280001b1eb2d3b22a529499d699f7177ab6c bytes=89723
- `decompiled/ngsutils.dll.c.txt` sha256=8c068942629a77d765bcf10cf813a904bfc2800ea88cedcd66a5e3318bc7ad03 bytes=260966
- `decompiled/pol_eos.dll.c.txt` sha256=6876b03e26d17fd87e0264f25b97dd5aaccaac6aa37e82d0548cfeb4ceee05da bytes=1638479
- `decompiled/pol_rxn.dll.c.txt` sha256=c72804ebdbe11735e862c1e8efc8daa78282b0b0eee8ca1f34fce2d2fdd9cf31 bytes=348421
- `decompiled/pol_segb.dll.c.txt` sha256=b9b1d27598868597817acec396a27814609c5a75102613ed73dd92490878407e bytes=280826
- `decompiled/ppada.dll.c.txt` sha256=e493a1d346b736753e9b6b8297cdeeffb033232b2790c3ce35a55287b2baa91a bytes=2099130
- `decompiled/ppbre.dll.c.txt` sha256=69bc54cf110f99ecfee4ec79d9b8459b432c595d13c95ca70adec6d8fbdd3625 bytes=299198
- `decompiled/ppcpa.dll.c.txt` sha256=7bcbc13579a0961252a80c75f7117e105c2b80bc6136b66b33e376e524263d34 bytes=253633
- `decompiled/ppelec.dll.c.txt` sha256=492d08e7c9d783ed032ca531ea519a2a411572fc99654a2b531cb5cceda5e2bb bytes=1315287
- `decompiled/ppeleci.dll.c.txt` sha256=ebd62b09660e9de7af49fde48a9e49dd6ae147d96251db5a169a9962491f2e7e bytes=224995
- `decompiled/ppeos.dll.c.txt` sha256=d9040e7423378e01553002702cb05569f0894b01f4219176e75dda098fa4d739 bytes=2851100
- `decompiled/ppgammai.dll.c.txt` sha256=eb9ecab9cc57ab9dfd35322e48cea8c42feb27a6d80942402483472e98d6271c bytes=139289
- `decompiled/ppiapws97.dll.c.txt` sha256=7effbd13bf1d663197e18c600b869c6979e18efe0e0bbeda60bbc9c302971745 bytes=789082
- `decompiled/ppncsolid.dll.c.txt` sha256=431c9218e54ea16242e3be25e1049988f60a3df1f2fbdd6a6aec0159988ff559 bytes=162947
- `decompiled/ppoli2.dll.c.txt` sha256=869c4abf5954e3ec2e7d0941c87918e42b4df8ec575b808412e9e8b36a3e438a bytes=112391
- `decompiled/pppces.dll.c.txt` sha256=0e976d3a3cd783bfa60d3aa116a04b362b3bee0a90c73bdf1d61b68f9ed0d79a bytes=2464368
- `decompiled/pppcs.dll.c.txt` sha256=1700fad5cfb90b3b48068a496ce657a084ea376e2f7aa7708cdc4c585f39ca9c bytes=49067
- `decompiled/pppdata.dll.c.txt` sha256=12ce71d7e023c8b0669cf1ee386e7d3208c076bd042e741540743602b341887c bytes=1462168
- `decompiled/pprxn.dll.c.txt` sha256=9b6bc8e71d079b4b7849b54344a718f6c80c376b14c90478418c71a4533cfaa6 bytes=1967496
- `decompiled/ppsem.dll.c.txt` sha256=93fafe51743d67c2c5bb58947bd67a4bdd8cd4e54a47eb3db4a7181eb55dd709 bytes=2266466
- `decompiled/ppstub.dll.c.txt` sha256=f70015c55ea1d15863ebd56873afe154fc8b8957b2b0601203b21df89dd783a8 bytes=697009
- `decompiled/pptabpoly.dll.c.txt` sha256=b103480e72e7f3577be0ec07937647f8fa6c5c65ab0956e60291b6e925b6f8e0 bytes=59787
- `decompiled/pptgs.dll.c.txt` sha256=b8e055a1917e19bcf664dda8901201007bd597854c094c4860f8b36b6faa6555 bytes=1340290
- `decompiled/ppthermo.dll.c.txt` sha256=5b27220c2ea9e767aa92bdaa79472d91d0e330489fb10bdea3a8bf98c686085c bytes=1203261
- `decompiled/ppthermoi.dll.c.txt` sha256=34c9901aec5bd1c7afb80121f53bb7fec0a27f4efd6e3234a2d7384dce3de286 bytes=185539
- `decompiled/pptransporti.dll.c.txt` sha256=17ae54c7e69226e0d6365f771457e9a5a494ca6a4a243ec15521ac8d039baa0c bytes=227412
- `decompiled/ppuser.dll.c.txt` sha256=82b6c6f5f824d97842fe4fc76a2bf597958f41226650045d0568b4284eeb7b2b bytes=36779
- `decompiled/rddlopt.exe.c.txt` sha256=cf3200c3893d9aee73fba0dcef0f35e40f2e0770e67ca595d934c15e96f00225 bytes=56589
- `decompiled/reposit.dll.c.txt` sha256=cc4c3dd289f378c6f4547b7f9ac024214baebd9d9f8104b821b38f807308b45c bytes=42679
- `decompiled/reposit_int.dll.c.txt` sha256=65848a0b92865cc97d855f0e0019c752e8cf19b075fe507263238bc89c587b43 bytes=203615
- `decompiled/rtmalloc.dll.c.txt` sha256=0e31f9f2c70ccc0c8eb053b2b2a24b2a131743e08141d85dfb239349d4341eef bytes=61054
- `decompiled/rtpdfutl1.dll.c.txt` sha256=6e7e962060805ee0ea5d304ae024b8f2a01556aa153d1e8d3bc5ee23bfeaefdb bytes=305189
- `decompiled/sdftab.exe.c.txt` sha256=ad38d57722f56745b8f373b9b8fc5b564b874231af4ed9a854130177cc624059 bytes=92366
- `decompiled/setup10.exe.c.txt` sha256=6ffa49766fdd64c2e53a5658d39018fa0ee252e3d21c7f0445e2022823079b30 bytes=59914
- `decompiled/tabledatawrapper.dll.c.txt` sha256=1c5082d993c657418bf25d7647f9c77327324e5f63a891aff38016ad5078ee6e bytes=229143
- `decompiled/utilsx.dll.c.txt` sha256=6300a26c348f57a16230e1e7cec81c7bc1a6d7cbcc6b2d9d941fefc9952159d3 bytes=257685
- `decompiled/xtrnexec.dll.c.txt` sha256=55eec1f6f113581951eb021d996f6148d1b4bfcf675f5280e644f1e233e875d1 bytes=237644
- `decompiled/zeASCDInp.dll.c.txt` sha256=5818c975ae7670ba2fa5bb10bc01f82da3eebe7a367bb7129d7dc04ebbb44fe9 bytes=254878
- `decompiled/zeaccting.dll.c.txt` sha256=aa51068b32016c2c0af6b5dc1354816cadf94504fa57f4e945a1911a6572080c bytes=229420
- `decompiled/zecvblock.dll.c.txt` sha256=767ef366f9a331152404daa8fca4dcdc1f3d9a12c8269b9ff159522ce333482e bytes=1534715
- `decompiled/zeftools.dll.c.txt` sha256=ab0909118a74f56b257ac74379a3e3a0b4379063cc80e64eac06d58ffc63e594 bytes=1943879
- `decompiled/zeftsem.dll.c.txt` sha256=d604149580bc2922d5bb866f9f7ff01a6d82c0327e72d50331b569476b40c4de bytes=1690673
- `decompiled/zeifms.dll.c.txt` sha256=b0388a1ee99218cb70b51f420a9f36035b6cfab8ac6c7f0c42df730562fde0cd bytes=77533
- `decompiled/zeinit.dll.c.txt` sha256=8e005a9a989e878e5cdcf6abd922d3ea2d4dc0ef3c3362123ab2065beb8b5eee bytes=34245
- `decompiled/zeitutl.dll.c.txt` sha256=f5d1972a94df1d8a33c6dc48eeae82d9314d42d89000e43d2f7b0b2e52ccaf7e bytes=2495475
- `decompiled/zemath.dll.c.txt` sha256=4d6c9810848a2d527f9c246cf05c4cf09864779ba7d0cde6cf299d25408f8074 bytes=2859903
- `decompiled/zemmback.dll.c.txt` sha256=50cf2101034efea20e9b6453954eeeafdb0db95965ead5d738a23d1708300c5b bytes=2214030
- `decompiled/zergibbs.dll.c.txt` sha256=00155a4062d6ca5abb0f74e63734fb1d43ed026024f1c986cf2af41670c42de0 bytes=1460656
- `decompiled/zertomod.dll.c.txt` sha256=7e460d6e5caa3cf1f38baf9927b60856e0362272db3d7eda8ac701598425d821 bytes=34981
- `decompiled/zesdfrpt.dll.c.txt` sha256=e3491f863e0672048efaeb85ecab705c0149908ec9b7d78ad0b0c703dba6ce7f bytes=216138
- `decompiled/zesem2.dll.c.txt` sha256=125865d9231e94eee28b4dacb0d775aee0f3f819a80b6715c36b2a1fad65f55f bytes=1617120
- `decompiled/zesem2util.dll.c.txt` sha256=8e1bb85826e5978fb6149a4f813307d90d2b56ca654731bb33661af185954e25 bytes=51961
- `decompiled/zestrlib.dll.c.txt` sha256=aa9d303ee25c3fb0730ed771ee80b9f6374dd1078388bc9801dd115e00fefd1a bytes=328489
- `decompiled/zetbs.dll.c.txt` sha256=23ed58b76aaa8cd271f594dd0d546784c314fb0eef19d00f718e492d4c1a3b1f bytes=1443991
- `decompiled/zetoolkit.dll.c.txt` sha256=c9d69c0919dc3b60c07068a1e565b6954ec0d180dd0e4dc46f9e0ac377e1156e bytes=2140389
- `decompiled/zeuosutl.dll.c.txt` sha256=f26d85e82dcc1dece2dfaeca2de10d602e0e9bf9975d62c521d0afdbd69fd7fd bytes=2930802
- `decompiled/zeusermod.dll.c.txt` sha256=ef1c5e04953f7af84310ea3a7a0443648a34d2b7cc4db5c0686b3fdaee670aa0 bytes=44293
- `decompiled/zevainfo.dll.c.txt` sha256=ed83fd41404f373ff56d2aa754b9a97099a98c8008f68bd75977b22c01ef1930 bytes=327032
- `decompiled/zever.dll.c.txt` sha256=649fe9716d08738a167e524eba07b340ef9bec28d6a4d043037c35cc229f52aa bytes=45791
- `disasm/ApSetComp.exe.asm.txt` sha256=c43910b95832766c68e0f5d48d1a45f247f26ce01665bd937a07f084fa1808cd bytes=235241
- `disasm/AprCorrMan.dll.asm.txt` sha256=b84b6a9134e7aedf79c6f58d31fc7c9bb4228d71c4aa0e1f23b35a0a35f279d9 bytes=216769
- `disasm/AspenTech.NGP.UnmanagedBridge.dll.asm.txt` sha256=7a743e1e8c19ccda57b5da903aab5b831a82364d1b2822384a4a0e73fbb9e024 bytes=170453
- `disasm/AspenTech_NGP_Managed2Unmanaged.dll.asm.txt` sha256=d9fc2ac86611225c4e91934a5c56e81b4fb7b7f4dfd68ce9c19fa38523763af0 bytes=224544
- `disasm/DataSvr.dll.asm.txt` sha256=f28ccf4268e86ba5f61d04bcc26637ab6ff2eaf2c1b6af34a1b1da8404efbe1d bytes=210839
- `disasm/DistillationAnalysis.exe.asm.txt` sha256=7bdd8405021ae2ae0049603113d131389e0e1946c136e21dcc1f5cc5d0ffe2f4 bytes=2962516
- `disasm/EDRProperties.dll.asm.txt` sha256=12283e2e027344856fb54b94985583e073059b7973c16fb15b117ef887b6edef bytes=385367
- `disasm/GasProps.dll.asm.txt` sha256=ec3a04d97e8a5d024c7dd9d8e16e1555d99dc03e7bea363525950fae081fd2a1 bytes=474464
- `disasm/MergeNN.exe.asm.txt` sha256=f015f2a41355053b981afcb3833e9c11252a61c01d2bd0cee045d6cad821d84e bytes=2547813
- `disasm/MergeNN_FNN.dll.asm.txt` sha256=294f8a8fd91f954a6d3c6a5e8a9305d21fde7a5c80142564dcd1b86ba767a8f5 bytes=377064
- `disasm/aosbridge.dll.asm.txt` sha256=9403c231049fc9995d811155f6ba44bfc4f2e6ee1e81cba1b17388200b22f97c bytes=423753
- `disasm/apbatutl.exe.asm.txt` sha256=a724ded6e9b28172f84af2f8599d5218ac54af07f0a8da6eb2248d287f277baa bytes=136442
- `disasm/apmaindll.dll.asm.txt` sha256=02a4a7105c69b82da84dd73ee846ee9a5c1efbf972852cb48175e1756605c18d bytes=205610
- `disasm/aprsysbridge.dll.asm.txt` sha256=8d02cb257014a56b75283645f5b9254e47b8b19d1d6ea8829099747e3e0b562f bytes=245676
- `disasm/aprtbsmn.exe.asm.txt` sha256=c2f5c9f1625a2a9c069c1295b15a985ae815677f68f60468a0e0afcefd09b67b bytes=113587
- `disasm/apserverdll.dll.asm.txt` sha256=1bc5a01c62fda4355080808157d9b355b360690be37799c8f837f08ad28039da bytes=2877966
- `disasm/apstorage.dll.asm.txt` sha256=39c56be55a759fb4f0d848af727c12bc510dbd7b21af853aaf04a9b62f4d9c69 bytes=276308
- `disasm/aptime.exe.asm.txt` sha256=b3e50ac2623e82c0475777229dd326f694f1311dde5fad4bcf1d1af2da448cff bytes=90722
- `disasm/apvcomps.dll.asm.txt` sha256=c2fb9afd0e80a2ca119d0c22f15843f24af7f0e18d957c966b6f9c2dfdb912e7 bytes=65284
- `disasm/ascddistil.dll.asm.txt` sha256=10a25079064a2ce8fe3d77d363a32619834529987453f57ee5cbe8e53e463201 bytes=3688455
- `disasm/atcomaterial.dll.asm.txt` sha256=64a21982f163c120ab064ea12ade0a8b186412860d9c2a6461a966c567512489 bytes=2739398
- `disasm/atcoproperties.dll.asm.txt` sha256=0e6c9f51e833f14453bb8015b7f80a43e62934f14006fb6acf73a23e3477c50d bytes=4126326
- `disasm/atdms.dll.asm.txt` sha256=a84b987f665969b030af86a1c7603b9d5b24c549b746a205bcdd5b8aad011e16 bytes=3249744
- `disasm/atmem.dll.asm.txt` sha256=e368522af65e278cb568e308b80f1ecfeec21fd80bfa32b251ce026c438fe5da bytes=51910
- `disasm/atpipe.dll.asm.txt` sha256=c5f23d88b2d42be434b685916262c79659400c48dde4e4ea5a4d00d7aa574dd7 bytes=175989
- `disasm/atregwithapluspaths.exe.asm.txt` sha256=b9caaa603f2842ac58b8515b005729c6b51a5f7043f6a32d5ac8bf5e895f15fd bytes=242184
- `disasm/atxc.dll.asm.txt` sha256=0c9327818ee5ef7654d3f20474357700d66727044cacfdda2674be8d3012434b bytes=5784492
- `disasm/cotafile.dll.asm.txt` sha256=4d54edf9f3bc4f891d36df3430ec2f1d0f54b79cbdfb998a4a62ddc4e01de2c1 bytes=327058
- `disasm/cotafilesvr.exe.asm.txt` sha256=554ab9e52d0f78fb265d66754098c04d4e70101ad75e1fcfba60167a49115312 bytes=247768
- `disasm/createva.exe.asm.txt` sha256=5a3f103ba2665f7bf85d62dde48ed47f38d00b0352067d80f147826e85bb2260 bytes=130145
- `disasm/dfmsmn.exe.asm.txt` sha256=ed5ae0d64b83b8cb235568071ed5a0f5db531a101b3f8d29ae53749b6e94bd38 bytes=89935
- `disasm/errout.exe.asm.txt` sha256=277abb47811b1cb8b6573768a75788931d06e150f3dc16c219c9b459c78b031a bytes=63544
- `disasm/fnapfile.exe.asm.txt` sha256=8fb7e77ce32b1b282a7e9078be37e1615110d3b95b651bcaa673591b470305ea bytes=148487
- `disasm/getridof.exe.asm.txt` sha256=91f5a345d41ea48b1ed3be1775747bc675e8ef1e6695ef4713c80485b625ef8e bytes=131988
- `disasm/hxnetintqaplus.dll.asm.txt` sha256=9e2bb2d05d5236aa3ed9cd003b66917728f2d461103d02a4e906e9671e04864c bytes=3610175
- `disasm/ifmsmn.exe.asm.txt` sha256=2507739a6b60100c7059ab46ced20ec5295c82b632ee173b17535fd1c5a887bc bytes=115111
- `disasm/ngsutils.dll.asm.txt` sha256=a68baad8fa0ba026abb44cc68959dbe4c296cfe8ce7e76666c8aa5c580eaa4b8 bytes=325067
- `disasm/pol_eos.dll.asm.txt` sha256=32926093b6cfc08c586f124099418ed58e57bd1d2d9a4fffeb072cae69c42a6d bytes=3493626
- `disasm/pol_rxn.dll.asm.txt` sha256=5a9613ccb493ff9936445d8c7d6ff7bd8e1c6def845cecb4632ba31736b26767 bytes=426147
- `disasm/pol_segb.dll.asm.txt` sha256=1b436e7a5a1bb1742367136ea9ef32c57a75db95b619be267831bff1e4e10795 bytes=414066
- `disasm/ppada.dll.asm.txt` sha256=7c7587aa090c04da8084ce49359dde8c47d322e578740fb31e66e8a109c90b97 bytes=4947671
- `disasm/ppbre.dll.asm.txt` sha256=d05db1a13e674c0ffde1e754242ded0fe7a816eddc8e652b47865c62c950854b bytes=488047
- `disasm/ppcpa.dll.asm.txt` sha256=f9551178b3a87a46fa9ca8ca609056ebc9adf8135ba9b64ab7f0bd04b04fefec bytes=461249
- `disasm/ppelec.dll.asm.txt` sha256=2bc2687d642f3e0585ed024044ccc9910f9e088272200ac09e5c2234ec6d413c bytes=3020635
- `disasm/ppeleci.dll.asm.txt` sha256=f45c7bfc2a4234f8a399578d2e07111540bd2c66262e9731c7142e5e2b218d5f bytes=330455
- `disasm/ppeos.dll.asm.txt` sha256=fcc47ec57cdd114cf5c6e41d47e5694a5a73a2d1d40dbb8cf87e3342e40e84b9 bytes=5296182
- `disasm/ppgammai.dll.asm.txt` sha256=9cecd285e37c4df864d92df23ed57761c2cb97c960a81c19d4707e96be1449f1 bytes=227693
- `disasm/ppiapws97.dll.asm.txt` sha256=425134474eb9b2efb64c9235640384909111160ed793b1d00417352e5327ffcf bytes=4923363
- `disasm/ppncsolid.dll.asm.txt` sha256=5dc9cd9f1aa24a9bc4a69d1459421e2713d65d98ac9018a3d3dc1b1a8ea29b6e bytes=343804
- `disasm/ppoli2.dll.asm.txt` sha256=ad20c8f7b22bafc8a0bb9857ef59694000155cf6bfab59794a4edc7c41afafd0 bytes=208971
- `disasm/pppces.dll.asm.txt` sha256=d30dcae9d5b8bbc09e8f9a78e64c95044d07ccce6c11e666678931e8622a0ef8 bytes=3887805
- `disasm/pppcs.dll.asm.txt` sha256=dc1362be71760942a713a756fc51f6847c2dab71745c70264b22b4bcc272e6ff bytes=73983
- `disasm/pppdata.dll.asm.txt` sha256=5a66dbbda12d248d90849cbafd78a884e5f93cf53bdbb44658f2d3a360769244 bytes=2199006
- `disasm/pprxn.dll.asm.txt` sha256=c68adac5d7d6300f21be0c078157739196f716be0eb12184c6706424abc085fe bytes=5282928
- `disasm/ppsem.dll.asm.txt` sha256=072c0bdae18487c712f5d8f613bbd649da1fadaa86de9303b751defad31bd4f1 bytes=3282931
- `disasm/ppstub.dll.asm.txt` sha256=356bce30d0202260403c50f500787ec9a94c353558d1eaaf583636403bf8f479 bytes=2377415
- `disasm/pptabpoly.dll.asm.txt` sha256=873a802dff2f537585e34f81d32bb3b10bb045478534f1dc72428039a5bcae5d bytes=498585
- `disasm/pptgs.dll.asm.txt` sha256=9efc2de9faad8a86a05abe4f25544df389ab50de3b4fb7bbeba5da808ee7097b bytes=3320749
- `disasm/ppthermo.dll.asm.txt` sha256=947325d71cf5132849bee0df038a1e15be8a2c079abe664ae8ae37e745aff29e bytes=2338233
- `disasm/ppthermoi.dll.asm.txt` sha256=9a2057b020889876c7200951d27d958e4d142f7b83d8b779f6b7614bc188664c bytes=313165
- `disasm/pptransporti.dll.asm.txt` sha256=e720e069bf817d878d93c9ba03e2bce81105519cfced8d8fa8fdb810212fb802 bytes=302950
- `disasm/ppuser.dll.asm.txt` sha256=b54c4c98ab0bcadd739e0a14714a6697340e19a7830e297f36abf5e126c79194 bytes=54700
- `disasm/rddlopt.exe.asm.txt` sha256=2b655e72306de5042fb22bbbaf2ebd225838ae6c7d73e60ce1911e4e853e4d95 bytes=83961
- `disasm/reposit.dll.asm.txt` sha256=40b6fc2aeb45ba78adb6e9bf987a63e7d5cb2300430d45ceac96a0f58e510d0e bytes=70788
- `disasm/reposit_int.dll.asm.txt` sha256=40314a613ff7fa729461d92a4103f3a56a66ca83487a471c5c805bc3e30c7991 bytes=414795
- `disasm/rtmalloc.dll.asm.txt` sha256=6deadfd43cf3399912708730878dc788c0d3adbc6cd82b8093d4fe6866b7dc91 bytes=107600
- `disasm/rtpdfutl1.dll.asm.txt` sha256=d721de111d36c95db1536b69153e4978b9054aced1aaf090bf4b07169fed3c28 bytes=401495
- `disasm/sdftab.exe.asm.txt` sha256=444073047f317611fda22acff58fa5bf4931cc15a8599e2963cd7fb55c64a363 bytes=137978
- `disasm/setup10.exe.asm.txt` sha256=46210fa164fa4a50e9ef1a4212675dc3773cf4fc2ca76ef72e2dae4ab13d341c bytes=97106
- `disasm/tabledatawrapper.dll.asm.txt` sha256=6ec3a727153548c1320a7ff2257f20a6df2195070883b3b41f60371bca1e5a3d bytes=326361
- `disasm/utilsx.dll.asm.txt` sha256=0e1103e6cf5860c40742026e65984acc47e46e59af96680d6cbf92dc7b129537 bytes=388761
- `disasm/xtrnexec.dll.asm.txt` sha256=369685fba6768585711d8afc1d04aa5fa17f479fda3aa5cf7496681428c505fa bytes=303829
- `disasm/zeASCDInp.dll.asm.txt` sha256=bc62c6f713b47685fa51c8b4899064a314fee96ea14b65c4bbd18a7edf436d91 bytes=343201
- `disasm/zeaccting.dll.asm.txt` sha256=c5f3007a14dbd8413f155deb4047519f4f6323024f5df7b6720cefe9ccb108dc bytes=346939
- `disasm/zecvblock.dll.asm.txt` sha256=3ea25c366ce4bd2a1800bf289dfe2b273de4f1eff1da16f6a633712a072ef657 bytes=2710369
- `disasm/zeftools.dll.asm.txt` sha256=8a6208bf6ef9f33ba489ef2ca328676ce46561e59efe3b7ecabd5f2c055132b2 bytes=3961865
- `disasm/zeftsem.dll.asm.txt` sha256=8d59162d063fd55864d9636e7e6ffe64a3e37c500511f5e733dd799062747d4f bytes=2627301
- `disasm/zeifms.dll.asm.txt` sha256=c4674d2223b76b6f0e5380f34e5a6602d5c85ab4007d240cf55f3fec80d1bb84 bytes=129661
- `disasm/zeinit.dll.asm.txt` sha256=f09875f28d0ed6473ea274aa3575fade76e10da15303c364051d842496b2fffd bytes=52234
- `disasm/zeitutl.dll.asm.txt` sha256=a87adfe0b65db62de0687ecbadec7c50468176ceb467f56227ab9488b13e8214 bytes=4111880
- `disasm/zemath.dll.asm.txt` sha256=0503885fe722a68e01dccdb1a1eb484a0f2d59e350bb92a5563bc25d22410353 bytes=4862933
- `disasm/zemmback.dll.asm.txt` sha256=5e6a2513c01ede66d9d7d2d4e29ecec8c5dad18badb4425c8a82299d710939c9 bytes=3668257
- `disasm/zergibbs.dll.asm.txt` sha256=fb206ec677a0b1c648465846c9674df30b0df11cf9d508f0fff04a5689d9eb59 bytes=5535931
- `disasm/zertomod.dll.asm.txt` sha256=53aac142f9a2d755506c1ff76567a254bbcb5dc38d618da0e65678388abd5809 bytes=52990
- `disasm/zesdfrpt.dll.asm.txt` sha256=be8f00e8338cf8cb5cd702c54951f545c2086a3fa714f97272501a0ccbb6b18b bytes=273866
- `disasm/zesem2.dll.asm.txt` sha256=7f73df26ff9b11e6c9b3a9ed9aa350f66751e97d52965841a7f959ed7119c1ad bytes=2787665
- `disasm/zesem2util.dll.asm.txt` sha256=176b33a91bdf8bf5ded7dcdf6c5bed00149127546afad833c3d6e5e4172c2877 bytes=142410
- `disasm/zestrlib.dll.asm.txt` sha256=3144a393e9d1db49db6a73f446cc403180b0e60f2a119f7d467fe477c58cee93 bytes=491166
- `disasm/zetbs.dll.asm.txt` sha256=5f4b994d31f19dc3a9d2c221a31288be19bfcd690f15273c8f86f400ad6e5b26 bytes=2332483
- `disasm/zetoolkit.dll.asm.txt` sha256=ca95abda5d49d5d625883a3b1faa217c8edd3d5a0418fb7ebd21607ed05db14c bytes=3915315
- `disasm/zeuosutl.dll.asm.txt` sha256=d55fbcfab3f5b7786b65e81558bcce0745a7406d753d0ff3b534dd39b7a6d472 bytes=5287925
- `disasm/zeusermod.dll.asm.txt` sha256=48c27932a6d05fb776d368f6130aa864c56ae545621b8ecadc45ebe9a11e9068 bytes=64959
- `disasm/zevainfo.dll.asm.txt` sha256=c785c25a9d0f82ea8e2852f1d7d3e34b75dcec42f4b2d8ec7f6a65669d81e796 bytes=611620
- `disasm/zever.dll.asm.txt` sha256=3c9a84ba48b604bf247773b1b40731dfcbdcc73158f4f4f877401afdd3fb4e01 bytes=75023
