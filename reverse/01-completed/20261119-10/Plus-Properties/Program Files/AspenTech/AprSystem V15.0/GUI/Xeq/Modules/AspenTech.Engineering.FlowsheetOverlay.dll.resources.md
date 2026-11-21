# AspenTech.Engineering.FlowsheetOverlay.dll.resources.zip

原件为 Aspen Plus 和 Aspen Properties V15 的 `AspenTech.Engineering.FlowsheetOverlay.dll`。文件与程序集版本均为 `41.0.0.19`，大小 56,872 字节，SHA-256 为 `7f8a50243d4ca57fefe9c438912e324e0f9a6a8e21ad287eb709644c217a5907`。

两个产品各自的 MSI 在 `AYS_GU~2.cab` 中定位到此成员，文件序号分别为 2155 和 1792。两份已提取成员的指纹与 `AprSystem V15.0/GUI/Xeq/Modules`、`Aspen Plus V15.0/GUI/Xeq` 下的安装件均相同。四条来源共同关联本成果，成员键、完整路径及清单记录见[来源证据](../../../../../../../../identity.json)。

**状态**　程序集内资源已通过第 20261119-10 轮静态归档验收。资源 ZIP 的 SHA-256 为 `b8f3c97e291004c44646094489752fd4404ee4200ac7ef6fe4aae86d29dc324e`。

唯一托管资源表 `AspenTech.Engineering.FlowsheetOverlay.g.resources` 含选中、未选中图例两张 RGBA PNG，分别为 136×168 和 136×166 像素。归档保留原资源键对应的两张图片及 PE 的 RT_VERSION 原始字节。使用 dnfile 0.18.0 读取 PE/CLR，校验 PNG 分块 CRC，用 Pillow 13.0.0 解码，并逐字节比对归档与原资源。

窗口及画布由 C# 创建。Mono.Cecil 0.11.6 的原方法指令记录确认了图例的 4 处图片调用、2 处画布宽高绑定、14 处事件订阅和 11 处解绑。宿主的三个接口实现和窗口钩子注册、移除位置均有记录。原版资源范围的核对已完成，图例拖动、显示及宿主在运行时的窗口行为留待 Windows 对照。[资源和界面证据](../../../../../../../../bindings.json)
