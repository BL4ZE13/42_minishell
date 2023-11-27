/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:45:02 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/27 10:35:06 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int check_sep(char *str, int *array)
{
	array[0] = 0;
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		array[0] = 2;
	else if (str[0] == '<' || str[0] == '>')
		array[0] = 1;
	else if (str[0] == '|')
		array[0] = 1;
	return (array[0]);
}

void	parser(char *res, char *str, char sep, int *array)
{
	int	len;

	len = 0;
	while (str && *str)
	{
		if ((*str == '\'' || *str == '\"') && (!sep || sep == *str))
			sep = (*str) * (sep != *str);
		else if (*str == ' ' && !sep)
			*str = 2;
		if (!sep && check_sep(str, array))
		{
			*res++ = 2;
			*res++ = (3 - (*str != '|' || len != 0 || array[1] == 0));
			if ((*str != '|' || !array[1]) || len)
				*res++ = *str;
			if (str++ && *str != '|' && array[0] == 2)
				*res++ = *str++;
			*res++ = 2;
			len++;
		}
		else if ((*str == 2 && array[1]) || \
			((*str != 2 || *str++ != 2) && ++array[1]))
			len = !(!!(*res++ = *str++));
	}
}
