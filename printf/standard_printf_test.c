/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standard_printf_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 19:54:29 by advorace          #+#    #+#             */
/*   Updated: 2025/06/30 19:54:36 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("Hello\n");
	printf("Hello %d\n", 5);
	printf("Hello %d", 4, 2);
	printf("Hello %d %d", 1);
	return (0);
}
