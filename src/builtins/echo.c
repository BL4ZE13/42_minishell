/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:56:54 by diomari           #+#    #+#             */
/*   Updated: 2023/11/22 10:35:09 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_mt(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (str[j])
		j++;
	while (str[i])
	{
		if ((i + 1) != j)
			printf("%s ", str[i]);
		else
			printf("%s ", str[i]);
		i++;
	}
}

void	echo_op(t_list **lst, int *flag)
{
	int	i;

	i = 1;
	while ((*lst)->ct[1][i])
	{
		if ((*lst)->ct[1][i] != 'n')
		{
			(*flag)++;
			break ;
		}
		i++;
	}
	if (!(*flag))
		(*flag) = 2;
}

void	echo_exec(t_list **lst)
{
	int	flag;

	flag = 0;
	close_fd(lst, 1);
	if ((*lst)->ct[1] && (*lst)->ct[1][0] == '-' && (*lst)->ct[1][1])
		echo_op(lst, &flag);
	if (flag == 1 || !flag)
	{
		print_mt((*lst)->ct, 1);
		printf("\n");
	}
	else if (flag == 2)
		print_mt((*lst)->ct, 2);
	all.status = 0;
}
