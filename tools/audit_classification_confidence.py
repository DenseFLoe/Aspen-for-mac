"""Review new Properties contents while preserving the existing Plus baseline.

This does not revalidate all data formats. Preliminary routes stay preliminary,
and unreadable contents are always listed for review, independently of suffix.
"""

import argparse
import collections
import hashlib
import json
from pathlib import Path
import sys

from inventory_aspen_sources import REVERSE, emit_json
from inventory_plus_properties import save_rows, key
from audit_aspen_suffixes import SourceReader, load_rows, ole_inspect, write_csv


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory', type=Path, required=True)
    parser.add_argument('--plus-baseline', type=Path, required=True,
                        help='existing Plus classification; reused by hash, never reclassified')
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--sevenzip', type=Path, required=True)
    parser.add_argument('--module-dir', type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        parser.error('output must be a new path; previous evidence is preserved')
    args.output.mkdir(parents=True)
    sys.path.insert(0, str(args.module_dir.resolve()))
    import olefile

    rows = load_rows(args.inventory)
    plus = {r['sha256']: r for r in load_rows(args.plus_baseline)
            if r['priority'] == '1' and r['sha256'] and r['read_status'] == 'ok'}
    original = [(r['owner'], r['package'], r['source'], r['relative_path'], r['sha256']) for r in rows]
    reader = SourceReader(args.sevenzip)
    evidence = {}
    for r in rows:
        if (r['owner'] != 'Properties' or r['sha256'] in plus
                or not r['relative_path'].casefold().endswith('/vbaproject.bin')
                or not r['sha256'] or r['sha256'] in evidence):
            continue
        data = reader.read(r)
        assert hashlib.sha256(data).hexdigest() == r['sha256']
        detail = ole_inspect(data, olefile)
        if not detail['vba']:
            raise ValueError('VBA filename lacks expected OLE/VBA structure: ' + r['relative_path'])
        path = args.output / ('vba-' + r['sha256'] + '.json')
        emit_json(path, dict(source_record=r, sha256=r['sha256'], structure=detail,
                            finding='OLE/VBA storage confirmed; project contains VBA code, not an ordinary data blob'))
        evidence[r['sha256']] = str(path.resolve())

    corrected = reused = 0
    frozen_fields = ('category', 'format', 'reason', 'review', 'classification_status',
                     'classification_evidence', 'classification_remaining')
    frozen = [tuple(r.get(k, '') for k in frozen_fields) for r in rows if r['owner'] != 'Properties']
    for r in rows:
        r['confidence_audit_previous_category'] = r['category']
        r['confidence_audit_previous_status'] = r.get('classification_status', '')
        if r['owner'] != 'Properties':
            # Existing Plus and dual-owned installed records are an input baseline,
            # not new classification work. Report copies may resolve evidence links.
            r['classification_review_required'] = str(bool(r['review']) or r['read_status'] != 'ok')
            r['classification_evidence_root'] = str(args.inventory.resolve())
            continue
        if r.get('classification_evidence') and not Path(r['classification_evidence']).is_absolute():
            r['classification_evidence'] = str(args.inventory.resolve() / r['classification_evidence'])
        if r['sha256'] in plus and r['read_status'] == 'ok':
            inherited = plus[r['sha256']]
            for field in frozen_fields:
                r[field] = inherited.get(field, '')
            detail = inherited.get('classification_evidence')
            r['classification_evidence'] = (str(args.plus_baseline.resolve() / detail) if detail
                and not Path(detail).is_absolute() else detail or str(args.plus_baseline.resolve() / inherited['category'] / 'primary-files.csv'))
            r['classification_status'] = 'inherited-plus-classification'
            reused += 1
        elif r['sha256'] in evidence:
            corrected += r['category'] != REVERSE
            r.update(category=REVERSE, format='OLE-VBA-project', reason='完整 OLE 存储确认 VBA 项目，需恢复其中代码',
                     classification_status='structure-verified', classification_evidence=evidence[r['sha256']],
                     classification_remaining='尚未完成 VBA 代码恢复和行为验收', review='')
        elif r.get('classification_status') == 'baseline' and r['format'] == 'resource/data/document':
            r.update(classification_status='preliminary-rule-only',
                     reason='资源/数据/文档初步处理路线；尚未逐内容核验，可能含内嵌代码',
                     review='通用后缀/文件头规则初分，尚无该内容哈希的完整结构或角色核验；当前路线未经分类验收',
                     classification_remaining='需核对具体格式、内部成员和原版读取用途后再确认处理路线')
        if r['read_status'] != 'ok':
            r['review'] = (r['review'] + '；' if r['review'] else '') + '原内容不可读，SHA-256 不可用，保留读取限制'
        r['classification_review_required'] = str(bool(r['review']) or r['read_status'] != 'ok')

    assert original == [(r['owner'], r['package'], r['source'], r['relative_path'], r['sha256']) for r in rows]
    assert frozen == [tuple(r.get(k, '') for k in frozen_fields) for r in rows if r['owner'] != 'Properties']
    assert all(r['category'] == REVERSE for r in rows if r['sha256'] in evidence)
    save_rows(args.output, rows)
    fields = list(rows[0])
    pending = sorted([r for r in rows if r['classification_review_required'] == 'True'], key=key)
    write_csv(args.output / 'remaining-review.csv', pending, fields)
    write_csv(args.output / 'category-corrections.csv', [r for r in rows if r['category'] != r['confidence_audit_previous_category']], fields)
    by_owner = {}
    for owner in ('Properties',):
        part = [r for r in rows if r['owner'] == owner and r['priority'] == '1']
        by_owner[owner] = dict(primary_rows=len(part), preliminary_rule_only=sum(r['classification_status'] == 'preliminary-rule-only' for r in part),
                              needs_review=sum(r['classification_review_required'] == 'True' for r in part))
    summary = dict(input=str(args.inventory.resolve()), plus_baseline=str(args.plus_baseline.resolve()),
                   scope='Properties only; existing Plus classifications frozen; known Plus hashes inherited',
                   source_rows=len(rows), verified_vba_hashes=len(evidence), inherited_plus_rows=reused,
                   plus_classification_unchanged=True,
                   corrected_source_rows=corrected, pending_source_rows=len(pending), primary_by_owner=by_owner,
                   unreadable_source_rows=sum(r['read_status'] != 'ok' for r in rows),
                   status_counts=dict(collections.Counter(r['classification_status'] for r in rows)),
                   note='Rule-only means a provisional route requiring review, not proof that all such files contain code. No complete format audit was performed.')
    emit_json(args.output / 'confidence-audit.json', summary)
    print(json.dumps(summary, ensure_ascii=False))


if __name__ == '__main__':
    main()
