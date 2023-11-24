/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:28:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/24 11:38:45 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	top_lst(t_list	**lst)
{
	while ((lst) && (*lst) && (*lst)->prev)
		(*lst) = (*lst)->prev;
}

t_list	*gen_lst(char *input)
{
	t_list	*lst;
	char	*split;
	int		array[2];

	split = ft_calloc((ft_strlen(input) * 3 + 1), 1);
	if (!split)
		return (NULL);
	array[0] = 0;
	array[1] = 0;
	parser(split, input, 0, array);
	all.vars->div = ft_split(split, 2);
	free(split);
	all.vars->div;
}