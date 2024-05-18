/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:38:08 by ksohail-          #+#    #+#             */
/*   Updated: 2024/05/18 20:35:57 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

extern char **myenv;
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include "../Libft/libft.h"
# include <limits.h>

typedef enum s_token
{
    Cmd,
    AppendFile,
    HereDocDel,
    Infile,
    OutFile,
    Input,		// '<'
    Output,		// '>'
    Append,		// '>>'
    HereDoc,	// '<<'
    Pipe,		// '|'
    Non
}   t_token;


// typedef struct s_env
// {
//     char *key;
//     char  *value;
//     struct  data *next;
// }   t_env;

typedef struct s_cmds
{
    char *cmd;
    t_token token;
    struct s_cmds *next;
    struct s_cmds *prev;
}   t_cmds;

typedef struct s_data
{
    char *line;
    t_cmds *lst;
}   t_data;

// lst
void	lstadd_back(t_cmds **lst, t_cmds *new);
void	lstadd_front(t_cmds **lst, t_cmds *new);
t_cmds	*lstlast(t_cmds *lst);
void	lstclear(t_cmds **lst);
t_cmds	*lstnew(char *cmd, t_cmds *stack);
int		lstsize(t_cmds *lst);

// parsing
void	free_array(char **array);
char	*rm_spaces(char *str);
void    get_list(char **cmd, int size, t_cmds **lst);
void    init_tokens(t_cmds *cmds);
void	parsing(t_data *data);

// executing
void    copieenv(char **env);
void printmyenv(void);
 int lenofmyenv(char **env);
 void executing(char *str);
 char *findmyvar(char *va);
 void set_myenv(char *key, char *value);
 void my_cd(char **av);
void change_mydir(char *path);
void mypwd(void);
void ft_echo(char **com);
void addnewenv(char *key, char *value);
void export(char **com);
void ft_echo_n(char **com);
void exit_myminishell(char **com);
void unset_env();

//tools 
void exiterror(void);
int	ft_strcmp(const char *s1, const char *s2);
void ft_putendle(char *str, int fd);
char **myrealloc(int size);
void	ft_putstrn_fd(char *s, int len, int fd);
int findmyindex(char *va);
void handle_envi();
#endif