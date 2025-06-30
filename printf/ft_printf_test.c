#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test_0 char: 'C'\nHello %cworld!\n", 'C');
	ft_printf("Test_1 string: 'Hey man ':\nHello %sworld!\n", "Hey man ");
	ft_printf("Test_2 int: 42:\nHello %dworld!\n", 42);
	return (0);
}
