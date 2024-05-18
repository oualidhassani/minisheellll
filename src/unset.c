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
    int j = 0;
    if(com[0][i] == '$')
    {
        i++;
        val = (char *)malloc(ft_strlen(com[0]) + 1);
        while(com[0][i])
        {
            val[j] = com[0][i];
            i++;
            j++;
            printf("===========>%c\n", val[j]);
        }
    }
    // val[j] = '\0';
    int b = findmyindex(val);

    printf("%d\n", b);

}
