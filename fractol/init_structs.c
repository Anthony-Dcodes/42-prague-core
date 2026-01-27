/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:49:57 by advorace          #+#    #+#             */
/*   Updated: 2026/01/27 22:19:31 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_t_vars(t_vars *vars, char fractal_type)
{
	vars->win_width = 800;
	vars->win_height = 600;
	vars->color_shift = 0;
	vars->frame = 0;
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
