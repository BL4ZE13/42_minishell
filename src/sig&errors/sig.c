/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:53:28 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 21:12:24 by diomari          ###   ########.fr       */
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
	//se n der com o all.status:
	//int status e substituir
	(void)sigint;
	pid_t	pid;
	
	pid = waitpid(-1, &all.status, 0);
	all.status = 130;
	write(2, "^C", 2);
	write(2, "\n", 1);
	if (all.hd)
	{
		all.stop = 1;
		return ;
	}
	if (pid = -1)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sigquit_handle(int sigquit)
{
	//mesma coisa da func anterior;
	(void)sigquit;
	pid_t	pid;
	
	pid = waitpid(-1, &all.status, 0);
	if (pid == -1)
		SIG_IGN ;
	else if (!all.hd)
	{
		write(1, "Quit (core dumped)\n", 20);
		return ;
	}
}