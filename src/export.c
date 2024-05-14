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

void swap(char **s1, char **s2)
{
     char *tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}
int comparestring(char *s1, char *s2)
{
    return ft_strcmp(s1, s2);
}
void sortexport(char **arr, int n)
{
    int i = 0;
    while(i < n - 1)
    {
        int j = 0;
        while(j < n  - i - 1)
        {
            if(comparestring(arr[j], arr[j + 1]) > 0)
                swap(&arr[j], &arr[j + 1]);
            j++;
        }
        i++;
    }
}
void printmyexport()
{
    int		i;

	i = 0;
    
    while(myenv[i])
        i++;
    sortexport(myenv, i);


    int j = 0;
	while (i > j)
    {
		ft_putendexp(myenv[j], 1);
        j++;
    }
}

void export(char **com)
{
    if(com[1] == NULL)
        printmyexport();
    // else
    //     {
    //         addnewenv()
    //     }
}