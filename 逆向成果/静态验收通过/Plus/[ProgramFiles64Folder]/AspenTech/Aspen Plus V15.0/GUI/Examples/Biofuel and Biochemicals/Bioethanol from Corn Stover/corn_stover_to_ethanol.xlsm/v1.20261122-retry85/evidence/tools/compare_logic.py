
from pathlib import Path
from collections import Counter
import json, re, struct, sys
w=Path(sys.argv[1])/'work'
p=(w/'pcode.txt').read_text(encoding='utf-8')
assert not re.search(r'Unrecognized opcode|error:',p,re.I)
paths=sorted((w/'modules').glob('*'))
ops_to_source = {
    'If':'if', 'IfBlock':'if', 'ElseIfBlock':'elseif', 'ElseBlock':'else', 'EndIfBlock':r'end\s+if',
    'For':'for', 'ForEach':r'for\s+each', 'NextVar':'next', 'ExitFor':r'exit\s+for', 'DoWhile':r'do\s+while',
    'Loop':'loop', 'EndSub':r'end\s+sub', 'ExitSub':r'exit\s+sub', 'OnError':r'on\s+error',
    'SelectCase':r'select\s+case', 'Case':'case', 'CaseElse':r'case\s+else', 'EndSelect':r'end\s+select',
    'With':'with', 'EndWith':r'end\s+with'
}
identifier_ops = set('ArgsCall ArgsLd ArgsMemCall ArgsMemLd ArgsMemSt Ld MemLd MemSt MemStWith St Set Label'.split())
str_pat = r'"(?:[^"]|"")*"'
evidence={}
for n,block in re.findall(r'^VBA/([^ \r\n]+) - \d+ bytes\n(.*?)(?=^VBA/|\Z)',p,re.M|re.S):
    f=next(f for f in paths if f.stem==n)
    rows=[(i,ln) for i,ln in enumerate(f.read_text(encoding='cp1252').splitlines(),1) if not ln.startswith('Attribute ')]
    pcs=dict((int(num), body) for num,body in re.findall(r'^Line #(\d+):\s*?\n(.*?)(?=^Line #|\Z)',block,re.M|re.S))
    if not pcs:
        assert not any(ln.strip() for _,ln in rows)
        continue
    assert set(pcs)==set(range(len(rows)))
    checks=Counter()
    claims=[]
    stack_order=[]
    mismatches=[]
    for idx,(physical,ln) in enumerate(rows):
        if ln.lstrip().startswith("'"):
            clean=''
            literals=[]
        else:
            clean=re.sub(str_pat, '""', ln)
            comment = clean.find("'")
            literal_with_positions=[m for m in re.finditer(str_pat + "|'",ln)]
            literals=[]
            for m in literal_with_positions:
                if m.group() == "'":
                    break
                literals.append(m.group()[1:-1].replace('""','"'))
            if comment!=-1:
                clean=clean[:comment]
        clean=clean.casefold().strip()
        body=pcs[idx]
        ops=[l.strip() for l in body.splitlines() if l.startswith('\t')]
        bc_str=[]
        bc_num=[]
        identifier_set=set(re.findall(r'\b\w+\b',clean))
        for op in ops:
            fields=op.split()
            name=fields[0]
            if name in identifier_ops:
                checks['identifier_operands']+=1
                if fields[1].casefold() not in identifier_set:
                    mismatches.append([physical,idx,name,fields[1]])
            if name in ops_to_source:
                checks['control_flow_ops']+=1
                if not re.search(r'\b'+ops_to_source[name]+r'\b',clean):
                    mismatches.append([physical,idx,name])
            if name=='LitStr':
                bc_str.append(re.fullmatch(r'LitStr \S+ "(.*)"',op)[1])
            if name=='LitDI2':
                bc_num.append(int(fields[1],16))
            if name=='LitR8':
                bc_num.append(struct.unpack('<d',struct.pack('<4H',*(int(word,16) for word in fields[1:])))[0])
        src_num=[float(lit) if '.' in lit else int(lit) for lit in re.findall(r'(?<![\w.])\d+(?:\.\d+)?(?![\w.])',clean)]
        checks['string_constants']+=len(bc_str)
        checks['numeric_constants']+=len(bc_num)
        if Counter(bc_str) != Counter(literals):
            mismatches.append([physical,idx,'string_literals'])
        if Counter(bc_num) != Counter(src_num):
            mismatches.append([physical,idx,'numeric_literals',bc_num,src_num])
        if bc_str != literals or bc_num != src_num:
            stack_order.append({'source_line':physical, 'pcode_line':idx, 'ops':ops})
        key = [op for op in ops if re.match(r'^(OnError|Label|ArgsCall|ArgsMemCall|LitR8)\b',op)]
        if key:
            claims.append({'source_line':physical,'pcode_line':idx,'ops':key})
    evidence[n]=dict(source_lines=len(rows), pcode_lines=len(pcs), checks=checks,
                     selected_operations=claims, stack_order=stack_order, mismatches=mismatches)
    print(n,dict(checks),'mismatches:',len(mismatches),mismatches[:25])
assert all(not item['mismatches'] for item in evidence.values())
(w/'logic-check.json').write_text(json.dumps(evidence,indent=2),encoding='utf-8')

