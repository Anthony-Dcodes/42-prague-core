#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char str[] = "hello";
	printf("str before: %s", str);
	ft_striteri(str, ft_bzero);
	printf("str after: %s", str);
	return (0);
}