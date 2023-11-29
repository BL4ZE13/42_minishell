/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diomarti <diomarti@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:22:56 by diomarti          #+#    #+#             */
/*   Updated: 2023/11/29 09:46:10 by diomarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	syn_sep(char *str, int *array)
{
	array[0] = 0;
	if ((str[0] == '<' && str[1] == '<') || (str[0] == '>' && str[1] == '>'))
		array[0] = 2;
	else if (str[0] == '<' || str[0] == '>')
		array[0] = 1;
	else if (str[0] == '|')
		array[0] = 1;
	else if (str[0] == ';')
		array[0] = 1;
	if (str[0] == '|')
		return (4);
	else
		return (array[0]);
}

//se n der mudar para -1 e ++i
void	syn_error(char *str, char *input, int size)
{
	int	i;

	i = 0;
	write(2, "minishell: syntax error near unexpected token `", 47);
	while (size != 0 && str[i])
	{
		write(2, &str[i++], 1);
		size--;
	}
	write(2, "\'\n", 2);
	if (input)
		free(input);
	g_all.status = 2;
	shell();
}

void	tr_sep(char *input, int i, int size, int *wd)
{
	int	tmp;
	int	n;
	int	sep;

	tmp = 0;
	n = 0;
	sep = 0;
	if (input[i] == '|')
		sep = input[i];
	if (input[i] == '|' && input[i + 1] == '|')
		syn_error("||", input, 2);
	else if (*wd == 0 && input[i] == '|')
		syn_error("|", input, 1);
	i += size;
	while (input[i])
	{
		if (((!sep && syn_sep(&input[i], &tmp)) \
			|| (sep && syn_sep(&input[i], &tmp) == 4)) && !n)
			syn_error(&input[i], input, tmp);
		else if (input[i] != 32)
			n++;
		i++;
	}
	if (!n)
		syn_error("newline", input, 8);
}

void	syntax(char *input)
{
	int	array[5];
	int	i;

	i = 0;
	while (i <= 4)
		array[i++] = 0;
	if (!input)
		return ;
	while (input[array[0]])
	{
		if ((input[array[0]] == '\'' || input[array[0]] == '\"') \
			&& (!array[4] || array[4] == input[array[0]]))
			array[4] = (input[array[0]]) * (array[4] != input[array[0]]);
		if (!array[4] && syn_sep(&input[array[0]], &(array[1])))
			tr_sep(input, array[0], array[1], &(array[2]));
		else if ((input[array[0]] == '\"' && !array[3]) \
			|| (input[array[0]] == '\'' && !array[3]))
			tr_quote(input, array[0], &array[3]);
		else if (input[array[0]] == array[3])
			array[3] = 0;
		else if (input[array[0]] != 32)
			(array[2])++;
		(array[0]) += (array[1] == 2);
		(array[0])++;
	}
}
