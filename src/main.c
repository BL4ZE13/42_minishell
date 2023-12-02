/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/30 18:33:19 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

struct s_global	g_all;

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	g_all.env = env_dup(env);
	g_all.status = 0;
	g_all.hd = 0;
	g_all.vars = i_vars();
	rl_catch_signals = 0;
	sig_def();
	shell();
}
