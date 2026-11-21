param([switch]$Verify)
$ErrorActionPreference = 'Stop'
$root = (Get-Item $PSScriptRoot).Parent.Parent.Parent.FullName
$source = 'C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/WPFForms/AspenTech.AspenPlus.MMForms.Flowsheet.dll'
$expected = 'aba9d5c58c1cbe4d0ee5584ea7c36ee8dd8be4196816c919151895adfe8b2bac'
if ((Get-FileHash $source).Hash -ne $expected) {throw 'Unexpected main DLL'}
$library = Join-Path $root '.local-tools/research/ilspycmd-9.1/tools/net8.0/any/Mono.Cecil.dll'
$cecil = [Reflection.Assembly]::LoadFrom($library)
$module = [Mono.Cecil.ModuleDefinition]::ReadModule($source)
function Token($member) { '0x{0:X8}' -f $member.MetadataToken.ToInt32() }
$names = 'MMFlowsh_Input','MMFlowsh_Input_Flowsh','MMFlowsh_ObjMan'
$types = @(foreach ($type in $module.GetTypes()) {
    if ($type.FullName -notlike '*MMFlowsh_*') {continue}
    $properties = @(foreach ($prop in $type.Properties) {
        [ordered]@{name=$prop.Name;type=$prop.PropertyType.FullName;token=(Token $prop);getter=if($prop.GetMethod){Token $prop.GetMethod};setter=if($prop.SetMethod){Token $prop.SetMethod}}
    })
    $fields = @(foreach ($field in $type.Fields) {
        [ordered]@{name=$field.Name;type=$field.FieldType.FullName;token=(Token $field)}
    })
    $methods = @(foreach ($method in $type.Methods) {
        if ($type.Name -notin $names) {continue}
        $inst = @(foreach ($item in $method.Body.Instructions) {
            $operand = $item.Operand
            $ref = $null
            if ($operand -is [Mono.Cecil.Cil.Instruction[]]) {$operand=@($operand | ForEach-Object Offset)}
            elseif ($operand -is [Mono.Cecil.Cil.Instruction]) {$operand=$operand.Offset}
            elseif ($null -ne $operand) {
                if ($operand -is [Mono.Cecil.IMetadataTokenProvider]) {$ref=Token $operand}
                $operand=$operand.ToString()
            }
            [ordered]@{offset=$item.Offset;op=$item.OpCode.Name;operand=$operand;ref=$ref}
        })
        [ordered]@{name=$method.Name;token=(Token $method);signature=$method.FullName;instructions=$inst}
    })
    [ordered]@{type=$type.FullName;base=$type.BaseType.FullName;interfaces=@($type.Interfaces | ForEach-Object {$_.InterfaceType.FullName});properties=$properties;fields=$fields;view_methods=$methods}
})
$report = [ordered]@{source=$source;sha256=$expected;cecil=$cecil.FullName;cecil_sha256=(Get-FileHash $library).Hash;types=$types}
$module.Dispose()
$bytes = [Text.UTF8Encoding]::new($false).GetBytes(($report | ConvertTo-Json -Depth 10))
$path = Join-Path $PSScriptRoot 'ui-il.json'
if ($Verify) {
    if ([Convert]::ToBase64String($bytes) -cne [Convert]::ToBase64String([IO.File]::ReadAllBytes($path))) {throw 'IL replay differs'}
} else {$file=[IO.File]::Open($path,[IO.FileMode]::CreateNew); try {$file.Write($bytes,0,$bytes.Length)} finally {$file.Dispose()}}
"IL indexed for three view classes; metadata for $($types.Count) related types."

