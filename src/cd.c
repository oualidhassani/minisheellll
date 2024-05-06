#include "../include/minishell.h"

void change_mydir(char *path, int mypath)
{
    char *cur;
    char buffer[4097];
    cur = getcwd(buffer, 4096);
    if(!chdir(path))
		set_myenv("OLDPWD", cur);
    set_myenv("PWD", path);

}
void my_cd(char **av)
{
    char *myhome = findmyvar("HOME");

    
    if(!av[0])
        change_mydir(myhome, 0);
    else 
        change_mydir(av[0], 0);
}

void mypwd(void)
{
    char *cur;
    char buffer[4097];
    cur = getcwd(buffer, 4096);
    printf("%s\n", cur);
}