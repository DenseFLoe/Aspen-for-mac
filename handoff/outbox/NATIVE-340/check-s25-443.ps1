param([Parameter(Mandatory)][string]$Original,[Parameter(Mandatory)][string]$Unit)
$ErrorActionPreference = 'Stop'
if ((Get-FileHash -LiteralPath $Original).Hash -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') { throw 'Unexpected input' }
Add-Type -AssemblyName System.Reflection.Metadata
$stream = [IO.File]::OpenRead((Resolve-Path -LiteralPath $Original).Path)
$pe = [System.Reflection.PortableExecutable.PEReader]::new($stream)
try {
    $md = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
    $tokens = [System.Reflection.Metadata.Ecma335.MetadataTokens]
    function Read-Bytes([int]$rva,[int]$length) {
        [byte[]]($pe.GetSectionData($rva).GetContent(0,$length))
    }
    function Get-IL([int]$rid) {
        $def = $md.GetMethodDefinition($tokens::MethodDefinitionHandle($rid))
        [byte[]]([System.Reflection.Metadata.PEReaderExtensions]::GetMethodBody($pe,$def.RelativeVirtualAddress).GetILBytes())
    }
    $body = [byte[]](Get-IL 0x30)
    $il = [Convert]::ToHexString($body)
    if ($il.Substring(6,74) -ne '7F56000004282F0000060D7F55000004282F00000609283900000A13041204281D00000A0A') { throw 'Unexpected producer or argument order' }
    if ($il.Substring(0x36*2,0x1e*2) -ne '064C1F686A584C0C06020829440000110B06254C1F106A584C2943000011') { throw 'Unexpected calli sites' }
    $parameters=[Runtime.InteropServices.RuntimeEnvironment].GetMethod('GetRuntimeInterfaceAsIntPtr').GetParameters().Name
    if (($parameters -join ',') -ne 'clsid,riid') { throw 'Unexpected framework signature' }
    $fields = foreach ($rid in 0x55,0x56) {
        $f = $md.GetFieldDefinition($tokens::FieldDefinitionHandle($rid))
        $rva = $f.GetRelativeVirtualAddress()
        [pscustomobject]@{ field='0x040000{0:X2}' -f $rid; name=$md.GetString($f.Name); rva='0x{0:X}' -f $rva; guid=[Guid]::new([byte[]](Read-Bytes $rva 16)).ToString() }
    }
    $signatures = foreach ($rid in 0x44,0x43) {
        $sig = $md.GetStandaloneSignature($tokens::StandaloneSignatureHandle($rid))
        [pscustomobject]@{ token='0x110000{0:X2}' -f $rid; body=[Convert]::ToHexString($md.GetBlobBytes($sig.Signature)) }
    }
    $modifiers = foreach ($rid in 0x14,0x18) {
        $t=$md.GetTypeReference($tokens::TypeReferenceHandle($rid))
        $md.GetString($t.Namespace) + '.' + $md.GetString($t.Name)
    }
    $producers = foreach ($rid in 0x39,0x1d) {
        $ref=$md.GetMemberReference($tokens::MemberReferenceHandle($rid))
        $t=$md.GetTypeReference([System.Reflection.Metadata.TypeReferenceHandle]::op_Explicit($ref.Parent))
        [pscustomobject]@{ member=$md.GetString($t.Namespace)+'.'+$md.GetString($t.Name)+'::'+$md.GetString($ref.Name); signature=[Convert]::ToHexString($md.GetBlobBytes($ref.Signature)) }
    }
    $insns = foreach ($pair in @(@(0x217f,5),@(0x2184,21),@(0x21a4,3),@(0x21a7,7),@(0x21ae,3),@(0x2874,146),@(0x29d0,8),@(0x48b0,2),@(0x61b8,8))) {
        [pscustomobject]@{ rva='0x{0:X}' -f $pair[0]; bytes=[Convert]::ToHexString([byte[]](Read-Bytes $pair[0] $pair[1])) }
    }
    $getSlot=[byte[]](Read-Bytes 0x29d0 8)
    $slot=0x29d0+7+[BitConverter]::ToInt32($getSlot,3)
    $section=$pe.PEHeaders.SectionHeaders | Where-Object { $slot -ge $_.VirtualAddress -and $slot -lt $_.VirtualAddress+$_.VirtualSize }
    if ($slot -ne 0x19b78 -or $section.Name -ne '.data' -or $slot-$section.VirtualAddress -lt $section.SizeOfRawData) { throw 'Unexpected callback storage' }
    $sectionFlags=[uint32]$section.SectionCharacteristics
    if ($sectionFlags -ne 0xc0000040u -or [Convert]::ToHexString([byte[]](Read-Bytes 0x28f3 14)) -ne '837A24007D0432C0EB0AB001EB06') { throw 'Unexpected section guard' }
    $calls=Import-Csv -LiteralPath (Join-Path $Unit 'calls.csv')
    $unresolved=@($calls | Where-Object class -eq 'unresolved')
    $fingerprints=Get-Content -Raw -LiteralPath (Join-Path $Unit 'code/s25-fingerprints.json') | ConvertFrom-Json -AsHashtable
    $bad=@(foreach ($entry in $fingerprints.GetEnumerator()) { if ((Get-FileHash -LiteralPath (Join-Path $Unit $entry.Key)).Hash -ne $entry.Value) { $entry.Key } })
    [pscustomobject]@{ps=$PSVersionTable.PSVersion.ToString();metadata_runtime=[System.Reflection.Metadata.MetadataReader].Assembly.FullName; method_IL=$il; guid_converter_IL=[Convert]::ToHexString([byte[]](Get-IL 0x2f)); fields=$fields; members=$producers; signature_modopts=$modifiers; signatures=$signatures; native_spans=$insns; callback_slot='0x{0:X}' -f $slot; slot_section=$section.Name; section_characteristics='0x{0:X8}' -f $sectionFlags; section_va=$section.VirtualAddress; section_virtual_size=$section.VirtualSize; section_raw_size=$section.SizeOfRawData; slot_section_offset=$slot-$section.VirtualAddress; unresolved_managed=@($unresolved | Where-Object kind -eq 'method').Count; unresolved_native=@($unresolved | Where-Object kind -eq 'native').Count; fingerprint_count=$fingerprints.Count; fingerprint_mismatches=$bad} | ConvertTo-Json -Depth 5
} finally { $pe.Dispose(); $stream.Dispose() }
