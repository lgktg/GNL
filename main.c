#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	char *line;
	char	*line2;
	(void)ac;
	int fd = open(av[1], O_RDONLY);
	int	fd2 = open(av[2], O_RDONLY);
	while (get_next_line(0, &line) > 0 || get_next_line(fd2, &line2) > 0)
	{
		printf("%s\n", line);
		ft_strdel(&line);
		printf("%s\n", line2);
		ft_strdel(&line2);
	}
	return (0);
}
