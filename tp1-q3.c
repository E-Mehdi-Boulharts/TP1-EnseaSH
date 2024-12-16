#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define FDW 1
#define FDR 0
#define BUF "\nBienvenue dans le Shell ENSEA. \nPour quitter, tapez 'exit'. \n"
#define SIZE 256

int main(void)
{
    char userW[SIZE];
    int nb_Char;
    write(FDW, BUF, sizeof(BUF));

    while(1)
    {
        nb_Char = read(FDR, userW, SIZE);
        userW[nb_Char-1]='\0';  //we remove the \n that appears when the user presses "enter"
        
        if(strcmp(userW, "exit") == 0)  //we make sure that the user writted "exit". If it's the cas we can exit
        {
            exit(EXIT_SUCCESS);
        }
    }
}
