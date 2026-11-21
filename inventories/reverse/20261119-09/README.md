# 第 20261119-09 轮 · 文件菜单控件

Aspen Plus 和独立 Aspen Properties 共用的 `AspenTech.Engineering.Controls.FileMenu.dll` 已通过整件静态归档验收。文件与程序集版本均为 `15.0.0.0`，大小为 87,592 字节，SHA-256 为 `db81bd19b9a31b5a560fe0c91ef62ce66d79e768a8d17809e32f618da5814b2f`。

## 安装来源

两个产品各自的 MSI 都将此文件定位到本产品的 `APRS~610.cab`，Plus 和 Properties 的文件序号分别为 2097 和 1734。按各自的 MSI 路径、CAB 路径和成员键，复用了先前解包时记录的两份成员指纹。两份成员的大小和 SHA-256 均与 `AprSystem V15.0/GUI/Xeq` 下的安装件相同。

## 代码与界面

旧档只选取了 3 个顶层类型。本轮已恢复全部 23 个顶层类型，按原定义核对 47 个字段、19 个属性和 124 个方法实现。其中 102 个方法通过序列点关联到 C#，2 个自动访问器与后备字段匹配，另有 20 个方法做了定点展开。

宽度转换器的首次导出使用了 C# 不允许的可空类型模式。按原始指令修正了类型判断，保留了正数分支返回浮点数、其余分支返回整数零的区别。最终 C# 通过 Roslyn 语法和类型检查。

界面资源包括 3 个控件页面、2 个资源字典和 1 份空的中性资源表。17 个内置菜单模板均已与枚举值及同名资源键对应。另一个字典含 324 个有名颜色。已核对 4 个命名控件、1 处布局事件、4 处代码事件订阅，以及 236 个单值绑定和 5 个多值绑定。宿主 `ApwnShell.dll` 的成员引用表记录了 `FileMenuControl.SetData` 和 `FileMenuTemplateManager.SetCustomTemplate`，分别用于传入菜单数据和注册自定义模板。实际渲染、命令执行、单位制切换和滚动响应留待 Windows 重建对照。

## 本机归档与台账

本机 `.local/reverse-round-20261119-09/01-completed/` 按原安装路径保存整件 C#、布局与资源 ZIP，并分别配有同名说明。轮次根目录的 `identity.json`、`code-coverage.json`、`bindings.json` 分别记录产品来源、代码覆盖和界面对应关系。`signoff.json` 登记本轮成果和证据指纹，`verification.json` 记录台账增量。

本轮 1 件由未完成转为已完成。Plus 总表、Properties 总表、Properties 重复子表和共用索引分别更新 3、2、2、3 行，涉及 3 条不同来源。累计 1,397 件中已完成 15 件，涉及 45 条来源。另有 28 件未完成、15 件暂存、1,339 件未开始。[累计台账](ledger.csv) · [归档指纹](artifacts.csv) · [上一轮](../20261119-08/README.md)
