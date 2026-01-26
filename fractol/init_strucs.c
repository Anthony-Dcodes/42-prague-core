/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strucs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:49:57 by advorace          #+#    #+#             */
/*   Updated: 2026/01/26 22:52:57 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_t_vars(t_vars *vars)
{
	vars->win_width = 800;
	vars->win_height = 600;
	vars->color_shift = 0;
	vars->frame = 0;
	vars->circle_x = 500;
	vars->circle_y = 500;
	vars->circle_size = 100;
	vars->x_min = MANDEL_X_MIN;
	vars->x_max = MANDEL_X_MAX;
	vars->y_min = MANDEL_Y_MIN;
	vars->y_max = MANDEL_Y_MAX;
}
