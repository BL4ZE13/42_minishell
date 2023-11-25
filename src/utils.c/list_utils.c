/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:28:06 by diomari           #+#    #+#             */
/*   Updated: 2023/11/25 19:37:40 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	top_lst(t_list	**lst)
{
	while ((lst) && (*lst) && (*lst)->prev)
		(*lst) = (*lst)->prev;
}

t_list	*ft_lstnew(int i)
{
	t_list	*new;

	new = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!new)
		return (NULL);
	new->ct = ft_calloc(sizeof(char *), i + 1);
	new->fd_m[0] = 0;
	new->fd_m[1] = 1;
	new->error[0] = 0;
	new->error[0] = 0;
	if (pipe(new->fd) == -1)
		perror("");
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
		{
			new->prev = ft_lstlast(*lst);
			ft_lstlast(*lst)->next = new;
		}
		else
			*lst = new;
	}
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
	all.vars->div = expander(all.vars->div, \
	ft_env_lst_to_array(all.env));
	lst = NULL;
	lst = ft_lstnew(ft_matrixlen(all.vars->div));
	all.vars->head = lst;
	redirection(lst, all.vars->div);
	ft_free_matrix(&all.vars->div);
	return (lst);
}