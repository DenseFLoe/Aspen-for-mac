# references.asm 静态证据说明

对应 ApwnIPShell.dll 41.0.0.614，原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，成果 SHA-256 为 `47ef7f338b74a7664478743f6f16c100e9c41e48f37e6fa47f78344debb2f2b8`。

按 RVA 保存从原件解码的入口、外部转移和数据引用的指令字节与操作数。每个地址只列一次；calls.csv 的行号可回到相应原件指令。表内 639 处间接转移待关联接收者或函数指针。s5/refresh.py 可从固定原件与上轮 Ghidra 函数区间重新生成。
