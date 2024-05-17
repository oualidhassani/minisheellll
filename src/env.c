#include "../include/minishell.h"

int findmyindex(char *va)
{
    int i = 0;
    char *tmp;
    tmp = ft_strjoin(va, "=");
    int len = ft_strlen(tmp);
        while(myenv[i])
        {
            if(ft_strncmp(myenv[i], tmp, len) == 0)
            {
                    free(tmp);
                    return(i);
            }
            i++;
        }
        free(tmp);
        return(0);
}

char *findmyvar(char *va)
{
    int i = 0;
    char *tmp;
    tmp = va;
        while(myenv[i])
        {
            char **vale = ft_split(myenv[i], '=');
            if(ft_strcmp(vale[0], tmp) == 0)
            {
                    return(ft_strchr(myenv[i], '=')) + 1;
            }
            i++;
        }
        free(tmp);
        return(0);
}


void printmyenv()
{
    int		i;

	i = 0;

	while (myenv[i])
    {
		ft_putendle(myenv[i], 1);
        i++;
    }
}

 int lenofmyenv(char **env)
{
    int i = 0;
    int mylen = 0;

    while(env[i])
    {
        i++;
        mylen++;
    }
    return(mylen);

}
void  copieenv(char **env)
{
    int len = lenofmyenv(env);
    myenv = (char **)malloc((len + 1)*sizeof(char *));
    
    if(!myenv)
        exiterror();
    int i = 0;
    while(env[i])
    {
        myenv[i] = ft_strdup(env[i]);
        if(!myenv[i])
        {
            exiterror();
        }
        i++;
    }
    myenv[i] = NULL;
}


void set_myenv(char *key, char *value)
{
    int myi = findmyindex(key);
    char *tmp = ft_strjoin("=", value);
    if(myi != 0)
    {
        free(myenv[myi]);
        if(value)
            myenv[myi] = ft_strjoin(key, tmp);
        else
            myenv[myi] = ft_strjoin(key, "=");
    }
    else
    {
        myenv = myrealloc(myi + 1);
        if(value)
            myenv[myi] = ft_strjoin(key, tmp);
        else
            myenv[myi] = ft_strjoin(key, "=");
    }
    free(tmp);
}

// void addnewenv(char *key, char *value)
// {
//     int myi = findmyindex(key);
//     int lenkey = ft_strlen(key);
//     int lenval = ft_strlen(value);
//     int tot = lenkey + lenval + 1;
//     char *newenv;
//     if(myi >= 0)
//         set_myenv(key, value);
//     else
//     {
//         myenv = myrealloc(tot * sizeof(char));
//         if(value)
//             newenv = ft_strjoin(key, value);
//         else
//             newenv = ft_strjoin(key, value);       
//     }
//     myenv[myi] = newenv;
//     myi++;
// }