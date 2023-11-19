/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:23:34 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 21:42:56 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	free_vars(void)
{
	if (all.vars)
	{
		if (all.vars->head)
		{
			top_lst(&all.vars->head);
			ft_free_list(&all.vars->head);
		}
		if (all.vars->str)
			free(all.vars->str);
		if (all.vars->env)
			ft_free_matrix(&all.vars->env);
		if (all.vars->div)
			ft_free_matrix(&all.vars->div);
		free(all.vars);
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