# import_thunks.c

原件为 Plus-Properties 的 APrSystem V15.0/Engine/Xeq/ppexec.dll，文件版本 41.0.0.605，原件 SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。

296 个 AMD64 跳板均通过各自的八字节 IAT 槽尾跳转。每个裸函数有单独的符号、入口和导入名称，通过 rebuild.py 复汇编并按目标 IAT RVA 应用 REL32 重定位，比较得到 296 个一致的完整六字节跨度。后续完整 DLL 链接需要绑定这些槽及其外部组件。

文件 SHA-256 为 97ef8965749a53a059b03f9fe2bad42506d43876a69a44e11fc1ad620da8ec5b。整件结论及复跑方式见 ../ppexec.dll.md。
