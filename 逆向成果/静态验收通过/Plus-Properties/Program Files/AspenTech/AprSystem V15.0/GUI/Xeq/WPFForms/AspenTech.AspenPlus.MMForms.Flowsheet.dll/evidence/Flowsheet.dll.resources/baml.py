from collections import Counter
import xml.etree.ElementTree as ET

from scan_aspen_ui import FIXED, VARIABLE, Reader

TAGS = {1:"DocumentStart",2:"DocumentEnd",3:"ElementStart",4:"ElementEnd",6:"PropertyCustom",
        7:"PropertyComplexStart",8:"PropertyComplexEnd",11:"PropertyIListStart",12:"PropertyIListEnd",
        16:"Text",20:"XmlnsProperty",25:"DefAttribute",27:"PIMapping",28:"AssemblyInfo",29:"TypeInfo",
        31:"AttributeInfo",34:"PropertyTypeReference",35:"PropertyWithExtension",36:"PropertyWithConverter",
        42:"ConstructorParametersStart",43:"ConstructorParametersEnd",45:"ConnectionId",46:"ContentProperty"}


def short(name):
    return ".".join(name.split(".")[-2:])


def inspect(raw, known, framework):
    reader = Reader(raw)
    assert reader.take(reader.unpack("I")[0]).decode("utf-16-le") == "MSBAML"
    versions = reader.unpack("6H")
    assert versions == (0,96,0,96,0,96)
    header = raw[:reader.pos]
    assemblies, types, members = {}, {}, {}
    objects, records, events, stack, scopes = [], [], [], [], []
    xml_root = ET.Element("interface", projection="static BAML; not executable XAML")
    xml_scopes = [xml_root]

    def typename(ident):
        return types[ident]["name"] if ident >= 0 else known["types"][str(-ident)]

    def membername(ident):
        return members[ident]["name"] if ident >= 0 else known["properties"][str(-ident)]

    def event(kind, name="", value=""):
        events.append(dict(record=offset,kind=kind,name=name,value=value,owner=stack[-1]["offset"] if stack else None))

    def prop(kind, name, value):
        stack[-1]["attributes"].append(dict(record=offset,framework_node=len(events)-1,kind=kind,name=name,value=value))

    while reader.pos < len(raw):
        offset = reader.pos
        tag, = reader.unpack("B")
        if tag in VARIABLE:
            start = reader.pos
            size = reader.integer() - (reader.pos-start)
        else:
            size = FIXED[tag]
        start = reader.pos
        part = Reader(reader.take(size))
        datum = dict(offset=offset,end=reader.pos,payload_offset=start,tag=tag,kind=TAGS[tag],
                     hex=raw[offset:reader.pos].hex())
        if tag == 1:
            async_mode, max_records, debug = part.unpack("BiB")
            datum.update(load_async=async_mode,max_async_records=max_records,debug_baml=debug)
            event("StartDocument")
        elif tag == 2:
            assert not scopes and not stack and reader.pos==len(raw)
            event("EndDocument")
        elif tag == 28:
            ident, = part.unpack("h")
            assert ident not in assemblies
            assemblies[ident] = part.string()
            datum.update(id=ident,name=assemblies[ident])
        elif tag == 29:
            ident, assembly = part.unpack("hh")
            assert ident not in types and assembly in assemblies
            types[ident] = dict(name=part.string(),assembly=assemblies[assembly])
            datum.update(id=ident,assembly_id=assembly,**types[ident])
        elif tag == 31:
            ident, owner, usage = part.unpack("hhB")
            assert ident not in members
            members[ident] = dict(name=typename(owner)+"."+part.string(),owner=typename(owner),usage=usage)
            datum.update(id=ident,owner_id=owner,**members[ident])
        elif tag == 27:
            namespace, clr = part.string(), part.string()
            ident, = part.unpack("h")
            datum.update(namespace=namespace,clr=clr,assembly=assemblies[ident],assembly_id=ident)
            event("PIMapping",value=namespace)
        elif tag == 3:
            ident, flags = part.unpack("hB")
            assert flags==0
            node = dict(offset=offset,type=typename(ident),parent=stack[-1]["offset"] if stack else None,
                        slot=scopes[-1][1] if scopes and scopes[-1][0] in (7,11) else "",attributes=[])
            objects.append(node)
            stack.append(node)
            scopes.append((3,node["type"]))
            datum.update(type_id=ident,element_type=node["type"],flags=flags)
            event("StartElement",node["type"])
        elif tag == 4:
            kind,name = scopes.pop()
            assert kind==3
            event("EndElement",name)
            stack.pop()
        elif tag in (7,11):
            ident, = part.unpack("h")
            name=membername(ident)
            scopes.append((tag,name))
            datum.update(member_id=ident,member=name)
            event("StartComplexProperty",name)
        elif tag in (8,12):
            kind,name = scopes.pop()
            assert kind==tag-1
            event("EndComplexProperty",name)
        elif tag == 42:
            scopes.append((42,""))
            event("StartConstructor")
        elif tag == 43:
            assert scopes.pop()==(42,"")
            event("EndConstructor")
        elif tag == 16:
            text=part.string()
            assert scopes[-1][0]==42
            datum.update(text=text)
            stack[-1]["constructor_argument"]=text
            event("Text",value=text)
        elif tag == 45:
            ident, = part.unpack("I")
            datum.update(id=ident)
            prop("ConnectionId","",str(ident))
        elif tag == 25:
            value=part.string()
            ident,=part.unpack("h")
            assert ident==-2
            datum.update(id=ident,value=value)
            prop("DefAttribute","Uid",value)
        elif tag == 20:
            prefix, uri=part.string(),part.string()
            count,=part.unpack("H")
            ids=part.unpack("h"*count)
            datum.update(prefix=prefix,uri=uri,assembly_ids=ids)
            prop("XmlnsProperty","xmlns"+(":"+prefix if prefix else ""),uri)
        elif tag in (6,34,35,36,46):
            ident,=part.unpack("h")
            name=membername(ident)
            datum.update(member_id=ident,member=name)
            if tag==6:
                serializer,=part.unpack("H")
                blob=part.take(len(part.data)-part.pos)
                datum.update(serializer=known["types"][str(serializer)],custom_hex=blob.hex())
                if datum["serializer"]=="BooleanConverter":
                    assert blob in (b"\x00",b"\x01")
                    value=str(bool(blob[0]))
                else:
                    assert datum["serializer"]=="XamlBrushSerializer" and len(blob)==5 and blob[0]==1
                    value="#%08X"%int.from_bytes(blob[1:],"little")
            elif tag==34:
                type_id,=part.unpack("h")
                datum.update(target_type=typename(type_id))
                value="{x:Type local:"+typename(type_id).split(".")[-1]+"}"
            elif tag==35:
                flags,ref=part.unpack("Hh")
                assert flags==602 and members[ref]["owner"]=="AspenTech.AspenPlus.Localization.ApwnResources"
                datum.update(extension=typename(-flags),target_member_id=ref,target_member=membername(ref))
                value="{x:Static res:"+short(membername(ref))+"}"
            elif tag==36:
                value=part.string()
                converter,=part.unpack("h")
                datum.update(converter_type=typename(converter),converter_id=converter)
            else:
                value=name.split(".")[-1]
            datum.update(value=value)
            prop("ContentProperty" if tag==46 else "Property",short(name),value)
        assert part.pos==len(part.data), (tag,offset,part.data[part.pos:])
        records.append(datum)
    assert header+b"".join(bytes.fromhex(row["hex"]) for row in records)==raw
    assert events[0]["kind"]=="StartDocument" and events[-1]["kind"]=="EndDocument"
    assert len(framework)==len(events)
    indexed={node["offset"]:node for node in objects}
    for ordinal,(encoded,actual) in enumerate(zip(events,framework)):
        kind=encoded["kind"]
        assert kind==actual["NodeType"]
        if kind in ("StartElement","EndElement"):
            assert encoded["name"]==actual["Name"] or ("." not in encoded["name"] and encoded["name"]==actual["LocalName"])
        if kind in ("StartComplexProperty","EndComplexProperty"):
            assert short(encoded["name"])==short(actual["Name"])
        if kind=="PIMapping":
            assert encoded["value"]==actual["XmlNamespace"]
        if kind=="Text":
            assert encoded["value"]==actual["Value"]
        def normalize(attr):
            return (attr["NodeType"],short(attr["Name"]) if attr["NodeType"] in ("Property","ContentProperty") else attr["Name"],attr["Value"])
        wanted=Counter((a["kind"],a["name"],a["value"]) for obj in objects for a in obj["attributes"] if a["framework_node"]==ordinal)
        actual_props=Counter(normalize(a) for a in actual["properties"])
        assert wanted==actual_props,(ordinal,kind,wanted-actual_props,actual_props-wanted)
        if kind=="StartElement":
            node=indexed[encoded["owner"]]
            node.update(clr_type=actual["Name"],framework_node=ordinal)
            xml=ET.SubElement(xml_scopes[-1],"object",type=actual["Name"],offset=hex(node["offset"]))
            for attr in node["attributes"]:
                if attr["kind"]=="XmlnsProperty":
                    continue
                ET.SubElement(xml,"attribute",kind=attr["kind"],name=attr["name"],value=attr["value"])
            xml_scopes.append(xml)
        else:
            if kind in ("StartConstructor","StartComplexProperty"):
                xml_scopes.append(ET.SubElement(xml_scopes[-1], "constructor" if kind=="StartConstructor" else "member",name=actual["Name"]))
            elif kind in ("EndElement","EndConstructor","EndComplexProperty"):
                xml_scopes.pop()
            elif kind=="Text":
                ET.SubElement(xml_scopes[-1],"text").text=actual["Value"]
    assert xml_scopes==[xml_root] and len(xml_root)==1
    ET.indent(xml_root)
    view=ET.tostring(xml_root,encoding="utf-8",xml_declaration=True)+b"\n"
    assert len(list(ET.fromstring(view).iter("object")))==len(objects)
    return dict(header_hex=header.hex(),versions=versions,record_count=len(records),end=len(raw),
                record_counts=dict(Counter(row["kind"] for row in records)),assemblies=assemblies,types=types,
                members=members,records=records,events=events,objects=objects),view
