# -*- coding: utf-8 -*-
"""s105 counterexamples: each recomputes the active manifest, then must still be located."""
import json, subprocess, sys
from pathlib import Path

ITEM = Path('handoff/inbox/NATIVE-337')
BIN = '_t13/orig/FindComponent.dll'


def run(args):
    r = subprocess.run([sys.executable, '-B', 'tool/s101_verify.py'] + args, capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def manifest():
    subprocess.run([sys.executable, '-B', 'qa/mk_fingerprints.py', '105'], check=True, capture_output=True)
    return True


def case(title, mutate, expect):
    manifest()
    rc, txt = run(['--folder', str(ITEM), '--binary', BIN, '--signature'])
    mutate()
    manifest()
    rc2, txt2 = run(['--folder', str(ITEM), '--binary', BIN, '--signature'])
    hit = expect in txt2 and rc2 != 0
    print('%-28s rc=%d located=%s status=%s' % (title, rc2, hit, 'PASS' if hit else 'FAIL'))
    for line in txt2.splitlines():
        if line.startswith('CONFLICT'):
            print('   ', line)
    return hit


def main():
    reg = ITEM / 's97-registration.json'
    orig = reg.read_bytes()
    ok = True

    def mutate(path_field, value):
        def _m():
            doc = json.loads(orig.decode('utf-8'))
            doc['FindComponentDriver']['methods'][0][path_field] = value
            reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
        return _m

    try:
        ok &= case('name only', mutate('name', 'ShowDialogX'), 'field=name')
        ok &= case('rva only', mutate('rva', 'B000'), 'field=rva')
        tbl = ITEM / 'code' / 's81-showdialog.csv'
        torig = tbl.read_bytes()

        def mutate_table():
            t = torig.decode('utf-8').replace('id-sig-impl,registration,2001080E', 'id-sig-impl,registration,20010E0E')
            tbl.write_text(t, encoding='utf-8')

        ok &= case('table signature', mutate_table, 'field=signature')
    finally:
        reg.write_bytes(orig)
        if (ITEM / 'code' / 's81-showdialog.csv').exists():
            (ITEM / 'code' / 's81-showdialog.csv').write_bytes(torig)
    manifest()

    # missing attachment
    reg.rename(reg.with_suffix('.bak'))
    manifest()
    rc, txt = run(['--folder', str(ITEM), '--binary', BIN, '--signature'])
    hit = ('s97-registration.json' in txt) and ('field=attachment' in txt) and rc != 0
    print('%-28s rc=%d located=%s status=%s' % ('missing attachment', rc, hit, 'PASS' if hit else 'FAIL'))
    for line in txt.splitlines():
        if line.startswith('CONFLICT'):
            print('   ', line)
    reg.with_suffix('.bak').rename(reg)
    manifest()
    ok &= hit
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
