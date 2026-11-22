# phcbio-model.c

原件为 Plus-Properties 的 APrSystem V15.0/Engine/Xeq/ppexec.dll，文件版本 41.0.0.605，原件 SHA-256 为 d93227b9a8f77c09fc1294834b6a4d87ba03a0697a680039fdce35cb1ce4549a。

PPEXEC_PHCBIO 的高层解释依据导出 0x2cc0 的完整指令、DMS_LOCATI 跳板以及 DMS_PLEX 和 DMS_IPOFF6 导入数据建立。保留两次带不同位移的 64 位读取和正值分支。以 Zig cc Windows GNU 目标、-Wall -Werror 编译通过。RAX 的高层结果由模型表示，原语言返回类型和完整 DLL ABI 待验证。逐字节回编针对 ppexec.c 中该入口的实现。

文件 SHA-256 为 82e72bc65f9b5e29976be69f2d963ec18a259846873c77310151b48d530e2113。整件结论及复跑方式见 ../ppexec.dll.md。
