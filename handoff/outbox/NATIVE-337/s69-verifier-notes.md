# NATIVE-337 s69 固定交付复验

固定 [#445 @ 12bca3ef](https://github.com/DenseFLoe/Aspen-for-mac/tree/12bca3ef1f92a7f3bc9ec9f575caff37bf62a610)，原件 SHA-256 `3b3a8100a0ac587d2707935409fb2a8c5fd71eae659f95edb99c9f604454ff02`，主干 `7ce64a251d9c5210041903988c016a53b3f85287`。核对本轮 9 个变更 blob、沿用 75 个固定证据文件。按[任务卡](../../assignments/NATIVE-337-s69.md)和[覆盖证据 v1](../../standards/native-coverage-evidence.v1.md)第 4、5 项复跑。

在固定候选目录放置主干覆盖检查器及同哈希原件硬链接 `_t13/orig/FindComponent.dll`。保留此前三套 `work/s49-layout-*` 布局。使用 Capstone 5.0.6、pefile 2024.8.26。

    python -B s69-review.py FIXED ORIGINAL s69-recheck.json

用 PE 异常目录内的原件代码独立找到 149 站，按固定导出函数边界追加解码后为 161 站，首跳、IAT 槽、导入库及名称或序号与提交的站集全部一致。三种布局均为 161 站，0x106C→525，0x12DA→528。六场景与三项 s69 测试退出 0。覆盖 v1 退出 2，307 个覆盖项、307 个原生条目、684 个调用、0 个覆盖缺口，112 个调用仍未决。

## 错误指令字节仍获相同输出

在固定原件和主表下，仅把 `code/native.asm` 第 28 行的编码从 `E8 32 3A 00 00` 改为 `E8 33 3A 00 00`。前者首跳 0x4AA3，后者 0x4AA4。证据文件输入指纹从 `0d84e8afeb96cbfbf90e58b9f78506cc19216292ecbb87883ac2c87fdf153c92` 变为 `07923dc4cc1eb6cd2dc300eaf16c134678c05b5118bc663a9b68b9666a7c7d91`。按第 4、5 项，应拒绝该证据并定位 0x106C。覆盖 v1 两次都退出 2，计数相同。候选分类器仍报 161 站全部 `ok`，因为它用原件重取跳转，但未比对候选行的指令字节。覆盖 v1 SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`，分类器 SHA-256 `89ceca2e4d32a812875f6ef4901551c2d79530021172192ce26dda7a97fffb0d`。建议按 RVA 对齐实际引用行，再核对整条编码和跳转目标。回归正例保留原字节及 161 个站，负例应定位 0x106C 并报告指令字节不符。

## 删除旧站表路径会漏掉原件站点

沿用 [s65](s65-verifier-notes.md) 的删清单指令用例。新分类器在有旧表时输出 160 个 `ok` 和一个 `missing-listing`。对同一缺行输入指定不存在的 `--reference`，分类器仍退出 0，且只输出 160 个 `ok`。覆盖 v1 正确退出 1。建议以从原件独立生成的站集关联各布局，对无法建立站集的输入明确报错。移除一个候选指令且未提供旧表时，仍应定位 0x106C 缺证或报告无法建立基准。

回执列出的 `tool/pe_reader.py` 指纹与固定 head 的实际指纹 `5383333399175b94f3624d5ef95db2fbffdc1d8c0f23b6983ef3cc01e4e87367` 不符。固定 head 脚本实测通过上述正例，下一交付随同更正指纹。完整用例、命令和输出见 [复跑记录](s69-recheck.json) 及 [固定文件指纹](s69-fixed-manifest.json)。
