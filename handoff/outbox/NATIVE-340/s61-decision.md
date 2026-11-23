# NATIVE-340 s61 裁定

s61 任务卡中的 EH 边界、双宽度链、三态 AL 与两套指纹复验通过。整件仍未通过静态验收。四条 filter 的 IL 偏移在交付中填入类型 token 列，另有 13 条托管和 15 条原生调用未决。续修先绑定四处异常过滤器入口，再追查 0x06000056 与 0x06000057 的 IL_0004 函数指针来源。[复验说明](s61-verifier-notes.md) · [测量记录](s61-recheck.json) · [s65 续领卡](../../assignments/NATIVE-340-s65.md)

任务归 tietoumiao，assigned_seq=61。已开工回执 2026-11-23 09:05 +08:00，固定候选提交 09:22:13 +08:00，#13 两条回执分别为 09:25:40、09:26:31 +08:00。[候选提交](https://github.com/DenseFLoe/Aspen-for-mac/commit/42dc0c03af69288288b70589a6f3064b7887494c) · [首次交付回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7089132352) · [补充回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7089143115)
