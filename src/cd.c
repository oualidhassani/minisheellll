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
void my_cd(char **av)
{
    char *myhome = findmyvar("HOME");

    if(av[1] == NULL || ft_strcmp(av[1], "") == 0)
        change_mydir(myhome);
    else 
    {
        printf("%s\n", "ana hna\n");
        change_mydir(av[1]);
    }
}

void mypwd(void)
{
    char *cur;
    char buffer[4097];
    cur = getcwd(buffer, 4096);
    printf("%s\n", cur);
}