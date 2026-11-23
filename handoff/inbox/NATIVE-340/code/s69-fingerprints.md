# 指纹文件选择规则（脚本生成）

## 规则

- 范围：`--unit` 目录下的全部常规文件（递归）。
- 排除：文件名含 `fingerprints` 的文件（指纹 JSON 与其规则索引都不自引用）。
- `--set receipt`（上游脚本读取的扁平映射）：额外排除 `*-started.md` 与 `*-submission.md`，本轮回执不进入该集，保证跨轮稳定。
- `--set round`（当轮回执）：纳入开工/提交回执与审计页，并把 `base_head` 记在文件头部。
- 哈希：SHA-256，按路径字典序；路径相对 `--unit`。
- `code/README.md` 属于常规文件，两套都在集内。

## 纳入路径（107 个，set=round，base_head=ba2c5d5f23eddb10ae0c9d78af2a4dc5d038fa1e）

| 路径 | SHA-256 |
| --- | --- |
| `calls.csv` | `ec0c423492ae0fc543c613f09317cf3562327257e591349c228ed0cece265c72` |
| `code/attachment-check.csv` | `3962493d447e0577d1146273870f3c8746f709c9e01eab4dc2e80a3aa239cc4f` |
| `code/fixup-targets.csv` | `cbc4a420569678282d565110b116ed8f728d449d4713b00ec933e20201ca756d` |
| `code/indirect-native.csv` | `32a174814316472b789abfa4156a01f3afbf48811e3a4b48a7c03e6306b04bbd` |
| `code/indirect.csv` | `ff178b32f33f33ca09e513f6ff45fa7be1bdc44eda275f21fd78ddace837404b` |
| `code/internal-ctor-sites.il` | `d91389edca098ea6c466294d3c5c577d993d098fc751d70595b21c43c7201926` |
| `code/loads-3660.csv` | `b60a6125c8d6b90cefe99f032035613868e37e27fe18af7c945fdb9eca682525` |
| `code/metadata.asm` | `b60183bababecbd0c2a5aeeb1bb3f19a666fc868de164cb11bdaca23d97c5e16` |
| `code/methods.il` | `67207ac2e6bc73135b5501eb43ebf559d33441f80ef859d7d394411ac8a55521` |
| `code/native-fixup-sites-s21.asm` | `b70aea11e116786676bf81631d93e1943773de5424786a5aba7398f5b68707c8` |
| `code/native-fixup-sites-s21.c` | `f842eebb10fff457a52c942e7342e5f02f68a401128450c2dcfd05078446acbc` |
| `code/native-fixup-sites.asm` | `f41f85925e5eea5d929ec581350040d07c6bf78b6f3853e7ddbda681b50a4fe9` |
| `code/native-fixup-sites.c` | `2a95cd2bd558f189b9b7bd27dff471da1d355db136ee802914c0813611479c1d` |
| `code/native.asm` | `92e5e086ba8ba535470842ee752f85258c8cc4cea7c1b4742e041892672fe282` |
| `code/native.c` | `66f39dd85f2206695af59818d0964414966e9792ebcab24301153497177fead1` |
| `code/newobj-sites.il` | `87dedd99cefa21e065ddb7051554e638c72151ce2d5e32760e406cb3f404b9f6` |
| `code/newobj.csv` | `d32c6d10d8bfd7ddc108dac143b6454a4e960db18895cb424f1c7d77b6f2754d` |
| `code/README.md` | `15acd622ba7600493c3676d1444335499da3bbdf7c76d75953d2d3dff4744532` |
| `code/recompile-verify.json` | `6fbff68888ba9473c9b76dac37aa7c077b6638c2f9c32e0caf07ac0895734538` |
| `code/s13-audit.json` | `d70ff9d524ff830bc638ac0507c19ee118111fde6846c35577461dd98f1a838a` |
| `code/s13-audit.md` | `b08a018e0cf0b4fdb06c5598f100fd33108ac287e97380dd65ce315b8a96d50e` |
| `code/s17-audit.md` | `932060fdd0e40ae12b94371cf13a92c4c66038aab34a36f30f089b825be751af` |
| `code/s21-audit.md` | `3ba259998368106f6a94eb4b708b0557422fde6715293a17fee968474c4cce62` |
| `code/s21-extra-sites.csv` | `4c2a74805f21f2a28e716b22cf32f90f1f32838d7b4a36bafe2cde9a69c4cb66` |
| `code/s25-audit.md` | `670a1ad66f24fb1f487243a52f37454a5dd0f3b164223cf400bda79003ccc705` |
| `code/s25-unresolved-managed.csv` | `f7b9db6aead97fcf99ec7ee5972be9b641335601389b009a165dc68369823c98` |
| `code/s25-unresolved-native.csv` | `350c9abd1a6fd1619bd9ca0475394f2ba157e75d70872a4f793e3e6845927cbf` |
| `code/s25-verdict-0x06000030.json` | `00deafdfc886e20e648310cde6b8051f318dcbb6135a7c9b751dddd9c7ed7c11` |
| `code/s29-audit.md` | `f3e72e0daf2e48b5e2653b09c7bb2609e4deebc8acd3cd81bcff388aa62a3b26` |
| `code/s29-verdict-0x06000030.json` | `9961c4a050a47bc927fb4375250407ab3253b33944358b250e40416d83d7e6de` |
| `code/s33-audit.md` | `956a749296df156c9961a09156c70bdd0261771b843edffc9e6cff2336cfa49b` |
| `code/s33-unresolved-managed.csv` | `f7b9db6aead97fcf99ec7ee5972be9b641335601389b009a165dc68369823c98` |
| `code/s33-unresolved-native.csv` | `350c9abd1a6fd1619bd9ca0475394f2ba157e75d70872a4f793e3e6845927cbf` |
| `code/s37-audit.md` | `d9bc427d71779f0d792f2bb4b415eb7af4c921f96cfe06a15f3f0727ca3e7174` |
| `code/s37-unresolved-managed.csv` | `f7b9db6aead97fcf99ec7ee5972be9b641335601389b009a165dc68369823c98` |
| `code/s37-unresolved-native.csv` | `350c9abd1a6fd1619bd9ca0475394f2ba157e75d70872a4f793e3e6845927cbf` |
| `code/s41-audit.md` | `c453fd37f022ffcece90a5185750e1aece51938043fa9df06e82c9f503bc92c1` |
| `code/s41-unresolved-managed.csv` | `f7b9db6aead97fcf99ec7ee5972be9b641335601389b009a165dc68369823c98` |
| `code/s41-unresolved-native.csv` | `350c9abd1a6fd1619bd9ca0475394f2ba157e75d70872a4f793e3e6845927cbf` |
| `code/s45-audit.md` | `55acb4581f896c584382841cec49292b585a2decdfd8263a6303ed09d47642ef` |
| `code/s45-injection.csv` | `8000a93c37c77e0c93cb42ab5802a20dbfa021940439e46c2022eda0e2ac3c65` |
| `code/s45-unresolved-managed.csv` | `f7b9db6aead97fcf99ec7ee5972be9b641335601389b009a165dc68369823c98` |
| `code/s45-unresolved-native.csv` | `350c9abd1a6fd1619bd9ca0475394f2ba157e75d70872a4f793e3e6845927cbf` |
| `code/s49-audit.md` | `366a820f543010e111dd7b724c44788a3387ccf1314d9d3e386cdd16d1acf050` |
| `code/s53-audit.md` | `96dbb09d85ccd1df8ca0f56f7d9be9049754d4137fe0865b7068a1fda1ff5bdb` |
| `code/s53-eh-sections.csv` | `bc7125945e8545a30a13c776568b26c9eff1eedf3d4d1bc573b1616b2210d87f` |
| `code/s57-audit.md` | `e7f2cc209074fff8627f483ceb1616757092095857d388bb9a1221f33cec9137` |
| `code/s57-branch-facts.csv` | `c0ad057e1cd4cb076fb7405e663586cff17a4f25c4538c17cea18ba3f1fc998b` |
| `code/s57-clauses.csv` | `4c1953084eeb379d57839bbd0e9acdf35669c4011e8e7a3d4ad164892ac824a7` |
| `code/s57-eh-sections.csv` | `5b962a10ff4d6cfc6ccfcecf25f370e3edce2215afc1337a78c6113978405308` |
| `code/s61-audit.md` | `81a68582ffe17875e49cfe957923ef9aef34207900246323d10d1d6afb5d7251` |
| `code/s61-branch-facts.csv` | `c0ad057e1cd4cb076fb7405e663586cff17a4f25c4538c17cea18ba3f1fc998b` |
| `code/s61-clauses.csv` | `4c1953084eeb379d57839bbd0e9acdf35669c4011e8e7a3d4ad164892ac824a7` |
| `code/s61-eh-sections.csv` | `5b962a10ff4d6cfc6ccfcecf25f370e3edce2215afc1337a78c6113978405308` |
| `code/s61-fixtures.csv` | `f865af7f8fb32d655cefda325e8deb5f991d344a9beaa3c201b092ee073aa96a` |
| `code/s65-audit.md` | `9322923329faca915a3b488c8ac12b780d1b597ecc24572538be4bbb37967a58` |
| `code/s65-calli.csv` | `cbd91760435b758bbdb3ba73c316cb076dd08d6d7246929975a29b26424d16bc` |
| `code/s65-catch-types.csv` | `b8e1ef498b79e1f013933c951230e61d2aa72d49f43a6b42071c2e8d6c8ea684` |
| `code/s65-eh-clauses.csv` | `927930a35c0b27caeb7acb7640d010e1a4fce4d395536b8df3d1e9a20db532d7` |
| `code/s65-eh-clauses.mutated.csv` | `2d434295ffe0aa7c87b759485938b0cf5515cecd86a8d49c7f5bb70d63b8ed29` |
| `code/s69-audit.md` | `10575d434cec773a17dcd3bb6c24206a03f172be3573f094d1b6604aadc8c6dd` |
| `code/s69-calli-sites.csv` | `7e84e184b3d030993620cb6aea1f9f10ea63188c272364ef384d8c0da2894cf1` |
| `code/s69-evidence.json` | `3a71a2f946423343b4321ffb4a0e8bcf69f528a10627e48bd3c732b72a0ca7e8` |
| `code/s69-method-access.csv` | `c2acb0eabb3864a715c4b25213ef5ab3c756e51719484ebf786a53b322682527` |
| `code/typedef-ranges.csv` | `e5b4e4399c140675ea5568f671aff867beec5427f6fc1dbe1f8c608db19399ff` |
| `code/types.cs` | `900e984b8c18ed6f8ba736d1065f578f479a78779c68d9e568cfb552e17c76f8` |
| `code/vtable-fixups.csv` | `7478ec22978224ab7a47ab8aabea87389ff6b9b5901a96442b5e2183ad9f4a44` |
| `coverage.csv` | `fd5d2d3946b876117fd59fe7a91829730fdd9a19e7ed58fd69d7dc941a7885a0` |
| `metrics.json` | `38e4b7b33554e6b7e7d46d61baa8ff6d5070ad78d035a16e428b80c0843ba512` |
| `native-functions.csv` | `737e83da0c37379bb178b5920445a239e6d0ed757f465bd9581f681ff3548ccd` |
| `run.json` | `e11c510de87f8d72df400739fbdee8b4a73c39361d876edfcb0ce11f05e66d7f` |
| `s1-started.md` | `778ed3b8ace013fe3a434a1c20971288291ddacd1d9719edc8a0a113a88ff4aa` |
| `s1-submission.md` | `408ba384ed174e3177955f0bda9a296e95730fcb650c62c4dcc2871eecd46028` |
| `s13-started.md` | `8909a02af61b668af46f7c526fa25b1d70518e4e195f1784439766eb9e81af88` |
| `s13-submission.md` | `785236b06a4b8a0b5e99b4c3813e7ce9a14656bb7fc72134df67a07cb923da7d` |
| `s17-started.md` | `4be869c1e53401aae36397f116ff14b64461fc92ec97b12e5344e69331f999b2` |
| `s17-submission.md` | `91c8cb823358166bd0862f9cbe3f0692220adb5c08f56dab080b10c4c948cf8c` |
| `s21-started.md` | `dc78b1dae1424fdb63892164019c7140284fce006f4443c5aae8190762dd2a93` |
| `s21-submission.md` | `bf576cc178e911c17257edb82bfa5ba4689f796a66332f2043f7e02016f5b1a2` |
| `s25-started.md` | `5e55ecf13c277aadb1329a1c6f45d8e62105cb3576465b645296c54ee9104b81` |
| `s25-submission.md` | `83a826e5705233ccba851d947957a101c0dce49c5b01f60f2dcb27468df2b35f` |
| `s29-started.md` | `7c4a15fba23d628beac0a68a8e2b0a32d656ad2bf362f390827eb903ffb6c3ae` |
| `s29-submission.md` | `5c1faaff36b734006ea981849a2367da058f73b224cf8f7caa7c029ca14846b4` |
| `s33-started.md` | `dadcd151951e85856caf3629709bda83bdfa336ad85d7013a6151a81ff7fdca3` |
| `s33-submission.md` | `82a7b40157112a9bf2a03ca3d5551acbbce26d7f686d4c9bca1222a33ad82e85` |
| `s37-started.md` | `30753a6dc2c74990809837548ece3b26e14f0b031dd5a163d9a3ae59d59d8ca2` |
| `s37-submission.md` | `19083308f218b858237be5a1eef8cb2ba3b8b08a8e15fbfe0e2fe7a58ff463b2` |
| `s41-started.md` | `f425f8bd8e3b7b826988eb09cd8238fe647b2c91005cc0add28c3ab256a996c4` |
| `s41-submission.md` | `cf6e16e47d5202303b38fa8835acb22897e00fd26840aea7b78373b17fdccf1e` |
| `s45-started.md` | `e95b591eb0ff745cf6e9eb1f84da0aa6e092db7e63483c0834087938ca9e39dd` |
| `s45-submission.md` | `c92fb1cbc3e0913046798250cf18335ee2882786a1ca90c03a55204f829ab934` |
| `s49-started.md` | `f84f2d15748cbc03790279404b98c1cd725d405391fc12bd25cd14cb8267123d` |
| `s49-submission.md` | `7721585d6a2d404652264a7e34c8bb7b6d2a5ef28169011be14260471bafd9f0` |
| `s5-started.md` | `a242870626800e1802aada7cb3b94fb801201c8ced1a92c2c2fa938308b3e873` |
| `s5-submission.md` | `7f7c55bd8ccd007ddd4b303f824741fcc360cb12374f41fdc42b8104bce9dc8d` |
| `s53-started.md` | `76da9804bfe3515dba10fab4febc4f6d9b2fee0034e8f4ae220908c25970f58a` |
| `s53-submission.md` | `277cf81ac7b14c2e8e83cc54de9071778e0dae1d5585e788d5acacded92a981d` |
| `s57-started.md` | `0acfad1033d506f7c6fc4102ddbee4ed293e620c65f7eff73294d743c5c3810f` |
| `s57-submission.md` | `dac555897298d1bded62343b31dabbc5044bc4a6ba7ca3dc95264812dffc3730` |
| `s61-started.md` | `a2f4d465bfff27931781059209c402a403d7a9f899cf148ead2c2878f514c0ac` |
| `s61-submission.md` | `6cd7810c0be53df1307d6c17feecc69f7e6758d009980bba7eb0aae0b9734ce4` |
| `s65-started.md` | `b557d20f06465283bd6682431795ec08a738a2ec550c09785f3f24c420bd1bb0` |
| `s65-submission.md` | `2b48caca74b3a24e9763861ca13a51a1495493a2815205054da83f2f4f1260e8` |
| `s69-started.md` | `099b797fdfc86216d4c9761e1a982ab9f7adf8e80750c14cf644526b072e8169` |
| `s69-submission.md` | `8050e5e142df500b50e8eadc2b1acc36bc188ed7bb5beae1525a383fe111b5f6` |
| `s9-started.md` | `c45ec3ac2a5a345d96cc7bd71e36ed837b1ddbdec1ee1b0316a5844bddd347ba` |
| `s9-submission.md` | `d828df979f3f9cf493af754f95481e2cb432fe61d7782a582d7f4860b45f61e1` |
