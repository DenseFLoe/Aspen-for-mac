# NATIVE-337 s97 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ ff5aa8a](https://github.com/DenseFLoe/Aspen-for-mac/tree/ff5aa8a36cfe444e9f540414b59a2bd1b441c680)。主干基线 54d8dd1dcb8bbbee003535a8270638fb4da6e187。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。检查器 SHA-256 为 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8，307 条覆盖、307 个原生条目、684 条调用、0 个声明缺口，exit 2。确认 524 条 external、48 条 data、112 条 unresolved。139/139 项声明匹配。交付范围 145 个文件，清单除自身和提交说明外另未列 code/README.md、s85-fingerprints.json、work/s49-inputs.json、work/s61-layouts.json。s93 已过的 0x106C、0x1072 对照输入和生成器未改。交付内 work/s97-gate.txt 的路径数 137 是早期快照，固定头 27007e5a QA 另跑得到 139，10 pass、0 fail、3 不适用、0 error。

复现 `python -B s97-replay.py CHECKER CANDIDATE_ROOT ORIGINAL s97-live-registration.json OUTPUT_DIR`。在相同安装上可执行 `pwsh -File s97-read-registration.ps1` 生成 registration.json。固定原件、正确列表的 22 行与提交表逐字节相同，variant-vt 唯一。原件中的真实 IID_NULL 位于 0x82F8，IID_IDispatch 位于 0x8308。

1. 原件不动，0x13DD 的 MOV 立即数 8→3（VT_I4），或 0x137F 的 LEA 位移 0x6F72→0x6F82（IID_IDispatch），每次只改列表中的一字节。原件和正确列表上预期两站一致，矛盾列表预期定位该站、拒绝作为通过证据。实测仅相应 listing_matches 由 yes 翻为 no，生成器仍 exit 0 且照常写出 22 行。保留两处已修复的局部识别，另验证复验入口的拒绝状态。

2. 本机注册表、安装程序集与 s85 旧证据和 s97 附件字节相同，均为 72abab6b73c616bc454ede59d9698510cee968a26100dbaaf07627ffa86b363e。注册 CLSID {09DC53C4-47A0-4AE0-9422-5675D014F182}，部署 PE SHA-256 为 04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5。IFindComponentDriver 和 FindComponentDriver 均声明实例 int32 ShowDialog(string dialogName)，签名 2001080E，类实现方法 RVA 0xA848。只改交付附件中实现方法签名的返回类型字节 08→09，接口、安装文件、原件和列表不动。预期输出定位实现方法签名不符，或明确待核；实测 exit 0 且生成表 SHA-256 与配对基线同为 137867fc0f35d4d18b3d7b058a903f63cff76c9f91670c9a517d4dff919863a2。deploy-signature 行的 PublicKeyToken=null 只描述强名称身份。动态 DISPID 继续未决。[原始注册与元数据](s97-live-registration.json)

3. 现行 variant-init 行和提交说明仍写将 24 字节设成 VT_EMPTY。原件 0x13C2、0x13CB 计算 i×24，0x13CF 调用 VariantInit；0x13DD/0x13E2 随后写入 VT_BSTR。契约只保证初始化 vt=VT_EMPTY。相应行应区分调用保证、数组取址和后续类型标记。[Microsoft VariantInit](https://learn.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-variantinit)

[逐项输出](s97-recheck.json) · [固定文件及 SHA-256](s97-fixed-manifest.json)
