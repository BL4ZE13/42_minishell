/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:43:44 by diomari           #+#    #+#             */
/*   Updated: 2023/12/06 11:14:19 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cmd_nf(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	g_all.status = 127;
	return ;
}

void	is_dir(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": is a directory\n", 17);
	g_all.status = 126;
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
		g_all.status = 127;
		return ;
	}
	else if (access(cmd, X_OK))
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, ": permisson denided\n", 20);
		g_all.status = 126;
		return ;
	}
	else
	{
		perror("");
		g_all.status = errno;
	}
}

int	hd_error(char *str)
{
	write(2, "warning: here-document at line 1 \
	delimited by end-of-file (wanted `", 67);
	write(2, str, ft_strlen(str));
	write(2, "')\n", 3);
	return (1);
}
