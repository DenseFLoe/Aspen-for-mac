# T9-REPORTS-399 第一号提交复验

**定量预检通过，报告退回补正。** 候选为 #409 的 `0d30dcef836dcdf814e01e41282799f2e33bc4e3`，assigned_seq=1。执行方已在 #13 评论 7079110758 提交此 head。使用主干 `47f1f4dd21b7b4bd1f5bc331a6d7561c5ba2b0fd` 的两层判定器和任务卡指定的六份原始输入复跑，返回 0，无 DIFFERENCE 或 REVIEW。实际运行候选生成器，四份报告与提交逐字节相同。[输入、候选及重生成指纹](pr409-recheck.json) · [第一号任务卡](https://github.com/DenseFLoe/Aspen-for-mac/blob/47f1f4dd21b7b4bd1f5bc331a6d7561c5ba2b0fd/handoff/assignments/T9-REPORTS-399.md)

独立核对两张 CSV 的 1,000 个身份，当前预审为 530 pass、470 fail、0 partial、0 blocked。产品与归档状态矩阵和 492 条原因明细均与台账相符。B4 的 455 个失败含 448 个原 PASS、6 个原 PARTIAL:no_il 和 1 个原 PARTIAL:no_claim。其余 15 个原 NOT_RUN 均为 fail。该专项复核可用于千件预审统计，整件静态验收仍使用各自的原件证据。

## 须补正的三处

1. `stats.md` 第 3 节将 Tier A 写成应做 1,000、实做 1,000、覆盖率 100%、未覆盖 15。固定台账的 Tier A 是 985 个 PASS 与 15 个 FAIL，全部 1,000 个均有执行结果。未覆盖应为 0，另列失败 15。修改生成器后重生成。
2. 说明实际核对路径。去掉输入目录中的 selection.csv 后，`tool/t9_reports.py` 仍生成完全相同的四份文件，实际只读 ledger-1000.csv。两张表由固定的 `check-t9-368.py` 逐行核对，`check-t9-reports-399.py` 再检查新报告。请写明这两步及正常生成命令的 `--out handoff/inbox/T9-REPORTS-399`，生成器当前默认输出到旧任务目录。报告所引的同目录 `reconciliation.json` 在本候选不存在，请链接到已归档的实际结果。
3. 固定 head 的交付目录只有四份报告。按第一号任务卡补齐 `s1-started.md`、`s1-submission.md` 或在新轮次按新卡提交回执，记录开工、提交、复跑命令和完整指纹。保留原有历史回执。#409 的更改清单另含六个原生工具文件，未纳入这次报告核验。

复验以新的固定 head 为准。保留已核的双表身份、492 条归因及 448+7 的更正，只需对新版本重跑四报告的生成和对照，再核查以上补正。
