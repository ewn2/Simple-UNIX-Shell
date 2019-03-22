#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <readline/readline.h>
#include <readline/history.h>


int main()
{
    printf("\n\nErwin Uppal CMPE 142 Assignment 1: Creating a UNIX Shell\n\n");
    char* username = getenv("USER");
    printf("\nWelcome @%s\n", username);
    char inp[20];
    fgets(inp,20,stdin);
    printf("\n%c, %s\n",inp[3],inp);
    return 0;
}