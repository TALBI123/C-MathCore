
# ==========================================
#           POLYNOME BUILD SCRIPT
# ==========================================

# ==========================================
#              CONFIGURATION
# ==========================================

$ErrorActionPreference = "Stop"

# Project paths
$ProjectRoot = Split-Path -Parent $PSScriptRoot
$BuildDir = Join-Path $ProjectRoot "build"
$Executable = Join-Path $BuildDir "polynome.exe"

# Compiler configuration
$Compiler = "gcc"

$CompilerFlags = @(
    "-Wall"
    "-Wextra"
    "-Iinclude"
)

# Source files
$SourceFiles = @(
    "app/main.c"
    "src/polynomes/operation.c"
    "src/polynomes/polynome.c"
    "src/polynomes/terme.c"
)


# ==========================================
#               BUILD PROCESS
# ==========================================

Write-Host "`n==========================================" -ForegroundColor Cyan
Write-Host "           POLYNOME BUILD SYSTEM" -ForegroundColor Cyan
Write-Host "==========================================" -ForegroundColor Cyan


# STEP 1: Check GCC
Write-Host "`n[1/4] Checking GCC compiler..." -ForegroundColor Yellow

if (!(Get-Command $Compiler -ErrorAction SilentlyContinue)) {
    Write-Host "[ERROR] GCC compiler not found!" -ForegroundColor Red
    exit 1
}

Write-Host "[SUCCESS] GCC is available." -ForegroundColor Green


# STEP 2: Create build directory
Write-Host "`n[2/4] Checking build directory..." -ForegroundColor Yellow

if (!(Test-Path $BuildDir)) {

    New-Item -ItemType Directory -Path $BuildDir | Out-Null

    Write-Host "[SUCCESS] Build directory created." -ForegroundColor Green

} else {

    Write-Host "[INFO] Build directory already exists." -ForegroundColor DarkCyan
}


# STEP 3: Compile project
Write-Host "`n[3/4] Compiling project..." -ForegroundColor Yellow

Push-Location $ProjectRoot

try {

    & $Compiler @CompilerFlags @SourceFiles -o $Executable

    if ($LASTEXITCODE -ne 0) {
        Write-Host "[ERROR] Compilation failed!" -ForegroundColor Red
        exit 1
    }

    Write-Host "[SUCCESS] Compilation completed." -ForegroundColor Green

}
finally {
    Pop-Location
}


# STEP 4: Execute application
Write-Host "`n[4/4] Running application..." -ForegroundColor Yellow

Write-Host "`n========== PROGRAM OUTPUT ==========" -ForegroundColor Cyan

& $Executable

if ($LASTEXITCODE -ne 0) {
    Write-Host "[ERROR] Program execution failed!" -ForegroundColor Red
    exit 1
}

Write-Host "`n====================================" -ForegroundColor Cyan

Write-Host "`n[SUCCESS] Build and execution completed!" -ForegroundColor Green
