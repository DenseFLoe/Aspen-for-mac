# 第 20261119-32 轮 · Aspen Plus 与 Aspen Properties 共用窗口宿主

`AspenTech.Visualisation.CommonShell.Wpf.dll` 通过整件静态逆向验收。两套安装包与安装件共用同一指纹，三条来源合计为一个原件。[逐件说明](../../../reverse/01-completed/20261119-32/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/AspenTech.Visualisation.CommonShell.Wpf.dll.md) · [本轮发布清单](../../../reverse/01-completed/20261119-32/publication.csv)

| 操作 | 从窗口宿主原件核对的行为 |
| --- | --- |
| 显示界面 | 按请求在当前窗口或全部窗口中查找匹配界面。找到时激活已有界面，跨窗口时先激活所属窗口。需要新建时发出可取消的显示前事件，再按请求选择当前窗口或新窗口。 |
| 激活界面 | 窗口将请求交给 ScreenManager，在找到界面所属窗格后激活该窗格。 |
| 关闭界面 | 普通关闭会询问界面能否关闭。处理程序取消时保留窗格。强制关闭跳过询问。发送关闭命令期间设置的标记在 finally 中复位。 |

已将这三条路径对应的 11 个方法与原始方法体指纹、调用位置关联。界面交互和宿主依赖的运行表现留待 Windows 阶段对照。[窗口调用记录](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/window-actions.json)

## 静态验收

- 覆盖 954 个方法定义。916 个方法体合计 18,944 条指令、106 个 finally、21 个 catch、3 个 fault。逐一核对其余 38 个声明。[托管验收](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/managed-audit.json) · [方法索引](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/methods.csv)
- 6 份布局包括两个窗口和四份资源字典。核对了 1,509 个 BAML 节点、57 个 Binding、67 个 TemplateBinding、15 个字段连接和 3 处事件挂接。[布局证据](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/ui-audit.json)
- 31 个图像流全部解码。叶形按钮的读取路径与嵌入资源目录有一处原始差异，缩放图标有一个使用 PNG 扩展名的 ICO。原图归档于本机。Windows 版本资源回编后与原件逐字节一致。[读取路径](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/image-lookups.json) · [图像格式与指纹](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/resource-assets.json) · [版本回编](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/resources.json)

累计 **37 / 1,397** 个不同原件通过静态验收，覆盖 **109 条不同来源**。本轮更新 Plus 清单 3 行、Properties 清单 2 行、Properties 重复子集 2 行、共用索引 3 行。四个视图中的来源按标识去重。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续 `AspenPlus.exe`。启动方法调用 `ApwnShell.dll` 的 `ApplicationHelper.Run`，该方法有三处调用本轮宿主的 `ShowMainWindow`。已定位主程序 58 个方法定义中的入口、初始化、启动和退出方法。[下轮入口与两段调用证据](../../../reverse/01-completed/20261119-32/Plus-Properties/evidence/next.json)
