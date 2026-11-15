"""Extract only referenced raster UI assets; never load the source assemblies.

Requires the same dnfile/pefile environment as scan_aspen_ui.py plus Pillow.
The manifest records exact source resources and hashes, including unresolved
references. No source DLL or intermediate extraction enters the repository.
"""
import argparse
import hashlib
import io
import json
import posixpath
import struct
from pathlib import Path

import dnfile
from PIL import Image
from scan_aspen_ui import managed_entries


def recover(root, catalog, output):
    cache = {}
    assets, references, unresolved = {}, {}, []

    def entries(relative):
        if relative in cache:
            return cache[relative]
        result = {}
        pe = dnfile.dnPE(str(root / relative), clr_lazy_load=True)
        table = pe.net.mdtables.ManifestResource
        for row in table.rows if table else []:
            if row.Implementation is not None and row.Implementation.row:
                continue
            addr = pe.net.struct.ResourcesRva + row.Offset
            size = struct.unpack('<I', pe.get_data(addr, 4))[0]
            for name, value, _ in managed_entries(pe.get_data(addr + 4, size)):
                if isinstance(value, bytes) and name.lower().endswith(('.png', '.ico', '.bmp', '.jpg', '.gif')):
                    result[name.lower()] = (name, value)
        pe.close()
        cache[relative] = result
        return result

    def add(key, relative, resource):
        path = root / relative
        if not path.is_file() and path.with_name(path.name.replace('.dll', '.resources.dll')).is_file():
            relative = path.with_name(path.name.replace('.dll', '.resources.dll')).relative_to(root).as_posix()
            path = root / relative
        if not path.is_file() and (path.parent.parent / path.name).is_file():
            relative = (path.parent.parent / path.name).relative_to(root).as_posix()
        if not (root / relative).is_file():
            return False
        resources = entries(relative)
        candidates = [resource.lower()]
        if '/images/' in resource.lower():
            candidates.append('images/' + resource.lower().split('/images/', 1)[1])
        match = next((resources[x] for x in candidates if x in resources), None)
        if not match:
            path = root / relative
            candidates_paths = [path.parent.parent / path.name.replace('.resources.dll', '.dll')]
            if not path.name.endswith('.resources.dll'):
                candidates_paths.append(path.parent / 'en-US' / path.name.replace('.dll', '.resources.dll'))
            for alternative in candidates_paths:
                if not alternative.is_file() or alternative == path:
                    continue
                other = entries(alternative.relative_to(root).as_posix())
                match = next((other[x] for x in candidates if x in other), None)
                if match:
                    relative = alternative.relative_to(root).as_posix()
                    break
        if not match:
            return False
        name, data = match
        digest = hashlib.sha256(data).hexdigest()
        if digest not in assets:
            image = Image.open(io.BytesIO(data)).convert('RGBA')
            destination = output / 'recovered' / (digest[:20] + '.png')
            destination.parent.mkdir(parents=True, exist_ok=True)
            image.save(destination)
            assets[digest] = {'file': 'recovered/' + destination.name, 'source': relative,
                              'resource': name, 'sha256': digest, 'width': image.width, 'height': image.height}
        references[key] = assets[digest]['file']
        return True

    common = 'AprSystem V15.0/GUI/Xeq/AspenTech.Visualisation.CommonImages.Wpf.dll'
    aliases = {'ribbon-collapse': 'ribboncollapse_16', 'ribbon-expand': 'ribbonexpand_16',
               'document-close': 'ribbonclosedocument_16', 'window-back': 'navigatebackward_16',
               'window-forward': 'navigateforward_16', 'find-component': 'findcomponents_16',
               'electrolyte-wizard': 'electrolyteswizard_48', 'user-components': 'componentwizard_16',
               'quick-help': 'help_16', 'reorder': 'navigationsync_16'}
    for key, name in aliases.items():
        if not add(key, common, 'images/' + name + '.png'):
            unresolved.append({'key': key, 'reference': name})
    index = json.loads((catalog / 'index.json').read_text(encoding='utf-8'))
    for module in index['modules']:
        for page in json.loads((catalog / module['file']).read_text(encoding='utf-8'))['pages']:
            source = page['source']
            for n, node in enumerate(page['nodes']):
                for prop in ('Source', 'ImageSource', 'SmallImage', 'LargeImage'):
                    value = node.get('p', {}).get(prop)
                    if not value:
                        continue
                    key = page['id'] + ':' + str(n) + ':' + prop
                    if not isinstance(value, str):
                        unresolved.append({'key': key, 'reference': value})
                        continue
                    relative = source['file']
                    resource = value.replace('\\', '/')
                    if ';component/' in resource:
                        assembly, resource = resource.split(';component/', 1)
                        assembly = assembly.rsplit('/', 1)[-1]
                        relative = str(Path(relative).parent / (assembly + '.dll')).replace('\\', '/')
                    else:
                        resource = posixpath.normpath(posixpath.join(posixpath.dirname(source['resource']), resource))
                    if not add(key, relative, resource):
                        unresolved.append({'key': key, 'reference': value})
    manifest = {'schemaVersion': 1, 'assets': list(assets.values()), 'references': references, 'unresolved': unresolved}
    (output / 'recovered.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(f'{len(assets)} assets, {len(references)} references, {len(unresolved)} unresolved')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--catalog', type=Path, default=Path('ui/recovered'))
    parser.add_argument('--output', type=Path, default=Path('ui/icons'))
    args = parser.parse_args()
    recover(args.root, args.catalog, args.output)
