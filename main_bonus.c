#include "get_next_line_bonus.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;

	fd = open("normal.txt", O_RDONLY);
    fd1 = open("bonus.txt", O_RDONLY);
	fd2 = open("bonus1.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("normal : \"%s\"\n", line);
	free(line);
	line = get_next_line(fd1);
	printf("bonus : \"%s\"\n", line);
	free(line);
	line = get_next_line(fd2);
	printf("bonus1 : \"%s\"\n", line);
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("normal : \"%s\"\n", line);
		free(line);
		line = get_next_line(fd1);
		printf("bonus : \"%s\"\n", line);
		free(line);
		line = get_next_line(fd2);
		printf("bonus1 : \"%s\"\n", line);
		free(line);
	}
	system("leaks a.out");
	return (0);
}