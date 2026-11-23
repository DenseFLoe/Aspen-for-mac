# -*- coding: utf-8 -*-
"""s69 falsifiable tests: exact symbol identity + missing-station behaviour."""
import csv, hashlib, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')
REF = BASE / 'code' / 's37-two-hop.csv'
CHECKER = Path('handoff/assignments/check-native-coverage.py')


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(cmd):
    r = subprocess.run(cmd, capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def copy(name):
    d = Path(tempfile.mkdtemp(prefix='s69-')) / name
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work'))
    return d


def rows_of(d):
    return list(csv.DictReader(open(d / 'calls.csv', encoding='utf-8')))


def write_rows(d, rows):
    with open(d / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(rows)


def classify(d):
    out = d / 's69.csv'
    rc, txt = run([sys.executable, '-B', 'tool/s65_counterexamples.py', '--folder', str(d),
                   '--binary', str(BIN), '--reference', str(REF), '--out', str(out)])
    rows = list(csv.DictReader(open(out, encoding='utf-8'))) if out.exists() else []
    from collections import Counter
    return rc, txt, rows, Counter(r['category'] for r in rows)


def main():
    ok = True
    # T1: only the declaration of 0x106C changes #2344 -> #23440
    d = copy('t1')
    rows = rows_of(d)
    hit = next(r for r in rows if r['listing'].startswith('code/native.asm#L28-'))
    hit['callee'] = 'mfc140.dll!#23440'
    write_rows(d, rows)
    rc, txt, res, cats = classify(d)
    contradicts = [r for r in res if r['category'] == 'contradiction']
    t1 = rc == 0 and len(contradicts) == 1 and contradicts[0]['site'].upper() == '0X106C'
    print('T1 prefix-ordinal : contradiction=%d site=%s status=%s' % (
        len(contradicts), contradicts[0]['site'] if contradicts else '-', 'PASS' if t1 else 'FAIL'))
    ok &= t1

    # T2: remove only the listing instruction of 0x106C
    d2 = copy('t2')
    p = d2 / 'code' / 'native.asm'
    lines = p.read_text(encoding='utf-8').splitlines()
    idx = next(i for i, ln in enumerate(lines) if ln.startswith('0000106C'))
    lines[idx] = '; moved-out-for-test 0000106C'
    p.write_text('\n'.join(lines) + '\n', encoding='utf-8')
    rc2, txt2, res2, cats2 = classify(d2)
    miss = [r for r in res2 if r['category'] == 'missing-listing' and r['site'].upper() == '0X106C']
    cov_rc, cov_txt = run([sys.executable, '-B', str(CHECKER), 'NATIVE-337', '--original', str(BIN),
                           '--submission', str(d2)])
    t2 = rc2 == 0 and len(miss) == 1
    t3 = cov_rc == 1
    print('T2 drop-instruction: missing-listing=%d site=%s status=%s' % (
        len(miss), '0x106C' if miss else '-', 'PASS' if t2 else 'FAIL'))
    print('T3 coverage refuse : exit=%d msg=%r status=%s' % (cov_rc, cov_txt.splitlines()[-1][:80], 'PASS' if t3 else 'FAIL'))
    ok &= t2 and t3
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
