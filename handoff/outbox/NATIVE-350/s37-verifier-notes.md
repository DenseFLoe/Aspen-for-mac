# NATIVE-350 s37 验收器对照

任务卡覆盖 v1 `check-native-coverage.py` 固定于主干 `b04042ca387010579df70bbfccbf882460435824`，SHA-256 `27f643b9452705c4156bdb5c028f8aad2d2523fafb6853c02058d471580a34a8`。[输入及指纹](../../inbox/NATIVE-350/s37/manifest.sha256)、[实测](s37-unwind-control.json)。

```text
python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original ORIGINAL --submission UNIT
python -B UNIT/s37/check-query.py ORIGINAL ZIG --evidence-dir OUTPUT
```

同一固定原件与候选，控制副本只把 `capability-query.c` 的 `.seh_stackalloc 32` 改为 48，保留 `sub rsp, 32` 并刷新源码和交付指纹。静态验收要求检查实现结构与必要元数据。覆盖检查的两次输出同为 255/255/3567/105、退出 2，无法指出 unwind 记录错误。独立回编两次都核对代码字节，真实交付退出 0，控制副本在 .xdata 对照退出 1。

建议对交付明确声称已恢复的异常展开记录，支持按 PE 异常目录选取和比较原件、回编件的 UNWIND_INFO。把此配对纳入回归。真实样本的展开记录应通过，控制副本应定位栈分配不符，两者均保留与该记录无关的缺口。生产验收器本轮沿用已发布版本。
