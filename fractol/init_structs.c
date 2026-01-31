/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:49:57 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 14:25:21 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_t_vars(t_vars *vars, char fractal_type)
{
	vars->win_width = SCREEN_WIDTH;
	vars->win_height = SCREEN_HEIGHT;
	vars->color_shift = 0;
	vars->frame = 0;
	vars->max_fractal_iter = MAX_FRACTAL_ITER;
	if (fractal_type == 'm' || fractal_type == 'b')
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
