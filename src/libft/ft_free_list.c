/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:35:32 by diomari           #+#    #+#             */
/*   Updated: 2023/11/23 19:05:49 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_free_list(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		close((*lst)->fd[0]);
		close((*lst)->fd[1]);
		ft_free_matrix(&(*lst)->ct);
		free((*lst)->path);
		free((*lst)->ct);
		free(*lst);
		*lst = temp;
	}
	all.vars->head = NULL;
}

void	print_list(t_list *list)
{
	int	i;

	if (!list)
		return ;
	while (list)
	{
		i = -1;
		printf("[p] %p", list);
		printf("\n[content]: ");
		while (list->ct[++i])
			printf("{%s}, ", list->ct[i]);
		printf("\n");
		printf("[fd in] %i\n", list->fd[0]);
		printf("[fd out] %i\n", list->fd[1]);
		printf("[fd OW in] %i\n", list->fd_m[0]);
		printf("[fd OW out] %i\n", list->fd_m[1]);
		list = list->next;
	}
}
