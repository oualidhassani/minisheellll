#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
   char *str;

	if (ac != 1)
		return (1);
	(void)av;
	copieenv(env);
    while (1)
    {
		char *str = readline("minishell$ ");
		if (str == NULL)
			break;
		// parsing(&data);
		executing(av, str);						// to do
		// free(data.line);
		// lstclear(&data.lst);
    }
	printf("\n");
	// lstclear(&data.env);;
}