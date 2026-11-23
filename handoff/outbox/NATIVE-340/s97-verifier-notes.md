# NATIVE-340 s97 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 38b6814](https://github.com/DenseFLoe/Aspen-for-mac/tree/38b6814d15332a90258f2caa42169b6f52e5bad4)。主干基线 44c22e3daac712802e8a7e865a42c301f70b714b。

#450 由 22135b6596af10a318fc80483b9c20d3680115bb 前移一项提交，11 路径增改。首份可核开工记录位于 08:55:20Z 的同一提交，收件 08:57:12Z。固定 234 个相关路径逐项验 Git blob 与 SHA-256，s29 的 102 项与 s97 的 152 项在各自活动清单内全部吻合。metrics.json 的 calls_sha256 仍是旧值 a17d6d99…，本轮实际 e991b6cc…。[固定收件](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7096038802)

1. 真实 #~ 流的 8 个阈值输入在前版有 4 个错列、exit 1，在新版本 8/8 正确、exit 0。以主干已归档的 `s93-width-controls.py` 作独立字节流探针。在临时副本仅使实际读取宽度返回 2，TABLES 不动，协作者同名脚本仍报 `pairs=3 mismatches=0`、exit 0，独立探针报 4 个错列、exit 1。原因是其 offset_of_next() 从表定义自行计算，并未调用 read()。真实读路径现从 TABLES 派生；回执所称已删除的 CODED_COLUMNS 仍存在于第 197 行。本轮使用 TABLES 中 2 位的 ImplMap.MemberForwarded 替代旧解码器的 1 位，合法原值 2、3 原应解为 Field[1]、MethodDef[1]，前版均正确，新版均返回 (None,0)。两个输入的完整指纹及前后实测可复跑。[.NET MemberForwarded 定义](https://github.com/dotnet/runtime/blob/main/src/libraries/System.Reflection.Metadata/src/System/Reflection/Metadata/Internal/MemberForwardedTag.cs) · [对照](s97-recheck.json)

2. `s97-site-owners.py` 交付 1,820 B，SHA-256 `bef8eb794ee90bb311578bbb05cc82589d05856557d293cbd79d7547425d175d`，回执列的是 2,258 B / ac0bed80…。它只选 note 带 IAT thunk 的行，将 note 中首个地址归于最近前序 census 起点。原件的 0x2B7A 实际在 listing 第 935 行，只把原有 caller 0x2B74 改为 0x3660 应拒绝并定位该行，实测与原样及等价搬移同为 19 条、0 错、exit 0。只把 0x4711 的清单行 1509 指向 1510，亦 exit 0；将该行备注的 IAT thunk 改为 IAT jump 后，检查数量从 19 降至 18 而 exit 0。对照更新各自输入 SHA-256。独立检查原件后，19/19 的字节、槽与导入符号吻合，但都在所报 caller 的已列函数区间外。前 16 行已写明待核，最后三行仍将 0x477D、0x47D1、0x4894 记为前六字节的另一跳板。0x2BCF 的 note 已更正 REX.W 和位移 13442，native.asm 第 1508 行仍写 3441189。[逐站结果及原生覆盖](s97-iat-digest.json)

3. .NET SDK 9.0.321 按原样编译运行两份固定源码。原件 MethodDef 188、MemberRef 109、CustomAttribute 786、MethodImpl 0。109 个 parent 与 786 个 constructor 逐行等于 read() 解码，原件 CustomAttribute[1].Type 原值 19，MemberRef[2]；MethodImpl 的阈值对照来自合成表流。167 条只读 IL 摘要实测原表 exit 0，单改、缺行、重复均 exit 1，逐项定位 0x06000043，输入指纹执行前后一致。[PEReader 原始 JSON](s97-pereader.json)

4. 正式 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。原件与错 caller 均 1105 覆盖 / 354 原生 / 578 调用 / 0 声明缺口、exit 2。QA `93bf962ce92430fe03768f6f2808e9a8096ad47f` 在 pefile 2024.8.26、capstone 5.0.7、keystone-engine 0.9.2 下独立运行 14 pass / 0 error、整体 exit 2；回编单元有 6,513 条记录、478 条跳过数据，6,035 条指令中 6,026 同文本、7 条允许列表、2 条未能组装（0x1756、0x4349），可比较共 6,033 条。该单元读取原件的可执行节，未重编交付源码。上一版 QA 27007e5a 的原始环境为 8 pass/5 error，上游补齐依赖时为 13 pass/0 error。[本轮 QA 结果](s97-qa-summary.json)

复现时，CANDIDATE、PARENT、ORIGINAL、CHECKER 分别替换为上述固定候选、22135b6、固定原件和主干检查器。WIDTH 是同目录历史 s93-width-controls.py（26a7eb09e7192fd5340403071c52a7b60bd606a4bfb09e6edfa4675ffb0064ea）。QA 指向 93bf962c 的 qa 目录；需使上述依赖可导入。SDK 输出只包含相对原件路径。

```text
dotnet run --project CANDIDATE/tool/pereader_340/pereader_340.csproj -c Release -- ORIGINAL > pereader.json
python -B s97-controls.py CANDIDATE PARENT ORIGINAL WIDTH pereader.json
python -B WIDTH CANDIDATE
python -B WIDTH PARENT
python -B s97-iat-digest.py CANDIDATE ORIGINAL CHECKER --require-iat
python -B CHECKER NATIVE-340 --original ORIGINAL --submission CANDIDATE/handoff/inbox/NATIVE-340
python -B QA/gate.py --task NATIVE-340 --item-dir CANDIDATE/handoff/inbox/NATIVE-340 --original ORIGINAL --l1-path CHECKER
```

[逐项输出](s97-recheck.json) · [固定文件及 SHA-256](s97-fixed-manifest.json)
