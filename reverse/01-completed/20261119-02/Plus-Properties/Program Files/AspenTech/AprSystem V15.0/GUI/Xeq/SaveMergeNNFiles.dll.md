# SaveMergeNNFiles.dll · 整程序集 C#

第 20261119-02 轮，Aspen Plus V15 与独立 Aspen Properties V15 共用。本原件逐文件逆向归档已完成。

- 原安装路径为 `C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/SaveMergeNNFiles.dll`，文件及程序集版本 38.0.0.301，原件 SHA-256 为 `a610bfe69f5b86a04d2ace8a8f01fa6048183bd3330ee0e7367a1e6c02671511`。
- 两产品 CAB 成员及安装件各 16,936 字节，独立复算哈希一致。相应 MSI、CAB、成员路径、清单与指纹见 `.local/reverse-round-20261119-02/savemerge-evidence/selection.json` 和 identity.json。
- 成果 `.local/reverse-round-20261119-02/01-completed/Plus-Properties/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/SaveMergeNNFiles.dll.cs` 的 SHA-256 为 `0d31aad550cacc204bad7825ebfb0f4dfc7cc6eed4832acf638747d8f19333f6`。C# 含程序集特性、三个显式方法和 LINQ 投影。投影及其单例、委托缓存由原件三个合成方法及两个字段支持，逐项映射见 coverage.json。
- 核验记录位于 `.local/reverse-round-20261119-02/savemerge-evidence`。coverage.json、source-map.json、资源清单和 operations.md 给出整程序集成员、原代码对应关系、工具版本、操作和逐方法结论。
- DLL 将找到的附件按清单顺序追加到目标文件，原始字节采用 Base64 编码。两处引用的外部程序集为 mscorlib、System.Core。混合模式包装器的实际调用目标与本件入口签名一致，包装器保持独立台账状态。
- 原版在合成文件上通过五组观测，逐字节输出及异常见 original-run-02/observations.json。应用数据目录回退分支仅经静态核验。本件当前归档范围已覆盖；下一步按原件哈希复用，工程重建及端到端对照留待 Windows 阶段。
