/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:56:28 by advorace          #+#    #+#             */
/*   Updated: 2026/01/16 18:56:43 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	my_mlx_square_put(t_data *data, int x, int y, int color, int size)
{
	char	*dst;
	int		i = 0;
	int		j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			dst = data->addr + ((y + j) * data->line_length + (x + i) * (data->bits_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}
