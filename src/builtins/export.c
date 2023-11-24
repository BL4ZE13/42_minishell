/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:42 by diomari           #+#    #+#             */
/*   Updated: 2023/11/24 11:47:51 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	expo_core(t_list **lst, char **str, int i)
{
	t_env	*cur;

	cur = NULL;
	if (!str || !str[0])
	{
		expo_error(lst, str, i);
		return ;
	}
	cur = e_search_lst(str[0]);
	if (!cur)
		e_add_back(&(all.env), e_new(ft_strdup((*lst)->ct[i])));
	if (cur)
	{
		if (str[1])
		{
			free(cur->ct);
			cur->ct = ft_strdup((*lst)->ct[i]);
		}
	}
	all.status = 0;
	ft_free_matrix(&str);
}

void	expo_error(t_list **lst, char **str, int i)
{
	write(2, "minishell: export: \'", 21);
	write(2, ((*lst)->ct[i]), ft_strlen((*lst)->ct[i]));
	write(2, "\' not a valid identifier\n", 26);
	ft_free_matrix(&str);
	all.status = 1;
}

void	expo_only(void)
{
	char	**env;

	env = ft_env_lst_to_array(all.env);
	ft_bubble_sort(env, ft_matrixlen(env));
	mod_matrix(env);
	ft_free_matrix(&env);
	return ;
}

void	export_exec(t_list **lst)
{
	char	**str;
	int		i;

	i = 1;
	if (!(*lst)->ct[1])
		expo_only();
	while ((*lst)->ct[1])
	{
		str = ft_split((*lst)->ct[1], '=');
		if ((*lst)->ct[i][0] == '=' || (str && !ft_isalnum(str[0])) \
			|| ft_isdigit((*lst)->ct[i][0]))
			expo_error(lst, str, i);
		else
			expo_core(lst, str, i);
		i++;
	}
}
