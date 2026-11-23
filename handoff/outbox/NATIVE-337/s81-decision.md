# NATIVE-337 s81 裁定

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ 661da2d](https://github.com/DenseFLoe/Aspen-for-mac/tree/661da2d59e2eb20cccdd6932e1dba5c8cde53a16)。主干基线 581aa65bc65667e09760dda9e5b954290d9d7e2b。

原件逐条对照确认 ShowDialog、两条 Release、DISPID 从 [rsp+0xc8] 进入 Invoke，以及失败返回 0。11 条表记录的指令字节一致，161 个两跳站和三种布局复现。GetIDsOfNames 参数表错位。0x137f 令 RDX 指向 IID_NULL，0x1377 令 R8 指向名称数组，0x1374 给 R9D 写 cNames=1，栈 [rsp+0x20] 为 LCID。0x13a7 的 64 位写入给出 cArgs=1、cNamedArgs=0。由 0x1449 和 0x1469 只能确认 HRESULT 成功时返回结果 VARIANT 的低 32 位，服务器成员和结果类型待绑定。覆盖 v1 为 307/307/684/0，退出 2，112 条未决。开工回执时间精度只到 11:5x，台账采用首次固定提交 03:49:40 UTC。 [GetIDsOfNames ABI](https://learn.microsoft.com/en-us/windows/win32/api/oaidl/nf-oaidl-idispatch-getidsofnames) · [DISPPARAMS 布局](https://learn.microsoft.com/en-us/windows/win32/api/oaidl/ns-oaidl-dispparams)

裁定 returned。覆盖命令、输入和实测见[复验记录](s81-verifier-notes.md)。交付复验证据 SHA-256 c713b7c335085745b026d0cf284603f8b781b55c9f741cca157ac83473739ed3。

[开工回执](../../inbox/NATIVE-337/s81-started.md) · [交付回执](../../inbox/NATIVE-337/s81-submission.md) · [续领卡](../../assignments/NATIVE-337-s85.md)
