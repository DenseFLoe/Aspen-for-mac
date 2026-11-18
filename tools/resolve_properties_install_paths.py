"""Resolve Properties symbolic targets using MSI assembly tables and read-only GAC evidence.

Does not run an installer, repair a component, load input code, or classify Plus.
Original CSV columns stay unchanged except target_resolution. All detailed output
is local; each run requires a new directory. Disabled components have no invented
physical path, and different installed bytes never replace installer hashes.
"""

import argparse
import collections
import csv
import ctypes as C
from ctypes import wintypes as W
import datetime
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess


CATEGORIES = ('01-needs-reverse', '02-no-reverse', '03-undetermined')
LISTS = [(c, 'files.csv') for c in CATEGORIES] + [(c, 'duplicates.csv') for c in CATEGORIES[:2]]
TABLES = {
    'File': ['File', 'Component_', 'FileName', 'FileSize'],
    'Component': ['Component', 'ComponentId', 'Directory_', 'Attributes', 'Condition', 'KeyPath'],
    'Directory': ['Directory', 'Directory_Parent', 'DefaultDir'],
    'MsiAssembly': ['Component_', 'Feature_', 'File_Manifest', 'File_Application', 'Attributes'],
    'MsiAssemblyName': ['Component_', 'Name', 'Value'],
    'Property': ['Property', 'Value'],
    'InstallExecuteSequence': ['Action', 'Condition', 'Sequence'],
}
ADDED_FIELDS = ('previous_target_resolution', 'assembly_identity', 'resolved_target',
                'installed_path', 'installed_sha256', 'installed_content_relation',
                'component_install_state', 'target_evidence')
BUCKETS = ('GAC_MSIL', 'GAC_32', 'GAC_64', 'GAC')


def require(condition, message):
    if not condition:
        raise ValueError(message)


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def fingerprint(path):
    return dict(path=str(Path(path).resolve()), sha256=sha(path))


def emit(path, data):
    with Path(path).open('x', encoding='utf-8') as stream:
        json.dump(data, stream, ensure_ascii=False, indent=2)
        stream.write('\n')


def read_csv(path):
    with Path(path).open(encoding='utf-8-sig', newline='') as stream:
        return list(csv.DictReader(stream))


def write_csv(path, rows, fields):
    with path.open('x', encoding='utf-8-sig', newline='') as stream:
        writer = csv.DictWriter(stream, fieldnames=fields)
        writer.writeheader()
        writer.writerows(rows)


def assembly_spec(row, tables):
    """Require relational evidence; a DLL filename or GAC-looking directory is insufficient."""
    file = next(f for f in tables['File'] if f['File'] == row['msi_file_id'])
    require(file['Component_'] == row['msi_component'], 'File/Component mismatch')
    require(file['FileName'].split('|')[-1] == row['relative_path'].split('/')[-1], 'filename mismatch')
    require(int(file['FileSize']) == int(row['size_bytes']), 'installer size mismatch')
    component = next(c for c in tables['Component'] if c['Component'] == row['msi_component'])
    assembly = next(a for a in tables['MsiAssembly'] if a['Component_'] == row['msi_component'])
    require(assembly['File_Application'] == '' and assembly['Attributes'] in ('', '0'),
            'not a global .NET assembly')
    require(component['KeyPath'] == assembly['File_Manifest'] == file['File'],
            'component/manifest does not identify this file')
    names = {n['Name'].lower(): n['Value'] for n in tables['MsiAssemblyName']
             if n['Component_'] == row['msi_component']}
    for key in ('name', 'version', 'culture', 'publickeytoken'):
        require(bool(names.get(key)), 'assembly identity missing ' + key)
    # These values become single path segments during narrowly scoped GAC reads.
    require(all(x not in names['name'] for x in ('/', '\\', ':')) and names['name'] not in ('.', '..'),
            'invalid assembly name')
    require({'MsiPublishAssemblies', 'MsiUnpublishAssemblies'} <=
            {a['Action'] for a in tables['InstallExecuteSequence']}, 'assembly actions missing')
    identity = ', '.join([names['name']] + [k + '=' + names[k.lower()] for k in
                         ('Version', 'Culture', 'PublicKeyToken', 'ProcessorArchitecture') if k.lower() in names])
    return dict(file=file, component=component, assembly=assembly, names=names, identity=identity)


def identity_matches(expected, actual):
    return not actual.get('error') and all(
        expected[k].casefold() == actual.get(k, '').casefold()
        for k in ('name', 'version', 'culture', 'publickeytoken', 'processorarchitecture') if k in expected)


def choose_result(spec, state, registered_path, candidates, source_sha):
    matches = [c for c in candidates if identity_matches(spec['names'], c)]
    registered = [c for c in matches if os.path.normcase(c['path']) == os.path.normcase(registered_path)]
    if state == 3:
        require(len(registered) == 1, 'local registered keypath has no matching assembly manifest')
        chosen = registered[0]
    elif state == -7:
        require(not registered_path and not matches, 'disabled component has conflicting physical evidence')
        return dict(target_resolution='gac-component-disabled', installed_path='', installed_sha256='',
                    installed_content_relation='not-installed-component-disabled')
    else:
        require(state in (-1, 2), 'unexpected component state: ' + str(state))
        require(len(matches) == 1, 'no unique physical GAC identity; do not guess a path')
        chosen = matches[0]
    relation = 'identical' if chosen['sha256'] == source_sha else 'different-content'
    return dict(target_resolution='gac-installed-' + relation, installed_path=chosen['path'],
                installed_sha256=chosen['sha256'], installed_content_relation=relation)


class InstalledState:
    def __init__(self):
        self.api = C.WinDLL('msi')
        self.api.MsiGetComponentPathW.argtypes = [W.LPCWSTR, W.LPCWSTR, W.LPWSTR, C.POINTER(W.DWORD)]
        self.api.MsiGetComponentPathW.restype = C.c_int
        self.api.MsiQueryProductStateW.argtypes = [W.LPCWSTR]
        self.api.MsiQueryProductStateW.restype = C.c_int

    def component(self, product, component):
        buffer, count = C.create_unicode_buffer(32768), W.DWORD(32768)
        state = self.api.MsiGetComponentPathW(product, component, buffer, C.byref(count))
        require(state != -3, 'component path buffer too small')
        return dict(state=state, path=buffer.value)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--inventory', type=Path, required=True)
    parser.add_argument('--package-inventory', type=Path, action='append', required=True)
    parser.add_argument('--plus-baseline', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    require(os.name == 'nt', 'read-only Windows Installer evidence requires Windows')
    require(not args.output.exists(), 'output must be new; historical assets are preserved')
    inputs = [args.inventory / c / n for c, n in LISTS] + [args.inventory / 'duplicate-groups.json']
    inputs += [args.plus_baseline / c / n for c in CATEGORIES[:2] for n in ('files.csv', 'primary-files.csv')]
    for package in args.package_inventory:
        inputs += [package / 'selection.json', package / 'physical-files.csv']
    rows = [r for c in CATEGORIES for r in read_csv(args.inventory / c / 'files.csv')]
    pending = [r for r in rows if r['target_resolution'] == 'symbolic-target-unresolved']
    require(pending and len({r['record_id'] for r in rows}) == len(rows), 'missing targets or duplicate source IDs')
    require(all(r['source'] == 'installer-payload' and r['priority'] == '1' and
                'Properties' in r['owner'].split(';') for r in pending), 'target exceeds Properties payload scope')
    packages = {p.name: p for p in args.package_inventory}
    require({r['package'] for r in pending} <= packages.keys(), 'missing package inventory')
    before = [fingerprint(p) for p in inputs]
    args.output.mkdir(parents=True)
    (args.output / 'evidence').mkdir()
    from inventory_aspen_sources import CabinetScanner, MsiReader
    state_api, sources, specs, requests = InstalledState(), {}, {}, {}
    cabinets = {}
    for name in sorted({r['package'] for r in pending}):
        package = packages[name]
        selection = json.loads((package / 'selection.json').read_text(encoding='utf-8'))
        msi = Path(selection['primary_path'])
        physical = {os.path.normcase(r['original_path']): r for r in read_csv(package / 'physical-files.csv')}
        msi_fp = fingerprint(msi)
        require(msi_fp['sha256'] == physical[os.path.normcase(str(msi))]['sha256'], 'original MSI changed')
        before.append(msi_fp)
        reader = MsiReader(msi)
        try:
            tables = {t: list(reader.rows(t, columns)) for t, columns in TABLES.items()}
        finally:
            reader.close()
        properties = {r['Property']: r['Value'] for r in tables['Property']}
        product = properties['ProductCode']
        table_name = name + '.msi-tables.json'
        emit(args.output / table_name, tables)
        sources[name] = dict(product_code=product, product_install_state=state_api.api.MsiQueryProductStateW(product),
                             msi=msi_fp, tables=table_name)
        for row in pending:
            if row['package'] != name:
                continue
            require(os.path.normcase(row['original_path']) == os.path.normcase(str(msi)), 'wrong installer ownership')
            spec = assembly_spec(row, tables)
            spec['registration'] = state_api.component(product, spec['component']['ComponentId'])
            candidates = set()
            # Enumerate only the named assembly in known cache buckets, not all Aspen products.
            for root in (Path(os.environ['WINDIR']) / 'Microsoft.NET/assembly', Path(os.environ['WINDIR']) / 'assembly'):
                for bucket in BUCKETS:
                    folder = root / bucket / spec['names']['name']
                    if folder.is_dir():
                        candidates.update(str(p) for p in folder.rglob(row['relative_path'].split('/')[-1]) if p.is_file())
            spec['candidate_paths'] = sorted(candidates)
            specs[row['record_id']] = spec
            for path in candidates:
                requests[path] = None
            cab = Path(row['container'])
            if str(cab) not in cabinets:
                fp = fingerprint(cab)
                require(fp['sha256'] == physical[os.path.normcase(str(cab))]['sha256'], 'original CAB changed')
                before.append(fp)
                cabinets[str(cab)] = None
    print(f'Confirmed assembly-table joins for {len(pending)} targets; reading {len(cabinets)} CABs and {len(requests)} GAC manifests.', flush=True)
    scanner = CabinetScanner()
    try:
        for cab in cabinets:
            cabinets[cab] = {r['name']: r for r in scanner.scan(Path(cab))}
    finally:
        scanner.close()
    for row in pending:
        payload = cabinets[row['container']][row['member']]
        require(payload['sha256'] == row['sha256'] and payload['size'] == int(row['size_bytes']),
                'installer payload content changed')
        specs[row['record_id']]['payload_recheck'] = dict(sha256=payload['sha256'], size_bytes=payload['size'])
    emit(args.output / 'assembly-identity-request.json', sorted(requests))
    collector = Path(__file__).with_name('Get-AssemblyIdentityEvidence.ps1').resolve()
    subprocess.run(['powershell.exe', '-NoProfile', '-NonInteractive', '-File', str(collector),
                    '-RequestPath', str((args.output / 'assembly-identity-request.json').resolve()),
                    '-OutputPath', str((args.output / 'assembly-identities.json').resolve())], check=True)
    identities = {r['path']: r for r in json.loads((args.output / 'assembly-identities.json').read_text(encoding='utf-8'))}
    updates, evidence_index = {}, []
    for row in pending:
        spec = specs[row['record_id']]
        candidates = [identities[p] for p in spec['candidate_paths']]
        registration = spec['registration']
        result = choose_result(spec, registration['state'], registration['path'], candidates, row['sha256'])
        evidence_path = 'evidence/' + row['record_id'] + '.json'
        update = dict(previous_target_resolution=row['target_resolution'], assembly_identity=spec['identity'],
                      resolved_target='GAC: ' + spec['identity'], component_install_state=registration['state'],
                      target_evidence=evidence_path, **result)
        detail = dict(record_id=row['record_id'], source={k: row[k] for k in
                      ('package', 'original_path', 'relative_path', 'container', 'member', 'msi_file_id',
                       'msi_component', 'sha256', 'analysis_key')}, installer=sources[row['package']],
                      specification=spec, candidate_identities=candidates, result=update)
        emit(args.output / evidence_path, detail)
        note = '\n'.join(['# ' + row['relative_path'].split('/')[-1] + ' 安装目标核验', '',
            '来源记录：`' + row['record_id'] + '`；原路径：`' + row['relative_path'] + '`。',
            '安装包：`' + row['original_path'] + '`；组件：`' + row['msi_component'] + '`。',
            '核验范围：File → Component → MsiAssembly / MsiAssemblyName、原 CAB 载荷哈希、只读安装注册及 GAC 清单。',
            '状态：`' + result['target_resolution'] + '`；安装身份：`' + spec['identity'] + '`。',
            '本机物理路径：`' + (result['installed_path'] or '无；本机组件状态为 NOTUSED (-7)，未伪造路径') + '`。',
            '来源哈希：`' + row['sha256'] + '`；本机哈希：`' + (result['installed_sha256'] or '无') + '`。',
            '验收依据及组件条件见同名 JSON；同名异内容保留独立哈希，不改变原分类或重复关系。',
            '剩余范围：本轮仅确认安装目标与当前存在状态，未完成反编译、重建或行为验收。',
            '下一步：沿原处理路线逐文件分析；不同内容分别处理，禁用组件在满足其安装条件的环境另行验证。', ''])
        with (args.output / evidence_path).with_suffix('.md').open('x', encoding='utf-8') as stream:
            stream.write(note)
        updates[row['record_id']] = update
        evidence_index.append(dict(record_id=row['record_id'], evidence=evidence_path, **update))
    for cat, filename in LISTS:
        old = read_csv(args.inventory / cat / filename)
        fields = list(rows[0]) + list(ADDED_FIELDS)
        amended = []
        for row in old:
            changed = {**row, **{k: '' for k in ADDED_FIELDS}, **updates.get(row['record_id'], {})}
            amended.append(changed)
        (args.output / cat).mkdir(exist_ok=True)
        write_csv(args.output / cat / filename, amended, fields)
    shutil.copyfile(args.inventory / 'duplicate-groups.json', args.output / 'duplicate-groups.json')
    emit(args.output / 'target-resolutions.json', evidence_index)
    summary = dict(time_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                   source_rows=len(rows), target_rows=len(pending),
                   target_status_counts=dict(collections.Counter(r['target_resolution'] for r in updates.values())),
                   package_rows=dict(collections.Counter(r['package'] for r in pending)),
                   physical_path_rows=sum(bool(r['installed_path']) for r in updates.values()),
                   unique_physical_paths=len({os.path.normcase(r['installed_path']) for r in updates.values() if r['installed_path']}),
                   unresolved_target_rows=0, classification_and_duplicate_fields_unchanged=True,
                   baseline_inventory=str(args.inventory.resolve()), plus_baseline_unchanged=True,
                   packages=sources, original_cabs_rechecked=len(cabinets),
                   limits=['Disabled component has a confirmed GAC identity, no physical installed path.',
                           'Different installed bytes keep a separate hash; source classification and duplicates stay frozen.',
                           'A shared GAC file does not establish installation of the server package.'])
    require(all(sha(Path(f['path'])) == f['sha256'] for f in before), 'an input changed during collection')
    emit(args.output / 'input-fingerprints.json', before)
    emit(args.output / 'summary.json', summary)
    (args.output / 'README.md').write_text('\n'.join([
        '# Properties 安装目标落实（2026-11-19）', '',
        '五份 CSV 沿用原分类及来源身份，仅增加安装定位证据；旧快照和全部源码归档继续保留。',
        '分类基线：`' + str(args.inventory.resolve()) + '`。本轮没有反编译或编译，不生成源码完成件。',
        '安装目标记录：' + str(len(pending)) + '；实际物理路径记录：' + str(summary['physical_path_rows']) + '。',
        '状态：`' + json.dumps(summary['target_status_counts'], ensure_ascii=False) + '`。',
        '本机禁用组件仍保留 GAC 身份，installed_path 为空；不同内容独立保留本机哈希。',
        '逐项入口：target-resolutions.json 及 evidence/ 下每条记录的 JSON 和同名说明。',
        '尚未确定清单表示内容处理路线；组件安装状态、内容差异与路径定位单独统计。',
        '本地报告与原版输入不上 GitHub。数据库、公式、历史证据均未覆盖。', '']), encoding='utf-8')
    print(json.dumps({k: summary[k] for k in ('target_rows', 'target_status_counts', 'physical_path_rows',
                                             'unique_physical_paths', 'unresolved_target_rows')}, ensure_ascii=False))


if __name__ == '__main__':
    main()
