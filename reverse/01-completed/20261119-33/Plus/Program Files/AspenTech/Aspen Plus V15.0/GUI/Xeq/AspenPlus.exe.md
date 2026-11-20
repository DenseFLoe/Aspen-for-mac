# AspenPlus.exe.cs 的静态逆向说明

原件为 Aspen Plus V15 的 `Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenPlus.exe`，文件与程序集版本 `41.0.0.614`，大小 810,024 字节。原件 SHA-256 为 `006d17165e434fb9263c5614844352604a72cf727a929a7174f1aca002c39bf9`。

来源为 Process Modeling (Aspen Plus) V15 (64bit).msi 的 `ASPE~253.cab`，成员 `aspenplus.exe.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`。使用和包内已核实指纹一致的安装件。两条来源以 `sha256:006d17165e434fb9263c5614844352604a72cf727a929a7174f1aca002c39bf9` 关联。

## 验收范围

本轮整件通过静态逆向验收。输入为 AMD64 .NET Framework 4.8 程序，托管入口为 `0x06000014`。核对 14 个类型定义（含模块伪类型和 4 个编译器生成类型）、19 个字段、6 个属性及 58 个方法。37 个方法体的 1,368 条指令、17 个 catch 和 2 个 finally 逐项与原件核对。21 个无 IL 体的 COM 声明中，4 个是原版虚表保留槽位。旧局部源码的 5 条 ILSpy 诊断在按原件约束配置引用后消失。整件 C# 用 ILSpy 9.1.0.7988 恢复，Roslyn 静态检查通过，12 个直接引用的程序集身份与原件匹配。

字段初始化、默认构造、表达式属性、三个闭包对象和动态转换调用点由 C# 编译器生成，原件令牌和源码位置已对应。C# 源码还原启动、语言选择、启动闪屏、收藏链接、异常及退出处理。原版 `App.OnStartup` 把启动和闪屏回调交给 `ApwnShell.dll` 的 `ApplicationHelper.Run`。第 32 轮已核对该方法到共用窗口宿主的调用。使用现有程序集声明完成本件核对。

[源文件](AspenPlus.exe.cs) · [方法对应表](../../../../../evidence/methods.csv) · [托管核验](../../../../../evidence/managed-audit.json) · [入口和调用证据](../../../../../evidence/startup.json)

## 重建时需要的材料

应用级资源字典、PE 资源以及六个 COM 导入接口的原版元数据均单独存档。C# 的 COM 保留槽位、接口行和参数名在重建阶段须按元数据清单恢复。独立声明件经内存写入和读回，已核实相关元数据可恢复。原版图像和带原指令字节的 IL 对照版在本机。本轮未启动原版或重建程序，Windows 阶段对照启动参数、语言切换、闪屏和 COM 调用以及主窗口生命周期。

[COM 材料说明](AspenPlus.exe.interop.md) · [发布范围](../../../../../../publication.csv)

本文件 SHA-256 `f82f836832da2eeaa0ae62c050dc41a128dd4a79040e6972a500de7e961e3d22`。
