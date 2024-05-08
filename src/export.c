 #include "../include/minishell.h"

void export(char **com)
{
    if(com[1][0] == NULL)
    {
        printmyenv();
        printf("im here\n");
    }
}