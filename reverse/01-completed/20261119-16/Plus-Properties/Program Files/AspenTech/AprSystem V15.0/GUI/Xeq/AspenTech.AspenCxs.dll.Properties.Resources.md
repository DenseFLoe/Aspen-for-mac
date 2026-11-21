# AspenTech.AspenCxs.dll 托管字符串资源

来源为 Aspen Plus 与 Aspen Properties 共用的 `AprSystem V15.0/GUI/Xeq/AspenTech.AspenCxs.dll`，文件版本 41.0.0.57，SHA-256 为 `84fdfccb7a92901d723ef284490cfe88d64c22758aeb75b2a2f6876255b57206`。

唯一的 ManifestResource（0x28000001）公开嵌入 `AspenTech.AspenCxs.Properties.Resources.resources`。CLR 目录的 344 字节由长度字段和 340 字节的资源负载构成。dnfile 0.18.0 解出一个 System.String，键为 `CxsProcessMonitor_ExceptionTryingToKillProcess`。资源管理器的基名、取值键、文化设置及 GetString 调用已与方法 0x060003CF、0x060003D2 对照。

该 RESX 通过静态验收。使用 .NET Framework 4 的 ResXResourceReader 读取可编辑文本并用 ResourceWriter 生成资源，再用 ResourceReader 核对字符串。重建的 340 字节与原件逐字节相同。资源负载 SHA-256 为 `27027c18823a7a50df53f9a4fdd59bb206df34cda1b22fc088955c4d7f89ad24`，RESX 的 SHA-256 为 `7072e9004a334b71c7b4d5a95b9af60846aa33b50fd82fa7d1891c8aebd9e99e`。详见本轮 managed-resource.json 与 layout-links.json。Windows 重建时使用清单中的公开资源名嵌入。
