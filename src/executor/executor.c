/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:43:40 by diomari           #+#    #+#             */
/*   Updated: 2023/11/25 19:53:56 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exe_core(t_list *lst)
{
	char **env;

	while (lst)
	{
		if (lst->ct[0] && !lst->error[0] && !lst->error[1])
		{
			env = ft_env_lst_to_array(all.env);
			lst->path = cmd_path(env, lst->ct);
			ft_free_matrix(&env);
			
		}
	}
}

void	executor(t_list *lst)
{
	int		status;
	pid_t	i;
	
	
}