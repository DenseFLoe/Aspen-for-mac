"""Independently validate the five Properties lists and their per-content evidence."""

import argparse
import collections
import csv
import hashlib
import json
import os
from pathlib import Path


def load(root, cat, name='files.csv'):
    with (root / cat / name).open(encoding='utf-8-sig', newline='') as stream:
        return list(csv.DictReader(stream))


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def check(condition, message):
    if not condition:
        raise ValueError(message)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--before', type=Path, required=True)
    parser.add_argument('--after', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    check(not args.output.exists(), 'validation output must be new')
    cats = ('01-needs-reverse', '02-no-reverse', '03-undetermined')
    original = [r for c in cats for r in load(args.before, c)]
    final = [r for c in cats for r in load(args.after, c)]
    old = {r['record_id']: r for r in original}
    new = {r['record_id']: r for r in final}
    check(len(old) == len(original) == len(final) == len(new), 'source identities duplicated or dropped')
    check(old.keys() == new.keys(), 'source identities changed')
    static_fields = ('extension', 'source', 'priority', 'scope', 'relative_path', 'original_path', 'container', 'member',
                     'size_bytes', 'sha256', 'version', 'read_status', 'msi_file_id', 'msi_component', 'msi_version',
                     'msi_size', 'analysis_key', 'owner', 'package', 'ownership_evidence', 'duplicate_type',
                     'properties_occurrences', 'plus_occurrences', 'duplicate_group', 'target_resolution')
    for key, before in old.items():
        row = new[key]
        check(all(row[k] == before[k] for k in static_fields), 'source or duplicate evidence changed: ' + key)
        if before['category'] != cats[2]:
            check(all(row[k] == v for k, v in before.items()), 'previously confirmed row reclassified or rewritten')
    evidence = {}
    for before in original:
        if before['category'] != cats[2]:
            continue
        row = new[before['record_id']]
        path = Path(row['classification_evidence'])
        if path not in evidence:
            detail = json.loads(path.read_text(encoding='utf-8'))
            check(path.with_suffix('.md').is_file(), 'missing individual content note')
            if before['sha256']:
                binary = path.with_name(path.name.removesuffix('.inspection.json'))
                check(sha(binary) == before['sha256'] and binary.stat().st_size == int(before['size_bytes']), 'content evidence hash/size mismatch')
            else:
                check(detail['confidence'] == 'SQL-catalog-confirmed' and not detail.get('sha256'), 'unreadable file given content identity')
                check(row['access_limitation'] and not row['duplicate_type'], 'metadata-only classification hides access restriction or invents duplicates')
            evidence[path] = detail
        detail = evidence[path]
        check(detail['category'] == row['category'], 'classification lacks matching content evidence')
        check(before['record_id'] in {r['record_id'] for r in detail['source_records']}, 'evidence omits classified source')
        check(row['classification_remaining'], 'remaining acceptance boundaries missing')
    for cat in cats:
        rows = load(args.after, cat)
        expected_order = sorted(rows, key=lambda r: (r['extension'].lower(), int(r['priority']), r['relative_path'].casefold(),
                                                    r['source'], r['container'], r['member'], r['record_id']))
        check(rows == expected_order, 'suffix order is not stable')
        if cat != cats[2]:
            duplicate = load(args.after, cat, 'duplicates.csv')
            check(duplicate == [r for r in rows if r['duplicate_type']], 'duplicate list is not the precise route subset')
    check((args.before / 'duplicate-groups.json').read_bytes() == (args.after / 'duplicate-groups.json').read_bytes(), 'duplicate source relationships changed')
    groups = json.loads((args.after / 'duplicate-groups.json').read_text(encoding='utf-8'))
    byhash = collections.defaultdict(list)
    for row in final:
        if row['sha256']:
            byhash[row['sha256']].append(row)
    for key, rows in byhash.items():
        check(len({r['category'] for r in rows}) == 1, 'same content has conflicting routes')
        check(len({r['analysis_key'] for r in rows}) == 1, 'same content has different analysis keys')
        if key in groups:
            check({r['record_id'] for r in rows} == {r['record_id'] for r in groups[key]['properties']}, 'duplicate group source coverage mismatch')
    modules = json.loads((args.after / 'internal-code-members.json').read_text(encoding='utf-8'))
    native_parts = json.loads((args.after / 'reader-code-evidence.json').read_text(encoding='utf-8'))
    for module in modules + native_parts:
        path = (args.after / module['path']).resolve()
        note = (args.after / module['note']).resolve()
        if os.name == 'nt':
            path, note = Path('\\\\?\\' + str(path)), Path('\\\\?\\' + str(note))
        check(path.is_file() and note.is_file() and sha(path) == module['sha256'], 'VBA result or matching note is missing or changed')
        check(module['acceptance'] == 'incomplete' and module['path'].startswith('02-incomplete/'), 'partial VBA falsely marked completed')
        check(new[module['source_record_id']]['category'] == cats[0], 'internal program omitted from reverse route')
    for fingerprint in json.loads((args.after / 'input-fingerprints.json').read_text(encoding='utf-8')):
        check(sha(Path(fingerprint['path'])) == fingerprint['sha256'], 'frozen inventory, evidence or Plus baseline changed')
    summary = json.loads((args.after / 'summary.json').read_text(encoding='utf-8'))
    counts = collections.Counter(r['category'] for r in final)
    check(all(summary['categories'][c]['rows'] == counts[c] for c in cats), 'summary count differs from independent CSV counts')
    result = dict(source_rows=len(final), source_identities_preserved=True, previously_confirmed_rows_unchanged=True,
                  content_evidence_files=len(evidence), readable_hashes=sum(bool(d.get('sha256')) for d in evidence.values()),
                  metadata_only_rows=sum(not r['sha256'] for r in original if r['category'] == cats[2]),
                  route_counts=dict(counts), internal_code_results_with_notes=len(modules),
                  native_reader_partial_results_with_notes=len(native_parts),
                  plus_and_original_fingerprints_unchanged=True, five_lists_and_duplicate_groups_valid=True)
    args.output.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(result, ensure_ascii=False))


if __name__ == '__main__':
    main()
