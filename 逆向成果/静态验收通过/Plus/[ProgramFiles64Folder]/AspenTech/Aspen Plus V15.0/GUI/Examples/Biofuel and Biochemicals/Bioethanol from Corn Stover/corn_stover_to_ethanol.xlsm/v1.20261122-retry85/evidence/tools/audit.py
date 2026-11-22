
from hashlib import sha256
from pathlib import Path
from io import BytesIO
from zipfile import ZipFile
from collections import Counter
from xml.etree import ElementTree as ET
import json, re, sys
from olefile import OleFileIO
from oletools.olevba import VBA_Project, decompress_stream

item = Path(sys.argv[1])
work = item / 'work'
src = item / 'input/corn_stover_to_ethanol.xlsm'
raw = src.read_bytes()
assert sha256(raw).hexdigest() == item.name

def digest(data):
    return sha256(data).hexdigest()

with ZipFile(BytesIO(raw)) as archive:
    assert archive.testzip() is None
    assert len(archive.namelist()) == len(set(archive.namelist()))
    parts = {n: archive.read(n) for n in archive.namelist()}
vba = parts['xl/vbaProject.bin']
ole = OleFileIO(BytesIO(vba))
project = VBA_Project(ole, '', 'PROJECT', 'VBA/dir', relaxed=False)
project.parse_project_stream()
list(project.parse_modules())
assert len(project.modules) == project.modules_count
project_text = ole.openstream('PROJECT').read().decode(project.codec)
pcode = (work / 'pcode.txt').read_text(encoding='utf-8-sig')
pcode_sections = dict((name, text) for name, text in re.findall(
    r'^VBA/([^ \r\n]+) - \d+ bytes\n(.*?)(?=^VBA/|\Z)', pcode, re.M | re.S))
assert set(pcode_sections) == {m.streamname for m in project.modules}
export = work / 'modules'
export.mkdir(exist_ok=True)
module_results = []
for m in project.modules:
    data = ole.openstream(m.code_path).read()
    source = decompress_stream(bytearray(data[m.textoffset:]))
    assert source == m.code_raw
    decoded = source.decode(project.codec)
    assert decoded.encode(project.codec) == source
    name = m.filename
    assert Path(name).name == name
    (export / name).write_bytes(source)
    source_procs = re.findall(
        r'^\s*(?:(?:Public|Private|Friend|Static)\s+)*(?:Sub|Function|Property (?:Get|Let|Set))\s+(\w+)\s*\(',
        decoded, re.M | re.I)
    block = pcode_sections[m.streamname]
    code_procs = re.findall(
        r'FuncDefn \((?:(?:Public|Private|Friend|Static)\s+)*(?:Sub|Function|Property (?:Get|Let|Set))\s+(\w+)\s*\(',
        block, re.I)
    assert source_procs == code_procs, (m.name, source_procs, code_procs)
    module_results.append(dict(name=m.name, stream=m.code_path, text_offset=m.textoffset,
                               file=name, size=len(source), sha256=digest(source), procedures=source_procs,
                               pcode_lines=len(re.findall(r'^Line #', block, re.M))))
rel = '{http://schemas.openxmlformats.org/officeDocument/2006/relationships}'
main = '{http://schemas.openxmlformats.org/spreadsheetml/2006/main}'
def xml(name):
    return ET.fromstring(parts[name])

relationships = []
import posixpath
from urllib.parse import unquote
for name in parts:
    if not name.endswith('.rels'):
        continue
    folder = posixpath.dirname(posixpath.dirname(name))
    ids = set()
    for el in xml(name):
        data = el.attrib
        assert data['Id'] not in ids
        ids.add(data['Id'])
        external = data.get('TargetMode') == 'External'
        target = unquote(data['Target'])
        resolved = None
        if not external:
            resolved = posixpath.normpath(posixpath.join(folder, target)).lstrip('/')
            assert resolved in parts, (name, data['Id'])
        relationships.append(dict(rels=name, id=data['Id'], type=data['Type'].split('/')[-1],
                                  target=resolved, external=external))
workbook = xml('xl/workbook.xml')
wr = {r['id']: r['target'] for r in relationships if r['rels'] == 'xl/_rels/workbook.xml.rels'}
sheets = []
for node in workbook.findall(f'{main}sheets/{main}sheet'):
    path = wr[node.get(rel+'id')]
    sheet = xml(path)
    prop = sheet.find(main+'sheetPr')
    sheets.append(dict(path=path, sheet_id=node.get('sheetId'), code_name=prop.get('codeName') if prop is not None else None,
                       formulas=len(sheet.findall('.//'+main+'f')),
                       controls=[el.attrib for el in sheet.iter() if el.tag.split('}')[-1] == 'control']))
assert {'ThisWorkbook', *(s['code_name'] for s in sheets)} <= {m.name for m in project.modules}
metadata = dict(parts=[dict(path=n, size=len(d), sha256=digest(d)) for n, d in parts.items()],
                relationships=relationships, sheets=sheets,
                vba=dict(encoding=project.codec, codepage=project.codepage, modules=module_results,
                         streams=[dict(path='/'.join(s), size=ole.get_size(s), sha256=digest(ole.openstream(s).read()))
                                  for s in ole.listdir()],
                         original_project_metadata_keys=[ln.split('=', 1)[0] for ln in project_text.splitlines()
                                                         if '=' in ln]))
(work / 'structure.json').write_text(json.dumps(metadata, indent=2), encoding='utf-8')
print('OPC parts:', len(parts), 'relationships:', len(relationships),
      'external:', sum(r['external'] for r in relationships), 'sheets:', len(sheets),
      'formulas:', sum(s['formulas'] for s in sheets))
print('VBA codepage:', project.codepage, 'streams:', len(ole.listdir()), 'modules:', project.modules_count)
for m in module_results:
    print(m['file'], m['size'], m['pcode_lines'], ', '.join(m['procedures']))
for s in sheets:
    if s['controls']:
        print(s['path'], s['code_name'], [(c.get('name'), c.get(rel+'id'), c.get('shapeId')) for c in s['controls']])
print('Project protection markers:', sorted(set(metadata['vba']['original_project_metadata_keys']) & {'CMG','DPB','GC'}))

