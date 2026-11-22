using System;
using System.Collections.Generic;
using System.Linq;
using Mono.Cecil;
using Mono.Cecil.Cil;

public static partial class LocalizationAudit
{
    public static string MethodId(MethodDefinition method) =>
        method.DeclaringType.FullName + "::" + method.Name + "(" +
        string.Join(",", method.Parameters.Select(p => p.ParameterType.FullName)) + "):" +
        method.ReturnType.FullName + "`" + method.GenericParameters.Count;

    public static IEnumerable<TypeDefinition> AllTypes(IEnumerable<TypeDefinition> types)
    {
        foreach (var type in types)
        {
            yield return type;
            foreach (var nested in AllTypes(type.NestedTypes))
                yield return nested;
        }
    }

    private static string Operand(object value, Dictionary<Instruction,int> positions)
    {
        if (value == null) return "";
        if (value is Instruction target) return positions[target].ToString();
        if (value is Instruction[] targets) return string.Join(",", targets.Select(x => positions[x]));
        if (value is MemberReference member) return member.FullName;
        if (value is ParameterDefinition parameter) return parameter.Index.ToString();
        if (value is VariableDefinition variable) return variable.Index.ToString();
        return Convert.ToString(value, System.Globalization.CultureInfo.InvariantCulture);
    }

    private static string Body(MethodDefinition method)
    {
        if (!method.HasBody) return "<no body>";
        var list = method.Body.Instructions;
        var positions = list.Select((x,i)=>(x,i)).ToDictionary(pair => pair.x, pair => pair.i);
        int Index(Instruction x) => x == null ? -1 : positions[x];
        return string.Join("\n", list.Select(x => x.OpCode.Name + " " + Operand(x.Operand, positions))) +
            "\nlocals:" + string.Join(",", method.Body.Variables.Select(v => v.VariableType.FullName + ":" + v.IsPinned)) +
            "\nEH:" + string.Join(";", method.Body.ExceptionHandlers.Select(h => string.Join(",", h.HandlerType,
                Index(h.TryStart), Index(h.TryEnd), Index(h.HandlerStart), Index(h.HandlerEnd), Index(h.FilterStart), h.CatchType?.FullName)));
    }

    private static string Attrs(ICustomAttributeProvider target)
    {
        return string.Join("|", target.CustomAttributes.Select(a => a.AttributeType.FullName + ":" + Convert.ToHexString(a.GetBlob())).OrderBy(s => s, StringComparer.Ordinal));
    }

        private static string Parameters(MethodDefinition method) =>
        string.Join("|", method.Parameters.Select(p => p.Name + ":" + p.Attributes + ":" + p.Constant + ":" + p.MarshalInfo?.NativeType + ":" + Attrs(p))) +
        " return:" + method.MethodReturnType.Attributes + ":" + method.MethodReturnType.MarshalInfo?.NativeType + ":" + Attrs(method.MethodReturnType);

    private static string TypeShape(TypeDefinition type)
    {
        return string.Join("\n", (int)type.Attributes, type.BaseType?.FullName, Attrs(type),
            string.Join("|", type.Interfaces.Select(i => i.InterfaceType.FullName).OrderBy(s => s, StringComparer.Ordinal)),
            string.Join("|", type.Fields.Select(f => f.FullName + ":" + (int)f.Attributes + ":" + f.Constant + ":" + Attrs(f)).OrderBy(s => s, StringComparer.Ordinal)),
            string.Join("|", type.Properties.Select(p => p.FullName + ":" + (int)p.Attributes + ":" + p.GetMethod?.Name + ":" + p.SetMethod?.Name + ":" + Attrs(p)).OrderBy(s => s, StringComparer.Ordinal)),
            string.Join("|", type.Events.Select(e => e.FullName + ":" + (int)e.Attributes).OrderBy(s => s, StringComparer.Ordinal)));
    }

    public static string[] Compare(string original, string rebuilt)
    {
        using var a = ModuleDefinition.ReadModule(original);
        using var b = ModuleDefinition.ReadModule(rebuilt);
        var am = AllTypes(a.Types).SelectMany(t => t.Methods).ToDictionary(MethodId);
        var bm = AllTypes(b.Types).SelectMany(t => t.Methods).ToDictionary(MethodId);
        var report = new List<string>();
        int matched = 0;
        foreach (var pair in am)
        {
            var hex = pair.Value.MetadataToken.ToUInt32().ToString("X8");
            if (!bm.TryGetValue(pair.Key, out var found)) report.Add("missing " + hex + " " + pair.Key);
            else if (Body(pair.Value) != Body(found)) report.Add("different " + hex + " " + pair.Key);
            else if (pair.Value.Attributes != found.Attributes || pair.Value.ImplAttributes != found.ImplAttributes || Attrs(pair.Value) != Attrs(found) || Parameters(pair.Value) != Parameters(found))
                report.Add("attributes " + hex + " " + pair.Key);
            else matched++;
        }
        foreach (var item in bm.Keys.Except(am.Keys)) report.Add("extra " + item);
        report.Insert(0, $"original_methods={am.Count} rebuilt_methods={bm.Count} matching={matched} flagged={report.Count}");
                var at = AllTypes(a.Types).ToDictionary(t => t.FullName);
        var bt = AllTypes(b.Types).ToDictionary(t => t.FullName);
        string[] typeDiffs = at.Keys.Union(bt.Keys).Where(k =>
            !at.TryGetValue(k, out var x) || !bt.TryGetValue(k, out var y) || TypeShape(x) != TypeShape(y)).ToArray();
        report.Add($"original_types={at.Count} rebuilt_types={bt.Count} type_differences={typeDiffs.Length}");
        report.AddRange(typeDiffs.Select(x => "type " + x));
        var ar = a.Resources.OfType<EmbeddedResource>().ToDictionary(r => r.Name);
        var br = b.Resources.OfType<EmbeddedResource>().ToDictionary(r => r.Name);
        string[] resourceDiffs = ar.Keys.Union(br.Keys).Where(k =>
            !ar.TryGetValue(k, out var x) || !br.TryGetValue(k, out var y) ||
            x.Attributes != y.Attributes || !x.GetResourceData().AsSpan().SequenceEqual(y.GetResourceData())).ToArray();
        report.Add($"original_resources={ar.Count} rebuilt_resources={br.Count} resource_differences={resourceDiffs.Length}");
        report.AddRange(resourceDiffs.Select(x => "resource " + x));
        report.Add("assembly_identity_equal=" + (a.Assembly.FullName == b.Assembly.FullName));
        report.Add("assembly_attributes_equal=" + (Attrs(a.Assembly) == Attrs(b.Assembly)));
        report.Add("module_attributes_equal=" + (Attrs(a) == Attrs(b)));
        foreach (var x in a.AssemblyReferences.Select(r => r.FullName).Except(b.AssemblyReferences.Select(r => r.FullName))) report.Add("original_ref_only " + x);
        foreach (var x in b.AssemblyReferences.Select(r => r.FullName).Except(a.AssemblyReferences.Select(r => r.FullName))) report.Add("rebuilt_ref_only " + x);
        return report.ToArray();
    }

    public static string[] Patterns(string path)
    {
        using var asm = ModuleDefinition.ReadModule(path);
        return AllTypes(asm.Types).SelectMany(x => x.Methods).Where(x => x.HasBody)
            .GroupBy(x => string.Join(" ", x.Body.Instructions.Select(i => i.OpCode.Name)))
            .OrderByDescending(x => x.Count()).Take(25)
            .Select(x => x.Count() + " " + x.Key.Substring(0, Math.Min(140,x.Key.Length)) + " / " + MethodId(x.First())).ToArray();
    }
}



