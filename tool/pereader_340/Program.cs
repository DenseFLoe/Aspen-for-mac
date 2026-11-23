using System;
using System.IO;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Text.Json;

class P {
    static void Main(string[] args) {
        string path = args[0];
        using var fs = File.OpenRead(path);
        using var pe = new PEReader(fs);
        var md = pe.GetMetadataReader();
        var impls = new System.Collections.Generic.List<object>();
        for (int row = 1; row <= md.GetTableRowCount(TableIndex.MethodImpl); row++) {
            var mi = md.GetMethodImplementation(MetadataTokens.MethodImplementationHandle(row));
            impls.Add(new { row, body_kind = mi.MethodBody.Kind.ToString(), body_rid = MetadataTokens.GetRowNumber(mi.MethodBody),
                            decl_kind = mi.MethodDeclaration.Kind.ToString(), decl_rid = MetadataTokens.GetRowNumber(mi.MethodDeclaration) });
        }
        var refs = new System.Collections.Generic.List<object>();
        for (int row = 1; row <= md.GetTableRowCount(TableIndex.MemberRef); row++) {
            var mr = md.GetMemberReference(MetadataTokens.MemberReferenceHandle(row));
            refs.Add(new { row, parent_kind = mr.Parent.Kind.ToString(), parent_rid = MetadataTokens.GetRowNumber(mr.Parent) });
        }
        var cattrs = new System.Collections.Generic.List<object>();
        for (int row = 1; row <= md.GetTableRowCount(TableIndex.CustomAttribute); row++) {
            var ca = md.GetCustomAttribute(MetadataTokens.CustomAttributeHandle(row));
            cattrs.Add(new { row, type_kind = ca.Constructor.Kind.ToString(), type_rid = MetadataTokens.GetRowNumber(ca.Constructor) });
        }
        var doc = new { file = path, sha256 = Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(File.ReadAllBytes(path))).ToLowerInvariant(),
                        methoddef_rows = md.GetTableRowCount(TableIndex.MethodDef),
                        memberref_rows = md.GetTableRowCount(TableIndex.MemberRef),
                        customattr_rows = md.GetTableRowCount(TableIndex.CustomAttribute),
                        methodimpl_rows = md.GetTableRowCount(TableIndex.MethodImpl),
                        impls, refs, cattrs };
        Console.WriteLine(JsonSerializer.Serialize(doc));
    }
}
