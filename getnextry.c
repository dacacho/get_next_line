#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*set_part(char *s1, char *s2, int len)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc((ft_strlen(s1) + (ft_strlen(s2) + len) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i] || s2[i] == 10)
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*tmp;
	int			nbytes;

	nbytes = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024)
		return (tmp);
	while (1)
	{
		if (buf[0])
			set_part(tmp, buf, checkchr(buf, 10));
		if (checkchr(tmp, 10) != -1)
			break ;
		nbytes = read(fd, buf, BUFFER_SIZE);
	}
	return (tmp);
}

int	main(void)
{
	int	fd = open("text1.txt", O_RDONLY);
	char	*str = get_next_line(fd);

	printf("%s", str);
	return (0);
}
