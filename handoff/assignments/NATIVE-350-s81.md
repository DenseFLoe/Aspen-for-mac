# zedstwu.dll s81 续领

NATIVE-350，owner upstream，assigned_seq=81，自 #13 ACK 起 24 小时。zedstwu.dll 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

恢复 [0x15bdc,0x15c74)，片段 SHA-256 `81780160b17c32a33bbbc2558815727294f8c1e334451a70b9c2bfeec2c823e7`。恢复 s77 过滤器的完整宿主，核对 0x15be8/0x15bf1/0x15bf8 的 PE 头引用、节范围迭代与属性位、0x15c6d 恢复分支，以及 0x1c1ac 的展开与过滤器范围记录。

按[上游原生覆盖 v1](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和局部回编，记录缺口与证据指纹。[上轮裁定](../outbox/NATIVE-350/s77-decision.md)
