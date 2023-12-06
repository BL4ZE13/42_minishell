/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:27 by diomari           #+#    #+#             */
/*   Updated: 2023/12/04 15:59:59 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	bpn(t_env **lst)
{
	(*lst)->prev->next = (*lst)->next;
	(*lst)->next->prev = (*lst)->prev;
	*lst = (*lst)->next;
}

t_env	*env_dup(char **env)
{
	int		i;
	t_env	*res;

	i = -1;
	res = NULL;
	while (env[++i])
		e_add_back(&res, e_new(ft_strdup(env[i])));
	return (res);
}

void	e_exec(t_list **lst)
{
	(void)lst;
	if (lst && (*lst)->ct[1])
	{
		write(2, "env: '", 6);
		write(2, (*lst)->ct[1], ft_strlen((*lst)->ct[1]));
		write(2, "': No such file or directory\n", 29);
		g_all.status = 127;
		return ;
	}
	while (g_all.env && g_all.env->ct)
	{
		if (ft_strchr(g_all.env->ct, '='))
			printf("%s\n", g_all.env->ct);
		if (!g_all.env->next)
			break ;
		g_all.env = g_all.env->next;
	}
	e_top(&g_all.env);
	g_all.status = 0;
}
