# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 17:29:03 by diomari           #+#    #+#              #
#    Updated: 2023/11/18 18:42:54 by diomari          ###   ########.fr        #
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
			src/utils/utils.c
		

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