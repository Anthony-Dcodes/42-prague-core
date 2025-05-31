#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"  // use relative path if needed

int	main(void)
{
	char	*s1 = "abababHelloWold!abababaaaa";
	char	*s2 = "ab";

	char	*result = ft_strtrim(s1, s2);
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