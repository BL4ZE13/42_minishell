/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:22:18 by diomari           #+#    #+#             */
/*   Updated: 2023/11/25 18:22:43 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_replacement(char *str, char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (!str)
		return (NULL);
	res = ft_calloc(ft_strlen(str) + ft_strlen(s2) + 1, 1);
	i = 0;
	j = 0;
	k = -1;
	while (str[++k])
	{
		if (!ft_strncmp(s1, &str[k], ft_strlen(s1)) && !j)
		{
			while (s2[j])
				res[i++] = s2[j++];
			j++;
			k += ft_strlen(s1) - 1;
		}
		else
			res[i++] = str[k];
	}
	return (res);
}
