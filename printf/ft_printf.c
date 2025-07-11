/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2025/07/11 20:01:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_helper(char format, va_list args)
{
	int	total;

	total = 0;
	if (ft_strchr("sc", format))
		total += handle_sc_formats(format, args);
	else if (ft_strchr("diu", format))
		total += handle_diu_formats(format, args);
	else if (ft_strchr("xXp", format))
		total += handle_xyp_formats(format, args);
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_printed;

	va_start(args, format);
	total_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (ft_strchr("scdiuxXp", *format))
				total_printed += print_helper(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			++total_printed;
		}
		++format;
	}
	va_end(args);
	return (total_printed);
}
