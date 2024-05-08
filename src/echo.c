#include "../include/minishell.h"
void ft_echo(char **com)
{
    int i = 1;
    int len ;
    if(com == NULL || com[1] == NULL)
        ft_putchar_fd('\n', 1);
    else
    {
        while(com[i])
        {
            len = ft_strlen(com[i]);
            if(com[i][0] == '"' && com[i][len - 1] == '"')
                ft_putstrn_fd(com[i] + 1 ,len - 2, 1);
            else
            {
                ft_putstr_fd(com[i], 1);
                ft_putchar_fd(' ', 1);
            }
            i++;
        }
        printf("\n");
    }
}