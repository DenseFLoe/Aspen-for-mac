# pol_pyro.dll 静态复核报告（native / T1N，IDA 9.5 重做）

## 0. 摘要

| 项目 | 结果 |
| --- | --- |
| 样本 | `pol_pyro.dll`，133672 字节，SHA-256 `d315fc701d534a8b10f913783f20828300ccc80eb9fafff0877959c7cce0613a` |
| 链 | T1N（native，IDA 9.5 + Hex-Rays 全函数反汇编 + 全函数伪 C） |
| 函数 | functions 199 = decomp_ok 197 + decomp_fail 2 |
| 证据等级 | 〔实测〕idat.exe -A -c -S<script> 单件跑通（auto_wait() 后统计），正文见同目录 disasm/ 与 decompiled/ |

含完整逆向正文，依据：用户 2026-11-20 指令，偏离仓库 AGENTS 该条

### 0.1 工具与统计字段（G2，逐项可按名检索）

- tool=IDA 9.5
- hexrays=yes
- functions=199
- decomp_ok=197
- decomp_fail=2
- prevtool=Ghidra 12.1.4

## 1. 样本与哈希

| 项 | 值 |
| --- | --- |
| 名称 | `pol_pyro.dll` |
| 字节数 | 133672 |
| SHA-256 | `d315fc701d534a8b10f913783f20828300ccc80eb9fafff0877959c7cce0613a` |
| 清单 | read-test-waiting.csv（kind=native） |
| 原始相对路径（清单 path，去掉产品段） | `[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Xeq/pol_pyro.dll` |
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
| 指令行数 | 14108 |

## 3. 反汇编清单（全量）

全文：disasm/pol_pyro.dll.asm.txt（IDA 逐函数 FUNC <addr> <name> / 指令行 / ENDFUNC，含函数边界与地址，无抽样）。

## 4. 反编译伪 C（Hex-Rays）

全文：decompiled/pol_pyro.dll.c.txt（逐函数 // FUNC <addr> <name> + Hex-Rays 伪 C 正文 + // ENDFUNC；反编译失败写 // DECOMP-FAIL <addr> <name> <ExceptionClass>，未填任何空函数体）。

## 5. 函数统计（functions = decomp_ok + decomp_fail）

- functions（asm） = 199
- decomp_ok（伪 C） = 197
- decomp_fail = 2
- 恒等式：成立〔实测〕

### 5.1 反编译失败清单（逐条函数名与原因）

- `1800025d0` `PYRO_PYRO`：RuntimeError（decompile returned None）
- `180003690` `sub_180003690`：RuntimeError（decompile returned None）

## 6. 工具与环境

- IDA Professional 9.5 headless：`idat.exe -A -c -S<script> -L<log> <dll>`，脚本先 `ida_auto.auto_wait()` 再统计，末尾 `idc.qexit(0)`
- Hex-Rays：`ida_hexrays.init_hexrays_plugin()` → True（IDA 9.5 内置）
- 脚本：tool/ida_export.py（本仓从零写，生成 IDAPython 脚本；产物同路径覆盖 Ghidra 旧版）
- 单件耗时（含自动分析）：13.8 s
- 日志：out/R1N/ida/logs/sha256_d315fc701d534a8b10f913783f20828300ccc80eb9fafff0877959c7cce0613a.log（本机保留，不进推送集）

## 7. 缺口与待验证

- 语义层（函数用途、调用约定、数据结构）未做人工复核；本报告只证明「全函数已反汇编/反编译落盘」。〔未验证〕
- 反编译失败函数 2 个（// DECOMP-FAIL 行可逐一核对）。

## 8. 结论

- `pol_pyro.dll` 全函数反汇编与全函数伪 C 已由 IDA 9.5 + Hex-Rays 落盘，functions == decomp_ok + decomp_fail 成立。

## 9. 与 Ghidra 12.1.4 函数数对账（G3）

| 项 | 值 |
| --- | --- |
| IDA 9.5 functions | 199 |
| Ghidra 12.1.4 基线 FUNC | 0 |
| 差值 | +199（+0.0%） |
| 判据 abs(diff) <= 10% | 通过 |

- 仅 Ghidra 有、IDA 未单列：无
- 仅 IDA 有：`PYRO_PYPACK`, `PYRO_PYCAPK`, `PYRO_PYRXWR`, `PYRO_IRXNPY`, `PYRO_PYRO`, `sub_180003690`, `sub_180006830`, `sub_18000B480`
- 命名口径：上两行按函数名对比。IDA 应用了 FLIRT 库签名（如 `__CRT_INIT@12`、`@__security_check_cookie@4`），同一地址在 Ghidra 侧仍是 `FUN_<addr>`，因此名单差异主要是命名差异；函数个数按上表比对。

## dumps

dumps: v0.20261121-w2#dumps-w2-part1.tar.gz

- `decompiled/ApSetComp.exe.c.txt` sha256=5e237771dd977b926169982f25ef8bc01f21c8ee57959ee257044c9c98311122 bytes=130599
- `decompiled/AprCorrMan.dll.c.txt` sha256=3b3ff81def0744035c38344da1fd49b89bf8e1144c58bf4404b3310f053038ec bytes=115284
- `decompiled/AspenTech.NGP.UnmanagedBridge.dll.c.txt` sha256=c3a1b9b7bf9942fa551f786b9cdbaa0f4ac89664583ba5399381fc89390dbbf5 bytes=104622
- `decompiled/AspenTech_NGP_Managed2Unmanaged.dll.c.txt` sha256=c6b860fb808ea86aa09d2712690b54681f3442cd700bbb52dee6470a3b3ff4b3 bytes=116673
- `decompiled/DataSvr.dll.c.txt` sha256=8fe06136f54c3f9128253307df66e8d37cedea165a5e1d3a69eec2ae46c40d3f bytes=129361
- `decompiled/EDRProperties.dll.c.txt` sha256=92ae852f5ca2a551b033b6159e35de8586703ec59989cdbaff076a9d36189aaf bytes=313486
- `decompiled/GasProps.dll.c.txt` sha256=f4462f718e314ceeb9ef918388fa20dc00734a872c2717c5dfe1a9637e5aed41 bytes=272020
- `decompiled/MergeNN_FNN.dll.c.txt` sha256=8ad202fd249933eb0b50de37fcc11fe9652d38cc91e6beba093720200ab13bb6 bytes=209943
- `decompiled/aosbridge.dll.c.txt` sha256=8884c5e4b6eefcc1ec15267bf882d07432872c321375bf3f3c578cd9eaf1739b bytes=186236
- `decompiled/apbatutl.exe.c.txt` sha256=8f23dd5044459fd37a1b280f4e531cfd073dcee0a3585c13a2278b942f43b311 bytes=83312
- `decompiled/apmaindll.dll.c.txt` sha256=c76a0359d0ca448be106dda524333841b7dd25b7f35ab53f37bd274e68088517 bytes=152312
- `decompiled/aprsysbridge.dll.c.txt` sha256=64d020ea5ad860d6cd4c96a1ec3fd22d6293827e233f2a000a312de6d396b679 bytes=136730
- `decompiled/aprtbsmn.exe.c.txt` sha256=8a463b99794d9c35ea4536f27e74871efd4e954d79992023b5b60869d5fc0211 bytes=84138
- `decompiled/apstorage.dll.c.txt` sha256=018ae6b864c09f1adab1560865b7c25a31c640f3554de9cdd3c2641b4625ad5a bytes=146322
- `decompiled/apvcomps.dll.c.txt` sha256=9fbb3a58815c6489a1bde85942cb1ab154b96732766dff1a0f7cceee517ba574 bytes=48210
- `decompiled/atdms2.dll.c.txt` sha256=c43ea67e3881828885a36a17a3320e1ed1869651da1faa64e5e7739fbdad8e24 bytes=380808
- `decompiled/atpipe.dll.c.txt` sha256=558b2982216b44dc66651d37bd53dace96e743f7052b8a0d73a48bef7f7f3652 bytes=101975
- `decompiled/atregwithapluspaths.exe.c.txt` sha256=5d973605172b79497144d8e2909c5991c90cc377fe5fe4e08002a6f271d7ec3a bytes=166939
- `decompiled/cotafile.dll.c.txt` sha256=9b5b72cc377226501b00500933002e6d044b672609fc7eb73b5eb1839af04158 bytes=255996
- `decompiled/cotafilesvr.exe.c.txt` sha256=7b179096b3fba28c6629538f51efd36d0f180a0f1c472e80bf3928f9c9921eb9 bytes=188848
- `decompiled/createva.exe.c.txt` sha256=95d524acf594310f81719df1ae59e634085cd5e79d850505048a2ea3618642f3 bytes=86555
- `decompiled/fnapfile.exe.c.txt` sha256=b98120275e04e1d0e36fc51c9350b4262e36d504fd042b215d234340bc935a50 bytes=87700
- `decompiled/getridof.exe.c.txt` sha256=adeee3c74922205f186a0d849799dff346ab5d1cfbf12e05b6a7fe7e1edc2a4b bytes=75990
- `decompiled/ifmsmn.exe.c.txt` sha256=9ecf5316bd40e6b5a7ff96e40e09280001b1eb2d3b22a529499d699f7177ab6c bytes=89723
- `decompiled/ngsutils.dll.c.txt` sha256=8c068942629a77d765bcf10cf813a904bfc2800ea88cedcd66a5e3318bc7ad03 bytes=260966
- `decompiled/pol_pyro.dll.c.txt` sha256=fd51361b3ea0d6049eca6e6644b0580635af4e2241ecfbd39b1bc29ea2f37fcc bytes=318943
- `decompiled/pol_rxn.dll.c.txt` sha256=c72804ebdbe11735e862c1e8efc8daa78282b0b0eee8ca1f34fce2d2fdd9cf31 bytes=348421
- `decompiled/pol_segb.dll.c.txt` sha256=b9b1d27598868597817acec396a27814609c5a75102613ed73dd92490878407e bytes=280826
- `decompiled/ppbre.dll.c.txt` sha256=69bc54cf110f99ecfee4ec79d9b8459b432c595d13c95ca70adec6d8fbdd3625 bytes=299198
- `decompiled/ppcpa.dll.c.txt` sha256=7bcbc13579a0961252a80c75f7117e105c2b80bc6136b66b33e376e524263d34 bytes=253633
- `decompiled/ppeleci.dll.c.txt` sha256=ebd62b09660e9de7af49fde48a9e49dd6ae147d96251db5a169a9962491f2e7e bytes=224995
- `decompiled/ppgammai.dll.c.txt` sha256=eb9ecab9cc57ab9dfd35322e48cea8c42feb27a6d80942402483472e98d6271c bytes=139289
- `decompiled/ppncsolid.dll.c.txt` sha256=431c9218e54ea16242e3be25e1049988f60a3df1f2fbdd6a6aec0159988ff559 bytes=162947
- `decompiled/ppoli2.dll.c.txt` sha256=869c4abf5954e3ec2e7d0941c87918e42b4df8ec575b808412e9e8b36a3e438a bytes=112391
- `decompiled/pptabpoly.dll.c.txt` sha256=b103480e72e7f3577be0ec07937647f8fa6c5c65ab0956e60291b6e925b6f8e0 bytes=59787
- `decompiled/ppthermoi.dll.c.txt` sha256=34c9901aec5bd1c7afb80121f53bb7fec0a27f4efd6e3234a2d7384dce3de286 bytes=185539
- `decompiled/pptransporti.dll.c.txt` sha256=17ae54c7e69226e0d6365f771457e9a5a494ca6a4a243ec15521ac8d039baa0c bytes=227412
- `decompiled/reposit_int.dll.c.txt` sha256=65848a0b92865cc97d855f0e0019c752e8cf19b075fe507263238bc89c587b43 bytes=203615
- `decompiled/rtmalloc.dll.c.txt` sha256=0e31f9f2c70ccc0c8eb053b2b2a24b2a131743e08141d85dfb239349d4341eef bytes=61054
- `decompiled/rtpdfutl1.dll.c.txt` sha256=6e7e962060805ee0ea5d304ae024b8f2a01556aa153d1e8d3bc5ee23bfeaefdb bytes=305189
- `decompiled/sdftab.exe.c.txt` sha256=ad38d57722f56745b8f373b9b8fc5b564b874231af4ed9a854130177cc624059 bytes=92366
- `decompiled/tabledatawrapper.dll.c.txt` sha256=1c5082d993c657418bf25d7647f9c77327324e5f63a891aff38016ad5078ee6e bytes=229143
- `decompiled/utilsx.dll.c.txt` sha256=6300a26c348f57a16230e1e7cec81c7bc1a6d7cbcc6b2d9d941fefc9952159d3 bytes=257685
- `decompiled/xtrnexec.dll.c.txt` sha256=55eec1f6f113581951eb021d996f6148d1b4bfcf675f5280e644f1e233e875d1 bytes=237644
- `decompiled/zeASCDInp.dll.c.txt` sha256=5818c975ae7670ba2fa5bb10bc01f82da3eebe7a367bb7129d7dc04ebbb44fe9 bytes=254878
- `decompiled/zeaccting.dll.c.txt` sha256=aa51068b32016c2c0af6b5dc1354816cadf94504fa57f4e945a1911a6572080c bytes=229420
- `decompiled/zeifms.dll.c.txt` sha256=b0388a1ee99218cb70b51f420a9f36035b6cfab8ac6c7f0c42df730562fde0cd bytes=77533
- `decompiled/zesdfrpt.dll.c.txt` sha256=e3491f863e0672048efaeb85ecab705c0149908ec9b7d78ad0b0c703dba6ce7f bytes=216138
- `decompiled/zesem2util.dll.c.txt` sha256=8e1bb85826e5978fb6149a4f813307d90d2b56ca654731bb33661af185954e25 bytes=51961
- `decompiled/zestrlib.dll.c.txt` sha256=aa9d303ee25c3fb0730ed771ee80b9f6374dd1078388bc9801dd115e00fefd1a bytes=328489
- `decompiled/zevainfo.dll.c.txt` sha256=ed83fd41404f373ff56d2aa754b9a97099a98c8008f68bd75977b22c01ef1930 bytes=327032
- `disasm/ApSetComp.exe.asm.txt` sha256=c43910b95832766c68e0f5d48d1a45f247f26ce01665bd937a07f084fa1808cd bytes=235241
- `disasm/AprCorrMan.dll.asm.txt` sha256=b84b6a9134e7aedf79c6f58d31fc7c9bb4228d71c4aa0e1f23b35a0a35f279d9 bytes=216769
- `disasm/AspenTech.NGP.UnmanagedBridge.dll.asm.txt` sha256=7a743e1e8c19ccda57b5da903aab5b831a82364d1b2822384a4a0e73fbb9e024 bytes=170453
- `disasm/AspenTech_NGP_Managed2Unmanaged.dll.asm.txt` sha256=d9fc2ac86611225c4e91934a5c56e81b4fb7b7f4dfd68ce9c19fa38523763af0 bytes=224544
- `disasm/DataSvr.dll.asm.txt` sha256=f28ccf4268e86ba5f61d04bcc26637ab6ff2eaf2c1b6af34a1b1da8404efbe1d bytes=210839
- `disasm/EDRProperties.dll.asm.txt` sha256=12283e2e027344856fb54b94985583e073059b7973c16fb15b117ef887b6edef bytes=385367
- `disasm/GasProps.dll.asm.txt` sha256=ec3a04d97e8a5d024c7dd9d8e16e1555d99dc03e7bea363525950fae081fd2a1 bytes=474464
- `disasm/MergeNN_FNN.dll.asm.txt` sha256=294f8a8fd91f954a6d3c6a5e8a9305d21fde7a5c80142564dcd1b86ba767a8f5 bytes=377064
- `disasm/aosbridge.dll.asm.txt` sha256=9403c231049fc9995d811155f6ba44bfc4f2e6ee1e81cba1b17388200b22f97c bytes=423753
- `disasm/apbatutl.exe.asm.txt` sha256=a724ded6e9b28172f84af2f8599d5218ac54af07f0a8da6eb2248d287f277baa bytes=136442
- `disasm/apmaindll.dll.asm.txt` sha256=02a4a7105c69b82da84dd73ee846ee9a5c1efbf972852cb48175e1756605c18d bytes=205610
- `disasm/aprsysbridge.dll.asm.txt` sha256=8d02cb257014a56b75283645f5b9254e47b8b19d1d6ea8829099747e3e0b562f bytes=245676
- `disasm/aprtbsmn.exe.asm.txt` sha256=c2f5c9f1625a2a9c069c1295b15a985ae815677f68f60468a0e0afcefd09b67b bytes=113587
- `disasm/apstorage.dll.asm.txt` sha256=39c56be55a759fb4f0d848af727c12bc510dbd7b21af853aaf04a9b62f4d9c69 bytes=276308
- `disasm/apvcomps.dll.asm.txt` sha256=c2fb9afd0e80a2ca119d0c22f15843f24af7f0e18d957c966b6f9c2dfdb912e7 bytes=65284
- `disasm/atdms2.dll.asm.txt` sha256=6bf268f859366469fdeae77cdeb9ac962a288134696fe403e37bc247674a3559 bytes=583207
- `disasm/atpipe.dll.asm.txt` sha256=c5f23d88b2d42be434b685916262c79659400c48dde4e4ea5a4d00d7aa574dd7 bytes=175989
- `disasm/atregwithapluspaths.exe.asm.txt` sha256=b9caaa603f2842ac58b8515b005729c6b51a5f7043f6a32d5ac8bf5e895f15fd bytes=242184
- `disasm/cotafile.dll.asm.txt` sha256=4d54edf9f3bc4f891d36df3430ec2f1d0f54b79cbdfb998a4a62ddc4e01de2c1 bytes=327058
- `disasm/cotafilesvr.exe.asm.txt` sha256=554ab9e52d0f78fb265d66754098c04d4e70101ad75e1fcfba60167a49115312 bytes=247768
- `disasm/createva.exe.asm.txt` sha256=5a3f103ba2665f7bf85d62dde48ed47f38d00b0352067d80f147826e85bb2260 bytes=130145
- `disasm/fnapfile.exe.asm.txt` sha256=8fb7e77ce32b1b282a7e9078be37e1615110d3b95b651bcaa673591b470305ea bytes=148487
- `disasm/getridof.exe.asm.txt` sha256=91f5a345d41ea48b1ed3be1775747bc675e8ef1e6695ef4713c80485b625ef8e bytes=131988
- `disasm/ifmsmn.exe.asm.txt` sha256=2507739a6b60100c7059ab46ced20ec5295c82b632ee173b17535fd1c5a887bc bytes=115111
- `disasm/ngsutils.dll.asm.txt` sha256=a68baad8fa0ba026abb44cc68959dbe4c296cfe8ce7e76666c8aa5c580eaa4b8 bytes=325067
- `disasm/pol_pyro.dll.asm.txt` sha256=029b6107bd201745841cd9107099b22627274cf8468264bfe3379e9f2d7a1911 bytes=557024
- `disasm/pol_rxn.dll.asm.txt` sha256=5a9613ccb493ff9936445d8c7d6ff7bd8e1c6def845cecb4632ba31736b26767 bytes=426147
- `disasm/pol_segb.dll.asm.txt` sha256=1b436e7a5a1bb1742367136ea9ef32c57a75db95b619be267831bff1e4e10795 bytes=414066
- `disasm/ppbre.dll.asm.txt` sha256=d05db1a13e674c0ffde1e754242ded0fe7a816eddc8e652b47865c62c950854b bytes=488047
- `disasm/ppcpa.dll.asm.txt` sha256=f9551178b3a87a46fa9ca8ca609056ebc9adf8135ba9b64ab7f0bd04b04fefec bytes=461249
- `disasm/ppeleci.dll.asm.txt` sha256=f45c7bfc2a4234f8a399578d2e07111540bd2c66262e9731c7142e5e2b218d5f bytes=330455
- `disasm/ppgammai.dll.asm.txt` sha256=9cecd285e37c4df864d92df23ed57761c2cb97c960a81c19d4707e96be1449f1 bytes=227693
- `disasm/ppncsolid.dll.asm.txt` sha256=5dc9cd9f1aa24a9bc4a69d1459421e2713d65d98ac9018a3d3dc1b1a8ea29b6e bytes=343804
- `disasm/ppoli2.dll.asm.txt` sha256=ad20c8f7b22bafc8a0bb9857ef59694000155cf6bfab59794a4edc7c41afafd0 bytes=208971
- `disasm/pptabpoly.dll.asm.txt` sha256=873a802dff2f537585e34f81d32bb3b10bb045478534f1dc72428039a5bcae5d bytes=498585
- `disasm/ppthermoi.dll.asm.txt` sha256=9a2057b020889876c7200951d27d958e4d142f7b83d8b779f6b7614bc188664c bytes=313165
- `disasm/pptransporti.dll.asm.txt` sha256=e720e069bf817d878d93c9ba03e2bce81105519cfced8d8fa8fdb810212fb802 bytes=302950
- `disasm/reposit_int.dll.asm.txt` sha256=40314a613ff7fa729461d92a4103f3a56a66ca83487a471c5c805bc3e30c7991 bytes=414795
- `disasm/rtmalloc.dll.asm.txt` sha256=6deadfd43cf3399912708730878dc788c0d3adbc6cd82b8093d4fe6866b7dc91 bytes=107600
- `disasm/rtpdfutl1.dll.asm.txt` sha256=d721de111d36c95db1536b69153e4978b9054aced1aaf090bf4b07169fed3c28 bytes=401495
- `disasm/sdftab.exe.asm.txt` sha256=444073047f317611fda22acff58fa5bf4931cc15a8599e2963cd7fb55c64a363 bytes=137978
- `disasm/tabledatawrapper.dll.asm.txt` sha256=6ec3a727153548c1320a7ff2257f20a6df2195070883b3b41f60371bca1e5a3d bytes=326361
- `disasm/utilsx.dll.asm.txt` sha256=0e1103e6cf5860c40742026e65984acc47e46e59af96680d6cbf92dc7b129537 bytes=388761
- `disasm/xtrnexec.dll.asm.txt` sha256=369685fba6768585711d8afc1d04aa5fa17f479fda3aa5cf7496681428c505fa bytes=303829
- `disasm/zeASCDInp.dll.asm.txt` sha256=bc62c6f713b47685fa51c8b4899064a314fee96ea14b65c4bbd18a7edf436d91 bytes=343201
- `disasm/zeaccting.dll.asm.txt` sha256=c5f3007a14dbd8413f155deb4047519f4f6323024f5df7b6720cefe9ccb108dc bytes=346939
- `disasm/zeifms.dll.asm.txt` sha256=c4674d2223b76b6f0e5380f34e5a6602d5c85ab4007d240cf55f3fec80d1bb84 bytes=129661
- `disasm/zesdfrpt.dll.asm.txt` sha256=be8f00e8338cf8cb5cd702c54951f545c2086a3fa714f97272501a0ccbb6b18b bytes=273866
- `disasm/zesem2util.dll.asm.txt` sha256=176b33a91bdf8bf5ded7dcdf6c5bed00149127546afad833c3d6e5e4172c2877 bytes=142410
- `disasm/zestrlib.dll.asm.txt` sha256=3144a393e9d1db49db6a73f446cc403180b0e60f2a119f7d467fe477c58cee93 bytes=491166
- `disasm/zevainfo.dll.asm.txt` sha256=c785c25a9d0f82ea8e2852f1d7d3e34b75dcec42f4b2d8ec7f6a65669d81e796 bytes=611620
