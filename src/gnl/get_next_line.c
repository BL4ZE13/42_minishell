/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomari <diomarti@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:22:21 by diomari           #+#    #+#             */
/*   Updated: 2023/11/20 17:22:23 by diomari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			flag;

	if (BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin_gnl(line, buffer);
		i = 0;
		j = 0;
		while (buffer[i])
		{
			if (flag)
				buffer[j++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}
