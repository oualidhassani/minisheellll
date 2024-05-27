#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	if (ac != 1)
		exit(1);
	copieenv(env);
    while (1)
    {
		//ADD HISTORY
		char *str = readline("minishell$ ");
		if (str == NULL)
			break;
		add_history(str);
		char **com = split_str(str);
		// parsing(&data);
		executing(str, av);						// to do
		execute_command(com);
		// ft_pipe(com);
		// get_my_path();
		// free(data.line);
		// lstclear(&data.lst);
    }
	printf("\n");
	// lstclear(&data.env);;
}