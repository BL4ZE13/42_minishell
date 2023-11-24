/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:57:08 by diomari           #+#    #+#             */
/*   Updated: 2023/11/24 10:36:36 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_isnum(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	exit_ov(t_list **lst)
{
	int	i;

	i = 0;
	if ((*lst)->ct[1] && (*lst)->ct[1][0])
		i = 0 + ((*lst)->ct[1][0] == '-' || (*lst)->ct[1][0] == '+');
	if ((*lst)->ct[1] && (ft_strlen((*lst)->ct[1] + i) > 19 || \
		(i && ft_strlen((*lst)->ct[1]) == 20 && \
		ft_strncmp("-9223372036854775808", (*lst)->ct[1], 20) < 0) || \
		(!i && ft_strlen((*lst)->ct[1]) == 19 && \
		ft_strncmp("9223372036854775807", (*lst)->ct[1], 19) < 0)))
	{
		write(2, "minishell: exit: ", 17);
		write(2, (*lst)->ct[1], ft_strlen((*lst)->ct[1]));
		write(2, ": numeric argument required\n", 29);
		return (1);
	}
	return (0);
}

void	exit_exec(t_list **lst)
{
	int	n;

	if (exit_ov(lst))
		all.status = 2;
	else if ((*lst)->ct[1] && (*lst)->ct[2])
	{
		all.status = 1;
		write(2, "minishell: exit: too many arguments\n", 37);
	}
	else if ((*lst)->ct[1] && ft_isnum((*lst)->ct[1]) == 0)
	{
		all.status = 2;
		write(2, "minishell: exit: ", 17);
		write(2, (*lst)->ct[1], ft_strlen((*lst)->ct[1]));
		write(2, ": numeric argument required\n", 29);
	}
	else if ((*lst)->ct[1])
	{
		n = ft_atoi((*lst)->ct[1]);
		if (n >= 256)
			n -= 256;
		all.status = n;
	}
}
