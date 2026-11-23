param([Parameter(Mandatory)][string]$Original, [Parameter(Mandatory)][string]$Delivery)
$ErrorActionPreference = 'Stop'
if ((Get-FileHash $Original).Hash -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') { throw 'Wrong original' }
Add-Type -TypeDefinition @'
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
public static class Aspen77Oracle
{
    public static object[] Read(string path) {
        using var stream = File.OpenRead(path);
        using var pe = new PEReader(stream);
        var md = pe.GetMetadataReader();
        var methods = new Dictionary<int,string>();
        foreach (var handle in md.MethodDefinitions) {
            var m = md.GetMethodDefinition(handle);
            if (m.RelativeVirtualAddress != 0 && ((int)m.ImplAttributes & 3) == 0)
                methods.Add(MetadataTokens.GetToken(handle), Convert.ToHexString(
                    SHA256.HashData(pe.GetMethodBody(m.RelativeVirtualAddress).GetILBytes())));
        }
        var directory = pe.PEHeaders.CorHeader.VtableFixupsDirectory;
        var reader = pe.GetSectionData(directory.RelativeVirtualAddress).GetReader(0, directory.Size);
        var slots = new Dictionary<int,string>();
        while (reader.RemainingBytes >= 8) {
            int rva = reader.ReadInt32(), count = reader.ReadUInt16(), flags = reader.ReadUInt16();
            int width = (flags & 2) != 0 ? 8 : 4;
            var values = pe.GetSectionData(rva).GetReader(0, count * width);
            for (int i=0; i<count; i++)
                slots[rva + width*i] = flags.ToString("X") + "/" + (width==8 ? values.ReadUInt64() : values.ReadUInt32()).ToString("X");
        }
        var counts = new [] { TableIndex.TypeDef, TableIndex.TypeRef, TableIndex.ModuleRef,
            TableIndex.MethodDef, TableIndex.TypeSpec, TableIndex.MemberRef, TableIndex.MethodImpl }
            .ToDictionary(t => t.ToString(), t => md.GetTableRowCount(t));
        return new object[]{methods, slots, counts};
    }
}
'@
$methods, $slots, $counts = [Aspen77Oracle]::Read((Resolve-Path $Original).Path)
$il = @(Import-Csv (Join-Path $Delivery 'code/s77-il-fingerprints.csv'))
$tokens = @($il.token | Sort-Object -Unique)
if ($il.Count -ne $methods.Count -or $tokens.Count -ne $methods.Count) { throw 'Method population differs' }
foreach ($m in $il) {
    if ($methods[[convert]::ToInt32($m.token, 16)] -ne $m.il_sha256) { throw "Digest differs at $($m.token)" }
}
# corhdr.h, COR_VTABLE_* constants, dotnet/runtime/src/coreclr/inc/corhdr.h
$pairs = foreach ($r in (Import-Csv (Join-Path $Delivery 'code/s77-vtable-fixups.csv'))) {
    $raw = $slots[[convert]::ToInt32($r.slot,16)]
    $flags = [convert]::ToInt32($r.dwFlags,16)
    if ($raw -ne ('{0:X}/{1:X}' -f $flags, [convert]::ToInt32($r.method,16))) { throw "Slot differs at $($r.slot)" }
    $names = @()
    if ($flags -band 2) { $names += 'COR_VTABLE_64BIT' }
    if ($flags -band 8) { $names += 'COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN' }
    if ($flags -band 16) { $names += 'COR_VTABLE_CALL_MOST_DERIVED' }
    [ordered]@{slot=$r.slot; raw=$raw; expected=($names -join ','); actual=$r.flags_meaning; equal=(($names -join ',') -ceq $r.flags_meaning)}
}
[ordered]@{verified_il=$methods.Count; row_counts=$counts; slots=$pairs} | ConvertTo-Json -Depth 5
