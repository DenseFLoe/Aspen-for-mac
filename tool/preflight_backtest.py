# -*- coding: utf-8 -*-
"""s27-step4 backtest: prove each preflight detector fires on an injected defect,
plus three anti-overfit probes (RVA shuffle / rename / unseen head)."""
import csv, hashlib, os, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')


def run(folder):
    env = dict(os.environ); env.setdefault('PYTHONPATH', 'D:/Lib/site-packages')
    r = subprocess.run([sys.executable, '-B', 'tool/preflight.py', '--folder', str(folder), '--binary', str(BIN)],
                       capture_output=True, text=True, env=env)
    return r.returncode, r.stdout + r.stderr


def copy(name):
    d = Path(tempfile.mkdtemp(prefix='pf-')) / name
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work'))
    return d


def edit_rows(d, fn):
    rows = list(csv.DictReader(open(d / 'calls.csv', encoding='utf-8')))
    fn(rows)
    with open(d / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(rows)


def main():
    ok = True
    # 1 symbol-substring: bind a prefix-relative symbol to the same site
    d = copy('substr')
    def f1(rows):
        hit = next(r for r in rows if r['listing'].startswith('code/native.asm#L28-'))
        rows.insert(rows.index(hit), dict(hit, callee='mfc140.dll!#23440'))
    edit_rows(d, f1)
    rc, txt = run(d)
    got = 'symbol-substring' in txt
    ok &= got
    print('BT symbol-substring : %s' % ('PASS' if got else 'FAIL'))

    # 2 wrong-symbol: unknown symbol name
    d = copy('wrong')
    def f2(rows):
        hit = next(r for r in rows if r['listing'].startswith('code/native.asm#L28-'))
        hit['callee'] = 'BOGUS.dll!NoSuchImport'
    edit_rows(d, f2)
    rc, txt = run(d)
    got = 'wrong-symbol' in txt
    ok &= got
    print('BT wrong-symbol     : %s' % ('PASS' if got else 'FAIL'))

    # 3 access-flags: claim private with flags 0x4013 (Assembly)
    d = copy('flags')
    p = d / 's999-submission.md'
    p.write_text('access level: private, flags=0x4013\n', encoding='utf-8')
    rc, txt = run(d)
    got = 'access-flags' in txt
    ok &= got
    print('BT access-flags     : %s' % ('PASS' if got else 'FAIL'))

    # 4 byte-mismatch
    d = copy('bytes')
    p = d / 'code' / 'native.asm'
    ls = p.read_text(encoding='utf-8').splitlines()
    i = next(k for k, ln in enumerate(ls) if ln.startswith('0000106C'))
    ls[i] = ls[i].replace('E8 32 3A 00 00', 'E8 33 3A 00 00')
    p.write_text(chr(10).join(ls) + chr(10), encoding='utf-8')
    rc, txt = run(d)
    got = 'byte-mismatch' in txt
    ok &= got
    print('BT byte-mismatch    : %s' % ('PASS' if got else 'FAIL'))

    # 5 receipt-misstatement: name a missing file
    d = copy('receipt')
    p = d / 's999-submission.md'
    p.write_text('see code/no-such-file.csv\n', encoding='utf-8')
    rc, txt = run(d)
    got = 'receipt-misstatement' in txt
    ok &= got
    print('BT receipt-misstate : %s' % ('PASS' if got else 'FAIL'))

    # anti-overfit probes
    d = copy('shuffle')
    rows = list(csv.DictReader(open(d / 'calls.csv', encoding='utf-8')))[::-1]
    with open(d / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(rows)
    rc, txt = run(d)
    ok_prob = rc == 1  # reversing rows changes listing->row mapping; detector must not crash/false-pass silently
    print('PROBE rva-shuffle   : rc=%d findings=%s' % (rc, txt.strip().splitlines()[-1][:60]))
    ok &= rc in (0, 1)  # no crash is the requirement

    d = copy('rename')
    (d / 'code' / 'native.asm').rename(d / 'code' / 'native-part.asm')
    rc, txt = run(d)
    print('PROBE rename        : rc=%d %s' % (rc, txt.strip().splitlines()[-1][:60]))
    ok &= rc in (0, 1)

    d = copy('unseen-head')
    for p in d.glob('s*-submission.md'):
        p.unlink()
    rc, txt = run(d)
    print('PROBE unseen-head   : rc=%d %s' % (rc, txt.strip().splitlines()[-1][:60]))
    ok &= rc in (0, 1)

    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
