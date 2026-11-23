# NATIVE-337 s89 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 157af57](https://github.com/DenseFLoe/Aspen-for-mac/tree/157af573f9b13fc4744eac14f50c2e9ae373d921)。主干基线 0554621e9ac0d627fad1e399d8868da06d1482e6。

1. 上游原件核对确认同位移 JMP→INC 时两个入口均从 161→160，再取另一站从 161→122。分类器 `s65_counterexamples.py` SHA-256 `26a94ce2c081fe4a2e838354993e2ebcbf74f4be9be98e7ef258aaf921d01cfa`。同原件只改 0x106C 的真实导入 #2344 为同 DLL 的 #2348，s65 从无冲突变为 1 处冲突。两跳表 `s37_two_hop.py` SHA-256 `8913f0902d0cdd46115c046007892da69490c432546e58749bb17c7510354819` 仍关联唯一错误行，两张 CSV 哈希相同。独立样本 0x1072 的 #2348→#2207 同样重现。枚举程序只负责站集合，因此其输出不受调用表替换影响。两跳表须在选择候选行前验证实际导入身份。这两个真实序号对照预期仅点名被改站的冲突。实际原件导入表中无 #2345 与 #23440。
2. 固定 `s81_showdialog.py` SHA-256 `04e5eabb32e3abb5c8bc0fe56f61514ec090c05a86c3d441f8b3790ba19d1e1c`。运行 `python -B handoff/outbox/NATIVE-337/s89-paired-replay.py CANDIDATE ORIGINAL`，复跑固定表与只改列表的对照。把 0x13DD 即时数 8 改为 3，程序仍退出 0，字节列 b808000000→b803000000，字段语义仍写 VT_BSTR。另只改 0x137F 的位移使 riid 指向 IID_IDispatch，整张 CSV 不变。建议从原件解析操作数与 IID 值，并校验列表与原件一致。两个单改反例预期各定位对应指令不符，拒绝原样生成。VariantInit 的公开契约只设置 vt 字段，24 字节是 VARIANT 元素步幅。[Microsoft VariantInit 文档](https://learn.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-variantinit)
3. 上游已经读取原件同安装的 64 位和 32 位注册与程序集元数据，确认 CLSID 09DC53C4-47A0-4AE0-9422-5675D014F182、程序集 SHA-256 `04e68b8eca60b732e661bf322d74b6f042abeba9ea801e2e2e410c1be007b5d5` 和实现 RVA 0xA848，签名为 int32 ShowDialog(string dialogName)。交付可引用上游的固定证据，继续保留运行期 DISPID。[既有注册与部署证据](s85-registration.json)
4. 在其旧头分别复算 s87、s88 清单 114/117，全部吻合。s89 的 126 项在最新头逐项复算，125 项吻合，唯一差异是清单给自己声明了前一次写入的哈希。3517b5ed 正确拦截。重建清单时排除清单自身，通过交付回执或独立外部指纹固定清单字节。把清单放入待核路径时，预期拒绝。
5. 本轮通过观测到的首个固定提交登记 started，按 #13 收到固定头的时间登记 submitted。上游补录开工证据见 [回执补记](s89-started-evidence.md)。

[逐项输出](s89-recheck.json) · [固定文件及 SHA-256](s89-fixed-manifest.json)
