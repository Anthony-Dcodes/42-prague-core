#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int	n1 = 0;
	int	n2 = -2147483648;
	int	n3 = 2147483647;

	char	*s1 = ft_itoa(n1);
	char	*s2 = ft_itoa(n2);
	char	*s3 = ft_itoa(n3);

	printf("Conver number: %d, to str with ft_itoa: %s\n", n1, s1);
	printf("Conver number: %d, to str with ft_itoa: %s\n", n2, s2);
	printf("Conver number: %d, to str with ft_itoa: %s\n", n3, s3);
	free(s1);
	free(s2);
	free(s3);
}
