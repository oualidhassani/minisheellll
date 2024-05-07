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
        perror("chdir");
	set_myenv("OLDPWD", cur);
    set_myenv("PWD", path);
}


void my_cd(char **com)
{
    char *myhome = findmyvar("HOME");

    int counter = morethan2arg(com);
    if(counter > 2)
        perror("chdir");
    if(com[1] == NULL)
        change_mydir(myhome);
    else
        change_mydir(com[1]);
}

void mypwd(void)
{
    char *cur;
    char buffer[4097];
    cur = getcwd(buffer, 4096);
    printf("%s\n", cur);
}