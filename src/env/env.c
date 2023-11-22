/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/22 10:58:29 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bpn(t_env **lst)
{
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	*lst = (*lst)->next;
}

t_env	*env_dup(char **env)
{
	int		i;
	t_env	*res;

	i = 0;
	res = NULL;
	while (env[i])
		e_add_back(&res, e_new(ft_strdup(env[i])));
	return (res);
}
