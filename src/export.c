 #include "../include/minishell.h"

void ft_putendexp(char *str, int fd)
{
    char	*tmp;

    if(!str)
        return ;
	tmp = ft_strjoin(str, "\n");
    ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(tmp, fd);
	free(tmp);
}
void printmyexport()
{
    int		i;

	i = 0;

	while (myenv[i])
    {
		ft_putendexp(myenv[i], 1);
        i++;
    }
}


void export(char **com)
{
    if(com[1] == NULL)
        printmyexport();
    else
        {
            addnewenv()
        }
}