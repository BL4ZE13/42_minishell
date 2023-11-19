# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 17:29:03 by diomari           #+#    #+#              #
#    Updated: 2023/11/19 21:44:43 by diomari          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

SOURCES =	src/main.c \
			src/gnl/get_next_line.c \
			src/gnl/get_next_line_utils.c \
			src/env/e_utils.c \
			src/env/env.c \
			src/libft/ft_calloc.c \
			src/libft/ft_strdup.c \
			src/libft/ft_free_list.c \
			src/libft/ft_free_matrix.c \
			src/shell/shell.c \
			src/sig&errors/sig.c \
			src/utils/list_utils.c \
			src/utils/vars.c \
		

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