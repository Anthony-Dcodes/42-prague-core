/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 19:48:52 by advorace          #+#    #+#             */
/*   Updated: 2025/12/19 15:37:15 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handler(int sig)
{
	static unsigned char	c;
	static int				bit_count;

	c <<= 1;
	if (sig == SIGUSR2)
		c |= 1;
	++bit_count;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("PID: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
