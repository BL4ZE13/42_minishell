/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:29:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 21:14:46 by diomari          ###   ########.fr       */
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
	// rl_catch_signals = 0;
	sig_def();
	shell(); //fazer shell
}