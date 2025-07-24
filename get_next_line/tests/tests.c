#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> // for free

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;

	printf("Test empty file:\n");
	fd = open("tests/test_empty.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((next_line = get_next_line(fd)))
	{
		printf("get_next_line call no.:%d\n", i);
		++i;
		printf("%s", next_line);
		free(next_line);

	}
	close(fd);

	printf("\nTest long lines file:\n");
	fd = open("tests/test_long_lines.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((next_line = get_next_line(fd)))
	{
		printf("get_next_line call no.:%d\n", i);
		++i;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);

	printf("\nTest short lines file:\n");
	fd = open("tests/test_short_lines.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	i = 1;
	while ((next_line = get_next_line(fd)))
	{
		printf("get_next_line call no.:%d\n", i);
		++i;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);

	return (0);
}
