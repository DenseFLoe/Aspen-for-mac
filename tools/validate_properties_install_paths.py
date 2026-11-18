"""Independently check path-only amendments, MSI joins, hashes and five-list coverage."""

import argparse
import collections
import csv
import hashlib
import json
import os
from pathlib import Path


def check(condition, message):
    if not condition:
        raise ValueError(message)


def digest(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def load(root, cat, name='files.csv'):
    with (root / cat / name).open(encoding='utf-8-sig', newline='') as stream:
        return list(csv.DictReader(stream))


def validate(before, after):
    cats = ('01-needs-reverse', '02-no-reverse', '03-undetermined')
    source = [r for c in cats for r in load(before, c)]
    final = [r for c in cats for r in load(after, c)]
    check(len({r['record_id'] for r in final}) == len(source) == len(final), 'source rows lost or duplicated')
    check([r['record_id'] for r in source] == [r['record_id'] for r in final], 'source identity/order changed')
    targets = {r['record_id']: r for r in source if r['target_resolution'] == 'symbolic-target-unresolved'}
    index = json.loads((after / 'target-resolutions.json').read_text(encoding='utf-8'))
    check(len(index) == len(targets) and {r['record_id'] for r in index} == targets.keys(), 'target coverage mismatch')
    changed, states, physical = [], collections.Counter(), set()
    checked_hashes = {}
    for old, row in zip(source, final):
        check(all(row[k] == v for k, v in old.items() if k != 'target_resolution'), 'original field changed: ' + old['record_id'])
        if old['record_id'] not in targets:
            check(row['target_resolution'] == old['target_resolution'], 'non-target rewritten')
            check(all(not row[k] for k in row.keys() - old.keys()), 'non-target given invented target evidence')
            continue
        changed.append(row)
        path = (after / row['target_evidence']).resolve()
        check(path.is_relative_to((after / 'evidence').resolve()), 'evidence outside local output')
        detail = json.loads(path.read_text(encoding='utf-8'))
        check(path.with_suffix('.md').is_file(), 'missing individual explanation')
        check(detail['record_id'] == row['record_id'], 'wrong evidence source identity')
        check(all(detail['source'][k] == row[k] for k in detail['source']), 'evidence source mismatch')
        check(all(str(v) == row[k] for k, v in detail['result'].items()), 'CSV differs from evidence result')
        raw = json.loads((after / detail['installer']['tables']).read_text(encoding='utf-8'))
        file = next(f for f in raw['File'] if f['File'] == row['msi_file_id'])
        component = next(c for c in raw['Component'] if c['Component'] == row['msi_component'])
        assembly = next(a for a in raw['MsiAssembly'] if a['Component_'] == row['msi_component'])
        names = {n['Name'].lower(): n['Value'] for n in raw['MsiAssemblyName'] if n['Component_'] == row['msi_component']}
        spec = detail['specification']
        check(spec['file'] == file and spec['component'] == component and spec['assembly'] == assembly and spec['names'] == names,
              'snapshot and per-target evidence disagree')
        check(file['Component_'] == component['Component'] and component['KeyPath'] == file['File'] == assembly['File_Manifest'], 'MSI joins invalid')
        check(file['FileName'].split('|')[-1] == row['relative_path'].split('/')[-1] and
              int(file['FileSize']) == int(row['size_bytes']), 'MSI name/size mismatch')
        check(not assembly['File_Application'] and assembly['Attributes'] in ('', '0'), 'not a global .NET target')
        check(spec['payload_recheck']['sha256'] == row['sha256'] and
              spec['payload_recheck']['size_bytes'] == int(row['size_bytes']), 'payload content not preserved')
        check(row['previous_target_resolution'] == 'symbolic-target-unresolved' and row['resolved_target'].startswith('GAC: '), 'missing original state or GAC destination')
        state = spec['registration']['state']
        check(str(state) == row['component_install_state'], 'component state mismatch')
        check(all(k in names for k in ('name', 'version', 'culture', 'publickeytoken')), 'incomplete GAC identity')
        matching = [c for c in detail['candidate_identities'] if not c.get('error') and all(
            c.get(k, '').lower() == names[k].lower() for k in
            ('name', 'version', 'culture', 'publickeytoken', 'processorarchitecture') if k in names)]
        if row['target_resolution'] == 'gac-component-disabled':
            check(state == -7 and not spec['registration']['path'] and not matching and
                  not row['installed_path'] and not row['installed_sha256'], 'disabled component assigned a physical path')
            check(row['installed_content_relation'] == 'not-installed-component-disabled', 'disabled component hidden')
        else:
            installed = row['installed_path']
            check(installed and state in (3, -1, 2), 'physical path lacks valid install state')
            chosen = [c for c in matching if c['path'] == installed]
            check(len(chosen) == 1, 'physical target lacks matching manifest identity')
            if state == 3:
                check(os.path.normcase(spec['registration']['path']) == os.path.normcase(installed), 'registered keypath mismatch')
            else:
                check(len(matching) == 1, 'ambiguous unregistered target')
            if installed not in checked_hashes:
                checked_hashes[installed] = digest(installed)
            actual = checked_hashes[installed]
            check(actual == row['installed_sha256'] == chosen[0]['sha256'], 'physical content changed or hash wrong')
            relation = 'identical' if actual == row['sha256'] else 'different-content'
            check(row['installed_content_relation'] == relation and row['target_resolution'] == 'gac-installed-' + relation,
                  'installed difference mislabeled')
            physical.add(os.path.normcase(installed))
        states[row['target_resolution']] += 1
    for cat in cats:
        if cat != cats[2]:
            route = load(after, cat)
            check(load(after, cat, 'duplicates.csv') == [r for r in route if r['duplicate_type']], 'duplicates subset changed')
    check((before / 'duplicate-groups.json').read_bytes() == (after / 'duplicate-groups.json').read_bytes(), 'duplicate source relationships changed')
    fingerprints = json.loads((after / 'input-fingerprints.json').read_text(encoding='utf-8'))
    for f in fingerprints:
        check(digest(f['path']) == f['sha256'], 'input, CAB or frozen Plus baseline changed: ' + f['path'])
    summary = json.loads((after / 'summary.json').read_text(encoding='utf-8'))
    check(summary['source_rows'] == len(final) and summary['target_rows'] == len(targets), 'summary source/target counts wrong')
    check(summary['target_status_counts'] == dict(states) and summary['unique_physical_paths'] == len(physical), 'summary statuses wrong')
    physical_rows = sum(bool(r['installed_path']) for r in changed)
    check(summary['physical_path_rows'] == physical_rows, 'physical row count wrong')
    check(summary['unresolved_target_rows'] == sum(r['target_resolution'] == 'symbolic-target-unresolved' for r in final), 'unresolved counter wrong')
    return dict(source_rows=len(final), target_rows=len(targets), target_status_counts=dict(states),
                physical_path_rows=physical_rows, unique_physical_paths=len(physical),
                individual_evidence_notes=len(changed), frozen_input_fingerprints=len(fingerprints),
                original_fields_preserved=True, classifications_and_duplicate_relationships_unchanged=True,
                all_input_hashes_and_current_physical_hashes_valid=True)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--before', type=Path, required=True)
    parser.add_argument('--after', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    check(not args.output.exists(), 'validation output must be new')
    result = validate(args.before, args.after)
    with args.output.open('x', encoding='utf-8') as stream:
        json.dump(result, stream, ensure_ascii=False, indent=2)
        stream.write('\n')
    print(json.dumps(result, ensure_ascii=False))


if __name__ == '__main__':
    main()
