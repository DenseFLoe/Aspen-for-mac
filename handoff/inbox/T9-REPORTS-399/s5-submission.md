# s5-submission · T9-REPORTS-399（第五号续领）

- 执行方: starter-t15（代 tietoumiao 本轮交付）
- 任务: T9-REPORTS-399 s5，assigned_seq=5
- 卡: `handoff/assignments/T9-REPORTS-399-s5.md»
- 开工: `s5-started.md»（本目录）
- 固定输入: `db544a6fdfb04ec60d182c311aa47d13a61d744b» 的 `handoff/review/t9-1000/» 六份文件
- 修订底稿: #409 `0d30dcef836dcdf814e01e41282799f2e33bc4e3»（四报告 + `tool/t9_reports.py»）
- 判定命令: `python -B handoff/assignments/check-t9-reports-399.py»（仓库根）

## 0. 本轮做了什么（先看结论）

| 项 | 状态 |
| --- | --- |
| 四份报告重生成 | ✅ 由本目录 `t9_reports.py» 从 `ledger-1000.csv» 生成（生成器 exit 0） |
| checker 真实 exit | **0**（原始 stdout：「fixed rows=1000, pass=530, fail=470, reason memberships=492, correction=448+7, CLR B4=455」，无 DIFFERENCE / REVIEW） |
| s5 卡三条硬要求 | ✅ Tier A 口径改 1,000 已执行 / 未覆盖 0 / 失败 15 另列；✅ 补可复现命令 + 生成器 + 指纹；✅ 纠正 reconciliation.json 位置 |
| 与 #409 的差异 | `failures.md» 逐字节相同；`README.md»/`stats.md»/`validation.md» 因更正口径与补文而变 |
| 数字来源 | 全部由脚本从两张固定 CSV 重算（第 3 节逐个给行列） |

## 1. 三处补正（s1-decision 要求，逐条对应）

1. **stats §3 Tier A 口径**：原文「应做 1,000 / 实做 1,000 / 覆盖率 100% / **未覆盖 15**」→ 现为 **未覆盖 0**，另加一行说明「台账 tier_a 列为 PASS 985 + FAIL 15 = 1,000，全部有执行结果；15 件 FAIL 即 a2_sha_missing + a3_report_missing，在 §4 单列，不从已执行里再扣一次」。表格行现为：
   `| Tier A 结构一致性 | 1000 | 1000 | 100.0% | 0 |»
2. **核对路径与生成命令**：README 与 validation 都写明——两张 CSV 的逐行身份由固定 `handoff/assignments/check-t9-368.py» 核对（SHA-256 `ff2fbcd5873e5d86d4912417dccdc39eb6d638fef701a80dd8c047f00e9a58b1»，被 check-t9-reports-399.py 以 `REFERENCE_SHA» 钉住）；本目录生成器**只读 ledger-1000.csv**。生成器 `--out» 默认值由旧任务目录 `handoff/inbox/T9-368-RECONCILE» 改为 **`handoff/inbox/T9-REPORTS-399»**。详见第 4 节命令。
   实测反例（写进报告）：把 `selection.csv» 移出输入目录后重跑，四份报告**逐字节相同** → 证明生成器不读 selection.csv。
3. **reconciliation.json 位置**：本候选目录**没有**该文件。固定结果归档在 **`handoff/inbox/T9-368-RECONCILE/reconciliation.json»**（T9 交叉核对 v1 §3 指定位置；`check-t9-368.py» 的 `RESULT» 常量同样指向该路径，见该文件第 22 行）。stats、README、validation 里原先的「同目录 reconciliation.json」已全部改指该归档路径。原写法错在：把「同目录」（即 `handoff/inbox/T9-REPORTS-399/»）当成固定结果所在处，而该目录从来只有四份报告。

## 2. checker 原始 stdout 与真实 exit

命令（仓库根，未加 `--input-dir»，走默认固定输入）：

```
$ python -B handoff/assignments/check-t9-reports-399.py
fixed rows=1000, pass=530, fail=470, reason memberships=492, correction=448+7, CLR B4=455
$ echo $?
0
```

离线复跑（六个固定输入放本地目录）：

```
$ python -B handoff/assignments/check-t9-reports-399.py --input-dir handoff/review/t9-1000 --reports handoff/inbox/T9-REPORTS-399
fixed rows=1000, pass=530, fail=470, reason memberships=492, correction=448+7, CLR B4=455
$ echo $?
0
```

两次均为 **exit 0**，stdout 无 DIFFERENCE、无 REVIEW 行；退出码直接取命令自身（没有经过管道，未用 `| tail» 取 `$?»）。

## 3. 每个数字 → CSV 行/列（自检）

台账 = `handoff/review/t9-1000/ledger-1000.csv»（1,000 数据行 + 表头；列：idx,shard,state,product,name,item_dir,relative_path,sha256,kind,tier_a,tier_b,verdict,fail_codes,evidence,evidence_level）。下表每个值都由脚本对该列重算，不是抄旧文档。

| 报告里的数字 | 台账出处（列/筛选） | 实测 |
| --- | --- | --- |
| 1000 | `ledger» 数据行数；idx 0–999 完整性 | 1000 行，idx 无缺无重 |
| 530 / 470 / 0 / 0 | `verdict» 列计数 | pass 530、fail 470、partial 0、blocked 0 |
| 958 / 19 / 23 | `product» 列 | Plus 958、Plus-Properties 19、Properties 23 |
| 519/439、4/15、7/16 | `product» × `verdict» | Plus 519 pass·439 fail；Plus-Properties 4·15；Properties 7·16 |
| 916 / 84 | `state» 列 | 待静态验收 916、静态验收未通过 84 |
| 470/446、60/24 | `state» × `verdict» | 待静态验收 470 pass·446 fail；静态验收未通过 60·24 |
| 985 / 15 | `tier_a» 列 | `PASS» 985、`FAIL:a3_report_missing,a2_sha_missing» 15 |
| 978 / 6 / 1 / 15 | `tier_b» 列（原值） | PASS 978、PARTIAL:no_il 6、PARTIAL:no_claim 1、NOT_RUN 15 |
| 455 | `fail_codes» 含 `tool_nag_tail» 的独立行数 | 455（且 `kind» 全为 CLR，CLR 共 455） |
| **448 + 7** | 上述 455 行的 `tier_b» 前缀 | 原 PASS 448 + 原 PARTIAL 7（no_il 6 + no_claim 1） |
| 15 / 15 / 6 / 1 | `fail_codes» 中 a2_sha_missing / a3_report_missing / tier_b_incomplete / analyze_failed 的独立行数 | 15 / 15 / 6 / 1 |
| **492**（归因占用） | 五个码独立行数之和 | 455+15+15+6+1 = 492 |
| 22 | 多码行数（`fail_codes» 含 `;» 的行） | 22（= 492 − 470） |
| **470**（身份行数） | `verdict=fail» 行数 | 470 |
| 530 / 455 / 15 | `kind» 列 | native 530、CLR 455、other 15 |
| 84×4 + 83×8 | `shard» 列 | 0–3 各 84；4–11 各 83（合计 1000） |
| 439 / 16 / 0 | `tool_nag_tail» 行 × `product» | Plus 439、Properties 16、Plus-Properties 0 |
| 446 / 9 | `tool_nag_tail» 行 × `state» | 待静态验收 446、静态验收未通过 9 |
| 135 | `evidence» 含 `b3_cs_hits=» 的行 | 135（观察项，不判 fail） |
| 115 变体导出件 | `evidence» 的 `rekind=kind_hint=other->native(src=tree:…)» | 100（`.asm.txt,.c.txt»）+ 15（`.asm.txt»）= **115**；另有 9 行 `native->native» 不计入 |

**455 的正确说法（按卡要求带限定词）**：旧称「455 件假 pass」**作废**；准确表述是 **Tier B 的 B4 失败 455 件 = 448 件原 pass + 7 件原 partial**，stats §4 与 validation「原判定与现判定分列」表同口径。

**448+7 与 492 不是一个量**：448+7 是 B4 失败的**身份构成**（455 件各自原先的判定），492 是 fail_code 的**归因占用次数**（允许一行多码），470 才是 fail 的**身份行数**。三者在 stats §4、README 限制、validation s5 更正第 5 条都分别标注，互不替代。

## 4. 可复现命令（别人在本轮目录直接跑出同样四份报告）

仓库根、Python 3.9+：

```bash
# 0) 六份固定输入逐个核对 SHA-256，并与归档 reconciliation.json 对照
python -B handoff/assignments/check-t9-368.py --input-dir handoff/review/t9-1000

# 1) 从台账重生成四份报告（本目录生成器；--out 默认 handoff/inbox/T9-REPORTS-399）
python -B handoff/inbox/T9-REPORTS-399/t9_reports.py \
    --input-dir handoff/review/t9-1000 --out handoff/inbox/T9-REPORTS-399

# 2) 核对重生成结果
python -B handoff/assignments/check-t9-reports-399.py \
    --input-dir handoff/review/t9-1000 --reports handoff/inbox/T9-REPORTS-399
```

本轮实跑：第 1 步 exit 0，第 2 步 exit 0。重生成的四份与提交逐字节相同（指纹见第 5 节与 `fingerprints.txt»）。

## 5. 指纹

固定输入（提交 db544a6f，逐个与 check-t9-368.py 的 SHA256 表相同）：

```
453dc4ac06f99b96ff319d00bf2d7049dde96362c473a5edf4c01638012e51e1  README.md
888b636a3d91c5d7a9214bde38c6bebbad4e49d33abc1349312772e35e74e70d  stats.md
083cc7a9690633e34006b836c3846a860d4aa779d3a44d956e976916d6cf2863  failures.md
f6d94bc8fa6b680b5455e0ed3cf9acb7857eb31f64af5abf9301c05f4dd5b963  validation.md
d5de1f69c1c56e375883aec40369e73caaa240f38b4fb73e0f7e7e873022506c  selection.csv
1312903e8fdf474cf985c356809495d3b80c5f141b289684134ae167fce70663  ledger-1000.csv
```

本轮输出（本目录）：

```
db87f03ab021a2a4f7270251132ac62dc960156cea08b0bb6d30edf6df42a07c  README.md
86dde84da2cea889a7b92ed370266883462ca7d6d8bb9480a2e4265cb9f6d849  stats.md
721af5b39d872112bbe5c08a7790edb0a3ab8cf52de84e8e2a02a9ad6bef5310  failures.md
1435aa61fb1b601ba8df7b3d3a39112629bf1de28e659f66c087ba59b697f24c  validation.md
8195e97114f53e73187dad84d609a16c6162c3a559a8058e57023f3a53175c3d  t9_reports.py
```

判定器：`check-t9-368.py» = `ff2fbcd5…e9a58b1»，`check-t9-reports-399.py» = `55abe043…4252518»。

## 6. 提交形态

- 分支: `tietoumiao/t9-reports-399-s5»
- PR 标题: `[READY s5] T9-REPORTS-399»
- 本目录清单：`README.md»、`stats.md»、`failures.md»、`validation.md»、`t9_reports.py»（生成器）、`fingerprints.txt»、`s5-started.md»、`s5-submission.md»
- 保留历史：`handoff/inbox/T9-368-RECONCILE/» 与 455 件单文件交付未动；`handoff/inbox/T9-REPORTS-399/received-0d30dcef/t9_reports.py» 为上游留存的上轮收件，未覆盖。
- 未纳入本轮：`tool/» 下六个原生工具文件（#409 同 PR 携带，属另一事项，本任务只负责预审报告）。

## 7. 三档收账

**已实测**：六份固定输入 SHA-256；1,000 行身份（idx 完整、item_dir 唯一由固定 check-t9-368.py 核）；530/470/0/0、产品与状态矩阵、985/15、978/6/1/15、455、448+7、15/15/6/1、492/22/470、530/455/15、分片 84×4+83×8、135 B3、115 变体件；checker 两次 exit 0；重生成逐字节相同；移走 selection.csv 后仍逐字节相同。

**未验证**：原件二进制不在仓库，语义层（类型用途、调用约定、逻辑等价）与运行期行为一律未做；Tier B 是「我方产物自证」（数 IL/ASM 条目 vs 报告声称值），不是从原件重算。

**无法判定**：B3 命中的 135 件是否真是原版行为（无法区分原版抛 NotImplementedException 与恢复缺口），只登记不判 fail；「静态验收未通过」84 件的最终结论仍由各件原件级验收决定，本报告不替代。
