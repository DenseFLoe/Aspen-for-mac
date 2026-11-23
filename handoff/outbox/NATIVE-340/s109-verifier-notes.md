# NATIVE-340 s109 验收与回归

原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。验收主干 `c30a97f2701d1b70a5cbf3fe67debf3e2ed2086b`，候选 [#450 @ db209d73](https://github.com/DenseFLoe/Aspen-for-mac/commit/db209d73e787346373ec3a4c156eceed864f6f70)。

从上一裁定头 `6d93c5981ddf3ad71907e9a814d739f874b4c218` 到本候选五次提交、十条净变更路径。双方均指向 main 为 PR 目标。与本次验收主干的共同祖先为 `773260c1033e524cebe000699409f5708bebfda0`，本次结论仅适用固定头。逐文件核对本件和 tool/ 共 250 个 Git blob 及其 SHA-256，回执十个脚本均命中实际大小与指纹。s29 清单 102/102，s109 清单 154/155。后者给 s109-submission.md 的 SHA-256 为 `6b20a3486f45a0f6b976ef4c4db6621856b8315da3e0603a513644973e5885db`，固定头实测 `c7c07c6065375fb679a93a757191f9552cf3692f834e7fd22974162174b635f7`。历史 s101、s105 分别 150/153、152/154，其历史快照独立保留。metrics 三摘要均匹配。

独立从 PE 解码的 19 条 IAT 尾跳转在字节、位移、槽与导入名上一致。对照实际 FUNC 末尾，0x477D、0x47D1、0x4894 均恰在半开区间的排他上界；三条已在 calls 和回执双标 census 推算、asm 区间外及待核。仅延长第一条 FUNC 边界 6 字节后，独立判定从区间外变为内。旧全站点脚本仍输出 67/0；s109 单站点脚本只检 L1509。保留归属待核。

L1509 为 RVA 0x4711、disp 0x18E9、slot 0x6000、KERNEL32.dll!QueryPerformanceCounter。通过修改实际文件并重算交付指纹复现。等价目录 exit 0；只改显示位移、符号后缀、移除引用各 exit 1 并定位。只把声明路径改为不存在的 bad/native.asm#L1509，s109 专项仍 exit 0，正式覆盖正确 exit 1。专项以行号尾串筛选而未验证实际引用路径；缺文件并真实保留行号的样本可作回归。

两个 CLI 控制使用相同字节流。交付的 read 行步长自检在原版上发现 5 个字段变化；只把正常 coded 字段的实际取宽锁为 2，保留 layout_for，行步长自检依旧 5 个变化、exit 0，交付 width-fixtures 同为 exit 0。独立读取跨阈值字段与紧邻列，从 8/8、exit 0 变为 4/8、exit 1。行步长测试只检查有任一差异，并未绑定正常值。此为既有读取宽度漏判在新自检中的实证。

正式 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，1105 行覆盖、354 原生入口、578 调用、0 声明 gap、退出 2；调用含 28 个 unresolved。固定 QA `93bf962ce92430fe03768f6f2808e9a8096ad47f` 正常启动后 14 个单元 pass、0 error、整体退出 2。指纹检测发现回执摘要差异，作为 advisory，处理 153 条路径、0 个脚本行。另有两个已知汇编 advisory。作者本轮回执虽列引号化 QA 命令，其原始输出仍为 argparse 失败。167 条 IL 摘要无差异，6 组 ImplMap 字段及邻列实际值正确。

从独立 Python 环境运行，需 pefile；固定 QA 另需 capstone、keystone，并将 QA_ROOT/qa 置于 PYTHONPATH。S105 与 WIDTH 分别是同一 outbox 的 s105-replay.py、s93-width-controls.py。以下脚本接受绝对输入路径。在可写的临时工作目录运行。

    python -B CHECKER NATIVE-340 --original ORIGINAL --submission CANDIDATE/handoff/inbox/NATIVE-340
    python -B s109-replay.py CANDIDATE ORIGINAL CHECKER S105 WIDTH QA_ROOT

[先记用例与预期](s109-plan.md) · [固定目录和增量指纹](s109-fixed-manifest.json) · [独立复跑脚本](s109-replay.py) · [逐项输入、输出与退出码](s109-recheck.json)。QA 日志仅省略本机依赖路径。
