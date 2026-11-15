"""Read installed UI resources without executing Aspen code. Raw inputs stay local.

Requires pefile and dnfile. See docs/ui-resource-recovery.md for scope and limits.
"""
from __future__ import annotations

import argparse
from collections import Counter
import hashlib
import json
import logging
from pathlib import Path
import struct

import dnfile
import pefile


class Reader:
    def __init__(self, data):
        self.data, self.pos = data, 0

    def take(self, n):
        if n < 0 or self.pos + n > len(self.data):
            raise ValueError(f'Truncated resource at {self.pos}, requested {n}')
        value = self.data[self.pos:self.pos+n]
        self.pos += n
        return value

    def unpack(self, fmt):
        return struct.unpack('<'+fmt, self.take(struct.calcsize('<'+fmt)))

    def integer(self):
        value = 0
        for shift in range(0, 35, 7):
            b = self.take(1)[0]
            value |= (b & 127) << shift
            if b < 128:
                return value
        raise ValueError('Invalid 7-bit integer')

    def string(self):
        return self.take(self.integer()).decode('utf-8')

    def wide(self):
        units = bytearray()
        while True:
            pair = self.take(2)
            if pair == b'\0\0':
                return units.decode('utf-16-le')
            units.extend(pair)

    def ordinal(self):
        start = self.pos
        value, = self.unpack('H')
        if value == 0xffff:
            return {'ordinal': self.unpack('H')[0]}
        self.pos = start
        return self.wide()

    def align(self, n=4):
        self.take((-self.pos) % n)


# Fixed payload sizes in Microsoft's BamlRecords.cs; other supported records
# carry a 7-bit size including the size field, excluding the record type.
FIXED = {1:6, 2:0, 3:3, 4:0, 7:2, 8:0, 9:2, 10:0, 11:2, 12:0,
         13:2, 14:0, 26:0, 33:4, 34:4, 35:6, 37:4, 39:9, 40:9,
         41:0, 42:0, 43:0, 44:2, 45:4, 46:2, 48:3, 49:0, 50:2,
         53:8, 54:4, 55:3, 56:4}
VARIABLE = {5, 6, 15, 16, 17, 18, 20, 25, 27, 28, 29, 30, 31, 32, 36, 38, 51, 52}


def parse_baml(data, known):
    r = Reader(data)
    if r.take(r.unpack('I')[0]).decode('utf-16-le') != 'MSBAML':
        raise ValueError('Not an MSBAML stream')
    r.take(12)
    types, attrs, strings = {}, {}, {}
    assemblies, type_assemblies, attr_owners = {}, {}, {}
    nodes, stack, contexts, records = [], [], [], Counter()
    def typename(i):
        return types.get(i, known['types'].get(str(-i), f'type#{i}'))
    def attrname(i):
        return attrs.get(i, known['properties'].get(str(-i), f'property#{i}'))
    def prop(key, value):
        if stack:
            nodes[stack[-1]]['properties'][key] = value
    ended = False
    while r.pos < len(data):
        offset = r.pos
        kind = r.take(1)[0]
        records[kind] += 1
        if kind in FIXED:
            payload = r.take(FIXED[kind])
        elif kind in VARIABLE:
            start = r.pos
            size = r.integer()
            payload = r.take(size - (r.pos-start))
        else:
            raise ValueError(f'Unsupported BAML record {kind} at {offset}')
        p = Reader(payload)
        if kind == 28:
            aid, = p.unpack('h'); assemblies[aid] = p.string().split(',')[0]
        elif kind in (29, 30):
            tid, aid = p.unpack('hh'); types[tid] = p.string(); type_assemblies[tid] = aid & 0xfff
        elif kind == 31:
            aid, owner, _ = p.unpack('hhB'); attrs[aid] = typename(owner).split('.')[-1]+'.'+p.string()
            attr_owners[aid] = owner
        elif kind == 32:
            sid, = p.unpack('h'); strings[sid] = p.string()
        elif kind in (3, 48, 40):
            tid, = p.unpack('h')
            node = {'type': typename(tid), 'parent': stack[-1] if stack else -1,
                    'slot': contexts[-1][1] if contexts and contexts[-1][0] == len(stack) else '',
                    'properties': {}, 'offset': offset}
            nodes.append(node); stack.append(len(nodes)-1)
        elif kind in (4, 49, 41):
            if not stack:
                raise ValueError('Unbalanced element end')
            stack.pop()
        elif kind in (7, 9, 11, 13):
            contexts.append((len(stack), attrname(p.unpack('h')[0])))
        elif kind in (8, 10, 12, 14):
            if not contexts:
                raise ValueError('Unbalanced property end')
            contexts.pop()
        elif kind in (5, 36):
            key = attrname(p.unpack('h')[0]); prop(key, p.string())
        elif kind == 6:
            aid, serializer = p.unpack('hh'); raw = p.take(len(payload)-4)
            name = known['types'].get(str(serializer & 0x3fff), str(serializer))
            value = {'serializer': name, 'hex': raw.hex()}
            if name == 'BooleanConverter' and len(raw) == 1:
                value = bool(raw[0])
            elif name == 'EnumConverter' and len(raw) == 4:
                value = {'enum': struct.unpack('<I', raw)[0]}
            prop(attrname(aid), value)
        elif kind == 35:
            aid, flags, value = p.unpack('hHh')
            prop(attrname(aid), {'extension': typename(-(flags & 0xfff)),
                                'valueId': value, 'flags': flags})
        elif kind in (16, 17):
            prop('$text', p.string())
        elif kind == 51:
            prop('$text', strings.get(p.unpack('h')[0], ''))
        elif kind == 25:
            value = p.string(); aid, = p.unpack('h'); prop({-1:'x:Name', -2:'x:Uid'}.get(aid, strings.get(aid, f'x:attribute#{aid}')), value)
        elif kind in (33, 34):
            aid, value = p.unpack('hh'); prop(attrname(aid), strings.get(value, '') if kind == 33 else {'type': typename(value)})
        elif kind == 45:
            prop('$connectionId', p.unpack('I')[0])
        elif kind == 2:
            ended = True
    if stack or contexts or not ended:
        raise ValueError('Incomplete BAML document')
    # Resolve x:Static members, particularly Aspen's localized captions.
    for node in nodes:
        for key, value in list(node['properties'].items()):
            if isinstance(value, dict) and value.get('extension') == 'StaticExtension':
                value['member'] = attrname(value['valueId'])
                owner = attr_owners.get(value['valueId'])
                if owner is not None:
                    value['declaringType'] = typename(owner)
                    if type_assemblies.get(owner) in assemblies:
                        value['assembly'] = assemblies[type_assemblies[owner]]
            elif isinstance(value, dict) and value.get('extension') in ('StaticResourceExtension', 'DynamicResourceExtension'):
                if value['flags'] & 0x4000:
                    value['type'] = typename(value['valueId'])
                elif value['flags'] & 0x2000:
                    value['member'] = attrname(value['valueId'])
                elif value['valueId'] in strings:
                    value['key'] = strings[value['valueId']]
    return {'nodes': nodes, 'recordTypes': dict(records)}


def parse_dialog(data):
    r = Reader(data)
    extended = data[:4] == b'\x01\x00\xff\xff'
    if extended:
        _, _, help_id, ex_style, style, count = r.unpack('HHIIIH')
    else:
        style, ex_style, count = r.unpack('IIH'); help_id = 0
    rect = list(r.unpack('hhhh'))
    menu, cls, title = r.ordinal(), r.ordinal(), r.wide()
    font = None
    if style & 0x40:
        point, = r.unpack('H')
        weight, italic, charset = r.unpack('HBB') if extended else (400, 0, 1)
        font = {'point':point, 'weight':weight, 'italic':italic, 'charset':charset, 'face':r.wide()}
    controls = []
    classes = {0x80:'Button', 0x81:'Edit', 0x82:'Static', 0x83:'ListBox', 0x84:'ScrollBar', 0x85:'ComboBox'}
    for _ in range(count):
        r.align()
        if extended:
            help_id, ex, flags = r.unpack('III')
            box = list(r.unpack('hhhh')); cid, = r.unpack('I')
        else:
            flags, ex = r.unpack('II'); box = list(r.unpack('hhhh')); cid, = r.unpack('H')
        cls, text = r.ordinal(), r.ordinal()
        if isinstance(cls, dict): cls = classes.get(cls['ordinal'], str(cls))
        extra, = r.unpack('H')
        if extra:
            if extended:
                r.align()
                r.take(extra)
            else:
                r.take(extra-2)  # Standard creation-data size includes its WORD.
        controls.append({'id':cid, 'type':cls, 'text':text, 'rect':box, 'style':flags, 'exStyle':ex})
    return {'title':title, 'rect':rect, 'font':font, 'style':style, 'menu':menu, 'controls':controls}


def parse_menu(data):
    r = Reader(data); version, offset = r.unpack('HH'); r.pos = 4+offset
    if version not in (0, 1): raise ValueError(f'Unsupported menu version {version}')
    def items(depth=0):
        if depth > 64: raise ValueError('Menu nesting too deep')
        result = []
        while True:
            if version == 1:
                r.align(); typ, state, cid, flags = r.unpack('IIIH'); text = r.wide(); r.align(); popup = flags & 1
                if popup: r.take(4)
            else:
                flags, = r.unpack('H'); popup = flags & 0x10
                cid = 0 if popup else r.unpack('H')[0]
                text = r.wide(); typ, state = flags, flags
            item = {'id':cid, 'text':text, 'flags':flags, 'state':state, 'type':typ}
            if popup: item['items'] = items(depth+1)
            result.append(item)
            if flags & 0x80: return result
    return {'version':version, 'items':items()}


def managed_entries(data):
    """Read ResourceSet v2 strings/streams by offsets; never deserialize objects.

    Name lengths are UTF-16 byte lengths; value strings use UTF-8 byte lengths.
    Unsupported serialized objects are inventoried, not instantiated.
    """
    r=Reader(data)
    magic, manager_version, header_size=r.unpack('III')
    if magic != 0xbeefcace: return
    r.take(header_size)
    version, count, type_count=r.unpack('III')
    if version != 2: raise ValueError(f'Unsupported ResourceSet version {version}')
    if count > len(data)//8 or type_count > len(data): raise ValueError('Invalid ResourceSet count')
    for _ in range(type_count): r.string()
    r.align(8); r.take(4*count)
    positions=r.unpack('I'*count)
    section,=r.unpack('I'); names=r.pos
    for position in positions:
        r.pos=names+position
        name=r.take(r.integer()).decode('utf-16-le')
        offset,=r.unpack('I'); r.pos=section+offset
        kind=r.integer(); value=None
        if kind==1: value=r.string()
        elif kind in (32,33): value=r.take(r.unpack('I')[0])
        yield name,value,kind


def sha(data):
    return hashlib.sha256(data).hexdigest()


def dump(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, ensure_ascii=False, separators=(',', ':'))+'\n', encoding='utf-8', newline='\n')


def scan(root, output, known, retry=False):
    roots = ['Aspen Plus V15.0', 'AprSystem V15.0', 'Aspen Properties V15.0']
    inventory, layouts, dialogs, menus, resources, strings, errors = [], [], [], [], [], [], []
    targets=None
    if retry:
        def previous(name): return json.loads((output/(name+'.json')).read_text(encoding='utf-8'))
        targets={e['file'] for e in previous('errors')} | {e['file'] for e in previous('dialogs')}
        inventory=[e for e in previous('files') if e['path'] not in targets]
        layouts, dialogs, menus, resources, strings, errors = [[e for e in previous(n) if e['file'] not in targets] for n in ('layouts','dialogs','menus','resources','strings','errors')]
    files = sorted(p for name in roots for p in (root/name).rglob('*') if p.is_file())
    for index, path in enumerate(files):
        relative = path.relative_to(root).as_posix()
        if targets is not None and relative not in targets: continue
        item = {'path':relative, 'size':path.stat().st_size}
        inventory.append(item)
        if path.suffix.lower() not in ('.exe', '.dll', '.ocx'): continue
        data = path.read_bytes(); item['sha256'] = sha(data)
        try:
            pe = pefile.PE(data=data, fast_load=True)
            pe.parse_data_directories(directories=[pefile.DIRECTORY_ENTRY['IMAGE_DIRECTORY_ENTRY_RESOURCE']])
            for typ in getattr(pe, 'DIRECTORY_ENTRY_RESOURCE', type('Empty', (), {'entries':[]})()).entries:
                for name in typ.directory.entries:
                    for lang in name.directory.entries:
                        d = lang.data.struct; payload = pe.get_data(d.OffsetToData, d.Size)
                        source = {'file':relative, 'resource':str(name.name or name.id), 'language':lang.id,
                                  'type':str(typ.name or typ.id), 'size':len(payload), 'sha256':sha(payload)}
                        resources.append(source)
                        try:
                            if typ.id == 5: dialogs.append({**source, **parse_dialog(payload)})
                            if typ.id == 4: menus.append({**source, **parse_menu(payload)})
                        except (ValueError, UnicodeError, struct.error) as exc:
                            errors.append({**source, 'error':str(exc)})
            clr = pe.OPTIONAL_HEADER.DATA_DIRECTORY[14]
            if clr.VirtualAddress:
                managed = dnfile.dnPE(data=data, clr_lazy_load=True)
                table = managed.net.mdtables.ManifestResource
                if table:
                    for row in table.rows:
                        if row.Implementation is not None and row.Implementation.row: continue
                        addr = managed.net.struct.ResourcesRva + row.Offset
                        size = struct.unpack('<I', managed.get_data(addr, 4))[0]
                        raw = managed.get_data(addr+4, size)
                        for name, val, kind in managed_entries(raw):
                            source = {'file':relative, 'container':str(row.Name), 'resource':name,
                                      'valueType':kind,
                                      'size':len(val) if isinstance(val,(str,bytes)) else 0}
                            if isinstance(val, bytes): source['sha256'] = sha(val)
                            resources.append(source)
                            if isinstance(val, str): strings.append({**source, 'value':val})
                            if isinstance(val, bytes) and name.lower().endswith('.baml'):
                                try: layouts.append({**source, **parse_baml(val, known)})
                                except (ValueError, UnicodeError, struct.error) as exc: errors.append({**source, 'error':str(exc)})
                managed.close()
            pe.close()
        except Exception as exc:
            errors.append({'file':relative, 'error':type(exc).__name__+': '+str(exc)})
        if index % 100 == 0: print(f'{index}/{len(files)} files; {len(layouts)} layouts', flush=True)
    inventory.sort(key=lambda x:x['path'])
    for values in (layouts,dialogs,menus,resources,strings,errors):
        values.sort(key=lambda x:(x['file'],x.get('container',''),str(x.get('type','')),str(x.get('resource','')),x.get('language',0)))
    for name, value in [('files',inventory),('resources',resources),('layouts',layouts),('dialogs',dialogs),('menus',menus),('strings',strings),('errors',errors)]:
        dump(output/(name+'.json'),value)
    summary = {'schemaVersion':1, 'roots':roots, 'files':len(files), 'peFiles':sum('sha256' in x for x in inventory),
               'resources':len(resources), 'bamlLayouts':len(layouts), 'nativeDialogs':len(dialogs),
               'nativeMenus':len(menus), 'strings':len(strings), 'errors':len(errors),
               'inputPolicy':'Installed files read only; no application code loaded or executed.'}
    dump(output/'summary.json', summary)
    print(json.dumps(summary, ensure_ascii=False))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--known', type=Path, default=Path(__file__).with_name('baml_known.json'))
    parser.add_argument('--retry-errors', action='store_true', help='Re-read failed files and native dialogs using the existing inventory')
    args = parser.parse_args()
    logging.disable(logging.CRITICAL)
    scan(args.root, args.output, json.loads(args.known.read_text(encoding='utf-8')), args.retry_errors)
