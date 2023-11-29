/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 09:39:29 by diomarti         ###   ########.fr       */
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
	sig_def();
	shell();
}

//rl_catch_signals = 0; (so funciona no linux) 
//meter por baixp do vars