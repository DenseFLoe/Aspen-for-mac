"""Compare screenshot-backed shell labels with the recovered static inventory.

Matching text is evidence of overlap, not proof of command identity or behavior.
"""
import argparse
from collections import Counter
import json
from pathlib import Path
import re


def read(path): return json.loads(path.read_text(encoding='utf-8'))
def normalize(text): return re.sub(r'[&\s….:：。]', '',text).casefold()
def labels(value):
    if isinstance(value,dict):
        for k,v in value.items():
            if k in ('label','title') and isinstance(v,str): yield v
            else: yield from labels(v)
    elif isinstance(value,list):
        for v in value: yield from labels(v)


def compare(root):
    components=read(root/'ui/components.json'); shell=read(root/'ui/aspen-plus.json')
    recovered=root/'ui/recovered'; index=read(recovered/'index.json')
    known={normalize(s) for s in labels(components)}|{normalize(s) for s in labels(shell)}
    buttons=read(recovered/'buttons.json')
    missing=[b for b in buttons if isinstance(b['label'],str) and b['label'] and normalize(b['label']) not in known]
    result={'baseline':{'pages':len(components['pages']),'tabs':sum(len(p.get('tabs',[])) for p in components['pages']),
                        'ribbons':len(shell['ribbons'])},
            'recovered':{'layouts':len(index['pages']),'tabContainers':sum(p['kind']=='tab-container' for p in index['pages']),
                         'modules':len(index['modules']),'buttonOccurrences':len(buttons)},
            'comparisonRule':'Normalized exact caption overlap only; no claim of runtime command identity.',
            'additionalButtonCaptions':sorted({b['label'] for b in missing}),
            'additionalButtonOccurrences':len(missing),
            'modules':[{'module':m['id'],'layouts':m['pages'],'previousCoverage':'partial-screenshot-backed' if m['id']=='Components' else 'resource-navigation-added'} for m in index['modules']],
            'dynamicReview':[
                {'area':'Runtime values and lists','status':'not-connected','reason':'VariablePath, PropertyPath and DataProperty are runtime references, not stored values.'},
                {'area':'Conditional enablement / visibility','status':'not-verified','reason':'Static templates do not establish empty-case state.'},
                {'area':'Original program spot checks','status':'requires-live-check','reason':'Static comparison does not execute the original program; see the dated research record for actual checks.'}]}
    (recovered/'coverage.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:v for k,v in result.items() if k not in ('modules','additionalButtonCaptions')},ensure_ascii=False))


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__); p.add_argument('--root',type=Path,default=Path('.'))
    compare(p.parse_args().root)
