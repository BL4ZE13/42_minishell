/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:54:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 20:13:36 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*env_dup(char **env)
{
	int		i = 0;
	t_env	*res = NULL;
	
	while (env[i])
		e_add_back(&res, e_new(ft_strdup(env[i])));
	return (res);
}