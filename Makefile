NAME = minishell

CC = cc

CFLAGS = -Wall  -Wextra -ggdb3 -lreadline -g3 -fsanitize=address #-Werror -v

SRCS =    src/exec_command.c src/unset.c src/export.c src/echo.c src/cd.c src/executing.c src/tools.c src/env.c src/minishell1.c  Libft/ft_split.c Libft/ft_putstr_fd.c\
		 Libft/ft_isdigit.c Libft/ft_strjoin.c Libft/ft_strdup.c Libft/ft_strlen.c\
		 Libft/ft_substr.c Libft/ft_memset.c Libft/ft_bzero.c Libft/ft_strchr.c Libft/ft_putchar_fd.c Libft/ft_strnstr.c Libft/ft_strncmp.c\
		 Libft/ft_isalpha.c\

OBJ = $(SRCS:.c=.o)

AR  = ar rcs

RM = rm -rf 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS)  -c $< -o $@

install:
	make
	cp ./minishell /user/local/bin/minishell

clean : 
		@$(RM) $(OBJ)

fclean :
		@$(RM) $(OBJ) $(NAME)

rminstall:
	rm -rf /user/local/bin/minishell

re : fclean all
