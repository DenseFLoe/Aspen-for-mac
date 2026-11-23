# ApwnIPShell.dll s113 续领

NATIVE-342，owner upstream，assigned_seq=113，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

补验三个已定位的清理目标，核对参数缩放、分配边界、末端调用及各自异常展开。范围与输入如下。

- `[0x1d570,0x1d5b3)` SHA-256 `656f2f241b7ee36d0da7632df7122055d85810f66a20ef54bc302d4aef9cbe5f`
- `[0x1d5c0,0x1d602)` SHA-256 `0a14d343f762907259fbc489b93f48952bb07b3072a5715acc943521db60cfe0`
- `[0x1d610,0x1d652)` SHA-256 `20d2e416920bedd457831630d142b7ee124d3d05a14096f0075ed3ff6cce017f`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s109-decision.md)
