# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: error01 <error01@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 14:29:42 by ksohail-          #+#    #+#              #
#    Updated: 2024/05/24 17:16:53 by ksohail-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_lstadd_back_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstmap_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\
				ft_atoi.c\
				ft_isascii.c\
				ft_memmove.c\
				ft_putstr_fd.c\
				ft_strjoin.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_strncmp.c\
				ft_tolower.c\
				ft_bzero.c\
				ft_isdigit.c\
				ft_memset.c\
				ft_split.c\
				ft_strlcat.c\
				ft_strnstr.c\
				ft_toupper.c\
				ft_calloc.c\
				ft_isprint.c\
				ft_memchr.c\
				ft_strchr.c\
				ft_strlcpy.c\
				ft_strrchr.c\
				ft_isalnum.c\
				ft_itoa.c\
				ft_memcmp.c\
				ft_strdup.c\
				ft_strlen.c\
				ft_strtrim.c\
				ft_isalpha.c\
				ft_memcpy.c\
				ft_striteri.c\
				ft_strmapi.c\
				ft_substr.c\

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = Libft.A
OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME):	$(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o:	%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.SECONDARY : ${OBJ}
.PHONY: all clean fclean re
