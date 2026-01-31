/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:09:48 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	render_rainbow(void *param)
// {
// 	t_vars	*vars;
// 	int		x;
// 	int		y;
// 	int		band;
// 	int		band_lenght;
// 	int		color_bands[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

// 	vars = (t_vars *)param;
// 	band_lenght = vars->win_height / 6;
// 	x = 0;
// 	y = 0;
// 	while (y < vars->win_height)
// 	{
// 		x = 0;
// 		band = (y / band_lenght + vars->color_shift) % 6;
// 		if (band > 5)
// 			band = 5;
// 		while (x < vars->win_width)
// 		{
// 			my_mlx_pixel_put(&vars->img, x, y, color_bands[band]);
// 			++x;
// 		}
// 		++y;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	++vars->frame;
// 	if (vars->frame % 100 == 0)
// 		++vars->color_shift;
// 	return (0);
// }

// int	render_circle(void *param)
// {
// 	t_vars	*vars;
// 	double	x1;
// 	double	y1;
// 	double	distance;

// 	vars = (t_vars *)param;
// 	y1 = 0;
// 	while (y1 < vars->win_height)
// 	{
// 		x1 = 0;
// 		while (x1 < vars->win_width)
// 		{
// 			distance = euclidian_distance(x1, vars->circle_x, y1,
//			vars->circle_y);
// 			if (distance <= vars->circle_size)
// 				my_mlx_pixel_put(&vars->img, x1, y1, RED);
// 			else
// 				my_mlx_pixel_put(&vars->img, x1, y1, GREEN);
// 			++x1;
// 		}
// 		++y1;
// 	}
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
// 	return (0);
// }

int	render_fractal(void *param)
{
	t_vars		*vars;
	int			x1;
	int			y1;
	t_fractal	fract;

	vars = (t_vars *)param;
	y1 = 0;
	vars->frame += 1;
	ft_printf("Frame n: %d\n", vars->frame);
	while (y1 < vars->win_height)
	{
		x1 = 0;
		while (x1 < vars->win_width)
		{
			if (vars->fract_type == 'm')
				render_mandlerbrot(vars, &fract, x1, y1);
			else if (vars->fract_type == 'j')
				render_julia(vars, &fract, x1, y1);
			else if (vars->fract_type == 'b')
				render_burning_ship(vars, &fract, x1, y1);
			++x1;
		}
		++y1;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}

void	render_mandlerbrot(t_vars *vars, t_fractal *fract, int x1, int y1)
{
	double		x_complex;
	double		y_complex;

	x_complex = x_coordinate_to_complex_plane(x1, vars->x_min,
			vars->x_max, vars->win_width);
	y_complex = y_coordinate_to_complex_plane(y1, vars->y_min,
			vars->y_max, vars->win_height);
	fractal_mandelbrot_set(x_complex, y_complex, fract);
	compute_polynomial_pallete(fract, vars);
	my_mlx_pixel_put(&vars->img, x1, y1, fract->final_color);
}

void	render_julia(t_vars *vars, t_fractal *fract, int x1, int y1)
{
	double		x_complex;
	double		y_complex;

	x_complex = x_coordinate_to_complex_plane(x1, vars->x_min,
			vars->x_max, vars->win_width);
	y_complex = y_coordinate_to_complex_plane(y1, vars->y_min,
			vars->y_max, vars->win_height);
	fractal_julia_set(x_complex, y_complex, fract, vars);
	compute_polynomial_pallete(fract, vars);
	my_mlx_pixel_put(&vars->img, x1, y1, fract->final_color);
}

void	render_burning_ship(t_vars *vars, t_fractal *fract, int x1, int y1)
{
	double		x_complex;
	double		y_complex;

	x_complex = x_coordinate_to_complex_plane(x1, vars->x_min,
			vars->x_max, vars->win_width);
	y_complex = y_coordinate_to_complex_plane(y1, vars->y_min,
			vars->y_max, vars->win_height);
	fractal_burning_ship(x_complex, y_complex, fract);
	compute_polynomial_pallete(fract, vars);
	my_mlx_pixel_put(&vars->img, x1, y1, fract->final_color);
}
