#include "../include/minishell.h"

void change_mydir(char *path)
{
    char *cur;
    char buffer[PATH_MAX];
    cur = getcwd(buffer,PATH_MAX);

    if(chdir(path) == 0)
		set_myenv("OLDPWD", cur);
    set_myenv("PWD", path);
}


void my_cd(char **com)
{
    char *myhome = findmyvar("HOME");

    if(com[1] == NULL)
        change_mydir(myhome);
    else
    {
        change_mydir(com[1]);
    }
}

void mypwd(void)
{
    char *cur;
    char buffer[4097];
    cur = getcwd(buffer, 4096);
    printf("%s\n", cur);
}