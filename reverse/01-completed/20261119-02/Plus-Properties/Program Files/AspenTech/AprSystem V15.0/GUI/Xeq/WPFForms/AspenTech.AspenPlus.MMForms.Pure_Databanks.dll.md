# AspenTech.AspenPlus.MMForms.Pure_Databanks.dll · 整程序集 C#

本轮 20261119-02，原版逐文件静态逆向归档已完成。产品为 Aspen Plus V15、独立 Aspen Properties V15 共用，原安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Pure_Databanks.dll`。文件与程序集版本均为 `41.0.0.614`，原件 SHA-256 为 `d6bd9487af6d3c4f08d3285503b35759bfa5b61681ca4dbfaae84aa461a5522c`。

- 本份成果为 `.local/reverse-round-20261119-02/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Pure_Databanks.dll.cs`，SHA-256 为 `83f235d97e8d94044ef6f987a54e9e2602394cbf21c5d4ed9ccb599f5502b3e2`。覆盖表单与 ViewModel 两个类型。0x06000004 的隐式构造和 0x06000005 的静态字段初始化可跳到同名指令档。属性将引擎路径 @main.Input.FILE_SYM_NAM 作为列表读取，清除时请求恢复默认。关闭命令按需初始化并调用 CloseForm。
- 两产品包的 APRS~393.cab 均含对应标识成员，逐份读取的原件与本机安装件相同。三条去重来源、具体 MSI/CAB 及原成员名、四份清单的指纹与行记录见 `.local/reverse-round-20261119-02/databanks-evidence/identity.json`。
- 逐方法对照在 `.local/reverse-round-20261119-02/databanks-evidence/coverage.json`，C# 映射在 `.local/reverse-round-20261119-02/databanks-evidence/source-map.json`。2 个用户类型及空模块类型、5 个字段、2 个属性、0 个事件、8 个 MethodDef 逐一对齐。8 个方法都有实现，共 84 条指令，0 个异常区，以 dnfile、dncil 独立核对元数据令牌与方法指令字节、偏移、操作码。隐式构造与属性初始化的原顺序和操作数保留在指令档。
- 首次仅用 WPFForms 查找依赖时，Connect 的两个字段转换产生类型诊断。补入真实 Xeq 依赖与 .NET Framework 引用后，诊断消失。CLI 的整件输出与 AST 行映射输出一致。工具版本、运行方式与日志见 `.local/reverse-round-20261119-02/databanks-evidence/operations.md` 和 `.local/reverse-round-20261119-02/databanks-evidence/versions.json`。
- 逐方法作用、控件绑定及外部接口见 `.local/reverse-round-20261119-02/databanks-evidence/behavior.json`。BAML 的 URI、连接编号、类型和字段均与本体对齐，4 个外部静态文本属性已在同版 Localization 程序集中定位；英文资源实值见 `.local/reverse-round-20261119-02/databanks-evidence/localization.json`。仅以 en-US 卫星和所引用的外部成员补足本体结构证据。
- 本轮静态完整性缺口已解决。界面操作、引擎数据变化、Windows 重建和运行结果留待后续阶段。相同原哈希可复用，原件、产物或证据指纹变化时重新核验。
