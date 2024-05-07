#include "../include/minishell.h"

int morethan2arg(char **com)
{
    int i = 0;
    int counter = 0;
    while(com[i])
    {
        i++;
        counter++;
    }
    return(counter);
}
void change_mydir(char *path)
{
    char *cur;
    char buffer[PATH_MAX];
    cur = getcwd(buffer,PATH_MAX);

    if(chdir(path) != 0)
        perror("cd");
	set_myenv("OLDPWD", cur);
    set_myenv("PWD", path);
}


void my_cd(char **com)
{
    int counter = morethan2arg(com);
    if(counter > 2)
    {
        ft_putstr_fd("cd: too many arguments", 1);
        exit(1);
    }
    char *myhome = findmyvar("HOME");
    if(com[1] == NULL || com[1][0] == '~')
        change_mydir(myhome);
    else
        change_mydir(com[1]);
}

void mypwd(void)
{
    char *cur;
    char buffer[PATH_MAX];
    cur = getcwd(buffer, PATH_MAX);
    printf("%s\n", cur);
}