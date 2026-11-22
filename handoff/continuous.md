# 双方连续工作约定

交接沿用 README 中的角色、任务行、状态和验收标准。每台机器从已经分给自己的独立任务中取活。第一件产物发 PR 并在 #13 指向固定 head 后，释放该执行槽位，立即开下一件。上游可以同时复验上一件。两台机器的输入可以复用，写入的原件、任务目录与输出不得相撞。

## 一个任务怎样接到下一件

1. 上游为双方各准备可独立开工的下一件。对能并行的原件预分多个独立 task_id，每行只有一个 owner，并写上完整原件 SHA-256 或固定的输入提交、标准、判定命令和时限。新分配以独立的 `handoff/assignments/<task_id>.md` 为证据，按实际字节写入台账。一次 PR 可发布多行。旧事件所引的 tasks.csv 指纹，按引入该事件的提交回读。
2. 执行进程按 owner 取 ready，结合本机的 CPU、内存、工具许可和已有作业决定能同时开几件。有空槽且有独立输入就可并发；同一机上的多个 worker 由一个本机分配者领取，登记后再启动。执行者在本机保留最近处理的 `task_id + assigned_seq`、工作目录和 PR head，进程重启先接回原工作。上游和对方各自控制自己的机器。
3. 开工回执用 `inbox/<task_id>/s<assigned_seq>-started.md`，交付回执用同目录的 `s<assigned_seq>-submission.md`。写明 owner、原件指纹、范围、产物路径、关键结果或缺件及恢复条件。两个回执和产物可沿用同一 PR；在 #13 给出任务号、轮次和最新 head。同一 PR 新 push 更新 head。旧版带时间戳的回执仍可由上游核对登记。
4. 上游优先处理 submitted，根据开工与交付证据补齐连续事件。按精确 PR head 运行主干已确认的验证器，复查内容、指纹与适用标准，再记录 accepted / returned / blocked。PR 在验证后有新提交，先验新增差异并绑定最新 head。采用 expected head 合并；主干前进时重读受影响的分配行和最新 seq 再写，禁止覆盖并行者的记录。
5. 返回或阻塞的任务保留原 owner 和历史。上游写明恢复条件后重新 assigned，新的 assigned 事件序号即新轮次。超时先走问询；换人前确认旧执行者已停或已交付，保留旧回执。去重分两层：同一原件 SHA + 同一工作范围与标准只由一方承担；同一轮的重复通知按 task_id、assigned_seq、PR head 和动作去重。交付后即检查剩余 ready，低于可用槽位时上游补入有证据、无人占用的下一件。暂无可做项时等待新信号。

## 领取和唤醒

在普通文件目录运行，需 Python 3.11+。上游用 `--owner upstream`，执行方用 `--owner tietoumiao`。有完整快照时使用本地队列。

```text
python -B handoff/dispatch.py --owner tietoumiao --json
python -B handoff/dispatch.py --owner upstream --limit 2 --json
```

输出中的 ready 可开工，working 表示已有开工信号，review 等待上游验收，waiting 说明等待原因，terminal 为已接受。每件同时带正式 ledger 状态和当前轮次。文件回执是提示，上游仍须登记正式状态。发现损坏的表或矛盾的序号时校验退出 2。若本机有尚未合入的开工 PR 或 #13 回执，优先续办原件，避免把主干的旧状态当作空闲任务。

已运行的本机调度器可从受信版本取得同目录的 `watch.py` 和 `dispatch.py`，用下列命令等远端变化。只读取本库 handoff/ 与 #13，下载任务表、台账及回执文件名。无需克隆、执行远端命令或安装常驻服务。

```text
python -B handoff/watch.py --owner tietoumiao
python -B handoff/watch.py --owner tietoumiao --after <上次已处理的cursor> --timeout 1800
```

首次调用立即返回当前队列。收到变化时先回读 #13 自上次已处理位置以来的全部新回执，并处理相关任务；成功后才由调用者持久保存 cursor 和该评论位置。传入旧 cursor 可重放。超时返回 changed=false。读取失败保留旧 cursor 并重试。匿名读取默认每 180 秒探测，已有 GitHub 只读身份时默认 60 秒。每次探测只比较两处入口；发生变化才展开任务表。也可用 `--timeout 0` 单次探测。对方正在运行的执行器可在提交、遇阻及释放空槽时直接调用；是否接入持续等待，由对方在 #13 回执。

GitHub 托管预检在交付 PR 更新时处理可在云端完成的检查。需要原版环境、Windows 原生工具或完整产物的复验留给相应机器。上游现有的 30 分钟巡检负责补查漏掉的事件、修复卡住的交付、验收及补足队列，同一轮可连续处理多件。检查点记录已读取的 main、PR head、#13 评论和未办事项，仅在成功处理后前移。
