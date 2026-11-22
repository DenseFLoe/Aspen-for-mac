using System;
using System.IO;
using System.Linq;
using System.Text;
using Mono.Cecil;
using Mono.Cecil.Cil;

public static partial class LocalizationAudit
{
    private static string Literal(string value)
    {
        var quoted = new StringBuilder("\"");
        foreach (char c in value)
        {
            if (c == '"' || c == '\\') quoted.Append('\\').Append(c);
            else if (char.IsControl(c) || char.IsSurrogate(c) || c == '\u2028' || c == '\u2029')
                quoted.Append("\\u").Append(((int)c).ToString("x4"));
            else quoted.Append(c);
        }
        return quoted.Append('"').ToString();
    }

    public static string Strip(string input, string reduced, string generated)
    {
        using var module = ModuleDefinition.ReadModule(input);
        using var output = new StreamWriter(generated);
        int removed = 0;
        foreach (var type in module.Types)
        {
            bool opened = false;
            foreach (var prop in type.Properties.ToArray())
            {
                var method = prop.GetMethod;
                if (method == null || !method.IsStatic || !method.HasBody || prop.SetMethod != null ||
                    prop.Parameters.Count != 0 || prop.PropertyType.FullName != "System.String" ||
                    prop.HasCustomAttributes || method.HasCustomAttributes) continue;
                var il = method.Body.Instructions;
                if (il.Count != 5 || il[0].OpCode.Code != Code.Call || il[1].OpCode.Code != Code.Ldstr ||
                    il[2].OpCode.Code != Code.Ldsfld || il[3].OpCode.Code != Code.Callvirt || il[4].OpCode.Code != Code.Ret ||
                    ((MethodReference)il[0].Operand).FullName != "System.Resources.ResourceManager " + type.FullName + "::get_ResourceManager()" ||
                    ((FieldReference)il[2].Operand).FullName != "System.Globalization.CultureInfo " + type.FullName + "::resourceCulture" ||
                    ((MethodReference)il[3].Operand).FullName != "System.String System.Resources.ResourceManager::GetString(System.String,System.Globalization.CultureInfo)" ||
                    method.Name != "get_" + prop.Name || !(method.IsPublic || method.IsAssembly)) continue;
                if (!opened)
                {
                    output.WriteLine("namespace " + type.Namespace + "\n{\n    partial class " + type.Name + "\n    {");
                    opened = true;
                }
                output.WriteLine("        " + (method.IsPublic ? "public" : "internal") + " static string @" + prop.Name +
                    " => ResourceManager.GetString(" + Literal((string)il[1].Operand) + ", resourceCulture);");
                type.Properties.Remove(prop);
                type.Methods.Remove(method);
                removed++;
            }
            if (opened) output.WriteLine("    }\n}");
        }
        module.Write(reduced);
        return "generated_getters=" + removed;
    }
}
