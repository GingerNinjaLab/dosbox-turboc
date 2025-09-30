#ifndef UTILS_H
#define UTILS_H

void screeenMode40();
void screeenMode80();

void hideCursor();
void showCursor();

#if defined(__MSDOS__)
char GetCharAtXY(char x, char y);
#endif


#endif
