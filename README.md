DosBox-TurboC  
# Compiling C for old 16-bit MSDOS machines on a modern OS 

Requirements:  
* Python  - Wrapper to automate the compolation tasks

* DOSBox  - DOS Machine emulator  

* Borland Turbo C Version 2.0 - The 16-bit compiler with attitude!

* TASM     - Borland Turbo Assembler files (for inline assembly) 

# Overview
You do all your lovely C stuff in your prefered code editor on your modern OS. When you want to compile you run a Python script that performs the following operations:  

* Parse arguments
* Clear down ready for next run
* Check DOSBOX config file
* Generate startup files for Dos
* Launch DosBox
* Wait for DosBox and compilation to finish
* Get compiler output
* Wait for keyboard or DosBox termination

When DosBox runs it has the following local drives mounted:  


| DOSBox Drive | Example Host path | Purpose                                 |
|--------------|-------------------|-----------------------------------------|
| C:           | c:\emulator\dosboxtc | Path that contains the Turbo C files |
| D:           | d:\dev\yourcode      | Path to your source code             |
| Z:           | -                    | The default DosBox startup drive     |





# Setup  
To configure the environment perform the following steps.  
Install Python and DosBox.  

Locate the default coinfig file for DosBox, Typically located in the path:
%appdata%\Local\DosBox  
In the example here is it called 'dosbox-0.74-3.conf'  
Copy this file into the root of the dosbox-turboc directory (this one)  
Ensure that the file 'dosbox-0.74-3.conf' and the path to the EXE for DosBox are updated in the rg-c-compile.py file:
```
EmulatorExePath='C:\\Program Files (x86)\\DOSBox-0.74-3\\DOSBox.exe'  
DosBoxConfigFile="dosbox-0.74-3.conf"  
```

Open the DosBox config file you copied and locate the [autoexec] section  
The default should look something like this:

```
[autoexec]  
# Lines in this section will be run at startup.  
# You can put your MOUNT lines here.  
```

Add the #RG-COMPILER-COMMANDS# tag to the end of the commands:  
```
[autoexec]  
# Lines in this section will be run at startup.  
# You can put your MOUNT lines here.  
#RG-COMPILER-COMMANDS#  
```
That will allow the program to automate each launch of DosBox.

You should then be able to launch DosBox using the following command:  

```
python .\rg-c-compile.py runonly source test.c utils.c    
```
That should open your stadnard DosBox environment as managed by this program. From here you can then start the install process of Turbo C.  

To install the Python modules issue the following command:  
```
pip install -r requirements.txt   
```

Next get hold of a copy of Borland Turbo C Version 2.0  
The program will typically be in a series of .img files (like 720k flopy images for eample.) Using 7zip decompress these files into a seperate directory.  

Make a temp folder called tcsetup.  
Unzip 7z file to temp folder
That should have something like:  
* disk01.img  
* disk02.img  
* disk03.img  

Using 7Zip on each file and extract here for each img file.
That should result in a temp folder with all the setup files.  

Run the DosBox emulator and cd into the tcsetup folder.  
You can then install the program into the c:\TC folder.   

Next get hold of a copy of Borland Turbo Assembler 2.0 files 
The program will typically be in a series of .img files (like 360k flopy images for eample.) Using 7zip decompress these files into a seperate directory.  

Make a temp folder called tcsetup.  
Unzip 7z file to temp folder
That should have something like:  
* disk01.img  
* disk02.img  

Using 7Zip on each file and extract here for each img file.
That should result in a temp folder with all the setup files.  

Run the DosBox emulator and cd into the tcsetup folder.  
You can then install the program into the c:\TASM folder.    

# Running

To run the program here are the command arguments:

```                
 python .\rg-c-compiler.py <mode> <source subdirectory> <file1.c> <file2.c> <file3.c>...
```
In fact the <file?.c> entries are what is added to the TCC command in dos.  
So in the example earlier the command:  

```
python .\rg-c-compile.py runonly source test.c utils.c    
```
Compiles the TCC command in DOS to:  

```
tcc  test.c utils.c > test.cmp 
```

The test.cmp are the complication results to be retrived by the Python script.  

mode can be:
* compileonly     - Compile the C file only
* compilerun      - Compile the C file and run it is created
* runonly         - Run the DosBox environment only and do not compile

For example:  
```
 python .\rg-c-compiler.py compileonly source test1.c
```

Would compile the file test1.c but not run it. The DosBox applicaiton is terminated, effectivly only acting as a compiler and not running the resulting program.

# MakeFile
The Python program also supports MakeFiles.  
Here is the syntax for that:  

```
python .\rg-c-compile.py compilerun source test.c make    
```

That will trigger the script to go into the source directory, using the name test.c as the main file (but this is overridden by the Makefile) then run a make.exe command. That will look for a file called makefile in the source path and attempt to compile your program.  

Here is an example makefile included in this repo:

```
#Make file for Turbo C Compiler
test.exe: test.c utils.c
	tcc -D__MSDOS__ test.c utils.c
```

Essentially doing the same thing as before from the command line.

