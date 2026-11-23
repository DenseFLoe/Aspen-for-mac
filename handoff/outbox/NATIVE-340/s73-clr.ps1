param(
    [Parameter(Mandatory)][string] $Original,
    [Parameter(Mandatory)][string] $Fixture
)
$ErrorActionPreference = 'Stop'
$reader = @'
using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;

public static class AspenS73
{
    public static object Read(string path)
    {
        using var stream = File.OpenRead(path);
        using var pe = new PEReader(stream);
        var md = pe.GetMetadataReader();
        var methods = new List<object>();
        var bindings = new List<object>();
        var parents = new Dictionary<string, int>();
        var exports = new List<object>();
        foreach (var handle in md.MethodDefinitions)
        {
            var method = md.GetMethodDefinition(handle);
            var rva = method.RelativeVirtualAddress;
            var il = rva != 0 && ((int) method.ImplAttributes & 3) == 0
                ? pe.GetMethodBody(rva).GetILBytes() : Array.Empty<byte>();
            methods.Add(new {
                token = MetadataTokens.GetToken(handle), name = md.GetString(method.Name),
                flags = (int) method.Attributes, implementation = (int) method.ImplAttributes,
                access = (method.Attributes & System.Reflection.MethodAttributes.MemberAccessMask).ToString(),
                rva, il_length = il.Length, il_sha256 = Convert.ToHexString(SHA256.HashData(il)).ToLowerInvariant()
            });
        }
        foreach (var handle in md.MemberReferences)
        {
            var reference = md.GetMemberReference(handle);
            var kind = reference.Parent.Kind.ToString();
            parents[kind] = parents.GetValueOrDefault(kind) + 1;
        }
        foreach (var handle in md.TypeDefinitions)
        {
            var type = md.GetTypeDefinition(handle);
            foreach (var implHandle in type.GetMethodImplementations())
            {
                var impl = md.GetMethodImplementation(implHandle);
                bindings.Add(new { owner = MetadataTokens.GetToken(handle),
                    body = MetadataTokens.GetToken(impl.MethodBody),
                    declaration = MetadataTokens.GetToken(impl.MethodDeclaration) });
            }
        }
        var directory = pe.PEHeaders.CorHeader.VtableFixupsDirectory;
        if (directory.Size > 0)
        {
            var rows = pe.GetSectionData(directory.RelativeVirtualAddress).GetReader(0, directory.Size);
            while (rows.RemainingBytes != 0)
            {
                var rva = rows.ReadInt32();
                var count = rows.ReadUInt16();
                var flags = rows.ReadUInt16();
                var width = (flags & 2) != 0 ? 8 : 4;
                var slotReader = pe.GetSectionData(rva).GetReader(0, count * width);
                var slots = new List<long>();
                for (var row = 0; row < count; row++)
                    slots.Add(width == 8 ? slotReader.ReadInt64() : slotReader.ReadUInt32());
                exports.Add(new { rva, count, flags, width, slots });
            }
        }
        return new { methods, member_ref_parent_kinds = parents, method_bindings = bindings,
                     fixup_rva = directory.RelativeVirtualAddress, fixup_size = directory.Size, fixup_descriptors = exports };
    }
}
'@
Add-Type -TypeDefinition $reader
if (-not (Test-Path -LiteralPath $Fixture)) {
    Add-Type -OutputAssembly $Fixture -TypeDefinition @'
public interface ILocalBinding { int Evaluate(); }
public sealed class ExplicitBinding : ILocalBinding {
    int ILocalBinding.Evaluate() { return 12; }
    private int Unbound() { return 12; }
}
'@
}
[ordered]@{
    original = [AspenS73]::Read((Resolve-Path -LiteralPath $Original).Path)
    fixture = [AspenS73]::Read((Resolve-Path -LiteralPath $Fixture).Path)
    fixture_sha256 = (Get-FileHash -Algorithm SHA256 -LiteralPath $Fixture).Hash.ToLowerInvariant()
} | ConvertTo-Json -Depth 10
