/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:41:57 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/22 10:42:57 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_fd(t_list **lst, int flag)
{
	t_list	*tmp;

	tmp = (*lst);
	if (flag)
		top_lst(lst);
	while ((*lst))
	{
		close((*lst)->fd[0]);
		close((*lst)->fd[1]);
		if ((*lst)->fd_m[1] > 2)
			close((*lst)->fd_m[1]);
		if ((*lst)->fd_m[0] > 2)
			close((*lst)->fd_m[0]);
		if (!flag)
			break ;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}
