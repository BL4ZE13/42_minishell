/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:09 by diomari           #+#    #+#             */
/*   Updated: 2023/11/30 17:18:54 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include "./src/gnl/get_next_line.h"

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
	void			(*ft_exec)(struct s_list **list);
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

extern struct s_global	g_all;

//BUILTINS
//cd
int			update_pwd(char *str);
int			change_dir(char *path);
void		finish_cd(char **env);
void		cd_exec(t_list **lst);
//echo
void		echo_exec(t_list **lst);
void		echo_op(t_list **lst, int *flag);
void		print_mt(char **str, size_t i);
//exit
int			ft_isnum(const char *str);
int			exit_ov(t_list **lst);
void		exit_exec(t_list **lst);
//pwd
void		pwd_exec(t_list **lst);
//export
void		expo_core(t_list **lst, char **str, int i);
void		expo_error(t_list **lst, char **str, int i);
void		expo_only(void);
void		export_exec(t_list **lst);
//unset
void		unset_exec(t_list **lst);

//ENV
//env
void		e_exec(t_list **lst);
void		bpn(t_env **lst);
t_env		*env_dup(char **env);
//e_utils
t_env		*e_last(t_env *lst);
void		e_add_back(t_env **lst, t_env *new);
t_env		*e_new(char *str);
int			free_env(t_env **lst);
char		*e_search(char **env, char *str);
//e_utils2
int			nb_search(char *s1, char *s2);
size_t		var_size(char *str);
void		e_top(t_env **env);
t_env		*e_search_lst(char *input);
void		e_del(t_env **lst);

//EXECUTOR
//executor
void		executor(t_list *lst);
void		exe_core(t_list *lst);
void		exec_cmd(t_list *lst);
void		exec_op(t_list *lst);
//executor_utils
void		def_exec(t_list **lst);
int			is_builtin(t_list *lst);
int			fd_check(t_list *lst);

//EXPANDER
char		**expander(char **div, char **env);
void		exp_util(char ***div, char **env, int *i, int *j);
void		exp_loop(char ***div, char **env, int *i, int *j);
char		**exp_prep(char *str);
char		*str_prep(char *str, int i, int len);
char		*chg_dollar(char *input, char **env);
void		chg_dollar_loop(char **input, char **buff, int *i, int *j);
int			is_alphnum(char c);

//GNL
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);

//HEREDOC
int			ft_heredoc(char *str);
void		hd_chid(char *str, int *fd);
void		chg_term(void);

//LIBFT
void		*ft_calloc(size_t nelem, size_t elsize);
char		*ft_strdup(const char *src);
void		ft_free_matrix(char ***m);
void		ft_free_list(t_list **lst);
void		print_list(t_list *list);
char		*ft_strchr(const char *s, int c);
int			ft_matrixlen(char **matrix);
char		**ft_env_lst_to_array(t_env *lst_env);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_itoa(int nbr);
int			ft_size(int nb);
char		*ft_strjoin(char *s1, char const *s2);
int			ft_strcmp(char *s1, char *s2);
const char	*ft_white_spaces(const char *nptr);
int			ft_atoi(const char *nptr);
void		ft_bubble_sort(char **arr, int size);
char		**recursive_split(char *str, char **arr, int words, char c);
char		**ft_split(const char *str, char c);
int			ft_isdigit(int i);
int			ft_isalnum(int i);
int			ft_str_islanum(char *str);
char		*ft_replacement(char *str, char *s1, char *s2);
int			e_lstsize(t_env *lst);

//PARSER
int			check_sep(char *str, int *array);
void		parser(char *res, char *str, char sep, int *array);

//REDIRECTIONS
void		redirection(t_list *lst, char **div);
void		token_red(char **div, int *i, t_list *lst);
void		inv_fd(t_list *lst);
int			token_check(char *str);

//SHELL
void		shell(void);

//SIG_ERRORS
//sig
void		sig_def(void);
void		sigint_handle(int sigint);
void		sigquit_handle(int sigquit);
void		sigs_hd(int sig);
//errors
void		error_handle(char *cmd);
void		is_dir(char *cmd);
void		cmd_nf(char *cmd);
int			hd_error(char *str);

//UTILS
//list_utils
void		top_lst(t_list	**lst);
t_list		*ft_lstnew(int i);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list		*gen_lst(char *input);
//list_utils2
int			ft_lstsize(t_list *lst);
//vars
int			free_vars(void);
t_vars		*i_vars(void);
//syntax
void		syntax(char *input);
void		tr_sep(char *input, int i, int size, int *wd);
void		syn_error(char *str, char *input, int size);
int			syn_sep(char *str, int *array);
//quotes_utils
void		tr_quote(char *input, int i, int *flag);
void		quote_del(char **input);
void		str_q_del(char **input, char c);
//utils
void		close_fd(t_list **lst, int flag);
void		mod_matrix(char **array);
char		*cmd_path(char **env, char **cmd);

#endif