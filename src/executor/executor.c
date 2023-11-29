/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 19:43:40 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 09:43:47 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_op(t_list *lst)
{
	if (!ft_strcmp(lst->ct[0], "cd"))
		lst->ft_exec = cd_exec;
	else if (!ft_strcmp(lst->ct[0], "echo"))
		lst->ft_exec = echo_exec;
	else if (!ft_strcmp(lst->ct[0], "export"))
		lst->ft_exec = export_exec;
	else if (!ft_strcmp(lst->ct[0], "pwd"))
		lst->ft_exec = pwd_exec;
	else if (!ft_strcmp(lst->ct[0], "unset"))
		lst->ft_exec = unset_exec;
	else if (!ft_strcmp(lst->ct[0], "env"))
		lst->ft_exec = e_exec;
	else if (!ft_strcmp(lst->ct[0], "exit"))
		lst->ft_exec = exit_exec;
	else
		lst->ft_exec = def_exec;
}

void	exec_cmd(t_list *lst)
{
	if (is_builtin(lst) && (ft_lstsize(lst) == 1))
	{
		lst->ft_exec(&lst);
		if (lst->ct && (!ft_strncmp(lst->ct[0], "exit", 5)) && \
		free_env(&g_all.env) && free_vars() && write(2, "exit\n", 5))
			exit(g_all.status);
		return ;
	}
	if (fork() == 0)
	{
		if (lst->prev && lst->fd_m[0] < 3)
			dup2(lst->fd[0], 0);
		else if (lst->fd_m[0] < 2)
			dup2(lst->fd_m[0], 0);
		if (lst->next && lst->fd_m[1] < 3)
			dup2(lst->next->fd[1], 1);
		else if (lst->fd_m[1] > 2)
			dup2(lst->fd_m[1], 1);
		lst->ft_exec(&lst);
		free_env(&g_all.env);
		free_vars();
		close(0);
		exit(g_all.status);
	}
	close_fd(&lst, 0);
}

void	exe_core(t_list *lst)
{
	char	**env;

	while (lst)
	{
		if (lst->ct[0] && !lst->error[0] && !lst->error[1])
		{
			env = ft_env_lst_to_array(g_all.env);
			lst->path = cmd_path(env, lst->ct);
			ft_free_matrix(&env);
			exec_op(lst);
			exec_cmd(lst);
		}
		if (!lst->next)
			break ;
		lst = lst->next;
	}
}

void	executor(t_list *lst)
{
	int		status;
	pid_t	i;

	exe_core(lst);
	top_lst(&lst);
	while (lst)
	{
		if (lst->ct[0])
		{
			i = waitpid(-1, &status, 0);
			if (i != -1 && WIFEXITED(status))
				g_all.status = WEXITSTATUS(status);
		}
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	if (fd_check(lst))
		g_all.status = 1;
}
