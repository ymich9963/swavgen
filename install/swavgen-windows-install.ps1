$SWAVGEN_install_path = 'C:\Program Files\swavgen'
$SWAVGEN_exe_link = "https://github.com/ymich9963/swavgen/releases/latest/download/swavgen.exe"

if (Test-Path -Path $SWAVGEN_install_path) {
    Write-Output "Removing previously installed executable."
    Remove-Item $SWAVGEN_install_path -r # rm command
}

New-Item -Path $SWAVGEN_install_path -ItemType Directory | Out-Null # make new dir and suppress output
curl -fsSLO $SWAVGEN_exe_link
Move-Item swavgen.exe $SWAVGEN_install_path # mv command
Write-Output "Downloaded executable." # echo command

$Sys_Env_Path_Value = Get-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Environment\' -Name Path 

# Change the backslashes to frontslashes so that -split can work
$SWAVGEN_install_path_frontslash = $SWAVGEN_install_path -replace "\\","/"
$Sys_Env_Path_Value_frontslash = $Sys_Env_Path_Value.Path -replace "\\", "/"

# Check if the install path exists by splitting the Path variable value
$SWAVGEN_path_check = $Sys_Env_Path_Value_frontslash -split $SWAVGEN_install_path_frontslash | Measure-Object 

if ($SWAVGEN_path_check.Count -igt 1) {
    Write-Output "Detected previous Swavgen installation."
    Write-Output "Nothing was added to the system Path variable."
} else {
    Write-Output "Detected no previous Swavgen install."
    Write-Output "Adding executable to system Path environment variable."
    $New_Path_Value = $Sys_Env_Path_Value.Path + ";" + $SWAVGEN_install_path + ";" 
    Set-ItemProperty -Path 'HKLM:\SYSTEM\CurrentControlSet\Control\Session Manager\Environment\' -Name Path -Value $New_Path_Value # set the system environment variable for Swavgen 
}

Write-Output "Succesfully installed Swavgen."

Read-Host -Prompt "Press Enter to exit"

Exit

