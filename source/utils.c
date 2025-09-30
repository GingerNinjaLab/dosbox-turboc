#include <stdio.h>
#include <conio.h>
#include "utils.h"

unsigned char getCharBuffer[1];

void screeenMode40() {
    textmode(C40); 
}

void screeenMode80() {
    textmode(C80); 
}

void hideCursor() {
    asm mov ch, 32
    asm mov ah, 1
    asm int 10h
}

void showCursor() {
    asm mov ch, 6
    asm	mov cl, 7
    asm mov ah, 1
    asm int 10h
}

#if defined(__MSDOS__)
char GetCharAtXY(char x, char y) {
    gettext(x,y,x+1,y,getCharBuffer);
    gotoxy(x,y);
    return getCharBuffer[0];
}
#endif

/*
https://yassinebridi.github.io/asm-docs/8086_bios_and_dos_interrupts.html

*/
