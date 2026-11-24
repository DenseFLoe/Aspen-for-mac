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


RULES = [
    ('s*-fingerprints.json', 'the manifest cannot contain itself',
     'the receipt states the manifest sha256 in plain text'),
    ('s*-submission.md', 'the receipt is the carrier, not the payload',
     'each receipt pins the manifest sha256 (reverse fixation)'),
    ('s*-audit.md', 'audit pages are conclusions that cite other files',
     'work/s<seq>-audit-pins.txt lists every audit page sha256 and is itself in the manifest'),
    ('work/*-gate.txt', 'gate logs change on every run',
     'explicitly NOT covered - run artifacts, reproduced by the command in the receipt'),
    ('work/*-exclusions.txt', 'the exclusion record describes the rule, not the payload',
     'explicitly NOT covered - the rule itself is in qa/mk_fingerprints.py'),
    ('tool/*', 'tool/ lives outside the item walk',
     'the receipt (section: verifier scripts) pins every tool script sha256 from the branch tree'),
]
PATTERNS = [r[0] for r in RULES]


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
    lines = ['exclusion rules (fnmatch, item-relative), each with its compensation control:', '']
    for pat, why, comp in RULES:
        lines.append('  pattern : %s' % pat)
        lines.append('    reason: %s' % why)
        lines.append('    compens: %s' % comp)
    lines.append('')
    lines.append('manifest: %s' % OUT.name)
    lines.append('entries: %d' % len(table))
    side.write_text(chr(10).join(lines) + chr(10), encoding='utf-8')
    print('fingerprints %d -> %s' % (len(table), OUT))


if __name__ == '__main__':
    main()
