# -*- coding: utf-8 -*-
"""Emit the delivery fingerprint table the gate can actually read.

Writes handoff/inbox/NATIVE-337/s<seq>-fingerprints.json = {"path": "sha256"} for every
delivered artifact (calls/coverage/native-functions/metrics/run + code/*), so detectors
that look for a *fingerprint*.json stop running on an empty input set.
"""
import hashlib, json, sys
from pathlib import Path

ITEM = Path('handoff/inbox/NATIVE-337')
OUT = ITEM / ('s%s-fingerprints.json' % (sys.argv[1] if len(sys.argv) > 1 else '85'))
SKIP = {'s85-fingerprints.json'}


def sha(p):
    return hashlib.sha256(p.read_bytes()).hexdigest()


PATTERNS = ['s*-fingerprints.json', 's*-submission.md', 'work/*-gate.txt',
            'work/*-exclusions.txt', 'tool/*', 's*-audit.md']  # receipts/manifests/logs and the tool tree never join the table


def main():
    seq = sys.argv[1] if len(sys.argv) > 1 else '85'
    skip_receipt = 's%s-submission.md' % seq
    skip_manifest = 's%s-fingerprints.json' % seq
    table = {}
    for p in sorted(ITEM.rglob('*')):
        rel0 = p.relative_to(ITEM).as_posix()
        if not p.is_file() or p.name in SKIP:
            continue
        import fnmatch
        if any(fnmatch.fnmatch(rel0, pat) for pat in PATTERNS):
            continue
        rel = p.relative_to(ITEM).as_posix()
        if rel.startswith('work/') and rel.endswith('-gate.txt'):
            continue  # gate logs change on every run; excluded so the table stays stable
        if rel.startswith('work/') and not rel.split('/')[-1].endswith('.txt'):
            continue
        table[rel] = sha(p)
    OUT.write_text(json.dumps(table, ensure_ascii=False, indent=1, sort_keys=True) + '\n', encoding='utf-8')
    side = ITEM / 'work' / ('s%s-exclusions.txt' % (sys.argv[1] if len(sys.argv) > 1 else '85'))
    side.parent.mkdir(parents=True, exist_ok=True)
    side.write_text('exclusion patterns (fnmatch, applied to item-relative paths):\n' +
                    '\n'.join('  ' + x for x in PATTERNS) + '\n\nmanifest: %s\nentries: %d\n' % (OUT.name, len(table)),
                    encoding='utf-8')
    print('fingerprints %d -> %s' % (len(table), OUT))


if __name__ == '__main__':
    main()
