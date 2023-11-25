/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:45:40 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/25 18:27:08 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_alphnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	chg_dollar_loop(char **input, char **buff, int *i, int *j)
{
	while (input && input[0] && input[0][++i[0]])
	{
		if (input[0][i[0]] == '$' || j[0])
			buff[0][j[0]++] = input[0][i[0]];
		if ((j[0] && !is_alphnum(input[0][i[0] + 1]) && \
			!(j[0] == 1 && input[0][i[0] + 1] == '?')) || buff[0][1] == '?')
		{
			if (j[0] == 1)
			{
				buff[0][0] = 0;
				j[0] = 0;
			}
			else
				break ;
		}
	}
}

char	*chg_dollar(char *input, char **env)
{
	char	*buff;
	char	*str;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	buff = ft_calloc(1024, 1);
	chg_dollar_loop(&input, &buff, &i, &j);
	if (!j)
	{
		free(buff);
		return (input);
	}
	tmp = e_search(env, buff + 1);
	str = ft_replacement(input, buff, tmp);
	if (*(buff + 1) == '?')
		free(tmp);
	free(input);
	free(buff);
	return (chg_dollar(str, env));
}
