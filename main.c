#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	fd = 0;
	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	char *line;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	return (0);
}
