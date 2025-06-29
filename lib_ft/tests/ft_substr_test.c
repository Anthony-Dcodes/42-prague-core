#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"  // use relative path if needed
#include "malloc.h"

int	main(void)
{
	char	*sub_0 = ft_substr("Hello world!", 6, 3);
	char	*sub_1 = ft_substr("hola", 2, 3);
	char	*sub_2 = ft_substr("hola", 3, 2);
	char	*sub_3 = ft_substr("hola", 4, 1);

	char *subs[] = {sub_0, sub_1, sub_2, sub_3};
	const char *labels[] = {"sub_0", "sub_1", "sub_2", "sub_3"};

	for (int i = 0; i < 4; i++)
	{
		if (subs[i])
		{
			printf("%s: \"%s\"\n", labels[i], subs[i]);
			printf("Allocated size: %zu bytes\n\n", malloc_usable_size(subs[i]));
			free(subs[i]);
		}
		else
		{
			printf("%s: Returned NULL\n", labels[i]);
		}
	}

	return 0;
}