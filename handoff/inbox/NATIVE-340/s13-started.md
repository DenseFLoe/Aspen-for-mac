---
task_id: NATIVE-340
type: started
state: planning
seq: 13
at: 2026-11-22T21:21:41+08:00
baseline: a0b8a11853f70d32870b9d0aa15267572c1ffb0a
---
已开始 s13（assigned_seq=13）：按 handoff/assignments/NATIVE-340-s13.md 逐项核对 CLR VTableFixups、newobj、其他间接转移、非空 TypeDef 方法范围与 0x3660 两次加载；保留 61 条跨界调用。

口径确认：工具自由、产物无工具署名、exit 2 可接受；calls.csv 保留 unresolved 并逐行给恢复条件，indirect.csv 作附件。
