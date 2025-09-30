#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include "utils.h"

FILE *fp;
char ch,k;
char buffer[1];
int i;

loadFile() 
{
        clrscr();
        fp = fopen("text.txt", "r");
        if (fp == NULL) {
                printf("Error: Could not open file.\n");
                return 1;
        }
        while ((ch = fgetc(fp)) != EOF) {
                putchar(ch); 
        }
        fclose(fp);
        return 0;
}

int main()  
{
        screeenMode40();
        hideCursor();
        clrscr();
        printf("DOS System test\r\n");

        printf("Write char to screen x/y\r\n");

        gotoxy(30, 2);
        printf("ABCDWTEYHDFHERYWERTWEFASDF");

        gettext(33, 2, 34, 2, buffer);

        gotoxy(1, 10);
        printf("Found char:%c\r\n",buffer[0]);

        sound(800);
        delay(500);
        nosound();

        
        printf("Press any key\r\n");
        k = getch();    

/*
        printf("Loading file");
        loadFile();
        printf("Complete");
        k = getch();
        */    
        screeenMode80();
        showCursor();
        return 0;
}

