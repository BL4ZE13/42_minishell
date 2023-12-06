/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:15:27 by diomari           #+#    #+#             */
/*   Updated: 2023/12/06 18:32:24 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	shell(void)
{
	char	*input;
	t_list	*lst;

	while (1)
	{
		g_all.stop = 0;
		input = readline("minishell: ");
		if (!input)
		{
			if (input)
				free(input);
			free_env(&g_all.env);
			free_vars();
			exit(0);
		}
		add_history(input);
		syntax(input);
		lst = gen_lst(input);
		if (!input[0] || !lst->ct[0] || !lst->ct[0][0])
			g_all.status = 0;
		if (lst->ct[0] && !g_all.stop)
			executor(lst);
		ft_free_list(&lst);
		free(input);
	}
}
