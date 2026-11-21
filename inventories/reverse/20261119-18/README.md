# 第 20261119-18 轮 · Flash2 与换热器表单

`AspenTech.AspenPlus.MMForms.Blocks.Flash_HX.dll` 通过整件静态逆向验收。已恢复 Decanter、Flash2、Flash3、Heater、Heatx、HXFlux 和 MHeatx 的输入及结果表单代码。旧档单独恢复了 3 个顶层类型，本轮覆盖 374 个顶层类型及 50 个嵌套类型。[源码、版本资源及同名说明](../../../reverse/01-completed/20261119-18/Plus-Properties/Program%20Files/AspenTech/AprSystem%20V15.0/GUI/Xeq/WPFForms/)

原版 Aspen Plus V15 和 Aspen Properties V15 的 MSI File 序号分别为 1866、1503。两条包内成员记录与共用安装件均为版本 41.0.0.614，大小 807,464 字节，SHA-256 为 `4c08d219e3f2495e392635e21111065f6ec9adce1a8be49d0a3dd5eb8d8ca169`。[来源核验](../../../reverse/01-completed/20261119-18/Plus-Properties/evidence/identity.json)

| 范围 | 静态验收结果 |
| --- | --- |
| 方法与接口 | 3,386 个方法定义中有 3,384 个 IL 实现和 2 个 Windows 外部声明。原件的 79,669 条指令和 88 个异常处理区间已逐项核对。449 个由高层 C# 隐含生成的方法另核对调用、字段、常量等有序记录。188 条显式接口映射已对照。 |
| 旧代码诊断 | Flash2 输入规格和加热器输入规格的旧代码分别有 466 和 665 行反编译诊断。全部 1,131 行已定位到原件的 6 个方法、对应指令偏移与新版 C# 行号。 |
| 页面与控件 | 主库不内嵌页面。188 个页面地址全部对应到独立的 en-US 卫星库，包含 4,961 个界面对象和 1,839 个控件字段连接。已核对 115 个 WPF 绑定、994 个变量或数据路径和 405 个表格路径。Flash2 输入规格页和结果汇总页各有 28 个对象，分别连接 14 和 16 个控件字段。 |
| 字符串与版本 | 51 个方法中的 211 条本地化调用关联到 100 个外部取值器及其字符串键。唯一的 Windows 版本资源由 RC 重建后，1,166 字节与原件逐字节相同。 |

换热器转换窗口 `EdrConvertRigorous` 的 Loaded 处理方法将窗口本身设为数据上下文。原版布局有 5 个绑定名称，在该窗口的 17 个属性及系统窗口继承层可查的 273 个属性中均无同名项。已保留原名，Windows 对照时应复查相应控件的可见性和启用状态。Roslyn 静态检查为零错误，18 条 CS1702 警告均涉及传递引用 AspenCxs 41.0.0.5 和本机 41.0.0.57 的实际版本绑定。[逐页核对](../../../reverse/01-completed/20261119-18/Plus-Properties/evidence/ui-pages.csv) · [窗口证据](../../../reverse/01-completed/20261119-18/Plus-Properties/evidence/ui-audit.json) · [旧诊断逐条定位](../../../reverse/01-completed/20261119-18/Plus-Properties/evidence/legacy-diagnostics.json)

本轮新增 1 个已完成原件，覆盖 3 条不同来源。Plus、Properties、Properties 重复子表及共用视图分别更新 3、2、2、3 行。完整 IL 和逐方法指纹保存在本轮本机 evidence 目录。累计 23 / 1,397 个不同原件通过静态验收，对应 68 条不同来源。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [来源变更](status-delta.csv) · [发布清单](../../../reverse/01-completed/20261119-18/publication.csv)

## 下一轮

接续 `AspenTech.AspenPlus.MMControls.dll`，SHA-256 为 `bd4b5cdf3e6c8ede0dbb54b9297581bb79fa7289fe45c71def67b5bf1107842c`。Flash2 输入规格和结果汇总页都调用它的 `MMTabPage` 构造函数。整份 Flash_HX 中有 510 个方法直接调用该库 1,028 次，48 个被调用签名均已匹配。旧档单独恢复了 544 个顶层类型中的 12 个，整件的 6,570 个方法定义及相关资源待核对。[调用签名与页面示例](../../../reverse/01-completed/20261119-18/Plus-Properties/evidence/next.json)
