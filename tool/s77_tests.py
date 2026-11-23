# -*- coding: utf-8 -*-
"""s77: paired experiment for the missing-station input.

Both runs use the same candidate listing with the 0x106C instruction removed:
  run 1: full cached station table present (must match the fresh derivation)
  run 2: the cached table has that station's row deleted and the delivery fingerprint recomputed
Both must keep reporting 0x106C (or refuse an invalid baseline) — never silently pass.
"""
import csv, hashlib, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')
ENV = {'PYTHONPATH': 'D:/Lib/site-packages'}


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def prep():
    d = Path(tempfile.mkdtemp(prefix='s77-')) / 'cand'
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work'))
    p = d / 'code' / 'native.asm'
    lines = p.read_text(encoding='utf-8').splitlines()
    i = next(k for k, ln in enumerate(lines) if ln.startswith('0000106C'))
    lines[i] = '; dropped 0000106C'
    p.write_text(chr(10).join(lines) + chr(10), encoding='utf-8')
    return d


def classify(d, out, stations_arg):
    cmd = [sys.executable, '-B', 'tool/s65_counterexamples.py', '--folder', str(d), '--binary', str(BIN), '--out', str(out)]
    if stations_arg:
        cmd += ['--stations', str(stations_arg)]
    r = subprocess.run(cmd, capture_output=True, text=True, env={**__import__('os').environ, **ENV})
    rows = list(csv.DictReader(open(out, encoding='utf-8'))) if out.exists() else []
    miss = [x for x in rows if x['category'] == 'missing-listing' and x['site'].upper() == '0X106C']
    return r.returncode, r.stdout.strip(), r.stderr.strip(), len(miss)


def main():
    d = prep()
    ok = True
    # run 1: full table
    rc1, out1, err1, miss1 = classify(d, d / 'r1.csv', d / 'code' / 's73-stations.csv')
    t1 = rc1 == 0 and miss1 == 1
    print('PAIR-1 full-table   : rc=%d missing_0x106C=%d status=%s' % (rc1, miss1, 'PASS' if t1 else 'FAIL'))
    ok &= t1
    # run 2: table with that row deleted, fingerprints recomputed on the new bytes
    t = d / 'code' / 's73-stations.csv'
    rows = [r for r in csv.DictReader(open(t, encoding='utf-8')) if r['site'].upper() != '0X106C']
    with open(t, 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader(); w.writerows(rows)
    fp = sha(t)
    (d / 'work').mkdir(exist_ok=True)
    (d / 'work' / 's73-tools.txt').write_text('code/s73-stations.csv %s\n' % fp, encoding='utf-8')
    rc2, out2, err2, miss2 = classify(d, d / 'r2.csv', t)
    # the cached table no longer matches the fresh derivation -> must refuse, or still report the station
    refused = rc2 != 0 and 'cached station table does not match' in (out2 + err2)
    t2 = refused or (rc2 == 0 and miss2 == 1)
    print('PAIR-2 drop-row     : rc=%d missing_0x106C=%d refused=%s status=%s' % (rc2, miss2, refused, 'PASS' if t2 else 'FAIL'))
    ok &= t2
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
