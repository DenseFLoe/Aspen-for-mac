<# Export APED through the installed read API. Run with Windows PowerShell 5.1.
   Each database runs independently. Existing output directories are refused.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)]
    [ValidateSet('APV150','NISTV150','APESV150','FACTV150')][string]$Database,
    [Parameter(Mandatory=$true)][string]$OutputDirectory,
    [string]$LibraryDirectory='C:\Program Files\AspenTech\AprSystem V15.0\PropertiesDatabase\Bin',
    [ValidateSet('parameters','storage')][string]$Mode='parameters',
    [int]$Limit=0
)
$ErrorActionPreference='Stop'
if(Test-Path -LiteralPath $OutputDirectory){throw 'Choose a new output directory.'}
$libraries=@('ApedGateway.dll','ApedDataProvider.dll') | ForEach-Object {
    $path=Join-Path $LibraryDirectory $_
    [void][Reflection.Assembly]::LoadFrom($path)
    $path
}
Add-Type -Path (Join-Path $PSScriptRoot 'AspenDatabaseExporter.cs') -ReferencedAssemblies (
    $libraries + @('System.Data.dll','System.Web.Extensions.dll','System.Core.dll'))
$absoluteOutput=$ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputDirectory)
if($Mode -eq 'storage'){
    [AspenDatabaseExporter]::RunStorage($Database,$absoluteOutput,$Limit)
}else{
    [AspenDatabaseExporter]::Run($Database,$absoluteOutput,$Limit)
}
