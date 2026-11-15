"""Build a portable, caption-resolved UI catalog from scan_aspen_ui output."""
from __future__ import annotations
import argparse
from collections import Counter, defaultdict
import hashlib
import json
from pathlib import Path
import re

from scan_aspen_ui import dump

MODULE_LABELS = {
    'Components':'组分', 'Setup':'设置', 'Properties':'物性方法',
    'Methods':'方法', 'PropAnalysis':'物性分析', 'Streams':'物流',
    'Reactions':'反应', 'Convergence':'收敛', 'Utility':'实用工具',
    'Results_Summary':'结果摘要', 'Flowsheeting_Options':'流程选项',
    'APropSetup':'物性设置', 'Pure_Databanks':'纯组分数据库',
    'Estimation':'物性估算', 'Regression':'数据回归',
    'Blocks':'单元操作', 'DynOptions':'动态选项', 'PlotForms':'绘图',
}


def load(folder, name):
    return json.loads((folder/(name+'.json')).read_text(encoding='utf-8'))


def rank(file):
    file = file.lower()
    return 3 if '/zh-hans/' in file else 2 if '/en-us/' in file else 0 if '/ru-ru/' in file or '/ja-jp/' in file else 1


def select_layouts(layouts):
    """Include product dialogs/controls outside WPFForms, excluding vendor templates.

    Prefer the existing WPFForms copy at equal language priority so stable page
    identities and source-node image references do not change unnecessarily.
    """
    selected = {}
    def priority(layout):
        return (rank(layout['file']), '/WPFForms/' in layout['file'])
    for layout in layouts:
        if not layout['nodes']:
            continue
        cls = layout['nodes'][0]['type']
        if not cls.startswith('AspenTech.AspenPlus.'):
            continue
        if cls not in selected or priority(layout) > priority(selected[cls]):
            selected[cls] = layout
    return selected


def build(source, target):
    files = {x['path']:x for x in load(source,'files')}
    translations, priorities = {}, {}
    for entry in load(source, 'strings'):
        parts = entry['container'].split('.')
        cls = parts[-3] if len(parts) > 2 and ('-' in parts[-2] or parts[-2].lower() in ('en','zh','ja','ru')) else parts[-2]
        key = cls+'.'+entry['resource']
        priority = rank(entry['file'])
        if key not in translations or priority > priorities[key]:
            translations[key], priorities[key] = entry['value'], priority
    # Strongly typed resource properties sanitize punctuation (e.g. Step2-2 ->
    # Step2_2). Accept an alias only when it identifies exactly one raw key.
    candidates=defaultdict(set)
    for key in translations:
        cls, member=key.split('.',1)
        candidates[cls+'.'+re.sub(r'[^\w]', '_', member)].add(key)
    aliases={k:next(iter(v)) for k,v in candidates.items() if len(v)==1 and k not in translations}
    layouts = load(source, 'layouts')
    selected = select_layouts(layouts)
    pages, types, buttons, unresolved, sources, wpf_menus = [], {}, [], [], {}, []
    grouped = defaultdict(list)
    for cls, layout in sorted(selected.items()):
        module = Path(layout['file']).name.replace('.resources.dll','').replace('AspenTech.AspenPlus.','').replace('MMForms.','')
        page_id = hashlib.sha256(cls.encode()).hexdigest()[:16]
        types[cls] = page_id
        nodes, refs = [], set()
        for number, node in enumerate(layout['nodes']):
            props = {}
            for key, value in node['properties'].items():
                key = key.split('.')[-1]
                if key.startswith('$') or key in ('x:Uid','HelpFile','HelpId'): continue
                if isinstance(value,dict) and value.get('extension') == 'StaticExtension':
                    member = value['member']; refs.add(member)
                    actual=aliases.get(member,member)
                    if actual in translations: value = translations[actual]
                    else: unresolved.append({'page':page_id, 'node':number, 'property':key, 'member':member})
                props[key] = value
            simple = {'type':node['type'].split('.')[-1], 'parent':node['parent'], 'slot':node['slot'].split('.')[-1], 'p':props}
            nodes.append(simple)
            if any(x in simple['type'] for x in ('Button','MenuItem')):
                buttons.append({'page':page_id, 'node':number, 'type':simple['type'],
                                'name':props.get('Name',''), 'label':props.get('Content',props.get('Header',props.get('Caption',''))),
                                'runtimeBinding':props.get('VariablePath','')})
        def menu_items(parent):
            result=[]
            for i,n in enumerate(nodes):
                if n['parent']!=parent: continue
                if n['type'] in ('MenuItem','ToolMenuItem','MenuTool','ButtonTool','Separator'):
                    p=n['p']; text=p.get('Header',p.get('Caption',p.get('Content','')))
                    item={'id':i,'text':text if isinstance(text,str) else '',
                          'state':3 if p.get('IsEnabled') is False else 0,'type':0,'flags':0}
                    children=menu_items(i)
                    if children: item['items']=children
                    result.append(item)
                elif n['slot'] not in ('Resources','Style','Template'):
                    result.extend(menu_items(i))
            return result
        for i,n in enumerate(nodes):
            if n['type'] not in ('ContextMenu','MenuTool','Menu'): continue
            items=menu_items(i)
            if items:
                wpf_menus.append({'file':layout['file'],'resource':layout['resource']+'#'+str(i),
                                  'title':n['p'].get('Caption',n['p'].get('Name','')),'language':0,
                                  'format':'BAML','page':page_id,'sha256':layout['sha256'],'items':items})
        short = cls.split('.')[-1]
        header = next((n['p'].get('Header') for n in nodes if n['type'] == 'MMTabItem' and isinstance(n['p'].get('Header'),str)), '')
        caption = nodes[0]['p'].get('Title') or translations.get('ApwnResources.'+short+'_MMFHeader0') or header
        if not isinstance(caption,str): caption = ''
        title = caption or short
        kind = 'tab-container' if any(n['type']=='MMTabItem' for n in nodes) else 'layout'
        page = {'id':page_id, 'type':cls, 'module':module, 'title':title, 'name':short,
                'kind':kind,
                'search':' '.join(sorted({v for n in nodes for k,v in n['p'].items() if k in ('Content','Header','Text','Title','Label','Caption') and isinstance(v,str)})),
                'source':{'file':layout['file'], 'resource':layout['resource'], 'sha256':layout['sha256']}, 'nodes':nodes}
        grouped[module].append(page)
        pages.append({k:page[k] for k in ('id','type','module','title','name','source','search','kind')})
        sources[layout['file']] = files[layout['file']]['sha256']
    module_index = []
    for module, values in sorted(grouped.items()):
        file = re.sub(r'[^a-zA-Z0-9_.-]', '_', module)+'.json'
        dump(target/file, {'pages':values})
        module_index.append({'id':module, 'label':MODULE_LABELS.get(module,module), 'file':file, 'pages':len(values)})
    native_menus = load(source,'menus')
    native_dialogs = load(source,'dialogs')
    # Every decoded native resource remains in the inventory, with its language id.
    dump(target/'native-menus.json', native_menus)
    dump(target/'menus.json', native_menus+wpf_menus)
    dump(target/'native-dialogs.json', native_dialogs)
    dump(target/'index.json', {'schemaVersion':1, 'modules':module_index, 'pages':pages, 'types':types})
    dump(target/'buttons.json', buttons)
    dump(target/'unresolved.json', unresolved)
    dump(target/'sources.json', sources)
    summary = load(source,'summary')
    summary.update({'portablePages':len(pages), 'portableModules':len(grouped), 'pageButtons':len(buttons),
                    'unresolvedStaticReferences':len(unresolved),
                    'unresolvedCaptions':sum(x['property'] in ('Content','Header','Text','Title','Label','Caption') for x in unresolved),
                    'wpfMenus':len(wpf_menus),
                    'tabContainers':sum(p['kind']=='tab-container' for p in pages),
                    'pageNodes':sum(len(p['nodes']) for g in grouped.values() for p in g)})
    dump(target/'summary.json', summary)
    # Resource names and hashes, not binary contents, make scanning auditable.
    dump(target/'scan-errors.json', load(source,'errors'))
    dump(target/'scan-files.json', list(files.values()))
    print(json.dumps(summary, ensure_ascii=False))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--scan', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    build(args.scan, args.output)
