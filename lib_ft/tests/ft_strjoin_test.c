#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"  // use relative path if needed

int	main(void)
{
	char	*s1 = "Hello";
	char	*s2 = "World!";

	char	*result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Result: %s\n", result); // Expected: "HelloWorld!"
		free(result);
	}
	else
	{
		printf("Returned NULL\n");
	}
	return 0;
}