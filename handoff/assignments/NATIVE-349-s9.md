# NATIVE-349 第九号分配

执行方 upstream，assigned_seq=9，自本轮 #13 ACK 起 24 小时。原件为 Plus-Properties 的 `Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/Ikc2Bkp.dll`，版本 41.0.0.614，217,128 字节。输入固定为 `64670801de54e990f975aaeda06e89340c0e4e08` 的 `issue-materials/349/Ikc2Bkp.dll`，SHA-256 为 `bba17051eb1071e5f48702f685f1d8d5d3b9f5cfd222f357e30fd0545bf00011`。[第五号候选完整目录](https://github.com/DenseFLoe/Aspen-for-mac/tree/bd51e24c0b9a7c87bea21e32bb8c955b31ce4a1e/handoff/inbox/NATIVE-349) · [原件与任务身份](NATIVE-349.md) · [上游原生覆盖标准](../standards/native-coverage-upstream.v1.md)

**新增恢复依据。** 原件的 PE 导入表把槽 0x26150 绑定到 `api-ms-win-crt-runtime-l1-1-0.dll!_initialize_onexit_table`。RVA 0x2548c 的六字节跳板为 `ff25be0c0000`，RIP 相对寻址恰落在该槽。0x24ada、0x24aea 两个直接调用均落到该跳板，前导 LEA 分别传入 0x34948、0x34960。两个表相距 24 字节；备用初始化路径从 0x29e90 读到十六个 FF，并写入两处表头。该证据将宿主 0x24ab0 与两份具体 CRT 数据表及其初始化 API 相连。

前一轮提示异常表边界附近仍有待解码字节。本次按异常目录真实右界复读，0x244c4–0x24548 为 132 字节、39 条指令，末尾 0x24545–0x24547 是 `90 90 cc`；0x24ab0–0x24b3b 为 139 字节、36 条指令，末尾 0x24b3a 是 `cc`。两处均无间接调用或间接跳转；所有条件分支落于各自已解码边界，两个末端前的直接调用均到 0x24ca8。按原件保留这些尾字节，并逐条区分正常返回、调用返回后后继和填充/陷阱语义。原件级字节摘要、调用和导入槽记录见[本轮恢复证据](../outbox/NATIVE-349/s9-recovery.json)，SHA-256 为 `6f0917aa0416dc6a3dfb61ed7927774b697f04ffd622b98e7f235c29472772a9`。可用 pefile 读取 exception/import 目录和映射映像，以 Capstone x86-64 从两处起点解至所列右界，复算两个宿主摘要、控制转移操作数与 RIP 相对目标。

**交付和裁定。** 在 `handoff/inbox/NATIVE-349/` 补两处宿主的可编辑实现、调用关系、数据与返回分支说明，留存指令覆盖和按原 RVA 应用 COFF 重定位的逐字节证据。逐项核对旧 17 个入口与 15 个未决转移的本轮去向，保持原 185 个实现和四处第五轮展开入口可复查。使用本轮独立回执 `s9-started.md`、`s9-submission.md`。原件级结论继续使用固定的原生覆盖标准。

在本件目录执行 `python -B reassemble.py <原件> <Zig>`，核对先前 145,008 个字节与 5,322 处重定位并列出新增量，再核对两份原始范围及控制流。由仓库根执行 `python -B handoff/assignments/check-native-coverage.py NATIVE-349 --original <原件>` 并记录退出码、调用及覆盖计数，列明剩余缺口。Zig 0.13.0、pefile 2024.8.26、Capstone 5.0.6 可复用。该卡已提供可开工依据，正式开工由领取回执确认。
