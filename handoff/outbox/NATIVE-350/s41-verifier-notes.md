# NATIVE-350 s41 验收器复验

沿用 [s37 的覆盖与回编对照](s37-verifier-notes.md)，本轮从原生异常目录扩展到可编辑的只读数据。覆盖 v1 固定在 [183ec4a 基线](https://github.com/DenseFLoe/Aspen-for-mac/tree/183ec4aeb38f5463a99aadc2fbdbbc3326ce243a)，SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。

    python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE
    python -B CANDIDATE/s41/check-initializer.py ORIGINAL ZIG --evidence-dir OUTPUT

只把 [initializer-data.c](../../inbox/NATIVE-350/s41/initializer-data.c) 的描述符 0x49 数值从 4096 改为 4097，并刷新成果清单和回执指纹。任务卡要求核对初始化器读写的原件数据。覆盖检查两版均退出 2，输出相同。范围回编正确版退出 0，改动版退出 1，报告 `descriptor table mismatch`。[成对输入指纹和原始输出](s41-descriptor-control.json)

建议在已有独立回编证据时，按原件数据区域上报重建字节比较。以本轮单变量用例回归，正确版应记录描述符表字节一致。改动版应定位描述符数据区域的差异，覆盖统计仍可如实保留。
