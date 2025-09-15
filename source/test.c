#include <stdio.h>
#include <conio.h>

FILE *fp;
char ch,k;

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

        gotoxy(10, 20);
        printf("Hello, World!");
        k = getch();    

        printf("Loading file");
        loadFile();
        printf("Complete");
        k = getch();    
        return 0;
}

