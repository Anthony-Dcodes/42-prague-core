/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:56:28 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 15:56:50 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	apply_polynomial_palette(t_fractal *fract, t_vars *vars)
{
	long double	t;
	long double	r;
	long double	g;
	long double	b;

	last_z_magnitude(fract);
	smooth_iter_count(fract);
	if (fract->iter == MAX_FRACTAL_ITER)
	{
		fract->final_color = BLACK;
		return ;
	}
	t = fract->smooth_iter_count / MAX_FRACTAL_ITER;
	t = fmod(t + fmod(vars->frame * 0.01, 1.0), 1.0);
	r = (int)(255 * (15 * (1 - t) * pow(t, 2)));
	g = (int)(255 * (8 * pow(1 - t, 2) * pow(t, 2)));
	b = (int)(255 * (3 * pow(1 - t, 3) * t));
	fract->final_color = create_trgb(0, r, g, b);
}
