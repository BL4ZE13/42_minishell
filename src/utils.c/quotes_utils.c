/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:03:27 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 17:29:27 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	str_q_del(char **input, char c)
{
	char *tmp = ft_calloc(ft_strlen(*input) + 1, 1);
	int i = -1;
	int j = 0;
	int flag = 0;

	if (!tmp)
		return ;
	while (input[0][++i])
	{
		if ((input[0][i] == '\'' || input[0][i] == '\"') && (!c || c == input[0][i]) && (!flag || flag == input[0][i]))
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
	int i = 0; //se n der mudar para -1 e ++i

	while (input[i])
	{
		if (ft_strchr(input[i], '\'') || ft_strchr(input[i], '\"'))
			str_q_del(&input[i], 0);
		i++;
	}
}

void tr_quote(char *input, int i, int *flag)
{
	char c = input[i];
	
	*flag = c;
	while (input[i])
	{
		if (c == input[i])
			return ;
		i++;
	}
	syn_error(&c, input, 1);
}