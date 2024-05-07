#include "../include/minishell.h"

char **myenv;
void free2array(char **str)
{
    if(!str)
        return ;
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

void exiterror(void)
{
    free2array(myenv);
    write(1, "\n", 1);
    exit(1);
}

void ft_putendle(char *str, int fd)
{
    char	*tmp;

    if(!str)
        return ;
	tmp = ft_strjoin(str, "\n");
	ft_putstr_fd(tmp, fd);
	free(tmp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}


char **myrealloc(int size)
{
    char **new;
    new = (char **)malloc(sizeof(char *) * (size + 1));

    int i = 0;
    while(size > i)
    {
        new[i] = NULL;
        i++;
    }
    i = 0;

    while(myenv[i] && i < size)
    {
        new[i] = ft_strdup(myenv[i]);
        free(myenv[i]);
        i++;
    }
    free(myenv);
    return(new);
}

char *ft_strncpy(char *dest, char *src, size_t n)
{
    while(*src && n--)
        *dest = *src;
    while(n--)
        *dest = '\0';

    return(dest); 
}