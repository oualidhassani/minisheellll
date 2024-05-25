#include "../include/minishell.h"

char **split_str(char *str)
{
    return(ft_split(str, ' '));
}

void executing(char *str, char **av)
{
    char **com = split_str(str);
    if(com[0] == NULL)
        return;
    // if(com[1][0] == '$')
    //     handle_envi(com);
    else if(ft_strcmp(com[0], "cd") == 0)   
        my_cd(com);
    else if(ft_strcmp(com[0], "env") == 0 && com[1] == NULL)
        printmyenv();
    else if(ft_strcmp(com[0], "pwd") == 0)
        mypwd();
    else if(ft_strcmp(com[0], "echo") == 0)
    {
        if(com[1] != NULL && ft_strcmp(com[1], "-n") == 0)
            ft_echo_n(com);
        else
            ft_echo(com);
    }
    else if(ft_strcmp(com[0], "export") == 0)
        export(com);
    else if(ft_strcmp(com[0], "exit") == 0)
        exit_myminishell(com);
    else if(ft_strcmp(com[0], "unset") == 0)
        unset_env(com);
    // else
    // {
        // printf("i enter here\n");
        // printf("%s\n", com[0]);
    // }
}