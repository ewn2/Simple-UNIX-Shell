#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#define MAX_WORD 64
#define MAX_CHAR 128


void cleanIn(char line[])
{
    int i = 0;
    while(line[i] != '\n')
    i++;
    line[i] = '\0';
}

void readIn(char line[])
{
    char* con = fgets(line, MAX_CHAR, stdin);
    cleanIn(line);
    if(strcmp(line,"exit") == 0 || con == NULL)
    {
        printf("\nExiting, Goodbye\n");
        kill(0, SIGINT);
    }
}

int tokenizer(char* args[], char line[])
{
    int i = 0;
    args[i] = strtok(line, " ");
    while(args[i] != NULL)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }

    return 1;
}

int parse(char* args[], char line[])
{
    int i = 0;
    readIn(line);
    tokenizer(args,line);
    return 1;
}

int main()
{
    char* args[MAX_WORD];
    char line[MAX_CHAR];
    printf("\nWelcome to eShell, CMPE 142, Erwin Uppal\n");
    while(parse(args,line))
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            execvp(args[0], args);
        }
        else
        {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}