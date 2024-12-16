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
        userW[nb_Char-1]='\0';
        
        if(strcmp(userW, "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }
        pid_t pid = fork(); // we create the son that will permits us to perform several actions at the same time without  stopping the program
        if(pid == -1) // cas when there is an error
        {
            write(FDW, "erreur", sizeof("erreur"));
        }
        else if(pid == 0) // son case's. Basically it's where we execute an external programm(in this case it's fortune)
        {
            if(strcmp(userW, "fortune") == 0)
            {
                execlp("/usr/games/fortune", "fortune", NULL); // we execute fortune knowing his path on our device
            }
        }
    }
}
