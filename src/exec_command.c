#include "../include/minishell.h"

void execute_command(char *path, char **com)
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Executing command in child process\n");
        execve(path, com, myenv);
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        free(path);
        perror("Fork failed to create a new process");
        return;
    }
    else
        wait(&pid);
    if (path)
        free(path);
}