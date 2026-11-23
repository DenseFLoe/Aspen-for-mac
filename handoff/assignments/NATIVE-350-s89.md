# zedstwu.dll s89 续领

NATIVE-350，owner upstream，assigned_seq=89，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 `[0x15c98,0x15cc1)`，片段 SHA-256 `1288ab854e40c127977a18655e781a4fc0e5dc84feb93677bd678af3e1ea5938`。恢复 0x15c98 主体，核对 0x22cc0 与 DL 的短路条件、两处对 0x184f8 的调用与中间的 CL 恢复、被调叶函数的 AL 语义以及 0x1c1ec 展开。查明 0x22cc0 的装载初值与可见写入范围。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-350/s85-decision.md)
