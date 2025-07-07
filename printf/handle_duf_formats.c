/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_duf_formats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:50:42 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 21:19:42 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_duf_formats(char format_specifier, va_list args)
{
	int				num_d;
	unsigned int	num_u;
	//float			num_f;
	char			*str;

	if (format_specifier == 'd')
	{
		num_d = va_arg(args, int);
		str = ft_itoa(num_d);
		return (common_print(str));
	}
	else if (format_specifier == 'u' || format_specifier == 'i')
	{
		num_u = va_arg(args, unsigned int);
		str = uiota(num_u);
		return (common_print(str));
	}
	return (-1);
	// else if (format_specifier == 'f')
	// (
	// 	num_f = va_arg(args, double);
	// 	str = diota(num_f);
	// 	return (common_print(str));
	// )
}
