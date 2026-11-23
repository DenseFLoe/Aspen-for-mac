# T9 统计（机检预审 · 第二轮更正）

- 总件数 **1000** ｜ pass **530** ｜ fail **470** ｜ partial **0** ｜ blocked **0**
- **2026-11-22 第二轮更正**：455 件 .cs.txt 尾部残留 ilspycmd 升级提示（tool_nag_tail），首轮判据只匹配行首工具名故漏检；结论由 pass 978 更正为 pass 530 / fail 470。产品矩阵、失败原因表、失败明细、README 限制说明与 validation R3 同轮按台账重算，旧汇总 978/15/7 与 537/463 一并作废。
- 机器可读重算结果见同目录 reconciliation.json：逐行取自 selection.csv + ledger-1000.csv 独立复算，不复制任何旧文档数字。
- 固定输入：提交 db544a6fdfb04ec60d182c311aa47d13a61d744b 的 handoff/review/t9-1000/ 六个文件（SHA-256 已逐个核对）。
- 证据档位：已实测 1000（无未验证 / 无法判定行）。
- 选件：待静态验收 916 + 静态验收未通过 84（按路径序）。

## 1. 分产品 × 结论矩阵

| product | 件数 | pass | fail | partial | blocked |
| --- | ---: | ---: | ---: | ---: | ---: |
| Plus | 958 | 519 | 439 | 0 | 0 |
| Plus-Properties | 19 | 4 | 15 | 0 | 0 |
| Properties | 23 | 7 | 16 | 0 | 0 |
| **合计** | **1000** | **530** | **470** | **0** | **0** |

> 更正对照：旧表 Plus 510/448、Properties 23/0，三行相加 537/463，与台账不符。本轮逐行重算：Plus 519/439、Properties 7/16、Plus-Properties 4/15，合计 530/470。

## 2. 分归档状态 × 结论

| state | 件数 | pass | fail | partial | blocked |
| --- | ---: | ---: | ---: | ---: | ---: |
| 待静态验收 | 916 | 470 | 446 | 0 | 0 |
| 静态验收未通过 | 84 | 60 | 24 | 0 | 0 |
| **合计** | **1000** | **530** | **470** | **0** | **0** |

> 归档状态与本次预审结论分别保留：同一原件的归档状态不因预审 verdict 改变。

## 3. Tier A / Tier B 覆盖率（实数）

| 层 | 应做 | 实做 | 覆盖率 | 失败件 |
| --- | ---: | ---: | ---: | ---: |
| Tier A 结构一致性 | 1000 | 1000 | 100.0% | 15 |
| Tier B 内容重算（CLR） | 455 | 455 | 100.0% | 0 |
| Tier B 内容重算（native） | 530 | 530 | 100.0% | 0 |
| Tier B 合计 | 985 | 985 | 100.0% | 0 |

> 应做 = kind ∈ {CLR, native}（含 115 件经 tree 回退重判的变体导出件）；other 15 件为真非 PE / 缺报告，只做 Tier A。
> **Tier B 原始字段分布**（tier_b 列原值，勿与最终 verdict 混读）：PASS 978、PARTIAL:no_il 6、PARTIAL:no_claim 1、NOT_RUN 15。这 6+1 件同时带 tool_nag_tail，最终 verdict 均为 fail，故最终 partial 计 0。

## 4. fail_code 独立行数

| fail_code | 独立行数 | 含义 |
| --- | ---: | --- |
| tool_nag_tail | 455 | .cs.txt 尾部残留 ilspycmd 升级提示（未注释、非合法 C#）；首轮 A6/B4 只匹配行首工具名，漏检 |
| a2_sha_missing | 15 | 归档说明或制作者报告里取不到 64 位 SHA-256（报告缺失 ⇒ 无第二处指纹可比） |
| a3_report_missing | 15 | 制作者报告（v0.*/制作者报告/<name>.md）缺失或为空 |
| tier_b_incomplete | 6 | Tier B 只做一半（CLR 缺 il.txt，tier_b=PARTIAL:no_il） |
| analyze_failed | 1 | 报告自述 status=failed_analyze（反编译失败），无统计数可比对（tier_b=PARTIAL:no_claim） |
| **原因占用合计** | **492** | 多码行重叠，去重后 fail 行 470 |

> 独立行数按「该原因出现在多少行」计，不做去重；同一行可带多个原因。重叠：a2_sha_missing + a3_report_missing 同现 15 行，tier_b_incomplete + tool_nag_tail 同现 6 行，analyze_failed + tool_nag_tail 同现 1 行 ⇒ 占用 492 次 = fail 470 行 + 重叠 22 行。
> tool_nag_tail 分布：Plus 439、Properties 16、Plus-Properties 0；kind 全为 CLR（CLR 共 455 件）；归档状态：待静态验收 446 / 静态验收未通过 9。

## 5. blocked 原因分布

| 原因（fail_codes） | 件数 |
| --- | ---: |
| （无） | 0 |

## 6. 分片执行（件数由台账重算）

| shard | 件数 | 占比 |
| ---: | ---: | ---: |
| 0 | 84 | 8.4% |
| 1 | 84 | 8.4% |
| 2 | 84 | 8.4% |
| 3 | 84 | 8.4% |
| 4 | 83 | 8.3% |
| 5 | 83 | 8.3% |
| 6 | 83 | 8.3% |
| 7 | 83 | 8.3% |
| 8 | 83 | 8.3% |
| 9 | 83 | 8.3% |
| 10 | 83 | 8.3% |
| 11 | 83 | 8.3% |

> idx % 12 分片，12 片并行；墙钟用时见分片日志，不属本轮可复算字段。

## 7. 口径限制

- 这是**机检预审**，不是上游 P0–P3 终判：原件二进制不在仓库，语义层与运行期证据一律未做。
- Tier B 是「我方产物自证」（数 IL/ASM 条目 vs 报告声称值），不是用 dnfile/pefile 从原件重算。
- B3 占位符命中只登记不判 fail（无法区分原版行为与恢复缺口）。

# 原判定与现判定分列（第二轮更正）

| 原 Tier B 判定 | 件数 | 现在 | 去向 |
| --- | ---: | --- | --- |
| PASS | 978 | pass 530 / fail 448 | 448 件尾部残留 ilspycmd 提示（B4 tool_nag_tail）转 fail |
| PARTIAL | 7 | fail 7 | 7 件原 partial（no_il 6 / no_claim 1）全部转 fail |
| NOT_RUN | 15 | fail 15 | a2/a3/tier_b/analyze_failed 等既有失败 |
| 合计 | 1000 | pass 530 / fail 470 | B4 的 455 个失败 = 原 PASS 448 + 原 PARTIAL 7；本表保留旧回执口径，不覆盖 |
