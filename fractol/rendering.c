/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:09:48 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:40:37 by advorace         ###   ########.fr       */
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
