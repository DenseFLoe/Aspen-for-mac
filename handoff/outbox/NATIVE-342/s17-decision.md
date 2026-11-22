# NATIVE-342 s17 裁定

**退回续办。** 原件 SHA-256 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`，基线 `b04042ca387010579df70bbfccbf882460435824`。候选见 [s17 交付](../../inbox/NATIVE-342/s17-submission.md)，[指纹清单](../../inbox/NATIVE-342/s17/manifest.sha256) SHA-256 `910d0938c06ec3fec4d930921bb3684da9a9cc26aead1a1ca05f11fbec3dcb59`。

上游在独立目录重编，0x33ac0–0x33b80 的 53 条指令、192 字节和 3 个 REL32 一致，独立核对八个异常目录记录及帧的共享关系。0x33b14 与 0x33b4d 的运行期目标保留未决。覆盖 v1 输出 1005/1005/7433/293，退出 2，636 条引用未决。整件维持未通过，s21 续查直调来源 0x33a40–0x33ab2。[复跑结果](s17-independent-reassembly.json) [任务卡](../../assignments/NATIVE-342-s21.md)
