/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:09:48 by advorace          #+#    #+#             */
/*   Updated: 2026/01/16 22:10:34 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_rainbow(void *param)
{
	t_vars	*vars;
	int		x;
	int		y;
	int		band;
	int		band_lenght;
	int		color_bands[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

	vars = (t_vars *)param;
	band_lenght = vars->win_height / 6;
	x = 0;
	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		band = (y / band_lenght + vars->color_shift) % 6;
		if (band > 5)
			band = 5;
		while (x < vars->win_width)
		{
			my_mlx_pixel_put(&vars->img, x, y, color_bands[band]);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	++vars->frame;
	if (vars->frame % 100 == 0)
		++vars->color_shift;
	return (0);
}
