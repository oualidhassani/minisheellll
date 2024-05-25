#include "../include/minishell.h"

char *get_my_path(char **com) 
{
    char *path1 = findmyvar("PATH");
    if (!path1) 
    {
        printf("PATH variable not found\n");
        return NULL;
    }

    char **str = ft_split(path1, ':');
    if (!str) {
        printf("Failed to split PATH\n");
        return NULL;
    }

    int i = 0;
    char *mypath = NULL;
    while (str[i]) 
    {
        char *joiner = ft_strjoin(str[i], "/");

        char *command_path = ft_strjoin(joiner, com[0]);
        free(joiner);

        if (!command_path) 
            printf("Memory allocation failed\n");

        if (access(command_path, X_OK) == 0) 
        {
            mypath = command_path; 
            break;
        }

        free(command_path);
        i++;
    }

    i = 0;
   free2array(str);

    if (!mypath)
        return NULL;

    return mypath;
}


void execute_command(char **com)
{
    int pid;

    char *path = get_my_path(com);
    pid = fork();
    if (pid == 0)
    {
        execve(path, com, myenv);
        perror("execve failed");
        exit(1);
    }
    else if (pid < 0)
    {
        free(path);
        perror("Fork failed to create a new process");
        return;
    }
    else
        wait(&pid);
    // if (path)
    //     free(path);

}
