/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:01:35 by diomari           #+#    #+#             */
/*   Updated: 2023/11/29 09:42:32 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_exec(t_list **lst)
{
	t_env	*cur;
	int		i;

	i = 1;
	if (!(*lst)->ct[1])
		return ;
	while ((*lst)->ct[i])
	{
		cur = e_search_lst((*lst)->ct[i]);
		if (cur)
			e_del(&cur);
		i++;
	}
	g_all.status = 0;
}
