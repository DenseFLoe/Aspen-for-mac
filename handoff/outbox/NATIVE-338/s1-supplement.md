# NATIVE-338 第一号分配补件核对

原件 Happ.dll，SHA-256 为 7d4964f25cee38127a0b68fd3c0360c79c030f4c6ed24aa2d2e50b68e008936a。[固定候选](https://github.com/DenseFLoe/Aspen-for-mac/commit/6ce02403d7a731b48d95ea0bcdc83d1b5b072092) 相对前次裁定的 2dae2f74ef4fd86e4eaeab00852b2fb6c3c3a6db 新增 10 个提交、共 13 个文件差异，均在本件收件目录。第一号分配维持原裁定。第五号分配已按 #13 指向的 #403 分支提交 372fca80ee5940ec58951f3d3b243a1ad92e7e1f 发出 ACK。本记录只核对旧轮候选补件。

新增的四份汇编、四份 C 分片分别连接后，和前版的 98,270 行汇编、93,248 行 C 逐字节相等。复核 1,971 条覆盖及其源码、清单引用，5,121 条主表和 2,630 条附件引用；每个新行号指向相同文本，其他业务字段逐行相等。表格指纹与此固定候选的 metrics.json 一致。

在相同原件及候选目录上运行 python handoff/assignments/check-native-coverage.py NATIVE-338 --original <原件> --submission <候选目录>。旧主干检查器 c0853c353b1dd8a3f4eb47695d485540faec6ea5 退出 0。#403 分支提交中的附件核对版 e0b5e9c4617c9fdff9ba8d3179b60f7abad52979 退出 1，检出 2,630 处附件转移在主表缺失。RVA 0x25b90 的函数和 0x3f478 的 11 项表仍只指向新分片 C 的标题行；两张表共同漏报的 50 项及 1,121 个调用方至导入跳板的关联尚待补齐。后续固定提交 6f513f88436347d23ab3f070f614413cb175e08e 相对本次证据只改 metrics.json 和 s9-submission.md。该时点 metrics 报 calls SHA-256 为 1c0483f2c5cbc8484ea776298fd8e4625860c042b905ea81cff8fd8707f83f46，交付说明记 7,751 行、exit 2；其 calls.csv 仍为下表的 5,121 行版。此处只记实际文件和说明的差异，待后续稳定材料及回执再复核。

[第一轮裁定](s1-decision.md)和[逐址清单](s1-addresses.csv)记录恢复条件。下表是固定候选 6ce02403d7a731b48d95ea0bcdc83d1b5b072092 的全部变更文件指纹。

| 变更文件 | SHA-256 |
| --- | --- |
| calls.csv | 51c17ec7d58fe6386a55ce997ba97338524dbdbd60f96d84c249d9d7568eebaf |
| code/indirect.csv | 2f08303dfabb26b23964149fd2649bf955032d0b5aaa063237483f2f955f514f |
| code/native-1.asm | 21a041eaa1777cc186c98c16f9322217283db4fd342ef29391ab61c82fa5fae7 |
| code/native-1.c | 821ee419cdd240079505ce973fca598b37b861eef2925959e1ae76cfa6c26ff1 |
| code/native-2.asm | b4eebb64b7ed5bdefe8b5a48aa3a4bddd09eec182234c82417239a809a887583 |
| code/native-2.c | 7b0c61468028f8e3eb52cfee1feb59c7e2c6545789f8d6e6bfbbdbd79239ddb9 |
| code/native-3.asm | 363a305d6bb523d677ca4883a7517cd733eace151a68d288c60d64bc15c37ac5 |
| code/native-3.c | b6140a372b561fe15d7381ab2ffdec16a65810d953666ec68801a0581c7e5a73 |
| code/native-4.asm | 3754fa04b06cbe8cc8f8bf4068871e9db7fbab23a9d89d05279f8933cdef542a |
| code/native-4.c | 611f1e93ac5a17009b040cb5f578f8f8029f4057a73bd7673cca52fa8e90e870 |
| coverage.csv | 7379a974936cced5f933d62655472f1fdc72fa1bc656e95b8651f6e13a532ce7 |
| metrics.json | 1f2c956ecb54c81987f703e3be7805fe980dcad9f3216e054250de889f696999 |
| s9-submission.md | 87fabbeccc4cbf100370e403fd7dd4e459a6c4edef4c3e195ee524856e4cc1a5 |
