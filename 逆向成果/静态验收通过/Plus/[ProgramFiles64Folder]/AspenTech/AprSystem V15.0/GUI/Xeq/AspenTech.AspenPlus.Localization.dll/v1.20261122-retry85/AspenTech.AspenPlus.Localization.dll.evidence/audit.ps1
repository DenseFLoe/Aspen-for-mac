param([string]$Cecil,[string]$Original,[string]$Rebuilt)
$ErrorActionPreference='Stop'
Add-Type -Path $Cecil
$refs = @(Get-ChildItem -LiteralPath "$PSHOME/ref" -Filter '*.dll' | ForEach-Object FullName)
Add-Type -Path "$PSScriptRoot/LocalizationAudit.cs" -ReferencedAssemblies ($refs + $Cecil)
if($Rebuilt){[LocalizationAudit]::Compare($Original,$Rebuilt)} else {[LocalizationAudit]::Patterns($Original)}
