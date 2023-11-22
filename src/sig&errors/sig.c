/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:53:28 by diomari           #+#    #+#             */
/*   Updated: 2023/11/22 10:30:53 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	sig_def(void)
{
	signal(SIGINT, sigint_handle);
	signal(SIGQUIT, sigquit_handle);
}

//se n der com o all.status:
	//int status e substituir
void	sigint_handle(int sigint)
{
	pid_t	pid;

	(void)sigint;
	pid = waitpid(-1, &all.status, 0);
	all.status = 130;
	write(2, "^C", 2);
	write(2, "\n", 1);
	if (all.hd)
	{
		all.stop = 1;
		return ;
	}
	if (pid == -1)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

//mesma coisa da func anterior;
void	sigquit_handle(int sigquit)
{
	pid_t	pid;

	(void)sigquit;
	pid = waitpid(-1, &all.status, 0);
	if (pid == -1)
		SIG_IGN ;
	else if (!all.hd)
	{
		write(1, "Quit (core dumped)\n", 20);
		return ;
	}
}
