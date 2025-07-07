/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:16 by advorace          #+#    #+#             */
/*   Updated: 2025/07/07 18:21:53 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	common_print(char *str)
{
	size_t	len;

	len = (int)(ft_strlen(str));
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
