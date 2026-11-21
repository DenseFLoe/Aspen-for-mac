import hashlib
from importlib.metadata import version
import json
from pathlib import Path
import platform
import struct
import sys

import dnfile

OUT=Path(__file__).resolve().parent
ROOT=OUT.parents[2]
PREV=ROOT/".local/reverse-round-20261119-04/startup-resources"
if not sys.dont_write_bytecode or not __debug__ or sys.argv[1:] not in ([],["--verify"]):
    raise SystemExit("Use python -B audit.py [--verify], without -O.")
sys.path.extend([str(ROOT/"tools"),str(PREV)])
from scan_aspen_ui import Reader
from native import version_tree,windows_resources
from baml import inspect
from trace import analyze,single

MAIN="AspenTech.AspenPlus.MMForms.Flowsheet"
MAIN_SHA="aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac"
SAT_SHA="d5edd484ef669276c47b41b867595027211ce07dd9da04147070eb481c09cab4"
REL=Path("AprSystem V15.0/GUI/Xeq/WPFForms")
HOME=Path("C:/Program Files/AspenTech")
FILE=REL/(MAIN+".dll")
SAT=REL/"en-US"/(MAIN+".resources.dll")
BASE=Path("materials")
artifacts=[]
pending={}


def sha(data):
    return hashlib.sha256(data).hexdigest()


def js(data):
    return (json.dumps(data,ensure_ascii=False,indent=2)+"\n").encode()


def stage(name,data):
    name=Path(name).as_posix()
    assert name not in pending and (OUT/name).resolve().is_relative_to(OUT)
    pending[name]=data
    return name


def note(name,data,source,scope,evidence,limit):
    name=Path(name).as_posix()
    desc=f"""# {Path(name).name}

- 来源：{source}；文件/程序集版本与源指纹见 index.json 的 inputs。仅已安装件，包身份交由主任务。
- 此件范围及状态：{scope}；限本机此哈希的资源静态核对，非整 DLL 验收。
- 成果：{len(data)} 字节；SHA-256：{sha(data)}。
- 复核：{evidence}。执行 README.md 所列只读验证；SHA256SUMS 收录本件及说明。
- 边界及下一步：{limit}。不实例化界面控件、不验证实际宿主、外观或业务执行；后续由整件任务决定验收。
"""
    side=stage(name+".md",desc.encode())
    artifacts.append(dict(path=name,bytes=len(data),sha256=sha(data),note=side,note_sha256=sha(pending[side])))


def material(name,data,source,scope,evidence,limit):
    name=stage(name,data)
    note(name,data,source,scope,evidence,limit)
    return name


def unpack_set(block,offset):
    reader=Reader(block)
    assert reader.unpack("II")==(0xbeefcace,1)
    header=Reader(reader.take(reader.unpack("I")[0]))
    manager,resource_set=header.string(),header.string()
    assert header.pos==len(header.data) and manager.startswith("System.Resources.ResourceReader,") and resource_set=="System.Resources.RuntimeResourceSet"
    fmt,count,user_types=reader.unpack("III")
    assert (fmt,count,user_types)==(2,3,0)
    reader.align(8)
    hashes=reader.unpack("I"*count)
    positions=reader.unpack("I"*count)
    data_base,=reader.unpack("I")
    name_base=reader.pos
    name_ranges,value_ranges=[],[]
    items={}
    for expected,pos in zip(hashes,positions):
        reader.pos=name_base+pos
        key=reader.take(reader.integer()).decode("utf-16-le")
        value_pos=data_base+reader.unpack("I")[0]
        name_ranges.append((name_base+pos,reader.pos))
        check=5381
        for char in key:
            check=((check*33)^ord(char))&0xffffffff
        assert expected==check and key not in items
        reader.pos=value_pos
        assert reader.integer()==33
        wire=reader.pos
        length,=reader.unpack("I")
        start=reader.pos
        raw=reader.take(length)
        value_ranges.append((value_pos,reader.pos))
        items[key]=(raw,dict(dll_name_offset=offset+name_base+pos,dll_type_offset=offset+value_pos,dll_wire_offset=offset+wire,
                              dll_payload_offset=offset+start,bytes=length,wire_sha256=sha(block[wire:reader.pos]),sha256=sha(raw)))
    for spans,first,last in [(name_ranges,name_base,data_base),(value_ranges,data_base,len(block))]:
        for low,high in sorted(spans):
            assert low==first and high>low
            first=high
        assert first==last
    return items


def facts(relative,digest,fw):
    source=HOME/relative
    data=source.read_bytes()
    assert sha(data)==digest
    pe=dnfile.dnPE(data=data)
    tables=pe.net.mdtables
    base,size=pe.net.struct.ResourcesRva,pe.net.struct.ResourcesSize
    rows=[] if tables.ManifestResource is None else list(tables.ManifestResource)
    mask=tables.header.MaskValid
    assert bool(mask & (1<<40))==bool(rows)
    assembly=single(tables.Assembly)
    leaf_data=windows_resources(source)
    assert set(leaf_data)=={(16,1,0)}
    native_rows=[]
    for kind in pe.DIRECTORY_ENTRY_RESOURCE.entries:
        for name in kind.directory.entries:
            for lang in name.directory.entries:
                ident=kind.id,name.id,lang.id
                leaf=lang.data.struct
                offset=pe.get_offset_from_rva(leaf.OffsetToData)
                binary=data[offset:offset+leaf.Size]
                assert binary==leaf_data[ident] and ident not in [tuple(r["path"]) for r in native_rows]
                tree=version_tree(binary)
                native_path=material(BASE/relative/"win32"/"RT_VERSION.1.0.bin",binary,source,"完整原 Win32 VERSIONINFO 叶子",
                                     "PE RVA 与长度、Win32 数据文件模式枚举读取及严格版本块遍历三者一致","不是控件或图形资源")
                native_rows.append(dict(path=ident,rva=leaf.OffsetToData,offset=offset,bytes=leaf.Size,code_page=leaf.CodePage,
                                        sha256=sha(binary),artifact=native_path,tree=tree))
    assert {tuple(row["path"]) for row in native_rows}==set(leaf_data)
    sets=fw["sets"] if relative==SAT else fw["main_resources"]
    assert len(rows)==len(pe.net.resources)==len(sets)
    directory=pe.OPTIONAL_HEADER.DATA_DIRECTORY[2]
    result=dict(path=str(source),sha256=digest,bytes=len(data),assembly=str(assembly.Name),culture=str(assembly.Culture) or "neutral",
                assembly_version=".".join(str(getattr(assembly,k)) for k in ("MajorVersion","MinorVersion","BuildNumber","RevisionNumber")),
                cli_header_file_offset=pe.net.struct.get_file_offset(),cli_resources_rva=base,cli_resources_size=size,
                tables_mask_valid=hex(mask),manifest_table_bit_40=bool(mask & (1<<40)),manifest_rows=len(rows),sets=[],
                native_directory_rva=directory.VirtualAddress,native_directory_size=directory.Size,native=native_rows)
    if relative==FILE:
        assert base==size==len(rows)==0
    else:
        row=single(rows)
        parsed=single(pe.net.resources)
        assert row.Implementation is None and row.Offset==0 and parsed.rva==base+4
        start=pe.get_offset_from_rva(base)
        length,=struct.unpack_from("<I",data,start)
        block=data[start+4:start+4+length]
        assert length==parsed.size==size-4 and block==pe.get_data(base+4,length)
        name=str(row.Name)
        framework=single(sets)
        assert name==framework["manifest"]==str(parsed.name)==MAIN+".g.en-US.resources" and sha(block)==framework["sha256"]
        path=material(BASE/relative/"sets"/name,block,source,"完整 CLR 内嵌 .resources 块，含头、名字与值区",
                      "ManifestResource/偏移/长度前缀与 .NET GetManifestResourceStream 哈希一致","子流位于本卫星，不在主 DLL")
        entries=unpack_set(block,start+4)
        independent={item["key"]:item for item in framework["entries"]}
        assert len(independent)==len(framework["entries"])==len(parsed.data.entries)==len(entries)
        assert set(entries)==set(independent)=={rr.name for rr in parsed.data.entries}
        records=[]
        for key in sorted(entries):
            payload,entry=entries[key]
            original=single(rr for rr in parsed.data.entries if rr.name==key)
            framework_entry=independent[key]
            assert original.struct.Type==33 and original.value==payload
            assert all(entry[field]==framework_entry[field] for field in ("bytes","sha256","wire_sha256"))
            assert payload==data[entry["dll_payload_offset"]:entry["dll_payload_offset"]+len(payload)]
            assert Path(key).name==key and key.endswith(".baml")
            origin=str(source)+" :: "+name+" :: "+key
            evidence="原始 PE 字节、dnfile 与独立 .NET ResourceReader 一致；记录级与 WPF 读到 EOF"
            bound="原字节与派生阅读定义分开；不恢复作者原始 XAML"
            raw_path=material(BASE/relative/"baml"/key,payload,origin,"BAML 原始字节流",evidence,bound)
            details,xml=inspect(payload,known,framework_entry["nodes"])
            relations=analyze(key,details,il,contracts)
            relations.update(key=key,baml_sha256=entry["sha256"],main_sha256=MAIN_SHA,satellite_sha256=SAT_SHA)
            all_relations.append(relations)
            details.update(key=key,sha256=entry["sha256"])
            detail_path=material(Path("pages")/(key+".json"),js(details),origin,"全部记录含起止位置、原字节、解码及元素归属",
                                 "逐段消费并回拼完整原流；按 WPF 节点/属性多重集及前后顺序对照到 EOF",bound)
            xml_path=material(Path("pages")/(key+".view.xml"),xml,origin,"供阅读的 XML 投影，不是 WPF 可加载源文件",
                              "每个对象、父子、复杂属性、构造参数与静态属性源于对齐后的记录；附带偏移与接线 ID",
                              "名字空间声明、PI 和转换器等编码细节以同名 JSON 与原 BAML 为准")
            records.append(dict(key=key,**entry,raw=raw_path,view=xml_path,records=detail_path,record_count=details["record_count"],
                                objects=len(details["objects"]),framework_nodes=len(framework_entry["nodes"]),
                                connection_ids=[r["id"] for r in relations["connections"]],bindings=len(relations["bindings"])))
        result["sets"].append(dict(name=name,rva=base+4,offset=start+4,bytes=length,sha256=sha(block),manifest_flags=row.struct.Flags,
                                   token="0x28000001",implementation=None,artifact=path,entries=records))
    pe.close()
    return result


known=json.loads((ROOT/"tools/baml_known.json").read_bytes())
fw=json.loads((OUT/"framework.json").read_bytes())
il=json.loads((OUT/"ui-il.json").read_bytes())
contracts=json.loads((OUT/"contracts.json").read_bytes())
assert il["sha256"]==MAIN_SHA
all_relations=[]
main=facts(FILE,MAIN_SHA,fw)
sat=facts(SAT,SAT_SHA,fw)
assert sum(len(r["connections"]) for r in all_relations)==11
assert sum(len(r["bindings"]) for r in all_relations)==8
pages=sat["sets"][0]["entries"]
lookup=json.loads((OUT/"lookup.json").read_bytes())
assert lookup["satellite_sha256"]==SAT_SHA and lookup["main_sha256"]==MAIN_SHA and Path(lookup["satellite_path"]).resolve()==(HOME/SAT).resolve()
assert lookup["base_name"]==MAIN+".g" and (lookup["requested_culture"],lookup["ultimate_fallback"],lookup["try_parents"])==("en-US","Satellite",False)
assert lookup["entries"]==[{k:entry[k] for k in ("key","sha256","bytes")} for entry in pages]
assert (sum(p["record_count"] for p in pages),sum(p["objects"] for p in pages),sum(p["framework_nodes"] for p in pages))==(445,46,133)
assert sum(len(node["properties"]) for entry in fw["sets"][0]["entries"] for node in entry["nodes"])==200
origin=str(HOME/FILE)+" + "+str(HOME/SAT)
material("relationships.json",js(all_relations),origin,"三条 URI、11 个 switch 分支/字段、事件、绑定与边界",
         "每个 BAML ID 与同页 switch、castclass、stfld/token 及真实字段类型/控件名对应；VM/模板属性和外部符号按元数据比对",
         "实际 DataContext、命令执行、排序与数字结果、COM 注册、最终显示文案未运行核验")
for name,source,scope,evidence in [
        ("ui-il.json",str(HOME/FILE),"三种视图类型的相关 IL 及视图/模型成员签名","Mono.Cecil 元数据和方法体；不做全程序集反编译"),
        ("framework.json",origin,".NET 资源读取与 WPF BamlReader 原生节点/属性输出","两个程序集清单、每个流的 wire/body 哈希、EndDocument 和 EOF"),
        ("lookup.json",origin,"从主程序集无界面查找 en-US 卫星及三条流","GetSatelliteAssembly 的实际路径/哈希、neutral fallback 属性及 ResourceManager（tryParents=false）取出的键/大小/哈希"),
        ("contracts.json",origin,"MMControls 与 Localization 的两处外部签名边界","Cecil 精确匹配继承 info_var 和每个引用的 ApwnResources 静态 getter；不读取外部业务实现")]:
    note(name,(OUT/name).read_bytes(),source,scope,evidence,"参考依赖的静态证据，不对其作整件验收")
tools=[ROOT/"tools/scan_aspen_ui.py",ROOT/"tools/baml_known.json",PREV/"native.py"]
index=dict(inputs=[main,sat],tools=dict(python=platform.python_version(),dnfile=version("dnfile"),pefile=version("pefile"),
           shared_files={str(p.relative_to(ROOT)):sha(p.read_bytes()) for p in tools}),artifacts=artifacts,
           scope="Installed files only; static resource subtask. Not signoff for either DLL.")
stage("index.json",js(index))
note("index.json",pending["index.json"],origin,"两个 PE 的资源目录、每个 Win32 版本块、托管容器和每页定位/摘要",
     "按原文件偏移、三个 .NET 资源层级哈希和 Win32 API 复核；索引自身在 SHA256SUMS","仅主 DLL/本文化卫星的资源子任务")
combined=dict(pending)
for filename in ["framework.json","ui-il.json","contracts.json","lookup.json","README.md","ACCEPTANCE.md","audit.py","baml.py","trace.py",
                 "read-framework.ps1","read-ui-il.ps1","read-contracts.ps1","read-lookup.ps1"]:
    combined[filename]=(OUT/filename).read_bytes()
stage("SHA256SUMS","".join(f"{sha(data)}  {path}\n" for path,data in sorted(combined.items())).encode())
verify=bool(sys.argv[1:])
for name,data in pending.items():
    path=OUT/name
    if verify:
        assert path.read_bytes()==data,name
    elif path.exists():
        raise SystemExit("Refusing to overwrite "+name)
if not verify:
    for name,data in pending.items():
        path=OUT/name
        path.parent.mkdir(parents=True,exist_ok=True)
        with path.open("xb") as handle:
            handle.write(data)
print(f"{'Verified' if verify else 'Created'}: 2 PEs, 2 Win32 leaves, 1 managed set, 3 BAML, 445 records, 46 objects, 8 Bindings, 11 connections; {len(combined)} fingerprints.")

