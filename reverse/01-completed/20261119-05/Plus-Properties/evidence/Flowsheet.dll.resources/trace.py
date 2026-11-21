from pathlib import PurePosixPath


def single(items):
    item, = items
    return item


def selected(items, op):
    return [item for item in items if item["op"]==op]


def prop(owner, name):
    member=single(p for p in owner["properties"] if p["name"]==name)
    return dict(owner=owner.get("type",owner.get("owner")),name=name,type=member["type"],
                token=member["token"],getter=member["getter"],setter=member.get("setter"))


def analyze(key, page, il, contracts):
    nodes=page["objects"]
    types={row["type"]:row for row in il["types"]}
    owner=types[nodes[0]["clr_type"]]
    methods={m["name"]:m for m in owner["view_methods"]}
    init=methods["InitializeComponent"]
    initialize=init["instructions"]
    connect=methods["System.Windows.Markup.IComponentConnector.Connect"]
    code=connect["instructions"]
    ctor=methods[".ctor"]["instructions"]
    vm_name=single(selected(ctor,"ldtoken"))["operand"]
    vm=types[vm_name]
    assert vm_name==owner["type"]+"_ViewModel"
    assert "MMViewModelContainer::set_ViewModelType" in ctor[5]["operand"]
    assert ctor[7]["ref"]==init["token"]
    uri=single(selected(initialize,"ldstr"))
    assert [i["op"] for i in initialize]==["ldarg.0","ldfld","brfalse.s","ret","ldarg.0","ldc.i4.1","stfld","ldstr","ldc.i4.2","newobj","stloc.0","ldarg.0","ldloc.0","call","ret"]
    assert initialize[2]["operand"]==initialize[4]["offset"] and initialize[1]["operand"]==initialize[6]["operand"]
    assert initialize[6]["operand"].endswith("::_contentLoaded")
    assert initialize[9]["operand"]=="System.Void System.Uri::.ctor(System.String,System.UriKind)"
    assert initialize[-2]["operand"]=="System.Void System.Windows.Application::LoadComponent(System.Object,System.Uri)"
    assembly,relative=uri["operand"].split(";component/")
    assert assembly=="/AspenTech.AspenPlus.MMForms.Flowsheet" and str(PurePosixPath(relative).with_suffix(".baml"))==key
    assert "System.Windows.Markup.IComponentConnector" in owner["interfaces"]
    assert [i["op"] for i in code[:5]]==["ldarg.1","ldc.i4.1","sub","switch","br.s"]
    branches=code[3]["operand"]
    default=code[4]["operand"]
    targets={field["name"]:field for field in owner["fields"]}
    found,bindings,references,field_uses=[],[],[],[]
    by_offset={node["offset"]:node for node in nodes}
    localization=single(c for c in contracts if c["owner"].endswith(".ApwnResources"))
    inherited=single(c for c in contracts if c["owner"]==vm["base"])
    for node in nodes:
        attrs={a["name"]:a for a in node["attributes"] if a["kind"]=="Property"}
        parent=by_offset.get(node["parent"])
        ancestors=[]
        while parent:
            ancestors.append(parent)
            parent=by_offset.get(parent["parent"])
        for attr in node["attributes"]:
            name,value,record=attr["name"],attr["value"],attr["record"]
            if attr["kind"]=="ConnectionId":
                ident=int(value)
                start=branches[ident-1]
                end=branches[ident] if ident<len(branches) else default
                case=[i for i in code if start<=i["offset"]<end]
                assert case[0]["offset"]==start and case[-1]["op"]=="ret"
                assert [i["op"] for i in case[:4]]==["ldarg.0","ldarg.2","castclass","stfld"]
                field=attrs["FrameworkElement.Name"]["value"]
                cast=case[2]["operand"]
                assert cast==node["clr_type"]==targets[field]["type"]
                assert case[3]["ref"]==targets[field]["token"] and case[3]["operand"]==cast+" "+owner["type"]+"::"+field
                handlers=[]
                if len(case)>5:
                    assert [i["op"] for i in case[4:-1]]==["ldarg.0","ldfld","ldarg.0","ldftn","newobj","callvirt"]
                    assert case[5]["ref"]==case[3]["ref"] and "::add_Click(" in case[-2]["operand"]
                    handler=methods[case[7]["operand"].split("::")[1].split("(")[0]]
                    assert case[7]["ref"]==handler["token"]
                    handlers.append(dict(event=case[-2]["operand"],add_offset=case[-2]["offset"],handler=handler["name"],
                                         method=handler["token"],calls=selected(handler["instructions"],"callvirt")))
                found.append(dict(id=ident,baml_record=record,object_offset=node["offset"],field=field,type=cast,
                                  field_token=targets[field]["token"],case_offset=start,stfld_offset=case[3]["offset"],
                                  ret_offset=case[-1]["offset"],handlers=handlers))
            if value.startswith("{x:Static "):
                symbol=value.rsplit(".",1)[-1][:-1]
                endpoint=prop(localization,symbol)
                assert endpoint["type"]=="System.String" and single(p for p in localization["properties"] if p["name"]==symbol)["static"]
                references.append(dict(kind="static caption getter; value not invoked",record=record,member=name,endpoint=endpoint))
            if name.endswith((".HelpFile",".HelpId",".ContentProgId",".ContentType")):
                references.append(dict(kind="metadata only",record=record,member=name,value=value))
            if name.endswith((".VariablePath",".DataProperty",".PropertyPath",".CommandPath",".CommandParameterPath",".VariableDataMember",".FieldName",".InnerDataItemType")):
                endpoint=None
                boundary=""
                if name.endswith((".VariablePath",".DataProperty",".CommandPath")):
                    endpoint=prop(inherited if value=="info_var" else vm,value)
                elif name.endswith((".PropertyPath",".CommandParameterPath")):
                    nested=any(a["type"].endswith(".MMScrollAreaHierarchicalField") for a in ancestors)
                    prefix="grdChild" if key=="mmflowsh_objman.baml" else "grdFlowsheet"
                    item=types[vm_name+"/"+prefix+"_GridData_"+("InnerTemplate" if nested else "ItemTemplate")]
                    endpoint=prop(item,value.split(".")[0])
                    if "." in value:
                        boundary="Value is late-bound on the object returned by the item getter; not a property of this DLL's item class."
                elif name.endswith(".InnerDataItemType"):
                    endpoint=dict(type=types[vm_name+"/"+value]["type"])
                elif name.endswith(".VariableDataMember"):
                    assert value=="Value"
                    boundary="MMControls value-member selector on a runtime object; not a local PropertyDef."
                else:
                    boundary="MMControls field identifier; not a ViewModel property path."
                field_uses.append(dict(record=record,object=node["offset"],member=name,value=value,endpoint=endpoint,boundary=boundary))
        if node["clr_type"]=="System.Windows.Data.Binding":
            arg=node.get("constructor_argument")
            path=arg if arg else attrs["Binding.Path"]["value"]
            bindings.append(dict(object=node["offset"],parent=node["parent"],parent_type=ancestors[0]["clr_type"],
                                 target_member=node["slot"],path=path,mode=attrs.get("Binding.Mode",{}).get("value","not specified"),
                                 notation="constructor" if arg else "Binding.Path",endpoint=prop(vm,path)))
    assert sorted(r["id"] for r in found)==list(range(1,len(branches)+1))
    other_fields=set(targets)-{r["field"] for r in found}
    assert other_fields==({"_recordToBeExpandedIndex","_contentLoaded"} if "grdFlowsheet_Loaded" in methods else {"_contentLoaded"})
    non_ui_fields=[dict(**targets[name],users=[method["token"] for method in methods.values()
                   if any(i["ref"]==targets[name]["token"] for i in method["instructions"])]) for name in sorted(other_fields)]
    fallback=[i for i in code if i["offset"]>=default]
    assert [i["op"] for i in fallback]==["ldarg.0","ldc.i4.1","stfld","ret"] and fallback[2]["operand"]==initialize[6]["operand"]
    lifetime=[]
    if "grdFlowsheet_Loaded" in methods:
        for method in (methods[".ctor"],methods["grdFlowsheet_Loaded"],methods["OnClosing"]):
            body=method["instructions"]
            for index,item in enumerate(body):
                if item["op"]!="ldftn":
                    continue
                tail=body[index+1:index+4]
                assert tail[0]["op"]=="newobj"
                call=single(i for i in tail if i["op"]=="callvirt")
                handler=single(m for m in methods.values() if m["token"]==item["ref"])
                lifetime.append(dict(site=method["name"],method=method["token"],ldftn_offset=item["offset"],delegate=tail[0]["operand"],
                                     handler=handler["name"],handler_token=item["ref"],call=call["operand"],call_offset=call["offset"],
                                     receiver_path=[i["operand"] for i in body[max(0,index-6):index] if i["op"] in ("ldfld","callvirt","ldsfld")],
                                     handled_events_too=True if any(i["op"]=="ldc.i4.1" for i in tail[:2]) else None))
        assert len(lifetime)==7
        added={r["handler"] for r in lifetime if r["site"]=="grdFlowsheet_Loaded"}
        assert added=={r["handler"] for r in lifetime if r["site"]=="OnClosing"} and len(added)==3
    return dict(root=owner["type"],base=owner["base"],constructor=methods[".ctor"]["token"],view_model=vm_name,
                initialize=init["token"],uri=uri["operand"],uri_kind="Relative (2)",uri_offset=uri["offset"],
                load_offset=initialize[-2]["offset"],connect=connect["token"],switch_offset=code[3]["offset"],
                default_offset=default,default_effect="_contentLoaded = true",connections=found,
                bindings=bindings,field_paths=field_uses,interface_references=references,code_event_sites=lifetime,non_control_fields=non_ui_fields)
