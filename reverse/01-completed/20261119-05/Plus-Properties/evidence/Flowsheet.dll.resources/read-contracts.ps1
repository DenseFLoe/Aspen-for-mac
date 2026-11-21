param([switch]$Verify)
$ErrorActionPreference = 'Stop'
$root = (Get-Item $PSScriptRoot).Parent.Parent.Parent.FullName
$library = Join-Path $root '.local-tools/research/ilspycmd-9.1/tools/net8.0/any/Mono.Cecil.dll'
$null = [Reflection.Assembly]::LoadFrom($library)
$xeq = 'C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq'
$fw = Get-Content -LiteralPath (Join-Path $PSScriptRoot 'framework.json') -Raw -Encoding utf8 | ConvertFrom-Json
$keys = @(foreach ($page in $fw.sets[0].entries) {
    foreach ($node in $page.nodes) {
        foreach ($prop in $node.properties) {
            if ($prop.Value -cmatch '^\{x:Static res:ApwnResources\.(\w+)\}$') {$Matches[1]}
        }
    }
})
$targets = @(
    @{assembly='AspenTech.AspenPlus.MMControls';type='AspenTech.AspenPlus.MMControls.MMTabPageViewModel';members=@('info_var')},
    @{assembly='AspenTech.AspenPlus.Localization';type='AspenTech.AspenPlus.Localization.ApwnResources';members=@($keys | Sort-Object -Unique)}
)
$result = @(foreach ($target in $targets) {
    $path = Join-Path $xeq ($target.assembly+'.dll')
    $module = [Mono.Cecil.ModuleDefinition]::ReadModule($path)
    try {
        $owner = $module.GetType($target.type)
        $selected = @($owner.Properties | Where-Object {$_.Name -cin $target.members} | Sort-Object Name)
        if ($selected.Count -ne $target.members.Count) {throw "Missing referenced API on $owner"}
        $props = @(foreach ($item in $selected) {
            if (!$item.GetMethod) {throw "Not readable: $item"}
            [ordered]@{name=$item.Name;type=$item.PropertyType.FullName;token=('0x{0:X8}' -f $item.MetadataToken.ToInt32());getter=('0x{0:X8}' -f $item.GetMethod.MetadataToken.ToInt32());static=$item.GetMethod.IsStatic}
        })
        [ordered]@{assembly=$module.Assembly.FullName;path=$path;sha256=(Get-FileHash $path).Hash.ToLowerInvariant();owner=$owner.FullName;properties=$props}
    } finally {$module.Dispose()}
})
$bytes=[Text.UTF8Encoding]::new($false).GetBytes((ConvertTo-Json -InputObject $result -Depth 8))
$path=Join-Path $PSScriptRoot 'contracts.json'
if ($Verify) {
    if ([Convert]::ToBase64String($bytes) -cne [Convert]::ToBase64String([IO.File]::ReadAllBytes($path))) {throw 'Interface replay differs'}
} else {$file=[IO.File]::Open($path,[IO.FileMode]::CreateNew); try {$file.Write($bytes,0,$bytes.Length)} finally {$file.Dispose()}}
"External signatures only: $($keys.Count) localization uses and inherited info_var."
