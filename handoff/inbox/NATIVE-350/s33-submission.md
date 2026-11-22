# zedstwu.dll s33 交付

NATIVE-350，owner upstream，assigned_seq=33。原件版本 41.0.0.609，SHA-256 为 09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b，基线 main 96b1f2452703fe53cdcfff16d26ed4bc11c20d68。

恢复 0x13000–0x148c1 的 6,337 字节，包括 139 条指令、704 个差值槽和 0x148c0 的单字节 RET。四处分派有 56 对位置与可达目标，另核对 33 个直接分支。0xcd1a 对反相能力位与 0x7189d9fee 做 TEST，匹配路径调用 0xccc0 取得 0x13000。0x1306d 从可写节读取 0x22250，64 位磁盘初值为 4,096。该值影响普通写入和非临时写入路径，运行期写入者待证。唯一 COFF REL32 字段为 0x13070。

255 个入口仍有 106 个缺口，3,567 条调用与数据引用中有 26 项未决。下一件核对 0x148d0 的索引与初始化门禁。

从仓库根运行 `python -B handoff/inbox/NATIVE-350/s33/check-fill.py ORIGINAL ZIG --evidence-dir OUTPUT`。复用 Zig 0.13.0、Capstone 5.0.6、pefile 2024.8.26，以及 zedstwu.dll 所用 iced-x86 1.21.0。复跑 JSON 与原件清单应吻合。结构覆盖命令见[覆盖检查记录](s33/coverage-check.txt)。[成果清单](s33/manifest.sha256) SHA-256 为 7f74f8417d6c7f74603a83858ea70a0d825067747693ad7e8b2601280e2c5bcc。
