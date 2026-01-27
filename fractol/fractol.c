/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advorace <advorace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:39:18 by advorace          #+#    #+#             */
/*   Updated: 2026/01/27 21:46:56 by advorace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		clean_up(&vars, EXIT_FAILURE);
	parse_arguments(&vars, argc, argv);
	init_t_vars(&vars, vars.fract_type);
	vars.win = mlx_new_window(vars.mlx, vars.win_width,
			vars.win_height, "Hellow world!");
	if (vars.win == NULL)
		clean_up(&vars, EXIT_FAILURE);
	vars.img.img = mlx_new_image(vars.mlx, vars.win_width, vars.win_height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_key_hook(vars.win, close_window_esc, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, close_window_red_cross, &vars);
	mlx_mouse_hook(vars.win, mouse_zoom_hook, &vars);
	mlx_loop_hook(vars.mlx, render_fractal, &vars);
	mlx_loop(vars.mlx);
}
