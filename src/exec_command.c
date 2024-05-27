#include "../include/minishell.h"

char *get_my_path(char **com) 
{
    char *path1 = findmyvar("PATH");
    if (!path1) 
        return NULL;

    char **str = ft_split(path1, ':');
    if (!str)
        return NULL;

    int i = 0;
    char *mypath = NULL;
    while (str[i]) 
    {
        char *joiner = ft_strjoin(str[i], "/");

        char *command_path = ft_strjoin(joiner, com[0]);
        free(joiner);

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
    // dprintf(2,"path %s\n",path);
    // dprintf(2,"com => %s\n",*com);
    pid = fork();
    // char *cmds[2] = {path,*com};
    if (pid == 0)
    {
        execve(path, com, myenv);
        perror("execve failed");
        exit(1);
    }
    else if (pid < 0)
    {
        free(path);
        return;
    }
    else
        wait(&pid);
    // if (path)
    //     free(path);

}
void ft_pipe(char **com)
{
    int fd[2];

    if(pipe(fd) == -1)
        return ;
    
    int pid = fork();

    if(pid == -1)
        return ;
    
    printf("%s\n", com[0]);
    if(pid == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execute_command(&com[0]);
        // exit(1);
    }

    int pid2 = fork();

    if(pid2 == -1)
        return ;
    printf("%s\n", com[2]);
    if(pid == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execute_command(&com[2]);
        // exit(1);
    }
    // waitpid(pid,NULL,1 0);
    // waitpid(pid2, NULL, 0);
    close(fd[0]);
    close(fd[1]);
}

