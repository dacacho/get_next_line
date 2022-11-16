/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:41:04 by danierod          #+#    #+#             */
/*   Updated: 2022/08/24 14:39:01 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			nb;

	tmp = NULL;
	nb = 1;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (tmp);
	while (nb > 0)
	{
		if (!buf[0])
			nb = read(fd, buf, BUFFER_SIZE);
		if (nb > 0)
			tmp = newline(buf, tmp);
		if (checknl(buf))
			break ;
	}
	return (tmp);
}
