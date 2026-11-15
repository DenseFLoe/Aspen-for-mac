"""Enumerate all recovered controls and every menu path, without executing Aspen.

This is a coverage inventory, never a claim that static commands are implemented.
Raw installed assemblies and database assets are not copied into the report.
"""
import argparse
from collections import Counter
import json
from pathlib import Path


def audit(root):
    def read(name):
        return json.loads((root / name).read_text(encoding='utf-8'))
    index=read('index.json')
    controls=[]
    for module in index['modules']:
        for page in read(module['file'])['pages']:
            for i,node in enumerate(page['nodes']):
                kind=node['type']; p=node['p']
                if not any(k in kind for k in ('Button','MenuItem','Combo','ListPicker','ListBox','DataGrid')):
                    continue
                controls.append({'module':module['id'],'page':page['id'],'form':page['name'],
                                 'node':i,'type':kind,'name':p.get('Name',''),
                                 'label':p.get('Content',p.get('Header',p.get('Caption',''))),
                                 'command':p.get('Command'), 'binding':p.get('VariablePath'),
                                 'status':'static-resource-only'})
    paths=[]
    def walk(items,menu,path=()):
        for ordinal,item in enumerate(items):
            current=path+(ordinal,)
            paths.append({'menu':menu,'path':list(current),'depth':len(current),**item})
            paths[-1].pop('items',None)
            walk(item.get('items',[]),menu,current)
    menus=read('menus.json')
    for i,menu in enumerate(menus): walk(menu['items'],i)
    return {'summary':{'modules':len(index['modules']),'layouts':len(index['pages']),
                       'controls':len(controls),'menuResources':len(menus),'menuNodes':len(paths),
                       'maxMenuDepth':max((p['depth'] for p in paths),default=0),
                       'iconOnlyCommands':sum(p.get('separator') is False and not p['text'] for p in paths),
                       'controlTypes':dict(Counter(c['type'] for c in controls))},
            'controls':controls,'menuPaths':paths}


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--catalog',type=Path,default=Path('ui/recovered'))
    parser.add_argument('--output',type=Path,required=True)
    args=parser.parse_args(); result=audit(args.catalog)
    args.output.parent.mkdir(parents=True,exist_ok=True)
    args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result['summary'],ensure_ascii=False))
