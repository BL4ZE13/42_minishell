/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:59:05 by diomari           #+#    #+#             */
/*   Updated: 2023/11/27 10:20:14 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	def_exec(t_list **lst)
{
	char **env;
	
	env = ft_env_lst_to_array(all.env);
	close_fd(lst, 1);
	if (execve((*lst)->path, (*lst)->ct, env) == -1)
		error_handle((*lst)->ct[0]);
	close(0);
	close(1);
	top_lst(lst);
	ft_free_matrix(&env);
	free_env(&all.env);
	free_vars();
	exit(all.status);
}

int	is_builtin(t_list *lst)
{
	if (!ft_strcmp(lst->ct[0], "pwd") || \
		!ft_strcmp(lst->ct[0], "cd") || \
		!ft_strcmp(lst->ct[0], "exit") || \
		!ft_strcmp(lst->ct[0], "env") || \
		!ft_strcmp(lst->ct[0], "export") || \
		!ft_strcmp(lst->ct[0], "unset"))
		return (1);
	else
		return (0);
}

int	fd_check(t_list *lst)
{
	int	res;
	
	res = 0;
	while (lst)
	{
		if (lst->fd_m[0] == -1 || lst->fd_m[1] == -1 \
			|| lst->error[0] || lst->error[1])
			res++;
		lst = lst->next;
	}
	return (res);
}