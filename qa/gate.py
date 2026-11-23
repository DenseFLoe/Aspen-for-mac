# -*- coding: utf-8 -*-
"""qa gate: run every detector and report inputs_checked / status per detector.

"defects=0 because nothing was checked" must never read as a pass:
  status = fail            when the detector reported hits
  status = not-applicable  when it had no input at all
  status = pass            when it had input and no hits
"""
import argparse, importlib.util, os, sys
from pathlib import Path

COUNT_KEYS = ('rows', 'sites', 'calls', 'receipts', 'files_scanned', 'instructions_checked',
              'documents_checked', 'numeric_keys', 'appendix_files', 'boundary_tables',
              'rows_checked', 'receipt_rows', 'declared_paths', 'fingerprint_files',
              'unresolved_rows', 'iat_symbols', 'iat_slots', 'census', 'declared_matched',
              'rows_declared', 'checked', 'files', 'slots')


def load(path):
    spec = importlib.util.spec_from_file_location('pf', path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


def inputs_of(stats):
    total = 0
    detail = {}
    for k, v in (stats or {}).items():
        if isinstance(v, int) and (k in COUNT_KEYS or k.endswith('_checked') or k.endswith('_files')):
            total += v
            detail[k] = v
    if total == 0 and stats and 'skipped' not in stats:
        # a detector that reports only descriptive stats still had *some* look; keep 0 honest
        total = 0
    return total, detail


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--task', default='NATIVE-337')
    ap.add_argument('--item-dir', default='handoff/inbox/NATIVE-337')
    ap.add_argument('--original', default='_t13/orig/FindComponent.dll')
    ap.add_argument('--tool', default='tool/preflight.py')
    a = ap.parse_args()
    if not Path(a.tool).exists():
        print('qa gate: %s not present (canonical copy lives on the QA branch)' % a.tool)
        return 2
    mod = load(a.tool)
    dets = getattr(mod, 'DETECTORS', [])
    if not dets:
        print('qa gate: %s exposes no DETECTORS' % a.tool)
        return 2
    rows = []
    worst = 0
    for fn in dets:
        try:
            hits, stats = fn(a.task, a.item_dir, a.original, {})
        except Exception as exc:
            print('%-28s ERROR %s' % (fn.__name__, exc))
            worst = 1
            continue
        n, detail = inputs_of(stats)
        status = 'fail' if hits else ('not-applicable' if n == 0 else 'pass')
        if status == 'fail':
            worst = 1
        rows.append((fn.__name__, n, status, len(hits), detail))
    print('%-30s %8s %-15s %7s' % ('detector', 'inputs', 'status', 'defects'))
    for name, n, status, nd, detail in rows:
        print('%-30s %8d %-15s %7d  %s' % (name[4:] if name.startswith('det_') else name, n, status, nd,
                                           '' if not detail else str(detail)[:70]))
    na = [r for r in rows if r[2] == 'not-applicable']
    print('summary: detectors=%d fail=%d not-applicable=%d pass=%d' % (
        len(rows), sum(1 for r in rows if r[2] == 'fail'), len(na),
        sum(1 for r in rows if r[2] == 'pass')))
    if na:
        print('WARNING: %d detector(s) had no input; their defects=0 is NOT a pass: %s'
              % (len(na), ', '.join(r[0] for r in na)))
    return worst


if __name__ == '__main__':
    sys.exit(main())
