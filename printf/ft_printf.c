/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 17:47:35 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (ft_strchr("sc", *format))
				handle_sc_formats(*format, args);
			else if (ft_strchr("duf", *format))
				handle_duf_formats(*format, args);
		}
		else
			ft_putchar_fd(*format, 1);
		++format;
	}
	va_end(args);
	return (0);
}
