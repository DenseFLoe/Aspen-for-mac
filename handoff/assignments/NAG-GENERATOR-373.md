# NAG-GENERATOR-373 · 上游审核生成端门禁

执行方为 upstream。此项接续 NAG-PREFLIGHT 对存量包的核查，可以与原生件任务并行。对象为 #373 的三份新增程序。固定 head 为 `8f5034f02722916e442881a6bd112baef419d1a7`。重报修订须单独记录新的 head 和适用用例。[原 PR](https://github.com/DenseFLoe/Aspen-for-mac/pull/373) · [原提交](https://github.com/DenseFLoe/Aspen-for-mac/tree/8f5034f02722916e442881a6bd112baef419d1a7/tool)

| 原程序 | SHA-256 |
| --- | --- |
| tool/b2_wave.py | `627fc3becb7cd89f2bf90027b68047f28fa5f20e06514c0a1f274b3fbb4956b3` |
| tool/batch_reverse.py | `2a33353dbb07e24f15b2a4f30c8d69883ef29688f849ad327d723f1102c6534e` |
| tool/check_cs_clean.py | `f6989df348c2d3052337f9483b40489dd7512eb20afeb98a83b15eb15c291b85` |

1. 读取固定提交的三个原程序作静态对照，记录每个实际写入点及扫描入口的路径、行号和指纹。保留一份可溯源的实际 ILSpy 原始 stdout 或其既有工件链接、内容 SHA-256、版本与换行方式，核对已知提示的边界。
2. 在 `handoff/inbox/NAG-GENERATOR-373/` 准备 `fixtures.json`、`results.json`、`run.log`、`review.md`。从仓库根用 `python handoff/assignments/check-generator-373.py --emit-fixtures handoff/inbox/NAG-GENERATOR-373/fixtures.json` 写入固定输入（先创建目录）。上游验证器只读提交方提供的产物。云端预检只读候选数据。上游可使用已留存的真实运行证据，也可先审阅固定源码，在本机隔离环境用受控夹具复现无外部副作用的写入路径。缺少完整日志时先验证静态反例，仍缺的输入逐项记入 #13。
3. 提交方的 `run.log` 记录执行环境、三个程序的实际身份、固定输入、两处真实生产路径如何接入、各次写入及门禁退出码。十组输入供两处入口各用一次，并对首次输出再走同一入口。每份原始输出均能关联到日志或工件。上游按这些证据复核 JSON 的来源。
4. `results.json` 顶层包括 `pr_head`、`sources_sha256`（上表路径到完整 SHA-256）、`fixtures_sha256`、`run_log_sha256`、`producers`。后者按两个 `tool/*.py` 写入入口、用例 ID 两级索引。每项存 `once_b64`、`twice_b64`（实际输出字节的 Base64）、`raw_gate_exit`、`after_gate_exit`（真实扫描退出码）。fixtures.json 中的 Base64 为原始输入。
5. 从仓库根执行 `python handoff/assignments/check-generator-373.py`。0 为 20 组输出与门禁值一致，1 为具体行为反例，2 为缺失或无法核验的输入。review.md 写明来源核对、原始工件、反例、复跑结果及上游裁定建议。认定源码存在具体缺陷须带能定位的源片段与固定输入，不得将未执行的输出填作实跑结果。正式裁定和状态由上游另记。
