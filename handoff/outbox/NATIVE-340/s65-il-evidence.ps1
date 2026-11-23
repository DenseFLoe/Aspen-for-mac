param(
    [Parameter(Mandatory)][string] $Original,
    [Parameter(Mandatory)][string] $Unit
)
$ErrorActionPreference = 'Stop'
$sha = (Get-FileHash -Algorithm SHA256 -LiteralPath $Original).Hash.ToLowerInvariant()
if ($sha -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') {
    throw "Original SHA-256 mismatch: $sha"
}
$source = @'
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;

public static class AspenS65
{
    private static Dictionary<ushort, OpCode> Opcodes =
        typeof(OpCodes).GetFields(BindingFlags.Public | BindingFlags.Static)
        .Where(field => field.FieldType == typeof(OpCode))
        .Select(field => (OpCode) field.GetValue(null))
        .GroupBy(opcode => unchecked((ushort) opcode.Value))
        .ToDictionary(group => group.Key, group => group.First());

    private sealed class Instruction
    {
        public int Offset { get; set; }
        public string Name { get; set; }
        public int Operand { get; set; }
    }

    private static List<Instruction> Decode(byte[] il)
    {
        var instructions = new List<Instruction>();
        for (int pos = 0; pos < il.Length;)
        {
            int start = pos;
            ushort code = il[pos++];
            if (code == 0xfe) code = (ushort) (0xfe00 | il[pos++]);
            var opcode = Opcodes[code];
            int width;
            switch (opcode.OperandType)
            {
                case OperandType.InlineNone: width = 0; break;
                case OperandType.ShortInlineI:
                case OperandType.ShortInlineBrTarget:
                case OperandType.ShortInlineVar: width = 1; break;
                case OperandType.InlineVar: width = 2; break;
                case OperandType.InlineI8:
                case OperandType.InlineR: width = 8; break;
                case OperandType.InlineSwitch: width = 4 + 4 * BitConverter.ToInt32(il, pos); break;
                default: width = 4; break;
            }
            if (pos + width > il.Length) throw new InvalidDataException("Truncated instruction");
            instructions.Add(new Instruction {
                Offset = start, Name = opcode.Name,
                Operand = width == 4 ? BitConverter.ToInt32(il, pos) : 0
            });
            pos += width;
        }
        return instructions;
    }

    public static List<string> Read(string path)
    {
        using (var stream = File.OpenRead(path))
        using (var pe = new PEReader(stream))
        {
            const int firstTarget = 0x06000056, secondTarget = 0x06000057;
            var metadata = pe.GetMetadataReader();
            var lines = new List<string>();
            foreach (var handle in metadata.MethodDefinitions)
            {
                var method = metadata.GetMethodDefinition(handle);
                int token = MetadataTokens.GetToken(handle);
                if (method.RelativeVirtualAddress == 0 ||
                    (method.ImplAttributes & MethodImplAttributes.CodeTypeMask) != MethodImplAttributes.IL)
                    continue;
                var body = pe.GetMethodBody(method.RelativeVirtualAddress);
                var il = body.GetILBytes();
                var instructions = Decode(il);
                foreach (var region in body.ExceptionRegions)
                {
                    int semantic = region.Kind == ExceptionRegionKind.Catch
                        ? MetadataTokens.GetToken(region.CatchType)
                        : region.Kind == ExceptionRegionKind.Filter ? region.FilterOffset : -1;
                    lines.Add($"eh\t{token:X8}\t{region.Kind}\t{region.TryOffset}\t{region.TryLength}\t{region.HandlerOffset}\t{region.HandlerLength}\t{semantic}");
                    if (region.Kind == ExceptionRegionKind.Filter)
                        lines.Add($"filter\t{token:X8}\t{region.FilterOffset}\t{region.HandlerOffset}\t{il[region.FilterOffset]:X2}\t{il[region.HandlerOffset-2]:X2}{il[region.HandlerOffset-1]:X2}\t{region.CatchType.IsNil}");
                }
                if (token == firstTarget || token == secondTarget)
                {
                    var call = instructions.Single(i => i.Name == "calli");
                    var signature = metadata.GetStandaloneSignature(MetadataTokens.StandaloneSignatureHandle(call.Operand & 0x00ffffff));
                    lines.Add($"wrapper\t{token:X8}\t{call.Offset:X4}\t{call.Operand:X8}\t{Convert.ToHexString(metadata.GetBlobBytes(signature.Signature))}\t{string.Join(",", instructions.TakeWhile(i => i != call).Select(i => i.Name))}");
                }
                for (int index = 0; index < instructions.Count; index++)
                {
                    var ins = instructions[index];
                    if (ins.Operand != firstTarget && ins.Operand != secondTarget) continue;
                    if (ins.Name != "call" && ins.Name != "callvirt" && ins.Name != "ldftn" &&
                        ins.Name != "ldvirtftn" && ins.Name != "jmp" && ins.Name != "ldtoken")
                        continue;
                    var previous = instructions.Skip(Math.Max(0, index - 4)).Take(Math.Min(index, 4)).ToArray();
                    var args = string.Join(",", previous.Select(p => p.Offset.ToString("X4") + ":" + p.Name + ":" + p.Operand.ToString("X8")));
                    lines.Add($"site\t{ins.Operand:X8}\t{token:X8}\t{ins.Offset:X4}\t{ins.Name}\t{args}");
                }
            }
            return lines;
        }
    }
}
'@
Add-Type -TypeDefinition $source
$originalRows = [AspenS65]::Read((Resolve-Path -LiteralPath $Original).Path)
$clauses = Import-Csv -LiteralPath (Join-Path $Unit 'code/s65-eh-clauses.csv')
$candidateEh = @($clauses | ForEach-Object {
    $clause = $_
    $semantic = switch ($clause.last_field_role) {
        'type_token' { [Convert]::ToInt32($clause.last_field_value.Substring(2), 16) }
        'filter_offset' { [Convert]::ToInt32($clause.last_field_value.Substring(3), 16) }
        'raw' { -1 }
        default { throw "Unrecognized EH clause role: $($clause.last_field_role)" }
    }
    $method = $_.method.Substring(2).ToUpperInvariant()
    "eh`t$method`t$($_.kind)`t$($_.try_offset)`t$($_.try_length)`t$($_.handler_offset)`t$($_.handler_length)`t$semantic"
})
$originalEh = @($originalRows | Where-Object { $_ -like 'eh*' })
$ehMismatch = @(Compare-Object ($originalEh | Sort-Object) ($candidateEh | Sort-Object))
$callSites = @($originalRows | Where-Object { $_ -like 'site*' } | ForEach-Object {
    $parts = $_ -split "`t"
    [ordered]@{ wrapper = $parts[1]; caller = $parts[2]; offset = $parts[3]; opcode = $parts[4]; context = $parts[5] }
})
$candidateCalls = Import-Csv -LiteralPath (Join-Path $Unit 'code/s65-calli.csv')
$candidateSites = @($candidateCalls | Where-Object caller | ForEach-Object {
    "$($_.method.Substring(2).ToUpperInvariant())/$($_.caller.Substring(2).ToUpperInvariant())/$($_.caller_at.Substring(3).ToUpperInvariant())"
})
$siteDiff = @(Compare-Object ($callSites | ForEach-Object { "$($_.wrapper)/$($_.caller)/$($_.offset)" } | Sort-Object) ($candidateSites | Sort-Object))
[ordered]@{
    original_sha256 = $sha
    eh_clauses = $originalEh.Count
    candidate_eh_clauses = $candidateEh.Count
    eh_differences = $ehMismatch
    filters = @($originalRows | Where-Object { $_ -like 'filter*' })
    catch = @($originalEh | Where-Object { $_ -match "`tCatch`t" })
    wrappers = @($originalRows | Where-Object { $_ -like 'wrapper*' })
    original_sites = $callSites
    candidate_sites = $candidateSites
    site_differences = $siteDiff
} | ConvertTo-Json -Depth 9
