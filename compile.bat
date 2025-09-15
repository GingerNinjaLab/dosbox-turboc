
@echo off
echo Compiling file go.c
cd source
tcc go.c > go.cmp
type go.cmp
echo Done > c:\ready.inf
echo %STDERR%

IF EXIST go.exe CLS
IF EXIST go.exe go.exe

