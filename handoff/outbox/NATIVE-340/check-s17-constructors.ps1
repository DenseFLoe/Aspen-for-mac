param(
    [Parameter(Mandatory)][string]$Original,
    [Parameter(Mandatory)][string]$Unit
)
$ErrorActionPreference = 'Stop'
if ((Get-FileHash -LiteralPath $Original -Algorithm SHA256).Hash -ne '869c4b23598e433086fc72a0fc1c7bd50b3e280e0d84ad6742de28df8e804fec') {
    throw 'Unexpected original'
}
Add-Type -AssemblyName System.Reflection.Metadata
$stream = [IO.File]::OpenRead((Resolve-Path -LiteralPath $Original).Path)
$pe = [System.Reflection.PortableExecutable.PEReader]::new($stream)
try {
    $meta = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
    $sites = @(Import-Csv -LiteralPath (Join-Path $Unit 'code/newobj.csv') | Where-Object verdict -eq 'external-ctor')
    $calls = @(Import-Csv -LiteralPath (Join-Path $Unit 'calls.csv') | Where-Object listing -like 'code/newobj-sites.il#*')
    $records = foreach ($site in $sites) {
        $token = [Convert]::ToInt32($site.token,16)
        $reference = $meta.GetMemberReference([System.Reflection.Metadata.Ecma335.MetadataTokens]::MemberReferenceHandle($token -band 0xffffff))
        $name = $meta.GetString($reference.Name)
        $parent = $reference.Parent
        $typeBlob = ''
        $suffix = ''
        if ($parent.Kind -eq 'TypeSpecification') {
            $spec = $meta.GetTypeSpecification([System.Reflection.Metadata.TypeSpecificationHandle]::op_Explicit($parent))
            $typeBlob = [Convert]::ToHexString($meta.GetBlobBytes($spec.Signature))
            $bytes = $meta.GetBlobReader($spec.Signature)
            if ($bytes.ReadByte() -ne 0x15 -or $bytes.ReadByte() -ne 0x12) { throw 'Expected genericinst class' }
            $codedIndex = $bytes.ReadCompressedInteger()
            if (($codedIndex -band 3) -ne 1 -or $bytes.ReadCompressedInteger() -ne 1 -or $bytes.ReadByte() -ne 0x1c -or $bytes.RemainingBytes -ne 0) {
                throw 'Expected TypeRef instantiated with System.Object'
            }
            $typeHandle = [System.Reflection.Metadata.Ecma335.MetadataTokens]::TypeReferenceHandle($codedIndex -shr 2)
            $suffix = '<System.Object>'
        } else {
            $typeHandle = [System.Reflection.Metadata.TypeReferenceHandle]::op_Explicit($parent)
        }
        $type = $meta.GetTypeReference($typeHandle)
        $typeName = $meta.GetString($type.Namespace) + '.' + $meta.GetString($type.Name)
        if ($suffix) { $typeName = ($typeName -replace '`1$','') + $suffix }
        $scope = $meta.GetAssemblyReference([System.Reflection.Metadata.AssemblyReferenceHandle]::op_Explicit($type.ResolutionScope))
        $target = $typeName + '::' + $name
        $call = @($calls | Where-Object { $_.caller -eq $site.caller_token -and $_.note.Contains($site.il_offset) })
        if ($call.Count -ne 1) { throw 'Caller and IL offset must identify one call' }
        [pscustomobject]@{
            caller=$site.caller_token; offset=$site.il_offset; memberref=$site.token
            type_spec_signature=$typeBlob; method_signature=[Convert]::ToHexString($meta.GetBlobBytes($reference.Signature))
            assembly=$meta.GetString($scope.Name); expected_target=$target; candidate_target=$call[0].callee
            owner_and_name_match=$call[0].callee.StartsWith($target + ' (')
        }
    }
    [pscustomobject]@{
        external_sites=$records.Count
        mismatching_owner_or_name=@($records | Where-Object { -not $_.owner_and_name_match }).Count
        sites=$records
    } | ConvertTo-Json -Depth 4
} finally {
    $pe.Dispose()
    $stream.Dispose()
}
