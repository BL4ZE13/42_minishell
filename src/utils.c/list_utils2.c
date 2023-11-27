/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:03:17 by diomari           #+#    #+#             */
/*   Updated: 2023/11/27 10:03:31 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	go_head(&lst);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
