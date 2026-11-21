# AspenTech.AspenPlus.Engine.Structures.dll

## 原件与范围

Aspen Plus V15 的安装包成员 `aspentech.aspenplus.engine.s.9DD71637_68A3_4F40_BE0C_34ABF98F3116` 来自 `APRS~202.cab`，复用已有提取件。文件版本 `41.0.0.39`，程序集标识版本 `41.0.0.0`。原件 SHA-256 为 `f11a69eb9b44250f1f6bc69878b6a72bcb6eab1181badf8ba114e337e30610ac`。四条同指纹来源分别对应 Plus 安装包、独立 Properties 安装包、Properties Enterprise Database Server 安装包及本机共用安装路径。[来源记录](../../../../../evidence/sources.json)

恢复 Gensen 输入段落与语句定义、变量和数组规格转换、报表生成及工厂分派。源码中的 `FormulaParagraph` 声明输入语法及字段，版本资源是唯一的 PE 资源。原件没有 CLR 清单资源或界面布局。

## 静态验收

- ILSpy 9.1.0.7988 导出 C# 和带定义令牌的 IL。dnfile 0.18.0 及 dncil 1.0.2 核对 447 个类型、635 个字段、176 个属性、1 个事件和全部 1,342 个方法定义。逐条核对了 1,328 个方法体内的 386,249 条指令。
- Roslyn 5.0.0 使用四个直接引用生成临时程序集并通过静态绑定。按指令、操作数与异常区域核对，1,286 个方法体一致，11 个方法体仅涉及生成名称重编号，9 个闭包保留了相应的数组、转换和赋值。另有 22 个方法体核对了分支、局部变量或向量捕获差异。最长的 `PresReliefParagraph` 构造器有 31,086 条指令，回编结果完整对应。
- 其余 10 个抽象定义和 4 个委托运行时定义均有原件依据。 `UnitOperationDefinition.Report(StreamWriter)` 在原件中直接抛出 `NotImplementedException`，已保留。Roslyn 自动生成原件的 `RefSafetyRules(11)` 模块属性，源码在同一位置注释记录原声明。编译器报告一条隐藏级别的未使用引用指令提示。
- 唯一的 Windows 版本资源有 1,182 字节，RC 读回复原与原数据逐字节相同。[方法令牌映射](../../../../../evidence/methods.csv) · [托管核验](../../../../../evidence/managed-audit.json) · [资源核验](../../../../../evidence/resources.json)

## 归档与后续

本件通过静态逆向验收。`AspenTech.AspenPlus.Engine.Structures.dll.cs` 的 SHA-256 为 `b1402e630e15b971bb0c5c1ed460cc26c08045036d55e6811d192afe9c321940`。原始指令字节版 IL 证据保存在本机。Windows 重建阶段复验强名程序集绑定、引擎调用及数据转换行为。
