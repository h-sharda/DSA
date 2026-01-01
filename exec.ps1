param(
    [string]$cppFile,
    [string]$inputFile = ".\input.txt"
    [string]$outputFile = ".\output.txt"
)

# Compile
g++ $cppFile -o test

# Run with input piped in
Get-Content $inputFile | .\test.exe | Set-Content $outputFile

# Clean up
Remove-Item .\test.exe -Force
