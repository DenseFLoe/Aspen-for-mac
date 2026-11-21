# app.xaml

Aspen Plus V15 主程序 `Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/AspenPlus.exe`，文件版本 `41.0.0.614`，SHA-256 为 `006d17165e434fb9263c5614844352604a72cf727a929a7174f1aca002c39bf9`。Plus 安装包 `ASPE~253.cab` 成员 `aspenplus.exe.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0` 与已读取的安装件指纹一致。

本件恢复 `AspenPlus.g.resources` 中的 `app.baml`。原流 2,823 字节，SHA-256 为 `2d7636cbaccac264fc9d8c2d96db06616b2a0f69e76626f49508db426af22aaa`。可编辑的 `app.xaml` 长 2,956 字节，SHA-256 为 `c84cf0708a0a6f94f3a17c2bbe465ab9728c995f6432508456945ce0d561de28`。根对象为 `AspenPlus.App`，定义应用资源、合并字典及四个显式资源键。

已通过静态验收。WPF 标记回编后，逐一核对 54 个有序节点及节点属性、22 个对象、8 个顶层合并字典。原件和回编件均无 Binding、TemplateBinding、字段连接或事件挂接。原始 `InitializeComponent`（`0x06000013`）在 `IL_0010` 取出 `/AspenPlus;component/app.xaml`，在 `IL_001e` 调用 `Application.LoadComponent`，回编生成相同的资源 URI。[布局验收](../../../../../evidence/ui-audit.json)

本页引用的 `DevExpressStyle.xaml` 已定位到 SpreadsheetCalculator 的托管资源。 `DataGridStyle.xaml` 已定位到 `ApwnShell.resources.dll` 的 en-US 卫星资源，主程序集声明 `NeutralResourcesLanguage("en-US", Satellite)`。两份安装卫星中的目标成员指纹相同。Windows 重建时核对实际卫星加载位置、样式生效和主题外观。[外部资源定位](../../../../../evidence/resource-references.json)
