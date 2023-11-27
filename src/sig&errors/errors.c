/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:43:44 by diomari           #+#    #+#             */
/*   Updated: 2023/11/27 09:53:11 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cmd_nf(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	all.status = 127;
	return ;
}

void	is_dir(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": is a directory\n", 17);
	all.status = 126;
	return ;
}

void	error_handle(char *cmd)
{
	if (!ft_strchr(cmd, '/'))
		cmd_nf(cmd);
	else if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		is_dir(cmd);
	else if (access(cmd, F_OK) != 0)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": No such file or directory\n", 28);
		all.status = 127;
		return ;
	}
	else if (access(cmd, X_OK))
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": permisson denided\n", 20);
		all.status = 126;
		return ;
	}
	else
	{
		perror("");
		all.status = errno;
	}	
}
