# 第 20261119-33 轮 · Aspen Plus 主程序

`AspenPlus.exe`（`41.0.0.614`）通过整件静态逆向验收。Plus 安装包成员和已安装文件的 SHA-256 一致，两条来源合计为一个原件。[逐件说明](../../../reverse/01-completed/20261119-33/Plus/Program%20Files/AspenTech/Aspen%20Plus%20V15.0/GUI/Xeq/AspenPlus.exe.md) · [发布清单](../../../reverse/01-completed/20261119-33/publication.csv)

- 核对 14 个类型定义、19 个字段、6 个属性和 58 个方法定义。37 个方法体共有 1,368 条指令，另有 17 个 COM 抽象声明及 4 个虚表保留槽位。旧局部源码的 5 条反编译诊断已处理。[托管验收](../../../reverse/01-completed/20261119-33/Plus/evidence/managed-audit.json) · [源码对应表](../../../reverse/01-completed/20261119-33/Plus/evidence/methods.csv)
- 托管入口构造应用并加载资源字典。`OnStartup` 向 `ApwnShell.dll` 的 `ApplicationHelper.Run` 传入闪屏回调，由该程序集调用共用窗口宿主。原版生成输入模式随后调用 `Shutdown`。[启动调用证据](../../../reverse/01-completed/20261119-33/Plus/evidence/startup.json)
- `app.xaml` 回编后的 54 个节点及属性与原件一致。两个外部样式字典均已定位，`DataGridStyle.xaml` 位于 `ApwnShell` 的 en-US 卫星程序集。11 个 PE 资源中 10 个回编后逐字节一致，应用清单规范化后 XML 内容一致。两份原图标保存在本机。[布局核验](../../../reverse/01-completed/20261119-33/Plus/evidence/ui-audit.json) · [PE 资源核验](../../../reverse/01-completed/20261119-33/Plus/evidence/native-resources.json)
- C# 独立 COM 声明样件与原件存在标记、接口行和参数名差异。按随附元数据清单恢复后，六个接口和 21 条方法声明的相关元数据经内存写入并读回，逐项匹配。Windows 阶段对照实际 COM 调用、资源选择及应用行为。[COM 声明说明](../../../reverse/01-completed/20261119-33/Plus/Program%20Files/AspenTech/Aspen%20Plus%20V15.0/GUI/Xeq/AspenPlus.exe.interop.md)

累计 **38 / 1,397** 个不同原件通过静态验收，覆盖 **111 条不同来源**。本轮更新 Plus 的两条来源状态。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [本地归档指纹](artifacts.csv)

## 下一轮

接续 `AspenTech.AspenPlus.MMForms.Reactions.dll`。已核实同版安装件指纹，并定位 488 个类型定义、169 个嵌套类型、4,166 个方法定义。其主程序集无内嵌托管资源，下一轮按实际引用核对卫星资源。[下一轮入口](../../../reverse/01-completed/20261119-33/Plus/evidence/next.json)
