#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	*next_line;

	printf("Test empty file:\n");
	fd = open("test_empty.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while(next_line)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
		printf("\n");
	}
	close(fd);
	printf("Test long lines file:\n");
	fd = open("test_long_lines.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while(next_line)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
		printf("\n");
	}
	close(fd);
	printf("Test short lines file:\n");
	fd = open("test_short_lines.txt", O_RDONLY);
	next_line = get_next_line(fd);
	while(next_line)
	{
		printf("%s", next_line);
		free(next_line);
		next_line = get_next_line(fd);
		printf("\n");
	}
	close(fd);
	return (1);
}
