# VERIFY-PILOT-3 第一号收件复跑

上游已收到 [#13 的试跑回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7081144599)，按[原任务](../../assignments/VERIFY-PILOT-3.md)及工具提交 `63f12578ef185f22e72b01076e81420b595a9499` 复跑。原件、三个候选和 Zig 0.13.0 沿用任务卡固定输入。上游报告 83,867 字节，SHA-256 `74a3fa68aec761eb4fd3d0cba49f3a82c79ade1c12b6e95a9489bcd105ed6e17`，与下游报告指纹一致。退出 1，绑定 3 件，整件结果为 0 通过、3 失败、0 待核。zedstwu 的四个导出回编专项通过，共 13,218 字节、812 处重定位。

FindComponent 在 #411 固定候选的 475 个原件可核站点中已有登记 462 个、其中显式未决 99 个。13 个漏登位置由 10 次访问 `0x7670` 的 CALL、2 次访问同一槽的 JMP，以及该槽磁盘值指向的 `0x6050: JMP RAX` 组成。逐址从固定原件重新解码。zedstwu 原件取自[首轮卡](../../assignments/NATIVE-350.md)中 `ad53650f6071f83b133ede7bf847bc5096cd3b56` 的固定链接，SHA-256 `09b4491feeb7389b072b9de06b86a6d978dbb61527ad821e181b072bc5b9a59b`。

上游另在可写临时目录与独立编译缓存下复跑，输出相同。将两项 Windows 复跑条件记录在[验收器运行说明](../../../tools/reverse_acceptance/README.md)。

[上游回执](https://github.com/DenseFLoe/Aspen-for-mac/issues/13#issuecomment-7081174181)已请执行方提交三份文件和固定 PR head。入库裁定以对应 PR 的开工、提交及报告三个 blob 为准。届时按同一指纹回读验收。
