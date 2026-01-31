/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:09:48 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:10:27 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_fractal(void *param)
{
	t_vars		*vars;
	int			x1;
	int			y1;
	t_fractal	fract;

	vars = (t_vars *)param;
	y1 = 0;
	vars->frame += 1;
	while (y1 < vars->win_height)
	{
		x1 = 0;
		while (x1 < vars->win_width)
		{
			put_fractal_pixel(vars, &fract, x1, y1);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
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
