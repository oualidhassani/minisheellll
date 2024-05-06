#include "../include/minishell.h"

void change_mydir(char *path)
{
    char *cur;
    char buffer[PATH_MAX];
    cur = getcwd(buffer,PATH_MAX);

    if(chdir(path) == 0)
		set_myenv("OLDPWD", cur);
    else
    {
        perror("hna");
        printf("l9lawi\n");
    }

}
void my_cd(char **av)
{
    char *myhome = findmyvar("HOME");

    if(av[1] == NULL || ft_strcmp(av[1], "") == 0)
    {
        printf("change to %s\n", myhome);
        change_mydir(myhome);

    }
    else 
    {
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