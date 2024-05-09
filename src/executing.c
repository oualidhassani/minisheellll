#include "../include/minishell.h"

char **split_str(char *str)
{
    return(ft_split(str, ' '));
}
void executing(char *str)
{
    char **com = split_str(str);
    if(com[0] == NULL)
        return;
    if(ft_strcmp(com[0], "cd") == 0)   
        my_cd(com);
    if(ft_strcmp(com[0], "env") == 0 && com[1] == NULL)
        printmyenv();
    if(ft_strcmp(com[0], "pwd") == 0)
        mypwd();
    if(ft_strcmp(com[0], "echo") == 0)
        ft_echo(com);
    if(ft_strcmp(com[0], "export") == 0 )
        export(com);
    // if(com[1] != NULL && ft_strcmp(com[1], "-n") == 0 && ft_strcmp(com[0], "echo") == 0);
    //     printf("ana dkhlt\n");
}