$ErrorActionPreference = 'Stop'
$prog = 'AspenTech.AspenPlus.WpfFindComponent.FindComponentDriver.410'
$results = [ordered]@{}
foreach ($view in 'Registry64','Registry32') {
    $base = [Microsoft.Win32.RegistryKey]::OpenBaseKey('ClassesRoot',$view)
    $clsid = $base.OpenSubKey("$prog\CLSID").GetValue('')
    $key = $base.OpenSubKey("CLSID\$clsid\InprocServer32")
    $entry = [ordered]@{ ProgID=$prog; CLSID=$clsid }; if ($key) { $entry.server=$key.GetValue(''); $entry.class=$key.GetValue('Class'); $entry.assembly=$key.GetValue('Assembly'); $entry.codeBase=$key.GetValue('CodeBase') }
    $results[$view]=$entry
}
$path = ([uri]($results.Registry64.codeBase.Replace('\','/'))).LocalPath
$f = [IO.File]::OpenRead($path)
$reader = [System.Reflection.PortableExecutable.PEReader]::new($f)
$md = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($reader)
function Get-AttributeData($handles) {
    foreach ($handle in $handles) {
        $attribute=$md.GetCustomAttribute($handle)
        if($attribute.Constructor.Kind -eq 'MemberReference') {
            $member=$md.GetMemberReference([System.Reflection.Metadata.MemberReferenceHandle]$attribute.Constructor)
            $parent=$md.GetTypeReference([System.Reflection.Metadata.TypeReferenceHandle]$member.Parent)
            [ordered]@{name=$md.GetString($parent.Name); value=[Convert]::ToHexString($md.GetBlobBytes($attribute.Value))}
        }
    }
}
$results.PE = [ordered]@{ sha256=(Get-FileHash $path).Hash; assemblyVersion=$md.GetAssemblyDefinition().Version.ToString(); psVersion=$PSVersionTable.PSVersion.ToString() }
foreach ($handle in $md.TypeDefinitions) {
    $type=$md.GetTypeDefinition($handle)
    $name=$md.GetString($type.Name)
    if ($name -in 'FindComponentDriver','IFindComponentDriver') {
        $methods = foreach ($methodHandle in $type.GetMethods()) {
            $method=$md.GetMethodDefinition($methodHandle)
            if ($md.GetString($method.Name) -eq 'ShowDialog') {
                [ordered]@{name='ShowDialog'; attributes=$method.Attributes.ToString(); signature=[Convert]::ToHexString($md.GetBlobBytes($method.Signature)); rva=('{0:X}' -f $method.RelativeVirtualAddress); params=@(foreach ($p in $method.GetParameters()) { $md.GetString($md.GetParameter($p).Name) }); customAttributes=@(Get-AttributeData $method.GetCustomAttributes())}
            }
        }
        $interfaces = foreach ($i in $type.GetInterfaceImplementations()) {
            $iface=$md.GetInterfaceImplementation($i)
            $md.GetString($md.GetTypeDefinition([System.Reflection.Metadata.TypeDefinitionHandle]$iface.Interface).Name)
        }
        $results[$name]=[ordered]@{namespace=$md.GetString($type.Namespace); attributes=$type.Attributes.ToString(); customAttributes=@(Get-AttributeData $type.GetCustomAttributes()); interfaces=@($interfaces); methods=@($methods)}
    }
}
$reader.Dispose()
$f.Dispose()
$results | ConvertTo-Json -Depth 7 | Set-Content -Encoding utf8NoBOM (Join-Path $PSScriptRoot 'registration.json')

