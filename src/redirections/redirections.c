/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:10:28 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 09:44:19 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	token_check(char *str)
{
	if (!ft_strcmp(str, "<<"))
		return (1);
	else if (!ft_strcmp(str, ">>"))
		return (2);
	else if (!ft_strcmp(str, "<"))
		return (3);
	else if (!ft_strcmp(str, ">"))
		return (4);
	return (0);
}

void	inv_fd(t_list *lst)
{
	if (lst->fd_m[0] == -1)
	{
		perror("");
		g_all.status = 1;
		lst->error[0] = 1;
	}
	if (lst->fd_m[1] == -1)
	{
		perror("");
		g_all.status = 1;
		lst->error[1] = 1;
	}
}

void	token_red(char **div, int *i, t_list *lst)
{
	int	op;

	if ((lst->fd_m[0] != -1 && lst->fd_m[1] != -1) || op == 1)
	{
		if (lst->fd_m[0] > 2 && (op == 1 || op == 3))
			close(lst->fd_m[0]);
		if (lst->fd_m[1] > 2 && (op == 2 || op == 4))
			close(lst->fd_m[1]);
		if (op == 2)
			lst->fd_m[1] = open(div[++(*i)], \
			O_WRONLY | O_APPEND | O_CREAT, 0644);
		else if (op == 1)
			lst->fd_m[0] = ft_heredoc(div[++(*i)]);
		else if (op == 3)
			lst->fd_m[0] = open(div[++(*i)], O_RDONLY, 0644);
		else if (op == 4)
			lst->fd_m[1] = open(div[++(*i)], \
			O_WRONLY | O_TRUNC | O_CREAT, 0644);
		inv_fd(lst);
	}
}

void	redirection(t_list *lst, char **div)
{
	int		i;
	int		j;
	t_list	*cur;

	i = -1;
	j = 0;
	cur = lst;
	quote_del(div);
	while (div && div[++i])
	{
		if (div[i][0] == 3)
		{
			ft_lstadd_back(&lst, ft_lstnew(ft_matrixlen(&div[i + 1])));
			if (cur->next)
				cur = cur->next;
			j = 0;
		}
		else if (token_check(div[1]))
			token_red(div, &i, cur);
		else
			cur->ct[j++] = ft_strdup(div[i]);
	}
}
