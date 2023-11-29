/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:03:17 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 10:20:26 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	top_lst(&lst);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
