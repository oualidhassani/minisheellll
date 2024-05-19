#include "../include/minishell.h"
void ft_echo(char **com)
{
    int i = 1;
    
    if(com == NULL || com[1] == NULL)
        ft_putchar_fd('\n', 1);
    else
    {
        while(com[i])
        {
            if(com[i][0] == '$')
                handle_envi(com);
            else
            {
                ft_putstr_fd(com[i], 1);
                ft_putchar_fd(' ', 1);
            }
            i++;
            printf("im here \n");
        }
    }
        printf("\n");
}

void ft_echo_n(char **com)
{
    int i = 1;
    
    if(com == NULL || com[1] == NULL)
        return ;
    else
    {
        while(com[++i])
        {
            ft_putstr_fd(com[i], 1);
            ft_putchar_fd(' ', 1);
        }
    }
}