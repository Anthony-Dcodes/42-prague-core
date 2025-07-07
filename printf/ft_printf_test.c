/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:58 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 21:17:15 by advorace         ###   ########.fr       */
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
	return (0);
}
