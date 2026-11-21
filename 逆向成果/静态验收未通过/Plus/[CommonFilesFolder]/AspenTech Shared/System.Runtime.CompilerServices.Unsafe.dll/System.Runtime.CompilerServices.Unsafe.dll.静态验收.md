# System.Runtime.CompilerServices.Unsafe.dll 第 3 轮静态验收

**静态验收未通过**。第四组于 2026-11-21 核对原件、交付的 C#、IL 清单和资源覆盖。转静态验收修复组，沿用复验组 4。

## 原件与交付

- Aspen Plus V15.0 原路径 `[CommonFilesFolder]/AspenTech Shared/System.Runtime.CompilerServices.Unsafe.dll`
- 安装介质成员 `DBMGR~18.cab` 中的 `system.runtime.compilerservi.00C8CD4F_F851_484A_A03B_6432F5895243`。复用已提取件，文件版本 `6.0.21.52210`，程序集版本 `6.0.0.0`，SHA-256 `37768488e8ef45729bc7d9a2677633c6450042975bb96516e186da6cb9cd0dcf`。
- [C# 交付](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/decompiled/System.Runtime.CompilerServices.Unsafe.dll.cs.txt) SHA-256 `f3acddda69bad8a8c94688c4a02822336857adf437ba359df9b9deaf151c9ff2`
- [IL 清单](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/il/System.Runtime.CompilerServices.Unsafe.dll.il.txt) SHA-256 `684e82133031cdbd79212785532411cd44632b685188ebd616159b40384822a2`
- [原逐件报告](%E5%88%86%E6%94%AF%E4%BA%A4%E4%BB%98/System.Runtime.CompilerServices.Unsafe.dll.md)

## 核对记录

用 PowerShell 7.6.9 的 `Get-FileHash` 核对原件并用 `System.Reflection.Metadata.PEReader` 直接枚举 .NET 元数据。原件有 6 项 TypeDef（含 `<Module>`）、1 项 FieldDef、47 项 MethodDef，其中 47 个有方法体。程序集引用 `mscorlib`。原件方法体另外登记了 0 条异常处理区域。

复查时，从交付 IL 清单的 `MD` 行读取方法令牌和 RVA，再按每条 `IL_` 行的偏移拼接十六进制指令，逐件与 `PEReader.GetMethodBody(rva).GetILBytes()` 比对。全部 47 项 MethodDef 的令牌与 RVA 相符，有体项合计 365 个 IL 指令字节相符。该计数覆盖指令字节，异常处理表单独计数。

## 缺口与复验条件

- C# 交付第 363–364 行是未加注释的 ILSpy 9.1.0.7988 版本提示，直接作为源文件会导致语法错误。
- 原件无托管清单资源。C# 第 38、45 行的两种 `ReadUnaligned<T>` 重载以 `Unsafe.ReadUnaligned<T>` 回调到同名同签名方法，且目录内无 IL 重写或替换步骤。原件 MethodDef `0x06000002` 与 `0x06000003` 都含 `ldarg.0`、`unaligned. 1`、`ldobj`、`ret`，指令字节为 `02fe1201710100001b2a`。`CopyBlockUnaligned` 与 `InitBlockUnaligned` 两对重载也有类似的调用与原 IL 的差异。
- PE 资源目录含类型 16（`RT_VERSION`），目录数据区长度 1296 字节。本件交付缺对应重建输入。

提供可编辑且可重建的实现或 IL 重写输入，覆盖泛型读写与块操作，以方法令牌复验调用目标、非对齐前缀、泛型签名及全部原 IL 语义，并补 PE 版本资源。 Windows 运行对照留到后续阶段。
