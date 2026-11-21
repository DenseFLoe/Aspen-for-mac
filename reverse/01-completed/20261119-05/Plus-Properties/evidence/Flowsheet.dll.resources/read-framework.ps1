param([switch]$Verify)
$ErrorActionPreference = 'Stop'
$folder = 'C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms'
$name = 'AspenTech.AspenPlus.MMForms.Flowsheet'
$mainPath = Join-Path $folder "$name.dll"
$satPath = Join-Path $folder "en-US/$name.resources.dll"
function Digest([byte[]]$bytes) {
    $sha = [Security.Cryptography.SHA256]::Create()
    try {[BitConverter]::ToString($sha.ComputeHash($bytes)).Replace('-','').ToLowerInvariant()} finally {$sha.Dispose()}
}
if ((Get-FileHash $mainPath).Hash -ne 'aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac' -or
    (Get-FileHash $satPath).Hash -ne 'd5edd484ef669276c47b41b867595027211ce07dd9da04147070eb481c09cab4') {throw 'Unexpected source'}
Add-Type -AssemblyName PresentationFramework
$wpf = [System.Windows.FrameworkElement].Assembly
$readerType = $wpf.GetType('System.Windows.Markup.BamlReader',$true)
$flags = [Reflection.BindingFlags]'Public,NonPublic,Instance'
function Node($reader) {
    $node = [ordered]@{}
    foreach ($key in 'NodeType','Name','LocalName','Prefix','Value','XmlNamespace','ConnectionId') {
        $field = $readerType.GetProperty($key,$flags).GetValue($reader,$null)
        $node[$key] = if ($field -is [Enum]) {$field.ToString()} else {$field}
    }
    $node
}
$main = [Reflection.Assembly]::LoadFrom($mainPath)
$sat = [Reflection.Assembly]::LoadFrom($satPath)
$loaded = [Collections.Generic.Dictionary[string,string]]::new()
$resolver = [ResolveEventHandler]{
    param($sender,$eventArgs)
    $ask = [Reflection.AssemblyName]::new($eventArgs.Name)
    if ($ask.Name -ceq $main.GetName().Name) {return $main}
    if ($ask.Name -notmatch '^[A-Za-z0-9_.-]+$' -or $ask.CultureName) {return $null}
    foreach ($dir in @($folder,(Split-Path $folder))) {
        $candidate = Join-Path $dir ($ask.Name+'.dll')
        if ([IO.File]::Exists($candidate) -and [Reflection.AssemblyName]::ReferenceMatchesDefinition($ask,[Reflection.AssemblyName]::GetAssemblyName($candidate))) {
            $loaded[$ask.Name]=$candidate
            return [Reflection.Assembly]::LoadFrom($candidate)
        }
    }
    return $null
}
[AppDomain]::CurrentDomain.add_AssemblyResolve($resolver)
try {
    $sets = @(foreach ($manifest in $sat.GetManifestResourceNames()) {
        $stream = $sat.GetManifestResourceStream($manifest)
        $memory = [IO.MemoryStream]::new()
        $stream.CopyTo($memory)
        $stream.Dispose()
        $block = $memory.ToArray()
        $memory.Position = 0
        $rr = [Resources.ResourceReader]::new($memory)
        $enum = $rr.GetEnumerator()
        $entries = @(while ($enum.MoveNext()) {
            $key = $enum.Key
            $kind = $null
            $wire = $null
            $rr.GetResourceData($key,[ref]$kind,[ref]$wire)
            if ($kind -cne 'ResourceTypeCode.Stream' -or [BitConverter]::ToInt32($wire,0) -ne $wire.Length-4) {throw $key}
            $data = [IO.MemoryStream]::new([byte[]]$wire[4..($wire.Length-1)],$false)
            $reader = $readerType.GetConstructor($flags,$null,@([IO.Stream]),$null).Invoke(@($data))
            $read = $readerType.GetMethod('Read',$flags)
            $first = $readerType.GetMethod('MoveToFirstProperty',$flags)
            $next = $readerType.GetMethod('MoveToNextProperty',$flags)
            $nodes = @(while ($read.Invoke($reader,$null)) {
                $record = Node $reader
                $record['properties'] = @(if ($first.Invoke($reader,$null)) {
                    do {Node $reader} while ($next.Invoke($reader,$null))
                })
                $record
            })
            if ($nodes[-1].NodeType -ne 'EndDocument' -or $data.Position -ne $data.Length) {throw "BAML EOF: $key"}
            [ordered]@{key=$key;kind=$kind;bytes=$data.Length;sha256=(Digest $data.ToArray());wire_sha256=(Digest $wire);nodes=$nodes}
            $data.Dispose()
        })
        $rr.Close()
        [ordered]@{manifest=$manifest;sha256=(Digest $block);entries=@($entries | Sort-Object key)}
    })
} finally {[AppDomain]::CurrentDomain.remove_AssemblyResolve($resolver)}
$report = [ordered]@{main_assembly=$main.FullName;main_resources=@($main.GetManifestResourceNames());satellite_assembly=$sat.FullName;wpf=$wpf.FullName;wpf_path=$wpf.Location;wpf_sha256=(Get-FileHash $wpf.Location).Hash;ps=$PSVersionTable.PSVersion.ToString();sets=$sets}
$bytes = [Text.UTF8Encoding]::new($false).GetBytes(($report | ConvertTo-Json -Depth 12))
$path = Join-Path $PSScriptRoot 'framework.json'
if ($Verify) {if ((Digest $bytes) -cne (Digest ([IO.File]::ReadAllBytes($path)))) {throw 'Framework replay differs'}}
else {$file=[IO.File]::Open($path,[IO.FileMode]::CreateNew); try {$file.Write($bytes,0,$bytes.Length)} finally {$file.Dispose()}}
"Framework read to EOF: $($entries.Count) streams; $($nodes.Count) nodes on last page."

