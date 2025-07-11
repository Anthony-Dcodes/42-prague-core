/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:03:16 by advorace          #+#    #+#             */
/*   Updated: 2025/07/11 18:36:17 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Always frees input str
#include "ft_printf.h"

int	common_print(char *str)
{
	size_t	len;

	len = (int)(ft_strlen(str));
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
