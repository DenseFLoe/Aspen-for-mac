# -*- coding: utf-8 -*-
"""Write s41 receipts (generator manifest, dependency list, repro command, fingerprints)."""
import hashlib, json, sys
from pathlib import Path

FOLDER = Path('handoff/inbox/NATIVE-337')
GEN = ['tool/s37_two_hop.py', 'tool/pe_reader.py']


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def main():
    cov = Path('work/s41_cov.txt').read_text(encoding='utf-8').strip()
    chk = Path('work/s41_chk33.txt').read_text(encoding='utf-8').strip()
    repro = Path('work/s41_repro.txt').read_text(encoding='utf-8').strip()
    metrics = json.loads((FOLDER / 'metrics.json').read_text(encoding='utf-8'))
    started = '''---
task_id: NATIVE-337
type: started
state: planning
seq: 41
at: 2026-11-23T04:55:00+08:00
---
s41：交付 161 条二跳附表的生成器（tool/s37_two_hop.py + tool/pe_reader.py），记录依赖、命令、输出路径与指纹，并在空目录复跑到固定摘要。
'''
    (FOLDER / 's41-started.md').write_text(started, encoding='utf-8')
    lines = ['# NATIVE-337 s41 提交', '',
             '## 生成器清单与指纹', '',
             '| 文件 | SHA-256 | 作用 |', '| --- | --- | --- |',
             '| tool/s37_two_hop.py | %s | 从原件重算 161 条二跳（首跳/IAT/符号/calls_row） |' % sha(GEN[0]),
             '| tool/pe_reader.py | %s | PE 段表、导入目录（IAT 槽→DLL!符号）、汇编清单解析 |' % sha(GEN[1]),
             '',
             '依赖：Python 3.13.5，仅标准库（argparse/csv/struct/sys/pathlib/re/json）——无 capstone/pefile。',
             '',
             '## 复跑命令与输出路径', '',
             '~~~sh',
             'mkdir -p repro/code && cp <原件>/FindComponent.dll repro/ \\',
             '  && cp <候选>/calls.csv repro/ \\',
             '  && cp <候选>/code/native.asm repro/code/ \\',
             '  && cp <候选>/code/s33-two-hop.csv repro/code/',
             'python -B tool/s37_two_hop.py --folder repro \\',
             '  --binary repro/FindComponent.dll \\',
             '  --prev repro/code/s33-two-hop.csv \\',
             '  --out repro/out/s37-two-hop.csv',
             '~~~',
             '',
             '输出：repro/out/s37-two-hop.csv（161 行）。',
             '',
             '## 空目录复跑结果', '',
             '~~~', repro, '~~~', '',
             '## 判定（原始输出）', '',
             'check-s33.py exit 0：', '~~~', chk[:1500], '~~~', '',
             'check-native-coverage.py exit 2：', '~~~', cov, '~~~', '',
             '## 机器指标（calls.csv 现算）', '',
             '- calls 684 = external %d + data %d + unresolved %d' % (metrics['external'], metrics['data'], metrics['unresolved']),
             '- direct_iat %d、indirect_annex %d 单列' % (metrics['direct_iat'], metrics['indirect_annex']),
             '- two_hop %d、com %d、dispatch %d' % (metrics['two_hop_rows'], metrics['com_rows'], metrics['dispatch_rows']),
             '- 指纹 calls %s / coverage %s / two-hop %s' % (metrics.get('calls_sha256', '')[:16], metrics.get('coverage_sha256', '')[:16],
                                                              sha(FOLDER / 'code' / 's37-two-hop.csv')[:16]),
             ]
    (FOLDER / 's41-submission.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print('wrote s41 receipts; generator sha', sha(GEN[0])[:16], 'two-hop sha', sha(FOLDER / 'code' / 's37-two-hop.csv')[:16])


if __name__ == '__main__':
    main()
