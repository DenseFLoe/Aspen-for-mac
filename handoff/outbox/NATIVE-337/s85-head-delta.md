# NATIVE-337 s85 末次增量复核

从已收件 `fedc23d69963d80b423f4e467efbf68da383ff43` 到 [#445 新头](https://github.com/DenseFLoe/Aspen-for-mac/tree/a26cc3db036fbd4521ecd0252e1fbc4d2bc8c5e0) 共三路差异。新增 `handoff/inbox/NATIVE-337/s85b-preflight.md`，blob `dadfe127f71689f2b9905f833988da8cd13c731c`，SHA-256 `ea20e08bd7257da99dd025a277b7421170cb146530cfb3d69f8ac4e5e9f75343`，删除旧 `tool/preflight.py` 与 `tool/preflight_backtest.py`。

新回执给出本地版预检 SHA-256 `fa486947bcdd5dd27322bfad70338ac88473bc56dd0afed8d655d742c50608d2` 与 L2 零缺陷，规范版另放 `tietoumiao/preflight`。复验需要该次实际工具及依赖的固定提交和可回读清单。0x1389 参数表与 s65 分类源在这段差异中未改，原件复验和 returned 继续适用。 [裁定](s85-decision.md) · [对照](https://github.com/DenseFLoe/Aspen-for-mac/compare/fedc23d69963d80b423f4e467efbf68da383ff43...a26cc3db036fbd4521ecd0252e1fbc4d2bc8c5e0)