/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_lst_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:10:55 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 10:11:23 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	e_lstsize(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	**ft_env_lst_to_array(t_env *lst_env)
{
	int		size;
	char	**arr;
	int		i;

	size = e_lstsize(lst_env);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	e_top(&lst_env);
	while (lst_env)
	{
		arr[i] = ft_strdup(lst_env->ct);
		lst_env = lst_env->next;
		i++;
	}
	arr[size] = NULL;
	return (arr);
}
