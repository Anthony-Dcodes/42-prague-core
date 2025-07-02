/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sc_formats.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:26:01 by advorace          #+#    #+#             */
/*   Updated: 2025/07/02 19:08:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_sc_formats(char format_specifier, va_list args)
{
	char	*str;
	char	ch;

	if (format_specifier == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (format_specifier == 'c')
	{
		ch = (char)va_arg(args, int);
		ft_putchar_fd(ch, 1);
		return (1);
	}
	return (0);
}
