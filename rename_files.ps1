param(
    [switch]$Apply
)

Write-Host "Scanning repository for files without extensions..." -ForegroundColor Cyan

$repoRoot = (Get-Location).Path

$files = Get-ChildItem -Path $repoRoot -Recurse -File | Where-Object {
    $_.Extension -eq '' -and
    $_.BaseName -notmatch '\.' -and
    $_.Name -notmatch '^\.' -and
    $_.FullName -notmatch '\\.git\\'
}

if ($files.Count -eq 0) {
    Write-Host "No extensionless files found." -ForegroundColor Green
    exit 0
}

$ops = @()

foreach ($f in $files) {
    $guess = $null
    try {
        $bytes = Get-Content -LiteralPath $f.FullName -Encoding Byte -TotalCount 4 -ErrorAction Stop
    } catch {
        $bytes = @()
    }

    try {
        $text = Get-Content -LiteralPath $f.FullName -Raw -ErrorAction Stop
    } catch {
        $text = ''
    }

    $sample = if ($text.Length -gt 32768) { $text.Substring(0,32768) } else { $text }

    if ($bytes.Count -ge 4 -and $bytes[0] -eq 0x7f -and $bytes[1] -eq 0x45 -and $bytes[2] -eq 0x4c -and $bytes[3] -eq 0x46) {
        $guess = '.exe'
    } elseif ($sample -match '#include\s+<iostream>' -or $sample -match 'using\s+namespace\s+std' -or $sample -match 'std::' -or $sample -match '<vector>' -or $sample -match '<string>' -or $sample -match '<fstream>') {
        $guess = '.cpp'
    } elseif ($sample -match '#include\s+<stdio.h>' -or $sample -match 'printf\s*\(' -or $sample -match 'scanf\s*\(' -or $sample -match '<stdlib.h>' -or $sample -match '<string.h>') {
        $guess = '.c'
    } else {
        Write-Host "Skipping (unknown type): $($f.FullName)" -ForegroundColor DarkYellow
    }

    if ($guess) {
        $newName = "$($f.Name)$guess"
        $newPath = Join-Path -Path $f.DirectoryName -ChildPath $newName
        $ops += [pscustomobject]@{ Old = $f.FullName; New = $newPath; Ext = $guess }
    }
}

if ($ops.Count -eq 0) {
    Write-Host "No safe rename candidates detected." -ForegroundColor Yellow
    exit 0
}

Write-Host "`nPlanned renames:" -ForegroundColor Cyan
$ops | ForEach-Object {
    Write-Host ("  {0}  ->  {1}" -f $_.Old, $_.New)
}

if (-not $Apply) {
    Write-Host "`nPreview only. Re-run with -Apply to perform the git mv operations." -ForegroundColor Green
    exit 0
}

Write-Host "`nStaging changes and committing..." -ForegroundColor Cyan
foreach ($op in $ops) {
    $old = $op.Old
    $new = $op.New
    Write-Host "Renaming `"$old`" -> `"$new`" ..." -ForegroundColor Cyan
    $gitResult = git mv -- "$old" "$new" 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-Host "git mv failed for $old -> $new" -ForegroundColor Red
        Write-Host $gitResult
    } else {
        Write-Host "Renamed." -ForegroundColor Green
    }
}

git add -A
git commit -m "Add extensions to previously extensionless files (via heuristic)" 2>&1
if ($LASTEXITCODE -eq 0) {
    Write-Host "Committed. Please push the changes." -ForegroundColor Green
} else {
    Write-Host "Commit failed or nothing to commit." -ForegroundColor Yellow
}
