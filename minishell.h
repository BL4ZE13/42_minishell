/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:09 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 18:56:21 by diomari          ###   ########.fr       */
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
int		nb_search(char *s1, char *s2);
char	*e_search(char **env, char *str);
size_t	var_size(char *str);
void	e_top(t_env **env);
t_env	*e_search_lst(char *input);


//LIBFT
void	*ft_calloc(size_t nelem, size_t elsize);
char	*ft_strdup(const char *src);
void	ft_free_matrix(char ***m);
void	ft_free_list(t_list **lst);
void	print_list(t_list *list);
char	*ft_strchr(const char *s, int c);
int		ft_matrixlen(char **matrix);
char	**ft_env_lst_to_array(t_env *lst_env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_itoa(int nbr);
int		ft_size(int nb);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);

//SHELL
void	shell(void);

//BUILTINS
//{
	//cd
int		update_pwd(char *str);
int		change_dir(char *path);
void	finish_cd(char **env);
void	cd_exec(t_list **lst);


//}

//EXPANDER

//GNL
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);


//EXECUTER

//HEREDOC

//PARSER

//UTILS
//{
	//list_utils
void	top_lst(t_list	**lst);
	//vars
int		free_vars(void);
t_vars	*i_vars(void);
	//syntax
void	syntax(char *input);
void	tr_sep(char *input, int i, int size, int *wd);
void	syn_error(char *str, char *input, int size);
int		syn_sep(char *str, int *array);
	//quotes_utils
void	tr_quote(char *input, int i, int *flag);
void	quote_del(char **input);
void	str_q_del(char **input, char c);

//}

//SIG&ERRORS
void	sig_def(void);
void	sigint_handle(int sigint);
void	sigquit_handle(int sigquit);

#endif