# AspenTech.NGP.Infrastructure.dll

Aspen Plus V15 安装包 `APRS~203.cab` 成员 `aspentech.ngp.infrastructure.9DD71637_68A3_4F40_BE0C_34ABF98F3116`。文件版本 `41.0.0.39`，程序集版本 `41.0.0.0`，原件 SHA-256 为 `3e360a5dcdf5347db0af25e0a45830022b5df5edbba035fdeb77f1e87f40dbdf`。四条同指纹来源是 Plus、独立 Properties、Properties Enterprise Database Server 三个包成员及本机共用安装路径。[来源记录](../../../../../evidence/sources.json)

本件包含物性查询与计算接口、数据源与组分接口、引擎输入结构接口、单位换算、属性元数据和输入关键字表。唯一的 PE 资源是 Windows 版本资源。

## 静态验收

- ILSpy 9.1.0.7988 导出 C# 与带定义令牌的 IL。dnfile 0.18.0 和 dncil 1.0.2 核对原件的 152 个类型定义（含 `<Module>`）、548 个字段、490 个属性、1 个事件、940 个方法定义以及 7 个 finally 区。189 个方法体共含 121,618 条 IL 指令，另有 751 个原件抽象声明。
- Roslyn 5.0.0.0 使用五个原版直接引用完成静态编译。回编的成员签名、显式接口槽、泛型约束及自定义属性与原件对应。185 个方法体的指令、操作数和异常区记录一致。核对另 4 个方法的单位偏移分支、字符位提取、局部变量重排和闭包委托缓存差异。回编多出的缓存字段属于方法级闭包。源码保留原模块属性的注释，编译器自动生成相同声明。静态编译报告一个原有未使用字段和一个未使用引用指令提示。
- 唯一的 PE 版本资源经 RC 编译读回，1,138 字节与原件逐字节相同。PE 资源树与 CLR 清单核对未发现界面布局。[托管核验](../../../../../evidence/managed-audit.json) · [方法令牌映射](../../../../../evidence/methods.csv) · [资源核验](../../../../../evidence/resources.json)

本件通过静态逆向验收。C# 的 SHA-256 为 `e4e23fa1d1b322eeb61ce07893850cb39b8de5abfe540752e68e5430d549dbb6`。带原始字节的 IL 保存在本机。强名绑定、单位与符号查找行为留到 Windows 重建对照阶段。
