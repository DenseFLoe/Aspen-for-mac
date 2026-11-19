# PFSCtrlLib.dll.interop.json

本件来自 Aspen Plus V15 的 `Program Files/AspenTech/Aspen Plus V15.0/GUI/Xeq/PFSCtrlLib.dll`。程序集与文件版本均为 `1.0.0.0`，原件 71,208 字节，SHA-256 为 `5073b8f277f687758a9d064a1508d6ae3439b648f5f4787455efcaf6e4133303`。Plus MSI 的第 2820 号文件位于 `ASPE~262.cab`，成员键为 `pfsctrllib.dll.D470D1DF_9FE5_4F3E_9EF6_CEAA577688D0`。既有包内成员指纹与本机安装件一致。[两条来源及定位](../../../../../../../identity.json)

本件与同目录另外两份成果共同通过第 20261119-11 轮整件静态逆向归档验收。 成果 SHA-256 为 `69d87af2f50a5c6f7882d62040afb681c999b7c532951992c2c96bcb825fffa1`。

本文件保留 C# 投影无法逐字表达的 CLR 互操作约定。使用 dnfile 0.18.0 按原表顺序读取 48 个类型、774 个方法的原始签名与标志、612 条参数元数据、261 条显式方法实现、274 条参数及返回值封送和 509 条自定义特性。属性和事件的 172 条访问器关系按原令牌保留。所有显式实现的方法签名均与对应接口定义一致。

41 个原委托各有两个运行库方法；原事件提供器以普通方法实现 41 对访问器。三个同名命令及事件分别由原 MethodDef、MethodImpl 和 Event 行标识。文件还保存 Mono.Cecil 0.11.6 读取的 Finalize、Dispose 指令、局部变量及异常区域，其方法原始字节和指令偏移已用 dncil 回读核对。后续 Windows 重建据此恢复精确的 CLR 接口形状。[C# 投影说明](../../../../../../../code-coverage.json) · [逐事件映射](../../../../../../../bindings.json)
