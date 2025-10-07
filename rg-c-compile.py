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
#                TASM     - Borland Turbo Assembler files (for inline assembly) 
# Setup        : Run the following command to install the required modules:
#
# pip install -r requirements.txt
#
# Running      :
# To run the program here are the command arguments:
#                
# rg-c-compiler.py <mode> <source subdirectory> <file1.c> <file2.c> <file3.c>...
# mode can be  : compileonly     - Compile the C file only
#                compilerun      - Compile the C file and run it is created
#                runonly         - Run the DosBox environment only and do not compile
#
# For example:
# rg-c-compiler.py compileonly source test.c
#

import sys
import os
import subprocess
import time
import keyboard
import psutil

#Top level config
#======================================================================================
EmulatorDosDataPath = os.getcwd()
EmulatorDosTCPath = "C:\\Emulators\\DosTc"
EmulatorExePath='C:\\Program Files (x86)\\DOSBox-0.74-3\\DOSBox.exe'
DosBoxConfigFile="dosbox-0.74-3.conf"
DosBoxConfigTempFilePath=os.path.join(EmulatorDosDataPath,"rg-c-dosbox.conf")
ReadyFileTriggerFile="ready.inf"
WaitTimeout=5
#======================================================================================

print("RetroGinger - MSDOS - C Compiler")
print("================================")

#Parse arguments
#======================================================================================
if (len(sys.argv)<4):
    print("Requires 3 arguments:")
    print("python .\\rg-c-compile.py <mode> <source> <file1.c> <file2.c> <file3.c>...")
    exit()
Mode=sys.argv[1]
SourcePath=sys.argv[2]
SourceFile=sys.argv[3]
SourceFile = SourceFile.replace(".c","")
UseMakeFile=False
if (len(sys.argv)>4):
    if sys.argv[4].lower()=="make":
        UseMakeFile=True

if Mode!="compileonly" and Mode!="compilerun" and Mode!="runonly":
    print("Specify mode: compileonly or compulerun")
    exit()



#Clear down ready for next run
#======================================================================================
ClearFilePath=os.path.join(EmulatorDosDataPath,ReadyFileTriggerFile)
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)
ClearFilePath=os.path.join(EmulatorDosDataPath,SourcePath,f"{SourceFile}.exe")
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)
ClearFilePath=os.path.join(EmulatorDosDataPath,SourcePath,f"{SourceFile}.cmp")
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)
ClearFilePath=os.path.join(EmulatorDosDataPath,"COMPILE.BAT")
if os.path.exists(ClearFilePath):
    os.remove(ClearFilePath)

#Check DOSBOX config file
#======================================================================================
DosBoxConfigFilePath=os.path.join(EmulatorDosDataPath,DosBoxConfigFile)
if os.path.exists(DosBoxConfigFilePath):
    print("Generating DOSBOX config")

    DosBoxConfigCommands=f"""
    mount c {EmulatorDosTCPath}
    mount d {EmulatorDosDataPath}
    SET PATH=%PATH%;c:\\tc;c:\\tasm
    D:
    COMPILE.BAT
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


#Generate startup files for Dos
#======================================================================================
dosStartUp=""

if Mode=="compilerun":
    print(f"Launching DOSBox and Compiler then run")
    dosStartUp=f"""
IF EXIST {SourceFile}.exe CLS
IF EXIST {SourceFile}.exe {SourceFile}.exe
"""

if Mode=="compileonly":
    print(f"Launching DOSBox and Compiler")

if Mode=="runonly":
    print(f"Launching DOSBox only")

CompileFileString=""
for i in range(3,len(sys.argv)):
    CompileFileString+=f" {sys.argv[i]}"

DosTemplateCompileBat=f"""
@echo off
echo Compiling file {SourceFile}.c
cd {SourcePath}
tcc -D__MSDOS__ {CompileFileString} > {SourceFile}.cmp
type {SourceFile}.cmp
echo Done > d:\\{ReadyFileTriggerFile}
echo %STDERR%
{dosStartUp}
"""

if UseMakeFile==True:
    DosTemplateCompileBat=f"""
@echo off
echo Compiling file {SourceFile}.c
cd {SourcePath}
make > {SourceFile}.cmp
type {SourceFile}.cmp
echo Done > d:\\{ReadyFileTriggerFile}
echo %STDERR%
{dosStartUp}
"""

if Mode=="runonly":
    print(f"Launching DOSBox only")
    DosTemplateCompileBat=f"""
@echo off
echo Run DosBox only
"""

print(f"Generating compile.bat")
compilerBatPath = os.path.join(EmulatorDosDataPath, 'compile.bat')
fileWriter = open(compilerBatPath, 'w')
fileWriter.write(DosTemplateCompileBat)
fileWriter.close()

#Launch DosBox
#======================================================================================
DETACHED_PROCESS = 0x00000008
if Mode=="compileonly":
    startupinfo = subprocess.STARTUPINFO()
    startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW
    startupinfo.wShowWindow = 6  # 6 = SW_MINIMIZE
    process = subprocess.Popen([EmulatorExePath,"-conf",DosBoxConfigTempFilePath],startupinfo=startupinfo)

if Mode=="compilerun":
    process = subprocess.Popen([EmulatorExePath,"-conf",DosBoxConfigTempFilePath],creationflags=DETACHED_PROCESS,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)

if Mode=="runonly":
    process = subprocess.Popen([EmulatorExePath,"-conf",DosBoxConfigTempFilePath],creationflags=DETACHED_PROCESS,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL)

print(f"Process PID: {process.pid}")

#Wait for DosBox and compilation to finish
#======================================================================================
print(f"Waiting for completion")
checkLoop=False
if (Mode=="runonly"):
    checkLoop=True

wait=1.0
ReadyFileTriggerPath=os.path.join(EmulatorDosDataPath, ReadyFileTriggerFile)
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
#======================================================================================
compilerOutputPath = os.path.join(EmulatorDosDataPath, SourcePath, f"{SourceFile}.cmp")
if os.path.exists(compilerOutputPath):
    compilerReportFile = open(compilerOutputPath, 'r')
    compilerReport = compilerReportFile.read()
    print(compilerReport)

#Wait for keyboard or DosBox termination
#======================================================================================
if Mode=="compilerun" or Mode=="runonly":
    print("Waiting for process. ctrl-alt-q to quit or close DosBox")
    checkLoop=False
    while(checkLoop!=True):

        #Check for process running
        foundProcess=False
        for proc in psutil.process_iter(['name']):
            if proc.pid==process.pid:
                foundProcess=True
        if foundProcess==False:
            checkLoop=True

        #Check for keypress
        if keyboard.is_pressed('q') and keyboard.is_pressed('alt') and keyboard.is_pressed('ctrl'):   
            process.terminate()
            checkLoop=True


