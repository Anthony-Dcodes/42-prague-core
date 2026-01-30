/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:49:57 by advorace          #+#    #+#             */
/*   Updated: 2026/01/30 23:27:29 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_t_vars(t_vars *vars, char fractal_type)
{
	vars->win_width = 800;
	vars->win_height = 600;
	vars->color_shift = 0;
	vars->frame = 0;
	vars->max_fractal_iter = MAX_FRACTAL_ITER;
	if (fractal_type == 'm')
	{
		vars->x_min = MANDEL_X_MIN;
		vars->x_max = MANDEL_X_MAX;
		vars->y_min = MANDEL_Y_MIN;
		vars->y_max = MANDEL_Y_MAX;
	}
	else if (fractal_type == 'j')
	{
		vars->x_min = JULIA_X_MIN;
		vars->x_max = JULIA_X_MAX;
		vars->y_min = JULIA_Y_MIN;
		vars->y_max = JULIA_Y_MAX;
	}
}
