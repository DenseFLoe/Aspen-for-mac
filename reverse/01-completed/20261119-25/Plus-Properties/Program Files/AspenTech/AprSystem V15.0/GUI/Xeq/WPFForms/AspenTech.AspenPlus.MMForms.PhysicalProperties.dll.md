# 物性表单主库

同目录的 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.cs` 为本机归档的完整可编辑源码。原件是 Aspen Plus V15 和 Aspen Properties V15 共用的 Windows 物性表单，版本 41.0.0.614。两套原版安装包分别使用各自 `APRS~389.cab` 的 MSI File 序号 1876 和 1513，各自成员与安装件均为 1,021,992 字节，SHA-256 为 `65ce3da43613a061e2b316c518ef9c6f530ef74cc106544313a3cf70373d45a9`。安装路径为 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.PhysicalProperties.dll`。[来源](../../../../../../evidence/identity.json) · [签名](../../../../../../evidence/signing.json)

## 静态验收

完整 C# 的 SHA-256 为 `3724b53f52093556212b3bd50af1c058dc37a5e571b4a566fa50ab54e1ed9b53`。ILSpy 9.1 恢复 496 个顶层类型及 234 个嵌套类型。原件的 4,955 个方法体、106,490 条 IL 指令、74 个异常处理区、259 条显式接口映射均已按定义令牌核对。3,985 个方法在正文可定位到执行语句，37 个自动访问器已核对后备字段，另有 933 个折叠方法按令牌核对。3 个迭代器的状态机及清理路径已复核。Roslyn 静态编译有 0 个错误、20 项警告。[托管核验](../../../../../../evidence/managed-audit.json) · [逐方法记录](../../../../../../evidence/methods.csv)

237 个布局均由 en-US 卫星中的原始 BAML 恢复，逐页核对 7,699 个布局对象、2,576 处字段和 6 处事件连接。卫星另含 4,356 个 PNG 资源键，图像包已在本机按原键名归档。主库的 1,198 字节版本资源回编一致。[逐页清单](../../../../../../evidence/ui-pages.csv) · [图片索引](../../../../../../evidence/resource-assets.json) · [版本资源](AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.version.md)

## 发布范围与下一步

完整 C# 含回归计算公式，仅保存在本机的第 25 轮完成目录。GitHub 版选取 337 个已核过正文的顶层类型，其中包括 NRTL 输入、二元分析方法、二元参数结果的视图与视图模型。公开文件名为 `AspenTech.AspenPlus.MMForms.PhysicalProperties.dll.01.cs`。两个含物理常数的布局在发布版保留控件和绑定，并标注原标签的位置。4,356 个 PNG 的键名、尺寸及指纹可用于定位本地原图。[代码选取对应表](../../../../../../evidence/code-extraction.json) · [布局发布范围](../../../../../../evidence/ui-publication.json) · [全部成果对应表](../../../../../../evidence/publication-scope.csv)

原版二元输入页的 `cboEntrainerFraction` 与纯组分输入页的 `cboHenryComp` 在同页均找不到同名目标控件。已保留原拼写。NRTL 的 `lblRvalue_state`、二元分析方法页的 `cboHenryComps_Enable` 等绑定留待宿主解析。Windows 对照还需验证参数查询对话框的错误与正常路径，以及实际数据下的结果页显示。[逐页核验](../../../../../../evidence/ui-audit.json) · [三页入口](../../../../../../evidence/binary-pages.json)
