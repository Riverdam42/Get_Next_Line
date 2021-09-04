#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("normal.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("LINE : \"%s\"\n", line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("LINE : \"%s\"\n", line);
		if (line != NULL)
			free(line);
	}
	system("leaks a.out");
	return (0);
}