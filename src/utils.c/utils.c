/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:41:57 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/29 09:33:31 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_fd(t_list **lst, int flag)
{
	t_list	*tmp;

	tmp = (*lst);
	if (flag)
		top_lst(lst);
	while ((*lst))
	{
		close((*lst)->fd[0]);
		close((*lst)->fd[1]);
		if ((*lst)->fd_m[1] > 2)
			close((*lst)->fd_m[1]);
		if ((*lst)->fd_m[0] > 2)
			close((*lst)->fd_m[0]);
		if (!flag)
			break ;
		(*lst) = (*lst)->next;
	}
	(*lst) = tmp;
}

void	mod_matrix(char **array)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
	{
		printf("declare -x ");
		j = 0;
		flag = 0;
		while (array[i][j])
		{
			printf("%c", array[i][j]);
			if (array[i][j] == '=' && !flag)
			{
				printf("\"");
				flag = 1;
			}
			j++;
		}
		printf("\"\n");
	}
}

char	*cmd_path(char **env, char **cmd)
{
	char	**matrix;
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	if (access(cmd[0], X_OK) == 0)
		return (ft_strdup(cmd[0]));
	matrix = ft_split(e_search(env, "PATH"), ':');
	res = ft_strjoin("/", cmd[0]);
	while (matrix[i])
	{
		tmp = ft_strjoin(matrix[i], res);
		if (access(tmp, X_OK) == 0)
		{
			free(res);
			res = tmp;
			break ;
		}
		free(tmp);
		i++;
	}
	ft_free_matrix(&matrix);
	return (res);
}
