#include "../include/minishell.h"

char *sub(char **com)
{
    int i = 0;
    while(com[0][i])
    {

        if(com[0][i] == '=')
        {
            char *sub = (char *)malloc(i + 1);
            ft_substr(sub, com[0], i);
            sub = '\0';
        }
        i++;
    }
    return(sub);
    printf("%s\n", sub);
}

char *handle(char **com)
{
    int i = 0;
    while(com[0][i])
    {
        
        if(com[0][i] == '=')
            return(ft_strchr(com[0], '=') + 1);
        i++;
    }
}
void ft_echo(char **com)
{
    int i = 1;
    if(com[1] == NULL)
        ft_putchar_fd('\n', 1);
    else
    {
        while(com[i])
        {
            ft_putstr_fd(com[i], 1);
            ft_putchar_fd(' ', 1);
            i++;
        }
        printf("\n");
    }
}