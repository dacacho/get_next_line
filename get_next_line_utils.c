/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:41:29 by danierod          #+#    #+#             */
/*   Updated: 2022/08/24 14:41:50 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	getlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		if (str[i] == 10)
			return (i + 1);
	return (i);
}

char	*newline(char *buf, char *tmp)
{
	int		i;
	char	*nl;

	i = 0;
	nl = malloc(getlen(buf) + getlen(tmp) + 1);
	while (tmp && tmp[i])
	{
		nl[i] = tmp[i];
		i++;
	}
	while (*buf)
	{
		nl[i] = *buf++;
		if (nl[i++] == 10)
			break ;
	}
	nl[i] = '\0';
	if (tmp)
		free (tmp);
	return (nl);
}

int	checknl(char *buf)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	j = 0;
	check = 0;
	while (buf[i] != '\0')
	{
		if (check == 0 && buf[i] == 10)
			check = 1;
		else if (check == 1)
			buf[j++] = buf[i];
		buf[i++] = 0;
	}
	return (check);
}
