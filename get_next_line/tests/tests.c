#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Test helper function to run a single file test
void test_file(const char *filename, const char *test_name)
{
	int fd;
	char *next_line;
	int i;

	printf("\n=== %s ===\n", test_name);
	printf("Testing file: %s\n", filename);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		printf("Failed to open %s\n", filename);
		return;
	}

	i = 1;
	while ((next_line = get_next_line(fd)))
	{
		printf("get_next_line returned: %s\n", next_line);
		printf("Line %d: ", i);
		// Show the line with visible newline indicators
		for (int j = 0; next_line[j]; j++)
		{
			if (next_line[j] == '\n')
				printf("\\n");
			else
				printf("%c", next_line[j]);
		}
		printf("\n");
		free(next_line);
		i++;
	}

	printf("Total lines read: %d\n", i - 1);
	close(fd);
}

// Test multiple calls after EOF
void test_multiple_calls_after_eof(const char *filename)
{
	int fd;
	char *next_line;
	int i;

	printf("\n=== Testing multiple calls after EOF ===\n");
	printf("File: %s\n", filename);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return;
	}

	// Read all lines normally
	i = 1;
	while ((next_line = get_next_line(fd)))
	{
		printf("Line %d read\n", i++);
		free(next_line);
	}

	// Try to read more lines after EOF
	printf("Attempting to read after EOF:\n");
	for (int j = 0; j < 3; j++)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			printf("Call %d after EOF: NULL (correct)\n", j + 1);
		else
		{
			printf("Call %d after EOF: Got unexpected data: %s\n", j + 1, next_line);
			free(next_line);
		}
	}

	close(fd);
}

// Test multiple file descriptors
void test_multiple_fds(void)
{
	int fd1, fd2;
	char *line1, *line2;

	printf("\n=== Testing multiple file descriptors ===\n");

	fd1 = open("tests/test_short_lines.txt", O_RDONLY);
	fd2 = open("tests/test_long_lines.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		perror("open");
		if (fd1 != -1) close(fd1);
		if (fd2 != -1) close(fd2);
		return;
	}

	// Alternate reading from both files
	for (int i = 0; i < 3; i++)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);

		printf("FD1 line %d: %s", i + 1, line1 ? line1 : "NULL\n");
		printf("FD2 line %d: %s", i + 1, line2 ? line2 : "NULL\n");

		if (line1) free(line1);
		if (line2) free(line2);

		if (!line1 && !line2) break;
	}

	close(fd1);
	close(fd2);
}

// Test invalid file descriptor
void test_invalid_fd(void)
{
	char *line;

	printf("\n=== Testing invalid file descriptor ===\n");

	line = get_next_line(-1);
	printf("get_next_line(-1): %s\n", line ? line : "NULL (correct)");
	if (line) free(line);

	line = get_next_line(999);
	printf("get_next_line(999): %s\n", line ? line : "NULL (correct)");
	if (line) free(line);
}

int main(void)
{
	printf("GET_NEXT_LINE TESTER\n");
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf("==================\n");

	// Test different files
	test_file("tests/test_empty.txt", "Empty file test");
	test_file("tests/test_short_lines.txt", "Short lines test");
	test_file("tests/test_long_lines.txt", "Long lines test");
	test_file("tests/code_text.txt", "Code text test");

	// Additional comprehensive tests
	test_multiple_calls_after_eof("tests/test_short_lines.txt");
	test_multiple_fds();
	test_invalid_fd();

	printf("\n=== Standard input test ===\n");
	printf("Type some lines (Ctrl+D to end):\n");

	char *next_line;
	int i = 1;
	while ((next_line = get_next_line(0)))
	{
		printf("STDIN Line %d: %s", i++, next_line);
		free(next_line);
	}

	printf("\nAll tests completed!\n");
	return (0);
}
