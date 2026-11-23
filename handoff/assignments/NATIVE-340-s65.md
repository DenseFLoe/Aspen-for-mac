# NATIVE-340 s65 续领

owner tietoumiao，assigned_seq=65，自 #13 ACK 起 24 小时。固定原件 SHA-256 `869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec`。从 [#450 @ 42dc0c03](https://github.com/DenseFLoe/Aspen-for-mac/tree/42dc0c03af69288288b70589a6f3064b7887494c) 继续。

按 EH 子句种类解读末字段，保留原始整数。catch 写出类型 token，filter 写出 IL 偏移，finally/fault 保留原始值并标注字段用途。核对 0x06000056/57/58/5B 的 filter 起点 0x0B/0x0B/0x0F/0x1E、handler 起点 0x18/0x18/0x1C/0x2B、末端 endfilter，并用独立读取器核对 7 个 catch。用同一有效样本只改交付中的一个 filter_offset，更新随之变化的指纹，语义比对应能定位错误行。

静态查 0x06000056 和 0x06000057 的 IL_0004 calli，核对 arg0 → loc0 的目标来源、arg1、签名 0x11000075、原件可见的调用者及其传参。能证明的目标再归类，仍受外部调用者或运行期指针限制的逐条写清缺失生产者和恢复条件。保持 s61 的 EH 范围、六张表中的三态 AL、双审计及两套指纹通过。复跑 [s61 复验命令](../outbox/NATIVE-340/s61-verifier-notes.md) 和固定主干覆盖检查，向 #13 回报新 head 和结果。
