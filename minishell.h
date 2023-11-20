/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:09 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 10:21:40 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>
#include <signal.h>
#include <term.h>
#include <termios.h>
#include "./src/gnl/get_next_line.h"

//STRUCTS
typedef struct s_env
{
	char			*ct;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_list
{
	char			**ct;
	char			*path;
	int				fd_m[2];
	int				fd[2];
	int				error[2];
	struct s_list	*next;
	struct s_list	*prev;
	//void			(*ft_exec)(struct s_list **lst);
}	t_list;

typedef struct s_vars
{
	t_list			*head;
	char			*str;
	char			**env;
	char			**div;
}	t_vars;

struct s_global
{
	t_vars			*vars;
	int				status;
	t_env			*env;
	int				hd;
	int				stop;
	struct termios	termios_save;
};

extern struct s_global all;

//MAIN

//ENV
t_env	*e_last(t_env *lst);
void	e_add_back(t_env **lst, t_env *new);
t_env	*e_new(char *str);
t_env	*env_dup(char **env);
void	free_env(t_env **lst);

//LIBFT
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(const char *src);
void	ft_free_matrix(char ***m);
void	ft_free_list(t_list **lst);
void	print_list(t_list *list);

//SHELL
void	shell(void);

//BUILTINS

//EXPANDER

//LIBFT

//EXECUTER

//HEREDOC

//PARSER

//UTILS
void	top_lst(t_list	**lst);
int		free_vars(void);
t_vars	*i_vars(void);

//SIG&ERRORS
void	sig_def(void);
void	sigint_handle(int sigint);
void	sigquit_handle(int sigquit);

#endif