# NATIVE-340 s77 QA 补证复核

固定 [#450 交付](https://github.com/DenseFLoe/Aspen-for-mac/tree/4702d2d7c3d29b6100838d9d27808c416fd4e773/handoff/inbox/NATIVE-340)、[QA 786fec74](https://github.com/DenseFLoe/Aspen-for-mac/tree/786fec744f31eb550e276688fbd8a2364c938aa9/qa) 和 WrapSaveMergeNNFiles.dll 原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。149 个候选文件按 Git blob 固定，85 与 125 两套清单逐项吻合。使用原件 PEReader 记录核对新表 167 行的 token、RVA、flags、访问级别、IL 长度和 SHA-256，全部吻合。固定工具的 27 文件版本 `b3d91f952a6dd085b285dc8b20c402a6067a7975df257546479858e4927f643e` 两次同步一致。

带 pefile 2024.8.26 在固定候选目录运行 `python -B TOOL/qa/gate.py --task NATIVE-340 --item-dir CANDIDATE --original ORIGINAL --l1-path CHECKER --json REPORT --quiet`，覆盖 v1 退出 2，QA 12 个通过、1 个不适用、0 个失败、0 个错误。固定注册表实际加载 13 单元。access-flags 的展示数 527 包含 5 张表、334 行检查和原件的 188 个方法。补证维持 s77 returned 及 s81 分配。回执 0x19608、0x19618 的 0x08 仍误标为 CALL_MOST_DERIVED，沿用上轮裁定。

## 成对复跑

执行 `python -B handoff/outbox/NATIVE-340/s77-qa-control.py TOOL/qa/gate.py ORIGINAL`，pefile 使用同版本。固定 `qa/gate.py` SHA-256 `988c9d4f0e3cb0f990e7af60a04268aac81906859854e7e373030c227810975f`，将 L1 设为通过以隔离 QA 单元。

1. 同一检测器正常返回一项，随后只改为抛出 ValueError。预期正常项 exit 0，错误项非零。实测两者均 exit 0，后者单位汇总为 error=1，未改变 L2 状态码。建议统一导入失败、抛错和返回错误时的非零退出，并保留原错误。配对预期为 0 / 非零。
2. 使用原件 0x06000001 的真实 0x0813 与 Assembly，单改 token 为未定义的 0x0600FFFF。预期有效行通过、无法绑定行报缺陷或待核。实测两项均 pass、exit 0、inputs=190，实际候选各一行。建议先核对原件绑定，分别统计已绑定原件行、缺失绑定和条目清单。成对预期为已绑定行 1 / 0，第二项至少报告一条绑定缺失。

[实测与输入指纹](s77-qa-recheck.json) · [前轮裁定](s77-decision.md)
