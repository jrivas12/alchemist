<#
Preview and optionally apply renames for files that currently have no extension.
Usage:
  # Preview only
  .\add_missing_extensions.ps1

  # Apply renames (uses `git mv` to preserve history)
  .\add_missing_extensions.ps1 -Apply

The script:
 - Scans the repo for files with no extension.
 - Heuristically inspects contents:
    * ELF magic -> .exe
    * C++ indicator (#include <iostream>, std::, using namespace, <vector>, etc.) -> .cpp
    * C indicator (#include <stdio.h>, printf, scanf, .c style includes) -> .c
 - Prints a preview. If -Apply specified it runs `git mv` for each candidate.
#>

param(
    [switch]$Apply
)

Write-Host "Scanning repository for files without extensions..." -ForegroundColor Cyan

$repoRoot = (Get-Location).Path

# Find files without a dot in the base name (ignores directories)
$files = Get-ChildItem -Path $repoRoot -Recurse -File |
    Where-Object {
        # ignore git internals and hidden stuff
        $_.FullName -notmatch '\\.git\\' -and
        $_.Name -notmatch '^\.' -and
        (-not ($_.BaseName -match '\.')) -and
        ($_.Extension -eq '')
    }

if ($files.Count -eq 0) {
    Write-Host "No extensionless files found." -ForegroundColor Green
    exit 0
}

$ops = @()

foreach ($f in $files) {
    $guess = $null
    # Try first 4 bytes for ELF magic
    try {
        $bytes = Get-Content -LiteralPath $f.FullName -Encoding Byte -TotalCount 4 -ErrorAction Stop
    } catch {
        $bytes = @()
    }

    if ($bytes.Count -ge 4 -and $bytes[0] -eq 0x7f -and $bytes[1] -eq 0x45 -and $bytes[2] -eq 0x4c -and $bytes[3] -eq 0x46) {
        # ELF binary -- on Windows repo we commonly want .exe for build artifact
        $guess = '.exe'
    } else {
        # Read as text for heuristics (limit to 32KB)
        try {
            $text = Get-Content -LiteralPath $f.FullName -Raw -ErrorAction Stop
        } catch {
            $text = ''
        }
        $sample = if ($text.Length -gt 32768) { $text.Substring(0,32768) } else { $text }

        if ($sample -match '#include\s+<iostream>' -or $sample -match 'using\s+namespace\s+std' -or $sample -match 'std::' -or $sample -match '<vector>' -or $sample -match '<string>' -or $sample -match '<fstream>') {
            $guess = '.cpp'
        } elseif ($sample -match '#include\s+<stdio.h>' -or $sample -match 'printf\s*\(' -or $sample -match 'scanf\s*\(' -or $sample -match '<stdlib.h>' -or $sample -match '<string.h>') {
            $guess = '.c'
        } elseif ($f.Name -match 'credit_App') {
            # special-case: we observed this is an ELF binary
            $guess = '.exe'
        } else {
            # fallback: unknown — do not rename automatically
            $guess = $null
        }
    }

    if ($guess) {
        $newName = "$($f.Name)$guess"
        $newPath = Join-Path -Path $f.DirectoryName -ChildPath $newName
        $ops += [pscustomobject]@{ Old = $f.FullName; New = $newPath; Ext = $guess }
    } else {
        Write-Host "Skipping (unknown type): $($f.FullName)" -ForegroundColor DarkYellow
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

# Apply renames using git mv to preserve history
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

Write-Host "`nStaging changes and committing..." -ForegroundColor Cyan
git add -A
git commit -m "Add proper extensions to extensionless files (heuristic)" 2>&1
if ($LASTEXITCODE -eq 0) {
    Write-Host "Committed. Please push the changes." -ForegroundColor Green
} else {
    Write-Host "Commit failed or nothing to commit." -ForegroundColor Yellow
}