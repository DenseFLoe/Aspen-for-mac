param([Parameter(Mandatory)][string]$InputList)
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = [Text.UTF8Encoding]::new($false)

function Get-Identity($reader, $entry, $keyHandle, [bool]$definition) {
    $bytes = $reader.GetBlobBytes($keyHandle)
    $token = 'null'
    if ($bytes.Length) {
        if ($definition -or (([int]$entry.Flags -band 1) -ne 0)) {
            $digest = [Security.Cryptography.SHA1]::HashData($bytes)
            $bytes = [byte[]]$digest[19..12]
        }
        $token = [Convert]::ToHexString($bytes).ToLowerInvariant()
    }
    $culture = $reader.GetString($entry.Culture)
    if (!$culture) { $culture = 'neutral' }
    [ordered]@{
        name = $reader.GetString($entry.Name)
        version = $entry.Version.ToString()
        culture = $culture
        public_key_token = $token
        content_type = ([int]$entry.Flags -band 3584)
        flags = [int]$entry.Flags
    }
}

foreach ($source in (Get-Content -LiteralPath $InputList -Encoding utf8 -Raw | ConvertFrom-Json)) {
    $stream = [IO.File]::OpenRead($source.path)
    try {
        $pe = [System.Reflection.PortableExecutable.PEReader]::new($stream)
        try {
            if (!$pe.HasMetadata) {
                @{sha256 = $source.sha256; skip = 'cli_without_metadata'} | ConvertTo-Json -Compress
                continue
            }
            $rd = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($pe)
            if (!$rd.IsAssembly) {
                @{sha256 = $source.sha256; skip = 'netmodule_without_assembly_definition'} | ConvertTo-Json -Compress
                continue
            }
            $def = $rd.GetAssemblyDefinition()
            $refs = @(foreach ($handle in $rd.AssemblyReferences) {
                $ref = $rd.GetAssemblyReference($handle)
                Get-Identity $rd $ref $ref.PublicKeyOrToken $false
            })
            [ordered]@{
                sha256 = $source.sha256
                identity = (Get-Identity $rd $def $def.PublicKey $true)
                refs = $refs
            } | ConvertTo-Json -Depth 4 -Compress
        } finally { $pe.Dispose() }
    } finally { $stream.Dispose() }
}
