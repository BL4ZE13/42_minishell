/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:23:34 by diomari           #+#    #+#             */
/*   Updated: 2023/12/04 16:16:17 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	free_vars(void)
{
	if (g_all.vars)
	{
		if (g_all.vars->head)
		{
			top_lst(&g_all.vars->head);
			ft_free_list(&g_all.vars->head);
		}
		if (g_all.vars->str)
			free(g_all.vars->str);
		if (g_all.vars->env)
			ft_free_matrix(&g_all.vars->env);
		if (g_all.vars->div)
			ft_free_matrix(&g_all.vars->div);
		free(g_all.vars);
	}
	return (1);
}

t_vars	*i_vars(void)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	vars->head = NULL;
	vars->str = NULL;
	vars->env = NULL;
	vars->div = NULL;
	return (vars);
}
