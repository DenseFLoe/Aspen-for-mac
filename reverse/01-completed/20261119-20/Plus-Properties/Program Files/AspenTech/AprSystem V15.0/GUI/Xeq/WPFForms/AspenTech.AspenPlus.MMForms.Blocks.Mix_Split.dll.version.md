# 混合与分流表单库的 Windows 版本资源

原件为 Aspen Plus 与 Aspen Properties V15 共用的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.dll`。两个 MSI 中的成员名均为 `aspentech.aspenplus.19.01AE6323_4069_4985_B882_1C2F459EE258`，File 序号分别为 1872 和 1509。两条既有包内成员记录与本次读取的安装件均为版本 41.0.0.614、235,560 字节，SHA-256 为 `d8009b165090c48196d9939d7f2f1f120c694e1cb95bc634021108cbebb72517`。本轮 `evidence/identity.json` 记录两个来源的 MSI、CAB、组件、原路径和指纹。

同目录的 `AspenTech.AspenPlus.MMForms.Blocks.Mix_Split.dll.version.rc` 已通过静态验收。该文件恢复了原件唯一的原生资源 RT_VERSION（名称 ID 1、语言 ID 0），包括固定版本字段、11 项字符串及语言和代码页 0/1200。RC 的 SHA-256 为 `f0dfca7652eea0901cc40bbb91589c42ca87b6aa334474e42ffe2cddd664abf2`。

用 dnfile 0.18.0、pefile 2024.8.26 读取资源目录和版本信息后，用 GNU windres 2.39 单独编译 RC，回读的 1,182 字节版本块与原件逐字节相同，SHA-256 为 `2585119b8b1d368b858a5108b9a10dbb0c67947df5966563b99ec38bde384397`。本轮 `evidence/resources.json` 记录原件偏移、全部字段、工具版本和回读结果。

此 DLL 没有 CLR ManifestResource 表，CLR 资源 RVA 和大小均为零。其代码的 26 个方法通过 101 次调用访问同版本 `AspenTech.AspenPlus.Localization.dll` 的 73 个字符串取值器。Mono.Cecil 0.11.6 按签名定位这些取值器，再按 IL 中的键逐项查到 4 张外部资源表中的对应字符串。本轮 `evidence/localization.json` 保存调用令牌、偏移、资源键和资源表指纹。中性语言为 en-US，最终回退位置为卫星程序集。

版本资源已全部恢复。Windows 重建时，可将本 RC 用于还原版本属性，并在对应语言环境下对照界面加载结果。
