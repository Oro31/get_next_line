/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 01:58:33 by rvalton           #+#    #+#             */
/*   Updated: 2020/03/02 15:32:07 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_init(void)
{
	char	*tmp;

	if (!(tmp = malloc(sizeof(char))))
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

int			is_endl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] == '\0' && i < BUFFER_SIZE)
		i++;
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

static void	get_fill(char *buf, char *tmp, int i)
{
	int	j;

	j = 0;
	while (buf[j] == '\0' && j < BUFFER_SIZE)
		j++;
	while (buf[j] != '\n' && j < BUFFER_SIZE)
	{
		tmp[i] = buf[j];
		buf[j] = '\0';
		i++;
		j++;
	}
	if (buf[j] == '\n')
		buf[j] = '\0';
	tmp[i] = '\0';
}

char		*get_realloc(char *buf, char **line)
{
	int		i;
	int		n;
	int		j;
	char	*tmp;

	i = 0;
	while (line[0][i])
		i++;
	j = 0;
	while (buf[j] == '\0' && j < BUFFER_SIZE)
		j++;
	n = 0;
	while (buf[j + n] != '\n' && (j + n) < BUFFER_SIZE)
		n++;
	if (!(tmp = malloc(sizeof(char) * (i + n + 3))))
		return (NULL);
	tmp[i + n + 2] = '\0';
	j = -1;
	while (line[0][++j])
		tmp[j] = line[0][j];
	get_fill(buf, tmp, i);
	free(line[0]);
	return (tmp);
}
