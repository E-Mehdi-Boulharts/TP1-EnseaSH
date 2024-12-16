#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

#define FDW 1
#define FDR 0
#define BUF "\nBienvenue dans le Shell ENSEA. \nPour quitter, tapez 'exit'. \n"
#define SIZE 256

void DispTime(int status, long mytime);
void Welcome(void);

int main(void)
{
    char userW[SIZE];
    int nb_Char;
    int status = -2; // we initialize the state for the first print 
    long mytime = 0; // we initialise our variable for the time of execution

    Welcome(); // print our welcome message

    while(1)
    {
        struct timespec start, end;  // we initalize the start and the end of execution.
        DispTime(status, mytime); // this function print time 
        nb_Char = read(FDR, userW, SIZE);
        userW[nb_Char-1]='\0';
        
        if(strcmp(userW, "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }

        pid_t pid = fork();
        if(pid == -1)
        {
            write(FDW, "erreur", sizeof("erreur"));
        }
        else if(pid == 0)
        {
            clock_gettime(CLOCK_REALTIME, &start); // we start counting from here
            if(strcmp(userW, "fortune") == 0)
            {
                execlp("/usr/games/fortune", "fortune", NULL);
            }
            exit(EXIT_SUCCESS);
        }
        else if(pid > 0)
        {
            wait(&status);
            clock_gettime(CLOCK_REALTIME, &end); // and this is where we stop counting
            mytime = (end.tv_sec - start.tv_sec) * 1000;
        }
    }
}



void Welcome(void) 
{
    write(FDW, BUF, sizeof(BUF));
}

void DispTime(int status, long mytime)
{
    if(WIFEXITED(status))
    {
        char time_msg[50];
        int exit_code = WIFEXITED(status);
        sprintf(time_msg, "[exit:%d|%ldms]\0\n", status, mytime);
        write(FDR, time_msg, strlen(time_msg));
    } 
    else if(WIFSIGNALED(status))
    {
        char signal_msg[50];
        int signal_code = WTERMSIG(status);
        sprintf(signal_msg, "[sign:%d|%ldms]\0\n", signal_code, mytime);
        write(FDR, signal_msg, strlen(signal_msg));
    }
}