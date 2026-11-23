# T9-368-RECONCILE 复核交付（第二轮修订）

owner upstream / starter-t13/worker-368，assigned_seq=1。本轮按首轮 s1-decision 逐条修掉裁定项，重生成四份报告 + reconciliation.json。固定输入：#368 提交 db544a6fdfb04ec60d182c311aa47d13a61d744b 的 handoff/review/t9-1000/ 下六个文件，逐个用 contents API 下载，SHA-256 与 check-t9-368.py 内定值全部一致（selection d5de1f69…、ledger 1312903e…、README 453dc4ac…、stats 888b636a…、failures 083cc7a9…、validation f6d94bc8…）。

## 1. 判定命令、原始 stdout、exit code

命令（在 _work/wf-20261120-aspen-batch 下执行）：

    python -B handoff/assignments/check-t9-368.py --input-dir _t13/t9

原始 stdout（逐字）：

    T9 reconciliation: 1000 matched identities; {'pass': 530, 'fail': 470, 'partial': 0, 'blocked': 0} ; inconsistent product rows: ['Plus', 'Properties']

exit code：**0**

读法：stdout 末段 inconsistent product rows: ['Plus', 'Properties'] 是脚本对「固定输入里旧 stats.md 矩阵」的比对输出（旧文档正是本次待修订对象），不是本轮交付文档的结论。用同一脚本解析修正后的四份文档：different_products=[]、codes_missing_from_table=[]、missing_idx_by_code 全 0、stale_detail_verdict_indices=[]、R3_fail_count=470，DOCS_CONSISTENT True（见 §4）。

## 2. 独立复算（只读两张 CSV，不抄旧文档）

- _t13/recompute.py：1000 行全在 0–999；identity（shard/state/product/name/item_dir）逐行一致；shard=idx%12 全对；item_dir 唯一 1000、登记 SHA-256 唯一 1000 且格式合法；15 行 relative_path 为空（916–926、930–933）；problems=0。
- verdict：pass **530** / fail **470** / partial **0** / blocked **0**。
- 产品矩阵：Plus 958（**519/439**）、Properties 23（**7/16**）、Plus-Properties 19（**4/15**），合计 1000（530/470）。
- 归档状态：待静态验收 916（470 pass/446 fail）、静态验收未通过 84（60 pass/24 fail）。
- 原因独立行数：tool_nag_tail **455**、a2_sha_missing **15**、a3_report_missing **15**、tier_b_incomplete **6**、analyze_failed **1**；占用 492 次，多码重叠 22 行（15 行 a2+a3、6 行 tier_b_incomplete+tool_nag_tail、1 行 analyze_failed+tool_nag_tail），去重后 fail 470 行。
- Tier B 原始字段：PASS **978**、PARTIAL:no_il **6**、PARTIAL:no_claim **1**、NOT_RUN **15**；kind：CLR 455、native 530、other 15；tier_a：PASS 985、FAIL:a3_report_missing,a2_sha_missing 15。
- tool_nag_tail 分布：Plus 439、Properties 16、Plus-Properties 0；kind 全为 CLR；归档状态 待静态验收 446 / 静态验收未通过 9。
- 反例：idx=893 Properties《Aspen Excel Add-in Manager 64 Bit.exe》SHA-256 475a6475332299a4be0eb1573403cbf88176a81e7fcacfa958f5aa9f596866f0 = tool_nag_tail / fail；idx=311（tier_b_incomplete+tool_nag_tail）、idx=982（analyze_failed+tool_nag_tail）为多码行；idx=916–933 为 a2+a3 双码 15 行；旧标 partial 的 7 件 311/332/357/359/459/968/982 全部带 tool_nag_tail、verdict 已为 fail。
- reconciliation.json 的 SHA-256 = 0025a4c4026162b383f68cc019c26487cef74efb0b1c6fe64a6f975e7f71da48，与首轮固定结果逐字节相同（本轮从固定输入重算复现，非复制旧文件）。

## 3. 四份文档改动对照（旧行号 → 新内容）

| 位置 | 旧（固定输入里） | 新（本轮交付） |
| --- | --- | --- |
| stats.md 16–18 | Plus 510/448、Properties 23/0（三行和 537/463） | Plus 519/439、Properties 7/16、Plus-Properties 4/15；合计 530/470 |
| stats.md 36–39 | 4 个原因，缺 tool_nag_tail | 5 个原因，tool_nag_tail 455 + 重叠 22 行说明 |
| stats.md 21–30 | Tier B 只给覆盖率 | 增加 tier_b 原值分布 978/6/1/15 与 verdict 的关系 |
| failures.md 5 | 978 pass / 15 fail / 7 partial | 530 pass / 470 fail / 0 partial / 0 blocked |
| failures.md 15–18 | 4 个原因，缺 tool_nag_tail | 5 个原因（同上） |
| failures.md 72–77、85 | 7 行 verdict=partial | 全部 fail，并进入 tool_nag_tail 455 行明细 |
| README.md 45 | 15 件 a3、6 件 partial、1 件 partial | 455+15+15+6+1 独立行数、重叠 22、partial 0；tier_b 原值单列 |
| validation.md 9（R3） | 15 件 fail | 470 件 fail 全带 fail_codes、failures.md 列全 idx |

完整明细：failures.md 现按 5 个原因分组列全每一行（tool_nag_tail 455 行 + a2 15 + a3 15 + tier_b_incomplete 6 + analyze_failed 1），verdict 列逐行取自台账，故同一 idx 可在多组出现。

## 4. 复现与自检（本机实跑）

    python -B _t13/recompute.py                                         # exit 0, rows=1000 problems=0
    python -B _t13/gen_t9_reports.py                                    # 由两张 CSV 重生成四份文档
    python -B _t13/verify_docs.py                                       # exit 0, DOCS_CONSISTENT True
    python -B handoff/assignments/check-t9-368.py --input-dir _t13/t9   # exit 0

verify_docs.py（用同一 checker 的解析器跑修正后文档）关键输出：

    readme summary     {'pass': 530, 'fail': 470, 'partial': 0, 'blocked': 0} partial_claims {'tier_b_incomplete': 6, 'analyze_failed': 1}
    stats diff_prod   []
    stats codes_miss  [] table {'tool_nag_tail': 455, 'a2_sha_missing': 15, 'a3_report_missing': 15, 'tier_b_incomplete': 6, 'analyze_failed': 1}
    fail  missing_idx {'a2_sha_missing': 0, 'a3_report_missing': 0, 'analyze_failed': 0, 'tier_b_incomplete': 0, 'tool_nag_tail': 0}
    fail  stale       []
    valid R3          470
    DOCS_CONSISTENT True

## 5. 文件清单（handoff/inbox/T9-368-RECONCILE/）

| 文件 | 字节 | SHA-256 |
| --- | ---: | --- |
| README.md | 4601 | 8856c51d71541f86a40894fd4dc429e891b0b5840e9e95e88e7c3da470a71198 |
| stats.md | 4713 | 4017ce61682f7a6548c6760cdea5678dd0b251e41a46c0ac24dd6d4039fd6ac0 |
| failures.md | 117712 | 721af5b39d872112bbe5c08a7790edb0a3ab8cf52de84e8e2a02a9ad6bef5310 |
| validation.md | 4197 | 1ce0514ac4d6572cac7928254f535d357175aa7400ea541547dcba74592584c5 |
| reconciliation.json | 6476 | 0025a4c4026162b383f68cc019c26487cef74efb0b1c6fe64a6f975e7f71da48 |
| s1-started.md | 见本目录 | — |
| s1-submission.md | 本文件 | — |

## 6. PR 正文需同步的旧汇总（建议替换文本，逐条照抄）

1. 「978 pass / 15 fail / 7 partial」→「**530 pass / 470 fail / 0 partial / 0 blocked**」。
2. 「产品矩阵三行相加 537 / 463」→「**Plus 958（519/439）、Properties 23（7/16）、Plus-Properties 19（4/15），合计 1000（530/470）**」。
3. 「Plus 510/448」「Properties 23/0」→「**Plus 519/439**」「**Properties 7/16**」。
4. 「fail 15 件（a3_report_missing）/ 7 件 partial」→「**fail 470 件**；原因独立行数 **tool_nag_tail 455、a2_sha_missing 15、a3_report_missing 15、tier_b_incomplete 6、analyze_failed 1**（占用 492 次，多码重叠 22 行）；partial / blocked 均为 **0**」。
5. 「7 件 partial（6 件 no_il + 1 件 no_claim）」→「**这 7 件均带 tool_nag_tail，最终 verdict=fail**；6 件 PARTIAL:no_il / 1 件 PARTIAL:no_claim 仅为 tier_b 列原值」。
6. 「R3：15 件 fail」→「**R3：470 件 fail 全带 fail_codes，failures.md 按 5 个原因列全 idx**」。
7. Tier B 覆盖率「985/985（CLR 455/455、native 530/530）」**保持不变**；凡引用 tier_b 原值处补一句「**978 PASS / 6 no_il / 1 no_claim / 15 NOT_RUN 为列原值，不等于最终 verdict**」。
8. 归档状态口径保持不变：「待静态验收 916（470/446）+ 静态验收未通过 84（60/24）」；新稿已补 stats.md §2 证明矩阵。

## 7. 限制

- 只做机械层：原件二进制不在仓库，A1/A2 比的是「归档说明登记值 vs 制作者报告登记值」；语义层（类型用途、调用约定、逻辑等价）与运行期未复核，预审结论≠上游 P0–P3 终判。
- reconciliation.json 的 document_claims 字段按 checker 契约记录的是**固定输入（旧文档）**的声明（因此里面仍能看到 different_products / codes_missing_from_table / R3=15 等旧值）；修正后的四份文档在本目录，二者不是同一对象。JSON 的 by_product / by_archive_state / code_counts / verdicts / examples 才是台账重算结论。
- 本轮未重跑 review_shard.py / merge_ledger.py：R6 的 mismatch=0 引自合并日志断言，非本轮复算；分片件数已按 idx%12 从台账复核（83–84 件/片）。
- 本机 handoff/ 镜像原缺 check-t9-368.py，已按 BASE 用 contents API 下载到 handoff/assignments/check-t9-368.py（SHA-256 ff2fbcd5873e5d86d4912417dccdc39eb6d638fef701a80dd8c047f00e9a58b1，与缓存副本一致），仅供本机判定命令使用。
- 未推远端：所有写入限于 _work/wf-20261120-aspen-batch（handoff/inbox/T9-368-RECONCILE/、handoff/assignments/、_t13/），由主 agent 统一推。
