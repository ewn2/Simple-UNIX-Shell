#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <readline/readline.h>
#include <readline/history.h>
void boilerplate()
{
   //clear();
    printf("\n\nErwin Uppal CMPE 142 Assignment 1: Creating a UNIX Shell\n\n");
    char* username = getenv("USER");
    printf("\nWelcome @%s\n", username);
    sleep(1);
    //clear();
}

int grabber(char* str)
{
    char* inbuff;
    //inbuff = readline("\n>>> ");
}

int main()
{
    boilerplate;
    printf("\n\nErwin Uppal CMPE 142 Assignment 1: Creating a UNIX Shell\n\n");
    char* username = getenv("USER");
    printf("\nWelcome @%s\n", username);
    return 0;
}