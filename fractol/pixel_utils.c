/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 18:56:28 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:38:11 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	apply_polynomial_palette(t_fractal *fract, t_vars *vars)
{
	long double	t;
	long double	r;
	long double	g;
	long double	b;

	compute_last_z_magnitude(fract);
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

void	put_fractal_pixel(t_vars *vars, t_fractal *fract, int x1, int y1)
{
	double		x_complex;
	double		y_complex;

	x_complex = map_x_to_complex_plane(x1, vars->x_min,
			vars->x_max, vars->win_width);
	y_complex = map_y_to_complex_plane(y1, vars->y_min,
			vars->y_max, vars->win_height);
	if (vars->fract_type == 'm')
		compute_mandelbrot(x_complex, y_complex, fract);
	else if (vars->fract_type == 'j')
		compute_julia(x_complex, y_complex, fract, vars);
	else if (vars->fract_type == 'b')
		compute_burningship(x_complex, y_complex, fract);
	apply_polynomial_palette(fract, vars);
	my_mlx_pixel_put(&vars->img, x1, y1, fract->final_color);
}
