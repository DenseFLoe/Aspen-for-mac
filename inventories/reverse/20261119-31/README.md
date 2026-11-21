# 第 20261119-31 轮 · Aspen Plus 模型库

`AspenTech.AspenPlus.ModelLibrary.dll` 通过整件静态逆向验收。Aspen Plus V15 原版安装包与安装件提供两条同哈希来源。共恢复 10,479 行 C#、22 份 XAML 和 Windows 版本资源声明。[逐件说明](../../../reverse/01-completed/20261119-31/Plus/Program%20Files/AspenTech/Aspen%20Plus%20V15.0/GUI/Xeq/Modules/AspenTech.AspenPlus.ModelLibrary.dll.md) · [完整发布清单](../../../reverse/01-completed/20261119-31/publication.csv)

| 操作 | 从原件确认的处理 |
| --- | --- |
| 加载库 | 根据普通名称或本地化名称识别物流分类，分别处理物料、功、热和动力物流的标签。批处理模式会跳过 `ACM Models`。加载完成后选取首个物流模型和首个设备分类。 |
| 更改启用的库 | 管理窗口刷新时清空列表，再按枚举顺序重新填入所有用户库。勾选发生变化时，以所选库的显示名称更新选择。成功后保存并通知其他界面，失败时显示错误。 |
| 打开与关闭编辑器 | 打开时先设置窗口尺寸。首次加载根据库类型选择标题，内置库隐藏保存按钮。用户库取得可编辑分类对象后支持拖放，关闭时将更改交给宿主保存。 |

以上路径核对了 13 个原始方法定义。运行时加载的数据、界面和保存结果留待 Windows 重建后与原版对照。[方法、调用位置与指纹](../../../reverse/01-completed/20261119-31/Plus/evidence/model-library-actions.json)

## 静态验收

- 核对了 865 个方法定义，其中 829 个有 IL 方法体，共 18,695 条指令、63 个 finally、12 个 catch 和 3 个 fault。其余 36 个定义逐一核对了声明。旧稿 1 个文件内的 17 条诊断现已定位至 4 个原方法并解决。静态编译为零错误。[托管验收与编译警告](../../../reverse/01-completed/20261119-31/Plus/evidence/managed-audit.json) · [逐方法索引](../../../reverse/01-completed/20261119-31/Plus/evidence/methods.csv) · [旧稿诊断](../../../reverse/01-completed/20261119-31/Plus/evidence/legacy-diagnostics.json)
- 配套卫星中的 22 份布局核对了 2,388 个 BAML 节点、159 个连接号、145 处字段和 155 处事件挂接。11 个 PNG、15 个 ICO 共 27 帧均已解码。版本资源回编后与原件逐字节相同。[布局](../../../reverse/01-completed/20261119-31/Plus/evidence/ui-audit.json) · [图像](../../../reverse/01-completed/20261119-31/Plus/evidence/resource-assets.json) · [版本](../../../reverse/01-completed/20261119-31/Plus/evidence/resources.json)

累计 **36 / 1,397** 个不同原件通过静态验收，覆盖 **106 条不同来源**。本轮只更新 Plus 清单内的两条来源。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

模型库的图标编辑窗口及模型库面板均调用 `CommonShellWindow.CloseScreen`。据此选择 Plus 与 Properties 共用的窗口宿主 `AspenTech.Visualisation.CommonShell.Wpf.dll`。原件有 954 个方法定义，已定位显示、激活和关闭界面的 6 个方法定义。[下轮入口](../../../reverse/01-completed/20261119-31/Plus/evidence/next.json)
