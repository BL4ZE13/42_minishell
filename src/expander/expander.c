/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:39:06 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/27 19:33:18 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*str_prep(char *str, int i, int len)
{
	char	*res;
	int		j;

	j = 0;
	i -= len - 1;
	res = ft_calloc(len + 1, 1);
	while (str[i] && j < len)
		res[j++] = str[i++];
	return (res);
}

//se n der com 0 exprimentar com -1 o i
char	**exp_prep(char *str)
{
	int		i;
	int		j;
	int		len;
	int		sep;
	char	**matrix;

	i = 0;
	j = 0;
	len = 0;
	sep = -1;
	matrix = ft_calloc(1024, sizeof(char *));
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && \
			(!sep || sep == str[i] || sep == -1))
			sep = (str[i]) * (sep != str[i]);
		if (++len && ((!sep && len) || ((str[i + 1] == '\'' \
			|| str[i + 1] == '\"') && sep < 0 && len)))
		{
			matrix[j++] = str_prep(str, i, len);
			len = 0;
		}
		i++;
	}
	*str = 0;
	return (matrix);
}

void	exp_loop(char ***div, char **env, int *i, int *j)
{
	int		k;
	char	**tmp;
	char	*str;

	tmp = NULL;
	tmp = exp_prep(div[0][i[0]]);
	k = -1;
	while (tmp[++k])
	{
		if (*tmp[k] != '\'')
			tmp[k] = chg_dollar(tmp[k], env);
	}
	k = -1;
	while (tmp[++k])
	{
		str = div[0][i[0] - j[0]];
		div[0][i[0] - j[0]] = ft_strjoin(str, tmp[k]);
		free(str);
	}
	ft_free_matrix(&tmp);
}

void	exp_util(char ***div, char **env, int *i, int *j)
{
	while (div[0][++i[0]])
	{
		if (ft_strchr(div[0][i[0]], '\'') || \
			ft_strchr(div[0][i[0]], '\"'))
			exp_loop(div, env, i, j);
		else
			div[0][i[0] - j[0]] = chg_dollar(div[0][i[0]], env);
		if (!div[0][i[0] - j[0]][0])
			free(div[0][i[0] - j[0]++]);
	}
}

char	**expander(char **div, char **env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	exp_util(&div, env, &i, &j);
	while (j)
		!(div[--i] = NULL) && j--;
	ft_free_matrix(&env);
	return (div);
}