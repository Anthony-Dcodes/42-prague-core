#include "libft.h"
#include "ft_printf.h"

int main(int argc, char *argv[])
{
	int	i;

	i = 1;
	ft_printf("Number of arguments: %d", argc);
	while (i < argc)
	{
		ft_printf("Arg %d: %s\n", i, argv[i]);
		++i;
	}
	return (0);
}