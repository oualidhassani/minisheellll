#include "../include/minishell.h"

void unset_env(char **com)
{
    if(com[1] == NULL)
        return ;
    int i = 1;
    int j;
    while(com[i])
    {
        j  = findmyindex(com[i]);
        if(j > 0)
        {
            free(myenv[j]);
            myenv[j] = NULL;
        }
        i++;
    }
}


void handle_envi(char **com)
{
    int i = 0;
    char *val;
    if(com[0][i] == '$')
    {
        i++;
        val = com[0];
    }   

    printf("%s\n", com[0]);
    // int j = findmyindex(com[1][0]);


}
   