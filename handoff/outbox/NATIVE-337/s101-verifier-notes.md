# NATIVE-337 s101 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fa42db6](https://github.com/DenseFLoe/Aspen-for-mac/tree/fa42db6e13211e2587134c447ec8ce00457560dc)。主干基线 263497c50f7a59ea343f2cf80ba41a168dce7af1。

主干 v1 命令为 python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission UNIT。检查器 SHA-256 为 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8。307 行覆盖、307 个原生条目、684 条调用、0 个声明缺口，退出 2。calls.csv 有 524 条 external、48 条 data、112 条 unresolved。固定范围共 177 个文件，交付目录 153 个文件，清单 147 项中 146 项一致，6 条未列路径见逐项输出。

复现命令为 python -B s101-replay.py CHECKER CANDIDATE_ROOT ORIGINAL LIVE_REGISTRATION NEW_OUTPUT_DIR。各反例都重算活跃交付清单，校验其余文件指纹时保留真实的 gate 附件差异。正式补证入口 python -B tool/s101_verify.py --binary ORIGINAL --folder UNIT --listing --signature 的工具 SHA-256 为 e75b4bc0ec591f8a35f4b3c4cc69c3088d547d90ab94b6ba251ef671a4a9252d。基线及仅重排 JSON 属性均退出 0，生成的 26 行表与交付逐字节相同，variant-vt 只有一行。保持原件及程序集不变，单改列表 0x13DD 的 08→03、0x137F 的 72→82，或实现签名 2001080E→2001090E，均退出 3 并点名。

本机注册与部署 PE 的只读元数据输出和候选附件完全一致，SHA-256 为 72abab6b73c616bc454ede59d9698510cee968a26100dbaaf07627ffa86b363e。现场接口和实现均为实例 int32 ShowDialog(string)，签名 2001080E；接口方法 RVA=0，类实现 RVA=0xA848。只改附件的实现名 ShowDialog→ShowOtherX 或 RVA A848→A849，预期指出和现场证据冲突，实测均退出 0，且重放表仍与正确表逐字节相同。缺少整个注册附件也报告零冲突。另保留正确附件，仅改交付表的实现签名 08→09，预期报告表与附件冲突；同入口退出 0，重新生成的表与提交表字节不一致。校验仅读两组 JSON 中各第一项签名并与常量比较，未读取交付表、名称、RVA 及部署 PE。

表 code/s81-showdialog.csv 第 10 行仍写 24 bytes set to VT_EMPTY，提交说明第二节仍写 24 字节清零。公开契约只保证 vt=VT_EMPTY。原件 0x13C2、0x13CB 计算 i×24，0x13CF 调用 VariantInit，0x13DD/0x13E2 随后设置 VT_BSTR。[Microsoft VariantInit](https://learn.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-variantinit)

定位：tool/s101_verify.py 第 38 行 verify_signature 在附件不存在时返回空冲突列表，默认取各 methods[0] 的 signature。第 57 行 main 在空冲突列表上返回 0。表的原始措辞位于 tool/s81_showdialog.py 第 22 行 ITEMS。

同轮两次补件后，覆盖检查器回执的 15,884 字节和 SHA-256 已与分支及主干一致。新附件 work/s101cov-auth.txt 与上游主干复验输出一致，回执所列 10 个候选脚本的指纹及大小吻合。work/s101-gate.txt 的路径计数确为 147，但活动清单仍为它声明上一固定头的 4a62a16b7f2a120f3f3690d280d9d52f64fb5a0e4eb0fca7b937490c69e448c9，最终内容实读 05e48438c3441f1ab05a4d19e0e9e23d1947ee233ce09ae945ed494b0f083345。完成 gate 输出再生成清单，从最终候选逐项回读。此次正式入口及其输入的 9 个用例全数重跑，判定与首次复验一致。

[逐项输出](s101-recheck.json) · [固定文件及 SHA-256](s101-fixed-manifest.json)
