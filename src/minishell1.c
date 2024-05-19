#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{

	if (ac != 1)
		exit(1);
	copieenv(env);
    while (1)
    {
		char *str = readline("minishell$ ");
		if (str == NULL)
			break;
		// parsing(&data);
		executing(str);						// to do
		// free(data.line);
		// lstclear(&data.lst);
    }
	printf("\n");
	// lstclear(&data.env);;
}