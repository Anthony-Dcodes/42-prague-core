/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_printf_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:54:29 by advorace          #+#    #+#             */
/*   Updated: 2025/07/10 21:37:16 by advorace         ###   ########.fr       */
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
	return (0);
}
