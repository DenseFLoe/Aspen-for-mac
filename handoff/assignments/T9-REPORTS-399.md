# T9-REPORTS-399 · 千件预审报告修订

执行方为 tietoumiao，assigned_seq=1，时限自上游在 #13 发布本卡 ACK 起 24 小时。交付目录为 `handoff/inbox/T9-REPORTS-399/`。适用 [T9 预审报告交叉核对 v1](../standards/t9-reconciliation.v1.md)。上游原有 `T9-368-RECONCILE` 首轮核对及回执已归档。

**固定输入。** 使用 `db544a6fdfb04ec60d182c311aa47d13a61d744b` 的 `handoff/review/t9-1000/` 目录内六个文件，其中 selection.csv SHA-256 为 `d5de1f69c1c56e375883aec40369e73caaa240f38b4fb73e0f7e7e873022506c`，ledger-1000.csv 为 `1312903e8fdf474cf985c356809495d3b80c5f141b289684134ae167fce70663`。其余四份旧报告的完整 SHA-256 已由 [check-t9-368.py](check-t9-368.py) 固定。修订底稿为 #399 的 `c4f2ff4d126936da46af988ca083bbb9521ed5f0`，取其 `handoff/inbox/T9-368-RECONCILE/` 下的 README.md、stats.md、failures.md 和 validation.md，以及 `tool/t9_reports.py`。按[固定 #399](https://github.com/DenseFLoe/Aspen-for-mac/tree/c4f2ff4d126936da46af988ca083bbb9521ed5f0/handoff/inbox/T9-368-RECONCILE)查看旧候选。四报告对应 SHA-256 依次为 `8856c51d71541f86a40894fd4dc429e891b0b5840e9e95e88e7c3da470a71198`、`4017ce61682f7a6548c6760cdea5678dd0b251e41a46c0ac24dd6d4039fd6ac0`、`721af5b39d872112bbe5c08a7790edb0a3ab8cf52de84e8e2a02a9ad6bef5310`、`1ce0514ac4d6572cac7928254f535d357175aa7400ea541547dcba74592584c5`。

**修订范围。** 在新目录发布四份可重生成的报告和相应生成器，回执使用该目录的 s1-started.md、s1-submission.md。保留原 T9 核对任务的历史回执和 455 件单文件交付。本任务只负责预审报告。上游逐件静态验收继续使用每个原件自己的证据。

1. 用两张固定 CSV 逐行核对 1,000 个身份。产品及归档状态矩阵、五类原因独立行数、492 个归因条目（对应 470 个 fail）、每行的 idx、分片、产品、对象目录和 verdict 均须与台账一致。README、stats、failures、validation 四份报告给出 530/470/0/0 的当前口径，validation 的 R3 与明细一致。
2. 在 validation 的更正说明里写清 455 行的来源：448 个原 pass、7 个原 partial。保留旧 Tier B 列原值（978 PASS、6 PARTIAL:no_il、1 PARTIAL:no_claim、15 NOT_RUN）的意义。stats 按新版 B4 计数时，CLR 失败数与 Tier B 失败合计均为 455。若并列旧字段，须给旧字段明确标记。解释覆盖或执行次数与新版失败数的关系。
3. 说明实际由哪个程序核对两张 CSV 的逐行身份，哪个程序从哪些文件生成报告。若生成器只读台账，明确指向执行双表核对的固定上游检查器。提交复跑命令、输入及生成文件指纹，上游将重生成四报告并与交付逐个对照。

**判定命令。** Python 3.9+，在仓库根执行 `python -B handoff/assignments/check-t9-reports-399.py`。离线复跑可加 `--input-dir <六份固定输入的目录>`，复验其他工作目录可加 `--reports <四份候选报告目录>`。检查器先校验六份原始输入，再核对新目录下四份真实报告。退出 0 表示已识别的定量检查通过；2 表示查到数值或逐行差异；3 表示版式或表述需要上游人工核实；输入或运行错误退出 1。语义等价的表述可按同一台账人工核对，上游另审更正说明、生成器及本轮提交范围后作正式裁定。
