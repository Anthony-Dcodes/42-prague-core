/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2025/06/11 22:48:40 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'c')
				ft_process_c(va_arg(args, int));
			else if (*format == 's')
				ft_process_s(va_arg(args, char *));
		}
		else
		{
			ft_putchar_fd(*format, 1);
		}
		++format;
	}
	return (0);

}

