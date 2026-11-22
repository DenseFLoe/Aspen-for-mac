
from hashlib import sha256
from io import BytesIO
from pathlib import Path, PurePosixPath
from xml.etree import ElementTree as ET
from zipfile import ZipFile, ZIP_DEFLATED
import json
import os
import re
import sys

item, destination = map(Path, sys.argv[1:])
if os.name == 'nt':
    destination = Path('\\\\?\\' + str(destination.resolve()))
work = item / 'work'
name = 'corn_stover_to_ethanol.xlsm'
original = item / 'input' / name
manifest = json.loads((work / 'structure.json').read_text(encoding='utf-8'))
signature = json.loads((work / 'sigcheck/signatures.json').read_text(encoding='utf-8'))
assert signature['workbook_sha256'] == item.name
assert len(signature['procedures']) == 5
macro = 'xl/vbaProject.bin'
with ZipFile(original) as archive:
    parts = {n: archive.read(n) for n in archive.namelist()}
assert len(parts) == 77
assert {r['path']: r['sha256'] for r in manifest['parts']} == {
    n: sha256(data).hexdigest() for n, data in parts.items()
}

def xml(n):
    return ET.fromstring(parts[n])

types = xml('[Content_Types].xml')
defaults = {el.get('Extension'): el.get('ContentType') for el in types if el.tag.endswith('}Default')}
overrides = {el.get('PartName').lstrip('/'): el.get('ContentType') for el in types if el.tag.endswith('}Override')}
rels = manifest['relationships']
assert all(not r['external'] for r in rels)
assert {r['target'] for r in rels} == {n for n in parts if not n.endswith('.rels') and n != '[Content_Types].xml'}
safe_name = re.compile(r'(?i)(?:password|passwd|passphrase|secret|authorization|api[-_ ]?key|access[-_ ]?token)')
for n, blob in parts.items():
    q = PurePosixPath(n)
    assert not q.is_absolute() and '..' not in q.parts
    if n != '[Content_Types].xml':
        assert n in overrides or q.suffix.lstrip('.') in defaults or q.name == '.rels'
    if n.endswith(('.xml', '.rels', '.vml')):
        xml(n)
        assert safe_name.search(blob.decode('utf-8')) is None, n
ms = '{http://schemas.openxmlformats.org/spreadsheetml/2006/main}'
od = '{http://schemas.openxmlformats.org/officeDocument/2006/relationships}'
ax = '{http://schemas.microsoft.com/office/2006/activeX}'
wb = xml('xl/workbook.xml')
assert wb.find(ms+'workbookPr').get('codeName') == 'ThisWorkbook'
assert len(manifest['sheets']) == 16
assert {s['code_name'] for s in manifest['sheets']} == {f'Sheet{i}' for i in range(1, 17)}
assert not any(s['formulas'] for s in manifest['sheets'])
assert not wb.findall('.//'+ms+'definedName')
relation_index = {(r['rels'], r['id']):r for r in rels}
binding_sheet = 'xl/worksheets/sheet1.xml'
binding_rels = 'xl/worksheets/_rels/sheet1.xml.rels'
sheet = xml(binding_sheet)
assert sheet.find(ms+'sheetPr').get('codeName') == 'Sheet3'
vlm = xml('xl/drawings/vmlDrawing1.vml')
shapes = {el.get('id'): el for el in vlm.iter() if el.tag.endswith('}shape')}
control_rows = []
expected_events = {'cmd_RunMEBTool_Click', 'cmd_UpdateFileName_Click'}
assert set(next(m['procedures'] for m in manifest['vba']['modules'] if m['name']=='Sheet3')) == expected_events
for control in sheet.iter(ms+'control'):
    pr = control.find(ms+'controlPr')
    if pr is None:
        continue
    name_ = control.get('name')
    target = relation_index[binding_rels, control.get(od+'id')]['target']
    root = xml(target)
    xp = PurePosixPath(target)
    root_rels = (xp.parent/'_rels'/(xp.name + '.rels')).as_posix()
    state = relation_index[root_rels, root.get(od+'id')]['target']
    image = relation_index[binding_rels, pr.get(od+'id')]['target']
    shape = shapes[name_]
    vml = {el.tag.split('}')[-1]:el.text for el in shape.iter()}
    cell = pr.get('linkedCell')
    cells = pr.get('listFillRange')
    assert cell == vml.get('FmlaLink') and cells == vml.get('FmlaRange')
    assert state in parts and image in parts
    event = None if cell else name_+'_Click'
    if event:
        assert event in expected_events
    control_rows.append(dict(name=name_, shape=control.get('shapeId'), rel_id=control.get(od+'id'),
                             definition=target, class_id=root.get(ax+'classid'), persistence=root.get(ax+'persistence'),
                             state=state, preview_image=image, linked_cell=cell, list_fill_range=cells, event=event))
assert len(control_rows) == 4
assert {ctl['class_id'] for ctl in control_rows} == {
    '{D7053240-CE69-11CD-A777-00DD01143C57}', '{8BD21D30-EC42-11CE-9E0D-00AA006002F3}'
}
(wb_map := work / 'controls.json').write_text(json.dumps(control_rows, indent=2), encoding='utf-8')
source_files = {m['file']: (work/'modules'/m['file']).read_bytes() for m in manifest['vba']['modules']}
assert len(source_files) == 19 and not any(safe_name.search(d.decode('cp1252')) for d in source_files.values())
assert {m['file']: m['sha256'] for m in manifest['vba']['modules']} == {
    n: sha256(data).hexdigest() for n, data in source_files.items()
}
for p in (work/'pcode.txt', work/'logic-check.json', work/'sigcheck/signatures.json'):
    assert safe_name.search(p.read_text(encoding='utf-8')) is None, p.name

deliveries = {
    'evidence/structure.json': work/'structure.json',
    'evidence/controls.json': wb_map,
    'evidence/pcode.txt': work/'pcode.txt',
    'evidence/logic-check.json': work/'logic-check.json',
    'evidence/signatures.json': work/'sigcheck/signatures.json',
    'evidence/tools/audit.py': work/'audit.py',
    'evidence/tools/compare_logic.py': work/'compare_logic.py',
    'evidence/tools/check_signatures.py': work/'sigcheck/check.py',
    'evidence/tools/package.py': Path(__file__),
}
editable = {n: b for n, b in parts.items() if n != macro}
staged = work / (name+'.source.zip')
with ZipFile(staged, 'w', ZIP_DEFLATED) as out:
    for n, data in sorted(editable.items()):
        out.writestr('workbook-parts/'+n, data)
    for n, data in sorted(source_files.items()):
        out.writestr('vba-src/'+n, data)
    for n, source in sorted(deliveries.items()):
        out.writestr(n, source.read_bytes())

with ZipFile(staged) as out:
    assert out.testzip() is None
    extracted = {n.removeprefix('workbook-parts/'): out.read(n) for n in out.namelist()
                 if n.startswith('workbook-parts/')}
    assert extracted == editable
    assert {n.removeprefix('vba-src/'):out.read(n) for n in out.namelist() if n.startswith('vba-src/')} == source_files
    for n, source in deliveries.items():
        assert out.read(n) == source.read_bytes()
rebuilt = BytesIO()
with ZipFile(rebuilt, 'w', ZIP_DEFLATED) as out:
    for n in parts:
        out.writestr(n, parts[macro] if n == macro else extracted[n])
with ZipFile(rebuilt) as out:
    assert out.testzip() is None
    assert set(out.namelist()) == set(parts)
    assert all(out.read(n) == data for n,data in parts.items())
print('OPC round-trip with original VBA: all 77 uncompressed parts byte-identical')
destination.mkdir(parents=True,exist_ok=True)
final = destination / staged.name
final.write_bytes(staged.read_bytes())
assert sha256(staged.read_bytes()).digest()==sha256(final.read_bytes()).digest()
print('Archive SHA-256:', sha256(final.read_bytes()).hexdigest())
print('Sources:', len(source_files), 'Workbook parts:',len(editable),'Evidence:',len(deliveries))

