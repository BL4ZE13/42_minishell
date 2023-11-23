/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:07:43 by diomari           #+#    #+#             */
/*   Updated: 2023/11/23 19:06:01 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] && matrix[i][0] != 3)
		i++;
	return (i);
}
