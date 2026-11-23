param([Parameter(Mandatory)][string]$Original,[Parameter(Mandatory)][string]$Unit)
$ErrorActionPreference = 'Stop'
$hash = (Get-FileHash -LiteralPath $Original).Hash.ToLowerInvariant()
if ($hash -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') { throw 'Original SHA-256 mismatch' }
Add-Type -AssemblyName System.Reflection.Metadata
$rows = Import-Csv -LiteralPath (Join-Path $Unit 'code/s61-clauses.csv')
$stream = [IO.File]::OpenRead((Resolve-Path -LiteralPath $Original).Path)
$pe = [System.Reflection.PortableExecutable.PEReader]::new($stream)
try {
    $md = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
    $tokens = [System.Reflection.Metadata.Ecma335.MetadataTokens]
    $methods = foreach ($handle in $md.MethodDefinitions) {
        $d = $md.GetMethodDefinition($handle)
        if ($d.RelativeVirtualAddress -eq 0 -or ([int]$d.ImplAttributes -band 3) -ne 0) { continue }
        $block = [System.Reflection.Metadata.PEReaderExtensions]::GetMethodBody($pe, $d.RelativeVirtualAddress)
        $token = '0x{0:X8}' -f $tokens::GetToken([System.Reflection.Metadata.EntityHandle]$handle)
        foreach ($region in $block.ExceptionRegions) {
            if ($region.Kind -ne 'Filter') { continue }
            $table = @($rows | Where-Object { $_.method -eq $token -and $_.type -eq 'filter' -and [int]$_.handler_offset -eq $region.HandlerOffset })
            if ($table.Count -ne 1) { throw "Missing matching clause $token" }
            $bytes = $block.GetILBytes()
            [pscustomobject]@{
                method = $token
                filter_offset = $region.FilterOffset
                handler_offset = $region.HandlerOffset
                filter_first_opcode = '0x{0:X2}' -f $bytes[$region.FilterOffset]
                last_two_before_handler = [Convert]::ToHexString([byte[]]$bytes[($region.HandlerOffset-2)..($region.HandlerOffset-1)])
                catch_type_is_nil = $region.CatchType.IsNil
                delivered_class_token = $table[0].class_token
                delivered_filter_offset = $table[0].filter_offset
            }
        }
    }
    $alNotes = foreach ($path in @('calls.csv') + @(25,33,37,41,45 | ForEach-Object { "code/s$_-unresolved-native.csv" })) {
        $hit = @(Import-Csv -LiteralPath (Join-Path $Unit $path) | Where-Object { $_.caller -eq '0x20CC' -and $_.listing -like 'code/native.asm*' })
        if ($hit.Count -ne 1) { throw "No unique branch row at $path" }
        $parts = @('原件 jge 落空 -> 候选路径 al=1、实际 al=0、跳过=真', '注入 jge->jl -> 取跳，实际 al=1、跳过=假', '注入 0x28FE 立即数 1->2 -> 仍落空，候选路径 al=2、实际 al=0、跳过=真')
        [pscustomobject]@{path=$path; matching_states=@($parts | Where-Object { $hit[0].note.Contains($_) }).Count}
    }
    [pscustomobject]@{original_sha256=$hash; filters=@($methods); branch_notes=@($alNotes)} | ConvertTo-Json -Depth 5
} finally { $pe.Dispose(); $stream.Dispose() }
