/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2025/06/09 22:03:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	char	c;

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				ft_putchar_fd(c, 1);
			}
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		++format;
	}
	return (0);

}

