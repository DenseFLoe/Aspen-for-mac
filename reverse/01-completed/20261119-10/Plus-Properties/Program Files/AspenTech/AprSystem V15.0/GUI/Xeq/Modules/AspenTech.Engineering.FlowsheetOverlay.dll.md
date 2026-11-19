# AspenTech.Engineering.FlowsheetOverlay.dll.cs

原件为 Aspen Plus 和 Aspen Properties V15 的 `AspenTech.Engineering.FlowsheetOverlay.dll`。文件与程序集版本均为 `41.0.0.19`，大小 56,872 字节，SHA-256 为 `7f8a50243d4ca57fefe9c438912e324e0f9a6a8e21ad287eb709644c217a5907`。

两个产品各自的 MSI 在 `AYS_GU~2.cab` 中定位到此成员，文件序号分别为 2155 和 1792。两份已提取成员的指纹与 `AprSystem V15.0/GUI/Xeq/Modules`、`Aspen Plus V15.0/GUI/Xeq` 下的安装件均相同。四条来源共同关联本成果，成员键、完整路径及清单记录见[来源证据](../../../../../../../../identity.json)。

**状态**　整件 C# 通过第 20261119-10 轮静态归档验收。成果 SHA-256 为 `1969ea0902d91f5f702417050126851c9f2a1fa490de7dba0738767d6ba18ece`。

ILSpy 9.1.0.7988 从上述 AprSystem 安装件导出全程序集。已按 CLR 定义令牌核对 18 个顶层类型和 1 个嵌套类型、63 个字段、14 个属性及 1 个事件。107 个方法定义中，81 个有 IL 实现。67 个以序列点定位，8 个自动访问器与后备字段及读写指令对应，6 个方法在 C# 附录按令牌展开。其余 26 个定义分别为 17 个抽象接口方法、5 个 user32 平台导入和 4 个由 CLR 提供的委托方法。原件 5,214 个 IL 代码字节已按方法核对。[逐令牌记录与工具指纹](../../../../../../../../code-coverage.json)

Roslyn 静态语法与类型检查为零错误。编译器提示原件字段 `mousePosition` 未使用，另有一条多余的 using 提示。已核对高亮服务注册，以及透明窗口与宿主交换的叠加层、位置和管理接口。窗口定位、鼠标交互和宿主事件派发留待 Windows 重建对照。[界面与宿主对应](../../../../../../../../bindings.json)
