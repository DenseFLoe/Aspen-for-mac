# NATIVE-340 s101 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。主干基线 19f94421ea3b724df2b27f65f71832db0259f34d，固定候选 [#450 @ 9c949d3f](https://github.com/DenseFLoe/Aspen-for-mac/commit/9c949d3f2caa5e90a793e1976057418a0cf4f6be)。

固定候选较 38b6814d15332a90258f2caa42169b6f52e5bad4 前移一次提交，增 6 改 6。共重验 240 个相关文件的 Git blob 和 SHA-256。活动清单 s29 的 102 项、s101 的 153 项全部匹配。metrics.json.calls_sha256 仍为旧的 e991b6cc5b388e259498dbd2fca74000b6e39f33b71c13207e005be6af60e821，当前 calls.csv 是 c92c66950f4a2f7c8f28df688dc499985f8e5a5d653e8618fe4a01619e1ae73f。候选提交说明的“检验器脚本”一节只给 QA 版本，未列出各脚本的指纹、命令、输入及原始退出码。[完整固定清单](s101-fixed-manifest.json)

- 通过项。直接构造六组 #~ 字节流，检查实际 read() 的 RID、名称和 ImportScope。两个标记值 2、3 及 16383、16384、32767、32768 边界全部正确。原件产生 15 个 ImplMap 项，旧版独立 PEReader 输出中的 109 个 MemberRef.Class 与 786 个 CustomAttribute.Type 逐行一致。历史八组实际读取控制 8/8。当前 85 列布局与旧版只差一处正确改动，交付布局差异脚本因该变动 exit 1。167 行只读摘要完整时 exit 0，单改第 67 行时定位 0x06000043、exit 1。
- 读宽盲点。保持 layout_for() 完整，只在 read() 取值循环将 coded 列宽固定为 2。交付的四个新夹具在原样及错误版本均报零失败、exit 0，历史独立探针则从 8/8、exit 0 变为 4/8、exit 1。交付的夹具只调用 layout_for()，且未构造 CustomAttribute 或 ImplMap 行。回归应读带非零相邻值的真实表行，保留输入哈希。
- 站点及归属。搬移同一交付，67 项、零差、exit 0。只改 L935 caller，或只把 0x4711 从 L1509 指向 L1510，均精确报错、exit 1。固定原件逐条核实 19 个跳板，其清单地址、备注地址、指令字节、RIP 位移及 IAT 导入符号全部吻合。19 个地址均在所列 caller 的半开 FUNC 区间外，前 16 条已标注待核。最后 0x477D、0x47D1、0x4894 各恰是所列函数的排他上界，备注仅以 census 归属。只将 L1509 listing 的 E9 换成 EA，或只把此调用的目标改成 GetStartupInfoW，分别重算样本指纹，脚本都误报 67 项零差、exit 0。脚本只抓 listing 的地址并取 census 最近前序起点，未读取原件及 FUNC 结束位置。回归应增加这两个单改反例并检查三条边界。
- 正式 v1 指纹 27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8，复跑得 1105 条覆盖、354 个原生入口、578 条调用、0 个声明缺口，退出 2。指标仍记 28 条未决，0x06000057 arg0 的外部指针来源仍须有新证据。

复现需可导入 pefile。CANDIDATE/PARENT 为上述固定头，ORIGINAL 为上述原件，CHECKER 为固定主干 handoff/assignments/check-native-coverage.py。WIDTH、SDK_JSON 分别取同目录历史 [s93-width-controls.py](s93-width-controls.py) 与 [s97-pereader.json](s97-pereader.json)。脚本会在当前目录内创建临时副本。
    
    python -B s101-replay.py CANDIDATE PARENT ORIGINAL CHECKER WIDTH SDK_JSON
    python -B CHECKER NATIVE-340 --original ORIGINAL --submission CANDIDATE/handoff/inbox/NATIVE-340

[用例与预期](s101-plan.md) · [重跑脚本](s101-replay.py) · [输入指纹与退出码](s101-recheck.json)。复验结果 SHA-256 fb463bfa7f64c4227d279745a00aa088a05aec1cb6690a99df0100487f535287。

## 10:22 UTC 补交

[补交固定头 f38c2df8](https://github.com/DenseFLoe/Aspen-for-mac/commit/f38c2df80fd991dab0bb23fdbe3e36f7ba864796) 只改本轮回执、两份本轮清单，并增加 tool/s101_receipt_section.py。固定实现及复验脚本仍为 9c949d3f2caa5e90a793e1976057418a0cf4f6be 对应的字节。合成当前 241 路径的只读视图，复用 237 个未变文件；四项变更独立核对 Git blob、大小和 SHA-256。s29/s101 的 102/153 项全部匹配。原[首版回执](s101-first-receipt.md)已保留。

[更新回执](../../inbox/NATIVE-340/s101-submission.md)列出七份脚本，大小和 SHA-256 全部吻合。其中四条复跑输出及退出码与上游实测一致。回执的 QA 命令在有空格的 Windows 路径上发生参数拆分，argparse 报 unrecognized arguments，exit 2，未执行任何判定单元。上游用独立参数传入同一路径，实测 14 pass、0 error，正式 v1 仍为 exit 2。新生成器从指定 Git 树计算脚本指纹，却从当前本地 ROOT 执行命令，复现时须核对本地执行文件及输入指纹。原件、实际取宽盲点、站点证据与待核数的判定沿用原固定复验。截至 10:25:25 UTC，#13 未见本轮单独回帖。[四路径及复跑结果](s101-supplement.json)

[#450 @ 4bc40c68](https://github.com/DenseFLoe/Aspen-for-mac/commit/4bc40c68ab7f501e2062c49c037adadc5d9f6808) 唯一差异是提交说明首行修正脚本指纹的来源头为 f38c2df8。固定树脚本、活动指纹、候选二进制和复跑结论沿用 f38c2df8。主干归档采用修正后的回执字节。
