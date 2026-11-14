"""Validate all portable page links, source hashes, node trees and inventories."""
import argparse
from collections import Counter
import json
from pathlib import Path


def verify(root):
    def read(file): return json.loads((root/file).read_text(encoding='utf-8'))
    index, summary = read('index.json'), read('summary.json')
    ids, types = {}, {}
    node_types, bindings, missing_links = Counter(), [], []
    for module in index['modules']:
        pages = read(module['file'])['pages']
        assert len(pages) == module['pages'], module['id']
        for page in pages:
            assert page['id'] not in ids, page['id']
            ids[page['id']] = page
            types[page['type']] = page['id']
            assert len(page['source']['sha256']) == 64
            nodes=page['nodes']
            assert nodes and nodes[0]['parent']==-1, page['id']
            for i,n in enumerate(nodes):
                assert -1 <= n['parent'] < i, (page['id'],i)
                node_types[n['type']]+=1
                if 'VariablePath' in n['p']: bindings.append({'page':page['id'],'node':i,'path':n['p']['VariablePath']})
                assert not isinstance(n['p'].get('Content'),dict) or n['p']['Content'].get('extension') != 'StaticExtension', (page['id'],i,'unresolved content')
    assert set(ids)=={p['id'] for p in index['pages']}
    assert types==index['types']
    assert len(ids)==summary['portablePages']
    for page in ids.values():
        for n in page['nodes']:
            ref=n['p'].get('ContentType',{})
            if isinstance(ref,dict) and ref.get('type') and ref['type'] not in types:
                missing_links.append({'page':page['id'],'type':ref['type']})
    result={'pages':len(ids),'modules':len(index['modules']),'nodeTypes':dict(node_types.most_common()),
            'runtimeBindings':len(bindings),'missingContentTypes':missing_links,
            'nativeDialogs':len(read('native-dialogs.json')),'nativeMenus':len(read('native-menus.json')),'allMenus':len(read('menus.json'))}
    print(json.dumps({k:v if k not in ('nodeTypes','missingContentTypes') else len(v) for k,v in result.items()},ensure_ascii=False))
    return result


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__); p.add_argument('catalog',type=Path); p.add_argument('--report',type=Path)
    args=p.parse_args(); result=verify(args.catalog)
    if args.report: args.report.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
