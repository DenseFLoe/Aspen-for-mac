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
from scan_aspen_ui import managed_entries, parse_baml


def literal_getter(pe, method):
    """Read only the exact tiny IL sequence ldstr; call; ret (or ldstr; ret).

    This reads metadata/bytes, never invokes or imports the source assembly.
    More complex getters deliberately remain unresolved.
    """
    if not method.Rva:
        return None
    header = pe.get_data(method.Rva, 1)[0]
    if header & 3 != 2:
        return None
    body = pe.get_data(method.Rva + 1, header >> 2)
    if body[:1] == b'\x02':  # Instance image provider: ldarg.0; ldstr; call; ret.
        body = body[1:]
    if not (len(body) in (6, 11) and body[0] == 0x72 and body[-1] == 0x2a):
        return None
    if len(body) == 11 and body[5] != 0x28:
        return None
    token = struct.unpack('<I', body[1:5])[0]
    if token >> 24 != 0x70:
        return None
    return pe.net.user_strings.get(token & 0xffffff).value


def literal_image_fields(pe, method):
    """Recognize a literal-only image cache initializer without executing IL."""
    header = pe.get_data(method.Rva, 12)
    if len(header) != 12 or header[0] & 3 != 3:
        return {}
    start = (struct.unpack('<H', header[:2])[0] >> 12) * 4
    body = pe.get_data(method.Rva + start, struct.unpack('<I', header[4:8])[0])
    # newobj Dictionary; stsfld cache, followed solely by literal image loads.
    if len(body) < 11 or body[0] != 0x73 or body[5] != 0x80 or body[-1] != 0x2a:
        return {}
    result = {}
    for offset in range(10, len(body)-1, 15):
        op = body[offset:offset+15]
        if len(op) != 15 or (op[0],op[5],op[10]) != (0x72,0x28,0x80):
            return {}
        token, field = struct.unpack('<I',op[1:5])[0], struct.unpack('<I',op[11:15])[0]
        if token >> 24 != 0x70 or field >> 24 != 4:
            return {}
        name = str(pe.net.mdtables.Field.rows[(field & 0xffffff)-1].Name)
        result[name] = pe.net.user_strings.get(token & 0xffffff).value
    return result


def recover(root, catalog, output):
    cache, getters, baml_cache = {}, {}, {}
    assets, references, unresolved, non_images = {}, {}, [], []
    inventory = json.loads((catalog / 'scan-files.json').read_text(encoding='utf-8'))
    known = json.loads(Path(__file__).with_name('baml_known.json').read_text(encoding='utf-8'))

    def assembly_files(relative):
        name = Path(relative).name.lower().replace('.resources.dll', '.dll')
        candidates = [x['path'] for x in inventory
                      if Path(x['path']).name.lower().replace('.resources.dll', '.dll') == name]
        def priority(file):
            return (file == relative, Path(file).parent == Path(relative).parent,
                    '/zh-hans/' in file.lower(), '/en-us/' in file.lower(), '/WPFForms/' in file)
        return sorted(candidates, key=priority, reverse=True)

    def member_resource(relative, member):
        owner, prop = member.rsplit('.', 1)
        for candidate in assembly_files(relative):
            if candidate.endswith('.resources.dll'):
                continue
            if candidate not in getters:
                pe = dnfile.dnPE(str(root / candidate), clr_lazy_load=True)
                values = {}
                for cls in pe.net.mdtables.TypeDef.rows:
                    if str(cls.TypeName) not in ('ImageResources', 'ImageSourceHelper', 'CommonImages'):
                        continue
                    for ref in cls.MethodList:
                        method = ref.row
                        if str(method.Name).startswith('get_'):
                            literal = literal_getter(pe, method)
                            if literal:
                                values[str(cls.TypeName) + '.' + str(method.Name)[4:]] = literal
                        elif str(method.Name) == '.cctor':
                            for field, literal in literal_image_fields(pe, method).items():
                                values[str(cls.TypeName) + '.' + field] = literal
                getters[candidate] = values
                pe.close()
            if member in getters[candidate]:
                return getters[candidate][member]
        return None

    def raw_page(source):
        key = (source['file'], source['resource'])
        if key not in baml_cache:
            pe = dnfile.dnPE(str(root / source['file']), clr_lazy_load=True)
            result = []
            for row in pe.net.mdtables.ManifestResource.rows:
                if row.Implementation is not None and row.Implementation.row:
                    continue
                addr = pe.net.struct.ResourcesRva + row.Offset
                size = struct.unpack('<I', pe.get_data(addr, 4))[0]
                for name, value, _ in managed_entries(pe.get_data(addr + 4, size)):
                    if name == source['resource'] and isinstance(value, bytes):
                        result = parse_baml(value, known)['nodes']
            pe.close()
            baml_cache[key] = result
        return baml_cache[key]

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
        candidates = [resource.lower(), 'images/' + resource.lower().split('/')[-1]]
        if '/images/' in resource.lower():
            candidates.append('images/' + resource.lower().split('/images/', 1)[1])
        match = None
        for alternative in assembly_files(relative):
            resources = entries(alternative)
            match = next((resources[x] for x in candidates if x in resources), None)
            if match:
                relative = alternative
                break
        if not match:
            # A few forms reference a shared image without an assembly URI.
            # Accept only an exact resource name already recovered with one hash.
            shared = [a for a in assets.values() if a['resource'].lower() in candidates]
            if len(shared) == 1:
                references[key] = shared[0]['file']
                return True
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
                    if prop == 'Source' and node['type'] not in ('Image', 'ImageButton', 'AutoDisabledImage', 'ImageBrush', 'BitmapImage', 'Binding'):
                        non_images.append({'key':key, 'type':node['type']})
                        continue
                    if node['type'] == 'Binding':
                        if node['slot'] not in ('Source', 'SmallImage', 'LargeImage', 'ImageSource'):
                            non_images.append({'key':key, 'type':node['type'], 'slot':node['slot']})
                            continue
                        key = page['id'] + ':' + str(node['parent']) + ':' + node['slot']
                    relative = source['file']
                    original = value
                    if isinstance(value, dict) and value.get('extension') == 'StaticExtension':
                        value = member_resource(relative, value['member'])
                        if value is None:
                            props = raw_page(source)[n]['properties']
                            detail = next((v for k,v in props.items() if k.split('.')[-1] == prop), {})
                            if detail.get('assembly'):
                                relative = detail['assembly'] + '.dll'
                                value = member_resource(relative, detail['member'])
                                original = detail
                    elif isinstance(value, dict) and value.get('extension') == 'StaticResourceExtension':
                        raw = raw_page(source)
                        props = raw[n]['properties'] if n < len(raw) else {}
                        detail = next((v for k,v in props.items() if k.split('.')[-1] == prop), {})
                        original = detail or original
                        value = None
                        if node['type'] == 'Binding' and any(x['type'] == 'AspenTech.Visualisation.CommonImages.CommonImages' for x in raw):
                            relative = common
                            value = member_resource(relative, 'CommonImages.' + node['p'].get('Path', ''))
                    if not isinstance(value, str):
                        unresolved.append({'key': key, 'reference': original, 'reason': 'No literal raster resource path'})
                        continue
                    resource = value.replace('\\', '/')
                    if ';component/' in resource:
                        assembly, resource = resource.split(';component/', 1)
                        assembly = assembly.rsplit('/', 1)[-1]
                        relative = str(Path(relative).parent / (assembly + '.dll')).replace('\\', '/')
                    else:
                        resource = posixpath.normpath(posixpath.join(posixpath.dirname(source['resource']), resource))
                    if not add(key, relative, resource):
                        unresolved.append({'key': key, 'reference': original, 'resolvedPath': value,
                                           'reason': 'Referenced raster not found in owning assembly resources'})
    manifest = {'schemaVersion': 1, 'assets': list(assets.values()), 'references': references,
                'unresolved': unresolved, 'nonImageSources': non_images}
    (output / 'recovered.json').write_text(json.dumps(manifest, ensure_ascii=False, indent=2) + '\n', encoding='utf-8', newline='\n')
    print(f'{len(assets)} assets, {len(references)} references, {len(unresolved)} unresolved')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--catalog', type=Path, default=Path('ui/recovered'))
    parser.add_argument('--output', type=Path, default=Path('ui/icons'))
    args = parser.parse_args()
    recover(args.root, args.catalog, args.output)
