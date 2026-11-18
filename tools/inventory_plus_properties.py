"""Build local Plus/Properties inventories and three consistent classification lists.

Original inputs are read only. Every invocation requires a new output directory.
MSI target paths establish installed ownership; SHA-256 establishes byte identity.
"""

import argparse
import collections
import concurrent.futures
import csv
import datetime
import hashlib
import json
from pathlib import Path
import zipfile

from inventory_aspen_sources import (DIRECT, REVERSE, digest_stream, emit_json,
                                    physical_file, record, walk)
from audit_aspen_suffixes import load_rows, write_csv


def key(row):
    return (row['category'], row['extension'], int(row['priority']),
            row['source'], row['relative_path'].casefold(), row.get('owner', ''))


def save_rows(root, rows):
    rows = sorted(rows, key=key)
    fields = list(dict.fromkeys(k for r in rows for k in r if not k.startswith('_')))
    for category in (REVERSE, DIRECT):
        folder = root / category
        folder.mkdir()
        part = [r for r in rows if r['category'] == category]
        write_csv(folder / 'files.csv', part, fields)
        for name, priority in [('primary-files.csv', '1'), ('backup-files.csv', '2'), ('surrounding-media.csv', '3')]:
            write_csv(folder / name, [r for r in part if str(r['priority']) == priority], fields)


def fingerprint(path):
    return dict(path=str(path.resolve()), sha256=hashlib.sha256(path.read_bytes()).hexdigest())


def target_path(relative):
    roots = {
        '[ProgramFiles64Folder]': 'C:/Program Files',
        '[ProgramFilesFolder]': 'C:/Program Files (x86)',
        '[CommonFiles64Folder]': 'C:/Program Files/Common Files',
        '[CommonFilesFolder]': 'C:/Program Files (x86)/Common Files',
        '[CommonAppDataFolder]': 'C:/ProgramData',
        '[WindowsFolder]': 'C:/Windows',
        '[SystemFolder]': 'C:/Windows/SysWOW64',
        '[System64Folder]': 'C:/Windows/System32',
    }
    base, sep, rest = relative.partition('/')
    return Path(roots[base]) / rest if base in roots and sep else None


def prepare(args):
    rows, evidence, ownership = [], [], collections.defaultdict(list)
    prior = load_rows(args.plus)
    prior_by_hash = {r['sha256']: r for r in prior if r['sha256'] and r.get('classification_evidence')}
    for owner, package, folder in [('Plus', 'Plus', args.plus)] + [
            ('Properties', p.name, p) for p in args.properties]:
        for category in (REVERSE, DIRECT):
            evidence.append(fingerprint(folder / category / 'files.csv'))
        selected = [dict(r, owner=owner, package=package) for r in load_rows(folder) if r['priority'] == '1']
        for r in selected:
            if owner == 'Properties':
                r['scope'] = r['scope'].replace('Aspen-Plus', 'Aspen-Properties')
            if r['source'] == 'installer-payload':
                path = target_path(r['relative_path'])
                if path:
                    ownership[str(path).casefold()].append(r)
        rows.extend(selected)
    # Only exact MSI targets in shared directories. New files in each product's
    # own directory are included separately as installed-only supplements.
    candidates = {p: (target_path(refs[0]['relative_path']), refs)
                  for p, refs in ownership.items() if Path(p).is_file()}
    errors = []
    for owner, folder in [('Plus', Path('C:/Program Files/AspenTech/Aspen Plus V15.0')),
                          ('Plus', Path('C:/ProgramData/AspenTech/Aspen Plus V15.0')),
                          ('Properties', Path('C:/Program Files/AspenTech/Aspen Properties V15.0')),
                          ('Properties', Path('C:/ProgramData/AspenTech/Aspen Properties V15.0')),
                          ('Properties', Path('C:/ProgramData/AspenTech/APED V15.0'))]:
        if not folder.is_dir():
            errors.append(dict(path=str(folder), error='product installation directory missing'))
            continue
        for path in walk(folder, errors):
            candidates.setdefault(str(path).casefold(), (path, [dict(owner=owner, relative_path='product-own-directory')]))
    tasks = [('installed-owned', 2, 'MSI-owned-or-product-directory', Path('C:/'), p)
             for p, refs in candidates.values()]
    installed = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        for task, r in zip(tasks, pool.map(physical_file, tasks)):
            refs = candidates[str(task[-1]).casefold()][1]
            r.update(owner=';'.join(sorted({x['owner'] for x in refs})), package='installed',
                     ownership_evidence=json.dumps([dict(owner=x['owner'], target=x['relative_path'],
                         component=x.get('msi_component', ''), installer=x.get('original_path', '')) for x in refs], ensure_ascii=False))
            installed.append(r)
    print(f'Read {len(installed)} owned installed files', flush=True)
    for outer in list(installed):
        if not outer.get('_zip') or outer['read_status'] != 'ok':
            continue
        try:
            with zipfile.ZipFile(outer['original_path']) as archive:
                for info in archive.infolist():
                    if info.is_dir():
                        continue
                    if info.flag_bits & 1:
                        sha, head, size, status = '', b'encrypted\0', info.file_size, 'encrypted-member-not-read'
                    else:
                        with archive.open(info) as stream:
                            sha, head, size = digest_stream(stream)
                        status = 'ok'
                    installed.append(record(info.filename, head, source='installed-owned:zip-member', priority=2,
                        scope=outer['scope'], relative_path=outer['relative_path'] + '!/' + info.filename,
                        original_path=outer['original_path'], container=outer['original_path'], member=info.filename,
                        size_bytes=size, sha256=sha, version='', read_status=status,
                        owner=outer['owner'], package='installed', ownership_evidence=outer['ownership_evidence']))
        except (OSError, ValueError, RuntimeError, zipfile.BadZipFile) as exc:
            errors.append(dict(path=outer['original_path'], error=str(exc)))
    rows.extend(installed)
    reused = 0
    for r in rows:
        r['priority'] = str(r['priority'])
        r.setdefault('ownership_evidence', 'original installer delivery: ' + r['package'])
        r['analysis_key'] = 'sha256:' + r['sha256'] if r['sha256'] and r['read_status'] == 'ok' else 'unverified'
        old = prior_by_hash.get(r['sha256']) if r['read_status'] == 'ok' else None
        if old:
            for name in ('category', 'format', 'reason', 'review', 'classification_status', 'classification_remaining'):
                r[name] = old.get(name, '')
            r['classification_evidence'] = str(args.plus.resolve()) + '/' + old['classification_evidence']
            reused += 1
    save_rows(args.output, rows)
    emit_json(args.output / 'inputs.json', evidence)
    emit_json(args.output / 'errors.json', errors)
    emit_json(args.output / 'installed-targets-not-present.json', [dict(target=p, owners=sorted({r['owner'] for r in refs}))
              for p, refs in ownership.items() if not Path(p).is_file()])
    emit_json(args.output / 'summary.json', dict(rows=len(rows), installed_physical=len(tasks),
        reused_classification_rows=reused, uncertain=sum(bool(r['review']) for r in rows),
        unresolved_symbolic_targets=sum(r['source'] == 'installer-payload' and target_path(r['relative_path']) is None for r in rows),
        time_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        installed_rule='Fresh reads of exact MSI targets and own product directories; other shared files excluded',
        roots_rule='64-bit MSI package: SystemFolder=SysWOW64; System64Folder=System32; TARGETDIR kept unresolved'))
    print(json.dumps(json.loads((args.output / 'summary.json').read_text()), ensure_ascii=False), flush=True)


def report(args):
    rows = load_rows(args.inventory)
    by_hash = collections.defaultdict(set)
    for r in rows:
        if r['priority'] == '1' and r['read_status'] == 'ok' and r['sha256']:
            by_hash[r['sha256']].update(r['owner'].split(';'))
    shared = {h for h, owners in by_hash.items() if owners == {'Plus', 'Properties'}}
    for r in rows:
        r['shared_content'] = str(r['sha256'] in shared and r['read_status'] == 'ok')
        r['memberships'] = 'Plus;Properties' if r['shared_content'] == 'True' else r['owner']
        # Existing classification evidence must remain resolvable after copying.
        if r.get('classification_evidence') and not Path(r['classification_evidence']).is_absolute():
            evidence_root = Path(r.get('classification_evidence_root') or args.inventory.resolve())
            r['classification_evidence'] = str(evidence_root / r['classification_evidence'])
    groups = {owner: [r for r in rows if owner in r['memberships'].split(';')] for owner in ('Plus', 'Properties')}
    groups['Shared'] = [r for r in rows if r['shared_content'] == 'True' or r['owner'] == 'Plus;Properties']
    # Exact target overlap is a second, separate relation, even for different bytes.
    targets = collections.defaultdict(list)
    symbolic_targets = collections.defaultdict(list)
    for r in rows:
        if r['source'] == 'installer-payload':
            group = targets if target_path(r['relative_path']) is not None else symbolic_targets
            group[r['relative_path'].casefold()].append(r)
    variants = []
    for path, items in targets.items():
        if {r['owner'] for r in items} == {'Plus', 'Properties'} and len({r['sha256'] for r in items}) > 1:
            variants.extend(dict(r, shared_target=path) for r in items)
    fields = list(dict.fromkeys(k for r in rows for k in r))
    write_csv(args.output / 'shared-target-variants.csv', sorted(variants, key=key), fields + ['shared_target'])
    symbolic_variants = [dict(r, symbolic_target=path) for path, items in symbolic_targets.items()
                         if {r['owner'] for r in items} == {'Plus', 'Properties'} and len({r['sha256'] for r in items}) > 1
                         for r in items]
    write_csv(args.output / 'symbolic-target-variants.csv', sorted(symbolic_variants, key=key), fields + ['symbolic_target'])
    summaries = {}
    for name, items in groups.items():
        folder = args.output / name.lower()
        folder.mkdir()
        save_rows(folder, items)
        fields = list(dict.fromkeys(k for r in items for k in r))
        write_csv(folder / 'remaining-review.csv', sorted([r for r in items if r['review'] or r['read_status'] != 'ok'], key=key), fields)
        stats = collections.Counter((r['category'], r['extension']) for r in items)
        write_csv(folder / 'extension-statistics.csv', [dict(category=c, extension=e, files=n) for (c,e),n in sorted(stats.items())],
                  ['category', 'extension', 'files'])
        lines = [f'# {name} 分类文档清单', '', '来源逐行列出，非去重文件数。两包同哈希内容在三份清单同时列出；owner 保留原交付归属。', '',
                 '详尽来源、组件、版本、内容哈希和证据见同目录两大类 CSV。此处按末级后缀排序，不表示已完成反编译。', '',
                 '两类包含规则初分条目，待核实项见 remaining-review.csv；分类状态为 preliminary-rule-only 的条目尚未通过分类验收。', '',
                 '| 类别 | 后缀 | 原始文件/成员路径 | SHA-256 | 交付来源 | 分类状态 |', '| --- | --- | --- | --- | --- | --- |']
        for r in sorted(items, key=key):
            path = r['relative_path'].replace('|', '&#124;')
            lines.append(f"| {r['category']} | {r['extension']} | `{path}` | `{r['sha256'] or '不可读'}` | {r['owner']} / {r['package']} / {r['source']} | {r.get('classification_status', 'baseline')} |")
        (folder / 'classification.md').write_text('\n'.join(lines) + '\n', encoding='utf-8')
        summaries[name] = dict(rows=len(items), categories=dict(collections.Counter(r['category'] for r in items)),
            unique_hashes=len({r['sha256'] for r in items if r['sha256']}), review=sum(bool(r['review']) for r in items),
            preliminary_rule_only=sum(r.get('classification_status') == 'preliminary-rule-only' for r in items),
            unreadable=sum(r['read_status'] != 'ok' for r in items),
            primary_payload=dict(collections.Counter(r['category'] for r in items if r['source'] == 'installer-payload' and r['owner'] == name)))
    identities = lambda items: {(r['owner'], r['package'], r['source'], r['relative_path'], r['sha256']) for r in items}
    shared_ids = identities(groups['Shared'])
    assert shared_ids <= identities(groups['Plus'])
    assert shared_ids <= identities(groups['Properties'])
    for items in groups.values():
        for r in items:
            if r['read_status'] == 'ok' and r['sha256']:
                assert r['analysis_key'] == 'sha256:' + r['sha256']
        for category in (REVERSE, DIRECT):
            part = [r for r in sorted(items, key=key) if r['category'] == category]
            assert [r['extension'] for r in part] == sorted(r['extension'] for r in part)
    summary = dict(input=str(args.inventory.resolve()), lists=summaries, shared_verified_hashes=len(shared),
        shared_runtime_payload_hashes=len({r['sha256'] for r in groups['Shared'] if r['source'] == 'installer-payload'}),
        shared_target_variant_paths=len({r['shared_target'] for r in variants}),
        symbolic_target_variant_paths=len({r['symbolic_target'] for r in symbolic_variants}),
        source_rows=len(rows), source_read_errors=[dict(path=r['original_path'], status=r['read_status']) for r in rows if r['read_status'] != 'ok'])
    emit_json(args.output / 'summary.json', summary)
    emit_json(args.output / 'verification.json', dict(triple_listing=True, analysis_keys=True, suffix_sort=True,
        inventory_inputs=[fingerprint(args.inventory / c / 'files.csv') for c in (REVERSE, DIRECT)],
        common_rule='verified SHA-256 present in primary deliveries of both products; exact installed targets also retain both ownerships',
        limitation='Common bytes do not prove runtime use. Installer streams/containers are distinguished by source. Same target with differing hashes remains a separate variant relation.'))
    (args.output / 'README.md').write_text('# Plus / Properties 双产品盘点及分类\n\n'
        '完整分类文档：\n\n- [Plus](plus/classification.md)\n- [Properties](properties/classification.md)\n- [共用](shared/classification.md)\n\n'
        '各目录按需要逆向 / 不需要逆向列出 CSV，类内按后缀排序。同哈希沿用分析键，双方来源保留。'
        '两类含规则初分条目，尚未通过分类验收的内容见各目录 remaining-review.csv。'
        'shared-target-variants.csv 单列同安装目标异哈希；summary.json 和 verification.json 保存统计与验证。'
        '安装容器、载荷、内嵌流与 ZIP 成员分别计数，不是去重文件数。原输入与详细资料仅本地保留。\n', encoding='utf-8')
    print(json.dumps(summary, ensure_ascii=False), flush=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest='action', required=True)
    a = sub.add_parser('prepare')
    a.add_argument('--plus', required=True, type=Path)
    a.add_argument('--properties', required=True, action='append', type=Path)
    b = sub.add_parser('report')
    b.add_argument('--inventory', required=True, type=Path)
    for p in (a, b):
        p.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    if args.output.exists():
        parser.error('output must be a new path; historical evidence is never overwritten')
    args.output.mkdir(parents=True)
    (prepare if args.action == 'prepare' else report)(args)


if __name__ == '__main__':
    main()
