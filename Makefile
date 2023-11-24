# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 17:29:03 by diomari           #+#    #+#              #
#    Updated: 2023/11/24 11:18:16 by diomarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

SOURCES =	src/main.c \
			src/builtins/cd.c \
			src/builtins/echo.c \
			src/builtins/exit.c \
			src/builtins/export.c \
			src/builtins/pwd.c \
			src/builtins/unset.c \
			src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c \
			src/env/e_utils.c \
			src/env/e_utils2.c \
			src/env/env.c \
			src/libft/ft_calloc.c \
			src/libft/ft_strdup.c \
			src/libft/ft_free_list.c \
			src/libft/ft_free_matrix.c \
			src/libft/ft_strchr.c \
			src/libft/ft_env_lst_to_array.c \
			src/libft/ft_itoa.c \
			src/libft/ft_matrixlen.c \
			src/libft/ft_strcmp.c \
			src/libft/ft_strjoin.c \
			src/libft/ft_strncmp.c \
			src/libft/ft_atoi.c \
			src/libft/ft_bubble_sort.c \
			src/libft/ft_isalnum.c \
			src/parser/parser.c \
			src/shell/shell.c \
			src/sig&errors/sig.c \
			src/utils/list_utils.c \
			src/utils/vars.c \
			src/utils/syntax.c \
			src/utils/quotes_utils.c \
			
		

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -o ${NAME} -lreadline

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME) minishell

re: fclean all

.PHONY: all clean fclean re