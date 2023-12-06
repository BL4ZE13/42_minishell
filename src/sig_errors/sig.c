/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:53:28 by diomari           #+#    #+#             */
/*   Updated: 2023/12/04 16:07:03 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sig_def(void)
{
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
}

void	sigint_handle(int sigint)
{
	pid_t	pid;
	int		status;

	pid = waitpid(-1, &status, 0);
	g_all.status = 130;
	(void)sigint;
	write(2, "^C", 2);
	write(2, "\n", 1);
	if (g_all.hd)
	{
		g_all.stop = 1;
		return ;
	}
	if (pid == -1)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sigquit_handle(int sigquit)
{
	pid_t	pid;
	int		status;

	(void)sigquit;
	pid = waitpid(-1, &status, 0);
	if (pid == -1)
		SIG_IGN ;
	else if (!g_all.hd)
	{
		write(1, "Quit (core dumped)\n", 20);
		return ;
	}
}

void	sigs_hd(int sig)
{
	if (sig == SIGQUIT)
		SIG_IGN ;
	else if (sig == SIGINT)
	{
		write(2, " ", 1);
		free_env(&g_all.env);
		free_vars();
		exit(1);
	}
}
