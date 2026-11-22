# zedstwu.dll 第十七号提交

NATIVE-350，owner upstream，assigned_seq=17。固定原件 SHA-256 09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b。固定上轮候选 c57d3a0349dff208bf2a4ef1bd32e9c03ac8a569。

0xcc00、0xccd0 的两个无栈入口与 0xcc20、0xccf0 的初始化器均恢复为可编辑内联汇编。Zig 0.13.0 的 COFF 逐条绑定原址后，319 字节、92 条指令、18 处重定位与原件吻合。两个缓存各自起始为零。读取的 0x22d30 能力字按 0x7189d9fee、0x9d9fee、0x6e 检查位集合，优先选择第一组满足项。复制侧依序为 0xe5c0、0xcd80、0x16560、VCRUNTIME140.dll!memcpy；填充侧为 0x13000、0x11f40、0x17610、VCRUNTIME140.dll!memset。第 4 项在前三套掩码均不满足时使用。原版随后分别在 0xcc9d、0xcd6a 缓存所选地址。逐址结果在 [分派证据](s17/dispatch-evidence.json)，具体运行时目标仍随能力字和缓存实际来源决定。

从仓库根运行 `python -B handoff/inbox/NATIVE-350/s17/verify-dispatch.py <zedstwu.dll> <zig>` （Capstone 5.0.7、iced-x86 1.21.0、pefile 2024.8.26）。运行任务卡的覆盖判定器，仍有 113 个入口缺口和 42 处未决引用。[文件清单](s17-manifest.sha256)
