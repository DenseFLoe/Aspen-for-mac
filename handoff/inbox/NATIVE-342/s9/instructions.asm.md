# instructions.asm 静态证据说明

ApwnIPShell.dll 41.0.0.614，原件 SHA-256 为 `ace0556a2b9da51821c45b2a8c119ac990b51135b8b5b5d5d4f09422e051502b`。成果 SHA-256 为 `777074658ec4509ca8df4a6095984de304df4db05aed89730671f5da9576dbd9`。

用 Capstone 5.0.6 直接从两个原件范围生成的 94 条指令和原件字节。用于本轮四条覆盖记录及四处间接转移。0x15ab、0x15f6 行仍落在同一宿主函数。
