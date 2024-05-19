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
    int j = 0;
    char * val;
    val = NULL;
    if(com[0] && com[0][i] == '$')
    {
        i++;
        val = malloc(sizeof(char)  * ft_strlen(com[0]));
        while(com[0][i])
        {
            val[j] = com[0][i];
            i++;
            j++;
        }
        val[j] = '\0';

    char *b = findmyvar(val);

        if(b != 0)
        {
            printf("%s\n", b);
        }
    }

}
