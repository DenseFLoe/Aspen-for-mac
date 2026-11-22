# -*- coding: utf-8 -*-
"""s49 counterexample suite for the two-hop generator.

One command, four scenarios, prints per-scenario status and exits non-zero if any fails:
  A  no-prev      : no historical annex supplied -> still discovers 161 sites from the listing
  B  drop-row     : historical annex missing 0x106C -> site independently recovered
  C  boundary     : 0x12DA moved into the fragment starting at 0x12B6 -> candidate 0x12B6 / original 0x11E0
  D  replay       : empty dir, all inputs fingerprinted -> 161 rows + digest recorded
     (historical regression digest 72918f68..., s45 uppercase layout digest 2ef4b467...)
"""
import csv, hashlib, json, shutil, subprocess, sys
from pathlib import Path

CAND = Path('handoff/inbox/NATIVE-337')
BIN = Path('_t13/orig/FindComponent.dll')
WORK = Path('work')
HIST_SHA = '72918f68564e24dcb5e6f376bc04deacd0cc3ceece560198cfcba0a519d906bf'
UPPER_SHA = '2ef4b467155284f011c9fecd7c457c80cbfb9bff148b0acee7c4a60c5e8a20bf'


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def run(folder, out):
    cmd = [sys.executable, '-B', 'tool/s37_two_hop.py', '--folder', str(folder), '--binary', str(BIN), '--out', str(out)]
    r = subprocess.run(cmd, capture_output=True, text=True)
    return r.returncode, r.stdout.strip(), r.stderr.strip()


def prep(name, mutate_listing=False, drop_row=None, with_prev=True):
    d = WORK / ('s49-' + name)
    if d.exists():
        shutil.rmtree(d)
    (d / 'code').mkdir(parents=True)
    shutil.copy(BIN, d / 'FindComponent.dll')
    shutil.copy(CAND / 'calls.csv', d / 'calls.csv')
    shutil.copy(CAND / 'code' / 'native.asm', d / 'code' / 'native.asm')
    if with_prev:
        shutil.copy(CAND / 'code' / 's33-two-hop.csv', d / 'code' / 's33-two-hop.csv')
        if drop_row:
            rows = list(csv.DictReader(open(d / 'code' / 's33-two-hop.csv', encoding='utf-8')))
            rows = [r for r in rows if r['site'].upper() != drop_row.upper()]
            with open(d / 'code' / 's33-two-hop.csv', 'w', newline='', encoding='utf-8') as fh:
                w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
                w.writeheader(); w.writerows(rows)
    if mutate_listing:
        p = d / 'code' / 'native.asm'
        s = p.read_text(encoding='utf-8')
        s = s.replace('; FUNC 000012BD-0000130D', '; FUNC 000012B6-0000130D')
        s = s.replace('; FUNC 000012B6-000012BD', '; FUNC 000012A0-000012B6')
        p.write_text(s, encoding='utf-8')
    return d


def split_listing(d):
    """s53 verifier layout: move native.asm lines 199-226 into native-part.asm lines 19-46."""
    src = d / 'code' / 'native.asm'
    lines = src.read_text(encoding='utf-8').splitlines()
    block = lines[198:226]                       # 1-based 199-226
    lines[198:226] = ['; moved to native-part.asm'] * len(block)
    src.write_text('\n'.join(lines) + '\n', encoding='utf-8')
    part = d / 'code' / 'native-part.asm'
    part.write_text('\n'.join(['; split listing part (verifier layout)'] * 18 + block) + '\n', encoding='utf-8')
    # rewrite calls.csv references into the moved block: file -> native-part.asm, line -= 180
    rows = list(csv.DictReader(open(d / 'calls.csv', encoding='utf-8')))
    for r in rows:
        ref = r['listing']
        if '#L' not in ref:
            continue
        fpart, lpart = ref.split('#L', 1)
        if not fpart.endswith('native.asm'):
            continue
        first, _, last = lpart.partition('-L')
        if 199 <= int(first) <= 226:
            r['listing'] = 'code/native-part.asm#L%d-L%d' % (int(first) - 180, int(last) - 180 if last else int(first) - 180)
    with open(d / 'calls.csv', 'w', newline='', encoding='utf-8') as fh:
        w = csv.DictWriter(fh, fieldnames=['kind', 'caller', 'callee', 'class', 'listing', 'note'])
        w.writeheader(); w.writerows(rows)


def main():
    ok = True
    # A: no historical annex at all
    d = prep('no-prev', with_prev=False)
    rc, out, err = run(d, d / 'out.csv')
    rows = list(csv.DictReader(open(d / 'out.csv', encoding='utf-8')))
    a_ok = rc == 0 and len(rows) == 161
    ok &= a_ok
    print('A no-prev      : rc=%d rows=%d status=%s' % (rc, len(rows), 'PASS' if a_ok else 'FAIL'))

    # B: drop one row from the historical annex
    d = prep('drop', drop_row='0x106c')
    rc, out, err = run(d, d / 'out.csv')
    rows = list(csv.DictReader(open(d / 'out.csv', encoding='utf-8')))
    sites = {r['site'].upper() for r in rows}
    b_ok = rc == 0 and len(rows) == 161 and '0X106C' in sites
    ok &= b_ok
    print('B drop-row     : rc=%d rows=%d recovered_0x106C=%s status=%s' % (rc, len(rows), '0X106C' in sites, 'PASS' if b_ok else 'FAIL'))

    # C: move 0x12DA into the fragment starting at 0x12B6
    d = prep('control', mutate_listing=True)
    rc, out, err = run(d, d / 'out.csv')
    by = {r['site'].upper(): r for r in csv.DictReader(open(d / 'out.csv', encoding='utf-8'))}
    r12 = by.get('0X12DA', {})
    c_ok = rc == 0 and r12.get('candidate_owner', '').upper() == '0X12B6' and r12.get('original_host', '').upper() == '0X11E0'
    ok &= c_ok
    print('C boundary     : rc=%d candidate_owner=%s original_host=%s status=%s' % (
        rc, r12.get('candidate_owner'), r12.get('original_host'), 'PASS' if c_ok else 'FAIL'))

    # D: empty-directory replay with all inputs fingerprinted
    d = prep('replay')
    inputs = {str(p.relative_to(d)): sha(p) for p in sorted(d.rglob('*')) if p.is_file()}
    rc, out, err = run(d, d / 'out' / 's37-two-hop.csv')
    out_p = d / 'out' / 's37-two-hop.csv'
    n = len(list(csv.DictReader(open(out_p, encoding='utf-8'))))
    digest = sha(out_p)
    d_ok = rc == 0 and n == 161 and digest in (HIST_SHA, UPPER_SHA)
    ok &= d_ok
    print('D replay       : rc=%d rows=%d sha256=%s status=%s' % (rc, n, digest, 'PASS' if d_ok else 'FAIL'))
    print('  baselines    : historical(72918f68) match=%s ; s45-uppercase(2ef4b467) match=%s' % (
        digest == HIST_SHA, digest == UPPER_SHA))
    # E: two layouts must agree on the two specific associations (s53 verifier notes)
    d1 = prep('layout-single', with_prev=False)
    rc1, _, _ = run(d1, d1 / 'out.csv')
    d2 = prep('layout-split', with_prev=False)
    split_listing(d2)
    rc2, _, _ = run(d2, d2 / 'out2.csv')
    def assoc(path):
        rows = list(csv.DictReader(open(path, encoding='utf-8')))
        got = {}
        for r in rows:
            if r['site'].upper() in ('0X106C', '0X12DA'):
                got[r['site'].upper()] = (r['asm'], r['calls_row'])
        return len(rows), got
    n1, g1 = assoc(d1 / 'out.csv')
    n2, g2 = assoc(d2 / 'out2.csv')
    e_ok = (rc1 == 0 and rc2 == 0 and n1 == 161 and n2 == 161
            and g1.get('0X106C', ('', ''))[1] == '525' and g1.get('0X12DA', ('', ''))[1] == '528'
            and g2.get('0X106C', ('', ''))[1] == '525' and g2.get('0X12DA', ('', ''))[1] == '528')
    ok &= e_ok
    print('E two-layout   : rc=%d/%d rows=%d/%d  0x106C=%s/525 0x12DA=%s/528 status=%s' % (
        rc1, rc2, n1, n2, g1.get('0X106C', ('', ''))[1], g1.get('0X12DA', ('', ''))[1],
        'PASS' if e_ok else 'FAIL'))
    (WORK / 's49-inputs.json').write_text(json.dumps(inputs, ensure_ascii=False, indent=1), encoding='utf-8')
    print('TOOLS          : generator=%s pe_reader=%s tests=%s' % (
        sha('tool/s37_two_hop.py'), sha('tool/pe_reader.py'), sha('tool/s45_tests.py')))
    print('SUITE          :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
