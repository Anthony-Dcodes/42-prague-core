/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:56:22 by advorace          #+#    #+#             */
/*   Updated: 2025/07/02 19:09:13 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Write unsinged int n to file descriptor fd
void	put_unsigned_int(unsigned int n, int fd)
{
	char	c;

	if (n == 4294967296)
	{
		write(fd, "4294967296", 10);
		return ;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
