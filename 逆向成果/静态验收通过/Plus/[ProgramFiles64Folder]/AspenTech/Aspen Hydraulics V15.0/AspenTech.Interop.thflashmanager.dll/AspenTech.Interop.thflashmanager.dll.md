# AspenTech.Interop.thflashmanager.dll 静态验收

- 产品归属 Plus
- 安装基准 Aspen V15.0，原件版本 V15.0
- 原相对路径 [ProgramFiles64Folder]/AspenTech/Aspen Hydraulics V15.0/AspenTech.Interop.thflashmanager.dll
- 原件 SHA-256 5c87a3e33800e6b08b404bbdf34c4fd1f9b06f5b54faf234534296f3ab4462b0
- 交付路线 C# 声明层（原件无 CIL 方法体）
- 结论 **静态验收通过**。核对安装原件、实际编译输入、代码和必要资源，复现结果与原件逐字节一致。
- no-IL 退化类：全部方法为 runtime managed internalcall，无 IL 方法体；CLR 元数据/证书表/强名称/CLR 头按原件保留输入回放；源码负责 PE 骨架、x86 引导桩、.rsrc、.reloc 与声明层，声明经独立 IL 比对全等。不得写成“源码完整重建”。
- Windows 重建与运行对照留待后续阶段。

[可编辑源码、资源及复验证据](<AspenTech.Interop.thflashmanager.dll.source.zip>) · [逐件证据](evidence/发布复核.json)

发布包 SHA-256 cc26b69169bcfbaba6811a8f8773f80b26c6442dc334634fa52ef8e18d05eef4。
