param([switch]$Verify)
$ErrorActionPreference='Stop'
$folder='C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms'
$name='AspenTech.AspenPlus.MMForms.Flowsheet'
$path=Join-Path $folder "$name.dll"
$main=[Reflection.Assembly]::LoadFrom($path)
$sha=(Get-FileHash $path).Hash.ToLowerInvariant()
if ($sha -cne 'aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac') {throw 'Wrong main hash'}
$culture=[Globalization.CultureInfo]::GetCultureInfo('en-US')
$satellite=$main.GetSatelliteAssembly($culture)
$actual=(Get-FileHash $satellite.Location).Hash.ToLowerInvariant()
if ($actual -cne 'd5edd484ef669276c47b41b867595027211ce07dd9da04147070eb481c09cab4') {throw 'Wrong satellite hash'}
$attrs=@([Reflection.CustomAttributeData]::GetCustomAttributes($main) | Where-Object {$_.AttributeType.FullName -eq 'System.Resources.NeutralResourcesLanguageAttribute'})
if ($attrs.Count -ne 1) {throw 'No unique fallback rule'}
$attrs=$attrs[0].ConstructorArguments
$fallback=[Resources.UltimateResourceFallbackLocation]($attrs[1].Value)
if ($attrs[0].Value -ne $culture.Name -or $fallback.ToString() -ne 'Satellite') {throw 'Unexpected fallback'}
$rm=[Resources.ResourceManager]::new("$name.g",$main)
try {
    $set=$rm.GetResourceSet($culture,$true,$false)
    $entries=@(foreach ($entry in $set.GetEnumerator()) {
        $stream=$entry.Value
        if ($stream -isnot [IO.Stream] -or $stream.Position -ne 0) {throw 'Not a fresh stream'}
        $hash=[Security.Cryptography.SHA256]::Create()
        try {$digest=[BitConverter]::ToString($hash.ComputeHash($stream)).Replace('-','').ToLowerInvariant()} finally {$hash.Dispose()}
        [pscustomobject][ordered]@{key=$entry.Key;sha256=$digest;bytes=$stream.Length}
    })
    $result=[ordered]@{main_sha256=$sha;neutral_culture=$attrs[0].Value;ultimate_fallback=$fallback.ToString();requested_culture=$culture.Name;
        satellite_path=$satellite.Location;satellite_sha256=$actual;base_name=$rm.BaseName;try_parents=$false;entries=@($entries | Sort-Object key)}
} finally {$rm.ReleaseAllResources()}
$bytes=[Text.UTF8Encoding]::new($false).GetBytes(($result | ConvertTo-Json -Depth 5))
$out=Join-Path $PSScriptRoot 'lookup.json'
if ($Verify) {if ([Convert]::ToBase64String($bytes) -cne [Convert]::ToBase64String([IO.File]::ReadAllBytes($out))) {throw 'ResourceManager replay differs'}}
else {$file=[IO.File]::Open($out,[IO.FileMode]::CreateNew); try {$file.Write($bytes,0,$bytes.Length)} finally {$file.Dispose()}}
"Non-GUI en-US ResourceManager: $($entries.Count) streams; fallback=$fallback."
