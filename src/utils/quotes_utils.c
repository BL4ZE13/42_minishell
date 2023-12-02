/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:03:27 by diomari           #+#    #+#             */
/*   Updated: 2023/12/02 19:15:59 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	str_q_del(char **input, char c)
{
	char	*tmp;
	int		i;
	int		j;
	int		flag;

	tmp = ft_calloc(ft_strlen(*input) + 1, 1);
	i = -1;
	j = 0;
	flag = 0;
	if (!tmp)
		return ;
	while (input[0][++i])
	{
		if ((input[0][i] == '\'' || input[0][i] == '\"') \
			&& (!c || c == input[0][i]) && (!flag || flag == input[0][i]))
			c = input[0][i] * (c != input[0][i]);
		else
			tmp[j++] = input[0][i];
		if (c)
			flag = c;
		else
			flag = 0;
	}
	free(*input);
	*input = tmp;
}

void	quote_del(char **input)
{
	int	i; 

	i = -1;
	while (input[++i])
	{
		if (ft_strchr(input[i], '\'') || ft_strchr(input[i], '\"'))
			str_q_del(&input[i], 0);
	}
}

void	tr_quote(char *input, int i, int *flag)
{
	char	c;

	c = input[i];
	*flag = c;
	while (input[++i])
	{
		if (c == input[i])
			return ;
	}
	syn_error(&c, input, 1);
}
