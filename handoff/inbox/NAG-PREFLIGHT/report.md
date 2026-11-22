# #369 与 #370 尾部提示修复预检

**建议退回 #370 当前提交。** 对 504 个变更路径逐一读取原始和修订后的源码文本，按 Git blob 去重核验了全部 390 个新对象。72 个路径精确删除指定的尾部两行，384 个同时将 CRLF 改为 LF，48 个即使归一换行仍有其他变化。

| 固定输入 | 提交 |
| --- | --- |
| 文件比对基准 | `a9ea5dfcc5ba8c12ac306e73f79fa02e30e7ea04` |
| [#369 的 mapping.csv](https://github.com/DenseFLoe/Aspen-for-mac/blob/584a04a3993eba2546bc6802cf4798f30a8e551d/handoff/fixes/nag-tail/mapping.csv) | `584a04a3993eba2546bc6802cf4798f30a8e551d` |
| [#370 全量修复](https://github.com/DenseFLoe/Aspen-for-mac/pull/370/files) | `b7391aa8cabacad7104de1d8c8e83ca5eaa69540` |

## 台账与文件身份

455 个来源行含 427 种旧 SHA-256、426 种预期新 SHA-256。每行的旧 SHA 均在同文件名的基准文本中找到。按文件名、旧 SHA 与新 SHA 三项联结，414/455 个来源行在修订目标上得到验证。41 行缺少预期版本，涉及 36 种不同新 SHA。按目标路径统计，443/504 个有匹配的台账指纹对，61 个没有。来源行和目标路径分别计数，同内容的多个目录只在按路径统计时展开。

390 个不同文件名在 #370 每名都只有一个新 blob。#369 中 35 个文件名各需两种或三种新内容，合计涉及 80 行。另有一处行数口径待解释，`Infragistics4.Win.UltraWinListView.v15.1.dll` 标注 TAIL2，行数记为 2 → 1。精确尾删以实际文件字节核验。

例如 `analysis/20261120-batch-driver/Aspen-Properties/[CommonFiles64Folder]/AspenTech Shared/decompiled/SLMServerCLS.dll.cs.txt` 的旧指纹为 `113c88f1c8fd…`，精确尾删应得到 `dce794406301…`，实际为 `d4008c900e8b…`。该改动把程序集版本从 2.0.0.0 改为 1.0.0.0，并移除了 `clsServer2` 类。该文件名的三个目标最终指向同一 blob `df76629f4d08ea0e3540b55a8c5a970b1870bd3a`。

## 镜像、索引与发布包

504 个目标全部为 `.cs.txt`。其中 428 个在正式导出目录，76 个在 decompiled 镜像目录。变更触及 1 个已经归入静态验收通过目录的导出物。逐一回读 428 份正式导出的同件归档说明，**428/428 的 C# 指纹前缀和字节数仍匹配基准文件**。PR 中变更的 manifest、指纹说明与包文件均为 0。历史发布记录可作为基准，修订版需另给可追溯的目标路径和新指纹。

读取 v0.20261121-w2 发布页的 5 个资产 ID、大小与 GitHub 记录的 SHA-256。资产总计 1,608,225,971 字节，本次只核验发布元数据，未下载发布包或逐个检验包内成员。正式导出、仓库镜像和原发布包应分别记录版本。[发布页](https://github.com/DenseFLoe/Aspen-for-mac/releases/tag/v0.20261121-w2)

## 恢复条件与复跑

按基准提交的目标完整路径及旧内容 SHA-256 分组，保留同名异版本和原换行。对每个路径执行精确尾删并核对新 SHA，同步修订版指纹及来源关系。若另需规范换行，由上游明确裁定其范围并独立计数。此预检只检查修复操作和索引，不改各原件的静态验收状态。

在仓库根目录执行 `python -B handoff/inbox/NAG-PREFLIGHT/preflight.py --check` 可离线重算指纹对、尾删分类及归档说明统计。退出 0 表示预检证据内部一致，修复裁决见本报告。使用 `--refresh --evidence <新路径> --jobs 12` 可重取固定提交的源码文本、逐件说明和 GitHub 元数据。两次采集间，发布页的资产元数据可能更新。原始映射、504 条路径记录和发布资产指纹收录于 [evidence.json](evidence.json)，本次证据文件 SHA-256 为 `1cc21f20f5a2154bbd79ab56c2d341a5c3d37d778bdd703fee3f0d4faf58be98`。
