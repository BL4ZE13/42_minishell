/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:15:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/22 10:31:17 by diomarti         ###   ########.fr       */
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
	}
}
