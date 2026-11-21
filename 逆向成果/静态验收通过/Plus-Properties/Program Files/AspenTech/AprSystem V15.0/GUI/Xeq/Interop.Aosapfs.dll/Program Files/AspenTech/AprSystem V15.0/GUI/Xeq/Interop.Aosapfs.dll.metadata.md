# Interop.Aosapfs.dll · 原始 IL 与 COM 属性映射

轮次 20261119-01，原版逐文件静态逆向已验收。本件与同目录另外两份成果共同覆盖原文件。

## 来源与范围

- Plus 安装包：`C:\Users\Administrator\Desktop\AspenONE V15.0(1)\3-ENG\Aspen-V15-ENG (2)\aspenONEMedia\aspenonesuite\Process Modeling (Aspen Plus) V15 (64bit)\Process Modeling (Aspen Plus) V15 (64bit).msi`，CAB `C:\Users\Administrator\Desktop\AspenONE V15.0(1)\3-ENG\Aspen-V15-ENG (2)\aspenONEMedia\aspenonesuite\Process Modeling (Aspen Plus) V15 (64bit)\APRS~423.cab`，成员 `interop.aosapfs.dll.01AE6323_4069_4985_B882_1C2F459EE258`。
- Properties 安装包：`C:\Users\Administrator\Desktop\AspenONE V15.0(1)\3-ENG\Aspen-V15-ENG (2)\aspenONEMedia\aspenonesuite\Aspen Properties V15 (64bit)\Aspen Properties V15 (64bit).msi`，CAB `C:\Users\Administrator\Desktop\AspenONE V15.0(1)\3-ENG\Aspen-V15-ENG (2)\aspenONEMedia\aspenonesuite\Aspen Properties V15 (64bit)\APRS~423.cab`，成员 `interop.aosapfs.dll.01AE6323_4069_4985_B882_1C2F459EE258`。
- 已安装副本 `C:\Program Files\AspenTech\AprSystem V15.0\GUI\Xeq\Interop.Aosapfs.dll`。两个 CAB 成员及该副本逐字节 SHA-256 相同，大小均为 39,464 字节。
- 程序集版本及原文件版本均为 5.0.0.0。原 SHA-256 为 `05f0b74afdc7a1c46f2a4f4f37fb35ca46526133ed2b937ebca8d71fb46a5b7d`，分析键 `sha256:05f0b74afdc7a1c46f2a4f4f37fb35ca46526133ed2b937ebca8d71fb46a5b7d`。
- 本件路径 `.local/reverse-round-20261119-01/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Interop.Aosapfs.dll.metadata.il`。成果 SHA-256 为 `a8e596f7a9709b3f02cb9fe166564d41472ac3c0a75e8ea6e1af2512a4ffef21`，大小 150,732 字节。

ILSpy 的未修订整模块 IL。覆盖空 <Module> 及 114 个用户类型。IAPFSControl 类型下的两条 .property 记录可与四条 .get/.set 定义、原参数和不同的 DispId 相互定位。模块级元数据及 PE 版本资源见同目录 .abi.zip。

## 验收证据

- 在仓库根目录下查看 `.local/reverse-round-20261119-01/interop-evidence/plan.json` 中的验收方法、四份分类清单指纹、精确来源行及 15 份历史局部输出。`input-proof.json` 记录两次独立 CAB 取件命令、容器指纹和安装文件复核。`commands.json` 记录 ILSpy 9.1.0.7988 的完整导出命令。两次完整导出的 stderr 为空。
- `.local/reverse-round-20261119-01/interop-evidence/coverage.json` 与 `validate.py` 记录 dnfile 0.18.0 的原始元数据及 Roslyn 5.0.0.0 的 C# 语法树对照。336 个方法定义按类型、槽位顺序、返回及参数类型/引用形式核对，336 项 RVA 均为零，原始标志为 COM 导入接口的 Abstract、Runtime、InternalCall。PE 入口是到 mscoree!_CorDllMain 的跳转。托管资源为零。
- 透明枚举底层字段 4 项由 C# 语法隐含。共 187 项字段，17 项枚举常量、51 项结构布局、15 项字段偏移、5 项接口继承、210 项封送和 191 条自定义特性全部核对。两项具名属性、四个访问器经 PropertyMap、MethodSemantics、原 IL 和元数据签名核对；59 个导入接口的 GUID 和两项 DispId 分别核对。
- ILSpy 原始输出 `assembly.cs` 将带参 BlockPosition 输出为无参普通属性。`correction.diff` 只修正这一投影，两个访问器均保留原索引及 set 的值参数。C# 中显式方法、IL 中的具名属性以及 ZIP 中的原始 Property 和 MethodSemantics 表一起保存此接口语义。另一个普通属性 Viewport 的签名正确。
- 独立原输入、未修订输出、修正差异、语法树、操作脚本和核对日志均在 `.local/reverse-round-20261119-01/interop-evidence`。原资源叶 SHA-256 为 `e11062ad26f65e98f35177fe5cd53f3ca62fa5827ff2fa1ac60aebbbb7422574`，ZIP 分项用解包后逐字节比较。原包签名及强名称区域有指纹，原件全文保存在本机。

## 边界与下一步

本件通过阶段 2 的静态归档。接口实现由外部 COM 服务端在运行时提供；程序集引用表中只有 mscorlib 4.0.0.0。没有待恢复的本文件方法体。已按原定义保存外部边界，本轮停止连锁。进入后续 Windows 验收时应由实际服务端检查 COM 调用以及 BlockPosition 的索引参数传递；本轮未进行构建或运行观察。
