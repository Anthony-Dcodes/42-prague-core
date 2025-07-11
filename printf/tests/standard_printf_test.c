/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_printf_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:54:29 by advorace          #+#    #+#             */
/*   Updated: 2025/07/11 19:59:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("Hello\n");
	printf("Hello %d\n", 5);
	printf("Hello %d\n", 4);
	printf("Hello %d\n", 1);
	printf("Hello %x\n", 992);
	printf("Hello %X\n", -992);

	int x = 42;
    int *ptr = &x;

    printf("Pointer address: %p\n", ptr);
    printf("Null pointer: %p\n", NULL);
	printf("Helllo %q aaa");
	return (0);
}
