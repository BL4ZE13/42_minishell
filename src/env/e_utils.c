/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:52 by diomari           #+#    #+#             */
/*   Updated: 2023/12/06 09:36:53 by diomarti         ###   ########.fr       */
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
	t_env	*new;

	new = (t_env *)ft_calloc(sizeof(t_env), 1);
	if (!new)
		return (NULL);
	new->ct = str;
	return (new);
}

int	free_env(t_env **lst)
{
	t_env	*cur;

	while (*lst)
	{
		cur = (*lst)->next;
		free((*lst)->ct);
		free(*lst);
		*lst = cur;
	}
	return (1);
}

char	*e_search(char **env, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env && env[i] && ft_strncmp(env[i], str, nb_search(env[i], str)))
		i++;
	if (*str == '?')
		return (ft_itoa(g_all.status));
	if (!env[i] || !str || !*str)
		return ("");
	tmp = (env[i] + ft_strlen(str));
	if (*tmp == '=')
		tmp++;
	return (tmp);
}
