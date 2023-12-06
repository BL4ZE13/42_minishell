/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:54 by diomari           #+#    #+#             */
/*   Updated: 2023/12/06 09:18:22 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd_exec(t_list **lst)
{
	char	cwd[1000000];

	(void)lst;
	close_fd(lst, 1);
	if ((*lst)->ct[1] && (*lst)->ct[1][0] == '-')
	{
		write(2, (*lst)->ct[1], ft_strlen((*lst)->ct[1]));
		write(2, ": you silly b*tch\n", 18);
		return ;
	}
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
	{
		perror("Error getting current directory");
		return ;
	}
	g_all.status = 0;
}
