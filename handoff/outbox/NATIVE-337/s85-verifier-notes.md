# NATIVE-337 s85 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ fedc23d](https://github.com/DenseFLoe/Aspen-for-mac/tree/fedc23d69963d80b423f4e467efbf68da383ff43)。主干基线 6f39d81802e8d60331c0c6706f192ae7d45ac52a。

开工回执只有 13:0x，台账使用第一个固定提交的 UTC。覆盖 v1 命令 `python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission CANDIDATE`。逐址复跑命令、工具指纹和输入见[独立复核](s85-independent.md)。

- `s65_counterexamples.py` SHA-256 `d16fc3b4121fa4ad2d3c31978f3fe902e05fa555e4c81570061f47fcf03d0d54` 在实际分类入口对 0x4AA3 用只含 mod/rm 的掩码。原 RVA 0x4AA4 由 `25` 改为 `05`，位移相同。预期枚举、分类均移除 0x106C；实际枚举 161→160，分类仍 161 ok。`s73_stations.py` SHA-256 `0bc2d114e359ba8d3557071ac10f053be93220eaee2929f2e1af4a239cc8e319`。给两个入口复用 FF /4 解码，并保留 JMP／INC 的生产路径配对。
- 固定真实原件，只改调用表 0x106C 的 #2344 为同 DLL 实际导入的 #2348，重算输入 SHA，实测 160 个正确及该站 1 个冲突，符合预期。
- [注册及元数据输出](s85-registration.json) 固定 64 位注册的 ProgID、CLSID、类、程序集 SHA 与方法签名，32 位视图另核同一 CLSID。复跑 `pwsh -File s85-registration.ps1`，需要匹配的 Aspen 安装；全程静态读取。

[逐项输出](s85-recheck.json) · [固定文件及 SHA-256](s85-fixed-manifest.json)
