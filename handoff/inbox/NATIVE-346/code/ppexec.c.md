# ppexec.c

原件为 Plus-Properties 的 APrSystem V15.0/Engine/Xeq/ppexec.dll，文件版本 41.0.0.605，原件 SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。

可编辑的 AMD64 内联汇编包括全部 21 个具名代码导出及 19 个内部实现。分支使用汇编标签，外部代码、IAT 和静态数据按原 RVA 命名。编译器采用 Zig 0.13.0 cc 的 Windows GNU 目标。reassembly.json 按函数记录每处重定位和原始跨度的字节摘要。少量对齐 NOP 保存特殊机器编码。绑定到完整 DLL 时仍须恢复其余函数、数据、导入以及展开和加载元数据。

文件 SHA-256 为 c4113bd79096e4aed273da35d47f6ddfefdd5674d7117b44b5a5b68b7bc17ba5。整件结论及复跑方式见 ../ppexec.dll.md。
