# NATIVE-337 s93 验收器复验

原件 FindComponent.dll，SHA-256 3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02。固定候选 [#445 @ a6f1c16](https://github.com/DenseFLoe/Aspen-for-mac/tree/a6f1c16a1363de07002b89d5f31ebd42d98315c7)。主干基线 2cb8a177a47da004ddd4b305f8fe31107c2d2afc。

本轮按固定原件和主干覆盖证据 v1 复验。

1. 在原件不变时，分别只改两跳表输入的同 DLL 真实序号 #2344→#2348 和 #2348→#2207。s37_two_hop.py SHA-256 6edacdbdac9a8a5e851a720f217057c0a34d60b6b00d68a90d1c5a851cf8d4dd，将行 525、526 各自改为空，符合逐站证据要求。
2. s81_showdialog.py SHA-256 156049b88e376906674638e83f3526c5ebf5669c9ab2c6b26fd7e62ebf778288。执行 `python -B s93-replay.py COVERAGE CANDIDATE ORIGINAL NATIVE-337`。固定原件，只把清单 0x13DD 的 MOV 立即数从 8 改成 3。预期报告固定原件与清单不符，实际退出 0，将 b803000000 同 vt=8 一起输出。另一对照仅将清单 0x137F 的 LEA 调到 IID_IDispatch，实际退出 0，整份生成表指纹原样。建议逐处比较原件和列表字节、为每个证据键输出唯一行。回归用例为原件和正确列表通过、任一位置单改时定位具体 RVA 并拒绝生成。
3. 生成表的 VariantInit 行仍写 24 bytes set to VT_EMPTY。公开契约只保证设置 vt，24 字节是元素步幅。已核同安装 ProgID、CLSID、程序集及 int32 ShowDialog(string) 的材料来自原件的部署证据。动态 DISPID 继续保留。[Microsoft VariantInit](https://learn.microsoft.com/en-us/windows/win32/api/oleauto/nf-oleauto-variantinit) · [已核部署证据](s85-registration.json)

[逐项输出](s93-recheck.json) · [固定文件及 SHA-256](s93-fixed-manifest.json)
