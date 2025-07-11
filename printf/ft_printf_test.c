/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:58 by advorace          #+#    #+#             */
/*   Updated: 2025/07/11 19:13:16 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test_0 char: 'C'\nHello %cworld!\n", 'C');
	ft_printf("Test_1 string: 'Hey man ':\nHello %sworld!\n", "Hey man ");
	ft_printf("Test_2 int i: 42:\nHello %iworld!\n", 42);
	ft_printf("Test_3 int d: 0:\nHello %dworld!\n", 0);
	ft_printf("Test_4 int d: -1002:\nHello %dworld!\n", -1002);
	ft_printf("Test_5 int u: 4294967295:\nHello %uworld!\n", 4294967295);
	ft_printf("Test_6 int u: 4294967295:\nHello %xworld!\n", 992);
	ft_printf("Test_7 int u: 4294967295:\nHello %Xworld!\n", -992);
	int x = 42;
    int *ptr = &x;

    ft_printf("Pointer address: %p\n", ptr);
    ft_printf("Null pointer: %p\n", NULL);
	return (0);
}
