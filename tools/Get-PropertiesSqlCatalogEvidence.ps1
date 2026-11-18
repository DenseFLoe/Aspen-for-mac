param([Parameter(Mandatory=$true)][string]$OutputPath)
$ErrorActionPreference = 'Stop'
if (Test-Path -LiteralPath $OutputPath) { throw 'Output must be a new local path' }
$propertiesSql = [System.Data.SqlClient.SqlConnection]::new('Server=.;Database=master;Integrated Security=SSPI;Encrypt=False')
try {
    $propertiesSql.Open()
    $propertiesCmd = $propertiesSql.CreateCommand()
    $propertiesCmd.CommandText = "SELECT DB_NAME(database_id) AS database_name, type_desc, physical_name, size AS size_pages FROM sys.master_files WHERE DB_NAME(database_id) IN ('APESV150','APV150','FACTV150','NISTV150') ORDER BY database_id, file_id"
    $propertiesReader = $propertiesCmd.ExecuteReader()
    $propertiesRows = @()
    while ($propertiesReader.Read()) {
        $propertiesRows += [ordered]@{ database_name=$propertiesReader['database_name']; type_desc=$propertiesReader['type_desc']; physical_name=$propertiesReader['physical_name']; size_pages=$propertiesReader['size_pages'] }
    }
    $propertiesReader.Close()
    [ordered]@{ query_scope=$propertiesCmd.CommandText; time_utc=[DateTime]::UtcNow.ToString('o'); files=$propertiesRows } | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $OutputPath -Encoding utf8
    Write-Output "Read-only Properties SQL catalog: $($propertiesRows.Count) files"
} finally { $propertiesSql.Dispose() }
