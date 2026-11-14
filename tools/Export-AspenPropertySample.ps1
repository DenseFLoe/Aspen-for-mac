<# Read an explicit APED parameter plan using the installed Windows API.
   Run in Windows PowerShell 5.1. No credentials, keys or Aspen DLLs are bundled.
   Raw binary vectors retain their ordered compound pair and API metadata.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory=$true)][string]$PlanPath,
    [Parameter(Mandatory=$true)][string]$OutputPath,
    [string]$LibraryDirectory='C:\Program Files\AspenTech\AprSystem V15.0\PropertiesDatabase\Bin'
)
$ErrorActionPreference='Stop'
if(Test-Path -LiteralPath $OutputPath){throw 'Output already exists; choose a new path.'}
$plan=Get-Content -LiteralPath $PlanPath -Raw | ConvertFrom-Json
if($plan.Count -eq 0){throw 'The export plan is empty.'}
foreach($item in $plan){
    if($item.database -notin @('APV150','NISTV150','APESV150','FACTV150')){throw 'Unexpected database in plan.'}
    if(-not $item.bank -or -not $item.property -or $item.compound_index -notmatch '^\d+$'){
        throw 'Each plan item requires a bank, property and numeric compound_index.'
    }
}
[void][Reflection.Assembly]::LoadFrom((Join-Path $LibraryDirectory 'ApedGateway.dll'))
[void][Reflection.Assembly]::LoadFrom((Join-Path $LibraryDirectory 'ApedDataProvider.dll'))
$records=[Collections.Generic.List[object]]::new()
$failures=[Collections.Generic.List[object]]::new()
foreach($group in ($plan | Group-Object database)){
    $db=[AspenTech.APED.SqlServerDatabase]::new()
    try {
        # Empty SQL login fields select the current Windows identity.
        if(-not $db.Connect($group.Name,'.','','',$group.Name)){throw 'APED connection failed.'}
        $banks=$null
        $db.EnumerateDatabanks([ref]$banks)
        $byName=@{}
        foreach($bank in $banks){$byName[$bank.Name]=$bank}
        foreach($item in $group.Group){
            try {
                if(-not $byName.ContainsKey($item.bank)){throw 'Databank was not enumerated.'}
                $value=$null
                # In V15 this method also accepts the CompoundIndex of a duo.
                # The SQL plan supplies the actual ordered pair; the resulting
                # ICompound name alone is insufficient to identify a binary pair.
                $db.PropertyValueManager.GetUnaryPropertyValue(
                    $byName[$item.bank],[string]$item.compound_index,'CompoundIndex',
                    [string]$item.property,[ref]$value)
                if($null -eq $value -or $null -eq $value.Value){throw 'API returned no value.'}
                $property=$value.Property
                if($property.Name -ne $item.property -or $value.Databank.Name -ne $item.bank){
                    throw 'Returned provenance differs from the requested plan.'
                }
                $units=@($property.UnitsTypeList | ForEach-Object {
                    [ordered]@{row_id=$_.RowId;type=$_.UnitRowName;default_unit=$_.DefaultUOM}
                })
                $records.Add([ordered]@{
                    database=$item.database;bank=$item.bank;entity_id=$item.entity_id
                    compound_index=$item.compound_index;compounds=@($item.compounds)
                    interaction=$item.interaction;property=$property.Name
                    description=$property.Description;value=$value.Value
                    value_type=$value.Value.GetType().FullName;element_count=$property.ElementCount
                    labels=@($property.LabelList);label_ij=@($property.LabelIJArray)
                    label_ji=@($property.LabelJIArray);symmetry=@($property.SymmetryList)
                    units=$units;data_source_type=$value.DataSourceType
                    uncertainty=$value.Uncertainty;notes=$value.Notes
                })
            } catch {
                # Exception type is sufficient for a reusable diagnostic and
                # avoids logging provider-specific connection details.
                $failures.Add([ordered]@{request=$item;error_type=$_.Exception.GetType().FullName})
            }
        }
    } finally {$db.CloseConnection();$db.Dispose()}
}
$result=[ordered]@{
    format_version=1;created_utc=[DateTime]::UtcNow.ToString('o')
    api_version=[AspenTech.APED.SqlServerDatabase].Assembly.GetName().Version.ToString()
    requested=$plan.Count;exported=$records.Count;failed=$failures.Count
    records=@($records.ToArray());failures=@($failures.ToArray())
}
$json=ConvertTo-Json -InputObject $result -Depth 16
$absoluteOutput=$ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputPath)
$outputStream=[IO.File]::Open($absoluteOutput,[IO.FileMode]::CreateNew,[IO.FileAccess]::Write)
$writer=[IO.StreamWriter]::new($outputStream,[Text.UTF8Encoding]::new($false))
try {$writer.Write($json)} finally {$writer.Dispose()}
Write-Output "Requested=$($plan.Count); exported=$($records.Count); failed=$($failures.Count)"
if($failures.Count -gt 0){throw 'Some parameter reads failed; see the local output file.'}
