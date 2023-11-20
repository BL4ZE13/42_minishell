/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_utils2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:16:15 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 18:38:18 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int nb_search(char *s1, char *s2)
{
	int res = ft_strlen(s2);
	int i = 0;
	
	while (s1[i] && s1[i] != '=')
		i++;
	if (i > res)
		return (i);
	return (res);
}

size_t	var_size(char *str)
{
	int i = 0;

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

	cur = all.env;
	e_top(&cur);
	while (cur && cur->ct)
	{
		cur = cur->next;
		if (!cur)
			break ;
		if (!ft_strncmp(cur->ct, input, ft_strlen(input)) && var_size(cur->ct) == ft_strlen(input))
			return (cur);
	}
	return (NULL);
}