/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:52:58 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 17:48:17 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("Test_0 char: 'C'\nHello %cworld!\n", 'C');
	ft_printf("Test_1 string: 'Hey man ':\nHello %sworld!\n", "Hey man ");
	ft_printf("Test_2 int: 42:\nHello %dworld!\n", 42);
	return (0);
}
