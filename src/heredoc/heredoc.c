/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:20:09 by diomari           #+#    #+#             */
/*   Updated: 2023/11/27 19:55:24 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	chg_term(void)
{
	int			rc;
	struct termios	new;
	
	rc = tcgetattr(0, &all.termios_save);
	if (rc)
	{
		perror("");
		return ;
	}
	new = all.termios_save;
	new.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, 0, &new);
	if (rc)
	{
		perror("");
		return ;
	}
}

void	hd_chid(char *str, int *fd)
{
	chg_term();
	all.vars->env = ft_env_lst_to_array(all.env);
	while (1)
	{
		write(0, ">", 1);
		all.vars->str = get_next_line(0);
		all.vars->str = chg_dollar(all.vars->str, all.vars->env);
		if (!all.vars->str && hd_error(str))
			break ;
		if ((ft_strncmp(all.vars->str, str, ft_strlen(str)) == 0) && \
			(ft_strlen(all.vars->str) - 1 == ft_strlen(str)))
			break ;
		write(fd[1], all.vars->str, ft_strlen(all.vars->str));
		free(all.vars->str);
		all.vars->str = NULL;
	}
	free_env(&all.env);
	free_vars();
	close(fd[1]);
	close(fd[0]);
	exit(0);
}

int	ft_heredoc(char *str)
{
	int	fd[2];
	int status;

	status = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigs_hd);
	all.hd = 1;
	if (pipe(fd) == -1)
		perror("");
	if (fork() == 0)
		hd_chid(str, fd);
	sig_def();
	close(fd[1]);
	waitpid(0, &status, 0);
	all.hd = 0;
	return (fd[0]);
}
