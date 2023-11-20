/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 10:32:17 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

struct s_global all;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	all.env = env_dup(env);
	all.status = 0;
	all.hd = 0;
	all.vars = i_vars();
	// rl_catch_signals = 0; (so funciona no linux)
	sig_def();
	shell(); //fazer shell
}