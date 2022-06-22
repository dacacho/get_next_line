#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	checkchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*set_tmp(char *buf, char *tmp, int len)
{
	int	tc;
	int	bc;

	tc = 0;
	bc = 0;
	while (buf[bc])
		tmp[tc + bc] = buf[bc++];
	tmp[tc + bc] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*tmp;
	int			nbytes;

	nbytes = 0;
	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024)
		return (tmp);
	while (1)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes != 0)
			set_tmp(buf, tmp, checkchr(buf, 10));
	}
	return (tmp);
}
