/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_lst_to_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:10:55 by diomari           #+#    #+#             */
/*   Updated: 2023/11/23 19:05:46 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_env_lst_to_array(t_env *lst_env)
{
	int		size;
	char	**arr;
	int		i;

	size = ft_env_lstsize(lst_env);
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	env_go_head(&lst_env);
	while (lst_env)
	{
		arr[i] = ft_strdup(lst_env->ct);
		lst_env = lst_env->next;
		i++;
	}
	arr[size] = NULL;
	return (arr);
}
