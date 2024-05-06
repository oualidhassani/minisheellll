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
