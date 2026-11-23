# NATIVE-337 s77 独立复验

按 [#445 固定 head](https://github.com/DenseFLoe/Aspen-for-mac/tree/44fcb193b159bfef5566ce1109c4d14808198d14)、[任务卡](../../assignments/NATIVE-337-s77.md)和[覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)复验。FindComponent.dll 原件 SHA-256 为 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`。本轮相对 s73 候选增改 12 路，PR 共 95 路，复验固定了 107 个相关文件和回执所列 9 个指纹。开工回执只写 11:0x，台账取本轮最早精确提交 02:50:19 UTC，提交时间取固定 head 的 02:50:25 UTC。[固定指纹](s77-fixed-manifest.json) · [交付回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7090268958)

以 Capstone 5.0.7 和 pefile 2024.8.26 运行：

```text
python -B handoff/assignments/check-native-coverage.py NATIVE-337 --original ORIGINAL --submission handoff/inbox/NATIVE-337
python -B s77-review.py FIXED ORIGINAL s77-recheck.json
```

覆盖 v1 SHA-256 为 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。覆盖结果 307/307/684/0，112 个未决，退出 2。三种布局各 161 站，0x106C 对应 525 行、0x12DA 对应 528 行。五个反例和六个旧场景均通过。原件重建站表与候选一致，161 个首跳目标均解码为 JMP。独立缺站对照中，完整缓存及省略缓存均报 0x106C 缺站，删去缓存一行并重算指纹的版本被拒绝。覆盖 v1 对缺指令退出 1。[复验脚本](s77-review.py) · [实测输出](s77-recheck.json)

原件 0x2388、0x23A0、0x23C8 对应 MultiByteToWideChar、CLSIDFromProgID、CoCreateInstance，已修正四行。0x23B4 指向 IID_IDispatch，0x23BB 将局部接口槽地址作为第五参数，0x23D2 加载该槽的值。0x23A8 和 0x23D0 可进入 0x23D8 返回 0。0x133D 在两条路径上均执行 MOV RDI,RAX，失败分支的 RDI 为零，提交说明中的“未定义”须修订。0x1343 失败边跳过四站。槽与位移均已独立复核。到 0x1389 的名称参数已有原件证据，0x1345 指向 0x7820 的 UTF-16LE `ShowDialog`。工厂读取 0x78A8 的 ProgID `AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410`，运行期 COM 地址继续凭实际组件或已有可复核的注册证据核对。

## 工具证据

- s77 分类器 `d16fc3b4121fa4ad2d3c31978f3fe902e05fa555e4c81570061f47fcf03d0d54` 和站集脚本 `8b6de989c572f7740f301fba1ef4118de8aebb884c2fcb28823865454b7d916f` 的两个 `thunk_slot` 都接受同 RIP 位移的 FF 25 与 FF 05。独立配对从同一地址解码得到 JMP 与 INC，两个函数实际均返回 0x2000。前者是契合本规则的直接导入跳板，后者只是内存操作。建议按反汇编操作码和间接内存寻址形式确认跳板，固定配对应输出 `0x2000, None`。本原件 161 个首跳均为 JMP，现有站数未受影响。见实测 JSON 的 `thunk_form_control`。
- 候选配对脚本 `7ebd14dd36f7c7bd6ff268ce339f7dda83b25bdfdfdd1443ebeba2fb3d90483e` 写死子进程 PYTHONPATH 为 `D:/Lib/site-packages`。在依赖已通过本机 PYTHONPATH 加载的环境里，CLI 缺 Capstone，两次退出 1。独立对照在保持本机解释器环境时得到预期结果。建议继承环境。回归在依赖位于其他目录且没有 D: 固定路径的环境中，两项应通过。
- 覆盖 v1 的完整操作数比较继续引用 [s73 已知问题](s73-verifier-notes.md)。本轮仅改 0x106C 位移的新候选对照仍为覆盖退出 2、分类器定位 1 处字节差异。
