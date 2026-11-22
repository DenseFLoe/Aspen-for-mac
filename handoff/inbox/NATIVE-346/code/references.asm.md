# references.asm

原件为 Plus-Properties 的 APrSystem V15.0/Engine/Xeq/ppexec.dll，文件版本 41.0.0.605，原件 SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。

从原件按 RVA 解码，包含已回编业务函数的指令、其他入口字节和相关调用与数据引用。调用行通过 calls.csv 回链；同一目的导入的调用者与跳板分别留记录。数据导出、路径外指针及寄存器调用的完整语义需进一步核对。

文件 SHA-256 为 66d9bbee66c9d9f3958ad200acedf5727a17fae4c98b9e54ec611eabebe77293。整件结论及复跑方式见 ../ppexec.dll.md。
