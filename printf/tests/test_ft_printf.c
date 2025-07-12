/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:58 by advorace          #+#    #+#             */
/*   Updated: 2025/07/12 11:05:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
	int count;
	int x = 42;
	int *ptr = &x;

	ft_printf("\n========== FT_PRINTF TEST ==========\n");

	// %c tests
	count = ft_printf("Char test: %c\n", 'A');
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Char null test: %cEND\n", '\0');
	ft_printf("Return count: %d\n", count);

	// %s tests
	count = ft_printf("String test: %s\n", "Hello, World!");
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Empty string test: %s\n", "");
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Null string test: %s\n", (char *)NULL);
	ft_printf("Return count: %d\n", count);

	// %p tests
	count = ft_printf("Pointer test: %p\n", ptr);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Null pointer test: %p\n", NULL);
	ft_printf("Return count: %d\n", count);

	// %d and %i tests
	count = ft_printf("Decimal zero: %d\n", 0);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Decimal positive: %d\n", 12345);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Decimal negative: %d\n", -12345);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Decimal INT_MAX: %d\n", INT_MAX);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Decimal INT_MIN: %d\n", INT_MIN);
	ft_printf("Return count: %d\n", count);

	count = ft_printf("Integer test: %i\n", 67890);
	ft_printf("Return count: %d\n", count);

	// %u tests
	count = ft_printf("Unsigned zero: %u\n", 0);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Unsigned normal: %u\n", 12345);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Unsigned max: %u\n", UINT_MAX);
	ft_printf("Return count: %d\n", count);

	// %x and %X tests
	count = ft_printf("Hex lower: %x\n", 0xBEEF);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Hex lower zero: %x\n", 0);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Hex upper: %X\n", 0xBEEF);
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Hex upper zero: %X\n", 0);
	ft_printf("Return count: %d\n", count);

	// Mixed test
	count = ft_printf("Mixed: char: %c, str: %s, dec: %d, hex: %x, ptr: %p\n", 'A', "Test", 42, 255, ptr);
	ft_printf("Return count: %d\n", count);

	// %% tests
	count = ft_printf("Percent test: %%\n");
	ft_printf("Return count: %d\n", count);
	count = ft_printf("Multiple percent: %%%% %%\n");
	ft_printf("Return count: %d\n", count);

	// Unknown specifier
	count = ft_printf("Unknown specifier: %q\n");
	ft_printf("Return count: %d\n", count);

	return 0;
}


