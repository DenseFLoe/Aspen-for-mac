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


def main():
    table = {}
    for p in sorted(ITEM.rglob('*')):
        if not p.is_file() or p.name in SKIP:
            continue
        rel = p.relative_to(ITEM).as_posix()
        if rel.startswith('work/') and not rel.split('/')[-1].endswith('.txt'):
            continue
        table[rel] = sha(p)
    OUT.write_text(json.dumps(table, ensure_ascii=False, indent=1, sort_keys=True) + '\n', encoding='utf-8')
    print('fingerprints %d -> %s' % (len(table), OUT))


if __name__ == '__main__':
    main()
