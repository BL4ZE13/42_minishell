/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:54 by diomari           #+#    #+#             */
/*   Updated: 2023/11/23 18:59:01 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	pwd_exec(t_list **lst)
{
	char	cwd[_PC_PATH_MAX];
	
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
	all.status = 0;
}