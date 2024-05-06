#include "../include/minishell.h"

void executing(char **av, char *str)
{
    if(ft_strcmp(str, "cd") == 0)
        my_cd(av + 1);
    if(ft_strcmp(str, "env") == 0)
        printmyenv();
    if(ft_strcmp(str, "pwd") == 0)
        mypwd();
}