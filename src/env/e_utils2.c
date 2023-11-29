/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:15 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 09:42:51 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	nb_search(char *s1, char *s2)
{
	int	res;
	int	i;

	res = ft_strlen(s2);
	i = 0;
	while (s1[i] && s1[i] != '=')
		i++;
	if (i > res)
		return (i);
	return (res);
}

size_t	var_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

void	e_top(t_env **env)
{
	while ((env) && (*env) && (*env)->prev)
		(*env) = (*env)->prev;
}

t_env	*e_search_lst(char *input)
{
	t_env	*cur;

	cur = g_all.env;
	e_top(&cur);
	while (cur && cur->ct)
	{
		cur = cur->next;
		if (!cur)
			break ;
		if (!ft_strncmp(cur->ct, input, ft_strlen(input)) \
			&& var_size(cur->ct) == ft_strlen(input))
			return (cur);
	}
	return (NULL);
}

void	e_del(t_env **lst)
{
	t_env	*cur;

	cur = (*lst);
	if (lst && *lst)
	{
		if (!(*lst)->prev && !(*lst)->next)
			*lst = NULL;
		else if (!(*lst)->prev && (*lst)->next)
		{
			(*lst)->next->prev = NULL;
			*lst = (*lst)->next;
		}
		else if ((*lst)->prev && !(*lst)->next)
		{
			(*lst)->prev->next = NULL;
			*lst = (*lst)->prev;
		}
		else if ((*lst)->prev && (*lst)->next)
			bpn(lst);
		if (cur->ct)
			free(cur->ct);
		free(cur);
	}
}
