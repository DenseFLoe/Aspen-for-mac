# ILSpy 生成器修订复验 v1

本标准用于 #373 退回后提交的新代码。行为要求继承 [generator-guard.v1](generator-guard.v1.md)。十个固定输入逐字节沿用主干 `7f909cc1e03e785e1165c110ac857a6ba9a3888a` 的 check-generator-373.py，fixtures.json 的 SHA-256 为 `bdfc2ae821e1d202e227ecace50656c34b879e055c35124a33d7b1a04e3aeb11`。该夹具文件内的旧 head 是输入集来源。修订代码身份单独记录在 results.json 中。

1. 在 Windows 上每个正式写入入口分别处理十种输入。每次在新目标目录生成实际文件，再将首次输出原始字节送回相同入口。两个目标均须实际存在，包括预期为零字节的用例。用真实扫描器分别读取原始输入和首次写入的目标，记录进程退出码。固定 [ILSpy 工件](../inbox/NAG-GENERATOR-373/review.md) 记录版本、换行及 SHA-256，并对两处修订入口额外回放。review.md 列出清除提示后的预期及实得指纹。
2. fixtures.json 可从原审核的 [fixtures.json](../inbox/NAG-GENERATOR-373/fixtures.json) 按字节复制。results.json 沿用原结构。pr_head 写测试代码的完整新提交。sources_sha256 按三个正式源路径记录新 SHA-256；新增助手另列 additional_sources_sha256。run_log_sha256 与 fixtures_sha256 绑定实际文件。producers 保留两个生产路径作键，十个用例各列 once_b64、twice_b64、once_present、twice_present、raw_gate_exit 和 after_gate_exit。存在性字段为 JSON 布尔值。原始运行日志按用例记录源入口、被测输出路径或可定位标识、实际字节数、指纹及扫描退出码。初次或重写未创建文件时，如实记录。
3. 任务行的受信命令按输入提交从本仓库读取三份源码及声明的助手原始字节，核对 SHA-256，再核对实际结果与旧基准定义的期望。独立验收时从连接器取得代码 PR 的最新 head，传入 `--expected-head <该完整 SHA>` 再核对当前候选树中的相同路径。如果证据单独提交，则同时记录证据 PR head。提交前后的代码内容有变化时，按新代码提交重新实跑。合并使用当前已核实的代码 PR head。
4. 判定器退出 0 表示所有提交身份、夹具、输出和门禁断言成立。退出 1 列出行为差异或被退回的旧提交，退出 2 表示输入、来源、日志或指纹缺失或不一致。上游另对照 PR 全部变更、真实写入路径、stdout 来源、实际工件回放，确认生产者与日志可追溯后裁定。旧 check-generator-373.py 和旧审核证据继续可重放。
