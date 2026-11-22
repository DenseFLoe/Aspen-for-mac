# 可执行的独立复核

Aspen Plus，APrSystem V15.0。原路径为 `Plus/[ProgramFiles64Folder]/AspenTech/APrSystem V15.0/Engine/Lib/nl2sol.lib`，原件 203,986 字节，SHA-256 为 `7738ce952d97d2f27c6fce67e735f5e710598a8ce1b77746cbe443f611fe4dee`。归档中没有独立库版本字段。

接受指纹已知的原版与本机 GNU as 的路径。在临时目录用交付源码重建，比较全库字节和成员指纹。接着在一份临时汇编源码的 SSQJAC 入口插入 NOP，核对其余 67 件、97 条代码重定位、26 个分派目标、函数范围和展开记录。实测两项检查均通过。

成果 `nl2sol.lib.check.py` 的 SHA-256 为 `a7252637d6d01c55393be7895def8f398e4361c5445812fcf7a0373c1970dff5`。本件已通过整库静态验收。独立复查命令、原件来源和后续 Windows 行为对照范围见 [逐件说明](nl2sol.lib.md)。
