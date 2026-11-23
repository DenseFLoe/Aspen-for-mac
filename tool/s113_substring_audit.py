# -*- coding: utf-8 -*-
"""s113 audit: identifier comparisons must never be substring comparisons.

Two layers:
  1. behaviour: constructed samples (A848/A8480, #2344/#23440, 2001080E/2001080E0) must be judged
     DIFFERENT by tool/ident.same_ident, and identical values must be judged SAME;
  2. statics: scan tool/*.py for substring comparisons applied to identifier-ish operands and
     fail unless the file is on the annotated allowlist below.
"""
import re, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import ident

PAIRS_DIFFERENT = [('A848', 'A8480'), ('0xA848', '0xA8480'), ('#2344', '#23440'),
                   ('2001080E', '2001080E0'), ('0x106C', '0x106C0'), ('mfc140.dll!#2344', 'mfc140.dll!#23440')]
PAIRS_SAME = [('A848', 'a848'), ('0xA848', 'A848'), ('#2344', '#2344'), ('2001080E', '2001080e')]

# intentional prefix semantics, each with the reason it is correct
ALLOW = {
    'det_symbol_substring.py': 'this file EXISTS to report prefix-relative symbols; prefix compare is the check',
    'det_wrong_symbol.py': 're.match(^0x) only decides whether a value is a plain RVA literal, not identity',
    'ident.py': 'defines the whole-value comparison helpers',
}
PATTERN = re.compile(r"(?:startswith|endswith)\(\s*[^)]*(?:rva|token|sym|callee|ordinal|disp|slot)", re.I)


def behaviour():
    bad = 0
    for a, b in PAIRS_DIFFERENT:
        if ident.same_ident(a, b):
            print('SAMPLE-CONFLATED %r == %r' % (a, b))
            bad += 1
    for a, b in PAIRS_SAME:
        if not ident.same_ident(a, b):
            print('SAMPLE-FALSE-NEGATIVE %r != %r' % (a, b))
            bad += 1
    print('behaviour: pairs=%d conflations=%d' % (len(PAIRS_DIFFERENT) + len(PAIRS_SAME), bad))
    return bad


def statics():
    bad = 0
    for p in sorted(Path('tool').glob('*.py')):
        if p.name in ALLOW:
            continue
        for i, line in enumerate(p.read_text(encoding='utf-8', errors='replace').splitlines(), 1):
            if line.lstrip().startswith('#'):
                continue
            if PATTERN.search(line):
                print('STATIC-HIT %s:%d %s' % (p.name, i, line.strip()[:90]))
                bad += 1
    print('statics: allowlisted=%d hits=%d' % (len(ALLOW), bad))
    return bad


def main():
    bad = behaviour() + statics()
    print('SUITE :', 'PASS' if not bad else 'FAIL (exit 1)')
    return 0 if not bad else 1


if __name__ == '__main__':
    sys.exit(main())
