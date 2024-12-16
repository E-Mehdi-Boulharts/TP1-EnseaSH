#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define FDW 1   //the variable that allow us to write in the "write"
#define FDR 0   //the variable that allow us to read in the "read"
#define BUF "\nBienvenue dans le Shell ENSEA. \nPour quitter, tapez 'exit'. \n"
#define USERWSIZE 16

int main(void)
{
    char userW[USERWSIZE];
    write(FDW, BUF, sizeof(BUF)); // write the welcome message
    do  // thes loop wait for us to write exit
    {
        read(FDR, userW, USERWSIZE);
    }while(strncmp(userW, "exit", 4) != 0);
    exit(EXIT_SUCCESS);
}
