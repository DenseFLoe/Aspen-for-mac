"""Organize only Properties into two routes, two duplicate lists and one pending list.

Existing Plus classification is read only. Detailed inventories remain local;
every output path must be new. Duplicate identity is verified content SHA-256.
"""

import argparse
import collections
import csv
import hashlib
import json
from pathlib import Path

from audit_aspen_suffixes import load_rows
from inventory_aspen_sources import DIRECT, REVERSE, emit_json


PENDING = '03-undetermined'


def fingerprint(path):
    return dict(path=str(path.resolve()), sha256=hashlib.sha256(path.read_bytes()).hexdigest())


def order(row):
    return (row['extension'].lower(), int(row['priority']), row['relative_path'].casefold(),
            row['source'], row['container'], row['member'], row['record_id'])


def write_csv(path, rows, fields):
    with path.open('w', encoding='utf-8-sig', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields, extrasaction='ignore')
        writer.writeheader()
        writer.writerows(sorted(rows, key=order))


def reference(row):
    return {k: row.get(k, '') for k in ('record_id', 'owner', 'package', 'source', 'relative_path',
                                       'original_path', 'container', 'member', 'msi_file_id')}


def record_id(row):
    fields = ('owner', 'package', 'source', 'priority', 'relative_path', 'original_path',
              'container', 'member', 'msi_file_id', 'msi_component', 'sha256')
    identity = json.dumps([row.get(k, '') for k in fields], ensure_ascii=False).encode('utf-8')
    return 'record-' + hashlib.sha256(identity).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory', type=Path, required=True)
    parser.add_argument('--plus-baseline', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.output.exists():
        parser.error('output must be new; existing inventories and assets are preserved')
    input_files = [args.inventory / c / 'files.csv' for c in (REVERSE, DIRECT)]
    plus_files = [args.plus_baseline / c / n for c in (REVERSE, DIRECT)
                  for n in ('files.csv', 'primary-files.csv')]
    before = [fingerprint(p) for p in input_files + plus_files]
    raw = load_rows(args.inventory)
    # Exclude Plus-only source rows copied into earlier combined indexes.
    rows = [dict(r) for r in raw if 'Properties' in r['owner'].split(';')]
    plus = [dict(r) for r in load_rows(args.plus_baseline)
            if r['priority'] == '1' and r['read_status'] == 'ok' and r['sha256']]
    by_plus, by_properties = collections.defaultdict(list), collections.defaultdict(list)
    for r in plus:
        by_plus[r['sha256']].append(r)
    for r in rows:
        r['record_id'] = record_id(r)
        if r['read_status'] == 'ok' and r['sha256']:
            by_properties[r['sha256']].append(r)
    assert len({r['record_id'] for r in rows}) == len(rows), 'source identity must be unique'
    groups = {}
    for sha, matches in by_properties.items():
        plus_matches = by_plus.get(sha, [])
        if len(matches) > 1 or plus_matches:
            groups[sha] = dict(sha256=sha, properties=[reference(r) for r in matches],
                               plus=[reference(r) for r in plus_matches])

    for r in rows:
        original_category = r['category']
        reasons = []
        if r['review']:
            reasons.append(r['review'])
        if r['read_status'] != 'ok':
            reasons.append('内容读取受限：' + r['read_status'])
        if r.get('classification_review_required') == 'True' and not reasons:
            reasons.append('已有分类记录明确要求复核')
        if r.get('classification_status') == 'preliminary-rule-only' and not reasons:
            reasons.append('仅规则初分，未确认具体处理路线')
        if original_category not in (REVERSE, DIRECT):
            reasons.append('未取得有效的处理分类')
        r['input_category'] = original_category
        r['proposed_category'] = original_category if reasons else ''
        r['category'] = PENDING if reasons else original_category
        r['uncertainty_reason'] = '；'.join(dict.fromkeys(reasons))
        root = r.get('classification_evidence_root') or str(args.inventory.resolve())
        evidence = r.get('classification_evidence', '')
        if evidence and not Path(evidence).is_absolute():
            r['classification_evidence'] = str(Path(root) / evidence)
        eligible = r['read_status'] == 'ok' and bool(r['sha256'])
        own = by_properties.get(r['sha256'], []) if eligible else []
        other = by_plus.get(r['sha256'], []) if eligible else []
        kinds = []
        if other:
            kinds.append('与 Plus 重复')
        if len(own) > 1:
            kinds.append('Properties 不同来源重复')
        r['duplicate_type'] = '；'.join(kinds)
        r['properties_occurrences'] = len(own)
        r['plus_occurrences'] = len(other)
        r['duplicate_group'] = 'sha256:' + r['sha256'] if kinds else ''
        r['duplicate_evidence'] = 'duplicate-groups.json#/' + r['sha256'] if kinds else ''
        r['plus_example_path'] = other[0]['relative_path'] if other else ''
        alternatives = [x for x in own if x['record_id'] != r['record_id']]
        r['properties_other_example_path'] = alternatives[0]['relative_path'] if alternatives else ''
        r['target_resolution'] = 'symbolic-target-unresolved' if r['relative_path'].startswith('[TARGETDIR]/') else 'recorded-source-path'

    buckets = {c: [r for r in rows if r['category'] == c] for c in (REVERSE, DIRECT, PENDING)}
    duplicate_rows = {c: [r for r in buckets[c] if r['duplicate_type']] for c in (REVERSE, DIRECT)}
    ids = lambda records: {r['record_id'] for r in records}
    assert not ids(buckets[PENDING]) & (ids(buckets[REVERSE]) | ids(buckets[DIRECT]))
    assert sum(map(len, buckets.values())) == len(rows)
    assert all(ids(duplicate_rows[c]) <= ids(buckets[c]) for c in (REVERSE, DIRECT))
    assert [fingerprint(p) for p in input_files + plus_files] == before
    args.output.mkdir(parents=True)
    fields = list(dict.fromkeys(k for r in rows for k in r))
    for c in (REVERSE, DIRECT, PENDING):
        folder = args.output / c
        folder.mkdir()
        write_csv(folder / 'files.csv', buckets[c], fields)
        if c != PENDING:
            write_csv(folder / 'duplicates.csv', duplicate_rows[c], fields)
    emit_json(args.output / 'duplicate-groups.json', groups)
    emit_json(args.output / 'input-evidence.json', before)

    def statistics(items):
        return dict(rows=len(items), primary_rows=sum(r['priority'] == '1' for r in items),
                    backup_rows=sum(r['priority'] == '2' for r in items),
                    unique_readable_hashes=len({r['sha256'] for r in items if r['sha256'] and r['read_status'] == 'ok'}))

    summary = dict(scope='Properties source records only; Plus classification unchanged',
                   properties_source_rows=len(rows), excluded_plus_only_rows=len(raw) - len(rows),
                   categories={c: statistics(items) for c, items in buckets.items()},
                   duplicate_lists={c: dict(**statistics(items),
                       with_plus_rows=sum(bool(r['plus_occurrences']) for r in items),
                       within_properties_rows=sum(r['properties_occurrences'] > 1 for r in items))
                       for c, items in duplicate_rows.items()},
                   unreadable_pending_rows=sum(r['read_status'] != 'ok' for r in buckets[PENDING]),
                   unresolved_symbolic_primary_targets=sum(r['priority'] == '1' and r['target_resolution'] == 'symbolic-target-unresolved' for r in rows),
                   pending_duplicate_rows=sum(bool(r['duplicate_type']) for r in buckets[PENDING]),
                   plus_files_unchanged=True,
                   duplicate_rule='Verified content SHA-256 only; name similarity and symbolic target equality do not establish duplicates')
    emit_json(args.output / 'summary.json', summary)
    lines = ['# Aspen Properties 当前分类入口', '',
             '只整理 Properties 原始归属记录；Plus 原分类只读对照。以下共五份清单，旧版本继续保留。', '',
             '| 清单 | 来源记录 | 首选安装来源 | 文件 |', '| --- | ---: | ---: | --- |']
    for title, items, path in [
            ('需要逆向', buckets[REVERSE], REVERSE + '/files.csv'),
            ('不需要逆向', buckets[DIRECT], DIRECT + '/files.csv'),
            ('需要逆向中的重复项', duplicate_rows[REVERSE], REVERSE + '/duplicates.csv'),
            ('不需要逆向中的重复项', duplicate_rows[DIRECT], DIRECT + '/duplicates.csv'),
            ('尚未确定', buckets[PENDING], PENDING + '/files.csv')]:
        lines.append(f"| {title} | {len(items):,} | {sum(r['priority'] == '1' for r in items):,} | [{path}]({path}) |")
    lines += ['', '需要逆向、不需要逆向、尚未确定三组互不重叠，合计覆盖全部 Properties 来源记录。',
              '两份重复清单是前两组的附加子集，不再相加；duplicate_type 区分与 Plus 重复、Properties 自身不同来源重复，也可能两者同时成立。',
              '相同 SHA-256 才认定同内容重复；保留原文件名、来源、组件、版本和分析键。duplicate-groups.json 保存每组全部对应来源，CSV 中列出示例与组索引。',
              '首选安装器/载荷/内层成员 priority=1；已安装补充 priority=2。均按末级后缀排序。数量按来源行计，包含容器、内容和副本，不是去重文件数。',
              '尚未确定项保留 proposed_category 与具体 uncertainty_reason，未混入已确认的两类。重复但分类未定的内容留在尚未确定清单并附重复标记。',
              f"{summary['unresolved_symbolic_primary_targets']} 条首选安装目标仍为符号根；这是路径定位状态，与程序/数据处理路线分别记录，不据此将明确的代码类别改成未知。",
              '此分类是处理路线，不是反编译已完成/未完成验收。所有原版资料及详细清单仅本地保存。']
    (args.output / 'README.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
    assert [fingerprint(p) for p in input_files + plus_files] == before
    print(json.dumps(summary, ensure_ascii=False))


if __name__ == '__main__':
    main()
