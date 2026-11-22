# check-cutoffs.py 的复验说明

仅复验本函数。使用 Zig 0.13.0、Capstone 5.0.6、iced-x86 1.21.0、pefile 2024.8.26 和同一交付目录的 verify.py。仓库根执行 `python -B handoff/inbox/NATIVE-350/s45/check-cutoffs.py ORIGINAL ZIG --evidence-dir OUTPUT`，标准输出为 JSON。脚本仅解析原件 PE，未加载执行 DLL。

Aspen Plus V15.0 Engine/Xeq/zedstwu.dll，版本 41.0.0.609，原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。 文件 SHA-256 `d71c89893abbe5158d1ae40b7582c21e57be629e202e6be72da128f7dc856c61`。

整件覆盖 152/255 个入口，尚余 103 个入口缺口和 26 条未决引用，静态验收未通过。 后续追踪见[本轮回执](../s45-submission.md)。
