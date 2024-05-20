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


// void handle_envi(char **com)
// {
//     int k = 1;
//     while(com[k])
//     {
//         int i = 0;
//         if(com[k][i] != '$')
//             break;
//         while (com[k][i] == '$')
//             i++;

//         int len = ft_strlen(com[k]);
//         char *val = malloc(sizeof(char) * (len + 1));
//         if (val == NULL)
//         {
//             printf("Memory allocation failed\n");
//             exit(1);
//         }

//         int j = 0;
//         while (com[k][i])
//         {
//             val[j] = com[k][i];
//             i++;
//             j++;
//         }
//         val[j] = '\0';
//         printf("the k index ======>%d\n", k);
//         k++;
//         // printf("%s\n", val);
//         char *b = findmyvar(val);
//         printf()
//         if (b > 0)
//             printf("%s ", b);
//     }
// }


