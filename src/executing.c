#include "../include/minishell.h"

char **split_str(char *str)
{
    return(ft_split(str, ' '));
}
void executing(char *str)
{
    char **com = split_str(str);
    if(ft_strcmp(com[0], "cd") == 0)   
        my_cd(com);
    if(ft_strcmp(com[0], "env") == 0)
        printmyenv();
    if(ft_strcmp(com[0], "pwd") == 0)
        mypwd();
}