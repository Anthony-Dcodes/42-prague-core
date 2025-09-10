#include "push_swap.h"

static int	error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;
	int	num;

	i = 1;
	if (argc == 1)
		return (0);
	while (i < argc)
	{
		if (!ft_atoi_safe(argv[i], &num))
		{
			return (error());
		}
		else
		{
			ft_printf("Number is int save: %d\n", num);
		}
		++i;
	}
	return (0);
}