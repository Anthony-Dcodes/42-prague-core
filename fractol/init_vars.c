/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:49:57 by advorace          #+#    #+#             */
/*   Updated: 2026/01/31 16:28:28 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_vars(t_vars *vars, char fractal_type)
{
	vars->win_width = SCREEN_WIDTH;
	vars->win_height = SCREEN_HEIGHT;
	vars->frame = 0;
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
