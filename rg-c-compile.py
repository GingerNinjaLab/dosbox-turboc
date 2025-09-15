#  _____      _              _____ _                       
# |  __ \    | |            / ____(_)                      
# | |__) |___| |_ _ __ ___ | |  __ _ _ __   __ _  ___ _ __ 
# |  _  // _ \ __| '__/ _ \| | |_ | | '_ \ / _` |/ _ \ '__|
# | | \ \  __/ |_| | | (_) | |__| | | | | | (_| |  __/ |   
# |_|  \_\___|\__|_|  \___/ \_____|_|_| |_|\__, |\___|_|   
#                                           __/ |          
#                                          |___/      
# RetroGinger - MSDOS - C Compiler
# ================================
# Purpose      : Compiling C for old 16-bit MSDOS machines on a modern OS
# Requirements : Python   - Wrapper to automate the compolation tasks
#                DOSBox   - DOS Machine emulator
#                Tource C - Borland Turbo C compiler files 
#                
# rg-c-compiler.py compileonly source test
#

import sys
import os
import subprocess
import time
import msvcrt

#Top level config
#EmulatorDosPath='C:\\dev\\dosbox-turboc'
EmulatorDosPath = os.getcwd()
EmulatorExePath='C:\\Program Files (x86)\\DOSBox-0.74-3\\DOSBox.exe'
DosBoxConfigFile="dosbox-0.74-3.conf"
DosBoxConfigTempFilePath=os.path.join(EmulatorDosPath,"rg-c-dosbox.conf")
ReadyFileTriggerFile="ready.inf"
WaitTimeout=5

print("RetroGinger - MSDOS - C Compiler")
print("================================")


if (len(sys.argv)!=4):
    print("Requires 3 arguments:")
    print("python .\\rg-c-compile.py <mode> <source> <test>")
    exit()

#Fetch arguments
Mode=sys.argv[1]
SourcePath=sys.argv[2]
SourceFile=sys.argv[3]

if Mode!="compileonly" and Mode!="compilerun":
    print("Specify mode: compileonly or compulerun")
    exit()


#Check DOSBOX config file
DosBoxConfigFilePath=os.path.join(EmulatorDosPath,DosBoxConfigFile)


if os.path.exists(DosBoxConfigFilePath):
    print("Generating DOSBOX config")

    DosBoxConfigCommands=f"""
    mount c {EmulatorDosPath}
    SET PATH=%PATH%;c:\\tc\\bin
    c:
    compile.bat
    """
    DosBoxConfigFileReader = open(DosBoxConfigFilePath, 'r')
    DosBoxConfigFileData = DosBoxConfigFileReader.read()
    DosBoxConfigFileReader.close()
    DosBoxConfigFileData=DosBoxConfigFileData.replace("#RG-COMPILER-COMMANDS#",DosBoxConfigCommands)

    DosBoxConfigFileWriter = open(DosBoxConfigTempFilePath, 'w')
    DosBoxConfigFileWriter.write(DosBoxConfigFileData)
    DosBoxConfigFileWriter.close()
else:
    print(f"DOSBOX Config file {DosBoxConfigFilePath} not found")


#Clear down ready for next run
ClearFilePath=os.path.join(EmulatorDosPath,ReadyFileTriggerFile)
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)
ClearFilePath=os.path.join(EmulatorDosPath,SourcePath,f"{SourceFile}.exe")
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)
ClearFilePath=os.path.join(EmulatorDosPath,SourcePath,f"{SourceFile}.cmp")
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)

#Launch DOSBox and compiler
print(f"Launching DOSBox and Compiler")
dosStartUp=""

if Mode=="compilerun":
    dosStartUp=f"""
IF EXIST {SourceFile}.exe CLS
IF EXIST {SourceFile}.exe {SourceFile}.exe
"""

DosTemplateCompileBat=f"""
@echo off
echo Compiling file {SourceFile}.c
cd {SourcePath}
tcc {SourceFile}.c > {SourceFile}.cmp
type {SourceFile}.cmp
echo Done > c:\\{ReadyFileTriggerFile}
echo %STDERR%
{dosStartUp}
"""

print(f"Generating compile.bat")
compilerBatPath = os.path.join(EmulatorDosPath, 'compile.bat')
fileWriter = open(compilerBatPath, 'w')
fileWriter.write(DosTemplateCompileBat)
fileWriter.close()



if Mode=="compileonly":
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = 6  # 6 = SW_MINIMIZE
    process = subprocess.Popen([EmulatorExePath,"-conf",DosBoxConfigTempFilePath],startupinfo=startupinfo)
else:
    DETACHED_PROCESS = 0x00000008
    process = subprocess.Popen([EmulatorExePath,"-conf",DosBoxConfigTempFilePath],creationflags=DETACHED_PROCESS,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)

print(f"Process PID: {process.pid}")
print(f"Waiting for completion")
checkLoop=False
wait=1.0
ReadyFileTriggerPath=os.path.join(EmulatorDosPath, ReadyFileTriggerFile)
while (checkLoop!=True):
    if os.path.exists(ReadyFileTriggerPath):
        checkLoop=True
    time.sleep(wait)
    print('.',end="")
    WaitTimeout-=1
    if WaitTimeout==0:
        print("Timeout, quitting")
        checkLoop=True

print(f"Complete")

if Mode=="compileonly":
    print(f"Closing emulator")
    process.terminate()

#Get compiler output
compilerOutputPath = os.path.join(EmulatorDosPath, SourcePath, f"{SourceFile}.cmp")
if os.path.exists(compilerOutputPath):
    compilerReportFile = open(compilerOutputPath, 'r')
    compilerReport = compilerReportFile.read()
    print(compilerReport)


if Mode=="compilerun":
    print("Waiting for process. q to quit")
    checkLoop=False
    while(checkLoop!=True):
        if msvcrt.kbhit():  # Check if a key is pressed
            key = msvcrt.getch()
            if key==b'q':
                process.terminate()
                checkLoop=True
