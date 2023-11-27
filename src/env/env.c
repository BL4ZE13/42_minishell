/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/27 09:37:41 by diomari          ###   ########.fr       */
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

	i = 0;
	res = NULL;
	while (env[i])
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
		all.status = 127;
		return ;
	}
	while (all.env && all.env->ct)
	{
		if (ft_strchr(all.env->ct, '='))
			printf("%s\n", all.env->ct);
		if (!all.env->next)
			break ;
		all.env = all.env->next;
	}
	e_top(&all.env);
	all.status = 0;
}