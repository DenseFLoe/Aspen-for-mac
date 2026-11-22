$ErrorActionPreference = 'Stop'
$dir = Join-Path $PSScriptRoot '../inbox/ROUNDTRIP-9'
$expected = @(Import-Csv -LiteralPath (Join-Path $dir 'scheme-C.csv'))
$rows = @(Import-Csv -LiteralPath (Join-Path $dir 'methods.csv'))
if ($expected.Count -ne 9 -or $rows.Count -ne 267) { throw 'Expected 9 assemblies and 267 method rows' }
$seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach ($r in $rows) {
    if ($r.sample -cnotin $expected.sample -or !$r.method -or !$seen.Add("$($r.sample)/$($r.method)")) { throw "Unknown or duplicate method: $($r.method)" }
    if ($r.raw -cnotin 'equal','different' -or ($r.rule -and $r.rule -notin '1','2','3','4','5')) { throw 'Invalid raw result or rule' }
    if ($r.raw -ceq 'different' -and [string]::IsNullOrWhiteSpace($r.evidence)) { throw "Missing evidence: $($r.method)" }
    if ($r.raw -ceq 'equal' -and $r.rule) { throw "Unexpected rule on an equal method: $($r.method)" }
}
if (@($rows | Where-Object raw -ceq 'equal').Count -ne 246) { throw 'Raw baseline differs from PR 372; upstream reconciliation required' }
foreach ($sample in $expected) {
    $matched = @($rows | Where-Object sample -ceq $sample.sample)
    if ($matched.Count -eq 0) { throw "Missing assembly $($sample.sample)" }
    $equal = @($matched | Where-Object raw -ceq 'equal').Count
    $waived = @($matched | Where-Object { $_.raw -ceq 'different' -and $_.rule -in '1','2','5' }).Count
    [pscustomobject]@{sample=$sample.sample; methods=$matched.Count; raw_equal=$equal; adjusted_equal=$equal+$waived; review=$matched.Count-$equal-$waived}
}
