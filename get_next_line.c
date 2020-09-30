/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 02:03:14 by rvalton           #+#    #+#             */
/*   Updated: 2020/03/02 15:48:36 by rvalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			rd_rtn_value;
	static char	buf[BUFFER_SIZE] = {0};

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(line[0] = get_init()))
		return (-1);
	while (!(is_endl(buf)))
	{
		if (!(line[0] = get_realloc(buf, line)))
			return (-1);
		rd_rtn_value = read(fd, buf, BUFFER_SIZE);
		if (rd_rtn_value == -1)
			return (-1);
		else if (rd_rtn_value == 0)
			return (0);
	}
	if (is_endl(buf))
	{
		if (!(line[0] = get_realloc(buf, line)))
			return (-1);
	}
	return (1);
}
