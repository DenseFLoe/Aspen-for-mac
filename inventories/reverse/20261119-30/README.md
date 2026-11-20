# 第 20261119-30 轮 · 流程图对话框库

`AspenTech.AspenPlus.PfsDialogs.dll` 通过整件静态验收。旧档按方法名去重，只列了 233 个方法名。本轮逐一核对原件的 525 个方法定义，恢复了完整 C#、13 个窗口和 1 份通用主题字典。两个原版安装包中的主库与安装件同哈希，合计三条来源。[逐件说明](../../../reverse/01-completed/20261119-30/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/AspenTech.AspenPlus.PfsDialogs.dll.md) · [完整发布清单](../../../reverse/01-completed/20261119-30/publication.csv)

| 窗口 | 从原件确认的操作 |
| --- | --- |
| 控制变量 | 单击记录当前变量名，双击有效行会确认并关闭。即使用户最后取消，驱动仍写出已记录的变量名，调用方可根据单独的返回码区分确认和取消。 |
| 书签 | 新增时按名称排序，界面拒绝重名。转到书签时读取所选项的视图范围、比例和名称。对话框关闭后，确认返回名称，取消返回空串。 |
| 查找对象 | 先判断选中的是设备还是物流，分别用 1 和 2 表示。若包含子层级，则拆分层级和对象名。宿主收到这两项、对象类型，以及居中和缩放两个标志。若打开层级视图的方法返回真，选择操作排到界面空闲时执行。 |

上述三条路径共核对 23 个方法，并与上一轮记录的三个初始化方法指纹逐一比对。窗口的实际显示与宿主反馈留待 Windows 重建后对照。[原始方法令牌与调用位置](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/dialog-actions.json)

## 静态验收

- 471 个有体方法共含 15,271 条 IL 指令、11 个 catch 和 8 个 finally。其余 54 个方法定义均有原件声明依据。回编核对了 14 个显式接口槽、49 个 COM 调度编号和 1 个本机调用。静态编译零错误。唯一警告为 `AspenCxs` 的直接与间接引用版本不同。[方法清单](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/methods.csv) · [验收与警告](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/managed-audit.json)
- 14 份可编辑布局及主题均已回编。13 个窗口的 228 个连接号、219 个字段与 206 处连接器事件订阅都能对应到主库。配套卫星中的 38 项图像逐帧核对。主库的版本与图标资源回编后与原件字节一致。[布局](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/ui-audit.json) · [图像](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/resource-assets.json) · [图标](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/native-icon.json) · [版本](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/resources.json)

累计 **35 / 1,397** 个不同原件通过静态验收，覆盖 **104 条不同来源**。本轮在 Plus、Properties、Properties 重复子集和共用索引中同步更新了这三条来源。[累计台账](ledger.csv) · [状态增量](status-delta.csv) · [归档指纹](artifacts.csv)

## 下一轮

接续 Aspen Plus 的模型库模块 `AspenTech.AspenPlus.ModelLibrary.dll`。原件有 865 个方法定义。旧稿只单独恢复了 53 个顶层类型中的 1 个，并留下 1 处反编译诊断。已定位模型库加载、管理窗口刷新和编辑器打开三个方法，供下一轮核对。[下轮入口](../../../reverse/01-completed/20261119-30/Plus-Properties/evidence/next.json)
