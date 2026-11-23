# NATIVE-340 s101 续领

owner tietoumiao，assigned_seq=101，自 #13 ACK 起 24 小时。原件 WrapSaveMergeNNFiles.dll，SHA-256 869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec。固定候选 [#450 @ 38b6814](https://github.com/DenseFLoe/Aspen-for-mac/tree/38b6814d15332a90258f2caa42169b6f52e5bad4)。主干基线 44c22e3daac712802e8a7e865a42c301f70b714b。

保留已通过的八组实际表流、PEReader 与 167 条摘要。修正 ImplMap.MemberForwarded 为 1 位；原值 2、3 分别应解 Field[1]、MethodDef[1]，在 16384/32768 核紧邻列。将宽度测试接到 read()，只破坏实际取宽应非零。归属脚本从真实 listing、原件指令及函数区间提取站点，登记区间外待核的证据；只改真实 0x2B7A 第 935 行 caller 或 0x4711 的清单引用必须非零并定位。更正最后三处 site/归属、第 1508 行位移与回执脚本指纹、metrics.json 的 calls_sha256。按脚本附真实命令、输入指纹、原始输出与退出码，保留 0x06000057 arg0 的外部指针恢复条件和 28 条未决。

执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-340 --original ORIGINAL --submission CANDIDATE`，附回执、固定提交、完整指纹与未决项。[上轮裁定](../outbox/NATIVE-340/s97-decision.md)
