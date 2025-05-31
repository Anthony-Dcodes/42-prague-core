#include <stdio.h>
#include <stdlib.h>
#include "libft.h"  // Make sure this includes ft_split

void	print_split_result(char **result)
{
	if (!result)
	{
		printf("Result: NULL\n");
		return;
	}
	for (int i = 0; result[i]; i++)
		printf("result[%d] = \"%s\"\n", i, result[i]);
}

int	main(void)
{
	char *test1 = "hello world this is libft";
	char *test2 = "   space   split   ";
	char *test3 = "";
	char *test4 = "only_one_word";
	char *test5 = "////a///b//c//";
	char *test6 = NULL;

	printf("Test 1:\n");
	print_split_result(ft_split(test1, ' '));

	printf("\nTest 2:\n");
	print_split_result(ft_split(test2, ' '));

	printf("\nTest 3:\n");
	print_split_result(ft_split(test3, ' '));

	printf("\nTest 4:\n");
	print_split_result(ft_split(test4, ' '));

	printf("\nTest 5:\n");
	print_split_result(ft_split(test5, '/'));

	printf("\nTest 6 (NULL input):\n");
	print_split_result(ft_split(test6, ' '));

	return (0);
}
