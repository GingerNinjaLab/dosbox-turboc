#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include "test.h"
#include "utils.h"

/* Test C file */
/* =========== */

FILE *fp;
char ch,k;
char buffer[1];
int i;

int loadFile() 
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
        clrscr();

        TestFunction("test\r\n");
        
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


        printf("Loading file\r\n");
        loadFile();
        printf("Complete\r\n");
        printf("Press any key\r\n");
        k = getch();
    
        clrscr();

        return 0;
}

