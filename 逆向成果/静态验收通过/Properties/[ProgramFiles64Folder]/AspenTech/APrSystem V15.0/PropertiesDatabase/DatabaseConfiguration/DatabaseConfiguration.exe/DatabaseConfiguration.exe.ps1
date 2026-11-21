# Regenerate the Windows GUI apphost for the adjacent managed entry assembly.
[CmdletBinding()]
param(
    [Parameter(Mandatory)] [string] $HostModelPath,
    [Parameter(Mandatory)] [string] $AppHostTemplate,
    [Parameter(Mandatory)] [string] $ManagedAssembly,
    [Parameter(Mandatory)] [string] $OutputDirectory
)

$ErrorActionPreference = 'Stop'
$hostModel = (Resolve-Path -LiteralPath $HostModelPath).ProviderPath
$template = (Resolve-Path -LiteralPath $AppHostTemplate).ProviderPath
$assembly = (Resolve-Path -LiteralPath $ManagedAssembly).ProviderPath
$output = (Resolve-Path -LiteralPath $OutputDirectory).ProviderPath
$managedName = 'DatabaseConfiguration.dll'
$templateHash = '9ecd7923139176a06d216b259e226108f484681ae34111c3d0c68407046fd5d2'

if ((Get-FileHash -LiteralPath $template -Algorithm SHA256).Hash -ne $templateHash) {
    throw 'Use apphost.exe from Microsoft.NETCore.App.Host.win-x64 8.0.8.'
}
if ([System.IO.Path]::GetFileName($assembly) -cne $managedName) {
    throw "Expected $managedName as the managed assembly and Windows resource input."
}

Add-Type -LiteralPath $hostModel
$destination = Join-Path $output 'DatabaseConfiguration.exe'
$temporary = Join-Path $output ([System.IO.Path]::GetRandomFileName())
try {
    [Microsoft.NET.HostModel.AppHost.HostWriter]::CreateAppHost(
        $template, $temporary, $managedName, $true, $assembly, $false
    )
    [System.IO.File]::Move($temporary, $destination)
}
finally {
    [System.IO.File]::Delete($temporary)
}
