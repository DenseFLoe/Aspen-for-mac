# NATIVE-340 s105 验收器复验

原件 WrapSaveMergeNNFiles.dll，SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。主干基线 `c8ec21865e2a9afc48873757ec1da993ceaf2f26`，固定候选 [#450 @ 6d93c598](https://github.com/DenseFLoe/Aspen-for-mac/commit/6d93c5981ddf3ad71907e9a814d739f874b4c218)。

相对 `34963f5d2e07142f9edd1b4c75aebaecea169d09` 两个提交、六个变更路径。固定树的本件及 tool/ 共 245 路径逐一核对 Git blob、大小与 SHA-256。s29 的 102 项、s105 的 154 项、回执八份脚本全部匹配。s101 历史清单在最新工作树的 151/153 项匹配，变化的是 metrics.json 与 s101 回执。当前 metrics 的 calls、coverage、native-functions 三个 SHA-256 均与实际文件相同。167 条 IL 摘要及六组真实 ImplMap 取值均通过。

- **站点校验漏报。** `tool/s105-site-evidence.py` SHA-256 `600975699de15c7ff150a336ac792726c40383e5229f835acdb727dd0e68c1ed`。固定输入和复制到不同路径的等价输入都是 67 项零差、exit 0。L1509 的 FF 25 改 FF 24，正确导入名称改 GetStartupInfoW，以及将引用 L1509 指向 L1510，各报 1 个含位置的冲突、exit 1。仅将 L1509 的显示位移 0x18E9 改 0x18E8、在 QueryPerformanceCounter 后追加 _WRONG、清空 listing 引用，分别报 67/0、67/0、66/0，均 exit 0。位移须同时核对原件字节与显示文本，导入符号须以固定槽地址的完整身份比较，缺引用须定位。
- **函数范围。** 19 个站点的字节、位移、导入符号和备注地址都与原件一致。它们都在所列 caller 的清单 FUNC 半开范围外。前三个未同步待核的端点是 0x477D、0x47D1、0x4894，恰等于所填来源区间排他上界。候选脚本采用原生 census 相邻起点，未读 FUNC 结束地址。只把 0x4777 范围结束地址从 0x477D 改为 0x4783，L1524 的范围关系从区间外变为区间内，实测仍为 67/0、exit 0。读取实参交付的 FUNC 起止后输出关系或冲突。原件归属仍待核时，在 calls.csv 及回执共同标记。
- **CLI 实际取宽。** 既有问题新增实证。`tool/s101_width_fixtures.py` SHA-256 `85145a458b4c4f1c9ff8dc3d0eeadadca2d81b5b2254e27af90027958b095a95`。把 coded 列实际取值宽度改为 2，保持 layout_for() 不变，交付脚本原样/变体均 exit 0。独立字节流探针从 8/8、exit 0 变成 4/8、exit 1。正例与单改反例需读真实行并比较邻列。
- **QA 的指纹和符号。** 固定 `93bf962ce92430fe03768f6f2808e9a8096ad47f` 用正确的 Windows 参数独立复跑，14 pass、0 error、整体 exit 2。候选回执的可复制命令与输出块仍记录 argparse 拒绝及零单元，回执正文所称已引号化复跑缺对应输出。固定 QA 的 `det_fingerprint_pathset.py` SHA-256 `d0379abfd3df805081b5514ae0acf04e956018cc563b8cec4ac482aae07d3316`。基线只计 152/154 条当前路径、0 个回执脚本行。分别单改声明的 code/types.cs、code/s73-il-bodies.bin，仍无命中。在已重算回执文件指纹的副本里把一个脚本摘要改为全零，仍无命中。扩展名漏验沿用既有缺口，新的固定证据涵盖「路径 | 字节 | SHA-256」回执格式。应按声明路径核验全部文件类型并识别该回执列，超出本输入范围的路径显式待核。此外把 L1509 改为原件另一个已导入的符号 GetStartupInfoW，独立 QA 的 wrong-symbol 与 symbol-substring 两单元均无命中，交付站点脚本正确拒绝。若 QA 要判定站点目标，应按实际 IAT 槽比较，而非整件导入集合。
- **正式 v1。** SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，1105 覆盖、354 原生入口、578 调用、0 声明缺口，exit 2。0x06000057 arg0 与其余未决依原恢复条件续办。

复跑环境需能导入 pefile。CANDIDATE 为上述固定头，ORIGINAL 为上述原件，CHECKER 为固定主干脚本，WIDTH 是 [s93 独立控制](s93-width-controls.py)，QA_ROOT 为固定 QA 源码根目录。实际 QA 整套复跑还需 capstone 和 keystone。

    python -B s105-replay.py CANDIDATE ORIGINAL CHECKER WIDTH
    python -B s105-qa-controls.py CANDIDATE/handoff/inbox/NATIVE-340 ORIGINAL QA_ROOT
    python -B CHECKER NATIVE-340 --original ORIGINAL --submission CANDIDATE/handoff/inbox/NATIVE-340
    python -B -m qa.gate --task NATIVE-340 --item-dir "CANDIDATE/handoff/inbox/NATIVE-340" --original "ORIGINAL" --l1-path "CHECKER"

[计划](s105-plan.md) · [复跑](s105-replay.py) · [输入输出](s105-recheck.json) · [固定清单](s105-fixed-manifest.json) · [QA 配对命令](s105-qa-controls.py) · [QA 配对结果](s105-qa-controls.json)。
