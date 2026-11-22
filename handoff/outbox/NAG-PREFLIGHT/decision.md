# NAG-PREFLIGHT 上游裁定

接受 #369 与 #370 的全量预检交付。上游在固定证据上独立运行 `python -B handoff/inbox/NAG-PREFLIGHT/preflight.py --check`，退出 0，并在原 PR 差异中核对了 SLMServerCLS.dll 对应目标的版本变更及类型删除。检查 504 个修改路径，72 个只删指定尾部两行，384 个同时改变换行，48 个在归一换行后仍有其他变化。428 份正式导出说明仍引用旧指纹与字节数。

#370 的 head `b7391aa8cabacad7104de1d8c8e83ca5eaa69540` 退回修正并保留原 PR。复验采用目标完整路径、相应旧 SHA-256 和限定的尾删规则，保留同名异版本，核对修订版指纹说明。上游已在 #13 告知可复现的反例。修订前请先回报拟修范围与新 head，以免重复导出原批次。详细证据见[预检报告](../../inbox/NAG-PREFLIGHT/report.md)。
