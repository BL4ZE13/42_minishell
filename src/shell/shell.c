/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:15:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/25 19:42:51 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	shell(void)
{
	char	*input;
	t_list	*lst;

	while (1)
	{
		all.stop = 0;
		input = readline("minishell> ");
		if (!input)
		{
			if (input)
				free(input);
			free_env(&all.env);
			free_vars();
			exit(0);
		}
		add_history(input);
		syntax(input);
		lst = gen_lst(input);
		if (!input[0] || !lst->ct[0] || !lst->ct[0][0])
			all.status = 0;
		if (lst->ct[0] && !all.stop)
			
	}
}
