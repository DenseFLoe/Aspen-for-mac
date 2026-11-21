# 组分表单主库

同目录的 `AspenTech.AspenPlus.MMForms.Components.dll.cs` 是 Aspen Plus V15 和 Aspen Properties V15 共用的可编辑组分表单源码，通过本阶段整件静态验收。两套安装包的 `APRS~371.cab` 分别以 MSI File 序号 1858 和 1495 引用主库，安装路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Components.dll`。两份既有成员与本机安装件均为 336,936 字节，版本 41.0.0.614，原件 SHA-256 为 `127354937eea94cce668a8101498e9aa2675e05ccc5d0bc29350cc0434ec3894`。C# 成果 SHA-256 为 `fcef1e0d1c4dee4ad04c5c84047c2041b109d18599f058fe517fd21457ef4ec7`。[主库身份](../../../../../../evidence/identity.json) · [签名](../../../../../../evidence/signing.json)

## 源码覆盖

用 ILSpy 9.1 恢复整库，并按原始定义令牌核对 157 个顶层类型、63 个嵌套类型、1,368 个字段、662 个属性、1 个事件和 1,314 个方法体。28,744 条原始 IL 指令及 28 个异常处理区已核对。1,022 个方法能直接定位到执行语句，20 个自动访问器已对照后备字段，272 个折叠方法已逐项核对。显式接口实现有 83 条。[托管验收](../../../../../../evidence/managed-audit.json)

按选中行枚举组分 ID 的迭代器已恢复为可编辑的显式状态机，核对了其 9 个方法及异常清理路径。Roslyn 静态编译有 6 项依赖版本警告、0 个错误。此前 5 份选取式 IL 稿中的 73 条方法记录对应 59 个不同方法令牌，已对照原始所属类型、签名名称、RVA、指令偏移与操作码。[方法验收](../../../../../../evidence/managed-audit.json) · [历史选取记录](../../../../../../evidence/legacy-il.json)

## 页面与资源

两套安装包和本机安装件中的 en-US 卫星哈希一致。主库按原资源路径加载 76 页，全部布局位于本目录 `en-US/AspenTech.AspenPlus.MMForms.Components.resources.dll/`，保留子目录及同名中文说明。已核对 1,454 个布局对象、598 处字段连接和 2 个连接器事件，各页均可通过 WPF 静态读取。主库的版本资源通过可编辑 RC 回编，1,134 字节与原件一致。[卫星来源](../../../../../../evidence/satellite-identity.json) · [布局核对](../../../../../../evidence/ui-audit.json) · [页面清单](../../../../../../evidence/ui-pages.csv) · [本地化](../../../../../../evidence/localization.json) · [版本资源](AspenTech.AspenPlus.MMForms.Components.dll.version.md)

组分查找命令及定义区域的双击处理程序都调用 `Find()`。当搜索返回 2 且确认结果为 1，代码将 `RUN_CLASS` 设为 `PCES`，导航至物性估算并发布运行事件。组分清单首次更新时，标识 `GLOBAL` 对应 `GCOMP_LIST=1`，其他标识对应 0。组分分组页按所选子物流读取成员列表，其列表属性禁止排序。[源码、页面和原始指令位置](../../../../../../evidence/selection.json)

## Windows 对照

有 4 处绑定需在宿主确认：3 个外部结果状态页的 `status_var` 及 1 个列头模板的 `IsMMEnabled`。 页面装载、数据上下文、组分搜索对话框、参数估算实际执行及与原版交互的一致性均留待 Windows 重建对照。主库逐令牌证据在本机 `.local/work-20261119-24-code/code-coverage.json`，原始指令清单位于同目录的 `AspenTech.AspenPlus.MMForms.Components.dll.instructions.il`。本轮签核在 `.local/reverse-round-20261119-24/signoff.json`。
