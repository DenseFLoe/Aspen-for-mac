# zedstwu.dll 第二十一号续领

NATIVE-350，owner upstream，assigned_seq=21，本轮 #13 ACK 后 24 小时。原件 SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`，来源见[首轮卡](NATIVE-350.md)。以[第十七号交付](../inbox/NATIVE-350/s17-submission.md)、[回编证据](../inbox/NATIVE-350/s17/dispatch-evidence.json)及[裁定](../outbox/NATIVE-350/s17-decision.md)为基线。

沿两个缓存初始化器加载目标的来源，先补三个原件入口。两个叶函数的原件均为 RIP 相对 LEA 后 RET，异常目录为 memcpy 分派目标固定了第三个边界。

| 范围 | 原件关系 | 原字节 SHA-256 |
| --- | --- | --- |
| `[0xcbe0,0xcbe8)` | 返回 `0xcd80` | `d740376f069513192c97c0dbdda6e5c39eedd1360a62c58fe60ce92d91d43fb8` |
| `[0xcbf0,0xcbf8)` | 返回 `0xe5c0` | `8e76d8faea7a668fed332a38927d8ebcb47e2f8484cdebe053e9e3cf10e846ea` |
| `[0xcd80,0xe589)` | memcpy 分派实现之一，6,153 字节 | `72586b05df77ea74f39bcc554d92941fe99e1e417afeb70728e4a4dec746d58b` |

恢复可编辑实现，分别回编并按原件核对重定位、批量边界和共享数据。将两个 LEA 绑定及 `0xcd80` 的调用、数据引用逐址入表。保留已证的分派及缓存槽关系，并记录另外几个候选目标的恢复条件。按[上游覆盖证据](../standards/native-coverage-upstream.v1.md)运行 `python -B handoff/assignments/check-native-coverage.py NATIVE-350 --original <固定原件>`，附三段实际回编和逐件判定。
