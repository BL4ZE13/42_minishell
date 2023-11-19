/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:52 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 20:10:32 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*e_last(t_env *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	e_add_back(t_env **lst, t_env *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->prev = e_last(*lst);
			e_last(*lst)->next = new;
		}
		else
			*lst = new;
	}
}

t_env	*e_new(char *str)
{
	t_env	*new = (t_env *)ft_calloc(sizeof(t_env), 1);
	
	if (!new)
		return (NULL);
	new->ct = str;
	return (new);
}