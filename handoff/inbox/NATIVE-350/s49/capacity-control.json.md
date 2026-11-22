# capacity-control.json 的复验说明

成对输入固定原件、调用表和其他证据，仅将可编辑源码中的 0x151da 容量立即数由 `0x200` 改成 `0x201`，重新生成交付清单。覆盖 v1 两次均返回 2，局部回编正确候选退出 0、变体退出 1 并报告差异字节 0x151dc。先复制候选到隔离目录，再改 `s49/report-diagnostic.c` 并刷新`s49/manifest.sha256` 的对应项，执行主干的 `check-native-coverage.py NATIVE-350 --original ORIGINAL --submission CANDIDATE` 和 `python -B CANDIDATE/s49/check-diagnostic.py ORIGINAL ZIG` 即可复跑。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，原件版本 41.0.0.609，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 RVA `[0x15180,0x15220)`，160 字节，范围 SHA-256 `3a7e60ad7c37883a4c047ccd60a1c35881af319f8d2c4bba9154a5d1fb1a92ef`。 本文件 SHA-256 `8bce688c871321153bfad02a0c6d6b815d34f3e6adc10e95bd747a360826616f`。

整件覆盖 153/255 个入口，仍有 102 个入口缺口和 26 条未决引用，静态验收未通过。 [本轮回执](../s49-submission.md)
