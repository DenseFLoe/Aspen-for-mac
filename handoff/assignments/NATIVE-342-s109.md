# ApwnIPShell.dll s109 续领

NATIVE-342，owner upstream，assigned_seq=109，自 #13 ACK 起 24 小时。ApwnIPShell.dll 41.0.0.614，原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。

批量恢复三个相邻非叶入口及展开，核对跨界调用的实际目标和对象参数来源。范围与输入如下。

- `[0x36d30,0x36d58)` SHA-256 `10038171822779d326cb8dc777b90ce7b8a4d51a1ce26c6bfc46d989c29831a5`
- `[0x36d70,0x36db3)` SHA-256 `8e5f3d09bf4f57c1f40ee3d4b03f38fcebe7f23376b22074c95515e316690e67`
- `[0x36dc0,0x36dfd)` SHA-256 `78b3429aa2c0b7fff5eb1c6defd5ba4d3c3c97d7b6009b2b68bb72221dd2d62e`

运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-342 --original ORIGINAL --submission CANDIDATE` 和局部回编。[上轮裁定](../outbox/NATIVE-342/s105-decision.md)
