#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"  // use relative path if needed

int	main(void)
{
	char	*str = "Hello world!";
	char	*sub = ft_substr(str, 6, 3);

	if (sub)
	{
		printf("Result: %s\n", sub); // Expected: "wor"
		free(sub);
	}
	else
	{
		printf("Returned NULL\n");
	}
	return 0;
}