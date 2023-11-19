/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 20:13:05 by diomari           #+#    #+#             */
/*   Updated: 2023/11/19 20:13:07 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*arr;
	size_t	i;

	i = -1;
	arr = malloc(elsize * nelem);
	if (!arr)
		return (NULL);
	if (nelem != 0)
	{
		while (++i < (elsize * nelem))
			arr[i] = 0;
		return ((void *)arr);
	}
	return ((void *)arr);
}
