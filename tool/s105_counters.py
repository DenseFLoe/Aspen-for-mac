# -*- coding: utf-8 -*-
"""s105 counterexamples, isolated: every case starts from a fresh copy of the same baseline.

Each case prints the sha256 of the file it mutates *before* and *after*, and all cases share
the same input_manifest_hash (the baseline tree hash), so only mutated_file/mutated_field differ.
"""
import hashlib, json, shutil, subprocess, sys, tempfile
from pathlib import Path

BASE = Path('handoff/inbox/NATIVE-337')
BIN = '_t13/orig/FindComponent.dll'


def tree_hash(root):
    h = hashlib.sha256()
    for p in sorted(Path(root).rglob('*')):
        if p.is_file():
            h.update(p.relative_to(root).as_posix().encode())
            h.update(b'\0')
            h.update(hashlib.sha256(p.read_bytes()).digest())
    return h.hexdigest()


def fresh(tag):
    d = Path(tempfile.mkdtemp(prefix='s105-%s-' % tag)) / 'cand'
    shutil.copytree(BASE, d, ignore=shutil.ignore_patterns('*.prev.csv', 'work', 's*-fingerprints.json'))
    return d


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def verify(folder):
    r = subprocess.run([sys.executable, '-B', 'tool/s101_verify.py', '--folder', str(folder),
                        '--binary', BIN, '--signature'], capture_output=True, text=True)
    return r.returncode, (r.stdout + r.stderr).strip()


def main():
    base = fresh('base')
    base_hash = tree_hash(base)
    print('baseline input_manifest_hash:', base_hash)
    hashes = []
    ok = True

    def case(title, mutate, expect_field, forbid=None):
        nonlocal ok
        d = fresh(title.replace(' ', '-'))
        hashes.append((title, tree_hash(d)))
        target, before = mutate(d)
        b_sha = sha(target)
        rc, txt = verify(d)
        a_sha = sha(target)
        hit = expect_field in txt and rc != 0
        bad = forbid and forbid in txt
        status = 'PASS' if (hit and not bad) else 'FAIL'
        print('%-18s rc=%d located=%s%s status=%s' % (
            title, rc, hit, '' if not bad else ' STALE(%s)' % forbid, status))
        print('   mutated_file=%s before_sha=%s' % (Path(target).relative_to(d).as_posix(), b_sha[:16]))
        print('   after_sha   =%s (unchanged by the run: %s)' % (a_sha[:16], b_sha == a_sha))
        for line in txt.splitlines():
            if line.startswith('CONFLICT'):
                print('   ', line)
        ok &= hit and not bad and (b_sha == a_sha)

    def reg_mutate(field, value):
        def _m(d):
            reg = d / 's97-registration.json'
            doc = json.loads(reg.read_text(encoding='utf-8'))
            doc['FindComponentDriver']['methods'][0][field] = value
            reg.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding='utf-8')
            return reg, value
        return _m

    def table_mutate(d):
        tbl = d / 'code' / 's81-showdialog.csv'
        t = tbl.read_text(encoding='utf-8').replace('id-sig-impl,registration,2001080E', 'id-sig-impl,registration,20010E0E')
        tbl.write_text(t, encoding='utf-8')
        return tbl, '20010E0E'

    case('name only', reg_mutate('name', 'ShowDialogX'), 'field=name')
    case('rva only', reg_mutate('rva', 'B000'), 'field=rva')
    case('table signature', table_mutate, 'field=signature', forbid='rva=B000')

    # missing attachment, also from a clean copy
    d = fresh('no-attachment')
    hashes.append(('missing attachment', tree_hash(d)))
    reg = d / 's97-registration.json'
    reg.unlink()
    rc, txt = verify(d)
    hit = 's97-registration.json' in txt and 'field=attachment' in txt and rc != 0
    print('%-18s rc=%d located=%s status=%s' % ('missing attachment', rc, hit, 'PASS' if hit else 'FAIL'))
    for line in txt.splitlines():
        if line.startswith('CONFLICT'):
            print('   ', line)
    ok &= hit

    same = len({h for _, h in hashes}) == 1
    print('input_manifest_hash identical across cases:', same)
    for title, h in hashes:
        print('  %-18s %s' % (title, h))
    ok &= same
    print('SUITE :', 'ALL PASS' if ok else 'FAILURES PRESENT')
    return 0 if ok else 1


if __name__ == '__main__':
    sys.exit(main())
