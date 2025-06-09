/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:40:52 by advorace          #+#    #+#             */
/*   Updated: 2025/06/09 21:26:05 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);

	while (*format)
	{
		ft_putchar_fd(*format, 1);
		++format;
	}
	return (0);

}

