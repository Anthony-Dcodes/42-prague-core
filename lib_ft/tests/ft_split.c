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

void	free_split_result(char **result)
{
	int i;

	if (!result)
		return;
	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	main(void)
{
	char *test1 = "hello world this is libft";
	char *test2 = "   space   split   ";
	char *test3 = "";
	char *test4 = "only_one_word";
	char *test5 = "////a///b//c//";
	char *test6 = NULL;
	char **result;

	printf("Test 1:\n");
	result = ft_split(test1, ' ');
	print_split_result(result);
	free_split_result(result);

	printf("\nTest 2:\n");
	result = ft_split(test2, ' ');
	print_split_result(result);
	free_split_result(result);

	printf("\nTest 3:\n");
	result = ft_split(test3, ' ');
	print_split_result(result);
	free_split_result(result);

	printf("\nTest 4:\n");
	result = ft_split(test4, ' ');
	print_split_result(result);
	free_split_result(result);

	printf("\nTest 5:\n");
	result = ft_split(test5, '/');
	print_split_result(result);
	free_split_result(result);

	printf("\nTest 6 (NULL input):\n");
	result = ft_split(test6, ' ');
	print_split_result(result);
	free_split_result(result);  // This will handle NULL safely

	return (0);
}